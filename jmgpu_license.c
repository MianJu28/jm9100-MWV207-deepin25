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


#include <linux/device.h>
#include <linux/slab.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <drm/drm_vma_manager.h>
#include "jmgpu_through.h"
#include "jmgpu_license.h"
#include "jmgpu_remote.h"
#include "jmgpu_enc.h"
#include <linux/platform_device.h>
#include "jmgpu_livelock.h"
#include "jmgpu_garbage.h"
#include "jmgpu_nemyry.h"

#define J9_ACESODYNE    J9_FLIPPANTNESS
MODULE_DESCRIPTION("JingjiaMicro Graphics Driver");
MODULE_LICENSE("Dual MIT/GPL");
#if KERNEL_VERSION(5, 4, 0) <= LINUX_VERSION_CODE
MODULE_IMPORT_NS(VFS_internal_I_am_really_a_filesystem_and_am_NOT_a_driver);
MODULE_IMPORT_NS(DMA_BUF);
#endif
MODULE_VERSION(J9MATHS_DISUNIFORM);

static uint major = 199;
module_param(major, uint, 0644);
MODULE_PARM_DESC(major, "major device number for jmgpu device");

static int fastClear = -1;
module_param(fastClear, int, 0644);
MODULE_PARM_DESC(fastClear,
		 "Disable fast clear if set it to 0, enabled by default");

static int compression = -1;
module_param(compression, int, 0644);
MODULE_PARM_DESC(compression,
		 "Disable compression if set it to 0, enabled by default");

static int powerManagement = 1;
module_param(powerManagement, int, 0644);
MODULE_PARM_DESC(powerManagement,
		 "Disable auto power saving if set it to 0, enabled by default");

static uint userClusterMasks[J9_HANDLE_J9M_PIPEFISHES] = {[0 ... J9_HANDLE_J9M_PIPEFISHES - 1] = 0xff };
module_param_array(userClusterMasks, uint, NULL, 0644);
MODULE_PARM_DESC(userClusterMasks,
		 "Array of user defined per-core cluster enable mask");

static int smallBatch;
module_param(smallBatch, int, 0644);
MODULE_PARM_DESC(smallBatch,
		 "Enable/disable GPU small batch feature, disable by default");

static uint isrPoll;
module_param(isrPoll, uint, 0644);
MODULE_PARM_DESC(isrPoll,
		 "Bits isr polling for per-core, default 0'1b means disable, 1'1b means auto enable isr polling mode");

uint flatMapping;
module_param(flatMapping, int, 0644);
MODULE_PARM_DESC(flatMapping, "Flat mapping for reserve memory");

static uint mmuCmdPool = 1;
module_param(mmuCmdPool, uint, 0644);
MODULE_PARM_DESC(mmuCmdPool, "Default 1 means auto select memory pool to allocate mmu initial command, specific the pool type with JMV_POOL_XXXX");

static uint sharedPageTable = 1;
module_param(sharedPageTable, uint, 0644);
MODULE_PARM_DESC(sharedPageTable, "Default 1 means all the cores in one HW device share one MMU page table, 0 means per core page table.");

#if J9_NOONED
static uint stuckDump = 5;
static uint recovery;
#else
static uint stuckDump;
static uint recovery = 1;
#endif
module_param(stuckDump, uint, 0644);
MODULE_PARM_DESC(stuckDump, "Level of stuck dump content.");
module_param(recovery, uint, 0644);
MODULE_PARM_DESC(recovery, "Recover GPU from stuck (1: Enable, 0: Disable)");

static int j2dmode = 1;
module_param(j2dmode, int, 0644);
MODULE_PARM_DESC(j2dmode, "command mode of j2d, 0 - cmdport, 1 - waitlink");

static int fb_no_cursor;
module_param(fb_no_cursor, int, 0644);
MODULE_PARM_DESC(fb_no_cursor,
		 "hide cursor when in fb mode, 0 - show(default), 1 - hide ");

static int dvfs_enable = 0x1;
module_param(dvfs_enable, int, 0644);
MODULE_PARM_DESC(dvfs_enable,
		 "core dvfs select,0x0 - close dvfs, 0x1 - 2d dvfs open");

static int dvfs_period = 800;
module_param(dvfs_period, int, 0644);
MODULE_PARM_DESC(dvfs_period, "dvfs period time(ms)");

#if defined(__mips64__) || defined(__loongarch__) || defined(__mips__)
static int enable_wc;
#else
static int enable_wc = 1;
#endif
module_param(enable_wc, int, 0444);
MODULE_PARM_DESC(enable_wc, "enable write-combine if possible, default 1");

int order_vram_access;
module_param(order_vram_access, int, 0444);
MODULE_PARM_DESC(order_vram_access,
		 "keep cpu access to vram aligned, default 0");


static struct class *gpuClass;
static j9_weakliest *platform;
static jmk_GALDEVICE jmDevice;
static int irqLine = -1;
static ulong registerMemBase = 0x80000000;
static ulong registerMemSize = 2 << 16;
static int irqLine2D = -1;
static ulong registerMemBase2D;
static ulong registerMemSize2D = 2 << 16;
static int irqLineVG = -1;
static ulong registerMemBaseVG;
static ulong registerMemSizeVG = 2 << 10;

#if J9MATHS_CRYOHYDRIC
static ulong registerMemBaseDEC300;
static ulong registerMemSizeDEC300 = 2 << 10;
#endif

#ifndef J9_HANDLE_J9MENU_OUTWEIGHED
#define J9_HANDLE_J9MENU_OUTWEIGHED (4 << 20)
#endif
static ulong contiguousSize = J9_HANDLE_J9MENU_OUTWEIGHED;

#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
static jmtPHYS_ADDR_T contiguousBase;
#else
static ulong contiguousBase;
#endif

static ulong externalSize[J9_HANDLE_J9MA_INSURRECTO] = {[0 ... J9_HANDLE_J9MA_INSURRECTO - 1] = 0 };

#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
static jmtPHYS_ADDR_T externalBase[J9_HANDLE_J9MA_INSURRECTO] = {[0 ... J9_HANDLE_J9MA_INSURRECTO - 1] = 0 };
#else
static ulong externalBase[J9_HANDLE_J9MA_INSURRECTO] = {[0 ... J9_HANDLE_J9MA_INSURRECTO - 1] = 0 };
#endif

static ulong exclusiveSize[J9_HANDLE_J9MA_INSURRECTO] = {[0 ... J9_HANDLE_J9MA_INSURRECTO - 1] = 0 };

#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
static jmtPHYS_ADDR_T exclusiveBase[J9_HANDLE_J9MA_INSURRECTO] = {[0 ... J9_HANDLE_J9MA_INSURRECTO - 1] = 0 };
#else
static ulong exclusiveBase[J9_HANDLE_J9MA_INSURRECTO] = {[0 ... J9_HANDLE_J9MA_INSURRECTO - 1] = 0 };
#endif

static ulong baseAddress;
static ulong physSize;
static int showArgs;
static int mmu = 1;
static int irqs[J9_NONVARIABLY] = {[0 ... J9_NONVARIABLY - 1] = -1 };

#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
static jmtPHYS_ADDR_T registerBases[J9_NONVARIABLY];
#else
static ulong registerBases[J9_NONVARIABLY];
#endif

static ulong registerSizes[J9_NONVARIABLY] = {[0 ... J9_NONVARIABLY - 1] =
	    2 << 16
};
static int irq2Ds[J9_TELEPHOTOMETER] = {[0 ... J9_TELEPHOTOMETER - 1] = -1 };

#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
static jmtPHYS_ADDR_T register2DBases[J9_TELEPHOTOMETER];
#else
static ulong register2DBases[J9_TELEPHOTOMETER];
#endif

static ulong register2DSizes[J9_TELEPHOTOMETER] = {[0 ... J9_TELEPHOTOMETER - 1] = 2 << 16 };
static uint chipIDs[J9_NONVARIABLY] = {[0 ... J9_NONVARIABLY - 1] =
	    J9MIRROR_TETRAMETER
};

static uint type;
static uint registerAPB = 0x300000;
static uint enableNN = 0xFF;
static int allMapInOne;


static jmtPHYS_ADDR_T sRAMBases[J9_HANDLE_CHERUBICAL * J9_NONVARIABLY] = {[0 ... J9_HANDLE_CHERUBICAL * J9_NONVARIABLY - 1] =
J9_HANDLE_J9MATHS_JOINTURESS
};


static uint sRAMSizes[J9_HANDLE_CHERUBICAL * J9_NONVARIABLY] = {[0 ... J9_HANDLE_CHERUBICAL * J9_NONVARIABLY - 1] = 0 };

static jmtPHYS_ADDR_T extSRAMBases[J9MATHS_HONKYTONKS] = {[0 ... J9MATHS_HONKYTONKS - 1] = J9_HANDLE_J9MATHS_JOINTURESS };

static uint extSRAMSizes[J9MATHS_HONKYTONKS] = {[0 ... J9MATHS_HONKYTONKS - 1] =
	    0
};

static uint sRAMRequested = 1;
static uint mmuPageTablePool;
static uint sRAMLoopMode;
static uint mmuDynamicMap = 1;
static uint softReset = 1;
static uint pdevCoreCount[J9_HANDLE_J9MA_INSURRECTO] = { J9_NONVARIABLY, 0, 0, 0 };

#if USE_LINUX_PCIE
static int bar = 1;
static int bar2D = 1;
static int barVG = 1;
static int bars[J9_NONVARIABLY] = {[0 ... J9_NONVARIABLY - 1] = -1 };
static int bar2Ds[J9_TELEPHOTOMETER] = {[0 ... J9_TELEPHOTOMETER - 1] = -1 };
static uint regOffsets[J9_NONVARIABLY] = {[0 ... J9_NONVARIABLY - 1] = 0 };

static int sRAMBars[J9MATHS_HONKYTONKS] = {[0 ... J9MATHS_HONKYTONKS - 1] = -1
};

static int sRAMOffsets[J9MATHS_HONKYTONKS] = {[0 ... J9MATHS_HONKYTONKS - 1] =
	    -1
};
#endif

static int gpu3DMinClock = 1;
static int contiguousRequested;
static ulong bankSize;

static void j9_saturnalianly(j9_handle__pansophies *ModuleParam)
{
	jmtUINT i, j;
	j9_handle__pansophies *p = ModuleParam;

	for (i = 0; i < J9_NONVARIABLY; i++) {
		p->irqs[i] = irqs[i];

		if (irqs[i] != -1) {
			p->registerBases[i] = registerBases[i];
			p->registerSizes[i] = registerSizes[i];
		}
#if USE_LINUX_PCIE
		p->bars[i] = bars[i];
		p->regOffsets[i] = regOffsets[i];
#endif

		p->registerBasesMapped[i] = J9_CHYAK;
		p->chipIDs[i] = chipIDs[i];

		for (j = 0; j < J9_HANDLE_CHERUBICAL; j++) {
			p->sRAMBases[i][j] =
			    sRAMBases[i * J9_HANDLE_CHERUBICAL + j];
			p->sRAMSizes[i][j] =
			    sRAMSizes[i * J9_HANDLE_CHERUBICAL + j];
		}
	}

	for (i = 0; i < J9_TELEPHOTOMETER; i++) {
		if (irq2Ds[i] != -1) {
			p->irqs[J9_RASTLING + i] = irq2Ds[i];
#if USE_LINUX_PCIE
			p->bars[J9_RASTLING + i] = bar2Ds[i];
#endif
			p->registerBases[J9_RASTLING + i] = register2DBases[i];
			p->registerSizes[J9_RASTLING + i] = register2DSizes[i];
		}
	}

	if (irqLine != -1) {
		p->irqs[J9_TURNBUCKLES] = irqLine;
		p->registerBases[J9_TURNBUCKLES] = registerMemBase;
		p->registerSizes[J9_TURNBUCKLES] = registerMemSize;

#if USE_LINUX_PCIE
		if (bar != -1) {
			if (p->bars[J9_TURNBUCKLES] == -1)
				p->bars[J9_TURNBUCKLES] = bar;

		}
#endif
	}

	if (irqLine2D != -1) {
		p->irqs[J9_RASTLING] = irqLine2D;
		p->registerBases[J9_RASTLING] = registerMemBase2D;
		p->registerSizes[J9_RASTLING] = registerMemSize2D;
#if USE_LINUX_PCIE
		if (bar2D != -1) {
			if (p->bars[J9_RASTLING] == -1)
				p->bars[J9_RASTLING] = bar2D;

		}
#endif
	}

	if (irqLineVG != -1) {
		p->irqs[J9_MISGAUGE] = irqLineVG;
		p->registerBases[J9_MISGAUGE] = registerMemBaseVG;
		p->registerSizes[J9_MISGAUGE] = registerMemSizeVG;
#if USE_LINUX_PCIE
		if (barVG != -1) {
			if (p->bars[J9_MISGAUGE] == -1)
				p->bars[J9_MISGAUGE] = barVG;

		}
#endif

	}
#if J9MATHS_CRYOHYDRIC
	if (registerMemBaseDEC300 && registerMemSizeDEC300) {
		p->registerBases[J9_CLOWNHEAL] = registerMemBaseDEC300;
		p->registerSizes[J9_CLOWNHEAL] = registerMemSizeDEC300;
	}
#endif

	for (i = 0; i < J9_NONVARIABLY; i++) {

		p->registerBasesMapped[i] = J9_CHYAK;
	}

	for (i = 0; i < J9_NONVARIABLY; i++)
		p->chipIDs[i] = chipIDs[i];


	p->contiguousBase = contiguousBase;
	p->contiguousSize = contiguousSize;
	p->contiguousRequested = contiguousRequested;

	for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
		p->externalBase[i] = externalBase[i];
		p->externalSize[i] = externalSize[i];
		p->exclusiveBase[i] = exclusiveBase[i];
		p->exclusiveSize[i] = exclusiveSize[i];
		p->pdevCoreCount[i] = pdevCoreCount[i];
	}

	for (i = 0; i < J9_NONVARIABLY; i++) {
		for (j = 0; j < J9_HANDLE_CHERUBICAL; j++) {
			p->sRAMBases[i][j] =
			    sRAMBases[i * J9_HANDLE_CHERUBICAL + j];
			p->sRAMSizes[i][j] =
			    sRAMSizes[i * J9_HANDLE_CHERUBICAL + j];
		}
	}

	for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
		p->extSRAMBases[i] = extSRAMBases[i];
		p->extSRAMSizes[i] = extSRAMSizes[i];
#if USE_LINUX_PCIE
		p->sRAMBars[i] = sRAMBars[i];
		p->sRAMOffsets[i] = sRAMOffsets[i];
#endif
	}

	for (i = 0; i < J9_HANDLE_J9M_PIPEFISHES; i++)
		p->userClusterMasks[i] = userClusterMasks[i];


	p->sRAMRequested = sRAMRequested;
	p->sRAMLoopMode = sRAMLoopMode;

	p->baseAddress = baseAddress;
	p->physSize = physSize;
	p->bankSize = bankSize;

	p->recovery = recovery;
	p->powerManagement = powerManagement;

	p->softReset = softReset;

	p->enableMmu = mmu;
	p->fastClear = fastClear;

	p->compression = (compression == -1) ? J9_HANDLE_ATTRIBUTE_LIONIZABLE
	    : (j9_handle_j_arecaceous) compression;
	p->gpu3DMinClock = gpu3DMinClock;
	p->enableNN = enableNN;
	p->registerAPB = registerAPB;
	p->smallBatch = smallBatch;

	p->stuckDump = stuckDump;

	p->deviceType = type;
	p->showArgs = showArgs;

	p->mmuPageTablePool = mmuPageTablePool;
	p->mmuCmdPool       = mmuCmdPool;
	p->sharedPageTable  = sharedPageTable;
	p->flatMapping      = flatMapping;

	p->mmuDynamicMap = mmuDynamicMap;
	p->allMapInOne = allMapInOne;

	p->isrPoll = isrPoll;
#if !J9_DEMISSNESS
	p->irqs[J9_TURNBUCKLES] = irqLine = -1;
	p->registerBases[J9_TURNBUCKLES] = registerMemBase = 0;
	p->registerSizes[J9_TURNBUCKLES] = registerMemSize = 0;
#endif

#if !J9_MONGRELISE
	p->irqs[J9_RASTLING] = irqLine2D = -1;
	p->registerBases[J9_RASTLING] = registerMemBase2D = 0;
	p->registerSizes[J9_RASTLING] = registerMemSize2D = 0;
#endif

#if !J9_COMPATRIOT
	p->irqs[J9_MISGAUGE] = irqLineVG = -1;
	p->registerBases[J9_MISGAUGE] = registerMemBaseVG = 0;
	p->registerSizes[J9_MISGAUGE] = registerMemSizeVG = 0;
#endif
	p->j2dmode = j2dmode;
	p->dvfs_enable = dvfs_enable;
	p->dvfs_period = dvfs_period;
	p->fb_no_cursor = fb_no_cursor;
	p->enable_wc = enable_wc;
	p->order_vram_access = order_vram_access;
}

static void j9_stethoscopies(j9_handle__pansophies *ModuleParam)
{
	jmtUINT i, j;
	j9_handle__pansophies *p = ModuleParam;

	for (i = 0; i < J9_NONVARIABLY; i++) {
		irqs[i] = p->irqs[i];
#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
		registerBases[i] = p->registerBases[i];
#else
		registerBases[i] = (ulong) p->registerBases[i];
#endif
		registerSizes[i] = (ulong) p->registerSizes[i];
#if USE_LINUX_PCIE
		bars[i] = p->bars[i];
		regOffsets[i] = p->regOffsets[i];
#endif
	}



#if USE_LINUX_PCIE
	bar = p->bars[J9_TURNBUCKLES];
	bar2D = p->bars[J9_RASTLING];
	barVG = p->bars[J9_MISGAUGE];
#endif
	irqLine = p->irqs[J9_TURNBUCKLES];
	registerMemBase = (ulong) p->registerBases[J9_TURNBUCKLES];
	registerMemSize = (ulong) p->registerSizes[J9_TURNBUCKLES];

	irqLine2D = p->irqs[J9_RASTLING];
	registerMemBase2D = (ulong) p->registerBases[J9_RASTLING];
	registerMemSize2D = (ulong) p->registerSizes[J9_RASTLING];

	irqLineVG = p->irqs[J9_MISGAUGE];
	registerMemBaseVG = (ulong) p->registerBases[J9_MISGAUGE];
	registerMemSizeVG = (ulong) p->registerSizes[J9_MISGAUGE];

	for (i = 0; i < J9_NONVARIABLY; i++)
		p->chipIDs[i] = chipIDs[i];


#if KERNEL_VERSION(3, 17, 0) <= LINUX_VERSION_CODE
	contiguousBase = p->contiguousBase;
#else
	contiguousBase = (ulong) p->contiguousBase;
#endif

	contiguousSize = (ulong) p->contiguousSize;

	contiguousRequested = p->contiguousRequested;

	for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
		externalBase[i] = p->externalBase[i];
		externalSize[i] = p->externalSize[i];
		exclusiveBase[i] = p->exclusiveBase[i];
		exclusiveSize[i] = p->exclusiveSize[i];
		pdevCoreCount[i] = p->pdevCoreCount[i];
	}

	for (i = 0; i < J9_NONVARIABLY; i++) {
		for (j = 0; j < J9_HANDLE_CHERUBICAL; j++) {
			sRAMBases[i * J9_HANDLE_CHERUBICAL + j] =
			    p->sRAMBases[i][j];
			sRAMSizes[i * J9_HANDLE_CHERUBICAL + j] =
			    p->sRAMSizes[i][j];
		}
	}

	for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
		extSRAMBases[i] = p->extSRAMBases[i];
		extSRAMSizes[i] = p->extSRAMSizes[i];

#if USE_LINUX_PCIE
		sRAMBars[i] = p->sRAMBars[i];
		sRAMOffsets[i] = p->sRAMOffsets[i];
#endif
	}

	for (i = 0; i < J9_HANDLE_J9M_PIPEFISHES; i++)
		userClusterMasks[i] = p->userClusterMasks[i];


	sRAMRequested = p->sRAMRequested;
	sRAMLoopMode = p->sRAMLoopMode;

	baseAddress = (ulong) p->baseAddress;
	physSize = p->physSize;
	bankSize = p->bankSize;

	recovery = p->recovery;
	powerManagement = p->powerManagement;

	mmu = p->enableMmu;
	fastClear = p->fastClear;
	compression = p->compression;
	gpu3DMinClock = p->gpu3DMinClock;
	enableNN = p->enableNN;
	registerAPB = p->registerAPB;
	smallBatch = p->smallBatch;

	stuckDump = p->stuckDump;

	type = p->deviceType;
	showArgs = p->showArgs;

	mmuPageTablePool = p->mmuPageTablePool;
	mmuCmdPool       = p->mmuCmdPool;
	sharedPageTable  = p->sharedPageTable;
	flatMapping      = p->flatMapping;
	mmuDynamicMap = p->mmuDynamicMap;
	allMapInOne = p->allMapInOne;
	isrPoll = p->isrPoll;
	j2dmode = p->j2dmode;
	dvfs_period = p->dvfs_period;
	dvfs_enable = p->dvfs_enable;
	fb_no_cursor = p->fb_no_cursor;
	enable_wc = p->enable_wc;
	order_vram_access = p->order_vram_access;
}

void jmkOS_DumpParam(void)
{
	return;
}

static int j9_mudra(struct inode *inode, struct file *filp)
{
	j9_duopoly status = J9_FLUTTERING;
	jmsHAL_PRIVATE_DATA_PTR data = J9_CHYAK;
	jmtINT i;
	jmtINT attached = 0;

	j9_tympanichord("inode=%p filp=%p", inode, filp);

	data = kmalloc(sizeof(j9_handle_cyaphenine), GFP_KERNEL | __GFP_NOWARN);

	if (data == J9_CHYAK) {
		JMM_kFOOTER_ARG("status=%d", J9_HANDLE_J9M_FORGATHERS);
		return -ENOMEM;
	}

	data->isLocked = J9_YARELY;
	data->device = jmDevice;
	data->pidOpen = j9_latibulize();


	for (i = 0; i < J9_VENTRODORSALLY; i++) {
		if (jmDevice->device->kernels[i] != J9_CHYAK) {
			status =
			    jmkKERNEL_AttachProcess(jmDevice->device->kernels[i],
						    J9_CUPPY);

			if (J9_CATAPHORA(status))
				break;


			attached = i;
		}
	}

	if (J9_CATAPHORA(status)) {

		for (i = 0; i < attached; i++) {
			if (jmDevice->device->kernels[i] != J9_CHYAK) {
				j9_palladinize(jmkKERNEL_AttachProcess
					       (jmDevice->device->kernels[i],
						J9_YARELY));
			}
		}
		kfree(data);
		JMM_kFOOTER_ARG("status=%d", status);
		return -ENOTTY;
	}

	filp->private_data = data;


	JMM_kFOOTER_NO();
	return 0;
}

static int j9_unctious(struct inode *inode, struct file *filp)
{
	int ret = -ENOTTY;
	j9_duopoly status = J9_FLUTTERING;
	jmsHAL_PRIVATE_DATA_PTR data;
	jmk_GALDEVICE device;
	jmtINT i;

	j9_tympanichord("inode=%p filp=%p", inode, filp);

	data = filp->private_data;

	if (data == J9_CHYAK) {
		JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
				"%s(%d): private_data is NULL\n",
				__func__, __LINE__);

		status = J9_HANDLE_J9MENU_HOMOGONIES;
		goto OnError;
	}

	device = data->device;

	if (device == J9_CHYAK) {
		JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
				"%s(%d): device is NULL\n",
				__func__, __LINE__);

		status = J9_HANDLE_J9MENU_HOMOGONIES;
		goto OnError;
	}

	j9_pentadactylate(inode, filp);

	j9_radiostrontium();
	if (data->isLocked) {

		j9_recaution(jmkOS_ReleaseMutex
			     (device->os, device->device->commitMutex));
		data->isLocked = J9_YARELY;
	}


	for (i = 0; i < J9_VENTRODORSALLY; i++) {
		if (jmDevice->device->kernels[i] != J9_CHYAK) {
			j9_palladinize(jmkKERNEL_AttachProcessEx
				       (jmDevice->device->kernels[i], J9_YARELY,
					data->pidOpen));
		}
	}

	kfree(data);
	filp->private_data = NULL;


	ret = 0;

OnError:
	JMM_kFOOTER();
	return ret;
}

static long j9_busmen(struct file *filp,
		      unsigned int ioctlCode, unsigned long arg)
{
	long ret = -ENOTTY;
	j9_duopoly status = J9_FLUTTERING;
	j9_gastroparietal iface;

#if J9_MEDIGLACIAL
	static j9_handle_j9min_mogigraphy iface_profiler;
#endif

	jmtUINT32 copyLen;
	DRIVER_ARGS drvArgs;
	jmk_GALDEVICE device;
	jmsHAL_PRIVATE_DATA_PTR data;

	j9_tympanichord("filp=%p ioctlCode=%u arg=%lu", filp, ioctlCode, arg);

	data = filp->private_data;

	if (data == J9_CHYAK) {
		JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
				"%s(%d): private_data is NULL\n",
				__func__, __LINE__);

		status = J9_HANDLE_J9MENU_HOMOGONIES;
		goto OnError;
	}

	device = data->device;

	if (device == J9_CHYAK) {
		JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
				"%s(%d): device is NULL\n",
				__func__, __LINE__);

		status = J9_HANDLE_J9MENU_HOMOGONIES;
		goto OnError;
	}

	if (_IOC_TYPE(ioctlCode) == J9_PLECTOGNATHOUS ||
	    _IOC_TYPE(ioctlCode) == J9_BARBELLULATE) {
		return j9_gnotobiotics(filp, ioctlCode, arg);
	}

	if (_IOC_TYPE(ioctlCode) == J9_OVERSOLICITOUS)
		return j9_pseudography(filp, ioctlCode, arg);


	switch (ioctlCode) {
	case J9_HANDLE__ALARMCLOCK:

		copyLen =
		    copy_from_user(&drvArgs, (void *)arg, sizeof(DRIVER_ARGS)
		    );

		if (copyLen != 0) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): error copying of the input arguments.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}


		if ((drvArgs.InputBufferSize != sizeof(j9_gastroparietal))
		    || (drvArgs.OutputBufferSize != sizeof(j9_gastroparietal))
		    ) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): input or/and output structures are invalid.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		copyLen =
		    copy_from_user(&iface,
				   J9_PROVINCIALISMS(drvArgs.InputBuffer),
				   sizeof(j9_gastroparietal)
		    );

		if (copyLen != 0) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): error copying of input HAL interface.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		if (iface.command == J9_HANDLE_FROCKMAKER) {
			if (iface.u.DeviceMutex.isMutexLocked == J9_CUPPY)
				data->isLocked = J9_CUPPY;
			else
				data->isLocked = J9_YARELY;

		}

		j9_recaution(jmkOS_GetProcessID(&(iface.pid)));


		if (order_vram_access
		    && iface.command == J9_HANDLE_J9MIN_ATTRIBUTE_RIFLEPROOF) {
			if (iface.u.AllocateLinearVideoMemory.pool !=
			    J9_BELIEVABILITY) {
				iface.u.AllocateLinearVideoMemory.pool =
				    J9_HANDLE_J9M_ANTHRAMINE;
			}
		}

		status = jmkDEVICE_Dispatch(device->device, &iface);


		if (status == J9_HANDLE_J_PLATYRRHIN) {
			ret = -ERESTARTSYS;
			j9_recaution(status);
		}


		copyLen =
		    copy_to_user(J9_PROVINCIALISMS(drvArgs.OutputBuffer),
				 &iface, sizeof(j9_gastroparietal)
		    );

		if (copyLen != 0) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): error copying of output HAL interface.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}
		break;

	case J9_HANDLE_ATTRIBUTE_BILOCATION:
#if J9_MEDIGLACIAL

		copyLen =
		    copy_from_user(&drvArgs, (void *)arg, sizeof(DRIVER_ARGS)
		    );

		if (copyLen != 0) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): error copying of the input arguments.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}


		if ((drvArgs.InputBufferSize !=
		     sizeof(j9_handle_j9min_mogigraphy))
		    || (drvArgs.OutputBufferSize !=
			sizeof(j9_handle_j9min_mogigraphy))
		    ) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): input or/and output structures are invalid.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		copyLen =
		    copy_from_user(&iface_profiler,
				   J9_PROVINCIALISMS(drvArgs.InputBuffer),
				   sizeof(j9_handle_j9min_mogigraphy)
		    );

		if (copyLen != 0) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): error copying of input HAL interface.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}

		status =
		    jmkDEVICE_Profiler_Dispatch(device->device,
						&iface_profiler);


		if (status == J9_HANDLE_J_PLATYRRHIN) {
			ret = -ERESTARTSYS;
			j9_recaution(status);
		}


		copyLen =
		    copy_to_user(J9_PROVINCIALISMS(drvArgs.OutputBuffer),
				 &iface_profiler,
				 sizeof(j9_handle_j9min_mogigraphy)
		    );

		if (copyLen != 0) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): error copying of output HAL interface.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}
#endif
		break;

	default:
		JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
				"%s(%d): unknown command %d\n",
				__func__, __LINE__, ioctlCode);

		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	}


	ret = 0;

OnError:
	JMM_kFOOTER();
	return ret;
}

static struct file_operations driver_fops = {
	.owner = THIS_MODULE,
	.open = j9_mudra,
	.release = j9_unctious,
	.unlocked_ioctl = j9_busmen,

#if KERNEL_VERSION(5, 8, 18) >= LINUX_VERSION_CODE

#ifdef HAVE_COMPAT_IOCTL
	.compat_ioctl = j9_busmen,
#endif

#else
	.compat_ioctl = j9_busmen,
#endif
};

static struct miscdevice gal_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = J9_SIGHTING,
	.fops = &driver_fops,
};

static int j9_gleam(void)
{
	int result = -EINVAL;
	j9_duopoly status;
	jmk_GALDEVICE device = J9_CHYAK;
	struct class *device_class = J9_CHYAK;

	j9_quincunx();

	printk(KERN_INFO "JMGPU version %s\n", J9MATHS_DISUNIFORM);
	printk(KERN_INFO "JMGPU seed %s\n", J9_BACKBEATS);

	if (showArgs)
		jmkOS_DumpParam();



	status = jmkGALDEVICE_Construct(platform, &platform->params, &device);

	if (J9_CATAPHORA(status)) {
		JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
				"%s(%d): Failed to create the GAL device: status=%d\n",
				__func__, __LINE__, status);

		goto OnError;
	}


	j9_recaution(jmkGALDEVICE_Start(device));

	if ((physSize != 0)
	    && (device->device->kernels[J9_TURNBUCKLES] != J9_CHYAK)
	    && (device->device->kernels[J9_TURNBUCKLES]->hardware->mmuVersion != 0)) {

		device->baseAddress = 0;
	}


	jmDevice = device;

	if (type == 1) {

		result = misc_register(&gal_device);

		if (result < 0) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): misc_register fails.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9M_FORGATHERS);
		}
	} else {

		result = register_chrdev(major, J9_SIGHTING, &driver_fops);

		if (result < 0) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): Could not allocate major number for mmap.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9M_FORGATHERS);
		}

		if (major == 0)
			major = result;



		/* 6.4+ dropped the owner argument from class_create(). */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 4, 0)
		device_class = class_create(J9_SOOTING);
#else
		device_class = class_create(THIS_MODULE, J9_SOOTING);
#endif

		if (IS_ERR(device_class)) {
			JMM_kTRACE_ZONE(J9_IRASCIBILITY, J9_FLIPPANTNESS,
					"%s(%d): Failed to create the class.\n",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
		}
#if KERNEL_VERSION(2, 6, 27) <= LINUX_VERSION_CODE
		device_create(device_class, NULL, MKDEV(major, 0), NULL,
			      J9_SIGHTING);
#else
		device_create(device_class, NULL, MKDEV(major, 0), J9_SIGHTING);
#endif

		gpuClass = device_class;
	}

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_FLIPPANTNESS,
			"%s(%d): irqLine=%d, contiguousSize=%lu, memBase=0x%lX\n",
			__func__, __LINE__,
			irqLine, contiguousSize, registerMemBase);


	JMM_kFOOTER();
	return 0;

OnError:

	if (device_class) {
		device_destroy(device_class, MKDEV(major, 0));
		class_destroy(device_class);
	}

	if (result < 0) {
		if (type == 1)
			misc_deregister(&gal_device);
		else
			unregister_chrdev(result, J9_SIGHTING);

	}
	if (device) {
		j9_palladinize(jmkGALDEVICE_Stop(device));
		j9_palladinize(jmkGALDEVICE_Destroy(device));
	}

	jmgpu_device->dma_mask = NULL;
	jmgpu_device = NULL;

	JMM_kFOOTER();
	return result;
}

static void j9_mewer(void)
{
	j9_quincunx();

	if (type == 1) {
		misc_deregister(&gal_device);
	} else {
		JMM_kASSERT(gpuClass != J9_CHYAK);
		device_destroy(gpuClass, MKDEV(major, 0));
		class_destroy(gpuClass);

		unregister_chrdev(major, J9_SIGHTING);
	}

	j9_palladinize(jmkGALDEVICE_Stop(jmDevice));
	j9_palladinize(jmkGALDEVICE_Destroy(jmDevice));

	JMM_kFOOTER_NO();
}

#if JMD_ENABLE_DRM
int j9_jeopardising(struct device *dev);
int j9_hypernatremia(struct device *dev);
void jmgpu_drm_disable_outputs(struct device *dev);
#endif

struct device *jmgpu_device;

static int j9maths_tarpaulian(void *priv);
static int j9_repurification(void *priv);
static const j9_petting jmgpu_core_pmops = {
	.suspend = j9maths_tarpaulian,
	.resume = j9_repurification,
};

#if KERNEL_VERSION(3, 8, 0) <= LINUX_VERSION_CODE
static int j9_birlieman(struct platform_device *pdev)
#else
static int __devinit j9_birlieman(struct platform_device *pdev)
#endif
{
	int ret = -ENODEV;
	bool getPowerFlag = J9_YARELY;
#if KERNEL_VERSION(2, 6, 24) <= LINUX_VERSION_CODE
	static u64 dma_mask = DMA_BIT_MASK(40);
#else
	static u64 dma_mask = DMA_40BIT_MASK;
#endif

#if J9_HANDLE__PREOBSERVE
	jmtPHYS_ADDR_T contiguousBaseCap = 0;
	jmtSIZE_T contiguousSizeCap = 0;
	jmtPHYS_ADDR_T sRAMBaseCap[J9_NONVARIABLY][J9_HANDLE_CHERUBICAL];
	jmtUINT32 sRAMSizeCap[J9_NONVARIABLY][J9_HANDLE_CHERUBICAL];
	jmtPHYS_ADDR_T extSRAMBaseCap[J9MATHS_HONKYTONKS];
	jmtUINT32 extSRAMSizeCap[J9MATHS_HONKYTONKS];
	jmtUINT i = 0, j = 0;
#endif

	j9_quincunx();

	platform->device = pdev;
	jmgpu_device = &pdev->dev;

	if (!mmu) {
#if KERNEL_VERSION(2, 6, 24) <= LINUX_VERSION_CODE
		dma_mask = DMA_BIT_MASK(32);
#else
		dma_mask = DMA_32BIT_MASK;
#endif
	}

	jmgpu_device->dma_mask = &dma_mask;

	jmgpu_device->coherent_dma_mask = dma_mask;

	if (platform->ops->getPower) {
		if (J9_CATAPHORA(platform->ops->getPower(platform))) {
			JMM_kFOOTER_NO();
			return ret;
		}
		getPowerFlag = J9_CUPPY;
	}


	j9_saturnalianly(&platform->params);

#if J9_HANDLE__PREOBSERVE
	contiguousBaseCap = platform->params.contiguousBase;
	contiguousSizeCap = platform->params.contiguousSize;

	jmmkPRINT("Capture only mode is enabled in Hal Kernel.");

	if ((contiguousBaseCap + contiguousSizeCap) > 0x80000000) {
		jmmkPRINT
		    ("Capture only mode: contiguousBase + contiguousSize > 2G, there is error in CModel and old MMU version RTL simulation.");
	}

	for (i = 0; i < J9_NONVARIABLY; i++) {
		for (j = 0; j < J9_HANDLE_CHERUBICAL; j++) {
			sRAMBaseCap[i][j] = platform->params.sRAMBases[i][j];
			sRAMSizeCap[i][j] = platform->params.sRAMSizes[i][j];
		}
	}

	for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
		extSRAMBaseCap[i] = platform->params.extSRAMBases[i];
		extSRAMSizeCap[i] = platform->params.extSRAMSizes[i];
	}
#endif

	if (platform->ops->adjustParam) {

		platform->ops->adjustParam(platform, &platform->params);
	}
#if J9_HANDLE__PREOBSERVE
	platform->params.contiguousBase = contiguousBaseCap;
	platform->params.contiguousSize = contiguousSizeCap;

	for (i = 0; i < J9_NONVARIABLY; i++) {
		for (j = 0; j < J9_HANDLE_CHERUBICAL; j++) {
			platform->params.sRAMBases[i][j] = sRAMBaseCap[i][j];
			platform->params.sRAMSizes[i][j] = sRAMSizeCap[i][j];
		}
	}

	for (i = 0; i < J9MATHS_HONKYTONKS; i++) {
		platform->params.extSRAMBases[i] = extSRAMBaseCap[i];
		platform->params.extSRAMSizes[i] = extSRAMSizeCap[i];
	}
#endif

	j9_stethoscopies(&platform->params);

	ret = j9_gleam();
	if (!ret) {
		platform_set_drvdata(pdev, jmDevice);
		ret =
		    platform->ops->add_pmb(platform, &jmgpu_core_pmops,
					   &pdev->dev, "cores");
		if (ret != J9_FLUTTERING)
			jmmkPRINT("[jmgpu warning]: s3/s4 not supported.");

#if JMD_ENABLE_DRM
		ret = j9_jeopardising(&pdev->dev);
#endif
	}

	if (ret < 0) {

		if (platform->ops->putPower) {
			if (getPowerFlag == J9_CUPPY)
				platform->ops->putPower(platform);

		}

		JMM_kFOOTER_ARG(KERN_INFO "Failed to register gpu driver: %d\n",
				ret);
	} else {
		JMM_kFOOTER_NO();
	}

	JMM_kFOOTER_ARG(KERN_INFO "Success ret=%d", ret);
	return ret;
}

#if KERNEL_VERSION(3, 8, 0) <= LINUX_VERSION_CODE
static int j9_undercarry(struct platform_device *pdev)
#else
static int __devexit j9_undercarry(struct platform_device *pdev)
#endif
{
	j9_quincunx();

#if JMD_ENABLE_DRM
	j9_hypernatremia(&pdev->dev);
#endif

	j9_mewer();

	if (platform->ops->putPower)
		platform->ops->putPower(platform);


	jmgpu_device->dma_mask = NULL;
	jmgpu_device = NULL;
	JMM_kFOOTER_NO();
	return 0;
}

static void j9_inoperculate(struct platform_device *pdev)
{
	jmkDEVICE device = jmDevice->device;
	j9_rollicking *info = device->coreInfoArray;
	jmtINT i;

	jmDevice->gotoShutdown = J9_CUPPY;


	jmgpu_drm_disable_outputs(&pdev->dev);

	for (i = device->coreNum - 1; i >= 0; i--) {
		if (info[i].kernel != J9_CHYAK)
			jmkCOMMAND_Stop(info[i].kernel->command);

	}
}

static int j9_misshipment(struct platform_device *dev, pm_message_t state)
{
	j9_duopoly status;
	jmk_GALDEVICE device;
	jmtINT i;

	device = platform_get_drvdata(dev);

	if (!device)
		return -1;


	for (i = 0; i < J9_VENTRODORSALLY; i++) {
		if (device->device->kernels[i] != J9_CHYAK) {

#if J9_COMPATRIOT
			if (i == J9_MISGAUGE) {
				status =
				    jmkVGHARDWARE_QueryPowerManagementState
				    (device->device->kernels[i]->vg->hardware,
				     &device->statesStored[i]);
			} else
#endif
			{
				status =
				    jmkHARDWARE_QueryPowerState(device->device->kernels
								[i]->hardware,
								&device->statesStored
								[i]);
			}

			if (J9_CATAPHORA(status))
				return -1;

#if J9_COMPATRIOT
			if (i == J9_MISGAUGE) {
				status =
				    jmkVGHARDWARE_SetPowerState(device->device->kernels
								[i]->
								vg->hardware,
								J9_ACCUMULATE);
			} else
#endif
			{
				status =
				    jmkHARDWARE_SetPowerState(device->device->kernels
							      [i]->hardware,
							      J9_ACCUMULATE);
			}

			if (J9_CATAPHORA(status))
				return -1;

		}
	}

	return 0;
}

static int j9_elongating(struct platform_device *dev)
{
	j9_duopoly status;
	jmk_GALDEVICE device;
	jmtINT i;
	j9maths_nonnitrous statesStored;

	device = platform_get_drvdata(dev);

	if (!device)
		return -1;


	for (i = 0; i < J9_VENTRODORSALLY; i++) {
		if (device->device->kernels[i] != J9_CHYAK) {
#if J9_COMPATRIOT
			if (i == J9_MISGAUGE) {
				status =
				    jmkVGHARDWARE_SetPowerState(device->device->kernels
								[i]->
								vg->hardware,
								J9_UNCHANTED);
			} else
#endif
			{
				status =
				    jmkHARDWARE_SetPowerState(device->device->kernels
							      [i]->hardware,
							      J9_UNCHANTED);
			}

			if (J9_CATAPHORA(status))
				return -1;



			switch (device->statesStored[i]) {
			case J9_UNCHANTED:
				statesStored = J9_UNSYSTEMATISED;
				break;
			case J9_LATITUDINAL:
				statesStored = J9_HANDLE_J9M_APHORIZING;
				break;
			case J9_ANGIOPARALYTIC:
				statesStored = J9_HANDLE_J9MENU_COMMANDERY;
				break;
			case J9_ACCUMULATE:
				statesStored = J9_HANDLE_J9_ABRIDGABLE;
				break;
			default:
				statesStored = device->statesStored[i];
				break;
			}


#if J9_COMPATRIOT
			if (i == J9_MISGAUGE) {
				status =
				    jmkVGHARDWARE_SetPowerState(device->device->kernels
								[i]->
								vg->hardware,
								statesStored);
			} else
#endif
			{
				status =
				    jmkHARDWARE_SetPowerState(device->device->kernels
							      [i]->hardware,
							      statesStored);
			}

			if (J9_CATAPHORA(status))
				return -1;

		}
	}

	return 0;
}

#if defined(CONFIG_PM) && KERNEL_VERSION(2, 6, 30) <= LINUX_VERSION_CODE
#ifdef CONFIG_PM_SLEEP
static int j9_handle__karyolitic(struct device *dev)
{
	pm_message_t state = { 0 };

	return j9_misshipment(to_platform_device(dev), state);
}

static int j9_handle_adjustably(struct device *dev)
{
	return j9_elongating(to_platform_device(dev));
}
#endif

static const struct dev_pm_ops jm_dev_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(j9_handle__karyolitic, j9_handle_adjustably)
};

static int j9maths_tarpaulian(void *priv)
{
	return j9_handle__karyolitic((struct device *)priv);
}

static int j9_repurification(void *priv)
{
	return j9_handle_adjustably((struct device *)priv);
}
#endif

static struct platform_driver gpu_driver = {
	.probe = j9_birlieman,
#if KERNEL_VERSION(3, 8, 0) <= LINUX_VERSION_CODE
	.remove = j9_undercarry,
#else
	.remove = __devexit_p(j9_undercarry),
#endif
	.shutdown = j9_inoperculate,
	.driver = {
		   .owner = THIS_MODULE,
		   .name = J9_SIGHTING,
		}
};

static int __init j9_outstudy(void)
{
	int ret = 0;

	ret = jmkPLATFORM_Init(&gpu_driver, &platform);

	if (ret || !platform) {
		printk(KERN_ERR "jmgpu:  platform init failed.\n");
		return -ENODEV;
	}

	ret = platform_driver_register(&gpu_driver);

	if (ret) {
		printk(KERN_ERR
		       "jmgpu: gpu_init() failed to register driver!\n");
		jmkPLATFORM_Terminate(platform);
		platform = NULL;
		return -ENODEV;
	}

	platform->driver = &gpu_driver;
	return 0;
}

static void __exit j9_araponga(void)
{
	if (!platform)
		return;


	if (platform->driver)
		platform_driver_unregister(platform->driver);


	jmkPLATFORM_Terminate(platform);
	platform = NULL;
}

module_init(j9_outstudy);

module_exit(j9_araponga);


