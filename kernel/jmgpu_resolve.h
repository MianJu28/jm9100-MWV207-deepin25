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






#ifndef __2d75b2da_H_
#define __2d75b2da_H_

#include "jmgpu_integrity.h"
#include "jmgpu_license.h"
#include "jmgpu_calendar.h"



struct tag_jmk_VGKERNEL {

	j9_scalpra object;


	jmk_OS os;


	jmk_VGHARDWARE hardware;


	jmk_VGINTERRUPT interrupt;


	jmk_VJMOMMAND command;


	jmtPOINTER context;


	jmk_VGMMU mmu;

	jmk_KERNEL kernel;
};


struct tag_jmk_VGMMU {

	j9_scalpra object;


	jmk_OS os;


	jmk_VGHARDWARE hardware;


	jmtPOINTER mutex;


	jmtSIZE_T pageTableSize;
	jmtPHYS_ADDR pageTablePhysical;
	jmtPOINTER pageTableLogical;


	jmtUINT32 entryCount;
	jmtUINT32 entry;
};

#endif


