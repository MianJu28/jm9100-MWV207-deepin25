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


#ifndef __c418e6d3_H_
#define __c418e6d3_H_

#ifdef __KERNEL__
#include <uapi/drm/drm.h>
#else
#include <drm.h>
#endif

#if defined(__cplusplus)
extern "C" {
#endif


#define DRM_JM_GEM_UNKNOWN         (0)
#define DRM_JM_GEM_CONTIGUOUS      (1u << 0)
#define DRM_JM_GEM_CACHED          (1u << 1)
#define DRM_JM_GEM_SECURE          (1u << 2)
#define DRM_JM_GEM_CMA_LIMIT       (1u << 3)
#define DRM_JM_GEM_CREATE_ALIGN    (1u << 4)
#define DRM_JM_GEM_VIRTUAL         (1u << 5)

struct drm_jm_gem_create {
    __u64 size;
    __u32 flags;
    __u32 handle;
};

struct drm_jm_gem_lock {
    __u32 handle;
    __u32 cacheable;
    __u64 logical;
    __u32 address;
    __u32 shared;
};

struct drm_jm_gem_unlock {
    __u32 handle;
};

#define DRM_JM_GEM_CLEAN_CACHE         0x01
#define DRM_JM_GEM_INVALIDATE_CACHE    0x02
#define DRM_JM_GEM_FLUSH_CACHE         0x03
#define DRM_JM_GEM_MEMORY_BARRIER      0x04

struct drm_jm_gem_cache {
    __u32 handle;
    __u32 op;
    __u64 logical;
    __u64 offset;
    __u64 bytes;
};

#define DRM_JM_GEM_XFER_RECT_FROM_DEVICE 0
#define DRM_JM_GEM_XFER_RECT_TO_DEVICE   1
struct drm_jm_gem_xfer_rect {
	__u32 handle;
	__u32 offset;
	__u32 vstride;
	__u32 mstride;
	__u32 width;
	__u32 height;
	__u64 maddr;
	__u32 direction;
	__s32 timeout;

	__u32 mhandle;
	__u32 moffset;
};


#define DRM_JM_GEM_PARAM_POOL      0x00
#define DRM_JM_GEM_PARAM_SIZE      0x01

struct drm_jm_gem_query {
    __u32 handle;
    __u32 param;
    __u64 value;
};


struct drm_jm_gem_timestamp {
    __u32 handle;

    __u32 inc;

    __u64 timestamp;
};


#define DRM_JM_GEM_TILING_LINEAR     0x01
#define DRM_JM_GEM_TILING_TILED      0x02
#define DRM_JM_GEM_TILING_SUPERTILED 0x04
#define DRM_JM_GEM_TILING_MINORTILED 0x08


#define DRM_JM_GEM_TILING_SPLIT    0x10
#define DRM_JM_GEM_TILING_X_MAJOR  0x20
#define DRM_JM_GEM_TILING_Y_MAJOR  0x40
#define DRM_JM_GEM_TILING_SWAP     0x80


#define DRM_JM_GEM_TS_NONE         0x00
#define DRM_JM_GEM_TS_DISABLED     0x01
#define DRM_JM_GEM_TS_NORMAL       0x02
#define DRM_JM_GEM_TS_COMPRESSED   0x03


#define DRM_JM_GEM_TS_CACHE_MODE_64B     0x00
#define DRM_JM_GEM_TS_CACHE_MODE_128B    0x01
#define DRM_JM_GEM_TS_CACHE_MODE_256B    0x02

struct drm_jm_gem_set_tiling {
    __u32 handle;
    __u32 tiling_mode;

    __u32 ts_mode;
    __u32 ts_cache_mode;
    __u64 clear_value;
};

struct drm_jm_gem_get_tiling {
    __u32 handle;
    __u32 tiling_mode;

    __u32 ts_mode;
    __u32 ts_cache_mode;
    __u64 clear_value;
};

struct drm_jm_gem_attach_aux {
    __u32 handle;
    __u32 ts_handle;
};

struct drm_jm_gem_ref_node {
    __u32 handle;


    __u32 node;
    __u32 ts_node;
};

#define DRM_JM_J2D_SEMD_CMD_FLAG_NOWAIT    0x01

struct drm_jm_j2d_send_cmd {
    __u64 cmd;
    __u32 size;
    __u32 flags;
};

struct drm_jm_j2d_wait_idle {
    __s32 timeout;
};

#define DRM_JM_GEM_CREATE          0x00
#define DRM_JM_GEM_LOCK            0x01
#define DRM_JM_GEM_UNLOCK          0x02
#define DRM_JM_GEM_CACHE           0x03
#define DRM_JM_GEM_QUERY           0x04
#define DRM_JM_GEM_TIMESTAMP       0x05
#define DRM_JM_GEM_SET_TILING      0x06
#define DRM_JM_GEM_GET_TILING      0x07
#define DRM_JM_GEM_ATTACH_AUX      0x08
#define DRM_JM_GEM_REF_NODE        0x09
#define DRM_JM_GEM_XFER_RECT       0x0A
#define DRM_JM_J2D_SEND_CMD        0x0B
#define DRM_JM_J2D_WAIT_IDLE       0x0C
#define DRM_JM_NUM_IOCTLS          0x0D


#define DRM_IOCTL_JM_GEM_CREATE        DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_CREATE,     struct drm_jm_gem_create)
#define DRM_IOCTL_JM_GEM_LOCK          DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_LOCK,       struct drm_jm_gem_lock)
#define DRM_IOCTL_JM_GEM_UNLOCK        DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_UNLOCK,     struct drm_jm_gem_unlock)
#define DRM_IOCTL_JM_GEM_CACHE         DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_CACHE,      struct drm_jm_gem_cache)
#define DRM_IOCTL_JM_GEM_QUERY         DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_QUERY,      struct drm_jm_gem_query)
#define DRM_IOCTL_JM_GEM_TIMESTAMP     DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_TIMESTAMP,  struct drm_jm_gem_timestamp)
#define DRM_IOCTL_JM_GEM_SET_TILING    DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_SET_TILING, struct drm_jm_gem_set_tiling)
#define DRM_IOCTL_JM_GEM_GET_TILING    DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_GET_TILING, struct drm_jm_gem_get_tiling)
#define DRM_IOCTL_JM_GEM_ATTACH_AUX    DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_ATTACH_AUX, struct drm_jm_gem_attach_aux)
#define DRM_IOCTL_JM_GEM_REF_NODE      DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_REF_NODE,   struct drm_jm_gem_ref_node)
#define DRM_IOCTL_JM_GEM_XFER_RECT     DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_GEM_XFER_RECT,  struct drm_jm_gem_xfer_rect)
#define DRM_IOCTL_JM_J2D_SEND_CMD      DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_J2D_SEND_CMD,   struct drm_jm_j2d_send_cmd)
#define DRM_IOCTL_JM_J2D_WAIT_IDLE     DRM_IOWR(DRM_COMMAND_BASE + DRM_JM_J2D_WAIT_IDLE,  struct drm_jm_j2d_wait_idle)


#ifdef __KERNEL__
# if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 9, 0)
#  define drm_gem_object_unreference_unlocked drm_gem_object_put
#  define drm_dev_unref                       drm_dev_put
# elif LINUX_VERSION_CODE >= KERNEL_VERSION(5, 4, 0)
#  define drm_gem_object_unreference_unlocked drm_gem_object_put_unlocked
#  define drm_dev_unref                       drm_dev_put
# endif
#endif

#if defined(__cplusplus)
}
#endif

#endif


