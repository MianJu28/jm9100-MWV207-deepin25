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





#ifndef __ed761dec_H_
#define __ed761dec_H_

typedef struct _LINUX_MDL LINUX_MDL, *PLINUX_MDL;
typedef struct _LINUX_MDL_MAP LINUX_MDL_MAP, *PLINUX_MDL_MAP;

struct _LINUX_MDL_MAP {
	jmtINT pid;


	jmtUINT32 count;

	struct vm_area_struct *vma;
	jmtPOINTER vmaAddr;
	jmtBOOL cacheable;

	struct list_head link;
};

struct _LINUX_MDL {
	jmk_OS os;

	atomic_t refs;


	char *addr;


	size_t bytes;
	size_t numPages;

	jmtBOOL contiguous;
	dma_addr_t dmaHandle;
	jmtBOOL cacheable;
	jmtBOOL cpuAccessible;

	struct device *dev;
	struct mutex mapsMutex;
	struct list_head mapsHead;


	void *allocator;


	void *priv;

	uint gid;

	struct list_head link;

	jmtBOOL pageUnit1M;


	struct list_head rmaHead;


	struct list_head rmaLink;


	jmtBOOL wrapFromLogical;

	jmtBOOL wrapFromPhysical;
	jmtBOOL userAccessed;


	jmtBOOL                 fromUser;
};

extern PLINUX_MDL_MAP FindMdlMap(IN PLINUX_MDL Mdl, IN jmtINT PID);

typedef struct _DRIVER_ARGS {
	jmtUINT64 InputBuffer;
	jmtUINT64 InputBufferSize;
	jmtUINT64 OutputBuffer;
	jmtUINT64 OutputBufferSize;
} DRIVER_ARGS;

#endif


