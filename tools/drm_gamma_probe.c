/*
 * tools/drm_gamma_probe.c -- 打印 CRTC 的 gamma/color-mgmt 契约与实际下发的 ramp
 *
 * 用途：定位「显示灰蒙蒙」的真实根因。内核 jmgpu 驱动通过
 * drm_crtc_enable_color_mgmt(crtc, 768, true, 768) 对外宣称
 * gamma_lut_size = 768（厂商把"3 通道 × 256"误当成一个 LUT 项数），
 * 但驱动自己的 atomic_flush 只读前 256 项：
 *
 *     lut = crtc->state->gamma_lut->data;
 *     for (i = 0; i < 256; i++) lutdata[i] = extract(lut[i].red, 8);
 *
 * 于是 X 下发 768 项 identity ramp 时，硬件实际拿到的是它的前 1/3，
 * 数值恰好是 in/3（采样 0,21,42,64,85）——整屏被压到 1/3 动态范围，
 * 表现为"黑发灰、白不白、色相正确"。
 *
 * 本探针把这条链路钉死：GAMMA_LUT_SIZE 是多少、当前 GAMMA_LUT blob
 * 实际有多少项（blob 长度 / 8 字节每项）。两者应当是同一个数，
 * 且应当等于驱动消费者真正读取的项数（256）。
 *
 * 编译：gcc -O2 -Wall -I/usr/include/libdrm -o /tmp/drm_gamma_probe \
 *           tools/drm_gamma_probe.c -ldrm
 * 用法：./drm_gamma_probe [/dev/dri/card0]
 */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

int main(int argc, char **argv)
{
	const char *node = argc > 1 ? argv[1] : "/dev/dri/card0";
	int fd = open(node, O_RDWR);
	drmModeRes *res;
	int i;

	if (fd < 0) {
		perror(node);
		return 1;
	}

	res = drmModeGetResources(fd);
	if (!res) {
		fprintf(stderr, "drmModeGetResources failed\n");
		return 1;
	}

	printf("== %s: %d CRTC(s) ==\n", node, res->count_crtcs);
	for (i = 0; i < res->count_crtcs; i++) {
		drmModeObjectProperties *props;
		drmModeCrtc *crtc;
		unsigned j;

		crtc = drmModeGetCrtc(fd, res->crtcs[i]);
		printf("crtc %u: legacy gamma_size=%d %s\n", res->crtcs[i],
		       crtc ? crtc->gamma_size : -1,
		       (crtc && crtc->gamma_size != 256) ?
		       "  <-- 非 256，值得注意" : "");
		if (crtc)
			drmModeFreeCrtc(crtc);

		props = drmModeObjectGetProperties(fd, res->crtcs[i],
						   DRM_MODE_OBJECT_CRTC);
		if (!props)
			continue;

		for (j = 0; j < props->count_props; j++) {
			drmModePropertyRes *p = drmModeGetProperty(fd,
								  props->props[j]);
			const char *name;

			if (!p)
				continue;
			name = p->name;
			if (strcmp(name, "GAMMA_LUT") &&
			    strcmp(name, "GAMMA_LUT_SIZE") &&
			    strcmp(name, "DEGAMMA_LUT") &&
			    strcmp(name, "DEGAMMA_LUT_SIZE") &&
			    strcmp(name, "CTM")) {
				drmModeFreeProperty(p);
				continue;
			}

			if (p->flags & DRM_MODE_PROP_BLOB) {
				uint64_t id = props->prop_values[j];

				if (id) {
					drmModePropertyBlobRes *b =
					    drmModeGetPropertyBlob(fd, id);
					unsigned n = b ? b->length / 8 : 0;

					printf("  %-18s blob: %u 字节 = %u 项\n",
					       name, b ? b->length : 0, n);
					/*
					 * 采样 5 点，直接看客户端下发的 ramp 内容：
					 * 契约正确时应为线性（identity 请求下
					 * 16 位值 ≈ i*257，即 8 位 0,64,128,192,255）；
					 * 若为 0,21,42,64,85(=in/3)，说明驱动消费的
					 * 项数又比契约少了 3 倍（历史 bug）。
					 */
					if (b && !strcmp(name, "GAMMA_LUT") && n >= 256) {
						struct drm_color_lut *l = b->data;
						static const unsigned s[5] =
						    { 0, 64, 128, 192, 255 };
						int k;

						printf("    ramp 采样(8位) R:");
						for (k = 0; k < 5; k++)
							printf(" %u", l[s[k]].red >> 8);
						printf("  G:");
						for (k = 0; k < 5; k++)
							printf(" %u", l[s[k]].green >> 8);
						printf("  B:");
						for (k = 0; k < 5; k++)
							printf(" %u", l[s[k]].blue >> 8);
						printf("\n    判定: %s\n",
						       l[255].red >> 8 > 240 ?
						       "线性(正确)" :
						       "疑似被截断/缩放(1/3 灰屏形态)");
					}
					if (b)
						drmModeFreePropertyBlob(b);
				} else {
					printf("  %-18s blob: (未设置)\n", name);
				}
			} else {
				printf("  %-18s value: %llu\n", name,
				       (unsigned long long)props->prop_values[j]);
			}
			drmModeFreeProperty(p);
		}
		drmModeFreeObjectProperties(props);
	}

	drmModeFreeResources(res);
	close(fd);
	return 0;
}
