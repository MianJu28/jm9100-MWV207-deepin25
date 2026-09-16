/*
 * tools/bar_probe.c -- 判断 JM9100 的其它 PCI BAR 是否也是显存窗口。
 *
 * 做法：用 jmgpu 私有 ioctl 分配一块落在 CPU 可见池的显存，经 GEM_LOCK
 * 拿到 CPU 地址并写入特征串；随后 mmap 各 BAR（sysfs resourceN）搜索特征串。
 * 若某个 BAR 里能搜到，说明该 BAR 也能映射显存，可作为额外的 CPU 可见窗口。
 *
 * 用法：gcc -O2 -I/usr/include/libdrm -o /tmp/bar_probe tools/bar_probe.c
 *       sudo /tmp/bar_probe <pci_dev_dir> <bars...>
 *   e.g. sudo /tmp/bar_probe /sys/bus/pci/devices/0000:07:00.0 0 2
 */
#define _GNU_SOURCE
#include <drm.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define DRM_JM_GEM_CREATE 0x00
#define DRM_JM_GEM_LOCK   0x01

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

#define DRM_IOCTL_JM_GEM_CREATE \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_CREATE, struct drm_jm_gem_create)
#define DRM_IOCTL_JM_GEM_LOCK \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_LOCK, struct drm_jm_gem_lock)

static const unsigned char MAGIC[32] = {
	0xde, 0xad, 0xbe, 0xef, 0x31, 0x41, 0x59, 0x26, 0x53, 0x58, 0x97, 0x93,
	0x23, 0x84, 0x62, 0x64, 0x33, 0x83, 0x27, 0x95, 0x02, 0x88, 0x41, 0x97,
	0x16, 0x93, 0x99, 0x37, 0x51, 0x05, 0x82, 0x09
};

int main(int argc, char **argv)
{
	size_t sz = 4u << 20;
	int fd, i, ret;
	struct drm_jm_gem_create cr;
	struct drm_jm_gem_lock lk;
	unsigned char *cpu, *bars[16];

	if (argc < 3) {
		fprintf(stderr, "usage: %s <pci_dev_dir> <bar0> [bar1 ...]\n",
			argv[0]);
		return 1;
	}

	fd = open("/dev/dri/renderD128", O_RDWR);
	if (fd < 0) {
		perror("open renderD128");
		return 1;
	}
	memset(&cr, 0, sizeof(cr));
	cr.size = sz;
	cr.flags = 1; /* CONTIGUOUS */
	ret = ioctl(fd, DRM_IOCTL_JM_GEM_CREATE, &cr);
	if (ret) {
		printf("GEM_CREATE failed (%d)\n", ret);
		return 1;
	}
	memset(&lk, 0, sizeof(lk));
	lk.handle = cr.handle;
	lk.cacheable = 1;
	ret = ioctl(fd, DRM_IOCTL_JM_GEM_LOCK, &lk);
	if (ret || !lk.logical) {
		printf("GEM_LOCK failed (%d)\n", ret);
		return 1;
	}
	cpu = (unsigned char *)(uintptr_t)lk.logical;

	/* 在缓冲区开头和 2MB 处各写一份特征串 */
	memcpy(cpu, MAGIC, sizeof(MAGIC));
	memcpy(cpu + (2u << 20), MAGIC, sizeof(MAGIC));
	printf("GEM %zu bytes: gpu_addr=0x%x logical=%p\n", sz, lk.address, cpu);

	for (i = 2; i < argc && i < 18; i++) {
		char path[512];
		int bar = atoi(argv[i]);
		struct stat st;
		size_t bsz;
		unsigned char *m;
		ssize_t k;

		snprintf(path, sizeof(path), "%s/resource%d", argv[1], bar);
		if (stat(path, &st) != 0) {
			printf("BAR%d: stat failed\n", bar);
			continue;
		}
		bsz = (size_t)st.st_size;
		m = mmap(NULL, bsz, PROT_READ, MAP_SHARED,
			 open(path, O_RDONLY | O_SYNC), 0);
		if (m == MAP_FAILED) {
			printf("BAR%d: mmap failed (%zu bytes)\n", bar, bsz);
			continue;
		}
		bars[bar] = m;
		printf("BAR%d: %zu MB mapped, searching...\n", bar, bsz >> 20);
		{
			size_t off = 0;
			int hits = 0;

			while (off + sizeof(MAGIC) <= bsz) {
				unsigned char *p = memmem(m + off, bsz - off,
							  MAGIC,
							  sizeof(MAGIC));

				if (!p)
					break;
				off = (size_t)(p - m);
				printf("  BAR%d: magic found at 0x%zx\n", bar,
				       off);
				hits++;
				if (hits > 8)
					break;
				off += sizeof(MAGIC);
			}
			if (!hits)
				printf("  BAR%d: magic NOT found\n", bar);
		}
	}

	printf("\n说明：BAR2 必然能找到（它就是可见显存）。若 BAR0 也能找到，\n"
	       "则 BAR0 也是显存窗口，可考虑作为额外 CPU 可见窗口（+128MB）。\n");
	return 0;
}
