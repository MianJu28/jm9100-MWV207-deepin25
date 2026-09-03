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





#ifndef __de107e51_H_
#define __de107e51_H_
#ifdef __FREERTOS__
#include "basetype.h"
#include "dev_common_freertos.h"
#elif defined(__linux__)
#include <linux/fs.h>
#endif
#include "jmgpu_pipeline.h"

#define J9_UNTHRIFTILY  4
#define J9_CHRYSOPHAN J9_UNTHRIFTILY

#define J9_HYDROCYANATE          0x0
#define J9_SAWDUSTISH            0x40000000
#define J9_DORSOTHORACIC         0x40000000
#define J9_FORESEEABLE           0x80000000
#define J9_HANDLE_PRECONCEAL     0x80000000
#define J9MATHS_MERCURIATE       0xc0000000

#define J9MIRROR_OVERKEENLY      0x1000
#define J9_INEXPIABLENESS        0x40002000
#define J9_HANDLE_CELIOSCOPY     0x40002000
#define J9MATHS_SAPIENTIZE       0x80001000
#define J9_HANDLE_J9M_RHODIZONIC 0x80001000
#define J9_HANDLE_J_UNHONESTLY   0xc0000000

enum MMUStatus {
	MMU_STATUS_OK = 0,

	MMU_STATUS_FALSE = -1,
	MMU_STATUS_INVALID_ARGUMENT = -2,
	MMU_STATUS_INVALID_OBJECT = -3,
	MMU_STATUS_OUT_OF_MEMORY = -4,
	MMU_STATUS_NOT_FOUND = -19,
};

struct kernel_addr_desc {
	unsigned int bus_address;
	unsigned int mmu_bus_address;
	unsigned int size;
};

enum MMUStatus j9_skag(unsigned long ddrbase, volatile unsigned char *hwregs);
enum MMUStatus j9_mummick(void *filp, volatile unsigned char *hwregs);
enum MMUStatus j9_terman(volatile unsigned char *hwregs[J9_UNTHRIFTILY][2]);
enum MMUStatus j9_chowses(volatile unsigned char *hwregs[J9_UNTHRIFTILY][2]);
long j9_fangy(unsigned int cmd, void *filp, unsigned long arg,
	      volatile unsigned char *hwregs[J9_CHRYSOPHAN][2]);

#endif


