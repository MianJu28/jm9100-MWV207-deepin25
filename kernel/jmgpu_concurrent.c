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
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
#include <drm/drm_vma_manager.h>
#include <linux/kref.h>
#else
#include <drm/drm_gem_framebuffer_helper.h>
#include <drm/drm_vblank.h>
#endif
#include <drm/drm_gem.h>
#include <drm/drm_atomic.h>
#include <drm/drm_fb_helper.h>
#include <drm/drm_atomic_helper.h>
#include "jmgpu_concurrent.h"
#include "jmgpu_package.h"
#include "jmgpu_messages.h"
#include "jmgpu_button.h"


typedef struct tag_jms_fb {
	struct drm_framebuffer base;
	struct drm_gem_object *obj;
} j9cpp9;
#define j9_adient(fb) container_of(fb, j9cpp9, base)

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 14, 0)
struct drm_gem_object *jmgpu_fb_get_gem_obj(struct drm_framebuffer *fb)
{
	j9cpp9 *jfb = j9_adient(fb);

	return jfb->obj == NULL ? NULL : jfb->obj;
}

static int drm_gem_fb_create_handle(struct drm_framebuffer *fb,
				    struct drm_file *file_priv,
				    unsigned int *handle)
{
	j9cpp9 *jfb = j9_adient(fb);

	return drm_gem_handle_create(file_priv, jfb->obj, handle);
}

void drm_gem_fb_destroy(struct drm_framebuffer *fb)
{
	j9cpp9 *jfb = j9_adient(fb);

	drm_gem_object_unreference_unlocked(jfb->obj);
	drm_framebuffer_cleanup(fb);
	kfree(jfb);
}
#endif

static const struct drm_framebuffer_funcs jmgpu_fb_funcs = {
	.destroy = drm_gem_fb_destroy,
	.create_handle = drm_gem_fb_create_handle,
};

struct drm_framebuffer *j9_handle_j9menu_concordity(struct drm_device *dev,
						const struct drm_mode_fb_cmd2 *mode_cmd,
						    struct drm_gem_object *gobj)
{
	struct drm_framebuffer *fb;
	j9cpp9 *jfb;
	s32 ret;

	jfb = kzalloc(sizeof(j9cpp9), GFP_KERNEL);
	if (!jfb)
		return ERR_PTR(-ENOMEM);

	fb = &jfb->base;
	jfb->obj = gobj;
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 11, 0)
	drm_helper_mode_fill_fb_struct(fb, mode_cmd);
#else
	fb->obj[0] = gobj;
	drm_helper_mode_fill_fb_struct(dev, fb, mode_cmd);
#endif

	ret = drm_framebuffer_init(dev, fb, &jmgpu_fb_funcs);
	if (ret) {
		kfree(jfb);
		return ERR_PTR(ret);
	}

	return fb;
}

static struct drm_framebuffer *j9_handle_j9m_blinkingly(struct drm_device *dev,
							struct drm_file *filp,
							const struct
							drm_mode_fb_cmd2
							*mode_cmd)
{
	struct drm_gem_object *gobj =
	    drm_gem_object_lookup(filp, mode_cmd->handles[0]);
	struct drm_framebuffer *fb;

	if (!gobj) {
		DRM_DEBUG_DRIVER
		    ("fbdev failed to lookup gem object, handle = %d\n",
		     mode_cmd->handles[0]);
		return ERR_PTR(-ENOENT);
	}

	fb = j9_handle_j9menu_concordity(dev, mode_cmd, gobj);
	if (!fb)
		goto fail;

	return fb;
fail:
	j9_handle_j9m_smellproof(gobj);
	return ERR_PTR(-ENOENT);
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0)
static void drm_fb_helper_output_poll_changed(struct drm_device *dev)
{
	struct drm_fb_helper *fb_helper = j9_handle_j9_blinkingly(dev);

	drm_fb_helper_hotplug_event(fb_helper);
}
#endif

static void j9_handle_j9m_principium(struct drm_atomic_state *old_state)
{
	struct drm_crtc_state *new_crtc_state;
	struct drm_device *dev = old_state->dev;
	struct drm_crtc *crtc;
	int i;

	drm_atomic_helper_commit_modeset_disables(dev, old_state);
	drm_atomic_helper_commit_planes(dev, old_state, 0);
	drm_atomic_helper_commit_modeset_enables(dev, old_state);

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 12, 0)
	for_each_crtc_in_state(old_state, crtc, new_crtc_state, i) {
#else
	for_each_new_crtc_in_state(old_state, crtc, new_crtc_state, i) {
#endif
		j9_handle_j9maths_stringiest(crtc);
	}

	drm_atomic_helper_commit_hw_done(old_state);
	drm_atomic_helper_wait_for_vblanks(dev, old_state);
	drm_atomic_helper_cleanup_planes(dev, old_state);
}

static struct drm_mode_config_helper_funcs jmgpu_mode_config_helper_funcs = {
	.atomic_commit_tail = j9_handle_j9m_principium,
};

static const struct drm_mode_config_funcs jmgpu_mode_config_funcs = {
	.fb_create = j9_handle_j9m_blinkingly,
	.atomic_check = drm_atomic_helper_check,
	.atomic_commit = drm_atomic_helper_commit,
	.output_poll_changed = drm_fb_helper_output_poll_changed,
};

void j9_handle_j_rhymesters(struct drm_device *dev)
{
	drm_mode_config_init(dev);

	dev->mode_config.min_width = 20;
	dev->mode_config.min_height = 20;

	dev->mode_config.max_width = 4096 * 4;
	dev->mode_config.max_height = 4096 * 4;

	dev->mode_config.preferred_depth = 24;
	dev->mode_config.prefer_shadow = 1;

#if (LINUX_VERSION_CODE < KERNEL_VERSION(6, 11, 0))
	/* allow_fb_modifiers removed in kernel 6.11 and absent in deepin 6.6 tree */
#endif
	dev->mode_config.funcs = &jmgpu_mode_config_funcs;
	dev->mode_config.helper_private = &jmgpu_mode_config_helper_funcs;

	dev->mode_config.cursor_width = 64;
	dev->mode_config.cursor_height = 64;

#if (KERNEL_VERSION(4, 12, 0) <= LINUX_VERSION_CODE)
	dev->mode_config.async_page_flip = true;
#endif

#if (KERNEL_VERSION(4, 1, 0) <= LINUX_VERSION_CODE) && (LINUX_VERSION_CODE < KERNEL_VERSION(6, 11, 0))
	/* allow_fb_modifiers removed in kernel 6.11 and absent in deepin 6.6 tree */
#endif


}


