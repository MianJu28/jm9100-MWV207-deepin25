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


#include "jmgpu_through.h"
#include "jmgpu_script.h"

#include <linux/pagemap.h>
#include <linux/seq_file.h>
#include <linux/mman.h>
#include <asm/atomic.h>
#include <linux/dma-mapping.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)
#include <linux/dma-direct.h>
#endif
#include <linux/slab.h>
#include <linux/platform_device.h>
#if defined(CONFIG_X86)
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 12, 0)
#include <asm/set_memory.h>
#endif
#endif
#if J9_HANDLE_J9MIN_POLITICISE
#include <linux/log2.h>
#include <linux/bitmap.h>
#endif

#define J9_ACESODYNE    J9_PASTURES
#define  J9_MATRIARCHALISM  0x400000UL
#define  J9_RUBBERNECKER    (J9_MATRIARCHALISM / PAGE_SIZE)

typedef struct tag_jms_DMA_PRIV *jmsDMA_PRIV_PTR;
typedef struct tag_jms_DMA_PRIV {
	atomic_t usage;
#if J9_HANDLE_J9MIN_POLITICISE
	jmtPOINTER fa_vaddr;
	dma_addr_t fa_daddr;
	struct device *dev;
	struct mutex lock;
	DECLARE_BITMAP(fast_alloc_map, J9_RUBBERNECKER);
#endif
} j9_squallery;

struct mdl_dma_priv {
	jmtPOINTER kvaddr;
	dma_addr_t dmaHandle;
#if J9_HANDLE_J9MIN_POLITICISE
	jmtBOOL isFastAlloc;
	jmtUINT32 fa_offset;
#endif
	struct sg_table sgt;
	struct list_head sgt_list;
	struct mutex sgt_mutex;
	struct sg_table *last_sgt;
	unsigned int last_offset;
	int list_count;
};

static int j9_neoclassicists(struct seq_file *m, void *data)
{
	j9_undissuade *node = m->private;
	jmkALLOCATOR Allocator = node->device;
	jmsDMA_PRIV_PTR priv = Allocator->privateData;
	long long usage = (long long)atomic_read(&priv->usage);

	seq_puts(m, "type        n pages        bytes\n");
	seq_printf(m, "normal   %10llu %12llu\n", usage, usage * PAGE_SIZE);

	return 0;
}

#if J9_HANDLE_J9MIN_POLITICISE
static int j9mirror_planetoids(struct seq_file *m, void *data)
{
	j9_undissuade *node = m->private;
	jmkALLOCATOR Allocator = node->device;
	jmsDMA_PRIV_PTR priv = Allocator->privateData;
	int usage;

	if (!priv->fa_vaddr) {
		usage = 0;
	} else {
		mutex_lock(&priv->lock);
		usage = bitmap_weight(priv->fast_alloc_map, J9_RUBBERNECKER);
		mutex_unlock(&priv->lock);
	}

	seq_puts(m, "n pages\t bytes\n");
	seq_printf(m, "%d\t %ld\n", usage, usage * PAGE_SIZE);

	return 0;
}
#endif

static j9_cadee InfoList[] = {
	{ "dmausage", j9_neoclassicists },
#if J9_HANDLE_J9MIN_POLITICISE
	{ "fausage", j9mirror_planetoids },
#endif
};

static void j9_shrewdest(IN jmkALLOCATOR Allocator, IN jmkDEBUGFS_DIR Root)
{
	j9_palladinize(jmkDEBUGFS_DIR_Init
		       (&Allocator->debugfsDir, Root->root, "dma"));

	j9_palladinize(jmkDEBUGFS_DIR_CreateFiles(&Allocator->debugfsDir,
						  InfoList,
						  J9_SANDBARS(InfoList),
						  Allocator));
}

static void j9_specialities(IN jmkALLOCATOR Allocator)
{
	j9_palladinize(jmkDEBUGFS_DIR_RemoveFiles(&Allocator->debugfsDir,
						  InfoList,
						  J9_SANDBARS(InfoList)
		       ));

	jmkDEBUGFS_DIR_Deinit(&Allocator->debugfsDir);
}

#if J9_HANDLE_J9MIN_POLITICISE
static void dma_free_contig(struct device *dev, size_t size,
			    void *cpu_addr, dma_addr_t dma_addr)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 8, 0)
	DEFINE_DMA_ATTRS(attrs);

#ifdef OS_IS_SERVER
	if (dev->iommu_group)
		dma_set_attr(0x0, &attrs);
	else
		dma_set_attr(DMA_ATTR_FORCE_CONTIGUOUS, &attrs);
#else
	dma_set_attr(DMA_ATTR_FORCE_CONTIGUOUS, &attrs);
#endif

	return dma_free_attrs(dev, size, cpu_addr, dma_addr, &attrs);
#else
#ifdef OS_IS_SERVER
	if (dev->iommu_group) {
		return dma_free_attrs(dev, size, cpu_addr, dma_addr,
			      0x0);
	} else {
		return dma_free_attrs(dev, size, cpu_addr, dma_addr,
			      DMA_ATTR_FORCE_CONTIGUOUS);
	}
#else
	return dma_free_attrs(dev, size, cpu_addr, dma_addr,
			DMA_ATTR_FORCE_CONTIGUOUS);
#endif
#endif
}

static void *dma_alloc_contig(struct device *dev, size_t size,
			      dma_addr_t *dma_addr, gfp_t gfp)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 8, 0)
	DEFINE_DMA_ATTRS(attrs);
#ifdef OS_IS_SERVER
	if (dev->iommu_group)
		dma_set_attr(0x0, &attrs);
	else
		dma_set_attr(DMA_ATTR_FORCE_CONTIGUOUS, &attrs);
#else
	dma_set_attr(DMA_ATTR_FORCE_CONTIGUOUS, &attrs);
#endif

	return dma_alloc_attrs(dev, size, dma_addr, gfp, &attrs);
#else
#ifdef OS_IS_SERVER
	if (dev->iommu_group) {
		return dma_alloc_attrs(dev, size, dma_addr, gfp,
			       0x0);
	} else {
		return dma_alloc_attrs(dev, size, dma_addr, gfp,
			       DMA_ATTR_FORCE_CONTIGUOUS);
	}
#else
	return dma_alloc_attrs(dev, size, dma_addr, gfp,
		       DMA_ATTR_FORCE_CONTIGUOUS);
#endif
#endif
}

static int dma_mmap_contig(struct device *dev, struct vm_area_struct *vma,
	       void *cpu_addr, dma_addr_t dma_addr, size_t size)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 8, 0)
	DEFINE_DMA_ATTRS(attrs);

#ifdef OS_IS_SERVER
	if (dev->iommu_group)
		dma_set_attr(0x0, &attrs);
	else
		dma_set_attr(DMA_ATTR_FORCE_CONTIGUOUS, &attrs);
#else
	dma_set_attr(DMA_ATTR_FORCE_CONTIGUOUS, &attrs);
#endif

	return dma_mmap_attrs(dev, vma, cpu_addr, dma_addr, size, &attrs);
#else
#ifdef OS_IS_SERVER
	if (dev->iommu_group) {
		return dma_mmap_attrs(dev, vma, cpu_addr, dma_addr, size,
				0x0);
	} else {
		return dma_mmap_attrs(dev, vma, cpu_addr, dma_addr, size,
				DMA_ATTR_FORCE_CONTIGUOUS);
	}
#else
	return dma_mmap_attrs(dev, vma, cpu_addr, dma_addr, size,
			DMA_ATTR_FORCE_CONTIGUOUS);
#endif
#endif
}

static jmtPOINTER
j9_gastrogenital(IN jmsDMA_PRIV_PTR allocatorPriv,
		 IN jmtSIZE_T NumPages,
		 OUT dma_addr_t *handle, OUT jmtUINT32 *offset)
{
	int off, order;

	if (!allocatorPriv->fa_vaddr || NumPages == 1)
		return J9_CHYAK;

	order = order_base_2(NumPages);
	mutex_lock(&allocatorPriv->lock);
	off =
	    bitmap_find_free_region(allocatorPriv->fast_alloc_map,
				    J9_RUBBERNECKER, order);
	mutex_unlock(&allocatorPriv->lock);
	if (off >= 0) {
		*offset = off;
		*handle = allocatorPriv->fa_daddr + PAGE_SIZE * off;
		return allocatorPriv->fa_vaddr + PAGE_SIZE * off;
	}

	return J9_CHYAK;
}

static void
j9_squamocellular(IN jmsDMA_PRIV_PTR allocatorPriv,
		  IN jmtSIZE_T NumPages, IN jmtUINT32 offset)
{
	BUG_ON(!allocatorPriv->fa_vaddr);
	mutex_lock(&allocatorPriv->lock);
	bitmap_release_region(allocatorPriv->fast_alloc_map, offset,
			      order_base_2(NumPages));
	mutex_unlock(&allocatorPriv->lock);
}
#endif

static int jmgpu_setup_dma_sgt(dma_addr_t addr, struct sg_table *sgt,
				struct page *pages, u32 size)
{
	int ret;

	ret = sg_alloc_table(sgt, 1, GFP_KERNEL);
	if (ret)
		return ret;
	sg_set_page(sgt->sgl, pages, size, 0);
	sgt->nents = sgt->orig_nents;
	sg_dma_address(sgt->sgl) = addr;
	sg_dma_len(sgt->sgl) = size;

	return ret;
}

static void jmgpu_cleanup_dma_sgt(struct sg_table *sgt)
{
	sg_free_table(sgt);
}

static j9_duopoly
j9_morbid(IN jmkALLOCATOR Allocator,
	  INOUT PLINUX_MDL Mdl, IN jmtSIZE_T NumPages, IN jmtUINT32 Flags)
{
	j9_duopoly status;
	u32 gfp = GFP_KERNEL | J9_WALLAHS;
	jmsDMA_PRIV_PTR allocatorPriv =
		(jmsDMA_PRIV_PTR) Allocator->privateData;

	struct mdl_dma_priv *mdlPriv = J9_CHYAK;
	dma_addr_t addr;
	struct page *pages;
	jmk_OS os = Allocator->os;
	int ret;

	j9_tympanichord("Mdl=%p NumPages=0x%zx Flags=0x%x", Mdl, NumPages,
			Flags);

	j9_recaution(jmkOS_Allocate(os,
				    sizeof(struct mdl_dma_priv),
				    (jmtPOINTER *)&mdlPriv));
	mdlPriv->kvaddr = J9_CHYAK;
	INIT_LIST_HEAD(&mdlPriv->sgt_list);
	mdlPriv->list_count = 0;
	mutex_init(&mdlPriv->sgt_mutex);

#if defined(CONFIG_ZONE_DMA32) && LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37)
	if (Flags & J9_HANDLE_J9_NORTHLIGHT)
		gfp |= __GFP_DMA32;
#else
	if (Flags & J9_HANDLE_J9_NORTHLIGHT)
		gfp |= __GFP_DMA;
#endif

#if J9_HANDLE_J9MIN_POLITICISE
	mdlPriv->kvaddr =
	    j9_gastrogenital(allocatorPriv, NumPages, &mdlPriv->dmaHandle,
			     &mdlPriv->fa_offset);
	if (!mdlPriv->kvaddr) {
		mdlPriv->kvaddr =
		    dma_alloc_contig(Mdl->dev, NumPages * PAGE_SIZE,
				     &mdlPriv->dmaHandle, gfp);
		mdlPriv->isFastAlloc = J9_YARELY;
	} else {
		mdlPriv->isFastAlloc = J9_CUPPY;
	}
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 6, 0)
	mdlPriv->kvaddr =
	    dma_alloc_wc(Mdl->dev, NumPages * PAGE_SIZE, &mdlPriv->dmaHandle,
			 gfp);
#else
	mdlPriv->kvaddr =
	    dma_alloc_writecombine(Mdl->dev, NumPages * PAGE_SIZE,
				   &mdlPriv->dmaHandle, gfp);
#endif
#endif

#ifdef CONFLICT_BETWEEN_BASE_AND_PHYS
	if ((os->device->baseAddress & 0x80000000) !=
	    (mdlPriv->dmaHandle & 0x80000000)) {
		mdlPriv->dmaHandle = (mdlPriv->dmaHandle & ~0x80000000)
		    | (os->device->baseAddress & 0x80000000);
	}
#endif

	if (mdlPriv->kvaddr == J9_CHYAK) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	addr = mdlPriv->dmaHandle;

	if (Allocator->os->iommu) {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 1, 0)
		addr = iommu_iova_to_phys(Allocator->os->iommu->domain, addr);
#else
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
#endif
		pages = pfn_to_page(addr >> PAGE_SHIFT);
	} else {
#if !defined(phys_to_page)
		pages = virt_to_page(mdlPriv->kvaddr);
#elif LINUX_VERSION_CODE < KERNEL_VERSION(3, 13, 0)
		pages = phys_to_page(addr);
#else
		pages = phys_to_page(dma_to_phys(Mdl->dev, addr));
#endif
	}

	ret = jmgpu_setup_dma_sgt(addr, &mdlPriv->sgt, pages,
				  NumPages << PAGE_SHIFT);

	if (ret)
		j9_recaution(J9_HANDLE__MAGISTRACY);

#if defined(CONFIG_X86) && !J9_HANDLE_J9MIN_POLITICISE
	if (os->enableWriteCombine) {
		if (set_memory_wc((unsigned long)(mdlPriv->kvaddr), NumPages) !=
		    0) {
			printk("%s(%d): failed to set_memory_wc\n", __func__,
			       __LINE__);
		}
	} else {
		if (set_memory_uc((unsigned long)(mdlPriv->kvaddr), NumPages) !=
		    0) {
			printk("%s(%d): failed to set_memory_uc\n", __func__,
			       __LINE__);
		}
	}
#endif
	Mdl->priv = mdlPriv;

	Mdl->dmaHandle = mdlPriv->dmaHandle;


	atomic_add(NumPages, &allocatorPriv->usage);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (mdlPriv)
		jmkOS_Free(os, mdlPriv);

	JMM_kFOOTER();
	return status;
}

static void clean_sgt_node_list(PLINUX_MDL mdl)
{
	struct mdl_dma_priv *mdlpriv = mdl->priv;
	struct sgt_node *node, *tmp;

	if (mdlpriv->list_count < 50)
		return;

	list_for_each_entry_safe(node, tmp, &mdlpriv->sgt_list, list) {
		list_del(&node->list);
		jmgpu_cleanup_dma_sgt(&node->sgt);
		kfree(node);
	}

	BUG_ON(!list_empty(&mdlpriv->sgt_list));

	mdlpriv->list_count = 0;
	mdlpriv->last_offset = 0;
	mdlpriv->last_sgt = &mdlpriv->sgt;
}

static j9_duopoly
j9_settled(IN jmkALLOCATOR Allocator,
	   IN PLINUX_MDL Mdl,
	   IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes, OUT jmtPOINTER *SGT)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 6, 0)
	struct mdl_dma_priv *mdlPriv = (struct mdl_dma_priv *)Mdl->priv;
	dma_addr_t addr;
	struct sgt_node *node;
	struct page *pages;
	int ret;
	j9_duopoly status = J9_FLUTTERING;

	BUG_ON(!mdlPriv);

	/*
	 * Real bounds check - the vendor only had a JMM_kASSERT() here, which is
	 * compiled out in release builds.  Offset/Bytes arrive from callers that
	 * may have been given user input (jmkVIDMEM_NODE_GetSGT() forwards the
	 * node offset straight from a DRM ioctl); without the check
	 * "Bytes - Offset" below goes negative and is handed to
	 * jmgpu_setup_dma_sgt() as a huge count.  Bytes is an *end* extent here.
	 */
	if (Offset > (Mdl->numPages << PAGE_SHIFT) ||
	    Bytes > (Mdl->numPages << PAGE_SHIFT) ||
	    (Offset && Offset >= Bytes))
		return J9_HANDLE_J9MENU_HOMOGONIES;

	if (!Offset) {
		*SGT = (jmtPOINTER)&mdlPriv->sgt;
		return status;
	}

	mutex_lock(&mdlPriv->sgt_mutex);

	if (Offset == mdlPriv->last_offset) {
		*SGT = (jmtPOINTER)mdlPriv->last_sgt;
		goto out;
	}

	list_for_each_entry(node, &mdlPriv->sgt_list, list) {
		if (Offset == node->offset) {
			mdlPriv->last_sgt = &node->sgt;
			mdlPriv->last_offset = Offset;
			*SGT = (jmtPOINTER)&node->sgt;
			goto out;
		}
	}

	clean_sgt_node_list(Mdl);

	node = kzalloc(sizeof(struct sgt_node), GFP_KERNEL);
	if (unlikely(!node)) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto out;
	}

	addr = mdlPriv->dmaHandle + Offset;

	if (Allocator->os->iommu) {
#if  LINUX_VERSION_CODE >= KERNEL_VERSION(3, 1, 0)
		addr = iommu_iova_to_phys(Allocator->os->iommu->domain, addr);
#endif
		pages = pfn_to_page(addr >> PAGE_SHIFT);
	} else {
#if !defined(phys_to_page)
		pages = virt_to_page((u64)mdlPriv->kvaddr + Offset);
#elif LINUX_VERSION_CODE < KERNEL_VERSION(3, 13, 0)
		pages = phys_to_page(addr);
#else
		pages = phys_to_page(dma_to_phys(Mdl->dev, addr));
#endif
	}

	ret = jmgpu_setup_dma_sgt(addr, &node->sgt, pages, Bytes - Offset);
	if (ret) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto free_out;
	}

	node->offset = Offset;
	list_add(&node->list, &mdlPriv->sgt_list);
	mdlPriv->list_count++;
	mdlPriv->last_sgt = &node->sgt;
	mdlPriv->last_offset = Offset;

	*SGT = (jmtPOINTER)&node->sgt;

	mutex_unlock(&mdlPriv->sgt_mutex);

	return status;

free_out:
	kfree(node);
out:
	mutex_unlock(&mdlPriv->sgt_mutex);
	return status;
#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

static void j9_frass(IN jmkALLOCATOR Allocator, IN OUT PLINUX_MDL Mdl)
{
	jmk_OS os = Allocator->os;
	struct sgt_node *node, *tmp;
	struct mdl_dma_priv *mdlPriv = (struct mdl_dma_priv *)Mdl->priv;
	jmsDMA_PRIV_PTR allocatorPriv =
		(jmsDMA_PRIV_PTR)Allocator->privateData;


	mutex_lock(&mdlPriv->sgt_mutex);
	list_for_each_entry_safe(node, tmp, &mdlPriv->sgt_list, list) {
		list_del(&node->list);
		jmgpu_cleanup_dma_sgt(&node->sgt);
		kfree(node);
	}
	mutex_unlock(&mdlPriv->sgt_mutex);

#if J9_HANDLE_J9MIN_POLITICISE
	if (mdlPriv->isFastAlloc) {
		j9_squamocellular(allocatorPriv, Mdl->numPages,
				  mdlPriv->fa_offset);
	} else {
		dma_free_contig(Mdl->dev,
				Mdl->numPages * PAGE_SIZE,
				mdlPriv->kvaddr, mdlPriv->dmaHandle);
	}
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 6, 0)
	dma_free_wc(Mdl->dev, Mdl->numPages * PAGE_SIZE, mdlPriv->kvaddr,
		    mdlPriv->dmaHandle);
#else
	dma_free_writecombine(Mdl->dev, Mdl->numPages * PAGE_SIZE,
			      mdlPriv->kvaddr, mdlPriv->dmaHandle);
#endif
#endif

	jmkOS_Free(os, mdlPriv);


	atomic_sub(Mdl->numPages, &allocatorPriv->usage);
}

static j9_duopoly
j9_antic(IN jmkALLOCATOR Allocator,
	 IN PLINUX_MDL Mdl,
	 IN jmtBOOL Cacheable,
	 IN jmtSIZE_T skipPages,
	 IN jmtSIZE_T numPages, IN struct vm_area_struct *vma)
{
	struct mdl_dma_priv *mdlPriv = (struct mdl_dma_priv *)Mdl->priv;
	j9_duopoly status = J9_FLUTTERING;
	int ret;

	j9_tympanichord("Allocator=%p Mdl=%p vma=%p", Allocator, Mdl, vma);

	/*
	 * Real bounds check - the vendor only had a JMM_kASSERT() here, which is
	 * compiled out in release builds.  skipPages/numPages come from the node
	 * placement and the mmap() length; without this the DMA mapping below
	 * (skipPages << PAGE_SHIFT) would run past the end of the allocation.
	 */
	if (skipPages >= Mdl->numPages ||
	    numPages > Mdl->numPages - skipPages)
		return J9_HANDLE_J9MENU_HOMOGONIES;

#if !J9_HANDLE_J9MIN_POLITICISE
	if (Allocator->os->enableWriteCombine)
		vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
	else
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
#endif

#if !J9_HANDLE_J9MIN_POLITICISE
	if (Allocator->os->enableWriteCombine) {

#if defined CONFIG_MIPS || defined CONFIG_CPU_CSKYV2 || defined CONFIG_PPC
		ret = remap_pfn_range(vma,
				      vma->vm_start,
				      (mdlPriv->dmaHandle >> PAGE_SHIFT) +
				      skipPages, numPages << PAGE_SHIFT,
				      pgprot_writecombine(vma->vm_page_prot));
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 6, 0)

		ret = dma_mmap_wc(Mdl->dev,
				  vma,
				  (jmtINT8_PTR) mdlPriv->kvaddr +
				  (skipPages << PAGE_SHIFT),
				  mdlPriv->dmaHandle +
				  (skipPages << PAGE_SHIFT),
				  numPages << PAGE_SHIFT);
#else

		ret = dma_mmap_writecombine(Mdl->dev,
					    vma,
					    (jmtINT8_PTR) mdlPriv->kvaddr +
					    (skipPages << PAGE_SHIFT),
					    mdlPriv->dmaHandle +
					    (skipPages << PAGE_SHIFT),
					    numPages << PAGE_SHIFT);
#endif
#endif
	} else {
		ret = dma_mmap_coherent(Mdl->dev,
					vma,
					(jmtINT8_PTR) mdlPriv->kvaddr +
					(skipPages << PAGE_SHIFT),
					mdlPriv->dmaHandle +
					(skipPages << PAGE_SHIFT),
					numPages << PAGE_SHIFT);
	}
#else

	ret = dma_mmap_contig(Mdl->dev, vma,
			(jmtINT8_PTR)mdlPriv->kvaddr +
			 (skipPages << PAGE_SHIFT),
			mdlPriv->dmaHandle + (skipPages << PAGE_SHIFT),
			numPages << PAGE_SHIFT);
#endif
	if (ret < 0) {
		JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS, J9_PASTURES,
				"%s(%d): dma_mmap_attrs error",
				__func__, __LINE__);

		status = J9_HANDLE_J9M_FORGATHERS;
	}

	JMM_kFOOTER();
	return status;
}

static void
j9_microzoary(IN jmkALLOCATOR Allocator,
	      IN PLINUX_MDL Mdl, IN PLINUX_MDL_MAP MdlMap, IN jmtUINT32 Size)
{
	if (unlikely(current->mm == J9_CHYAK)) {

		return;
	}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 4, 0)
	if (vm_munmap((unsigned long)MdlMap->vmaAddr, Size) < 0) {
		JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS, J9_PASTURES,
				"%s(%d): vm_munmap failed",
				__func__, __LINE__);
	}
#else
	down_write(&j9mirror_ecstatical);
	if (do_munmap(current->mm, (unsigned long)MdlMap->vmaAddr, Size) < 0) {
		JMM_kTRACE_ZONE(J9_ERYTHROPOIESIS, J9_PASTURES,
				"%s(%d): do_munmap failed",
				__func__, __LINE__);
	}
	up_write(&j9mirror_ecstatical);
#endif

	MdlMap->vma = NULL;
	MdlMap->vmaAddr = NULL;
}

static j9_duopoly
j9_metamers(jmkALLOCATOR Allocator,
	    PLINUX_MDL Mdl, PLINUX_MDL_MAP MdlMap, jmtBOOL Cacheable)
{
	jmtPOINTER userLogical = J9_CHYAK;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Allocator=%p Mdl=%p Cacheable=%d", Allocator, Mdl,
			Cacheable);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 4, 0)
#if J9_HANDLE_J9MENU_STREAMLETS
	userLogical = (jmtPOINTER) vm_mmap(Allocator->anon_file,
#else
	userLogical = (jmtPOINTER) vm_mmap(J9_CHYAK,
#endif
					   0L,
					   Mdl->numPages * PAGE_SIZE,
					   PROT_READ | PROT_WRITE,
					   MAP_SHARED | MAP_NORESERVE, 0);
#else
	down_write(&j9mirror_ecstatical);
	userLogical = (jmtPOINTER) do_mmap_pgoff(J9_CHYAK,
						 0L,
						 Mdl->numPages * PAGE_SIZE,
						 PROT_READ | PROT_WRITE,
						 MAP_SHARED, 0);
	up_write(&j9mirror_ecstatical);
#endif

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
			"%s(%d): vmaAddr->%p for phys_addr->%p",
			__func__, __LINE__, userLogical, Mdl);

	if (IS_ERR(userLogical)) {
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
				"%s(%d): do_mmap_pgoff error",
				__func__, __LINE__);

		userLogical = J9_CHYAK;

		j9_recaution(J9_HANDLE_J9M_FORGATHERS);
	}

	down_write(&j9mirror_ecstatical);

	do {
		struct vm_area_struct *vma =
		    find_vma(current->mm, (unsigned long)userLogical);
		if (vma == J9_CHYAK) {
			JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
					"%s(%d): find_vma error",
					__func__, __LINE__);

			j9_scrawliness(J9_HANDLE_J9MENU_UNEJECTIVE);
		}

		j9_scrawliness(j9_antic
			       (Allocator, Mdl, Cacheable, 0, Mdl->numPages,
				vma));

		MdlMap->vmaAddr = userLogical;
		MdlMap->cacheable = J9_YARELY;
		MdlMap->vma = vma;
	} while (J9_YARELY);

	up_write(&j9mirror_ecstatical);

OnError:
	if (J9_CATAPHORA(status) && userLogical) {
		MdlMap->vmaAddr = userLogical;
		j9_microzoary(Allocator, Mdl, MdlMap,
			      Mdl->numPages * PAGE_SIZE);
	}
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_morrowmass(IN jmkALLOCATOR Allocator,
	      IN PLINUX_MDL Mdl,
	      IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical)
{
	struct mdl_dma_priv *mdlPriv = (struct mdl_dma_priv *)Mdl->priv;
	*Logical = (uint8_t *) mdlPriv->kvaddr + Offset;
	return J9_FLUTTERING;
}

static j9_duopoly
j9_misappraised(IN jmkALLOCATOR Allocator,
		IN PLINUX_MDL Mdl, IN jmtPOINTER Logical)
{
	return J9_FLUTTERING;
}

static j9_duopoly
j9_kookri(IN jmkALLOCATOR Allocator,
	  IN PLINUX_MDL Mdl,
	  IN jmtSIZE_T Offset,
	  IN jmtPOINTER Logical,
	  IN jmtSIZE_T Bytes, IN j9maths_eventuated Operation)
{
	switch (Operation) {
	case J9_UNIDEATIONAL:
	case J9_HALISTERESIS:
		j9_maidenhairs();
		break;
	case J9_HANDLE_UNCOMBATED:
		break;
	default:
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	return J9_FLUTTERING;
}

static j9_duopoly
j9_pastosity(IN jmkALLOCATOR Allocator,
	     IN PLINUX_MDL Mdl,
	     IN jmtUINT32 Offset, OUT jmtPHYS_ADDR_T * Physical)
{
	struct mdl_dma_priv *mdlPriv = (struct mdl_dma_priv *)Mdl->priv;

	/*
	 * The whole Mdl is one DMA allocation of numPages * PAGE_SIZE, and
	 * Offset is user supplied (DRM_JM_GEM_XFER_RECT.offset).  j9_settled()
	 * only guards the equivalent expression with a debug JMM_kASSERT(), so
	 * enforce it for real here instead of returning an address past the
	 * allocation.
	 */
	if (!mdlPriv || Offset >= (Mdl->numPages << PAGE_SHIFT))
		return J9_HANDLE_J9MENU_HOMOGONIES;

	*Physical = mdlPriv->dmaHandle + Offset;

	return J9_FLUTTERING;
}

static void j9_handle_j9_nonnitrous(j9_hylegiacal *Allocator)
{
	j9_specialities(Allocator);

	if (Allocator->privateData) {
#if J9_HANDLE_J9MIN_POLITICISE
		jmsDMA_PRIV_PTR priv = (jmsDMA_PRIV_PTR) Allocator->privateData;

		if (priv->fa_vaddr) {
			dma_free_contig(priv->dev,
					J9_MATRIARCHALISM,
					priv->fa_vaddr, priv->fa_daddr);
			priv->fa_vaddr = 0;
		}
#endif
		kfree(Allocator->privateData);
	}

	kfree(Allocator);
}


j9_handle_j9m_spermarium DmaAllocatorOperations = {
	.Alloc = j9_morbid,
	.Free = j9_frass,
	.Mmap = j9_antic,
	.MapUser = j9_metamers,
	.UnmapUser = j9_microzoary,
	.MapKernel = j9_morrowmass,
	.UnmapKernel = j9_misappraised,
	.Cache = j9_kookri,
	.Physical = j9_pastosity,
	.GetSGT = j9_settled,
};


j9_duopoly
_DmaAlloctorInit(IN jmk_OS Os,
		 IN j9_shopbreaking * Parent, OUT jmkALLOCATOR *Allocator)
{
	j9_duopoly status;
	jmkALLOCATOR allocator = J9_CHYAK;
	jmsDMA_PRIV_PTR priv = J9_CHYAK;
#if J9_HANDLE_J9MIN_POLITICISE
	u32 gfp = GFP_KERNEL | J9_WALLAHS | __GFP_DMA32;
	j9_weakliest *platform;
	struct device *dev;
#endif

	j9_recaution(j9_handle_j_indentwise
		     (Os, &DmaAllocatorOperations, &allocator));

	priv = kzalloc(J9_NONPROS(j9_squallery), GFP_KERNEL | J9_WALLAHS);

	if (!priv) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	atomic_set(&priv->usage, 0);
#if J9_HANDLE_J9MIN_POLITICISE
	platform = Os->device->platform;
	dev = platform->ops->getSubDevice(platform);
	priv->dev = dev;
	if (dev) {
		priv->fa_vaddr = dma_alloc_contig(dev,
						  J9_MATRIARCHALISM,
						  &priv->fa_daddr, gfp);
	}
	mutex_init(&priv->lock);
#endif


	allocator->privateData = priv;
	allocator->destructor = j9_handle_j9_nonnitrous;

	j9_shrewdest(allocator, Parent);

	allocator->capability = J9_HANDLE_J9MA_SPERMARIUM
	    | J9_HANDLE_J_ATTRIBUTE_SCOUTINGLY
	    | J9_HANDLE_J9_PREADAPTED | J9_HANDLE_J9_BANDCUTTER
	    | JMV_ALLOC_FLAG_FROM_USER
#if (defined(CONFIG_ZONE_DMA32) || defined(CONFIG_ZONE_DMA)) && LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37)
	    | J9_HANDLE_J9_NORTHLIGHT
#endif
#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	    | JMV_ALLOC_FLAG_WITH_MIRROR
#endif
	    ;

	if (Os->iommu) {

		allocator->capability |= J9_HANDLE_J9MIRROR_NOVICELIKE;
		allocator->capability |= J9_HANDLE_J9_MUTILATING;
		allocator->capability |= J9_HANDLE_J9M_SUPERCIVIL;
		allocator->capability |= J9_HANDLE_J9_BANDCUTTER;
	}

	*Allocator = allocator;

	return J9_FLUTTERING;

OnError:
	kfree(allocator);
	return status;
}


