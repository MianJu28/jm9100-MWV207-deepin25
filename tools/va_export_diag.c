/*
 * tools/va_export_diag.c -- LD_PRELOAD 诊断：拦截 vaExportSurfaceHandle，
 * 对比「导出 dmabuf 的 mmap 内容」与「同一 surface 的 vaGetImage 内容」。
 *
 * 目的：判定导出的 VIDMEM 节点是否就是解码器实际写入的那个节点。
 *   - 若 vaGetImage 非零而导出 mmap 全零 -> 导出节点与解码节点不一致（厂商侧）
 *   - 若两者都零                        -> surface 本身为空
 *
 * 构建：gcc -O2 -fPIC -shared -o /tmp/va_diag.so tools/va_export_diag.c -ldl
 * 使用：LIBVA_DRIVER_NAME=jmgpu LD_PRELOAD=/tmp/va_diag.so mpv --hwdec=vaapi ...
 */
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <va/va.h>
#include <va/va_drmcommon.h>

typedef VAStatus (*e_t)(VADisplay, VASurfaceID, uint32_t, uint32_t, void *);
typedef VAStatus (*g_t)(VADisplay, VASurfaceID, int, int, unsigned int,
			unsigned int, VAImageID);
typedef VAStatus (*ci_t)(VADisplay, VAImageFormat *, int, int, VAImage *);
typedef VAStatus (*mb_t)(VADisplay, VABufferID, void **);
typedef VAStatus (*ub_t)(VADisplay, VABufferID);
typedef VAStatus (*di_t)(VADisplay, VAImageID);

static e_t r;
static g_t p_get;
static ci_t p_ci;
static mb_t p_mb;
static ub_t p_ub;
static di_t p_di;
static int c;
static int cg;

static unsigned nz_of(const unsigned char *p, unsigned sz)
{
	unsigned n = 0, i;

	for (i = 0; i < sz; i += 512)
		n += !!p[i];
	return n;
}

static void check_getimage(VADisplay d, VASurfaceID s, unsigned w, unsigned h)
{
	VAImageFormat fmt;
	VAImage im;
	VAStatus st;
	void *buf = NULL;
	unsigned nz = -1u;

	if (++cg > 4)
		return;
	if (!p_get)
		return;

	memset(&fmt, 0, sizeof(fmt));
	fmt.fourcc = VA_FOURCC_NV12;
	memset(&im, 0, sizeof(im));
	st = p_ci(d, &fmt, (int)w, (int)h, &im);
	if (st)
		return;
	st = p_get(d, s, 0, 0, w, h, im.image_id);
	if (!st && p_mb(d, im.buf, &buf) == VA_STATUS_SUCCESS && buf) {
		unsigned char *b = buf;

		nz = nz_of(b, (unsigned)(w * h * 3 / 2));
		fprintf(stderr,
			"[vad]   vaGetImage(%ux%u) nz=%u/%u head=%02x %02x %02x %02x\n",
			w, h, nz, (unsigned)(w * h * 3 / 2) / 512 + 1, b[0], b[1],
			b[2], b[3]);
		p_ub(d, im.buf);
	}
	p_di(d, im.image_id);
}

VAStatus vaExportSurfaceHandle(VADisplay d, VASurfaceID s, uint32_t m,
			       uint32_t f, void *p)
{
	VAStatus st;

	if (!r)
		r = (e_t)dlsym(RTLD_NEXT, "vaExportSurfaceHandle");
	if (!p_get) {
		p_get = (g_t)dlsym(RTLD_NEXT, "vaGetImage");
		p_ci = (ci_t)dlsym(RTLD_NEXT, "vaCreateImage");
		p_mb = (mb_t)dlsym(RTLD_NEXT, "vaMapBuffer");
		p_ub = (ub_t)dlsym(RTLD_NEXT, "vaUnmapBuffer");
		p_di = (di_t)dlsym(RTLD_NEXT, "vaDestroyImage");
	}
	st = r(d, s, m, f, p);
	if (st || m != 0x40000000 || c >= 16)
		return st;
	c++;
	{
		VADRMPRIMESurfaceDescriptor *dd = (VADRMPRIMESurfaceDescriptor *)p;
		unsigned sz = dd->objects[0].size;
		unsigned char *mm = mmap(0, sz, 1, 1, dd->objects[0].fd, 0);

		if (mm == (void *)-1) {
			fprintf(stderr, "[vad]#%d mmap failed\n", c);
			return st;
		}
		fprintf(stderr,
			"[vad]#%d %c%c%c%c %dx%d sz=%u mmap_nz=%u\n", c,
			(char)(dd->fourcc & 0xff), (char)((dd->fourcc >> 8) & 0xff),
			(char)((dd->fourcc >> 16) & 0xff),
			(char)((dd->fourcc >> 24) & 0xff), dd->width, dd->height,
			sz, nz_of(mm, sz));
		munmap(mm, sz);
		if (dd->width >= 640)
			check_getimage(d, s, dd->width, dd->height);
	}
	return st;
}
