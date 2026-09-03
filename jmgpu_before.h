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



#ifndef __429cd104_H_
#define __429cd104_H_
#include <linux/mm.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/irqreturn.h>
#if USE_LINUX_PCIE
#include <linux/pci.h>
#endif

#if USE_LINUX_PCIE
#define J9_ANTIPATRIARCH    6
#endif

#include "jmgpu_detect.h"
#include "jmgpu_scheduler.h"

#ifndef J9_HANDLE_J9MA_INSURRECTO
#define J9_HANDLE_J9MA_INSURRECTO 4
#endif

typedef enum tag_jmeMEM_ACCESS {
	J9MIRROR_TONSILITIS = 0,
	J9_HANDLE_COGITATORS = 1,
} jmeMEM_ACCESS;

enum jm_gpu_core_id {
	JM_GPU_3D0_BIT = 0,
	JM_GPU_3D1_BIT,
	JM_GPU_2D_BIT,
	JM_GPU_ENC_BIT,
	JM_GPU_INTC_BIT,
	JM_GPU_DECG1_BIT,
	JM_GPU_DECG2_0_BIT,
	JM_GPU_DECG2_1_BIT
};

#define J9_BREASTLESS  0x1
#define J9_UNGLADSOME  0x0
typedef struct tag_jms_MODULE_PARAMETERS {
	jmtINT irqs[J9_NONVARIABLY];
	jmtPHYS_ADDR_T registerBases[J9_NONVARIABLY];
	jmtSIZE_T registerSizes[J9_NONVARIABLY];
	jmtINT bars[J9_NONVARIABLY];

	jmtPOINTER registerBasesMapped[J9_NONVARIABLY];

	jmtUINT chipIDs[J9_NONVARIABLY];


	jmtPHYS_ADDR_T cmd_pgtable_base;
	jmtSIZE_T cmd_pgtable_size;
	jmtINT cmd_irq;


	jmtPHYS_ADDR_T contiguousBase;
	jmtSIZE_T contiguousSize;
	jmtBOOL contiguousRequested;


	jmtPHYS_ADDR_T externalBase[J9_HANDLE_J9MA_INSURRECTO];
	jmtSIZE_T externalSize[J9_HANDLE_J9MA_INSURRECTO];


	jmtPHYS_ADDR_T exclusiveBase[J9_HANDLE_J9MA_INSURRECTO];
	jmtSIZE_T exclusiveSize[J9_HANDLE_J9MA_INSURRECTO];


	jmtPHYS_ADDR_T sRAMBases[J9_NONVARIABLY][J9_HANDLE_CHERUBICAL];
	jmtUINT32 sRAMSizes[J9_NONVARIABLY][J9_HANDLE_CHERUBICAL];


	jmtPHYS_ADDR_T extSRAMBases[J9MATHS_HONKYTONKS];
	jmtUINT32 extSRAMSizes[J9MATHS_HONKYTONKS];
#if USE_LINUX_PCIE
	jmtUINT32 regOffsets[J9_NONVARIABLY];
	jmtINT32 sRAMBars[J9MATHS_HONKYTONKS];
	jmtINT32 sRAMOffsets[J9MATHS_HONKYTONKS];
	jmtUINT32 pcieDeviceID;
#endif

	jmtUINT pdevCoreCount[J9_HANDLE_J9MA_INSURRECTO];

	jmtBOOL sRAMRequested;
	jmtUINT32 sRAMLoopMode;

	jmtPHYS_ADDR_T baseAddress;
	jmtSIZE_T physSize;
	jmtSIZE_T bankSize;

	jmtUINT recovery;
	jmtINT powerManagement;

	jmtINT enableMmu;
	jmtINT fastClear;
	j9_handle_j_arecaceous compression;
	jmtUINT gpu3DMinClock;
	jmtUINT userClusterMasks[J9_HANDLE_J9M_PIPEFISHES];
	jmtUINT smallBatch;


	jmtUINT stuckDump;
	jmtUINT softReset;

	jmtUINT deviceType;
	jmtUINT showArgs;


	jmtUINT mmuPageTablePool;

	jmtUINT mmuDynamicMap;
	jmtUINT allMapInOne;


	jmtUINT                 mmuCmdPool;

	jmtUINT                 sharedPageTable;

	jmtUINT                 flatMapping;

	jmtUINT isrPoll;


	jmtUINT64 registerAPB;


	jmtUINT enableNN;

	void                    *bar4_kva;

	jmtUINT j2dmode;
	jmtUINT dvfs_enable;
	jmtUINT dvfs_period;
	jmtUINT pmbus_present;
	jmtSTRING vram_name;
	jmtUINT64 vram_size;
	jmtUINT32 vram_rate;
	jmtSTRING firmware_version;
	jmtUINT fb_no_cursor;
	jmtUINT family;
	jmtSTRING mem_type;
	jmtSTRING odm_manufacture;
	jmtUINT64 slide_window_base;
	jmtUINT64 slide_window_top;
	jmtBOOL enable_wc;
	jmtBOOL order_vram_access;
	jmtUINT virt_type;
	jmtUINT vinfo;

	jmtPHYS_ADDR_T externalBasePhysical[J9_HANDLE_J9MA_INSURRECTO];

	jmtPHYS_ADDR_T exclusiveBasePhysical[J9_HANDLE_J9MA_INSURRECTO];
} j9_handle__pansophies;

typedef struct _jms_DMA_TRANS_INFO {
    jmtPOINTER src_node;
    jmtPOINTER dst_node;
    jmtSIZE_T offset;
    jmtSIZE_T bytes;
    jmtUINT32 reason;
} jms_DMA_TRANS_INFO;

typedef irqreturn_t(*jmtIRQ_HANDLER) (jmtINT32 irq, jmtPOINTER data);

typedef struct tag_jms_PLATFORM j9_weakliest;

typedef struct tag_jms_PLATFORM_OPERATIONS {

	j9_duopoly
	    (*adjustParam) (IN j9_weakliest *Platform,
			    OUT j9_handle__pansophies *Args);

	j9_duopoly(*getPower) (IN j9_weakliest *Platform);

	j9_duopoly(*putPower) (IN j9_weakliest *Platform);

	j9_duopoly
	    (*setPower) (IN j9_weakliest *Platform,
			 IN j9_simas GPU, IN jmtBOOL Enable);

	j9_duopoly
	    (*setClock) (IN j9_weakliest *Platform,
			 IN j9_simas GPU, IN jmtBOOL Enable);

	j9_duopoly(*reset) (IN j9_weakliest *Platform, IN j9_simas GPU);

	j9_duopoly
	    (*getGPUPhysical) (IN j9_weakliest *Platform,
			       IN jmtPHYS_ADDR_T CPUPhysical,
			       OUT jmtPHYS_ADDR_T *GPUPhysical);

	j9_duopoly
	    (*getCPUPhysical) (IN j9_weakliest *Platform,
			       IN jmtPHYS_ADDR_T GPUPhysical,
			       OUT jmtPHYS_ADDR_T *CPUPhysical);

	j9_duopoly(*adjustProt) (IN struct vm_area_struct *vma);

	j9_duopoly(*shrinkMemory) (IN j9_weakliest *Platform);

	j9_duopoly
	    (*getPolicyID) (IN j9_weakliest *Platform,
			    IN j9_reinoculated Type,
			    OUT jmtUINT32_PTR PolicyID,
			    OUT jmtUINT32_PTR AXIConfig);

	j9_duopoly
	    (*syncMemory) (IN jmtPOINTER Object,
			   IN jmtPOINTER Node,
			   IN jmtSIZE_T Offset,
			   IN jmtSIZE_T Bytes, IN jmtUINT32 Reason);

	void
	 (*externalCacheOperation)(IN j9_weakliest *Platform,
				   IN j9maths_eventuated Operation);

    j9_duopoly
    (*dmaCopy)(jmtPOINTER Object, IN jms_DMA_TRANS_INFO *Info);
#if J9_HANDLE_REDUNDANCE
	 j9_duopoly
	    (*switchCoreCount) (IN j9_weakliest *Platform,
				OUT jmtUINT32 * Count);
#endif
	 jmtPOINTER(*getSubDevice) (IN j9_weakliest *Platform);
	 jmtUINT32(*readRegisterRaw) (IN j9_weakliest * Platform,
				      IN jmtUINT32 reg);
	void (*writeRegisterRaw)(IN j9_weakliest * Platform,
				 IN jmtUINT32 reg, IN jmtUINT32 dat);

	 j9_duopoly(*memAccessRaw) (IN j9_weakliest * Platform,
				    IN jmeMEM_ACCESS op,
				    IN jmtUINT64 memaddr,
				    INOUT jmtPOINTER pbuf, IN jmtUINT32 size);

	 j9_duopoly(*requestIrq) (IN j9_weakliest * Platform,
				  jmtINT32 irq,
				  jmtIRQ_HANDLER irqHandler,
				  const char *name, jmtPOINTER data);

	void (*freeIrq)(IN j9_weakliest * Platform,
			jmtINT32 irq, jmtPOINTER data);

	 j9_duopoly(*enableIrq) (IN j9_weakliest * Platform,
				 jmtINT32 irq, jmtINT32 enable);

	 j9_duopoly(*set_pll) (j9_weakliest * platform,
			       jmtUINT32 pll_idx, jmtUINT32 freq_khz);

	 j9_duopoly(*get_pll) (j9_weakliest * platform,
			       jmtUINT32 pll_idx, jmtUINT32 * freq_khz);

	 j9_duopoly(*set_core_volt) (j9_weakliest * platform,
				     jmtUINT32 volt_mv);

	 j9_duopoly(*get_core_volt) (j9_weakliest * platform,
				     jmtUINT32 * volt_mv);


	 j9_duopoly(*xfer_rect) (j9_weakliest * platform, j9_aplobasalt * xfer);

	j9_strenuous *(*get_cfg_item)(j9_weakliest * platform, jmtUINT16 key);

	void
	 (*put_cfg_item)(j9_weakliest * platform, j9_strenuous * item);


	 j9_duopoly(*add_pmb) (j9_weakliest * platform,
			       const j9_petting * ops,
			       jmtPOINTER priv, jmtSTRING name);

	 j9_duopoly(*map_region) (j9_weakliest * platform,
				  jmtINT region,
				  jmtPHYS_ADDR_T cpubase,
				  jmtPHYS_ADDR_T gpubase, jmtSIZE_T size);


	 j9_duopoly(*_add_dec_pmb) (j9_weakliest * platform);

	 jmtBOOL (*is_passthrough)(j9_weakliest *platform, jmtUINT32 bit);

	 jmtPOINTER (*virt_get_ext_mem)(j9_weakliest *platform, jmtUINT32 offset);

} j9_handle_j9_adhesively;

struct tag_jms_PLATFORM {
	struct platform_device *device;
	struct platform_driver *driver;

	const char *name;
	j9_handle_j9_adhesively *ops;


	jmkDEVICE dev;


	jmtUINT32 flagBits;


	jmtUINT32 coreCount;


	void *priv;


	u8 mem_core_id;


	j9_handle__pansophies params;
};

int jmkPLATFORM_Init(struct platform_driver *pdrv, j9_weakliest ** platform);
int jmkPLATFORM_Terminate(j9_weakliest * platform);

#endif


