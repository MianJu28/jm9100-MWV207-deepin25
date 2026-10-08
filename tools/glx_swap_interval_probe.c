/*
 * 由 /tmp/glxsync.c 固化（2026-10-08）。编译：gcc -O2 -o glxsync glx_swap_interval_probe.c -lGL -lX11
 * glxsync —— 测试厂商 GLX 是否支持各种"交换间隔"同步 API
 *   glXSwapIntervalEXT (GLX_EXT_swap_control)
 *   glXSwapIntervalSGI (GLX_SGI_swap_control)
 *   glXSwapIntervalMESA(GLX_MESA_swap_control)
 * 若某个 API 能把交换速率压到 ~100Hz，就是可用的修复路径。
 */
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/glxext.h>
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

static double rate(Display *dpy, Window win, int n)
{
	int i; double t0, t1;
	for (i = 0; i < 5; i++) { glClear(GL_COLOR_BUFFER_BIT); glXSwapBuffers(dpy, win); }
	t0 = now();
	for (i = 0; i < n; i++) {
		glClearColor((i & 1) ? 1.f : 0.f, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glXSwapBuffers(dpy, win);
	}
	t1 = now();
	return n / (t1 - t0);
}

int main(int argc, char **argv)
{
	int n = argc > 1 ? atoi(argv[1]) : 200;
	setvbuf(stdout, NULL, _IONBF, 0);
	Display *dpy;
	Window win;
	GLXContext ctx;
	XVisualInfo *vi;
	XSetWindowAttributes swa;
	Colormap cmap;
	int attribs[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	const char *ext;
	PFNGLXSWAPINTERVALEXTPROC pEXT;
	PFNGLXSWAPINTERVALSGIPROC pSGI;
	PFNGLXSWAPINTERVALMESAPROC pMESA;

	dpy = XOpenDisplay(NULL);
	if (!dpy) return 1;
	vi = glXChooseVisual(dpy, DefaultScreen(dpy), attribs);
	cmap = XCreateColormap(dpy, RootWindow(dpy, vi->screen), vi->visual, AllocNone);
	swa.colormap = cmap; swa.event_mask = ExposureMask;
	win = XCreateWindow(dpy, RootWindow(dpy, vi->screen), 0, 0, 320, 240, 0,
			    vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
	XMapWindow(dpy, win);
	ctx = glXCreateContext(dpy, vi, NULL, GL_TRUE);
	glXMakeCurrent(dpy, win, ctx);
	printf("renderer = %s\n", (const char *)glGetString(GL_RENDERER));

	ext = glXQueryExtensionsString(dpy, DefaultScreen(dpy));
	printf("GLX extensions 含:\n");
	printf("  EXT_swap_control : %s\n", strstr(ext, "GLX_EXT_swap_control") ? "是" : "否");
	printf("  SGI_swap_control : %s\n", strstr(ext, "GLX_SGI_swap_control") ? "是" : "否");
	printf("  MESA_swap_control: %s\n", strstr(ext, "GLX_MESA_swap_control") ? "是" : "否");

	printf("\n基线(不设任何间隔)          : %.1f Hz\n", rate(dpy, win, n));

	pEXT = (PFNGLXSWAPINTERVALEXTPROC)glXGetProcAddress((const GLubyte *)"glXSwapIntervalEXT");
	if (pEXT) { pEXT(dpy, win, 1); printf("glXSwapIntervalEXT(1)       : %.1f Hz\n", rate(dpy, win, n)); }
	else printf("glXSwapIntervalEXT          : 符号不存在\n");

	pMESA = (PFNGLXSWAPINTERVALMESAPROC)glXGetProcAddress((const GLubyte *)"glXSwapIntervalMESA");
	if (pMESA) { printf("glXSwapIntervalMESA(1) ret=%d", pMESA(1)); printf("  : %.1f Hz\n", rate(dpy, win, n)); }
	else printf("glXSwapIntervalMESA         : 符号不存在\n");

	pSGI = (PFNGLXSWAPINTERVALSGIPROC)glXGetProcAddress((const GLubyte *)"glXSwapIntervalSGI");
	if (pSGI) { printf("glXSwapIntervalSGI(1) ret=%d", pSGI(1)); printf("   : %.1f Hz\n", rate(dpy, win, n)); }
	else printf("glXSwapIntervalSGI          : 符号不存在\n");

	printf("\n判读: 能压到 ~100Hz 的 API 即有效修复路径\n");
	glXMakeCurrent(dpy, None, NULL);
	glXDestroyContext(dpy, ctx);
	XDestroyWindow(dpy, win);
	XCloseDisplay(dpy);
	return 0;
}
