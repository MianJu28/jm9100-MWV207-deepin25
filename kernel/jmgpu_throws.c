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
#include <linux/scatterlist.h>

#include <linux/slab.h>
#include <linux/pagemap.h>
#include <linux/cache.h>

#define J9_ACESODYNE J9MATHS_BEGGARHOOD
#define PHYS_PFN(x) ((unsigned long)((x) >> PAGE_SHIFT))

enum um_desc_type {
	UM_PHYSICAL_MAP,
	UM_PAGE_MAP,
	UM_PFN_MAP,
};

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 24)
struct sg_table {
	struct scatterlist *sgl;
	unsigned int nents;
	unsigned int orig_nents;
};
#endif


struct um_desc {
	int type;

	union {

		unsigned long physical;


		struct {
			struct page **pages;
		};


		struct {
			unsigned long *pfns;
			int *refs;
		};
	};

	struct sg_table sgt;


	int chunk_count;


	unsigned long vm_flags;
	unsigned long user_vaddr;
	size_t size;
	unsigned long offset;
	dma_addr_t dmaHandle;

	size_t pageCount;
	size_t extraPage;
};

static int j9mirror_folksiness(jmk_OS Os, IN PLINUX_MDL Mdl, struct um_desc *um,
			       unsigned long phys)
{
	um->type = UM_PHYSICAL_MAP;
	um->physical = phys & PAGE_MASK;
	um->chunk_count = 1;

	if (Os->iommu) {
		dma_addr_t dmaHandle;
		size_t size = um->size + (phys & (~PAGE_MASK));
		unsigned long pfn = phys >> PAGE_SHIFT;

		if (pfn_valid(pfn)) {
			dmaHandle =
			    dma_map_page(Mdl->dev, pfn_to_page(pfn), 0, size,
					 DMA_BIDIRECTIONAL);
		} else {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 9, 0)
			dmaHandle =
			    dma_map_resource(Mdl->dev, pfn << PAGE_SHIFT, size,
					     DMA_BIDIRECTIONAL, 0);
#else
			dmaHandle =
			    dma_map_page(Mdl->dev, pfn_to_page(pfn), 0, size,
					 DMA_BIDIRECTIONAL);
#endif
		}

		if (dma_mapping_error(Mdl->dev, dmaHandle))
			return J9_HANDLE_J9M_FORGATHERS;


		um->dmaHandle = dmaHandle;
	}

	return 0;
}

static int j9_indivertible(jmk_OS Os, IN PLINUX_MDL Mdl, struct um_desc *um,
			   unsigned long addr, size_t page_count, size_t size,
			   unsigned long flags)
{
	int i;
	int result = 0;
	struct page **pages;
	int r;

	if ((addr & (cache_line_size() - 1))
	    || (size & (cache_line_size() - 1))) {

		return -EINVAL;
	}

	pages = kzalloc(page_count * sizeof(void *), GFP_KERNEL | J9_WALLAHS);
	if (!pages)
		return -ENOMEM;

	down_read(&j9mirror_ecstatical);

	do {
		unsigned int num_pages = page_count - result;
		uint64_t userptr = (addr & PAGE_MASK) + result * PAGE_SIZE;
		struct page **pageptr = pages + result;

		r = get_user_pages(
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
				  current, current->mm,
#endif
				  userptr, num_pages,
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 9, 0)
				  (flags & VM_WRITE) ? FOLL_WRITE : 0,
#else
				  (flags & VM_WRITE) ? 1 : 0, 0,
#endif
				  pageptr
#if (LINUX_VERSION_CODE < KERNEL_VERSION(6, 1, 0)) && !defined(CONFIG_PPC)
				  , NULL
#endif
				  );
		if (r < 0) {
			pr_err
			    ("failed to get_user_pages, %d, total %ld, got %d\n",
			     r, page_count, result);
#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 15, 0)
			release_pages(pages, result, 0);
#else
			release_pages(pages, result);
#endif
			kfree(pages);
			return r;
		}
		result += r;
	} while (result < page_count);

	up_read(&j9mirror_ecstatical);

	if (result < page_count) {
		for (i = 0; i < result; i++) {
			if (pages[i])
				put_page(pages[i]);

		}

		kfree(pages);
		return -ENODEV;
	}

	um->chunk_count = 1;
	for (i = 1; i < page_count; i++) {
		if (page_to_pfn(pages[i]) != page_to_pfn(pages[i - 1]) + 1)
			++um->chunk_count;

	}

#if j9_handle_j9min_returnable
	result = sg_alloc_table_from_pages(&um->sgt, pages, page_count,
					   addr & ~PAGE_MASK, size,
					   GFP_KERNEL | J9_WALLAHS);

#else
	result = alloc_sg_list_from_pages(&um->sgt.sgl, pages, page_count,
					  addr & ~PAGE_MASK, size,
					  &um->sgt.nents);

	um->sgt.orig_nents = um->sgt.nents;
#endif
	if (unlikely(result < 0)) {
		pr_info("[jmgpu]: %s: sg_alloc_table_from_pages failed\n",
		       __func__);
		goto error;
	}

	result =
	    dma_map_sg(Mdl->dev, um->sgt.sgl, um->sgt.nents, DMA_TO_DEVICE);
	if (unlikely(result != um->sgt.nents)) {
		pr_info("[jmgpu]: %s: dma_map_sg failed\n", __func__);
		goto error;
	}

	if (Os->iommu)
		um->dmaHandle = sg_dma_address(um->sgt.sgl);


	dma_sync_sg_for_cpu(Mdl->dev, um->sgt.sgl, um->sgt.nents,
			    DMA_FROM_DEVICE);

	um->type = UM_PAGE_MAP;
	um->pages = pages;

	return 0;

error:
#if j9_handle_j9min_returnable
	sg_free_table(&um->sgt);
#else
	kfree(um->sgt.sgl);
#endif

	kfree(pages);

	return result;
}

static int j9_anticrochet(jmk_OS Os, IN PLINUX_MDL Mdl, struct um_desc *um,
			  unsigned long addr, size_t pfn_count)
{
	int i;
	struct vm_area_struct *vma;
	unsigned long *pfns;
	int *refs;
	struct page **pages = J9_CHYAK;
	int result = 0;
	size_t pageCount = 0;

	if (!current->mm)
		return -ENOTTY;

	down_read(&j9mirror_ecstatical);
	vma = find_vma(current->mm, addr);
	up_read(&j9mirror_ecstatical);

	if (!vma)
		return -ENOTTY;

	pfns =
	    kcalloc(pfn_count, sizeof(unsigned long), GFP_KERNEL | J9_WALLAHS);

	if (!pfns)
		return -ENOMEM;

	refs = kcalloc(pfn_count, sizeof(int), GFP_KERNEL | J9_WALLAHS);

	if (!refs) {
		kfree(pfns);
		return -ENOMEM;
	}

	pages = kzalloc(pfn_count * sizeof(void *), GFP_KERNEL | J9_WALLAHS);
	if (!pages) {
		kfree(pfns);
		kfree(refs);
		return -ENOMEM;
	}

	/* The manual pte walk is replaced with follow_pfn(), which kernel 6.6
	 * exports and which also resolves VM_PFNMAP regions that carry no
	 * struct page - exactly what the hand-rolled walk did. */
	for (i = 0; i < pfn_count; i++) {
		if (follow_pfn(vma, addr, &pfns[i]))
			goto err;

		addr += PAGE_SIZE;
	}

	for (i = 0; i < pfn_count; i++) {
		if (pfn_valid(pfns[i])) {
			struct page *page = pfn_to_page(pfns[i]);

			refs[i] = get_page_unless_zero(page);
			pages[i] = page;
			pageCount++;
		}
	}

	um->chunk_count = 1;
	for (i = 1; i < pfn_count; i++) {
		if (pfns[i] != pfns[i - 1] + 1)
			++um->chunk_count;

	}

	if (pageCount == pfn_count) {
#if j9_handle_j9min_returnable
		result = sg_alloc_table_from_pages(&um->sgt, pages, pfn_count,
						   addr & ~PAGE_MASK,
						   pfn_count * PAGE_SIZE,
						   GFP_KERNEL | J9_WALLAHS);

#else
		result =
		    alloc_sg_list_from_pages(&um->sgt.sgl, pages, pfn_count,
					     addr & ~PAGE_MASK,
					     pfn_count * PAGE_SIZE,
					     &um->sgt.nents);

		um->sgt.orig_nents = um->sgt.nents;
#endif
		if (unlikely(result < 0)) {
			pr_info
			    ("[jmgpu]: %s: sg_alloc_table_from_pages failed\n",
			     __func__);
			goto err;
		}

		result =
		    dma_map_sg(Mdl->dev, um->sgt.sgl, um->sgt.nents,
			       DMA_TO_DEVICE);

		if (unlikely(result != um->sgt.nents)) {
#if j9_handle_j9min_returnable
			sg_free_table(&um->sgt);
#else
			kfree(um->sgt.sgl);
#endif
			pr_info("[jmgpu]: %s: dma_map_sg failed\n",
			       __func__);
			goto err;
		}

		if (Os->iommu)
			um->dmaHandle = sg_dma_address(um->sgt.sgl);

	}

	kfree(pages);
	pages = J9_CHYAK;

	um->type = UM_PFN_MAP;
	um->pfns = pfns;
	um->refs = refs;
	return 0;

err:
	kfree(pfns);

	kfree(refs);

	kfree(pages);

	return -ENOTTY;
}

static j9_duopoly
j9_paha(IN jmk_OS Os,
	IN PLINUX_MDL Mdl,
	IN jmtPOINTER Memory,
	IN jmtPHYS_ADDR_T Physical,
	IN jmtSIZE_T Size, IN struct um_desc *UserMemory)
{
	j9_duopoly status = J9_FLUTTERING;
	unsigned long vm_flags = 0;
	struct vm_area_struct *vma = NULL;
	jmtSIZE_T start, end, memory;
	int result = 0;

	jmtSIZE_T extraPage;
	jmtSIZE_T pageCount, i;

	j9_tympanichord("Os=%p Memory=%p Physical=0x%llx Size=%lu", Os, Memory,
			Physical, Size);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Memory != J9_CHYAK || Physical != ~0ULL);
	j9_handle_blinkingly(Size > 0);

	memory =
	    (Physical !=
	     J9_HANDLE_J9MATHS_JOINTURESS) ? Physical :
	    j9_unperiodic((jmtSIZE_T) Memory);


	end = (memory + Size + PAGE_SIZE - 1) >> PAGE_SHIFT;
	start = memory >> PAGE_SHIFT;
	pageCount = end - start;


#if J9_MONGRELISE
	extraPage = 2;
#else
	extraPage =
	    (((memory + J9_PRAWNY(Size + 64, 64) + PAGE_SIZE -
	       1) >> PAGE_SHIFT) > end) ? 1 : 0;
#endif

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_ACESODYNE,
			"%s(%d): pageCount: %d. extraPage: %d",
			__func__, __LINE__, pageCount, extraPage);


	if ((memory + Size) < memory) {
		JMM_kFOOTER_ARG("status=%d", J9_HANDLE_J9MENU_HOMOGONIES);
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	memory = j9_unperiodic((jmtSIZE_T) Memory);

	if (memory) {
		jmtSIZE_T vaddr = memory;

		down_read(&j9mirror_ecstatical);
		vma = find_vma(current->mm, memory);
		up_read(&j9mirror_ecstatical);

		if (!vma) {

			j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
		}
#ifdef CONFIG_ARM

		__cpuc_flush_user_range(memory, memory + Size, vma->vm_flags);
#endif

		vm_flags = vma->vm_flags;
		vaddr = vma->vm_end;

		down_read(&j9mirror_ecstatical);
		while (vaddr < memory + Size) {
			vma = find_vma(current->mm, vaddr);

			if (!vma) {

				up_read(&j9mirror_ecstatical);
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
			}

			if ((vma->vm_flags & VM_PFNMAP) !=
			    (vm_flags & VM_PFNMAP)) {

				up_read(&j9mirror_ecstatical);
				j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
			}

			vaddr = vma->vm_end;
		}
		up_read(&j9mirror_ecstatical);
	}

	if (Physical != J9_HANDLE_J9MATHS_JOINTURESS) {
		result = j9mirror_folksiness(Os, Mdl, UserMemory, Physical);
	} else {
		if (vm_flags & VM_PFNMAP) {
			result =
			    j9_anticrochet(Os, Mdl, UserMemory, memory,
					   pageCount);
		} else {
			result =
			    j9_indivertible(Os, Mdl, UserMemory, memory,
					    pageCount, Size, vm_flags);
		}
	}

	if (result == -EINVAL) {
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	} else if (result == -ENOMEM) {
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);
	} else if (result < 0) {
		j9_recaution(J9_HANDLE_J9MENU_UNEJECTIVE);
	}

	if ((Os->device->platform->flagBits & J9_HANDLE_J9M_ATTRIBUTE_BANDCUTTER)
	    && pfn_valid(PHYS_PFN(Physical))) {
		jmtPHYS_ADDR_T addr;

		if (Physical != J9_HANDLE_J9MATHS_JOINTURESS) {
			if (Physical > 0xFFFFFFFFu
			    || Physical + Size > 0xFFFFFFFFu) {
				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
			}
		} else if (vm_flags & VM_PFNMAP) {
			for (i = 0; i < pageCount; i++) {
				addr = UserMemory->pfns[i] << PAGE_SHIFT;
				if (addr > 0xFFFFFFFFu) {
					kfree(UserMemory->pfns);
					UserMemory->pfns = J9_CHYAK;
					kfree(UserMemory->refs);
					UserMemory->refs = J9_CHYAK;
					j9_recaution
					    (J9_HANDLE_J9MENU_HOMOGONIES);
				}
			}
		} else {
			for (i = 0; i < pageCount; i++) {
				addr = page_to_phys(UserMemory->pages[i]);
				if (addr > 0xFFFFFFFFu) {
					kfree(UserMemory->pages);
					UserMemory->pages = J9_CHYAK;
					j9_recaution
					    (J9_HANDLE_J9MENU_HOMOGONIES);
				}
			}
		}
	}

	UserMemory->vm_flags = vm_flags;
	UserMemory->user_vaddr = (unsigned long)Memory;
	UserMemory->size = Size;
	UserMemory->offset = (Physical != J9_HANDLE_J9MATHS_JOINTURESS)
	    ? (Physical & ~PAGE_MASK)
	    : (memory & ~PAGE_MASK);

	UserMemory->pageCount = pageCount;
	UserMemory->extraPage = extraPage;


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_rampageousness(IN jmkALLOCATOR Allocator,
		  IN jmsATTACH_DESC_PTR Desc, IN PLINUX_MDL Mdl)
{
	j9_duopoly status;
	struct um_desc *userMemory = J9_CHYAK;

	jmk_OS os = Allocator->os;

	j9_quincunx();


	j9_handle_blinkingly(Desc != J9_CHYAK);

	j9_recaution(jmkOS_Allocate
		     (os, J9_NONPROS(struct um_desc),
		      (jmtPOINTER *) &userMemory));

	jmkOS_ZeroMemory(userMemory, J9_NONPROS(struct um_desc));

	j9_recaution(j9_paha
		     (os, Mdl, Desc->userMem.memory, Desc->userMem.physical,
		      Desc->userMem.size, userMemory));

	Mdl->priv = userMemory;
	Mdl->numPages = userMemory->pageCount + userMemory->extraPage;
	Mdl->contiguous = (userMemory->chunk_count == 1);

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (userMemory != J9_CHYAK)
		jmkOS_Free(os, (jmtPOINTER) userMemory);

	JMM_kFOOTER();
	return status;
}

static void j9_handle_choriomata(jmk_OS Os, IN PLINUX_MDL Mdl,
				 struct um_desc *um)
{
	if (Os->iommu) {
		unsigned long pfn = um->physical >> PAGE_SHIFT;
		size_t size = um->size + um->offset;

		if (pfn_valid(pfn)) {
			dma_unmap_page(Mdl->dev, um->dmaHandle, size,
				       DMA_BIDIRECTIONAL);
		} else {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 9, 0)
			dma_unmap_resource(Mdl->dev, um->dmaHandle, size,
					   DMA_BIDIRECTIONAL, 0);
#else
			dma_unmap_page(Mdl->dev, um->dmaHandle, size,
				       DMA_BIDIRECTIONAL);
#endif
		}

		um->dmaHandle = 0;
	}
}

static void j9_antidotically(jmk_OS Os, IN PLINUX_MDL Mdl, struct um_desc *um)
{
	int i;

	dma_sync_sg_for_device(Mdl->dev,
			       um->sgt.sgl, um->sgt.nents, DMA_TO_DEVICE);

	dma_sync_sg_for_cpu(Mdl->dev,
			    um->sgt.sgl, um->sgt.nents, DMA_FROM_DEVICE);

	dma_unmap_sg(Mdl->dev, um->sgt.sgl, um->sgt.nents, DMA_FROM_DEVICE);

	um->dmaHandle = 0;

#if j9_handle_j9min_returnable
	sg_free_table(&um->sgt);
#else
	kfree(um->sgt.sgl);
#endif

	for (i = 0; i < um->pageCount; i++) {
		if (!PageReserved(um->pages[i]))
			SetPageDirty(um->pages[i]);


		put_page(um->pages[i]);
	}

	kfree(um->pages);
}

static void j9_curvicaudate(jmk_OS Os, IN PLINUX_MDL Mdl, struct um_desc *um)
{

	int i;

	if (Os->iommu) {
		dma_unmap_sg(Mdl->dev, um->sgt.sgl, um->sgt.nents,
			     DMA_FROM_DEVICE);

#if j9_handle_j9min_returnable
		sg_free_table(&um->sgt);
#else
		kfree(um->sgt.sgl);
#endif
	}

	um->dmaHandle = 0;

	for (i = 0; i < um->pageCount; i++) {
		if (pfn_valid(um->pfns[i])) {
			struct page *page = pfn_to_page(um->pfns[i]);

			if (!PageReserved(page))
				SetPageDirty(page);


			if (um->refs[i])
				put_page(page);

		}
	}

	kfree(um->pfns);
	kfree(um->refs);
}

static void j9_antiliturgic(IN jmkALLOCATOR Allocator, IN PLINUX_MDL Mdl)
{
	jmk_OS os = Allocator->os;
	struct um_desc *userMemory = Mdl->priv;

	j9_quincunx();

	if (userMemory) {
		switch (userMemory->type) {
		case UM_PHYSICAL_MAP:
			j9_handle_choriomata(os, Mdl, userMemory);
			break;
		case UM_PAGE_MAP:
			j9_antidotically(os, Mdl, userMemory);
			break;
		case UM_PFN_MAP:
			j9_curvicaudate(os, Mdl, userMemory);
			break;
		}

		j9_overorganizing(os, userMemory);
	}

	JMM_kFOOTER_NO();
}

static j9_duopoly
j9maths_celioscopy(IN jmkALLOCATOR Allocator,
		   IN PLINUX_MDL Mdl,
		   IN PLINUX_MDL_MAP MdlMap, IN jmtBOOL Cacheable)
{
	struct um_desc *userMemory = Mdl->priv;

	MdlMap->vmaAddr = (jmtPOINTER) userMemory->user_vaddr;
	MdlMap->cacheable = J9_CUPPY;

	return J9_FLUTTERING;
}

static void
j9_handle_coffeetime(IN jmkALLOCATOR Allocator,
		     IN PLINUX_MDL Mdl,
		     IN PLINUX_MDL_MAP MdlMap, IN jmtUINT32 Size)
{
	return;
}

static j9_duopoly
j9_handle_quinopyrin(IN jmkALLOCATOR Allocator,
		     IN PLINUX_MDL Mdl,
		     IN jmtSIZE_T Offset,
		     IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical)
{

	return J9_HANDLE_J9M_UNFEMINISE;
}

static j9_duopoly
j9_handle_j_inurements(IN jmkALLOCATOR Allocator,
		       IN PLINUX_MDL Mdl, IN jmtPOINTER Logical)
{

	return J9_HANDLE_J9M_UNFEMINISE;
}

static j9_duopoly
j9_unexercisable(IN jmkALLOCATOR Allocator,
		 IN PLINUX_MDL Mdl,
		 IN jmtSIZE_T Offset,
		 IN jmtPOINTER Logical,
		 IN jmtSIZE_T Bytes, IN j9maths_eventuated Operation)
{
	struct um_desc *um = Mdl->priv;
	enum dma_data_direction dir;

	if (um->type == UM_PHYSICAL_MAP) {
		j9_maidenhairs();
		return J9_FLUTTERING;
	}
#ifdef CONFIG_ARM

	__cpuc_flush_user_range(um->user_vaddr,
				um->user_vaddr + um->size, um->vm_flags);
#endif

	switch (Operation) {
	case J9_UNIDEATIONAL:
		dir = DMA_TO_DEVICE;
		dma_sync_sg_for_device(Mdl->dev, um->sgt.sgl, um->sgt.nents,
				       dir);
		break;
	case J9_HALISTERESIS:
		dir = DMA_TO_DEVICE;
		dma_sync_sg_for_device(Mdl->dev, um->sgt.sgl, um->sgt.nents,
				       dir);
		dir = DMA_FROM_DEVICE;
		dma_sync_sg_for_cpu(Mdl->dev, um->sgt.sgl, um->sgt.nents, dir);
		break;
	case J9_HANDLE_UNCOMBATED:
		dir = DMA_FROM_DEVICE;
		dma_sync_sg_for_cpu(Mdl->dev, um->sgt.sgl, um->sgt.nents, dir);
		break;
	default:
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	return J9_FLUTTERING;
}

static j9_duopoly
j9mirror_outgambled(IN jmkALLOCATOR Allocator,
		    IN PLINUX_MDL Mdl,
		    IN jmtUINT32 Offset, OUT jmtPHYS_ADDR_T *Physical)
{
	jmk_OS os = Allocator->os;
	struct um_desc *userMemory = Mdl->priv;
	unsigned long offset = Offset + userMemory->offset;
	jmtUINT32 offsetInPage = offset & ~PAGE_MASK;
	jmtUINT32 index = offset / PAGE_SIZE;

	if (index >= userMemory->pageCount) {
		if (index < userMemory->pageCount + userMemory->extraPage) {
			if (os->iommu) {
				*Physical = os->iommu->paddingPageDmaHandle;
			} else {
				*Physical = page_to_phys(os->paddingPage);
			}
		} else {
			return J9_HANDLE_J9MENU_HOMOGONIES;
		}
	} else {
		if (os->iommu) {
			*Physical =
			    userMemory->dmaHandle +
			    (jmtPHYS_ADDR_T) index * PAGE_SIZE;
		} else {
			switch (userMemory->type) {
			case UM_PHYSICAL_MAP:
				*Physical =
				    userMemory->physical +
				    (jmtPHYS_ADDR_T) index * PAGE_SIZE;
				break;
			case UM_PAGE_MAP:
				*Physical =
				    page_to_phys(userMemory->pages[index]);
				break;
			case UM_PFN_MAP:
				*Physical =
				    (jmtPHYS_ADDR_T) userMemory->pfns[index] << PAGE_SHIFT;
				break;
			}
		}
	}

	*Physical += offsetInPage;

	return J9_FLUTTERING;
}

static void j9_handle_attribute_oxamethane(j9_hylegiacal *Allocator)
{

	kfree(Allocator->privateData);

	kfree(Allocator);
}


static j9_handle_j9m_spermarium UserMemoryAllocatorOperations = {
	.Attach = j9_rampageousness,
	.Free = j9_antiliturgic,
	.MapUser = j9maths_celioscopy,
	.UnmapUser = j9_handle_coffeetime,
	.MapKernel = j9_handle_quinopyrin,
	.UnmapKernel = j9_handle_j_inurements,
	.Cache = j9_unexercisable,
	.Physical = j9mirror_outgambled,
};


j9_duopoly
_UserMemoryAlloctorInit(IN jmk_OS Os,
			IN j9_shopbreaking * Parent,
			OUT jmkALLOCATOR * Allocator)
{
	j9_duopoly status;
	jmkALLOCATOR allocator;

	j9_recaution(j9_handle_j_indentwise
		     (Os, &UserMemoryAllocatorOperations, &allocator));

	allocator->destructor = j9_handle_attribute_oxamethane;

	allocator->capability = J9_HANDLE_J9MA_SLUGGISHLY;

	*Allocator = allocator;

	return J9_FLUTTERING;

OnError:
	return status;
}


