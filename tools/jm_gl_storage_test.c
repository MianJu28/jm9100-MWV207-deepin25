/*
 * tools/jm_gl_storage_test.c - 端到端验证 GL_EXT_EGL_image_storage 是否原生可用
 *
 * 与 v1 的区别：GL 上下文改用 **EGL** 创建（pbuffer surface），让 EGLImage
 * 和 GL 上下文走同一套 EGL 对象表 —— 厂商实现需要这一点（用 GLX 上下文 +
 * EGL 创建的 image 会在 OES 路径就崩，属测试环境问题，不是驱动缺陷）。
 *
 * 流程：
 *   1. jmgpu 内核驱动分配 dumb buffer → 导出 dmabuf
 *   2. 厂商 EGL 把它包成 EGLImage
 *   3. 用 glXGetProcAddressARB 取两个入口（这正是本补丁修的路径）：
 *        A) glEGLImageTargetTexture2DOES      （GL_OES_EGL_image，已知可用）
 *        B) glEGLImageTargetTexStorageEXT     （GL_EXT_EGL_image_storage）
 *   4. 各自绑定到全新纹理，检查 GL_TEXTURE_WIDTH/HEIGHT
 *
 * 编译：
 *   gcc -O2 -I/usr/include/libdrm -o /tmp/gl_storage_test tools/jm_gl_storage_test.c \
 *       -lGL -lEGL -lX11 -ldrm -ldl
 * 运行：
 *   DISPLAY=:N XAUTHORITY=... __GLX_VENDOR_LIBRARY_NAME=mwv207 \
 *     __EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/10_mwv207.json \
 *     /tmp/gl_storage_test
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
#include <string.h>
#include <unistd.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

#define WIDTH  256
#define HEIGHT 128
#define FOURCC_ARGB8888 0x34325241

typedef void (*PFN_TEX2DOES)(GLenum, GLeglImageOES);
typedef void (*PFN_TEXSTORAGE)(GLenum, GLeglImageOES, const GLint *);

static EGLDisplay edpy;
static EGLContext ectx;

static int setup_egl(Display *dpy)
{
	EGLint major = 0, minor = 0;
	EGLint cfg_attribs[] = {
		EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
		EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
		EGL_NONE
	};
	EGLConfig cfg;
	EGLint ncfg = 0;
	EGLSurface surf;
	EGLint pb[] = { EGL_WIDTH, 16, EGL_HEIGHT, 16, EGL_NONE };

	edpy = eglGetDisplay((EGLNativeDisplayType)dpy);
	if (edpy == EGL_NO_DISPLAY) {
		fprintf(stderr, "eglGetDisplay failed\n");
		return -1;
	}
	if (!eglInitialize(edpy, &major, &minor)) {
		fprintf(stderr, "eglInitialize failed %#x\n", eglGetError());
		return -1;
	}
	printf("EGL %d.%d vendor=%s\n", major, minor,
	       eglQueryString(edpy, EGL_VENDOR));

	if (!eglBindAPI(EGL_OPENGL_API)) {
		fprintf(stderr, "eglBindAPI(OpenGL) failed %#x\n", eglGetError());
		return -1;
	}
	if (!eglChooseConfig(edpy, cfg_attribs, &cfg, 1, &ncfg) || ncfg < 1) {
		fprintf(stderr, "eglChooseConfig failed %#x\n", eglGetError());
		return -1;
	}
	surf = eglCreatePbufferSurface(edpy, cfg, pb);
	if (surf == EGL_NO_SURFACE) {
		fprintf(stderr, "eglCreatePbufferSurface failed %#x\n",
			eglGetError());
		return -1;
	}
	ectx = eglCreateContext(edpy, cfg, EGL_NO_CONTEXT, NULL);
	if (ectx == EGL_NO_CONTEXT) {
		fprintf(stderr, "eglCreateContext failed %#x\n", eglGetError());
		return -1;
	}
	if (!eglMakeCurrent(edpy, surf, surf, ectx)) {
		fprintf(stderr, "eglMakeCurrent failed %#x\n", eglGetError());
		return -1;
	}
	printf("GL_VENDOR   = %s\n", (const char *)glGetString(GL_VENDOR));
	printf("GL_RENDERER = %s\n", (const char *)glGetString(GL_RENDERER));
	return 0;
}

static int make_dmabuf(int *out_fd, unsigned int *out_pitch)
{
	int fd = open("/dev/dri/card0", O_RDWR | O_CLOEXEC);
	struct drm_mode_create_dumb cd = { 0 };
	struct drm_prime_handle ph = { 0 };

	if (fd < 0) {
		perror("open /dev/dri/card0");
		return -1;
	}
	cd.width = WIDTH;
	cd.height = HEIGHT;
	cd.bpp = 32;
	if (drmIoctl(fd, DRM_IOCTL_MODE_CREATE_DUMB, &cd)) {
		perror("CREATE_DUMB");
		close(fd);
		return -1;
	}
	ph.handle = cd.handle;
	ph.flags = DRM_CLOEXEC | DRM_RDWR;
	if (drmIoctl(fd, DRM_IOCTL_PRIME_HANDLE_TO_FD, &ph)) {
		perror("PRIME_HANDLE_TO_FD");
		close(fd);
		return -1;
	}
	printf("[dmabuf] handle=%u pitch=%u size=%u fd=%d\n", cd.handle,
	       cd.pitch, cd.size, ph.fd);
	*out_fd = ph.fd;
	*out_pitch = cd.pitch;
	close(fd);
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

int main(void)
{
	Display *dpy = XOpenDisplay(NULL);
	PFN_TEX2DOES oes;
	PFN_TEXSTORAGE storage;
	EGLImage img;
	int fdm = -1;
	unsigned int pitch = 0;
	GLuint tex;
	const char *ext;

	setvbuf(stdout, NULL, _IONBF, 0);
	if (!dpy) {
		fprintf(stderr, "XOpenDisplay failed\n");
		return 1;
	}
	if (setup_egl(dpy))
		return 1;

	ext = (const char *)glGetString(GL_EXTENSIONS);
	printf("GL_EXT_EGL_image_storage advertised = %s\n",
	       (ext && strstr(ext, "GL_EXT_EGL_image_storage")) ? "YES" : "NO");
	printf("GL_OES_EGL_image advertised         = %s\n",
	       (ext && strstr(ext, "GL_OES_EGL_image")) ? "YES" : "NO");

	if (make_dmabuf(&fdm, &pitch))
		return 1;

	{
		PFNEGLCREATEIMAGEKHRPROC create_image =
			(PFNEGLCREATEIMAGEKHRPROC)eglGetProcAddress(
				"eglCreateImageKHR");
		EGLint attribs[] = {
			EGL_WIDTH, WIDTH,
			EGL_HEIGHT, HEIGHT,
			EGL_LINUX_DRM_FOURCC_EXT, FOURCC_ARGB8888,
			EGL_DMA_BUF_PLANE0_FD_EXT, fdm,
			EGL_DMA_BUF_PLANE0_OFFSET_EXT, 0,
			EGL_DMA_BUF_PLANE0_PITCH_EXT, (EGLint)pitch,
			EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT, 0,	/* LINEAR */
			EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT, 0,
			EGL_NONE
		};

		if (!create_image) {
			fprintf(stderr, "no eglCreateImageKHR\n");
			return 1;
		}
		img = create_image(edpy, EGL_NO_CONTEXT, EGL_LINUX_DMA_BUF_EXT,
				   NULL, attribs);
	}
	if (img == EGL_NO_IMAGE_KHR) {
		fprintf(stderr, "eglCreateImageKHR failed %#x\n", eglGetError());
		return 1;
	}
	printf("[eglimg] EGLImage ok (%dx%d)\n", WIDTH, HEIGHT);

	oes = (PFN_TEX2DOES)glXGetProcAddressARB(
		(const GLubyte *)"glEGLImageTargetTexture2DOES");
	storage = (PFN_TEXSTORAGE)glXGetProcAddressARB(
		(const GLubyte *)"glEGLImageTargetTexStorageEXT");
	printf("[proc ] OES=%p storage=%p\n", (void *)oes, (void *)storage);

	printf("\n== A/B 对照（各自全新纹理）==\n");

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	while (glGetError() != GL_NO_ERROR)
		;
	if (oes) {
		oes(GL_TEXTURE_2D, img);
		report("A) glEGLImageTargetTexture2DOES");
	} else {
		printf("  A) OES 入口为 NULL\n");
	}

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	while (glGetError() != GL_NO_ERROR)
		;
	if (storage) {
		storage(GL_TEXTURE_2D, img, NULL);
		report("B) glEGLImageTargetTexStorageEXT");
	} else {
		printf("  B) storage 入口为 NULL\n");
	}

	printf("\n判据：B 的 level0 应为 %dx%d（= 空桩的话是 0x0）\n",
	       WIDTH, HEIGHT);
	eglMakeCurrent(edpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
	XCloseDisplay(dpy);
	return 0;
}
