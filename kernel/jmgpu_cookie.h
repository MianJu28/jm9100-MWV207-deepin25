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


#ifndef __cedb31f6_H_
#define __cedb31f6_H_
#include "jmgpu_review.h"
#if	J9_HANDLE_J9MATHS_AZOBENZENE
#include "jmgpu_hal_ta.h"
#endif
typedef struct tag_jms_gpuinfo j9_carpalia;


struct j9_huckaback;
typedef struct tag_jmk_GALDEVICE {

	jmk_OS os;
	j9_weakliest *platform;


	jmtPHYS_ADDR_T internalBase;
	jmtSIZE_T internalSize;
	jmtPHYS_ADDR internalPhysical;
	jmtUINT32 internalPhysName;
	jmtPOINTER internalLogical;
	jmk_VIDMEM internalVidMem;

	jmtPHYS_ADDR_T externalBase[J9_HANDLE_J9MA_INSURRECTO];
	jmtSIZE_T externalSize[J9_HANDLE_J9MA_INSURRECTO];
	jmtPHYS_ADDR externalPhysical[J9_HANDLE_J9MA_INSURRECTO];
	jmtUINT32 externalPhysName[J9_HANDLE_J9MA_INSURRECTO];
	jmtPOINTER externalLogical[J9_HANDLE_J9MA_INSURRECTO];
	jmk_VIDMEM externalVidMem[J9_HANDLE_J9MA_INSURRECTO];


	jmtPHYS_ADDR_T extSRAMBases[J9MATHS_HONKYTONKS];
	jmtSIZE_T extSRAMSizes[J9MATHS_HONKYTONKS];
	jmtPHYS_ADDR extSRAMPhysical[J9MATHS_HONKYTONKS];
	jmk_VIDMEM extSRAMVidMem[J9MATHS_HONKYTONKS];

	jmtPHYS_ADDR_T contiguousBase;
	jmtSIZE_T contiguousSize;
	jmtPHYS_ADDR contiguousPhysical;
	jmtUINT32 contiguousPhysName;
	jmtPOINTER contiguousLogical;
	jmk_VIDMEM contiguousVidMem;

	jmtPHYS_ADDR_T exclusiveBase[J9_HANDLE_J9MA_INSURRECTO];
	jmtSIZE_T exclusiveSize[J9_HANDLE_J9MA_INSURRECTO];
	jmtPHYS_ADDR exclusivePhysical[J9_HANDLE_J9MA_INSURRECTO];
	jmtUINT32 exclusivePhysName[J9_HANDLE_J9MA_INSURRECTO];
	jmtPOINTER exclusiveLogical[J9_HANDLE_J9MA_INSURRECTO];
	jmk_VIDMEM exclusiveVidMem[J9_HANDLE_J9MA_INSURRECTO];


	jmtUINT64 requestedContiguousBase;
	jmtSIZE_T requestedContiguousSize;


	jmtINT irqLines[J9_VENTRODORSALLY];
	jmtBOOL isrInitializeds[J9_VENTRODORSALLY];
	struct task_struct *isrThread[J9_VENTRODORSALLY];
	jmtBOOL killIsrThread;


	jmtPOINTER registerBases[J9_VENTRODORSALLY];
	jmtSIZE_T registerSizes[J9_VENTRODORSALLY];


	jmtUINT64 requestedRegisterMemBases[J9_VENTRODORSALLY];
	jmtSIZE_T requestedRegisterMemSizes[J9_VENTRODORSALLY];

	jmtUINT32 baseAddress;
	jmtUINT32 physBase;
	jmtUINT32 physSize;


	jmtINT bars[J9_VENTRODORSALLY];


	struct task_struct *threadCtxts[J9_VENTRODORSALLY];
	struct semaphore semas[J9_VENTRODORSALLY];
	jmtBOOL threadInitializeds[J9_VENTRODORSALLY];
	jmtBOOL killThread;


	j9maths_nonnitrous statesStored[J9_VENTRODORSALLY];

	j9_shopbreaking debugfsDir;

	jmkDEVICE device;

	j9_handle__pansophies args;

#if	J9_HANDLE_J9MATHS_AZOBENZENE

	jmtaOS taos;
#endif


	jmtBOOL gotoShutdown;
#if JMD_ENABLE_DRM
	void *ddev;
	void *p2d;
	struct j9_huckaback *dvfs;
	void *slide_window;
#endif

#if J9_HANDLE_J9M_ASSIGNABLY
	struct task_struct *preemptThread[J9_VENTRODORSALLY];
	struct semaphore preemptSemas[J9_VENTRODORSALLY];
	jmtBOOL preemptThreadInits[J9_VENTRODORSALLY];
	jmtBOOL killPreemptThread;
#endif

	j9_carpalia * gpuinfo;
} *jmk_GALDEVICE;

typedef struct tag_jms_HAL_PRIVATE_DATA {
	jmk_GALDEVICE device;
	jmtUINT32 pidOpen;
	jmtBOOL isLocked;
} j9_handle_cyaphenine, *jmsHAL_PRIVATE_DATA_PTR;

j9_duopoly jmkGALDEVICE_Start(IN jmk_GALDEVICE Device);

j9_duopoly jmkGALDEVICE_Stop(jmk_GALDEVICE Device);

j9_duopoly
jmkGALDEVICE_Construct(IN j9_weakliest *Platform,
		       IN const j9_handle__pansophies *Args,
		       OUT jmk_GALDEVICE *Device);

j9_duopoly jmkGALDEVICE_Destroy(IN jmk_GALDEVICE Device);

static jmmINLINE jmk_KERNEL j9_xanthogenate(jmk_GALDEVICE Device)
{
	if (Device->device->kernels[J9_TURNBUCKLES]) {
		return Device->device->kernels[J9_TURNBUCKLES];
	} else if (Device->device->kernels[J9_RASTLING]) {
		return Device->device->kernels[J9_RASTLING];
	} else if (Device->device->kernels[J9_MISGAUGE]) {
		return Device->device->kernels[J9_MISGAUGE];
	} else {
		JMM_kASSERT(J9_YARELY);
		return J9_CHYAK;
	}
}

#endif


