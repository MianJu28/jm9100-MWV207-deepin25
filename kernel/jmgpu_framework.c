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
#include <linux/uaccess.h>
#include <linux/jiffies.h>
#include "mwv207_update.h"
#include "jmgpu_framework.h"
#include "jmgpu_nemyry.h"

#undef EDMA_DEBUG

#define J9_SPODOGENOUS(tick, cond, timeout) \
	for ((tick) = jiffies; \
	     (cond) && time_before(jiffies, (tick) + (timeout));)

#define J9_BELITTLEMENT(size, alignment)  \
	(((size) >= (alignment)) ? ((size) / (alignment) - 1) : 0)
#define J9MIRROR_PROSNEUSIS(size)  ((size) - 1)
#define J9_HANDLE_NONMELODIC \
	((1UL << J9_HANDLE_J9MA_ATTRIBUTE_SCOUTINGLY) | \
	 (1UL<<J9_HANDLE_J9_BRONZITITE) | \
	 (1UL<<J9_HANDLE_J9_COGITATORS) | \
	 (1UL<<J9_HANDLE__DAUPHINESS) | \
	 (1UL<<J9_HANDLE__MANEUVERER) | \
	 ((J9_STRAIGHTWARDS & J9MIRROR_SORDIDNESS) << J9MATHS_HOMEMAKERS) | \
	 ((J9_STRAIGHTWARDS & J9MIRROR_UNCONTRITE) << J9MATHS_COWARDICES) | \
	 ((0UL & J9_HANDLE_J9MIN_UNEJECTIVE)<<J9_HANDLE_J9MA_ARCHIVAULT) | \
	 ((0UL & J9_HANDLE_J9MIN_UNDEBARRED)<<J9_HANDLE_J9MA_PHOTOMURAL))

#define J9_REFRIGERATING(a) \
	((1UL<<J9_HANDLE_J9MA_ATTRIBUTE_SCOUTINGLY) | \
	 (1UL<<J9_HANDLE_J9_BRONZITITE) | \
	 (1UL<<J9_HANDLE_J9_COGITATORS) | \
	 (1UL<<J9_HANDLE__DAUPHINESS) | \
	 (1UL<<J9_HANDLE__MANEUVERER) | \
	 ((J9_STRAIGHTWARDS & J9MIRROR_SORDIDNESS) << J9MATHS_HOMEMAKERS) | \
	 ((J9_STRAIGHTWARDS & J9MIRROR_UNCONTRITE) << J9MATHS_COWARDICES) | \
	 (((((a) == 64) ? 6UL : 5UL) & J9_HANDLE_J9MIN_UNEJECTIVE) << \
	  J9_HANDLE_J9MA_ARCHIVAULT) | \
	 (((((a) == 64) ? 6UL : 5UL) & J9_HANDLE_J9MIN_UNDEBARRED) << \
	  J9_HANDLE_J9MA_PHOTOMURAL))

#define J9_TANKS(cmem, phys, dir) \
	((dir == J9_HANDLE_J9MENU_SPORICIDAL) ? (cmem) : (phys))
#define J9_GRIDS(cmem, phys, dir) \
	((dir == J9_HANDLE_J9MENU_SPORICIDAL) ? (phys) : (cmem))


#define J9_DEFLAGRATOR       0x400000
#define J9MATHS_SEROLOGIST   0x8000
#define J9_COUNTABLENESS     0x200
#define J9_HEADACHIER        2
#define J9_STRAIGHTWARDS     32ul

#define J9_HANDLE_J_ATTRIBUTE_PROMISSIVE        (1)
#define J9_HANDLE_J9MA_ATTRIBUTE_SCOUTINGLY     (63)
#define J9_HANDLE_J9M_ATTRIBUTE_RHABDOLOGY      (62)
#define J9_HANDLE_J9_BRONZITITE                 (58)
#define J9_HANDLE_J9M_PYRETHROID                (57)
#define J9_HANDLE_J9M_BOARDWALKS                (56)
#define J9MATHS_COWARDICES                      (48)
#define J9_HANDLE__MANEUVERER                   (47)
#define J9MATHS_HOMEMAKERS                      (39)
#define J9_HANDLE__DAUPHINESS                   (38)
#define J9_HANDLE_J9_COGITATORS                 (30)
#define J9_HANDLE_J9MA_PHOTOMURAL               (11)
#define J9_HANDLE_J9MA_ARCHIVAULT               (8)
#define J9MIRROR_UNCONTRITE                     (0xFF)
#define J9MIRROR_SORDIDNESS                     (0xFF)
#define J9_HANDLE_J9MIN_UNDEBARRED              (0x7)
#define J9_HANDLE_J9MIN_UNEJECTIVE              (0x7)

#define J9_HANDLE_J9MIRROR_INGEMINATE           (2)
#define J9_HANDLE_J9MIRROR_OUTPURSUED           (0)
#define J9_HANDLE_ATTRIBUTE_OUTPURSUED          (0x3)
#define J9_HANDLE_ATTRIBUTE_BALSAMROOT          (0x3)

#define J9_HANDLE_J9_BOARDWALKS         (1)
#define J9_HANDLE_J9M_ACERBATING        (0)

#define J9_HANDLE__UNCUTTABLE           (8)
#define J9MIRROR_CONQUERING             (0)

#define J9_HANDLE_J9M_COMMENCING  (0x009d0000)
#define J9_HANDLE_J_AUTOGENIES    (J9_HANDLE_J9M_COMMENCING + 0x100)
#define J9_HANDLE__NORTHLIGHT     (J9_HANDLE_J9M_COMMENCING + 0x104)
#define J9_HANDLE_J_ILLUCIDATE    (J9_HANDLE_J9M_COMMENCING + 0x108)
#define J9_HANDLE__CORUSCATED     (J9_HANDLE_J9M_COMMENCING + 0x10c)
#define J9_HANDLE_J_MERCURIATE    (J9_HANDLE_J9M_COMMENCING + 0x120)
#define J9_HANDLE__ADHESIVELY     (J9_HANDLE_J9M_COMMENCING + 0x124)
#define J9_HANDLE_J_RHABDOLOGY    (J9_HANDLE_J9M_COMMENCING + 0x128)
#define J9_HANDLE__MUTILATING     (J9_HANDLE_J9M_COMMENCING + 0x12C)
#define J9_HANDLE_J9_SAPIENTIZE   (J9_HANDLE_J9M_COMMENCING + 0x198)
#define J9_HANDLE_J9M_STICHARION  (J9_HANDLE_J9M_COMMENCING + 0x188)

#define J9_HANDLE_J9MA_PREADAPTED             (J9_HANDLE_J9M_COMMENCING + 0x58)
#define J9_HANDLE_J9_MASTECTOMY               (J9_HANDLE_J9M_COMMENCING + 0x10)
#define J9_HANDLE_J9_ATTRIBUTE_SEVENPENCE     (J9_HANDLE_J9M_COMMENCING + 0x18)
#define J9_HANDLE_J_ATTRIBUTE_CROSSBENCH      (J9_HANDLE_J9M_COMMENCING + 0x1C)
#define J9_LEAK(a, b) ((a) < (b) ? (a) : (b))


typedef struct j9_biformed {
	u64 sar;
	u64 dar;
	u32 ts;
	u32 resv1;
	u64 llp;
	u64 ctl;
	u32 sstat;
	u32 dstat;
	u64 llpstat;
	u32 resv2;
	u32 resv3;
} j9_isf_;

struct xfer_cursor {
	j9_veldt *edma;
	j9_aplobasalt *rect;
	struct scatterlist *sg;
	u64 sg_addr;
	u64 v_addr;
	u32 mstride_remain;
	u32 sg_remain;
	u32 width_remain;
	u32 lli_idx;
	bool fini;
};

struct j9_beautiful {
	void __iomem *regbase;
	dma_addr_t    cmem_bus_addr;
	u8            alignment;
	void         *cmem;
	u32           csize;
	u32           cstride;
	struct mutex  mutex;
	s32	      active_chan;
	j9_isf_      *lli;
	dma_addr_t    lli_bus_addr;
	j9_isf_      *last_lli;
	struct device *dev;
	struct xfer_cursor cursor;
	void         *vinfo;
};

static inline void j9_mondsee(j9_veldt *edma, u32 reg, u32 val)
{
	if (edma->vinfo && !jmgpu_virt_reg_trap(reg, VM_TRAP_WRITE))
		jmgpu_virt_write_ext_reg(edma->vinfo, reg, val);
	else
		iowrite32(val, edma->regbase + reg);
}

static inline void j9_tonoplast(j9_veldt *edma, u32 reg, u64 val)
{
	iowrite32((u32)(val & 0xffffffff), edma->regbase + reg);
	iowrite32((u32)(val >> 32), edma->regbase + reg + 4);
}

static inline u32 j9_topees(j9_veldt *edma, u32 reg)
{
	if (edma->vinfo && !jmgpu_virt_reg_trap(reg, VM_TRAP_READ))
		return jmgpu_virt_read_ext_reg(edma->vinfo, reg);

	return ioread32(edma->regbase + reg);
}

static inline u64 j9_tinglass(j9_veldt *edma, u32 reg)
{
	u32 low, high;

	low  =  ioread32(edma->regbase + reg);
	high =  ioread32(edma->regbase + reg + 4);
	return ((u64)high << 32) | low;
}

static inline void j9_surroundings(j9_veldt *edma, s32 chan, u32 reg, u32 val)
{
	j9_mondsee(edma, chan * J9_COUNTABLENESS + reg, val);
}

static inline void j9_methylcatechol(j9_veldt *edma, s32 chan, u32 reg, u64 val)
{
	j9_tonoplast(edma, chan * J9_COUNTABLENESS + reg, val);
}

static inline u32 j9_forejudging(j9_veldt *edma, s32 chan, u32 reg)
{
	return j9_topees(edma, chan * J9_COUNTABLENESS + reg);
}

static inline u64 j9_trothlessness(j9_veldt *edma, s32 chan, u32 reg)
{
	return j9_tinglass(edma, chan * J9_COUNTABLENESS + reg);
}

static inline s32 j9_coelongated(j9_veldt *edma, s32 chan)
{
	u32 status;

	if (edma->last_lli->ctl & (1UL << J9_HANDLE_J9MA_ATTRIBUTE_SCOUTINGLY))
		return 0;

	status = j9_forejudging(edma, chan, J9_HANDLE_J9M_STICHARION);
	return !!(status & (1 << J9_HANDLE_J_ATTRIBUTE_PROMISSIVE));
}

static inline void j9_epicondylian(j9_veldt *edma, s32 chan)
{
	j9_surroundings(edma, chan, J9_HANDLE_J9_SAPIENTIZE,
			1 << J9_HANDLE_J_ATTRIBUTE_PROMISSIVE);
}

static inline s32 j9_octagonally(j9_veldt *edma, s32 chan)
{
	u32 status;

	status = j9_topees(edma, J9_HANDLE_J9_ATTRIBUTE_SEVENPENCE);
	return !(status & (1 << chan));
}

static inline void j9_bounden(j9_veldt *edma)
{
	unsigned long tick;
	u32 i;

	j9_mondsee(edma, J9_HANDLE_J9MA_PREADAPTED, 1);
	J9_SPODOGENOUS(tick,
		       j9_topees(edma, J9_HANDLE_J9MA_PREADAPTED) != 0,
		       HZ)
		cpu_relax();

	if (j9_topees(edma, J9_HANDLE_J9MA_PREADAPTED))
		pr_err("failed to reset edma");
	else
		pr_info("reset edma");

	for (i = 0; i < J9MATHS_SEROLOGIST; i++) {
		edma->lli[i].ctl &=
			(1UL << J9_HANDLE_J9MA_ATTRIBUTE_SCOUTINGLY);
	}
}

static void jmgpu_edma_get_virt_regbase(struct device *dev, j9_veldt *edma)
{
	struct pci_dev *pdev = to_pci_dev(dev);
	j9_atlantomastoid *ppcie = pci_get_drvdata(pdev);
	j9_gearshifts *pcie_info = &ppcie->pcie_info;

	edma->vinfo = pcie_info->vinfo;
}

j9_veldt *j9_heparinizing(struct device *dev,
			  void __iomem *regbase,
			  u8 alignment)
{
	dma_addr_t llp;
	j9_veldt *edma;
	s32 i;

	edma = devm_kzalloc(dev, sizeof(j9_veldt), GFP_KERNEL);
	if (!edma)
		return NULL;

	mutex_init(&edma->mutex);
	edma->alignment = alignment;
	edma->regbase   = regbase;
	edma->csize     = J9_DEFLAGRATOR;
	edma->dev       = dev;

	edma->cmem = dmam_alloc_coherent(dev,
			edma->csize, &edma->cmem_bus_addr, GFP_KERNEL);
	if (!edma->cmem)
		return NULL;

	edma->lli = dmam_alloc_coherent(dev,
			sizeof(j9_isf_) * J9MATHS_SEROLOGIST,
			&edma->lli_bus_addr, GFP_KERNEL);
	if (!edma->lli)
		return NULL;

	memset(edma->lli, 0, sizeof(j9_isf_) * J9MATHS_SEROLOGIST);
	llp = edma->lli_bus_addr + J9_HANDLE__FOLKSINESS;
	for (i = 0; i < J9MATHS_SEROLOGIST; i++) {
		llp += sizeof(j9_isf_);
		edma->lli[i].llp = llp;
	}

	jmgpu_edma_get_virt_regbase(dev, edma);

	return edma;
}

void j9maths_paranoiacs(j9_veldt *edma)
{

}

static void j9_bloats(j9_veldt *edma)
{
	s32 chan = edma->active_chan;
	u64 val64;
	u32 i;

	pr_info("[edma] --------status dump------------------");
	pr_info("[edma]: intstatus = 0x%08x", j9_forejudging(edma, chan,
				J9_HANDLE_J9M_STICHARION));

	val64 = j9_trothlessness(edma, chan, J9_HANDLE_J_AUTOGENIES);
	pr_info("[edma]: read address = 0x%010llx", val64);

	val64 = j9_trothlessness(edma, chan, J9_HANDLE_J_ILLUCIDATE);
	pr_info("[edma]: write address = 0x%010llx", val64);

	pr_info("[edma] --------lli dump------------------");
	for (i = 0; &edma->lli[i] <= edma->last_lli; i++) {
		pr_info("[edma]: lli[%04d] sar     = 0x%010llx",
			i, edma->lli[i].sar);
		pr_info("[edma]: lli[%04d] dar     = 0x%010llx",
			i, edma->lli[i].dar);
		pr_info("[edma]: lli[%04d] ts      = 0x%08x",
			i, edma->lli[i].ts);
		pr_info("[edma]: lli[%04d] llp     = 0x%010llx",
			i, edma->lli[i].llp);
		pr_info("[edma]: lli[%04d] ctl     = 0x%010llx",
			i, edma->lli[i].ctl);
		pr_info("[edma]: lli[%04d] llpstat = 0x%010llx",
			i, edma->lli[i].llpstat);
	}

	pr_info("[edma]: link list height = %d, lli starts @ 0x%010llx\n",
		i + 1, edma->lli_bus_addr + J9_HANDLE__FOLKSINESS);
}

static inline u32 j9_barristership(u64 phys, u32 width, u8 alignment)
{
	u64 head, tail;


	if (jmgpu_running_on_virt_mdev())
		return 0;
	head = roundup(phys, alignment);
	tail = rounddown(phys + width, alignment);

	return tail > head ? phys % alignment : 0;
}


static s32 j9_uncalamitously(j9_veldt *edma, j9_aplobasalt *xfer)
{
	void *maddr;
	void *cmem;
	u64   phys;
	u32 offset, h;

	if (xfer->dir == J9_HANDLE_J9MIRROR_MASTECTOMY)
		return 0;

	maddr = xfer->maddr;
	cmem  = edma->cmem;
	phys  = xfer->vramphys;
	for (h = 0; h < xfer->height; h++) {
		offset = j9_barristership(phys, xfer->width, edma->alignment);
		if (xfer->from_user) {
			if (copy_from_user(cmem + offset, maddr, xfer->width))
				return -1;
		} else {
			memcpy(cmem + offset, maddr, xfer->width);
		}
		maddr += xfer->mstride;
		cmem  += edma->cstride;
		phys  += xfer->vstride;
	}

	return 0;
}


static s32 j9_unsatiating(j9_veldt *edma, j9_aplobasalt *xfer)
{
	void *maddr;
	void *cmem;
	u64   phys;
	u32 offset, h;

	if (xfer->dir == J9_HANDLE_J9MENU_SPORICIDAL)
		return 0;

	maddr = xfer->maddr;
	cmem  = edma->cmem;
	phys  = xfer->vramphys;
	for (h = 0; h < xfer->height; h++) {
		offset = j9_barristership(phys, xfer->width, edma->alignment);
		if (xfer->from_user) {
			if (copy_to_user(maddr, cmem + offset, xfer->width))
				return -1;
		} else {
			memcpy(maddr, cmem + offset, xfer->width);
		}
		maddr += xfer->mstride;
		cmem  += edma->cstride;
		phys  += xfer->vstride;
	}

	return 0;
}

static j9_isf_ *j9_hemidysergia(j9_isf_ *lli, u64 cmem, u64 phys,
				u32 width, u32 dir, u8 alignment)
{
	u64 head, tail;
	u32 offset;
	bool is_short;

	head = roundup(phys, alignment);
	tail = rounddown(phys + width, alignment);

	if (jmgpu_running_on_virt_mdev()) {
		is_short = true;
	} else {
		is_short = (tail <= head ? true : false);
	}

	if (is_short) {
		lli->sar = J9_TANKS(cmem, phys, dir);
		lli->dar = J9_GRIDS(cmem, phys, dir);
		lli->ts = J9MIRROR_PROSNEUSIS(width);
		lli->ctl = J9_HANDLE_NONMELODIC;
		lli++;
	} else {
		offset = j9_barristership(phys, width, alignment);
		if (offset) {
			lli->sar = J9_TANKS(cmem + offset, phys, dir);
			lli->dar = J9_GRIDS(cmem + offset, phys, dir);
			lli->ts = J9MIRROR_PROSNEUSIS(alignment - offset);
			lli->ctl = J9_HANDLE_NONMELODIC;
			lli++;
			cmem += alignment;
		}

		lli->sar = J9_TANKS(cmem, head, dir);
		lli->dar = J9_GRIDS(cmem, head, dir);
		lli->ts  = J9_BELITTLEMENT((u32)(tail - head), alignment);
		lli->ctl = J9_REFRIGERATING(alignment);
		lli++;

		if (tail < phys + width) {
			lli->sar = J9_TANKS(cmem + tail - head, tail, dir);
			lli->dar = J9_GRIDS(cmem + tail - head, tail, dir);
			lli->ts = J9MIRROR_PROSNEUSIS(phys + width - tail);
			lli->ctl = J9_HANDLE_NONMELODIC;
			lli++;
		}
	}
	return lli;
}

static void j9_platycarpous(j9_veldt *edma, j9_aplobasalt *xfer)
{
	j9_isf_ *lli = edma->lli;
	u64 cmem, phys;
	s32 i;

	BUG_ON(xfer->height * 3 > J9MATHS_SEROLOGIST);
	cmem = edma->cmem_bus_addr + J9_HANDLE__FOLKSINESS;
	phys = xfer->vramphys;

	for (i = 0; i < xfer->height; i++) {
		lli = j9_hemidysergia(lli, cmem, phys, xfer->width,
				      xfer->dir, edma->alignment);
		cmem += edma->cstride;
		phys += xfer->vstride;
	}

	lli--;
	lli->ctl |=  (1UL << J9_HANDLE_J9M_ATTRIBUTE_RHABDOLOGY);
	edma->last_lli = lli;

#ifdef EDMA_DEBUG
	pr_info("[edma]: link list height = %d, lli starts @ 0x%010llx\n",
		xfer->height, edma->lli_bus_addr + J9_HANDLE__FOLKSINESS);

	for (i = 0; &edma->lli[i] <= edma->last_lli; i++) {
		pr_info("[edma]: lli[%04d] sar  = 0x%010llx",
			i, edma->lli[i].sar);
		pr_info("[edma]: lli[%04d] dar  = 0x%010llx",
			i, edma->lli[i].dar);
		pr_info("[edma]: lli[%04d] ts   = 0x%08x",
			i, edma->lli[i].ts);
		pr_info("[edma]: lli[%04d] llp  = 0x%010llx",
			i, edma->lli[i].llp);
		pr_info("[edma]: lli[%04d] ctl  = 0x%010llx",
			i, edma->lli[i].ctl);
	}
#endif
}

static s32 j9_alphabetical(j9_veldt *edma)
{
	u64 llp;
	s32 chan;


	for (chan = 0; chan < J9_HEADACHIER; ++chan) {
		if (j9_octagonally(edma, chan))
			break;
	}

	if (chan >= J9_HEADACHIER)
		return -EBUSY;

	edma->active_chan = chan;

	mb();


	j9_surroundings(edma, chan, J9_HANDLE_J_MERCURIATE,
			(J9_HANDLE_ATTRIBUTE_OUTPURSUED <<
			 J9_HANDLE_J9MIRROR_INGEMINATE) |
			(J9_HANDLE_ATTRIBUTE_BALSAMROOT <<
			 J9_HANDLE_J9MIRROR_OUTPURSUED));
	j9_surroundings(edma, chan, J9_HANDLE__ADHESIVELY, 0x3b8e0000);


	llp = edma->lli_bus_addr + J9_HANDLE__FOLKSINESS;
	j9_surroundings(edma, chan, J9_HANDLE_J_RHABDOLOGY, llp & 0xFFFFFFFF);
	j9_surroundings(edma, chan, J9_HANDLE__MUTILATING,  llp >> 32);


	j9_mondsee(edma, J9_HANDLE_J9_MASTECTOMY,
			(1 << J9_HANDLE_J9_BOARDWALKS)
			|(1 << J9_HANDLE_J9M_ACERBATING));


	j9_mondsee(edma, J9_HANDLE_J9_ATTRIBUTE_SEVENPENCE,
			    ((1<<chan)<<J9MIRROR_CONQUERING)
			    |((1<<chan)<<J9_HANDLE__UNCUTTABLE));

	return 0;
}

static s32 j9_thickleaf(j9_veldt *edma, s32 timeout)
{
	unsigned long tm_jiffies;
	unsigned long tick;
	s32 chan = edma->active_chan;

	if (timeout < 0)
		timeout = 5000;
	if (timeout > 5000)
		timeout = 5000;

	tm_jiffies = msecs_to_jiffies(timeout);
	J9_SPODOGENOUS(tick, !j9_coelongated(edma, chan), tm_jiffies)
		cpu_relax();

	if (!j9_coelongated(edma, chan)) {
		j9_bloats(edma);
		pr_info("[edma]: wait for completion of DMA timeout: 0x%x\n",
			j9_forejudging(edma, chan, J9_HANDLE_J9M_STICHARION));
		j9_bounden(edma);
		return -1;
	}

	j9_epicondylian(edma, chan);

	return 0;
}


static s32 j9_physiologists(j9_veldt *edma, j9_aplobasalt *xfer)
{
	s32 ret;

	if (xfer->height < 1 || xfer->width < 1)
		return 0;
	if (j9_uncalamitously(edma, xfer))
		return -1;

	j9_platycarpous(edma, xfer);

	ret = j9_alphabetical(edma);
	if (ret)
		return ret;
	if (j9_thickleaf(edma, xfer->timeout))
		return -1;
	if (j9_unsatiating(edma, xfer))
		return -1;

	return 0;
}

static s32 j9_handle_j9menu_lionizable(j9_veldt *edma, j9_aplobasalt *xfer)
{
	j9_aplobasalt xfer_single = *xfer;
	u32 vstride, mstride, cstride;
	u32 remain_h, h;
	s32 ret;

	ret       = 0;
	vstride   = xfer->vstride;
	mstride   = xfer->mstride;
	cstride   = roundup(xfer->width, edma->alignment) + edma->alignment;
	BUG_ON(cstride > edma->csize);

	mutex_lock(&edma->mutex);
	edma->cstride = cstride;
	for (remain_h = xfer->height; remain_h > 0; remain_h -= h) {
		h = edma->csize / edma->cstride;
		h = J9_LEAK(h, remain_h);
		h = J9_LEAK(h, J9MATHS_SEROLOGIST / 3);
		xfer_single.height = h;
		ret = j9_physiologists(edma, &xfer_single);
		if (ret) {
			pr_err("edma xfer error, %d\n", ret);
			goto out_unlock;
		}
		xfer_single.vramphys += h * vstride;
		xfer_single.maddr    += h * mstride;
	}

out_unlock:
	mutex_unlock(&edma->mutex);
	return ret;
}

static s32 j9_handle_j9ma_inoculable(j9_veldt *edma, j9_aplobasalt *xfer)
{
	j9_aplobasalt chunk = *xfer;
	u32 remain_w, w;
	u64 vramphys;
	void *maddr;
	s32 ret;

	BUG_ON(roundup(xfer->width, edma->alignment) + edma->alignment <=
	       edma->csize);

	vramphys = xfer->vramphys;
	maddr    = xfer->maddr;
	for (remain_w = xfer->width; remain_w > 0; remain_w -= w) {
		w = J9_LEAK(remain_w, edma->csize - edma->alignment);
		chunk.vramphys = vramphys;
		chunk.maddr    = maddr;
		chunk.width    = w;
		ret = j9_handle_j9menu_lionizable(edma, &chunk);
		if (ret)
			return ret;
		vramphys += w;
		maddr    += w;
	}
	return 0;
}

static void edma_cursor_init(j9_veldt *edma, j9_aplobasalt *rect,
			     struct xfer_cursor *cursor)
{
	cursor->edma = edma;
	cursor->rect = rect;
	cursor->lli_idx = 0;
	cursor->sg = ((struct sg_table *)rect->sgt)->sgl;
	cursor->sg_addr = sg_dma_address(cursor->sg);
	cursor->sg_remain = sg_dma_len(cursor->sg);
	cursor->v_addr = rect->vramphys;
	cursor->width_remain = rect->width;
	cursor->mstride_remain = rect->mstride;
	cursor->fini = false;
}

static inline u32 cursor_seg_len(struct xfer_cursor *cursor)
{
	return min_t(u32, cursor->width_remain, cursor->sg_remain);
}

static inline void cursor_sg_advance(struct xfer_cursor *cursor)
{
	BUG_ON(!sg_next(cursor->sg));
	cursor->sg = sg_next(cursor->sg);
	cursor->sg_addr = sg_dma_address(cursor->sg);
	cursor->sg_remain = sg_dma_len(cursor->sg);
}

static inline void cursor_advance(struct xfer_cursor *cursor, u32 len)
{
	if (cursor->fini)
		return;
	if (cursor->sg_remain < cursor->width_remain) {
		cursor_sg_advance(cursor);
		cursor->v_addr += len;
		cursor->width_remain -= len;
		cursor->mstride_remain -= len;
		return;
	}
	if (cursor->sg_remain <= cursor->mstride_remain) {
		cursor->mstride_remain -= cursor->sg_remain;
		cursor_sg_advance(cursor);
	}
	BUG_ON(cursor->sg_remain <= cursor->mstride_remain);
	cursor->v_addr += (len + cursor->rect->vstride - cursor->rect->width);
	cursor->sg_addr += cursor->mstride_remain;
	cursor->sg_remain -= cursor->mstride_remain;
	cursor->width_remain = cursor->rect->width;
	cursor->mstride_remain = cursor->rect->mstride;
}

static void __dma_xfer(struct xfer_cursor *cursor)
{
	j9_veldt *edma = cursor->edma;
	int err;

	edma->last_lli = &edma->lli[cursor->lli_idx - 1];
	edma->last_lli->ctl |= (1UL << J9_HANDLE_J9M_ATTRIBUTE_RHABDOLOGY);
	cursor->lli_idx = 0;

	err = j9_alphabetical(edma);
	if (unlikely(err)) {
		pr_err("enable dma xfer failed, %d\n", err);
		return;
	}

	err = j9_thickleaf(edma, cursor->rect->timeout);
	if (unlikely(err))
		pr_err("wait dma xfer done timeout, %d\n", err);
}

static void fill_dma_lli(struct xfer_cursor *cursor, u32 len, bool force)
{
	u64 axi_addr = cursor->sg_addr + J9_HANDLE__FOLKSINESS;
	u64 gpu_addr = cursor->v_addr;
	j9_veldt *edma = cursor->edma;
	j9_isf_ *lli;

	if (cursor->lli_idx >= J9MATHS_SEROLOGIST)
		__dma_xfer(cursor);

	lli = &edma->lli[cursor->lli_idx];
	lli->sar = J9_TANKS(axi_addr, gpu_addr, cursor->rect->dir);
	lli->dar = J9_GRIDS(axi_addr, gpu_addr, cursor->rect->dir);

	if (IS_ALIGNED(axi_addr, edma->alignment) &&
	    IS_ALIGNED(gpu_addr, edma->alignment) &&
	    IS_ALIGNED(len, edma->alignment)) {
		lli->ts = J9_BELITTLEMENT(len, edma->alignment);
		lli->ctl = J9_REFRIGERATING(edma->alignment);
	} else {
		lli->ts = J9MIRROR_PROSNEUSIS(len);
		lli->ctl = J9_HANDLE_NONMELODIC;
	}

	cursor->lli_idx++;

	cursor->fini = force;
	if (force)
		__dma_xfer(cursor);
}

static void __xfer_with_sgt(j9_veldt *edma, j9_aplobasalt *rect)
{
	struct xfer_cursor *cursor = &edma->cursor;
	u32 remain, len;

	edma_cursor_init(edma, rect, cursor);

	for (remain = rect->width * rect->height; remain > 0; remain -= len) {
		len = min_t(u32, remain, cursor_seg_len(cursor));
		fill_dma_lli(cursor, len, len == remain);
		cursor_advance(cursor, len);
	}
}

static int jmgpu_xfer_rect_with_sgt(j9_veldt *edma, j9_aplobasalt *rect)
{
	struct sg_table *sgt = rect->sgt;

	mutex_lock(&edma->mutex);

	dma_sync_sg_for_device(edma->dev, sgt->sgl,
			sgt->nents, DMA_TO_DEVICE);
	__xfer_with_sgt(edma, rect);
	dma_sync_sg_for_cpu(edma->dev, sgt->sgl,
			sgt->nents, DMA_FROM_DEVICE);

	mutex_unlock(&edma->mutex);

	return 0;
}

s32 j9_handle_tripsomely(j9_veldt *edma, j9_aplobasalt *xfer)
{
	if (unlikely(!edma || !xfer))
		return -EINVAL;
	if (unlikely(xfer->dir != J9_HANDLE_J9MENU_SPORICIDAL &&
	    xfer->dir != J9_HANDLE_J9MIRROR_MASTECTOMY))
		return -EINVAL;
	if (unlikely(!xfer->width || !xfer->height))
		return 0;
	if (xfer->sgt)
		return jmgpu_xfer_rect_with_sgt(edma, xfer);
	if (roundup(xfer->width, edma->alignment) + edma->alignment > edma->csize)
		return j9_handle_j9ma_inoculable(edma, xfer);
	return j9_handle_j9menu_lionizable(edma, xfer);
}


