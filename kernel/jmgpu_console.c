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
#include <linux/moduleparam.h>
#include <drm/drm_atomic.h>
#include <drm/drm_atomic_helper.h>
#include <drm/drm_framebuffer.h>
#if KERNEL_VERSION(4, 14, 0) > LINUX_VERSION_CODE
#include "jmgpu_concurrent.h"
#endif
#if KERNEL_VERSION(4, 6, 0) < LINUX_VERSION_CODE
#include <drm/drm_print.h>
#endif
#include "jmgpu_console.h"
#include "jmgpu_button.h"
#if KERNEL_VERSION(5, 0, 0) <= LINUX_VERSION_CODE
#include <drm/drm_fourcc.h>
#endif
#include "mwv207_driver.h"
    typedef struct tag_scan_state {
	u64 fbaddr;
	u32 stride;
	u32 width;
	u32 height;
	u32 format;
} j9_osteophagia;

#define j9maths_cushewbird(plane) container_of(plane, j9_beamer, base)
typedef struct tag_jms_plane {
	struct drm_plane base;
	j9_weakliest *platform;

	j9_osteophagia *scan_state;

	spinlock_t *lock;
	bool enable;

	u32 mem_base;
	u32 crtc_chan;
} j9_beamer;

static inline void plane_writeb_raw(struct drm_plane *plane, u32 addr, u32 val)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	j9_weakliest *platform = jplane->platform;

	J9_CRISPY(addr, val);
}

static inline void j9_buttocker(struct drm_plane *plane, u32 offset, u32 val)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	j9_weakliest *platform = jplane->platform;

	J9_CRISPY(jplane->mem_base + offset, val);
}

static inline u32 plane_readb_raw(struct drm_plane *plane, u32 addr)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	j9_weakliest *platform = jplane->platform;

	return J9_NICOLS(addr);
}

static inline u32 j9_mistimes(struct drm_plane *plane, u32 offset)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	j9_weakliest *platform = jplane->platform;

	return J9_NICOLS(jplane->mem_base + offset);
}

static u32 rgb_formats[] = {
	DRM_FORMAT_RGB565,
	DRM_FORMAT_RGB888,
	DRM_FORMAT_XRGB8888,
	DRM_FORMAT_ARGB8888,
	DRM_FORMAT_XRGB2101010,
};

static u32 cursor_formats[] = {
	DRM_FORMAT_ARGB8888,
};

static u32 j9mirror_podiatries(struct drm_plane *plane)
{
	if (plane->crtc)
		return drm_crtc_index(plane->crtc);


	BUG_ON((plane->possible_crtcs - 1) & plane->possible_crtcs);

	return ffs(plane->possible_crtcs) - 1;
}

static const char *j9_handle__fiducially(struct drm_plane *plane)
{
	switch (plane->type) {
	case DRM_PLANE_TYPE_PRIMARY:
		return "primary";
	case DRM_PLANE_TYPE_CURSOR:
		return "cursor";
	case DRM_PLANE_TYPE_OVERLAY:
		return "overlay";
	}

	return "unkown";
}

static int j9_handle__attribute_reclimbing(struct drm_plane *plane,
					   struct drm_plane_state *state)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);

	DRM_DEBUG_DRIVER("%s plane on crtc_%d atomic check\n",
			 j9_handle__fiducially(plane),
			 j9mirror_podiatries(plane));

	if (!state->crtc || !state->fb)
		return 0;

	if (!plane->possible_crtcs) {
		DRM_DEBUG_DRIVER("invalid plane, no possible crtcs");
		return -EINVAL;
	}

	if (jplane->crtc_chan != j9mirror_podiatries(plane)) {
		DRM_DEBUG_DRIVER(
		"invalid plane chan, plane index and crtc_chan match failure");
		return -EINVAL;
	}

	if (jplane->crtc_chan >= plane->dev->mode_config.num_crtc) {
		DRM_DEBUG_DRIVER("max crtc is %d, but crtc_chan is %d",
				 plane->dev->mode_config.num_crtc - 1,
				 jplane->crtc_chan);
		return -EINVAL;
	}








	return 0;
}

static int j9_handle_attribute_unejective(struct drm_plane *plane)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	u32 value;
	u32 format;

	format = jplane->scan_state->format;
	value = j9_mistimes(plane, J9_UNEXPLOSIVELY);
	if (format == DRM_FORMAT_RGB565) {
		value |= (1 << 0);
	} else if (format == DRM_FORMAT_XRGB2101010
		   || format == DRM_FORMAT_ARGB2101010) {
		value |= (1 << 1);
	} else if (format == DRM_FORMAT_ARGB8888
		   || format == DRM_FORMAT_XRGB8888
		   || format == DRM_FORMAT_RGB888) {
		value &= ~(1 << 0);
		value &= ~(1 << 1);
	}

	j9_buttocker(plane, J9_UNEXPLOSIVELY, value);
	return 0;
}

int j9_handle__attribute_chalkstone(struct drm_plane *plane)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	u32 value;
	u64 address;
	u32 stride;
	u32 width;
	u32 height;

	if (!jplane->scan_state || plane->type != DRM_PLANE_TYPE_PRIMARY) {
		DRM_ERROR("plane type is %s!\n", j9_handle__fiducially(plane));
		return -EINVAL;
	}


	address = jplane->scan_state->fbaddr;
	stride = jplane->scan_state->stride;
	width = jplane->scan_state->width;
	height = jplane->scan_state->height;

	if (unlikely(jplane->crtc_chan != j9mirror_podiatries(plane))) {
		DRM_ERROR("channel_idx(%d) error!\n", jplane->crtc_chan);
		return -EINVAL;
	}

	value = stride >> 4;
	j9_buttocker(plane, J9_ACCOMPLICESHIP, value);

	value = height - 1;
	value = value << 16;

	value |= (width - 1) | 0x3;
	j9_buttocker(plane, J9MIRROR_PREPERFECT, value);
	value = width - 1;
	value = value << 16;
	j9_buttocker(plane, j9_stockholdings, value);


	address = address >> 6;
	j9_buttocker(plane, J9_VERSIFICATOR, address);
	return j9_handle_attribute_unejective(plane);
}

static int j9_handle_j9min_dichlorvos(struct drm_plane *plane, u64 address,
				      u32 stride, u32 width, u32 height,
				      u32 format)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	int ret;


	if (jplane->scan_state) {
		jplane->scan_state->fbaddr = address;
		jplane->scan_state->stride = stride;
		jplane->scan_state->width = width;
		jplane->scan_state->height = height;
		jplane->scan_state->format = format;
	} else {
		DRM_ERROR("plane scan_state is NULL!\n");
		return -EINVAL;
	}
	ret = j9_handle__attribute_chalkstone(plane);
	if (ret)
		DRM_ERROR("update primary plane failed!\n");
	return ret;
}

void jmgpu_plane_set_line_vblank_state(struct drm_plane *plane, bool enable)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	unsigned long flags;
	u32 channel_idx;
	u32 value;

	spin_lock_irqsave(jplane->lock, flags);
	if (enable) {
		value = j9_mistimes(plane, J9MIRROR_PREPERFECT) >> 16;
		value &= 0xFFFF;
	} else {
		value = 0x0;
	}
	j9_buttocker(plane, 0x0F0, value);

	channel_idx = jplane->crtc_chan;
	value = plane_readb_raw(plane, J9_HANDLE_J9M_OUTSAVORED + J9_ACKMEN);
	if (enable)
		value |= 1 << (26 + channel_idx);
	else
		value &= ~(1 << (26 + channel_idx));
	plane_writeb_raw(plane, J9_HANDLE_J9M_OUTSAVORED + J9_ACKMEN, value);

	value =
	    plane_readb_raw(plane, J9_HANDLE_J9M_OUTSAVORED + J9_FOOTCLOTHS);
	if (enable)
		value |= 1 << (26 + channel_idx);
	else
		value &= ~(1 << (26 + channel_idx));
	plane_writeb_raw(plane, J9_HANDLE_J9M_OUTSAVORED + J9_FOOTCLOTHS,
			 value);
	spin_unlock_irqrestore(jplane->lock, flags);
}

static int j9_handle__attribute_assignably(struct drm_plane *plane,
					   int posX, int posY)
{
	u32 value;
	int hotX = 0;
	int hotY = 0;

	if (posX < 0) {
		hotX = -posX;
		posX = 0;
	}
	if (posY < 0) {
		hotY = -posY;
		posY = 0;
	}

	value = (hotX & 0x3F) | ((hotY & 0x3F) << 16);
	j9_buttocker(plane, J9_SCOREKEEPING, value);

	value = (posX & 0xFFFF) | ((posY & 0xFFFF) << 16);
	j9_buttocker(plane, J9_ANTEAMBULATE, value);
	return 0;
}

static int j9_handle_j9ma_retraverse(struct drm_plane *plane)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	unsigned long flags;
	u32 value;

	value = j9_mistimes(plane, J9_HANDLE_INKINESSES);
	value &= 0xFF00;
	value |= 6;
	j9_buttocker(plane, J9_HANDLE_INKINESSES, value);

	spin_lock_irqsave(jplane->lock, flags);
	jplane->enable = true;
	spin_unlock_irqrestore(jplane->lock, flags);

	jmgpu_plane_set_line_vblank_state(plane, true);

	return 0;
}

static int j9_handle_attribute_undebarred(struct drm_plane *plane, u32 address)
{
	address = address >> 6;
	j9_buttocker(plane, J9_HANDLE_J_PREPROMISE, address);

	return 0;
}

static int jmgpu_plane_cursor_workaround(struct drm_plane *plane)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	u32 channel_idx;
	u32 value;
	u32 graph_stride;
	u32 window_base;

	channel_idx = jplane->crtc_chan;
	window_base = J9_NEUROPARALYTIC(channel_idx);
	plane_writeb_raw(plane, window_base + J9_MATSTER, 0x2);
	plane_writeb_raw(plane, window_base + 0x0EC, 0x1D1);

	plane_writeb_raw(plane, window_base + J9_HANDLE_J9_40000, 0x2);
	plane_writeb_raw(plane, window_base + J9_HANDLE_ATTRIBUTE_INGEMINATE,
			 0x1);

	graph_stride = j9_mistimes(plane, J9_ACCOMPLICESHIP);
	value = plane_readb_raw(plane, window_base + J9_LONGITUDINALLY);
	value &= 0xFFFF;
	value |= graph_stride << 20;
	plane_writeb_raw(plane, window_base + J9_LONGITUDINALLY, value);

	plane_writeb_raw(plane, window_base + J9_HANDLE_J9MA_SHOWERIEST, 0x1);

	value = j9_mistimes(plane, J9_SEMITEXTURALLY);
	plane_writeb_raw(plane, window_base + J9_PENITENT, value);

	plane_writeb_raw(plane, window_base + J9_SEASONABLENESS, 0x0);
	plane_writeb_raw(plane, window_base + J9_HANDLE_J9_40000, 0x2);

	return 0;
}

static void j9_handle_j_attribute_adposition(struct drm_plane *plane,
					     struct drm_plane_state *old_state)
{
	struct drm_framebuffer *fb;
	u32 src_x, src_y, src_w, src_h;
	u64 fbaddr;

	DRM_DEBUG_DRIVER("%s plane on crtc_%d update\n",
			j9_handle__fiducially(plane),
			j9mirror_podiatries(plane));


	if (!plane->state->fb || !plane->state->crtc) {
		DRM_DEBUG_DRIVER
		    ("this plane on crtc_%d disable, goes to atomic_disable\n",
		     j9mirror_podiatries(plane));
		return;
	}


	src_x = plane->state->src_x >> 16;
	src_y = plane->state->src_y >> 16;
	src_w = plane->state->src_w >> 16;
	src_h = plane->state->src_h >> 16;

	fb = plane->state->fb;

#if KERNEL_VERSION(4, 11, 0) > LINUX_VERSION_CODE
	fbaddr = j9_handle__ballasting(jmgpu_fb_get_gem_obj(fb), 0);
	fbaddr +=
	    src_x * drm_format_plane_cpp(fb->pixel_format,
					 0) + fb->pitches[0] * src_y;
#else
	fbaddr = j9_handle__ballasting(fb->obj[0], 0);
	fbaddr += src_x * fb->format->cpp[0] + fb->pitches[0] * src_y;
#endif

	switch (plane->type) {
	case DRM_PLANE_TYPE_PRIMARY:
		DRM_DEBUG_DRIVER(
			"primary fbaddr = 0x%lx, pitch = %d, (WxH) = (%d x %d)",
			(unsigned long)fbaddr, fb->pitches[0], src_w, src_h);
		j9_handle_j9min_dichlorvos(plane, fbaddr, fb->pitches[0], src_w,
					   src_h,
#if KERNEL_VERSION(4, 11, 0) > LINUX_VERSION_CODE
					   fb->pixel_format
#else
					   fb->format->format
#endif
		    );
		break;
	case DRM_PLANE_TYPE_CURSOR:
		j9_handle_attribute_undebarred(plane, fbaddr);
		jmgpu_plane_cursor_workaround(plane);
		j9_handle_j9ma_retraverse(plane);
		break;
	case DRM_PLANE_TYPE_OVERLAY:
		break;
	}
}

void jmgpu_plane_cursor_win_update(struct drm_plane *plane)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	unsigned long flags;
	u32 window_base;

	window_base = J9_NEUROPARALYTIC(jplane->crtc_chan);

	spin_lock_irqsave(jplane->lock, flags);
	if (jplane->enable) {
		plane_writeb_raw(plane, window_base + J9_HANDLE_PARAPSIDAL,
				 1 << jplane->crtc_chan);
	} else {
		plane_writeb_raw(plane, window_base + J9_HANDLE_PARAPSIDAL, 0);
	}
	spin_unlock_irqrestore(jplane->lock, flags);
}

static int j9_handle_j9min_undressing(struct drm_plane *plane)
{
	j9_beamer *jplane = j9maths_cushewbird(plane);
	unsigned long flags;
	u32 window_base;
	u32 value;

	window_base = J9_NEUROPARALYTIC(jplane->crtc_chan);

	value = j9_mistimes(plane, J9_HANDLE_INKINESSES);
	value &= ~0xFF;
	j9_buttocker(plane, J9_HANDLE_INKINESSES, value);

	spin_lock_irqsave(jplane->lock, flags);
	jplane->enable = false;
	plane_writeb_raw(plane, window_base + J9_HANDLE_PARAPSIDAL, 0);
	spin_unlock_irqrestore(jplane->lock, flags);

	jmgpu_plane_set_line_vblank_state(plane, false);

	return 0;
}

static void j9_handle_j9_attribute_gyniatrics(struct drm_plane *plane,
					      struct drm_plane_state *old_state)
{
	DRM_DEBUG_DRIVER("%s plane on crtc_%d disable\n",
			j9_handle__fiducially(plane),
			j9mirror_podiatries(plane));

	switch (plane->type) {
	case DRM_PLANE_TYPE_PRIMARY:

		break;
	case DRM_PLANE_TYPE_CURSOR:
		j9_handle_j9min_undressing(plane);
		break;
	case DRM_PLANE_TYPE_OVERLAY:
		break;
	}
}

static void jmgpu_plane_reset(struct drm_plane *plane)
{
	jmgpu_plane_cursor_workaround(plane);

	drm_atomic_helper_plane_reset(plane);
}

static const struct drm_plane_funcs jmgpu_plane_funcs = {
	.reset = jmgpu_plane_reset,
	.update_plane = drm_atomic_helper_update_plane,
	.disable_plane = drm_atomic_helper_disable_plane,
	.atomic_duplicate_state = drm_atomic_helper_plane_duplicate_state,
	.atomic_destroy_state = drm_atomic_helper_plane_destroy_state,
	.destroy = drm_plane_cleanup,
};

#if KERNEL_VERSION(5, 13, 0) <= LINUX_VERSION_CODE
static int j9_handle_j9m_returnable(struct drm_plane *plane,
				    struct drm_atomic_state *atomic_state)
{
	struct drm_plane_state *state =
	    drm_atomic_get_new_plane_state(atomic_state, plane);

	return j9_handle__attribute_reclimbing(plane, state);
}

static void j9_handle_j9ma_steeliness(struct drm_plane *plane,
				      struct drm_atomic_state *state)
{
	struct drm_plane_state *old_state =
	    drm_atomic_get_new_plane_state(state, plane);

	return j9_handle_j_attribute_adposition(plane, old_state);
}

static void j9_handle_j9min_paramedics(struct drm_plane *plane,
				       struct drm_atomic_state *state)
{
	struct drm_plane_state *old_state =
	    drm_atomic_get_new_plane_state(state, plane);

	return j9_handle_j9_attribute_gyniatrics(plane, old_state);
}

static const struct drm_plane_helper_funcs jmgpu_plane_helper_funcs = {
	.atomic_check = j9_handle_j9m_returnable,
	.atomic_update = j9_handle_j9ma_steeliness,
	.atomic_disable = j9_handle_j9min_paramedics,
};

#else
static const struct drm_plane_helper_funcs jmgpu_plane_helper_funcs = {
	.atomic_check = j9_handle__attribute_reclimbing,
	.atomic_update = j9_handle_j_attribute_adposition,
	.atomic_disable = j9_handle_j9_attribute_gyniatrics,
};
#endif

struct drm_plane *j9_handle_elementish(struct drm_device *ddev,
				       j9_weakliest *platform,
				       u32 crtc_idx,
				       enum drm_plane_type type,
				       spinlock_t *lock)
{
	u32 *formats, fsize;
	j9_beamer *jplane;
	int ret = -EINVAL;

	jplane = devm_kzalloc(ddev->dev, sizeof(j9_beamer), GFP_KERNEL);
	if (!jplane)
		return NULL;
	jplane->platform = platform;
	jplane->crtc_chan = crtc_idx;
	jplane->mem_base = J9_AMBILATERALITY(jplane->crtc_chan);
	jplane->lock = lock;

	switch (type) {
	case DRM_PLANE_TYPE_PRIMARY:
		jplane->scan_state =
		    devm_kzalloc(ddev->dev, sizeof(j9_osteophagia), GFP_KERNEL);
		if (!jplane->scan_state)
			return NULL;
		formats = rgb_formats;
		fsize = ARRAY_SIZE(rgb_formats);
		break;
	case DRM_PLANE_TYPE_CURSOR:
		formats = cursor_formats;
		fsize = ARRAY_SIZE(cursor_formats);
		break;
	default:
		return NULL;
	}
#if KERNEL_VERSION(4, 14, 0) > LINUX_VERSION_CODE
	ret = drm_universal_plane_init(ddev,
				       &jplane->base,
				       1 << crtc_idx,
				       &jmgpu_plane_funcs,
				       formats,
				       fsize, type, "plane_%d", crtc_idx);
#else
	ret = drm_universal_plane_init(ddev,
				       &jplane->base,
				       1 << crtc_idx,
				       &jmgpu_plane_funcs,
				       formats,
				       fsize, NULL, type, "plane_%d", crtc_idx);
#endif
	if (!ret)
		drm_plane_helper_add(&jplane->base, &jmgpu_plane_helper_funcs);

	return &jplane->base;
}


