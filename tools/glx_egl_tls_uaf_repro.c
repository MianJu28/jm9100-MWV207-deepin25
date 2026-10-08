/*
 * glx_egl_tls_uaf_repro —— 厂商 jmgpu 用户态栈的确定性崩溃复现（给厂商的取证程序）
 *
 * ============================ 一句话结论 ============================
 * 厂商 EGL 路径在「解绑 / 销毁」上下文时**没有清理其内嵌 libglapi 的 TLS
 * current context**，留下悬垂指针；随后厂商 GLX 的 glXDestroyContext →
 * dri3DestroyContext → jmgpu_dri.so:jmDestroyContext 读取该 TLS 并直接解引用
 * （只判 != NULL，未校验有效性）⇒ SIGSEGV。
 *
 * 真实触发者：GTK3 / WebKit2GTK 应用（EasyTier、MiniBrowser 等）——它们的
 * GL 上下文创建走 glXCreateContextAttribsARB(3.2 core)，而进程里同时存在
 * EGL 路径（WebKit/GStreamer），于是踩中上述悬垂 TLS。
 *
 * ============================ 实测证据 ============================
 * 本程序阶段输出（厂商栈，__GLX_VENDOR_LIBRARY_NAME=mwv207）：
 *   03 after eglMakeCurrent          TLS current = 0xffff8ae01010   <- EGL 写入
 *   04 after eglMakeCurrent(NULL)    TLS current = 0xffff8ae01010   <- 解绑未清 ★
 *   05 after eglDestroyContext       TLS current = 0xffff8ae01010   <- 销毁后仍留着 ★★
 *   07 glXDestroyContext -> SIGSEGV
 * 崩溃现场（gdb / core）：
 *   #0 jmDestroyContext+56  jmgpu_dri.so   ldr x0,[x0,#376]   x0 不在任何映射内
 *   #1 dri3DestroyContext   libGLX_mwv207.so
 *   #2 glXDestroyContext    libGLX_mwv207.so
 * 反编译佐证：
 *   - libEGL_mwv207.so 中**无任何** _glapi_set_context / _glapi_get_context 引用
 *     ⇒ EGL 侧从不清理 TLS。
 *   - jmgpu_dri.so 的 _glapi_get/set_context 绑定到厂商自带的
 *     libGLX_mwv207.so 的 _glapi_*@@VERSION（非系统 libglapi.so.0）。
 *   - jmDestroyContext 中 [ctx,#376]/[ctx,#368] 访问均有 cbz 空指针检查，
 *     而 [current,#376]（current=_glapi_get_context()）**只判 != NULL**。
 *
 * ============================ 编译与运行 ============================
 *   gcc -O2 -o glx_egl_tls_uaf_repro glx_egl_tls_uaf_repro.c -lEGL -lGL -lX11 -ldl
 *
 *   # 复现（预期 SIGSEGV / 段错误）
 *   __GLX_VENDOR_LIBRARY_NAME=mwv207 DISPLAY=:0 ./glx_egl_tls_uaf_repro
 *   # 对照 1：跳过 EGL 阶段 ⇒ 不崩（证明 EGL 阶段是前置条件）
 *   __GLX_VENDOR_LIBRARY_NAME=mwv207 DISPLAY=:0 ./glx_egl_tls_uaf_repro --no-egl
 *   # 对照 2：EGL 改用 Mesa（GLX 仍用厂商）⇒ 不崩
 *   __GLX_VENDOR_LIBRARY_NAME=mwv207 \
 *   __EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/50_mesa.json \
 *   DISPLAY=:0 ./glx_egl_tls_uaf_repro
 *
 * ============================ 厂商侧修复建议 ============================
 *  1) libEGL_mwv207（或 DRI 驱动的 EGL 路径）在
 *     eglMakeCurrent(EGL_NO_CONTEXT) 与 eglDestroyContext() 中，
 *     必须调用其自带 libglapi 的 _glapi_set_context(NULL)。
 *  2) jmgpu_dri.so:jmDestroyContext 在解引用 current=[_glapi_get_context()]
 *     之前增加有效性防护（与同函数内其它字段的 cbz 检查保持一致），
 *     至少做到"悬垂即跳过"，不崩溃。
 *  3) 建议内部自查 EGL/GLX 共用同一份 libglapi 时，TLS 生命周期的唯一归属。
 */
#define _GNU_SOURCE
#include <X11/Xlib.h>
#include <EGL/egl.h>
#include <GL/glx.h>
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void *(*api_get) (void);
static void (*api_set) (void *);

static void trace(const char *tag)
{
	Dl_info di;
	void *v = api_get ? api_get() : NULL;

	printf("  %-34s TLS current = %p", tag, v);
	if (api_set && dladdr((void *)api_set, &di) && di.dli_fname)
		printf("   [%s]", strrchr(di.dli_fname, '/') + 1);
	printf("\n");
	fflush(stdout);
}

int main(int argc, char **argv)
{
	int no_egl = (argc > 1 && strcmp(argv[1], "--no-egl") == 0);
	Display *d;
	void *h;

	printf("== glx_egl_tls_uaf_repro ==\n");
	printf("GLX vendor env = %s\n", getenv("__GLX_VENDOR_LIBRARY_NAME") ? : "(default)");
	printf("EGL vendor env = %s\n", getenv("__EGL_VENDOR_LIBRARY_FILENAMES") ? : "(default order)");
	printf("mode          = %s\n\n", no_egl ? "跳过 EGL 阶段（对照）" : "EGL -> GLX（复现）");

	/* 取厂商自带 libglapi 的 _glapi_get/set_context（与 jmgpu_dri.so 绑定同一份） */
	h = dlopen("libGLX_mwv207.so.0", RTLD_NOW | RTLD_GLOBAL);
	if (h) {
		api_get = dlsym(h, "_glapi_get_context");
		api_set = dlsym(h, "_glapi_set_context");
	}
	printf("vendor _glapi_get_context=%p  _glapi_set_context=%p\n", (void *)api_get, (void *)api_set);
	trace("00 start");

	if (!no_egl) {
		EGLDisplay ed;
		EGLConfig ec;
		EGLContext ectx;
		EGLSurface pb;
		EGLint n = 0;
		static EGLint cfgattr[] = { EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
			EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
			EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8, EGL_NONE
		};
		static EGLint ctxattr[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
		static EGLint pbattr[] = { EGL_WIDTH, 64, EGL_HEIGHT, 64, EGL_NONE };

		ed = eglGetDisplay(EGL_DEFAULT_DISPLAY);
		if (!eglInitialize(ed, NULL, NULL)) {
			printf("  eglInitialize 失败\n");
			return 0;
		}
		printf("  EGL_VENDOR = %s\n", eglQueryString(ed, EGL_VENDOR));
		eglBindAPI(EGL_OPENGL_ES_API);
		if (!eglChooseConfig(ed, cfgattr, &ec, 1, &n) || n == 0) {
			printf("  无合适 EGLConfig\n");
			return 0;
		}
		ectx = eglCreateContext(ed, ec, EGL_NO_CONTEXT, ctxattr);
		pb = eglCreatePbufferSurface(ed, ec, pbattr);
		eglMakeCurrent(ed, pb, pb, ectx);
		trace("03 after eglMakeCurrent");
		eglMakeCurrent(ed, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		trace("04 after eglMakeCurrent(NULL)  <-- KEY");
		eglDestroySurface(ed, pb);
		eglDestroyContext(ed, ectx);
		trace("05 after eglDestroyContext     <-- KEY");
		eglTerminate(ed);
	} else {
		printf("  （跳过 EGL 阶段）\n");
	}

	/* 第二阶段：厂商 GLX 建 + 销毁（此处应崩溃） */
	d = XOpenDisplay(NULL);
	if (!d) {
		printf("  XOpenDisplay 失败\n");
		return 0;
	}
	{
		typedef GLXContext (*pf) (Display *, GLXFBConfig, GLXContext, Bool, const int *);
		int scr = DefaultScreen(d);
		static int fattr[] = { GLX_X_RENDERABLE, True, GLX_DRAWABLE_TYPE,
			GLX_WINDOW_BIT, GLX_RENDER_TYPE, GLX_RGBA_BIT, None };
		int n = 0;
		GLXFBConfig *cfg = glXChooseFBConfig(d, scr, fattr, &n);
		pf ca = (pf) glXGetProcAddressARB((const GLubyte *)"glXCreateContextAttribsARB");
		int at[] = { GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
			GLX_CONTEXT_MINOR_VERSION_ARB, 2,
			GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
			None
		};
		GLXContext c;

		if (!cfg || n == 0 || !ca) {
			printf("  GLX 初始化失败\n");
			return 0;
		}
		printf("\n  [GLX] glXCreateContextAttribsARB(3.2 core) ...\n");
		fflush(stdout);
		c = ca(d, cfg[0], NULL, True, at);
		printf("  glx ctx = %p\n", (void *)c);
		trace("06 after glXCreateContextAttribsARB");
		printf("  [GLX] glXDestroyContext —— 预期在此 SIGSEGV ...\n");
		fflush(stdout);
		glXDestroyContext(d, c);
		trace("07 after glXDestroyContext");
	}
	printf("\n未崩溃（对照/已修复）\n");
	return 0;
}
