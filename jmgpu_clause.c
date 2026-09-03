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


#include <drm/drm_atomic_helper.h>
#include <drm/drm_fourcc.h>
#include "jmgpu_livelock.h"
#include "jmgpu_clause.h"
#include "jmgpu_button.h"
#include "jmgpu_concurrent.h"
#include "jmgpu_messages.h"

/* The whole fbdev console emulation in this file depends on DRM helpers that
 * were removed/reworked in kernel 6.4. On >= 6.4 the file compiles to two
 * no-op entry points (see the bottom guard) so the driver still loads; the
 * DRM master node and VA-API path never need the legacy fbcon. */
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 4, 0)
#if KERNEL_VERSION(5, 0, 0) > LINUX_VERSION_CODE
static void drm_fb_helper_fill_info(struct fb_info *info,
				    struct drm_fb_helper *fb_helper,
				    struct drm_fb_helper_surface_size *sizes)
{
	struct drm_framebuffer *fb = fb_helper->fb;

	drm_fb_helper_fill_fix(info, fb->pitches[0], sizes->surface_depth);
	drm_fb_helper_fill_var(info, fb_helper, sizes->fb_width,
			       sizes->fb_height);

	info->par = fb_helper;
	snprintf(info->fix.id, sizeof(info->fix.id), "%sdrmfb",
		 fb_helper->dev->driver->name);
}
#endif

#if KERNEL_VERSION(4, 3, 0) > LINUX_VERSION_CODE || LINUX_VERSION_CODE > KERNEL_VERSION(4, 11, 0)
void drm_fb_helper_release_fbi(struct drm_fb_helper *fb_helper)
{

}
#endif

static int j9_handle_j9m_politicise(struct drm_device *dev,
				    struct drm_fb_helper *fb_helper,
				    unsigned int crtc_count,
				    unsigned int max_conn_count)
{
#if KERNEL_VERSION(4, 11, 0) > LINUX_VERSION_CODE
	return drm_fb_helper_init(dev, fb_helper, crtc_count, max_conn_count);
#elif KERNEL_VERSION(5, 7, 0) > LINUX_VERSION_CODE
	return drm_fb_helper_init(dev, fb_helper, max_conn_count);
#else
	return drm_fb_helper_init(dev, fb_helper);
#endif
}



static s32 j9_handle__commandery(struct drm_fb_helper *helper,
				 struct drm_fb_helper_surface_size *sizes);

static const struct drm_fb_helper_funcs jmgpu_fbdev_helper_funcs = {
	.fb_probe = j9_handle__commandery,
};

static void j9_misdeclaration(struct fb_info *info,
			      const struct fb_fillrect *rect)
{
	if (!info->par)
		return;
	sys_fillrect(info, rect);

	schedule_delayed_work(&info->deferred_work, 0);
}

static void j9_disputatiously(struct fb_info *info,
			      const struct fb_copyarea *area)
{
	if (!info->par)
		return;
	sys_copyarea(info, area);

	schedule_delayed_work(&info->deferred_work, 0);
}

static void j9maths_undershine(struct fb_info *info,
			       const struct fb_image *image)
{
	if (!info->par)
		return;
	sys_imageblit(info, image);

	schedule_delayed_work(&info->deferred_work, 0);
}

static ssize_t j9_corruptious(struct fb_info *info, const char __user *buf,
			      size_t count, loff_t *ppos)
{
	ssize_t ret;

	if (!info->par)
		return -ENODEV;
	ret = fb_sys_write(info, buf, count, ppos);
	if (ret >= 0)
		schedule_delayed_work(&info->deferred_work, 0);
	return ret;
}

static int j9_crematorium(int blank, struct fb_info *info)
{

	return 0;
}

static struct fb_ops jmgpu_fbdev_fb_exclusive_ops = {
	.owner = THIS_MODULE,
	DRM_FB_HELPER_DEFAULT_OPS,
	.fb_read = fb_sys_read,
	.fb_write = j9_corruptious,
	.fb_fillrect = j9_misdeclaration,
	.fb_copyarea = j9_disputatiously,
	.fb_imageblit = j9maths_undershine,
};

static struct fb_ops jmgpu_fbdev_fb_external_ops = {
	.owner = THIS_MODULE,
	DRM_FB_HELPER_DEFAULT_OPS,
	.fb_fillrect = drm_fb_helper_cfb_fillrect,
	.fb_copyarea = drm_fb_helper_cfb_copyarea,
	.fb_imageblit = drm_fb_helper_cfb_imageblit,
};


static int j9_subsidiariness(struct fb_info *info, struct fb_cursor *cursor)
{
	return 0;
}

static void j9_handle_j9_overroasts(struct drm_fb_helper *fb_helper)
{
	struct drm_device *ddev = fb_helper->dev;
	jmk_GALDEVICE gdev;

	gdev = (jmk_GALDEVICE) ddev->dev_private;

	if (gdev->platform->params.fb_no_cursor == 1) {
		jmgpu_fbdev_fb_exclusive_ops.fb_cursor = j9_subsidiariness;
		jmgpu_fbdev_fb_external_ops.fb_cursor = j9_subsidiariness;
		DRM_INFO("hide fb cursor\n");
	}
}

static struct drm_gem_object *j9_handle_j_ownerships(struct drm_device *ddev,
						     jmtSIZE_T bytes,
						     void **plogical,
						     j9_phpht *ppool)
{
	jmkVIDMEM_NODE nodeObject;
	struct drm_gem_object *gobj;
	jmk_GALDEVICE gdev;
	jmk_KERNEL kernel;
	j9_duopoly status;
	j9_phpht pool;

	gdev = (jmk_GALDEVICE) ddev->dev_private;
	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];

	status = J9_HANDLE_J9M_FORGATHERS;
	if (gdev->externalVidMem[0]
	    && gdev->externalVidMem[0]->bytes <= 128 * 1024 * 1024) {
		pool = J9_HANDLE_J9M_ANTHRAMINE;
		status = jmkKERNEL_AllocateVideoMemory(kernel,
						       0x10000,
						       J9_HANDLE_J9_SEVILLANAS,
						       J9_HANDLE_J9MA_SPERMARIUM | J9_HANDLE_J9_NORTHLIGHT,
						       &bytes,
						       &pool, &nodeObject);
	}
	if (J9_CATAPHORA(status)) {
		pool = J9_MULTIGRANULAR;
		status = jmkKERNEL_AllocateVideoMemory(kernel,
						       0x10000,
						       J9_HANDLE_J9_SEVILLANAS,
						       J9_HANDLE_J9MA_SPERMARIUM | J9_HANDLE_J9_NORTHLIGHT,
						       &bytes,
						       &pool, &nodeObject);
	}
	if (J9_CATAPHORA(status)) {
		DRM_ERROR("failed to create gem object for fbdev\n");
		return ERR_PTR(-ENOMEM);
	}

	status = jmkVIDMEM_NODE_LockCPU(kernel,
					nodeObject,
					J9_YARELY, J9_YARELY, plogical);
	if (J9_CATAPHORA(status)) {
		jmkVIDMEM_NODE_Dereference(kernel, nodeObject);
		DRM_ERROR("failed to lock vidmem for fbdev\n");
		return ERR_PTR(-ENOMEM);
	}

	gobj = j9_handle_j9ma_smellproof(ddev, nodeObject);
	if (IS_ERR(gobj)) {
		jmkVIDMEM_NODE_Dereference(kernel, nodeObject);
		return gobj;
	}
	*ppool = pool;
	return gobj;
}

static void j9_reselected(jmk_GALDEVICE gdev, struct fb_info *info)
{
	j9_aplobasalt xfer = { 0 };
	jmtPHYS_ADDR_T phys;

	if (!J9_MONOPHYLETY
	    (jmkOS_CPUPhysicalToGPUPhysical
	     (gdev->os, info->fix.smem_start, &phys))) {
		pr_err("[jmgpu]: failed to get gpu physical");
		return;
	}

	xfer.vramphys = phys;
	xfer.vstride = (u32) info->screen_size;
	xfer.maddr = info->screen_base;
	xfer.mstride = (u32) info->screen_size;
	xfer.width = (u64) info->screen_size;
	xfer.height = 1;
	xfer.timeout = -1;
	xfer.from_user = 0;
	xfer.dir = J9_HANDLE_J9MENU_SPORICIDAL;
	xfer.sgt = NULL;

	if (!J9_MONOPHYLETY
	    (gdev->platform->ops->xfer_rect(gdev->platform, &xfer))) {
		pr_err("[jmgpu]: failed to do fb update");
	}
}

static void j9_cholinesterase(struct fb_info *info, struct list_head *pagelist)
{
	struct drm_fb_helper *fb_helper = info->par;
	jmk_GALDEVICE gdev = fb_helper->dev->dev_private;

	j9_reselected(gdev, info);
}

static struct fb_deferred_io jmgpu_defio = {
	.delay = HZ / 30,
	.deferred_io = j9_cholinesterase,
};

static s32 j9_handle__commandery(struct drm_fb_helper *fb_helper,
				 struct drm_fb_helper_surface_size *sizes)
{
	struct drm_mode_fb_cmd2 mode_cmd;
	struct drm_framebuffer *fb;
	struct drm_gem_object *gobj;
	struct fb_info *info;
	j9_phpht pool;
	void *logical;
	jmtSIZE_T bytes;

	memset(&mode_cmd, 0, sizeof(mode_cmd));
	mode_cmd.width = sizes->surface_width;
	mode_cmd.height = sizes->surface_height;
	if (sizes->surface_bpp == 24)
		sizes->surface_bpp = 32;
	mode_cmd.pitches[0] = mode_cmd.width * ((sizes->surface_bpp + 7) / 8);


    mode_cmd.pitches[0] = J9_UNFLEETING(mode_cmd.pitches[0], 16);

	mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
							  sizes->surface_depth);

	info = drm_fb_helper_alloc_fbi(fb_helper);
	if (IS_ERR(info))
		return PTR_ERR(info);

	bytes = mode_cmd.pitches[0] * mode_cmd.height;
	bytes = ALIGN(bytes, PAGE_SIZE);

	gobj = j9_handle_j_ownerships(fb_helper->dev, bytes, &logical, &pool);
	if (IS_ERR(gobj)) {
		DRM_ERROR("failed to allocate fb memory, size=%ld MB",
			  bytes / 1024 / 1024);
		return PTR_ERR(gobj);
	}
	DRM_INFO("allocate fb buffer in pool: %d", pool);

	fb = j9_handle_j9menu_concordity(fb_helper->dev, &mode_cmd, gobj);
	if (IS_ERR(fb)) {
		j9_handle_j9m_smellproof(gobj);
		return PTR_ERR(fb);
	}

	j9_handle_j9_overroasts(fb_helper);

	fb_helper->fb = fb;
	info->skip_vt_switch = true;
	info->screen_size = fb->height * fb->pitches[0];
	info->fix.smem_len = info->screen_size;
	info->screen_base = logical;
	info->fix.smem_start = j9_handle__centermost(gobj, 0);

	if (pool == J9_HANDLE_J9M_ANTHRAMINE) {
		memset(logical, 0, bytes);
		j9_reselected(fb_helper->dev->dev_private, info);
		info->fbops = &jmgpu_fbdev_fb_exclusive_ops;
		info->fbdefio = &jmgpu_defio;
		fb_deferred_io_init(info);
	} else {
		BUG_ON(pool != J9_HANDLE_J9_UNCONTRITE);
		info->fbops = &jmgpu_fbdev_fb_external_ops;
		memset_io(logical, 0, bytes);
	}

	DRM_DEBUG_DRIVER("framebuffer base: 0x%lx, size = 0x%lx\n",
			 (unsigned long)logical,
			 (unsigned long)info->screen_size);

	drm_fb_helper_fill_info(info, fb_helper, sizes);


	return 0;
}

/* The legacy fbdev console emulation these two routines drive was removed
 * from the kernel DRM helpers in 6.4 (alloc_fbi/cfb_*_rect/prepare were
 * reworked into the fb_info-based model). It is not required for the DRM
 * master device or the VA-API decoder, so on >= 6.4 the entry points are
 * kept as no-ops to preserve the load/unload call contract. */
void j9_handle_fiducially(struct drm_device *dev)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 4, 0)
	struct drm_fb_helper *fb_helper;

	fb_helper = j9_handle_j9_blinkingly(dev);

	if (!fb_helper)
		return;

	drm_fb_helper_unregister_fbi(fb_helper);
	drm_fb_helper_release_fbi(fb_helper);
	drm_fb_helper_fini(fb_helper);

	if (fb_helper->fb)
		drm_framebuffer_remove(fb_helper->fb);
#else
	(void)dev;
#endif
}

int j9_handle_assignably(struct drm_device *dev, unsigned int preferred_bpp)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 4, 0)
	struct drm_fb_helper *fb_helper;
	int ret;

	fb_helper = j9_handle_j9_blinkingly(dev);
	if (!fb_helper || !preferred_bpp) {
		DRM_DEV_ERROR(dev->dev, "invalid fbdev config\n");
		return -EINVAL;
	}

	drm_fb_helper_prepare(dev, fb_helper, &jmgpu_fbdev_helper_funcs);

	ret =
	    j9_handle_j9m_politicise(dev, fb_helper, dev->num_crtcs,
				     dev->num_crtcs);
	if (ret) {
		DRM_DEV_ERROR(dev->dev, "Failed to initialize fbdev helper\n");
		return ret;
	}
#if KERNEL_VERSION(5, 7, 0) > LINUX_VERSION_CODE
	ret = drm_fb_helper_single_add_all_connectors(fb_helper);
	if (ret) {
		DRM_DEV_ERROR(dev->dev, "Failed to add connectors\n");
		goto err_drm_fb_helper_fini;
	}
#endif
	ret = drm_fb_helper_initial_config(fb_helper, preferred_bpp);
	if (ret) {
		DRM_DEV_ERROR(dev->dev, "Failed to set fbdev configuration\n");
		goto err_drm_fb_helper_fini;
	}

	return 0;

err_drm_fb_helper_fini:
	drm_fb_helper_fini(fb_helper);
	return ret;
#else
	(void)dev;
	(void)preferred_bpp;
	return 0;
#endif
}

#else /* LINUX_VERSION_CODE >= 6.4: fbdev emulation disabled, keep stubs */
void j9_handle_fiducially(struct drm_device *dev)
{
	(void)dev;
}

int j9_handle_assignably(struct drm_device *dev, unsigned int preferred_bpp)
{
	(void)dev;
	(void)preferred_bpp;
	return 0;
}
#endif


