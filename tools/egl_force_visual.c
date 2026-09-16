/*
 * tools/egl_force_visual.c -- 强行用同一个 EGLConfig 在「屏幕全部 X visual」上建 window surface
 *
 * 目的：判定 libEGL_mwv207 的 eglCreateWindowSurface 是否真的要求
 *       「窗口 visual == config 的 EGL_NATIVE_VISUAL_ID(只有 0x21)」。
 *       若在其它 visual 上也能成功建面并渲染，则 §3.7 的黑窗根因需要修正。
 *
 * 编译：gcc -O2 -o /tmp/egl_force_visual tools/egl_force_visual.c -lEGL -lX11 -lGLESv2
 * 用法：DISPLAY=:0 /tmp/egl_force_visual [visual十六进制...]
 *       不带参数 = 测全部 visual
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>

static const char *eglErrStr(EGLint e) {
	switch (e) {
	case 0x3000: return "EGL_SUCCESS";
	case 0x3001: return "EGL_NOT_INITIALIZED";
	case 0x3002: return "EGL_BAD_ACCESS";
	case 0x3003: return "EGL_BAD_ALLOC";
	case 0x3004: return "EGL_BAD_ATTRIBUTE";
	case 0x3005: return "EGL_BAD_CONFIG";
	case 0x3006: return "EGL_BAD_CONTEXT";
	case 0x3007: return "EGL_BAD_CURRENT_SURFACE";
	case 0x3008: return "EGL_BAD_DISPLAY";
	case 0x3009: return "EGL_BAD_MATCH";
	case 0x300A: return "EGL_BAD_NATIVE_PIXMAP";
	case 0x300B: return "EGL_BAD_NATIVE_WINDOW";
	case 0x300C: return "EGL_BAD_PARAMETER";
	case 0x300D: return "EGL_BAD_SURFACE";
	case 0x300E: return "EGL_CONTEXT_LOST";
	default: return "?";
	}
}

int main(int argc, char **argv) {
	Display *dpy = XOpenDisplay(NULL);
	if (!dpy) { fprintf(stderr, "无法打开 X display\n"); return 1; }
	int scr = DefaultScreen(dpy);

	EGLDisplay edpy = eglGetDisplay((EGLNativeDisplayType)dpy);
	if (edpy == EGL_NO_DISPLAY) { fprintf(stderr, "eglGetDisplay 失败\n"); return 1; }
	EGLint mj = 0, mn = 0;
	if (!eglInitialize(edpy, &mj, &mn)) {
		fprintf(stderr, "eglInitialize 失败 0x%x\n", eglGetError());
		return 1;
	}
	eglBindAPI(EGL_OPENGL_ES_API);

	EGLConfig cfgs[256];
	EGLint n = 0;
	if (!eglGetConfigs(edpy, cfgs, 256, &n) || n == 0) {
		fprintf(stderr, "eglGetConfigs 失败\n");
		return 1;
	}
	EGLint vid0 = 0;
	eglGetConfigAttrib(edpy, cfgs[0], EGL_NATIVE_VISUAL_ID, &vid0);
	printf("厂商 EGL：共 %d 个 config，统一使用 config[0]=%p（其 EGL_NATIVE_VISUAL_ID=0x%x）\n\n",
	       n, (void *)cfgs[0], vid0);

	XVisualInfo tmpl;
	tmpl.screen = scr;
	XVisualInfo *vis = NULL;
	int nvis = 0;
	vis = XGetVisualInfo(dpy, VisualScreenMask, &tmpl, &nvis);

	printf("%-8s %-5s %-10s %-8s %-22s %s\n", "visual", "depth", "class", "surface",
	       "eglGetError", "渲染(glClear+swap)");
	int ok = 0, surfbad = 0;
	for (int i = 0; i < nvis; i++) {
		/* 命令行只测指定 visual */
		if (argc > 1) {
			int want = 0;
			for (int a = 1; a < argc; a++)
				if (strtoul(argv[a], NULL, 16) == vis[i].visualid) want = 1;
			if (!want) continue;
		}

		XSetWindowAttributes attr;
		memset(&attr, 0, sizeof(attr));
		attr.colormap = XCreateColormap(dpy, RootWindow(dpy, scr), vis[i].visual, AllocNone);
		attr.border_pixel = 0;
		attr.background_pixel = 0;
		Window w = XCreateWindow(dpy, RootWindow(dpy, scr), 0, 0, 64, 64, 0, vis[i].depth,
					 InputOutput, vis[i].visual,
					 CWColormap | CWBorderPixel | CWBackPixel, &attr);
		XSync(dpy, False);

		const char *cls = vis[i].class == TrueColor ? "TrueColor"
				: vis[i].class == DirectColor ? "DirectColor" : "other";
		char surfstr[16] = "-", errstr[32] = "-", rend[24] = "-";
		EGLSurface s = eglCreateWindowSurface(edpy, cfgs[0], (EGLNativeWindowType)w, NULL);
		if (s == EGL_NO_SURFACE) {
			EGLint e = eglGetError();
			snprintf(errstr, sizeof(errstr), "0x%x %s", e, eglErrStr(e));
			surfbad++;
		} else {
			snprintf(surfstr, sizeof(surfstr), "OK");
			EGLContext ctx = eglCreateContext(edpy, cfgs[0], EGL_NO_CONTEXT, NULL);
			if (ctx != EGL_NO_CONTEXT && eglMakeCurrent(edpy, s, s, ctx)) {
				glClearColor(0.2f, 0.6f, 0.2f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);
				if (eglSwapBuffers(edpy, s)) snprintf(rend, sizeof(rend), "OK");
				else snprintf(rend, sizeof(rend), "swap失败");
				eglMakeCurrent(edpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
				ok++;
			} else {
				snprintf(rend, sizeof(rend), "context失败");
			}
			if (ctx != EGL_NO_CONTEXT) eglDestroyContext(edpy, ctx);
			eglDestroySurface(edpy, s);
		}
		printf("  0x%-6lx %-5d %-10s %-8s %-22s %s\n", vis[i].visualid, vis[i].depth, cls,
		       surfstr, errstr, rend);

		XDestroyWindow(dpy, w);
		XFreeColormap(dpy, attr.colormap);
	}

	printf("\n小结: visual 总数 %d，surface 建立失败 %d，可完整渲染 %d\n", nvis, surfbad, ok);
	XFree(vis);
	eglTerminate(edpy);
	XCloseDisplay(dpy);
	return 0;
}
