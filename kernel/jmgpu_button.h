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





#include <drm/drm_gem.h>
#if KERNEL_VERSION(5, 4, 0) >= LINUX_VERSION_CODE
#include <drm/drmP.h>
#endif

#ifndef __7a2ca4b0_H_
#define __7a2ca4b0_H_

#ifdef __cplusplus
extern "C" {
#endif

#define J9_HANDLE_J9MATHS_CONCORDITY    0x1

#ifdef JMGPU_DRM_STANDALONE
	typedef struct tag_jms_gem_object {
		struct drm_gem_object base;
		u32 node_handle;
		void *node_object;
		bool cacheable;
		u32 alloc_flag;
		u32 pid;
	} j9_multihearth;
#else
#include "jmgpu_standard.h"
	typedef struct tag_jms_gem_object {
		struct drm_gem_object base;
		u32 node_handle;
		jmkVIDMEM_NODE node_object;
		jmtBOOL cacheable;
		jmtUINT32 alloc_flag;
		jmtUINT32 pid;
	} j9_multihearth;
#endif

#if KERNEL_VERSION(5, 0, 0) > LINUX_VERSION_CODE
#define j9_handle_j9m_smellproof drm_gem_object_unreference_unlocked
#elif KERNEL_VERSION(5, 9, 0) > LINUX_VERSION_CODE
#define j9_handle_j9m_smellproof drm_gem_object_put_unlocked
#else
#define j9_handle_j9m_smellproof drm_gem_object_put
#endif

	s32 jm_gem_create_object(struct drm_device *dev, u32 size,
				 struct drm_gem_object **gobj);
	void jm_gem_free_object(struct drm_gem_object *gobj);
	u64 j9_handle__centermost(struct drm_gem_object *gobj, u64 offset);
	u64 j9_handle__ballasting(struct drm_gem_object *gobj, u64 offset);

	struct drm_gem_object *j9_handle_j9ma_smellproof(struct drm_device *dev,
							 jmkVIDMEM_NODE node);

#ifdef __cplusplus
}
#endif
#endif


