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


#include <linux/version.h>
#include <linux/delay.h>
#include <drm/drm_atomic.h>
#include <linux/moduleparam.h>
#include <drm/drm_crtc.h>
#include <drm/drm_atomic_helper.h>
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 6, 0)
#include <drm/drm_vblank.h>
#include <drm/drm_print.h>
#endif
#include "jmgpu_garbage.h"
#include "jmgpu_messages.h"
#include "jmgpu_console.h"
#include "jmgpu_package.h"
#include "jmgpu_livelock.h"
#include "mwv207_driver.h"
#include "mwv207reg_procedure.h"

#define J9_HANDLE__COMBUSTING 42
#define JMD_MWV207_PALETTE_MAX_NUM 1024

#define j9_transmittance(crtc) container_of(crtc, j9_raced, base)

static int fake_vblank;
module_param(fake_vblank, int, 0644);
MODULE_PARM_DESC(fake_vblank, "use hw or sw to generate vblank, "\
		 "0x0 - use interrupt, 0x1 - use software timer");

/*
 * 用户态 gamma ramp 归一化系数（写 LUT 前的额外缩放）.
 *
 * 历史: 观测到 X 下发的 identity ramp 采样为 [0,21,42,64,85](=in/3),
 * 一度判定为 X 专有驱动 (mwv207_drv.so) 的 gamma 缩放缺陷, 并用
 * gamma_norm=3 在内核侧乘回去补偿.
 *
 * 2026-09-11 定位到真实根因: 是本驱动的 color-mgmt 契约不一致 ——
 * drm_crtc_enable_color_mgmt(crtc, 768, true, 768) 宣称 gamma_lut_size=768
 * (厂商把"3 通道 x 256"当成一个 LUT 的项数), 而 atomic_flush 只读前 256 项,
 * 于是客户端下发的 768 项 identity ramp 只有前 1/3 生效(数值恰为 in/3).
 * 已在 jmgpu_crtc_init 中把契约统一为 256, X 侧无需任何改动, 故默认值改回
 * "原样写"(1); gamma_norm=3 仅在使用旧契约(768)的模块上有意义.
 *
 * gamma_norm=1(默认): 原样写 LUT —— 契约修正后这就是正确行为.
 * gamma_norm=0: 完全跳过用户态 gamma (LUT 恒为 reset 时的线性表, 亮度调节失效).
 * gamma_norm=3: 对 ramp 乘 3 归一化, 用于复现/兼容旧的 768 契约.
 */
static int gamma_norm = 1;
module_param(gamma_norm, int, 0644);
MODULE_PARM_DESC(gamma_norm, "extra scaling applied to the userspace gamma "\
		 "ramp before writing the LUT: 0=skip userspace gamma, "\
		 "1=apply as-is (default, correct now that GAMMA_LUT_SIZE is "\
		 "consistent), 3=compensate the historical 768-entry contract "\
		 "truncation (debug)");

/*
 * 每通道 gamma LUT 表项数.
 * 这个值必须同时用于三处，否则会出现"契约/消费"不一致:
 *   1) drm_crtc_enable_color_mgmt() 对外宣称的 gamma_lut_size;
 *   2) jcrtc->lutdata 的每通道布局 (lutdata + rgb * N);
 *   3) atomic_flush 里从 drm_color_lut 读出的项数.
 * 历史事故: 厂商把 (1) 写成 768 (误把"3 通道 x 256"当成一个 LUT 的项数),
 * 而 (3) 只读 256 —— 客户端下发的 ramp 只有前 1/3 进硬件, 整屏压暗
 * ("黑发灰/白不白"), 长期被误判为 X 驱动的 gamma 缺陷.
 */
#define JMGPU_LUT_ENTRIES_PER_CHANNEL 256

typedef struct tag_jms_crtc {
	struct drm_crtc base;
	j9_weakliest *platform;
	struct drm_pending_vblank_event *event;
	struct hrtimer vblank_timer;
	u32 mem_base;
	u16 lutdata[3 * JMGPU_LUT_ENTRIES_PER_CHANNEL];
	u8 crtc_chan;


	spinlock_t lock;
} j9_raced;

static inline void j9_resurrective(struct drm_crtc *crtc, u32 addr, u32 val)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	j9_weakliest *platform = jcrtc->platform;

	J9_CRISPY(addr, val);
}

static inline void j9_garboils(struct drm_crtc *crtc, u32 offset, u32 val)
{
	j9_raced *jcrtc = j9_transmittance(crtc);

	j9_resurrective(crtc, jcrtc->mem_base + offset, val);
}

static inline void j9_handle_reentering(struct drm_crtc *crtc, u32 addr,
					u32 mask, u32 val)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	j9_weakliest *platform = jcrtc->platform;

	J9_UNPERFECTLY(addr, mask, val);
}

static inline u32 j9_mildfulness(struct drm_crtc *crtc, u32 addr)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	j9_weakliest *platform = jcrtc->platform;

	return J9_NICOLS(addr);
}

static inline u32 j9_tunnels(struct drm_crtc *crtc, u32 offset)
{
	j9_raced *jcrtc = j9_transmittance(crtc);

	return j9_mildfulness(crtc, jcrtc->mem_base + offset);
}


static enum hrtimer_restart jmgpu_vkms_crtc_finish_page_flip_func(struct hrtimer *timer)
{
	j9_raced *pl = container_of(timer, j9_raced, vblank_timer);
	struct drm_crtc *crtc = &pl->base;
	int put_vblank = false;
	unsigned long flags;

	drm_crtc_handle_vblank(crtc);

	if (pl->event) {
		spin_lock_irqsave(&crtc->dev->event_lock, flags);
		drm_crtc_send_vblank_event(crtc, pl->event);
		pl->event = NULL;
		spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
		put_vblank = true;
	}

	if (put_vblank) {
		drm_crtc_vblank_put(crtc);
	}

	hrtimer_forward_now(timer, ns_to_ktime(1000000000 / drm_mode_vrefresh(&crtc->state->mode)));
	return HRTIMER_RESTART;
}

static void jmgpu_vkms_vblank_timer_init(j9_raced *pl)
{
	hrtimer_init(&pl->vblank_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	pl->vblank_timer.function = jmgpu_vkms_crtc_finish_page_flip_func;
#if LINUX_VERSION_CODE <= KERNEL_VERSION(5, 14, 0) || IS_ENABLED(CONFIG_DRM_LEGACY)
	pl->base.dev->irq_enabled = true;
#endif
}

void jmgpu_vkms_crtc_finish_page_flip(struct drm_crtc *crtc)
{

}

static inline s32 jmgpu_vkms_crtc_set_vblank(struct drm_crtc *crtc, bool enable)
{
	j9_raced *pl = j9_transmittance(crtc);
	if (enable) {
		hrtimer_start(&pl->vblank_timer, ms_to_ktime(0), HRTIMER_MODE_REL);
	} else {
		hrtimer_cancel(&pl->vblank_timer);
	}

	return 0;
}

static s32 jmgpu_vkms_crtc_enable_vblank(struct drm_crtc *crtc)
{
	return jmgpu_vkms_crtc_set_vblank(crtc, true);
}

static void jmgpu_vkms_crtc_disable_vblank(struct drm_crtc *crtc)
{
	jmgpu_vkms_crtc_set_vblank(crtc, false);
}

void j9_handle_j9maths_stringiest(struct drm_crtc *crtc)
{
	struct drm_pending_vblank_event *event = crtc->state->event;
	j9_raced *jcrtc = j9_transmittance(crtc);
	unsigned long flags;

	if (event) {
		if (crtc->state->active) {
			WARN_ON(drm_crtc_vblank_get(crtc) != 0);
			spin_lock_irqsave(&crtc->dev->event_lock, flags);
			jcrtc->event = event;
			spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
		} else {
			spin_lock_irqsave(&crtc->dev->event_lock, flags);
			drm_crtc_send_vblank_event(crtc, crtc->state->event);
			spin_unlock_irqrestore(&crtc->dev->event_lock, flags);
		}
		crtc->state->event = NULL;
	}
}

static void j9_handle_j9menu_cuckolding(struct drm_crtc *crtc)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	int put_vblank = false;
	unsigned long flags;

	spin_lock_irqsave(&crtc->dev->event_lock, flags);
	if (jcrtc->event) {
		drm_crtc_send_vblank_event(crtc, jcrtc->event);
		jcrtc->event = NULL;
		put_vblank = true;
	}
	spin_unlock_irqrestore(&crtc->dev->event_lock, flags);

	if (put_vblank)
		drm_crtc_vblank_put(crtc);

}

static void jmgpu_crtc_set_overlay(struct drm_crtc *crtc)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	u32 window_base;
	u32 value;
	u64 addr_overlay;
	u64 addr_graph;
	u32 graph_stride;
	u32 graph_width;
	u32 winxreg;
	u32 cut_x_fix;
	int posX, posY;
	int hotX = 0;
	int hotY = 0;

	posX = crtc->cursor->state->crtc_x;
	posY = crtc->cursor->state->crtc_y;

	if (posX == 0 && posY == 0)
		return;

	if (posX < 0) {
		hotX = -posX;
		posX = 0;
	}
	if (posY < 0) {
		hotY = -posY;
		posY = 0;
	}

	window_base = J9_NEUROPARALYTIC(jcrtc->crtc_chan);
	addr_graph = j9_tunnels(crtc, J9_VERSIFICATOR);
	graph_stride = j9_tunnels(crtc, J9_ACCOMPLICESHIP);
	addr_overlay =
	    (addr_graph << 6) + ((posX & 0xFFFF) << 2) +
	    (posY & 0xFFFF) * (graph_stride << 4);
	cut_x_fix = 0;
	if ((addr_overlay & 0xFFF) > 3839) {
		addr_overlay -= 768;
		cut_x_fix = 192;
	}
	j9_resurrective(crtc, window_base + J9_HANDLE_J9_EVENTUATED,
			addr_overlay >> 6);

	value = (hotX & 0x3F) | ((hotY & 0x3F) << 16);
	j9_garboils(crtc, J9_SCOREKEEPING, value);

	value = (posX & 0xFFFF) | ((posY & 0xFFFF) << 16);
	j9_garboils(crtc, J9_ANTEAMBULATE, value);
	j9_resurrective(crtc, window_base + J9_BIREFRINGENCE, value);

	winxreg = (addr_overlay & 0x3F) >> 2;
	winxreg += cut_x_fix;
	value = ((winxreg + 63) | 0x3) | (0x3F << 16);
	j9_resurrective(crtc, window_base + J9_HERPETOGRAPHY, value);

	value = j9_mildfulness(crtc, window_base + J9MIRROR_CLEANLIEST);
	value &= (0xFFFF << 16);
	value |= winxreg;
	j9_resurrective(crtc, window_base + J9MIRROR_CLEANLIEST, value);

	value = j9_tunnels(crtc, j9_stockholdings);
	graph_width = value >> 16;
	value = (0x3F << 16);
	value |=
	    ((graph_width - 63) >=
	     (posX & 0xFFFF)) ? 63 : (graph_width - (posX & 0xFFFF));
	j9_resurrective(crtc, window_base + J9MIRROR_PLOTTINGLY, value);

	jmgpu_plane_cursor_win_update(crtc->cursor);
}

static void j9_handle_j9maths_sulphurous(j9_raced *jcrtc)
{
	j9_weakliest *platform = jcrtc->platform;

	platform->ops->freeIrq(platform, J9_HANDLE__COMBUSTING, jcrtc);
}

static int j9_handle_j9menu_plottingly(struct drm_crtc *crtc, bool enable)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	unsigned long flags;
	u32 channel_idx;
	u32 value;

	spin_lock_irqsave(&jcrtc->lock, flags);
	channel_idx = jcrtc->crtc_chan;
	value = j9_mildfulness(crtc, J9_HANDLE_J9M_OUTSAVORED + J9_ACKMEN);
	if (enable) {
		value |= 1 << (12 + channel_idx);
	} else {
		value &= ~(1 << (12 + channel_idx));
	}
	j9_resurrective(crtc, J9_HANDLE_J9M_OUTSAVORED + J9_ACKMEN, value);

	value = j9_mildfulness(crtc, J9_HANDLE_J9M_OUTSAVORED + J9_FOOTCLOTHS);
	if (enable) {
		value |= 1 << (12 + channel_idx);
	} else {
		value &= ~(1 << (12 + channel_idx));
	}
	j9_resurrective(crtc, J9_HANDLE_J9M_OUTSAVORED + J9_FOOTCLOTHS, value);

	spin_unlock_irqrestore(&jcrtc->lock, flags);
	return 0;
}

static inline s32 j9_handle__cenotaphic(struct drm_crtc *crtc, bool enable)
{
	s32 ret;

	ret = j9_handle_j9menu_plottingly(crtc, enable);
	if (ret) {
		DRM_ERROR("failed to %s vblank on %s, ret = %d\n",
			  enable ? "enable" : "disable", crtc->name, ret);
	}
	DRM_DEBUG_VBL("%s vblank state is %s!",
		      crtc->name, enable ? "enabled" : "disabled");
	return ret;
}

static s32 j9_handle_j9m_smoothback(struct drm_crtc *crtc)
{
	if (jmgpu_kms_vdisplay_is_enable(crtc->dev) || fake_vblank)
		return jmgpu_vkms_crtc_enable_vblank(crtc);

	return j9_handle__cenotaphic(crtc, true);
}

static void j9_handle_j9ma_politicise(struct drm_crtc *crtc)
{
	if (jmgpu_kms_vdisplay_is_enable(crtc->dev) || fake_vblank)
		jmgpu_vkms_crtc_disable_vblank(crtc);
	else
		j9_handle__cenotaphic(crtc, false);
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 12, 0)
s32 j9_handle_j9maths_outpursued(struct drm_device *dev, unsigned int pipe)
{
	struct drm_crtc *crtc = NULL;
	u32 i = 0;

	drm_for_each_crtc(crtc, dev) {
		if (i == pipe)
			break;

		i++;
	}

	if (jmgpu_kms_vdisplay_is_enable(crtc->dev) || fake_vblank)
		return jmgpu_vkms_crtc_enable_vblank(crtc);
	else
		return j9_handle__cenotaphic(crtc, true);
}

void j9_handle_j9mirror_outwriggle(struct drm_device *dev, unsigned int pipe)
{
	struct drm_crtc *crtc = NULL;
	u32 i = 0;

	drm_for_each_crtc(crtc, dev) {
		if (i == pipe)
			break;

		i++;
	}

	j9_handle__cenotaphic(crtc, false);
}
#endif

static bool j9_handle__trignesses(struct drm_crtc *crtc,
				  struct drm_display_mode *mode,
				  struct drm_display_mode *native_mode)
{
	s32 vsync;
	u32 width;
	u32 dst_htotal;
	u32 dst_vsync;
	u32 dst_vbp;
	u32 hbackporch;
	u32 hfrontporch;
	u32 hsync;
	bool zoom_enable;

	if (!mode || !native_mode)
		return false;


	if (native_mode->crtc_hdisplay == 0 || native_mode->crtc_vdisplay == 0) {
		DRM_DEBUG_DRIVER("zoom enabled while native mode is invalid");
		return false;
	}

	hbackporch = 2;
	hsync = 2;
	hfrontporch = native_mode->hsync_start - native_mode->hdisplay;
	width = mode->hdisplay;
	vsync = (5201 + width + hfrontporch + hbackporch + hsync) /
	    (width + hfrontporch + hbackporch + hsync) - 1;

	dst_htotal = native_mode->htotal;
	dst_vsync = native_mode->vsync_end - native_mode->vsync_start;
	dst_vbp = native_mode->vtotal - native_mode->vsync_end;

	zoom_enable = (vsync > (s32) ((dst_htotal * (dst_vsync + dst_vbp)) /
				      (3 *
				       (width + hfrontporch + hbackporch +
					hsync)) - 4)) ? false : true;

	return zoom_enable;
}

static int j9_handle_attribute_drearihead(struct drm_crtc *crtc,
					  struct drm_crtc_state *state)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	struct drm_display_mode *target_mode = NULL;
	struct drm_display_mode *native_mode = NULL;
	struct drm_encoder *encoder;

	DRM_DEBUG_DRIVER("%s atomic check", crtc->name);

	drm_for_each_encoder_mask(encoder, crtc->dev, crtc->state->encoder_mask) {
		if (!drm_encoder_crtc_ok(encoder, crtc)) {
			DRM_ERROR("%s should not bind current %s!",
				  crtc->name, encoder->name);
			return -EINVAL;
		}
	}

	if (jcrtc->crtc_chan >= crtc->dev->mode_config.num_crtc) {
		DRM_DEBUG_DRIVER("max crtc is %d, but crtc_chan is %d",
				 crtc->dev->mode_config.num_crtc - 1,
				 jcrtc->crtc_chan);
		return -EINVAL;
	}
	if (jcrtc->crtc_chan != drm_crtc_index(crtc)) {
		DRM_DEBUG_DRIVER
		    ("invalid crtc chan, crtc index and crtc_chan match failure");
		return -EINVAL;
	}

	if (jcrtc->crtc_chan == 0) {
		target_mode = &crtc->state->mode;
		native_mode = j9_handle_j9ma_sinuousity(crtc->dev);
		if (native_mode) {
			if (!j9_handle__trignesses
			    (crtc, target_mode, native_mode)) {
				DRM_DEBUG_DRIVER
				    ("%s zoom_enabled! but this mode is invalid!",
				     crtc->name);
				return -EINVAL;
			}
		}
	}

	return 0;
}
static s32 jmgpu_crtc_wait_lut_fifo(struct drm_crtc *crtc)
{
	int i;

	for (i = 0; j9_tunnels(crtc, J9_HANDLE_J9_OVERKEENLY) > 0
	     && i < 120; ++i) {
		msleep(1);
	}
	if (i >= 120) {
		DRM_ERROR("ERROR:Timeout waiting for lut fifo");
		return -1;
	} else {
		return 0;
	}
}

static s32 j9_handle__autoclasis(struct drm_crtc *crtc)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	u32 i;
	u32 ram;
	u32 window_base;
	u32 rgb;
	u32 curPaletteRam;
	u32 value;
	u16 *data = NULL;
	u16 *pWriteData = NULL;

	window_base = J9_NEUROPARALYTIC(jcrtc->crtc_chan);

	value = j9_mildfulness(crtc, MWV207REG_TOP_VA_UNIT_CFG_3);
	value |= 1 << (16 + jcrtc->crtc_chan);
	j9_resurrective(crtc, MWV207REG_TOP_VA_UNIT_CFG_3, value);

	data = jcrtc->lutdata;
	value = j9_tunnels(crtc, J9_URUGUAYANS);
	value &= ~(1 << 31);
	j9_garboils(crtc, J9_URUGUAYANS, value);

	value = data[384] * 15 / 8;
	value |= (1 << 31);
	j9_resurrective(crtc, window_base + J9_GASTALDITE, value);

	/* palette RAM 为双缓冲: 必须像开源栈 mwv207_va_lut_enable 一样把两块
	 * RAM 全部写入. 原实现只写当前 active RAM 就把 active 切到另一块
	 * (从未写过) -> 实际显示走的是那块 RAM 的上电默认内容, 而非线性表,
	 * 造成整体低对比度(黑发灰/白不白). 每轮先重新读 active, 写完切换,
	 * 两轮后 active 回到初始 RAM, 且两块内容均为 lutdata 线性表. */
	for (ram = 0; ram < 2; ram++) {
		curPaletteRam = j9_tunnels(crtc, J9_HANDLE_J9_CELIOSCOPY);
		for (rgb = 0; rgb < 3; rgb++) {
			j9_garboils(crtc, J9_HANDLE_BESMUTTING, rgb);
			pWriteData = data + rgb * JMGPU_LUT_ENTRIES_PER_CHANNEL;
			j9_garboils(crtc, J9_HANDLE_J_CELIOSCOPY, 1);
			udelay(2);
			j9_garboils(crtc, J9_HANDLE_J_CELIOSCOPY, 0);
			udelay(2);
			mb();
			for (i = 0; i < JMD_MWV207_PALETTE_MAX_NUM; i++) {

				if ((i % 10 == 0)
						&& jmgpu_crtc_wait_lut_fifo(crtc)) {
					DRM_ERROR("crtc_%u: lut fifo timeout writing ram %u rgb %u",
						  jcrtc->crtc_chan, ram, rgb);
					return -2;
				}
				mb();


				value = (pWriteData[i / 4] << 2) | 0x03;
				if (value > 1024 - 5)
					value = 1024 - 5;

				j9_garboils(crtc, J9_HANDLE_POSTLUDIUM, value);
				mb();
			}
			if (jmgpu_crtc_wait_lut_fifo(crtc)) {
				DRM_ERROR("crtc_%u: lut fifo drain timeout after ram %u rgb %u",
					  jcrtc->crtc_chan, ram, rgb);
				return -2;
			}
			mb();
		}
		j9_garboils(crtc, J9_HANDLE_J9_CELIOSCOPY, 1 - curPaletteRam);
	}

	return 0;
}

static void j9_handle_attribute_chockstone(struct drm_crtc *crtc, struct drm_crtc_state
					   *old_crtc_state)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	struct drm_color_lut *lut;
	u16 i;

	DRM_DEBUG_DRIVER("%s atomic flush", crtc->name);

	if (jmgpu_kms_vdisplay_is_enable(crtc->dev))
		return;

	if (crtc->state->color_mgmt_changed) {
		if (crtc->state->gamma_lut) {
			DRM_DEBUG_DRIVER("%s set lut color", crtc->name);

			lut =
			    (struct drm_color_lut *)crtc->state->gamma_lut->data;
			/*
			 * 消费项数必须等于 jmgpu_crtc_init 宣称的
			 * GAMMA_LUT_SIZE（JMGPU_LUT_ENTRIES_PER_CHANNEL），
			 * 否则客户端下发的 ramp 只会有一部分生效：历史上契约写成
			 * 768 而这里只读 256，于是 768 项 identity ramp 的前 1/3
			 * （采样恰为 0,21,42,64,85 = in/3）进了硬件，整屏被压到
			 * 1/3 动态范围，表现为"黑发灰、白不白、色相正确"。
			 */
			BUILD_BUG_ON(3 * JMGPU_LUT_ENTRIES_PER_CHANNEL >
				     ARRAY_SIZE(jcrtc->lutdata));
			for (i = 0; i < JMGPU_LUT_ENTRIES_PER_CHANNEL; i++) {
				jcrtc->lutdata[i] =
				    drm_color_lut_extract(lut[i].red, 8);
				jcrtc->lutdata[i + JMGPU_LUT_ENTRIES_PER_CHANNEL] =
				    drm_color_lut_extract(lut[i].green, 8);
				jcrtc->lutdata[i + 2 * JMGPU_LUT_ENTRIES_PER_CHANNEL] =
				    drm_color_lut_extract(lut[i].blue, 8);
			}
			if (crtc->state->gamma_lut->length !=
			    JMGPU_LUT_ENTRIES_PER_CHANNEL *
			    sizeof(struct drm_color_lut))
				DRM_WARN("crtc_%u: gamma blob %zu bytes != %u entries\n",
					 jcrtc->crtc_chan,
					 crtc->state->gamma_lut->length,
					 JMGPU_LUT_ENTRIES_PER_CHANNEL);
			/* 诊断: 打印下发 ramp 的采样值（内核已归一化到 8 位）.
			 * 契约正确时应为线性 0,64,128,192,255；
			 * 若仍是 0,21,42,64,85 说明又出现了契约/消费不一致，或
			 * gamma_norm 仍为旧的补偿值 3. */
			DRM_INFO("crtc_%u gamma_lut updated: R[0,64,128,192,255]=%u,%u,%u,%u,%u G=%u,%u,%u,%u,%u B=%u,%u,%u,%u,%u\n",
				 jcrtc->crtc_chan,
				 jcrtc->lutdata[0], jcrtc->lutdata[64],
				 jcrtc->lutdata[128], jcrtc->lutdata[192],
				 jcrtc->lutdata[255],
				 jcrtc->lutdata[256], jcrtc->lutdata[320],
				 jcrtc->lutdata[384], jcrtc->lutdata[448],
				 jcrtc->lutdata[511],
				 jcrtc->lutdata[512], jcrtc->lutdata[576],
				 jcrtc->lutdata[640], jcrtc->lutdata[704],
				 jcrtc->lutdata[767]);
			if (gamma_norm == 0) {
				static bool skip_reported;
				if (!skip_reported) {
					DRM_INFO("jmgpu: gamma_norm=0, skip applying userspace gamma ramp (keep identity LUT)\n");
					skip_reported = true;
				}
			} else {
				if (gamma_norm > 1) {
					/* 归一化: 补偿 X 专有驱动的 1/3 缩放缺陷.
					 * 恒等 ramp 恢复线性(修灰滤镜), 用户
					 * 亮度/gamma 调节按真实意图生效. */
					for (i = 0; i < 3 * 256; i++) {
						u32 v = (u32)jcrtc->lutdata[i]
							* gamma_norm;
						if (v > 255)
							v = 255;
						jcrtc->lutdata[i] = v;
					}
				}
				j9_handle__autoclasis(crtc);
			}
		}
	}
}

static int j9maths_petroxolin(struct drm_crtc *crtc, u32 channel_idx)
{
	u32 value;

	value = j9_mildfulness(crtc, J9_HANDLE_J9M_OUTSAVORED + J9_CYCLOOLEFIN);

	if (!(value & (1 << (channel_idx + 1))))
		return 0;


	if (!(value & (1 << (channel_idx + 5))))
		return 0;


	if (!(value & (1 << (channel_idx + 9))))
		return 0;


	return 1;
}

static s32 j9_handle_j9menu_cleanliest(struct drm_crtc *crtc)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	u32 channel_idx = jcrtc->crtc_chan;
	u32 val_cfg1, val_cfg2, val_cfg3;
	u32 window_base;
	unsigned long tick;

	window_base = J9_NEUROPARALYTIC(channel_idx);
	j9_resurrective(crtc, window_base + J9_HANDLE_J9_40000, 0);
	j9_garboils(crtc, J9_LUXURIATES, 0);
	j9_resurrective(crtc, window_base + J9_HANDLE_PARAPSIDAL, 0);
	j9_resurrective(crtc, window_base + J9MATHS_RIFLEPROOF, 0);

	val_cfg1 = j9_mildfulness(crtc, MWV207REG_TOP_VA_UNIT_CFG_1);
	val_cfg2 = j9_mildfulness(crtc, MWV207REG_TOP_VA_UNIT_CFG_2);
	val_cfg3 = j9_mildfulness(crtc, MWV207REG_TOP_VA_UNIT_CFG_3);

	if (val_cfg1 != 0 || val_cfg2 != 0 || val_cfg3 != 0) {
		J9_SPODOGENOUS(tick, !j9maths_petroxolin(crtc, channel_idx),
			       100) {
			msleep(4);
		}
		if (!j9maths_petroxolin(crtc, channel_idx)) {
			DRM_ERROR("va wait idle timeout, val:0x%x",
				  j9_mildfulness(crtc,
						 J9_HANDLE_J9M_OUTSAVORED +
						 J9_CYCLOOLEFIN));
		}
	}

	j9_handle_reentering(crtc, MWV207REG_TOP_VA_UNIT_CFG_3,
			     0x1 << (16 + channel_idx), 0);
	udelay(10);
	j9_handle_reentering(crtc, MWV207REG_TOP_VA_UNIT_CFG_3,
			     0x1 << channel_idx, 0);
	udelay(1);

	return 0;
}

static void j9_handle_j9mirror_inoculable(struct drm_crtc *crtc)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	u32 channel_idx = jcrtc->crtc_chan;

	j9_handle_reentering(crtc, MWV207REG_TOP_VA_UNIT_CFG_3,
			     0x1 << channel_idx, 0x1 << channel_idx);
	udelay(10);
	j9_handle_reentering(crtc, MWV207REG_TOP_VA_UNIT_CFG_3,
			     0x1 << (16 + channel_idx),
			     0x1 << (16 + channel_idx));
	msleep(1);
}

static int j9_handle_j9min_spodogenic(struct drm_crtc *crtc)
{
	u32 value;

	value = j9_tunnels(crtc, j9_malalignment);
	value &= ~((1 << 1) | (1 << 2));
	value |= (1 << 0);
	j9_garboils(crtc, j9_malalignment, value);
	return 0;

}

static int j9_handle__chrysaline(struct drm_crtc *crtc, j9_observandum *timing)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	j9_weakliest *platform = jcrtc->platform;
	u32 value;
	u32 hblankbegin;
	u32 hblankend;
	u32 hsbegin;
	u32 hsend;
	u32 htotal;
	u32 hhalf;
	u32 vblankbegin;
	u32 vblankend;
	u32 vsbegin;
	u32 vsend;
	u32 vtotal;
	u32 vblank_1field_begin;
	u32 vblank_1field_end;
	u32 vs_1field_begin;
	u32 vs_1field_end;
	u32 vblank_2field_begin;
	u32 vblank_2field_end;
	u32 vs_2field_begin;
	u32 vs_2field_end;

	if (j9_handle_chockstone(&j9_paleomagnetist(platform)->pcie_info)) {
		timing->htotal += 2 * 8192;
		timing->hfrontporch += 2 * 8192;
	}
	hblankbegin = 0;
	hblankend = timing->htotal - timing->hactive;
	htotal = timing->htotal;
	hsbegin = timing->hfrontporch;
	hsend = timing->hfrontporch + timing->hsync;
	hhalf =
	    (timing->is_interleaved) ? (htotal / 2 +
					timing->hfrontporch) : htotal / 2;
	vblankbegin = 0;
	vblankend = timing->vtotal - timing->vactive;

	vblank_1field_begin = 0;
	vblank_1field_end = (timing->is_interleaved) ?
	    ((timing->vtotal - timing->vactive) * 2)
	    : (timing->vtotal - timing->vactive);

	vblank_2field_begin =
	    (timing->vactive + (timing->vtotal - timing->vactive)) * 2;
	vblank_2field_end =
	    (timing->vactive + (timing->vtotal - timing->vactive)) * 2 +
	    (timing->vtotal - timing->vactive + 1) * 2;

	vsbegin = timing->vfrontporch;
	vsend = timing->vfrontporch + timing->vsync;

	vs_1field_begin = (timing->is_interleaved)
	    ? (timing->vfrontporch * 2) : (timing->vfrontporch);
	vs_1field_end = (timing->is_interleaved)
	    ? ((timing->vfrontporch + timing->vsync) * 2)
	    : (timing->vfrontporch + timing->vsync);
	vs_2field_begin =
	    (timing->vactive + (timing->vtotal - timing->vactive)) * 2 +
	    timing->vfrontporch * 2 + 1;
	vs_2field_end =
	    (timing->vactive + (timing->vtotal - timing->vactive)) * 2 +
	    (timing->vfrontporch + timing->vsync) * 2 + 1;
	vtotal = (timing->is_interleaved)
	    ? ((timing->vactive * 2 + (timing->vtotal - timing->vactive) * 2 +
		1) * 2)
	    : timing->vtotal;

	value = hsbegin | (hsend << 16);
	j9_garboils(crtc, J9_OPHTHALMOTROPE, value);

	value = hblankbegin | (hblankend << 16);
	j9_garboils(crtc, J9_HANDLE__INDIGENOUS, value);

	value = htotal | (hhalf << 16);
	j9_garboils(crtc, J9_INEVASIBLENESS, value);

	value = vblank_1field_begin | (vblank_1field_end << 16);
	j9_garboils(crtc, J9_HANDLE_J9MATHS_OVEREXPAND, value);

	value = vblank_1field_begin | (vblank_1field_end << 16);
	j9_garboils(crtc, J9_HANDLE_J_ATTRIBUTE_PHLEBOLOGY, value);

	value = vblank_2field_begin | (vblank_2field_end << 16);
	j9_garboils(crtc, J9_HANDLE_J9MATHS_LEPROLOGIC, value);

	value = vblank_2field_begin | (vblank_2field_end << 16);
	j9_garboils(crtc, J9_HANDLE_J_ATTRIBUTE_CALCIFUGAL, value);

	value = vs_1field_begin | (vs_1field_end << 16);
	j9_garboils(crtc, J9_HANDLE_J9M_HOUSESMITH, value);

	value = vs_2field_begin | (vs_2field_end << 16);
	j9_garboils(crtc, J9_HANDLE_J9M_COENOTYPIC, value);

	value = j9_tunnels(crtc, J9_HANDLE_J9MENU_40000);
	value = value & 0xFFFF0000;
	value |= vtotal;
	j9_garboils(crtc, J9_HANDLE_J9MENU_40000, value);

	value = timing->is_interleaved;
	if (timing->is_interleaved && timing->hactive == 1440)
		value |= 0x2;

	j9_garboils(crtc, J9_UNRECOUNTABLE, value);
	j9_garboils(crtc, J9_LUXURIATES, 1);

	return j9_handle_j9min_spodogenic(crtc);
}

static void j9_handle_j9maths_cryohydric(struct drm_crtc *crtc,
					 j9_observandum *timing)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	struct mutex *reset_lock;

	reset_lock = j9_handle_j9m_devoration(crtc->dev);
	mutex_lock(reset_lock);
	j9_handle_j9menu_cleanliest(crtc);
	jcrtc->platform->ops->set_pll(jcrtc->platform, jcrtc->crtc_chan + 1,
				      timing->clk_khz);
	j9_handle_j9mirror_inoculable(crtc);
	mutex_unlock(reset_lock);


	j9_handle__attribute_chalkstone(crtc->primary);
	j9_handle__chrysaline(crtc, timing);
}

static void j9_handle_j9ma_cordwainer(struct drm_crtc *crtc,
				      struct drm_display_mode *orig_mode,
				      struct drm_display_mode *native_mode)
{
	j9_observandum orig_timing;
	j9_observandum target_timing;
	u32 value;
	u32 vbackporch;
	u32 hbackporch;
	u32 vfrontporch;
	u32 hfrontporch;
	u32 vsync;
	u32 hsync;
	u32 width;
	u32 height;
	u32 scaleup_width;
	u32 scaleup_height;

	if (native_mode->crtc_hdisplay == 0 || native_mode->crtc_vdisplay == 0) {
		DRM_ERROR("native_mode is invalid");
		return;
	}
	if (orig_mode->crtc_hdisplay == 0 || orig_mode->crtc_vdisplay == 0) {
		DRM_ERROR("orig_mode is invalid");
		return;
	}

	j9_handle_attribute_amidstream(&orig_timing, orig_mode);
	j9_handle_attribute_amidstream(&target_timing, native_mode);

	width = orig_timing.hactive;
	height = orig_timing.vactive;
	scaleup_width = target_timing.hactive;
	scaleup_height = target_timing.vactive;

	if (scaleup_width == width && scaleup_height == height)
		return;


	DRM_DEBUG_DRIVER("scaleup: frome %dx%d to %dx%d",
			 orig_timing.hactive, orig_timing.vactive,
			 target_timing.hactive, target_timing.vactive);

	vbackporch = 2;
	hbackporch = 2;
	hsync = 2;
	vfrontporch = target_timing.vfrontporch;
	hfrontporch = target_timing.hfrontporch;
	vsync = (5201 + width + hfrontporch + hbackporch + hsync) /
	    (width + hfrontporch + hbackporch + hsync) - 1;

	j9_garboils(crtc, j9maths_prepiously, 0);

	value = j9_tunnels(crtc, j9_malalignment);
	value &= ~((1 << 2) | (1 << 1) | (1 << 0));
	j9_garboils(crtc, j9_malalignment, value);

	value = ((height - 1) << 16) | (width - 1);
	j9_garboils(crtc, j9_handle__apozemical, value);


	value = (vbackporch << 16) | hbackporch;
	j9_garboils(crtc, j9_handle_j9m_eventuated, value);

	value = (vsync << 16) | hsync;
	j9_garboils(crtc, j9_handle_j_redoubting, value);

	value = (vfrontporch << 16) | hfrontporch;
	j9_garboils(crtc, j9_handle_j9m_nonnitrous, value);

	value = ((scaleup_height - 1) << 16) | (scaleup_width - 1);
	j9_garboils(crtc, j9maths_cordwainer, value);

	value = 65536 * (width - 1) / (scaleup_width - 1);
	j9_garboils(crtc, j9_handle_j_emmenology, value);

	value = 65536 * (height - 1) / (scaleup_height - 1);
	j9_garboils(crtc, j9_handle_j_damfoolish, value);

	j9_garboils(crtc, j9maths_prepiously, 1);

	return;
}

static void j9_handle__attribute_principium(struct drm_crtc *crtc, struct drm_crtc_state
					    *old_crtc_state)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	j9_observandum crtc_timing;
	struct drm_display_mode *target_mode = NULL;
	struct drm_display_mode *native_mode = NULL;

	DRM_DEBUG_DRIVER("%s atomic enable\n", crtc->name);

	target_mode = &crtc->state->mode;
	if (jmgpu_kms_vdisplay_is_enable(crtc->dev))
		goto out;

	if (jcrtc->crtc_chan == 0) {
		native_mode = j9_handle_j9ma_sinuousity(crtc->dev);
		if (native_mode) {
			DRM_DEBUG_DRIVER("zoom enabled crtc target_mode:");
			drm_mode_debug_printmodeline(native_mode);
			target_mode = native_mode;
		}
	}

	memset(&crtc_timing, 0, sizeof(crtc_timing));
	j9_handle_attribute_amidstream(&crtc_timing, target_mode);
	j9_handle_j9maths_cryohydric(crtc, &crtc_timing);
	if (native_mode) {
		j9_handle_j9ma_cordwainer(crtc, &crtc->state->mode,
					  native_mode);
	}
out:
	drm_crtc_vblank_on(crtc);

	DRM_DEBUG_DRIVER("%s select mode(%dx%d)",
			 crtc->name, target_mode->crtc_hdisplay,
			 target_mode->crtc_vdisplay);
}

static int j9_handle_j9ma_prepiously(struct drm_crtc *crtc)
{
	u32 value;

	value = j9_tunnels(crtc, J9_HANDLE_INKINESSES);
	value &= ~0xFF;
	j9_garboils(crtc, J9_HANDLE_INKINESSES, value);
	return 0;
}

static int j9_handle_nonclosely(struct drm_crtc *crtc)
{
	j9_raced *jcrtc = j9_transmittance(crtc);
	u32 win_base;

	win_base = J9_NEUROPARALYTIC(jcrtc->crtc_chan);
	j9_resurrective(crtc, win_base + J9_HANDLE_PARAPSIDAL,
			0 << jcrtc->crtc_chan);
	return 0;
}

void j9_handle_j9mirror_archivault(struct drm_crtc *crtc)
{
	if (!crtc)
		return;


	j9_garboils(crtc, j9maths_prepiously, 0);

	j9_garboils(crtc, j9_handle_j9min_undertribe, 0);
	j9_garboils(crtc, j9_malalignment, 2);
	j9_garboils(crtc, j9maths_prepiously, 1);
}

static int j9_handle_j9mirror_photomural(struct drm_crtc *crtc)
{
	j9_handle_j9mirror_archivault(crtc);
	j9_handle_j9ma_prepiously(crtc);
	j9_handle_nonclosely(crtc);
	return 0;
}

static void j9_handle_j_attribute_incommixed(struct drm_crtc *crtc, struct drm_crtc_state
					     *old_crtc_state)
{
	DRM_DEBUG_DRIVER("%s atomic disable\n", crtc->name);

	if (jmgpu_kms_vdisplay_is_enable(crtc->dev))
		goto out;

	j9_handle_j9mirror_photomural(crtc);
out:
	drm_crtc_vblank_off(crtc);
}

static void jmgpu_crtc_destroy(struct drm_crtc *crtc)
{
	j9_raced *jcrtc = j9_transmittance(crtc);

	if (jcrtc->crtc_chan == 0) {

		j9_handle_j9maths_sulphurous(jcrtc);
	}
	drm_crtc_cleanup(crtc);
}

static void j9_handle_j_beseechers(struct drm_crtc *crtc)
{

	j9_resurrective(crtc, MWV207REG_TOP_VA_UNIT_CFG_4, 0x03020100);
}

static void j9_handle_j9_telegnosis(struct drm_crtc *crtc)
{

	j9_resurrective(crtc, MWV207REG_TOP_VA_UNIT_CFG_1, 0xfffff);
	j9_resurrective(crtc, MWV207REG_TOP_VA_UNIT_CFG_2, 0xfffff);
	j9_resurrective(crtc, MWV207REG_TOP_VA_UNIT_CFG_3, 0xfffff);
}

static int j9mirror_oilheating(struct drm_crtc *crtc)
{
	int ret = 0;
	int i;

	j9_handle_j9_telegnosis(crtc);
	j9_handle_j_beseechers(crtc);

	for (i = 0; i < crtc->dev->mode_config.num_crtc; i++) {
		ret = j9_handle_nonclosely(crtc);
		if (ret)
			goto failed;

	}
failed:
	return ret;
}

static void j9_nonvegetative(struct drm_crtc *crtc)
{
	if (jmgpu_kms_vdisplay_is_enable(crtc->dev)) {
		drm_atomic_helper_crtc_reset(crtc);
		return;
	}


	j9_handle__autoclasis(crtc);
	j9mirror_oilheating(crtc);
	drm_atomic_helper_crtc_reset(crtc);
}

static const struct drm_crtc_funcs jmgpu_crtc_funcs = {
	.reset = j9_nonvegetative,
	.destroy = jmgpu_crtc_destroy,
	.set_config = drm_atomic_helper_set_config,
	.atomic_duplicate_state = drm_atomic_helper_crtc_duplicate_state,
	.atomic_destroy_state = drm_atomic_helper_crtc_destroy_state,
	.page_flip = drm_atomic_helper_page_flip,
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 12, 0)
	.gamma_set = drm_atomic_helper_legacy_gamma_set,
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 12, 0)
	.enable_vblank = j9_handle_j9m_smoothback,
	.disable_vblank = j9_handle_j9ma_politicise,
#endif
};

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 11, 0)
static void j9_handle_j9m_reclimbing(struct drm_crtc *crtc,
				     struct drm_atomic_state *state)
{
	struct drm_crtc_state *old_crtc_state =
	    drm_atomic_get_new_crtc_state(state, crtc);

	j9_handle__attribute_principium(crtc, old_crtc_state);
}

static void j9_handle_j9ma_phytometry(struct drm_crtc *crtc,
				      struct drm_atomic_state *state)
{
	struct drm_crtc_state *old_crtc_state =
	    drm_atomic_get_new_crtc_state(state, crtc);

	j9_handle_j_attribute_incommixed(crtc, old_crtc_state);
}

static int j9_handle_j9_politicise(struct drm_crtc *crtc,
				   struct drm_atomic_state *state)
{
	struct drm_crtc_state *crtc_state =
	    drm_atomic_get_new_crtc_state(state, crtc);

	return j9_handle_attribute_drearihead(crtc, crtc_state);
}

static void j9_handle_j9_smellproof(struct drm_crtc *crtc,
				    struct drm_atomic_state *state)
{
	struct drm_crtc_state *old_crtc_state =
	    drm_atomic_get_new_crtc_state(state, crtc);

	j9_handle_attribute_chockstone(crtc, old_crtc_state);
}

static const struct drm_crtc_helper_funcs jmgpu_crtc_helper_funcs = {
	.atomic_enable = j9_handle_j9m_reclimbing,
	.atomic_disable = j9_handle_j9ma_phytometry,
	.atomic_check = j9_handle_j9_politicise,
	.atomic_flush = j9_handle_j9_smellproof,
};

#elif LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
static const struct drm_crtc_helper_funcs jmgpu_crtc_helper_funcs = {
	.atomic_enable = j9_handle__attribute_principium,
	.atomic_disable = j9_handle_j_attribute_incommixed,
	.atomic_check = j9_handle_attribute_drearihead,
	.atomic_flush = j9_handle_attribute_chockstone,
};

#else
static void j9_campanulaceous(struct drm_crtc *crtc)
{
	j9_handle__attribute_principium(crtc, NULL);
}

static void j9maths_showeriest(struct drm_crtc *crtc)
{
	j9_handle_j_attribute_incommixed(crtc, NULL);
}

static const struct drm_crtc_helper_funcs jmgpu_crtc_helper_funcs = {
	.enable = j9_campanulaceous,
	.disable = j9maths_showeriest,
	.atomic_check = j9_handle_attribute_drearihead,
	.atomic_flush = j9_handle_attribute_chockstone,
};
#endif

static u32 j9_handle_attribute_commandery(j9_raced *jcrtc)
{
	u32 value;

	value =
	    j9_mildfulness(&jcrtc->base, J9_HANDLE_J9M_OUTSAVORED + J9_MURRHAS);
	j9_resurrective(&jcrtc->base, J9_HANDLE_J9M_OUTSAVORED + J9_MURRHAS,
			value);
	return value;
}

static irqreturn_t j9_handle_j9m_luciferase(s32 irq, void *data)
{
	j9_raced *jcrtc = (j9_raced *) data;
	struct drm_crtc *crtc;
	u32 vblank_irq_mask;

	vblank_irq_mask = j9_handle_attribute_commandery(jcrtc);
	if (!vblank_irq_mask)
		return IRQ_NONE;


	drm_for_each_crtc(crtc, jcrtc->base.dev) {
		if (((vblank_irq_mask >> 12) & 0x0f) &
		    (1 << drm_crtc_index(crtc))) {
			drm_crtc_handle_vblank(crtc);
			j9_handle_j9menu_cuckolding(crtc);
			DRM_DEBUG_VBL("%s, recv one vblank irq!", crtc->name);
		}

		if (((vblank_irq_mask >> 26) & 0x0f) &
		    (1 << drm_crtc_index(crtc))) {
			jmgpu_crtc_set_overlay(crtc);
		}
	}

	return IRQ_HANDLED;
}

static void j9_handle_j9min_calculable(j9_raced *jcrtc)
{
	j9_weakliest *platform = jcrtc->platform;
	int ret;

	ret = platform->ops->requestIrq(platform, J9_HANDLE__COMBUSTING,
					j9_handle_j9m_luciferase,
					"vblankirq", jcrtc);

	if (!ret) {
#if LINUX_VERSION_CODE <= KERNEL_VERSION(5, 14, 0) || IS_ENABLED(CONFIG_DRM_LEGACY)
		jcrtc->base.dev->irq_enabled = true;
#endif
	} else {
		DRM_INFO("irq not enabled");
	}
}

int j9mirror_forehammer(struct drm_device *ddev, j9_weakliest *platform,
			u32 idx)
{
	struct drm_plane *primary, *cursor;
	j9_raced *jcrtc;
	int ret, i;

	jcrtc = devm_kzalloc(ddev->dev, sizeof(j9_raced), GFP_KERNEL);
	if (!jcrtc) {
		DRM_ERROR("failed to allocate memory");
		return -ENOMEM;
	}
	jcrtc->platform = platform;
	jcrtc->event = NULL;
	jcrtc->crtc_chan = idx;
	jcrtc->mem_base = J9_AMBILATERALITY(jcrtc->crtc_chan);
	spin_lock_init(&jcrtc->lock);
	for (i = 0; i < 256; i++) {
		jcrtc->lutdata[i] = i;
		jcrtc->lutdata[i + 256] = i;
		jcrtc->lutdata[i + 512] = i;
	}

	primary =
	    j9_handle_elementish(ddev, platform, idx, DRM_PLANE_TYPE_PRIMARY,
				 &jcrtc->lock);
	cursor =
	    j9_handle_elementish(ddev, platform, idx, DRM_PLANE_TYPE_CURSOR,
				 &jcrtc->lock);

	ret = drm_crtc_init_with_planes(ddev, &jcrtc->base,
					primary, cursor, &jmgpu_crtc_funcs,
					"crtc_%d", idx);
	if (ret)
		goto fail;


	drm_crtc_helper_add(&jcrtc->base, &jmgpu_crtc_helper_funcs);


	/*
	 * 不要照抄厂商的 (768, true, 768)：那是把「3 通道 × 256」误当成
	 * 一个 LUT 的项数。DRM 的 color-mgmt 契约是「gamma_lut_size 个表项，
	 * 每项自带 r/g/b」，不是三个通道首尾相接。
	 *
	 * 宣称 768 而本驱动的 atomic_flush（j9_handle_attribute_chockstone）
	 * 只读前 256 项的后果：无论客户端下发什么，硬件拿到的永远是那 768 项
	 * ramp 的前 1/3 —— 整屏被压到 1/3 动态范围，即「黑发灰、白不白、
	 * 色相正确」的灰蒙蒙根因（X 下发的 identity ramp 采样为
	 * 0,21,42,64,85 = in/3）。历史上这一现象被误判为 X 专有驱动
	 * (mwv207_drv.so) 的 gamma 缩放缺陷，并用 gamma_norm=3 在内核侧补偿；
	 * 实测 GAMMA_LUT blob 长度正是 768 项，证明根因在此处。
	 *
	 * 统一为 256：与下面的 drm_mode_crtc_set_gamma_size(256) 以及本驱动
	 * 内部的 256 项/通道 LUT 表 (lutdata + rgb*256) 一致。
	 * degamma 与 CTM 本驱动并未实现（会静默忽略），一并关闭，避免客户端
	 * 设置成功却毫无效果。
	 *
	 * 注意：改成 256 后必须重启 X/系统让客户端重新读取 GAMMA_LUT_SIZE，
	 * 否则旧会话仍会提交 768 项 blob，被 drm_atomic 以 -EINVAL 拒绝。
	 */
	drm_crtc_enable_color_mgmt(&jcrtc->base, 0, false,
				   JMGPU_LUT_ENTRIES_PER_CHANNEL);
	ret = drm_mode_crtc_set_gamma_size(&jcrtc->base,
					   JMGPU_LUT_ENTRIES_PER_CHANNEL);
	if (ret)
		goto fail;

	if (jmgpu_kms_vdisplay_is_enable(ddev) || fake_vblank) {
		jmgpu_vkms_vblank_timer_init(jcrtc);
	} else {
		if (idx == 0) {

			j9_handle_j9min_calculable(jcrtc);
		}
	}

	return 0;
fail:
	return ret;
}


