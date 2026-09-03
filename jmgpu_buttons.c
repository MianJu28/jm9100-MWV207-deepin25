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


#include <drm/drm_atomic.h>
#include <linux/moduleparam.h>
#include <drm/drm_crtc_helper.h>
#include <linux/version.h>
#if KERNEL_VERSION(5, 0, 0) <= LINUX_VERSION_CODE
#include <drm/drm_probe_helper.h>
#endif
#include <drm/drm_atomic_helper.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/spinlock.h>
#include <linux/wait.h>
#include <drm/drm_edid.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_dp_helper.h>
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_dp_helper.h>
#else
#include <drm/drm_dp_helper.h>
#endif
#endif
#if KERNEL_VERSION(4, 6, 0) < LINUX_VERSION_CODE
#include <drm/drm_print.h>
#endif
#include "jmgpu_authentication.h"
#include "jmgpu_bitmap.h"
#include "jmgpu_buttons.h"
#include "jmgpu_package.h"
#include "jmgpu_signal.h"
#include "jmgpu_implicit.h"
#include "jmgpu_unified.h"
#include "mwv207reg_procedure.h"

#define J9_NONAPPEALING       40
#define J9_NONRUSTICALLY      127
#define J9_HANDLE_J9MATHS_ATTRIBUTE_INIMITABLY  1000
#define J9_HANDLE_J_ATTRIBUTE_OESOPHAGAL        4
#define J9_HANDLE_J9MATHS_PREADAMITE            4
#define J9_HANDLE_TANGLESOME                    3
#define J9_HANDLE_PINPRICKED                    2
#define EDP_SHORT_IRQ_FLAG  (0x1 << 0)
#define EDP_HPD_IRQ_FLAG    (0x1 << 2)

typedef struct tag_jms_edp_config {
	u8 pre_emphasis[J9_HANDLE_J_ATTRIBUTE_OESOPHAGAL];
	u8 voltage_swing[J9_HANDLE_J9MATHS_PREADAMITE];
} __attribute__((packed)) j9maths_loricating;

static j9maths_loricating
	edp_phy_config_table[J9_HANDLE_PINPRICKED][J9_HANDLE_TANGLESOME] = {

	{

	 { { 0x1, 0x2, 0x3, 0x4}, { 0x1f, 0x18, 0x1c, 0x1f}},

	 { { 0x1, 0x2, 0x3, 0x4}, { 0x1f, 0x18, 0x1c, 0x1f}},

	 { { 0x1, 0x2, 0x3, 0x4}, { 0x1f, 0x18, 0x1c, 0x1f}}
	  },

	{

	 { { 0x1, 0x2, 0x3, 0x4}, { 0x1f, 0x18, 0x1c, 0x1f}},

	 { { 0x1, 0x2, 0x3, 0x4}, { 0x1f, 0x18, 0x1c, 0x1f}},

	 { { 0x1, 0x2, 0x3, 0x4}, { 0x1f, 0x18, 0x1c, 0x1f}}
	}
};

#define j9_schonfelsite(conn) container_of(conn, j9_fot_, connector)
#define j9_underbeaten(enc) container_of(enc, j9_fot_, encoder)
#define j9_cyclothymia(aux) container_of(aux, j9_fot_, drm_aux)
#define j9_unpreparedly(link) container_of(link, j9_fot_, link)

typedef struct tag_jms_edp_irq {
	bool edp_irq_enabled;
	bool auto_test_enabled;
} j9_overwide;

typedef struct tag_jms_edp_poll {
	struct task_struct *poll_task;
	wait_queue_head_t poll_wait;
	spinlock_t hpd_lock;
	u8 wait_cond;
} j9_glariness;

typedef struct _tag_jms_kms_edp {
	struct drm_connector connector;
	struct drm_encoder encoder;
	struct drm_dp_aux drm_aux;
	struct jmgpu_drm_dp_link link;
	struct tag_jms_edp_irq irq;
	struct tag_jms_edp_poll poll;
	struct i2c_adapter *ddc;
	struct jmgpu_panel *panel;
	struct mutex aux_mutex;
	struct mutex clk_lock;
	struct completion msg_comp;
	j9_weakliest *platform;
	enum drm_connector_status last_connector_result;
	struct edid *edid;
	u32 mem_base;
	u32 key_idx;
	u32 edp_chan;

	bool edidforce;

	bool zoomEn;
	bool power_on;
} j9_fot_;

enum i2caux_transaction_action {
	I2CAUX_TRANSACTION_ACTION_I2C_WRITE = 0x0 << 8,
	I2CAUX_TRANSACTION_ACTION_I2C_READ = 0x1 << 8,
	I2CAUX_TRANSACTION_ACTION_I2C_STATUS_REQUEST = 0x2 << 8,

	I2CAUX_TRANSACTION_ACTION_I2C_WRITE_MOT = 0x4 << 8,
	I2CAUX_TRANSACTION_ACTION_I2C_READ_MOT = 0x5 << 8,
	I2CAUX_TRANSACTION_ACTION_I2C_STATUS_REQUEST_MOT = 0x6 << 8,

	I2CAUX_TRANSACTION_ACTION_DP_WRITE = 0x8 << 8,
	I2CAUX_TRANSACTION_ACTION_DP_READ = 0x9 << 8
};

static inline void j9_breechcloth(j9_fot_ *edp, u32 addr, u32 val)
{
	j9_weakliest *platform = edp->platform;

	J9_CRISPY(addr, val);
}

static inline void j9_palings(j9_fot_ *edp, u32 offset, u32 val)
{
	j9_breechcloth(edp, edp->mem_base + offset, val);
}

static inline void j9mirror_berrettino(j9_fot_ *edp, u32 addr, u32 mask,
				       u32 val)
{
	j9_weakliest *platform = edp->platform;

	J9_UNPERFECTLY(addr, mask, val);
}

static inline u32 j9_hemophobia(j9_fot_ *edp, u32 addr)
{
	j9_weakliest *platform = edp->platform;

	return J9_NICOLS(addr);
}

static inline u32 j9_enters(j9_fot_ *edp, u32 offset)
{
	return j9_hemophobia(edp, edp->mem_base + offset);
}

static void j9_handle_j9m_scythework(struct drm_encoder *encoder);
static int j9_paratonically(j9_fot_ *edp, u32 address, u8 *reply,
			    u8 *buffer, u32 size, u32 command)
{
	s32 i;
	unsigned long time_left;
	s32 ret = size;
	s32 err;
	u8 code_reply;

	err = mutex_lock_interruptible(&edp->aux_mutex);
	if (err)
		return err;


	j9_palings(edp, J9_HANDLE_J9MIN_BANDCUTTER, address);

	if (command == I2CAUX_TRANSACTION_ACTION_I2C_WRITE
	    || command == I2CAUX_TRANSACTION_ACTION_I2C_WRITE_MOT
	    || command == I2CAUX_TRANSACTION_ACTION_DP_WRITE) {
		for (i = 0; i < size; i++) {
			j9_palings(edp, J9_HANDLE_J9MIRROR_BESMUTTING,
				   buffer[i]);
		}
	}

	reinit_completion(&edp->msg_comp);
	if (size == 0) {
		j9_palings(edp, J9_HANDLE_J9MIN_SAPOROSITY,
			   command | (0x1 << 12));
	} else {
		j9_palings(edp, J9_HANDLE_J9MIN_SAPOROSITY,
			   command | (size - 1));
	}

	DRM_DEBUG_DRIVER("wait_for_completion");
	time_left = wait_for_completion_timeout(&edp->msg_comp,
						msecs_to_jiffies(300));
	if (!time_left) {
		pr_err("%s: aux timeout,\n", __func__);
		ret = -ETIMEDOUT;
		goto unlock_exit;
	}
	DRM_DEBUG_DRIVER("completion");


	if (command == I2CAUX_TRANSACTION_ACTION_I2C_READ
	    || command == I2CAUX_TRANSACTION_ACTION_I2C_READ_MOT
	    || command == I2CAUX_TRANSACTION_ACTION_DP_READ) {
		for (i = 0; i < size; i++) {
			buffer[i] =
			    j9_enters(edp, J9_HANDLE_J9MIRROR_PARAPSIDAL);
		}
	}

	code_reply = j9_enters(edp, J9_HANDLE_J9MIRROR_SCOUTINGLY);
	if (reply)
		*reply = code_reply;

unlock_exit:
	mutex_unlock(&edp->aux_mutex);
	return ret;
}

static ssize_t j9_handle_j_overgrazes(struct drm_dp_aux *aux,
				      struct drm_dp_aux_msg *msg)
{
	ssize_t result = 0;
	enum i2caux_transaction_action action;
	j9_fot_ *edp = j9_cyclothymia(aux);

	if (WARN_ON(msg->size > 16))
		return -E2BIG;

	switch (msg->request & ~DP_AUX_I2C_MOT) {
	case DP_AUX_NATIVE_READ:
		action = I2CAUX_TRANSACTION_ACTION_DP_READ;

		result = j9_paratonically(edp, msg->address, &msg->reply,
					  (u8 *) msg->buffer,
					  msg->size, action);
		break;
	case DP_AUX_NATIVE_WRITE:
		action = I2CAUX_TRANSACTION_ACTION_DP_WRITE;

		j9_paratonically(edp, msg->address, &msg->reply,
				 (u8 *) msg->buffer, msg->size, action);
		result = msg->size;
		break;
	case DP_AUX_I2C_READ:
		if (msg->request & DP_AUX_I2C_MOT)
			action = I2CAUX_TRANSACTION_ACTION_I2C_READ_MOT;
		else
			action = I2CAUX_TRANSACTION_ACTION_I2C_READ;

		result = j9_paratonically(edp, msg->address, &msg->reply,
					  (u8 *) msg->buffer,
					  msg->size, action);
		break;
	case DP_AUX_I2C_WRITE:
		if (msg->request & DP_AUX_I2C_MOT)
			action = I2CAUX_TRANSACTION_ACTION_I2C_WRITE_MOT;
		else
			action = I2CAUX_TRANSACTION_ACTION_I2C_WRITE;

		j9_paratonically(edp, msg->address, &msg->reply,
				 (u8 *) msg->buffer, msg->size, action);
		result = msg->size;
		break;
	default:
		return -EINVAL;
	}

	if (result < 0) {
		result = -EIO;
	}

	DRM_DEBUG_DRIVER("Op: %x, addr: 0x%04x, size: %ld, reply code = %x",
			 action >> 8, msg->address, msg->size, msg->reply);
	return result;
}

static void j9_handle_attribute_clinicians(j9_fot_ *edp)
{
	complete(&edp->msg_comp);
	DRM_DEBUG_DRIVER("edp irq timeout!");
}

static void j9_handle_j_nonvesture(j9_fot_ *edp)
{
	complete(&edp->msg_comp);
	DRM_DEBUG_DRIVER("edp irq recv!");
}

static void j9_handle_j9min_coagulator(j9_fot_ *edp)
{
	spin_lock(&edp->poll.hpd_lock);
	edp->poll.wait_cond |= EDP_SHORT_IRQ_FLAG;
	spin_unlock(&edp->poll.hpd_lock);

	wake_up_interruptible(&edp->poll.poll_wait);
}

static void j9_handle_spondaical(j9_fot_ *edp)
{
	spin_lock(&edp->poll.hpd_lock);
	edp->poll.wait_cond |= EDP_HPD_IRQ_FLAG;
	spin_unlock(&edp->poll.hpd_lock);

	wake_up_interruptible(&edp->poll.poll_wait);
}

static irqreturn_t j9_handle__predecease(int irq, void *data)
{
	j9_fot_ *edp = (j9_fot_ *) data;
	u8 event_mask;

	if (!edp->irq.edp_irq_enabled)
		return IRQ_NONE;

	event_mask = j9_enters(edp, J9_HANDLE_ATTRIBUTE_CUREMASTER);

	DRM_DEBUG_DRIVER("edp recv irq %d\n", event_mask);

	while (event_mask) {
		if (event_mask & (0x1 << 0)) {

			j9_handle_spondaical(edp);
		}
		if (event_mask & (0x1 << 1)) {

			j9_handle_j9min_coagulator(edp);
		}
		if (event_mask & (0x1 << 2)) {

			j9_handle_j_nonvesture(edp);
		}
		if (event_mask & (0x1 << 3)) {

			j9_handle_attribute_clinicians(edp);
		}







		j9_enters(edp, J9_HANDLE_J9M_DOWNLOADED);
		event_mask = j9_enters(edp, J9_HANDLE_ATTRIBUTE_CUREMASTER);
	}

	return IRQ_HANDLED;
}

void j9maths_reacquired(j9_fot_ *edp, u32 chan)
{

	j9_palings(edp, J9_HANDLE_J9MIRROR_CACODYLATE, 0x0);
}

static s32 j9_handle_j9_sobersault(struct jmgpu_drm_dp_link *link, u32 lanenum)
{
	j9_fot_ *edp = j9_unpreparedly(link);
	u8 lev = link->train.request.pre_emphasis[lanenum];
	u8 edp_chan = edp->edp_chan;
	u8 rate_index;

	DRM_DEBUG_DRIVER("current lev is %d", lev);

	if (edp_chan >= J9_HANDLE_PINPRICKED) {
		DRM_ERROR("invalid edp_chan = %d", edp_chan);
		return 0;
	}
	if (link->rate == 162000) {
		rate_index = 0;
	} else if (link->rate == 270000) {
		rate_index = 1;
	} else if (link->rate == 540000) {
		rate_index = 2;
	} else {
		DRM_ERROR("invalid link rate = %d", link->rate);
		return 0;
	}
	if (lev >= J9_HANDLE_J_ATTRIBUTE_OESOPHAGAL)
		lev = J9_HANDLE_J_ATTRIBUTE_OESOPHAGAL - 1;

	return edp_phy_config_table[edp_chan][rate_index].pre_emphasis[lev];
}

static s32 j9_westernisation(struct jmgpu_drm_dp_link *link, u32 lanenum)
{
	j9_fot_ *edp = j9_unpreparedly(link);
	u8 lev = link->train.request.voltage_swing[lanenum];
	u8 edp_chan = edp->edp_chan;
	u8 rate_index;

	DRM_DEBUG_DRIVER("current lev is %d", lev);

	if (edp_chan >= J9_HANDLE_PINPRICKED) {
		DRM_ERROR("invalid edp_chan = %d", edp_chan);
		return 0;
	}
	if (link->rate == 162000) {
		rate_index = 0;
	} else if (link->rate == 270000) {
		rate_index = 1;
	} else if (link->rate == 540000) {
		rate_index = 2;
	} else {
		DRM_ERROR("invalid link rate = %d", link->rate);
		return 0;
	}
	if (lev >= J9_HANDLE_J9MATHS_PREADAMITE)
		lev = J9_HANDLE_J9MATHS_PREADAMITE - 1;

	return edp_phy_config_table[edp_chan][rate_index].voltage_swing[lev];
}

static int j9_handle_j9_diplacuses(struct jmgpu_drm_dp_link *link)
{
	j9_fot_ *edp = j9_unpreparedly(link);
	unsigned int lane;
	u32 voltage_swing = 0;
	u32 pre_emphasis = 0;
	u32 value;

	for (lane = 0; lane < link->lanes; lane++) {
		pre_emphasis = j9_handle_j9_sobersault(link, lane);
		voltage_swing = j9_westernisation(link, lane);

		value =
		    (u32) ((pre_emphasis << 6) | (voltage_swing << 1) | 0x1);
		j9_palings(edp, J9_HANDLE_J9MIRROR_CELIOSCOPY + 0x4 * lane,
			   value);
		j9_palings(edp, J9_HANDLE_J9MIRROR_CLINICIANS + 0x4 * lane,
			   voltage_swing);
		j9_palings(edp, J9_HANDLE_J9MATHS_FOLKSINESS + 0x4 * lane,
			   pre_emphasis);
		DRM_DEBUG_DRIVER
		    ("lane_%d pre_emphasis = 0x%x, voltage_swing = 0x%x", lane,
		     pre_emphasis, voltage_swing);
	}

	j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_CELIBATIST,
		   link->train.pattern);
	usleep_range(20, 100);
	DRM_DEBUG_DRIVER("training lane = %d, rate = %d, pattern = %d",
			 link->lanes, link->rate, link->train.pattern);
	return 0;
}

static u32 j9maths_qualifying(u32 edp_chan, u32 rate)
{
	switch (rate) {
	case 162000:
		return 0x06;
	case 270000:
		return 0x0a;
	case 540000:
		return 0x14;
	}

	DRM_ERROR("edp(%d) rate(%d) didn't find speed", edp_chan, rate);
	return 0;
}

static void j9_dentiparous(struct jmgpu_drm_dp_link *link, u8 lane_count,
			   u32 rate)
{
	unsigned int edp_pll_value[3][8] = {
		{ 0x140067F2, 0x6C8024A6, 0x21653330, 0x474D900E, 0x9C1143D1,
		 0x1, 0x0, 0x1143 },
		{ 0x140067F2, 0x6C8024A6, 0x21653330, 0x474D900E, 0x9C1170D1,
		 0x1, 0x0, 0x1170 },
		{ 0x140067F2, 0x6C8024A6, 0x21653330, 0x47408110, 0x9C0570D1,
		 0x1, 0x0, 0x1070 },
	};
	j9_fot_ *edp = j9_unpreparedly(link);
	s32 wait_time_left_us;
	u32 value;
	u8 rate_inx = 1;


	j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_OUTGAMBLED, 0);

	j9_palings(edp, J9_HANDLE_ATTRIBUTE_PREPERFECT, 0);

	j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_TONGUELESS, 0);
	usleep_range(1, 2);

	switch (lane_count) {
	case 1:
		value = 0xf0 | 0x1;
		break;
	case 2:
		value = 0xf0 | 0x3;
		break;
	case 3:
		value = 0xf0 | 0x7;
		break;
	case 4:
		value = 0xf0 | 0xf;
		break;
	default:
		DRM_ERROR("lane_count(%d) num err\n", lane_count);
		return;
	}

	j9_palings(edp, J9_HANDLE_J9MENU_ATTRIBUTE_CROSSBENCH, value);
	usleep_range(1, 2);


	j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_OUTGAMBLED, 3);
	usleep_range(1, 2);


	value = 0xD9;
	j9_palings(edp, J9_HANDLE_J9MIRROR_CELIOSCOPY, value);
	j9_palings(edp, J9_HANDLE_J9MIRROR_PRECONCEAL, value);
	j9_palings(edp, J9_HANDLE_J9MIRROR_CHORIOMATA, value);
	j9_palings(edp, J9_HANDLE_J9MIRROR_PREPERFECT, value);


	j9_palings(edp, J9_HANDLE_J9MIN_DEFAITISME, 0);
	j9_palings(edp, J9_HANDLE_J9MIN_CRAQUELURE, 0);
	if (link->caps.max_downspread) {
		j9_palings(edp, J9_HANDLE_J9MIN_SIGNATURES,
			   rate == 162000 ? 0x5528 : 0x6118);
	} else {
		j9_palings(edp, J9_HANDLE_J9MIN_SIGNATURES, 0);
	}
	j9_palings(edp, J9_HANDLE_J9MIN_INKINESSES, 0);
	j9_palings(edp, J9_HANDLE_J9MIN_MANEUVERER, 0);


	if (rate > 270000)
		rate_inx = 2;
	else if (rate < 270000)
		rate_inx = 0;
	else
		rate_inx = 1;

	j9_palings(edp, J9_HANDLE_J9MIN_DAUPHINESS, edp_pll_value[rate_inx][0]);
	j9_palings(edp, J9_HANDLE_J9MIN_UNCUTTABLE, edp_pll_value[rate_inx][1]);
	j9_palings(edp, J9_HANDLE_J9MIN_ACQUIRENDA, edp_pll_value[rate_inx][2]);
	j9_palings(edp, J9_HANDLE_J9MIN_CHATOYANCY, edp_pll_value[rate_inx][3]);
	j9_palings(edp, J9_HANDLE_J9MIN_DIVINENESS, edp_pll_value[rate_inx][4]);
	j9_palings(edp, J9_HANDLE_J9MIN_CLEANLIEST, edp_pll_value[rate_inx][5]);
	j9_palings(edp, J9_HANDLE_J9MIN_ECSTATICAL, edp_pll_value[rate_inx][6]);
	j9_palings(edp, J9_HANDLE_J9MIN_PLOTTINGLY, edp_pll_value[rate_inx][7]);
	usleep_range(10, 11);

	wait_time_left_us = J9_HANDLE_J9MATHS_ATTRIBUTE_INIMITABLY;
	while (!(j9_enters(edp, J9_HANDLE_J_ATTRIBUTE_PRENEGLECT) & 0x1) &&
	       wait_time_left_us > 0) {
		usleep_range(10, 11);
		wait_time_left_us -= 10;
	}
	if (wait_time_left_us <= 0)
		DRM_DEBUG_DRIVER("edp pll lock timeout!");



	j9_palings(edp, J9_HANDLE_ATTRIBUTE_PREPERFECT, 1);


	switch (lane_count) {
	case 1:
		value = 0x1;
		break;
	case 2:
		value = 0x3;
		break;
	case 3:
		value = 0x7;
		break;
	case 4:
		value = 0xf;
		break;
	default:
		DRM_ERROR("invalid lanes\n");
		return;
	}
	j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_TONGUELESS, value);
	usleep_range(1, 2);

	j9_palings(edp, J9_HANDLE_J9MIN_MANEUVERER, 0x1 << 19);


	j9_palings(edp, J9_HANDLE_ATTRIBUTE_BRAZENNESS, 1);
}

static void j9_handle_j9mirror_paranoiacs(struct jmgpu_drm_dp_link *link)
{
	j9_fot_ *edp = j9_unpreparedly(link);
	u32 ichan = edp->edp_chan;
	u8 speed;

	speed = j9maths_qualifying(ichan, link->rate);


	j9_palings(edp, J9_HANDLE_J9MIN_DISTORTION, speed);
	j9_palings(edp, J9_HANDLE_J9MIRROR_PREDECLINE, link->lanes);

	j9_palings(edp, J9_HANDLE_J_ATTRIBUTE_RHODIZONIC,
		   link->caps.enhanced_framing);
	usleep_range(400, 1000);
	j9_palings(edp, J9_HANDLE_J9M_ATTRIBUTE_PRECONCEAL,
		   link->caps.alternate_scrambler_reset);


	drm_dp_dpcd_writeb(&edp->drm_aux, DP_LINK_BW_SET, speed);
	drm_dp_dpcd_writeb(&edp->drm_aux, DP_LANE_COUNT_SET,
			   (s8) (link->lanes | 0x80));
	drm_dp_dpcd_writeb(&edp->drm_aux, DP_SET_POWER, 1);

	j9_dentiparous(link, link->lanes, link->rate);
}

static int j9maths_affirmable(struct jmgpu_drm_dp_link *link)
{
	j9_fot_ *edp = j9_unpreparedly(link);

	j9_palings(edp, J9_HANDLE_ATTRIBUTE_POSTLUDIUM,
		   link->caps.max_downspread);
	j9_handle_j9mirror_paranoiacs(link);
	DRM_DEBUG_DRIVER("configure lane = %d, rate = %d", link->lanes,
			 link->rate);
	return 0;
}

static const struct drm_dp_link_ops jmgpu_dp_link_funcs = {
	.apply_training = j9_handle_j9_diplacuses,
	.configure = j9maths_affirmable,
};

static bool j9_handle__bloomeries(struct drm_dp_aux *aux, u8 *sink_irq_vector)
{
	return drm_dp_dpcd_readb(aux, DP_DEVICE_SERVICE_IRQ_VECTOR,
				 sink_irq_vector) == 1;
}

static void j9_handle_j9ma_solemnizes(j9_fot_ *edp)
{
	u8 sink_irq_vector = 0;
	struct drm_dp_aux *aux = NULL;

	aux = &edp->drm_aux;
	if (!aux)
		return;



	if (j9_handle__bloomeries(aux, &sink_irq_vector) &&
	    sink_irq_vector != 0) {

		drm_dp_dpcd_writeb(aux,
				   DP_DEVICE_SERVICE_IRQ_VECTOR,
				   sink_irq_vector);




		if (sink_irq_vector & (DP_CP_IRQ | DP_SINK_SPECIFIC_IRQ))
			DRM_DEBUG_DRIVER("CP or sink specific irq unhandled\n");

	}

}

static u8 jmgpu_edp_get_wait_cond(j9_fot_ *edp)
{
	unsigned long flags;
	u8 wait_cond;

	spin_lock_irqsave(&edp->poll.hpd_lock, flags);
	wait_cond = edp->poll.wait_cond;
	edp->poll.wait_cond = 0;
	spin_unlock_irqrestore(&edp->poll.hpd_lock, flags);

	return wait_cond;
}

static int j9mirror_tadpoledom(void *arg)
{
	j9_fot_ *edp = (j9_fot_ *) arg;
	int ret;
	u8 wait_cond;

	set_freezable();
	while (!kthread_should_stop()) {
		try_to_freeze();
		ret = wait_event_interruptible_timeout(edp->poll.poll_wait,
						       (wait_cond =
						       jmgpu_edp_get_wait_cond
						       (edp)),
						       msecs_to_jiffies(1000));
		if (ret == 0)
			continue;

		if (wait_cond & EDP_HPD_IRQ_FLAG) {
			DRM_DEBUG_DRIVER("handle edp hpd...");
			drm_helper_hpd_irq_event(edp->connector.dev);
		}
		if (wait_cond & EDP_SHORT_IRQ_FLAG) {
			DRM_DEBUG_DRIVER("handle dp auto test...");
			j9_handle_j9ma_solemnizes(edp);
		}
	}
	return 0;
}

static s32 j9_handle_j9min_scorbutize(j9_fot_ *edp, u16 key)
{
	j9maths_loricating *ptr;
	j9_strenuous *item;
	int ret = 0;
	u8 edp_chan = edp->edp_chan;
	u8 i;


	item = edp->platform->ops->get_cfg_item(edp->platform, key);
	if (!item) {
		DRM_DEBUG_DRIVER("cfg(%d) is not exist!", key);
		return -EINVAL;
	}
	if (item->len != (sizeof(j9maths_loricating)) * J9_HANDLE_TANGLESOME) {
		DRM_DEBUG_DRIVER("invalid edp phy table length(%d)", item->len);
		ret = -EINVAL;
		goto release;
	}

	ptr = item->data;
	for (i = 0; i < J9_HANDLE_TANGLESOME; i++)
		edp_phy_config_table[edp_chan][i] = *ptr++;

release:

	edp->platform->ops->put_cfg_item(edp->platform, item);

	return ret;
}

static void j9_handle_j9mirror_denegation(struct drm_connector *connector)
{
	j9_fot_ *edp = j9_schonfelsite(connector);
	u32 key;
	u8 edp_chan;

	if (!edp->panel) {
		DRM_DEBUG_DRIVER("panel invalid!");
		return;
	}

	edp_chan = edp->edp_chan;
	key = edp_chan * 20 + J9_NONRUSTICALLY;
	if (j9_handle_j9min_scorbutize(edp, key)) {
		DRM_INFO("[jmgpu] edp_%d use default phy config value",
			 edp_chan);
	}

	if (!j9_handle_j9mirror_hypotarsus
	    (edp->panel, edp->key_idx, &edp->edid)) {
		edp->edidforce = true;
	} else {
		edp->edidforce = false;
	}
	if (edp->edidforce) {
		edp->connector.force = DRM_FORCE_ON;

		DRM_INFO("edp_%d: DRM_FORCE_ON!", edp_chan);
	}

	jmgpu_kms_panel_set_zoom_is_enable(edp->panel, edp->zoomEn);

	if (edp->zoomEn) {

		DRM_INFO("edp_%d: EDP_ZOOM_ON!", edp_chan);
	}
}

static int j9_handle_j9maths_unciferous(struct drm_connector *connector)
{
	j9_fot_ *edp = j9_schonfelsite(connector);
	int edp_chan;
	int ret;


	ret = j9_handle_amphimixes(connector->dev, edp->platform, &edp->panel,
				   edp->key_idx, DRM_MODE_CONNECTOR_eDP);
	if (ret < 0)
		return ret;

#if KERNEL_VERSION(5, 14, 0) <= LINUX_VERSION_CODE
	edp->drm_aux.drm_dev = connector->dev;
#endif
	edp->drm_aux.name = "jmgpu_edp_aux";
	edp->drm_aux.dev = connector->dev->dev;
	edp->drm_aux.transfer = j9_handle_j_overgrazes;
	ret = drm_dp_aux_register(&edp->drm_aux);
	if (ret) {
		DRM_ERROR("failed to register drm aux: %d\n", ret);
		return -EINVAL;
	}
	edp->ddc = &edp->drm_aux.ddc;

	edp->link.ops = &jmgpu_dp_link_funcs;
	edp->link.aux = &edp->drm_aux;

	j9_handle_j9mirror_denegation(connector);

	edp->connector.interlace_allowed = false;

	edp->connector.polled = DRM_CONNECTOR_POLL_HPD;
	spin_lock_init(&edp->poll.hpd_lock);
	init_waitqueue_head(&edp->poll.poll_wait);
	edp->poll.wait_cond = 0;
	edp->poll.poll_task =
	    kthread_run(j9mirror_tadpoledom, edp,
			"DP_AUTO_TEST_AND_TRAINING_FAIL");
	if (IS_ERR(edp->poll.poll_task)) {
		DRM_ERROR("unable to create kernel thread: %ld\n",
			  PTR_ERR(edp->poll.poll_task));
	}


	edp_chan = edp->edp_chan;
	ret = edp->platform->ops->requestIrq(edp->platform,
					     J9_NONAPPEALING + edp_chan,
					     j9_handle__predecease,
					     "jmgpu_edp_irq", edp);
	if (ret) {
		DRM_ERROR("failed request_irq %d for edp-%d\n",
			  J9_NONAPPEALING + edp_chan, edp_chan);
	} else {
		edp->irq.edp_irq_enabled = true;
		j9maths_reacquired(edp, edp_chan);
	}

	return 0;
}

static void j9_handle__attribute_rampacious(struct drm_connector *connector)
{
	j9_fot_ *edp = j9_schonfelsite(connector);
	int edp_chan;

	edp_chan = edp->edp_chan;

	edp->platform->ops->freeIrq(edp->platform,
				    J9_NONAPPEALING + edp_chan, edp);

	kthread_stop(edp->poll.poll_task);
	edp->poll.poll_task = NULL;

	drm_dp_aux_unregister(&edp->drm_aux);
	if (edp->panel)
		j9_handle_j_goodliness(edp->panel);

}

static void j9_handle_j_overnursed(struct drm_connector *conn)
{
	drm_connector_unregister(conn);
	drm_connector_cleanup(conn);
}

static bool j9_handle_j9_unapprized(struct drm_connector *conn)
{
	j9_fot_ *edp = j9_schonfelsite(conn);
	u8 val;
	bool connect_state = false;

	mutex_lock(&edp->clk_lock);
	val = j9_enters(edp, J9_HANDLE_J9MIRROR_GROUNDWAVE);
	mutex_unlock(&edp->clk_lock);
	connect_state = val ? true : false;

	return connect_state;
}

static int j9_handle_j9ma_cherubical(struct drm_connector *conn,
				     struct drm_modeset_acquire_ctx *ctx,
				     bool force)
{
	j9_fot_ *edp = j9_schonfelsite(conn);

	if (conn->force == DRM_FORCE_OFF)
		return connector_status_disconnected;


	if ((conn->force == DRM_FORCE_ON)
	    || (conn->force == DRM_FORCE_ON_DIGITAL)) {
		return connector_status_connected;
	}

	if (edp->edidforce)
		return connector_status_connected;

	if (edp->last_connector_result != connector_status_unknown
		&& !edp->power_on)
		return edp->last_connector_result;


	j9mirror_paraselene(edp->panel);
	edp->last_connector_result = j9_handle_j9_unapprized(conn)
	    ? connector_status_connected : connector_status_disconnected;

	if (!edp->power_on) {

		j9_handle__corymbiate(edp->panel);
	}

	return edp->last_connector_result;
}

static int j9_handle__attribute_undebarred(struct drm_connector *connector,
					   struct drm_display_mode *native_mode)
{
	j9_fot_ *edp = j9_schonfelsite(connector);
	int count = 0;

	if (native_mode) {
		count = drm_add_modes_noedid(&edp->connector,
					     native_mode->hdisplay,
					     native_mode->vdisplay);
	}

	return count;
}

static s32 j9_handle_j9m_breechless(struct drm_connector *conn)
{
	j9_fot_ *edp = j9_schonfelsite(conn);
	struct drm_display_mode *native_mode = NULL;
	struct edid *edid;
	s32 count = 0;


	j9mirror_paraselene(edp->panel);

	if (edp->edidforce && edp->edid)
		edid = (struct edid *)edp->edid;
	else
		edid = drm_get_edid(&edp->connector, edp->ddc);

#if KERNEL_VERSION(4, 16, 0) > LINUX_VERSION_CODE
	drm_mode_connector_update_edid_property(conn, edid);
#else
	drm_connector_update_edid_property(conn, edid);
#endif
	count = drm_add_edid_modes(conn, edid);

	if (edp->zoomEn) {
		j9_handle__attribute_fiducially(edp->panel, conn, &native_mode);
		count += j9_handle__attribute_undebarred(conn, native_mode);
	}

	if (!edp->edidforce)
		kfree(edid);

	return count;
}

#if KERNEL_VERSION(4, 11, 0) >= LINUX_VERSION_CODE
static enum drm_connector_status j9_handle__stamineous(struct drm_connector
						       *conn, bool force)
{
	return j9_handle_j9ma_cherubical(conn, NULL, force);
}
#endif

static enum drm_mode_status j9_handle_j9ma_devoration(struct drm_connector
						      *connector, struct drm_display_mode
						      *mode)
{
	j9_fot_ *edp = j9_schonfelsite(connector);
	j9_weakliest *platform = edp->platform;
	jmtUINT64 vram_size = platform->params.vram_size;

	if (!j9_handle_j9maths_promulging(edp->panel, mode, vram_size))
		return MODE_CLOCK_HIGH;


	return MODE_OK;
}

static const struct drm_connector_helper_funcs jmgpu_edp_connector_helper_funcs
	= {
	.get_modes = j9_handle_j9m_breechless,
	.mode_valid = j9_handle_j9ma_devoration,
#if KERNEL_VERSION(4, 11, 0) < LINUX_VERSION_CODE
	.detect_ctx = j9_handle_j9ma_cherubical
#endif
};

static const struct drm_connector_funcs jmgpu_connector_edp_funcs = {
	.reset = drm_atomic_helper_connector_reset,
	.fill_modes = drm_helper_probe_single_connector_modes,
	.atomic_duplicate_state = drm_atomic_helper_connector_duplicate_state,
	.atomic_destroy_state = drm_atomic_helper_connector_destroy_state,
	.destroy = j9_handle_j_overnursed,
#if KERNEL_VERSION(4, 11, 0) >= LINUX_VERSION_CODE
	.detect = j9_handle__stamineous,
	.dpms = drm_atomic_helper_connector_dpms,
	.set_property = drm_atomic_helper_connector_set_property,
#endif
	.late_register = j9_handle_j9maths_unciferous,
	.early_unregister = j9_handle__attribute_rampacious,
};

static enum drm_mode_status j9_handle_j9maths_corpulence(struct drm_encoder
							 *crtc, const struct
							 drm_display_mode * mode)
{
	if (mode->clock > 594000)
		return MODE_CLOCK_HIGH;

	return MODE_OK;
}

static int j9_handle_attribute_homogonies(struct drm_encoder *encoder,
					  struct drm_crtc_state *crtc_state,
					  struct drm_connector_state
					  *conn_state)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	struct drm_display_mode *native_mode = NULL;

	DRM_DEBUG_DRIVER("%s atomic check\n", encoder->name);

	if (edp->zoomEn) {
		native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
		if (!native_mode) {
			DRM_DEBUG_DRIVER
			    ("zoom_enabled but native_mode is invalid\n");
			return -EINVAL;
		}
	}
	return 0;
}

static void j9_handle_j9menu_uncuttable(struct drm_encoder *encoder,
					u32 crtc_chan)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	u8 edp_chan;

	edp_chan = edp->edp_chan;
	j9mirror_berrettino(edp, j9_handle_j9min_curemaster + edp_chan * 4,
			    0x1 << (crtc_chan * 4 + 3),
			    0x1 << (crtc_chan * 4 + 3));
	j9mirror_berrettino(edp, j9_handle_j9min_curemaster + edp_chan * 4, 0x7,
			    crtc_chan);
}

static u32 j9_superqualified(u8 ichan, u8 speed)
{
	switch (speed) {
	case 0x06:
		return 162000;
	case 0x0a:
		return 270000;
	case 0x14:
		return 540000;
	}

	DRM_ERROR("edp(%d) speed(0x%x) didn't find rate", ichan, speed);
	return 0;
}

static void j9_handle_j9_attribute_dowagerism(struct drm_encoder *encoder)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	struct jmgpu_drm_dp_link *link = NULL;
	u32 ichan;
	unsigned int rate = 0;
	u8 lane_count = 0;
	u8 speed = 0;

	ichan = edp->edp_chan;
	drm_dp_dpcd_readb(&edp->drm_aux, DP_MAX_LINK_RATE, &speed);
	drm_dp_dpcd_readb(&edp->drm_aux, DP_MAX_LANE_COUNT, &lane_count);

	rate = j9_superqualified(ichan, speed);

	j9_palings(edp, J9_HANDLE_ATTRIBUTE_OUTSAVORED, 0x01);
	j9_palings(edp, J9_HANDLE_J9MIN_DISTORTION, speed);

	if (j9_enters(edp, J9_HANDLE_J9MIRROR_PREDECLINE) != lane_count)
		j9_palings(edp, J9_HANDLE_J9MIRROR_PREDECLINE, lane_count);


	if (lane_count > 4)
		lane_count = 4;

	drm_dp_dpcd_writeb(&edp->drm_aux, DP_LINK_BW_SET, speed);
	drm_dp_dpcd_writeb(&edp->drm_aux, DP_LANE_COUNT_SET,
			   (s8) (lane_count | 0x80));
	drm_dp_dpcd_writeb(&edp->drm_aux, DP_SET_POWER, 1);

	link = &edp->link;
	j9_dentiparous(link, lane_count, rate);

	DRM_DEBUG_DRIVER("speed = 0x%x, lane_count = %d, rate = %d", speed,
			 lane_count, rate);
}

static u32 j9mirror_abridgable(u32 fapb)
{
	u32 n, b, d;
	s32 a;

	n = 1000 / fapb;
	a = (s32) n;
	b = n - a;
	d = b * (1 << 16);
	d = a << 16 | d;
	return d;
}

static void j9_handle__fribbleism(struct drm_encoder *encoder)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	int aux_clk;
	int freq_khz;
	u8 value;

	edp->platform->ops->get_pll(edp->platform, J9MATHS_PERIPTEROS,
				    &freq_khz);
	aux_clk = freq_khz / 5 / 1000;

	j9_palings(edp, J9_HANDLE_J9MIN_CHRONICLED, aux_clk);


	value = j9mirror_abridgable(aux_clk);
	j9_palings(edp, J9_HANDLE_J9MIN_ATTRIBUTE_MISQUALITY, value);
	DRM_DEBUG_DRIVER("freq_khz = 0x%x, aux_clk = 0x%x", freq_khz, aux_clk);
}

static void jmgpu_edp_set_irq_enable(struct drm_encoder *encoder, int enable)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	j9_weakliest *platform = edp->platform;
	u8 edp_chan = edp->edp_chan;
	j9_duopoly status;

	if (!edp->irq.edp_irq_enabled)
		return;

	if (enable) {
		j9maths_reacquired(edp, edp_chan);
		status = platform->ops->enableIrq(platform, J9_NONAPPEALING + edp_chan, 1);
		if (status != J9_FLUTTERING)
			DRM_WARN("failed to enable edp interrupt");
	} else {
		status = platform->ops->enableIrq(platform, J9_NONAPPEALING + edp_chan, 0);
		if (status != J9_FLUTTERING)
			DRM_WARN("failed to disable edp interrupt");
		else
			msleep(1);
	}
}

static void j9_handle_j9mirror_scapulette(struct drm_encoder *encoder)
{
	j9_fot_ *edp = j9_underbeaten(encoder);


	j9_palings(edp, J9_HANDLE__CTENOIDIAN, 0x1);

	j9_handle__fribbleism(encoder);

	j9_palings(edp, J9_HANDLE_J9M_ATTRIBUTE_CHORIOMATA, 0x12);


	j9_handle_j9_attribute_dowagerism(encoder);
	j9_palings(edp, J9_HANDLE_J9_ATTRIBUTE_EXTRANEOUS, 1);
}

static void j9_handle_j9ma_attribute_misteacher(struct drm_encoder *encoder,
						bool enable)
{
	j9_fot_ *edp = j9_underbeaten(encoder);

	j9_palings(edp, J9_HANDLE_J9_ATTRIBUTE_INSTILLING, enable);
	if (!enable) {
		j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_OUTGAMBLED, 0);
		j9_palings(edp, J9_HANDLE_ATTRIBUTE_PREPERFECT, 0);
		j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_TONGUELESS, 0);
		j9_palings(edp, J9_HANDLE_J9MENU_ATTRIBUTE_CROSSBENCH, 0);
	}
	j9mirror_berrettino(edp, j9_handle_j9min_curemaster + edp->edp_chan * 4,
			    1 << 3, enable ? 1 << 3 : 0);
}

static s32 j9_handle_j9min_reparative(struct drm_encoder *encoder, u32 clk_idx)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	u32 val, mask;
	u8 edp_chan;

	edp_chan = edp->edp_chan;
	val = clk_idx << (edp_chan ? 28 : 24);
	mask = 0b11 << (edp_chan ? 28 : 24);
	j9mirror_berrettino(edp, MWV207REG_TOP_VO_CFG_3, mask, val);
	return 0;
}

static u32 j9_aquacultural(u8 lane_count, u32 rate, u32 pixclock)
{
	u32 pixel_clk = pixclock;
	u8 kdefault_tu_size = 64;
	u8 bits_per_color = 8;
	u8 color_factor = 3;
	u64 link_sr, vid_sr;
	u64 data_per_tu;
	u32 a, b;
	u32 tu;

	rate = rate / 100;
	link_sr =
	    (u64) pixel_clk * color_factor * bits_per_color * kdefault_tu_size *
	    10;
	vid_sr = (u64) lane_count * rate * 8;
	data_per_tu = link_sr / vid_sr;

	a = (u32) data_per_tu / 1000;
	b = (u32) (data_per_tu % 1000) * 16 / 1000;
	tu = (b << 24) | (a << 16) | 0x40;

	DRM_DEBUG_DRIVER("EDP pixel_clk = %d khz, rate = %d, lane_count = %d",
			 pixel_clk, rate, lane_count);
	DRM_DEBUG_DRIVER("link_sr = %llu, vid_sr = %llu, data_per_tu = %llu",
			 link_sr, vid_sr, data_per_tu);
	DRM_DEBUG_DRIVER("a = %d, b = %d, tu size: 0x%x", a, b, tu);
	return tu;
}

static void j9_handle_j9maths_antistatic(struct drm_encoder *encoder,
					 j9_observandum *t)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	struct jmgpu_drm_dp_link *link = &edp->link;
	u32 value;
	u32 symbol;
	u32 udc;

	if (link->lanes == 0 || link->rate == 0) {
		DRM_ERROR
		    ("invalid lane_count(%d) or rate(%d), please check hw!",
		     link->lanes, link->rate);
		return;
	}


	j9_palings(edp, J9_HANDLE_J9_ATTRIBUTE_EXTRANEOUS, 0);
	usleep_range(400, 401);
	j9_palings(edp, J9_HANDLE_J_ATTRIBUTE_PREPERFECT, t->htotal);
	j9_palings(edp, J9_HANDLE_J_ATTRIBUTE_INSTILLING, t->vtotal);
	value = ((~t->vpolarity & 1) << 1) | (~t->hpolarity & 1);
	j9_palings(edp, J9_HANDLE_J9M_ATTRIBUTE_BRAZENNESS, value);
	j9_palings(edp, J9_HANDLE_J9_ATTRIBUTE_QUINTUPLET, t->hsync);
	j9_palings(edp, J9_HANDLE_J9_ATTRIBUTE_QUINOPYRIN, t->vsync);
	j9_palings(edp, J9_HANDLE_ATTRIBUTE_RIFLEPROOF, t->hactive);
	j9_palings(edp, J9_HANDLE_ATTRIBUTE_CACODYLATE, t->vactive);
	value = t->htotal - t->hactive - t->hfrontporch;
	j9_palings(edp, J9_HANDLE_J_ATTRIBUTE_CHORIOMATA, value);
	value = t->vtotal - t->vactive - t->vfrontporch;
	j9_palings(edp, J9_HANDLE_J_ATTRIBUTE_BRAZENNESS, value);

	j9_palings(edp, J9_HANDLE__ATTRIBUTE_AUTOGENIES, 0);
	j9_palings(edp, J9_HANDLE_J9MIN_COMMENCING, t->clk_khz);
	j9_palings(edp, J9_HANDLE_J9MIRROR_ATTRIBUTE_EXTRANEOUS, 0x40);

	symbol = ((t->hactive * 24) + 7) / 8;
	udc = (symbol + link->lanes - 1) / link->lanes;
	j9_palings(edp, J9_HANDLE_J9M_ATTRIBUTE_PREPERFECT, udc);
	j9_palings(edp, J9_HANDLE__ATTRIBUTE_ILLUCIDATE, 0);
	j9_palings(edp, J9_HANDLE_J9MIN_COMMENCING, t->clk_khz / 10);
	j9_palings(edp, J9_HANDLE_J9M_ATTRIBUTE_INSTILLING, 0xf);
	j9_palings(edp, J9_HANDLE_J9MIN_STICHARION, link->rate / 10);

	if (t->bpp == 30)
		value = 0x41;
	else
		value = 0x21;

	j9_palings(edp, J9_HANDLE__ATTRIBUTE_RHABDOLOGY, value);
	j9_palings(edp, J9_HANDLE__ATTRIBUTE_AUTOGENIES, 0);

	j9_palings(edp, J9_HANDLE_J9MENU_ATTRIBUTE_INUREMENTS, 1);

	value = j9_aquacultural(link->lanes, link->rate, t->clk_khz);
	j9_palings(edp, J9_HANDLE_J9MIRROR_ATTRIBUTE_EXTRANEOUS, value);
	j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_UNICYCLIST, 0x20042004);
	j9_palings(edp, J9_HANDLE_J9MA_ATTRIBUTE_UNHONESTLY, 0x20042004);
	j9_palings(edp, J9_HANDLE_J9MIN_COMMENCING, t->clk_khz / 10);
	j9_palings(edp, J9_HANDLE_J9MIN_STICHARION, link->rate / 10);


	j9_palings(edp, J9_HANDLE_J9MA_CORUSCATED, 0);
	j9_palings(edp, J9_HANDLE_J9MATHS_CACODYLATE, 0x1);
}

static void j9_handle_j9m_scythework(struct drm_encoder *encoder)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	struct drm_display_info *info;
	struct drm_connector *conn;
	struct drm_display_mode *target_mode;
	struct drm_display_mode *native_mode;
	j9_observandum target_timing;
	int cur_crtc;
	int err;
	u32 repeat = 0;

	DRM_DEBUG_DRIVER("%s atomic enable", encoder->name);

	j9mirror_paraselene(edp->panel);
	edp->power_on = true;

	cur_crtc = drm_crtc_index(edp->connector.state->crtc);
	target_mode = &edp->connector.state->crtc->mode;

	native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
	if (edp->zoomEn && native_mode)
		target_mode = native_mode;


	j9_handle_attribute_amidstream(&target_timing, target_mode);

	j9_handle_j9menu_uncuttable(encoder, cur_crtc);
	j9_handle_j9mirror_scapulette(encoder);

	conn = &edp->connector;
	info = &conn->display_info;
	err = j9_handle_j9_resarcelee(edp->link.aux, &edp->link);
	if (err < 0)
		DRM_DEBUG_DRIVER("failed to probe DP link: %d\n", err);

	err = j9_handle_j9m_homemakers(&edp->link, target_mode, info);
	if (err < 0)
		DRM_DEBUG_DRIVER("failed to choose link: %d\n", err);

	while (repeat < 20) {
		err = j9_handle_j9_beterschap(&edp->link);
		if (err < 0) {
			DRM_DEBUG_DRIVER("link training failed: %d\n", err);
			repeat++;
		} else {
			DRM_DEBUG_DRIVER("link training succeeded\n");
			break;
		}
	}

	err = j9_handle_j9min_snobbiness(edp->link.aux, &edp->link);
	if (err < 0)
		DRM_DEBUG_DRIVER("failed to power up DP link: %d\n", err);


	j9_handle_j9maths_antistatic(encoder, &target_timing);
	j9_handle_j9min_reparative(encoder, cur_crtc);
	j9_handle_j9ma_attribute_misteacher(encoder, true);

	j9maths_nonfascist(edp->panel);

	DRM_DEBUG_DRIVER("%s mode(%dx%d) bind crtc_%d",
			 encoder->name, target_timing.hactive,
			 target_timing.vactive, cur_crtc);
}

static void j9_handle_j9ma_artophoria(struct drm_encoder *encoder)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	struct drm_display_mode *target_mode = NULL;
	struct drm_display_mode *native_mode = NULL;
	struct drm_crtc *crtc = NULL;
	int err;
	int refresh;

	DRM_DEBUG_DRIVER("%s atomic disable", encoder->name);

	crtc = edp->connector.state->crtc;
	if (crtc) {
		target_mode = &crtc->mode;
		native_mode = j9_handle_j9ma_sinuousity(encoder->dev);
		if (edp->zoomEn && native_mode)
			target_mode = native_mode;

		refresh = drm_mode_vrefresh(target_mode);
		if (refresh == 0)
			refresh = 60;

		j9_handle_j9mirror_archivault(crtc);
		msleep((1000 / refresh) + 1);
	}

	j9mirror_madbrained(edp->panel);
	j9_handle_j9ma_attribute_misteacher(encoder, false);
	err = j9_handle_j9maths_forgathers(edp->link.aux, &edp->link);
	if (err < 0)
		DRM_DEBUG_DRIVER("failed to power down DP link: %d\n", err);

	j9_handle__corymbiate(edp->panel);
	edp->power_on = false;


	edp->last_connector_result = connector_status_unknown;
}

static void j9mirror_tickliness(struct drm_encoder *encoder)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	struct mutex *gpio_mutex;
	u32 reg_gpio;
	u8 edp_chan;

	gpio_mutex = j9_handle_j9_rhymesters(encoder->dev);
	edp_chan = edp->edp_chan;
	mutex_lock(gpio_mutex);

	if (edp->platform->params.family == J9_UNGLADSOME) {
		reg_gpio = J9_HANDLE_J9MIRROR_TONGUELESS;
		j9mirror_berrettino(edp, reg_gpio,
				    0b11 << (12 + edp_chan * 4),
				    1 << (12 + edp_chan * 4));
	} else {
		reg_gpio = J9_HANDLE_J9MIRROR_ETHEROLATE;
		j9mirror_berrettino(edp, reg_gpio,
				    0b11 << (20 + edp_chan * 4),
				    1 << (20 + edp_chan * 4));
	}
	if (edp_chan == 0) {

		j9mirror_berrettino(edp, J9_HANDLE_J9MATHS_PALMETTOES,
				    0b11 << 28, 0 << 28);

		j9mirror_berrettino(edp, J9_HANDLE_J9MIRROR_COFFEETIME, 0x3, 0);

		j9mirror_berrettino(edp, J9_HANDLE_J9MATHS_PALMETTOES,
				    0x3 << 16, 0x1 << 16);

		j9mirror_berrettino(edp, J9_HANDLE_PEDIMENTED, 0x1 << 12, 0);
	} else if (edp_chan == 1) {

		j9mirror_berrettino(edp, J9_HANDLE_J9MIRROR_COFFEETIME,
				    0b11 << 4, 0 << 4);

		j9mirror_berrettino(edp, J9_HANDLE_J9MIRROR_COFFEETIME,
				    0x3 << 8, 0);

		j9mirror_berrettino(edp, J9_HANDLE_J9MATHS_PALMETTOES,
				    0x3 << 20, 0x1 << 20);

		j9mirror_berrettino(edp, J9_HANDLE_PEDIMENTED, 0x1 << 13, 0);
	} else {
		DRM_ERROR("invalid type_idx: %d", edp_chan);
	}


	j9mirror_berrettino(edp, J9_HANDLE_COMMENCING,
			    0x1 << (15 + edp_chan * 2),
			    0x0 << (15 + edp_chan * 2));
	j9mirror_berrettino(edp, J9_HANDLE_COMMENCING,
			    0x1 << (16 + edp_chan * 2),
			    0x0 << (16 + edp_chan * 2));
	mutex_unlock(gpio_mutex);
}

static void j9mirror_epistrophy(struct drm_encoder *encoder)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	u8 edp_chan;
	u8 reset_bit;

	edp_chan = edp->edp_chan;
	reset_bit = (edp_chan == 0) ? 8 : 9;
	mutex_lock(&edp->clk_lock);
	j9mirror_berrettino(edp, MWV207REG_TOP_VO_CFG_1, 0x1 << reset_bit, 0);
	j9mirror_berrettino(edp, MWV207REG_TOP_VO_CFG_2, 0x1 << reset_bit, 0);
	msleep(20);
	j9mirror_berrettino(edp, MWV207REG_TOP_VO_CFG_1, 0x1 << reset_bit,
			    0x1 << reset_bit);
	j9mirror_berrettino(edp, MWV207REG_TOP_VO_CFG_2, 0x1 << reset_bit,
			    0x1 << reset_bit);
	msleep(20);
	j9_breechcloth(edp, j9_handle_j9min_curemaster + edp_chan * 4, 0);
	mutex_unlock(&edp->clk_lock);
}

static void j9_handle_j9_beseechers(struct drm_encoder *encoder)
{
	j9_fot_ *edp = j9_underbeaten(encoder);
	u8 edp_chan;
	u8 reset_bit;

	DRM_DEBUG_DRIVER("%s atomic reset", encoder->name);

	edp_chan = edp->edp_chan;
	reset_bit = (edp_chan == 0) ? 8 : 9;

	jmgpu_edp_set_irq_enable(encoder, 0);

	j9mirror_epistrophy(encoder);

	j9_handle_j9ma_attribute_misteacher(encoder, false);

	j9mirror_tickliness(encoder);

	j9_handle__fribbleism(encoder);

	j9_palings(edp, J9_HANDLE__ATTRIBUTE_BEHAVIOUR_COENOTYPIC, 400);

	j9_palings(edp, J9_HANDLE__CTENOIDIAN, 0x1);

	jmgpu_edp_set_irq_enable(encoder, 1);
}

static const struct drm_encoder_funcs jmgpu_encoder_funcs = {
	.reset = j9_handle_j9_beseechers,
	.destroy = drm_encoder_cleanup,
};

static const struct drm_encoder_helper_funcs jmgpu_encoder_helper_funcs = {
#if KERNEL_VERSION(4, 13, 0) <= LINUX_VERSION_CODE
	.mode_valid = j9_handle_j9maths_corpulence,
#endif
	.atomic_check = j9_handle_attribute_homogonies,
	.enable = j9_handle_j9m_scythework,
	.disable = j9_handle_j9ma_artophoria,
};

int j9maths_cloddiness(struct drm_device *ddev, j9_weakliest *platform,
		       u32 key_idx, u32 edp_chan)
{
	j9_fot_ *edp;
	u32 possible_crtcs;
	u32 zoom_mask;
	int ret;

	edp = devm_kzalloc(ddev->dev, sizeof(j9_fot_), GFP_KERNEL);
	if (!edp)
		return -ENOMEM;

	edp->platform = platform;
	edp->key_idx = key_idx;
	edp->edp_chan = edp_chan;
	edp->mem_base = J9_HANDLE_J9MA_SAPOROSITY(edp->edp_chan);
	edp->power_on = true;
	mutex_init(&edp->aux_mutex);
	mutex_init(&edp->clk_lock);
	init_completion(&edp->msg_comp);

	zoom_mask = j9_handle_j9_goodliness(ddev);
	edp->zoomEn    = j9_handle_j9maths_dulcigenic(ddev, edp->key_idx);
	possible_crtcs = (1 << j9_handle_j_tubiporoid(ddev)) - 1;
	if (zoom_mask) {

		if (edp->zoomEn) {
			edp->encoder.possible_crtcs = 0x1;
		} else {
			edp->encoder.possible_crtcs = J9_MDSE(possible_crtcs, 0);
		}
	} else {
		edp->encoder.possible_crtcs = possible_crtcs;
	}

	ret = drm_connector_init(ddev, &edp->connector,
				 &jmgpu_connector_edp_funcs,
				 DRM_MODE_CONNECTOR_eDP);
	if (ret)
		return ret;
	drm_connector_helper_add(&edp->connector, &jmgpu_edp_connector_helper_funcs);

	ret = drm_encoder_init(ddev, &edp->encoder, &jmgpu_encoder_funcs,
			       DRM_MODE_ENCODER_TMDS, "edp-%d", edp->edp_chan);
	if (ret)
		return ret;

	drm_encoder_helper_add(&edp->encoder, &jmgpu_encoder_helper_funcs);

#if KERNEL_VERSION(4, 19, 0) > LINUX_VERSION_CODE
	ret = drm_mode_connector_attach_encoder(&edp->connector, &edp->encoder);
#else
	ret = drm_connector_attach_encoder(&edp->connector, &edp->encoder);
#endif
	if (ret)
		return ret;

	return drm_connector_register(&edp->connector);
}


