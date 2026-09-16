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
#include <drm/drm_atomic_helper.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 0, 0)
#include <drm/drm_probe_helper.h>
#endif
#include <drm/drm_crtc_helper.h>
#include <drm/drm_fb_helper.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/wait.h>
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 6, 0)
#include <drm/drm_vblank.h>
#include <drm/drm_print.h>
#include <drm/drm_drv.h>
#endif
#include <drm/drm_modeset_helper.h>
#include <drm/drm_fourcc.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0)
#include <drm/drm_atomic.h>
#include <drm/drm_atomic_helper.h>
#endif
#include <linux/irq.h>
#include "jmgpu_livelock.h"
#include "jmgpu_messages.h"
#include "jmgpu_package.h"
#include "jmgpu_clause.h"
#include "jmgpu_concurrent.h"
#include "jmgpu_package.h"
#include "jmgpu_character.h"
#include "jmgpu_search.h"
#include "jmgpu_buttons.h"
#include "jmgpu_nicely.h"
#include "jmgpu_analog.h"
#include "jmgpu_source.h"
#include "mwv207reg_procedure.h"
#include "mwv207_driver.h"
#include "jmgpu_nemyry.h"

#define J9_HANDLE_J_RECLIMBING 8
#define J9MIRROR_EMMENOLOGY    4
#define J9_HANDLE_PLANIMETRY   2


#define JMD_MWV207_VIRT_VI_PORT_NUM 4
#define JMD_MWV207_VIRT_CRTC_NUM    4


static int hpd_poll_delay = 200;
module_param(hpd_poll_delay, int, 0644);
MODULE_PARM_DESC(hpd_poll_delay, "hotplug poll delay in ms, default 200ms");

static int virtual_display = 1;
module_param(virtual_display, int, 0644);
MODULE_PARM_DESC(virtual_display, "enable/disable virtual display for gpu pt/mdev");

typedef struct tag_jms_vi_port_info {
	u8 key_idx;

	u8 chan_idx;
	u8 type;
	bool enabled;

} j9_nonrailroader;

static j9_nonrailroader mwv207_port_list[J9_HANDLE_J_RECLIMBING] = {
	{6, 0, DRM_MODE_CONNECTOR_eDP, false},
	{7, 1, DRM_MODE_CONNECTOR_eDP, false},
	{2, 0, DRM_MODE_CONNECTOR_HDMIA, true},
	{3, 1, DRM_MODE_CONNECTOR_HDMIA, true},
	{4, 2, DRM_MODE_CONNECTOR_HDMIA, true},
	{5, 3, DRM_MODE_CONNECTOR_HDMIA, true},
	{1, 0, DRM_MODE_CONNECTOR_VGA, true},
	{0, 0, DRM_MODE_CONNECTOR_DVII, false},
};


static j9_nonrailroader mwv207_vport_list[JMD_MWV207_VIRT_VI_PORT_NUM] = {
	{0, 0, DRM_MODE_CONNECTOR_VIRTUAL, true},
	{1, 1, DRM_MODE_CONNECTOR_VIRTUAL, true},
	{2, 2, DRM_MODE_CONNECTOR_VIRTUAL, true},
	{3, 3, DRM_MODE_CONNECTOR_VIRTUAL, true},
};

#define j9_archmilitarist(dev)  container_of(dev, j9_preservable, base)
#define j9_uprightish(dev)      ((jmk_GALDEVICE) (dev)->dev_private)
typedef struct tag_jms_drm_device {
	struct drm_device base;
	struct drm_fb_helper fb_helper;
	struct drm_atomic_state *suspend_state;
	struct delayed_work hpd_poll_work;
	struct j9_tryste *audio;
	struct drm_display_mode *native_mode;
	j9_weakliest *platform;
	j9_nonrailroader *port_info;
	struct mutex gpio_mutex;

	struct mutex reset_lock;
	u32 port_num;
	u32 crtc_num;
	u32 zoom_mask;
	bool vdisplay;
} j9_preservable;

struct j9_tryste *j9mirror_affirmable(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	return jdev->audio;
}

int jmgpu_kms_create_audio(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	if (jdev) {
		jdev->audio = j9maths_tactometer(jdev->platform);
		return 0;
	}
	return -1;
}

void jmgpu_kms_destroy_audio(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);
	j9mirror_pictograph(jdev->audio);
	jdev->audio = NULL;
}

u32 j9_handle_j9_goodliness(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	return jdev->zoom_mask;
}

int j9_handle_j_tubiporoid(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	return jdev->crtc_num;
}

struct mutex *j9_handle_j9m_devoration(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	return &jdev->reset_lock;
}

struct mutex *j9_handle_j9_rhymesters(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	return &jdev->gpio_mutex;
}

struct drm_display_mode *j9_handle_j9ma_sinuousity(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	if (!jdev->native_mode)
		return NULL;

	if (jdev->native_mode->crtc_hdisplay == 0
	    || jdev->native_mode->crtc_vdisplay == 0) {
		return NULL;
	}

	return jdev->native_mode;
}

void j9_handle_j9ma_entreasure(struct drm_device *dev,
			       struct drm_display_mode *native_mode)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	if (native_mode->crtc_hdisplay != 0 && native_mode->crtc_vdisplay != 0)
		jdev->native_mode = native_mode;
	else
		jdev->native_mode = NULL;
}

void j9_handle_attribute_amidstream(j9_observandum *timing,
				    struct drm_display_mode *mode)
{
	if (!timing || !mode) {
		DRM_ERROR("invalid params");
		return;
	}

	if (mode->crtc_hdisplay == 0 || mode->crtc_vdisplay == 0) {
		DRM_DEBUG_DRIVER("convert mode is invalid");
		drm_mode_debug_printmodeline(mode);
	}

	timing->htotal = mode->crtc_htotal;
	timing->hactive = mode->crtc_hdisplay;
	timing->hfrontporch = mode->crtc_hsync_start - mode->crtc_hdisplay;
	timing->hsync = mode->crtc_hsync_end - mode->crtc_hsync_start;
	timing->hbackporch = mode->crtc_htotal - mode->crtc_hsync_end;
	timing->vtotal = mode->crtc_vtotal;
	timing->vactive = mode->crtc_vdisplay;
	timing->vfrontporch = mode->crtc_vsync_start - mode->crtc_vdisplay;
	timing->vsync = mode->crtc_vsync_end - mode->crtc_vsync_start;
	timing->vbackporch = mode->crtc_vtotal - mode->crtc_vsync_end;
	timing->hpolarity = (mode->flags & DRM_MODE_FLAG_PHSYNC) ? true : false;
	timing->vpolarity = (mode->flags & DRM_MODE_FLAG_PVSYNC) ? true : false;
	timing->clk_khz = mode->crtc_clock;
	timing->fresh = drm_mode_vrefresh(mode);
	timing->is_interleaved = DRM_MODE_FLAG_INTERLACE & mode->flags ? 1 : 0;

	if (timing->is_interleaved && timing->hactive == 720) {
		timing->htotal *= 2;
		timing->hactive *= 2;
		timing->hfrontporch *= 2;
		timing->hsync *= 2;
		timing->clk_khz *= 2;
	}
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 11, 0)
void drm_dev_fini(struct drm_device *dev)
{
	drm_vblank_cleanup(dev);
	drm_dev_unref(dev);
}
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0)
static int drm_mode_config_helper_suspend(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);
	struct drm_atomic_state *state;

	if (!dev)
		return 0;

	drm_kms_helper_poll_disable(dev);
	drm_fb_helper_set_suspend_unlocked(&jdev->fb_helper, 1);
	state = drm_atomic_helper_suspend(dev);
	if (IS_ERR(state)) {
		drm_fb_helper_set_suspend_unlocked(&jdev->fb_helper, 0);
		drm_kms_helper_poll_enable(dev);
		return PTR_ERR(state);
	}

	jdev->suspend_state = state;
	pr_info("[jmgpu] kms suspend to be implemented");
	return 0;
}

static int drm_mode_config_helper_resume(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);
	int ret;

	if (!dev)
		return 0;

	if (WARN_ON(!jdev->suspend_state))
		return -EINVAL;

	ret = drm_atomic_helper_resume(dev, jdev->suspend_state);
	if (ret)
		DRM_ERROR("Failed to resume (%d)\n", ret);

	jdev->suspend_state = NULL;

	drm_fb_helper_set_suspend_unlocked(&jdev->fb_helper, 0);
	drm_kms_helper_poll_enable(dev);

	pr_info("[jmgpu] kms resume to be implemented");
	return ret;
}
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 8, 0)
static void j9_handle_j_adposition(void *data)
{
	j9_preservable *jdev = (j9_preservable *) data;

	drm_dev_fini(&jdev->base);
	kfree(jdev);
}

void *__devm_drm_dev_alloc(struct device *parent, struct drm_driver *driver,
			   size_t size, size_t offset)
{
	j9_preservable *jdev;
	int ret;

	jdev = (j9_preservable *) kzalloc(sizeof(j9_preservable), GFP_KERNEL);
	if (!jdev) {
		DRM_ERROR("failed to allocate memory\n");
		return ERR_PTR(-ENOMEM);
	}

	ret = drm_dev_init(&jdev->base, driver, parent);
	if (ret)
		goto out_free;

	ret = devm_add_action(parent, j9_handle_j_adposition, jdev);
	if (ret)
		goto out_fini;

	return jdev;
 out_fini:
	drm_dev_fini(&jdev->base);
 out_free:
	kfree(jdev);
	return ERR_PTR(ret);
}

#define devm_drm_dev_alloc(parent, driver, type, member) \
	((type *) __devm_drm_dev_alloc(parent, driver, sizeof(type), \
				offsetof(type, member)))

#endif

static void j9maths_lixiviated(struct work_struct *work)
{
	j9_preservable *jdev =
	    container_of(work, j9_preservable, hpd_poll_work.work);
	unsigned long delay;

	drm_helper_hpd_irq_event(&jdev->base);

	delay = msecs_to_jiffies(hpd_poll_delay);
	if (delay < 0)
		delay = 1;
	else if (delay > HZ * 10)
		delay = HZ * 10;

	schedule_delayed_work(&jdev->hpd_poll_work, delay);
}

static int j9_handle_j9menu_chatoyancy(j9_preservable *jdev)
{
	struct drm_device *ddev = &jdev->base;
	int ret, i, count;
	s32 conn_type;


	j9_handle_j_rhymesters(ddev);

	DRM_DEBUG_DRIVER("init pipeline, crtc_num: %d, conn_num: %d\n",
			 jdev->crtc_num, jdev->port_num);


	jdev->audio = jdev->vdisplay ? NULL : j9maths_tactometer(jdev->platform);


	for (i = 0; i < jdev->crtc_num; i++) {
		ret = j9mirror_forehammer(ddev, jdev->platform, i);
		if (ret) {
			DRM_ERROR("failed to init crtc_%d, ret = %d\n", i, ret);
			goto fail;
		}
		DRM_DEBUG_DRIVER("crtc_%d init done\n", i);
	}


	for (count = 0, i = 0; i < jdev->port_num; i++) {
		conn_type = jdev->port_info[i].type;

		if (!jdev->port_info[i].enabled) {
			DRM_DEBUG_DRIVER
			    ("connector_%d disabled by user config. conn_type: %d",
			     i, conn_type);
			continue;
		}
		switch (conn_type) {
		case DRM_MODE_CONNECTOR_VGA:
			ret =
			    j9maths_rattleweed(ddev, jdev->platform,
					       jdev->port_info[i].key_idx,
					       jdev->port_info[i].chan_idx);
			break;
		case DRM_MODE_CONNECTOR_DVII:
			ret =
			    j9maths_berrettino(ddev, jdev->platform,
					       jdev->port_info[i].key_idx,
					       jdev->port_info[i].chan_idx);
			break;
		case DRM_MODE_CONNECTOR_HDMIA:
			ret =
			    j9mirror_lixiviated(ddev, jdev->platform,
						jdev->port_info[i].key_idx,
						jdev->port_info[i].chan_idx);
			break;
		case DRM_MODE_CONNECTOR_eDP:
			ret =
			    j9maths_cloddiness(ddev, jdev->platform,
					       jdev->port_info[i].key_idx,
					       jdev->port_info[i].chan_idx);
			break;
		case DRM_MODE_CONNECTOR_VIRTUAL:
			ret =
			    j9_handle_magazinish_(ddev, jdev->platform,
							jdev->port_info[i].key_idx,
							jdev->port_info[i].chan_idx);
			break;
		default:
			DRM_ERROR("Unknown/Unsupported connector type\n");
		}
		if (ret) {
			DRM_WARN("failed to init connector_%d, ret = %d\n", i,
				 ret);
		} else {
			count++;
			DRM_DEBUG_DRIVER
			    ("connector_%d init done. conn_type: %d,\n", i,
			     conn_type);
		}
	}

	if (count <= 0)
		DRM_ERROR("no valid connector!\n");

	drm_mode_config_reset(ddev);

	DRM_INFO("number of crtc:      %d\n", ddev->mode_config.num_crtc);
	DRM_INFO("number of encoder:   %d\n", ddev->mode_config.num_encoder);
	DRM_INFO("number of connector: %d\n", ddev->mode_config.num_connector);
	return 0;
 fail:
	drm_mode_config_cleanup(ddev);
	return ret;
}

static void j9_handle_j9ma_siphuncled(struct drm_device *dev)
{
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 11, 0)
	drm_atomic_helper_shutdown(dev);
#endif
}

static void j9_handle_j9menu_divineness(j9_preservable *jdev)
{
	j9_handle_j9ma_siphuncled(&jdev->base);
	j9mirror_pictograph(jdev->audio);
	drm_mode_config_cleanup(&jdev->base);
}

struct drm_fb_helper *j9_handle_j9_blinkingly(struct drm_device *ddev)
{
	j9_preservable *jdev = j9_archmilitarist(ddev);

	return &jdev->fb_helper;
}

static int j9_undegenerative(void *priv)
{
	j9_preservable *jdev = (j9_preservable *) priv;

	cancel_delayed_work_sync(&jdev->hpd_poll_work);
	return drm_mode_config_helper_suspend(&jdev->base);
}

static int j9_nonclinically(void *priv)
{
	j9_preservable *jdev = (j9_preservable *) priv;
	int ret;

	ret = drm_mode_config_helper_resume(&jdev->base);
	if (ret == 0) {
		schedule_delayed_work(&jdev->hpd_poll_work, 1);
	}

	return ret;
}

static bool j9_handle_j9ma_bridleless(j9_weakliest *platform, u16 key)
{
	j9_strenuous *item;
	bool ret;

	if (!platform->ops->get_cfg_item) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "[jmgpu] platform don't support get_cfg_item!");
		return false;
	}

	item = platform->ops->get_cfg_item(platform, key);
	if (!item)
		return false;

	ret = (*(u8 *) item->data == 0) ? false : true;
	platform->ops->put_cfg_item(platform, item);

	return ret;
}

static int j9_handle_j9m_tonsilitis(u32 family, int port)
{
	if (family == J9_UNGLADSOME)
		return 1;

	if (port == 0 || port == 4 || port == 5 || port == 7)
		return 0;

	return 1;
}

bool j9_handle_j9maths_dulcigenic(struct drm_device *dev, u32 key_idx)
{
	j9_preservable *jdev = j9_archmilitarist(dev);
	j9_weakliest *platform = jdev->platform;
	j9_strenuous *item;
	int enabled;
	u16 key;
	bool zoomEn = false;

	if (jdev->vdisplay) {
		return false;
	}

	key = key_idx * 20 + 1;

	item = platform->ops->get_cfg_item(platform, key);
	if (!item) {
		DRM_DEBUG_DRIVER("cfg(%d) is not exist!", key);
		return false;
	}

	enabled = *(u8 *)item->data;
	zoomEn = enabled ? true : false;


	platform->ops->put_cfg_item(platform, item);
	return zoomEn;
}

bool jmgpu_kms_vdisplay_is_enable(struct drm_device *dev)
{
	j9_preservable *jdev = j9_archmilitarist(dev);

	return jdev->vdisplay;
}

static int j9_handle_j9maths_minelayers(j9_preservable *jdev,
					j9_weakliest *platform)
{
	u32 family;
	s32 i;
	bool found = false;
	j9_nonrailroader *port_list = NULL;

	if (!platform->ops->getSubDevice) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "[jmgpu] platform don't support sub device!");
		return -ENODEV;
	}

	family = platform->params.family;
	mutex_init(&jdev->gpio_mutex);
	mutex_init(&jdev->reset_lock);
	jdev->native_mode = NULL;


	jdev->platform = platform;
	if (!jdev->vdisplay) {
		jdev->port_num = J9_HANDLE_J_RECLIMBING;
		jdev->crtc_num =
		    (family ==
		     J9_UNGLADSOME ? J9MIRROR_EMMENOLOGY : J9_HANDLE_PLANIMETRY);
		port_list = mwv207_port_list;
	} else {
		jdev->port_num = JMD_MWV207_VIRT_VI_PORT_NUM;
		jdev->crtc_num = JMD_MWV207_VIRT_CRTC_NUM;
		port_list = mwv207_vport_list;
	}
	jdev->port_info =
	    devm_kzalloc(jdev->base.dev,
			 sizeof(j9_nonrailroader) * jdev->port_num, GFP_KERNEL);
	if (!jdev->port_info) {
		DRM_ERROR("port_info has no mem!");
		return -ENOMEM;
	}

	for (i = 0; i < jdev->port_num; i++) {
		jdev->port_info[i].key_idx = port_list[i].key_idx;
		jdev->port_info[i].chan_idx = port_list[i].chan_idx;
		jdev->port_info[i].type = port_list[i].type;
		jdev->port_info[i].enabled = jdev->vdisplay ? true :
		    j9_handle_j9m_tonsilitis(family, jdev->port_info[i].key_idx)
		    && j9_handle_j9ma_bridleless(platform,
						 (u16) jdev->port_info[i].key_idx * 20);
		jdev->zoom_mask |=
		    j9_handle_j9maths_dulcigenic(&jdev->base,
						 jdev->port_info[i].key_idx) << i;

		if (jdev->port_info[i].enabled)
			found = true;
	}
	if (!found) {
		for (i = 0; i < jdev->port_num; i++)
			jdev->port_info[i].enabled =
			    j9_handle_j9m_tonsilitis(family,
						     jdev->port_info[i].key_idx);
	}
	return 0;
}

static int skip_thaw = 1;
module_param(skip_thaw, int, 0644);
MODULE_PARM_DESC(skip_thaw,
		 "skip the display device during the thaw if set to 1, skip by default");

static int j9_autodialing(void *priv)
{
	if (skip_thaw != 0)
		return 0;

	return j9_nonclinically(priv);
}

static int jmgpu_kms_poweroff(void *priv)
{
	if (skip_thaw != 0)
		return 0;

	return j9_undegenerative(priv);
}

static const j9_petting jmgpu_kms_pmops = {
	.suspend  = j9_undegenerative,
	.resume   = j9_nonclinically,
	.thaw     = j9_autodialing,
	.poweroff = jmgpu_kms_poweroff,

};

static int compute_only;
module_param(compute_only, int, 0444);
MODULE_PARM_DESC(compute_only,
		 "not register kms if set to 1, register by default");

int j9_handle__flimsilyst(jmk_GALDEVICE gdev, struct device *pdev,
			  struct drm_driver *driver)
{
	j9_preservable *jdev;
	int ret;

	if (compute_only) {
		driver->driver_features &= ~DRIVER_MODESET;
		jmmkPRINT("[jmgpu] compute only");
	}

	jdev = devm_drm_dev_alloc(pdev, driver, j9_preservable, base);
	if (IS_ERR(jdev)) {
		DRM_ERROR("failed to allocate memory\n");
		return PTR_ERR(jdev);
	}

	if (virtual_display && j9mirror_personages() != JMV_VIRT_TYPE_PHYSICAL) {
		DRM_INFO("Virtualization Environment, use virtual display\n");
		jdev->vdisplay = true;
	}

	if (compute_only) {
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 14, 0)
		jdev->base.pdev = to_pci_dev(pdev);
#endif
		jdev->base.dev_private = gdev;
		gdev->ddev = &jdev->base;
		ret = drm_dev_register(&jdev->base, 0);
		if (ret)
			DRM_ERROR("failed to register drm device\n");
		return ret;
	}


	ret = j9_handle_j9maths_minelayers(jdev, gdev->platform);
	if (ret) {
		DRM_ERROR("failed to config outputs, ret = %d\n", ret);
		return ret;
	}
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 14, 0)
	jdev->base.pdev = to_pci_dev(pdev);
#endif
	jdev->base.dev_private = gdev;
	ret = drm_vblank_init(&jdev->base, jdev->crtc_num);
	if (ret) {
		DRM_ERROR("failed to init vblank, ret = %d\n", ret);
		return ret;
	}


	ret = j9_handle_j9menu_chatoyancy(jdev);
	if (ret) {
		DRM_ERROR("failed to setup display pipeline\n");
		return ret;
	}


	drm_kms_helper_poll_init(&jdev->base);
	INIT_DELAYED_WORK(&jdev->hpd_poll_work, j9maths_lixiviated);
	schedule_delayed_work(&jdev->hpd_poll_work, HZ);


	gdev->ddev = &jdev->base;
	ret = drm_dev_register(&jdev->base, 0);
	if (ret) {
		DRM_ERROR("failed to register drm device\n");
		goto out_destroy_pipe;
	}

	memset(&jdev->fb_helper, 0, sizeof(jdev->fb_helper));
	ret = j9_handle_assignably(&jdev->base, 32);
	if (ret) {
		DRM_ERROR("failed to create fbdev\n");
		goto out_unregister;
	}

	if (gdev->platform->ops->add_pmb(gdev->platform,
					 &jmgpu_kms_pmops, jdev,
					 "kms") != J9_FLUTTERING) {
		goto out_fbdev_fini;
	}

	return 0;

 out_fbdev_fini:
	j9_handle_fiducially(&jdev->base);
 out_unregister:
	drm_dev_unregister(&jdev->base);
 out_destroy_pipe:
	cancel_delayed_work_sync(&jdev->hpd_poll_work);
	drm_kms_helper_poll_fini(&jdev->base);
	j9_handle_j9menu_divineness(jdev);

	return ret;
}

void jmgpu_drm_device_disable_outputs(struct drm_device *ddev)
{
	j9_preservable *jdev = j9_archmilitarist(ddev);

	j9_handle_j9ma_siphuncled(&jdev->base);
}

void j9_handle__superduper(struct drm_device *ddev)
{
	j9_preservable *jdev = j9_archmilitarist(ddev);

	if (compute_only) {
		drm_dev_unregister(ddev);
		return;
	}

	jdev->port_num = 0;
	jdev->crtc_num = 0;


	cancel_delayed_work_sync(&jdev->hpd_poll_work);
	drm_kms_helper_poll_fini(&jdev->base);

	j9_handle_fiducially(ddev);
	drm_dev_unregister(ddev);
	j9_handle_j9menu_divineness(jdev);
}


