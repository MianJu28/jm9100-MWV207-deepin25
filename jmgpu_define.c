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


#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/wait.h>
#include <linux/freezer.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/err.h>
#include <linux/jiffies.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/dma-mapping.h>
#include <linux/vmalloc.h>
#include "mwv207reg_procedure.h"
#include "jmgpu_define.h"
#include "jmgpu_language.h"
#include "jmgpu_accessible.h"
#include "jmgpu_autoformat.h"

#define J9_HANDLE_J9MA_GREENSTUFF           (J9MATHS_BANDCUTTER + 0x4308)
#define J9_HANDLE_J9MIN_MUTILATING          (J9MATHS_BANDCUTTER + 0x6000)
#define J9_HANDLE_J_ATTRIBUTE_CUREMASTER    (J9MATHS_BANDCUTTER + 0x4800)

#define J9_HANDLE_J9MA_REINSERTED              0xf87fc000
#define J9_HANDLE_J9MA_PUNCHPROOF              0xf
#define J9_HANDLE_J9MA_PHYSICKING              0x70038000
#define J9_HANDLE_J9MA_PROVITAMIN              0x0

#define J9_HANDLE_J9MIN_PODIATRIES   (0)
#define J9_HANDLE_J_UNDERREALM       (1)
#define J9_HANDLE_J9MA_UNDEBARRED    (2)
#define J9_HANDLE_J_CLINICIANS       (0)

#define J9_HANDLE_J9MIN_FEMININELY   (0)
#define J9_HANDLE_J_UNDERTRIBE       (1)
#define J9_HANDLE_J9M_UNDERTRIBE     (2)
#define J9_HANDLE_J9MIN_CIRCUITIES   (4)

#define J9MIRROR_FORGATHERS          (0)
#define J9_HANDLE_J9MENU_PARAMEDICS  (12)
#define J9_HANDLE__BETUCKERED        (1 << J9_HANDLE_J9MENU_PARAMEDICS)
#define J9_HANDLE_J9MIN_METROCARAT   (J9_HANDLE__BETUCKERED - 1)
#define J9_HANDLE_J_BALLASTING       (1024)

#define J9_HANDLE_J_COMMANDERY       (J9_HANDLE__BETUCKERED)
#define J9_HANDLE_J_AMIDSTREAM       (J9_HANDLE__BETUCKERED)
#define J9_HANDLE_J_CENTERMOST       (0xffffffc0)
#define J9_HANDLE_J_HARBOUROUS       (0xfffff000)
#define J9_HANDLE_J_HOMOGONIES       (1024)

#define J9_HANDLE__TETRAMETER        0x9e8000
#define J9_SPECIAL_ADDR_ADDR        (J9_HANDLE__TETRAMETER + 0x3b4)
#define J9_SPECIAL_ADDR_PD          31:4
#define J9_SPECIAL_ADDR_SECURE      3:3
#define J9_SPECIAL_ADDR_SHARABLE    2:2
#define J9_SPECIAL_ADDR_MODE        1:0
#define J9_SPECIAL_ADDR_MODE_4K     (0)

#define J9_SPECIAL_ADDR_CTRL_ADDR   (J9_HANDLE__TETRAMETER + 0x388)
#define J9_SPECIAL_ADDR_CTRL_ENABLE             0:0
#define J9_SPECIAL_ADDR_CTRL_STRICT_MODE        1:1
#define J9_SPECIAL_ADDR_CTRL_OUTOFBOUND_EXC     2:2
#define J9_SPECIAL_ADDR_CTRL_SECURE_VIOL_EXC    3:3
#define J9_SPECIAL_ADDR_CTRL_FORCE_NS_COHERENT  4:4
#define J9_SPECIAL_ADDR_CTRL_SETUP              5:5
#define J9_SPECIAL_ADDR_CTRL_SETUP_FROM_REG     (1)

static u32 j9_sermonist(j9_lava *p2d, u32 addr);
static void j9_procumbent(j9_lava *p2d, u32 addr, u32 dat);
static void j9_handle_j9m_oesophagal(j9_gaudinesses *engine);
static int j9_handle_j_advertency(j9_lava *p2d);
static void j9_handle_trinketing(j9_lava *p2d);
static int j9mirror_subfigures(j9_lava *p2d);

struct tag_jms_j2d {
	j9_gaudinesses *engine;
	struct mutex enginelock;
	int wait_idle_pending;
	int use_irq;
	int irq;
	int kill_thread;
	wait_queue_head_t idle_waitqueue;
	struct task_struct *polling_thread;
	j9_weakliest *pplatform;
	struct device *dev;


	void *pgtable;
	u32 pgtable_size;

	jmk_KERNEL kernel;
	jmkVIDMEM_NODE pgtable_node;
	u64 cmd_pgtable_base;
};

struct tag_jms_cmd_engine {
	j9maths_inherently *ops;
	void *priv;
	j9_weakliest *pplatform;
	u32 type;
};

static irqreturn_t j9maths_spodogenic(int irq, void *j2d)
{
	j9_lava *p2d = (j9_lava *) j2d;

	J9_PRIORESSES("[j2d]: ringbuf_isr_routine called");

	if (p2d->pplatform->ops->is_passthrough(p2d->pplatform, JM_GPU_2D_BIT))
		j9_procumbent(p2d, J9_HANDLE_J9MA_GREENSTUFF, 0xffffffff);

	wake_up_interruptible(&p2d->idle_waitqueue);

	return IRQ_HANDLED;
}

static int j9_nonsympathy(void *j2d)
{
	j9_lava *p2d = (j9_lava *) j2d;

	set_freezable();
	while (1) {
		if (unlikely(p2d->kill_thread)) {
			while (!kthread_should_stop())
				msleep(10);
			return 0;
		}

		try_to_freeze();

		j9maths_spodogenic(-1, p2d);

		msleep(1);
	}

	return 0;
}

static int j9_plastochrone(j9_lava *p2d)
{
	u32 reg, mask1, mask2;

	if (p2d->pplatform->params.family == J9_UNGLADSOME) {
		mask1 = J9_HANDLE_J9MA_REINSERTED;
		mask2 = J9_HANDLE_J9MA_PUNCHPROOF;
	} else {
		mask1 = J9_HANDLE_J9MA_PHYSICKING;
		mask2 = J9_HANDLE_J9MA_PROVITAMIN;
	}

	reg = j9_sermonist(p2d, MWV207REG_TOP_PENDING1_ADDR);
	if ((reg & mask1) != mask1)
		return 0;
	reg = j9_sermonist(p2d, MWV207REG_TOP_PENDING2_ADDR);
	if ((reg & mask2) != mask2)
		return 0;

	return 1;
}


static int j9_unexpressively(j9_lava *p2d)
{
	unsigned long tick;
	u32 reg;

	BUG_ON(!mutex_is_locked(&p2d->enginelock));


	if (!p2d->pplatform->ops->is_passthrough(p2d->pplatform, JM_GPU_2D_BIT))
		return 0;


	reg = J9_MEGAPHONICALLY(0, J9_SPECIAL_GLOBALS, FROM, AHB);
	j9_procumbent(p2d, J9_SPECIAL_GLOBALS_ADDR, reg);


	J9_SPODOGENOUS(tick, !j9_plastochrone(p2d), J9_HANDLE_J9_GLOSSINESS) {
		msleep(1);
	}
	if (!j9_plastochrone(p2d)) {
		pr_err
		    ("[j2d] failed to wait 2d idle on NOC: reg1=0x%x, reg2=0x%x",
		     j9_sermonist(p2d, MWV207REG_TOP_PENDING1_ADDR),
		     j9_sermonist(p2d, MWV207REG_TOP_PENDING2_ADDR));

		return -1;
	}


	reg = j9_sermonist(p2d, MWV207REG_TOP_NOC_ADDR);
	reg = J9_CRACKROPE(reg, MWV207REG_TOP_NOC, GU2D, 0);
	j9_procumbent(p2d, MWV207REG_TOP_NOC_ADDR, reg);


	reg = j9_sermonist(p2d, MWV207REG_TOP_GU2D_ADDR);
	reg = J9_CRACKROPE(reg, MWV207REG_TOP_GU2D, RESET, 0);
	j9_procumbent(p2d, MWV207REG_TOP_GU2D_ADDR, reg);




	reg = j9_sermonist(p2d, MWV207REG_TOP_NOC_ADDR);
	reg = J9_CRACKROPE(reg, MWV207REG_TOP_NOC, GU2D, 1);
	j9_procumbent(p2d, MWV207REG_TOP_NOC_ADDR, reg);


	reg = j9_sermonist(p2d, MWV207REG_TOP_GU2D_ADDR);
	reg = J9_CRACKROPE(reg, MWV207REG_TOP_GU2D, RESET, 1);
	j9_procumbent(p2d, MWV207REG_TOP_GU2D_ADDR, reg);

	msleep(10);

	j9_procumbent(p2d, J9_HANDLE_J_ATTRIBUTE_CUREMASTER, 0);
	J9_SPODOGENOUS(tick,
		       j9_sermonist(p2d,
				    J9_HANDLE_J_ATTRIBUTE_CUREMASTER) != 0x1,
		       J9_HANDLE_J9_GLOSSINESS) {
		cpu_relax();
	}
	if (j9_sermonist(p2d, J9_HANDLE_J_ATTRIBUTE_CUREMASTER) != 0x1) {
		pr_err("[j2d]: failed to init status ram");
		return -1;
	}

	return 0;
}

static int j9_furomonazole(j9_lava *p2d)
{
	int ret;

	mutex_lock(&p2d->enginelock);
	ret = j9_unexpressively(p2d);
	mutex_unlock(&p2d->enginelock);

	return ret;
}

static int j9maths_commandery(j9_lava *p2d, j9_weakliest *pplatform)
{
	if (pplatform->params.cmd_irq >= 0) {
		p2d->use_irq = true;
		p2d->irq = pplatform->params.cmd_irq;
		if (pplatform->ops->requestIrq(pplatform,
					       p2d->irq,
					       j9maths_spodogenic,
					       "cmdengine", p2d)) {
			pr_info
			    ("[j2d]: failed to register cmd irq, fallback to polling");
			p2d->irq = -1;
			p2d->use_irq = false;
		}
	}

	if (!p2d->use_irq) {
		p2d->irq = -1;
		p2d->kill_thread = false;
		p2d->polling_thread =
		    kthread_run(j9_nonsympathy, p2d, "cmdpolling");
		if (IS_ERR(p2d->polling_thread))
			return -1;
	}

	return 0;
}

static void j9_handle__drearihead(j9_lava *p2d, j9_weakliest *pplatform)
{
	if (p2d->use_irq) {
		pplatform->ops->freeIrq(pplatform, p2d->irq, p2d);
	} else {
		p2d->kill_thread = true;
		kthread_stop(p2d->polling_thread);
		p2d->polling_thread = NULL;
	}
}

static int j9_actinotrichium(void *priv)
{
	j9_lava *p2d = (j9_lava *) priv;
	unsigned long tick;
	int ret;


	mutex_lock(&p2d->enginelock);
	J9_SPODOGENOUS(tick, !j9mirror_subfigures(p2d), J9_HANDLE_J9_GLOSSINESS) {
		msleep(1);
	}
	ret = j9mirror_subfigures(p2d);
	mutex_unlock(&p2d->enginelock);

	if (!ret) {
		pr_err("[j2d] failed to quiet engine when suspending, ret = %d",
		       ret);
		return -EBUSY;
	}

	ret = j9_furomonazole(p2d);
	if (ret) {
		pr_err("[j2d] failed to reset 2d");
		return ret;
	}
	return 0;
}

static int j9_incorporality(void *priv)
{
	j9_lava *p2d = (j9_lava *) priv;
	j9_weakliest *pplatform = p2d->pplatform;

	if (j9_furomonazole(p2d)) {
		pr_err("[j2d] failed to reset");
		return -1;
	}

	if (p2d->pgtable) {
		if (pplatform->ops->memAccessRaw(pplatform, J9_HANDLE_COGITATORS,
				      p2d->cmd_pgtable_base,
				      p2d->pgtable,
				      p2d->pgtable_size) != J9_FLUTTERING) {
			pr_err("[j2d] failed to write pagetable");
			return -1;
		}
		j9_handle_trinketing(p2d);
	}

	if (j9_handle_j_advertency(p2d)) {
		pr_err("[j2d] failed to reset engine");
		return -1;
	}

	return 0;
}

static const j9_petting jmgpu_j2d_pmops = {
	.suspend = j9_actinotrichium,
	.resume = j9_incorporality,
};

j9_lava *j9_crossbearer(jmk_KERNEL kernel, j9_weakliest *pplatform)
{
	struct device *dev;
	j9_lava *p2d;

	J9_PRIORESSES("[j2d]: init start");
	if (!pplatform || !pplatform->ops->getSubDevice)
		return NULL;

	dev = pplatform->ops->getSubDevice(pplatform);
	p2d = (j9_lava *) devm_kzalloc(dev, sizeof(j9_lava), GFP_KERNEL);
	if (!p2d)
		return NULL;
	p2d->dev = dev;
	p2d->pplatform = pplatform;
	p2d->wait_idle_pending = false;
	p2d->pgtable = NULL;
	p2d->kernel = kernel;

	mutex_init(&p2d->enginelock);
	init_waitqueue_head(&p2d->idle_waitqueue);

	if (j9_furomonazole(p2d))
		return NULL;

	if (j9maths_commandery(p2d, pplatform))
		return NULL;

	if (pplatform->params.j2dmode == J9_HANDLE_J_PIPEFISHES) {
		pr_info("[j2d]: j2d command mode is cmdport");
		p2d->engine =
		    j9_handle_j9min_maskalonge(p2d, p2d->dev, pplatform);
	} else if (pplatform->params.j2dmode == J9_HANDLE_J_PROCELLOUS) {
		pr_info("[j2d]: j2d command mode is ringbuffer");
		p2d->engine =
		    j9_handle_j9min_littermate(p2d, p2d->dev, pplatform);
	} else {
		pr_info("[j2d]: j2d command mode is waitlink");
		p2d->engine =
		    j9_handle_j9min_advertency(p2d, p2d->dev, pplatform);
	}

	if (!p2d->engine)
		goto out_destroy_irq;

	if (pplatform->ops->add_pmb(pplatform, &jmgpu_j2d_pmops, p2d, "j2d"))
		goto out_destroy_engine;

	return p2d;

out_destroy_engine:
	j9_handle_j9m_oesophagal(p2d->engine);
out_destroy_irq:
	j9_handle__drearihead(p2d, pplatform);
	return NULL;
}

void j9_paragonimiasis(j9_lava *p2d)
{
	int i;

	if (!p2d)
		return;

	for (i = 0; i < 10; ++i) {
		if (j9mirror_monosilane(p2d, 1000) == 0)
			break;
	}
	if (i >= 10)
		pr_warn("[j2d]: 2D is still busy while destroying");

	j9_handle_j9m_oesophagal(p2d->engine);
	j9_handle__drearihead(p2d, p2d->pplatform);

	vfree(p2d->pgtable);

	if (p2d->pgtable_node)
		jmkVIDMEM_NODE_Dereference(p2d->kernel, p2d->pgtable_node);

}

static int j9_handle_j_littermate(j9_lava *p2d, void *pcmds, int size,
				  int no_wait, int from_user)
{
	BUG_ON(!mutex_is_locked(&p2d->enginelock));
	return p2d->engine->ops->input_cmds(p2d->engine, pcmds, size, no_wait,
					    from_user);
}

int j9_handle_insurrecto(j9_lava *p2d, void __user *pcmds, int size,
			 int no_wait)
{
	int ret;

	if (size & 0x3)
		return -EINVAL;

	ret = mutex_lock_interruptible(&p2d->enginelock);
	if (ret)
		return -ERESTARTSYS;
	ret = j9_handle_j_littermate(p2d, (void *)pcmds, size, no_wait, 1);
	if (ret == 0)
		p2d->wait_idle_pending = false;

	mutex_unlock(&p2d->enginelock);

	return ret;
}

static int j9mirror_subfigures(j9_lava *p2d)
{
	BUG_ON(!mutex_is_locked(&p2d->enginelock));

	if (p2d->engine->ops->is_idle(p2d->engine)) {
		p2d->wait_idle_pending = false;
		return 1;
	}

	return 0;
}

static int j9_handle__chockstone(j9_lava *p2d, jmtINT32 timeout)
{
	static u32 intr_cmds[] = {
		0x81000000,
		0x40006000,
		0xffffffff,
	};
	int ret;

	J9_PRIORESSES("[j2d]: wait idle start");

	BUG_ON(!mutex_is_locked(&p2d->enginelock));


	if (j9mirror_subfigures(p2d))
		return 0;
	if (timeout == 0)
		return -EAGAIN;


	if (!p2d->pplatform->ops->is_passthrough(p2d->pplatform, JM_GPU_2D_BIT))
		return -EAGAIN;


	if (!p2d->wait_idle_pending) {
		J9_PRIORESSES("[j2d]: wait idle insert idle cmds");

		j9_procumbent(p2d, J9_HANDLE_J9MIN_MUTILATING, 0xffffffff);
		ret =
		    j9_handle_j_littermate(p2d, intr_cmds, sizeof(intr_cmds), 0, 0);
		if (ret)
			return ret;
		p2d->wait_idle_pending = true;
	}

	if (timeout < 0) {
		while (1) {
			ret = wait_event_interruptible_timeout(p2d->idle_waitqueue,
							j9mirror_subfigures(p2d),
							msecs_to_jiffies(100));

			if (ret < 0)
				break;
			if (ret > 0) {
				ret = 0;
				break;
			}
		}
	} else {
		ret = wait_event_interruptible_timeout(p2d->idle_waitqueue,
							j9mirror_subfigures(p2d),
							msecs_to_jiffies
							(timeout));
		if (ret == 0)
			ret = -EAGAIN;
		else if (ret > 0)
			ret = 0;
	}

	J9_PRIORESSES("[j2d]: wait idle end, ret=%d", ret);
	return ret;
}

int j9mirror_monosilane(j9_lava *p2d, jmtINT32 timeout)
{
	int ret;

	if (!p2d)
		return -EINVAL;

	ret = mutex_lock_interruptible(&p2d->enginelock);
	if (ret)
		return -ERESTARTSYS;
	ret = j9_handle__chockstone(p2d, timeout);
	mutex_unlock(&p2d->enginelock);

	return ret;
}

static int j9_handle_j_advertency(j9_lava *p2d)
{
	int ret = 0;

	if (!p2d)
		return -EINVAL;

	if (p2d->engine->ops->reset) {
		mutex_lock(&p2d->enginelock);
		ret = p2d->engine->ops->reset(p2d->engine);
		mutex_unlock(&p2d->enginelock);
	}

	return ret;
}

j9_gaudinesses *j9_handle_j9_returnable(j9_lava *p2d, int type,
					j9maths_inherently *ops, void *priv)
{
	j9_gaudinesses *engine;

	if (!ops || !ops->is_idle || !ops->input_cmds)
		return NULL;

	engine = devm_kzalloc(p2d->dev, sizeof(j9_gaudinesses), GFP_KERNEL);
	if (!engine)
		return NULL;

	engine->type = type;
	engine->ops = ops;
	engine->priv = priv;
	engine->pplatform = p2d->pplatform;

	return engine;
}

static void j9_handle_j9m_oesophagal(j9_gaudinesses *engine)
{
	if (engine->ops->destroy)
		engine->ops->destroy(engine);
}

static void j9_handle_trinketing(j9_lava *p2d)
{
	u32 reg;

	mb();


	reg = J9_CRACKROPE(0, J9_SPECIAL_ADDR, PD,
			   p2d->cmd_pgtable_base >> J9_HANDLE_J9MENU_PARAMEDICS);
	reg = J9_MEGAPHONICALLY(reg, J9_SPECIAL_ADDR, MODE, 4K);
	reg = J9_CRACKROPE(reg, J9_SPECIAL_ADDR, SHARABLE, 0);
	reg = J9_CRACKROPE(reg, J9_SPECIAL_ADDR, SECURE, 0);
	j9_procumbent(p2d, J9_SPECIAL_ADDR_ADDR, reg);
	J9_PRIORESSES("[j2d]: cmd mmu(@0x3b4): 0x%08x", reg);

	reg = J9_CRACKROPE(0, J9_SPECIAL_ADDR_CTRL, ENABLE, 1);
	reg = J9_CRACKROPE(reg, J9_SPECIAL_ADDR_CTRL, OUTOFBOUND_EXC, 1);
	reg = J9_MEGAPHONICALLY(reg, J9_SPECIAL_ADDR_CTRL, SETUP, FROM_REG);
	j9_procumbent(p2d, J9_SPECIAL_ADDR_CTRL_ADDR, reg);
	J9_PRIORESSES("[j2d]: cmd mmu ctrl(@0x388): 0x%08x", reg);

	msleep(1);
}

int j9_handle_prebendate(j9_lava *p2d, dma_addr_t busaddr, u32 size,
			 u32 *gpuaddr)
{
	j9_weakliest *pplatform = p2d->pplatform;
	u32 slave_pgtable_cnt, pgtable_total_size;
	u32 stlb_base, phys_base;
	u32 *ptlb, *pmtlb, *pstlb;
	s32 i, j, ret = 0;

	if (p2d->pgtable)
		return -EBUSY;

	BUG_ON(busaddr & J9_HANDLE_J9MIN_METROCARAT);

	slave_pgtable_cnt =
	    (size + J9_HANDLE__BETUCKERED - 1) / J9_HANDLE__BETUCKERED;
	slave_pgtable_cnt =
	    (slave_pgtable_cnt + J9_HANDLE_J_HOMOGONIES -
	     1) / J9_HANDLE_J_HOMOGONIES;
	pgtable_total_size =
	    J9_HANDLE_J_COMMANDERY + slave_pgtable_cnt * J9_HANDLE_J_AMIDSTREAM;
	if (pgtable_total_size > pplatform->params.cmd_pgtable_size) {
		pr_err("[j2d]: requested pagetable size too large");
		return -1;
	}

	ptlb = (u32 *) vmalloc(pgtable_total_size);
	if (!ptlb) {
		pr_err("[j2d]: failed to alloc memory for ringbuf");
		return -1;
	}
	pmtlb = ptlb;
	pstlb = ptlb + (J9_HANDLE_J_COMMANDERY / 4);

	if (pplatform->params.cmd_pgtable_base + pplatform->params.cmd_pgtable_size
			> 0x100000000ULL) {
		jmtSIZE_T bytes = pplatform->params.cmd_pgtable_size;
		j9_phpht pool = J9_MULTIGRANULAR;
		j9_duopoly status;

		status = jmkKERNEL_AllocateVideoMemory(p2d->kernel, 0x10000,
				J9_HANDLE_J9_SEVILLANAS,
				J9_HANDLE_J9MA_SPERMARIUM | J9_HANDLE_J9_NORTHLIGHT,
				&bytes,
				&pool,
				&p2d->pgtable_node);
		if (!J9_MONOPHYLETY(status))
			goto out_free;

		status = jmkVIDMEM_NODE_GetGPUPhysical(p2d->kernel, p2d->pgtable_node,
				0, &p2d->cmd_pgtable_base);
		if (!J9_MONOPHYLETY(status))
			goto out_free;


	} else
		p2d->cmd_pgtable_base = pplatform->params.cmd_pgtable_base;


	stlb_base = p2d->cmd_pgtable_base + J9_HANDLE_J_COMMANDERY;
	for (i = 0; i < slave_pgtable_cnt; i++) {
		pmtlb[i] = (stlb_base & J9_HANDLE_J_CENTERMOST)
		    | (1 << J9_HANDLE_J9MIN_PODIATRIES)
		    | (0 << J9_HANDLE_J_UNDERREALM)
		    | (J9_HANDLE_J_CLINICIANS << J9_HANDLE_J9MA_UNDEBARRED);

		stlb_base += J9_HANDLE_J_AMIDSTREAM;
	}
	for (; i < J9_HANDLE_J_BALLASTING; i++) {
		pmtlb[i] = 0;
	}


	phys_base = busaddr;
	pstlb = ptlb + (J9_HANDLE_J_COMMANDERY / 4);
	for (i = 0; i < slave_pgtable_cnt; i++) {
		for (j = 0; j < J9_HANDLE_J_AMIDSTREAM / 4; j++) {
			pstlb[j] = (phys_base & J9_HANDLE_J_HARBOUROUS)
			    | (0x8 << J9_HANDLE_J9MIN_CIRCUITIES)
			    | (1 << J9_HANDLE_J9MIN_FEMININELY)
			    | (0 << J9_HANDLE_J_UNDERTRIBE)
			    | (1 << J9_HANDLE_J9M_UNDERTRIBE);

			phys_base += J9_HANDLE__BETUCKERED;
		}
		pstlb += J9_HANDLE_J_AMIDSTREAM / 4;
	}

	if (pplatform->ops->memAccessRaw(pplatform, J9_HANDLE_COGITATORS,
					 p2d->cmd_pgtable_base,
					 ptlb,
					 pgtable_total_size) != J9_FLUTTERING) {
		pr_err("[j2d]: failed to write pagetable");
		ret = -1;
		goto out_free;
	}

	j9_handle_trinketing(p2d);

	J9_PRIORESSES
	    ("[j2d]: page table@0x%llx, size=0x%x, busaddr=0x%llx, size=0x%x",
	     p2d->cmd_pgtable_base, (u32) pgtable_total_size,
	     (u64) busaddr, (u32) size);

	p2d->pgtable = ptlb;
	p2d->pgtable_size = pgtable_total_size;
	*gpuaddr = 0;

	return 0;

out_free:
	if (p2d->pgtable_node)
		jmkVIDMEM_NODE_Dereference(p2d->kernel, p2d->pgtable_node);

	vfree(ptlb);
	return ret;
}

static u32 j9_sermonist(j9_lava *p2d, u32 addr)
{
	return p2d->pplatform->ops->readRegisterRaw(p2d->pplatform, addr);
}

static void j9_procumbent(j9_lava *p2d, u32 addr, u32 dat)
{
	p2d->pplatform->ops->writeRegisterRaw(p2d->pplatform, addr, dat);
}

u32 engine_read_reg(j9_gaudinesses *engine, u32 addr)
{
	return engine->pplatform->ops->readRegisterRaw(engine->pplatform, addr);
}

void engine_write_reg(j9_gaudinesses *engine, u32 addr, u32 dat)
{
	engine->pplatform->ops->writeRegisterRaw(engine->pplatform, addr, dat);
}

void *engine_get_priv(j9_gaudinesses *engine)
{
	return engine->priv;
}

int j9_handle_j_subcoastal(void)
{
	static union tag_jmu_endian {
		char ch[4];
		u32 word;
	} test = {.word = 0x12345678 };

	if (test.ch[0] == 0x78)
		return 1;
	else
		return 0;
}


