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


#include <drm/drm_atomic.h>
#include <drm/drm_crtc_helper.h>
#include <linux/version.h>
#include <linux/moduleparam.h>
#include <drm/drm_modeset_lock.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 0, 0)
#include <drm/drm_probe_helper.h>
#endif
#include <drm/drm_atomic_helper.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/delay.h>
#include <linux/wait.h>
#include <linux/spinlock.h>
#ifdef NEOKYLIN50
#include <linux/media-bus-format.h>
#else
#include <uapi/linux/media-bus-format.h>
#endif
#include <uapi/linux/videodev2.h>
#include <linux/hdmi.h>
#include <drm/drm_crtc.h>
#include <linux/gfp.h>
#include <linux/i2c.h>
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 11, 0)
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_scdc_helper.h>
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_scdc_helper.h>
#else
#include <drm/drm_scdc_helper.h>
#endif
#endif
#endif
#include <drm/drm_edid.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 16, 0)
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_hdcp.h>
#else
#include <drm/drm_hdcp.h>
#endif
#endif
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 6, 0)
#include <drm/drm_print.h>
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_hdmi_helper.h>
#endif
#include "jmgpu_authentication.h"
#include "jmgpu_bitmap.h"
#include "jmgpu_nicely.h"
#include "jmgpu_implicit.h"
#include "jmgpu_source.h"
#include "jmgpu_software.h"
#include "mwv207_driver.h"
#include "mwv207reg_procedure.h"

#define J9_PALEOPEDOLOGY      32
#define J9MATHS_HANDICRAFT	340000000

#define SCDC_MIN_SOURCE_VERSION	0x1

#define J9_HANDLE_J_BEFORENESS	11

#define j9_disfranchises(conn) container_of(conn, j9_amylo, connector)
#define j9_nonveritably(enc) container_of(enc, j9_amylo, encoder)

#define J9_HANDLE_J9_ATTRIBUTE_BURSECTOMY 47
#define J9MIRROR_DAMFOOLISH               4
#define J9_HANDLE_ATTRIBUTE_EXTENDIBLE    19


static uint hdmi_disable533250;
module_param(hdmi_disable533250, uint, 0644);
MODULE_PARM_DESC(hdmi_disable533250, "Disable hdmi 533250 mode if set to 1");


static uint hdmi_enable_prefer_mode_4K30;
module_param(hdmi_enable_prefer_mode_4K30, uint, 0644);
MODULE_PARM_DESC(hdmi_enable_prefer_mode_4K30,
		 "Disable hdmi prefer 4K30 mode if set to 0");

typedef struct tag_jms_hdmi_phy_config {
	u32 min_freq_khz;
	u32 max_freq_khz;
	u32 bpp;
	u8 config[J9_HANDLE_J9_ATTRIBUTE_BURSECTOMY];
	u8 padding;
} __packed j9mirror_antifungin;

static j9mirror_antifungin
mwv207_hdmi_phy_config[J9MIRROR_DAMFOOLISH][J9_HANDLE_ATTRIBUTE_EXTENDIBLE]
	= {
	{

	 { 24000, 47999, 8,
	  { 0xD2, 0x78, 0xB0, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x8B, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 28000, 95999, 8,
	  { 0xD2, 0x3C, 0x50, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x85, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 96000, 143999, 8,
	  { 0xD4, 0x50, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x83, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 144000, 296999, 8,
	  { 0xD8, 0x50, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x81, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 297000, 340000, 8,
	  { 0xDC, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x80, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 595000, 8,
	  { 0xDC, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x80, 0xC0,
	   0xF4, 0x69, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	 { 24000, 27999, 10,
	  { 0xD2, 0x7D, 0x90, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x99, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 28000, 55999, 10,
	  { 0xD4, 0xC8, 0x70, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x97, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 56000, 111999, 10,
	  { 0xD4, 0x64, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x93, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 112000, 223999, 10,
	  { 0xD8, 0x64, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x91, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 224000, 272000, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 272001, 340000, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 475200, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	 { 24000, 47999, 12,
	  { 0xD1, 0x3C, 0x70, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA7, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 48000, 95999, 12,
	  { 0xD2, 0x3C, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA3, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 96000, 197999, 12,
	  { 0xD4, 0x3C, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA1, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 198000, 226999, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 227000, 340000, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 396000, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	  },
	{

	 { 24000, 47999, 8,
	  { 0xD2, 0x78, 0xB0, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x8B, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 28000, 95999, 8,
	  { 0xD2, 0x3C, 0x50, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x85, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 96000, 143999, 8,
	  { 0xD4, 0x50, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x83, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 144000, 296999, 8,
	  { 0xD8, 0x50, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x81, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 297000, 340000, 8,
	  { 0xDC, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x80, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 595000, 8,
	  { 0xDC, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x80, 0xC0,
	   0xF4, 0x69, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	 { 24000, 27999, 10,
	  { 0xD2, 0x7D, 0x90, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x99, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 28000, 55999, 10,
	  { 0xD4, 0xC8, 0x70, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x97, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 56000, 111999, 10,
	  { 0xD4, 0x64, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x93, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 112000, 223999, 10,
	  { 0xD8, 0x64, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x91, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 224000, 272000, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 272001, 340000, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 475200, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	 { 24000, 47999, 12,
	  { 0xD1, 0x3C, 0x70, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA7, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 48000, 95999, 12,
	  { 0xD2, 0x3C, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA3, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 96000, 197999, 12,
	  { 0xD4, 0x3C, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA1, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 198000, 226999, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 227000, 340000, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 396000, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	  },
	{

	 { 24000, 47999, 8,
	  { 0xD2, 0x78, 0xB0, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x8B, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 28000, 95999, 8,
	  { 0xD2, 0x3C, 0x50, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x85, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 96000, 143999, 8,
	  { 0xD4, 0x50, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x83, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 144000, 296999, 8,
	  { 0xD8, 0x50, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x81, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 297000, 340000, 8,
	  { 0xDC, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x80, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 595000, 8,
	  { 0xDC, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x80, 0xC0,
	   0xF4, 0x69, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	 { 24000, 27999, 10,
	  { 0xD2, 0x7D, 0x90, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x99, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 28000, 55999, 10,
	  { 0xD4, 0xC8, 0x70, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x97, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 56000, 111999, 10,
	  { 0xD4, 0x64, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x93, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 112000, 223999, 10,
	  { 0xD8, 0x64, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x91, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 224000, 272000, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 272001, 340000, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 475200, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	 { 24000, 47999, 12,
	  { 0xD1, 0x3C, 0x70, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA7, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 48000, 95999, 12,
	  { 0xD2, 0x3C, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA3, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 96000, 197999, 12,
	  { 0xD4, 0x3C, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA1, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 198000, 226999, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 227000, 340000, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 396000, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	  },
	{

	 { 24000, 47999, 8,
	  { 0xD2, 0x78, 0xB0, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x8B, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 28000, 95999, 8,
	  { 0xD2, 0x3C, 0x50, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x85, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 96000, 143999, 8,
	  { 0xD4, 0x50, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x83, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 144000, 296999, 8,
	  { 0xD8, 0x50, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x81, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 297000, 340000, 8,
	  { 0xDC, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x80, 0xF0,
	   0x22, 0x82, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 595000, 8,
	  { 0xDC, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0x01, 0x25, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x80, 0xC0,
	   0xF4, 0x69, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	 { 24000, 27999, 10,
	  { 0xD2, 0x7D, 0x90, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x99, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 28000, 55999, 10,
	  { 0xD4, 0xC8, 0x70, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x97, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 56000, 111999, 10,
	  { 0xD4, 0x64, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x93, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 112000, 223999, 10,
	  { 0xD8, 0x64, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x91, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 224000, 272000, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 272001, 340000, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 475200, 10,
	  { 0xDC, 0x4B, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xCD, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0x90, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	 { 24000, 47999, 12,
	  { 0xD1, 0x3C, 0x70, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA7, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 48000, 95999, 12,
	  { 0xD2, 0x3C, 0x30, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA3, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 96000, 197999, 12,
	  { 0xD4, 0x3C, 0x10, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA1, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 198000, 226999, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3A, 0x74, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 227000, 340000, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x83, 0x0F, 0x3E,
	   0xF8, 0x00, 0x00}},
	 { 340001, 396000, 12,
	  { 0xD8, 0x3C, 0x00, 0x01, 0x00, 0x88, 0x02, 0x4F, 0x30, 0x33, 0x65,
	   0x00, 0xAB, 0x24, 0x80, 0x6C, 0xF2, 0x67, 0x00, 0x10, 0xA0, 0xC0,
	   0x3D, 0xFA, 0x8F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
	   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
	   0xFF, 0x00, 0x00}},
	}
};

typedef struct tag_jms_hdmi_irq {
	bool hdmi_irq_enabled;
} j9_phenicine;

static const u16 csc_coeff_default[3][4] = {
	{ 0x2000, 0x0000, 0x0000, 0x0000 },
	{ 0x0000, 0x2000, 0x0000, 0x0000 },
	{ 0x0000, 0x0000, 0x2000, 0x0000 }
};

static const u16 csc_coeff_rgb_out_eitu601[3][4] = {
	{ 0x2000, 0x6926, 0x74fd, 0x010e },
	{ 0x2000, 0x2cdd, 0x0000, 0x7e9a },
	{ 0x2000, 0x0000, 0x38b4, 0x7e3b }
};

static const u16 csc_coeff_rgb_out_eitu709[3][4] = {
	{ 0x2000, 0x7106, 0x7a02, 0x00a7 },
	{ 0x2000, 0x3264, 0x0000, 0x7e6d },
	{ 0x2000, 0x0000, 0x3b61, 0x7e25 }
};

static const u16 csc_coeff_rgb_in_eitu601[3][4] = {
	{ 0x2591, 0x1322, 0x074b, 0x0000 },
	{ 0x6535, 0x2000, 0x7acc, 0x0200 },
	{ 0x6acd, 0x7534, 0x2000, 0x0200 }
};

static const u16 csc_coeff_rgb_in_eitu709[3][4] = {
	{ 0x2dc5, 0x0d9b, 0x049e, 0x0000 },
	{ 0x62f0, 0x2000, 0x7d11, 0x0200 },
	{ 0x6756, 0x78ab, 0x2000, 0x0200 }
};

static const u16 csc_coeff_rgb_full_to_rgb_limited[3][4] = {
	{ 0x1b7c, 0x0000, 0x0000, 0x0020 },
	{ 0x0000, 0x1b7c, 0x0000, 0x0020 },
	{ 0x0000, 0x0000, 0x1b7c, 0x0020 }
};

typedef struct tag_jms_hdmi_poll {
	struct task_struct *poll_task;
	spinlock_t hpd_lock;
	wait_queue_head_t poll_wait;
	u8 wait_cond;
} j9_watchmaker;

struct hdmi_vmode {
	bool mdataenablepolarity;

	unsigned int mpixelclock;
	unsigned int mpixelrepetitioninput;
	unsigned int mpixelrepetitionoutput;
	unsigned int mtmdsclock;
};

struct hdmi_data_info {
	unsigned int enc_in_bus_format;
	unsigned int enc_out_bus_format;
	unsigned int enc_in_encoding;
	unsigned int enc_out_encoding;
	unsigned int pix_repet_factor;
	unsigned int hdcp_enable;
	struct hdmi_vmode video_mode;
	bool rgb_limited_range;
};

typedef struct _tag_jms_kms_hdmi {
	struct drm_connector connector;
	struct drm_encoder encoder;
	struct tag_jms_hdmi_irq irq;
	struct tag_jms_hdmi_poll poll;
	struct hdmi_data_info hdmi_data;
	struct delayed_work scdc;
	struct mutex clk_lock;
	struct i2c_adapter *ddc;
	struct jmgpu_panel *panel;
	struct j9_tryste *audio;
	j9_weakliest *platform;
	enum drm_connector_status last_connector_result;
	struct edid *edid;
	struct drm_device *ddev;
	u32 mem_base;
	u32 key_idx;
	u32 hdmi_chan;
	u32 cur_clk_khz;
	u32 scdc_cnt;
	u32 cur_crtc;
	int vic;
	u8 mc_clkdis;

	bool edidforce;

	bool zoomEn;
	bool sink_is_hdmi;
	bool sink_has_audio;
	bool sink_has_4K30;
	bool rgb_quant_range_selectable;
	bool output_active;
} j9_amylo;

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 12, 0)
#define SCDC_SINK_VERSION 0x01

#define SCDC_SOURCE_VERSION 0x02

#define SCDC_UPDATE_0 0x10
#define  SCDC_READ_REQUEST_TEST (1 << 2)
#define  SCDC_CED_UPDATE (1 << 1)
#define  SCDC_STATUS_UPDATE (1 << 0)

#define SCDC_UPDATE_1 0x11

#define SCDC_TMDS_CONFIG 0x20
#define  SCDC_TMDS_BIT_CLOCK_RATIO_BY_40 (1 << 1)
#define  SCDC_TMDS_BIT_CLOCK_RATIO_BY_10 (0 << 1)
#define  SCDC_SCRAMBLING_ENABLE (1 << 0)

#define SCDC_SCRAMBLER_STATUS 0x21
#define  SCDC_SCRAMBLING_STATUS (1 << 0)

#define SCDC_CONFIG_0 0x30
#define  SCDC_READ_REQUEST_ENABLE (1 << 0)

#define SCDC_STATUS_FLAGS_0 0x40
#define  SCDC_CH2_LOCK (1 < 3)
#define  SCDC_CH1_LOCK (1 < 2)
#define  SCDC_CH0_LOCK (1 < 1)
#define  SCDC_CH_LOCK_MASK (SCDC_CH2_LOCK | SCDC_CH1_LOCK | SCDC_CH0_LOCK)
#define  SCDC_CLOCK_DETECT (1 << 0)

#define SCDC_STATUS_FLAGS_1 0x41
#define SCDC_I2C_SLAVE_ADDRESS 0x54
#define SCDC_ERR_DET_0_L 0x50
#define SCDC_ERR_DET_0_H 0x51
#define SCDC_ERR_DET_1_L 0x52
#define SCDC_ERR_DET_1_H 0x53
#define SCDC_ERR_DET_2_L 0x54
#define SCDC_ERR_DET_2_H 0x55
#define  SCDC_CHANNEL_VALID (1 << 7)

#define SCDC_ERR_DET_CHECKSUM 0x56

#define SCDC_TEST_CONFIG_0 0xc0
#define  SCDC_TEST_READ_REQUEST (1 << 7)
#define  SCDC_TEST_READ_REQUEST_DELAY(x) ((x) & 0x7f)

#define SCDC_MANUFACTURER_IEEE_OUI 0xd0
#define SCDC_MANUFACTURER_IEEE_OUI_SIZE 3

#define SCDC_DEVICE_ID 0xd3
#define SCDC_DEVICE_ID_SIZE 8

#define SCDC_DEVICE_HARDWARE_REVISION 0xdb
#define  SCDC_GET_DEVICE_HARDWARE_REVISION_MAJOR(x) (((x) >> 4) & 0xf)
#define  SCDC_GET_DEVICE_HARDWARE_REVISION_MINOR(x) (((x) >> 0) & 0xf)

#define SCDC_DEVICE_SOFTWARE_MAJOR_REVISION 0xdc
#define SCDC_DEVICE_SOFTWARE_MINOR_REVISION 0xdd

#define SCDC_MANUFACTURER_SPECIFIC 0xde
#define SCDC_MANUFACTURER_SPECIFIC_SIZE 34
ssize_t drm_scdc_read(struct i2c_adapter *adapter, u8 offset, void *buffer,
		      size_t size)
{
	int ret;
	struct i2c_msg msgs[2] = {
		{
		 .addr = SCDC_I2C_SLAVE_ADDRESS,
		 .flags = 0,
		 .len = 1,
		 .buf = &offset,
		  }, {
		      .addr = SCDC_I2C_SLAVE_ADDRESS,
		      .flags = I2C_M_RD,
		      .len = size,
		      .buf = buffer,
		}
	};

	ret = i2c_transfer(adapter, msgs, ARRAY_SIZE(msgs));
	if (ret < 0)
		return ret;
	if (ret != ARRAY_SIZE(msgs))
		return -EPROTO;

	return 0;
}

ssize_t drm_scdc_write(struct i2c_adapter *adapter, u8 offset,
		       const void *buffer, size_t size)
{
	struct i2c_msg msg = {
		.addr = SCDC_I2C_SLAVE_ADDRESS,
		.flags = 0,
		.len = 1 + size,
		.buf = NULL,
	};
	void *data;
	int err;

	data = kmalloc(1 + size, GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	msg.buf = data;

	memcpy(data, &offset, sizeof(offset));
	memcpy(data + 1, buffer, size);

	err = i2c_transfer(adapter, &msg, 1);

	kfree(data);

	if (err < 0)
		return err;
	if (err != 1)
		return -EPROTO;

	return 0;
}

static inline int drm_scdc_readb(struct i2c_adapter *adapter, u8 offset,
				 u8 *value)
{
	return drm_scdc_read(adapter, offset, value, sizeof(*value));
}

static inline int drm_scdc_writeb(struct i2c_adapter *adapter, u8 offset,
				  u8 value)
{
	return drm_scdc_write(adapter, offset, &value, sizeof(value));
}


bool jmgpu_scdc_set_scrambling(struct i2c_adapter *adapter, bool enable)
{
	u8 config;
	int ret;

	ret = drm_scdc_readb(adapter, SCDC_TMDS_CONFIG, &config);
	if (ret < 0) {
		DRM_ERROR("Failed to read tmds config, err=%d\n", ret);
		return false;
	}

	if (enable)
		config |= SCDC_SCRAMBLING_ENABLE;
	else
		config &= ~SCDC_SCRAMBLING_ENABLE;

	ret = drm_scdc_writeb(adapter, SCDC_TMDS_CONFIG, config);
	if (ret < 0) {
		DRM_ERROR("Failed to enable scrambling, error %d\n", ret);
		return false;
	}

	return true;
}

bool jmgpu_scdc_set_high_tmds_clock_ratio(struct i2c_adapter *adapter, bool set)
{
	u8 config;
	int ret;

	ret = drm_scdc_readb(adapter, SCDC_TMDS_CONFIG, &config);
	if (ret < 0) {
		DRM_ERROR("Failed to read tmds config, err=%d\n", ret);
		return false;
	}

	if (set)
		config |= SCDC_TMDS_BIT_CLOCK_RATIO_BY_40;
	else
		config &= ~SCDC_TMDS_BIT_CLOCK_RATIO_BY_40;

	ret = drm_scdc_writeb(adapter, SCDC_TMDS_CONFIG, config);
	if (ret < 0) {
		DRM_ERROR("Failed to set TMDS clock ratio, error %d\n", ret);
		return false;
	}

	usleep_range(1000, 2000);
	return true;
}
#endif

static void j9_handle_j9ma_cancerweed(struct drm_encoder *encoder);
static inline void j9_crosshatched(j9_amylo *hdmi, u32 addr, u32 val)
{
	j9_weakliest *platform = hdmi->platform;

	J9_CRISPY(addr, val);
}

static inline void j9_pangolin(j9_amylo *hdmi, u32 val, u32 offset)
{
	j9_crosshatched(hdmi, hdmi->mem_base + offset * 4, val);
}

static inline void j9_handle_marshalman(j9_amylo *hdmi, u32 addr, u32 mask,
					u32 val)
{
	j9_weakliest *platform = hdmi->platform;

	J9_UNPERFECTLY(addr, mask, val);
}

static inline void j9_garran(j9_amylo *hdmi, u32 val, u32 mask, u32 offset)
{
	j9_handle_marshalman(hdmi, hdmi->mem_base + offset * 4, mask, val);
}

static void j9_conceitedness(j9_amylo *hdmi, u8 data, unsigned int reg,
			     u8 shift, u8 mask)
{
	j9_garran(hdmi, data << shift, mask, reg);
}

static inline u32 j9_mentolabial(j9_amylo *hdmi, u32 addr)
{
	j9_weakliest *platform = hdmi->platform;

	return J9_NICOLS(addr);
}

static inline u32 j9_nitrite(j9_amylo *hdmi, u32 offset)
{
	return j9_mentolabial(hdmi, hdmi->mem_base + offset * 4);
}

#define J9_PROCRYPTICALLY                 0xfff0
static u16 j9_handle_j9_tubiporoid(u16 type_idx)
{
	return J9_PROCRYPTICALLY + type_idx;
}

static s32 j9_handle_j9menu_citynesses(j9_amylo *hdmi, u16 key)
{
	j9mirror_antifungin *ptr;
	j9_strenuous *item;
	int ret = 0;
	u8 hdmi_chan = hdmi->hdmi_chan;
	u8 i;


	item = hdmi->platform->ops->get_cfg_item(hdmi->platform, key);
	if (!item)
		return -EINVAL;

	if (item->len !=
	    (sizeof(j9mirror_antifungin)) * J9_HANDLE_ATTRIBUTE_EXTENDIBLE) {
		ret = -EINVAL;
		goto release;
	}

	ptr = item->data;
	for (i = 0; i < J9_HANDLE_ATTRIBUTE_EXTENDIBLE; i++) {
		mwv207_hdmi_phy_config[hdmi_chan][i] = *ptr++;

		mwv207_hdmi_phy_config[hdmi_chan][i].min_freq_khz =
		    le32_to_cpu(mwv207_hdmi_phy_config[hdmi_chan]
				[i].min_freq_khz);
		mwv207_hdmi_phy_config[hdmi_chan][i].max_freq_khz =
		    le32_to_cpu(mwv207_hdmi_phy_config[hdmi_chan]
				[i].max_freq_khz);
		mwv207_hdmi_phy_config[hdmi_chan][i].bpp =
		    le32_to_cpu(mwv207_hdmi_phy_config[hdmi_chan][i].bpp);
	}

release:

	hdmi->platform->ops->put_cfg_item(hdmi->platform, item);

	return ret;
}

static void j9_handle_attribute_traversals(struct drm_connector *connector)
{
	j9_amylo *hdmi = j9_disfranchises(connector);
	u32 ret;
	u8 hdmi_chan = hdmi->hdmi_chan;

	if (!hdmi->panel) {
		DRM_DEBUG_DRIVER("panel invalid!");
		return;
	}

	ret =
	    j9_handle_j9menu_citynesses(hdmi,
					j9_handle_j9_tubiporoid(hdmi_chan));
	if (ret) {
		DRM_INFO("[jmgpu] hdmi(%d) use default phy config value",
			 hdmi_chan);
	}

	if (!j9_handle_j9mirror_hypotarsus
	    (hdmi->panel, hdmi->key_idx, &hdmi->edid)) {
		hdmi->edidforce = true;
	} else {
		hdmi->edidforce = false;
	}
	if (hdmi->edidforce) {
		hdmi->connector.force = DRM_FORCE_ON;
		hdmi->last_connector_result = connector_status_connected;

		DRM_INFO("hdmi_%d: DRM_FORCE_ON!", hdmi->hdmi_chan);
	}

	jmgpu_kms_panel_set_zoom_is_enable(hdmi->panel, hdmi->zoomEn);
	if (hdmi->zoomEn) {

		DRM_INFO("hdmi_%d: HDMI_ZOOM_ON!", hdmi->hdmi_chan);
	}
}

#define J9_HANDLE_J9MIN_COWARDICES \
	(HDMI_IH_PHY_STAT0_RX_SENSE0 | HDMI_IH_PHY_STAT0_RX_SENSE1 | \
	 HDMI_IH_PHY_STAT0_RX_SENSE2 | HDMI_IH_PHY_STAT0_RX_SENSE3)
#define J9_CYTOPATHOLOGIC \
	(HDMI_PHY_RX_SENSE0 | HDMI_PHY_RX_SENSE1 | \
	 HDMI_PHY_RX_SENSE2 | HDMI_PHY_RX_SENSE3)

#define HDMI_PLUGIN  (0x1 << 0)
#define HDMI_PLUGOUT (0x1 << 1)
static void j9_handle__antrophose(j9_amylo *hdmi, u32 chan)
{
	u8 intr_stat, phy_int_pol, phy_pol_mask, phy_stat;

	intr_stat = j9_nitrite(hdmi, J9_ANCHORITICALLY);
	phy_int_pol = j9_nitrite(hdmi, J9_SUBPROCTOR);
	phy_stat = j9_nitrite(hdmi, J9_FICTIONALLY);

	phy_pol_mask = 0;
	if (intr_stat & HDMI_IH_PHY_STAT0_HPD)
		phy_pol_mask |= HDMI_PHY_HPD;
	if (intr_stat & HDMI_IH_PHY_STAT0_RX_SENSE0)
		phy_pol_mask |= HDMI_PHY_RX_SENSE0;
	if (intr_stat & HDMI_IH_PHY_STAT0_RX_SENSE1)
		phy_pol_mask |= HDMI_PHY_RX_SENSE1;
	if (intr_stat & HDMI_IH_PHY_STAT0_RX_SENSE2)
		phy_pol_mask |= HDMI_PHY_RX_SENSE2;
	if (intr_stat & HDMI_IH_PHY_STAT0_RX_SENSE3)
		phy_pol_mask |= HDMI_PHY_RX_SENSE3;

	if (phy_pol_mask)
		j9_garran(hdmi, ~phy_int_pol, phy_pol_mask, J9_SUBPROCTOR);

	if (intr_stat & HDMI_IH_PHY_STAT0_HPD) {
		DRM_DEBUG_DRIVER("HDMI_%d, EVENT=%s\n",
				 chan,
				 phy_int_pol & HDMI_PHY_HPD ? "plugin" :
				 "plugout");

		spin_lock(&hdmi->poll.hpd_lock);
		if (phy_int_pol & HDMI_PHY_HPD)
			hdmi->poll.wait_cond = HDMI_PLUGIN;
		else
			hdmi->poll.wait_cond = HDMI_PLUGOUT;

		spin_unlock(&hdmi->poll.hpd_lock);

		wake_up_interruptible(&hdmi->poll.poll_wait);
	}


	j9_pangolin(hdmi, intr_stat, J9_ANCHORITICALLY);
	j9_pangolin(hdmi, ~(HDMI_IH_PHY_STAT0_HPD | J9_HANDLE_J9MIN_COWARDICES),
		    J9_HANDLE_J_DENEGATION);
}

static void j9_handle_j9min_disenthral(j9_amylo *hdmi, u32 chan)
{
	u8 state;


	state = j9_nitrite(hdmi, J9_INAPPRECIABLE);
	j9_pangolin(hdmi, state, J9_INAPPRECIABLE);

	state = j9_nitrite(hdmi, J9_SUBLACUSTRINE);
	j9_pangolin(hdmi, state, J9_SUBLACUSTRINE);
}

static void j9_handle_j9min_outvaunted(j9_amylo *hdmi, u32 chan)
{
	u8 fc_state;


	fc_state = j9_nitrite(hdmi, J9_INDOCIBLENESS);
	j9_pangolin(hdmi, fc_state, J9_INDOCIBLENESS);
}

static void j9_handle_j9min_epistomata(j9_amylo *hdmi, u32 chan)
{
	u8 fc_state;


	fc_state = j9_nitrite(hdmi, J9_UNRESPONSIBLE);
	j9_pangolin(hdmi, fc_state, J9_UNRESPONSIBLE);
}

static void j9_handle_paraglider(j9_amylo *hdmi, u32 chan)
{
	u8 state;


	state = j9_nitrite(hdmi, J9_CRINICULTURAL);
	j9_pangolin(hdmi, state, J9_CRINICULTURAL);
}

static void j9_handle_j9_octaemeron(j9_amylo *hdmi, u32 chan)
{
	if (hdmi->audio)
		j9_handle_j9maths_maturities(hdmi->audio, chan);
}

static void j9_handle__aneuploidy(j9_amylo *hdmi, u32 chan)
{
	u8 state;


	state = j9_nitrite(hdmi, J9_REACCLIMATIZED);
	j9_pangolin(hdmi, state, J9_REACCLIMATIZED);
}

static void j9_handle_j_octaemeron(j9_amylo *hdmi, u32 chan)
{
	u8 state;


	state = j9_nitrite(hdmi, J9MATHS_MANEUVERER);
	j9_pangolin(hdmi, state, J9MATHS_MANEUVERER);
}

static irqreturn_t j9_handle_j_translater(int irq, void *data)
{
	j9_amylo *hdmi = (j9_amylo *) data;
	u32 chan = hdmi->hdmi_chan;
	u8 event_mask;

	if (!hdmi->irq.hdmi_irq_enabled)
		return IRQ_NONE;

	event_mask = j9_nitrite(hdmi, 0x170);

	DRM_DEBUG_DRIVER("hdmi_%d recv irq %d\n", hdmi->hdmi_chan, event_mask);

	while (event_mask) {
		if (event_mask & (0x1 << 0)) {

			j9_handle_j9_octaemeron(hdmi, chan);
		}
		if (event_mask & (0x1 << 1)) {

			j9_handle__aneuploidy(hdmi, chan);
		}
		if (event_mask & (0x1 << 2)) {

			j9_handle_j_octaemeron(hdmi, chan);
		}
		if (event_mask & (0x1 << 3)) {

			j9_handle__antrophose(hdmi, chan);
		}
		if (event_mask & (0x1 << 4)) {

			j9_handle_paraglider(hdmi, chan);
		}
		if (event_mask & (0x1 << 5)) {

			j9_handle_j9min_disenthral(hdmi, chan);
		}
		if (event_mask & (0x1 << 6)) {

			j9_handle_j9min_outvaunted(hdmi, chan);
		}
		if (event_mask & (0x1 << 7)) {

			j9_handle_j9min_epistomata(hdmi, chan);
		}
		event_mask = j9_nitrite(hdmi, 0x170);
	}


	j9_pangolin(hdmi,
		    ~HDMI_IH_MUTE_MUTE_ALL_INTERRUPT & HDMI_IH_MUTE_MUTE_MASK,
		    J9_CELEBRITY);

	return IRQ_HANDLED;
}

static void j9mirror_qualifying(j9_amylo *hdmi)
{
	u8 ih_mute;

	ih_mute = j9_nitrite(hdmi, J9_CELEBRITY) |
	    HDMI_IH_MUTE_MUTE_WAKEUP_INTERRUPT |
	    HDMI_IH_MUTE_MUTE_ALL_INTERRUPT;

	j9_pangolin(hdmi, ih_mute, J9_CELEBRITY);


	j9_pangolin(hdmi, 0xff, J9_OVERMORAL);
	j9_pangolin(hdmi, 0xff, J9_FORMALITER);
	j9_pangolin(hdmi, 0xff, J9_CITIZENDOM);
	j9_pangolin(hdmi, 0xff, J9_GROCERYMEN);
	j9_pangolin(hdmi, 0xff, J9_PHANTOMLIKE);
	j9_pangolin(hdmi, 0xff, J9_HANDLE_J_CENOTAPHIC);
	j9_pangolin(hdmi, 0xff, J9_HANDLE_J9MA_UNDERTRIBE);
	j9_pangolin(hdmi, 0xff, J9_PANICALLY);
	j9_pangolin(hdmi, 0xff, J9_REAPPROACHABLE);
	j9_pangolin(hdmi, 0xff, J9_DIMENSIONALITY);
	j9_pangolin(hdmi, 0xff, J9_BUCKEROOS);
	j9_pangolin(hdmi, 0xff, J9_ELECTROPHILIC);
	j9_pangolin(hdmi, 0xff, J9_EIGENVALUE);
	j9_pangolin(hdmi, 0xff, J9_CHROMONEMATIC);


	j9_pangolin(hdmi, 0xff, J9_HANDLE__APHORIZING);
	j9_pangolin(hdmi, 0xff, J9_HANDLE__DELINEAVIT);
	j9_pangolin(hdmi, 0xff, J9_HANDLE__NONERODING);
	j9_pangolin(hdmi, 0xff, J9_HANDLE__INCESSABLE);
	j9_pangolin(hdmi, 0xff, J9_HANDLE_J_DENEGATION);
	j9_pangolin(hdmi, 0xff, J9_HANDLE_J9_SUPERDUPER);
	j9_pangolin(hdmi, 0xff, J9_HANDLE_J_SUBRECTORY);
	j9_pangolin(hdmi, 0xff, J9_HANDLE__SUICIDICAL);
	j9_pangolin(hdmi, 0xff, J9_HANDLE_J9MIN_TRIPSOMELY);
	j9_pangolin(hdmi, 0xff, J9_HANDLE_J9MATHS_HERETICIZE);


	ih_mute &= ~(HDMI_IH_MUTE_MUTE_WAKEUP_INTERRUPT |
		     HDMI_IH_MUTE_MUTE_ALL_INTERRUPT);
	j9_pangolin(hdmi, ih_mute, J9_CELEBRITY);


	j9_pangolin(hdmi, HDMI_PHY_HPD | J9_CYTOPATHOLOGIC, J9_SUBPROCTOR);
	j9_pangolin(hdmi, HDMI_IH_PHY_STAT0_HPD | J9_HANDLE_J9MIN_COWARDICES,
		    J9_ANCHORITICALLY);


	j9_pangolin(hdmi, 0xfd, J9_PHANTOMLIKE);


	j9_pangolin(hdmi, HDMI_IH_PHY_STAT0_HPD | J9_HANDLE_J9MIN_COWARDICES,
		    J9_ANCHORITICALLY);
	j9_pangolin(hdmi, ~(HDMI_IH_PHY_STAT0_HPD | J9_HANDLE_J9MIN_COWARDICES),
		    J9_HANDLE_J_DENEGATION);
}

static u8 jmgpu_hdmi_get_wait_cond(j9_amylo *hdmi)
{
	unsigned long flags;
	u8 wait_cond;

	spin_lock_irqsave(&hdmi->poll.hpd_lock, flags);
	wait_cond = hdmi->poll.wait_cond;
	hdmi->poll.wait_cond = 0;
	spin_unlock_irqrestore(&hdmi->poll.hpd_lock, flags);

	return wait_cond;
}

static int j9_handle_demiurgism(void *arg)
{
	j9_amylo *hdmi = (j9_amylo *) arg;
	int ret;
	u8 wait_cond;

	BUG_ON(!hdmi);

	set_freezable();
	while (!kthread_should_stop()) {
		try_to_freeze();
		ret = wait_event_interruptible_timeout(hdmi->poll.poll_wait,
						       (wait_cond =
						       jmgpu_hdmi_get_wait_cond
						       (hdmi)),
						       msecs_to_jiffies(1000));
		if (ret == 0)
			continue;

		DRM_DEBUG_DRIVER("handle hdmi_%d hpd...", hdmi->hdmi_chan);

		if (wait_cond & HDMI_PLUGIN) {
			if (hdmi->cur_clk_khz > 340000) {
				DRM_DEBUG_DRIVER("hdmi_%d start scdc work...",
						 hdmi->hdmi_chan);
				hdmi->scdc_cnt = 0;
				schedule_delayed_work(&hdmi->scdc, HZ);
			}
		}
		if (wait_cond & HDMI_PLUGOUT) {
			if (hdmi->cur_clk_khz > 340000) {
				DRM_DEBUG_DRIVER("hdmi_%d stop scdc work...",
						 hdmi->hdmi_chan);
				cancel_delayed_work_sync(&hdmi->scdc);
			}
		}

		drm_helper_hpd_irq_event(hdmi->connector.dev);
	}
	return 0;
}

static int j9_handle_j_attribute_arecaceous(struct i2c_adapter *adapter)
{
	u8 status;
	int ret;

	ret = drm_scdc_readb(adapter, SCDC_SCRAMBLER_STATUS, &status);
	if (ret < 0) {
		DRM_DEBUG_KMS("Failed to read scrambling status: %d\n", ret);
		return ret;
	}

	return status & SCDC_SCRAMBLING_STATUS;
}

static bool j9_handle_j9_translater(j9_amylo *hdmi,
				    const struct drm_display_info *display)
{

	if (!hdmi->ddc)
		return false;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 12, 0)

	if (!display->hdmi.scdc.supported ||
	    !display->hdmi.scdc.scrambling.supported)
		return false;

	if (!display->hdmi.scdc.scrambling.low_rates &&
	    display->max_tmds_clock <= 340000)
		return false;
#endif

	return true;
}

void hdmi_set_high_tmds_clock_ratio(j9_amylo *hdmi,
				    const struct drm_display_info *display)
{

	if (j9_handle_j9_translater(hdmi, display)) {
		if (hdmi->cur_clk_khz > 340000)
			drm_scdc_set_high_tmds_clock_ratio(&hdmi->connector, 1);
		else
			drm_scdc_set_high_tmds_clock_ratio(&hdmi->connector, 0);
	}
}

void hdmi_phy_config_para(struct drm_encoder *encoder, unsigned int clk_khz,
			  unsigned int id, u32 bpp)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);
	u32 base = 0;
	u32 offset = 0;
	u32 i = 0;
	u32 j = 0;
	u32 val = 0;
	u8 bytes;

	for (i = 0; i < J9_HANDLE_ATTRIBUTE_EXTENDIBLE; i++) {
		if (clk_khz >=
		    mwv207_hdmi_phy_config[hdmi->hdmi_chan][i].min_freq_khz
		    && clk_khz <=
		    mwv207_hdmi_phy_config[hdmi->hdmi_chan][i].max_freq_khz
		    && bpp == mwv207_hdmi_phy_config[hdmi->hdmi_chan][i].bpp) {
			break;
		}
	}

	if (i >= J9_HANDLE_ATTRIBUTE_EXTENDIBLE) {
		DRM_ERROR("no matching phy config(%d) found!", clk_khz);
		return;
	}

	if (hdmi->cur_clk_khz > 340000) {
		val = j9_nitrite(hdmi, J9_NONRUINOUSNESS);
		val |= HDMI_FC_INVIDCONF_HDCP_KEEPOUT_ACTIVE;
		j9_pangolin(hdmi, val, J9_NONRUINOUSNESS);
		drm_scdc_readb(hdmi->ddc, SCDC_SINK_VERSION, &bytes);
		drm_scdc_writeb(hdmi->ddc, SCDC_SOURCE_VERSION,
				min_t(u8, bytes, SCDC_MIN_SOURCE_VERSION));
		drm_scdc_set_scrambling(&hdmi->connector, 1);
		drm_scdc_set_high_tmds_clock_ratio(&hdmi->connector, 1);
		j9_pangolin(hdmi, (u8) ~HDMI_MC_SWRSTZ_TMDSSWRST_REQ,
			    J9_LATICOSTATE);
		j9_pangolin(hdmi, 1, J9_HANDLE_J_PERIOSTOMA);
	} else {
		j9_pangolin(hdmi, 0, J9_HANDLE_J_PERIOSTOMA);
		j9_pangolin(hdmi, (u8) ~HDMI_MC_SWRSTZ_TMDSSWRST_REQ,
			    J9_LATICOSTATE);
		drm_scdc_set_scrambling(&hdmi->connector, 0);
		drm_scdc_set_high_tmds_clock_ratio(&hdmi->connector, 0);
	}


	base = J9_HANDLE_J9MIRROR_CELIBATIST(id);
	j9_crosshatched(hdmi, base + 0x70, 0xc8);
	j9_crosshatched(hdmi, base + 0x74, 0x2);
	for (j = 0; j < J9_HANDLE_J9_ATTRIBUTE_BURSECTOMY; j++) {
		offset = 0x4 + j * 4;
		if (unlikely(offset == 0x84) ||
		    unlikely(offset == 0x88) || unlikely(offset == 0xB8)) {
			continue;
		}
		j9_crosshatched(hdmi, base + offset,
				mwv207_hdmi_phy_config[hdmi->hdmi_chan][i].config[j]);
	}
}

void hdmi_phy_gen2_txpwron(j9_amylo *hdmi, u8 enable)
{
	u32 base = 0;

	base = J9_HANDLE_J9MIRROR_CELIBATIST(hdmi->hdmi_chan);
	if (enable) {
		j9_crosshatched(hdmi, base + 0x84, 0x80);
		j9_handle_marshalman(hdmi,
				     J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
				     0x1 << 28, 0x0 << 28);
		j9_handle_marshalman(hdmi,
				     J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
				     0x1 << 0, 0x1 << 0);
	} else {
		j9_handle_marshalman(hdmi,
				     J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
				     0x1 << 0, 0x0 << 0);
		msleep(50);
		j9_handle_marshalman(hdmi,
				     J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
				     0x1 << 28, 0x1 << 28);
		j9_crosshatched(hdmi, base + 0x84, 0x0);
	}
	j9_conceitedness(hdmi, enable, J9_INCREMATION,
			 HDMI_PHY_CONF0_GEN2_TXPWRON_OFFSET,
			 HDMI_PHY_CONF0_GEN2_TXPWRON_MASK);
}

void hdmi_phy_gen2_pddq(j9_amylo *hdmi, u8 enable)
{
	j9_conceitedness(hdmi, enable, J9_INCREMATION,
			 HDMI_PHY_CONF0_GEN2_PDDQ_OFFSET,
			 HDMI_PHY_CONF0_GEN2_PDDQ_MASK);
}

static void j9maths_presternal(j9_amylo *hdmi)
{
	unsigned int i;
	u16 val;

	hdmi_phy_gen2_txpwron(hdmi, 0);

	for (i = 0; i < 5; ++i) {
		val = j9_nitrite(hdmi, J9_FICTIONALLY);
		if (!(val & HDMI_PHY_TX_PHY_LOCK))
			break;

		usleep_range(1000, 2000);
	}

	if (val & HDMI_PHY_TX_PHY_LOCK)
		DRM_WARN("PHY failed to power down\n");
	else
		DRM_DEBUG_DRIVER("PHY powered down in %u iterations\n", i);

	hdmi_phy_gen2_pddq(hdmi, 1);
}

static int j9_cholelithotomy(j9_amylo *hdmi)
{
	unsigned int i;
	u8 val;

	hdmi_phy_gen2_txpwron(hdmi, 1);
	hdmi_phy_gen2_pddq(hdmi, 0);


	for (i = 0; i < 5; ++i) {
		val = j9_nitrite(hdmi, J9_FICTIONALLY) & HDMI_PHY_TX_PHY_LOCK;
		if (val)
			break;

		usleep_range(1000, 2000);
	}

	if (!val) {
		DRM_ERROR("PHY PLL failed to lock\n");
		return -ETIMEDOUT;
	}

	DRM_DEBUG_DRIVER("PHY PLL locked %u iterations\n", i);

	return 0;
}

void hdmi_phy_reset(j9_amylo *hdmi)
{

	j9_pangolin(hdmi, HDMI_MC_PHYRSTZ_PHYRSTZ, J9_UNVOYAGEABLE);
	j9_pangolin(hdmi, 0, J9_UNVOYAGEABLE);
}

static void j9_handle_j_saddlebill(j9_amylo *hdmi, u8 enable)
{
	j9_conceitedness(hdmi, enable, J9_INCREMATION,
			 HDMI_PHY_CONF0_SVSRET_OFFSET,
			 HDMI_PHY_CONF0_SVSRET_MASK);
}

static int j9maths_unequipped(j9_amylo *hdmi,
			      const struct drm_display_info *display)
{
	j9maths_presternal(hdmi);

	hdmi_set_high_tmds_clock_ratio(hdmi, display);
	j9_handle_j_saddlebill(hdmi, 1);
	hdmi_phy_reset(hdmi);
	j9_pangolin(hdmi, HDMI_MC_HEACPHY_RST_ASSERT, J9MIRROR_HUMILIATED);


	hdmi_phy_config_para(&hdmi->encoder, hdmi->cur_clk_khz, hdmi->hdmi_chan,
			     8);


	if (hdmi->cur_clk_khz > 340000)
		msleep(100);

	return j9_cholelithotomy(hdmi);
}

static void j9_handle_j9m_crawlerize(j9_amylo *hdmi, u8 enable)
{
	j9_conceitedness(hdmi, enable, J9_INCREMATION,
			 HDMI_PHY_CONF0_SELDATAENPOL_OFFSET,
			 HDMI_PHY_CONF0_SELDATAENPOL_MASK);
}

static void j9_handle_attribute_centermost(j9_amylo *hdmi, u8 enable)
{
	j9_conceitedness(hdmi, enable, J9_INCREMATION,
			 HDMI_PHY_CONF0_SELDIPIF_OFFSET,
			 HDMI_PHY_CONF0_SELDIPIF_MASK);
}

static int j9_troglodyte(j9_amylo *hdmi,
			 const struct drm_display_info *display)
{
	int i, ret;


	for (i = 0; i < 2; i++) {
		j9_handle_j9m_crawlerize(hdmi, 1);
		j9_handle_attribute_centermost(hdmi, 0);

		ret = j9maths_unequipped(hdmi, display);
		if (ret)
			return ret;
	}

	return 0;
}

static void j9_boilerworks(struct work_struct *work)
{
	j9_amylo *hdmi = container_of(work, j9_amylo, scdc.work);
	int ret;
	u8 scdc_flag = 0;
	struct drm_modeset_acquire_ctx ctx;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 15, 0)
	drm_modeset_acquire_init(&ctx, DRM_MODESET_ACQUIRE_INTERRUPTIBLE);
#else
	drm_modeset_acquire_init(&ctx, 0);
#endif

retry:
	ret = drm_modeset_lock_all_ctx(hdmi->ddev, &ctx);
	if (ret)
		goto unlock;

	if (hdmi->cur_clk_khz <= 340000)
		goto unlock;

	ret = j9_handle_j_attribute_arecaceous(hdmi->ddc);
	if (ret < 0) {
		goto unlock;
	} else if (ret == 1) {
		DRM_DEBUG_DRIVER("HDMI_%d SCDC scrambled\n", hdmi->hdmi_chan);
		drm_scdc_readb(hdmi->ddc, SCDC_STATUS_FLAGS_0, &scdc_flag);
		DRM_DEBUG_DRIVER("HDMI_%d scramble reg(0x40) scdc_flag = 0x%x",
				 hdmi->hdmi_chan, scdc_flag);

		if (scdc_flag == 0xf) {
			if (hdmi->scdc_cnt < 3)
				hdmi->scdc_cnt++;
		} else {
			hdmi->scdc_cnt = 0;
			j9_pangolin(hdmi, 255, J9_UNCLASSIFIED);
		}

		if (hdmi->scdc_cnt == 2)
			j9_pangolin(hdmi, 12, J9_UNCLASSIFIED);

		goto unlock;
	}

	if (!hdmi->output_active)
		goto unlock;

	DRM_DEBUG_DRIVER
		("HDMI_%d SCDC not scrambled, reconfig hdmi phy\n",
		 hdmi->hdmi_chan);
	hdmi->scdc_cnt = 0;
	j9_handle_j9ma_cancerweed(&hdmi->encoder);

unlock:
	if (ret == -EDEADLK) {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 15, 0)
		ret = drm_modeset_backoff(&ctx);
		if (!ret)
			goto retry;
#else
		drm_modeset_backoff(&ctx);
		goto retry;
#endif
	}
	drm_modeset_drop_locks(&ctx);
	drm_modeset_acquire_fini(&ctx);

	schedule_delayed_work(&hdmi->scdc, msecs_to_jiffies(1000));
}

static int j9_handle_j9mirror_presidente(struct drm_connector *connector)
{
	j9_amylo *hdmi = j9_disfranchises(connector);
	int hdmi_chan;
	int ret;
	u8 i2c_ch;


	ret = j9_handle_amphimixes(connector->dev, hdmi->platform, &hdmi->panel,
				   hdmi->key_idx, DRM_MODE_CONNECTOR_HDMIA);
	if (ret < 0)
		return ret;

	i2c_ch = hdmi->hdmi_chan;
	hdmi->ddc = j9_bountifulness(connector->dev, hdmi->platform, i2c_ch);
	if (!hdmi->ddc) {
		DRM_ERROR("Failed to create i2c adapter channel(%d)\n", i2c_ch);
		return -EINVAL;
	}

	j9_handle_attribute_traversals(connector);
	hdmi->audio = j9mirror_affirmable(hdmi->ddev);

	hdmi->connector.interlace_allowed = false;

	hdmi->connector.polled = DRM_CONNECTOR_POLL_HPD;

	INIT_DELAYED_WORK(&hdmi->scdc, j9_boilerworks);
	spin_lock_init(&hdmi->poll.hpd_lock);

	init_waitqueue_head(&hdmi->poll.poll_wait);
	hdmi->poll.wait_cond = 0;
	hdmi->poll.poll_task =
	    kthread_run(j9_handle_demiurgism, hdmi, "HDMI_IRQ_TASK");
	if (IS_ERR(hdmi->poll.poll_task)) {
		DRM_ERROR("unable to create kernel thread: %ld\n",
			  PTR_ERR(hdmi->poll.poll_task));
	}


	hdmi_chan = hdmi->hdmi_chan;
	ret = hdmi->platform->ops->requestIrq(hdmi->platform,
					      J9_PALEOPEDOLOGY + hdmi_chan,
					      j9_handle_j_translater,
					      "jmgpu_hdmi_irq", hdmi);
	if (ret) {
		DRM_ERROR("failed request_irq %d for hdmi-%d\n",
			  J9_PALEOPEDOLOGY + hdmi_chan, hdmi_chan);
	} else {
		hdmi->irq.hdmi_irq_enabled = true;
		j9mirror_qualifying(hdmi);
	}

	return 0;
}

static void j9_handle_j_attribute_desolately(struct drm_connector *connector)
{
	j9_amylo *hdmi = j9_disfranchises(connector);
	int hdmi_chan;

	hdmi_chan = hdmi->hdmi_chan;

	hdmi->platform->ops->freeIrq(hdmi->platform,
				     J9_PALEOPEDOLOGY + hdmi_chan, hdmi);
	kthread_stop(hdmi->poll.poll_task);
	hdmi->poll.poll_task = NULL;

	cancel_delayed_work_sync(&hdmi->scdc);


	if (hdmi->panel)
		j9_handle_j_goodliness(hdmi->panel);
}

static void j9_handle_j9_scrumption(struct drm_connector *conn)
{
	drm_connector_unregister(conn);
	drm_connector_cleanup(conn);
}

static enum drm_connector_status j9_handle_j9m_fossilised(struct drm_connector
							  *conn)
{
	j9_amylo *hdmi = j9_disfranchises(conn);
	enum drm_connector_status conn_state;
	u8 hdmi_chan;

	hdmi_chan = hdmi->hdmi_chan;

	mutex_lock(&hdmi->clk_lock);
	if (hdmi->ddc && j9_antiorthodox(hdmi->ddc)) {
		conn_state = connector_status_connected;
	} else {
		conn_state = j9_nitrite(hdmi, J9_FICTIONALLY) & HDMI_PHY_HPD ?
		    connector_status_connected : connector_status_disconnected;
	}
	mutex_unlock(&hdmi->clk_lock);

	return conn_state;
}

static int j9_handle_j9min_executonis(struct drm_connector *conn,
				      struct drm_modeset_acquire_ctx *ctx,
				      bool force)
{
	j9_amylo *hdmi = j9_disfranchises(conn);

	if (conn->force == DRM_FORCE_OFF)
		return connector_status_disconnected;

	if ((conn->force == DRM_FORCE_ON)
	    || (conn->force == DRM_FORCE_ON_DIGITAL)) {
		return connector_status_connected;
	}

	if (hdmi->edidforce)
		return connector_status_connected;


	j9mirror_paraselene(hdmi->panel);
	hdmi->last_connector_result = j9_handle_j9m_fossilised(conn);

	if (hdmi->last_connector_result == connector_status_disconnected) {

		j9_handle__corymbiate(hdmi->panel);
	}

	return hdmi->last_connector_result;
}

static int j9_handle_j_attribute_overroasts(struct drm_connector *connector, struct drm_display_mode
					    *native_mode)
{
	j9_amylo *hdmi = j9_disfranchises(connector);
	int count = 0;

	if (native_mode) {
		count = drm_add_modes_noedid(&hdmi->connector,
					     native_mode->hdisplay,
					     native_mode->vdisplay);
	}

	return count;
}

static s32 j9_handle_j9ma_tonsilitis(struct drm_connector *conn)
{
	j9_amylo *hdmi = j9_disfranchises(conn);
	struct drm_display_mode *native_mode = NULL;
	struct drm_display_mode *mode = NULL;
	struct edid *edid;
	s32 count = 0;


	j9mirror_paraselene(hdmi->panel);

	if (hdmi->edidforce && hdmi->edid)
		edid = (struct edid *)hdmi->edid;
	else
		edid = drm_get_edid(&hdmi->connector, hdmi->ddc);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0)
	drm_mode_connector_update_edid_property(conn, edid);
#else
	drm_connector_update_edid_property(conn, edid);
#endif
	count = drm_add_edid_modes(conn, edid);

	hdmi->sink_is_hdmi = drm_detect_hdmi_monitor(edid);
	hdmi->sink_has_audio = drm_detect_monitor_audio(edid);
	if (hdmi->sink_has_audio && hdmi->output_active) {
		j9maths_estafetted(hdmi->audio, hdmi->key_idx,
				   hdmi->connector.eld, hdmi->cur_clk_khz,
				   true, true);
	} else {
		if (hdmi->audio) {
			j9maths_estafetted(hdmi->audio, hdmi->key_idx,
					   NULL, 0, false, hdmi->last_connector_result == connector_status_connected);
		}
	}


#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 19, 0) && LINUX_VERSION_CODE < KERNEL_VERSION(5, 1, 0)
	hdmi->rgb_quant_range_selectable = drm_rgb_quant_range_selectable(edid);
#endif
	if (hdmi->zoomEn) {
		j9_handle__attribute_fiducially(hdmi->panel, conn,
						&native_mode);
		count += j9_handle_j_attribute_overroasts(conn, native_mode);
	}

	if (hdmi_enable_prefer_mode_4K30) {
		list_for_each_entry(mode, &conn->probed_modes, head) {
			if (mode->hdisplay == 3840 && mode->vdisplay == 2160
			    && drm_mode_vrefresh(mode) == 30) {
				hdmi->sink_has_4K30 = true;
			}
		}
	}

	if (!hdmi->edidforce)
		kfree(edid);

	return count;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 11, 0)
enum hdmi_quantization_range
drm_default_rgb_quant_range(const struct drm_display_mode *mode)
{

	return drm_match_cea_mode(mode) > 1 ?
	    HDMI_QUANTIZATION_RANGE_LIMITED : HDMI_QUANTIZATION_RANGE_FULL;
}
#endif

#if LINUX_VERSION_CODE <= KERNEL_VERSION(4, 11, 0)
static enum drm_connector_status j9_handle_j_telegnosis(struct drm_connector
							*conn, bool force)
{
	return j9_handle_j9min_executonis(conn, NULL, force);
}
#endif

static enum drm_mode_status j9_handle_j9min_detachedly(struct drm_connector
						       *connector, struct drm_display_mode
						       *mode)
{
	j9_amylo *hdmi = j9_disfranchises(connector);
	j9_weakliest *platform = hdmi->platform;
	jmtUINT64 vram_size = platform->params.vram_size;

	if (!j9_handle_j9maths_promulging(hdmi->panel, mode, vram_size))
		return MODE_CLOCK_HIGH;


	if (hdmi_disable533250 != 0) {
		if (mode->clock >= 533000 && mode->clock <= 534000)
			return MODE_CLOCK_HIGH;
	}

	if (!hdmi->sink_is_hdmi) {
		if (mode->clock >= 165000)
			return MODE_CLOCK_HIGH;
	}

	if (hdmi_enable_prefer_mode_4K30) {

		if (hdmi->sink_has_4K30) {
			if (mode->hdisplay == 3840 && mode->vdisplay == 2160
			    && drm_mode_vrefresh(mode) == 30) {
				mode->type |= DRM_MODE_TYPE_PREFERRED;
			} else {
				mode->type &= ~DRM_MODE_TYPE_PREFERRED;
			}
		}
	}

	return MODE_OK;
}

static const struct drm_connector_helper_funcs jmgpu_hdmi_connector_helper_funcs
= {
	.get_modes = j9_handle_j9ma_tonsilitis,
	.mode_valid = j9_handle_j9min_detachedly,
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 11, 0)
	.detect_ctx = j9_handle_j9min_executonis
#endif
};

static const struct drm_connector_funcs jmgpu_connector_hdmi_funcs = {
	.reset = drm_atomic_helper_connector_reset,
	.fill_modes = drm_helper_probe_single_connector_modes,
	.atomic_duplicate_state = drm_atomic_helper_connector_duplicate_state,
	.atomic_destroy_state = drm_atomic_helper_connector_destroy_state,
	.destroy = j9_handle_j9_scrumption,
#if LINUX_VERSION_CODE <= KERNEL_VERSION(4, 11, 0)
	.detect = j9_handle_j_telegnosis,
	.dpms = drm_atomic_helper_connector_dpms,
	.set_property = drm_atomic_helper_connector_set_property,
#endif
	.late_register = j9_handle_j9mirror_presidente,
	.early_unregister = j9_handle_j_attribute_desolately,
};

static enum drm_mode_status j9_handle_j9mirror_subrectory(struct drm_encoder
							  *crtc, const struct
							  drm_display_mode
							  *mode)
{
	j9_amylo *hdmi = j9_nonveritably(crtc);

	if (mode->clock > 594000)
		return MODE_CLOCK_HIGH;

	if (!hdmi->sink_is_hdmi) {
		if (mode->clock >= 165000)
			return MODE_CLOCK_HIGH;
	}
	return MODE_OK;
}

static int j9_handle__attribute_chockstone(struct drm_encoder *encoder,
					   struct drm_crtc_state *crtc_state,
					   struct drm_connector_state
					   *conn_state)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);
	struct drm_display_mode *native_mode = NULL;

	DRM_DEBUG_DRIVER("%s atomic check\n", encoder->name);

	if (hdmi->zoomEn) {
		native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
		if (!native_mode) {
			DRM_DEBUG_DRIVER
			    ("zoom_enabled but native_mode is invalid\n");
			return -EINVAL;
		}
	}
	return 0;
}

static bool j9mirror_cloddiness(unsigned int bus_format)
{
	switch (bus_format) {
	case MEDIA_BUS_FMT_RGB888_1X24:
	case MEDIA_BUS_FMT_RGB101010_1X30:
	case MEDIA_BUS_FMT_RGB121212_1X36:
	case MEDIA_BUS_FMT_RGB161616_1X48:
		return true;

	default:
		return false;
	}
}

static bool j9_handle_j_hadephobia(unsigned int bus_format)
{
	switch (bus_format) {
	case MEDIA_BUS_FMT_YUV8_1X24:
	case MEDIA_BUS_FMT_YUV10_1X30:
	case MEDIA_BUS_FMT_YUV12_1X36:
	case MEDIA_BUS_FMT_YUV16_1X48:
		return true;

	default:
		return false;
	}
}

static bool j9_handle_j_sobersault(unsigned int bus_format)
{
	switch (bus_format) {
	case MEDIA_BUS_FMT_UYVY8_1X16:
	case MEDIA_BUS_FMT_UYVY10_1X20:
	case MEDIA_BUS_FMT_UYVY12_1X24:
		return true;

	default:
		return false;
	}
}

static bool j9_handle_j_breastless(unsigned int bus_format)
{
	switch (bus_format) {
	case MEDIA_BUS_FMT_UYYVYY8_0_5X24:
	case MEDIA_BUS_FMT_UYYVYY10_0_5X30:
	case MEDIA_BUS_FMT_UYYVYY12_0_5X36:
	case MEDIA_BUS_FMT_UYYVYY16_0_5X48:
		return true;

	default:
		return false;
	}
}

static int j9_handle_j9m_diplacuses(unsigned int bus_format)
{
	switch (bus_format) {
	case MEDIA_BUS_FMT_RGB888_1X24:
	case MEDIA_BUS_FMT_YUV8_1X24:
	case MEDIA_BUS_FMT_UYVY8_1X16:
	case MEDIA_BUS_FMT_UYYVYY8_0_5X24:
		return 8;

	case MEDIA_BUS_FMT_RGB101010_1X30:
	case MEDIA_BUS_FMT_YUV10_1X30:
	case MEDIA_BUS_FMT_UYVY10_1X20:
	case MEDIA_BUS_FMT_UYYVYY10_0_5X30:
		return 10;

	case MEDIA_BUS_FMT_RGB121212_1X36:
	case MEDIA_BUS_FMT_YUV12_1X36:
	case MEDIA_BUS_FMT_UYVY12_1X24:
	case MEDIA_BUS_FMT_UYYVYY12_0_5X36:
		return 12;

	case MEDIA_BUS_FMT_RGB161616_1X48:
	case MEDIA_BUS_FMT_YUV16_1X48:
	case MEDIA_BUS_FMT_UYYVYY16_0_5X48:
		return 16;

	default:
		return 0;
	}
}

static void j9_handle_j_attribute_lionizable(j9_amylo *hdmi)
{
	j9_pangolin(hdmi, HDMI_IH_MUTE_FC_STAT2_OVERFLOW_MASK,
		    J9_HANDLE__NONERODING);
}

static s32 j9_handle_j9min_attribute_demolished(struct drm_encoder *encoder,
						bool enable)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);

	if (enable) {
		if (hdmi->cur_clk_khz > 340000) {
			DRM_DEBUG_DRIVER
			    ("hdmi_%d start scdc work after 1000ms...",
			     hdmi->hdmi_chan);
			hdmi->scdc_cnt = 0;
			schedule_delayed_work(&hdmi->scdc,
					      msecs_to_jiffies(1000));
		}


		j9_handle_marshalman(hdmi, J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
			     0x1 << 28, 0x0 << 28);
		j9_handle_marshalman(hdmi, J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
			     1, 1);
	} else {

		j9_pangolin(hdmi, 2, J9_SLIMMING);
		msleep(50);

		j9_handle_marshalman(hdmi, J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
				     0x1 << 0, 0x0 << 0);
		msleep(50);
		j9_handle_marshalman(hdmi,
				     J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
				     0x1 << 28, 0x1 << 28);
		if (hdmi->cur_clk_khz > 340000) {
			DRM_DEBUG_DRIVER("hdmi_%d stop scdc work...",
					 hdmi->hdmi_chan);
			cancel_delayed_work(&hdmi->scdc);
		}
	}

	return 0;
}


static void j9mirror_rattleweed(j9_amylo *hdmi)
{
	u8 de;

	if (hdmi->hdmi_data.video_mode.mdataenablepolarity)
		de = HDMI_A_VIDPOLCFG_DATAENPOL_ACTIVE_HIGH;
	else
		de = HDMI_A_VIDPOLCFG_DATAENPOL_ACTIVE_LOW;


	j9_garran(hdmi, HDMI_A_HDCPCFG0_RXDETECT_DISABLE,
		  HDMI_A_HDCPCFG0_RXDETECT_MASK, J9_PROTHYSTERON);

	j9_garran(hdmi, de, HDMI_A_VIDPOLCFG_DATAENPOL_MASK, J9_TELECOMPUTING);

	j9_garran(hdmi, HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_DISABLE,
		  HDMI_A_HDCPCFG1_ENCRYPTIONDISABLE_MASK, J9_MULTINUCLEAR);
}


static void j9_handle_j9ma_debasement(j9_amylo *hdmi)
{
	unsigned int count;
	unsigned int i;
	u8 val;


	count = 4;

	j9_pangolin(hdmi, (u8) ~HDMI_MC_SWRSTZ_TMDSSWRST_REQ, J9_LATICOSTATE);

	val = j9_nitrite(hdmi, J9_NONRUINOUSNESS);
	for (i = 0; i < count; i++)
		j9_pangolin(hdmi, val, J9_NONRUINOUSNESS);
}

static void j9_undecompounded(j9_amylo *hdmi)
{
	int color_format = 0;
	u8 val;

	switch (hdmi->hdmi_data.enc_in_bus_format) {
	case MEDIA_BUS_FMT_RGB888_1X24:
		color_format = 0x01;
		break;
	case MEDIA_BUS_FMT_RGB101010_1X30:
		color_format = 0x03;
		break;
	case MEDIA_BUS_FMT_RGB121212_1X36:
		color_format = 0x05;
		break;
	case MEDIA_BUS_FMT_RGB161616_1X48:
		color_format = 0x07;
		break;

	case MEDIA_BUS_FMT_YUV8_1X24:
	case MEDIA_BUS_FMT_UYYVYY8_0_5X24:
		color_format = 0x09;
		break;
	case MEDIA_BUS_FMT_YUV10_1X30:
	case MEDIA_BUS_FMT_UYYVYY10_0_5X30:
		color_format = 0x0B;
		break;
	case MEDIA_BUS_FMT_YUV12_1X36:
	case MEDIA_BUS_FMT_UYYVYY12_0_5X36:
		color_format = 0x0D;
		break;
	case MEDIA_BUS_FMT_YUV16_1X48:
	case MEDIA_BUS_FMT_UYYVYY16_0_5X48:
		color_format = 0x0F;
		break;

	case MEDIA_BUS_FMT_UYVY8_1X16:
		color_format = 0x16;
		break;
	case MEDIA_BUS_FMT_UYVY10_1X20:
		color_format = 0x14;
		break;
	case MEDIA_BUS_FMT_UYVY12_1X24:
		color_format = 0x12;
		break;

	default:
		return;
	}

	val = HDMI_TX_INVID0_INTERNAL_DE_GENERATOR_DISABLE |
	    ((color_format << HDMI_TX_INVID0_VIDEO_MAPPING_OFFSET) &
	     HDMI_TX_INVID0_VIDEO_MAPPING_MASK);
	j9_pangolin(hdmi, val, J9_EXHIBITABLE);


	val = HDMI_TX_INSTUFFING_BDBDATA_STUFFING_ENABLE |
	    HDMI_TX_INSTUFFING_RCRDATA_STUFFING_ENABLE |
	    HDMI_TX_INSTUFFING_GYDATA_STUFFING_ENABLE;
	j9_pangolin(hdmi, val, J9MATHS_ANTERETHIC);
	j9_pangolin(hdmi, 0x0, J9_SEMIELEVATED);
	j9_pangolin(hdmi, 0x0, J9_INTHRALLMENT);
	j9_pangolin(hdmi, 0x0, J9_MOLLUSCICIDAL);
	j9_pangolin(hdmi, 0x0, J9_PURPOSIVENESS);
	j9_pangolin(hdmi, 0x0, J9_UNINVIGORATED);
	j9_pangolin(hdmi, 0x0, J9_NEOPLASTICISM);
}

static void j9_handle_paraselene(j9_amylo *hdmi)
{
	unsigned int color_depth = 0;
	unsigned int remap_size = HDMI_VP_REMAP_YCC422_16bit;
	unsigned int output_select = HDMI_VP_CONF_OUTPUT_SELECTOR_PP;
	struct hdmi_data_info *hdmi_data = &hdmi->hdmi_data;
	u8 val, vp_conf;

	if (j9mirror_cloddiness(hdmi->hdmi_data.enc_out_bus_format) ||
	    j9_handle_j_hadephobia(hdmi->hdmi_data.enc_out_bus_format) ||
	    j9_handle_j_breastless(hdmi->hdmi_data.enc_out_bus_format)) {
		switch (j9_handle_j9m_diplacuses
			(hdmi->hdmi_data.enc_out_bus_format)) {
		case 8:
			color_depth = 4;
			output_select = HDMI_VP_CONF_OUTPUT_SELECTOR_BYPASS;
			break;
		case 10:
			color_depth = 5;
			break;
		case 12:
			color_depth = 6;
			break;
		case 16:
			color_depth = 7;
			break;
		default:
			output_select = HDMI_VP_CONF_OUTPUT_SELECTOR_BYPASS;
		}
	} else if (j9_handle_j_sobersault(hdmi->hdmi_data.enc_out_bus_format)) {
		switch (j9_handle_j9m_diplacuses
			(hdmi->hdmi_data.enc_out_bus_format)) {
		case 0:
		case 8:
			remap_size = HDMI_VP_REMAP_YCC422_16bit;
			break;
		case 10:
			remap_size = HDMI_VP_REMAP_YCC422_20bit;
			break;
		case 12:
			remap_size = HDMI_VP_REMAP_YCC422_24bit;
			break;

		default:
			return;
		}
		output_select = HDMI_VP_CONF_OUTPUT_SELECTOR_YCC422;
	} else {
		return;
	}


	val = ((color_depth << HDMI_VP_PR_CD_COLOR_DEPTH_OFFSET) &
	       HDMI_VP_PR_CD_COLOR_DEPTH_MASK) |
	    ((hdmi_data->pix_repet_factor <<
	      HDMI_VP_PR_CD_DESIRED_PR_FACTOR_OFFSET) &
	     HDMI_VP_PR_CD_DESIRED_PR_FACTOR_MASK);
	j9_pangolin(hdmi, val, J9_POPULARITY);

	j9_garran(hdmi, HDMI_VP_STUFF_PR_STUFFING_STUFFING_MODE,
		  HDMI_VP_STUFF_PR_STUFFING_MASK, J9_PSEUDOSMIA);


	if (hdmi_data->pix_repet_factor > 1) {
		vp_conf = HDMI_VP_CONF_PR_EN_ENABLE |
		    HDMI_VP_CONF_BYPASS_SELECT_PIX_REPEATER;
	} else {
		vp_conf = HDMI_VP_CONF_PR_EN_DISABLE |
		    HDMI_VP_CONF_BYPASS_SELECT_VID_PACKETIZER;
	}

	j9_garran(hdmi, vp_conf,
		  HDMI_VP_CONF_PR_EN_MASK |
		  HDMI_VP_CONF_BYPASS_SELECT_MASK, J9_ACQUAINTS);

	j9_garran(hdmi, 1 << HDMI_VP_STUFF_IDEFAULT_PHASE_OFFSET,
		  HDMI_VP_STUFF_IDEFAULT_PHASE_MASK, J9_PSEUDOSMIA);

	j9_pangolin(hdmi, remap_size, J9_SEMIFLORET);

	if (output_select == HDMI_VP_CONF_OUTPUT_SELECTOR_PP) {
		vp_conf = HDMI_VP_CONF_BYPASS_EN_DISABLE |
		    HDMI_VP_CONF_PP_EN_ENABLE | HDMI_VP_CONF_YCC422_EN_DISABLE;
	} else if (output_select == HDMI_VP_CONF_OUTPUT_SELECTOR_YCC422) {
		vp_conf = HDMI_VP_CONF_BYPASS_EN_DISABLE |
		    HDMI_VP_CONF_PP_EN_DISABLE | HDMI_VP_CONF_YCC422_EN_ENABLE;
	} else if (output_select == HDMI_VP_CONF_OUTPUT_SELECTOR_BYPASS) {
		vp_conf = HDMI_VP_CONF_BYPASS_EN_ENABLE |
		    HDMI_VP_CONF_PP_EN_DISABLE | HDMI_VP_CONF_YCC422_EN_DISABLE;
	} else {
		return;
	}

	j9_garran(hdmi, vp_conf,
		  HDMI_VP_CONF_BYPASS_EN_MASK | HDMI_VP_CONF_PP_EN_ENMASK |
		  HDMI_VP_CONF_YCC422_EN_MASK, J9_ACQUAINTS);

	j9_garran(hdmi, HDMI_VP_STUFF_PP_STUFFING_STUFFING_MODE |
		  HDMI_VP_STUFF_YCC422_STUFFING_STUFFING_MODE,
		  HDMI_VP_STUFF_PP_STUFFING_MASK |
		  HDMI_VP_STUFF_YCC422_STUFFING_MASK, J9_PSEUDOSMIA);

	j9_garran(hdmi, output_select, HDMI_VP_CONF_OUTPUT_SELECTOR_MASK,
		  J9_ACQUAINTS);
}

static void j9_pyroarsenite(j9_amylo *hdmi,
			    struct drm_connector *connector,
			    struct drm_display_mode *mode)
{
	struct hdmi_avi_infoframe frame;
	bool is_hdmi2_sink;
	u8 val;

	is_hdmi2_sink = false;

#if LINUX_VERSION_CODE > KERNEL_VERSION(5, 0, 0)
	drm_hdmi_avi_infoframe_from_display_mode(&frame, connector, mode);
#elif LINUX_VERSION_CODE > KERNEL_VERSION(4, 13, 0)
	drm_hdmi_avi_infoframe_from_display_mode(&frame, mode, true);
#else
	drm_hdmi_avi_infoframe_from_display_mode(&frame, mode);
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 12, 0)
	is_hdmi2_sink = connector->display_info.hdmi.scdc.supported;
#endif
	if (j9mirror_cloddiness(hdmi->hdmi_data.enc_out_bus_format)) {
#if LINUX_VERSION_CODE > KERNEL_VERSION(5, 0, 0)
		drm_hdmi_avi_infoframe_quant_range(&frame, connector, mode,
						   hdmi->hdmi_data.rgb_limited_range ?
						   HDMI_QUANTIZATION_RANGE_LIMITED
						   :
						   HDMI_QUANTIZATION_RANGE_FULL);
#elif LINUX_VERSION_CODE > KERNEL_VERSION(4, 14, 0)
		drm_hdmi_avi_infoframe_quant_range(&frame, mode,
						   hdmi->hdmi_data.rgb_limited_range ?
						   HDMI_QUANTIZATION_RANGE_LIMITED
						   :
						   HDMI_QUANTIZATION_RANGE_FULL,
						   hdmi->rgb_quant_range_selectable,
						   is_hdmi2_sink);
#elif LINUX_VERSION_CODE > KERNEL_VERSION(4, 10, 0)
		drm_hdmi_avi_infoframe_quant_range(&frame, mode,
						   hdmi->hdmi_data.rgb_limited_range ?
						   HDMI_QUANTIZATION_RANGE_LIMITED
						   :
						   HDMI_QUANTIZATION_RANGE_FULL,
						   hdmi->rgb_quant_range_selectable);
#endif
	} else {
		frame.quantization_range = HDMI_QUANTIZATION_RANGE_DEFAULT;
		frame.ycc_quantization_range =
		    HDMI_YCC_QUANTIZATION_RANGE_LIMITED;
	}

	if (j9_handle_j_hadephobia(hdmi->hdmi_data.enc_out_bus_format))
		frame.colorspace = HDMI_COLORSPACE_YUV444;
	else if (j9_handle_j_sobersault(hdmi->hdmi_data.enc_out_bus_format))
		frame.colorspace = HDMI_COLORSPACE_YUV422;
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 0, 0)
	else if (j9_handle_j_breastless(hdmi->hdmi_data.enc_out_bus_format))
		frame.colorspace = HDMI_COLORSPACE_YUV420;
#endif
	else
		frame.colorspace = HDMI_COLORSPACE_RGB;


	if (!j9mirror_cloddiness(hdmi->hdmi_data.enc_out_bus_format)) {
		switch (hdmi->hdmi_data.enc_out_encoding) {
		case V4L2_YCBCR_ENC_601:
			if (hdmi->hdmi_data.enc_in_encoding ==
			    V4L2_YCBCR_ENC_XV601)
				frame.colorimetry = HDMI_COLORIMETRY_EXTENDED;
			else
				frame.colorimetry = HDMI_COLORIMETRY_ITU_601;
			frame.extended_colorimetry =
			    HDMI_EXTENDED_COLORIMETRY_XV_YCC_601;
			break;
		case V4L2_YCBCR_ENC_709:
			if (hdmi->hdmi_data.enc_in_encoding ==
			    V4L2_YCBCR_ENC_XV709)
				frame.colorimetry = HDMI_COLORIMETRY_EXTENDED;
			else
				frame.colorimetry = HDMI_COLORIMETRY_ITU_709;
			frame.extended_colorimetry =
			    HDMI_EXTENDED_COLORIMETRY_XV_YCC_709;
			break;
		default:
			frame.colorimetry = HDMI_COLORIMETRY_ITU_601;
			frame.extended_colorimetry =
			    HDMI_EXTENDED_COLORIMETRY_XV_YCC_601;
			break;
		}
	} else {
		frame.colorimetry = HDMI_COLORIMETRY_NONE;
		frame.extended_colorimetry =
		    HDMI_EXTENDED_COLORIMETRY_XV_YCC_601;
	}


	val = (frame.scan_mode & 3) << 4 | (frame.colorspace & 3);
	if (frame.active_aspect & 15)
		val |= HDMI_FC_AVICONF0_ACTIVE_FMT_INFO_PRESENT;
	if (frame.top_bar || frame.bottom_bar)
		val |= HDMI_FC_AVICONF0_BAR_DATA_HORIZ_BAR;
	if (frame.left_bar || frame.right_bar)
		val |= HDMI_FC_AVICONF0_BAR_DATA_VERT_BAR;
	j9_pangolin(hdmi, val, J9_MYELONEURITIS);


	val = ((frame.colorimetry & 0x3) << 6) |
	    ((frame.picture_aspect & 0x3) << 4) | (frame.active_aspect & 0xf);
	j9_pangolin(hdmi, val, J9_URETHROBULBAR);


	val = ((frame.extended_colorimetry & 0x7) << 4) |
	    ((frame.quantization_range & 0x3) << 2) | (frame.nups & 0x3);
	if (frame.itc)
		val |= HDMI_FC_AVICONF2_IT_CONTENT_VALID;
	j9_pangolin(hdmi, val, J9_AUTOINHIBITED);


	val = frame.video_code & 0x7f;
	j9_pangolin(hdmi, val, J9_CHRYSAROBIN);


	val = (((hdmi->hdmi_data.video_mode.mpixelrepetitioninput + 1) <<
		HDMI_FC_PRCONF_INCOMING_PR_FACTOR_OFFSET) &
	       HDMI_FC_PRCONF_INCOMING_PR_FACTOR_MASK) |
	    ((hdmi->hdmi_data.video_mode.mpixelrepetitionoutput <<
	      HDMI_FC_PRCONF_OUTPUT_PR_FACTOR_OFFSET) &
	     HDMI_FC_PRCONF_OUTPUT_PR_FACTOR_MASK);
	j9_pangolin(hdmi, val, J9_GHOSTFLOWER);

	val = ((frame.ycc_quantization_range & 0x3) << 2) |
	    (frame.content_type & 0x3);
	j9_pangolin(hdmi, val, J9_MONOTONICALLY);


	j9_pangolin(hdmi, frame.top_bar & 0xff, J9_HALLUCINOSES);
	j9_pangolin(hdmi, (frame.top_bar >> 8) & 0xff, J9_FLUOTANTALIC);
	j9_pangolin(hdmi, frame.bottom_bar & 0xff, J9_REEMIGRATION);
	j9_pangolin(hdmi, (frame.bottom_bar >> 8) & 0xff, J9_INDECLINABLY);
	j9_pangolin(hdmi, frame.left_bar & 0xff, J9_SEDUCTRESSES);
	j9_pangolin(hdmi, (frame.left_bar >> 8) & 0xff, J9_CIRCUMCENTER);
	j9_pangolin(hdmi, frame.right_bar & 0xff, J9_NONCERTITUDE);
	j9_pangolin(hdmi, (frame.right_bar >> 8) & 0xff, J9_MALLOSEISMIC);
}

static void j9_handle_j9menu_attribute_mutilating(j9_amylo *hdmi, struct drm_connector
						  *connector,
						  struct drm_display_mode *mode)
{
	struct hdmi_vendor_infoframe frame;
	u8 buffer[10];
	ssize_t err = 0;

#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 16, 0)
	err = drm_hdmi_vendor_infoframe_from_display_mode(&frame, connector,
							  (const struct
							   drm_display_mode *)
							  mode);
#elif LINUX_VERSION_CODE > KERNEL_VERSION(3, 11, 0)
	err = drm_hdmi_vendor_infoframe_from_display_mode(&frame, mode);
#endif
	if (err < 0)
		return;

	err = hdmi_vendor_infoframe_pack(&frame, buffer, sizeof(buffer));
	if (err < 0) {
		DRM_ERROR("Failed to pack vendor infoframe: %zd\n", err);
		return;
	}
	j9_conceitedness(hdmi, 0, J9_MESOPRESCUTAL, HDMI_FC_DATAUTO0_VSD_OFFSET,
			 HDMI_FC_DATAUTO0_VSD_MASK);


	j9_pangolin(hdmi, buffer[2], J9_DISCRIMINANT);


	j9_pangolin(hdmi, buffer[4], J9MATHS_CHATOYANCY);
	j9_pangolin(hdmi, buffer[5], J9MATHS_ACQUIRENDA);
	j9_pangolin(hdmi, buffer[6], J9MATHS_UNCUTTABLE);


	j9_pangolin(hdmi, buffer[7], J9MIRROR_DULCIGENIC);
	j9_pangolin(hdmi, buffer[8], J9MIRROR_PROMULGING);

	if (frame.s3d_struct >= HDMI_3D_STRUCTURE_SIDE_BY_SIDE_HALF)
		j9_pangolin(hdmi, buffer[9], J9MIRROR_PLATYRRHIN);


	j9_pangolin(hdmi, 1, J9_ARCHICEREBRUM);


	j9_pangolin(hdmi, 0x11, J9_PSEUDOLATERAL);


	j9_conceitedness(hdmi, 1, J9_MESOPRESCUTAL, HDMI_FC_DATAUTO0_VSD_OFFSET,
			 HDMI_FC_DATAUTO0_VSD_MASK);
}

static void j9_handle_j9ma_parrotlike(j9_amylo *hdmi,
				      const struct drm_connector *connector)
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(5, 0, 0)
	const struct drm_connector_state *conn_state = connector->state;
	struct hdmi_drm_infoframe frame;
	u8 buffer[30];
	ssize_t err;
	int i;

	j9_garran(hdmi, HDMI_FC_PACKET_TX_EN_DRM_DISABLE,
		  HDMI_FC_PACKET_TX_EN_DRM_MASK, J9_HANDLE_SULPHUROUS);

	err = drm_hdmi_infoframe_set_hdr_metadata(&frame, conn_state);
	if (err < 0)
		return;

	err = hdmi_drm_infoframe_pack(&frame, buffer, sizeof(buffer));
	if (err < 0) {
		DRM_ERROR("Failed to pack drm infoframe: %zd\n", err);
		return;
	}

	j9_pangolin(hdmi, frame.version, J9_UNTORPORIFIC);
	j9_pangolin(hdmi, frame.length, J9_PSEUDOSOCIAL);

	for (i = 0; i < frame.length; i++)
		j9_pangolin(hdmi, buffer[4 + i], J9_SUCCEDANEUMS + i);

	j9_pangolin(hdmi, 1, J9_MARTIALISTS);
	j9_garran(hdmi, HDMI_FC_PACKET_TX_EN_DRM_ENABLE,
		  HDMI_FC_PACKET_TX_EN_DRM_MASK, J9_HANDLE_SULPHUROUS);
#endif
}

static void j9_individuating(j9_amylo *hdmi,
			     const struct drm_display_info *display,
			     const struct drm_display_mode *mode)
{
	u8 inv_val, bytes;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 12, 0)
	const struct drm_hdmi_info *hdmi_info = &display->hdmi;
	u32 low_rates = hdmi_info->scdc.scrambling.low_rates;
#else
	u32 low_rates = 1;
#endif
	struct hdmi_vmode *vmode = &hdmi->hdmi_data.video_mode;
	int hblank, vblank, h_de_hs, v_de_vs, hsync_len, vsync_len;
	unsigned int vdisplay, hdisplay;
	u32 rate;

	vmode->mpixelclock = mode->clock * 1000;

	DRM_DEBUG_DRIVER("final pixclk = %d\n", vmode->mpixelclock);

	vmode->mtmdsclock = vmode->mpixelclock;

	if (!j9_handle_j_sobersault(hdmi->hdmi_data.enc_out_bus_format)) {
		switch (j9_handle_j9m_diplacuses
			(hdmi->hdmi_data.enc_out_bus_format)) {
		case 16:
			vmode->mtmdsclock = vmode->mpixelclock * 2;
			break;
		case 12:
			vmode->mtmdsclock = vmode->mpixelclock * 3 / 2;
			break;
		case 10:
			vmode->mtmdsclock = vmode->mpixelclock * 5 / 4;
			break;
		}
	}

	if (j9_handle_j_breastless(hdmi->hdmi_data.enc_out_bus_format))
		vmode->mtmdsclock /= 2;

	hdmi->cur_clk_khz = vmode->mtmdsclock / 1000;
	DRM_DEBUG_DRIVER("final tmdsclock = %d\n", vmode->mtmdsclock);


	j9_pangolin(hdmi, 1, J9_SLIMMING);


	inv_val = (hdmi->hdmi_data.hdcp_enable ||
		   (j9_handle_j9_translater(hdmi, display) &&
		    (vmode->mtmdsclock > J9MATHS_HANDICRAFT ||
		     low_rates)) ?
		   HDMI_FC_INVIDCONF_HDCP_KEEPOUT_ACTIVE :
		   HDMI_FC_INVIDCONF_HDCP_KEEPOUT_INACTIVE);

	inv_val |= mode->flags & DRM_MODE_FLAG_PVSYNC ?
	    HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_ACTIVE_HIGH :
	    HDMI_FC_INVIDCONF_VSYNC_IN_POLARITY_ACTIVE_LOW;

	inv_val |= mode->flags & DRM_MODE_FLAG_PHSYNC ?
	    HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_ACTIVE_HIGH :
	    HDMI_FC_INVIDCONF_HSYNC_IN_POLARITY_ACTIVE_LOW;

	inv_val |= (vmode->mdataenablepolarity ?
		    HDMI_FC_INVIDCONF_DE_IN_POLARITY_ACTIVE_HIGH :
		    HDMI_FC_INVIDCONF_DE_IN_POLARITY_ACTIVE_LOW);

	if (hdmi->vic == 39)
		inv_val |= HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_HIGH;
	else
		inv_val |= mode->flags & DRM_MODE_FLAG_INTERLACE ?
		    HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_HIGH :
		    HDMI_FC_INVIDCONF_R_V_BLANK_IN_OSC_ACTIVE_LOW;

	inv_val |= mode->flags & DRM_MODE_FLAG_INTERLACE ?
	    HDMI_FC_INVIDCONF_IN_I_P_INTERLACED :
	    HDMI_FC_INVIDCONF_IN_I_P_PROGRESSIVE;

	inv_val |= hdmi->sink_is_hdmi ?
	    HDMI_FC_INVIDCONF_DVI_MODEZ_HDMI_MODE :
	    HDMI_FC_INVIDCONF_DVI_MODEZ_DVI_MODE;

	j9_pangolin(hdmi, inv_val, J9_NONRUINOUSNESS);

	rate = drm_mode_vrefresh(mode) * 1000;
	j9_pangolin(hdmi, rate >> 16, J9_SPHINCTERIAL);
	j9_pangolin(hdmi, rate >> 8, J9_VATICINATION);
	j9_pangolin(hdmi, rate, J9_CHIEFTAINESS);

	j9_handle_marshalman(hdmi,
			     J9_HANDLE_ATTRIBUTE_CHALKSTONE(hdmi->hdmi_chan),
			     0x1 << 9,
			     ((mode->flags & DRM_MODE_FLAG_PHSYNC) ? 1 : 0) <<
			     9);
	j9_handle_marshalman(hdmi,
			     J9_HANDLE_ATTRIBUTE_CHALKSTONE(hdmi->hdmi_chan),
			     0x1 << 8,
			     ((mode->flags & DRM_MODE_FLAG_PVSYNC) ? 1 : 0) <<
			     8);

	j9_handle_marshalman(hdmi,
			     J9_HANDLE_ATTRIBUTE_CHALKSTONE(hdmi->hdmi_chan),
			     0x1 << 10, vmode->mdataenablepolarity << 10);

	hdisplay = mode->hdisplay;
	hblank = mode->htotal - mode->hdisplay;
	h_de_hs = mode->hsync_start - mode->hdisplay;
	hsync_len = mode->hsync_end - mode->hsync_start;

	if (j9_handle_j_breastless(hdmi->hdmi_data.enc_out_bus_format)) {
		hdisplay /= 2;
		hblank /= 2;
		h_de_hs /= 2;
		hsync_len /= 2;
	}

	vdisplay = mode->vdisplay;
	vblank = mode->vtotal - mode->vdisplay;
	v_de_vs = mode->vsync_start - mode->vdisplay;
	vsync_len = mode->vsync_end - mode->vsync_start;

	if (mode->flags & DRM_MODE_FLAG_INTERLACE) {
		vdisplay /= 2;
		vblank /= 2;
		v_de_vs /= 2;
		vsync_len /= 2;
	}


	if (j9_handle_j9_translater(hdmi, display)) {
		if (vmode->mtmdsclock > J9MATHS_HANDICRAFT || low_rates) {
			drm_scdc_readb(hdmi->ddc, SCDC_SINK_VERSION, &bytes);
			drm_scdc_writeb(hdmi->ddc, SCDC_SOURCE_VERSION,
					min_t(u8, bytes,
					      SCDC_MIN_SOURCE_VERSION));


			drm_scdc_set_scrambling(&hdmi->connector, 1);
			j9_pangolin(hdmi, (u8) ~HDMI_MC_SWRSTZ_TMDSSWRST_REQ,
				    J9_LATICOSTATE);
			j9_pangolin(hdmi, 1, J9_HANDLE_J_PERIOSTOMA);
		} else {
			j9_pangolin(hdmi, 0, J9_HANDLE_J_PERIOSTOMA);
			j9_pangolin(hdmi, (u8) ~HDMI_MC_SWRSTZ_TMDSSWRST_REQ,
				    J9_LATICOSTATE);
			drm_scdc_set_scrambling(&hdmi->connector, 0);
		}
	}


	j9_pangolin(hdmi, hdisplay >> 8, J9_COMPANIONSHIP);
	j9_pangolin(hdmi, hdisplay, J9_PRELIQUIDATED);


	j9_pangolin(hdmi, vdisplay >> 8, J9_TRICHOSCHISIS);
	j9_pangolin(hdmi, vdisplay, J9_SEMIOSTRACISM);


	j9_pangolin(hdmi, hblank >> 8, J9_PROTOAMPHIBIAN);
	j9_pangolin(hdmi, hblank, J9_TRIDIMENSIONED);


	j9_pangolin(hdmi, vblank >> 8, J9_DESTRUCTIONISM);
	j9_pangolin(hdmi, vblank, J9_SEMITRADITONAL);


	j9_pangolin(hdmi, h_de_hs >> 8, J9_HANDLE__PLATYRRHIN);
	j9_pangolin(hdmi, h_de_hs, J9_HANDLE__PROMULGING);


	j9_pangolin(hdmi, v_de_vs >> 8, J9_HANDLE__ELEMENTISH);
	j9_pangolin(hdmi, v_de_vs, J9_HANDLE__AMPHIMIXES);


	j9_pangolin(hdmi, hsync_len >> 8, J9_HANDLE__ANTHRAMINE);
	j9_pangolin(hdmi, hsync_len, J9_HANDLE__OMMATIDIUM);


	j9_pangolin(hdmi, vsync_len, J9_HANDLE_NONSERVILE);
}

static void j9_handle_j9maths_osmolality(struct drm_encoder *encoder,
					 u32 crtc_chan)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);


	j9_handle_marshalman(hdmi, J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
			     0b11 << 4, crtc_chan << 4);

}

static int j9_handle_j9ma_mineworker(j9_amylo *hdmi)
{
	struct hdmi_data_info *hdmi_data = &hdmi->hdmi_data;
	bool is_input_rgb, is_output_rgb;

	is_input_rgb = j9mirror_cloddiness(hdmi_data->enc_in_bus_format);
	is_output_rgb = j9mirror_cloddiness(hdmi_data->enc_out_bus_format);

	return (is_input_rgb != is_output_rgb) ||
	    (is_input_rgb && is_output_rgb && hdmi_data->rgb_limited_range);
}

static int j9_handle_j9ma_scythework(j9_amylo *hdmi)
{
	if (!j9_handle_j_sobersault(hdmi->hdmi_data.enc_out_bus_format))
		return 0;

	if (j9mirror_cloddiness(hdmi->hdmi_data.enc_in_bus_format) ||
	    j9_handle_j_hadephobia(hdmi->hdmi_data.enc_in_bus_format))
		return 1;

	return 0;
}

static int j9_handle_j9maths_corrosives(j9_amylo *hdmi)
{
	if (!j9_handle_j_sobersault(hdmi->hdmi_data.enc_in_bus_format))
		return 0;

	if (j9mirror_cloddiness(hdmi->hdmi_data.enc_out_bus_format) ||
	    j9_handle_j_hadephobia(hdmi->hdmi_data.enc_out_bus_format))
		return 1;

	return 0;
}

static bool j9_homography(j9_amylo *hdmi)
{
	return j9_handle_j9ma_mineworker(hdmi) ||
	    j9_handle_j9ma_scythework(hdmi) ||
	    j9_handle_j9maths_corrosives(hdmi);
}

static void j9_handle_j9maths_polyporite(j9_amylo *hdmi)
{
	const u16(*csc_coeff)[3][4] = &csc_coeff_default;
	bool is_input_rgb, is_output_rgb;
	unsigned int i;
	u32 csc_scale = 1;

	is_input_rgb = j9mirror_cloddiness(hdmi->hdmi_data.enc_in_bus_format);
	is_output_rgb = j9mirror_cloddiness(hdmi->hdmi_data.enc_out_bus_format);

	if (!is_input_rgb && is_output_rgb) {
		if (hdmi->hdmi_data.enc_out_encoding == V4L2_YCBCR_ENC_601)
			csc_coeff = &csc_coeff_rgb_out_eitu601;
		else
			csc_coeff = &csc_coeff_rgb_out_eitu709;
	} else if (is_input_rgb && !is_output_rgb) {
		if (hdmi->hdmi_data.enc_out_encoding == V4L2_YCBCR_ENC_601)
			csc_coeff = &csc_coeff_rgb_in_eitu601;
		else
			csc_coeff = &csc_coeff_rgb_in_eitu709;
		csc_scale = 0;
	} else if (is_input_rgb && is_output_rgb &&
		   hdmi->hdmi_data.rgb_limited_range) {
		csc_coeff = &csc_coeff_rgb_full_to_rgb_limited;
	}


	for (i = 0; i < ARRAY_SIZE(csc_coeff_default[0]); i++) {
		u16 coeff_a = (*csc_coeff)[0][i];
		u16 coeff_b = (*csc_coeff)[1][i];
		u16 coeff_c = (*csc_coeff)[2][i];

		j9_pangolin(hdmi, coeff_a & 0xff, J9_HANDLE_ECSTATICAL + i * 2);
		j9_pangolin(hdmi, coeff_a >> 8, J9_HANDLE_PLOTTINGLY + i * 2);
		j9_pangolin(hdmi, coeff_b & 0xff, J9_HANDLE_MANEUVERER + i * 2);
		j9_pangolin(hdmi, coeff_b >> 8, J9_HANDLE_CITYNESSES + i * 2);
		j9_pangolin(hdmi, coeff_c & 0xff, J9_HANDLE_ABRIDGABLE + i * 2);
		j9_pangolin(hdmi, coeff_c >> 8, J9_HANDLE_DIPROTODAN + i * 2);
	}

	j9_garran(hdmi, csc_scale, HDMI_CSC_SCALE_CSCSCALE_MASK,
		  J9_UNHONORABLE);
}

static void j9_sectarianly(j9_amylo *hdmi)
{
	int color_depth = 0;
	int interpolation = HDMI_CSC_CFG_INTMODE_DISABLE;
	int decimation = 0;


	if (j9_handle_j9maths_corrosives(hdmi))
		interpolation = HDMI_CSC_CFG_INTMODE_CHROMA_INT_FORMULA1;
	else if (j9_handle_j9ma_scythework(hdmi))
		decimation = HDMI_CSC_CFG_DECMODE_CHROMA_INT_FORMULA3;

	switch (j9_handle_j9m_diplacuses(hdmi->hdmi_data.enc_out_bus_format)) {
	case 8:
		color_depth = HDMI_CSC_SCALE_CSC_COLORDE_PTH_24BPP;
		break;
	case 10:
		color_depth = HDMI_CSC_SCALE_CSC_COLORDE_PTH_30BPP;
		break;
	case 12:
		color_depth = HDMI_CSC_SCALE_CSC_COLORDE_PTH_36BPP;
		break;
	case 16:
		color_depth = HDMI_CSC_SCALE_CSC_COLORDE_PTH_48BPP;
		break;

	default:
		return;
	}


	j9_pangolin(hdmi, interpolation | decimation, J9_FANFISHES);
	j9_garran(hdmi, color_depth, HDMI_CSC_SCALE_CSC_COLORDE_PTH_MASK,
		  J9_UNHONORABLE);

	j9_handle_j9maths_polyporite(hdmi);
}


static void j9_handle_j9maths_succussion(j9_amylo *hdmi)
{
	struct hdmi_vmode *vmode = &hdmi->hdmi_data.video_mode;


	if (vmode->mtmdsclock > J9MATHS_HANDICRAFT)
		j9_pangolin(hdmi, 255, J9_UNCLASSIFIED);
	else
		j9_pangolin(hdmi, 12, J9_UNCLASSIFIED);

	j9_pangolin(hdmi, 32, J9_DIFFERENTIATOR);
	j9_pangolin(hdmi, 1, J9MATHS_DIVINENESS);


	j9_pangolin(hdmi, 0x0B, J9_UNTHEORETICAL);
	j9_pangolin(hdmi, 0x16, J9_PROPOLIZATION);
	j9_pangolin(hdmi, 0x21, J9_APOTHEOSIZING);


	hdmi->mc_clkdis |= HDMI_MC_CLKDIS_HDCPCLK_DISABLE |
	    HDMI_MC_CLKDIS_CSCCLK_DISABLE |
	    HDMI_MC_CLKDIS_AUDCLK_DISABLE |
	    HDMI_MC_CLKDIS_PREPCLK_DISABLE | HDMI_MC_CLKDIS_TMDSCLK_DISABLE;
	hdmi->mc_clkdis &= ~HDMI_MC_CLKDIS_PIXELCLK_DISABLE;
	j9_pangolin(hdmi, hdmi->mc_clkdis, J9_BIOCOENOSIS);

	hdmi->mc_clkdis &= ~HDMI_MC_CLKDIS_TMDSCLK_DISABLE;
	j9_pangolin(hdmi, hdmi->mc_clkdis, J9_BIOCOENOSIS);


	if (j9_homography(hdmi)) {
		hdmi->mc_clkdis &= ~HDMI_MC_CLKDIS_CSCCLK_DISABLE;
		j9_pangolin(hdmi, hdmi->mc_clkdis, J9_BIOCOENOSIS);

		j9_pangolin(hdmi, HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_CSC_IN_PATH,
			    J9_EPITHALAMIAST);
	} else {
		hdmi->mc_clkdis |= HDMI_MC_CLKDIS_CSCCLK_DISABLE;
		j9_pangolin(hdmi, hdmi->mc_clkdis, J9_BIOCOENOSIS);

		j9_pangolin(hdmi, HDMI_MC_FLOWCTRL_FEED_THROUGH_OFF_CSC_BYPASS,
			    J9_EPITHALAMIAST);
	}
}

static void j9_handle_j9min_serologist(j9_amylo *hdmi,
				       struct drm_display_mode *mode)
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 11, 0)
	struct drm_connector *conn = &hdmi->connector;
	struct drm_display_info *info = &conn->display_info;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 0, 0)
	struct drm_connector_state *conn_state = conn->state;
	u8 max_bpc = conn_state->max_requested_bpc;
#else
	u8 max_bpc = 32;
#endif
	bool is_hdmi2_sink = info->hdmi.scdc.supported ||
	    (info->color_formats & DRM_COLOR_FORMAT_YCBCR420);
	u32 *output_fmts;
	unsigned int i = 0, num_output_fmts;

	num_output_fmts = 0;
	output_fmts = kcalloc(J9_HANDLE_J_BEFORENESS, sizeof(*output_fmts),
			      GFP_KERNEL);
	if (!output_fmts)
		return;

	if (conn->ycbcr_420_allowed &&
	    (drm_mode_is_420_only(info, mode) ||
	     (is_hdmi2_sink && drm_mode_is_420_also(info, mode)))) {


		if (max_bpc >= 16 && info->bpc == 16 &&
		    (info->hdmi.y420_dc_modes & DRM_EDID_YCBCR420_DC_48))
			output_fmts[i++] = MEDIA_BUS_FMT_UYYVYY16_0_5X48;

		if (max_bpc >= 12 && info->bpc >= 12 &&
		    (info->hdmi.y420_dc_modes & DRM_EDID_YCBCR420_DC_36))
			output_fmts[i++] = MEDIA_BUS_FMT_UYYVYY12_0_5X36;

		if (max_bpc >= 10 && info->bpc >= 10 &&
		    (info->hdmi.y420_dc_modes & DRM_EDID_YCBCR420_DC_30))
			output_fmts[i++] = MEDIA_BUS_FMT_UYYVYY10_0_5X30;


		output_fmts[i++] = MEDIA_BUS_FMT_UYYVYY8_0_5X24;

		num_output_fmts = i;
		for (i = 0; i < num_output_fmts; i++) {
			DRM_DEBUG_DRIVER
			    ("hdmi_%d 420 %d num_output_fmts = 0x%x",
			     hdmi->hdmi_chan, i, output_fmts[i]);
		}
		goto release;
	}


	if (max_bpc >= 16 && info->bpc == 16) {
		if (info->color_formats & DRM_COLOR_FORMAT_YCBCR444)
			output_fmts[i++] = MEDIA_BUS_FMT_YUV16_1X48;

		output_fmts[i++] = MEDIA_BUS_FMT_RGB161616_1X48;
	}

	if (max_bpc >= 12 && info->bpc >= 12) {
		if (info->color_formats & DRM_COLOR_FORMAT_YCBCR422)
			output_fmts[i++] = MEDIA_BUS_FMT_UYVY12_1X24;

		if (info->color_formats & DRM_COLOR_FORMAT_YCBCR444)
			output_fmts[i++] = MEDIA_BUS_FMT_YUV12_1X36;

		output_fmts[i++] = MEDIA_BUS_FMT_RGB121212_1X36;
	}

	if (max_bpc >= 10 && info->bpc >= 10) {
		if (info->color_formats & DRM_COLOR_FORMAT_YCBCR422)
			output_fmts[i++] = MEDIA_BUS_FMT_UYVY10_1X20;

		if (info->color_formats & DRM_COLOR_FORMAT_YCBCR444)
			output_fmts[i++] = MEDIA_BUS_FMT_YUV10_1X30;

		output_fmts[i++] = MEDIA_BUS_FMT_RGB101010_1X30;
	}

	if (info->color_formats & DRM_COLOR_FORMAT_YCBCR422)
		output_fmts[i++] = MEDIA_BUS_FMT_UYVY8_1X16;

	if (info->color_formats & DRM_COLOR_FORMAT_YCBCR444)
		output_fmts[i++] = MEDIA_BUS_FMT_YUV8_1X24;


	output_fmts[i++] = MEDIA_BUS_FMT_RGB888_1X24;

	num_output_fmts = i;

	for (i = 0; i < num_output_fmts; i++) {
		DRM_DEBUG_DRIVER("hdmi_%d %d num_output_fmts = 0x%x",
				 hdmi->hdmi_chan, i, output_fmts[i]);
	}

release:


	DRM_DEBUG_DRIVER("select intput format = 0x%x, output format = 0x%x",
			 hdmi->hdmi_data.enc_in_bus_format,
			 hdmi->hdmi_data.enc_out_bus_format);
	kfree(output_fmts);
	output_fmts = NULL;
#endif
}

static s32 j9_handle_j9menu_dauphiness(struct drm_encoder *encoder, u32 clk_idx)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);
	u32 val, mask;

	mask = 0b111 << (8 + hdmi->hdmi_chan * 4);
	val = clk_idx << (8 + hdmi->hdmi_chan * 4);
	j9_handle_marshalman(hdmi, MWV207REG_TOP_VO_CFG_3, mask, val);
	J9_STORMCOCK(150);

	return 0;
}

static void j9_handle_j9ma_cancerweed(struct drm_encoder *encoder)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);
	struct drm_connector *connector = &hdmi->connector;
	struct drm_display_mode *target_mode;
	struct drm_display_mode *native_mode;
	u8 hdmi_chan;

	DRM_DEBUG_DRIVER("%s atomic enable\n", encoder->name);
	if (IS_ERR_OR_NULL(hdmi->connector.state->crtc)) {
		DRM_DEBUG_DRIVER("error crtc addr %pK\n",
				hdmi->connector.state->crtc);
		return;
	}

	if (IS_ERR_OR_NULL(&hdmi->connector.state->crtc->mode)) {
		DRM_DEBUG_DRIVER("error crtc mode addr %pK\n",
				&hdmi->connector.state->crtc->mode);
		return;
	}

	hdmi->output_active = true;

	hdmi_chan = hdmi->hdmi_chan;
	j9mirror_paraselene(hdmi->panel);

	hdmi->cur_crtc = drm_crtc_index(hdmi->connector.state->crtc);
	target_mode = &hdmi->connector.state->crtc->mode;

	native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
	if (hdmi->zoomEn && native_mode)
		target_mode = native_mode;

	j9_handle_j9maths_osmolality(encoder, hdmi->cur_crtc);
	j9_handle_j9menu_dauphiness(encoder, hdmi->cur_crtc);
	j9_handle_j_attribute_lionizable(hdmi);

	hdmi->hdmi_data.enc_in_bus_format = MEDIA_BUS_FMT_FIXED;
	hdmi->hdmi_data.enc_out_bus_format = MEDIA_BUS_FMT_FIXED;
	j9_handle_j9min_serologist(hdmi, target_mode);

	hdmi->vic = drm_match_cea_mode(target_mode);

	if (!hdmi->vic)
		DRM_DEBUG_DRIVER("Non-CEA mode used in HDMI\n");
	else
		DRM_DEBUG_DRIVER("CEA mode used vic=%d\n", hdmi->vic);

	if ((hdmi->vic == 6) || (hdmi->vic == 7) ||
	    (hdmi->vic == 21) || (hdmi->vic == 22) ||
	    (hdmi->vic == 2) || (hdmi->vic == 3) ||
	    (hdmi->vic == 17) || (hdmi->vic == 18))
		hdmi->hdmi_data.enc_out_encoding = V4L2_YCBCR_ENC_601;
	else
		hdmi->hdmi_data.enc_out_encoding = V4L2_YCBCR_ENC_709;

	hdmi->hdmi_data.video_mode.mpixelrepetitionoutput = 0;
	hdmi->hdmi_data.video_mode.mpixelrepetitioninput = 0;

	if (hdmi->hdmi_data.enc_in_bus_format == MEDIA_BUS_FMT_FIXED)
		hdmi->hdmi_data.enc_in_bus_format = MEDIA_BUS_FMT_RGB888_1X24;


	hdmi->hdmi_data.enc_in_encoding = V4L2_YCBCR_ENC_DEFAULT;

	if (hdmi->hdmi_data.enc_out_bus_format == MEDIA_BUS_FMT_FIXED)
		hdmi->hdmi_data.enc_out_bus_format = MEDIA_BUS_FMT_RGB888_1X24;

	hdmi->hdmi_data.rgb_limited_range = hdmi->sink_is_hdmi &&
	    drm_default_rgb_quant_range(target_mode) ==
	    HDMI_QUANTIZATION_RANGE_LIMITED;

	hdmi->hdmi_data.pix_repet_factor = 0;
	hdmi->hdmi_data.hdcp_enable = 0;
	hdmi->hdmi_data.video_mode.mdataenablepolarity = true;


	j9_individuating(hdmi, &connector->display_info, target_mode);

	j9_handle_j9min_attribute_demolished(encoder, true);


	j9_troglodyte(hdmi, &connector->display_info);


	j9_handle_j9maths_succussion(hdmi);


	if (hdmi->sink_is_hdmi) {
		DRM_DEBUG_DRIVER("HDMI mode\n");


		j9_pyroarsenite(hdmi, connector, target_mode);
		j9_handle_j9menu_attribute_mutilating(hdmi, connector,
						      target_mode);
		j9_handle_j9ma_parrotlike(hdmi, connector);
	} else {
		DRM_DEBUG_DRIVER("DVI mode\n");
	}

	j9_handle_paraselene(hdmi);
	j9_sectarianly(hdmi);
	j9_undecompounded(hdmi);
	j9mirror_rattleweed(hdmi);

	j9_handle_j9ma_debasement(hdmi);

	j9maths_nonfascist(hdmi->panel);

	if (hdmi->sink_has_audio) {
		j9maths_estafetted(hdmi->audio, hdmi->key_idx,
				   hdmi->connector.eld, hdmi->cur_clk_khz,
				   true, true);
		DRM_DEBUG_DRIVER("sink has audio support\n");
	}

	DRM_DEBUG_DRIVER("%s mode(%dx%d) bind crtc_%d\n",
			 encoder->name, target_mode->hdisplay,
			 target_mode->vdisplay, hdmi->cur_crtc);
}

static void j9_handle_j_attribute_beguileful(j9_amylo *hdmi)
{
	u32 va_mem_base;

	if (!hdmi)
		return;

	va_mem_base = J9_AMBILATERALITY(hdmi->cur_crtc);

	j9_crosshatched(hdmi, va_mem_base + j9maths_prepiously, 0);

	j9_crosshatched(hdmi, va_mem_base + j9_handle_j9min_undertribe, 0);
	j9_crosshatched(hdmi, va_mem_base + j9_malalignment, 3);
	j9_crosshatched(hdmi, va_mem_base + j9maths_prepiously, 1);
}

static void j9_handle_j9min_cloacaline(struct drm_encoder *encoder)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);
	u8 hdmi_chan;
	bool hw_connected =
	    hdmi->last_connector_result == connector_status_connected;

	hdmi->output_active = false;

	DRM_DEBUG_DRIVER("%s atomic disable\n", encoder->name);

	hdmi_chan = hdmi->hdmi_chan;
	j9mirror_madbrained(hdmi->panel);
	if (hdmi->sink_has_audio) {
		j9maths_estafetted(hdmi->audio, hdmi->key_idx,
				   NULL, 0, false, hw_connected);
		DRM_DEBUG_DRIVER("sink has no audio support\n");
	}

	j9_handle_j_attribute_beguileful(hdmi);
	j9_handle_j9min_attribute_demolished(encoder, false);
	j9_handle__corymbiate(hdmi->panel);
}

static void j9_handle_unfeelable(struct drm_encoder *encoder)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);

	mutex_lock(&hdmi->clk_lock);
	j9_handle_marshalman(hdmi, MWV207REG_TOP_VO_CFG_2,
			     0x10 << hdmi->hdmi_chan, 0);
	j9_handle_marshalman(hdmi, MWV207REG_TOP_VO_CFG_1,
			     0x10 << hdmi->hdmi_chan, 0);
	msleep(20);
	j9_handle_marshalman(hdmi, MWV207REG_TOP_VO_CFG_1,
			     0x10 << hdmi->hdmi_chan, 0x10 << hdmi->hdmi_chan);
	j9_handle_marshalman(hdmi, MWV207REG_TOP_VO_CFG_2,
			     0x10 << hdmi->hdmi_chan, 0x10 << hdmi->hdmi_chan);
	mutex_unlock(&hdmi->clk_lock);
}

static void j9_handle_j9m_dispurpose(struct drm_encoder *encoder)
{
	j9_amylo *hdmi = j9_nonveritably(encoder);
	j9_weakliest *platform = hdmi->platform;
	j9_duopoly status;
	u8 hdmi_chan;

	DRM_DEBUG_DRIVER("%s atomic reset", encoder->name);

	hdmi_chan = hdmi->hdmi_chan;

	if (hdmi->irq.hdmi_irq_enabled) {
		status =
		    platform->ops->enableIrq(platform,
					     J9_PALEOPEDOLOGY + hdmi_chan, 0);
		if (status != J9_FLUTTERING)
			DRM_WARN("failed to disable hdmi interrupt");
		else
			msleep(1);
	}

	j9_handle_unfeelable(encoder);
	j9_handle_marshalman(hdmi, J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
			     0x1 << 0, 0x0 << 0);
	msleep(50);
	j9_handle_marshalman(hdmi, J9_HANDLE_J_INTERESTER(hdmi->hdmi_chan),
			     0x1 << 28, 0x1 << 28);
	if (hdmi->irq.hdmi_irq_enabled) {
		j9mirror_qualifying(hdmi);
		status =
		    platform->ops->enableIrq(platform,
					     J9_PALEOPEDOLOGY + hdmi_chan, 1);
		if (status != J9_FLUTTERING)
			DRM_WARN("failed to enable hdmi interrupt");
	}
}

static const struct drm_encoder_funcs jmgpu_encoder_funcs = {
	.reset = j9_handle_j9m_dispurpose,
	.destroy = drm_encoder_cleanup,
};

static const struct drm_encoder_helper_funcs jmgpu_encoder_helper_funcs = {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 13, 0)
	.mode_valid = j9_handle_j9mirror_subrectory,
#endif
	.atomic_check = j9_handle__attribute_chockstone,
	.enable = j9_handle_j9ma_cancerweed,
	.disable = j9_handle_j9min_cloacaline,
};

int j9mirror_lixiviated(struct drm_device *ddev, j9_weakliest *platform,
			u32 key_idx, u32 hdmi_chan)
{
	j9_amylo *hdmi;
	u32 possible_crtcs;
	u32 zoom_mask;
	int ret;

	hdmi = devm_kzalloc(ddev->dev, sizeof(j9_amylo), GFP_KERNEL);
	if (!hdmi)
		return -ENOMEM;

	hdmi->ddev = ddev;
	hdmi->platform = platform;
	hdmi->key_idx = key_idx;
	hdmi->hdmi_chan = hdmi_chan;

	hdmi->mem_base  = J9_HANDLE_J9MIN_BURSECTOMY(hdmi->hdmi_chan);
	mutex_init(&hdmi->clk_lock);

	zoom_mask = j9_handle_j9_goodliness(ddev);
	hdmi->zoomEn   = j9_handle_j9maths_dulcigenic(ddev, hdmi->key_idx);
	possible_crtcs = (1 << j9_handle_j_tubiporoid(ddev)) - 1;
	if (zoom_mask) {

		if (hdmi->zoomEn) {
			hdmi->encoder.possible_crtcs = 0x1;
		} else {
			hdmi->encoder.possible_crtcs = J9_MDSE(possible_crtcs, 0);
		}
	} else {
		hdmi->encoder.possible_crtcs = possible_crtcs;
	}


	ret = drm_connector_init(ddev, &hdmi->connector,
				 &jmgpu_connector_hdmi_funcs,
				 DRM_MODE_CONNECTOR_HDMIA);
	if (ret)
		return ret;

	drm_connector_helper_add(&hdmi->connector,
				 &jmgpu_hdmi_connector_helper_funcs);

	ret = drm_encoder_init(ddev, &hdmi->encoder, &jmgpu_encoder_funcs,
			       DRM_MODE_ENCODER_TMDS, "hdmi-%d",
			       hdmi->hdmi_chan);
	if (ret)
		return ret;

	drm_encoder_helper_add(&hdmi->encoder, &jmgpu_encoder_helper_funcs);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 19, 0)
	ret =
	    drm_mode_connector_attach_encoder(&hdmi->connector, &hdmi->encoder);
#else
	ret = drm_connector_attach_encoder(&hdmi->connector, &hdmi->encoder);
#endif
	if (ret)
		return ret;

	return drm_connector_register(&hdmi->connector);
}


