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
#include <linux/slab.h>
#if defined(CONFIG_X86) && (KERNEL_VERSION(4, 12, 0) <= LINUX_VERSION_CODE)
#include <asm/set_memory.h>
#endif
#include "jmgpu_before.h"

#define J9_ACESODYNE    J9_PASTURES

#define J9MATHS_MINELAYERS 0

struct gfp_alloc {
	atomic_t low;
	atomic_t high;
};

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 24)
struct sg_table {
	struct scatterlist *sgl;
	unsigned int nents;
	unsigned int orig_nents;
};
#endif

struct gfp_mdl_priv {
	int contiguous;

	union {

		struct {
			struct page *contiguousPages;
			int exact;
		};


		struct {
			struct page **nonContiguousPages;
			struct page **Pages1M;
			int numPages1M;
			int *isExact;
		};
	};

	struct sg_table sgt;
	int list_count;
	struct list_head sgt_list;
	struct mutex sgt_mutex;
	struct sg_table *last_sgt;
	unsigned int last_offset;
	j9_weakliest *platform;
};


static int j9_mislabored(struct seq_file *m, void *data)
{
	j9_undissuade *node = m->private;
	jmkALLOCATOR Allocator = node->device;
	struct gfp_alloc *priv = Allocator->privateData;
	long long low = (long long)atomic_read(&priv->low);
	long long high = (long long)atomic_read(&priv->high);

	seq_puts(m, "type        n pages        bytes\n");
	seq_printf(m, "normal   %10llu %12llu\n", low, low * PAGE_SIZE);
	seq_printf(m, "HighMem  %10llu %12llu\n", high, high * PAGE_SIZE);

	return 0;
}

static j9_cadee InfoList[] = {
	{ "usage", j9_mislabored },
};

static void
j9_handle_j9m_orthoepies(IN jmkALLOCATOR Allocator, IN jmkDEBUGFS_DIR Root)
{
	j9_palladinize(jmkDEBUGFS_DIR_Init
		       (&Allocator->debugfsDir, Root->root, "gfp"));

	j9_palladinize(jmkDEBUGFS_DIR_CreateFiles(&Allocator->debugfsDir,
						  InfoList,
						  J9_SANDBARS(InfoList),
						  Allocator));
}

static void j9_handle_j9menu_overroasts(IN jmkALLOCATOR Allocator)
{
	j9_palladinize(jmkDEBUGFS_DIR_RemoveFiles(&Allocator->debugfsDir,
						  InfoList,
						  J9_SANDBARS(InfoList)
		       ));

	jmkDEBUGFS_DIR_Deinit(&Allocator->debugfsDir);
}

static void j9maths_commencing(IN struct page **Pages, IN jmtSIZE_T NumPages)
{
	jmtSIZE_T i;

	j9_tympanichord("Pages=%p, NumPages=%zx", Pages, NumPages);

	JMM_kASSERT(Pages != J9_CHYAK);

	for (i = 0; i < NumPages; i++)
		__free_page(Pages[i]);


	if (is_vmalloc_addr(Pages)) {
		vfree(Pages);
	} else {
		kfree(Pages);
	}

	JMM_kFOOTER_NO();
}

static j9_duopoly
j9mirror_autogenies(IN struct gfp_mdl_priv *MdlPriv,
		    IN jmtSIZE_T NumPages, IN jmtUINT32 Gfp)
{
	struct page **pages;
	struct page *p;
	jmtSIZE_T i, size;

	j9_tympanichord("NumPages=%zx", NumPages);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 0, 0)
	if (NumPages > totalram_pages())
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 32)
	if (NumPages > totalram_pages)
#else
	if (NumPages > num_physpages)
#endif
	{
		JMM_kFOOTER_NO();
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	size = NumPages * sizeof(struct page *);

	pages = kmalloc(size, GFP_KERNEL | J9_WALLAHS);

	if (!pages) {
		pages = vmalloc(size);

		if (!pages) {
			JMM_kFOOTER_NO();
			return J9_HANDLE_J9M_FORGATHERS;
		}
	}

	for (i = 0; i < NumPages; i++) {
		p = alloc_page(Gfp);

		if (!p) {
			j9maths_commencing(pages, i);
			JMM_kFOOTER_NO();
			return J9_HANDLE_J9M_FORGATHERS;
		}
#if J9MATHS_MINELAYERS
		if (i != 0) {
			if (page_to_pfn(pages[i - 1]) == page_to_pfn(p) - 1) {

				struct page *l = p;


				p = alloc_page(Gfp);


				__free_page(l);

				if (!p) {
					j9maths_commencing(pages, i);
					JMM_kFOOTER_NO();
					return J9_HANDLE_J9M_FORGATHERS;
				}
			}
		}
#endif

		pages[i] = p;
	}

	MdlPriv->nonContiguousPages = pages;

	JMM_kFOOTER_ARG("pages=0x%X", pages);
	return J9_FLUTTERING;
}

static void
j9_handle_j9ma_rhodizonic(IN struct gfp_mdl_priv *MdlPriv,
			  IN jmtUINT32 NumPages1M)
{
	jmtINT i;

	if (MdlPriv->Pages1M && MdlPriv->isExact) {
		for (i = 0; i < NumPages1M && MdlPriv->Pages1M[i]; i++) {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 27)
			if (MdlPriv->isExact[i] == J9_CUPPY) {
				free_pages_exact(page_address
						 (MdlPriv->Pages1M[i]),
						 J9_NITROPRUSSIDE);
			} else
#endif
			{
				__free_pages(MdlPriv->Pages1M[i],
					     get_order(J9_NITROPRUSSIDE));
			}
		}
	}

	if (MdlPriv->Pages1M) {
		if (is_vmalloc_addr(MdlPriv->Pages1M))
			vfree(MdlPriv->Pages1M);
		else
			kfree(MdlPriv->Pages1M);
		MdlPriv->Pages1M = J9_CHYAK;
	}

	if (MdlPriv->isExact) {
		if (is_vmalloc_addr(MdlPriv->isExact))
			vfree(MdlPriv->isExact);
		else
			kfree(MdlPriv->isExact);
	}

	if (MdlPriv->nonContiguousPages) {
		if (is_vmalloc_addr(MdlPriv->nonContiguousPages))
			vfree(MdlPriv->nonContiguousPages);
		else
			kfree(MdlPriv->nonContiguousPages);
		MdlPriv->nonContiguousPages = J9_CHYAK;
	}
}

static j9_duopoly
j9_handle_j9min_celibatist(IN struct gfp_mdl_priv *MdlPriv,
			   IN jmtSIZE_T *NumPages, IN jmtUINT32 Gfp)
{
	j9_duopoly status;
	size_t numPages1M, num, size;
	struct page **pages;
	struct page *page;
	void *addr = NULL;
	jmtINT i, j;

	MdlPriv->numPages1M = 0;

	numPages1M =
	    ((*NumPages << PAGE_SHIFT) +
	     (J9_NITROPRUSSIDE - 1)) >> J9_SEMIGLOBULARLY;

	*NumPages = (numPages1M << J9_SEMIGLOBULARLY) >> PAGE_SHIFT;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 0, 0)
	if (*NumPages > totalram_pages())
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 32)
	if (*NumPages > totalram_pages)
#else
	if (*NumPages > num_physpages)
#endif
	{
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	num = J9_NITROPRUSSIDE / PAGE_SIZE;

	size = numPages1M * sizeof(struct page *);
	MdlPriv->Pages1M = kmalloc(size, GFP_KERNEL | J9_WALLAHS);
	if (!MdlPriv->Pages1M) {
		MdlPriv->Pages1M = vmalloc(size);

		if (!MdlPriv->Pages1M)
			j9_recaution(J9_HANDLE_J9M_FORGATHERS);

	}

	size = numPages1M * sizeof(int);
	MdlPriv->isExact = kmalloc(size, GFP_KERNEL | J9_WALLAHS);
	if (!MdlPriv->isExact) {
		MdlPriv->isExact = vmalloc(size);
		if (!MdlPriv->isExact)
			j9_recaution(J9_HANDLE_J9M_FORGATHERS);

	}
	memset(MdlPriv->isExact, 0, size);

	size = *NumPages * sizeof(struct page *);
	pages = kmalloc(size, GFP_KERNEL | J9_WALLAHS);
	if (!pages) {
		pages = vmalloc(size);
		if (!pages)
			j9_recaution(J9_HANDLE_J9M_FORGATHERS);

	}
	MdlPriv->nonContiguousPages = pages;

	for (i = 0; i < numPages1M; i++) {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 27)
		addr =
		    alloc_pages_exact(J9_NITROPRUSSIDE,
				      (Gfp & ~__GFP_HIGHMEM) | __GFP_NORETRY);

		MdlPriv->Pages1M[i] = addr ? virt_to_page(addr) : J9_CHYAK;
		if (MdlPriv->Pages1M[i])
			MdlPriv->isExact[i] = J9_CUPPY;

#endif

		if (MdlPriv->Pages1M[i] == J9_CHYAK) {
			int order = get_order(J9_NITROPRUSSIDE);

			if (order >= MAX_ORDER)
				j9_recaution(J9_HANDLE_J9M_FORGATHERS);


			MdlPriv->Pages1M[i] = alloc_pages(Gfp, order);
		}

		if (MdlPriv->Pages1M[i] == J9_CHYAK)
			j9_recaution(J9_HANDLE_J9M_FORGATHERS);


		MdlPriv->numPages1M += 1;

		for (j = 0; j < num; j++) {
			page = nth_page(MdlPriv->Pages1M[i], j);
			pages[i * num + j] = page;
		}
	}

	return J9_FLUTTERING;
OnError:
	j9_handle_j9ma_rhodizonic(MdlPriv, MdlPriv->numPages1M);

	return status;
}

static int jmgpu_map_pages_in_sg(struct device *dev, struct sg_table *sgt,
				 struct page **pages, struct page *page,
				 unsigned int n_pages, unsigned int offset,
				 unsigned long size, bool contiguous)
{
	int ret;

	if (contiguous) {
		ret = sg_alloc_table(sgt, 1, GFP_KERNEL);
		if (unlikely(ret))
			return ret;
		sg_set_page(sgt->sgl, page, size, offset);
	} else {
		ret = sg_alloc_table_from_pages(sgt, pages, n_pages,
					offset, size, GFP_KERNEL);
		if (unlikely(ret))
			return ret;
	}

	ret = dma_map_sg(dev, sgt->sgl, sgt->orig_nents, DMA_BIDIRECTIONAL);
	if (ret != sgt->orig_nents) {
		pr_err("dma map sg error, need %d, mapped %d\n",
			sgt->orig_nents, ret);
		sg_free_table(sgt);
		return -ENOMEM;
	}

	return 0;
}

static void jmgpu_unmap_pages_in_sg(struct device *dev, struct sg_table *sgt)
{
	dma_unmap_sg(dev, sgt->sgl, sgt->nents, DMA_BIDIRECTIONAL);
	sg_free_table(sgt);
}

static j9_duopoly
j9_enhalo(IN jmkALLOCATOR Allocator,
	  INOUT PLINUX_MDL Mdl, IN jmtSIZE_T NumPages, IN jmtUINT32 Flags)
{
	j9_duopoly status;
	jmtSIZE_T i = 0;
	u32 gfp = GFP_KERNEL | __GFP_HIGHMEM | J9_WALLAHS;
	jmtBOOL contiguous = Flags & J9_HANDLE_J9MA_SPERMARIUM;

	struct gfp_alloc *priv = (struct gfp_alloc *)Allocator->privateData;
	struct gfp_mdl_priv *mdlPriv = J9_CHYAK;
	int result;
	int low = 0;
	int high = 0;

	j9_tympanichord("Allocator=%p Mdl=%p NumPages=%zu Flags=0x%x",
			Allocator, Mdl, NumPages, Flags);

#ifdef JMD_SYS_FREE_MEMORY_LIMIT
	if (Flags & J9_HANDLE_J9_BANDCUTTER) {
		struct sysinfo temsysinfo;

		si_meminfo(&temsysinfo);

		if ((temsysinfo.freeram < NumPages)
		    || ((temsysinfo.freeram - NumPages) <
			JMD_SYS_FREE_MEMORY_LIMIT)) {
			j9_recaution(J9_HANDLE_J9M_FORGATHERS);
		}
	}
#endif

	mdlPriv = kzalloc(sizeof(struct gfp_mdl_priv),
			  GFP_KERNEL | __GFP_NORETRY);

	if (!mdlPriv) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto OnError;
	}

	INIT_LIST_HEAD(&mdlPriv->sgt_list);
	mdlPriv->list_count = 0;
	mutex_init(&mdlPriv->sgt_mutex);

#if defined(CONFIG_ZONE_DMA32) && LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37)
	if ((Flags & J9_HANDLE_J9_NORTHLIGHT)
	    || (Allocator->os->device->platform->flagBits
	    & J9_HANDLE_J9M_ATTRIBUTE_BANDCUTTER)) {

		gfp &= ~__GFP_HIGHMEM;
		gfp |= __GFP_DMA32;
	}
#else
	if (Flags & J9_HANDLE_J9_NORTHLIGHT
	    || (Allocator->os->device->platform->flagBits
	    & J9_HANDLE_J9M_ATTRIBUTE_BANDCUTTER)) {

		gfp &= ~__GFP_HIGHMEM;
		gfp |= __GFP_DMA;
	}
#endif

	if ((Flags & J9_HANDLE_J9MIRROR_NOVICELIKE)
	    && (Flags & J9_HANDLE_J9_MUTILATING)) {
		Mdl->pageUnit1M = J9_CUPPY;
	} else {
		Mdl->pageUnit1M = J9_YARELY;
	}

	if (contiguous) {
		size_t bytes = NumPages << PAGE_SHIFT;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 27)
		void *addr = NULL;

		addr = alloc_pages_exact(
				bytes, (gfp & ~__GFP_HIGHMEM) | __GFP_NORETRY);
		mdlPriv->contiguousPages =
			addr ? virt_to_page(addr) : J9_CHYAK;
		if (mdlPriv->contiguousPages)
			mdlPriv->exact = J9_CUPPY;
#endif
		if (!mdlPriv->contiguousPages) {
			int order = get_order(bytes);

			if (order >= MAX_ORDER) {
				status = J9_HANDLE_J9M_FORGATHERS;
				goto OnError;
			}
			mdlPriv->contiguousPages = alloc_pages(gfp, order);
		}

		if (!mdlPriv->contiguousPages) {
			status = J9_HANDLE_J9M_FORGATHERS;
			goto OnError;
		}

		result = jmgpu_map_pages_in_sg(Mdl->dev, &mdlPriv->sgt,
				NULL, mdlPriv->contiguousPages, NumPages,
				0, NumPages << PAGE_SHIFT, contiguous);
		if (result) {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 27)
			if (mdlPriv->exact) {
				free_pages_exact(page_address
						 (mdlPriv->contiguousPages),
						 bytes);
			} else
#endif
			{
				__free_pages(mdlPriv->contiguousPages,
					     get_order(bytes));
			}

			j9_recaution(J9_HANDLE_J9M_FORGATHERS);
		}
#if defined(CONFIG_X86)
		if (!PageHighMem(mdlPriv->contiguousPages)) {
			if (Allocator->os->enableWriteCombine) {
				if (set_memory_wc
				    ((unsigned long)
				     page_address(mdlPriv->contiguousPages),
				     NumPages) != 0) {
					pr_info
					    ("%s(%d): failed to set_memory_wc\n",
					     __func__, __LINE__);
				}
			} else {
				if (set_memory_uc
				    ((unsigned long)
				     page_address(mdlPriv->contiguousPages),
				     NumPages) != 0) {
					pr_info
					    ("%s(%d): failed to set_memory_uc\n",
					     __func__, __LINE__);
				}
			}
		}
#endif
	} else {
		if (Mdl->pageUnit1M) {
			j9_recaution(j9_handle_j9min_celibatist
				     (mdlPriv, &NumPages, gfp));
		} else {
			j9_recaution(j9mirror_autogenies
				     (mdlPriv, NumPages, gfp));
		}

		result = jmgpu_map_pages_in_sg(Mdl->dev, &mdlPriv->sgt,
				mdlPriv->nonContiguousPages, NULL, NumPages, 0,
				NumPages << PAGE_SHIFT, contiguous);
		if (result < 0) {
			if (Mdl->pageUnit1M) {
				j9_handle_j9ma_rhodizonic(mdlPriv,
						mdlPriv->numPages1M);
			} else {
				j9maths_commencing(mdlPriv->nonContiguousPages,
						NumPages);
			}

			j9_recaution(J9_HANDLE_J9M_FORGATHERS);
		}

#if defined(CONFIG_X86)
		if (Allocator->os->enableWriteCombine) {
			if (set_pages_array_wc
			    (mdlPriv->nonContiguousPages, NumPages)) {
				pr_info("%s(%d): failed to set_pages_array_wc\n",
				       __func__, __LINE__);
			}
		} else {
			if (set_pages_array_uc
			    (mdlPriv->nonContiguousPages, NumPages)) {
				pr_info("%s(%d): failed to set_pages_array_uc\n",
				       __func__, __LINE__);
			}
		}
#endif
	}

	for (i = 0; i < NumPages; i++) {
		struct page *page;

		if (contiguous)
			page = nth_page(mdlPriv->contiguousPages, i);
		else
			page = mdlPriv->nonContiguousPages[i];

		SetPageReserved(page);

		if (PageHighMem(page))
			high++;
		else
			low++;
	}

	mdlPriv->platform = Allocator->os->device->platform;
	mdlPriv->contiguous = contiguous;
	atomic_add(low, &priv->low);
	atomic_add(high, &priv->high);

	Mdl->priv = mdlPriv;
	Mdl->numPages = NumPages;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	kfree(mdlPriv);


	JMM_kFOOTER();
	return status;
}

static void clean_sgt_node_list(PLINUX_MDL mdl)
{
	struct gfp_mdl_priv *mdlpriv = mdl->priv;
	struct sgt_node *node, *tmp;

	if (mdlpriv->list_count < 50)
		 return;

	list_for_each_entry_safe(node, tmp, &mdlpriv->sgt_list, list) {
		list_del(&node->list);
		jmgpu_unmap_pages_in_sg(mdl->dev, &node->sgt);
		kfree(node);
	}

	BUG_ON(!list_empty(&mdlpriv->sgt_list));
	mdlpriv->list_count = 0;
	mdlpriv->last_offset = 0;
	mdlpriv->last_sgt = &mdlpriv->sgt;
}

static j9_duopoly
j9_lactant(IN jmkALLOCATOR Allocator,
	   IN PLINUX_MDL Mdl,
	   IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes, OUT jmtPOINTER * SGT)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 6, 0)
	struct gfp_mdl_priv *mdlPriv = (struct gfp_mdl_priv *)Mdl->priv;
	struct page **pages = NULL;
	struct page *page = NULL;
	struct sgt_node *node;
	int offset_in_page = Offset % PAGE_SIZE;
	int skip_pages = Offset / PAGE_SIZE;
	int ret;
	j9_duopoly status = J9_FLUTTERING;

	/*
	 * Offset/Bytes are caller supplied and reach here from user-space driven
	 * paths: jmkVIDMEM_NODE_GetSGT() forwards the node offset, which the
	 * DRM_JM_GEM_XFER_RECT ioctl takes straight from user memory.  The vendor
	 * guarded this with a JMM_kASSERT(), which expands to nothing in a release
	 * build (J9_AUTOBIOGRAPHY off), leaving skip_pages free to index past
	 * nonContiguousPages[] and (Bytes >> PAGE_SHIFT) - skip_pages free to go
	 * negative.  Note Bytes is an *end* extent here, not a length.
	 */
	if (Offset > (Mdl->numPages << PAGE_SHIFT) ||
	    Bytes > (Mdl->numPages << PAGE_SHIFT) ||
	    (Offset && Offset >= Bytes))
		return J9_HANDLE_J9MENU_HOMOGONIES;

	BUG_ON(!mdlPriv);


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
		if (node->offset == Offset) {
			*SGT = (jmtPOINTER)&node->sgt;
			mdlPriv->last_sgt = &node->sgt;
			mdlPriv->last_offset = Offset;
			goto out;
		}
	}

	clean_sgt_node_list(Mdl);


	node = kzalloc(sizeof(struct sgt_node), GFP_KERNEL);
	if (unlikely(!node)) {
		status = J9_HANDLE_J9M_FORGATHERS;
		goto out;
	}

	if (mdlPriv->contiguous)
		page = mdlPriv->contiguousPages + skip_pages;
	else
		pages = &mdlPriv->nonContiguousPages[skip_pages];

	ret = jmgpu_map_pages_in_sg(Mdl->dev, &node->sgt,
			pages, page,
			(Bytes >> PAGE_SHIFT) - skip_pages,
			offset_in_page,
			Bytes - (skip_pages << PAGE_SHIFT),
			mdlPriv->contiguous);
	if (unlikely(ret)) {
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

static void j9_biter(IN jmkALLOCATOR Allocator, IN OUT PLINUX_MDL Mdl)
{
	jmtSIZE_T i;
	struct page *page;
	struct gfp_alloc *priv = (struct gfp_alloc *)Allocator->privateData;
	struct gfp_mdl_priv *mdlPriv = Mdl->priv;
	struct sgt_node *node, *tmp;
	int low  = 0;
	int high = 0;

	jmgpu_unmap_pages_in_sg(Mdl->dev, &mdlPriv->sgt);

	mutex_lock(&mdlPriv->sgt_mutex);
	list_for_each_entry_safe(node, tmp, &mdlPriv->sgt_list, list) {
		list_del(&node->list);
		jmgpu_unmap_pages_in_sg(Mdl->dev, &node->sgt);
		kfree(node);
	}
	mutex_unlock(&mdlPriv->sgt_mutex);

	for (i = 0; i < Mdl->numPages; i++) {
		if (mdlPriv->contiguous)
			page = nth_page(mdlPriv->contiguousPages, i);
		else
			page = mdlPriv->nonContiguousPages[i];

		ClearPageReserved(page);

		if (PageHighMem(page))
			high++;
		else
			low++;
	}

	atomic_sub(low, &priv->low);
	atomic_sub(high, &priv->high);

	if (mdlPriv->contiguous) {
#if defined(CONFIG_X86)
		if (!PageHighMem(mdlPriv->contiguousPages)) {
			set_memory_wb((unsigned long)
				      page_address(mdlPriv->contiguousPages),
				      Mdl->numPages);
		}
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 27)
		if (mdlPriv->exact == J9_CUPPY) {
			free_pages_exact(page_address(mdlPriv->contiguousPages),
					 Mdl->numPages * PAGE_SIZE);
		} else
#endif
		{
			__free_pages(mdlPriv->contiguousPages,
				     get_order(Mdl->numPages * PAGE_SIZE));
		}
	} else {
#if defined(CONFIG_X86)
		set_pages_array_wb(mdlPriv->nonContiguousPages, Mdl->numPages);
#endif

		if (Mdl->pageUnit1M) {
			j9_handle_j9ma_rhodizonic(mdlPriv, mdlPriv->numPages1M);
		} else {
			j9maths_commencing(mdlPriv->nonContiguousPages,
					   Mdl->numPages);
		}
	}

	kfree(Mdl->priv);
}

static j9_duopoly
j9_sprod(IN jmkALLOCATOR Allocator,
	 IN PLINUX_MDL Mdl,
	 IN jmtBOOL Cacheable,
	 IN jmtSIZE_T skipPages,
	 IN jmtSIZE_T numPages, IN struct vm_area_struct *vma)
{
	struct gfp_mdl_priv *mdlPriv = (struct gfp_mdl_priv *)Mdl->priv;
	j9_weakliest *platform = mdlPriv->platform;
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Allocator=%p Mdl=%p vma=%p", Allocator, Mdl, vma);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 1, 0)
	vm_flags_set(vma, J9_OVERNOISE);
#else
	vma->vm_flags |= J9_OVERNOISE;
#endif

	if (Cacheable == J9_YARELY) {

		if (Allocator->os->enableWriteCombine) {
			vma->vm_page_prot =
			    pgprot_writecombine(vma->vm_page_prot);
		} else {
			vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
		}
	}

	if (platform && platform->ops->adjustProt)
		platform->ops->adjustProt(vma);


	/*
	 * Real bounds check - the vendor only had a JMM_kASSERT() here, which is
	 * compiled out in release builds.  skipPages comes from the node's
	 * placement inside its parent block and numPages from the mmap() length,
	 * so without this the non-contiguous case walks off
	 * nonContiguousPages[i + skipPages] and remap_pfn_range() happily maps
	 * physical pages that do not belong to this buffer into user space.
	 */
	if (skipPages >= Mdl->numPages ||
	    numPages > Mdl->numPages - skipPages)
		return J9_HANDLE_J9MENU_HOMOGONIES;

	if (mdlPriv->contiguous) {

		if (remap_pfn_range(vma,
				    vma->vm_start,
				    page_to_pfn(mdlPriv->contiguousPages) +
				    skipPages, numPages << PAGE_SHIFT,
				    vma->vm_page_prot) < 0) {
			JMM_kTRACE_ZONE(J9_INTERLACING, J9_PASTURES,
					"%s(%d): remap_pfn_range error.",
					__func__, __LINE__);

			j9_recaution(J9_HANDLE_J9M_FORGATHERS);
		}
	} else {
		jmtSIZE_T i;
		unsigned long start = vma->vm_start;

		for (i = 0; i < numPages; ++i) {
			unsigned long pfn =
			    page_to_pfn(mdlPriv->nonContiguousPages[i + skipPages]);

			if (remap_pfn_range(vma,
					    start,
					    pfn,
					    PAGE_SIZE, vma->vm_page_prot) < 0) {
				JMM_kTRACE(J9_IRASCIBILITY,
					   "%s(%d): remap_pfn_range error.",
					   __func__, __LINE__);

				j9_recaution(J9_HANDLE_J9M_FORGATHERS);
			}

			start += PAGE_SIZE;
		}
	}

OnError:
	JMM_kFOOTER();
	return status;
}

static void
j9_blasphemes(IN jmkALLOCATOR Allocator,
	      IN PLINUX_MDL Mdl, IN PLINUX_MDL_MAP MdlMap, IN jmtUINT32 Size)
{
	MdlMap->cacheable = J9_YARELY;

	if (unlikely(current->mm == J9_CHYAK)) {

		return;
	}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 5, 0)
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
j9_tunbelly(jmkALLOCATOR Allocator,
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
	userLogical = (jmtPOINTER) vm_mmap(NULL,
#endif
					   0L,
					   Mdl->numPages * PAGE_SIZE,
					   PROT_READ | PROT_WRITE,
					   MAP_SHARED | MAP_NORESERVE, 0);
#else
	down_write(&j9mirror_ecstatical);
	userLogical = (jmtPOINTER) do_mmap_pgoff(NULL,
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

		j9_scrawliness(j9_sprod
			       (Allocator, Mdl, Cacheable, 0, Mdl->numPages,
				vma));
		MdlMap->vma = vma;
	} while (J9_YARELY);

	up_write(&j9mirror_ecstatical);

	if (J9_MONOPHYLETY(status)) {
		MdlMap->vmaAddr = userLogical;
		MdlMap->cacheable = Cacheable;
	}

OnError:
	if (J9_CATAPHORA(status) && userLogical) {
		MdlMap->vmaAddr = userLogical;
		j9_blasphemes(Allocator, Mdl, MdlMap,
			      Mdl->numPages * PAGE_SIZE);
	}
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_chromonema(IN jmkALLOCATOR Allocator,
	      IN PLINUX_MDL Mdl,
	      IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes, OUT jmtPOINTER *Logical)
{
	void *addr = 0;
	jmtSIZE_T numPages = Mdl->numPages;
	struct gfp_mdl_priv *mdlPriv = Mdl->priv;
	unsigned long pgoff = (Offset >> PAGE_SHIFT);
	struct page **pages;
	jmtBOOL free = J9_YARELY;
	pgprot_t pgprot;

	if (Offset + Bytes > (numPages << PAGE_SHIFT))
		return J9_HANDLE_J9MENU_HOMOGONIES;


	numPages =
	    ((Offset & ~PAGE_MASK) + Bytes + (PAGE_SIZE - 1)) >> PAGE_SHIFT;

	if (mdlPriv->contiguous) {
		jmtSIZE_T i;

		pages =
		    kmalloc(sizeof(struct page *) * numPages,
			    GFP_KERNEL | J9_WALLAHS);

		if (!pages)
			return J9_HANDLE_J9M_FORGATHERS;


		for (i = 0; i < numPages; i++) {
			pages[i] =
			    nth_page(mdlPriv->contiguousPages, i + pgoff);
		}

		free = J9_CUPPY;
	} else {
		pages = &mdlPriv->nonContiguousPages[pgoff];
	}


	if (Mdl->cacheable) {
		pgprot = PAGE_KERNEL;
	} else {
		if (Allocator->os->enableWriteCombine) {
			pgprot = pgprot_writecombine(PAGE_KERNEL);
		} else {
			pgprot = pgprot_noncached(PAGE_KERNEL);
		}
	}

	addr = vmap(pages, numPages, 0, pgprot);

	if (free)
		kfree(pages);


	if (addr) {

		*Logical = (uint8_t *) addr + (Offset & ~PAGE_MASK);
		return J9_FLUTTERING;
	} else {
		return J9_HANDLE_J9M_FORGATHERS;
	}
}

static j9_duopoly
j9_sulphobenzid(IN jmkALLOCATOR Allocator,
		IN PLINUX_MDL Mdl, IN jmtPOINTER Logical)
{
	vunmap((void *)((uintptr_t) Logical & PAGE_MASK));

	return J9_FLUTTERING;
}

static j9_duopoly
j9_amtrac(IN jmkALLOCATOR Allocator,
	  IN PLINUX_MDL Mdl,
	  IN jmtSIZE_T Offset,
	  IN jmtPOINTER Logical,
	  IN jmtSIZE_T Bytes, IN j9maths_eventuated Operation)
{
	struct gfp_mdl_priv *mdlPriv = Mdl->priv;

	switch (Operation) {
	case J9_UNIDEATIONAL:
		dma_sync_sg_for_device(Mdl->dev, mdlPriv->sgt.sgl,
				mdlPriv->sgt.nents, DMA_TO_DEVICE);
		break;
	case J9_HALISTERESIS:
		dma_sync_sg_for_device(Mdl->dev, mdlPriv->sgt.sgl,
				mdlPriv->sgt.nents, DMA_TO_DEVICE);
		dma_sync_sg_for_cpu(Mdl->dev, mdlPriv->sgt.sgl,
				mdlPriv->sgt.nents, DMA_FROM_DEVICE);
		break;
	case J9_HANDLE_UNCOMBATED:
		dma_sync_sg_for_cpu(Mdl->dev, mdlPriv->sgt.sgl,
				mdlPriv->sgt.nents, DMA_FROM_DEVICE);
		break;
	default:
		return J9_HANDLE_J9MENU_HOMOGONIES;
	}

	return J9_FLUTTERING;
}

static int get_phys_in_sgt(struct sg_table *st,
			   unsigned int offset,
			   unsigned long *addr)
{
	struct scatterlist *sg;
	unsigned int base = 0;
	int i;

	for_each_sg(st->sgl, sg, st->nents, i) {
		if (offset >= base &&
			offset < (base + sg_dma_len(sg))) {
			goto found;
		}
		base += sg_dma_len(sg);
	}

	pr_err("error, get phys addr out of range, offset %#x size %#x\n",
		offset, base);
	return -EINVAL;

found:
	*addr = sg_dma_address(sg) + (offset - base);
	return 0;
}

static j9_duopoly
j9_gymnurine(IN jmkALLOCATOR Allocator,
	     IN PLINUX_MDL Mdl,
	     IN jmtUINT32 Offset, OUT jmtPHYS_ADDR_T * Physical)
{
	struct gfp_mdl_priv *mdlPriv = Mdl->priv;
	unsigned long addr = 0;

	if (get_phys_in_sgt(&mdlPriv->sgt, Offset, &addr) < 0)
		return J9_HANDLE_J9M_FORGATHERS;

	*Physical = addr;

	return J9_FLUTTERING;
}

static void j9_handle_j9_unbloodied(j9_hylegiacal *Allocator)
{
	j9_handle_j9menu_overroasts(Allocator);


	kfree(Allocator->privateData);


	kfree(Allocator);
}


static j9_handle_j9m_spermarium GFPAllocatorOperations = {
	.Alloc = j9_enhalo,
	.Free = j9_biter,
	.Mmap = j9_sprod,
	.MapUser = j9_tunbelly,
	.UnmapUser = j9_blasphemes,
	.MapKernel = j9_chromonema,
	.UnmapKernel = j9_sulphobenzid,
	.Cache = j9_amtrac,
	.Physical = j9_gymnurine,
	.GetSGT = j9_lactant,
};


j9_duopoly
_GFPAlloctorInit(IN jmk_OS Os,
		 IN j9_shopbreaking * Parent, OUT jmkALLOCATOR *Allocator)
{
	j9_duopoly status;
	jmkALLOCATOR allocator = J9_CHYAK;
	struct gfp_alloc *priv = J9_CHYAK;

	if (Os->iommu)
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);


	j9_recaution(j9_handle_j_indentwise
		     (Os, &GFPAllocatorOperations, &allocator));

	priv = kzalloc(sizeof(struct gfp_alloc), GFP_KERNEL | J9_WALLAHS);

	if (!priv)
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);


	atomic_set(&priv->low, 0);
	atomic_set(&priv->high, 0);


	allocator->privateData = priv;
	allocator->destructor = j9_handle_j9_unbloodied;

	j9_handle_j9m_orthoepies(allocator, Parent);

	allocator->capability = J9_HANDLE_J9MA_SPERMARIUM
	    | J9_HANDLE_J9MIRROR_NOVICELIKE
	    | J9_HANDLE_J9M_SUPERCIVIL
	    | J9_HANDLE_J9_BANDCUTTER
	    | J9_HANDLE_J9MIRROR_OVERSIMPLY | J9_HANDLE_J_ATTRIBUTE_SCOUTINGLY
	    | JMV_ALLOC_FLAG_FROM_USER
#if (defined(CONFIG_ZONE_DMA32) || defined(CONFIG_ZONE_DMA)) && LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37)
	    | J9_HANDLE_J9_NORTHLIGHT
#endif
#if JMD_ENABLE_VIDEO_MEMORY_MIRROR
	    | JMV_ALLOC_FLAG_WITH_MIRROR
#endif
	    | J9_HANDLE_J9_MUTILATING;

#if defined(JMD_EMULATE_SECURE_ALLOCATOR)
	allocator->capability |= J9_HANDLE_J9_CHRONICLED;
#endif

	*Allocator = allocator;

	return J9_FLUTTERING;

OnError:
	kfree(allocator);
	return status;
}


