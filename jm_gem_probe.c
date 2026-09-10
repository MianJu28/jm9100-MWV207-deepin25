/*
 * jm_gem_probe.c -- 纯内核路径 dmabuf 导出保真度探针（绕开闭源 VA 驱动）
 *
 * 用 jmgpu 私有 GEM ioctl 分配显存 -> GEM_LOCK 取 CPU 地址 -> PRIME 导出 -> mmap。
 * 双向交叉验证两个映射是否指向同一块物理内存，并用 /proc/self/pagemap 读出
 * 两者真实的 PFN，判断导出映射算出的总线地址是否正确。
 *
 * 用法：gcc -O2 -I/usr/include/libdrm -o /tmp/jm_gem_probe jm_gem_probe.c
 *       sudo /tmp/jm_gem_probe          # 遍历多种 size/flags 组合
 *       sudo /tmp/jm_gem_probe <size> <flags>
 */
#include <drm.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>

#define DRM_JM_GEM_CONTIGUOUS (1u << 0)
#define DRM_JM_GEM_CACHED     (1u << 1)
#define DRM_JM_GEM_CMA_LIMIT  (1u << 3)
#define DRM_JM_GEM_VIRTUAL    (1u << 5)

#define DRM_JM_GEM_CREATE 0x00
#define DRM_JM_GEM_LOCK   0x01
#define DRM_JM_GEM_QUERY  0x04

struct drm_jm_gem_create {
	uint64_t size;
	uint32_t flags;
	uint32_t handle;
};
struct drm_jm_gem_lock {
	uint32_t handle;
	uint32_t cacheable;
	uint64_t logical;
	uint32_t address;
	uint32_t shared;
};
struct drm_jm_gem_query {
	uint32_t handle;
	uint32_t param;
	uint64_t value;
};

#define DRM_IOCTL_JM_GEM_CREATE \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_CREATE, struct drm_jm_gem_create)
#define DRM_IOCTL_JM_GEM_LOCK \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_LOCK, struct drm_jm_gem_lock)
#define DRM_IOCTL_JM_GEM_QUERY \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_QUERY, struct drm_jm_gem_query)

static int pmfd = -1;

static unsigned long long va_to_pfn(void *va)
{
	unsigned long long e;
	off_t off = ((off_t)((uintptr_t)va / 4096)) * 8;

	if (pmfd < 0)
		return ~0ULL;
	if (pread(pmfd, &e, 8, off) != 8)
		return ~0ULL;
	if (!(e & (1ULL << 63)))
		return ~0ULL; /* not present */
	return e & ((1ULL << 55) - 1);
}

static void one(int fd, size_t sz, uint32_t flags)
{
	struct drm_jm_gem_create cr;
	struct drm_jm_gem_lock lk;
	struct drm_prime_handle ph;
	unsigned char *cpu, *dmm;
	size_t i;
	int okA = 0, badA = 0, okB = 0, badB = 0;
	int ret;

	memset(&cr, 0, sizeof(cr));
	cr.size = sz;
	cr.flags = flags;
	ret = ioctl(fd, DRM_IOCTL_JM_GEM_CREATE, &cr);
	if (ret) {
		printf("sz=%zu flags=0x%x CREATE ret=%d\n", sz, flags, ret);
		return;
	}
	memset(&lk, 0, sizeof(lk));
	lk.handle = cr.handle;
	lk.cacheable = 1;
	ret = ioctl(fd, DRM_IOCTL_JM_GEM_LOCK, &lk);
	if (ret || !lk.logical) {
		printf("sz=%zu flags=0x%x LOCK ret=%d logical=%#llx\n", sz, flags,
		       ret, (unsigned long long)lk.logical);
		return;
	}
	cpu = (unsigned char *)(uintptr_t)lk.logical;

	memset(&ph, 0, sizeof(ph));
	ph.handle = cr.handle;
	ph.flags = O_RDWR | O_CLOEXEC;
	ret = ioctl(fd, DRM_IOCTL_PRIME_HANDLE_TO_FD, &ph);
	if (ret) {
		printf("sz=%zu flags=0x%x PRIME ret=%d\n", sz, flags, ret);
		return;
	}
	dmm = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, ph.fd, 0);
	if (dmm == MAP_FAILED) {
		printf("sz=%zu flags=0x%x mmap dmabuf FAILED\n", sz, flags);
		close(ph.fd);
		return;
	}

	for (i = 0; i < sz; i += 4096)
		cpu[i] = (unsigned char)(0xA5 ^ (i >> 12));
	for (i = 0; i < sz; i += 4096)
		(dmm[i] == (unsigned char)(0xA5 ^ (i >> 12))) ? okA++ : badA++;
	for (i = 0; i < sz; i += 4096)
		dmm[i] = (unsigned char)(0x5A ^ (i >> 12));
	for (i = 0; i < sz; i += 4096)
		(cpu[i] == (unsigned char)(0x5A ^ (i >> 12))) ? okB++ : badB++;

	printf("sz=%-9zu flags=0x%-3x gpu_addr=0x%-9x cpu=%p(pfn=%#llx) "
	       "dma=%p(pfn=%#llx)  A[ok=%d bad=%d] B[ok=%d bad=%d] "
	       "cpu[0]=%02x dma[0]=%02x\n",
	       sz, flags, lk.address, cpu, va_to_pfn(cpu), dmm, va_to_pfn(dmm),
	       okA, badA, okB, badB, cpu[0], dmm[0]);

	munmap(dmm, sz);
	close(ph.fd);
}

int main(int argc, char **argv)
{
	const char *node = "/dev/dri/renderD128";
	int fd;

	pmfd = open("/proc/self/pagemap", O_RDONLY);
	if (pmfd < 0)
		perror("pagemap (PFN 将不可用)");
	fd = open(node, O_RDWR);
	if (fd < 0) {
		perror("open");
		return 1;
	}

	if (argc > 2) {
		one(fd, strtoull(argv[1], NULL, 0),
		    (uint32_t)strtoul(argv[2], NULL, 0));
	} else {
		static const uint32_t fl[] = { 0,
					       DRM_JM_GEM_CONTIGUOUS,
					       DRM_JM_GEM_CACHED,
					       DRM_JM_GEM_CONTIGUOUS |
						       DRM_JM_GEM_CACHED,
					       DRM_JM_GEM_CMA_LIMIT,
					       DRM_JM_GEM_VIRTUAL };
		static const size_t sizes[] = { 1 << 20, 3 << 20, 64 << 20 };
		size_t s;
		unsigned f;

		for (s = 0; s < 3; s++)
			for (f = 0; f < 6; f++)
				one(fd, sizes[s], fl[f]);
	}
	close(fd);
	return 0;
}
