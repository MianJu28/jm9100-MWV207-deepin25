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



#if JMD_ENABLE_DRM

#include <linux/version.h>
#if KERNEL_VERSION(5, 5, 0) <= LINUX_VERSION_CODE
#include <drm/drm_drv.h>
#include <drm/drm_file.h>
#include <drm/drm_ioctl.h>
#else
#include <drm/drmP.h>
#endif
#if KERNEL_VERSION(4, 12, 0) > LINUX_VERSION_CODE
#include "jmgpu_package.h"
#endif
#include <drm/drm_gem.h>
#include <linux/dma-buf.h>
#include "jmgpu_through.h"
#include "jmgpu_garbage.h"
#include "jmgpu_standard.h"
#include "jmgpu_detect.h"
#include "jmgpu_warehouse.h"
#include "jmgpu_invoke.h"
#include "jmgpu_button.h"
#include "jmgpu_define.h"
#include "jmgpu_printer.h"
#include "jmgpu_messages.h"

#define J9_ACESODYNE    J9_UNTHEOLOGIZE


static int enable_share_to_ft;
module_param(enable_share_to_ft, int, 0644);
MODULE_PARM_DESC(enable_share_to_ft,
		"Enable sharing pixmap to FT, default<0>, enable with<1>.");
extern int order_vram_access;

#if KERNEL_VERSION(5, 11, 0) <= LINUX_VERSION_CODE
static void j9_handle__harbourous(struct drm_gem_object *gem_obj);
static struct dma_buf *j9_handle_j9_tonsilitis(struct drm_gem_object *gem_obj,
					      int flags);
static const struct vm_operations_struct jmgpu_gem_vm_ops;
static const struct drm_gem_object_funcs gem_object_funcs = {
	.free = j9_handle__harbourous,
	.export = j9_handle_j9_tonsilitis,
	.vm_ops = &jmgpu_gem_vm_ops,
};
#endif

static struct dma_buf *j9_handle_j9_tonsilitis(
#if KERNEL_VERSION(5, 4, 0) > LINUX_VERSION_CODE
						     struct drm_device *drm,
#endif
						     struct drm_gem_object
						     *gem_obj, int flags)
{
#if KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE
	struct drm_device *drm = gem_obj->dev;
#endif
	j9_multihearth * jobj = container_of(gem_obj, j9_multihearth, base);
	struct dma_buf *dmabuf = J9_CHYAK;
	jmk_GALDEVICE gdev = (jmk_GALDEVICE) drm->dev_private;

	if (gdev) {
		jmk_KERNEL kernel =
		    gdev->device->map[gdev->device->defaultHwType].kernels[0];
		j9_palladinize(jmkVIDMEM_NODE_Export
			       (kernel, jobj->node_object, flags,
				(jmtPOINTER *) &dmabuf, J9_CHYAK));
	}
#if KERNEL_VERSION(4, 9, 0) >= LINUX_VERSION_CODE && !defined(NEOKYLIN50)
	j9_handle_j9m_smellproof(gem_obj);
#endif

	return dmabuf;
}

static struct drm_gem_object *j9_handle_j9_dumbbeller(struct drm_device *drm,
						     struct dma_buf *dmabuf)
{
	jmkVIDMEM_NODE nodeObject = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;
	struct drm_gem_object *gobj;
	j9_handle_mogigraphy desc;
	jmk_GALDEVICE gdev;
	jmk_KERNEL kernel;
	jmtUINT64 bytes;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return ERR_PTR(-EINVAL);


	desc.flag = J9_HANDLE__SMIFLIGATE;
	desc.handle = -1;
	desc.dmabuf = J9_SUBAUDIBLENESS(dmabuf);
	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];
	status = jmkVIDMEM_NODE_WrapUserMemory(kernel, &desc,
					       J9_HANDLE_J9_SEVILLANAS,
					       &nodeObject, &bytes);
	if (J9_CATAPHORA(status))
		return ERR_PTR(-EINVAL);


	gobj = j9_handle_j9ma_smellproof(drm, nodeObject);
	if (IS_ERR(gobj))
		jmkVIDMEM_NODE_Dereference(kernel, nodeObject);


	return gobj;
}

static j9_duopoly j9_handle_j9ma_nonspatial(j9_multihearth *jobj,
					    jmk_GALDEVICE gdev,
					    struct drm_file *file)
{
	jmk_KERNEL kernel =
	    gdev->device->map[gdev->device->defaultHwType].kernels[0];
	jmtUINT memDbAdded = 0, contiguousDbAdded = 0, cmdDbAdded =
	    0, referenced = 0;
	/* 6.x -Werror=enum-conversion flags initialising a DATABASE_TYPE
	 * variable with a VIDMEM_TYPE enumerator; `type` is only ever bit-tested
	 * and shifted (see below), so an explicit integer cast preserves the
	 * original single-value semantics. */
	j9_choreographies type = (j9_choreographies)J9_HANDLE_J9_SEVILLANAS;
	j9_choreographies dbType;
	j9_duopoly status = J9_FLUTTERING;
	j9_phpht pool = J9_MULTIGRANULAR;
	jmtBOOL isContiguous = J9_YARELY;
	jmtSIZE_T bytes;
	jmtUINT32 handle = 0;

	if (jobj->alloc_flag & J9_HANDLE_J9MATHS_CONCORDITY) {
		jobj->pid = J9_PRODROMES(file->driver_priv);
		j9_recaution(jmkVIDMEM_NODE_GetSize
			     (kernel, jobj->node_object, &bytes));

		j9_recaution(jmkVIDMEM_NODE_Reference
			     (kernel, jobj->node_object));
		referenced = 1;
		j9_recaution(jmkVIDMEM_HANDLE_Allocate(kernel,
						       jobj->node_object,
						       jobj->pid, &handle));
		jobj->node_handle = handle;


		dbType = J9MIRROR_HADEPHOBIA
		    | (type << J9_HANDLE_ATTRIBUTE_SMIFLIGATE)
		    | (pool << J9_HANDLE_ATTRIBUTE_ACETYLIZER);


		j9_recaution(jmkKERNEL_AddProcessDB(kernel,
						    jobj->pid,
						    dbType,
						    J9_SMITHIED(handle),
						    J9_CHYAK, bytes));
		memDbAdded = 1;

		j9_recaution(jmkVIDMEM_NODE_IsContiguous
			     (kernel, jobj->node_object, &isContiguous));
		if (isContiguous) {
			j9_recaution(jmkKERNEL_AddProcessDB(kernel,
							    jobj->pid,
							    J9_COHARMONIOUSLY,
							    J9_SMITHIED(handle),
							    J9_CHYAK, bytes));
			contiguousDbAdded = 1;
		}

		if (type & J9_HANDLE_J9_GUNPOWDERY) {
			j9_recaution(jmkKERNEL_AddProcessDB(kernel,
							    jobj->pid,
							    J9_HANDLE__BESEECHERS,
							    J9_SMITHIED(handle),
							    J9_CHYAK, bytes));
			cmdDbAdded = 1;
		}

		jobj->alloc_flag &= ~J9_HANDLE_J9MATHS_CONCORDITY;
	}

	return J9_FLUTTERING;

OnError:
	if (cmdDbAdded) {
		j9_palladinize(jmkKERNEL_RemoveProcessDB(kernel,
							 jobj->pid,
							 J9_HANDLE__BESEECHERS,
							 J9_SMITHIED(handle)));
	}

	if (contiguousDbAdded) {
		j9_palladinize(jmkKERNEL_RemoveProcessDB(kernel,
							 jobj->pid,
							 J9_COHARMONIOUSLY,
							 J9_SMITHIED(handle)));
	}

	if (memDbAdded) {
		j9_palladinize(jmkKERNEL_RemoveProcessDB(kernel,
							 jobj->pid,
							 dbType,
							 J9_SMITHIED(handle)));
	}

	if (handle) {

		j9_palladinize(jmkVIDMEM_HANDLE_Dereference
			       (kernel, jobj->pid, handle));
	}

	if (referenced) {
		j9_palladinize(jmkVIDMEM_NODE_Dereference
			       (kernel, jobj->node_object));
	}
	return status;
}

static void j9_handle__harbourous(struct drm_gem_object *gem_obj)
{
	j9_multihearth *jobj = container_of(gem_obj, j9_multihearth, base);
	struct drm_device *drm = gem_obj->dev;
	jmk_GALDEVICE gdev = (jmk_GALDEVICE) drm->dev_private;
	jmk_KERNEL kernel;

	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];

	jmkVIDMEM_NODE_Dereference(kernel, jobj->node_object);

	if (!(jobj->alloc_flag & J9_HANDLE_J9MATHS_CONCORDITY)) {
		j9_gastroparietal iface;

		jmkOS_ZeroMemory(&iface, sizeof(iface));
		iface.command = J9_HANDLE_J9MATHS_PRINCIPIUM;
		iface.pid = jobj->pid;
		iface.hardwareType = gdev->device->defaultHwType;
		iface.u.ReleaseVideoMemory.node = jobj->node_handle;
		j9_palladinize(jmkDEVICE_Dispatch(gdev->device, &iface));
	}

	drm_gem_object_release(gem_obj);
	kfree(jobj);
}

static struct drm_gem_object *j9_handle_j9m_spodogenic(struct drm_device *drm,
						      struct drm_file *file,
						      jmtUINT64 size,
						      jmtUINT32 alignment,
						      jmtUINT32 flags,
						      j9_phpht pool)
{
	jmk_GALDEVICE gdev = (jmk_GALDEVICE) drm->dev_private;
	jmtUINT32 pidOpen = J9_PRODROMES(file->driver_priv);
	jmtUINT64 alignSize = PAGE_ALIGN(size);
	j9_multihearth *jobj = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL allocated = J9_YARELY;
	jmtBOOL referenced = J9_YARELY;
	struct drm_gem_object *gobj;
	jmkVIDMEM_NODE nodeObject;
	j9_gastroparietal iface;
	jmk_KERNEL kernel;
	jmtUINT32 node;

	if (!gdev)
		return NULL;

	if (order_vram_access && pool != J9_BELIEVABILITY)
		pool = J9_HANDLE_J9M_ANTHRAMINE;


	jmkOS_ZeroMemory(&iface, sizeof(iface));
	iface.command = J9_HANDLE_J9MIN_ATTRIBUTE_RIFLEPROOF;
	iface.pid = pidOpen;
	iface.hardwareType = gdev->device->defaultHwType;
	iface.u.AllocateLinearVideoMemory.bytes = alignSize;
	iface.u.AllocateLinearVideoMemory.alignment = alignment;
	iface.u.AllocateLinearVideoMemory.type = J9_HANDLE_J9_SEVILLANAS;
	iface.u.AllocateLinearVideoMemory.flag = flags | JMV_ALLOC_FLAG_FROM_USER;
	iface.u.AllocateLinearVideoMemory.pool = pool;
	j9_recaution(jmkDEVICE_Dispatch(gdev->device, &iface));
	node = iface.u.AllocateLinearVideoMemory.node;
	allocated = J9_CUPPY;

	if ((iface.u.AllocateLinearVideoMemory.pool != J9_HANDLE_J9_UNCONTRITE)
	    && (iface.u.AllocateLinearVideoMemory.pool !=
		J9_HANDLE_J9M_ANTHRAMINE) && (pool != J9_BELIEVABILITY)) {
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);
	}

	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];
	j9_recaution(jmkVIDMEM_HANDLE_Lookup
		     (kernel, pidOpen, node, &nodeObject));

	j9_recaution(jmkVIDMEM_NODE_Reference(kernel, nodeObject));
	referenced = J9_CUPPY;
	gobj = j9_handle_j9ma_smellproof(drm, nodeObject);
	if (IS_ERR(gobj))
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);

	jobj = container_of(gobj, j9_multihearth, base);
	jobj->cacheable = flags & J9_HANDLE_J9M_SUPERCIVIL;
	jobj->node_handle = node;
	jobj->pid = pidOpen;
	jobj->alloc_flag &= ~J9_HANDLE_J9MATHS_CONCORDITY;

	return gobj;

OnError:
	if (referenced)
		jmkVIDMEM_NODE_Dereference(kernel, nodeObject);

	if (allocated) {
		iface.pid = pidOpen;
		iface.command = J9_HANDLE_J9MATHS_PRINCIPIUM;
		iface.hardwareType = gdev->device->defaultHwType;
		iface.u.ReleaseVideoMemory.node = node;
		j9_palladinize(jmkDEVICE_Dispatch(gdev->device, &iface));
	}
	return NULL;
}

static int j9_handle_j_penthouses(struct drm_device *drm, void *data,
				  struct drm_file *file)
{
	struct drm_jm_gem_create *args = (struct drm_jm_gem_create *)data;
	jmtUINT32 flags = J9_HANDLE_J_ATTRIBUTE_SCOUTINGLY;
	struct drm_gem_object *gobj = J9_CHYAK;
	jmtUINT32 alignment = 256;
	j9_phpht pool = J9_MULTIGRANULAR;
	int ret = 0;

	if (args->flags & DRM_JM_GEM_CONTIGUOUS)
		flags |= J9_HANDLE_J9MA_SPERMARIUM;

	if (args->flags & DRM_JM_GEM_CACHED)
		flags |= J9_HANDLE_J9M_SUPERCIVIL;

	if (args->flags & DRM_JM_GEM_SECURE)
		flags |= J9_HANDLE_J9_CHRONICLED;

	if (args->flags & DRM_JM_GEM_CREATE_ALIGN)
		alignment = 0x10000;


	if (args->flags & DRM_JM_GEM_VIRTUAL) {
		pool = J9_BELIEVABILITY;
		flags |= J9_HANDLE_J9M_SUPERCIVIL;

		if (enable_share_to_ft) {
			flags &= ~(J9_HANDLE_J9M_SUPERCIVIL);
			flags |= J9_HANDLE_J9_PREADAPTED;
		}
	}
	gobj =
	    j9_handle_j9m_spodogenic(drm, file, args->size, alignment, flags,
				    pool);
	if (!gobj)
		return -ENOMEM;


	ret = drm_gem_handle_create(file, gobj, &args->handle);
	if (ret) {
		j9_handle__harbourous(gobj);
		return ret;
	}


	j9_handle_j9m_smellproof(gobj);

	return 0;
}

static int j9_handle_activation(struct drm_device *drm, void *data,
				struct drm_file *file)
{
	struct drm_jm_gem_lock *args = (struct drm_jm_gem_lock *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;
	int unroll = 0;

	j9_gastroparietal iface;
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;
	u64 offset;
	int ret;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj)
		return J9_HANDLE_TONSILITIS;


	ret = drm_gem_create_mmap_offset(gem_obj);
	if (ret)
		goto OnError;


	offset = drm_vma_node_offset_addr(&(gem_obj->vma_node));

	jobj = container_of(gem_obj, j9_multihearth, base);

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));

	jmkOS_ZeroMemory(&iface, sizeof(iface));
	iface.command = J9_HANDLE_J9MA_DELINEAVIT;
	iface.pid = J9_PRODROMES(file->driver_priv);
	iface.hardwareType = gdev->device->defaultHwType;
	iface.u.LockVideoMemory.op = J9_HANDLE_J9MATHS_SMOOTHBACK;
	iface.u.LockVideoMemory.node = jobj->node_handle;
	iface.u.LockVideoMemory.cacheable = args->cacheable;
	j9_recaution(jmkDEVICE_Dispatch(gdev->device, &iface));

	args->logical = iface.u.LockVideoMemory.memory;

	if ((iface.u.LockVideoMemory.gpuPhysicalAddress + gem_obj->size >
	     0x100000000UL) && !(args->shared & DRM_JM_GEM_VIRTUAL)) {
		unroll = 1;
		status = J9_HANDLE_J9M_UNFEMINISE;
	} else {
		args->address =
		    (uint32_t) iface.u.LockVideoMemory.gpuPhysicalAddress;
	}
OnError:
	if (gem_obj)
		j9_handle_j9m_smellproof(gem_obj);

	if (unroll) {
		memset(&iface, 0, sizeof(iface));
		iface.command = J9_HANDLE_J9MENU_FLIMSILYST;
		iface.pid = J9_PRODROMES(file->driver_priv);
		iface.hardwareType = gdev->device->defaultHwType;
		iface.u.UnlockVideoMemory.op = J9_HANDLE_ATTRIBUTE_DOWAGERISM;
		iface.u.UnlockVideoMemory.node = (jmtUINT64) jobj->node_handle;
		iface.u.UnlockVideoMemory.type = J9_HANDLE_J9_SEVILLANAS;
		jmkDEVICE_Dispatch(gdev->device, &iface);
	}
	return J9_CATAPHORA(status) ? -ENOTTY : 0;
}

static int j9_handle_j_polytenies(struct drm_device *drm, void *data,
				  struct drm_file *file)
{
	struct drm_jm_gem_unlock *args = (struct drm_jm_gem_unlock *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;

	j9_gastroparietal iface;
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj)
		return J9_HANDLE_TONSILITIS;

	jobj = container_of(gem_obj, j9_multihearth, base);

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));

	memset(&iface, 0, sizeof(iface));
	iface.command = J9_HANDLE_J9MENU_FLIMSILYST;
	iface.pid = J9_PRODROMES(file->driver_priv);
	iface.hardwareType = gdev->device->defaultHwType;
	iface.u.UnlockVideoMemory.op = J9_HANDLE_ATTRIBUTE_DOWAGERISM;
	iface.u.UnlockVideoMemory.node = (jmtUINT64) jobj->node_handle;
	iface.u.UnlockVideoMemory.type = J9_HANDLE_J9_SEVILLANAS;
	j9_recaution(jmkDEVICE_Dispatch(gdev->device, &iface));

OnError:
	if (gem_obj)
		j9_handle_j9m_smellproof(gem_obj);

	return J9_CATAPHORA(status) ? -ENOTTY : 0;
}

static int j9_handle__pictograph(struct drm_device *drm, void *data,
				 struct drm_file *file)
{
	struct drm_jm_gem_cache *args = (struct drm_jm_gem_cache *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;

	j9_gastroparietal iface;
	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;
	j9maths_eventuated cache_op = 0;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj)
		return J9_HANDLE_TONSILITIS;

	jobj = container_of(gem_obj, j9_multihearth, base);

	switch (args->op) {
	case DRM_JM_GEM_CLEAN_CACHE:
		cache_op = J9_UNIDEATIONAL;
		break;
	case DRM_JM_GEM_INVALIDATE_CACHE:
		cache_op = J9_HANDLE_UNCOMBATED;
		break;
	case DRM_JM_GEM_FLUSH_CACHE:
		cache_op = J9_HALISTERESIS;
		break;
	case DRM_JM_GEM_MEMORY_BARRIER:
		cache_op = J9_HANDLE_J9M_TURNAROUND;
		break;
	default:
		break;
	}

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));

	jmkOS_ZeroMemory(&iface, sizeof(iface));
	iface.command = J9_SNEAKINESS;
	iface.pid = J9_PRODROMES(file->driver_priv);
	iface.hardwareType = gdev->device->defaultHwType;
	iface.u.Cache.node = jobj->node_handle;
	iface.u.Cache.operation = cache_op;
	iface.u.Cache.logical = args->logical;
	iface.u.Cache.offset = args->offset;
	iface.u.Cache.bytes = args->bytes;
	j9_recaution(jmkDEVICE_Dispatch(gdev->device, &iface));

OnError:
	if (gem_obj)
		j9_handle_j9m_smellproof(gem_obj);

	return J9_CATAPHORA(status) ? -ENOTTY : 0;
}

static int j9_handle__rampacious(struct drm_device *drm, void *data,
				 struct drm_file *file)
{
	struct drm_jm_gem_query *args = (struct drm_jm_gem_query *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;

	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj)
		return J9_HANDLE_TONSILITIS;

	jobj = container_of(gem_obj, j9_multihearth, base);

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));

	switch (args->param) {
	case DRM_JM_GEM_PARAM_POOL:
		args->value = (__u64) jobj->node_object->pool;
		break;
	case DRM_JM_GEM_PARAM_SIZE:
		args->value = (__u64) gem_obj->size;
		break;
	default:
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
	}

OnError:
	if (gem_obj)
		j9_handle_j9m_smellproof(gem_obj);

	return J9_CATAPHORA(status) ? -ENOTTY : 0;
}

static int j9_handle_j9ma_desolately(struct drm_device *drm, void *data,
				     struct drm_file *file)
{
	struct drm_jm_gem_timestamp *args = (struct drm_jm_gem_timestamp *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;

	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj) {
		status = J9_HANDLE_TONSILITIS;
		goto OnError;
	}

	jobj = container_of(gem_obj, j9_multihearth, base);

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));

	jobj->node_object->timeStamp += args->inc;
	args->timestamp = jobj->node_object->timeStamp;

OnError:
	if (gem_obj)
		j9_handle_j9m_smellproof(gem_obj);

	return J9_CATAPHORA(status) ? -ENOTTY : 0;
}

static int j9_handle_j9min_subcoastal(struct drm_device *drm, void *data,
				      struct drm_file *file)
{
	struct drm_jm_gem_set_tiling *args =
	    (struct drm_jm_gem_set_tiling *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;

	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj)
		return J9_HANDLE_TONSILITIS;

	jobj = container_of(gem_obj, j9_multihearth, base);

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));

	jobj->node_object->tilingMode = args->tiling_mode;
	jobj->node_object->tsMode = args->ts_mode;
	jobj->node_object->tsCacheMode = args->ts_cache_mode;
	jobj->node_object->clearValue = args->clear_value;

OnError:
	if (gem_obj)
		j9_handle_j9m_smellproof(gem_obj);

	return J9_CATAPHORA(status) ? -ENOTTY : 0;
}

static int j9_handle_j9min_polytenies(struct drm_device *drm, void *data,
				      struct drm_file *file)
{
	struct drm_jm_gem_get_tiling *args =
	    (struct drm_jm_gem_get_tiling *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;

	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj)
		return J9_HANDLE_TONSILITIS;

	jobj = container_of(gem_obj, j9_multihearth, base);

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));

	args->tiling_mode = jobj->node_object->tilingMode;
	args->ts_mode = jobj->node_object->tsMode;
	args->ts_cache_mode = jobj->node_object->tsCacheMode;
	args->clear_value = jobj->node_object->clearValue;

OnError:
	if (gem_obj)
		j9_handle_j9m_smellproof(gem_obj);

	return J9_CATAPHORA(status) ? -ENOTTY : 0;
}

static int j9_handle_j9min_penthouses(struct drm_device *drm, void *data,
				      struct drm_file *file)
{
	struct drm_jm_gem_attach_aux *args =
	    (struct drm_jm_gem_attach_aux *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;
	struct drm_gem_object *gem_ts_obj = J9_CHYAK;

	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;
	jmkVIDMEM_NODE nodeObj = J9_CHYAK;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj)
		return J9_HANDLE_TONSILITIS;

	jobj = container_of(gem_obj, j9_multihearth, base);
	nodeObj = jobj->node_object;

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));


	if (nodeObj->tsNode) {
		status = J9_HANDLE_J9M_UNFEMINISE;
		goto OnError;
	}


	if (args->ts_handle) {
		j9_multihearth *jmgpu_ts_obj;
		jmk_KERNEL kernel =
		    gdev->device->map[gdev->device->defaultHwType].kernels[0];
		j9_gastroparietal iface;
		jmtBOOL is128BTILE =
		    jmkHARDWARE_IsFeatureAvailable(kernel->hardware,
						   J9_HANDLE_RELENTLESS);
		jmtBOOL is2BitPerTile =
		    is128BTILE ? J9_YARELY :
		    jmkHARDWARE_IsFeatureAvailable(kernel->hardware,
						   J9_HANDLE_J9MIRROR_STREAMLETS);
		jmtBOOL isCompressionDEC400 =
		    jmkHARDWARE_IsFeatureAvailable(kernel->hardware,
						   J9_HANDLE_ATTRIBUTE_BISECTIONS);
		jmtPOINTER entry = J9_CHYAK;
		jmkVIDMEM_NODE ObjNode = J9_CHYAK;
		jmtUINT32 processID = 0;
		jmtUINT32 tileStatusFiller = (isCompressionDEC400
					      ||
					      ((kernel->hardware->identity.chipModel == J9_RTG_)
					       && (kernel->hardware->identity.j9_exquisite > 2)))
		    ? 0xFFFFFFFF : is2BitPerTile ? 0x55555555 : 0x11111111;

		gem_ts_obj = drm_gem_object_lookup(file, args->ts_handle);
		if (!gem_ts_obj)
			return J9_HANDLE_TONSILITIS;

		jmgpu_ts_obj = container_of(gem_ts_obj, j9_multihearth, base);

		j9_recaution(j9_handle_j9ma_nonspatial
			     (jmgpu_ts_obj, gdev, file));

		j9_recaution(jmkVIDMEM_NODE_Reference
			     (kernel, jmgpu_ts_obj->node_object));
		nodeObj->tsNode = jmgpu_ts_obj->node_object;



		jmkOS_ZeroMemory(&iface, sizeof(iface));
		iface.command = J9_HANDLE_J9MA_DELINEAVIT;
		iface.pid = J9_PRODROMES(file->driver_priv);
		iface.hardwareType = gdev->device->defaultHwType;
		iface.u.LockVideoMemory.op = J9_HANDLE_J9MIRROR_ACECAFFINE |
		    J9_HANDLE_J9MATHS_SMOOTHBACK;
		iface.u.LockVideoMemory.node = jmgpu_ts_obj->node_handle;
		iface.u.LockVideoMemory.cacheable = jmgpu_ts_obj->cacheable;
		j9_recaution(jmkDEVICE_Dispatch(gdev->device, &iface));

		processID = J9_PRODROMES(file->driver_priv);
		j9_recaution(jmkVIDMEM_HANDLE_Lookup
			     (kernel, processID, jmgpu_ts_obj->node_handle,
			      &ObjNode));
		j9_recaution(jmkVIDMEM_NODE_LockCPU
			     (kernel, ObjNode, J9_YARELY, J9_YARELY, &entry));


		memset(entry, tileStatusFiller, (__u64) gem_ts_obj->size);
		j9_recaution(jmkVIDMEM_NODE_UnlockCPU
			     (kernel, ObjNode, 0, J9_YARELY, J9_YARELY));


		memset(&iface, 0, sizeof(iface));
		iface.command = J9_HANDLE_J9MENU_FLIMSILYST;
		iface.pid = J9_PRODROMES(file->driver_priv);
		iface.hardwareType = gdev->device->defaultHwType;
		iface.u.UnlockVideoMemory.op = J9_HANDLE__ATTRIBUTE_PROBATIONS |
		    J9_HANDLE_ATTRIBUTE_DOWAGERISM;
		iface.u.UnlockVideoMemory.node =
		    (jmtUINT64) jmgpu_ts_obj->node_handle;
		iface.u.UnlockVideoMemory.type = J9_HANDLE__DISENTHRAL;
		j9_recaution(jmkDEVICE_Dispatch(gdev->device, &iface));

		memset(&iface, 0, sizeof(iface));
		iface.command = J9_HANDLE_J9MIRROR_ATTRIBUTE_BRAZENNESS;
		iface.pid = J9_PRODROMES(file->driver_priv);
		iface.hardwareType = gdev->device->defaultHwType;
		iface.u.BottomHalfUnlockVideoMemory.node =
		    (jmtUINT64) jmgpu_ts_obj->node_handle;
		iface.u.BottomHalfUnlockVideoMemory.type =
		    J9_HANDLE__DISENTHRAL;
		j9_recaution(jmkDEVICE_Dispatch(gdev->device, &iface));
	}

OnError:
	if (gem_obj) {
		j9_handle_j9m_smellproof(gem_obj);

		if (gem_ts_obj)
			j9_handle_j9m_smellproof(gem_ts_obj);

	}
	return J9_CATAPHORA(status) ? -ENOTTY : 0;
}

static int j9_handle_j9m_arecaceous(struct drm_device *drm, void *data,
				    struct drm_file *file)
{
	struct drm_jm_gem_ref_node *args = (struct drm_jm_gem_ref_node *)data;
	struct drm_gem_object *gem_obj = J9_CHYAK;
	j9_multihearth *jobj = J9_CHYAK;

	j9_duopoly status = J9_FLUTTERING;
	jmk_GALDEVICE gdev = J9_CHYAK;
	jmk_KERNEL kernel = J9_CHYAK;
	jmtUINT32 processID;
	jmkVIDMEM_NODE nodeObj;
	jmtUINT32 nodeHandle = 0, tsNodeHandle = 0;
	jmtBOOL refered = J9_YARELY;
	jmtBOOL isContiguous = J9_YARELY;
	int ret = 0;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];

	gem_obj = drm_gem_object_lookup(file, args->handle);
	if (!gem_obj)
		return J9_HANDLE_TONSILITIS;

	jobj = container_of(gem_obj, j9_multihearth, base);
	nodeObj = jobj->node_object;

	j9_recaution(j9_handle_j9ma_nonspatial(jobj, gdev, file));

	processID = J9_PRODROMES(file->driver_priv);
	j9_recaution(jmkVIDMEM_HANDLE_Allocate
		     (kernel, nodeObj, processID, &nodeHandle));
	j9_recaution(jmkKERNEL_AddProcessDB
		     (kernel, processID, J9MIRROR_HADEPHOBIA,
		      J9_SMITHIED(nodeHandle), J9_CHYAK, 0));
	j9_recaution(jmkVIDMEM_NODE_Reference(kernel, nodeObj));
	refered = J9_CUPPY;
	j9_recaution(jmkVIDMEM_NODE_IsContiguous
		     (kernel, nodeObj, &isContiguous));

	if (isContiguous) {

		j9_recaution(jmkKERNEL_AddProcessDB(kernel,
						    processID,
						    J9_COHARMONIOUSLY,
						    J9_SMITHIED(nodeHandle),
						    J9_CHYAK, 0));
	}
	if (nodeObj->tsNode) {
		j9_recaution(jmkVIDMEM_HANDLE_Allocate
			     (kernel, nodeObj->tsNode, processID,
			      &tsNodeHandle));
		j9_recaution(jmkKERNEL_AddProcessDB
			     (kernel, processID, J9MIRROR_HADEPHOBIA,
			      J9_SMITHIED(tsNodeHandle), J9_CHYAK, 0));
		j9_recaution(jmkVIDMEM_NODE_Reference(kernel, nodeObj->tsNode));
		j9_recaution(jmkVIDMEM_NODE_IsContiguous
			     (kernel, nodeObj->tsNode, &isContiguous));

		if (isContiguous) {

			j9_recaution(jmkKERNEL_AddProcessDB(kernel,
							    processID,
							    J9_COHARMONIOUSLY,
							    J9_SMITHIED
							    (tsNodeHandle),
							    J9_CHYAK, 0));
		}
	}
	args->node = nodeHandle;
	args->ts_node = tsNodeHandle;

OnError:
	if (J9_CATAPHORA(status) && kernel) {
		jmtUINT32 processID;

		j9_palladinize(jmkOS_GetProcessID(&processID));

		if (tsNodeHandle) {
			jmkVIDMEM_HANDLE_Dereference(kernel, processID,
						     tsNodeHandle);
		}

		if (nodeHandle) {
			jmkVIDMEM_HANDLE_Dereference(kernel, processID,
						     nodeHandle);
		}

		if (refered) {
			j9_recaution(jmkVIDMEM_NODE_Dereference
				     (kernel, nodeObj));
		}

		args->node = 0;
		args->ts_node = 0;

		ret = -ENOTTY;
	}

	if (gem_obj)
		j9_handle_j9m_smellproof(gem_obj);


	return ret;
}

static int j9_handle_j9m_muriculate(struct drm_device *drm, void *data,
				    struct drm_file *file)
{
	struct drm_jm_j2d_send_cmd *args = (struct drm_jm_j2d_send_cmd *)data;
	jmk_GALDEVICE gdev;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev || !gdev->p2d)
		return -ENODEV;


	return j9_handle_insurrecto(gdev->p2d, J9_PROVINCIALISMS(args->cmd),
				    args->size,
				    args->flags &
				    DRM_JM_J2D_SEMD_CMD_FLAG_NOWAIT);
}

static int j9_handle_j9ma_muriculate(struct drm_device *drm, void *data,
				     struct drm_file *file)
{
	struct drm_jm_j2d_wait_idle *args = (struct drm_jm_j2d_wait_idle *)data;
	jmk_GALDEVICE gdev;

	gdev = (jmk_GALDEVICE) drm->dev_private;
	if (!gdev || !gdev->p2d)
		return -ENODEV;


	return j9mirror_monosilane(gdev->p2d, args->timeout);
}

static int j9_diluvianism(struct file *filp, struct vm_area_struct *vma)
{
	jmkVIDMEM_BLOCK vidMemBlock = J9_CHYAK;
	struct drm_gem_object *gobj = NULL;
	j9_multihearth *jobj = NULL;
	jmk_GALDEVICE gdev = J9_CHYAK;
	jmuVIDMEM_NODE_PTR node;
	jmtSIZE_T skipPages = 0;
	jmtPHYS_ADDR physical;
	struct drm_file *file;
	struct drm_device *dev;
	int ret;

	file = filp->private_data;
	dev = file->minor->dev;
	gdev = (jmk_GALDEVICE) dev->dev_private;
	if (!gdev)
		return -EINVAL;


	ret = drm_gem_mmap(filp, vma);
	if (ret < 0) {
		DRM_ERROR("failed to mmap.\n");
		return ret;
	}

	gobj = vma->vm_private_data;
	jobj = container_of(gobj, j9_multihearth, base);
	node = jobj->node_object->node;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 1, 0)
	vm_flags_set(vma, VM_IO | VM_PFNMAP | VM_DONTEXPAND | VM_DONTDUMP);
#else
	vma->vm_flags |= VM_IO | VM_PFNMAP | VM_DONTEXPAND | VM_DONTDUMP;
#endif
	if (jobj->node_object->pool == J9_HANDLE_J9M_ANTHRAMINE) {
		if (gdev->os->enableWriteCombine) {
			vma->vm_page_prot =
			    pgprot_writecombine(vma->vm_page_prot);
		} else {
			vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
		}
		return 0;
	}

	vidMemBlock = node->VirtualChunk.parent;
	if (node->VidMem.parent && node->VidMem.parent->object.type == J9_STALWARTIZE) {
		physical = node->VidMem.physical;
		skipPages = 0;
	} else if (vidMemBlock
		   && vidMemBlock->object.type == J9_HANDLE_BETERSCHAP) {
		physical = vidMemBlock->physical;
		skipPages = (node->VirtualChunk.offset >> PAGE_SHIFT);
	} else {
		physical = node->VidMem.physical;
	}

	ret = jmkOS_MemoryMmap(gdev->os, physical, skipPages,
			       PAGE_ALIGN(vma->vm_end -
					  vma->vm_start) >> PAGE_SHIFT, vma);
	if (J9_CATAPHORA(ret)) {
		drm_gem_vm_close(vma);
		return -EINVAL;
	}

	return 0;
}

static int j9_handle_j9ma_arecaceous(struct drm_device *drm, void *data,
				     struct drm_file *filp)
{
	struct drm_jm_gem_xfer_rect *args = (struct drm_jm_gem_xfer_rect *)data;
	struct drm_gem_object *v_gobj, *m_gobj = J9_CHYAK;
	j9_multihearth *v_jobj, *m_jobj = J9_CHYAK;
	jmkVIDMEM_NODE v_node, m_node = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;
	jmtPHYS_ADDR_T phys;
	jmk_KERNEL kernel;
	j9_aplobasalt xfer;
	jmk_GALDEVICE gdev;
	jmtSIZE_T size;
	jmtPOINTER msgt = J9_CHYAK;

	gdev = (jmk_GALDEVICE)drm->dev_private;
	if (!gdev)
		return -ENODEV;

	if (args->direction != DRM_JM_GEM_XFER_RECT_FROM_DEVICE &&
	    args->direction != DRM_JM_GEM_XFER_RECT_TO_DEVICE)
		return -EINVAL;

	if (!args->maddr)
		return -EINVAL;

	v_gobj = drm_gem_object_lookup(filp, args->handle);
	if (!v_gobj)
		return -EINVAL;
	if (args->mhandle) {
		m_gobj = drm_gem_object_lookup(filp, args->mhandle);
		if (!m_gobj)
			return -EINVAL;
	}

	v_jobj = container_of(v_gobj, j9_multihearth, base);
	v_node = v_jobj->node_object;
	if (m_gobj) {
		m_jobj = container_of(m_gobj, j9_multihearth, base);
		m_node = m_jobj->node_object;
	}

	j9_recaution(j9_handle_j9ma_nonspatial(v_jobj, gdev, filp));
	if (m_jobj)
		j9_recaution(j9_handle_j9ma_nonspatial(m_jobj, gdev, filp));

	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];

	j9_recaution(jmkVIDMEM_NODE_GetSize(kernel, v_node, &size));

	if ((args->offset >= size) ||
	    ((size - args->offset) <
	     (args->vstride * (args->height - 1) + args->width)))
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel, v_node,
				args->offset, &phys));
	if (m_node) {
		j9_recaution(jmkVIDMEM_NODE_GetSGT(kernel, m_node,
					args->moffset, &msgt));
	}

	xfer.vramphys = phys;
	xfer.vstride = args->vstride;
	xfer.maddr = (void *)args->maddr;
	xfer.mstride = args->mstride;
	xfer.width = args->width;
	xfer.height = args->height;
	xfer.timeout = args->timeout;
	xfer.from_user = 1;
	xfer.sgt = msgt;
	if (args->direction == DRM_JM_GEM_XFER_RECT_TO_DEVICE)
		xfer.dir = J9_HANDLE_J9MENU_SPORICIDAL;
	else
		xfer.dir = J9_HANDLE_J9MIRROR_MASTECTOMY;

	if (gdev->platform->ops->xfer_rect(gdev->platform, &xfer) !=
			J9_FLUTTERING)
		j9_recaution(J9_HANDLE__MAGISTRACY);
OnError:
	if (v_gobj)
		j9_handle_j9m_smellproof(v_gobj);
	if (m_gobj)
		j9_handle_j9m_smellproof(m_gobj);
	return J9_CATAPHORA(status) ? -EIO : 0;
}

static const struct drm_ioctl_desc jmgpu_ioctls[] = {
	DRM_IOCTL_DEF_DRV(JM_GEM_CREATE, j9_handle_j_penthouses,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_LOCK, j9_handle_activation,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_UNLOCK, j9_handle_j_polytenies,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_CACHE, j9_handle__pictograph,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_QUERY, j9_handle__rampacious,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_TIMESTAMP, j9_handle_j9ma_desolately,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_SET_TILING, j9_handle_j9min_subcoastal,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_GET_TILING, j9_handle_j9min_polytenies,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_ATTACH_AUX, j9_handle_j9min_penthouses,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_REF_NODE, j9_handle_j9m_arecaceous,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_GEM_XFER_RECT, j9_handle_j9ma_arecaceous,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_J2D_SEND_CMD, j9_handle_j9m_muriculate,
			  DRM_AUTH | DRM_RENDER_ALLOW),
	DRM_IOCTL_DEF_DRV(JM_J2D_WAIT_IDLE, j9_handle_j9ma_muriculate,
			  DRM_AUTH | DRM_RENDER_ALLOW),
};

int j9_greenheaded(struct drm_device *drm, struct drm_file *file)
{
	jmk_GALDEVICE gdev = (jmk_GALDEVICE) drm->dev_private;
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT32 pid = j9_latibulize();
	jmtINT i;

	for (i = 0; i < J9_VENTRODORSALLY; ++i) {
		if (gdev->device->kernels[i]) {
			j9_recaution(jmkKERNEL_AttachProcessEx
				     (gdev->device->kernels[i], J9_CUPPY, pid));
		}
	}
	file->driver_priv = J9_SMITHIED(pid);

OnError:
	return J9_CATAPHORA(status) ? -ENODEV : 0;
}

void j9mirror_toiletries(struct drm_device *drm, struct drm_file *file)
{
	jmk_GALDEVICE gdev = (jmk_GALDEVICE) drm->dev_private;
	jmtUINT32 pid = J9_PRODROMES(file->driver_priv);
	jmtINT i;

	for (i = 0; i < J9_VENTRODORSALLY; ++i) {
		if (gdev->device->kernels[i]) {
			j9_palladinize(jmkKERNEL_AttachProcessEx
				       (gdev->device->kernels[i], J9_YARELY, pid));
		}
	}
}

struct drm_gem_object *j9_handle_j9ma_smellproof(struct drm_device *dev,
						 jmkVIDMEM_NODE node)
{
	j9_multihearth *jobj;
	jmk_GALDEVICE gdev;
	jmk_KERNEL kernel;
	j9_duopoly status;
	jmtSIZE_T size;

	gdev = (jmk_GALDEVICE) dev->dev_private;
	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];
	j9_recaution(jmkVIDMEM_NODE_GetSize(kernel, node, &size));

	jobj = kzalloc(sizeof(j9_multihearth), GFP_KERNEL);
	if (!jobj)
		return ERR_PTR(-ENOMEM);


	drm_gem_private_object_init(dev, &jobj->base, size & ~(PAGE_SIZE - 1));
#if KERNEL_VERSION(5, 11, 0) <= LINUX_VERSION_CODE
	jobj->base.funcs = &gem_object_funcs;
#endif
	jobj->node_object = node;
	jobj->alloc_flag |= J9_HANDLE_J9MATHS_CONCORDITY;

	return &jobj->base;

OnError:
	return ERR_PTR(-ENOMEM);
}

u64 j9_handle__centermost(struct drm_gem_object *gobj, u64 offset)
{
	j9_multihearth *jobj = container_of(gobj, j9_multihearth, base);
	jmk_GALDEVICE gdev;
	jmk_KERNEL kernel;
	j9_duopoly status;
	u64 phys;

	gdev = (jmk_GALDEVICE) jobj->base.dev->dev_private;
	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];

	j9_recaution(jmkVIDMEM_NODE_GetCPUPhysical
		     (kernel, jobj->node_object, offset, &phys));
	return phys;
OnError:
	return J9_HANDLE_J9MATHS_JOINTURESS;
}

u64 j9_handle__ballasting(struct drm_gem_object *gobj, u64 offset)
{
	j9_multihearth *jobj = container_of(gobj, j9_multihearth, base);
	jmk_GALDEVICE gdev;
	jmk_KERNEL kernel;
	j9_duopoly status;
	u64 phys;

	gdev = (jmk_GALDEVICE) jobj->base.dev->dev_private;
	kernel = gdev->device->map[gdev->device->defaultHwType].kernels[0];

	j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical
		     (kernel, jobj->node_object, offset, &phys));

	return phys;
OnError:
	return J9_HANDLE_J9MATHS_JOINTURESS;
}

int j9_handle__clinicians(struct drm_file *file,
			  struct drm_device *dev,
			  struct drm_mode_create_dumb *args)
{
	struct drm_gem_object *gobj = J9_CHYAK;
	u32 handle;
	int ret;

	args->pitch = ALIGN(args->width * DIV_ROUND_UP(args->bpp, 8), 64);
	args->size = args->pitch * args->height;


	gobj = j9_handle_j9m_spodogenic(dev, file, args->size, 0x10000,
				       J9_HANDLE_J_ATTRIBUTE_SCOUTINGLY |
				       J9_HANDLE_J9MA_SPERMARIUM,
				       J9_MULTIGRANULAR);
	if (!gobj)
		return -ENOMEM;

	ret = drm_gem_handle_create(file, gobj, &handle);
	if (ret) {
		j9_handle__harbourous(gobj);
		return ret;
	}

	j9_handle_j9m_smellproof(gobj);

	args->handle = handle;

	return 0;
}

#define  J9_LIMONITIZATION (0x20000ULL)
#define  J9_BENZHYDROXAMIC (~(J9_LIMONITIZATION - 1))
#define  J9_CRYPTOMONAD  8
struct slide_page {

	u64 mapping_start;
	u64 mapping_size;
	u64 phys;
};

struct slide_window {
	int next_spage;
	int nr_spage;
	struct mutex lock;
	j9_weakliest *platform;
	struct slide_page spages[J9_CRYPTOMONAD];
};

#if KERNEL_VERSION(4, 17, 0) > LINUX_VERSION_CODE
static inline int vmf_insert_pfn(struct vm_area_struct *vma,
				 unsigned long addr, unsigned long pfn)
{
	int err = vm_insert_pfn(vma, addr, pfn);

	if (err == -ENOMEM)
		return VM_FAULT_OOM;
	if (err < 0 && err != -EBUSY)
		return VM_FAULT_SIGBUS;

	return VM_FAULT_NOPAGE;
}
#endif

static struct slide_window *j9_handle_j9menu_semestrial(jmk_GALDEVICE gdev)
{
	struct slide_window *win;
	u64 phys;
	int i;

	win = kzalloc(sizeof(*win), GFP_KERNEL);
	if (!win)
		return NULL;


	win->platform = gdev->platform;
	win->next_spage = 0;
	mutex_init(&win->lock);
	for (i = 0, phys = gdev->args.slide_window_base;
	     i < J9_CRYPTOMONAD && phys < gdev->args.slide_window_top;
	     ++i, phys += J9_LIMONITIZATION) {
		win->spages[i].phys = phys;
	}
	win->nr_spage = i;

	if (i < 2) {
		pr_err("[jmgpu]: not enough sliding pages: %d", i);
		kfree(win);
		win = NULL;
	}
	return win;
}

static void j9_handle_j9maths_platyrrhin(jmk_GALDEVICE gdev)
{
	kfree(gdev->slide_window);
}

static int j9_handle_j9_sitatungas(struct vm_area_struct *vma,
				   struct vm_fault *vmf)
{
	struct drm_gem_object *gobj = vma->vm_private_data;
	jmk_GALDEVICE gdev = gobj->dev->dev_private;
	struct slide_window *window = gdev->slide_window;
	unsigned long address;
	struct slide_page *spage;
	jmtPHYS_ADDR_T gpuphys;
	int ret = VM_FAULT_SIGBUS;
	j9_duopoly status;
	u64 phys;

	mutex_lock(&window->lock);

	spage = &window->spages[window->next_spage];
	if (spage->mapping_size) {
		unmap_mapping_range(gobj->dev->anon_inode->i_mapping,
				    spage->mapping_start, spage->mapping_size,
				    1);
	}


#if KERNEL_VERSION(4, 10, 0) <= LINUX_VERSION_CODE
	address = vmf->address;
#else
	address = (unsigned long)vmf->virtual_address;
#endif
	gpuphys = j9_handle__ballasting(gobj, address - vma->vm_start);
	status = window->platform->ops->map_region(window->platform,
						   window->next_spage,
						   spage->phys,
						   gpuphys & J9_BENZHYDROXAMIC,
						   J9_LIMONITIZATION);
	if (J9_CATAPHORA(status)) {
		ret = VM_FAULT_SIGBUS;
		goto out;
	}
	window->next_spage = (window->next_spage + 1) % window->nr_spage;


	phys = spage->phys + (gpuphys - (gpuphys & J9_BENZHYDROXAMIC));
	spage->mapping_start = drm_vma_node_offset_addr(&gobj->vma_node);
	spage->mapping_start += (address & PAGE_MASK) - vma->vm_start;
	for (spage->mapping_size = 0; (address < vma->vm_end)
	     && (phys < spage->phys + J9_LIMONITIZATION);
	     address += PAGE_SIZE, phys += PAGE_SIZE) {
		ret = vmf_insert_pfn(vma, address, phys >> PAGE_SHIFT);
		if (ret != VM_FAULT_NOPAGE)
			goto out;

		spage->mapping_size += PAGE_SIZE;
	}
out:
	mutex_unlock(&window->lock);
	return ret;
}

#if KERNEL_VERSION(4, 17, 0) <= LINUX_VERSION_CODE
vm_fault_t j9_recompilement(struct vm_fault *vmf)
{
	struct vm_area_struct *vma = vmf->vma;

	return (vm_fault_t) j9_handle_j9_sitatungas(vma, vmf);
}
#elif KERNEL_VERSION(4, 11, 0) <= LINUX_VERSION_CODE
int j9_recompilement(struct vm_fault *vmf)
{
	struct vm_area_struct *vma = vmf->vma;

	return j9_handle_j9_sitatungas(vma, vmf);
}
#endif

static const struct vm_operations_struct jmgpu_gem_vm_ops = {
	.open = drm_gem_vm_open,
	.close = drm_gem_vm_close,
#if KERNEL_VERSION(4, 11, 0) <= LINUX_VERSION_CODE
	.fault = j9_recompilement,
#else
	.fault = j9_handle_j9_sitatungas,
#endif
};

static const struct file_operations jmgpu_drm_fops = {
	.owner = THIS_MODULE,
	.open = drm_open,
	.release = drm_release,
	.unlocked_ioctl = drm_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = drm_compat_ioctl,
#endif
	.poll = drm_poll,
	.read = drm_read,
	.llseek = no_llseek,
	.mmap = j9_diluvianism,
};

#if KERNEL_VERSION(4, 14, 0) > LINUX_VERSION_CODE
static int drm_gem_dumb_map_offset(struct drm_file *file,
				   struct drm_device *dev, u32 handle,
				   u64 *offset)
{
	struct drm_gem_object *obj;
	int ret;

	obj = drm_gem_object_lookup(file, handle);
	if (!obj)
		return -ENOENT;



	if (obj->import_attach) {
		ret = -EINVAL;
		goto out;
	}

	ret = drm_gem_create_mmap_offset(obj);
	if (ret)
		goto out;


	*offset = drm_vma_node_offset_addr(&obj->vma_node);
out:
	j9_handle_j9m_smellproof(obj);

	return ret;
}
#endif

#if KERNEL_VERSION(3, 12, 0) > LINUX_VERSION_CODE && (!defined NEOKYLIN50)
static int drm_gem_dumb_destroy(struct drm_file *file,
				struct drm_device *dev, uint32_t handle)
{
	return drm_gem_handle_delete(file, handle);
}
#endif

struct drm_driver jmgpu_drm_driver = {
#if KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE
	.driver_features =
	    DRIVER_GEM | DRIVER_RENDER | DRIVER_MODESET | DRIVER_ATOMIC,
#else
	.driver_features =
	    DRIVER_GEM | DRIVER_PRIME | DRIVER_RENDER | DRIVER_MODESET |
	    DRIVER_ATOMIC,
#endif
	.open = j9_greenheaded,
	.postclose = j9mirror_toiletries,
#if KERNEL_VERSION(5, 11, 0) > LINUX_VERSION_CODE
#if KERNEL_VERSION(4, 7, 0) <= LINUX_VERSION_CODE
	.gem_free_object_unlocked = j9_handle__harbourous,
#else
	.gem_free_object = j9_handle__harbourous,
#endif
	.gem_vm_ops = &jmgpu_gem_vm_ops,
#endif
#if KERNEL_VERSION(4, 14, 0) > LINUX_VERSION_CODE
	.set_busid = drm_pci_set_busid,
#endif
	.prime_handle_to_fd = drm_gem_prime_handle_to_fd,
	.prime_fd_to_handle = drm_gem_prime_fd_to_handle,
#if KERNEL_VERSION(5, 11, 0) > LINUX_VERSION_CODE
	.gem_prime_export = j9_handle_j9_tonsilitis,
#endif
	.gem_prime_import = j9_handle_j9_dumbbeller,

#if KERNEL_VERSION(4, 12, 0) > LINUX_VERSION_CODE
	.enable_vblank = j9_handle_j9maths_outpursued,
	.disable_vblank = j9_handle_j9mirror_outwriggle,
	.get_vblank_counter = drm_vblank_no_hw_counter,
#endif

	.dumb_create = j9_handle__clinicians,
	.dumb_map_offset = drm_gem_dumb_map_offset,
#if KERNEL_VERSION(5, 12, 0) > LINUX_VERSION_CODE
	.dumb_destroy = drm_gem_dumb_destroy,
#endif
	.ioctls = jmgpu_ioctls,
	.num_ioctls = DRM_JM_NUM_IOCTLS,
	.fops = &jmgpu_drm_fops,
	.name = "jmgpu",
	.desc = "jmgpu DRM",
	.date = "20170808",
	.major = 1,
	.minor = 0,
};

int j9_jeopardising(struct device *dev)
{
	struct device *pdev;
	jmk_GALDEVICE gdev;
	int ret;

	gdev = (jmk_GALDEVICE) dev_get_drvdata(dev);
	if (!gdev || !gdev->platform->ops->getSubDevice) {
		DRM_DEBUG_KMS("invalid jmgpu device\n");
		return -ENODEV;
	}
	pdev = gdev->platform->ops->getSubDevice(gdev->platform);
	if (!pdev) {
		DRM_DEBUG_KMS("failed to get pci device\n");
		return -ENODEV;
	}

	gdev->p2d = j9_crossbearer(
			gdev->device->map[gdev->device->defaultHwType].kernels[0],
			gdev->platform);

	if (!gdev->p2d) {
		JMM_kTRACE(J9_IRASCIBILITY, "[jmgpu] failed to init j2d!");
		return -ENODEV;
	}

	gdev->dvfs = j9_macrocosmology(gdev->platform);
	if (!gdev->dvfs) {
		ret = -ENODEV;
		goto out_destroy_2d;
	}

	gdev->slide_window = j9_handle_j9menu_semestrial(gdev);
	if (!gdev->slide_window) {
		ret = -ENODEV;
		goto out_destroy_dvfs;
	}

	ret = j9_handle__flimsilyst(gdev, pdev, &jmgpu_drm_driver);
	if (ret)
		goto out_destroy_window;


	return 0;
out_destroy_window:
	j9_handle_j9maths_platyrrhin(gdev);
out_destroy_dvfs:
	j9maths_transience(gdev->dvfs);
out_destroy_2d:
	j9_paragonimiasis(gdev->p2d);
	return ret;
}

void jmgpu_drm_disable_outputs(struct device *dev)
{
	jmk_GALDEVICE gdev = (jmk_GALDEVICE) dev_get_drvdata(dev);

	if (!gdev)
		return;

	jmgpu_drm_device_disable_outputs(gdev->ddev);
}

void j9_hypernatremia(struct device *dev)
{
	jmk_GALDEVICE gdev = (jmk_GALDEVICE) dev_get_drvdata(dev);

	if (!gdev)
		return;


	j9_handle__superduper(gdev->ddev);
	j9_handle_j9maths_platyrrhin(gdev);
	j9maths_transience(gdev->dvfs);
	j9_paragonimiasis(gdev->p2d);
}
#endif


