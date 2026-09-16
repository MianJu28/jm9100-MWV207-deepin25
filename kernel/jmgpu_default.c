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




#include <linux/atomic.h>
#include <linux/kref.h>
#include <linux/vmalloc.h>
#include <drm/drm_vma_manager.h>
#include "jmgpu_evaluate.h"


static struct slice_info *slicehdr;
static atomic_t sliceinitd;
static atomic_t slicenum;

int findslice_bydev(struct device *dev)
{
	int i = 0;
	struct slice_info *hdr = slicehdr;

	if (atomic_read(&sliceinitd) == 0)
		return -1;

	while (hdr) {
		if (hdr->dev == dev)
			return i;
		i++;
		hdr = hdr->next;
	}
	return -1;
}


struct slice_info *getslicenode_ininit(u32 sliceindex)
{
	int i = 0;
	struct slice_info *hdr = slicehdr;

	if (sliceindex >= atomic_read(&slicenum))
		return NULL;
	for (i = 0; i < sliceindex; i++)
		hdr = hdr->next;

	return hdr;
}

struct slice_info *getslicenode(u32 sliceindex)
{
	return getslicenode_ininit(sliceindex);
}

int get_slicecorenum(u32 sliceindex, slice_coretype type)
{
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return 0;

	switch (type) {
	case JMD_HD_CORE_ENC:
		return hdr->enccore_num;
	case JMD_HD_CORE_DEC:
		return hdr->deccore_num;
	case JMD_HD_CORE_CACHE:
		return hdr->cachecore_num;
	case JMD_HD_CORE_D400:
		return hdr->dec400core_num;
	case JMD_HD_CORE_MMU:
		return hdr->mmucore_num;
	case JMD_HD_CORE_VCMD:
		return hdr->vcmdcore_num;
	default:
		return 0;
	}
}


struct j9_lamori *get_decnodes(u32 sliceindex, u32 nodeidx)
{
	int i;
	struct j9_lamori *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;

	p = hdr->dechdr;
	for (i = 0; i < nodeidx; i++) {
		if (!p)
			break;
		p = p->next;
	}
	return p;
}

struct mmu_t *get_mmunode(u32 sliceindex, u32 nodeidx)
{
	int i;
	struct mmu_t *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;
	p = hdr->mmuhdr;
	for (i = 0; i < nodeidx; i++) {
		if (!p)
			break;
		p = p->next;
	}
	return p;
}

struct mmu_t *get_mmunodebytype(u32 sliceindex, u32 nodetype)
{
	struct mmu_t *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;
	p = hdr->mmuhdr;
	while (p) {
		if (p->core_cfg.parenttype & nodetype)
			break;
		p = p->next;
	}
	return p;
}

struct j9_lamori *getfirst_decnodes(struct slice_info *pslice)
{
	if (atomic_read(&slicenum))
		return pslice->dechdr;
	return NULL;
}


struct j9_aarrgh *get_encnodes(u32 sliceindex, u32 nodeidx)
{
	int i;
	struct j9_aarrgh *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;
	p = hdr->enchdr;
	for (i = 0; i < nodeidx; i++) {
		if (!p)
			break;
		p = p->next;
	}
	return p;
}


struct cache_dev_t *get_cachenodes(u32 sliceindex, u32 nodeidx)
{
	int i;
	struct cache_dev_t *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;
	p = hdr->cachehdr;
	for (i = 0; i < nodeidx; i++) {
		if (!p)
			break;
		p = p->next;
	}
	return p;
}

struct cache_dev_t *get_cachenodebytype(u32 sliceindex, u32 parenttype,
					u32 parentnodeidx)
{
	struct cache_dev_t *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;
	p = hdr->cachehdr;
	while (p) {
		if (p->parentid == parentnodeidx &&
		    ((parenttype == J9_CUSTOMIZED &&
		      p->parenttype == JMD_HD_CORE_DEC) ||
		     (parenttype == J9_HARLOTRIES &&
		      p->parenttype == JMD_HD_CORE_ENC)))
			break;
		p = p->next;
	}
	return p;
}


struct dec400_t *get_dec400nodes(u32 sliceindex, u32 nodeidx)
{
	int i;
	struct dec400_t *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;
	p = hdr->dec400hdr;
	for (i = 0; i < nodeidx; i++) {
		if (!p)
			break;
		p = p->next;
	}
	return p;
}


struct dec400_t *get_dec400nodebytype(u32 sliceindex, u32 parenttype,
				      u32 parentnodeidx)
{
	struct dec400_t *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;
	p = hdr->dec400hdr;
	while (p) {
		if (p->parentid == parentnodeidx &&
		    ((parenttype == J9_CUSTOMIZED &&
		      p->parenttype == JMD_HD_CORE_DEC) ||
		     (parenttype == J9_HARLOTRIES &&
		      p->parenttype == JMD_HD_CORE_ENC)))
			break;
		p = p->next;
	}
	return p;
}



struct axife_t *get_axifenodes(u32 sliceindex, u32 nodeidx)
{
	int i;
	struct axife_t *p;
	struct slice_info *hdr = getslicenode(sliceindex);

	if (!hdr)
		return NULL;
	p = hdr->axifehdr;
	for (i = 0; i < nodeidx; i++) {
		if (!p)
			break;
		p = p->next;
	}
	return p;
}


struct axife_t *get_axifenodebytype(u32 sliceindex, u32 parenttype,
				  u32 parentnodeidx)
{
struct axife_t *p;
struct slice_info *hdr = getslicenode(sliceindex);

if (!hdr)
	return NULL;
p = hdr->axifehdr;
while (p) {
	if (p->parentid == parentnodeidx &&
		  ((parenttype == J9_CUSTOMIZED &&
			p->parenttype == JMD_HD_CORE_DEC) ||
		   (parenttype == J9_HARLOTRIES &&
			p->parenttype == JMD_HD_CORE_ENC)))
		break;
	p = p->next;
}
return p;
}



int add_decnode(u32 sliceindex, struct j9_lamori *deccore)
{
	struct j9_lamori *pdec;
	struct slice_info *splice = getslicenode_ininit(sliceindex);

#ifdef USE_DTB_PROBE
	if (!splice)
		return -EINVAL;
#else
	if (!splice && sliceindex == atomic_read(&slicenum)) {
		sliceindex = addslice(NULL, 0, 0);
		if (sliceindex < 0)
			return -EINVAL;
		splice = getslicenode_ininit(sliceindex);
	}
	if (!splice)
		return -EINVAL;
#endif

	pdec = splice->dechdr;
	if (!pdec) {
		splice->dechdr = deccore;
	} else {
		while (pdec->next)
			pdec = pdec->next;
		pdec->next = deccore;
	}
	deccore->next = NULL;
	splice->deccore_num++;
	deccore->core_id = splice->deccore_num - 1;
	deccore->sliceidx = sliceindex;
	deccore->parentslice = splice;
	splice->config |= J9_FASCICULI;

	sema_init(&splice->dec_core_sem, splice->deccore_num);
	return 0;
}

int add_encnode(u32 sliceindex, struct j9_aarrgh *enccore)
{
	struct j9_aarrgh *penc;
	struct slice_info *splice = getslicenode_ininit(sliceindex);

#ifdef USE_DTB_PROBE
	if (!splice)
		return -EINVAL;
#else
	if (!splice && sliceindex == atomic_read(&slicenum)) {
		sliceindex = addslice(NULL, 0, 0);
		if (sliceindex < 0)
			return -EINVAL;
		splice = getslicenode_ininit(sliceindex);
	}
#endif

	penc = splice->enchdr;
	if (!penc) {
		splice->enchdr = enccore;
	} else {
		while (penc->next)
			penc = penc->next;
		penc->next = enccore;
	}
	enccore->next = NULL;
	splice->enccore_num++;
	enccore->core_id = splice->enccore_num - 1;
	enccore->core_cfg.sliceidx = sliceindex;
	enccore->parentslice = splice;
	splice->config |= J9_EUCAIRITE;
	return 0;
}

int add_dec400node(u32 sliceindex, struct dec400_t *dec400core)
{
	struct dec400_t *pdec400;
	struct j9_lamori *pdec;
	struct j9_aarrgh *penc;
	struct slice_info *splice = getslicenode_ininit(sliceindex);

	if (!splice)
		return -EINVAL;

	pdec400 = splice->dec400hdr;
	if (!pdec400) {
		splice->dec400hdr = dec400core;
	} else {
		while (pdec400->next)
			pdec400 = pdec400->next;
		pdec400->next = dec400core;
	}
	dec400core->next = NULL;
	splice->dec400core_num++;
	dec400core->core_id = splice->dec400core_num - 1;
	splice->config |= J9_PEACHING;
	dec400core->core_cfg.sliceidx = sliceindex;


	dec400core->parentcore = splice;
	dec400core->parentid = sliceindex;
	dec400core->parenttype = JMD_HD_CORE_SLICE;
	dec400core->parentslice = splice;

	if (dec400core->core_cfg.parentaddr == splice->rsvmem_addr) {
		dec400core->parentcore = splice;
		dec400core->parenttype = JMD_HD_CORE_SLICE;
		goto end;
	}
	penc = splice->enchdr;
	while (penc) {
		if ((unsigned long long)penc->core_cfg.base_addr ==
		    dec400core->core_cfg.parentaddr) {
			dec400core->parentcore = penc;
			dec400core->parentid = penc->core_id;
			dec400core->parenttype = JMD_HD_CORE_ENC;
			goto end;
		}
		penc = penc->next;
	}
	pdec = splice->dechdr;
	while (pdec) {
		if ((unsigned long long)pdec->multicorebase ==
		    dec400core->core_cfg.parentaddr) {
			dec400core->parentcore = pdec;
			dec400core->parentid = pdec->core_id;
			dec400core->parenttype = JMD_HD_CORE_DEC;
			goto end;
		}
		pdec = pdec->next;
	}
end:
	return 0;
}

int add_axifenode(u32 sliceindex, struct axife_t *axifecore)
{
	struct axife_t *paxife;
	struct j9_lamori *pdec;
	struct j9_aarrgh *penc;
	struct slice_info *splice = getslicenode_ininit(sliceindex);
	int core_etype = CORE_AXIFE;
	unsigned long total_iosize;

	if (!splice)
		return -EINVAL;

	paxife = splice->axifehdr;
	if (!paxife) {
		splice->axifehdr = axifecore;
	} else {
		while (paxife->next)
			paxife = paxife->next;
		paxife->next = axifecore;
	}
	axifecore->next = NULL;
	splice->axifecore_num++;
	axifecore->core_id = splice->axifecore_num - 1;
	splice->config |= J9_ELEVENSES;
	axifecore->core_cfg.sliceidx = sliceindex;


	axifecore->parentcore = splice;
	axifecore->parentid = sliceindex;
	axifecore->parenttype = JMD_HD_CORE_SLICE;
	axifecore->parentslice = splice;

	if (axifecore->core_cfg.parentaddr == splice->rsvmem_addr) {
		axifecore->parentcore = splice;
		axifecore->parenttype = JMD_HD_CORE_SLICE;
		goto end;
	}
	penc = splice->enchdr;
	while (penc) {
		if ((unsigned long long)penc->core_cfg.base_addr ==
		    axifecore->core_cfg.parentaddr) {
			axifecore->parentcore = penc;
			axifecore->parentid = penc->core_id;
			axifecore->parenttype = JMD_HD_CORE_ENC;

			if (penc->core_info.offset[CORE_AXIFE])
				core_etype = CORE_AXIFE_1;
			penc->core_info.type_info |= core_etype;
			penc->core_info.offset[core_etype] = axifecore->core_cfg.axifecorebase - axifecore->core_cfg.parentaddr;
			penc->core_info.regSize[core_etype] = axifecore->core_cfg.iosize;

			total_iosize = penc->core_info.offset[core_etype] + axifecore->core_cfg.iosize;
			if (total_iosize > penc->core_cfg.iosize)
				penc->core_cfg.iosize = total_iosize;
			pr_info("%s,%d,axifecorebase %llx,parentaddr %llx,parent io size %x\n", __func__, __LINE__,
				axifecore->core_cfg.axifecorebase, axifecore->core_cfg.parentaddr, penc->core_cfg.iosize);

			goto end;
		}
		penc = penc->next;
	}
	pdec = splice->dechdr;
	while (pdec) {
		if ((unsigned long long)pdec->multicorebase ==
		    axifecore->core_cfg.parentaddr) {
			axifecore->parentcore = pdec;
			axifecore->parentid = pdec->core_id;
			axifecore->parenttype = JMD_HD_CORE_DEC;
			goto end;
		}
		pdec = pdec->next;
	}
end:
	return 0;
}

int add_cachenode(u32 sliceindex, struct cache_dev_t *cachecore)
{
	struct cache_dev_t *pcache;
	struct j9_lamori *pdec;
	struct j9_aarrgh *penc;
	struct slice_info *splice = getslicenode_ininit(sliceindex);

	if (!splice)
		return -ENODEV;

	pcache = splice->cachehdr;
	if (!pcache) {
		splice->cachehdr = cachecore;
	} else {
		while (pcache->next)
			pcache = pcache->next;
		pcache->next = cachecore;
	}
	cachecore->next = NULL;
	splice->cachecore_num++;
	cachecore->core_id = splice->cachecore_num - 1;
	cachecore->core_cfg.sliceidx = sliceindex;
	splice->config |= J9_NONDECISIVE;


	cachecore->parentcore = splice;
	cachecore->parentid = sliceindex;
	cachecore->parenttype = JMD_HD_CORE_SLICE;
	cachecore->parentslice = splice;

	if (cachecore->core_cfg.client == ENC) {
		penc = splice->enchdr;
		while (penc) {
			if ((unsigned long long)penc->core_cfg.base_addr ==
			    cachecore->core_cfg.parentaddr) {
				cachecore->parentcore = penc;
				cachecore->parentid = penc->core_id;
				cachecore->parenttype = JMD_HD_CORE_ENC;
				break;
			}
			penc = penc->next;
		}
	} else {
		pdec = splice->dechdr;
		while (pdec) {
			if ((unsigned long long)pdec->multicorebase ==
			    cachecore->core_cfg.parentaddr) {
				cachecore->parentcore = pdec;
				cachecore->parentid = pdec->core_id;
				cachecore->parenttype = JMD_HD_CORE_DEC;
				break;
			}
			pdec = pdec->next;
		}
	}
	return 0;
}

int add_mmunode(u32 sliceindex, struct mmu_t *mmucore)
{
	struct mmu_t *pmmu;
	struct slice_info *splice = getslicenode_ininit(sliceindex);

	if (!splice)
		return -ENODEV;

	pmmu = splice->mmuhdr;
	if (!pmmu) {
		splice->mmuhdr = mmucore;
	} else {
		while (pmmu->next)
			pmmu = pmmu->next;
		pmmu->next = mmucore;
	}
	mmucore->next = NULL;
	splice->mmucore_num++;
	mmucore->core_id = splice->mmucore_num - 1;
	mmucore->core_cfg.sliceidx = sliceindex;
	splice->config |= J9_REDODOING;
	mmucore->parentslice = splice;

	return 0;
}

int add_vcmdnode(u32 sliceindex, struct jmgpu_vcmd_t *vcmdcore)
{
	struct jmgpu_vcmd_t *pvcmd;
	struct j9_lamori *pdec;
	struct j9_aarrgh *penc;
	struct slice_info *splice = getslicenode_ininit(sliceindex);

	if (!splice)
		return -EINVAL;

	pvcmd = splice->vcmdhdr;
	if (!pvcmd) {
		splice->vcmdhdr = vcmdcore;
	} else {
		while (pvcmd->next)
			pvcmd = pvcmd->next;
		pvcmd->next = vcmdcore;
	}
	vcmdcore->next = NULL;
	splice->vcmdcore_num++;
	vcmdcore->core_id = splice->vcmdcore_num - 1;
	splice->config |= J9_DEMONESS;


	vcmdcore->parentcore = splice;
	vcmdcore->sliceidx = sliceindex;
	vcmdcore->parentid = sliceindex;
	vcmdcore->parenttype = JMD_HD_CORE_SLICE;
	vcmdcore->parentslice = splice;

	penc = splice->enchdr;
	while (penc) {
		if ((unsigned long long)penc->core_cfg.base_addr ==
		    vcmdcore->parentaddr) {
			vcmdcore->parentcore = penc;
			vcmdcore->parentid = penc->core_id;
			vcmdcore->parenttype = JMD_HD_CORE_ENC;
			goto end;
		}
		penc = penc->next;
	}
	pdec = splice->dechdr;
	while (pdec) {
		if ((unsigned long long)pdec->multicorebase ==
		    vcmdcore->parentaddr) {
			vcmdcore->parentcore = pdec;
			vcmdcore->parentid = pdec->core_id;
			vcmdcore->parenttype = JMD_HD_CORE_DEC;
			goto end;
		}
		pdec = pdec->next;
	}
end:
	return 0;
}

int get_slicenumber(void)
{
	return atomic_read(&slicenum);
}

struct slice_info *getparentslice(void *node, int type)
{
	struct slice_info *pslice = NULL;
	void *parentslice;

	switch (type) {
	case JMD_HD_CORE_CACHE:
		pslice = (struct slice_info *)((struct cache_dev_t *)node)
				 ->parentslice;
		;
		break;
	case JMD_HD_CORE_DEC:
		pslice = (struct slice_info *)((struct j9_lamori *)node)
				 ->parentslice;
		break;
	case JMD_HD_CORE_ENC:
		pslice = (struct slice_info *)((struct j9_aarrgh *)node)
				 ->parentslice;
		break;
	case JMD_HD_CORE_D400:
		pslice = (struct slice_info *)((struct dec400_t *)node)
				 ->parentslice;
		break;
	case JMD_HD_CORE_MMU:
		parentslice = ((struct mmu_t *)node)->parentslice;
		pslice = (struct slice_info *)parentslice;
		break;
	case JMD_HD_CORE_VCMD:
		pslice = (struct slice_info *)((struct jmgpu_vcmd_t *)node)
				 ->parentslice;
		break;
	default:
		break;
	}
	return pslice;
}


int slice_remove(void)
{
	struct slice_info *post, *prev;

	prev = slicehdr;
	post = slicehdr;
	while (prev) {
		post = prev->next;
		kfree(prev);
		prev = post;
	}
	atomic_set(&slicenum, 0);
	atomic_set(&sliceinitd, 0);
	slicehdr = NULL;
	return 0;
}

int addslice(struct device *dev, phys_addr_t sliceaddr, phys_addr_t slicesize)
{
	struct slice_info *pslice =
		kzalloc(sizeof(struct slice_info), GFP_KERNEL);

	if (!pslice)
		return -ENOMEM;

	pslice->dev = dev;
	pslice->rsvmem_addr = sliceaddr;
	pslice->memsize = slicesize;
	pslice->config = 0;
	pslice->next = NULL;
	pslice->deccore_num = 0;
	pslice->enccore_num = 0;
	pslice->cachecore_num = 0;
	pslice->dec400core_num = 0;
	pslice->mmucore_num = 0;
	pslice->dechdr = NULL;
	pslice->enchdr = NULL;
	pslice->cachehdr = NULL;
	pslice->dec400hdr = NULL;
	pslice->mmuhdr = NULL;

	init_waitqueue_head(&pslice->cache_hw_queue);
	init_waitqueue_head(&pslice->cache_wait_queue);
	spin_lock_init(&pslice->cache_owner_lock);

	sema_init(&pslice->enc_core_sem, 1);
	init_waitqueue_head(&pslice->enc_hw_queue);
	spin_lock_init(&pslice->enc_owner_lock);
	init_waitqueue_head(&pslice->enc_wait_queue);

	pslice->dec_irq = 0;
	pslice->pp_irq = 0;
	spin_lock_init(&pslice->owner_lock);
	init_waitqueue_head(&pslice->dec_wait_queue);
	init_waitqueue_head(&pslice->pp_wait_queue);
	init_waitqueue_head(&pslice->hw_queue);
	sema_init(&pslice->pp_core_sem, 1);

	if (!slicehdr) {
		slicehdr = pslice;
	} else {
		struct slice_info *head = slicehdr;

		while (head->next)
			head = head->next;
		head->next = pslice;
	}
	atomic_inc(&slicenum);
	return atomic_read(&slicenum) - 1;
}

static void j9_capillaries(struct j9_lamori *decnode)
{
	int update = 0;
	struct slice_info *splice = getslicenode_ininit(decnode->sliceidx);
	struct j9_lamori *pdecnode, *pn;

	if (!splice)
		return;

	pdecnode = splice->dechdr;
	if (pdecnode == decnode) {
		splice->dechdr = decnode->next;
		pdecnode = splice->dechdr;
		vfree(decnode);
		splice->deccore_num--;
		update = 1;
	} else {
		while (pdecnode) {
			pn = pdecnode->next;
			if (pn == decnode) {
				pdecnode->next = pn->next;
				pdecnode = pn->next;
				vfree(decnode);
				splice->deccore_num--;
				update = 1;
				break;
			}
			pdecnode = pdecnode->next;
		}
	}
	if (update) {
		if (splice->deccore_num == 0) {
			splice->config &= ~J9_FASCICULI;
		} else {
			while (pdecnode) {
				pdecnode->core_id--;
				pdecnode = pdecnode->next;
			}
		}
	}
}

static void j9_lycoperdoid(struct j9_aarrgh *encnode)
{
	int update = 0;
	struct slice_info *splice =
		getslicenode_ininit(encnode->core_cfg.sliceidx);
	struct j9_aarrgh *pencnode, *pn;

	if (!splice)
		return;

	pencnode = splice->enchdr;
	if (pencnode == encnode) {
		splice->enchdr = encnode->next;
		pencnode = splice->enchdr;
		vfree(encnode);
		splice->enccore_num--;
		update = 1;
	} else {
		while (pencnode) {
			pn = pencnode->next;
			if (pn == encnode) {
				pencnode->next = pn->next;
				pencnode = pn->next;
				vfree(encnode);
				splice->enccore_num--;
				update = 1;
				break;
			}
			pencnode = pencnode->next;
		}
	}
	if (update) {
		if (splice->enccore_num == 0) {
			splice->config &= ~J9_EUCAIRITE;
		} else {
			while (pencnode) {
				pencnode->core_id--;
				pencnode = pencnode->next;
			}
		}
	}
}

static void j9_acceptingness(struct cache_dev_t *cachenode)
{
	int update = 0;
	struct slice_info *splice =
		getslicenode_ininit(cachenode->core_cfg.sliceidx);
	struct cache_dev_t *pcache, *pn;

	if (!splice)
		return;

	pcache = splice->cachehdr;
	if (pcache == cachenode) {
		splice->cachehdr = cachenode->next;
		pcache = splice->cachehdr;
		vfree(cachenode);
		splice->cachecore_num--;
		update = 1;
	} else {
		while (pcache) {
			pn = pcache->next;
			if (pn == cachenode) {
				pcache->next = pn->next;
				pcache = pn->next;
				vfree(cachenode);
				splice->cachecore_num--;
				update = 1;
				break;
			}
			pcache = pcache->next;
		}
	}
	if (update) {
		if (splice->cachecore_num == 0) {
			splice->config &= ~J9_NONDECISIVE;
		} else {
			while (pcache) {
				pcache->core_id--;
				pcache = pcache->next;
			}
		}
	}
}

static void j9_ultraplausible(struct dec400_t *dec400)
{
	int update = 0;
	struct slice_info *splice =
		getslicenode_ininit(dec400->core_cfg.sliceidx);
	struct dec400_t *pdec400, *pn;

	if (!splice)
		return;

	pdec400 = splice->dec400hdr;
	if (pdec400 == dec400) {
		splice->dec400hdr = dec400->next;
		pdec400 = splice->dec400hdr;
		vfree(dec400);
		splice->dec400core_num--;
		update = 1;
	} else {
		while (pdec400) {
			pn = pdec400->next;
			if (pn == dec400) {
				pdec400->next = pn->next;
				pdec400 = pn->next;
				vfree(dec400);
				splice->dec400core_num--;
				update = 1;
				break;
			}
			pdec400 = pdec400->next;
		}
	}
	if (update) {
		if (splice->dec400core_num == 0) {
			splice->config &= ~J9_PEACHING;
		} else {
			while (pdec400) {
				pdec400->core_id--;
				pdec400 = pdec400->next;
			}
		}
	}
}

static void j9_irreplaceably(struct axife_t *axife)
{
	int update = 0;
	struct slice_info *splice =
		getslicenode_ininit(axife->core_cfg.sliceidx);
	struct axife_t *paxife, *pn;

	if (!splice)
		return;

	paxife = splice->axifehdr;
	if (paxife == axife) {
		splice->axifehdr = axife->next;
		paxife = splice->axifehdr;
		vfree(axife);
		splice->axifecore_num--;
		update = 1;
	} else {
		while (paxife) {
			pn = paxife->next;
			if (pn == axife) {
				paxife->next = pn->next;
				paxife = pn->next;
				vfree(axife);
				splice->axifecore_num--;
				update = 1;
				break;
			}
			paxife = paxife->next;
		}
	}
	if (update) {
		if (splice->axifecore_num == 0) {
			splice->config &= ~J9_ELEVENSES;
		} else {
			while (paxife) {
				paxife->core_id--;
				paxife = paxife->next;
			}
		}
	}
}

static void j9_thistlebird(struct mmu_t *mmu)
{
	int update = 0;
	struct slice_info *splice = getslicenode_ininit(mmu->core_cfg.sliceidx);
	struct mmu_t *pmmu, *pn;

	if (!splice)
		return;

	pmmu = splice->mmuhdr;
	if (pmmu == mmu) {
		splice->mmuhdr = pmmu->next;
		pmmu = splice->mmuhdr;
		vfree(mmu);
		splice->mmucore_num--;
		update = 1;
	} else {
		while (pmmu) {
			pn = pmmu->next;
			if (pn == mmu) {
				pmmu->next = pn->next;
				pmmu = pn->next;
				vfree(mmu);
				splice->mmucore_num--;
				update = 1;
				break;
			}
			pmmu = pmmu->next;
		}
	}
	if (update) {
		if (splice->mmucore_num == 0) {
			splice->config &= ~J9_REDODOING;
		} else {
			while (pmmu) {
				pmmu->core_id--;
				pmmu = pmmu->next;
			}
		}
	}
}

static void j9_sphygmograph(struct jmgpu_vcmd_t *vcmdcore)
{
	int update = 0;
	struct slice_info *splice = getslicenode_ininit(vcmdcore->sliceidx);
	struct jmgpu_vcmd_t *pvcmd, *pn;

	if (!splice)
		return;

	pvcmd = splice->vcmdhdr;
	if (pvcmd == vcmdcore) {
		splice->vcmdhdr = pvcmd->next;
		pvcmd = splice->vcmdhdr;
		vfree(vcmdcore);
		splice->vcmdcore_num--;
		update = 1;
	} else {
		while (pvcmd) {
			pn = pvcmd->next;
			if (pn == vcmdcore) {
				pvcmd->next = pn->next;
				pvcmd = pn->next;
				vfree(vcmdcore);
				splice->vcmdcore_num--;
				update = 1;
				break;
			}
			pvcmd = pvcmd->next;
		}
	}
	if (update) {
		if (splice->vcmdcore_num == 0) {
			splice->config &= ~J9_DEMONESS;
		} else {
			while (pvcmd) {
				pvcmd->core_id--;
				pvcmd = pvcmd->next;
			}
		}
	}
}

void remove_node(void *pnode, int type)
{
	switch (type) {
	case JMD_HD_CORE_DEC:
		j9_capillaries(pnode);
		break;
	case JMD_HD_CORE_ENC:
		j9_lycoperdoid(pnode);
		break;
	case JMD_HD_CORE_CACHE:
		j9_acceptingness(pnode);
		break;
	case JMD_HD_CORE_D400:
		j9_ultraplausible(pnode);
		break;
	case JMD_HD_CORE_MMU:
		j9_thistlebird(pnode);
		break;
	case JMD_HD_CORE_VCMD:
		j9_sphygmograph(pnode);
		break;
	default:
		break;
	}
}


int slice_init(void)
{
	atomic_set(&slicenum, 0);
	atomic_set(&sliceinitd, 0);
	slicehdr = NULL;
	return 0;
}

void slice_init_finish(void)
{
	atomic_inc(&sliceinitd);
}

void slice_printdebug(void)
{
	struct j9_lamori *pdec, *pdec2;
	struct j9_aarrgh *penc, *penc2;
	struct slice_info *pslice;
	struct cache_dev_t *pcache, *pcache2;
	struct dec400_t *pdec400, *pdec400_2;
	int i, n = get_slicenumber(), k;
	int decn, encn, cachen, dec400n;
	struct slice_info *slice0, *slice1;

	pr_debug("########### slice info start #############");
	pr_debug("slice num = %d", n);
	slice0 = slicehdr;
	for (i = 0; i < n; i++) {
		pr_debug("slice %d:%lx:%llx:%lld:%x", i,
			 (unsigned long)slice0->dev, slice0->rsvmem_addr,
			 slice0->memsize, slice0->config);

		decn = get_slicecorenum(i, JMD_HD_CORE_DEC);
		pr_debug("dec num = %d", decn);
		encn = get_slicecorenum(i, JMD_HD_CORE_ENC);
		pr_debug("enc num = %d", encn);
		cachen = get_slicecorenum(i, JMD_HD_CORE_CACHE);
		pr_debug("cache  num = %d", cachen);
		dec400n = get_slicecorenum(i, JMD_HD_CORE_D400);
		pr_debug("dec400n num = %d", dec400n);

		pdec = get_decnodes(i, 0);
		k = 0;
		while (pdec) {
			pr_debug("dec core %d", k);
			pdec2 = get_decnodes(i, k);
			slice1 = getparentslice(pdec, JMD_HD_CORE_DEC);
			if (pdec != pdec2)
				pr_debug("get_decnodes fails @ %d", k);
			if (slice0 != slice1)
				pr_debug("getparentslice fails @ dec %d:%d", i,
					 k);
			pr_debug("addr=%llx, size=%d", pdec->multicorebase,
				 pdec->iosize);
			pr_debug("irq0=%d, irq1=%d", pdec->irqlist[0],
				 pdec->irqlist[1]);
			if (pdec->its_main_core_id) {
				pdec2 = pdec->its_main_core_id;
				pr_debug("main core = %d:%d", pdec2->sliceidx,
					 pdec2->core_id);
			}
			if (pdec->its_aux_core_id) {
				pdec2 = pdec->its_aux_core_id;
				pr_debug("aux core = %d:%d", pdec2->sliceidx,
					 pdec2->core_id);
			}
			pdec = pdec->next;
			k++;
		}

		penc = get_encnodes(i, 0);
		k = 0;
		while (penc) {
			pr_debug("enc core %d:", k);
			penc2 = get_encnodes(i, k);
			slice1 = getparentslice(penc, JMD_HD_CORE_ENC);
			if (penc != penc2)
				pr_debug("get_encnodes fails @ %d", k);
			if (slice0 != slice1)
				pr_debug("getparentslice fails @ enc %d:%d", i,
					 k);
			pr_debug("addr=%llx, size=%d", penc->core_cfg.base_addr,
				 penc->core_cfg.iosize);
			pr_debug("irq0=%d, irq1=%d", penc->irqlist[0],
				 penc->irqlist[1]);
			penc = penc->next;
			k++;
		}

		pcache = get_cachenodes(i, 0);
		k = 0;
		while (pcache) {
			pr_debug("cache core %d:", k);
			pcache2 = get_cachenodes(i, k);
			slice1 = getparentslice(pcache, JMD_HD_CORE_CACHE);
			if (pcache != pcache2)
				pr_debug("get_cachenodes fails @ %d", k);
			if (slice0 != slice1)
				pr_debug("getparentslice fails @ cache %d:%d",
					 i, k);
			pr_debug("addr=%llx, size=%d, type=%d, dir=%d",
				 pcache->core_cfg.base_addr,
				 pcache->core_cfg.iosize,
				 pcache->core_cfg.client, pcache->core_cfg.dir);
			pr_debug("irq0=%d, irq1=%d", pcache->irqlist[0],
				 pcache->irqlist[1]);
			pr_debug("parent addr=%llx",
				 pcache->core_cfg.parentaddr);
			if (pcache->parentcore) {
				if (pcache->core_cfg.client == ENC) {
					penc = (struct j9_aarrgh *)
						       pcache->parentcore;
					pr_debug(
						"parent enc core = %d:%d,addr %llx",
						penc->core_cfg.sliceidx,
						penc->core_id,
						penc->core_cfg.base_addr);
				} else {
					pdec = (struct j9_lamori *)
						       pcache->parentcore;
					pr_debug(
						"parent dec core = %d:%d,addr %llx",
						pdec->sliceidx, pdec->core_id,
						pdec->multicorebase);
				}
			} else {
				pr_debug("parent core = NULL");
			}
			pcache = pcache->next;
			k++;
		}
		pdec400 = get_dec400nodes(i, 0);
		k = 0;
		while (pdec400) {
			pr_debug("dec400 core %d:", k);
			pdec400_2 = get_dec400nodes(i, k);
			slice1 = getparentslice(pdec400, JMD_HD_CORE_D400);
			if (pdec400 != pdec400_2)
				pr_debug("get_dec400nodes fails @ %d", k);
			if (slice0 != slice1)
				pr_debug("getparentslice fails @ dec400 %d:%d",
					 i, k);
			pr_debug("addr=%llx, size=%d",
				 pdec400->core_cfg.dec400corebase,
				 pdec400->core_cfg.iosize);
			pr_debug("parent addr=%llx",
				 pdec400->core_cfg.parentaddr);
			if (pdec400->parentcore) {
				switch (pdec400->parenttype) {
				case JMD_HD_CORE_ENC:
					penc = (struct j9_aarrgh *)
						       pdec400->parentcore;
					pr_debug(
						"parent enc core = %d:%d,addr %llx",
						penc->core_cfg.sliceidx,
						penc->core_id,
						penc->core_cfg.base_addr);
					break;
				case JMD_HD_CORE_DEC:
					pdec = (struct j9_lamori *)
						       pdec400->parentcore;
					pr_debug(
						"parent dec core = %d:%d,addr %llx",
						pdec->sliceidx, pdec->core_id,
						pdec->multicorebase);
					break;
				case JMD_HD_CORE_SLICE:
					pslice = (struct slice_info *)
							 pdec400->parentcore;
					pr_debug("parent slice addr %llx",
						 pslice->rsvmem_addr);
					break;
				default:
					pr_debug(
						"error: dec400 parent type unknown");
					break;
				}
			} else {
				pr_debug("parent core = NULL");
			}
			pdec400 = pdec400->next;
			k++;
		}
		slice0 = slice0->next;
	}
	pr_debug("########### slice info finish #############");
}


