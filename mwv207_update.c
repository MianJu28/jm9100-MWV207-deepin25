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



#include <linux/delay.h>
#include "mwv207reg_procedure.h"
#include "jmgpu_software.h"
#include "jmgpu_livelock.h"
#include "mwv207_update.h"
#include "mwv207_boolean.h"
#include "mwv207_method.h"
#include "mwv207_driver.h"
#include "jmgpu_nemyry.h"


#define J9MIRROR_INIMITABLY   0x10000


#define J9_HANDLE_J9M_ATTRIBUTE_PALEOSTYLY          0x100
#define J9_HANDLE_J9M_ATTRIBUTE_PICHICIAGO          0x104
#define J9_HANDLE_ATTRIBUTE_BEHAVIOUR_40000    0x114
#define J9_HANDLE_ATTRIBUTE_BEHAVIOUR_UNABLENESS    0x118

#define J9_HANDLE_J9_ATTRIBUTE_OVEREXPAND           0x108
#define J9_HANDLE_J9_ATTRIBUTE_BALLBUSTER           0x10C
#define J9_HANDLE_J9M_ATTRIBUTE_TIMBERLIKE          0x110
#define J9_HANDLE_J9MA_ATTRIBUTE_CROSSBENCH         0x11C
#define J9_HANDLE_J9M_ATTRIBUTE_PATHOMANIA          0x120


#define J9_HANDLE_J9MA_ATTRIBUTE_OVEREXPAND         0x000
#define J9_HANDLE_J9MA_ATTRIBUTE_BALLBUSTER         0x004
#define J9_HANDLE_J9M_ATTRIBUTE_CALCIFUGAL          0x008
#define J9_HANDLE_J9M_ATTRIBUTE_PHLEBOLOGY          0x00C
#define J9_HANDLE_J9M_ATTRIBUTE_OVEREXPAND          0x010
#define J9_HANDLE_J9MENU_ATTRIBUTE_HOUSESMITH       0x014
#define J9_HANDLE_J9MENU_ATTRIBUTE_CALCIFUGAL       0x018
#define J9_HANDLE_J9MIN_ATTRIBUTE_TIMBERLIKE        0x01C
#define J9_HANDLE_J9M_ATTRIBUTE_BALLBUSTER          0x020

#define J9_HANDLE_MILLIHENRY  8

typedef struct j9mirror_bluepoints {
	j9maths_ingeminate *pintctlr;
} j9_ecumenically;

#define j9_undutifully(ppcie_info) ((j9_ecumenically *)(ppcie_info)->pinfo->priv)

static int j9_phenomenal(void *priv);
static const j9_petting mwv207_pmops = {
	.resume = j9_phenomenal,
};

s32 j9_handle_attribute_interester(const j9_gearshifts *ppcie_info,
				   u32 regaddr, u32 val)
{
	if (regaddr < 0x1000)
		return pci_write_config_dword(ppcie_info->pdev, regaddr, val);
	else
		return j9_handle_subfigures(ppcie_info, regaddr, val);

}

s32 j9_handle_j9mirror_rhabdology(const j9_gearshifts *ppcie_info, u32 regaddr,
				  u32 *pval)
{
	if (regaddr < 0x1000)
		return pci_read_config_dword(ppcie_info->pdev, regaddr, pval);
	else
		return j9mirror_metrocarat(ppcie_info, regaddr, pval);

}

static void mwv207_3d_initiator_disable(j9_gearshifts *ppcie_info, int core_id)
{
	u32 offset, i;

	for (i = 0; i < 4; i++) {
		offset = 0x101060c + (0x100 * i) + (0x400 * core_id);
		j9_antiroyalist(ppcie_info, offset, 0x1);
		offset = 0x1010610 + (0x100 * i) + (0x400 * core_id);
		j9_antiroyalist(ppcie_info, offset, 0x0);
	}
}

static void mwv207_3d_initiator_enable(j9_gearshifts *ppcie_info, int core_id)
{
	u32 offset, i;

	for (i = 0; i < 4; i++) {
		offset = 0x101060c + (0x100 * i) + (0x400 * core_id);
		j9_antiroyalist(ppcie_info, offset, 0x3);
		offset = 0x1010610 + (0x100 * i) + (0x400 * core_id);
		j9_antiroyalist(ppcie_info, offset, 0x1000);
	}
}

static void mwv207_3d_reset(j9_gearshifts *ppcie_info, int core_id)
{
	u32 offset, val;

	mwv207_3d_initiator_disable(ppcie_info, core_id);

	offset = 0x9003A8 + (0x10000 * core_id);
	j9_antiroyalist(ppcie_info, offset, 0x1);

	msleep(300);

	j9_antiroyalist(ppcie_info, offset, 0x0);

	offset = 0x900004 + (0x10000 * core_id);
	j9_intercreate(ppcie_info, offset, &val);

	if (!(val & 0x1)) {
		pr_warn("[jmgpu] 3D core%d reset failed, idle %x\n", core_id, val);
	} else {
		pr_info("[jmgpu] 3D core%d reset done, idle %x\n", core_id, val);
	}

	mwv207_3d_initiator_enable(ppcie_info, core_id);
}


static void j9_corduroys(j9_gearshifts *ppcie_info)
{
	u32 reg;
	u8 i;

	pr_info("[jmgpu] software reset");

	if (j9mirror_personages() != JMV_VIRT_TYPE_PHYSICAL) {
		if (jmgpu_virt_support_3d_time_sharing(ppcie_info)) {

			return;
		}
		if (jmgpu_is_passthrough(ppcie_info, JM_GPU_3D0_BIT)) {
			mwv207_3d_reset(ppcie_info, 0);
		}

		if (ppcie_info->pinfo->has_gddr && jmgpu_is_passthrough(ppcie_info, JM_GPU_3D1_BIT)) {
			mwv207_3d_reset(ppcie_info, 1);
		}
	}

	for (i = 0; i < 4; i++) {
		reg = j9maths_prepiously + J9_AMBILATERALITY(i);
		j9_antiroyalist(ppcie_info, reg, 0);


		reg = j9_handle_j9min_undertribe + J9_AMBILATERALITY(i);
		j9_antiroyalist(ppcie_info, reg, 0);
		reg = j9_malalignment + J9_AMBILATERALITY(i);
		j9_antiroyalist(ppcie_info, reg, 2);

		reg = j9maths_prepiously + J9_AMBILATERALITY(i);
		j9_antiroyalist(ppcie_info, reg, 1);
	}



	j9_intercreate(ppcie_info, MWV207REG_TOP_NOC_ADDR, &reg);
	j9_antiroyalist(ppcie_info, MWV207REG_TOP_NOC_ADDR, reg & ~0x1cf);


	j9_intercreate(ppcie_info, MWV207REG_TOP_GU3D_ADDR, &reg);
	j9_antiroyalist(ppcie_info, MWV207REG_TOP_GU3D_ADDR, reg & ~0x30000);


	j9_intercreate(ppcie_info, MWV207REG_TOP_HD_ADDR, &reg);
	j9_antiroyalist(ppcie_info, MWV207REG_TOP_HD_ADDR, reg & ~0xf0000);


	j9_intercreate(ppcie_info, MWV207REG_TOP_GU2D_ADDR, &reg);
	j9_antiroyalist(ppcie_info, MWV207REG_TOP_GU2D_ADDR, reg & ~0x10000);



	j9_intercreate(ppcie_info, MWV207REG_TOP_NOC_ADDR, &reg);
	j9_antiroyalist(ppcie_info, MWV207REG_TOP_NOC_ADDR, reg | 0x1cf);


	j9_intercreate(ppcie_info, MWV207REG_TOP_GU3D_ADDR, &reg);
	j9_antiroyalist(ppcie_info, MWV207REG_TOP_GU3D_ADDR, reg | 0x30000);


	j9_intercreate(ppcie_info, MWV207REG_TOP_HD_ADDR, &reg);
	j9_antiroyalist(ppcie_info, MWV207REG_TOP_HD_ADDR, reg | 0xf0000);


	j9_intercreate(ppcie_info, MWV207REG_TOP_GU2D_ADDR, &reg);
	j9_antiroyalist(ppcie_info, MWV207REG_TOP_GU2D_ADDR, reg | 0x10000);

	msleep(10);
}

static void j9_handle__halophilic(j9_gearshifts *ppcie_info)
{
	u32 fw_state;

	j9_intercreate(ppcie_info, MWV207REG_TOP_FW_STATE_ADDR, &fw_state);
	pr_info("[jmgpu] firmware_state info: 0x%08x", fw_state);
}

static inline u32 j9_transmigrator(const j9_gearshifts *ppcie_info, u32 region,
				   u32 reg)
{
	u32 val;

	j9_handle_j9mirror_rhabdology(ppcie_info,
				      J9MIRROR_INIMITABLY +
				      region * J9_HANDLE_J9MA_AMIDSTREAM + reg,
				      &val);
	return val;
}

static inline void j9_aluminothermic(const j9_gearshifts *ppcie_info,
				     u32 region, u32 reg, u32 val)
{
	j9_handle_attribute_interester(ppcie_info,
				       J9MIRROR_INIMITABLY +
				       region * J9_HANDLE_J9MA_AMIDSTREAM + reg,
				       val);
}

static void j9_underhorsemen(j9_gearshifts *ppcie_info)
{
	u32 type, ctrl;
	u64 target;
	int i;

	for (i = 0; i < 16; ++i) {
		target =
		    j9_transmigrator(ppcie_info, i,
				     J9_HANDLE_ATTRIBUTE_BEHAVIOUR_UNABLENESS);
		target = target << 32;
		target +=
		    j9_transmigrator(ppcie_info, i,
				     J9_HANDLE_ATTRIBUTE_BEHAVIOUR_40000);
		type =
		    j9_transmigrator(ppcie_info, i,
				     J9_HANDLE_J9M_ATTRIBUTE_PALEOSTYLY);
		ctrl =
		    j9_transmigrator(ppcie_info, i,
				     J9_HANDLE_J9M_ATTRIBUTE_PICHICIAGO);
		pr_info("[jmgpu]: inbound region[%d]", i);
		pr_info("         target = 0x%llx", target);
		pr_info("         type   = 0x%x", type);
		pr_info("         ctrl   = 0x%x", ctrl);
	}
}

#define J9_HANDLE_CHRYSALINE(bar) ((J9_HANDLE__NOVICELIKE << J9_HANDLE_CUREMASTER) \
				  | (1 << J9_HANDLE_J_PREPERFECT)\
				  | ((bar) << J9_HANDLE_J_PRECONCEAL))
#define J9_HANDLE__FRACTIONED()  ((J9_HANDLE_J_BRAZENNESS << J9_HANDLE_CUREMASTER) \
				  | (1 << J9_HANDLE_J_PREPERFECT)\
				  | ((6) << J9_HANDLE_J_PRECONCEAL))


static int j9mirror_sturdiness(j9_gearshifts *ppcie_info, int bar, u64 target)
{
	volatile u32 check;

	j9_aluminothermic(ppcie_info, bar + J9_HANDLE_MILLIHENRY + 1,
			  J9_HANDLE_ATTRIBUTE_BEHAVIOUR_40000,
			  target & 0xffffffff);
	j9_aluminothermic(ppcie_info, bar + J9_HANDLE_MILLIHENRY + 1,
			  J9_HANDLE_ATTRIBUTE_BEHAVIOUR_UNABLENESS,
			  target >> 32);
	j9_aluminothermic(ppcie_info, bar + J9_HANDLE_MILLIHENRY + 1,
			  J9_HANDLE_J9M_ATTRIBUTE_PALEOSTYLY,
			  J9_HANDLE_RIFLEPROOF);
	j9_aluminothermic(ppcie_info, bar + J9_HANDLE_MILLIHENRY + 1,
			  J9_HANDLE_J9M_ATTRIBUTE_PICHICIAGO,
			  J9_HANDLE_CHRYSALINE(bar));

	check = j9_transmigrator(ppcie_info, bar + J9_HANDLE_MILLIHENRY + 1,
				 J9_HANDLE_J9M_ATTRIBUTE_PICHICIAGO);
	if (check != J9_HANDLE_CHRYSALINE(bar)) {
		pr_err("[jmgpu]: iatu map readback is inconsistant");
		return -1;
	}

	return 0;
}

static int j9_handle_j9ma_physicking(j9_gearshifts *ppcie_info, int region,
				     u64 base, u64 target, u64 size)
{
	volatile u32 check;


	j9_aluminothermic(ppcie_info, region,
			  J9_HANDLE_J9_ATTRIBUTE_OVEREXPAND, base & 0xffffffff);
	j9_aluminothermic(ppcie_info, region,
			  J9_HANDLE_J9_ATTRIBUTE_BALLBUSTER, base >> 32);

	j9_aluminothermic(ppcie_info, region,
			  J9_HANDLE_ATTRIBUTE_BEHAVIOUR_40000,
			  target & 0xffffffff);
	j9_aluminothermic(ppcie_info, region,
			  J9_HANDLE_ATTRIBUTE_BEHAVIOUR_UNABLENESS,
			  target >> 32);

	j9_aluminothermic(ppcie_info, region,
			  J9_HANDLE_J9M_ATTRIBUTE_TIMBERLIKE,
			  (base + size - 1) & 0xffffffff);

	j9_aluminothermic(ppcie_info, region,
			  J9_HANDLE_J9M_ATTRIBUTE_PALEOSTYLY,
			  J9_HANDLE_RIFLEPROOF);
	j9_aluminothermic(ppcie_info, region,
			  J9_HANDLE_J9M_ATTRIBUTE_PICHICIAGO,
			  J9_HANDLE__FRACTIONED());

	check =
	    j9_transmigrator(ppcie_info, region,
			     J9_HANDLE_J9M_ATTRIBUTE_PICHICIAGO);
	if (check != J9_HANDLE__FRACTIONED()) {
		pr_err("[jmgpu]: iatu map readback is inconsistant");
		return -1;
	}
	return 0;
}

static int j9_handle_j_frockmaker(j9_gearshifts *ppcie_info, int region,
				  u64 base, u64 target, u64 size)
{
	BUG_ON(region >= J9_HANDLE_MILLIHENRY);
	return j9_handle_j9ma_physicking(ppcie_info, region, base, target,
					 size);

}

static void j9_microtasimeter(j9_gearshifts *ppcie_info)
{
	volatile u32 check;
	int i;

	for (i = 0; i < 16; ++i) {
		j9_aluminothermic(ppcie_info, i,
				  J9_HANDLE_ATTRIBUTE_BEHAVIOUR_UNABLENESS, 0);
		j9_aluminothermic(ppcie_info, i,
				  J9_HANDLE_ATTRIBUTE_BEHAVIOUR_40000, 0);
		j9_aluminothermic(ppcie_info, i,
				  J9_HANDLE_J9M_ATTRIBUTE_PALEOSTYLY, 0);
		j9_aluminothermic(ppcie_info, i,
				  J9_HANDLE_J9M_ATTRIBUTE_PICHICIAGO, 0);
	}
	check =
	    j9_transmigrator(ppcie_info, 15,
			     J9_HANDLE_J9M_ATTRIBUTE_PICHICIAGO);
	if (check != 0)
		pr_info("[jmgpu]: iatu data is sticky");

}

s32 j9_governmentish(j9_gearshifts *ppcie_info)
{
	j9_ecumenically *pmwv207_info;
	s32 ret = 0;

	if (!ppcie_info->pinfo)
		return -1;


	j9_microtasimeter(ppcie_info);

	pmwv207_info =
	    devm_kzalloc(&ppcie_info->pdev->dev, sizeof(*pmwv207_info),
			 GFP_KERNEL);
	if (!pmwv207_info)
		return -1;

	ppcie_info->pinfo->priv = pmwv207_info;

	ret = j9mirror_sturdiness(ppcie_info, ppcie_info->regbar.no, 0x0);
	ret |= j9mirror_sturdiness(ppcie_info, ppcie_info->mem0bar.no,
				   roundup(J9_HANDLE_J9M_TRIPSOMELY,
					   ppcie_info->mem0bar.size));
	if (ppcie_info->regbar.size <= J9_HANDLE_J9M_NOVICELIKE) {
		pr_info("[jmgpu]: remap vi registers into 16M BAR");
		ret |=
		    j9_handle_j9ma_physicking(ppcie_info, J9_HANDLE_MILLIHENRY,
					      pci_bus_address(ppcie_info->pdev,
							      1) +
					      J9_HANDLE_J9MATHS_SUICIDICAL,
					      J9_HANDLE_J9M_NOVICELIKE,
					      0x200000);
	}
	if (ret)
		return -1;


	j9_handle__halophilic(ppcie_info);
	j9_corduroys(ppcie_info);

	return j9_cumbersome(ppcie_info->pdev, &mwv207_pmops, ppcie_info,
			     "pcie");
}

s32 j9_semiconfluent(j9_gearshifts *ppcie_info)
{
	j9_ecumenically *pmwv207_info = j9_undutifully(ppcie_info);
	j9_atlantomastoid *pplatform = container_of(ppcie_info,
						    j9_atlantomastoid,
						    pcie_info);
	j9maths_ingeminate *pmwv207_intctlr;

	if (!pmwv207_info)
		return -1;


	pmwv207_intctlr =
	    j9mirror_promissive(ppcie_info, ppcie_info->pdev->irq);
	if (!pmwv207_intctlr)
		return -1;


	pmwv207_info->pintctlr = pmwv207_intctlr;
	pplatform->pintctlr = pmwv207_intctlr->pintctlr;

	return 0;
}

s32 j9maths_coruscated(j9_gearshifts *ppcie_info)
{
	j9_ecumenically *pmwv207_info = j9_undutifully(ppcie_info);

	if (pmwv207_info)
		j9_handle_j_sporicidal(pmwv207_info->pintctlr);


	return 0;
}

static int j9_phenomenal(void *priv)
{
	j9_gearshifts *ppcie_info = (j9_gearshifts *) priv;
	int ret;

	j9_microtasimeter(ppcie_info);
	ret = j9mirror_sturdiness(ppcie_info, ppcie_info->regbar.no, 0x0);
	ret |= j9mirror_sturdiness(ppcie_info, ppcie_info->mem0bar.no,
				   roundup(J9_HANDLE_J9M_TRIPSOMELY,
					   ppcie_info->mem0bar.size));
	if (ppcie_info->regbar.size <= J9_HANDLE_J9M_NOVICELIKE) {
		pr_info("[jmgpu]: remap vi registers into 16M BAR");
		ret |=
		    j9_handle_j9ma_physicking(ppcie_info, J9_HANDLE_MILLIHENRY,
					      pci_bus_address(ppcie_info->pdev,
							      1) +
					      J9_HANDLE_J9MATHS_SUICIDICAL,
					      J9_HANDLE_J9M_NOVICELIKE,
					      0x200000);
	}
	if (ret)
		return ret;


	j9_handle__halophilic(ppcie_info);
	j9_corduroys(ppcie_info);

	return 0;
}

j9_turbans mwv207_hw_ops = {
	.pcie_init = j9_governmentish,
#ifndef MWV207_TRUECHIP_BUILD
	.ddr_init = j9_indefaceable,
#endif
	.intr_init = j9_semiconfluent,
	.intr_deinit = j9maths_coruscated,
	.map_bar = j9mirror_sturdiness,
	.map_region = j9_handle_j_frockmaker
};


