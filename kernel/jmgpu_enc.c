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




#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/moduleparam.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/semaphore.h>
#include <linux/spinlock.h>
#include <linux/io.h>
#include <linux/pci.h>
#include <linux/uaccess.h>
#include <linux/ioport.h>
#include <linux/version.h>
#include <linux/vmalloc.h>
#include <linux/timer.h>
#include <drm/drm_vma_manager.h>
#include "jmgpu_enc.h"
#include <linux/irq.h>
#include <linux/delay.h>
#include "jmgpu_pipeline.h"
#include "jmgpu_livelock.h"
#include "jmgpu_nemyry.h"

static u32 resource_shared;

#ifndef USE_DTB_PROBE
#define J9_HETEROPHILIC 0


#define J9_HANDLE_J9MENU_PRENEGLECT 0



#define J9_UNDERCELLARER 0x920000
#define J9_SOMNILOQUENCE (500 * 4)

#define J9_SCRIBBLEMANIA 0x185538000
#define J9_QUASIPARTICLE (500 * 4)


#define J9_INFUNDIBULATE 0x18553c000
#define J9_SKIAGRAPHICAL (500 * 4)



#define J9_PREINSCRIBING 0x285539000
#define J9_REPROVABILITY (500 * 4)

#define J9_RISORGIMENTOS 0x285538000
#define J9_MONONUCLEOSIS (500 * 4)


#define J9_INSENSITIVITY 0x28553c000
#define J9_SUBSTANTIATOR (500 * 4)



#define J9_MNEMOTECHNICS 0x385539000
#define J9_LEUCOCHALCITE (500 * 4)

#define J9_NONREDEMPTIVE 0x385538000
#define J9_HEPATECTOMIES (500 * 4)


#define J9_CHLOROCALCITE 0x38553c000
#define J9_BICONCAVITIES (500 * 4)



#define J9_UNPROGRESSIVE 0x485539000
#define J9_POLYPROTHETIC (500 * 4)

#define J9_INDESCRIBABLE 0x485538000
#define J9_PSYCHOGNOSTIC (500 * 4)


#define J9_UNDEROFFICIAL 0x48553c000
#define J9_VULGARIZATION (500 * 4)

#define J9_STULTIFYING -1
#define J9_EXENTERATED -1
#define J9_NONEGOISTIC -1



static CORE_CONFIG core_array[] = {
	{ J9_UNDERCELLARER, J9_SOMNILOQUENCE, J9_STULTIFYING,
	  J9_HANDLE_J9MENU_PRENEGLECT, 0 },
};
#endif

#define J9_HANDLE_J9_TRIPSOMELY 215
#define J9_HANDLE_J9M_ARROWSTONE 219
#define J9_COMMERCIALISM 16

#define VM_ENC_VREG_PT 0x0
#define VM_ENC_VREG_BUF 0x1
#define VM_ENC_VREG_ZERO_COPY 0x2

static int bencprobed;
static int enc_vreg_type = VM_ENC_VREG_PT;







static int j9_uplane(struct j9_aarrgh *pcore);
static void j9_superb(struct j9_aarrgh *pcore);
static void j9_fueler(struct j9_aarrgh *dev);
static int j9mirror_quasiorder(struct j9_aarrgh *dev);
static void j9_retroflexed(struct j9_aarrgh *dev, u32 *core_info,
			   u32 nodenum);
static int j9_cybernetically(void *priv);
static int j9_remonstrative(void *priv);
static const j9_petting jmgpu_enc_pmops = {
	.suspend = j9_cybernetically,
	.resume  = j9_remonstrative,
};


#if KERNEL_VERSION(2, 6, 18) > LINUX_VERSION_CODE
static irqreturn_t j9_diphtheric(int irq, void *dev_id, struct pt_regs *regs);
#else
static irqreturn_t j9_diphtheric(int irq, void *dev_id);
#endif


unsigned long long sram_base;
unsigned int sram_size;

static int j9_citronwood;


static inline void enc_write_vreg_swreg5(struct j9_aarrgh *pcore, u32 val)
{
	if (enc_vreg_type == VM_ENC_VREG_ZERO_COPY) {
		iowrite32(val, pcore->hwregs + VM_ENC_REG5_EMU_REG);
	} else if (enc_vreg_type == VM_ENC_VREG_BUF) {
		iowrite32(val, pcore->hwregs_ext + 0x14);
	}
}

static int j9_unsounding(u32 slice_idx, u32 core_id, u32 core_type,
	u32 offset, u32 val)
{
	struct j9_aarrgh *pcore = get_encnodes(slice_idx, core_id);

	if (!pcore)
		return -1;

	if (core_type >= CORE_TYPE_MAX)
		return -1;

	if (jmgpu_running_on_virt_mdev()) {

		if ((offset == 0x14) && (val & 0x1) && enc_vreg_type) {
			enc_write_vreg_swreg5(pcore, val);
			return 0;
		}
	}

	iowrite32(val, pcore->hwregs + pcore->core_info.offset[core_type] + offset);

	return 0;
}

static int j9_piggyback(u32 slice_idx, u32 core_id, u32 core_type,
	u32 offset, u32 *val)
{
	struct j9_aarrgh *pcore = get_encnodes(slice_idx, core_id);

	if (!pcore)
		return -1;

	if (core_type >= CORE_TYPE_MAX)
		return -1;

	*val = ioread32(pcore->hwregs + pcore->core_info.offset[core_type] + offset);

	return 0;
}

static int forceRelaseEnc(void)
{
	struct j9_aarrgh *pcore = get_encnodes(0, 0);

	if (jmgpu_running_on_virt_mdev()) {
		uint32_t val = 0x100;
		J9OUI_("[%s]\n", __func__);
		iowrite32(val, (void *)(pcore->hwregs + VM_REG_RESERVE_ENC));
	}
	return 0;
}

static int j9_infinite(struct j9_aarrgh *dev, u32 *core_info,
	u32 *irq_status, u32 nodenum)
{
	unsigned long flags;
	int rdy = 0;
	u32 i = 0;
	u8 core_mapping = 0;
	struct slice_info *parentslice = getparentslice(dev, JMD_HD_CORE_ENC);

	core_mapping = (u8)(*core_info & 0xFF);


	while (core_mapping) {
		if (core_mapping & 0x1) {
			if (i >= nodenum)
				break;

			spin_lock_irqsave(&parentslice->enc_owner_lock, flags);

			if (dev->irq_received) {

				J9OUI_("check %d irq ready\n", i);
				dev->irq_received = 0;
				rdy = 1;
				*core_info = i;
				*irq_status = dev->irq_status;
			}

			spin_unlock_irqrestore(&parentslice->enc_owner_lock,
					       flags);
			break;
		}
		core_mapping = core_mapping >> 1;
		i++;
		dev = dev->next;
	}

	return rdy;
}

static int j9_handle_onwardness(struct j9_aarrgh *dev, u32 *irq_status)
{
	unsigned long flags;
	int rdy = 0;
	u32 irq, hwId, majorId, wClr;
	u32 loop = 3000;

	struct slice_info *parentslice = getparentslice(dev, JMD_HD_CORE_ENC);

	do {
		spin_lock_irqsave(&parentslice->enc_owner_lock, flags);

		if (dev->irq_received) {
			J9OUI_("check %d irq ready\n", loop);
			dev->irq_received = 0;
			rdy = 1;
			*irq_status = dev->irq_status;
			goto end_1;
		}

		irq = (u32)ioread32((void *)(dev->hwregs + 0x04));


		if (irq & J9_DISINTRICATE) {
			if (irq & 0x20)
				iowrite32(0, (void *)(dev->hwregs + 0x14));

			hwId = ioread32((void *)dev->hwregs);
			majorId = (hwId & 0x0000FF00) >> 8;
			wClr = (majorId >= 0x61) ? irq : (irq & (~0x1FD));
			iowrite32(wClr, (void *)(dev->hwregs + 0x04));

			rdy = 1;
			*irq_status = irq;
			dev->irq_received = 0;
			dev->irq_status = irq;

			goto end_1;
		}

		spin_unlock_irqrestore(&parentslice->enc_owner_lock, flags);
		usleep_range(1000, 1100);
	} while (loop--);
	goto end_2;

end_1:
	spin_unlock_irqrestore(&parentslice->enc_owner_lock, flags);
end_2:
	return rdy;
}

static unsigned int j9_overmerit(struct j9_aarrgh *dev, u32 *core_info,
				 u32 *irq_status, u32 nodenum)
{
	struct slice_info *parentslice = getparentslice(dev, JMD_HD_CORE_ENC);

	int ret = -1;
	ret = wait_event_interruptible_timeout(parentslice->enc_wait_queue, j9_infinite(dev, core_info, irq_status, nodenum), 300);
	if (-ERESTARTSYS == ret) {
		J9OUI_("ENC wait_event_interruptible interrupted\n");
		j9_retroflexed(dev, core_info, nodenum);
		return -ERESTARTSYS;
	} else if (0 == ret) {
		J9OUI_("ENC wait_event_interruptible timeout\n");
		j9_retroflexed(dev, core_info, nodenum);
		return -ERESTARTSYS;
	} else if (1 <= ret) {
		J9OUI_("ENC wait_event_interruptible ready\n");
		return 0;
	} else {
		j9_retroflexed(dev, core_info, nodenum);
		return -1;
	}
}

static int j9_subrogation(struct j9_aarrgh *dev, CORE_WAIT_OUT *out)
{
	int rdy = 0;
	u32 i = 0;

	while ((dev) && (out->irq_num < J9_UNKET)) {
		if (1 ==
		    j9_handle_onwardness(dev, &out->irq_status[out->irq_num])) {

			J9OUI_("check %d irq ready\n", i);
			out->irq_status[out->irq_num] = dev->irq_status;
			out->job_id[out->irq_num] = dev->core_id;
			out->irq_num++;
			rdy = 1;
		}
		i++;
		dev = dev->next;
	}
	return rdy;
}

static unsigned int j9_astigmometry(struct j9_aarrgh *dev, CORE_WAIT_OUT *out)
{
	struct slice_info *parentslice = getparentslice(dev, JMD_HD_CORE_ENC);

	int ret = -1;
	ret = wait_event_interruptible_timeout(parentslice->enc_wait_queue, j9_subrogation(dev, out), 300);
	if (-ERESTARTSYS == ret) {
		J9OUI_("ENC wait_event_interruptible interrupted\n");
		return -ERESTARTSYS;
	} else if (0 == ret) {
		J9OUI_("ENC wait_event_interruptible timeout\n");
		return -ERESTARTSYS;
	} else if (1 <= ret) {
		J9OUI_("ENC wait_event_interruptible ready\n");
		return 0;
	} else {
		return -1;
	}
}

u32 j9_handle_j9_lionizable(int sliceidx, int isreadBW)
{
	int i, slicen = get_slicenumber();
	u32 bandwidth = 0;
	struct j9_aarrgh *pcore;
	u8 *rregs;
	u8 *wregs;

	if (sliceidx < 0) {
		for (i = 0; i < slicen; i++) {
			pcore = get_encnodes(i, 0);
			while (pcore) {
				rregs = pcore->hwregs +
					J9_HANDLE_J9_TRIPSOMELY * 4;
				wregs = pcore->hwregs +
					J9_HANDLE_J9M_ARROWSTONE * 4;
				if (isreadBW)
					bandwidth += ioread32((void *)rregs);
				else
					bandwidth += ioread32((void *)wregs);
				pcore = pcore->next;
			}
		}
	} else {
		pcore = get_encnodes(sliceidx, 0);
		while (pcore) {
			rregs = pcore->hwregs + J9_HANDLE_J9_TRIPSOMELY * 4;
			wregs = pcore->hwregs + J9_HANDLE_J9M_ARROWSTONE * 4;
			if (isreadBW)
				bandwidth += ioread32((void *)rregs);
			else
				bandwidth += ioread32((void *)wregs);
			pcore = pcore->next;
		}
	}
	return bandwidth * J9_COMMERCIALISM;
}

static int j9mirror_quasiorder(struct j9_aarrgh *dev)
{
	int ret = 0;
	unsigned long flags;
	struct slice_info *parentslice = getparentslice(dev, JMD_HD_CORE_ENC);

	spin_lock_irqsave(&parentslice->enc_owner_lock, flags);
	if (!dev->is_reserved) {
		dev->is_reserved = 1;
		dev->pid = current->tgid;
		ret = 1;
		J9OUI_("%s pid=%d\n", __func__, dev->pid);
	}

	spin_unlock_irqrestore(&parentslice->enc_owner_lock, flags);

	return ret;
}

static int j9_homomorphous(struct j9_aarrgh *dev, u32 *core_info,
			   u32 *core_info_tmp, u32 nodenum)
{
	int ret = 0;
	u32 i = 0;
	u32 cores;
	u8 core_type = 0;
	u32 required_num = 0;

	cores = *core_info;
	required_num = ((cores >> J9_HANDLE_J9_PREPROMISE) & 0x7) + 1;
	core_type = (u8)(cores & 0xFF);

	if (*core_info_tmp == 0)
		*core_info_tmp = required_num << J9_HANDLE_J9_PREPROMISE;
	else
		required_num = (*core_info_tmp >> J9_HANDLE_J9_PREPROMISE);

	J9OUI_("%s:required_num=%d,core_info=%x\n", __func__, required_num,
	       *core_info);

	if (required_num) {

		for (i = 0; i < nodenum; i++) {
			if (j9mirror_quasiorder(dev)) {
				*core_info_tmp = ((((*core_info_tmp >>
						     J9_HANDLE_J9_PREPROMISE) -
						    1)
						   << J9_HANDLE_J9_PREPROMISE) |
						  (*core_info_tmp & 0x0FF));
				*core_info_tmp = (*core_info_tmp | (1 << i));
				if ((*core_info_tmp >>
				     J9_HANDLE_J9_PREPROMISE) == 0) {
					ret = 1;
					*core_info = (dev->core_id << 16) |
						     (*core_info_tmp & 0xFF);
					required_num = 0;
					break;
				}
			}
			dev = dev->next;
		}
	} else {
		ret = 1;
	}

	J9OUI_("*core_info = %x\n", *core_info);
	return ret;
}

static long j9_pamphletize(struct j9_aarrgh *dev, u32 *core_info, u32 nodenum)
{
	struct slice_info *parentslice = getparentslice(dev, JMD_HD_CORE_ENC);
	u32 core_info_tmp = 0;
	if (resource_shared) {
		if (down_interruptible(&parentslice->enc_core_sem))
			return -ERESTARTSYS;
	}


	if (wait_event_interruptible(parentslice->enc_hw_queue,
				     j9_homomorphous(dev, core_info,
						     &core_info_tmp,
						     nodenum) != 0))
		return -ERESTARTSYS;

	return 0;
}

static void j9_retroflexed(struct j9_aarrgh *dev, u32 *core_info, u32 nodenum)
{
	unsigned long flags;
	u32 core_num = 0;
	u32 i = 0, core_id;
	u8 core_mapping = 0;
	struct slice_info *parentslice = getparentslice(dev, JMD_HD_CORE_ENC);

	core_num = ((*core_info >> J9_HANDLE_J9_PREPROMISE) & 0x7) + 1;

	core_mapping = (u8)(*core_info & 0xFF);

	J9OUI_("%s:core_num=%d,core_mapping=%x\n", __func__, core_num,
	       core_mapping);

	while (core_mapping) {
		if (core_mapping & 0x1) {
			if (i >= nodenum)
				break;
			core_id = i;
			spin_lock_irqsave(&parentslice->enc_owner_lock, flags);
			J9OUI_("dev[%d].pid=%d,current->tgid=%d\n", core_id,
			       dev->pid, current->tgid);
			if (dev->is_reserved) {
				dev->pid = -1;
				dev->is_reserved = 0;
				dev->irq_received = 0;
				dev->irq_status = 0;
			}
			spin_unlock_irqrestore(&parentslice->enc_owner_lock,
					       flags);


		}
		core_mapping = core_mapping >> 1;
		i++;
		dev = dev->next;
	}

	wake_up_interruptible_all(&parentslice->enc_hw_queue);

	if (resource_shared)
		up(&parentslice->enc_core_sem);
}

long j9_pseudography(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned int tmp;
	struct j9_aarrgh *pcore;
	u32 core_info;
	jmu_hd_ioctl_id ioctl_id_par;
	int ret;
	u64 par;

	switch (cmd) {
	case J9_HANDLE_J_FLIMSILYST: {
		__get_user(par, (u64 *)arg);

		ioctl_id_par.data = (u32)par;
		pcore = get_encnodes(ioctl_id_par.ID_PAR.node_idx,
				     ioctl_id_par.ID_PAR.codec_idx);
		if (!pcore)
			return -EFAULT;

		__put_user(pcore->core_cfg.base_addr, (u64 *)arg);
		break;
	}

	case J9_HANDLE_J_SUPERDUPER: {
		u32 io_size;

		__get_user(ioctl_id_par.data, (u32 *)arg);

		pcore = get_encnodes(ioctl_id_par.ID_PAR.node_idx,
				     ioctl_id_par.ID_PAR.codec_idx);
		if (!pcore)
			return -EFAULT;
		io_size = pcore->core_cfg.iosize;

		__put_user(io_size, (u32 *)arg);
		return 0;
	}
	case J9_HANDLE_J9M_CLINICIANS:
		__put_user(sram_base, (u64 *)arg);
		break;
	case J9_HANDLE_J9MA_TRAVERSALS:
		__put_user(sram_size, (u32 *)arg);
		break;
	case J9_HANDLE_J9_CENTERMOST:
		tmp = arg;
		return get_slicecorenum(tmp, JMD_HD_CORE_ENC);
	case J9_HANDLE_J9MIN_PREBENDATE: {
		struct nor32_parameter core_info;

		J9OUI_("Reserve ENC Cores\n");
		ret = copy_from_user(&core_info, (void *)arg,
				     sizeof(struct nor32_parameter));
		if (ret)
			return ret;
		ioctl_id_par.data = core_info.id;
		pcore = get_encnodes(ioctl_id_par.ID_PAR.node_idx, 0);
		if (!pcore)
			return -EFAULT;
		tmp = get_slicecorenum(ioctl_id_par.ID_PAR.node_idx,
				       JMD_HD_CORE_ENC);
		ret = j9_pamphletize(pcore, (u32 *)&core_info.data, tmp);
		if (ret)
			return ret;
		if (jmgpu_running_on_virt_mdev()) {
			uint32_t val = (core_info.id << 16) | (core_info.data << 8) | 0x1;
			iowrite32(val, (void *)(pcore->hwregs + VM_REG_RESERVE_ENC));

		}

		if (ret == 0) {
			ret = copy_to_user((void *)arg, &core_info,
					   sizeof(struct nor32_parameter));
		}
		return ret;
	}
	case J9_HANDLE_J9MIN_INSURRECTO: {
		struct nor32_parameter core_cfg;

		ret = copy_from_user(&core_cfg, (void *)arg,
				     sizeof(struct nor32_parameter));
		if (ret)
			return ret;
		ioctl_id_par.data = core_cfg.id;
		pcore = get_encnodes(ioctl_id_par.ID_PAR.node_idx, 0);
		if (!pcore)
			return -EFAULT;
		J9OUI_("Release ENC Core\n");
		tmp = get_slicecorenum(ioctl_id_par.ID_PAR.node_idx,
				       JMD_HD_CORE_ENC);
		if (jmgpu_running_on_virt_mdev()) {
			uint32_t val = (core_cfg.id << 16) | (core_cfg.data << 8) | 0x0;
			iowrite32(val, (void *)(pcore->hwregs + VM_REG_RESERVE_ENC));
		}

		j9_retroflexed(pcore, (u32 *)&core_cfg.data, tmp);

		break;
	}

	case J9_HANDLE_J9M_UNDERREALM: {
		struct nor32_parameter core_cfg;

		ret = copy_from_user(&core_cfg, (void *)arg,
				     sizeof(struct nor32_parameter));
		if (ret)
			return ret;
		ioctl_id_par.data = core_cfg.id;
		pcore = get_encnodes(ioctl_id_par.ID_PAR.node_idx, 0);
		if (!pcore)
			return -EFAULT;
		tmp = get_slicecorenum(ioctl_id_par.ID_PAR.node_idx,
				       JMD_HD_CORE_ENC);

		core_info = core_cfg.data;
		tmp = j9_overmerit(pcore, &core_info, (u32 *)&core_cfg.data,
				   tmp);
		if (tmp == 0) {
			ret = copy_to_user((void *)arg, &core_cfg,
					   sizeof(struct nor32_parameter));
			return core_info;
		}
		ret = copy_to_user((void *)arg, &core_cfg,
				   sizeof(struct nor32_parameter));
		return -1;

		break;
	}

	case J9_HANDLE_J9M_BALLASTING: {

		SUBSYS_CORE_INFO in_data;

		ret = copy_from_user(&in_data, (void *)arg,
				     sizeof(SUBSYS_CORE_INFO));
		if (ret)
			return ret;
		ioctl_id_par.data = in_data.id;
		pcore = get_encnodes(ioctl_id_par.ID_PAR.node_idx, 0);
		if (!pcore)
			return -EFAULT;

		ret = copy_to_user((void *)arg, &pcore->core_info,
				     sizeof(SUBSYS_CORE_INFO));
		return ret;
		break;
	}
	case J9_HANDLE_J9MENU_POLYGAMIAN: {
		CORE_WAIT_OUT out;

		ret = copy_from_user((void *)(&out), (void *)arg,
				     sizeof(CORE_WAIT_OUT));
		if (ret)
			return ret;
		ioctl_id_par.data = out.id;

		pcore = get_encnodes(ioctl_id_par.ID_PAR.node_idx, 0);
		tmp = j9_astigmometry(pcore, &out);
		if (tmp == 0) {
			ret = copy_to_user((void *)arg, &out,
					   sizeof(CORE_WAIT_OUT));
			return ret;
		} else {
			return -1;
		}

		break;
	}
	case J9_HANDLE_DELINEAVIT:
		return jmgpu_hd_dev.config;
	case J9_HANDLE_J9M_COMMANDERY:
		return get_slicenumber();
	case J9_HANDLE_J9_BALLASTING: {
		j9_unperforate reg;

		ret = copy_from_user(&reg, (void *)arg, sizeof(reg));
		if (ret)
			return ret;

		ret = j9_piggyback(reg.slice_idx,
				reg.core_id,
				reg.core_type,
				reg.offset,
				&reg.val);
		if (ret)
			return ret;

		put_user(reg.val, &((j9_unperforate *)arg)->val);
		break;
	}
	case J9_HANDLE_J9M_HARBOUROUS: {
		j9_unperforate reg;

		ret = copy_from_user(&reg, (void *)arg, sizeof(reg));
		if (ret)
			return ret;

		return j9_unsounding(reg.slice_idx,
				reg.core_id,
				reg.core_type,
				reg.offset,
				reg.val);
	}
	}
	return 0;
}

int j9_radiostrontium(void)
{
	struct slice_info *parentslice;
	int i, slicen = get_slicenumber();
	struct j9_aarrgh *dev;
	unsigned long flags;

	for (i = 0; i < slicen; i++) {
		dev = get_encnodes(i, 0);
		if (!dev)
			continue;
		parentslice = getparentslice(dev, JMD_HD_CORE_ENC);
		while (dev) {
			spin_lock_irqsave(&parentslice->enc_owner_lock, flags);
			if (dev->is_reserved == 1 && dev->pid == current->tgid) {
				dev->pid = -1;
				dev->is_reserved = 0;
				dev->irq_received = 0;
				dev->irq_status = 0;
				forceRelaseEnc();
				pr_info("release reserved core\n");
			}
			spin_unlock_irqrestore(&parentslice->enc_owner_lock,
					       flags);
			dev = dev->next;
		}
		wake_up_interruptible_all(&parentslice->enc_hw_queue);
		if (resource_shared)
			up(&parentslice->enc_core_sem);
	}
	return 0;
}

int j9_railroaders(struct pci_dev *pdev)
{
	sram_base = 0;
	sram_size = 0;
	j9_citronwood = 0;
	resource_shared = 0;
	bencprobed = 0;
	return j9_cumbersome(pdev, &jmgpu_enc_pmops, pdev, "encoder");
}

static int j9_cybernetically(void *priv)
{
	int i, j, k, coren;
	u32 *regs;
	u32 nregs;

	for (i = 0; i < get_slicenumber(); i++) {
		coren = get_slicecorenum(i, JMD_HD_CORE_ENC);
		for (k = 0; k < coren; k++) {
			struct j9_aarrgh *encnode = get_encnodes(i, k);

			if (!encnode)
				break;

			if (!encnode->hwregs)
				continue;

			nregs = encnode->core_cfg.iosize / 4;
			regs = kmalloc(nregs * 4, GFP_KERNEL);
			if (!regs) {
				pr_warn("[jmgpu] out of memory, encoder state not saved");
				return 0;
			}
			for (j = 1; j < nregs; j++)
				regs[j] = ioread32((void *)encnode->hwregs + j * 4);

			encnode->reg_state = regs;
		}
	}

	return 0;
}

static int j9_remonstrative(void *priv)
{
	int i, j, k, coren;
	u32 *regs;
	u32 nregs;

	for (i = 0; i < get_slicenumber(); i++) {
		coren = get_slicecorenum(i, JMD_HD_CORE_ENC);
		for (k = 0; k < coren; k++) {
			struct j9_aarrgh *encnode = get_encnodes(i, k);

			if (!encnode)
				break;

			if (!encnode->hwregs)
				continue;

			j9_fueler(encnode);

			msleep(20);

			if (!encnode->reg_state)
				continue;

			nregs = encnode->core_cfg.iosize / 4;
			regs  = encnode->reg_state;
			for (j = 1; j < nregs; j++)
				iowrite32(regs[j], (void *)encnode->hwregs + j * 4);
			kfree(regs);
			encnode->reg_state = NULL;
		}
	}

	return 0;
}

static int jmgpu_enc_alloc_vreg(struct device *dev, struct j9_aarrgh *penccore)
{
	void *vaddr;
	dma_addr_t dma;
	u32 size;

	size = penccore->core_info.regSize[CORE_ENC] + VM_REG_ENC_EXTRA_SIZE,
	vaddr = dmam_alloc_coherent(dev, size, &dma,
			GFP_KERNEL | GFP_DMA32);
	if (!vaddr) {
		pr_err("jmgpu_venc: failed to allocate register buffer for vm\n");
		return -ENOMEM;
	} else {
		pr_info("jmgpu_venc: vreg buffer, physical addr: 0x%llx, bus addr: 0x%llx, vaddr:%p, size:%u",
			(u64)__pa(vaddr), dma, vaddr, size);
		penccore->hwregs_ext = penccore->hwregs;
		penccore->hwregs = vaddr;
		penccore->vreg_dma_addr = dma;
		iowrite32(penccore->vreg_dma_addr,
			penccore->hwregs_ext + VM_REG_MEM_ADDR_ENC);
	}
	return 0;
}

static int jmgpu_check_vreg_type(struct j9_aarrgh *pcore)
{
	uint32_t val;
	int ret;

	val = (u32)ioread32((void *)pcore->hwregs + VM_REG_MEM_ADDR_ENC);
	if (val == J9_UNDERCELLARER) {
		pr_info("jmgpu_enc: vreg type is zero-copy\n");
		ret = VM_ENC_VREG_ZERO_COPY;
	} else if (val == (J9_UNDERCELLARER | 0xffff)) {
		pr_info("jmgpu_enc: vreg type is copy-buffer\n");
		ret = VM_ENC_VREG_BUF;
	} else {
		pr_info("jmgpu_enc: vreg type is pass-through\n");
		ret = VM_ENC_VREG_PT;
	}
	return ret;
}

int j9_predigesting(dtbnode *pnode, int useirq, int loop,
		    struct j9_aarrgh *penccore, struct pci_dev *pdev,
		     j9_weakliest *pplatform)
{
	int result = 0;
	struct j9_aarrgh *pcore;
	int i, k;

	if (loop == 0) {
#ifndef USE_DTB_PROBE
		for (i = 0; i < ARRAY_SIZE(core_array); i++) {
			pcore = vmalloc(sizeof(*pcore));
			if (!pcore)
				break;

			memset(pcore, 0, sizeof(struct j9_aarrgh));
			pcore->core_cfg.base_addr = core_array[i].base_addr;
			pcore->core_cfg.iosize = core_array[i].iosize;
			pcore->core_cfg.sliceidx = core_array[i].sliceidx;
			for (k = 0; k < 4; k++)
				pcore->irqlist[k] = -1;
			pcore->irqlist[0] = core_array[i].irq;
			pcore->irqlist[0] = pdev->irq;

			pcore->core_info.type_info |= CORE_ENC;
			pcore->core_info.offset[CORE_ENC] = 0;
			pcore->core_info.regSize[CORE_ENC] = pcore->core_cfg.iosize;
			pcore->core_info.irq[CORE_ENC] = pcore->irqlist[0];

			add_encnode(pcore->core_cfg.sliceidx, pcore);
		}
#else
		{
			pcore = vmalloc(sizeof(*pcore));
			if (!pcore)
				return -ENOMEM;

			memset(pcore, 0, sizeof(struct j9_aarrgh));
			pcore->core_cfg.base_addr = pnode->ioaddr;
			pcore->core_cfg.iosize = pnode->iosize;
			pcore->core_cfg.sliceidx = pnode->sliceidx;
			for (i = 0; i < 4; i++)
				pcore->irqlist[i] = -1;
			pcore->irqlist[0] = pnode->irq[0];

			pcore->core_info.type_info |= CORE_ENC;
			pcore->core_info.offset[CORE_ENC] = 0;
			pcore->core_info.regSize[CORE_ENC] = pcore->core_cfg.iosize;
			pcore->core_info.irq[CORE_ENC] = pcore->irqlist[0];

			add_encnode(pnode->sliceidx, pcore);
		}
#endif
	} else {
		enc_vreg_type = jmgpu_check_vreg_type(penccore);
		if (jmgpu_running_on_virt_mdev() && (enc_vreg_type == VM_ENC_VREG_BUF)) {
			result = jmgpu_enc_alloc_vreg(&pdev->dev, penccore);
			if (result < 0)
				return -ENOMEM;
		}

		result = j9_uplane(penccore);
		if (result < 0) {
			pr_info("hx280enc: reserve reg 0x%llx-0x%lx fail\n",
			       penccore->core_cfg.base_addr,
			       penccore->core_info.regSize[CORE_ENC]);
			return result;
		}

		if (!jmgpu_running_on_virt_mdev())
			j9_fueler(penccore);
#if J9_HETEROPHILIC
		result = pplatform->ops->requestIrq(pplatform,
				J9_HANDLE_J9MIN_FORTEMENTE,
				j9_froggery,
				"encodeirq",
				penccore);
		if (!result)
		else
			pr_info("irq not enabled");
		}
#endif
	}

	return 0;
}

void j9_hepatocellular(j9_gearshifts *pcie_info)
{
	int i, slicen = get_slicenumber();
	struct j9_aarrgh *pcore, *pnext;
	j9_atlantomastoid *ppcie_platform;

	ppcie_platform = container_of(pcie_info, j9_atlantomastoid, pcie_info);

	for (i = 0; i < slicen; i++) {
		pcore = get_encnodes(i, 0);
		while (pcore) {
			u32 hwId = pcore->hw_id;
			u32 majorId = (hwId & 0x0000FF00) >> 8;
			u32 wClr = (majorId >= 0x61) ? (0x1FD) : (0);

			pnext = pcore->next;
			iowrite32(0, (void *)(pcore->hwregs +
					      0x14));
			iowrite32(wClr, (void *)(pcore->hwregs +
						 0x04));


			ppcie_platform->base.ops->freeIrq(&(ppcie_platform->base),
				J9_HANDLE_J9MIN_FORTEMENTE, pcore);
			j9_superb(pcore);
			vfree(pcore);
			pcore = pnext;
		}
	}
	bencprobed = 0;
	j9_handle_j9_incommixed();
	pr_info("jmgpuenc: module removed\n");
}

static int j9_uplane(struct j9_aarrgh *pcore)
{
	u32 hwid;


	hwid = (u32)ioread32((void *)pcore->hwregs);


	if (((((hwid >> 16) & 0xFFFF) != ((J9_EXILING >> 16) & 0xFFFF))) &&
	    ((((hwid >> 16) & 0xFFFF) != ((J9_TOUTING >> 16) & 0xFFFF)))) {
		pr_info("jmgpuenc: HW not found at %llx\n",
			pcore->core_cfg.base_addr);
		j9_superb(pcore);
		return -1;
	}
	pcore->hw_id = hwid;

	return 0;
}

static void j9_superb(struct j9_aarrgh *pcore)
{
}

#if KERNEL_VERSION(2, 6, 18) > LINUX_VERSION_CODE
static irqreturn_t j9_froggery(int irq, void *dev_id, struct pt_regs *regs)
#else
static irqreturn_t j9_froggery(int irq, void *dev_id)
#endif
{
	unsigned int handled = 0;
	struct j9_aarrgh *dev = (struct j9_aarrgh *)dev_id;
	u32 irq_status;
	unsigned long flags;
	struct slice_info *parentslice = getparentslice(dev, JMD_HD_CORE_ENC);


	spin_lock_irqsave(&parentslice->enc_owner_lock, flags);
	if (!dev->is_reserved) {
		pr_info("j9_froggery:received IRQ but core is not reserved!\n");
		irq_status = (u32)ioread32((void *)(dev->hwregs + 0x04));
		if (irq_status & 0x01) {
			u32 hwId = ioread32((void *)dev->hwregs);
			u32 majorId = (hwId & 0x0000FF00) >> 8;
			u32 wClr = (majorId >= 0x61) ? irq_status :
						       (irq_status & (~0x1FD));

			if (irq_status & 0x20)
				iowrite32(0, (void *)(dev->hwregs + 0x14));
			iowrite32(wClr, (void *)(dev->hwregs + 0x04));
		}
		spin_unlock_irqrestore(&parentslice->enc_owner_lock, flags);
		return IRQ_HANDLED;
	}
	spin_unlock_irqrestore(&parentslice->enc_owner_lock, flags);

	irq_status = (u32)ioread32((void *)(dev->hwregs + 0x04));

	if (irq_status & 0x01) {
		u32 hwId = ioread32((void *)dev->hwregs);
		u32 majorId = (hwId & 0x0000FF00) >> 8;
		u32 wClr = (majorId >= 0x61) ? irq_status :
					       (irq_status & (~0x1FD));

		if (irq_status & 0x20)
			iowrite32(0, (void *)(dev->hwregs + 0x14));
		iowrite32(wClr, (void *)(dev->hwregs + 0x04));
		spin_lock_irqsave(&parentslice->enc_owner_lock, flags);
		dev->irq_received = 1;
		dev->irq_status = irq_status & (~0x01);
		spin_unlock_irqrestore(&parentslice->enc_owner_lock, flags);

		wake_up_interruptible_all(&parentslice->enc_wait_queue);
		handled++;
	}
	if (!handled)
		pr_info("IRQ received, but not hd enc's!\n");

	return IRQ_HANDLED;
}

static void j9_fueler(struct j9_aarrgh *dev)
{
	int i;

#ifndef SIMICS_TEST
	iowrite32(0, (void *)(dev->hwregs + 0x14));
	for (i = 4; i < dev->core_info.regSize[CORE_ENC]; i += 4)
		iowrite32(0, (void *)(dev->hwregs + i));
#endif
}


