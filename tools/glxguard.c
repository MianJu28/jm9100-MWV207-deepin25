/*
 * glxguard —— 厂商 jmgpu 用户态栈「悬垂 libglapi TLS 解引用」的守卫（v2）
 *
 * ── 背景（完整取证：README §8.6.1 / docs/VENDOR_FEEDBACK_PRESENTATION.md §10）──
 * 厂商 EGL 在「解绑」与「销毁上下文」后**不清**其内嵌 libglapi 的 TLS current context，
 * 留下悬垂指针；随后厂商 GLX 的 glXDestroyContext → dri3DestroyContext
 * → jmgpu_dri.so:jmDestroyContext 读取该 TLS 并直接解引用（只判 != NULL）
 * ⇒ SIGSEGV。受影响：GTK3/WebKit2GTK（EasyTier、MiniBrowser）。
 *
 * ── v1 的教训（重要）──
 * v1 用 mincore() 判"指针是否已不在任何映射中"。实测**不可靠**：
 *   悬垂场景一：对象在已 munmap 的池里 ⇒ mincore 报未映射 ⇒ 能拦（v1 曾通过）
 *   悬垂场景二：对象在**仍然映射**的池里（WebKit 实际形态）⇒ mincore 报已映射
 *               ⇒ 漏判 ⇒ 仍崩（实测 wkmin 复现器）
 * 结论：**"已映射" ≠ "对象有效"**，无法靠地址属性判定。
 *
 * ── v2 策略：按正确语义清除，不做猜测 ──
 * 业界语义（Mesa 同款）：一旦「当前上下文」被解绑或被销毁，glapi TLS 必须置空。
 * 于是在两个层面按该语义精确清除：
 *
 *   EGL 层（真正的源头）：
 *     eglMakeCurrent(*, EGL_NO_CONTEXT)  ⇒ 解绑 ⇒ 清 TLS
 *     eglDestroyContext(被销毁的==当前) ⇒ 清 TLS
 *   GLX 层（兜底，覆盖经 GLX 解绑/销毁的路径）：
 *     glXMakeCurrent(dpy, None, NULL)   ⇒ 清 TLS
 *     glXDestroyContext(被销毁的==当前) ⇒ 清 TLS
 *
 *   全部**只在调用成功后**、且**只清"当前上下文"**（销毁非当前上下文绝不动）。
 *   额外保留 mincore 兜底：销毁前若 TLS 指向已 unmapped 地址 ⇒ 也清（覆盖 v1 能拦的场景）。
 *   ⇒ 合法存活的当前上下文永不被误清；而任何"被释放的当前上下文"都会被清。
 *
 * ── 编译 / 使用 ──
 *   gcc -shared -fPIC -O2 -o glxguard.so glxguard.c -ldl
 *   LD_PRELOAD=/usr/local/lib/glxguard.so <程序>          # 诊断：JMGLXGUARD_VERBOSE=1
 *
 * ── 部署 ──
 *   tools/fix_easytier_glxguard.sh apply   （包装脚本注入 LD_PRELOAD，提权实例同样生效）
 *
 * ── 实测（2026-09-18，用 /tmp/wkmin 最小 WebKit 复现器 + 抓屏像素统计）──
 *   见 README §8.6.3。
 */
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <EGL/egl.h>
#include <GL/glx.h>

typedef void *(*getctx_t) (void);
typedef void (*setctx_t) (void *);

static getctx_t api_get_context;
static setctx_t api_set_context;
static long page_size;
static int verbose, inited;

/* ---- 原函数指针 ---- */
static void (*real_glXDestroyContext) (Display *, GLXContext);
static Bool (*real_glXMakeCurrent) (Display *, GLXDrawable, GLXContext);
static Bool (*real_glXMakeContextCurrent) (Display *, GLXDrawable, GLXDrawable, GLXContext);
static EGLBoolean (*real_eglMakeCurrent) (EGLDisplay, EGLSurface, EGLSurface, EGLContext);
static EGLBoolean (*real_eglDestroyContext) (EGLDisplay, EGLContext);

static void init_once(void)
{
	Dl_info di;

	real_glXDestroyContext = dlsym(RTLD_NEXT, "glXDestroyContext");
	real_glXMakeCurrent = dlsym(RTLD_NEXT, "glXMakeCurrent");
	real_glXMakeContextCurrent = dlsym(RTLD_NEXT, "glXMakeContextCurrent");
	real_eglMakeCurrent = dlsym(RTLD_NEXT, "eglMakeCurrent");
	real_eglDestroyContext = dlsym(RTLD_NEXT, "eglDestroyContext");
	api_get_context = (getctx_t) dlsym(RTLD_DEFAULT, "_glapi_get_context");
	api_set_context = (setctx_t) dlsym(RTLD_DEFAULT, "_glapi_set_context");
	page_size = sysconf(_SC_PAGESIZE);
	if (page_size <= 0)
		page_size = 4096;
	verbose = getenv("JMGLXGUARD_VERBOSE") != NULL;

	if (verbose) {
		fprintf(stderr,
			"[glxguard] glXDestroy=%p glXMakeCurrent=%p eglDestroy=%p eglMakeCurrent=%p\n",
			(void *)real_glXDestroyContext, (void *)real_glXMakeCurrent,
			(void *)real_eglDestroyContext, (void *)real_eglMakeCurrent);
		if (api_set_context && dladdr((void *)api_set_context, &di) && di.dli_fname)
			fprintf(stderr, "[glxguard] _glapi_set_context = %p (%s)\n",
				(void *)api_set_context, di.dli_fname);
	}
	inited = 1;
}

/* 仅当厂商那份 _glapi 存在时才动作（对纯 Mesa 进程完全透明） */
static int have_vendor_glapi(void)
{
	return api_get_context && api_set_context;
}

static void clear_tls(const char *why)
{
	void *cur;

	if (!have_vendor_glapi())
		return;
	cur = api_get_context();
	if (!cur)
		return;
	if (verbose)
		fprintf(stderr, "[glxguard] 清 TLS current=%p（%s）\n", cur, why);
	api_set_context(NULL);
}

/* 兜底：TLS 指向已 unmapped 的地址（真 munmap 型悬垂） */
static int tls_unmapped(void)
{
	unsigned char vec = 0;
	void *cur;
	uintptr_t a;

	if (!have_vendor_glapi())
		return 0;
	cur = api_get_context();
	if (!cur)
		return 0;
	a = (uintptr_t) cur & ~(uintptr_t) (page_size - 1);
	return mincore((void *)a, (size_t) page_size, &vec) != 0;
}

/* ============ GLX 层 ============ */
void glXDestroyContext(Display *dpy, GLXContext ctx)
{
	if (!inited)
		init_once();
	if (!real_glXDestroyContext)
		return;

	/* 销毁的正是当前上下文 ⇒ 销毁后 TLS 必须为空 */
	if (glXGetCurrentContext() == ctx)
		clear_tls("销毁 GLX 当前上下文");
	/* 兜底：TLS 指向已 unmapped 地址 */
	else if (tls_unmapped())
		clear_tls("TLS 指向未映射地址");

	real_glXDestroyContext(dpy, ctx);
}

Bool glXMakeCurrent(Display *dpy, GLXDrawable draw, GLXContext ctx)
{
	Bool r;

	if (!inited)
		init_once();
	if (!real_glXMakeCurrent)
		return 0;
	r = real_glXMakeCurrent(dpy, draw, ctx);
	if (ctx == NULL)
		clear_tls("glXMakeCurrent(None,NULL) 解绑");
	return r;
}

Bool glXMakeContextCurrent(Display *dpy, GLXDrawable draw, GLXDrawable read,
			   GLXContext ctx)
{
	Bool r;

	if (!inited)
		init_once();
	if (!real_glXMakeContextCurrent)
		return 0;
	r = real_glXMakeContextCurrent(dpy, draw, read, ctx);
	if (ctx == NULL)
		clear_tls("glXMakeContextCurrent(NULL) 解绑");
	return r;
}

/* ============ EGL 层（真正的源头）============ */
EGLBoolean eglMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read,
			  EGLContext ctx)
{
	EGLBoolean r;

	if (!inited)
		init_once();
	if (!real_eglMakeCurrent)
		return EGL_FALSE;
	r = real_eglMakeCurrent(dpy, draw, read, ctx);
	if (r == EGL_TRUE && ctx == EGL_NO_CONTEXT)
		clear_tls("eglMakeCurrent(NO_CONTEXT) 解绑");
	return r;
}

EGLBoolean eglDestroyContext(EGLDisplay dpy, EGLContext ctx)
{
	EGLBoolean r;
	int was_current;

	if (!inited)
		init_once();
	if (!real_eglDestroyContext)
		return 0;

	/* 必须在真销毁之前判断"它是不是当前上下文" */
	was_current = (eglGetCurrentContext() == ctx);
	r = real_eglDestroyContext(dpy, ctx);
	if (r == EGL_TRUE && was_current)
		clear_tls("销毁 EGL 当前上下文");
	return r;
}
