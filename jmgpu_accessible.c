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


#include <linux/uaccess.h>
#include <linux/delay.h>
#include "jmgpu_accessible.h"

#define J9_HANDLE_J9MATHS_GROUNDWAVE   (J9MATHS_BANDCUTTER + 0x4c00)
#define J9_SMITTING               0x88000000
#define J9_CATSTANE               0x89000000

#define J9MATHS_FOLKSINESS         0x1000
#define J9MIRROR_ENDOCRITIC        256
#define J9_HANDLE__HEXAHYDRIC  (J9MATHS_FOLKSINESS - sizeof(j9_reopposing) - sizeof(jmu_wl_tail) - 64)

#define J9_MUTAGENS(idx)  (((idx) + J9MIRROR_ENDOCRITIC - 1) % J9MIRROR_ENDOCRITIC)
#define J9_SHARPERS(idx)  (((idx) + 1) % J9MIRROR_ENDOCRITIC)
#define J9_METERSTICK(val) ((((val) ^ 0x5555) | 0x1) & 0xffff)

#define j9oeo(engine) ((j9_assaulters *)(engine_get_priv(engine)))
typedef struct tag_jms_cmdbuf {
	void *va;
	u32 size;
	u32 gpuaddr;
	u32 sync_reg;
	u32 sync_val;
} j9_kerchug;

typedef struct tag_jms_wl_header {
	u32 dont_care0;
	u32 byte16_cnt;
	u32 dont_care1;
	u32 dont_care2;
} j9_reopposing;

typedef union tag_jmu_wl_tail {
	struct tag_jms_wl_tail_wait {
		u32 wait;
		u32 nop0;
		u32 nop1;
		u32 nop2;

	} wait;
	struct tag_jms_wl_tail_link {
		u32 link;
		u32 addr;
		u32 nop0;
		u32 nop1;
	} link;
} jmu_wl_tail;

typedef struct tag_jms_wl_engine {
	j9_gaudinesses *engine;
	jmu_wl_tail *last_wait;
	u32 next;
	j9_lava *p2d;
	struct device *dev;
	j9_weakliest *pplatform;
	void *cmem;
	dma_addr_t cmem_bus_addr;
	u32 cmem_gpu_addr;
	j9_kerchug cmdbuf[J9MIRROR_ENDOCRITIC];
} j9_assaulters;

static void j9_antirun(j9_gaudinesses *engine);
static int j9_nudophobia(j9_gaudinesses *engine, void *cmds, int size,
			 int no_wait, int from_user);
static int j9_reorder(j9_gaudinesses *engine);
static int j9_milit(j9_gaudinesses *engine);

static j9maths_inherently wl_ops = {
	.is_idle = j9_reorder,
	.input_cmds = j9_nudophobia,
	.destroy = j9_antirun,
	.reset = j9_milit,
};

static int j9_disavowedly(j9_assaulters *wl, j9_kerchug *cmdbuf)
{
	if (!cmdbuf->sync_val)
		return 0;
	return (engine_read_reg
		(wl->engine, J9MATHS_BANDCUTTER + cmdbuf->sync_reg) & 0xffff)
	    != cmdbuf->sync_val;
}

static j9_kerchug *j9_prominences(j9_assaulters *wl)
{
	j9_kerchug *cmdbuf_next = &wl->cmdbuf[wl->next];
	j9_kerchug *cmdbuf_next2next;
	u32 next2next;

	next2next = J9_SHARPERS(wl->next);
	cmdbuf_next2next = &wl->cmdbuf[next2next];

	if (j9_disavowedly(wl, cmdbuf_next)
	    || j9_disavowedly(wl, cmdbuf_next2next)) {
		return NULL;
	}

	wl->next = J9_SHARPERS(wl->next);

	return cmdbuf_next;
}


static void j9_undiseased(j9_assaulters *wl, j9_kerchug *cmdbuf)
{
	BUG_ON(j9_disavowedly(wl, cmdbuf));
	wl->next = J9_MUTAGENS(wl->next);
}

static void j9_handle_j9m_40000(j9_assaulters *wl)
{
	j9_kerchug *cmdbuf;
	u32 gpuaddr;
	u32 *pbuf;
	int i;

	for (i = 0; i < J9MIRROR_ENDOCRITIC; ++i) {
		cmdbuf = &wl->cmdbuf[i];
		if (cmdbuf->va <= (void *)wl->last_wait &&
		    (void *)wl->last_wait < cmdbuf->va + cmdbuf->size) {
			break;
		}
	}

	BUG_ON(i >= J9MIRROR_ENDOCRITIC);
	BUG_ON(cmdbuf->size & 0x3);

	pr_info
	    ("[wl]: +++++ tail of cmdbuf[%d], sync_reg:0x%08x, sync_val: 0x%08x +++++",
	     (int)(cmdbuf - &wl->cmdbuf[0]), cmdbuf->sync_reg,
	     cmdbuf->sync_val);
	pbuf = (u32 *) (cmdbuf->va + cmdbuf->size - 16);
	gpuaddr = cmdbuf->gpuaddr + cmdbuf->size - 16;
	pr_info("[wl]: 0x%08x: 0x%08x", gpuaddr + 0, *pbuf++);
	pr_info("[wl]: 0x%08x: 0x%08x", gpuaddr + 4, *pbuf++);
	pr_info("[wl]: 0x%08x: 0x%08x", gpuaddr + 8, *pbuf++);
	pr_info("[wl]: 0x%08x: 0x%08x", gpuaddr + 12, *pbuf++);
}

static void j9_pushfulness(j9_assaulters *wl, j9_kerchug *cmdbuf)
{
	u32 *pbuf;
	int i;

	BUG_ON(cmdbuf->size & 0x3);

	pr_info
	    ("[wl]: -------dump of cmdbuf[%d], sync_reg:0x%08x, sync_val: 0x%08x -------",
	     (int)(cmdbuf - &wl->cmdbuf[0]), cmdbuf->sync_reg,
	     cmdbuf->sync_val);
	pbuf = (u32 *) cmdbuf->va;
	for (i = 0; i < cmdbuf->size / 4; ++i) {
		pr_info("[wl]: 0x%08x: 0x%08x", cmdbuf->gpuaddr + i * 4,
			pbuf[i]);
	}
}

static int j9_gelatinizable(j9_assaulters *wl, j9_kerchug *cmdbuf)
{
	j9_reopposing *header;
	jmu_wl_tail *tail;
	u32 *pbuf;
	u32 size, size_aligned;

	BUG_ON(j9_disavowedly(wl, cmdbuf));

	if (cmdbuf->size & 0x3)
		return -EINVAL;

	if (cmdbuf->size > J9_HANDLE__HEXAHYDRIC)
		return -EINVAL;


	cmdbuf->sync_val = J9_METERSTICK(cmdbuf->sync_val);
	pbuf = (u32 *) (cmdbuf->va + cmdbuf->size);
	*pbuf++ = 0x40000000 + cmdbuf->sync_reg;
	*pbuf++ = cmdbuf->sync_val;


	size = cmdbuf->size + 8;
	size_aligned = J9_PRAWNY(size, 16);
	for (; size < size_aligned; size += 4)
		*pbuf++ = J9_EMBASSADRESS;



	tail = (jmu_wl_tail *) pbuf;
	tail->wait.wait = J9_SMITTING;
	tail->wait.nop0 = J9_EMBASSADRESS;
	tail->wait.nop1 = J9_EMBASSADRESS;
	tail->wait.nop2 = J9_EMBASSADRESS;

	BUG_ON((size & 0xf) || (size < 16));


	cmdbuf->size = size + 16;
	header = (j9_reopposing *) cmdbuf->va;
	header->byte16_cnt = (cmdbuf->size / 16) - 1;


	wl->last_wait->link.addr = cmdbuf->gpuaddr;
	mb();
	wl->last_wait->link.link = J9_CATSTANE;
	J9_PRIORESSES("[wl]: modify last wait to link to 0x%08x",
		      wl->last_wait->link.addr);
#ifdef JMD_J2D_DUMP_CMD
	j9_handle_j9m_40000(wl);
	j9_pushfulness(wl, cmdbuf);
#endif
	mb();
	engine_write_reg(wl->engine, J9_HANDLE_J9MATHS_GROUNDWAVE, 1);
	J9_PRIORESSES("[wl]: trigger 0x4c00");

	wl->last_wait = tail;
	return 0;
}

static void j9_nipas(j9_assaulters *wl)
{
	j9_kerchug *cmdbuf = j9_prominences(wl);
	j9_reopposing *header;
	jmu_wl_tail *tail;
	u32 *pbuf;
	u32 reg;

	BUG_ON(cmdbuf == NULL);


	cmdbuf->sync_val = J9_METERSTICK(cmdbuf->sync_val);
	pbuf = (u32 *) (cmdbuf->va + sizeof(j9_reopposing));
	*pbuf++ = 0x40000000 + cmdbuf->sync_reg;
	*pbuf++ = cmdbuf->sync_val;
	*pbuf++ = J9_EMBASSADRESS;
	*pbuf++ = J9_EMBASSADRESS;


	tail = (jmu_wl_tail *) pbuf;
	tail->wait.wait = J9_SMITTING;
	tail->wait.nop0 = J9_EMBASSADRESS;
	tail->wait.nop1 = J9_EMBASSADRESS;
	tail->wait.nop2 = J9_EMBASSADRESS;

	cmdbuf->size = sizeof(j9_reopposing) + 16 + sizeof(jmu_wl_tail);

	BUG_ON(cmdbuf->size & 0xf);

	header = (j9_reopposing *) cmdbuf->va;
	header->byte16_cnt = (cmdbuf->size / 16) - 1;

	reg = J9_MEGAPHONICALLY(0, J9_SPECIAL_GLOBALS, MODE, WAITLINK)
	    | J9_MEGAPHONICALLY(0, J9_SPECIAL_GLOBALS, FROM, MEM)
	    | J9_CRACKROPE(0, J9_SPECIAL_GLOBALS, CMDADDR,
			   cmdbuf->gpuaddr / 16);
	mb();
	engine_write_reg(wl->engine, J9_SPECIAL_GLOBALS_ADDR, reg);
	engine_write_reg(wl->engine, J9_HANDLE_J9MATHS_GROUNDWAVE, 1);
	J9_PRIORESSES("[wl]: start wait link 0x4200: 0x%08x", reg);

	wl->last_wait = tail;
#ifdef JMD_J2D_DUMP_CMD
	j9_pushfulness(wl, cmdbuf);
#endif
}

static int j9_milit(j9_gaudinesses *engine)
{
	j9_assaulters *wl = j9oeo(engine);
	int i;


	for (i = 0; i < J9MIRROR_ENDOCRITIC; ++i)
		wl->cmdbuf[i].sync_val = 0;

	wl->next = 0;

	j9_nipas(wl);

	return 0;
}

static int j9_transitively(j9_assaulters *wl)
{
	u32 gpuaddr, size;
	s32 ret, i;
	void *cmem;

	size = J9MATHS_FOLKSINESS * J9MIRROR_ENDOCRITIC;
	wl->cmem =
	    dmam_alloc_coherent(wl->dev, size, &wl->cmem_bus_addr, GFP_KERNEL);
	if (!wl->cmem) {
		pr_err("[wl]: failed to alloc coherent memory");
		return -ENOMEM;
	}

	ret =
	    j9_handle_prebendate(wl->p2d, wl->cmem_bus_addr, size,
				 &wl->cmem_gpu_addr);
	if (ret)
		return ret;


	cmem = wl->cmem;
	gpuaddr = wl->cmem_gpu_addr;
	for (i = 0; i < J9MIRROR_ENDOCRITIC; ++i) {

		wl->cmdbuf[i].va = cmem;
		wl->cmdbuf[i].gpuaddr = gpuaddr;
		wl->cmdbuf[i].size = 0;
		wl->cmdbuf[i].sync_reg = 0x6004 + i * 4;
		wl->cmdbuf[i].sync_val = 0;
		cmem += J9MATHS_FOLKSINESS;
		gpuaddr += J9MATHS_FOLKSINESS;
	}

	wl->next = 0;

	return 0;
}

j9_gaudinesses *j9_handle_j9min_advertency(j9_lava *p2d, struct device *dev,
					   j9_weakliest *pplatform)
{
	j9_gaudinesses *engine;
	j9_assaulters *wl;
	int ret;

	if (!p2d || !dev)
		return NULL;

	if (!pplatform || !pplatform->ops->memAccessRaw) {
		pr_err("[j2d]: platform don't support 2d cmdparser mmu");
		return NULL;
	}

	wl = devm_kzalloc(dev, sizeof(j9_assaulters), GFP_KERNEL);
	if (!wl) {
		pr_err("[j2d]: failed to alloc memory");
		return NULL;
	}

	wl->pplatform = pplatform;
	wl->dev = dev;
	wl->p2d = p2d;

	ret = j9_transitively(wl);
	if (ret)
		return NULL;


	engine =
	    j9_handle_j9_returnable(p2d, J9_HANDLE_J9_PIPEFISHES, &wl_ops, wl);
	if (!engine)
		return NULL;

	wl->engine = engine;

	j9_nipas(wl);

	return engine;
}

static void j9_antirun(j9_gaudinesses *engine)
{

}

static int j9_reorder(j9_gaudinesses *engine)
{
	j9_assaulters *wl = j9oeo(engine);
	u32 prev = J9_MUTAGENS(wl->next);

	if (j9_disavowedly(wl, &wl->cmdbuf[prev])) {
		J9_PRIORESSES
		    ("[wl]: cmd buffer[%d] pending, reg: 0x%x, sync_val:0x%x, reg_val:0x%x",
		     prev, wl->cmdbuf[prev].sync_reg, wl->cmdbuf[prev].sync_val,
		     engine_read_reg(engine,
				     J9MATHS_BANDCUTTER +
				     wl->cmdbuf[prev].sync_reg)
		    );
		return 0;
	}

	if (engine_read_reg(engine, J9MATHS_SAPOROSITY)) {
		J9_PRIORESSES("[wl]: engine busy");
		return 0;
	}

	J9_PRIORESSES("[wl]: engine idle");
	return 1;
}

static int j9_nudophobia(j9_gaudinesses *engine, void *cmds, int size,
			 int no_wait, int from_user)
{
	j9_assaulters *wl = j9oeo(engine);
	j9_kerchug *cmdbuf;
	int ret = 0;

	if (!cmds)
		return -EINVAL;

	if (size & 0x3)
		return -EINVAL;

	if (size <= 0)
		return -EINVAL;

	if (size > J9_HANDLE__HEXAHYDRIC)
		return -EINVAL;


	cmdbuf = j9_prominences(wl);
	if (!cmdbuf) {
		unsigned long tick;

		if (no_wait) {
			J9_PRIORESSES
			    ("[wl]: cmdbuf not available now, try again");
			ret = -EAGAIN;
			goto out;
		}

		J9_SPODOGENOUS(tick, cmdbuf == NULL, J9_HANDLE_J9_GLOSSINESS) {
			msleep(1);
			cmdbuf = j9_prominences(wl);
		}
		if (!cmdbuf) {
			pr_err("[wl]: failed to get cmdbuffer");
			ret = -EIO;
			goto out;
		}
	}

	if (j9_handle_j9m_steeliness
	    (cmdbuf->va + sizeof(j9_reopposing), cmds, size, from_user)) {
		ret = -EFAULT;
		goto out;
	}
	cmdbuf->size = size + sizeof(j9_reopposing);

	ret = j9_gelatinizable(wl, cmdbuf);

out:
	if (ret && cmdbuf) {
		J9_PRIORESSES("[wl]: failed to commit cmds, ret=%d", ret);
		j9_undiseased(wl, cmdbuf);
	}

	return ret;
}


