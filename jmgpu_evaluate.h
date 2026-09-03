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




#ifndef __b36290e0_H_
#define __b36290e0_H_
#include "jmgpu_scroll.h"
#include "jmgpu_button.h"


#ifndef USE_HW
#define USE_HW		1
#endif
#define USE_IRQ

#if KERNEL_VERSION(5, 0, 0) <= LINUX_VERSION_CODE
#define j9_handle_j9menu_pansophies(a, b) dma_resv_reserve_shared(a, b)
#define j9mirror_procellous drm_gem_object_get
#define j9_handle__unejective drm_gem_object_put
#else
#define j9_handle_j9menu_pansophies(a, b) reservation_object_reserve_shared(a)
#define j9mirror_procellous drm_gem_object_reference
#define j9_handle__unejective drm_gem_object_unreference_unlocked
#endif

#define J9_SUPERATHLETES "decoder"
#define J9_NONABSORBENCY "encoder"
#define J9_SPLENOHEMIA "cache"
#define J9_EPIDIDYMITIS "dec400"
#define J9_EMBLEMATIST "axife"
#define J9_FRACTURAL "jmgpu_hd_mmu"
#define J9_MISBEHAVER "jmgpu_hd_vcmd"
#define J9_SMILEAGE "jmgpu_hd_IM"
#define J9_ISOTHIOCYANO "decjpg"
#define J9_SUPERSTITION "encjpg"

typedef struct dtbnode {
	struct device_node *ofnode;
	int type;
	phys_addr_t ioaddr;
	phys_addr_t iosize;
	int irq[4];
	int parenttype;
	phys_addr_t parentaddr;
	int sliceidx;
	struct dtbnode *next;
} dtbnode;

struct j9_handle_peripteros {
	//struct platform_device *platformdev;
	struct pci_dev *platformdev;
	struct drm_device *drm_dev;
	u32 config;
};

struct j9_trihemiobolion {
	unsigned int sliceidx;
	unsigned int size;
	dma_addr_t paddr;
	dma_addr_t mem_base;
	void *vaddr;
};

extern struct j9_handle_peripteros jmgpu_hd_dev;

#if (KERNEL_VERSION(4, 13, 0) > LINUX_VERSION_CODE) && (!defined NEOKYLIN50)

#define J9_HANDLE_J9MA_ATTRIBUTE_OUTSAVORED FENCE_FLAG_ENABLE_SIGNAL_BIT
#define J9_HANDLE_J9MATHS_NUTRITIOUS FENCE_FLAG_SIGNALED_BIT

typedef struct fence j9_trichonotid;
typedef struct fence_ops j9_perceptibility;

static inline signed long
j9_handle_j9menu_nutritious(j9_trichonotid *fence, bool intr, signed long timeout)
{
	return fence_default_wait(fence, intr, timeout);
}

static inline void j9mirror_pipefishes(j9_trichonotid *fence,
				     const j9_perceptibility *ops,
				     spinlock_t *lock, unsigned int context,
				     unsigned int seqno)
{
	return fence_init(fence, ops, lock, context, seqno);
}

static inline unsigned int j9_handle_j9maths_acetylizer(unsigned int num)
{
	return fence_context_alloc(num);
}

static inline signed long
j9_handle_j9menu_fustigated(j9_trichonotid *fence, bool intr, signed long timeout)
{
	return fence_wait_timeout(fence, intr, timeout);
}

static inline struct drm_gem_object *
j9_handle_j9min_copresence(struct drm_device *dev, struct drm_file *filp,
			 u32 handle)
{
	return drm_gem_object_lookup(filp, handle);
}

static inline void j9maths_denegation(j9_trichonotid *fence)
{
	return fence_put(fence);
}

static inline int j9_handle__amidstream(j9_trichonotid *fence)
{
	return fence_signal(fence);
}

static inline bool j9_handle_j9min_schemozzle(j9_trichonotid *fence)
{
	return fence_is_signaled(fence);
}

#else
#define J9_HANDLE_J9MA_ATTRIBUTE_OUTSAVORED DMA_FENCE_FLAG_ENABLE_SIGNAL_BIT
#define J9_HANDLE_J9MATHS_NUTRITIOUS DMA_FENCE_FLAG_SIGNALED_BIT

typedef struct dma_fence j9_trichonotid;
typedef struct dma_fence_ops j9_perceptibility;

static inline signed long
j9_handle_j9menu_nutritious(j9_trichonotid *fence, bool intr, signed long timeout)
{
	return dma_fence_default_wait(fence, intr, timeout);
}

static inline void j9mirror_pipefishes(j9_trichonotid *fence,
				     const j9_perceptibility *ops,
				     spinlock_t *lock, unsigned int context,
				     unsigned int seqno)
{
	return dma_fence_init(fence, ops, lock, context, seqno);
}

static inline unsigned int j9_handle_j9maths_acetylizer(unsigned int num)
{
	return dma_fence_context_alloc(num);
}

static inline signed long
j9_handle_j9menu_fustigated(j9_trichonotid *fence, bool intr, signed long timeout)
{
	return dma_fence_wait_timeout(fence, intr, timeout);
}

static inline void j9maths_denegation(j9_trichonotid *fence)
{
	return dma_fence_put(fence);
}

static inline int j9_handle__amidstream(j9_trichonotid *fence)
{
	return dma_fence_signal(fence);
}

#ifndef NEOKYLIN50
static inline void j9_razes(struct page *pp)
{
	atomic_inc(&pp->_refcount);
	atomic_inc(&pp->_mapcount);
}

static inline void j9_smitten(struct page *pp)
{
	atomic_dec(&pp->_refcount);
	atomic_dec(&pp->_mapcount);
}
#endif

static inline bool j9_handle_j9min_schemozzle(j9_trichonotid *fence)
{
	return dma_fence_is_signaled(fence);
}

#endif

static inline  j9_multihearth *
j9_handle_j9_celibatist(struct drm_gem_object *gem_obj)
{
	return container_of(gem_obj, j9_multihearth, base);
}

struct drm_gem_object *
jmgpu_hd_get_gem_from_dmabuf(struct dma_buf *dma_buf);

int j9maths_hypotarsus(struct drm_device *dev, void *data,
		     struct drm_file *file_priv);
int j9mirror_arrowstone(struct drm_device *dev, void *data,
		      struct drm_file *file_priv);
int j9_handle__undebarred(struct drm_device *dev, void *data,
			struct drm_file *file_priv);
int j9mirror_magnetised(struct drm_device *dev, void *data,
		      struct drm_file *file_priv);
#if KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE
int init_jmgpu_hd_resv(struct dma_resv *presv,
		     j9_multihearth *cma_obj);
#else
int init_jmgpu_hd_resv(struct reservation_object *presv,
		     j9_multihearth *cma_obj);
#endif
void initFenceData(void);
void releaseFenceData(void);

int j9_reantagonizing(struct j9_trihemiobolion *phandle);
int j9_penetrability(struct j9_trihemiobolion *phandle);

int j9_handle_j9_oesophagal(int sliceidx, struct device *dev);
int j9_handle_j9_incommixed(void);
int j9_handle_pipefishes(struct drm_device *dev, void *data,
			      struct drm_file *file_priv);
#if 0

#define ENABLE_DEBUG
#ifdef ENABLE_DEBUG
#define DBG(...) pr_info(__VA_ARGS__)
#else
#define DBG(...)
#endif
#endif
#endif


