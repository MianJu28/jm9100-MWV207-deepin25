/*
 * 由 /tmp/glxswap.c 固化（2026-10-08）。编译：gcc -O2 -o glxswap glx_swap_sync_probe.c -lGL -lX11
 * glxswap —— 客观测量 GLX 交换是否受 vblank 限制
 *
 * 原理：若交换与 vblank 同步，glXSwapBuffers 会被节流到面板刷新率
 * （本机 100Hz ⇒ 单次约 10ms）；若不同步，则会跑到几百~几千 Hz。
 * 这直接对应"扫描输出读到正在被写入的缓冲"（三角/楔形错位）的成因。
 *
 * 用法: glxswap [n]
 */
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static double now(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main(int argc, char **argv)
{
	int n = argc > 1 ? atoi(argv[1]) : 300;
	Display *dpy;
	Window win;
	GLXContext ctx;
	XVisualInfo *vi;
	XSetWindowAttributes swa;
	Colormap cmap;
	int attribs[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	int i;
	double t0, t1;

	dpy = XOpenDisplay(NULL);
	if (!dpy) { fprintf(stderr, "no display\n"); return 1; }
	vi = glXChooseVisual(dpy, DefaultScreen(dpy), attribs);
	if (!vi) { fprintf(stderr, "no visual\n"); return 1; }
	cmap = XCreateColormap(dpy, RootWindow(dpy, vi->screen), vi->visual, AllocNone);
	swa.colormap = cmap;
	swa.event_mask = ExposureMask;
	win = XCreateWindow(dpy, RootWindow(dpy, vi->screen), 0, 0, 320, 240, 0,
			    vi->depth, InputOutput, vi->visual,
			    CWColormap | CWEventMask, &swa);
	XMapWindow(dpy, win);
	ctx = glXCreateContext(dpy, vi, NULL, GL_TRUE);
	glXMakeCurrent(dpy, win, ctx);

	printf("renderer=%s\n", (const char *)glGetString(GL_RENDERER));

	/* 预热 */
	for (i = 0; i < 5; i++) { glClear(GL_COLOR_BUFFER_BIT); glXSwapBuffers(dpy, win); }

	t0 = now();
	for (i = 0; i < n; i++) {
		glClearColor((i & 1) ? 1.0f : 0.0f, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glXSwapBuffers(dpy, win);
	}
	t1 = now();

	printf("swaps=%d elapsed=%.3fs  => 交换速率 ≈ %.1f Hz  单次 %.3f ms\n",
	       n, t1 - t0, n / (t1 - t0), (t1 - t0) * 1000.0 / n);
	printf("判读: 接近面板刷新率(100Hz)=与vblank同步 ✓ ; 远高于=未同步 ✗\n");

	glXMakeCurrent(dpy, None, NULL);
	glXDestroyContext(dpy, ctx);
	XDestroyWindow(dpy, win);
	XCloseDisplay(dpy);
	return 0;
}
