/*
 * jm_gl_glx_path_test.c - GLX 路径下验证 glEGLImageTargetTexStorageEXT 是否可用
 *
 * 背景（README §9.6 遗留项）：EGL 上下文路径已实测通过；**GLX 上下文**下的
 * dmabuf→EGLImage 互操作在厂商栈上未验证 —— 上一版探针用 jmgpu dumb buffer
 * 造 image 时，连已知可用的 OES 入口都会崩（疑似 image 来源/对象表不匹配），
 * 因此无法据此判断 storage 入口。
 *
 * 本探针改用**真实来源**：libva 建 surface → vaExportSurfaceHandle(DRM_PRIME_2)
 * 导出 dmabuf → 厂商 EGL 包成 EGLImage → GLX 上下文里绑定到纹理。
 * 这正是 mpv / VA-API 直通的真实数据流。
 *
 * 用法（**建议 A/B 分进程跑**，任一崩掉也能各自取证）：
 *   LIBVA_DRIVER_NAME=jmgpu __GLX_VENDOR_LIBRARY_NAME=mwv207 \
 *     DISPLAY=:N XAUTHORITY=... /tmp/x oes       # 只测 A（基准，应成功）
 *   LIBVA_DRIVER_NAME=jmgpu __GLX_VENDOR_LIBRARY_NAME=mwv207 \
 *     DISPLAY=:N XAUTHORITY=... /tmp/x storage   # 只测 B（本补丁目标）
 *   ... /tmp/x both        # 顺序跑 A、B（happy path）
 *   ... /tmp/x errcheck    # 不需要合法 image：用 NULL image 对比 GL 错误码
 *
 * 编译：
 *   gcc -O2 -I/usr/include/libdrm -o /tmp/jm_glx jm_gl_glx_path_test.c \
 *       -lva -lva-drm -lEGL -lGL -lX11 -ldrm -ldl
 *
 * 判据：B 的 level0 应等于 surface 尺寸（= A 的结果）；若为 0x0 说明入口仍是
 * glvnd 空桩。errcheck 判据：厂商实现会置 GL 错误，空桩不会。
 */
#define _GNU_SOURCE
#define EGL_EGLEXT_PROTOTYPES
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <va/va.h>
#include <va/va_drm.h>
#include <va/va_drmcommon.h>
#include <xf86drm.h>

#define W 256
#define H 128

#define FMT_ARGB8888 0x34325241u	/* 'AR24' */
#define FMT_R8       0x20203852u	/* 'R8  ' */
#define FMT_GR88     0x38385247u	/* 'GR88' */

typedef void (*PFN_TEX2DOES)(GLenum, GLeglImageOES);
typedef void (*PFN_TEXSTORAGE)(GLenum, GLeglImageOES, const GLint *);

static Display *xdpy;
static GLXContext glctx;
static Window win;

static int setup_va(VADisplay *out_dpy, VASurfaceID *out_sid,
		    VADRMPRIMESurfaceDescriptor *d, int *out_fmt)
{
	const char *node = getenv("PROBE_NODE") ? getenv("PROBE_NODE")
						: "/dev/dri/renderD128";
	VADisplay dpy;
	VAStatus st;
	int major = 0, minor = 0, fd;
	VASurfaceID sid = VA_INVALID_SURFACE;

	fd = open(node, O_RDWR);
	if (fd < 0) {
		perror("open render node");
		return -1;
	}
	dpy = vaGetDisplayDRM(fd);
	if (!dpy) {
		fprintf(stderr, "vaGetDisplayDRM failed\n");
		return -1;
	}
	st = vaInitialize(dpy, &major, &minor);
	if (st != VA_STATUS_SUCCESS) {
		fprintf(stderr, "vaInitialize: %s (%d)\n", vaErrorStr(st), st);
		return -1;
	}
	printf("VA %d.%d driver=%s\n", major, minor, vaQueryVendorString(dpy));

	/*
	 * 优先 NV12（双平面 R8 + GR88）——实测 jmgpu VA 只允许导出视频面，
	 * RGB32 面 vaExportSurfaceHandle 会返回 invalid VASurfaceID。
	 */
	st = vaCreateSurfaces(dpy, VA_RT_FORMAT_YUV420, W, H, &sid, 1, NULL, 0);
	if (st == VA_STATUS_SUCCESS) {
		*out_fmt = 1;
	} else {
		st = vaCreateSurfaces(dpy, VA_RT_FORMAT_RGB32, W, H, &sid, 1,
				      NULL, 0);
		if (st != VA_STATUS_SUCCESS) {
			fprintf(stderr, "vaCreateSurfaces: %s (%d)\n",
				vaErrorStr(st), st);
			return -1;
		}
		*out_fmt = 0;
	}
	printf("VA surface %#x %dx%d (%s)\n", sid, W, H,
	       *out_fmt ? "NV12/2-plane" : "RGB32/1-plane");

	/*
	 * jmgpu VA 的 surface dmabuf 是**懒分配**的：直接 vaExportSurfaceHandle
	 * 会返回 invalid VASurfaceID。先用 vaPutImage 走一次（与
	 * va_export_probe.c 一致）把 backing 存储落实。
	 */
	{
		VAImage vimg;
		VAImageFormat fmt;
		void *map = NULL;

		memset(&fmt, 0, sizeof(fmt));
		fmt.fourcc = *out_fmt ? VA_FOURCC_NV12 : VA_FOURCC_ARGB;
		memset(&vimg, 0, sizeof(vimg));
		st = vaCreateImage(dpy, &fmt, W, H, &vimg);
		if (st != VA_STATUS_SUCCESS) {
			fprintf(stderr, "vaCreateImage: %s (%d)\n",
				vaErrorStr(st), st);
			return -1;
		}
		st = vaMapBuffer(dpy, vimg.buf, &map);
		if (st == VA_STATUS_SUCCESS && map) {
			memset(map, 0x40, vimg.data_size);
			vaUnmapBuffer(dpy, vimg.buf);
		}
		st = vaPutImage(dpy, sid, vimg.image_id, 0, 0, W, H, 0, 0, W, H);
		printf("vaPutImage -> %s (%d)\n", vaErrorStr(st), st);
		vaSyncSurface(dpy, sid);
		vaDestroyImage(dpy, vimg.image_id);
	}

	memset(d, 0, sizeof(*d));
	st = vaExportSurfaceHandle(dpy, sid,
				   VA_SURFACE_ATTRIB_MEM_TYPE_DRM_PRIME_2,
				   VA_EXPORT_SURFACE_READ_ONLY, d);
	if (st != VA_STATUS_SUCCESS) {
		fprintf(stderr, "vaExportSurfaceHandle: %s (%d)\n",
			vaErrorStr(st), st);
		return -1;
	}
	printf("export: objects=%u layers=%u\n", d->num_objects, d->num_layers);
	{
		unsigned i, p;

		for (i = 0; i < d->num_layers && i < 4; i++) {
			printf("  layer[%u] fmt=0x%08x planes=%u", i,
			       d->layers[i].drm_format,
			       d->layers[i].num_planes);
			for (p = 0; p < d->layers[i].num_planes && p < 4; p++)
				printf(" obj=%u off=%u pitch=%u",
				       d->layers[i].object_index[p],
				       d->layers[i].offset[p],
				       d->layers[i].pitch[p]);
			printf("\n");
		}
	}

	*out_dpy = dpy;
	*out_sid = sid;
	return 0;
}

static int make_egl_image(EGLDisplay edpy, VADRMPRIMESurfaceDescriptor *d,
			  int nv12, EGLImage *out)
{
	PFNEGLCREATEIMAGEKHRPROC create_image =
		(PFNEGLCREATEIMAGEKHRPROC)eglGetProcAddress("eglCreateImageKHR");
	EGLint attribs[40];
	int n = 0;
	/*
	 * jmgpu 的 NV12 描述符是 **2 个 layer、每 layer 1 个 plane**：
	 *   layer0 = DRM_FORMAT_R8   (Y 平面)
	 *   layer1 = DRM_FORMAT_GR88 (UV 平面)
	 * 所以 plane0 取 layer0、plane1 取 layer1（与 mpv 的
	 * dmabuf_interop_egl 一致），不能按"单 layer 双 plane"去取。
	 */
	unsigned l0o = d->layers[0].object_index[0];
	unsigned l1o = d->num_layers > 1 ? d->layers[1].object_index[0] : l0o;

	if (!create_image) {
		fprintf(stderr, "no eglCreateImageKHR\n");
		return -1;
	}
	if (nv12 && d->num_layers < 2) {
		fprintf(stderr, "NV12 但只有 %u 个 layer，无法描述 UV 平面\n",
			d->num_layers);
		return -1;
	}
	attribs[n++] = EGL_WIDTH;
	attribs[n++] = W;
	attribs[n++] = EGL_HEIGHT;
	attribs[n++] = H;
	attribs[n++] = EGL_LINUX_DRM_FOURCC_EXT;
	attribs[n++] = nv12 ? (EGLint)FMT_R8 : (EGLint)FMT_ARGB8888;
	attribs[n++] = EGL_DMA_BUF_PLANE0_FD_EXT;
	attribs[n++] = d->objects[l0o].fd;
	attribs[n++] = EGL_DMA_BUF_PLANE0_OFFSET_EXT;
	attribs[n++] = (EGLint)d->layers[0].offset[0];
	attribs[n++] = EGL_DMA_BUF_PLANE0_PITCH_EXT;
	attribs[n++] = (EGLint)d->layers[0].pitch[0];
	attribs[n++] = EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT;
	attribs[n++] = 0;
	attribs[n++] = EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT;
	attribs[n++] = 0;
	if (nv12) {
		attribs[n++] = EGL_DMA_BUF_PLANE1_FD_EXT;
		attribs[n++] = d->objects[l1o].fd;
		attribs[n++] = EGL_DMA_BUF_PLANE1_OFFSET_EXT;
		attribs[n++] = (EGLint)d->layers[1].offset[0];
		attribs[n++] = EGL_DMA_BUF_PLANE1_PITCH_EXT;
		attribs[n++] = (EGLint)d->layers[1].pitch[0];
		attribs[n++] = EGL_DMA_BUF_PLANE1_MODIFIER_LO_EXT;
		attribs[n++] = 0;
		attribs[n++] = EGL_DMA_BUF_PLANE1_MODIFIER_HI_EXT;
		attribs[n++] = 0;
	}
	attribs[n++] = EGL_NONE;

	*out = create_image(edpy, EGL_NO_CONTEXT, EGL_LINUX_DMA_BUF_EXT, NULL,
			    attribs);
	if (*out == EGL_NO_IMAGE_KHR) {
		fprintf(stderr, "eglCreateImageKHR failed: %#x\n",
			eglGetError());
		return -1;
	}
	return 0;
}

static void report(const char *tag)
{
	GLint w = -1, h = -1;
	GLenum err = glGetError();

	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
	printf("  %-34s level0=%dx%d  err=%#x\n", tag, w, h, err);
}

int main(int argc, char **argv)
{
	const char *mode = argc > 1 ? argv[1] : "both";
	VADisplay vdpy = NULL;
	VASurfaceID sid = VA_INVALID_SURFACE;
	VADRMPRIMESurfaceDescriptor desc;
	int nv12 = 0;
	EGLDisplay edpy;
	EGLImage img = EGL_NO_IMAGE_KHR;
	PFN_TEX2DOES oes;
	PFN_TEXSTORAGE storage;
	GLuint tex;
	const char *ext;
	int screen;
	GLXFBConfig *cfg;
	XVisualInfo *vi;
	Colormap cmap;
	XSetWindowAttributes swa;
	int ncfg = 0, glx_major = 0, glx_minor = 0;

	setvbuf(stdout, NULL, _IONBF, 0);
	if (setup_va(&vdpy, &sid, &desc, &nv12))
		return 1;

	xdpy = XOpenDisplay(NULL);
	if (!xdpy) {
		fprintf(stderr, "XOpenDisplay failed\n");
		return 1;
	}
	screen = DefaultScreen(xdpy);
	glXQueryVersion(xdpy, &glx_major, &glx_minor);
	printf("GLX %d.%d  vendor=%s\n", glx_major, glx_minor,
	       glXGetClientString(xdpy, GLX_VENDOR));

	cfg = glXChooseFBConfig(xdpy, screen, NULL, &ncfg);
	if (!cfg || !ncfg) {
		fprintf(stderr, "no FBConfig\n");
		return 1;
	}
	vi = glXGetVisualFromFBConfig(xdpy, cfg[0]);
	cmap = XCreateColormap(xdpy, RootWindow(xdpy, vi->screen), vi->visual,
			       AllocNone);
	swa.colormap = cmap;
	swa.event_mask = StructureNotifyMask;
	win = XCreateWindow(xdpy, RootWindow(xdpy, screen), 0, 0, 64, 64, 0,
			    vi->depth, InputOutput, vi->visual,
			    CWColormap | CWEventMask, &swa);
	XMapWindow(xdpy, win);		/* 必须 map，否则部分厂商路径拿不到 drawable */
	XSync(xdpy, False);

	glctx = glXCreateContext(xdpy, vi, NULL, True);
	if (!glctx || !glXMakeCurrent(xdpy, win, glctx)) {
		fprintf(stderr, "GLX context failed\n");
		return 1;
	}
	printf("GLX direct=%d  GL_VENDOR=%s  renderer=%s\n",
	       glXIsDirect(xdpy, glctx), (const char *)glGetString(GL_VENDOR),
	       (const char *)glGetString(GL_RENDERER));
	ext = (const char *)glGetString(GL_EXTENSIONS);
	printf("advertised storage=%s  OES=%s\n",
	       (ext && strstr(ext, "GL_EXT_EGL_image_storage")) ? "YES" : "NO",
	       (ext && strstr(ext, "GL_OES_EGL_image")) ? "YES" : "NO");

	edpy = eglGetDisplay((EGLNativeDisplayType)xdpy);
	if (edpy == EGL_NO_DISPLAY || !eglInitialize(edpy, NULL, NULL)) {
		fprintf(stderr, "EGL init failed\n");
		return 1;
	}

	if (strcmp(mode, "errcheck") != 0) {
		if (make_egl_image(edpy, &desc, nv12, &img))
			return 1;
		printf("EGLImage ok\n");
	}

	oes = (PFN_TEX2DOES)glXGetProcAddressARB(
		(const GLubyte *)"glEGLImageTargetTexture2DOES");
	storage = (PFN_TEXSTORAGE)glXGetProcAddressARB(
		(const GLubyte *)"glEGLImageTargetTexStorageEXT");
	printf("proc: OES=%p storage=%p\n", (void *)oes, (void *)storage);

	if (!strcmp(mode, "oes") || !strcmp(mode, "both")) {
		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		while (glGetError() != GL_NO_ERROR)
			;
		printf("  [A] call OES...\n");
		if (oes)
			oes(GL_TEXTURE_2D, img);
		report("A) glEGLImageTargetTexture2DOES");
	}
	if (!strcmp(mode, "storage") || !strcmp(mode, "both")) {
		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		while (glGetError() != GL_NO_ERROR)
			;
		printf("  [B] call storage...\n");
		if (storage)
			storage(GL_TEXTURE_2D, img, NULL);
		report("B) glEGLImageTargetTexStorageEXT");
	}
	if (!strcmp(mode, "errcheck")) {
		/*
		 * 不依赖合法 image 的判别法：厂商实现会校验参数并置 GL 错误，
		 * glvnd 空桩则什么都不做（错误保持 GL_NO_ERROR）。
		 * 分进程跑，万一厂商实现直接解引用崩溃也能单独取证。
		 */
		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		while (glGetError() != GL_NO_ERROR)
			;
		printf("  [E] call storage(target, NULL, NULL)...\n");
		if (storage)
			storage(GL_TEXTURE_2D, (GLeglImageOES)0, NULL);
		report("E) storage(NULL image)");

		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		while (glGetError() != GL_NO_ERROR)
			;
		printf("  [F] call OES(target, NULL)  (基准)...\n");
		if (oes)
			oes(GL_TEXTURE_2D, (GLeglImageOES)0);
		report("F) OES(NULL image)");
	}

	printf("== done ==\n");
	return 0;
}
