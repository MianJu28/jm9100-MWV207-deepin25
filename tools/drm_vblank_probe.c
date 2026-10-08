/*
 * 由 /tmp/vbtest.c 固化（2026-10-08）。编译：gcc -O2 -I/usr/include/libdrm -o vbtest drm_vblank_probe.c -ldrm
 * vbtest —— 直接问 DRM 内核：vblank 计数到底有没有在走？
 *
 * 原理：DRM_IOCTL_WAIT_VBLANK 的完成依赖 drm_crtc_handle_vblank() 被调用
 * （它推进 drm_vblank_count 并唤醒等待队列）。驱动里唯一会调用它的地方是
 *   A) 硬件中断 j9_handle_j9luciferase()（读 vblank_irq_mask 的 bit12+crtc）
 *   B) 软件 hrtimer jmgpu_vkms_crtc_finish_page_flip_func()（fake_vblank/vdisplay 或 sw_vblank_counter）
 * 所以本测试能区分"硬件 vblank 到底有没有到 DRM 核心"。
 *
 * 用法: vbtest [card] [n]
 *   n = 要等的 vblank 个数；每个都设 3s 超时，超时即判定"卡住"。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <time.h>
#include <xf86drm.h>

static volatile sig_atomic_t timed_out;

static void on_alarm(int s) { (void)s; timed_out = 1; }

static double now(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main(int argc, char **argv)
{
	const char *card = argc > 1 ? argv[1] : "/dev/dri/card0";
	int n = argc > 2 ? atoi(argv[2]) : 120;
	unsigned int crtc = argc > 3 ? (unsigned int)atoi(argv[3]) : 0;
	int fd, i, ok = 0, stuck = 0;
	double t0, t1;

	fd = open(card, O_RDWR);
	if (fd < 0) { perror("open"); return 1; }

	signal(SIGALRM, on_alarm);

	printf("card=%s crtc=%u n=%d\n", card, crtc, n);
	t0 = now();
	for (i = 0; i < n; i++) {
		drmVBlank vbl;
		int r;

		memset(&vbl, 0, sizeof(vbl));
		vbl.request.type = DRM_VBLANK_RELATIVE | ((crtc & 0x1) << 8);
		vbl.request.sequence = 1;   /* 等下一个 vblank */

		timed_out = 0;
		alarm(3);
		r = ioctl(fd, DRM_IOCTL_WAIT_VBLANK, &vbl);
		alarm(0);

		if (timed_out) {
			stuck++;
			printf("  #%d  **卡住(>3s)**: WAIT_VBLANK 未返回\n", i);
			if (stuck >= 2) break;
			continue;
		}
		if (r) { perror("  WAIT_VBLANK"); break; }
		ok++;
		if (i < 3 || i >= n - 2)
			printf("  #%d  seq=%u  t=%ld.%06ld\n", i, vbl.reply.sequence,
			       (long)vbl.reply.tval_sec, (long)vbl.reply.tval_usec);
	}
	t1 = now();
	printf("成功 %d / %d，卡住 %d，用时 %.3fs",
	       ok, i, stuck, t1 - t0);
	if (ok > 1)
		printf("  => vblank 速率 ≈ %.1f Hz", (ok - 1) / (t1 - t0));
	printf("\n");
	close(fd);
	return stuck ? 2 : 0;
}
