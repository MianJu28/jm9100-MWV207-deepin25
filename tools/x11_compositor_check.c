/*
 * 由 /tmp/cmcheck.c 固化（2026-10-08）。编译：gcc -O2 -o cmcheck x11_compositor_check.c -lX11
 * 注意：xprop -root _NET_WM_CM_S0 查不到不代表没有合成器（那是 selection 而非属性）。
 * cmcheck —— 正确检查 X 合成管理器（Composite Manager）是否在接管
 *
 * 说明：`xprop -root _NET_WM_CM_S0` 查不到并不代表没有合成器 —— 该名字是
 * **selection owner**（XSetSelectionOwner），不是 root window 的属性。
 * 本程序用 XGetSelectionOwner() 正确判定。
 *
 * 用法: cmcheck [screen]   （默认 :0.0）
 */
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	Display *dpy = XOpenDisplay(argc > 1 ? argv[1] : NULL);
	int scr;
	Atom cm;
	Window owner;
	char name[64];

	if (!dpy) { fprintf(stderr, "无法打开 display\n"); return 1; }
	scr = DefaultScreen(dpy);

	snprintf(name, sizeof(name), "_NET_WM_CM_S%d", scr);
	cm = XInternAtom(dpy, name, False);
	owner = cm ? XGetSelectionOwner(dpy, cm) : None;

	printf("display = %s  screen = %d\n", DisplayString(dpy), scr);
	printf("原子 %s = %lu\n", name, (unsigned long)cm);
	printf("selection owner = 0x%lx  =>  %s\n", (unsigned long)owner,
	       owner != None ? "有合成器接管 ✓" : "无合成器 ✗");

	/* 附带：报告 root 上的 _NET_KDE_COMPOSITE_TOGGLING（KWin 特有） */
	{
		Atom t = XInternAtom(dpy, "_NET_KDE_COMPOSITE_TOGGLING", False);
		Atom type; int fmt; unsigned long n, after; unsigned char *data = NULL;
		if (t && XGetWindowProperty(dpy, DefaultRootWindow(dpy), t, 0, 4,
					    False, AnyPropertyType, &type, &fmt,
					    &n, &after, &data) == Success && data) {
			printf("_NET_KDE_COMPOSITE_TOGGLING = %ld\n", (long)*(long *)data);
			XFree(data);
		}
	}
	XCloseDisplay(dpy);
	return 0;
}
