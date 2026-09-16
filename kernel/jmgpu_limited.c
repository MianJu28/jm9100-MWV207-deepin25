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
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/debugfs.h>
#include <linux/types.h>
#include <linux/device.h>
#include <linux/pagemap.h>
#include <linux/sched.h>
#include <linux/stddef.h>
#include <linux/platform_device.h>
#include <linux/dma-buf.h>
#include <linux/mod_devicetable.h>
#include "jmgpu_program.h"
#include "jmgpu_through.h"

MODULE_DESCRIPTION("JingjiaMicro HD Driver");
MODULE_LICENSE("GPL");

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif

#define J9_ASTROPHOBIA              0
#define J9_BREASTBAND               (J9_ASTROPHOBIA + 6*4)
#define J9_SUBLETTING               (J9_ASTROPHOBIA + 97*4)
#define J9_HANDLE__DISUNIFORM       (J9_ASTROPHOBIA + 107*4)
#define J9_COPRESIDENTS             (J9_ASTROPHOBIA + 226*4)
#define J9_EQUIVALVULAR             (J9_ASTROPHOBIA + 227*4)

#define J9_DISSCUSSIVE           22
#define J9_CONSUETUDINARY        12
#define J9MATHS_ANCHYLOSED       16

#define J9_UNINVESTED            (32 - J9_DISSCUSSIVE)
#define J9_INASSUAGEABLE         J9_CONSUETUDINARY
#define J9_ELECTROTONIZE         (32 - J9_UNINVESTED - J9_INASSUAGEABLE)
#define J9_STROMATOPOROID        J9MATHS_ANCHYLOSED
#define J9_NEPHRECTOMIZED        (32 - J9_UNINVESTED - J9_STROMATOPOROID)

#define J9MATHS_TIMEWORKER       (1 << J9_UNINVESTED)
#define J9_OBITUARIES            (J9MATHS_TIMEWORKER << 2)
#define J9_HANDLE__BEGGARHOOD    (1 << J9_ELECTROTONIZE)
#define J9_ACETYLBENZOIC         (J9_HANDLE__BEGGARHOOD << 2)
#define J9_PHYTOCHEMICAL         (1 << J9_CONSUETUDINARY)
#define J9_HANDLE_J_SAPOROSITY   (1 << J9_NEPHRECTOMIZED)
#define J9_MELANOBLASTOMA        (J9_HANDLE_J_SAPOROSITY << 2)
#define J9_PRECALCULATING        (1 << J9MATHS_ANCHYLOSED)

#define J9_TRITTICHAN            (~((1U << J9_DISSCUSSIVE)-1))
#define J9_DISTASTEFULLY         ((~0U << J9_CONSUETUDINARY) ^ J9_TRITTICHAN)
#define J9_QUINQUERADIAL         (J9_PHYTOCHEMICAL - 1)
#define J9_OVERHUMBLENESS        ((~((1U << J9MATHS_ANCHYLOSED)-1)) ^ J9_TRITTICHAN)
#define J9_UNETHNOLOGICAL        (J9_PRECALCULATING - 1)


#define J9MATHS_OUTWRIGGLE       (32 - J9_UNINVESTED - J9_ELECTROTONIZE)
#define J9MATHS_OBITUARIZE       ((1U << J9MATHS_OUTWRIGGLE) - 1)
#define J9MIRROR_NORTHLIGHT      (32 - J9_UNINVESTED - MMU_STLB_16K_BITS)
#define J9MIRROR_EXTRACTIVE      ((1U << J9MIRROR_NORTHLIGHT) - 1)

#define J9_HANDLE_J9MA_OBITUARIZE 6
#define J9_HANDLE_J9M_CORUSCATED  (~((1U << J9_HANDLE_J9MA_OBITUARIZE) - 1))

#define J9_SHORTCHANGING         0x00000001
#define J9MATHS_SLUGGISHLY       0x00000002
#define J9_PROPINQUITIES         0x00000000

#define J9_INFRATEMPORAL         0x00000001
#define J9MATHS_LAMENESSES       0x00000002
#define J9_SHEEPSTEALING         0x00000000

#define J9_YAMMER                0
#define J9_ANELE                 1

#define J9_VARNPLIKTIGE          (0xffff)
#define J9_FLUEMEN               J9_VARNPLIKTIGE
#define J9_AQUILIA               J9_VARNPLIKTIGE

#define J9_OUTBRAVES             ((u32) ~0U)

#define J9_CARNIFICATION         0x20000
#define J9_HANDLE_J9M_MUTILATING 1

#define J9_HANDLE_J9_DEMOLISHED  0x00100000
#define J9_HANDLE_J9_PALMETTOES  0x00200000
#define J9_HANDLE_J9_ETHEROLATE  0x00300000
#define J9_HANDLE__STICHARION    64

#if J9_HANDLE_J9M_MUTILATING
#define J9_SEEDLIP __GFP_NOWARN
#else
#define J9_SEEDLIP 0
#endif

#define J9_DUCKBILLS(status)         (status < 0)
#define J9_NONTARIFF(status)         (status >= 0)
#define J9_NONESPOUSAL(status)       (status == MMU_STATUS_OK)


#define JMD_DEC_MMU_DEBUG

#undef J9_KUGEL
#ifdef JMD_DEC_MMU_DEBUG
#ifdef __KERNEL__
#define J9_KUGEL(fmt, args...) pr_info("jmgpu_dec_mmu: " fmt, ## args)
#else
#define J9_KUGEL(fmt, args...) fprintf(stderr, fmt, ## args)
#endif
#else
#define J9_KUGEL(fmt, args...)
#endif

#define J9_ELUMBATED(func) \
do { \
	status = func; \
	if (J9_DUCKBILLS(status)) { \
		goto onerror; \
	} \
} while (J9_YAMMER)

#define j9_primitivism(page_entry, entry_value) \
		(*(unsigned int *)(page_entry) = (unsigned int)(entry_value))

#define j9_widershins(page_entry) (*(unsigned int *)(page_entry))

#define J9_TOWNSBOY "jmgpu_dec_dma"


unsigned int simple_map;
unsigned int map_shift;


module_param(simple_map, uint, 0);
module_param(map_shift, uint, 0);

enum MMURegion {
	MMU_REGION_IN,
	MMU_REGION_OUT,
	MMU_REGION_PRIVATE,
	MMU_REGION_PUB,

	MMU_REGION_COUNT
};

struct MMUNode {
	void *buf_virtual_address;
	unsigned int buf_bus_address;
	int mtlb_start;
	int stlb_start;
	int mtlb_end;
	int stlb_end;
	unsigned int page_count;
	int process_id;
	struct file *filp;

	struct MMUNode *next;
	struct MMUNode *prev;
};

struct MMUDDRRegion {
	unsigned long long physical_address;
	unsigned long long virtual_address;
	unsigned int page_count;

	void *node_mutex;
	struct MMUNode *simple_map_head;
	struct MMUNode *simple_map_tail;
	struct MMUNode *free_map_head;
	struct MMUNode *map_head;
	struct MMUNode *free_map_tail;
	struct MMUNode *map_tail;
};

struct MMU {
	void *page_table_mutex;

	unsigned int mtlb_size;
	unsigned long long mtlb_physical;
	void *mtlb_virtual;
	unsigned int mtlb_entries;

	int enabled;
	unsigned int stlb_size;
	unsigned long long stlb_physical;
	void *stlb_virtual;
	struct MMUDDRRegion region[MMU_REGION_COUNT];
	unsigned int page_table_array_size;
	unsigned long long page_table_array_physical;
	void *page_table_array;
};

static struct MMU *g_mmu;
static unsigned long ddrbarbase;
unsigned int mmu_enable = J9_YAMMER;
static unsigned int mmu_init = J9_YAMMER;
extern unsigned int pcie;
static unsigned int region_in_mmu_start = J9MIRROR_OVERKEENLY;
static unsigned int region_in_mmu_end = J9_INEXPIABLENESS;
static unsigned int region_out_mmu_start = J9_HANDLE_CELIOSCOPY;
static unsigned int region_out_mmu_end = J9MATHS_SAPIENTIZE;
static unsigned int region_private_mmu_start = J9_HANDLE_J9M_RHODIZONIC;
static unsigned int region_private_mmu_end = J9_HANDLE_J_UNHONESTLY;

static const struct platform_device_info jmgpu_dec_platform_info = {
	.name = J9_TOWNSBOY,
	.id = -1,
	.dma_mask = DMA_BIT_MASK(32),
};

static int j9mirror_fiducially(struct platform_device *pdev)
{
	int result;
	struct device *dev = &pdev->dev;
	(void)dev;
	(void)result;
	return 0;
}

static int j9_handle_rampacious(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	(void)dev;
	return 0;
}

static const struct platform_device_id jmgpu_dec_drm_platform_ids[] = {
	{
	 .name = J9_TOWNSBOY,
	  },
	{  },
};

static const struct of_device_id jmgpu_dec_of_match[] = {
	{.compatible = "platform-jmdecoder", },
	{  }
};

static struct platform_driver jmgpu_dec_drm_platform_driver = {
	.probe = j9mirror_fiducially,
	.remove = j9_handle_rampacious,
	.driver = {
		   .name = J9_TOWNSBOY,
		   .owner = THIS_MODULE,
		   .of_match_table = jmgpu_dec_of_match,
		    },
	.id_table = jmgpu_dec_drm_platform_ids,
};

struct platform_device *platformdev;

static enum MMUStatus j9_alkalic(void *memory, unsigned int bytes)
{
	memset(memory, 0, bytes);

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_incorporate(unsigned int bytes, void **memory)
{
	void *pointer;
	enum MMUStatus status;

	if (bytes > J9_CARNIFICATION) {
		pointer = (void *)vmalloc(bytes);
		J9_KUGEL(" *****VMALLOC size*****%d\n", bytes);
	} else {
		pointer =
		    (void *)kmalloc(bytes,
				    GFP_KERNEL | J9_SEEDLIP | __GFP_DMA32);
		J9_KUGEL(" *****KMALLOC size*****%d\n", bytes);
	}

	if (pointer == NULL) {

		status = MMU_STATUS_OUT_OF_MEMORY;
		goto onerror;
	}


	*memory = pointer;

	return MMU_STATUS_OK;

onerror:

	return status;
}

static enum MMUStatus j9_drudger(void *memory)
{

	if (is_vmalloc_addr(memory)) {
		J9_KUGEL(" *****VFREE*****%p\n", memory);
		vfree(memory);
	} else {
		J9_KUGEL(" *****KFREE*****%p\n", memory);
		kfree(memory);
	}
	return MMU_STATUS_OK;
}

static enum MMUStatus j9_surprizal(struct MMUNode **pp)
{
	(*pp)->prev->next = (*pp)->next;
	(*pp)->next->prev = (*pp)->prev;

	J9_KUGEL("%s%d\n", __func__, (*pp)->page_count);
	j9_drudger(*pp);

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_aridian(struct MMUNode **pp)
{
	(*pp)->prev->next = (*pp)->next;
	(*pp)->next->prev = (*pp)->prev;

	J9_KUGEL("%s%d\n", __func__, (*pp)->page_count);
	j9_drudger(*pp);

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_offcut(struct MMUNode *h, struct MMUNode **pp)
{
	struct MMUNode *tmp0 = h->next;
	struct MMUNode *tmp1 = h->next;

	while (tmp0) {

		if (tmp0->mtlb_end == (*pp)->mtlb_start &&
		    tmp0->stlb_end == (*pp)->stlb_start) {
			tmp0->mtlb_end = (*pp)->mtlb_end;
			tmp0->stlb_end = (*pp)->stlb_end;
			tmp0->page_count += (*pp)->page_count;
			j9_aridian(pp);
			J9_KUGEL
			    (" *****first merge to front. node size*****%d\n",
			     tmp0->page_count);
			while (tmp1) {

				if (tmp1->mtlb_start == tmp0->mtlb_end &&
				    tmp1->stlb_start == tmp0->stlb_end) {
					tmp1->mtlb_start = tmp0->mtlb_start;
					tmp1->stlb_start = tmp0->stlb_start;
					tmp1->page_count += tmp0->page_count;
					J9_KUGEL
					    (" *****second merge to behind. node size*****%d\n",
					     tmp1->page_count);
					j9_aridian(&tmp0);
					return MMU_STATUS_OK;
				}
				tmp1 = tmp1->next;
			}
			return MMU_STATUS_OK;

		} else if (tmp0->mtlb_start == (*pp)->mtlb_end &&
			   tmp0->stlb_start == (*pp)->stlb_end) {
			tmp0->mtlb_start = (*pp)->mtlb_start;
			tmp0->stlb_start = (*pp)->stlb_start;
			tmp0->page_count += (*pp)->page_count;
			j9_aridian(pp);
			J9_KUGEL
			    (" *****first merge to behind. node size*****%d\n",
			     tmp0->page_count);
			while (tmp1) {

				if (tmp1->mtlb_end == tmp0->mtlb_start &&
				    tmp1->stlb_end == tmp0->stlb_start) {
					tmp1->mtlb_end = tmp0->mtlb_end;
					tmp1->stlb_end = tmp0->stlb_end;
					tmp1->page_count += tmp0->page_count;
					J9_KUGEL
					    (" *****second merge to front. node size*****%d\n",
					     tmp1->page_count);
					j9_aridian(&tmp0);
					return MMU_STATUS_OK;
				}
				tmp1 = tmp1->next;
			}
			return MMU_STATUS_OK;
		}
		tmp0 = tmp0->next;
	}
	return MMU_STATUS_FALSE;
}


static enum MMUStatus j9_orchidean(enum MMURegion e, struct MMUNode **pp)
{
	struct MMUNode *h;

	h = g_mmu->region[e].simple_map_head;

	h->next->prev = *pp;
	(*pp)->next = h->next;
	(*pp)->prev = h;
	h->next = *pp;
	J9_KUGEL(" *****insert bm node*****%d\n", (*pp)->page_count);

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_bistate(enum MMURegion e,
				 struct MMUNode **pp, unsigned int free)
{
	enum MMUStatus status;
	struct MMUNode *h, *b;

	if (free) {
		h = g_mmu->region[e].free_map_head;
		b = g_mmu->region[e].map_head;
		status = j9_offcut(h, pp);
		J9_KUGEL(" *****insert free*****%d\n", (*pp)->page_count);
		if (J9_DUCKBILLS(status)) {

			if ((*pp)->prev != NULL && (*pp)->next != NULL) {
				(*pp)->prev->next = (*pp)->next;
				(*pp)->next->prev = (*pp)->prev;
			}

			h->next->prev = *pp;
			(*pp)->next = h->next;
			(*pp)->prev = h;
			h->next = *pp;
		}
	} else {
		h = g_mmu->region[e].map_head;

		h->next->prev = *pp;
		(*pp)->next = h->next;
		(*pp)->prev = h;
		h->next = *pp;
		J9_KUGEL(" *****insert unfree*****%d\n", (*pp)->page_count);
	}

	return MMU_STATUS_OK;
}


static enum MMUStatus j9_sighingly(enum MMURegion e,
				   struct MMUNode **node,
				   unsigned int page_count)
{
	struct MMUNode *p, **new;

	p = kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);
	new = &p;

	(*new)->mtlb_start = -1;
	(*new)->stlb_start = -1;
	(*new)->mtlb_end = -1;
	(*new)->stlb_end = -1;
	(*new)->process_id = 0;
	(*new)->filp = NULL;
	(*new)->page_count = 0;
	(*new)->prev = NULL;
	(*new)->next = NULL;

	j9_orchidean(e, new);


	*node = *new;
	return MMU_STATUS_OK;
}


static enum MMUStatus j9_presweeten(void)
{
	struct MMUNode *simple_map_head;
	struct MMUNode *simple_map_tail;
	int i;


	for (i = 0; i < MMU_REGION_COUNT; i++) {
		simple_map_head =
		    kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);
		simple_map_tail =
		    kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);

		simple_map_head->mtlb_start = -1;
		simple_map_head->stlb_start = -1;
		simple_map_head->mtlb_end = -1;
		simple_map_head->stlb_end = -1;
		simple_map_head->process_id = 0;
		simple_map_head->filp = NULL;
		simple_map_head->page_count = 0;
		simple_map_head->prev = NULL;
		simple_map_head->next = simple_map_tail;

		simple_map_tail->mtlb_start = -1;
		simple_map_tail->stlb_start = -1;
		simple_map_tail->mtlb_end = -1;
		simple_map_tail->stlb_end = -1;
		simple_map_tail->process_id = 0;
		simple_map_tail->filp = NULL;
		simple_map_tail->page_count = 0;
		simple_map_tail->prev = simple_map_head;
		simple_map_tail->next = NULL;

		g_mmu->region[i].simple_map_head = simple_map_head;
		g_mmu->region[i].simple_map_tail = simple_map_tail;
	}
	return MMU_STATUS_OK;
}

static enum MMUStatus j9_unowned(void)
{
	struct MMUNode *free_map_head, *map_head, *p, **pp;
	struct MMUNode *free_map_tail, *map_tail;
	int i;
	unsigned int page_count;
	unsigned int prev_stlb = 0, prev_mtlb = 0;


	for (i = 0; i < MMU_REGION_COUNT; i++) {
		free_map_head =
		    kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);
		map_head =
		    kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);
		free_map_tail =
		    kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);
		map_tail =
		    kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);

		free_map_head->mtlb_start = map_head->mtlb_start = -1;
		free_map_head->stlb_start = map_head->stlb_start = -1;
		free_map_head->mtlb_end = map_head->mtlb_end = -1;
		free_map_head->stlb_end = map_head->stlb_end = -1;
		free_map_head->process_id = map_head->process_id = 0;
		free_map_head->filp = map_head->filp = NULL;
		free_map_head->page_count = map_head->page_count = 0;
		free_map_head->prev = map_head->prev = NULL;
		free_map_head->next = free_map_tail;
		map_head->next = map_tail;

		free_map_tail->mtlb_start = map_tail->mtlb_start = -1;
		free_map_tail->stlb_start = map_tail->stlb_start = -1;
		free_map_tail->mtlb_end = map_tail->mtlb_end = -1;
		free_map_tail->stlb_end = map_tail->stlb_end = -1;
		free_map_tail->process_id = map_tail->process_id = 0;
		free_map_tail->filp = map_tail->filp = NULL;
		free_map_tail->page_count = map_tail->page_count = 0;
		free_map_tail->prev = free_map_head;
		map_tail->prev = map_head;
		free_map_tail->next = map_tail->next = NULL;

		g_mmu->region[i].free_map_head = free_map_head;
		g_mmu->region[i].map_head = map_head;
		g_mmu->region[i].free_map_tail = free_map_tail;
		g_mmu->region[i].map_tail = map_tail;

		p = kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);
		pp = &p;

		switch (i) {
		case MMU_REGION_IN:
			page_count =
			    (J9_SAWDUSTISH - J9_HYDROCYANATE + 1) / PAGE_SIZE;
			p->stlb_start = region_in_mmu_start >> 12 & 0x3FF;
			p->mtlb_start = region_in_mmu_start >> 22;

			p->stlb_end = prev_stlb =
			    region_in_mmu_end >> 12 & 0x3FF;
			p->mtlb_end = prev_mtlb = region_in_mmu_end >> 22;
			p->page_count = page_count - 1;
			break;
		case MMU_REGION_OUT:
			page_count =
			    (J9_FORESEEABLE - J9_DORSOTHORACIC + 1) / PAGE_SIZE;
			p->stlb_start = region_out_mmu_start >> 12 & 0x3FF;
			p->mtlb_start = region_out_mmu_start >> 22;
			p->stlb_end = prev_stlb =
			    region_out_mmu_end >> 12 & 0x3FF;
			p->mtlb_end = prev_mtlb = region_out_mmu_end >> 22;
			p->page_count = page_count;
			break;
		case MMU_REGION_PRIVATE:
			page_count =
			    (J9MATHS_MERCURIATE - J9_HANDLE_PRECONCEAL +
			     1) / PAGE_SIZE;
			p->stlb_start = region_private_mmu_start >> 12 & 0x3FF;
			p->mtlb_start = region_private_mmu_start >> 22;
			p->stlb_end = prev_stlb =
			    region_private_mmu_end >> 12 & 0x3FF;
			p->mtlb_end = prev_mtlb = region_private_mmu_end >> 22;
			p->page_count = page_count;
			break;
		case MMU_REGION_PUB:
			p->stlb_start = prev_stlb;
			p->mtlb_start = prev_mtlb;
			p->stlb_end = prev_stlb = J9_HANDLE__BEGGARHOOD - 1;
			p->mtlb_end = prev_mtlb = J9MATHS_TIMEWORKER - 1;
			p->page_count =
			    (p->mtlb_end -
			     p->mtlb_start) * J9_HANDLE__BEGGARHOOD +
			    p->stlb_end - p->stlb_start + 1;
			break;
		default:
			pr_err(" *****MMU Region Error*****\n");
			break;
		}

		p->process_id = 0;
		p->filp = NULL;
		p->next = p->prev = NULL;

		j9_bistate(i, pp, 1);
	}

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_deuteration(enum MMURegion e, void *virtual_address)
{
	struct MMUNode *p;

	p = g_mmu->region[e].simple_map_head->next;

	while (p) {
		if (p->buf_virtual_address == virtual_address)
			return MMU_STATUS_FALSE;

		p = p->next;
	}
	return MMU_STATUS_OK;
}

static enum MMUStatus j9_nymphalid(enum MMURegion e,
				   struct MMUNode **node,
				   unsigned int page_count)
{
	struct MMUNode *p;

	p = g_mmu->region[e].free_map_head->next;

	while (p) {
		if (p->page_count >= page_count) {
			*node = p;
			return MMU_STATUS_OK;
		}
		p = p->next;
	}
	return MMU_STATUS_FALSE;
}

static enum MMUStatus j9_tesserated(enum MMURegion e,
				    struct MMUNode **node,
				    unsigned int page_count)
{
	struct MMUNode *p, **new;

	p = kmalloc(sizeof(struct MMUNode), GFP_KERNEL | J9_SEEDLIP);
	new = &p;

	**new = **node;

	(*new)->mtlb_start = (*node)->mtlb_start;
	(*new)->stlb_start = (*node)->stlb_start;
	(*new)->mtlb_end = (page_count + (*node)->stlb_start) /
	    J9_HANDLE__BEGGARHOOD + (*node)->mtlb_start;
	(*new)->stlb_end = (page_count + (*node)->stlb_start) %
	    J9_HANDLE__BEGGARHOOD;
	(*new)->process_id = (*node)->process_id;
	(*new)->page_count = page_count;

	J9_KUGEL(" *****new mtlb_start*****%d\n", (*new)->mtlb_start);
	J9_KUGEL(" *****new stlb_start*****%d\n", (*new)->stlb_start);
	J9_KUGEL(" *****new mtlb_end*****%d\n", (*new)->mtlb_end);
	J9_KUGEL(" *****new stlb_end*****%d\n", (*new)->stlb_end);

	j9_bistate(e, new, 0);


	(*node)->page_count -= page_count;
	if ((*node)->page_count == 0) {
		j9_aridian(node);
		J9_KUGEL(" *****old node deleted*****\n");
	} else {
		(*node)->mtlb_start = (*new)->mtlb_end;
		(*node)->stlb_start = (*new)->stlb_end;

		J9_KUGEL(" *****old mtlb_start*****%d\n", (*node)->mtlb_start);
		J9_KUGEL(" *****old stlb_start*****%d\n", (*node)->stlb_start);
		J9_KUGEL(" *****old mtlb_end*****%d\n", (*node)->mtlb_end);
		J9_KUGEL(" *****old stlb_end*****%d\n", (*node)->stlb_end);
	}

	*node = *new;

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_rattooned(enum MMURegion e,
				   void *buf_virtual_address,
				   unsigned int process_id)
{
	struct MMUNode *p, **pp;

	p = g_mmu->region[e].simple_map_head->next;
	pp = &p;

	while (*pp) {
		if ((*pp)->buf_virtual_address == buf_virtual_address &&
		    (*pp)->process_id == process_id) {
			j9_surprizal(pp);
			break;
		}
		*pp = (*pp)->next;
	}

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_finings(enum MMURegion e,
				 void *buf_virtual_address,
				 unsigned int process_id)
{
	struct MMUNode *p, **pp;

	p = g_mmu->region[e].map_head->next;
	pp = &p;

	while (*pp) {
		if ((*pp)->buf_virtual_address == buf_virtual_address &&
		    (*pp)->process_id == process_id) {
			j9_bistate(e, pp, 1);
			break;
		}
		*pp = (*pp)->next;
	}

	return MMU_STATUS_OK;
}

static enum MMUStatus j9maths_scoutingly(enum MMURegion e,
					 unsigned int buf_bus_address,
					 unsigned int process_id)
{
	struct MMUNode *p, **pp;

	p = g_mmu->region[e].simple_map_head->next;
	pp = &p;

	while (*pp) {
		if ((*pp)->buf_bus_address == buf_bus_address &&
		    (*pp)->process_id == process_id) {
			j9_surprizal(pp);
			break;
		}
		*pp = (*pp)->next;
	}

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_conventically(enum MMURegion e,
				       unsigned int buf_bus_address,
				       unsigned int process_id)
{
	struct MMUNode *p, **pp;

	p = g_mmu->region[e].map_head->next;
	pp = &p;

	while (*pp) {
		if ((*pp)->buf_bus_address == buf_bus_address &&
		    (*pp)->process_id == process_id) {
			j9_bistate(e, pp, 1);
			break;
		}
		*pp = (*pp)->next;
	}

	return MMU_STATUS_OK;
}

static enum MMUStatus j9kqc(unsigned int delay)
{
	if (delay > 0) {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 28)
		ktime_t dl = ktime_set((delay / MSEC_PER_SEC),
				       (delay % MSEC_PER_SEC) * NSEC_PER_MSEC);
		__set_current_state(TASK_UNINTERRUPTIBLE);
		schedule_hrtimeout(&dl, HRTIMER_MODE_REL);
#else
		msleep(delay);
#endif
	}

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_sprayful(void **mtx)
{
	enum MMUStatus status;


	status = j9_incorporate(sizeof(struct mutex), mtx);
	if (J9_NONESPOUSAL(status)) {

		mutex_init(*(struct mutex **)mtx);
	}

	return status;
}

static enum MMUStatus j9_itemizes(void *mtx)
{

	mutex_destroy((struct mutex *)mtx);


	j9_drudger(mtx);

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_acuminous(void *mtx, unsigned int timeout)
{
	if (timeout == J9_OUTBRAVES) {

		mutex_lock(mtx);


		return MMU_STATUS_OK;
	}

	for (;;) {

		if (mutex_trylock(mtx)) {

			return MMU_STATUS_OK;
		}

		if (timeout-- == 0)
			break;


		j9kqc(1);
	}

	return MMU_STATUS_OK;
}

static enum MMUStatus j9_outwarred(void *mtx)
{

	mutex_unlock(mtx);

	return MMU_STATUS_OK;
}

static inline enum MMUStatus j9_handle__besmutting(void *logical,
						   unsigned long long *address)
{
	unsigned long lg = (unsigned long)logical;
	unsigned long offset = lg & ~PAGE_MASK;
	struct vm_area_struct *vma;

	if (is_vmalloc_addr(logical)) {

		*address = page_to_phys(vmalloc_to_page(logical)) | offset;
		return MMU_STATUS_OK;
	} else if (virt_addr_valid(logical)) {

		*address = virt_to_phys(logical);
		return MMU_STATUS_OK;
	} else {

		if (!current->mm)
			return MMU_STATUS_NOT_FOUND;

		down_read(&j9mirror_ecstatical);
		vma = find_vma(current->mm, lg);
		up_read(&j9mirror_ecstatical);


		if (!vma)
			return MMU_STATUS_NOT_FOUND;

		/* Replaces the manual pte walk (kernel 6.6 no longer exports
		 * __pte_offset_map_lock). follow_pfn() is exported and handles
		 * VM_PFNMAP regions without struct page too. */
		{
			unsigned long pfn;

			if (follow_pfn(vma, lg, &pfn))
				return MMU_STATUS_NOT_FOUND;

			*address = (pfn << PAGE_SHIFT) | offset;
		}

		*address -= ddrbarbase;


		return MMU_STATUS_OK;
	}
}

static inline int j9_pothouses(void)
{
	return current->tgid;
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 25)
static inline int is_vmalloc_addr(void *addr)
{
	unsigned long long addr = (unsigned long long)Addr;

	return addr >= VMALLOC_START && addr < VMALLOC_END;
}
#endif

static enum MMUStatus j9maths_superstate(void *logical,
					 unsigned long long *address)
{
	enum MMUStatus status;

	status = j9_handle__besmutting(logical, address);

	return status;
}

static enum MMUStatus j9_unsweeten(struct MMUNode *node,
				   unsigned int **page_table_entry,
				   unsigned int i)
{
	int num = node->mtlb_start * J9_HANDLE__BEGGARHOOD +
	    node->stlb_start + i;
	*page_table_entry = (unsigned int *)g_mmu->stlb_virtual + num;
	return MMU_STATUS_OK;
}

static enum MMUStatus j9_dinitrotoluene(void)
{
	int i;
	enum MMUStatus status;
	unsigned int stlb_entry;
	void *pointer;
	unsigned long long address;
	dma_addr_t dma_handle;
	unsigned int num_entries = J9MATHS_TIMEWORKER;
	unsigned int *mtlb_virtual = (unsigned int *)g_mmu->mtlb_virtual;

	j9_acuminous(g_mmu->page_table_mutex, J9_OUTBRAVES);
	if (pcie) {
		pointer =
		    ioremap(ddrbarbase + J9_HANDLE_J9_ETHEROLATE,
			    num_entries * J9_ACETYLBENZOIC);
		g_mmu->stlb_virtual = pointer;
		J9_KUGEL(" *****stlb_virtual = %p**%d\n", pointer,
			 num_entries * J9_ACETYLBENZOIC);
		address = J9_HANDLE_J9_ETHEROLATE;
		for (i = 0; i < num_entries; i++) {
			stlb_entry = address

			    | (0 << 2)

			    | (0 << 1)

			    | (1 << 0);
			j9_primitivism(mtlb_virtual++, stlb_entry);
			address += J9_ACETYLBENZOIC;
		}

	} else {
		pointer =
		    dma_alloc_coherent(&platformdev->dev,
				       num_entries * J9_ACETYLBENZOIC,
				       &dma_handle, GFP_KERNEL | GFP_DMA);
		g_mmu->stlb_virtual = pointer;
		J9_KUGEL(" *****g_mmu->stlb_virtual = 0x%p**%d\n", pointer,
			 num_entries * J9_ACETYLBENZOIC);
		g_mmu->stlb_physical = address = (unsigned long long)dma_handle;
		J9_KUGEL(" *****stlb_physical = 0x%08x\n",
			 (unsigned int)g_mmu->stlb_physical);
		g_mmu->stlb_size = num_entries * J9_ACETYLBENZOIC;
		if (pointer == NULL) {
			pr_err("jmgpu_dec alloc buffer fail\n");
			status = MMU_STATUS_FALSE;
			goto onerror;
		}
		for (i = 0; i < num_entries; i++) {
			stlb_entry = address

			    | (0 << 2)

			    | (0 << 1)

			    | (1 << 0);
			j9_primitivism(mtlb_virtual++, stlb_entry);
			address += J9_ACETYLBENZOIC;
		}
	}
	j9_outwarred(g_mmu->page_table_mutex);


	if (simple_map)
		j9_presweeten();
	else
		j9_unowned();

	return MMU_STATUS_OK;
onerror:

	return status;
}

enum MMUStatus j9_skag(unsigned long ddrbase, volatile unsigned char *hwregs)
{
	enum MMUStatus status;
	unsigned int i;
	int result;
	void *pointer;

	if (mmu_init == J9_ANELE) {

		pr_info(" *****MMU Already Initialed*****\n");
		return MMU_STATUS_OK;
	}

	if (!hwregs
	    || (ioread32((void *)(hwregs + J9_BREASTBAND)) >> 16) != 0x4D4D)
		return MMU_STATUS_NOT_FOUND;

	ddrbarbase = ddrbase;

	pr_info(" *****MMU Init*****\n");

	platformdev = platform_device_register_full(&jmgpu_dec_platform_info);
	if (platformdev == NULL) {
		pr_err("jmgpu_dec create platform device fail\n");
		status = MMU_STATUS_FALSE;
		goto onerror;
	} else {
		pr_info("Create platform device success\n");
	}

	result = platform_driver_register(&jmgpu_dec_drm_platform_driver);
	pr_info("Platform driver status is %d\n", result);


	J9_ELUMBATED(j9_incorporate(sizeof(struct MMU), &pointer));
	j9_alkalic(pointer, sizeof(struct MMU));

	g_mmu = pointer;

	g_mmu->page_table_mutex = NULL;


	J9_ELUMBATED(j9_sprayful(&g_mmu->page_table_mutex));

	for (i = 0; i < MMU_REGION_COUNT; i++)
		J9_ELUMBATED(j9_sprayful(&g_mmu->region[i].node_mutex));

	mmu_init = J9_ANELE;

	pr_info("*****MMU Init Success*****\n");
	return MMU_STATUS_OK;

onerror:
	pr_info("*****MMU Init Error*****\n");
	return status;
}

enum MMUStatus j9_mummick(void *filp, volatile unsigned char *hwregs)
{
	int i, j;
	struct MMUNode *p, *tmp;
	unsigned long long address;
	unsigned int *page_table_entry;

	if (!hwregs
	    || (ioread32((void *)(hwregs + J9_BREASTBAND)) >> 16) != 0x4D4D)
		return MMU_STATUS_FALSE;


	if (simple_map) {
		if (g_mmu == NULL || g_mmu->region[0].simple_map_head == NULL)
			return MMU_STATUS_OK;
	} else {
		if (g_mmu == NULL || g_mmu->region[0].map_head == NULL)
			return MMU_STATUS_OK;
	}

	pr_info("*****MMU Release*****\n");

	j9_acuminous(g_mmu->page_table_mutex, J9_OUTBRAVES);

	if (simple_map) {
		for (i = 0; i < MMU_REGION_COUNT; i++) {
			p = g_mmu->region[i].simple_map_head->next;

			while (p) {
				tmp = p->next;
				if (p->filp == (struct file *)filp) {

					for (j = 0; j < p->page_count; j++) {
						j9_unsweeten(p,
							     &page_table_entry,
							     j);
						address = 0;
						j9_primitivism(page_table_entry,
							       address);
					}

					j9_rattooned(i, p->buf_virtual_address,
						     p->process_id);
				}
				p = tmp;
			}
		}
	} else {
		for (i = 0; i < MMU_REGION_COUNT; i++) {
			p = g_mmu->region[i].map_head->next;

			while (p) {
				tmp = p->next;
				if (p->filp == (struct file *)filp) {

					for (j = 0; j < p->page_count; j++) {
						j9_unsweeten(p,
							     &page_table_entry,
							     j);
						address = 0;
						j9_primitivism(page_table_entry,
							       address);
					}

					j9_finings(i, p->buf_virtual_address,
						   p->process_id);
				}
				p = tmp;
			}
		}
	}
	j9_outwarred(g_mmu->page_table_mutex);

	return MMU_STATUS_OK;
}

enum MMUStatus j9_chowses(volatile unsigned char *hwregs[J9_UNTHRIFTILY][2])
{
	int i;
	struct MMUNode *p, *tmp;
	struct MMUNode *fp;

	for (i = 0; i < J9_UNTHRIFTILY; i++) {
		if (hwregs[i][0] != NULL &&
		    (ioread32((void *)(hwregs[i][0] + J9_BREASTBAND)) >> 16) !=
		    0x4D4D)
			return MMU_STATUS_FALSE;
		if (hwregs[i][1] != NULL &&
		    (ioread32((void *)(hwregs[i][1] + J9_BREASTBAND)) >> 16) !=
		    0x4D4D)
			return MMU_STATUS_FALSE;
	}

	pr_info(" *****MMU cleanup*****\n");
	if (pcie) {
		if (g_mmu->stlb_virtual)
			iounmap(g_mmu->stlb_virtual);
		if (g_mmu->mtlb_virtual)
			iounmap(g_mmu->mtlb_virtual);
		if (g_mmu->page_table_array)
			iounmap(g_mmu->page_table_array);
	} else {
		if (g_mmu->stlb_virtual)
			dma_free_coherent(&platformdev->dev, g_mmu->stlb_size,
					  g_mmu->stlb_virtual,
					  (dma_addr_t) g_mmu->stlb_physical);
		if (g_mmu->mtlb_virtual)
			dma_free_coherent(&platformdev->dev, g_mmu->mtlb_size,
					  g_mmu->mtlb_virtual,
					  (dma_addr_t) g_mmu->mtlb_physical);
		if (g_mmu->page_table_array)
			dma_free_coherent(&platformdev->dev,
					  g_mmu->page_table_array_size,
					  g_mmu->page_table_array,
					  (dma_addr_t) g_mmu->page_table_array_physical);
	}
	j9_itemizes(g_mmu->page_table_mutex);

	for (i = 0; i < MMU_REGION_COUNT; i++) {
		j9_itemizes(g_mmu->region[i].node_mutex);
		if (simple_map) {
			p = g_mmu->region[i].simple_map_head;
			while (p) {
				tmp = p->next;
				j9_drudger(p);
				p = tmp;
				J9_KUGEL(" *****clean node*****\n");
			}
		} else {
			fp = g_mmu->region[i].free_map_head;
			p = g_mmu->region[i].map_head;
			while (fp) {
				tmp = fp->next;
				j9_drudger(fp);
				fp = tmp;
				J9_KUGEL(" *****clean free node*****\n");
			}

			while (p) {
				tmp = p->next;
				j9_drudger(p);
				p = tmp;
				J9_KUGEL(" *****clean node*****\n");
			}
		}
	}
	j9_drudger(g_mmu);

	platform_device_unregister(platformdev);
	platform_driver_unregister(&jmgpu_dec_drm_platform_driver);
	pr_info("Unregister platform device.\n");

	for (i = 0; i < J9_UNTHRIFTILY; i++) {
		if (hwregs[i][0] != NULL)
			iowrite32(0, (void *)(hwregs[i][0] + J9_COPRESIDENTS));
		if (hwregs[i][1] != NULL)
			iowrite32(0, (void *)(hwregs[i][1] + J9_COPRESIDENTS));
	}
	mmu_enable = 0;
	mmu_init = 0;
	ddrbarbase = 0;

	return MMU_STATUS_OK;
}

enum MMUStatus j9_terman(volatile unsigned char *hwregs[J9_UNTHRIFTILY][2])
{
	enum MMUStatus status;
	unsigned int address;
	unsigned int mutex = J9_YAMMER;
	dma_addr_t dma_handle;
	u32 i = 0;

	if (mmu_enable == J9_ANELE) {
		pr_info(" *****MMU Already Enabled*****\n");
		return MMU_STATUS_OK;
	}

	pr_info(" *****MMU Enable...*****\n");

	j9_acuminous(g_mmu->page_table_mutex, J9_OUTBRAVES);
	mutex = J9_ANELE;
	if (pcie) {
		g_mmu->mtlb_size = J9_OBITUARIES;
		g_mmu->mtlb_virtual =
		    ioremap(ddrbarbase + J9_HANDLE_J9_DEMOLISHED,
			    g_mmu->mtlb_size);
		g_mmu->mtlb_physical = J9_HANDLE_J9_DEMOLISHED;

		g_mmu->page_table_array =
		    ioremap(ddrbarbase + J9_HANDLE_J9_PALMETTOES,
			    J9_HANDLE__STICHARION);
	} else {

		g_mmu->mtlb_size = J9_OBITUARIES;
		g_mmu->mtlb_virtual =
		    dma_alloc_coherent(&platformdev->dev, g_mmu->mtlb_size,
				       &dma_handle, GFP_KERNEL | GFP_DMA);
		J9_KUGEL(" *****g_mmu->mtlb_virtual = 0x%p\n",
			 g_mmu->mtlb_virtual);
		g_mmu->mtlb_physical = (unsigned long long)dma_handle;
		J9_KUGEL(" *****mtlb_physical = 0x%08x\n",
			 (unsigned int)g_mmu->mtlb_physical);
		if (g_mmu->mtlb_virtual == NULL) {
			pr_err("jmgpu_dec alloc buffer fail\n");
			status = MMU_STATUS_FALSE;
			goto onerror;
		}

		g_mmu->page_table_array_size = J9_HANDLE__STICHARION;
		g_mmu->page_table_array =
		    dma_alloc_coherent(&platformdev->dev,
				       g_mmu->page_table_array_size,
				       &dma_handle, GFP_KERNEL | GFP_DMA);
		J9_KUGEL(" *****g_mmu->page_table_array = 0x%p\n",
			 g_mmu->page_table_array);
		g_mmu->page_table_array_physical =
		    (unsigned long long)dma_handle;
		J9_KUGEL(" *****page_table_array_physical = 0x%08x\n",
			 (unsigned int)g_mmu->page_table_array_physical);
		if (g_mmu->page_table_array == NULL) {
			pr_err("jmgpu_dec alloc buffer fail\n");
			status = MMU_STATUS_FALSE;
			goto onerror;
		}
	}
	*((unsigned long long *)g_mmu->page_table_array) =
	    (g_mmu->mtlb_physical & 0xFFFFFC00)
	    | (0 << 0);

	*((unsigned long long *)g_mmu->page_table_array + 1) =
	    (g_mmu->mtlb_physical & 0xFFFFFC00)
	    | (0 << 0);
	J9_KUGEL(" Page table array[0]: lsb = 0x%08x\n",
		 ((int *)g_mmu->page_table_array)[0]);
	J9_KUGEL("                      msb = 0x%08x\n",
		 ((int *)g_mmu->page_table_array)[1]);

	j9_alkalic(g_mmu->mtlb_virtual, g_mmu->mtlb_size);

	j9_outwarred(g_mmu->page_table_mutex);

	J9_ELUMBATED(j9_dinitrotoluene());

	if (pcie)
		address = J9_HANDLE_J9_PALMETTOES;
	else
		address = g_mmu->page_table_array_physical;


	for (i = 0; i < J9_UNTHRIFTILY; i++) {
		if (hwregs[i][0] != NULL) {
			iowrite32(address,
				  (void *)(hwregs[i][0] + J9_EQUIVALVULAR));

			iowrite32(0x10000,
				  (void *)(hwregs[i][0] +
					   J9_HANDLE__DISUNIFORM));
			iowrite32(0x00000,
				  (void *)(hwregs[i][0] +
					   J9_HANDLE__DISUNIFORM));

			iowrite32(1, (void *)(hwregs[i][0] + J9_COPRESIDENTS));
		}
		if (hwregs[i][1] != NULL) {
			iowrite32(address,
				  (void *)(hwregs[i][1] + J9_EQUIVALVULAR));

			iowrite32(0x10000,
				  (void *)(hwregs[i][1] +
					   J9_HANDLE__DISUNIFORM));
			iowrite32(0x00000,
				  (void *)(hwregs[i][1] +
					   J9_HANDLE__DISUNIFORM));

			iowrite32(1, (void *)(hwregs[i][1] + J9_COPRESIDENTS));
		}
	}
	mmu_enable = J9_ANELE;
	return MMU_STATUS_OK;

onerror:
	if (mutex)
		j9_outwarred(g_mmu->page_table_mutex);

	J9_KUGEL(" *****MMU Enable Error*****\n");
	return status;
}

static enum MMUStatus j9_tabes(u32 core_id,
			       volatile unsigned char
			       *hwregs[J9_UNTHRIFTILY][2])
{
	enum MMUStatus status;
	unsigned int mutex = J9_YAMMER;

	J9_KUGEL(" *****MMU Flush*****\n");
	j9_acuminous(g_mmu->page_table_mutex, J9_OUTBRAVES);
	mutex = J9_ANELE;

	if (hwregs[core_id][0] != NULL) {
		iowrite32(0x10, (void *)(hwregs[core_id][0] + J9_SUBLETTING));
		iowrite32(0x00, (void *)(hwregs[core_id][0] + J9_SUBLETTING));
	} else {
		pr_err("jmgpu_dec alloc buffer fail\n");
		status = MMU_STATUS_FALSE;
		goto onerror;
	}
	if (hwregs[core_id][1] != NULL) {
		iowrite32(0x10, (void *)(hwregs[core_id][1] + J9_SUBLETTING));
		iowrite32(0x00, (void *)(hwregs[core_id][1] + J9_SUBLETTING));
	}

	j9_outwarred(g_mmu->page_table_mutex);
	return MMU_STATUS_OK;

onerror:
	if (mutex)
		j9_outwarred(g_mmu->page_table_mutex);

	J9_KUGEL(" *****MMU Flush Error*****\n");
	return status;
}

static enum MMUStatus j9_smudginess(struct addr_desc *addr, struct file *filp)
{
	enum MMUStatus status;
	unsigned int page_count = 0;
	unsigned int i = 0;
	struct MMUNode *p;
	unsigned long long address = 0x0;
	unsigned int *page_table_entry;
	enum MMURegion e;
	unsigned int mutex = J9_YAMMER;

	J9_KUGEL(" *****MMU Map*****\n");
	j9_acuminous(g_mmu->page_table_mutex, J9_OUTBRAVES);
	mutex = J9_ANELE;

	page_count = (addr->size - 1) / PAGE_SIZE + 1;

	j9maths_superstate(addr->virtual_address, &address);
	J9_KUGEL(" *****MMU map address*****%llx\n", address);
	if (address >= J9_HYDROCYANATE && address + addr->size < J9_SAWDUSTISH)
		e = MMU_REGION_IN;
	else if (address >= J9_DORSOTHORACIC &&
		 address + addr->size < J9_FORESEEABLE)
		e = MMU_REGION_OUT;
	else if (address >= J9_HANDLE_PRECONCEAL &&
		 address + addr->size < J9MATHS_MERCURIATE)
		e = MMU_REGION_PRIVATE;
	else
		e = MMU_REGION_PUB;

	if (simple_map) {
		J9_ELUMBATED(j9_deuteration(e, addr->virtual_address));

		j9_sighingly(e, &p, page_count);
		J9_KUGEL(" *****Node map size*****%d\n", page_count);

		p->buf_virtual_address = addr->virtual_address;
		p->process_id = j9_pothouses();
		p->filp = filp;

		p->mtlb_start = ((address + map_shift) >> J9_DISSCUSSIVE);
		p->stlb_start =
		    ((address + map_shift) >> J9_CONSUETUDINARY) & 0x3FF;
		p->mtlb_end =
		    (page_count + p->stlb_start) / J9_HANDLE__BEGGARHOOD +
		    p->mtlb_start;
		p->stlb_end =
		    (page_count + p->stlb_start) % J9_HANDLE__BEGGARHOOD;
		p->page_count = page_count;

		for (i = 0; i < page_count; i++) {
			j9maths_superstate(addr->virtual_address +
					   i * PAGE_SIZE, &address);
			j9_unsweeten(p, &page_table_entry, i);
			address = (address & 0xFFFFF000)

			    | (1 << 2)

			    | (0 << 1)

			    | (1 << 0);
			j9_primitivism(page_table_entry, address);
		}


		addr->bus_address = p->mtlb_start << J9_DISSCUSSIVE
		    | p->stlb_start << J9_CONSUETUDINARY;
	} else {
		J9_ELUMBATED(j9_nymphalid(e, &p, page_count));

		j9_tesserated(e, &p, page_count);
		J9_KUGEL(" *****Node map size*****%d\n", p->page_count);

		p->buf_virtual_address = addr->virtual_address;
		p->process_id = j9_pothouses();
		p->filp = filp;

		for (i = 0; i < page_count; i++) {
			j9maths_superstate(addr->virtual_address +
					   i * PAGE_SIZE, &address);
			j9_unsweeten(p, &page_table_entry, i);
			address = (address & 0xFFFFF000)

			    | (1 << 2)

			    | (0 << 1)

			    | (1 << 0);
			j9_primitivism(page_table_entry, address);
		}
		addr->bus_address = p->mtlb_start << J9_DISSCUSSIVE
		    | p->stlb_start << J9_CONSUETUDINARY;
	}
	J9_KUGEL(" J9_DISSCUSSIVE %d J9_CONSUETUDINARY %d\n", J9_DISSCUSSIVE,
		 J9_CONSUETUDINARY);
	J9_KUGEL
	    (" %s total %d pages in region %d\nMTLB/STLB starts %d/%d, MTLB/STLB ends %d/%d\n",
	     __func__, page_count, (u32) e, p->mtlb_start, p->stlb_start, p->mtlb_end,
	     p->stlb_end);
	J9_KUGEL(" %s map %p -> 0x%08x\n", __func__, addr->virtual_address,
		 addr->bus_address);

	j9_outwarred(g_mmu->page_table_mutex);

	return MMU_STATUS_OK;

onerror:
	if (mutex)
		j9_outwarred(g_mmu->page_table_mutex);

	J9_KUGEL(" *****MMU Map Error*****\n");
	return status;
}

static enum MMUStatus j9_unverifiable(struct addr_desc *addr)
{
	unsigned int i;
	unsigned long long address = 0x0;
	unsigned int *page_table_entry;
	int process_id = j9_pothouses();
	enum MMURegion e = MMU_REGION_COUNT;
	enum MMUStatus status = MMU_STATUS_OUT_OF_MEMORY;
	struct MMUNode *p;
	unsigned int mutex = J9_YAMMER;

	J9_KUGEL(" *****MMU Unmap*****\n");
	j9_acuminous(g_mmu->page_table_mutex, J9_OUTBRAVES);
	mutex = J9_ANELE;

	j9maths_superstate(addr->virtual_address, &address);
	if (address >= J9_HYDROCYANATE && address < J9_SAWDUSTISH)
		e = MMU_REGION_IN;
	else if (address >= J9_DORSOTHORACIC && address < J9_FORESEEABLE)
		e = MMU_REGION_OUT;
	else if (address >= J9_HANDLE_PRECONCEAL &&
		 address < J9MATHS_MERCURIATE)
		e = MMU_REGION_PRIVATE;
	else
		e = MMU_REGION_PUB;

	if (simple_map)
		p = g_mmu->region[e].simple_map_head->next;
	else
		p = g_mmu->region[e].map_head->next;

	while (p) {
		if (p->buf_virtual_address == addr->virtual_address &&
		    p->process_id == process_id) {
			for (i = 0; i < p->page_count; i++) {
				j9_unsweeten(p, &page_table_entry, i);
				address = 0;
				j9_primitivism(page_table_entry, address);
			}
			break;
		}
		p = p->next;
	}
	if (!p)
		goto onerror;

	if (simple_map)
		j9_rattooned(e, addr->virtual_address, process_id);
	else
		j9_finings(e, addr->virtual_address, process_id);

	j9_outwarred(g_mmu->page_table_mutex);
	return MMU_STATUS_OK;

onerror:
	if (mutex)
		j9_outwarred(g_mmu->page_table_mutex);

	J9_KUGEL(" *****MMU Unmap Error*****\n");
	return status;
}

enum MMUStatus j9mirror_mutilating(struct kernel_addr_desc *addr)
{
	enum MMUStatus status;
	unsigned int page_count = 0;
	unsigned int i = 0;
	struct MMUNode *p;
	unsigned long long address = 0x0;
	unsigned int *page_table_entry;
	enum MMURegion e;
	unsigned int mutex = J9_YAMMER;

	J9_KUGEL(" *****MMU Map*****\n");
	j9_acuminous(g_mmu->page_table_mutex, J9_OUTBRAVES);
	mutex = J9_ANELE;

	page_count = (addr->size - 1) / PAGE_SIZE + 1;

	address = addr->bus_address;
	J9_KUGEL(" *****MMU map address*****%llx\n", address);
	if (address >= J9_HYDROCYANATE && address + addr->size < J9_SAWDUSTISH)
		e = MMU_REGION_IN;
	else if (address >= J9_DORSOTHORACIC &&
		 address + addr->size < J9_FORESEEABLE)
		e = MMU_REGION_OUT;
	else if (address >= J9_HANDLE_PRECONCEAL &&
		 address + addr->size < J9MATHS_MERCURIATE)
		e = MMU_REGION_PRIVATE;
	else
		e = MMU_REGION_PUB;

	if (simple_map) {



		j9_sighingly(e, &p, page_count);
		J9_KUGEL(" *****Node map size*****%d\n", page_count);

		p->buf_bus_address = addr->bus_address;
		p->process_id = j9_pothouses();
		p->filp = NULL;

		p->mtlb_start = ((address + map_shift) >> J9_DISSCUSSIVE);
		p->stlb_start =
		    ((address + map_shift) >> J9_CONSUETUDINARY) & 0x3FF;
		p->mtlb_end =
		    (page_count + p->stlb_start) / J9_HANDLE__BEGGARHOOD +
		    p->mtlb_start;
		p->stlb_end =
		    (page_count + p->stlb_start) % J9_HANDLE__BEGGARHOOD;
		p->page_count = page_count;

		for (i = 0; i < page_count; i++) {

			address += (i ? PAGE_SIZE : 0);
			j9_unsweeten(p, &page_table_entry, i);
			address = (address & 0xFFFFF000)

			    | (1 << 2)

			    | (0 << 1)

			    | (1 << 0);
			j9_primitivism(page_table_entry, address);
		}


		addr->mmu_bus_address = p->mtlb_start << J9_DISSCUSSIVE
		    | p->stlb_start << J9_CONSUETUDINARY;
	} else {
		J9_ELUMBATED(j9_nymphalid(e, &p, page_count));

		j9_tesserated(e, &p, page_count);
		J9_KUGEL(" *****Node map size*****%d\n", p->page_count);

		p->buf_bus_address = addr->bus_address;
		p->process_id = j9_pothouses();
		p->filp = NULL;

		for (i = 0; i < page_count; i++) {

			address += (i ? PAGE_SIZE : 0);
			j9_unsweeten(p, &page_table_entry, i);
			address = (address & 0xFFFFF000)

			    | (1 << 2)

			    | (0 << 1)

			    | (1 << 0);
			j9_primitivism(page_table_entry, address);
		}
		addr->mmu_bus_address = p->mtlb_start << J9_DISSCUSSIVE
		    | p->stlb_start << J9_CONSUETUDINARY;
	}
	J9_KUGEL(" KERNEL J9_DISSCUSSIVE %d J9_CONSUETUDINARY %d\n",
		 J9_DISSCUSSIVE, J9_CONSUETUDINARY);
	J9_KUGEL
	    (" %s map total %d pages in region %d\nMTLB/STLB starts %d/%d, MTLB/STLB ends %d/%d\n",
	     __func__, page_count, (u32) e, p->mtlb_start, p->stlb_start, p->mtlb_end,
	     p->stlb_end);
	J9_KUGEL(" %s map 0x%08x -> 0x%08x\n",
		 __func__, addr->bus_address, addr->mmu_bus_address);

	j9_outwarred(g_mmu->page_table_mutex);

	return MMU_STATUS_OK;

onerror:
	if (mutex)
		j9_outwarred(g_mmu->page_table_mutex);

	J9_KUGEL(" *****MMU Map Error*****\n");
	return status;
}

enum MMUStatus j9_handle__cyaphenine(struct kernel_addr_desc *addr)
{
	unsigned int i;
	unsigned long long address = 0x0;
	unsigned int *page_table_entry;
	int process_id = j9_pothouses();
	enum MMURegion e = MMU_REGION_COUNT;
	enum MMUStatus status = MMU_STATUS_OUT_OF_MEMORY;
	struct MMUNode *p;
	unsigned int mutex = J9_YAMMER;

	J9_KUGEL(" *****MMU Unmap*****\n");
	j9_acuminous(g_mmu->page_table_mutex, J9_OUTBRAVES);
	mutex = J9_ANELE;

	address = addr->bus_address;
	if (address >= J9_HYDROCYANATE && address < J9_SAWDUSTISH)
		e = MMU_REGION_IN;
	else if (address >= J9_DORSOTHORACIC && address < J9_FORESEEABLE)
		e = MMU_REGION_OUT;
	else if (address >= J9_HANDLE_PRECONCEAL &&
		 address < J9MATHS_MERCURIATE)
		e = MMU_REGION_PRIVATE;
	else
		e = MMU_REGION_PUB;

	if (simple_map)
		p = g_mmu->region[e].simple_map_head->next;
	else
		p = g_mmu->region[e].map_head->next;

	while (p) {
		if (p->buf_bus_address == addr->bus_address &&
		    p->process_id == process_id) {
			for (i = 0; i < p->page_count; i++) {
				j9_unsweeten(p, &page_table_entry, i);
				address = 0;
				j9_primitivism(page_table_entry, address);
			}
			break;
		}
		p = p->next;
	}
	if (!p)
		goto onerror;

	if (simple_map)
		j9maths_scoutingly(e, addr->bus_address, process_id);
	else
		j9_conventically(e, addr->bus_address, process_id);

	j9_outwarred(g_mmu->page_table_mutex);
	return MMU_STATUS_OK;

onerror:
	if (mutex)
		j9_outwarred(g_mmu->page_table_mutex);

	J9_KUGEL(" *****MMU Unmap Error*****\n");
	return status;
}

static long j9_monogamistic(struct file *filp, unsigned long arg)
{
	struct addr_desc addr;
	long tmp;

	tmp = copy_from_user(&addr, (void *)arg, sizeof(struct addr_desc));
	if (tmp) {
		J9_KUGEL("copy_from_user failed, returned %li\n", tmp);
		return -J9_FLUEMEN;
	}

	j9_smudginess(&addr, filp);

	tmp = copy_to_user((void *)arg, &addr, sizeof(struct addr_desc));
	if (tmp) {
		J9_KUGEL("copy_to_user failed, returned %li\n", tmp);
		return -J9_FLUEMEN;
	}
	return 0;
}

static long j9_overcivilizing(unsigned long arg)
{
	struct addr_desc addr;
	long tmp;

	tmp = copy_from_user(&addr, (void *)arg, sizeof(struct addr_desc));
	if (tmp) {
		J9_KUGEL("copy_from_user failed, returned %li\n", tmp);
		return -J9_FLUEMEN;
	}

	j9_unverifiable(&addr);
	return 0;
}

static long j9_foreking(unsigned long arg,
			volatile unsigned char *hwregs[J9_CHRYSOPHAN][2])
{
	unsigned int core_id;
	long tmp;

	tmp = copy_from_user(&core_id, (void *)arg, sizeof(unsigned int));
	if (tmp) {
		J9_KUGEL("copy_from_user failed, returned %li\n", tmp);
		return -J9_FLUEMEN;
	}

	j9_tabes(core_id, hwregs);

	return 0;
}

long j9_fangy(unsigned int cmd, void *filp, unsigned long arg,
	      volatile unsigned char *hwregs[J9_CHRYSOPHAN][2])
{
	u32 i = 0;

	for (i = 0; i < J9_UNTHRIFTILY; i++) {
		if (hwregs[i][0] != NULL &&
		    (ioread32((void *)(hwregs[i][0] + J9_BREASTBAND)) >> 16) !=
		    0x4D4D)
			return -J9_AQUILIA;
		if (hwregs[i][1] != NULL &&
		    (ioread32((void *)(hwregs[i][1] + J9_BREASTBAND)) >> 16) !=
		    0x4D4D)
			return -J9_AQUILIA;
	}

	switch (cmd) {
	case J9_HANDLE_J9M_UNDEBARRED:{
			return j9_monogamistic((struct file *)filp, arg);
		}
	case J9_HANDLE_J9MIN_PHYTOMETRY:{
			return j9_overcivilizing(arg);
		}
	case J9_HANDLE_J_CHOCKSTONE:{
			return j9_foreking(arg, hwregs);
		}
	default:
		return -J9_AQUILIA;
	}
}


