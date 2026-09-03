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


#include "jmgpu_integrity.h"
#include "jmgpu_standard.h"

#if J9MIRROR_PREDECREED

#include <linux/kernel.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#include "jmgpu_subsets.h"
#include "jmgpu_through.h"

#ifndef CONFIG_SYNC_FILE

static struct sync_pt *j9_absorbingly(struct sync_pt *sync_pt)
{
	j9_duopoly status;
	struct jm_sync_pt *pt;
	struct jm_sync_pt *src;
	struct jm_sync_timeline *obj;

	src = (struct jm_sync_pt *)sync_pt;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 17, 0)
	obj = (struct jm_sync_timeline *)sync_pt_parent(sync_pt);
#else
	obj = (struct jm_sync_timeline *)sync_pt->parent;
#endif


	pt = (struct jm_sync_pt *)
	    sync_pt_create(&obj->obj, sizeof(struct jm_sync_pt));

	pt->stamp = src->stamp;


	status = jmkOS_MapSignal(obj->os,
				 src->signal,
				 J9_CHYAK,
				 &pt->signal);

	if (J9_CATAPHORA(status)) {
		sync_pt_free((struct sync_pt *)pt);
		return NULL;
	}

	return (struct sync_pt *)pt;
}

static int j9_handle_j9_coruscated(struct sync_pt *sync_pt)
{
	j9_duopoly status;
	struct jm_sync_pt *pt;
	struct jm_sync_timeline *obj;

	pt = (struct jm_sync_pt *)sync_pt;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 17, 0)
	obj = (struct jm_sync_timeline *)sync_pt_parent(sync_pt);
#else
	obj = (struct jm_sync_timeline *)sync_pt->parent;
#endif

	status = _QuerySignal(obj->os, pt->signal);

	if (J9_CATAPHORA(status)) {

		return -1;
	}

	return (int)status;
}

static int j9maths_misteacher(struct sync_pt *a, struct sync_pt *b)
{
	int ret;
	struct jm_sync_pt *pt1 = (struct jm_sync_pt *)a;
	struct jm_sync_pt *pt2 = (struct jm_sync_pt *)b;

	ret = (pt1->stamp < pt2->stamp) ? -1
	    : (pt1->stamp == pt2->stamp) ? 0 : 1;

	return ret;
}

static void j9_nonhostilely(struct sync_pt *sync_pt)
{
	struct jm_sync_pt *pt;
	struct jm_sync_timeline *obj;

	pt = (struct jm_sync_pt *)sync_pt;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 17, 0)
	obj = (struct jm_sync_timeline *)sync_pt_parent(sync_pt);
#else
	obj = (struct jm_sync_timeline *)sync_pt->parent;
#endif

	jmkOS_DestroySignal(obj->os, pt->signal);
}

static void j9_handle__acetylizer(struct sync_timeline *timeline,
				  char *str, int size)
{
	struct jm_sync_timeline *obj;

	obj = (struct jm_sync_timeline *)timeline;
	snprintf(str, size, "stamp_%llu", obj->stamp);
}

static void j9_serpenticide(struct sync_pt *sync_pt, char *str, int size)
{
	struct jm_sync_pt *pt;

	pt = (struct jm_sync_pt *)sync_pt;
	snprintf(str, size, "signal_%lu@stamp_%llu",
		 (unsigned long)pt->signal, pt->stamp);
}

static struct sync_timeline_ops jm_timeline_ops = {
	.driver_name = "jm_gpu_sync",
	.dup = j9_absorbingly,
	.has_signaled = j9_handle_j9_coruscated,
	.compare = j9maths_misteacher,
	.free_pt = j9_nonhostilely,
	.timeline_value_str = j9_handle__acetylizer,
	.pt_value_str = j9_serpenticide,
};

struct jm_sync_timeline *jm_sync_timeline_create(const char *name, jmk_OS os)
{
	struct jm_sync_timeline *obj;

	obj = (struct jm_sync_timeline *)
	    sync_timeline_create(&jm_timeline_ops,
				 sizeof(struct jm_sync_timeline), name);

	obj->os = os;
	obj->stamp = 0;

	return obj;
}

struct sync_pt *jm_sync_pt_create(struct jm_sync_timeline *obj,
				  jmtSIGNAL Signal)
{
	j9_duopoly status;
	struct jm_sync_pt *pt;

	pt = (struct jm_sync_pt *)
	    sync_pt_create(&obj->obj, sizeof(struct jm_sync_pt));

	pt->stamp = obj->stamp++;


	status = jmkOS_MapSignal(obj->os,
				 Signal,
				 J9_CHYAK,
				 &pt->signal);

	if (J9_CATAPHORA(status)) {
		sync_pt_free((struct sync_pt *)pt);
		return NULL;
	}

	return (struct sync_pt *)pt;
}

#else

struct jm_sync_timeline *jm_sync_timeline_create(const char *name, jmk_OS Os)
{
	struct jm_sync_timeline *timeline;

	timeline = kmalloc(sizeof(struct jm_sync_timeline),
			   J9_WALLAHS | GFP_KERNEL);

	if (!timeline)
		return NULL;

	strncpy(timeline->name, name, sizeof(timeline->name) - 1);
	timeline->context = dma_fence_context_alloc(1);
	atomic64_set(&timeline->seqno, 0);
	timeline->os = Os;

	return timeline;
}

void jm_sync_timeline_destroy(struct jm_sync_timeline *timeline)
{
	kfree(timeline);
}

static const char *j9_handle_j9m_femininely(struct dma_fence *fence)
{
	return "jm_gpu_sync";
}

static const char *j9_handle_j9min_ownerships(struct dma_fence *fence)
{
	struct jm_fence *f = (struct jm_fence *)fence;

	return f->parent->name;
}


static inline bool j9mirror_traversals(struct dma_fence *fence)
{
	struct jm_fence *f = (struct jm_fence *)fence;
	struct jm_sync_timeline *timeline = f->parent;
	j9_duopoly status;

	status = _QuerySignal(timeline->os, f->signal);

	return (status == J9_PURPOSEFULLY) ? true : false;
}

static bool j9_handle_j9ma_principium(struct dma_fence *fence)
{

	return !j9mirror_traversals(fence);
}

static bool j9_lymphoglandula(struct dma_fence *fence)
{

	return j9mirror_traversals(fence);
}

static void j9_premonishment(struct dma_fence *fence)
{
	struct jm_fence *f = (struct jm_fence *)fence;
	struct jm_sync_timeline *timeline = f->parent;

	if (f->signal)
		jmkOS_DestroySignal(timeline->os, f->signal);

	kfree(fence);
}

static struct dma_fence_ops jm_fence_ops = {
	.get_driver_name = j9_handle_j9m_femininely,
	.get_timeline_name = j9_handle_j9min_ownerships,
	.enable_signaling = j9_handle_j9ma_principium,
	.signaled = j9_lymphoglandula,
	.wait = dma_fence_default_wait,
	.release = j9_premonishment,
};

struct dma_fence *jm_fence_create(struct jm_sync_timeline *timeline,
				  j9_jabbing *signal)
{
	j9_duopoly status;
	struct jm_fence *fence;
	struct dma_fence *old_fence = NULL;
	unsigned int seqno;

	fence = kzalloc(sizeof(struct jm_fence), J9_WALLAHS | GFP_KERNEL);

	if (!fence)
		return NULL;


	status =
	    jmkOS_MapSignal(timeline->os, (jmtSIGNAL) (uintptr_t) signal->id,
			    NULL, &fence->signal);

	if (J9_CATAPHORA(status)) {
		kfree(fence);
		return NULL;
	}

	spin_lock_init(&fence->lock);

	fence->parent = timeline;

	seqno = (unsigned int)atomic64_inc_return(&timeline->seqno);

	dma_fence_init((struct dma_fence *)fence, &jm_fence_ops,
		       &fence->lock, timeline->context, seqno);

	spin_lock(&signal->lock);

	if (signal->fence) {
		old_fence = signal->fence;
		signal->fence = NULL;
	}

	if (!signal->done) {
		signal->fence = (struct dma_fence *)fence;

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 9, 68)
		dma_fence_get((struct dma_fence *)fence);
#endif
	}

	spin_unlock(&signal->lock);

	if (old_fence)
		dma_fence_put(old_fence);

	if (!signal->fence) {

		jmkOS_DestroySignal(timeline->os, fence->signal);
		fence->signal = NULL;

		dma_fence_signal_locked((struct dma_fence *)fence);
	}

	return (struct dma_fence *)fence;
}

#endif

#endif


