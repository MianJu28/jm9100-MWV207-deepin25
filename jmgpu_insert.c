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


#include <linux/version.h>
#include <linux/moduleparam.h>
#include <linux/pci_regs.h>
#include <linux/kref.h>
#include <linux/fb.h>
#include <drm/drm_vma_manager.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 0, 0)
#include <drm/drm_aperture.h>
#endif
#include <linux/pm.h>
#include <linux/delay.h>
#include <linux/vgaarb.h>
#ifdef __aarch64__
#include <asm/cputype.h>
#endif
#include "jmgpu_scheduler.h"
#include "jmgpu_remote.h"
#include "jmgpu_enc.h"
#include "jmgpu_scroll.h"
#include "jmgpu_software.h"
#include "jmgpu_framework.h"
#include "jmgpu_livelock.h"
#include "mwv207_update.h"
#include "mwv207_method.h"
#include "jmgpu_forward.h"
#include "jmgpu_hypertext.h"
#include "jmgpu_repeat.h"
#include "jmgpu_setfont.h"
#include "jmgpu_unchecked.h"
#include "mwv207reg_procedure.h"
#include "jmgpu_nemyry.h"

extern uint flatMapping;

static char *cfg_file;
module_param(cfg_file, charp, 0444);
MODULE_PARM_DESC(cfg_file,
		 "use /lib/firmware/'cfg_file' if available, default to 'mwv207config.bin' if file not found.");

static ulong vram_space_limit;
module_param(vram_space_limit, ulong, 0644);
MODULE_PARM_DESC(vram_space_limit,
		 "set limit for vram space, default 0, no limit");


#define J9_HANDLE_J_CABALASSOU    0x10EE
#define J9_HANDLE_PRINCIPIUM      0x8018
#define J9_HANDLE_ARROWSTONE      0x10EE
#define J9MATHS_SCAPULETTE        0x8019
#define J9_HANDLE_J9M_INCOMMIXED  0xFF

#define J9MIRROR_CUSHEWBIRD       0xd10000
#define J9MIRROR_DERMATAGRA       0x20

#define J9_HANDLE_J9M_ACTIVATION  0xA000

#define J9_UNIMPAIRABLE           0x800

#define J9MIRROR_CURELESSLY       0xB880
#define J9_PRAISABLENESS          16

#define J9MIRROR_EMMENOLOGY    4
#define J9_HANDLE_PLANIMETRY   2

extern struct drm_driver jm_drm_driver;
extern struct drm_driver jmgpu_drm_driver;
struct j9_handle_peripteros jmgpu_hd_dev;

#ifndef J9_THERMOTICALLY
#define J9_THERMOTICALLY 6
#endif

static inline jmtPHYS_ADDR_T jmgpu_vram_iatu_offset(j9_gearshifts *ppcie_info)
{
	return roundup(J9_HANDLE_J9M_TRIPSOMELY, ppcie_info->mem0bar.size)
		- J9_HANDLE_J9M_TRIPSOMELY;
}

#ifdef NEOKYLIN50
#define PCI_IRQ_LEGACY		(1 << 0)
#define PCI_IRQ_MSI		(1 << 1)
int pci_irq_vector(struct pci_dev *dev, unsigned int nr)
{
	return 0;
}

static inline int
pci_alloc_irq_vectors(struct pci_dev *dev, unsigned int min_vecs,
			  unsigned int max_vecs, unsigned int flags)
{
	return 0;
}

void pci_free_irq_vectors(struct pci_dev *dev)
{
}
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0)
#define pci_dbg(pdev, fmt, arg...) dev_dbg(&(pdev)->dev, fmt, ##arg)
#endif

#define J9_ACESODYNE    J9_REINTRENCHED

static j9_precartilage jmgpu_9200_info = {
	.reg3doffsets = 0x00900000,
	.has_3d = { 1, 1, },
	.has_decg1 = { 1, 0 },
	.has_decg2 = { 1, 1 },
	.has_enc = 1,
	.has_mmu = 1,
	.has_gddr = 1,
	.use_intr = 1,
#ifdef NEOKYLIN50
	.use_msi = 0,
#else
	.use_msi = 1,
#endif
	.ops = &mwv207_hw_ops,
	.has_display = 1,
	.has_pll = 1,
	.priv = NULL,
};

static j9_precartilage jmgpu_9100_info = {
	.reg3doffsets = 0x00900000,
	.has_3d = { 1, },
	.has_decg1 = { 1, 0 },
	.has_decg2 = { 1, 0 },
	.has_enc = 0,
	.has_mmu = 1,
	.has_gddr = 0,
	.use_intr = 1,
#ifdef NEOKYLIN50
	.use_msi = 0,
#else
	.use_msi = 1,
#endif
	.ops = &mwv207_hw_ops,
	.has_display = 1,
	.has_pll = 1,
	.priv = NULL,
};

static j9_precartilage jmgpu_9200_fpga_info = {
	.reg3doffsets = 0x00900000,
	.has_3d = { 0, },
	.has_decg1 = { 0, },
	.has_decg2 = { 0, },
	.has_enc = 0,
	.has_mmu = 0,
	.has_gddr = 1,
	.use_intr = 0,
	.use_msi = 1,
	.ops = &mwv207_fpga_ops,
	.has_display = 3,
	.has_pll = 0,
	.priv = NULL,
};

static j9_precartilage jmgpu_9200_haps_info = {
	.reg3doffsets = 0x00900000,
	.has_3d = { 1, },
	.has_decg1 = { 0, },
	.has_decg2 = { 0, },
	.has_enc = 0,
	.has_mmu = 0,
	.has_gddr = 1,
	.use_intr = 1,
	.use_msi = 1,
	.has_display = 3,
	.has_pll = 0,
	.ops = &mwv207_fpga_ops,
	.priv = NULL,
};

#define J9MIRROR_IMMATERIAL(vend, dev, data) \
	.vendor = vend, .device = dev, .driver_data = (kernel_ulong_t)(data), \
	.subvendor = PCI_ANY_ID, .subdevice = PCI_ANY_ID, \
	.class = 0, .class_mask = 0

static const struct pci_device_id jmgpu_pci_ids[] = {
	{ J9MIRROR_IMMATERIAL(0x0731, 0x9100, &jmgpu_9100_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x910a, &jmgpu_9100_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x9200, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x920a, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x920b, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x920c, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x920d, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x9210, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x9211, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x9230, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x9231, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x9250, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x930a, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x930b, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x930c, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(0x0731, 0x930d, &jmgpu_9200_info) },
	{ J9MIRROR_IMMATERIAL(J9_HANDLE_J_CABALASSOU,
				  J9_HANDLE_PRINCIPIUM,
				  &jmgpu_9200_fpga_info) },
	{ J9MIRROR_IMMATERIAL(J9_HANDLE_ARROWSTONE,
				  J9MATHS_SCAPULETTE,
				  &jmgpu_9200_haps_info) },

	{  }
};

MODULE_DEVICE_TABLE(pci, jmgpu_pci_ids);

#define J9_READJUDICATING      0x970000
static u32 j9_handle_j9min_rampacious(j9_weakliest * platform)
{
	u32 data0, data1;
	u32 tmp0, tmp1;

	if (!platform)
		return 0;

	data0 =
		platform->ops->readRegisterRaw(platform,
					   J9_READJUDICATING + 0x4028);
	data1 =
		platform->ops->readRegisterRaw(platform,
					   J9_READJUDICATING + 0x402c);
	tmp0 = (data0 >> 16) & 0xff;
	tmp1 = data1 & 0xff;

	return (2 * ((tmp0 + tmp1) + 8)) * 64 / 8;
}

u8 j9_handle_chockstone(j9_gearshifts *ppcie_info)
{
	if (ppcie_info->pdev->device == J9MATHS_SCAPULETTE)
		return 1;

	return 0;
}

u8 j9_handle_drearihead(j9_gearshifts *ppcie_info)
{
	if (ppcie_info->pdev->device == J9_HANDLE_PRINCIPIUM)
		return 1;

	return 0;
}

static void j9_noninertial(j9_atlantomastoid * pcie_platfrom);
static j9_duopoly
j9maths_unbloodied(IN j9_weakliest * pplatform,
		   OUT j9_handle__pansophies * Args);
static j9_duopoly j9_handle_j_polygamian(IN j9_weakliest * pplatform,
					 IN jmtPHYS_ADDR_T CPUPhysical,
					 OUT jmtPHYS_ADDR_T *GPUPhysical);
static jmtPOINTER j9maths_archivault(IN j9_weakliest * pplatform);
static jmtUINT32 j9_hypophyllous(IN j9_weakliest * pplatform, jmtUINT32 reg);
static void j9_paleethnology(IN j9_weakliest * pplatform, jmtUINT32 reg,
				 jmtUINT32 val);
static j9_duopoly j9_uraniscochasma(IN j9_weakliest * pplatform,
					jmeMEM_ACCESS op, jmtUINT64 memaddr,
					jmtPOINTER pbuf, jmtUINT32 size);
static j9_duopoly j9maths_harbourous(IN j9_weakliest * pplatform, jmtINT32 irq,
					 jmtIRQ_HANDLER handler, const char *name,
					 jmtPOINTER data);
static void j9_resterilized(IN j9_weakliest * pplatform, jmtINT32 irq,
				jmtPOINTER data);
static j9_duopoly j9_hydroquinoline(IN j9_weakliest * pplatform, jmtINT32 irq,
					jmtINT32 enable);
static j9_duopoly j9mirror_crustalogy(j9_weakliest *platform,
					  jmtUINT32 pll_idx, jmtUINT32 freq_khz);
static j9_duopoly j9mirror_nonfascist(j9_weakliest *platform,
					  jmtUINT32 pll_idx, jmtUINT32 *freq_khz);
static j9_duopoly j9_handle_signalling(j9_weakliest *platform,
					   jmtUINT32 volt_mv);
static j9_duopoly j9_handle_antrophose(j9_weakliest *platform,
					   jmtUINT32 *volt_mv);

static j9_duopoly j9_chromatophore(IN j9_weakliest *pplatform,
				   j9_aplobasalt *xfer);
static j9_duopoly j9maths_homogonies(IN jmtPOINTER Object,
					 IN jmtPOINTER Node,
					 IN jmtSIZE_T Offset,
					 IN jmtSIZE_T Bytes, IN jmtUINT32 Reason);
static j9_duopoly
jmgpu_dma_copy(IN jmtPOINTER Object, IN jms_DMA_TRANS_INFO * Info);

static j9_strenuous *j9mirror_drearihead(j9_weakliest *platform, u16 key);
static void j9mirror_chockstone(j9_weakliest *platform, j9_strenuous *item);
static j9_duopoly j9_dauntlessly(j9_weakliest *platform,
				 const j9_petting *ops, jmtPOINTER priv,
				 jmtSTRING name);
static jmtPOINTER _jmgpu_virt_get_ext_mem(j9_weakliest *platform, jmtUINT32 offset);
static bool _jmgpu_mem_check_valid(j9_weakliest *pplatform, jmtPHYS_ADDR_T physical, jmtUINT64 size);

static j9_duopoly j9maths_forehammer(j9_weakliest *platform)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(platform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;

	if (j9_allopathically(ppcie_info))
		return J9_HANDLE_J9MENU_UNEJECTIVE;

	return J9_FLUTTERING;
}

static void j9_handle_j9m_russifying(IN j9_weakliest *platform,
					 IN j9maths_eventuated Operation)
{
	volatile u32 readback;
	int vm_id;


	vm_id = JM_VGPU_GET_ID(platform->params.vinfo);

	if (vm_id == 2) {
		readback = j9_hypophyllous(platform, 0x910004);
	} else {
		readback = j9_hypophyllous(platform, 0x900004);
	}
	mb();
}

static j9_duopoly j9_microphytology(j9_weakliest *platform,
					jmtINT region,
					jmtPHYS_ADDR_T cpubase,
					jmtPHYS_ADDR_T gpubase, jmtSIZE_T size)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(platform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;
	u64 bus_addr;
	int ret;

	if (region < 0 || cpubase < platform->params.slide_window_base
		|| cpubase > platform->params.slide_window_top) {
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}
	bus_addr = pci_bus_address(ppcie_info->pdev, 2);
	bus_addr += cpubase - ppcie_info->mem0bar.base;
	ret = ppcie_info->pinfo->ops->map_region(ppcie_info, region,
						 bus_addr,
						 J9_HANDLE_J9M_TRIPSOMELY +
						 gpubase, size);
	if (ret)
		return J9_HANDLE_J9MIRROR_MARIJUANAS;

	return J9_FLUTTERING;
}

#if J9_HANDLE_REDUNDANCE
j9_duopoly
jmgpu_3d_switch_core_cnt(IN j9_weakliest *platform, OUT jmtUINT32 *Count);
#endif


static jmtBOOL _jmgpu_is_passthrough(j9_weakliest *platform, jmtUINT32 bit)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(platform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;

	return jmgpu_is_passthrough(ppcie_info, bit);
}


static struct tag_jms_PLATFORM_OPERATIONS jmgpu_ops = {
	.adjustParam = j9maths_unbloodied,
	.getGPUPhysical = j9_handle_j_polygamian,
#if 0
	.syncMemory = j9maths_homogonies,
#endif
	.dmaCopy = jmgpu_dma_copy,
	.externalCacheOperation = j9_handle_j9m_russifying,
#if J9_HANDLE_REDUNDANCE
	.switchCoreCount = jmgpu_3d_switch_core_cnt,
#endif
	.getSubDevice = j9maths_archivault,
	.readRegisterRaw = j9_hypophyllous,
	.writeRegisterRaw = j9_paleethnology,
	.memAccessRaw = j9_uraniscochasma,
	.requestIrq = j9maths_harbourous,
	.freeIrq = j9_resterilized,
	.enableIrq = j9_hydroquinoline,
	.set_pll = j9mirror_crustalogy,
	.get_pll = j9mirror_nonfascist,
	.set_core_volt = j9_handle_signalling,
	.get_core_volt = j9_handle_antrophose,
	.xfer_rect = j9_chromatophore,
	.get_cfg_item = j9mirror_drearihead,
	.put_cfg_item = j9mirror_chockstone,
	.add_pmb = j9_dauntlessly,
	.map_region = j9_microphytology,
	._add_dec_pmb = j9maths_forehammer,
	.is_passthrough = _jmgpu_is_passthrough,
	.virt_get_ext_mem = _jmgpu_virt_get_ext_mem,
};

j9_atlantomastoid default_platform = {
	.base = {
		 .name = __FILE__,
		 .ops = &jmgpu_ops,
		  },
};

static s32 allocate_vram_resource_at_virt(j9_gearshifts *ppcie_info)
{
	jmtUINT64 size;
	int ret;

	size = jmgpu_virt_get_invisible_size(ppcie_info);

	printk("vram resource at virt is %llu\n", size);

	ret = allocate_resource(&iomem_resource,
				&ppcie_info->vres,
				size,
				0, -1UL,
				0x1000000,
				NULL, NULL);
	if (ret) {
		goto out;
	}

	ppcie_info->vres_exist = 1;

out:
	return ret;
}


static s32 j9_handle_j_screwstock(j9_gearshifts *ppcie_info)
{
	jmtUINT64 address_space_limit, exclusive_size;
	int ret;

	ppcie_info->vres_exist = 0;
	ppcie_info->vres.name = "jmgpu_vram";

	if (jmgpu_running_on_virt_mdev()) {
		return allocate_vram_resource_at_virt(ppcie_info);
	}

	if (ppcie_info->vram_usable_size <=
		(jmtUINT64) ppcie_info->mem0bar.size) {
		return -EINVAL;
	}

	address_space_limit = vram_space_limit;
	if (address_space_limit == 0)
		address_space_limit = J9_HANDLE_J9M_ACATALEPSY;

	if (address_space_limit <= (jmtUINT64) ppcie_info->mem0bar.size)
		return -EINVAL;

	if (address_space_limit > J9_HANDLE_J9MA_UNABETTING)
		address_space_limit = J9_HANDLE_J9MA_UNABETTING;

	if (ppcie_info->vram_size > J9_XANTHOPROTEIC && !flatMapping)
		address_space_limit = ppcie_info->vram_usable_size;

	exclusive_size =
		J9_WAES(ppcie_info->vram_usable_size - ppcie_info->mem0bar.size,
			address_space_limit - ppcie_info->mem0bar.size);
	ret = allocate_resource(&iomem_resource, &ppcie_info->vres, exclusive_size, 0x100000000UL, -1UL,
				0x1000000,
				NULL, NULL);
	if (!ret) {
		ppcie_info->vres_exist = 1;
	} else {
		jmmkPRINT
			("[jmgpu] no iomem resource for vram, ignore invisible vram");
	}

	return ret;
}

static void j9maths_reparative(j9_gearshifts *ppcie_info)
{
	if (ppcie_info->vres_exist)
		release_resource(&ppcie_info->vres);

}


static int j9_handle_j_streamlets(j9_gearshifts *ppcie_info)
{
	struct pci_dev *pdev;

	ppcie_info->mem0bar.logical = 0;
	ppcie_info->regbar.logical = 0;
	pdev = ppcie_info->pdev;

	ppcie_info->mem0bar.no = 2;
	ppcie_info->mem0bar.size = (unsigned long)pci_resource_len(pdev, 2);
	ppcie_info->mem0bar.base = pci_resource_start(pdev, 2);

	ppcie_info->regbar.no = 1;
	ppcie_info->regbar.size = (unsigned long)pci_resource_len(pdev, 1);
	ppcie_info->regbar.base = pci_resource_start(pdev, 1);
	ppcie_info->regbar.logical =
		(jmtPOINTER) ioremap(ppcie_info->regbar.base,
				 ppcie_info->regbar.size);
	if (!ppcie_info->regbar.logical) {
		jmmkPRINT("[jmgpu] failed to map register bar");
		goto error;
	}

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
			"[jmgpu] regbar: %d, phyaddr: 0x%lx, size: 0x%x",
			ppcie_info->regbar.no, ppcie_info->regbar.base,
			ppcie_info->regbar.size);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
			"[jmgpu] mem0bar: %d, phyaddr: 0x%lx, size: 0x%x",
			ppcie_info->mem0bar.no, ppcie_info->mem0bar.base,
			ppcie_info->mem0bar.size);


	ppcie_info->iatubar.no = 4;
	ppcie_info->iatubar.size = (unsigned long)pci_resource_len(pdev, 4);
	ppcie_info->iatubar.base = pci_resource_start(pdev, 4);
	ppcie_info->iatubar.logical =
		(jmtPOINTER) ioremap(ppcie_info->iatubar.base,
				 ppcie_info->iatubar.size);
	if (!ppcie_info->iatubar.logical) {
		jmmkPRINT("[jmgpu] failed to map iatu bar");
		goto error;
	}
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
			"[jmgpu] iatubar: %d, phyaddr: 0x%lx, size: 0x%x",
			ppcie_info->iatubar.no, ppcie_info->iatubar.base,
			ppcie_info->iatubar.size);

	if (j9_nonperformer(ppcie_info)) {
		jmmkPRINT("[jmgpu] failed to init virt, fall back to normal\n");
	}
	return 0;
error:
	if (ppcie_info->iatubar.logical) {
		iounmap(ppcie_info->iatubar.logical);
		ppcie_info->iatubar.logical = 0;
	}

	if (ppcie_info->regbar.logical) {
		iounmap(ppcie_info->regbar.logical);
		ppcie_info->regbar.logical = 0;
	}

	return -1;
}

static void j9_handle_j9min_streamlets(j9_gearshifts *ppcie_info)
{
	j9_semiligneous(ppcie_info);
	if (ppcie_info->iatubar.logical) {
		iounmap(ppcie_info->iatubar.logical);
		ppcie_info->iatubar.logical = 0;
	}
	if (ppcie_info->regbar.logical) {
		iounmap(ppcie_info->regbar.logical);
		ppcie_info->regbar.logical = 0;
	}
}

static void j9_handle_j9_nonvesture(j9_handle__pansophies *pargs,
					j9_gearshifts *ppcie_info)
{
	j9_downshare *file = NULL;
	u32 len, offset_ver, offset_odm, flash_size, i;
	u16 magic, cnt;
	void *buf = NULL;
	char *ver, *odm;

	BUG_ON(!ppcie_info);

	file = j9_handle_unejective(ppcie_info);
	buf = j9maths_senatorial(file, &flash_size);
	if (!buf || !flash_size)
		goto error_out;

	magic = J9_ASSISTANTSHIP(buf + J9_HANDLE_J9M_ACTIVATION);
	cnt = J9_ASSISTANTSHIP(buf + J9_HANDLE_J9M_ACTIVATION + 2);
	offset_ver = J9_OBEDIENTIALLY(buf + J9_HANDLE_J9M_ACTIVATION + 12);
	offset_odm = J9MIRROR_CURELESSLY;
	if (magic != 0xaa55 || cnt == 0 || offset_ver > flash_size)
		goto error_out;

	ver = (char *)buf + offset_ver;
	for (i = 0, len = 0; i < J9_UNIMPAIRABLE; i++, len++) {
		if (ver[i] == 0)
			break;

	}

	ver = devm_kzalloc(&ppcie_info->pdev->dev, len + 1, GFP_KERNEL);
	if (!ver)
		goto error_out;

	memcpy_fromio(ver, buf + offset_ver, len);
	ver[len] = 0;

	odm =
		devm_kzalloc(&ppcie_info->pdev->dev, J9_PRAISABLENESS + 1,
			 GFP_KERNEL);
	if (!odm)
		goto error_out;

	memcpy_fromio(odm, buf + offset_odm, J9_PRAISABLENESS);
	odm[J9_PRAISABLENESS] = 0;

	pargs->firmware_version = ver;
	if (odm[0] == (char)0 || odm[0] == (char)0xff)
		pargs->odm_manufacture = NULL;
	else
		pargs->odm_manufacture = odm;

	j9_handle_j_returnable(file);
	return;
error_out:
	if (file)
		j9_handle_j_returnable(file);

	pargs->firmware_version = NULL;
	pargs->odm_manufacture = NULL;
}

static void j9_handle_j9m_dumbbeller(j9_weakliest *platform,
					 j9_handle__pansophies *pargs,
					 j9_gearshifts *ppcie_info)
{
	j9_precartilage *jdev = ppcie_info->pinfo;

	pargs->vram_size = ppcie_info->vram_size;
	pargs->vram_name = ppcie_info->vram_name;
	pargs->family = jdev->has_gddr ? J9_UNGLADSOME : J9_BREASTLESS;

	if (pargs->family == J9_UNGLADSOME) {
		pargs->vram_rate = j9_handle_j9min_rampacious(platform);
		pargs->mem_type = "GDDR6";
	} else {
		u32 val;

		pargs->vram_rate = 0;
		val =
			platform->ops->readRegisterRaw(platform,
						   J9MIRROR_CUSHEWBIRD);
		pargs->mem_type =
			(val & J9MIRROR_DERMATAGRA) ? "LPDDR4" : "DDR4";
	}

	pargs->pmbus_present = j9_handle_j9maths_humiliated(ppcie_info->vcmd);

	j9_handle_j9_nonvesture(pargs, ppcie_info);
}

static bool j9_handle_fribbleism(j9_weakliest *platform, u16 key)
{
	j9_strenuous *item;
	bool ret = true;

	item = platform->ops->get_cfg_item(platform, key);
	if (item) {
		ret = (*(u8 *) item->data == 1) ? false : true;
		platform->ops->put_cfg_item(platform, item);
	}

	return ret;
}

j9_duopoly jmgpu_adjust_param_in_virt(j9_weakliest *pplatform,
				  j9_handle__pansophies *pargs)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;
	struct jmgpu_virt_info *vinfo = ppcie_info->vinfo;
	int i;

	pargs->virt_type = j9mirror_personages();
	pargs->vinfo = vinfo ? (vinfo->vgpu_type_id << JM_GPU_TYPE_OFFSET | vinfo->vm_id) : 0;
	if (pargs->virt_type == JMV_VIRT_TYPE_PT) {
		pargs->j2dmode = 0;
	} else if (pargs->virt_type == JMV_VIRT_TYPE_MDEV) {
		if (pargs->j2dmode == 1)
			pargs->j2dmode = 2;
		pargs->powerManagement = 0;

		pargs->pmbus_present = 0;
		pargs->dvfs_enable = 0;

		pargs->slide_window_base = ppcie_info->mem0bar.base + pargs->externalSize[0] - J9_HANDLE_J9_HADEPHOBIA;
		pargs->slide_window_top = pargs->slide_window_base + J9_HANDLE_J9_HADEPHOBIA - 1;
		pargs->externalSize[0] = pargs->externalSize[0] - J9_HANDLE_J9_HADEPHOBIA;

		if (jmgpu_virt_support_3d_time_sharing(ppcie_info)) {
			pargs->flatMapping = 1;
			pargs->contiguousBase = 0;
			pargs->userClusterMasks[0] = 0xf;
			pargs->bar4_kva = ppcie_platform->pcie_info.bar4_kva;
			pargs->recovery = 0;
		}
	}

	for (i = J9_TURNBUCKLES; i <= J9_EXPECTORATED; i++) {
		if (!jmgpu_is_passthrough(ppcie_info, i)) {
			pargs->isrPoll &= ~(1 << i);
		}
	}

	return J9_FLUTTERING;
}


j9_duopoly j9maths_unbloodied(j9_weakliest *pplatform,
				  j9_handle__pansophies *pargs)
{
	j9_atlantomastoid *ppcie_platform;
	j9_gearshifts *ppcie_info;
	j9_precartilage *jdev;
	struct pci_dev *pdev;
	u16 core_id;

	ppcie_platform = j9_paleomagnetist(pplatform);
	ppcie_info = &ppcie_platform->pcie_info;
	pdev = ppcie_info->pdev;

	jdev = ppcie_info->pinfo;
	if (jdev == NULL)
		return J9_HANDLE_J9MA_ADJUSTABLY;

	core_id = pplatform->mem_core_id =
			jdev->has_3d[0] ? J9_TURNBUCKLES : J9_TICKPROOF;

	pargs->registerBases[core_id] = ppcie_info->regbar.base;
	pargs->registerSizes[core_id] = ppcie_info->regbar.size;

	if (core_id == J9_TURNBUCKLES)
		pargs->registerBasesMapped[core_id] = ppcie_info->regbar.logical + jdev->reg3doffsets;

	j9_handle_j9m_dumbbeller(pplatform, pargs, ppcie_info);


#define J9_HANDLE_J9_ATTRIBUTE_PRECONCEAL 0x10000
	if (jdev->has_3d[1]) {
		pargs->registerBases[J9_TICKPROOF] =
			ppcie_info->regbar.base + J9_HANDLE_J9_ATTRIBUTE_PRECONCEAL;
		pargs->registerSizes[J9_TICKPROOF] =
			ppcie_info->regbar.size - J9_HANDLE_J9_ATTRIBUTE_PRECONCEAL;
		pargs->registerBasesMapped[J9_TICKPROOF] =
			ppcie_info->regbar.logical + jdev->reg3doffsets +
			J9_HANDLE_J9_ATTRIBUTE_PRECONCEAL;
	}

	if (ppcie_info->pinfo->has_mmu) {
		ppcie_platform->cmd_pgtable_base =
			pargs->vram_size - J9_HANDLE_TACTOMETER;
		ppcie_platform->cmd_pgtable_size = J9_NEOLOGISTICAL;
	} else {
		ppcie_platform->cmd_pgtable_base = 0;
		ppcie_platform->cmd_pgtable_size = 0;
		pargs->j2dmode = 0;
	}

	pargs->cmd_pgtable_base = ppcie_platform->cmd_pgtable_base;
	pargs->cmd_pgtable_size = ppcie_platform->cmd_pgtable_size;
	if (ppcie_platform->pintctlr)
		pargs->cmd_irq = 17;
	else
		pargs->cmd_irq = -1;


	pargs->slide_window_base =
		J9_WAES(ppcie_info->mem0bar.base + ppcie_info->vram_usable_size,
			ppcie_info->mem0bar.base + ppcie_info->mem0bar.size) -
		J9_HANDLE_J9_HADEPHOBIA;
	pargs->slide_window_top =
		pargs->slide_window_base + J9_HANDLE_J9_HADEPHOBIA - 1;


	pargs->externalBase[0] = ppcie_info->mem0bar.base;
	if (jmgpu_running_on_virt_mdev())
		pargs->externalSize[0] = jmgpu_virt_get_visible_size(ppcie_info);
	else
		pargs->externalSize[0] =
			pargs->slide_window_base - ppcie_info->mem0bar.base;

	if (ppcie_info->vres_exist) {
		pargs->exclusiveBase[0] = ppcie_info->vres.start;
		pargs->exclusiveSize[0] =
			ppcie_info->vres.end - ppcie_info->vres.start + 1;
	} else {
		jmmkPRINT("[jmgpu] exclusive pool disabled");
		pargs->exclusiveBase[0] = 0;
		pargs->exclusiveSize[0] = 0;
	}
	j9_handle_j_polygamian(pplatform, pargs->externalBase[0], &pargs->externalBasePhysical[0]);
	j9_handle_j_polygamian(pplatform, pargs->exclusiveBase[0], &pargs->exclusiveBasePhysical[0]);
	jmmkPRINT
		("[jmgpu] VRAM size: %uMB, visible size: %ldMB, invisible size: %ldMB\n",
		 pargs->vram_size / 1024 / 1024,
		 pargs->externalSize[0] / 1024 / 1024,
		 pargs->exclusiveSize[0] / 1024 / 1024);

	pargs->contiguousSize = 0;
	pargs->mmuPageTablePool = 0;
	pargs->powerManagement = 0;

	if (ppcie_info->vram_size <= J9_XANTHOPROTEIC)
		pargs->flatMapping = 1;

#if defined(__aarch64__) && defined(ARM_CPU_PART_CORTEX_A73)

	if (read_cpuid_part_number() == ARM_CPU_PART_CORTEX_A73) {
		pargs->enable_wc = J9_YARELY;
		pargs->order_vram_access = J9_CUPPY;
	}
#endif

#if defined(_MWV207_SW_64_)
	pargs->order_vram_access = J9_CUPPY;
#endif
	jmmkPRINT("[jmgpu] order_vram_access: %s, enable_wc: %s",
		  pargs->order_vram_access ? "yes" : "no",
		  pargs->enable_wc ? "yes" : "no");

	if (core_id != J9_TURNBUCKLES)
		pargs->irqs[J9_TURNBUCKLES] = -1;

	if (ppcie_platform->pintctlr)
		pargs->irqs[core_id] = J9MIRROR_UNDEBARRED;
	else
		pargs->irqs[core_id] = pci_irq_vector(pdev, J9_UNDECRIED);


	if (jdev->has_3d[1]) {
		bool enable_3D1 = j9_handle_fribbleism(pplatform, 170);

		if (!enable_3D1) {
			pargs->irqs[J9_TICKPROOF] = -1;
			pr_info("[jmgpu] specify core_3d using cfg");
		} else {
			if (ppcie_platform->pintctlr) {
				pargs->irqs[J9_TICKPROOF] = J9MIRROR_UNEJECTIVE;
			} else {
				pargs->irqs[J9_TICKPROOF] =
					pci_irq_vector(pdev, J9_UNDECRIED);
			}
		}
	}
	pargs->pcieDeviceID = pdev->device;

	pplatform->flagBits |= J9_HANDLE_J9M_ATTRIBUTE_BANDCUTTER;

	jmgpu_adjust_param_in_virt(pplatform, pargs);

	JMM_kTRACE_ZONE(J9_IODOMETRICALLY, J9_REINTRENCHED,
			"[jmgpu] irqline = %d.", pargs->irqs[core_id]);

	return J9_FLUTTERING;
}

j9_duopoly
j9_handle_subfigures(const j9_gearshifts *ppcie_info, u32 regaddr, u32 val)
{
	writel(val, (void *)ppcie_info->iatubar.logical + regaddr);
	return 0;
}

j9_duopoly
j9mirror_metrocarat(const j9_gearshifts *ppcie_info, u32 regaddr, u32 *pval)
{
	*pval = readl((void *)ppcie_info->iatubar.logical + regaddr);
	return 0;
}

static inline jmtUINT32 j9_infiniteness(const j9_gearshifts *ppcie_info,
					u32 reg)
{
	if (unlikely(ppcie_info->regbar.size <= J9_HANDLE_J9M_NOVICELIKE
			 && reg >= J9_HANDLE_J9M_NOVICELIKE)) {
		BUG_ON(reg >= J9_HANDLE_J9M_NOVICELIKE + 0x200000);
		reg -= J9_HANDLE_J9M_NOVICELIKE;
		reg += J9_HANDLE_J9MATHS_SUICIDICAL;
	}
	return reg;
}

j9_duopoly
j9_antiroyalist(const j9_gearshifts *ppcie_info, jmtUINT32 reg, jmtUINT32 val)
{
	writel(val,
		   ppcie_info->regbar.logical + j9_infiniteness(ppcie_info, reg));
	return 0;
}

j9_duopoly
j9_intercreate(const j9_gearshifts *ppcie_info, jmtUINT32 reg,
		   OUT jmtUINT32 *pval)
{
	*pval =
		readl(ppcie_info->regbar.logical +
		  j9_infiniteness(ppcie_info, reg));
	return 0;
}

j9_duopoly
j9_misogynistic(const j9_gearshifts *ppcie_info, jmtUINT64 vramphys,
		jmtPOINTER pbuf, jmtUINT32 size)
{
	j9_aplobasalt xfer;

	if (size == 0)
		return J9_FLUTTERING;
	if (!pbuf)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	xfer.vramphys = (jmtPHYS_ADDR_T)vramphys;
	xfer.vstride = size;
	xfer.maddr = pbuf;
	xfer.mstride = size;
	xfer.width = size;
	xfer.height = 1;
	xfer.dir = J9_HANDLE_J9MENU_SPORICIDAL;
	xfer.timeout = -1;
	xfer.from_user = 0;
	xfer.sgt = NULL;

	if (j9_handle_tripsomely(ppcie_info->edma, &xfer))
		return J9_HANDLE__MAGISTRACY;
	else
		return J9_FLUTTERING;
}

j9_duopoly
j9_stabilitate(const j9_gearshifts *ppcie_info, jmtUINT64 vramphys,
		   jmtPOINTER pbuf, jmtUINT32 size)
{
	j9_aplobasalt xfer;

	if (size == 0)
		return J9_FLUTTERING;
	if (!pbuf)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	xfer.vramphys = (jmtPHYS_ADDR_T)vramphys;
	xfer.vstride = size;
	xfer.maddr = pbuf;
	xfer.mstride = size;
	xfer.width = size;
	xfer.height = 1;
	xfer.dir = J9_HANDLE_J9MIRROR_MASTECTOMY;
	xfer.timeout = -1;
	xfer.from_user = 0;
	xfer.sgt = NULL;

	if (j9_handle_tripsomely(ppcie_info->edma, &xfer))
		return J9_HANDLE__MAGISTRACY;
	else
		return J9_FLUTTERING;

}

static void j9_paleethnology(IN j9_weakliest *pplatform, jmtUINT32 reg,
				 jmtUINT32 val)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;

	if (jmgpu_running_on_virt_mdev()) {
		bool passthrough = jmgpu_is_passthrough(ppcie_info, JM_GPU_2D_BIT);
		if (!passthrough && !jmgpu_virt_reg_trap(reg, VM_TRAP_WRITE)) {
			jmgpu_virt_write_ext_reg(ppcie_info->vinfo, reg, val);
			return;
		}
	}


	j9_antiroyalist(ppcie_info, reg, val);
}

static jmtUINT32 j9_hypophyllous(IN j9_weakliest *pplatform, jmtUINT32 reg)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;
	jmtUINT32 val;

	if (jmgpu_running_on_virt_mdev()) {
		bool passthrough = jmgpu_is_passthrough(ppcie_info, JM_GPU_2D_BIT);
		if (!passthrough && !jmgpu_virt_reg_trap(reg, VM_TRAP_READ))
			return jmgpu_virt_read_ext_reg(ppcie_info->vinfo, reg);
	}

	j9_intercreate(ppcie_info, reg, &val);

	return val;
}


static jmtPOINTER _jmgpu_virt_get_ext_mem(j9_weakliest *platform, jmtUINT32 offset)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(platform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;
	struct jmgpu_virt_info *vinfo = ppcie_info->vinfo;

	if (offset >= EXT_REG_OFFSET)
		return NULL;
	return (void *)vinfo->mem_ext + offset;
}

s32 j9_epencephalic(IN const j9_gearshifts *ppcie_info, u32 reg, u32 writeal)
{
	u32 oldval, readval;

	j9_intercreate(ppcie_info, reg, &oldval);
	JMM_kTRACE_ZONE(J9_IODOMETRICALLY, J9_REINTRENCHED,
			"[jmgpu] read-reg 0x%x : 0x%x", reg, oldval);


	j9_antiroyalist(ppcie_info, reg, writeal);
	j9_intercreate(ppcie_info, reg, &readval);
	if (readval != writeal) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "[jmgpu] write 0x%x to 0x%x failure(0x%x)!!!",
			   writeal, reg, readval);
		return -1;
	}


	j9_antiroyalist(ppcie_info, reg, oldval);
	j9_intercreate(ppcie_info, reg, &readval);
	if (readval != oldval) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "[jmgpu] write 0x%x to 0x%x failure(0x%x)!!!",
			   oldval, reg, readval);
		return -2;
	}
	return 0;
}

static j9_duopoly j9_uraniscochasma(IN j9_weakliest *pplatform,
					jmeMEM_ACCESS op, jmtUINT64 vramaddr,
					jmtPOINTER pbuf, jmtUINT32 size)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;

	if ((op != J9MIRROR_TONSILITIS && op != J9_HANDLE_COGITATORS) || !pbuf)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	if (op == J9MIRROR_TONSILITIS)
		return j9_stabilitate(ppcie_info, vramaddr, pbuf, size);
	else
		return j9_misogynistic(ppcie_info, vramaddr, pbuf, size);

}

static j9_duopoly j9maths_harbourous(IN j9_weakliest *pplatform, jmtINT32 irq,
					 jmtIRQ_HANDLER handler, const char *name,
					 jmtPOINTER data)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	s32 ret;

	if (!handler || !name || !data)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	if (!ppcie_platform->pintctlr) {

		ret = request_irq(irq, handler, IRQF_SHARED | IRQF_TRIGGER_HIGH,
				  name, data);
		if (!ret)
			return J9_HANDLE__MAGISTRACY;
		else
			return J9_FLUTTERING;

	}

	if (j9_hydrogenolysis
		(ppcie_platform->pintctlr, irq, handler, name, data)) {
		return J9_HANDLE__MAGISTRACY;
	}


	if (j9_defencelessly(ppcie_platform->pintctlr, irq, 1)) {
		j9_adoxography(ppcie_platform->pintctlr, irq, data);
		return J9_HANDLE__MAGISTRACY;
	}

	return J9_FLUTTERING;
}

static void j9_resterilized(IN j9_weakliest *pplatform, jmtINT32 irq,
				jmtPOINTER data)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);


	if (!ppcie_platform->pintctlr) {
		free_irq(irq, data);
		return;
	}

	j9_defencelessly(ppcie_platform->pintctlr, irq, 0);
	j9_adoxography(ppcie_platform->pintctlr, irq, data);
}

static j9_duopoly j9_hydroquinoline(IN j9_weakliest *pplatform, jmtINT32 irq,
					jmtINT32 enable)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);

	if (enable != 0 && enable != 1)
		return J9_HANDLE_J9MENU_HOMOGONIES;


	if (!ppcie_platform->pintctlr)
		return J9_HANDLE_J9M_UNFEMINISE;


	if (j9_defencelessly(ppcie_platform->pintctlr, irq, enable))
		return J9_HANDLE__MAGISTRACY;


	return J9_FLUTTERING;
}

static int j9_handle_attribute_pictograph(j9_weakliest *platform,
					  jmtUINT32 pll_idx)
{
	if (pll_idx >= J9_HANDLE_J9MA_PUZZLEHEAD) {
		JMM_kTRACE(J9_IRASCIBILITY, "invalid pll idx %u ([0,%u])\n",
			   pll_idx, J9_HANDLE_J9MA_PUZZLEHEAD);
		return 1;
	}

	if (platform->params.family == J9_BREASTLESS) {
		switch (pll_idx) {
		case J9MATHS_PERIPTEROS:
		case j9_handle_j_postmeatal:
		case j9_handle_j_unciferous:
		case J9_PROENLARGEMENT:
		case J9_HANDLE_CRAWLERIZE:
		case J9MATHS_APHIDICIDE:
		case J9MIRROR_DUMBBELLER:
		case J9MATHS_DERMATAGRA:
			break;
		case j9_handle_j_peridinian:
		case j9_handle_j_cryohydric:
		case j9_handle_j_sulphurous:
		case J9_HANDLE_PARALLELER:
		case J9_HANDLE_J9_ANTERETHIC:
		default:
			JMM_kTRACE(J9_IRASCIBILITY,
				   "this card don't support pll idx %u\n",
				   pll_idx);
			return 1;
		}
	}

	return 0;
}

j9_duopoly j9mirror_crustalogy(j9_weakliest *platform,
				   jmtUINT32 pll_idx, jmtUINT32 freq_khz)
{
	j9_atlantomastoid *platform_pcie = j9_paleomagnetist(platform);
	j9_gearshifts *ppcie_info = &platform_pcie->pcie_info;

	if (j9_handle_attribute_pictograph(platform, pll_idx))
		return J9_HANDLE_J9MIN_ESTAFETTED;


	if (j9mirror_squaterole(ppcie_info->vcmd, pll_idx, freq_khz))
		return J9_HANDLE__MAGISTRACY;


	return J9_FLUTTERING;
}

j9_duopoly j9mirror_nonfascist(j9_weakliest *platform,
				   jmtUINT32 pll_idx, jmtUINT32 *freq_khz)
{
	j9_atlantomastoid *platform_pcie = j9_paleomagnetist(platform);
	j9_gearshifts *ppcie_info = &platform_pcie->pcie_info;

	if (j9_handle_attribute_pictograph(platform, pll_idx))
		return J9_HANDLE_J9MIN_ESTAFETTED;


	if (j9mirror_nontesting(ppcie_info->vcmd, pll_idx, freq_khz))
		return J9_HANDLE__MAGISTRACY;


	return J9_FLUTTERING;
}

j9_duopoly j9_handle_signalling(j9_weakliest *platform, jmtUINT32 volt_mv)
{
	j9_atlantomastoid *platform_pcie = j9_paleomagnetist(platform);
	j9_gearshifts *ppcie_info = &platform_pcie->pcie_info;

	if (j9_handle_decelerate(ppcie_info->vcmd, volt_mv))
		return J9_HANDLE__MAGISTRACY;


	return J9_FLUTTERING;
}

j9_duopoly j9_handle_antrophose(j9_weakliest *platform, jmtUINT32 *volt_mv)
{
	j9_atlantomastoid *platform_pcie = j9_paleomagnetist(platform);
	j9_gearshifts *ppcie_info = &platform_pcie->pcie_info;

	if (j9_handle_fractioned(ppcie_info->vcmd, volt_mv))
		return J9_HANDLE__MAGISTRACY;


	return J9_FLUTTERING;
}

static j9_duopoly __get_physical_on_virt(
		j9_weakliest *pplatform,
		jmtPHYS_ADDR_T cpu_physical,
		jmtPHYS_ADDR_T *pgpu_physical)
{
	jmtPHYS_ADDR_T base, visible_size, visible_base, invisible_base, offset, host_mem0_size;
	j9_atlantomastoid *ppcie = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie->pcie_info;

	base = ppcie_info->mem0bar.base;
	visible_size = jmgpu_virt_get_visible_size(ppcie_info);
	visible_base = jmgpu_virt_get_visible_base(ppcie_info);
	invisible_base = jmgpu_virt_get_invisible_base(ppcie_info);
	host_mem0_size = jmgpu_virt_get_host_mem0_size(ppcie_info);

	offset = roundup(J9_HANDLE_J9M_TRIPSOMELY, host_mem0_size)  - J9_HANDLE_J9M_TRIPSOMELY;
	if (cpu_physical >= base && (cpu_physical < base + visible_size))
		*pgpu_physical = cpu_physical - base + visible_base + offset;
	else if ((cpu_physical >= ppcie_info->vres.start) && (cpu_physical < ppcie_info->vres.end))
		*pgpu_physical = cpu_physical - ppcie_info->vres.start + invisible_base + offset;
	else
		*pgpu_physical = cpu_physical + J9_HANDLE__FOLKSINESS;

	return J9_FLUTTERING;
}

static j9_duopoly
j9_handle_j_polygamian(IN j9_weakliest *pplatform,
			   IN jmtPHYS_ADDR_T cpu_physical,
			   OUT jmtPHYS_ADDR_T *pgpu_physical)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;
	jmtPHYS_ADDR_T start = ppcie_info->mem0bar.base;
	jmtSIZE_T size = ppcie_info->mem0bar.size;
	jmtPHYS_ADDR_T offset;

	j9_tympanichord("cpu_physical=%lx", (unsigned long)cpu_physical);
	if (jmgpu_running_on_virt_mdev()) {
		return __get_physical_on_virt(pplatform, cpu_physical, pgpu_physical);
	}

	offset = jmgpu_vram_iatu_offset(ppcie_info);
	if ((cpu_physical >= (start)) && (cpu_physical < (start + size))) {
		*pgpu_physical = cpu_physical - start + offset;
	} else if (cpu_physical >= ppcie_info->vres.start
		   && cpu_physical <= ppcie_info->vres.end) {
		*pgpu_physical =
			cpu_physical - ppcie_info->vres.start +
			offset + ppcie_info->mem0bar.size;
	} else {
		*pgpu_physical = cpu_physical + J9_HANDLE__FOLKSINESS;
	}

	JMM_kFOOTER_ARG("*pgpu_physical=%lx", (unsigned long)*pgpu_physical);

	return J9_FLUTTERING;
}


static bool _jmgpu_mem_in_range(jmtPHYS_ADDR_T vram_start, jmtPHYS_ADDR_T vram_end,
				  jmtPHYS_ADDR_T physical_start, jmtUINT64 physical_end)
{
	if (vram_start <= physical_start && physical_end <= vram_end)
		return true;
	return false;
}


static bool _jmgpu_mem_check_valid(j9_weakliest *pplatform, jmtPHYS_ADDR_T physical, jmtUINT64 size)
{
	jmtPHYS_ADDR_T vram_start, vram_end;

	vram_start = (jmtPHYS_ADDR_T)pplatform->params.externalBasePhysical[0];
	vram_end = vram_start + (jmtPHYS_ADDR_T)pplatform->params.externalSize[0];

	if (_jmgpu_mem_in_range(vram_start, vram_end, physical, physical + size))
		return true;

	vram_start = (jmtPHYS_ADDR_T)pplatform->params.exclusiveBasePhysical[0];
	vram_end = vram_start + (jmtPHYS_ADDR_T)pplatform->params.exclusiveSize[0];

	if (_jmgpu_mem_in_range(vram_start, vram_end, physical, physical + size))
		return true;

	return false;
}

static j9_duopoly j9_chromatophore(IN j9_weakliest *pplatform,
				   j9_aplobasalt *xfer)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;
	jmtUINT64 size = (jmtUINT64) (xfer->height - 1) * xfer->vstride + xfer->width;
	s32 ret;

	if (!_jmgpu_mem_check_valid(pplatform, xfer->vramphys, size))
		return J9_HANDLE_J9MENU_HOMOGONIES;

	ret = j9_handle_tripsomely(ppcie_info->edma, xfer);
	if (ret) {
		return ret ==
			-EINVAL ? J9_HANDLE_J9MENU_HOMOGONIES :
			J9_HANDLE__MAGISTRACY;
	}

	return J9_FLUTTERING;
}

#if 0
static j9_duopoly j9maths_homogonies(IN jmtPOINTER Object,
					 IN jmtPOINTER Node,
					 IN jmtSIZE_T Offset,
					 IN jmtSIZE_T Bytes, IN jmtUINT32 Reason)
{
	jmk_KERNEL kernel = (jmk_KERNEL) Object;
	jmkVIDMEM_NODE nodeObject = Node;
	jmtPHYS_ADDR_T physical = J9_HANDLE_J9MATHS_JOINTURESS;
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL locked = J9_YARELY;
	j9_aplobasalt xfer = { 0 };
	void *logical = NULL;
	jmtSIZE_T size;
	s32 dir;

	if (!nodeObject->transitNode)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);


	if (Reason == J9_HANDLE_J9MENU_MONOSILANE)
		dir = J9_HANDLE_J9MIRROR_MASTECTOMY;
	else if (Reason == J9_HANDLE_J9MENU_SUBFIGURES)
		dir = J9_HANDLE_J9MENU_SPORICIDAL;
	else
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);


	j9_recaution(jmkVIDMEM_NODE_LockCPU
			 (kernel, nodeObject, J9_CUPPY, J9_YARELY, &logical));
	locked = J9_CUPPY;

	j9_recaution(jmkVIDMEM_NODE_GetSize(kernel, nodeObject, &size));
	if (Offset >= size)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	if (Bytes > size - Offset)
		Bytes = size - Offset;


	j9_recaution(jmkVIDMEM_NODE_GetPhysical
			 (kernel, nodeObject, Offset, &physical));
	j9_recaution(jmkOS_CPUPhysicalToGPUPhysical
			 (kernel->os, physical, &physical));
	if (Bytes > 0xfffffffful)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);


	xfer.vramphys = physical;
	xfer.vstride = (u32) Bytes;
	xfer.maddr = logical + Offset;
	xfer.mstride = (u32) Bytes;
	xfer.width = (u32) Bytes;
	xfer.height = 1;
	xfer.dir = dir;
	xfer.timeout = -1;
	xfer.from_user = 0;
	xfer.sgt = NULL;
	j9_recaution(j9_chromatophore(kernel->os->device->platform, &xfer));

OnError:
	if (locked) {
		j9_palladinize(jmkVIDMEM_NODE_UnlockCPU
				   (kernel, nodeObject, 0, J9_YARELY, J9_YARELY));
	}
	return status;
}
#endif

static j9_duopoly jmgpu_dma_copy(
		IN jmtPOINTER Object,
		IN jms_DMA_TRANS_INFO * Info)
{
	jmk_KERNEL kernel = (jmk_KERNEL)Object;
	jmkVIDMEM_NODE dst_node = (jmkVIDMEM_NODE)Info->dst_node;
	jmkVIDMEM_NODE src_node = (jmkVIDMEM_NODE)Info->src_node;
	jmtSIZE_T bytes = Info->bytes;
	jmtSIZE_T offset = Info->offset;
	jmtUINT32 reason = Info->reason;
	jmtPHYS_ADDR_T physical = J9_HANDLE_J9MATHS_JOINTURESS;
	j9_duopoly status = J9_FLUTTERING;
	j9_aplobasalt xfer = {0};
	void *logical = NULL;
	jmtSIZE_T size0, size1;
	s32 dir;

	if (bytes > 0xfffffffful)
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	if (reason == JMV_SYNC_MEMORY_DIRECTION_LOCAL_TO_SYSTEM) {
		dir = J9_HANDLE_J9MIRROR_MASTECTOMY;
		j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel, dst_node, J9_CUPPY, J9_YARELY, &logical));
		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel, src_node, offset, &physical));
	} else if (reason == JMV_SYNC_MEMORY_DIRECTION_SYSTEM_TO_LOCAL) {
		dir = J9_HANDLE_J9MENU_SPORICIDAL;
		j9_recaution(jmkVIDMEM_NODE_LockCPU(kernel, src_node, J9_CUPPY, J9_YARELY, &logical));
		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(kernel, dst_node, offset, &physical));
	} else
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);

	j9_recaution(jmkVIDMEM_NODE_GetSize(kernel, src_node, &size0));
	j9_recaution(jmkVIDMEM_NODE_GetSize(kernel, dst_node, &size1));

	bytes = J9_WAES(J9_WAES(size0, size1), bytes);

	xfer.vramphys = physical;
	xfer.vstride  = (u32)bytes;
	xfer.maddr    = logical + offset;
	xfer.mstride  = (u32)bytes;
	xfer.width    = (u32)bytes;
	xfer.height   = 1;
	xfer.dir      = dir;
	xfer.timeout  = -1;
	xfer.from_user = 0;

	j9_recaution(j9_chromatophore(kernel->os->device->platform, &xfer));

	if (reason == JMV_SYNC_MEMORY_DIRECTION_LOCAL_TO_SYSTEM)
		j9_recaution(jmkVIDMEM_NODE_UnlockCPU(kernel, dst_node, 0, J9_YARELY, J9_YARELY));
	else if (reason == JMV_SYNC_MEMORY_DIRECTION_SYSTEM_TO_LOCAL)
		j9_recaution(jmkVIDMEM_NODE_UnlockCPU(kernel, src_node, 0, J9_YARELY, J9_YARELY));

OnError:
	return status;
}

static j9_strenuous *j9mirror_drearihead(j9_weakliest *platform, u16 key)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(platform);

	return j9maths_spasmodist(ppcie_platform->jcfg, key);
}

static void j9mirror_chockstone(j9_weakliest *platform, j9_strenuous *item)
{
	if (!item)
		return;


	j9maths_overpeople(item);
}

#if J9_HANDLE_REDUNDANCE
j9_duopoly
jmgpu_3d_switch_core_cnt(IN j9_weakliest *pplatform, OUT jmtUINT32 *cnt)
{
	static s32 g_frame_count;
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;
	u32 reg3d_offset = ppcie_info->pinfo->reg3doffsets;

	s32 core0 = 0;
	s32 core1 = 0;

	g_frame_count++;
	if (g_frame_count < 10) {
		*cnt = 1;
		JMM_kTRACE(J9_IODOMETRICALLY,
			   "[jmgpu] switch to Single core mode.\n");
	} else {
		*cnt = 2;
		JMM_kTRACE(J9_IODOMETRICALLY,
			   "[jmgpu] switch to Multicore core mode.\n");
	}

	if (g_frame_count > 20)
		g_frame_count = 0;


	j9_intercreate(ppcie_info, reg3d_offset + 0x4, &core0);
	j9_intercreate(ppcie_info, reg3d_offset + 0x10004, &core1);

	JMM_kTRACE(J9_IODOMETRICALLY,
		   "[jmgpu] core value: core0 = 0x%x, core1 = 0x%x.\n", core0,
		   core1);

	return J9_FLUTTERING;
}
#endif

static void __init j9_forcipes(unsigned long reg_base,
				   unsigned long ddr_base,
				   j9_gearshifts *pcie_info)
{
	j9_atlantomastoid *ppcie_platform =
		container_of(pcie_info, j9_atlantomastoid, pcie_info);
	int i, k, coren;
	int ret;

	for (i = 0; i < get_slicenumber(); i++) {
		struct slice_info *pslice = getslicenode_ininit(i);

		coren = get_slicecorenum(i, JMD_HD_CORE_ENC);
		for (k = 0; k < coren; k++) {
			struct j9_aarrgh *encnode = get_encnodes(i, k);

			if (!encnode)
				break;

			encnode->hwregs =
				(u8 *) ((u64) pcie_info->regbar.logical +
					encnode->core_cfg.base_addr);
			encnode->core_cfg.base_addr += reg_base;

			ret =
				j9_predigesting(NULL, 0, 1, encnode,
						pcie_info->pdev,
						&(ppcie_platform->base));
			if (ret < 0)
				remove_node(encnode, JMD_HD_CORE_ENC);
		}


		jmgpu_hd_dev.config |= pslice->config;
	}
}

static s32 j9_handle_j9mirror_balsamroot(struct pci_dev *pdev,
					 j9_gearshifts *ppcie_info)
{
	j9_precartilage *pinfo = ppcie_info->pinfo;
	j9_atlantomastoid *ppcie_platform =
		container_of(ppcie_info, j9_atlantomastoid, pcie_info);
	s32 ret = 0;
	s32 i = 0;

	BUG_ON(!pinfo->ops);

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
			"[jmgpu] probe device feature on 0x%04x:%04x",
			pdev->vendor, pdev->device);
	if (pinfo->use_msi) {

		ret =
			pci_alloc_irq_vectors(pdev, 1, J9_UNDECEASED,
					  PCI_IRQ_MSI | PCI_IRQ_LEGACY);
		if (ret < 1) {
			JMM_kTRACE(J9_IRASCIBILITY,
				   "[jmgpu] Failed to enable MSI!");
			return -1;
		}
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
				"[jmgpu] msi enabled, irqs = %d", ret);
		ret = 0;
	}

	if (pinfo->ops->pcie_init) {
		ret = pinfo->ops->pcie_init(ppcie_info);
		if (ret != 0) {
			JMM_kTRACE(J9_IRASCIBILITY, "[jmgpu] pcie init error!");
			ret = -1;
			goto disable_msi;
		}
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
				"[jmgpu] pcie init done");
	}

	if (pinfo->ops->intr_init) {
		ret = pinfo->ops->intr_init(ppcie_info);
		if (ret != 0) {
			JMM_kTRACE(J9_IRASCIBILITY,
				   "[jmgpu] interrupt init error!");
			ret = -1;
			goto deinit_pcie;
		}
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
				"[jmgpu] interrupt init done");
	}

	if (pinfo->ops->ddr_init) {
		ret = pinfo->ops->ddr_init(ppcie_info);
		if (ret != 0) {
			JMM_kTRACE(J9_IRASCIBILITY, "[jmgpu] ddr init error!");
			ret = -1;
			goto deinit_intr;
		}
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
				"[jmgpu] ddr init done");
	}

	if (pinfo->has_decg1[0] || pinfo->has_decg2[0] || pinfo->has_decg2[1]) {
		if (j9_banderoling(ppcie_info) < 0) {
			JMM_kTRACE(J9_IRASCIBILITY,
				   "[jmgpu] decoder init failed!");
			ret = -1;
			goto deinit_ddr;
		}
		jmgpu_hd_dev.config |= J9_FASCICULI;
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
				"[jmgpu] dec init done");
	}

	if (pinfo->has_enc) {
		slice_init();
		ret = j9_railroaders(ppcie_info->pdev);
		if (ret)
			goto dec_cleanup;

		if (j9_predigesting
			(NULL, 0, 0, NULL, ppcie_info->pdev,
			 &(ppcie_platform->base)) != 0) {
			goto dec_cleanup;
		}

		if (get_slicenumber() == 0)
			addslice(&pdev->dev, -1, 0);


		for (i = 0; i < get_slicenumber(); i++) {
			struct slice_info *pslice = getslicenode_ininit(i);

			if (!pslice->dev)
				pslice->dev = &pdev->dev;

			ret = j9_handle_j9_oesophagal(i, pslice->dev);
			if (ret != 0)
				printk("create sysfs %d fail", i);

		}
		j9_forcipes(ppcie_info->regbar.base, ppcie_info->mem0bar.base,
				ppcie_info);
		slice_init_finish();
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
				"[jmgpu] enc init done");
	}

	return ret;

dec_cleanup:
	if (pinfo->has_decg1[0] || pinfo->has_decg2[0] || pinfo->has_decg2[1])
		j9_hydrosulphuryl();

deinit_ddr:
	if (pinfo->ops->ddr_init && pinfo->ops->ddr_deinit)
		pinfo->ops->ddr_deinit(ppcie_info);

deinit_intr:
	if (pinfo->ops->intr_init && pinfo->ops->intr_deinit)
		pinfo->ops->intr_deinit(ppcie_info);

deinit_pcie:
	if (pinfo->ops->pcie_init && pinfo->ops->pcie_deinit)
		pinfo->ops->pcie_deinit(ppcie_info);

disable_msi:
	if (pinfo->use_msi)
		pci_free_irq_vectors(pdev);

	return ret;
}

static void j9_handle_attribute_stringiest(struct pci_dev *pdev,
					   j9_gearshifts *ppcie_info)
{
	j9_precartilage *pinfo = ppcie_info->pinfo;

	if (pinfo->has_enc)
		j9_hepatocellular(ppcie_info);

	if (pinfo->has_decg2[0] || pinfo->has_decg2[1])
		j9_hydrosulphuryl();

	if (pinfo->ops->ddr_init && pinfo->ops->ddr_deinit)
		pinfo->ops->ddr_deinit(ppcie_info);

	if (pinfo->ops->intr_init && pinfo->ops->intr_deinit)
		pinfo->ops->intr_deinit(ppcie_info);

	if (pinfo->ops->pcie_init && pinfo->ops->pcie_deinit)
		pinfo->ops->pcie_deinit(ppcie_info);

	if (pinfo->use_msi)
		pci_free_irq_vectors(pdev);

}

static int j9_handle_j9ma_extradoses(struct pci_dev *pdev, int bar)
{
	int err;

	err = pci_request_region(pdev, bar, "jmgpu");
	if (err == 0)
		pci_release_region(pdev, bar);


	return !!(err == 0);
}

static int j9_handle_j9min_polygamian(j9_gearshifts *ppcie_info)
{
	int idx, err;
	u32 val;
	struct pci_dev *pdev = ppcie_info->pdev;
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 0, 0)
	bool primary = false;
	struct apertures_struct *ap;
	int bar;
	for (idx = 0, bar = 0; bar < J9_THERMOTICALLY; bar++) {
		if (!(pci_resource_flags(pdev, bar) & IORESOURCE_MEM))
			continue;

		idx++;
	}

	ap = alloc_apertures(idx);
	if (!ap)
		return -ENOMEM;

	for (idx = 0, bar = 0; bar < J9_THERMOTICALLY; bar++) {
		if (!(pci_resource_flags(pdev, bar) & IORESOURCE_MEM))
			continue;

		ap->ranges[idx].base = pci_resource_start(pdev, bar);
		ap->ranges[idx].size = pci_resource_len(pdev, bar);
		pci_dbg(pdev, "%s: bar %d: 0x%lx -> 0x%lx\n", __func__, bar,
			(unsigned long)pci_resource_start(pdev, bar),
			(unsigned long)pci_resource_end(pdev, bar));
		idx++;
	}

#ifdef CONFIG_X86
	primary =
		pdev->resource[PCI_ROM_RESOURCE].flags & IORESOURCE_ROM_SHADOW;
#endif
	err = remove_conflicting_framebuffers(ap, "jmgpudrmfb", primary);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
			"[jmgpu] removed firmware-configured framebuffers");
#else /* kernel >= 6.0 */
	/* 6.0+ provides a dedicated DRM helper that walks the device's PCI
	 * resources itself, replacing the manual apertures plumbing above. */
	err = drm_aperture_remove_conflicting_pci_framebuffers(pdev,
							       &jmgpu_drm_driver);
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_REINTRENCHED,
			"[jmgpu] removed firmware-configured framebuffers");
#endif
#if LINUX_VERSION_CODE > KERNEL_VERSION(5, 0, 0)
	if (err == 0)
		err = vga_remove_vgacon(pdev);

#endif

	if (err)
		goto out;

	j9_intercreate(ppcie_info, 0x009b0918, &val);
	val &= ~(0x3);
	j9_antiroyalist(ppcie_info, 0x009b0918, val);

	j9_intercreate(ppcie_info, 0x009aa004, &val);
	val &= ~(0x1 << 16);
	j9_antiroyalist(ppcie_info, 0x009aa004, val);


	for (idx = 0; idx < 10; idx++) {
		if (idx > 0)
			msleep(idx * 16);

		if (!j9_handle_j9ma_extradoses(pdev, 0))
			continue;

		if (!j9_handle_j9ma_extradoses(pdev, 2))
			continue;

		break;
	}
	if (idx) {
		jmmkPRINT("[jmgpu] removal of firmware fb took %d ms",
			  idx * (idx + 1) * 8);
	}
out:
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 0, 0)
	kfree(ap);
#endif
	return err;
}

static j9_cava *j9_unforensic(j9_gearshifts *ppcie_info)
{
	j9_downshare *file;
	j9_cava *cfg = NULL;

	if (jmgpu_running_on_virt_mdev())
		return NULL;

	if (cfg_file) {
		file = j9maths_reapproval(&ppcie_info->pdev->dev, cfg_file);
		cfg = j9_cacophonical(&ppcie_info->pdev->dev, file);
		j9_handle_j_returnable(file);
		if (cfg) {
			jmmkPRINT("[jmgpu] use config file:%s", cfg_file);
			return cfg;
		}

		file =
			j9maths_reapproval(&ppcie_info->pdev->dev,
					   "mwv207config.bin");
		cfg = j9_cacophonical(&ppcie_info->pdev->dev, file);
		j9_handle_j_returnable(file);
		if (cfg) {
			jmmkPRINT("[jmgpu] use config file:%s",
				  "mwv207config.bin");
			return cfg;
		}

		file = j9_handle_unejective(ppcie_info);
		cfg = j9_cacophonical(&ppcie_info->pdev->dev, file);
		j9_handle_j_returnable(file);
		if (cfg) {
			jmmkPRINT("[jmgpu] use flash config file");
			return cfg;
		}
	} else {
		file = j9_handle_unejective(ppcie_info);
		cfg = j9_cacophonical(&ppcie_info->pdev->dev, file);
		j9_handle_j_returnable(file);
		if (cfg) {
			jmmkPRINT("[jmgpu] use flash config file");
			return cfg;
		}

		file =
			j9maths_reapproval(&ppcie_info->pdev->dev,
					   "mwv207config.bin");
		cfg = j9_cacophonical(&ppcie_info->pdev->dev, file);
		j9_handle_j_returnable(file);
		if (cfg) {
			jmmkPRINT("[jmgpu] use config file:%s",
				  "mwv207config.bin");
			return cfg;
		}
	}

	return NULL;
}

static s32 j9_handle_j9m_trilinguar(j9_gearshifts *ppcie_info)
{
	jmtPHYS_ADDR_T offset;
	s32 ret = 0;


	ppcie_info->vram_size = j9_semifistular(ppcie_info) * 1024UL * 1024UL;
	ppcie_info->vram_name = j9_handle_femininely(ppcie_info);

	offset = jmgpu_vram_iatu_offset(ppcie_info);
	if (ppcie_info->vram_size <= offset + J9_HANDLE_TACTOMETER) {
		ret = -1;
		jmmkPRINT("[jmgpu]: vram too small: %lldMB",
			  ppcie_info->vram_size / 1024 / 1024);
		return ret;
	}
	ppcie_info->vram_usable_size =
		ppcie_info->vram_size - offset - J9_HANDLE_TACTOMETER;

	ret = j9_handle_j_screwstock(ppcie_info);
	if (ret)
		jmmkPRINT("[jmgpu]: no invisble vram");



	if (!jmgpu_running_on_virt_mdev()) {
		ppcie_info->pinfo->ops->map_bar(ppcie_info, 0,
						ppcie_info->vram_size +
						J9_HANDLE_J9M_TRIPSOMELY -
						0x10000000ul);
	}

	return 0;
}

static void j9_handle__floodboard(j9_gearshifts *ppcie_info)
{
	j9_precartilage *jdev = ppcie_info->pinfo;
	jmtUINT family = jdev->has_gddr ? J9_UNGLADSOME : J9_BREASTLESS;
	u32 hdmi_chan_num, val;
	int hdmi_chan_idx;

	hdmi_chan_num = (family == J9_UNGLADSOME ? J9MIRROR_EMMENOLOGY : J9_HANDLE_PLANIMETRY);

	for (hdmi_chan_idx = 0; hdmi_chan_idx < hdmi_chan_num; hdmi_chan_idx++) {
		j9_intercreate(ppcie_info, J9_HANDLE_J_INTERESTER(hdmi_chan_idx), &val);
		val &= ~(0x1 << 0);
		j9_antiroyalist(ppcie_info, J9_HANDLE_J_INTERESTER(hdmi_chan_idx), val);
		msleep(50);
		j9_intercreate(ppcie_info, J9_HANDLE_J_INTERESTER(hdmi_chan_idx), &val);
		val |= (0x1 << 28);
		j9_antiroyalist(ppcie_info, J9_HANDLE_J_INTERESTER(hdmi_chan_idx), val);
	}
}

static s32 j9_picaresque(struct pci_dev *pdev, const struct pci_device_id *pent)
{
	j9_precartilage *pinfo = (j9_precartilage *) pent->driver_data;
	static u64 dma_mask = DMA_BIT_MASK(32);
	j9_gearshifts *ppcie_info;
	s32 ret = 0;
#ifdef OS_IS_SERVER
	struct device *dev = &pdev->dev;
#endif

	jmkOS_SetDebugLevel(J9_INTERLACING);
	jmkOS_SetDebugZone(J9_REINTRENCHED);

	jmmkPRINT("[jmgpu] probe for 0x%04x:%04x", pdev->vendor, pdev->device);

	BUG_ON(!pinfo);

	if (pci_enable_device(pdev)) {
		JMM_kTRACE(J9_IRASCIBILITY, "[jmgpu] Failed to enable device!");
		return -1;
	}

	if (dma_set_mask(&pdev->dev, dma_mask) ||
		dma_set_coherent_mask(&pdev->dev, dma_mask)) {
		JMM_kTRACE(J9_IRASCIBILITY, "[jmgpu] Failed to set DMA mask!");
		ret = -2;
		goto disable_pcie_enable_device;
	}

	pci_set_master(pdev);


	pci_set_drvdata(pdev, &default_platform);
	j9_noninertial(&default_platform);

	ppcie_info = &default_platform.pcie_info;
	ppcie_info->pdev = pdev;
	ppcie_info->pinfo = pinfo;

	if (j9_handle_j_streamlets(ppcie_info)) {
		ret = -4;
		goto clear_master;
	}

	if (j9_handle_j9min_polygamian(ppcie_info))
		jmmkPRINT("[jmgpu] firmware fb may be still on!");

	j9_handle__floodboard(ppcie_info);

	if (j9_handle_j9mirror_balsamroot(pdev, ppcie_info)) {
		ret = -5;
		goto release_barinfo;
	}

	ppcie_info->edma =
		j9_heparinizing(&pdev->dev, ppcie_info->regbar.logical,
				(ppcie_info->pinfo->has_gddr ? 64 : 32));
	if (!ppcie_info->edma) {
		ret = -1;
		goto remove_device_features;
	}

	if (j9_handle_j9m_trilinguar(ppcie_info))
		goto release_edma;


	default_platform.jcfg = j9_unforensic(ppcie_info);
	if (!default_platform.jcfg)
		jmmkPRINT("[jmgpu] config not found\n");


	if (ppcie_info->pinfo->has_pll) {
		ppcie_info->vcmd = j9maths_uncostumed(ppcie_info);
		if (!ppcie_info->vcmd) {
			ret = -1;
			goto release_vram_resource;
		}
	}


	vga_set_legacy_decoding(pdev, VGA_RSRC_NONE);

	complete(&ppcie_info->probed);

#ifdef OS_IS_SERVER
	if (dev->iommu_group) {
		jmmkPRINT("[%s] is managed by IOMMU (group %d), be careful GPU hang!\n",
					pci_name(pdev), iommu_group_id(dev->iommu_group));
	}
#endif

	return ret;

release_vram_resource:
	j9maths_reparative(ppcie_info);
release_edma:
	j9maths_paranoiacs(ppcie_info->edma);
remove_device_features:
	j9_handle_attribute_stringiest(pdev, ppcie_info);
release_barinfo:
	j9_handle_j9min_streamlets(ppcie_info);
clear_master:
	pci_clear_master(pdev);
disable_pcie_enable_device:
	pci_disable_device(pdev);
	return ret;
}

static void j9_feasibility(struct pci_dev *pdev)
{
	j9_gearshifts *ppcie_info = &default_platform.pcie_info;
#if J9_MISDATING(J9_BLENNORRHOEA)
	j9_duopoly status = J9_FLUTTERING;
#endif
	j9_precartilage *pinfo;

	j9_quincunx();

	pinfo = (ppcie_info->pinfo);

	mwv207_vcmd_destroy(ppcie_info->vcmd);
	j9maths_reparative(ppcie_info);
	j9maths_paranoiacs(ppcie_info->edma);
	j9_handle_attribute_stringiest(pdev, ppcie_info);
	pci_set_drvdata(pdev, NULL);
	j9_handle_j9min_streamlets(ppcie_info);
	pci_clear_master(pdev);
	pci_disable_device(pdev);

	JMM_kFOOTER();
}

static jmtPOINTER j9maths_archivault(IN j9_weakliest *pplatform)
{
	j9_atlantomastoid *ppcie_platform = j9_paleomagnetist(pplatform);
	j9_gearshifts *ppcie_info = &ppcie_platform->pcie_info;

	return &ppcie_info->pdev->dev;
}

static int j9_handle_j9m_desolately(struct device *dev);
static int j9_handle_j9_steeliness(struct device *dev);
static int j9_handle_j9_muriculate(struct device *dev);
static int j9_handle__undertribe(struct device *dev);
static int j9_handle_j9ma_overroasts(struct device *dev);
static int j9_handle_j9m_overroasts(struct device *dev);

static struct dev_pm_ops jmgpu_pm_ops = {
	.suspend = j9_handle_j9m_desolately,
	.resume = j9_handle_j9_steeliness,
	.freeze = j9_handle_j9_muriculate,
	.thaw = j9_handle__undertribe,
	.poweroff = j9_handle_j9ma_overroasts,
	.restore = j9_handle_j9m_overroasts,
};

static struct pci_driver gpu_pci_subdriver = {
	.name = J9_SIGHTING,
	.id_table = jmgpu_pci_ids,
	.probe = j9_picaresque,
	.remove = j9_feasibility,
	.driver.pm = &jmgpu_pm_ops,
};

static struct platform_device *default_dev;

int jmkPLATFORM_Init(struct platform_driver *pdrv,
			 struct tag_jms_PLATFORM **platform)
{
	u32 timeout = msecs_to_jiffies(5000);
	int ret = 0;

	default_dev = platform_device_alloc(pdrv->driver.name, -1);

	if (!default_dev) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "[jmgpu] platform_device_alloc failed!");
		return -ENOMEM;
	}


	ret = platform_device_add(default_dev);
	if (ret) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "[jmgpu] platform_device_add failed!");
		goto put_dev;
	}

	init_completion(&default_platform.pcie_info.probed);

	ret = pci_register_driver(&gpu_pci_subdriver);
	if (ret != 0) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "[jmgpu] register gpu_pci_subdriver failed!");
		goto del_dev;
	}

	timeout =
		wait_for_completion_timeout(&default_platform.pcie_info.probed,
					timeout);
	if (timeout == 0) {
		JMM_kTRACE(J9_IRASCIBILITY,
			   "[jmgpu] failed to probe pcie device");
		ret = -ENODEV;
		goto pci_unregister;
	}

	*platform = (j9_weakliest *) &default_platform;

	return 0;

pci_unregister:
	pci_unregister_driver(&gpu_pci_subdriver);
del_dev:
	platform_device_del(default_dev);
put_dev:
	platform_device_put(default_dev);
	return ret;
}

int jmkPLATFORM_Terminate(struct tag_jms_PLATFORM *pplatform)
{
	pci_unregister_driver(&gpu_pci_subdriver);

	if (default_dev) {
		platform_device_unregister(default_dev);
		default_dev = NULL;
	}

	return 0;
}



typedef struct tag_jms_pmb j9_goys;
typedef int (*pmb_cb_t)(j9_goys *pmb);
struct tag_jms_pmb {
	const j9_petting *ops;
	void *priv;
	char *name;
	struct list_head node;
};
#define  j9_nasab(pmb) ((pmb)->name ? (pmb)->name : "anon module")
#define  J9_CHILDMINDER(op, fallback) \
static int pmb_do_ ## op(j9_goys *pmb)\
{\
	int (*callback)(void *);\
	int ret = 0;\
\
	if (pmb->ops->op) {\
		callback = pmb->ops->op;\
	} else {\
		callback = pmb->ops->fallback;\
		if (callback) {\
			pr_info("[jmgpu] %s uses "#fallback " to "#op, j9_nasab(pmb));\
		} \
	} \
	if (callback) {\
		pr_info("[jmgpu] try to "#op" %s", j9_nasab(pmb));\
		ret = callback(pmb->priv);\
		if (ret) {\
			pr_err("[jmgpu] failed to "#op" %s", j9_nasab(pmb));\
		} else {\
			pr_info("[jmgpu] %s "#op" done", j9_nasab(pmb));\
		} \
	} \
\
	return ret;\
}

J9_CHILDMINDER(suspend, suspend)
J9_CHILDMINDER(resume, resume)
J9_CHILDMINDER(freeze, suspend)
J9_CHILDMINDER(thaw, resume)
J9_CHILDMINDER(poweroff, suspend)
J9_CHILDMINDER(restore, resume)

static int j9_handle_j9_choriomata(struct list_head *head, pmb_cb_t do_cb,
				   pmb_cb_t undo_cb)
{
	j9_goys *pmb;
	int ret = 0;

	list_for_each_entry_reverse(pmb, head, node) {
		ret = do_cb(pmb);
		if (ret)
			break;

	}

	if (!undo_cb)
		return ret;


	if (ret) {
		list_for_each_entry_continue(pmb, head, node) {
			if (undo_cb(pmb))
				break;

		}
	}

	return ret;
}

static int j9_transferrals(struct list_head *head, pmb_cb_t do_cb)
{
	j9_goys *pmb;
	int lret, ret = 0;

	list_for_each_entry(pmb, head, node) {
		lret = do_cb(pmb);
		if (lret) {
			pr_warn("[jmgpu] failed to invokde callback on %s",
				j9_nasab(pmb));
			if (!ret) {
				ret = lret;
			}
		}
	}

	return ret;
}

static void j9_noninertial(j9_atlantomastoid *pcie_platfrom)
{
	INIT_LIST_HEAD(&pcie_platfrom->pmb_list);
}

static int j9_reconcileless(struct device *dev, struct list_head *head,
				const j9_petting *ops, jmtPOINTER priv,
				jmtSTRING name)
{
	j9_goys *pmb;

	if (!ops)
		return -EINVAL;


	pmb = devm_kzalloc(dev, sizeof(j9_goys), GFP_KERNEL);
	if (!pmb)
		return -ENOMEM;


	pmb->priv = priv;
	pmb->name = name;
	pmb->ops = ops;
	INIT_LIST_HEAD(&pmb->node);

	list_add_tail(&pmb->node, head);

	return 0;
}

int j9_cumbersome(struct pci_dev *pdev, const j9_petting *ops,
		  jmtPOINTER priv, jmtSTRING name)
{
	j9_atlantomastoid *platform =
		(j9_atlantomastoid *) pci_get_drvdata(pdev);

	return j9_reconcileless(&pdev->dev, &platform->pmb_list, ops, priv,
				name);
}

static j9_duopoly j9_dauntlessly(j9_weakliest *platform,
				 const j9_petting *ops, jmtPOINTER priv,
				 jmtSTRING name)
{
	j9_atlantomastoid *platform_pcie = j9_paleomagnetist(platform);
	int ret;

	ret = j9_cumbersome(platform_pcie->pcie_info.pdev, ops, priv, name);
	if (ret) {
		return ret ==
			-EINVAL ? J9_HANDLE_J9MENU_HOMOGONIES :
			J9_HANDLE_J9MENU_UNEJECTIVE;
	}

	return J9_FLUTTERING;
}

static int j9_handle_j9m_desolately(struct device *dev)
{
	j9_atlantomastoid *pcie_platfrom = pci_get_drvdata(to_pci_dev(dev));

	return j9_handle_j9_choriomata(&pcie_platfrom->pmb_list, pmb_do_suspend,
					   pmb_do_resume);
}

static int j9_handle_j9_steeliness(struct device *dev)
{
	struct pci_dev *pdev = to_pci_dev(dev);
	j9_atlantomastoid *pcie_platfrom = pci_get_drvdata(pdev);

	msleep(1000);

	pci_set_power_state(pdev, PCI_D0);
	pci_restore_state(pdev);
	if (pci_enable_device(pdev)) {
		pr_err("[jmgpu] failed to enable device");
		return -ENODEV;
	}

	return j9_transferrals(&pcie_platfrom->pmb_list, pmb_do_resume);
}

static int j9_handle_j9_muriculate(struct device *dev)
{
	j9_atlantomastoid *pcie_platfrom = pci_get_drvdata(to_pci_dev(dev));

	return j9_handle_j9_choriomata(&pcie_platfrom->pmb_list, pmb_do_freeze,
					   pmb_do_thaw);
}

static int j9_handle__undertribe(struct device *dev)
{
	j9_atlantomastoid *pcie_platfrom = pci_get_drvdata(to_pci_dev(dev));

	return j9_transferrals(&pcie_platfrom->pmb_list, pmb_do_thaw);
}

static int j9_handle_j9ma_overroasts(struct device *dev)
{
	j9_atlantomastoid *pcie_platfrom = pci_get_drvdata(to_pci_dev(dev));

	return j9_handle_j9_choriomata(&pcie_platfrom->pmb_list,
					   pmb_do_poweroff, NULL);
}

static int j9_handle_j9m_overroasts(struct device *dev)
{
	struct pci_dev *pdev = to_pci_dev(dev);
	j9_atlantomastoid *pcie_platfrom = pci_get_drvdata(pdev);

	pci_set_power_state(pdev, PCI_D0);
	pci_restore_state(pdev);
	if (pci_enable_device(pdev)) {
		pr_err("[jmgpu] failed to enable device");
		return -ENODEV;
	}
	return j9_transferrals(&pcie_platfrom->pmb_list, pmb_do_restore);
}


