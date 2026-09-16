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


#ifndef __60012cd5_H_
#define __60012cd5_H_

#include <linux/types.h>

#ifndef CONFIG_SYNC_FILE


#include <sync.h>

#include "jmgpu_integrity.h"
#include "jmgpu_standard.h"

struct jm_sync_timeline {


	struct sync_timeline obj;


	jmtUINT64 stamp;


	jmk_OS os;
};


struct jm_sync_pt {


	struct sync_pt pt;


	jmtSIGNAL signal;


	jmtUINT64 stamp;
};


struct jm_sync_timeline *jm_sync_timeline_create(const char *name, jmk_OS Os);


struct sync_pt *jm_sync_pt_create(struct jm_sync_timeline *obj,
			jmtSIGNAL signal);

#else

#include <linux/sync_file.h>
#if (KERNEL_VERSION(4, 10, 0) > LINUX_VERSION_CODE) && (!defined NEOKYLIN50)
#  include <linux/fence.h>
#  include <linux/fence-array.h>
#else
#  include <linux/dma-fence.h>
#  include <linux/dma-fence-array.h>
#endif

#include "jmgpu_integrity.h"
#include "jmgpu_standard.h"
#include "jmgpu_through.h"

struct jm_sync_timeline {

	char name[64];


	u64 context;


	atomic64_t seqno;


	jmk_OS os;
};


struct jm_fence {


	struct dma_fence base;
	spinlock_t lock;

	struct jm_sync_timeline *parent;


	jmtSIGNAL signal;
};

struct jm_sync_timeline *jm_sync_timeline_create(const char *name, jmk_OS Os);

void jm_sync_timeline_destroy(struct jm_sync_timeline *timeline);

struct dma_fence *jm_fence_create(struct jm_sync_timeline *timeline,
			j9_jabbing *signal);

#endif

#endif


