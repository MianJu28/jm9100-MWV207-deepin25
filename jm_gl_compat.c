/*
 * jm_gl_compat.c -- 景嘉微 JM9100(mwv207) 用户态 GL 兼容层（LD_PRELOAD）
 *
 * 背景
 * ----
 * 见 purelive 仓库 docs/LINUX_JM9100_HWDECODE_AUDIT.md §10.1/§10.2 与
 * jm9100 仓库 README §3.3。景美闭源桌面 GL 的用户态实现存在两处不对称：
 *
 *   1. 声明了 GL_OES_EGL_image 且 glEGLImageTargetTexture2DOES 可用、能真正把
 *      dmabuf 挂到纹理上；
 *   2. 但**未声明** GL_EXT_EGL_image_storage，而 glEGLImageTargetTexStorageEXT
 *      这个入口「存在却不真正挂接 dmabuf」（README §3.3：纹理恒为全零）。
 *
 * 后果：走现代 storage 路径的客户端（mpv 的 vaapi_gl_mapper、Chromium 等）在
 * 桌面 GL 下会**主动拒绝** VA-API dmabuf 零拷贝 —— 要么回落 vaapi-copy（多一次
 * 回读，收益被搬运吃光），要么回落软解；而在 Mesa/llvmpipe 上更会**静默产出全零
 * 帧**（深绿绿屏）。此前只能给 mpv 打补丁（mpv_dmabuf_oes_image.patch），
 * 属于「逐应用修」。
 *
 * 本兼容层做的事（一次性覆盖所有应用，无需改应用）
 * -------------------------------------------------
 *   a) 把 GL_EXT_EGL_image_storage 加入扩展列表
 *      （glGetString(GL_EXTENSIONS) 与 glGetStringi 两条路径都覆盖，
 *        并把 glGetIntegerv(GL_NUM_EXTENSIONS) 的计数 +1）；
 *   b) 把 glEGLImageTargetTexStorageEXT() 转发到驱动**真正能用**的
 *      glEGLImageTargetTexture2DOES()（语义等价：两者都作用于「当前绑定的纹理」，
 *      且都属于 immutable storage；OES 入口正是 mpv 补丁采用的可行路径）；
 *   c) 通过 glXGetProcAddress(ARB) / eglGetProcAddress 也返回上述重定向，
 *      因为 epoxy / glad / GLEW 这类加载器**绕过动态链接器符号表**，
 *      只做 LD_PRELOAD 符号插入是抓不到它们的。
 *
 * 生效条件（防御式，只对景美栈生效）
 * ---------------------------------
 *   * GL_VENDOR 含 "Jingjia"；且
 *   * 真实存在 glEGLImageTargetTexture2DOES（能力判据，而非只看字符串）。
 *   其它 GPU / Mesa / llvmpipe 一律原样透传，不做任何改动。
 *
 * 开关
 * ----
 *   JMGPU_GL_COMPAT=0         关闭（默认开启）
 *   JMGPU_GL_COMPAT_DEBUG=1   打印兼容层日志
 *
 * 编译
 * ----
 *   gcc -O2 -Wall -Wextra -fPIC -shared -o /tmp/libjm_gl_compat.so \
 *       jm_gl_compat.c -ldl -lpthread
 *
 * 用法
 * ----
 *   LD_PRELOAD=/tmp/libjm_gl_compat.so LIBVA_DRIVER_NAME=jmgpu \
 *       mpv --vo=gpu --hwdec=vaapi 视频.mp4
 */

#define _GNU_SOURCE

#include <dlfcn.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- 只用到的 GL 常量/类型，自带声明以免依赖 GL 头文件 ---- */
typedef unsigned int GLenum;
typedef unsigned char GLubyte;
typedef unsigned int GLuint;
typedef int GLint;
typedef void *GLeglImageOES;

#define GL_VENDOR 0x1F00
#define GL_EXTENSIONS 0x1F03
#define GL_NUM_EXTENSIONS 0x821D

#define EXT_STORAGE "GL_EXT_EGL_image_storage"
#define VENDOR_TAG "Jingjia"

/* ---- 真实入口点 ---- */
typedef const GLubyte *(*PFN_glGetString)(GLenum name);
typedef const GLubyte *(*PFN_glGetStringi)(GLenum name, GLuint index);
typedef void (*PFN_glGetIntegerv)(GLenum pname, GLint *data);
typedef void (*PFN_glEGLImageTargetTexture2DOES)(GLenum target, GLeglImageOES image);
typedef void (*PFN_glEGLImageTargetTexStorageEXT)(GLenum target, GLeglImageOES image,
                                                  const GLint *attrib_list);
typedef void *(*PFN_glXGetProcAddress)(const GLubyte *name);
typedef void *(*PFN_eglGetProcAddress)(const char *name);

static void *g_egl_handle;
static PFN_eglGetProcAddress g_real_egl_get_proc;
static PFN_glXGetProcAddress g_real_glx_get_proc_arb;
static PFN_glXGetProcAddress g_real_glx_get_proc;
static PFN_glGetString g_real_gl_get_string;
static PFN_glGetStringi g_real_gl_get_string_i;
static PFN_glGetIntegerv g_real_gl_get_integerv;
static PFN_glEGLImageTargetTexture2DOES g_real_oes_image;
static PFN_glEGLImageTargetTexStorageEXT g_real_tex_storage;

static int g_compat = -1; /* -1=未判定  0=不介入  1=介入 */
static int g_debug;
static int g_inited;
static pthread_once_t g_once = PTHREAD_ONCE_INIT;

/* 增强后的 GL_EXTENSIONS 字符串缓存 */
static char *g_aug_buf;
static const char *g_aug_src;

/* ------------------------------------------------------------------ 工具 */

static int debugOn(void) {
  static int cached = -1;
  if (cached < 0) {
    const char *v = getenv("JMGPU_GL_COMPAT_DEBUG");
    cached = (v != NULL && v[0] != '\0' && strcmp(v, "0") != 0) ? 1 : 0;
  }
  return cached;
}

#define DBG(...)                                     \
  do {                                               \
    if (g_debug) fprintf(stderr, "jm-gl-compat: " __VA_ARGS__); \
  } while (0)

/* 按「空格分隔的整词」判断扩展是否存在，避免子串误判 */
static int hasToken(const char *list, const char *token) {
  size_t tlen;
  const char *p;

  if (list == NULL || token == NULL || *token == '\0') return 0;
  tlen = strlen(token);
  p = list;
  while ((p = strstr(p, token)) != NULL) {
    int left_ok = (p == list) || (p[-1] == ' ');
    char after = p[tlen];
    int right_ok = (after == '\0') || (after == ' ');
    if (left_ok && right_ok) return 1;
    p += tlen;
  }
  return 0;
}

/* 解析真实符号：优先 getProcAddress（glvnd 下扩展入口必须走这条），
 * 再退回动态链接器。 */
static void *resolveReal(const char *name) {
  void *p = NULL;

  if (g_real_egl_get_proc != NULL) p = g_real_egl_get_proc(name);
  if (p == NULL && g_real_glx_get_proc_arb != NULL) {
    p = g_real_glx_get_proc_arb((const GLubyte *)name);
  }
  if (p == NULL && g_real_glx_get_proc != NULL) {
    p = g_real_glx_get_proc((const GLubyte *)name);
  }
  if (p == NULL) p = dlsym(RTLD_NEXT, name);
  if (p == NULL) p = dlsym(RTLD_DEFAULT, name);
  return p;
}

static void initReal(void) {
  static const char *kEglNames[] = {"libEGL.so.1", "libEGL.so", NULL};
  int i;

  for (i = 0; kEglNames[i] != NULL && g_egl_handle == NULL; ++i) {
    /* RTLD_LOCAL：只借用 eglGetProcAddress，不污染应用的全局符号空间 */
    g_egl_handle = dlopen(kEglNames[i], RTLD_LAZY | RTLD_LOCAL);
  }
  if (g_egl_handle != NULL) {
    g_real_egl_get_proc = (PFN_eglGetProcAddress)dlsym(g_egl_handle, "eglGetProcAddress");
  }

  g_real_glx_get_proc_arb = (PFN_glXGetProcAddress)dlsym(RTLD_NEXT, "glXGetProcAddressARB");
  g_real_glx_get_proc = (PFN_glXGetProcAddress)dlsym(RTLD_NEXT, "glXGetProcAddress");

  g_real_gl_get_string = (PFN_glGetString)resolveReal("glGetString");
  g_real_gl_get_string_i = (PFN_glGetStringi)resolveReal("glGetStringi");
  g_real_gl_get_integerv = (PFN_glGetIntegerv)resolveReal("glGetIntegerv");
  g_real_oes_image =
      (PFN_glEGLImageTargetTexture2DOES)resolveReal("glEGLImageTargetTexture2DOES");
}

static void ensureReal(void) {
  if (g_inited) return;
  pthread_once(&g_once, initReal);
  g_inited = 1;
}

/* 兼容层是否应当介入：必须真的能用 OES 入口（能力判据），且厂商是景美 */
static int compatEnabled(void) {
  const GLubyte *vendor;

  if (g_compat >= 0) return g_compat;
  g_compat = 0;

  if (getenv("JMGPU_GL_COMPAT") != NULL && strcmp(getenv("JMGPU_GL_COMPAT"), "0") == 0) {
    DBG("disabled by JMGPU_GL_COMPAT=0\n");
    return 0;
  }
  if (g_real_gl_get_string == NULL) return 0;

  vendor = g_real_gl_get_string(GL_VENDOR);
  if (vendor == NULL || strstr((const char *)vendor, VENDOR_TAG) == NULL) return 0;

  if (g_real_oes_image == NULL) {
    g_real_oes_image =
        (PFN_glEGLImageTargetTexture2DOES)resolveReal("glEGLImageTargetTexture2DOES");
  }
  if (g_real_oes_image == NULL) {
    DBG("GL_VENDOR is %s but glEGLImageTargetTexture2DOES is missing; staying passive\n",
        (const char *)vendor);
    return 0;
  }

  g_compat = 1;
  DBG("active on vendor '%s'\n", (const char *)vendor);
  return 1;
}

/* ------------------------------------------------------------------ 扩展广告 */

static const GLubyte *augmentExtensions(const char *base) {
  size_t n;
  char *buf;

  if (hasToken(base, EXT_STORAGE)) return (const GLubyte *)base;
  if (g_aug_buf == NULL || g_aug_src != base) {
    n = strlen(base);
    buf = (char *)malloc(n + 1 + sizeof(EXT_STORAGE));
    if (buf == NULL) return (const GLubyte *)base;
    memcpy(buf, base, n);
    buf[n] = ' ';
    memcpy(buf + n + 1, EXT_STORAGE, sizeof(EXT_STORAGE)); /* 含结尾 NUL */
    free(g_aug_buf);
    g_aug_buf = buf;
    g_aug_src = base;
    DBG("advertising " EXT_STORAGE "\n");
  }
  return (const GLubyte *)g_aug_buf;
}

const GLubyte *glGetString(GLenum name) {
  const GLubyte *value;

  ensureReal();
  if (g_real_gl_get_string == NULL) return NULL;
  value = g_real_gl_get_string(name);
  if (name != GL_EXTENSIONS || value == NULL) return value;
  if (!compatEnabled()) return value;
  return augmentExtensions((const char *)value);
}

const GLubyte *glGetStringi(GLenum name, GLuint index) {
  GLint count = 0;

  ensureReal();
  if (g_real_gl_get_string_i == NULL) return NULL;
  if (name != GL_EXTENSIONS || !compatEnabled()) return g_real_gl_get_string_i(name, index);

  if (g_real_gl_get_integerv != NULL) g_real_gl_get_integerv(GL_NUM_EXTENSIONS, &count);
  if (count > 0 && (GLint)index == count) return (const GLubyte *)EXT_STORAGE;
  return g_real_gl_get_string_i(name, index);
}

void glGetIntegerv(GLenum pname, GLint *data) {
  ensureReal();
  if (g_real_gl_get_integerv == NULL) return;

  if (pname == GL_NUM_EXTENSIONS && data != NULL) {
    *data = 0;
    g_real_gl_get_integerv(pname, data);
    if (*data > 0 && compatEnabled()) *data += 1;
    return;
  }
  g_real_gl_get_integerv(pname, data);
}

/* ------------------------------------------------------------------ storage 重定向 */

void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image,
                                    const GLint *attrib_list);

void glEGLImageTargetTextureStorageEXT(GLenum target, GLeglImageOES image,
                                       const GLint *attrib_list) {
  glEGLImageTargetTexStorageEXT(target, image, attrib_list);
}

void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image,
                                    const GLint *attrib_list) {
  ensureReal();

  if (!compatEnabled()) {
    /* 非景美栈：尽量调用驱动真实的 storage 入口；没有就什么都不做 */
    if (g_real_tex_storage == NULL) {
      g_real_tex_storage =
          (PFN_glEGLImageTargetTexStorageEXT)resolveReal("glEGLImageTargetTexStorageEXT");
      if (g_real_tex_storage == glEGLImageTargetTexStorageEXT) g_real_tex_storage = NULL;
    }
    if (g_real_tex_storage != NULL) {
      g_real_tex_storage(target, image, attrib_list);
    } else {
      DBG("passive: no real glEGLImageTargetTexStorageEXT, call dropped\n");
    }
    return;
  }

  (void)attrib_list; /* OES 入口无 attrib 参数；mpv 补丁同样忽略它 */
  if (g_real_oes_image != NULL) {
    static int logged;
    if (!logged) {
      logged = 1;
      DBG("redirect glEGLImageTargetTexStorageEXT(target=0x%x) -> "
          "glEGLImageTargetTexture2DOES\n",
          target);
    }
    g_real_oes_image(target, image);
  } else {
    fprintf(stderr, "jm-gl-compat: no glEGLImageTargetTexture2DOES; call dropped\n");
  }
}

/* ------------------------------------------------------------------ 函数地址拦截 */

static void *overrideFor(const char *name) {
  if (name == NULL) return NULL;
  if (strcmp(name, "glEGLImageTargetTexStorageEXT") == 0) {
    return (void *)(PFN_glEGLImageTargetTexStorageEXT)glEGLImageTargetTexStorageEXT;
  }
  if (strcmp(name, "glEGLImageTargetTextureStorageEXT") == 0) {
    return (void *)(PFN_glEGLImageTargetTexStorageEXT)glEGLImageTargetTextureStorageEXT;
  }
  /* 关键：glxinfo / epoxy / glad / GLEW 等都用 getProcAddress 解析 GL 入口，
   * 只做 LD_PRELOAD 符号插入抓不到它们，扩展广告就会失效。 */
  if (strcmp(name, "glGetString") == 0) return (void *)glGetString;
  if (strcmp(name, "glGetStringi") == 0) return (void *)glGetStringi;
  if (strcmp(name, "glGetIntegerv") == 0) return (void *)glGetIntegerv;
  return NULL;
}

void *glXGetProcAddressARB(const GLubyte *name) {
  void *over;

  ensureReal();
  over = overrideFor((const char *)name);
  if (over != NULL) {
    DBG("intercept glXGetProcAddressARB(%s)\n", (const char *)name);
    return over;
  }
  if (g_real_glx_get_proc_arb != NULL) return g_real_glx_get_proc_arb(name);
  return dlsym(RTLD_NEXT, (const char *)name);
}

void *glXGetProcAddress(const GLubyte *name) {
  void *over;

  ensureReal();
  over = overrideFor((const char *)name);
  if (over != NULL) return over;
  if (g_real_glx_get_proc != NULL) return g_real_glx_get_proc(name);
  if (g_real_glx_get_proc_arb != NULL) return g_real_glx_get_proc_arb(name);
  return dlsym(RTLD_NEXT, (const char *)name);
}

void *eglGetProcAddress(const char *name) {
  void *over;

  ensureReal();
  over = overrideFor(name);
  if (over != NULL) {
    DBG("intercept eglGetProcAddress(%s)\n", name);
    return over;
  }
  if (g_real_egl_get_proc != NULL) return g_real_egl_get_proc(name);
  if (g_real_glx_get_proc_arb != NULL) return g_real_glx_get_proc_arb((const GLubyte *)name);
  return dlsym(RTLD_NEXT, name);
}

__attribute__((constructor)) static void jmGlCompatInit(void) {
  if (getenv("JMGPU_GL_COMPAT") != NULL && strcmp(getenv("JMGPU_GL_COMPAT"), "0") == 0) {
    return;
  }
  g_debug = debugOn();
  if (g_debug) fprintf(stderr, "jm-gl-compat: loaded (debug on)\n");
}
