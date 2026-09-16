/* ext_dump.c - 打印 GL_EXTENSIONS 与 glGetStringi 计数，判断扩展表是否 NULL 终止 */
#define _GNU_SOURCE
#include <GL/gl.h>
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <string.h>
extern const unsigned char *glGetStringi(unsigned int, unsigned int);

int main(void)
{
	Display *dpy = XOpenDisplay(NULL);
	GLXFBConfig *fbcfg;
	XVisualInfo *vi;
	GLXContext ctx;
	Window win;
	Colormap cmap;
	XSetWindowAttributes swa;
	const char *ext;
	GLint n = -1, i;
	int screen, cnt = 0;

	if (!dpy)
		return 1;
	screen = DefaultScreen(dpy);
	fbcfg = glXChooseFBConfig(dpy, screen, NULL, &cnt);
	if (!fbcfg || !cnt)
		return 1;
	vi = glXGetVisualFromFBConfig(dpy, fbcfg[0]);
	cmap = XCreateColormap(dpy, RootWindow(dpy, vi->screen), vi->visual,
			       AllocNone);
	swa.colormap = cmap;
	swa.event_mask = 0;
	win = XCreateWindow(dpy, RootWindow(dpy, screen), 0, 0, 16, 16, 0,
			    vi->depth, InputOutput, vi->visual,
			    CWColormap | CWEventMask, &swa);
	ctx = glXCreateContext(dpy, vi, NULL, True);
	if (!ctx || !glXMakeCurrent(dpy, win, ctx))
		return 1;

	ext = (const char *)glGetString(GL_EXTENSIONS);
	if (ext) {
		int n_ext = 1;
		const char *p;
		for (p = ext; *p; p++)
			if (*p == ' ')
				n_ext++;
		printf("glGetString(GL_EXTENSIONS): %zu bytes, ~%d names\n",
		       strlen(ext), n_ext);
		printf("%s\n", ext);
	} else {
		printf("glGetString(GL_EXTENSIONS) = NULL\n");
	}
	glGetIntegerv(GL_NUM_EXTENSIONS, &n);
	printf("GL_NUM_EXTENSIONS = %d\n", n);
	for (i = 0; i < n; i++) {
		const char *s = (const char *)glGetStringi(GL_EXTENSIONS, i);
		if (!s)
			printf("  [%d] <NULL>\n", i);
	}
	/* 关键：表的最后几项是否可枚举到 205 */
	if (n > 0) {
		printf("last[%d] = %s\n", n - 1,
		       (const char *)glGetStringi(GL_EXTENSIONS, n - 1));
	}
	glXMakeCurrent(dpy, None, NULL);
	return 0;
}
