/*
 * jm_dumb_probe.c -- 验证 jmgpu 的 dumb buffer 能否被 mmap
 *
 * 背景：驱动的 file_operations.mmap = j9_diluvianism()，它先调 drm_gem_mmap()
 * 建立 vma->vm_private_data 与 vm_ops，真正的页映射由 vm_ops.fault
 * （j9_handle_j9_sitatungas，BAR2 尾部的滑动窗口）完成——即使 gem_object_funcs
 * 里没有 .mmap / drm_driver 里没有 .gem_prime_mmap，只要 vm_ops.fault 在，
 * dumb/GEM mmap 依然可用（实测通）。
 *
 * dumb buffer（DRM_IOCTL_MODE_CREATE_DUMB + MAP_DUMB + mmap）是 X 的影子帧缓冲、
 * kmscube、ffmpeg 的 drm 输出、weston 软渲染等一大批客户端的必经路径，所以这条
 * 路径通不通有实际影响。而它只覆盖「GEM/dumb mmap（经滑动窗口）」这一种 CPU
 * 访问；dmabuf 的 dma_buf_mmap() 不过窗口，对不可见池会静默读全零（见 README
 * §3.3 的两条路径对比表）。
 *
 * 编译：gcc -O2 -Wall -I/usr/include/libdrm -o /tmp/jm_dumb_probe \
 *           jm_dumb_probe.c -ldrm
 * 用法：./jm_dumb_probe [节点]        默认 /dev/dri/card0
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

#define W 256
#define H 256

int main(int argc, char **argv)
{
	const char *node = argc > 1 ? argv[1] : "/dev/dri/card0";
	int fd = open(node, O_RDWR);
	uint32_t handle = 0, pitch = 0;
	uint64_t size = 0, offset = 0;
	void *map;
	int ret;

	if (fd < 0) {
		perror(node);
		return 1;
	}

	/* 1) 创建 dumb buffer */
	ret = drmModeCreateDumbBuffer(fd, W, H, 32, 0, &handle, &pitch, &size);
	printf("[1] CREATE_DUMB      : %s (handle=%u pitch=%u size=%llu)\n",
	       ret ? strerror(errno) : "ok", handle, pitch,
	       (unsigned long long)size);
	if (ret)
		return 1;

	/* 2) 取 mmap 偏移（对应驱动 dumb_map_offset / GEM mmap offset） */
	ret = drmModeMapDumbBuffer(fd, handle, &offset);
	printf("[2] MAP_DUMB(取偏移) : %s (offset=0x%llx)\n",
	       ret ? strerror(errno) : "ok", (unsigned long long)offset);
	if (ret) {
		drmModeDestroyDumbBuffer(fd, handle);
		return 1;
	}

	/* 3) mmap —— 这一步会走 file_operations.mmap = j9_diluvianism() */
	map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
		   (off_t)offset);
	if (map == MAP_FAILED) {
		printf("[3] mmap             : FAILED (%s)   <-- GEM/dumb mmap 不可用\n",
		       strerror(errno));
		drmModeDestroyDumbBuffer(fd, handle);
		return 2;
	}
	printf("[3] mmap             : ok (%p)\n", map);

	/* 4) 读写回环 */
	memset(map, 0xA5, 64);
	printf("[4] 读写回环         : map[0]=0x%02x map[63]=0x%02x %s\n",
	       ((unsigned char *)map)[0], ((unsigned char *)map)[63],
	       ((unsigned char *)map)[0] == 0xA5 ? "(正常)" : "(内容不符!)");

	munmap(map, size);
	drmModeDestroyDumbBuffer(fd, handle);
	close(fd);
	return 0;
}
