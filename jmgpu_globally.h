/*
 * JMGPU driver
 *
 * Copyright (c) 2020 ChangSha JingJiaMicro Electronics Co., Ltd.
 * All rights reserved.
 *
 * Author:
 *      wj <jjwgpu@jingjiamicro.com>
 *
 * The software and information contained herein is proprietary and
 * confidential to JingJiaMicro Electronics. This software can only be
 * used by JingJiaMicro Electronics Corporation. Any use, reproduction,
 * or disclosure without the written permission of JingJiaMicro
 * Electronics Corporation is strictly prohibited.
 *
 */





#ifndef __8528c4f8_H_
#define __8528c4f8_H_

#define J9_WINDBLOWN(ch0, ch1, ch2, ch3)                                       \
	((unsigned long)(unsigned char)(ch0) |                                 \
	 ((unsigned long)(unsigned char)(ch1) << 8) |                          \
	 ((unsigned long)(unsigned char)(ch2) << 16) |                         \
	 ((unsigned long)(unsigned char)(ch3) << 24))

#define J9_HANDLE__ATTRIBUTE_OUTWRIGGLE J9_WINDBLOWN('V', 'I', 'V', 'M')

enum jm_image_format {
	IMAGE_BYTE = 0,
	IMAGE_YUV420,
	IMAGE_NV12,
	IMAGE_UYVY,
	IMAGE_YUY2,
	IMAGE_Y8,
	IMAGE_UV8,
	IMAGE_MS_P010,
	IMAGE_P010,
	IMAGE_Y210,
	IMAGE_Y10,
	IMAGE_UV10,
	IMAGE_XRGB8888,
	IMAGE_ARGB8888,
	IMAGE_A2R10G10B10,
	IMAGE_X2R10G10B10,
	IMAGE_BAYER10,
	IMAGE_BAYER12,
	IMAGE_BAYER14,
	IMAGE_BAYER16,
	IMAGE_FORMAT_MAX
};

enum jm_tile_format {
	TILE_NONE = 0,
	TILE_Y_4x4,
	TILE_Y_8x8,
	TILE_4x4_INTERLEAVE,
	TILE_8x8_X_MAJOR,
	TILE_8x8_Y_MAJOR,
	TILE_FMT_MAX
};

enum jm_dec_tile_mode {
	CMVDEC_TILE_MODE_8x8_X_MAJOR = 0,
	CMVDEC_TILE_MODE_8x8_Y_MAJOR = 1,
	CMVDEC_TILE_MODE_16x4 = 2,
	CMVDEC_TILE_MODE_8x4 = 3,
	CMVDEC_TILE_MODE_4x8 = 4,
	CMVDEC_TILE_MODE_4x4 = 5,
	CMVDEC_TILE_MODE_16x4_RASTER = 6,
	CMVDEC_TILE_MODE_64x4 = 7,
	CMVDEC_TILE_MODE_32x4 = 8,
	CMVDEC_TILE_MODE_256x1_RASTER = 9,
	CMVDEC_TILE_MODE_128x1_RASTER = 10,
	CMVDEC_TILE_MODE_64x4_RASTER = 11,
	CMVDEC_TILE_MODE_256x2_RASTER = 12,
	CMVDEC_TILE_MODE_128x2_RASTER = 13,
	CMVDEC_TILE_MODE_128x4_RASTER = 14,
	CMVDEC_TILE_MODE_64x1_RASTER = 15,
	CMVDEC_TILE_MODE_16x8_RASTER = 16,
	CMVDEC_TILE_MODE_8x16_RASTER = 17,
	CMVDEC_TILE_MODE_512x1_RASTER = 18,
	CMVDEC_TILE_MODE_32x4_RASTER = 19,
	CMVDEC_TILE_MODE_64x2_RASTER = 20,
	CMVDEC_TILE_MODE_32x2_RASTER = 21,
	CMVDEC_TILE_MODE_32x1_RASTER = 22,
	CMVDEC_TILE_MODE_16x1_RASTER = 23,
	CMVDEC_TILE_MODE_128x4 = 24,
	CMVDEC_TILE_MODE_256x4 = 25,
	CMVDEC_TILE_MODE_512x4 = 26,
	CMVDEC_TILE_MODE_16x16 = 27,
	CMVDEC_TILE_MODE_32x16 = 28,
};

struct jm_vidmem_metadata {
	u32 magic;
	u32 dmabuf_size;
	u32 time_stamp;

	u32 image_format;
	u32 compressed;
	struct {
		u32 offset;
		u32 stride;
		u32 width;
		u32 height;

		u32 tile_format;
		u32 compress_format;

		u32 ts_offset;

		s32 ts_fd;

		s32 ts_fd2;

		s32 ts_vaddr;


		u32 fc_enabled;

		u32 fc_value_lower;

		u32 fc_value_upper;
	} plane[3];
};

#endif


