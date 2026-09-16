/*
 * tools/va_export_probe.c -- VA-API PRIME_2 导出链数据保真度探针
 *
 * 目的：区分「内核 dmabuf 导出/mmap 地址算错」与「解码输出不落在 surface 节点」。
 * 对照组 A：vaPutImage 由 CPU 写入已知图案后导出并检查内容。
 *
 * 用法：
 *   gcc -O2 -o /tmp/va_export_probe tools/va_export_probe.c -lva -lva-drm
 *   LIBVA_DRIVER_NAME=jmgpu /tmp/va_export_probe [w h]
 * 环境变量：PROBE_GETIMAGE_FIRST=1 导出前先 vaGetImage
 *          PROBE_NODE=/dev/dri/renderD128
 */
#include <drm.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include <va/va.h>
#include <va/va_drm.h>
#include <va/va_drmcommon.h>

static int W = 1920, H = 1088;

static void fill_nv12(unsigned char *b, int w, int h)
{
	unsigned char *y = b, *uv = b + (size_t)w * h;
	int i, j;
	size_t k;

	for (j = 0; j < h; j++)
		for (i = 0; i < w; i++)
			y[(size_t)j * w + i] = (unsigned char)((i + j) & 0xff);
	for (k = 0; k < (size_t)w * h / 2; k++)
		uv[k] = (unsigned char)(0x40 + (k & 0x3f));
}

static unsigned long count_nz(const unsigned char *p, size_t sz)
{
	unsigned long n = 0;
	size_t i;

	for (i = 0; i < sz; i += 512)
		n += !!p[i];
	return n;
}

static void dump_desc(const char *tag, VADRMPRIMESurfaceDescriptor *d)
{
	unsigned i, p;

	printf("[%s] fourcc=0x%08x %ux%u objects=%u layers=%u\n", tag, d->fourcc,
	       d->width, d->height, d->num_objects, d->num_layers);
	for (i = 0; i < d->num_objects && i < 4; i++) {
		struct stat st;
		size_t fsz = 0;

		if (fstat(d->objects[i].fd, &st) == 0)
			fsz = (size_t)st.st_size;
		printf("  obj[%u] fd=%d desc_size=%u fstat=%zu mod=0x%llx\n", i,
		       d->objects[i].fd, d->objects[i].size, fsz,
		       (unsigned long long)d->objects[i].drm_format_modifier);
	}
	for (i = 0; i < d->num_layers && i < 4; i++) {
		printf("  layer[%u] fmt=0x%08x planes=%u\n", i,
		       d->layers[i].drm_format, d->layers[i].num_planes);
		for (p = 0; p < d->layers[i].num_planes && p < 4; p++)
			printf("    plane%u obj=%u off=%u pitch=%u\n", p,
			       d->layers[i].object_index[p], d->layers[i].offset[p],
			       d->layers[i].pitch[p]);
	}
}

static void check(const unsigned char *m, size_t sz, unsigned off,
		  unsigned pitch, int w, int h)
{
	int ok = 0, bad = 0, i, j;

	if (!pitch || (size_t)off + (size_t)pitch * h > sz) {
		printf("    plane outside mapping (off=%u pitch=%u sz=%zu)\n", off,
		       pitch, sz);
		return;
	}
	for (j = 0; j < h; j += 16)
		for (i = 0; i < w; i += 16) {
			unsigned char want = (unsigned char)((i + j) & 0xff);

			if (m[off + (size_t)j * pitch + i] == want)
				ok++;
			else
				bad++;
		}
	printf("    pattern match=%d mismatch=%d\n", ok, bad);
}

static void probe(const char *tag, VADisplay dpy, VASurfaceID sid)
{
	VADRMPRIMESurfaceDescriptor d;
	VAStatus st;
	unsigned i;

	memset(&d, 0, sizeof(d));
	st = vaExportSurfaceHandle(dpy, sid,
				   VA_SURFACE_ATTRIB_MEM_TYPE_DRM_PRIME_2,
				   VA_EXPORT_SURFACE_READ_ONLY, &d);
	if (st != VA_STATUS_SUCCESS) {
		printf("[%s] export failed: %s (%d)\n", tag, vaErrorStr(st), st);
		return;
	}
	dump_desc(tag, &d);
	for (i = 0; i < d.num_objects && i < 4; i++) {
		size_t sz = d.objects[i].size;
		unsigned char *m;
		int k;

		if (!sz)
			continue;
		m = mmap(NULL, sz, PROT_READ, MAP_SHARED, d.objects[i].fd, 0);
		if (m == MAP_FAILED) {
			printf("  obj[%u] mmap failed\n", i);
			continue;
		}
		printf("  obj[%u] nz(step512)=%lu/%lu head:", i, count_nz(m, sz),
		       (unsigned long)(sz / 512 + 1));
		for (k = 0; k < 16 && k < (int)sz; k++)
			printf(" %02x", m[k]);
		printf("\n");
		munmap(m, sz);
	}
	if (d.num_layers && d.layers[0].num_planes) {
		unsigned oi = d.layers[0].object_index[0];
		size_t sz = d.objects[oi].size;
		unsigned char *m;

		m = mmap(NULL, sz, PROT_READ, MAP_SHARED, d.objects[oi].fd, 0);
		if (m != MAP_FAILED) {
			check(m, sz, d.layers[0].offset[0], d.layers[0].pitch[0],
			      W, H);
			munmap(m, sz);
		}
	}
	/* 内核同驱动导入路径测试：把导出的 fd 重新 import 回同一驱动，
	 * 这正是 Jingjia EGL/GL 建立 EGLImage 时走的路径。 */
	if (d.num_objects && d.objects[0].fd >= 0) {
		int dfd = open(getenv("PROBE_NODE") ? getenv("PROBE_NODE")
						    : "/dev/dri/renderD128",
			       O_RDWR);
		struct drm_prime_handle ph;

		if (dfd >= 0) {
			memset(&ph, 0, sizeof(ph));
			ph.fd = d.objects[0].fd;
			ph.flags = O_RDWR | O_CLOEXEC;
			int rc = ioctl(dfd, DRM_IOCTL_PRIME_FD_TO_HANDLE, &ph);

			printf("  PRIME_FD_TO_HANDLE -> rc=%d errno=%d handle=%u\n",
			       rc, rc ? errno : 0, ph.handle);
			close(dfd);
		}
	}

	for (i = 0; i < d.num_objects && i < 4; i++)
		if (d.objects[i].fd >= 0)
			close(d.objects[i].fd);
}

int main(int argc, char **argv)
{
	VADisplay dpy;
	VAStatus st;
	int major = 0, minor = 0, fd;
	VASurfaceID sid = VA_INVALID_SURFACE;
	VAImage img;
	VAImageFormat fmt;
	unsigned char *src;
	void *imgbuf = NULL;
	const char *node = getenv("PROBE_NODE");

	if (argc > 2) {
		W = atoi(argv[1]);
		H = atoi(argv[2]);
	}
	if (!node)
		node = "/dev/dri/renderD128";

	fd = open(node, O_RDWR);
	if (fd < 0) {
		perror("open");
		return 1;
	}
	dpy = vaGetDisplayDRM(fd);
	if (!dpy) {
		fprintf(stderr, "vaGetDisplayDRM failed\n");
		return 1;
	}
	st = vaInitialize(dpy, &major, &minor);
	if (st != VA_STATUS_SUCCESS) {
		fprintf(stderr, "vaInitialize: %s (%d)\n", vaErrorStr(st), st);
		return 1;
	}
	printf("VA %d.%d driver=%s\n", major, minor, vaQueryVendorString(dpy));

	st = vaCreateSurfaces(dpy, VA_RT_FORMAT_YUV420, W, H, &sid, 1, NULL, 0);
	if (st != VA_STATUS_SUCCESS) {
		fprintf(stderr, "vaCreateSurfaces %dx%d: %s (%d)\n", W, H,
			vaErrorStr(st), st);
		return 1;
	}
	printf("surface %#x (%dx%d)\n", sid, W, H);

	src = malloc((size_t)W * H * 3 / 2);
	if (!src)
		return 1;
	fill_nv12(src, W, H);

	memset(&fmt, 0, sizeof(fmt));
	fmt.fourcc = VA_FOURCC_NV12;
	memset(&img, 0, sizeof(img));
	st = vaCreateImage(dpy, &fmt, W, H, &img);
	if (st != VA_STATUS_SUCCESS) {
		fprintf(stderr, "vaCreateImage: %s (%d)\n", vaErrorStr(st), st);
		return 1;
	}
	printf("image id=%#x fmt=0x%08x %ux%u pitches=%u,%u,%u offsets=%u,%u,%u\n",
	       img.image_id, img.format.fourcc, img.width, img.height,
	       img.pitches[0], img.pitches[1], img.pitches[2], img.offsets[0],
	       img.offsets[1], img.offsets[2]);

	st = vaMapBuffer(dpy, img.buf, (void **)&imgbuf);
	if (st != VA_STATUS_SUCCESS) {
		fprintf(stderr, "vaMapBuffer: %s (%d)\n", vaErrorStr(st), st);
		return 1;
	}
	memcpy(imgbuf, src, (size_t)W * H * 3 / 2);
	vaUnmapBuffer(dpy, img.buf);

	st = vaPutImage(dpy, sid, img.image_id, 0, 0, W, H, 0, 0, W, H);
	printf("vaPutImage -> %s (%d)\n", vaErrorStr(st), st);
	vaSyncSurface(dpy, sid);

	/* 回读校验：确认 vaPutImage 是否真的把数据写进了 surface */
	{
		VAImage img2;
		unsigned char *back = malloc((size_t)W * H * 3 / 2);
		void *b2 = NULL;

		memset(&img2, 0, sizeof(img2));
		st = vaCreateImage(dpy, &fmt, W, H, &img2);
		if (st == VA_STATUS_SUCCESS) {
			st = vaGetImage(dpy, sid, 0, 0, W, H, img2.image_id);
			printf("vaGetImage -> %s (%d)\n", vaErrorStr(st), st);
			if (st == VA_STATUS_SUCCESS &&
			    vaMapBuffer(dpy, img2.buf, &b2) == VA_STATUS_SUCCESS) {
				int i, ok = 0, bad = 0;

				memcpy(back, b2, (size_t)W * H * 3 / 2);
				vaUnmapBuffer(dpy, img2.buf);
				for (i = 0; i < W * H * 3 / 2; i += 512)
					(back[i] == src[i]) ? ok++ : bad++;
				printf("  getimage vs source: ok=%d bad=%d head:", ok,
				       bad);
				for (i = 0; i < 8; i++)
					printf(" %02x", back[i]);
				printf("\n");
			}
			vaDestroyImage(dpy, img2.image_id);
		}
		free(back);
	}

	probe("A:after-putimage", dpy, sid);

	vaDestroyImage(dpy, img.image_id);
	vaDestroySurfaces(dpy, &sid, 1);
	vaTerminate(dpy);
	close(fd);
	printf("done\n");
	return 0;
}
