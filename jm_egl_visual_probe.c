/*
 * jm_egl_visual_probe.c -- 给出「哪些 X visual 能被景美 EGL 真正建出 window surface」
 *
 * 背景
 * ----
 * purelive 在硬件 GL 栈下窗口纯黑，引擎持续报
 *   [ERROR:flutter/.../embedder.cc(939)]  Could not wrap embedder supplied frame-buffer.
 *   [ERROR:flutter/.../embedder.cc(1538)] Could not create a surface from an embedder
 *                                         provided render target.
 * Flutter(GTK embedder) 最终是**用 EGL 给窗口建 surface**；而窗口的 visual 是应用
 * 侧按「32 位 ARGB 优先」挑的（本机为 0x7c）。景美 GLX/EGL 的 config 集合并不覆盖
 * 屏幕的全部 visual（审计 §10.1：GLX FBConfig 的 visual 只有 0x21/0x22/0x113…0x14c），
 * 于是 eglCreateWindowSurface 拿不到匹配 config → EGL_BAD_MATCH → 表面建不出来 → 黑窗。
 *
 * 应用侧现有探测（linux/jm9100_gl.cc）只验证 gdk_window_create_gl_context()（GLX 路径），
 * 没验证 EGL window surface —— 本探针补齐这一环，给出可直接用于选 visual 的实测表。
 *
 * 编译：gcc -O2 -Wall -o /tmp/jm_egl_visual_probe jm_egl_visual_probe.c -lEGL -lX11
 * 用法：./jm_egl_visual_probe                默认 DISPLAY
 *       DISPLAY=:0 ./jm_egl_visual_probe
 *       __EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/50_mesa.json \
 *           ./jm_egl_visual_probe              # 对照组：Mesa 软栈
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>

#define MAXCFG 256

typedef struct {
	unsigned long visual;
	int configs;
	EGLConfig first;
	int alpha;
	int buffer_size;
} VisualMap;

/* -a：逐个 dump 全部 EGL config 的关键属性。
 * 关键点在于对照 EGL_NATIVE_VISUAL_ID 与 EGL_NATIVE_VISUAL_TYPE：
 * 前者在 libEGL_mwv207 里是「显示级」调用（不读 config），后者读 config+48，
 * 因此前者对 40 个 config 恒定、后者才可能是每 config 独立值。 */
static void dumpConfigs(EGLDisplay edpy) {
	EGLConfig cfgs[MAXCFG];
	EGLint ncfg = 0;
	if (!eglGetConfigs(edpy, cfgs, MAXCFG, &ncfg)) {
		fprintf(stderr, "eglGetConfigs 失败\n");
		return;
	}
	printf("\n%-4s %-10s %-12s %-12s %-5s %-4s %-4s %-4s %-4s %-6s %-8s %-6s %s\n",
	       "#", "CONFIG_ID", "VISUAL_ID", "VISUAL_TYPE", "BUF", "R", "G", "B", "A",
	       "DEPTH", "STENCIL", "SAMPLES", "SURFACE_TYPE");
	for (int i = 0; i < ncfg; i++) {
		EGLint id, vid, vtype, bufsz, r, g, b, a, depth, stencil, samples, stype;
		eglGetConfigAttrib(edpy, cfgs[i], EGL_CONFIG_ID, &id);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_NATIVE_VISUAL_ID, &vid);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_NATIVE_VISUAL_TYPE, &vtype);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_BUFFER_SIZE, &bufsz);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_RED_SIZE, &r);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_GREEN_SIZE, &g);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_BLUE_SIZE, &b);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_ALPHA_SIZE, &a);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_DEPTH_SIZE, &depth);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_STENCIL_SIZE, &stencil);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_SAMPLES, &samples);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_SURFACE_TYPE, &stype);
		printf("%-4d 0x%-8x 0x%-10x 0x%-10x %-5d %-4d %-4d %-4d %-4d %-6d %-8d %-6d 0x%x\n",
		       i + 1, id, vid, vtype, bufsz, r, g, b, a, depth, stencil, samples,
		       stype);
	}
}

int main(int argc, char **argv) {
	Display *dpy = XOpenDisplay(NULL);
	if (dpy == NULL) {
		fprintf(stderr, "无法打开 X display（DISPLAY=%s）\n",
			getenv("DISPLAY") ? getenv("DISPLAY") : "(未设置)");
		return 1;
	}

	EGLDisplay edpy = EGL_NO_DISPLAY;
	PFNEGLGETPLATFORMDISPLAYEXTPROC get_platform =
		(PFNEGLGETPLATFORMDISPLAYEXTPROC)eglGetProcAddress("eglGetPlatformDisplayEXT");
	if (get_platform != NULL)
		edpy = get_platform(EGL_PLATFORM_X11_KHR, (void *)dpy, NULL);
	if (edpy == EGL_NO_DISPLAY)
		edpy = eglGetDisplay((EGLNativeDisplayType)dpy);
	if (edpy == EGL_NO_DISPLAY) {
		fprintf(stderr, "eglGetDisplay 失败\n");
		return 1;
	}

	EGLint major = 0, minor = 0;
	if (!eglInitialize(edpy, &major, &minor)) {
		fprintf(stderr, "eglInitialize 失败 (0x%x)\n", eglGetError());
		return 1;
	}

	printf("EGL_VENDOR  = %s\n", eglQueryString(edpy, EGL_VENDOR));
	printf("EGL_VERSION = %s\n", eglQueryString(edpy, EGL_VERSION));
	printf("EGL_CLIENT_APIS = %s\n", eglQueryString(edpy, EGL_CLIENT_APIS));
	printf("EGL_EXTENSIONS 含 EGL_EXT_platform_x11: %s\n",
	       (eglQueryString(edpy, EGL_EXTENSIONS) &&
		strstr(eglQueryString(edpy, EGL_EXTENSIONS), "EGL_EXT_platform_x11"))
		       ? "yes"
		       : "no");

	/* 收集 EGL config -> 各自的 X visual */
	EGLConfig cfgs[MAXCFG];
	EGLint ncfg = 0;
	if (!eglGetConfigs(edpy, cfgs, MAXCFG, &ncfg)) {
		fprintf(stderr, "eglGetConfigs 失败 (0x%x)\n", eglGetError());
		return 1;
	}

	VisualMap map[MAXCFG];
	int n = 0;
	for (int i = 0; i < ncfg && n < MAXCFG; i++) {
		EGLint vid = 0, alpha = 0, bufsz = 0;
		if (!eglGetConfigAttrib(edpy, cfgs[i], EGL_NATIVE_VISUAL_ID, &vid))
			continue;
		eglGetConfigAttrib(edpy, cfgs[i], EGL_ALPHA_SIZE, &alpha);
		eglGetConfigAttrib(edpy, cfgs[i], EGL_BUFFER_SIZE, &bufsz);
		int k = -1;
		for (int j = 0; j < n; j++)
			if (map[j].visual == (unsigned long)vid) { k = j; break; }
		if (k < 0) {
			k = n++;
			map[k].visual = (unsigned long)vid;
			map[k].configs = 0;
			map[k].first = cfgs[i];
			map[k].alpha = alpha;
			map[k].buffer_size = bufsz;
		}
		map[k].configs++;
	}

	printf("\nEGL 共 %d 个 config，覆盖 %d 个 X visual\n", ncfg, n);
	printf("屏幕 visual 覆盖情况：\n");
	printf("  %-8s %-6s %-10s %-12s %s\n", "visual", "depth", "class", "EGL config", "window surface");

	XVisualInfo tmpl;
	tmpl.screen = DefaultScreen(dpy);
	XVisualInfo *vis = NULL;
	int nvis = 0;
	vis = XGetVisualInfo(dpy, VisualScreenMask, &tmpl, &nvis);

	int ok_cnt = 0, cfg_missing = 0, surf_fail = 0;
	for (int i = 0; i < nvis; i++) {
		int k = -1;
		for (int j = 0; j < n; j++)
			if (map[j].visual == vis[i].visualid) { k = j; break; }

		const char *cls = vis[i].class == TrueColor ? "TrueColor"
				  : vis[i].class == DirectColor ? "DirectColor"
								: "other";
		char cfgstr[32] = "-";
		char surfstr[64] = "（无匹配 config，引擎必然失败）";
		if (k >= 0) {
			snprintf(cfgstr, sizeof(cfgstr), "%d个", map[k].configs);
			/* 用该 visual 真的建一个窗口，再建 EGL window surface */
			XSetWindowAttributes attr;
			memset(&attr, 0, sizeof(attr));
			attr.colormap = XCreateColormap(dpy, RootWindow(dpy, tmpl.screen),
							vis[i].visual, AllocNone);
			attr.border_pixel = 0;
			attr.background_pixel = 0;
			Window win = XCreateWindow(dpy, RootWindow(dpy, tmpl.screen),
						   0, 0, 64, 64, 0, vis[i].depth, InputOutput,
						   vis[i].visual, CWColormap | CWBorderPixel |
									  CWBackPixel,
						   &attr);
			XSync(dpy, False);
			if (win != 0) {
				EGLSurface s = eglCreateWindowSurface(
					edpy, map[k].first, (EGLNativeWindowType)win, NULL);
				if (s != EGL_NO_SURFACE) {
					snprintf(surfstr, sizeof(surfstr), "OK");
					ok_cnt++;
					eglDestroySurface(edpy, s);
				} else {
					snprintf(surfstr, sizeof(surfstr), "FAIL (eglError=0x%x)",
						 eglGetError());
					surf_fail++;
				}
				XDestroyWindow(dpy, win);
			}
			XFreeColormap(dpy, attr.colormap);
		} else {
			cfg_missing++;
		}
		printf("  0x%-6lx %-6d %-10s %-12s %s\n", vis[i].visualid, vis[i].depth,
		       cls, cfgstr, surfstr);
	}

	if (argc > 1 && strcmp(argv[1], "-a") == 0) dumpConfigs(edpy);

	printf("\n小结: visual 总数 %d，无 EGL config %d，有 config 但 surface 失败 %d，可用 %d\n",
	       nvis, cfg_missing, surf_fail, ok_cnt);

	/* 顺带给出默认屏幕 visual 的结论（应用探测优先 ARGB，往往落在这里之外） */
	printf("屏幕默认 visual = 0x%lx\n", DefaultVisual(dpy, tmpl.screen)->visualid);
	printf("\n提示: 应用侧选 visual 时，应只接受上表里 window surface 为 OK 的那些。\n");

	XFree(vis);
	eglTerminate(edpy);
	XCloseDisplay(dpy);
	return ok_cnt > 0 ? 0 : 2;
}
