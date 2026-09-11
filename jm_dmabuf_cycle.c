/*
 * jm_dmabuf_cycle.c -- dmabuf 导出/导入 循环压测与泄漏检查
 *
 * 目的：VA-API 直通每帧都要走一遍「VA 驱动导出 dmabuf → GL 侧按 GEM 句柄
 * 导入」的链路。本仓库为这条链路加了同驱动导入快捷路径
 * (jmgpu_dmabuf_peek_node -> j9_handle_j9_dumbbeller)，它会
 * jmkVIDMEM_NODE_Reference() 一次。若引用计数不平衡（多一次/少一次释放），
 * 播放几小时后显存会被慢慢吃光。本探针就用纯 DRM 接口把这条链路压循环：
 *
 *     GEM_CREATE -> PRIME_HANDLE_TO_FD(导出) -> PRIME_FD_TO_HANDLE(导入)
 *       -> GEM_CLOSE(导入句柄) -> close(fd) -> GEM_CLOSE(原句柄)
 *
 * 泄漏指示器（不需要 root）：压测前后各测一次「能分配成功的最大连续块」。
 * 若每次循环都漏一个缓冲，循环 N 次后可用显存会明显缩水，最大块随之下降。
 *
 * 编译：gcc -O2 -Wall -I/usr/include/libdrm -o /tmp/jm_dmabuf_cycle \
 *           jm_dmabuf_cycle.c -ldrm
 * 用法：./jm_dmabuf_cycle [循环次数] [每次字节] [节点]
 *       默认 2000 次 x 1MB，节点 /dev/dri/card0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <drm.h>
#include <xf86drm.h>

#define DRM_JM_GEM_CONTIGUOUS (1u << 0)

#define DRM_JM_GEM_CREATE 0x00

struct drm_jm_gem_create {
	uint64_t size;
	uint32_t flags;
	uint32_t handle;
};

#define DRM_IOCTL_JM_GEM_CREATE \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_CREATE, struct drm_jm_gem_create)

static int gem_create(int fd, size_t sz, uint32_t flags, uint32_t *handle)
{
	struct drm_jm_gem_create cr;

	memset(&cr, 0, sizeof(cr));
	cr.size = sz;
	cr.flags = flags;
	if (ioctl(fd, DRM_IOCTL_JM_GEM_CREATE, &cr))
		return -errno;
	*handle = cr.handle;
	return 0;
}

/* 能分配成功的最大块（倍增 + 二分）；flags 决定是否要求物理连续 */
static size_t max_alloc(int fd, size_t lo, size_t hi, uint32_t flags)
{
	size_t sz;
	uint32_t h = 0;

	sz = lo;
	while (sz <= hi) {
		if (gem_create(fd, sz, flags, &h))
			break;
		drmCloseBufferHandle(fd, h);
		sz *= 2;
	}
	if (sz > hi)
		sz = hi;
	else
		sz /= 2;

	/* 在 (sz, 2*sz) 内二分收敛 */
	{
		size_t a = sz, b = sz * 2 > hi ? hi : sz * 2;

		while (a < b) {
			size_t m = a + (b - a + 1) / 2;

			if (gem_create(fd, m, flags, &h) == 0) {
				drmCloseBufferHandle(fd, h);
				a = m;
			} else {
				b = m - 1;
			}
		}
		sz = a;
	}
	return sz;
}

int main(int argc, char **argv)
{
	long iters = argc > 1 ? atol(argv[1]) : 2000;
	size_t sz = argc > 2 ? (size_t)atol(argv[2]) : (1u << 20);
	const char *node = argc > 3 ? argv[3] : "/dev/dri/renderD128";
	uint32_t flags = (argc > 4 && atoi(argv[4])) ? DRM_JM_GEM_CONTIGUOUS : 0;
	size_t before, after;
	long i, failures = 0;
	int fd = open(node, O_RDWR);

	if (fd < 0) {
		perror(node);
		return 1;
	}

	before = max_alloc(fd, 1u << 20, 512u << 20, flags);
	printf("压测前最大可分配: %zu 字节 (%.1f MB)  flags=0x%x\n", before,
	       before / 1048576.0, flags);

	for (i = 0; i < iters; i++) {
		uint32_t handle = 0, imported = 0;
		int dmabuf_fd = -1;
		int ret;

		ret = gem_create(fd, sz, flags, &handle);
		if (ret) {
			failures++;
			continue;
		}
		ret = drmPrimeHandleToFD(fd, handle, DRM_CLOEXEC, &dmabuf_fd);
		if (ret) {
			failures++;
			drmCloseBufferHandle(fd, handle);
			continue;
		}
		ret = drmPrimeFDToHandle(fd, dmabuf_fd, &imported);
		if (ret)
			failures++;

		if (!ret)
			drmCloseBufferHandle(fd, imported);
		close(dmabuf_fd);
		drmCloseBufferHandle(fd, handle);
	}
	printf("循环 %ld 次 x %zu 字节，失败 %ld 次%s\n", iters, sz, failures,
	       failures == iters ? "  <-- 全部失败，检查节点/尺寸" : "");

	after = max_alloc(fd, 1u << 20, 512u << 20, flags);
	printf("压测后最大可分配: %zu 字节 (%.1f MB)\n", after,
	       after / 1048576.0);

	if (after + sz < before) {
		printf("==> 疑似泄漏：可用显存减少 %.1f MB（约 %ld 个缓冲）\n",
		       (before - after) / 1048576.0,
		       (long)((before - after) / sz));
		close(fd);
		return 2;
	}
	printf("==> 未见泄漏：导出/导入/释放链路引用计数平衡\n");
	close(fd);
	return 0;
}
