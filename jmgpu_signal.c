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
#include <drm/drm_crtc.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_dp_helper.h>
#else
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 6, 0)
#include <drm/display/drm_dp_helper.h>
#else
#include <drm/drm_dp_helper.h>
#endif
#endif
#include <drm/drm_atomic_helper.h>
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 6, 0)
#include <drm/drm_print.h>
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 18, 0)
#define DP_DPCD_REV_14                     0x14
#define DP_TRAINING_AUX_RD_MASK            0x7F
#endif


#ifndef DP_ADJUST_REQUEST_POST_CURSOR2
#define DP_ADJUST_REQUEST_POST_CURSOR2      0x20c
#endif

#include "jmgpu_signal.h"

#define J9_TRANSCURVATION		    (1 << 0)
static const u8 drm_dp_edp_revisions[] = { 0x11, 0x12, 0x13, 0x14, 0x14, 0x14 };

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 5, 0)
static inline bool drm_dp_fast_training_cap(const u8 dpcd[DP_RECEIVER_CAP_SIZE])
{
	return dpcd[DP_DPCD_REV] >= 0x11 &&
		(dpcd[DP_MAX_DOWNSPREAD] & DP_NO_AUX_HANDSHAKE_LINK_TRAINING);
}

	static inline bool
drm_dp_channel_coding_supported(const u8 dpcd[DP_RECEIVER_CAP_SIZE])
{
	return dpcd[DP_MAIN_LINK_CHANNEL_CODING] & J9_TRANSCURVATION;
}

	static inline bool
drm_dp_alternate_scrambler_reset_cap(const u8 dpcd[DP_RECEIVER_CAP_SIZE])
{
	return dpcd[DP_EDP_CONFIGURATION_CAP] & DP_ALTERNATE_SCRAMBLER_RESET_CAP;
}
#endif

static inline bool drm_dp_max_down_spread(const u8 dpcd[DP_RECEIVER_CAP_SIZE])
{
	return dpcd[DP_MAX_DOWNSPREAD] & DP_MAX_DOWNSPREAD_0_5;
}

static u8 j9_stabilizers(const u8 link_status[DP_LINK_STATUS_SIZE], int r)
{
	return link_status[r - DP_LANE0_1_STATUS];
}

u8 drm_dp_get_adjust_request_post_cursor(const u8
		link_status[DP_LINK_STATUS_SIZE],
		unsigned int lane)
{
	unsigned int offset = DP_ADJUST_REQUEST_POST_CURSOR2;
	u8 value = j9_stabilizers(link_status, offset);

	return (value >> (lane << 1)) & 0x3;
}

static void drm_dp_link_caps_reset(struct jmgpu_drm_dp_link_caps *caps)
{
	caps->enhanced_framing = false;
	caps->tps3_supported = false;
	caps->fast_training = false;
	caps->channel_coding = false;
	caps->alternate_scrambler_reset = false;
}

void drm_dp_link_caps_copy(struct jmgpu_drm_dp_link_caps *dest,
		const struct jmgpu_drm_dp_link_caps *src)
{
	dest->enhanced_framing = src->enhanced_framing;
	dest->tps3_supported = src->tps3_supported;
	dest->fast_training = src->fast_training;
	dest->channel_coding = src->channel_coding;
	dest->alternate_scrambler_reset = src->alternate_scrambler_reset;
}

static void drm_dp_link_reset(struct jmgpu_drm_dp_link *link)
{
	unsigned int i;

	if (!link)
		return;

	link->revision = 0;
	link->max_rate = 0;
	link->max_lanes = 0;

	drm_dp_link_caps_reset(&link->caps);
	link->aux_rd_interval.cr = 0;
	link->aux_rd_interval.ce = 0;
	link->edp = 0;

	link->rate = 0;
	link->lanes = 0;

	for (i = 0; i < DP_MAX_SUPPORTED_RATES; i++)
		link->rates[i] = 0;

	link->num_rates = 0;
	link->train.skip_swing = false;
}

int j9_handle_j9min_peltatifid(struct jmgpu_drm_dp_link *link,
		unsigned long rate)
{
	unsigned int i, pivot;

	if (link->num_rates == DP_MAX_SUPPORTED_RATES)
		return -ENOSPC;

	for (pivot = 0; pivot < link->num_rates; pivot++)
		if (rate <= link->rates[pivot])
			break;

	if (pivot != link->num_rates && rate == link->rates[pivot])
		return -EEXIST;

	for (i = link->num_rates; i > pivot; i--)
		link->rates[i] = link->rates[i - 1];

	link->rates[pivot] = rate;
	link->num_rates++;

	return 0;
}

int j9_handle_j9mirror_traversals(struct jmgpu_drm_dp_link *link,
		unsigned long rate)
{
	unsigned int i;

	for (i = 0; i < link->num_rates; i++)
		if (rate == link->rates[i])
			break;

	if (i == link->num_rates)
		return -EINVAL;

	link->num_rates--;

	while (i < link->num_rates) {
		link->rates[i] = link->rates[i + 1];
		i++;
	}

	return 0;
}

void j9_handle_attribute_tripsomely(struct jmgpu_drm_dp_link *link)
{
	unsigned int i, count = 0;

	for (i = 0; i < link->num_rates; i++) {
		if (link->rates[i] != 0)
			link->rates[count++] = link->rates[i];
	}

	for (i = count; i < link->num_rates; i++)
		link->rates[i] = 0;

	link->num_rates = count;
}

int j9_handle_j9_resarcelee(struct drm_dp_aux *aux,
		struct jmgpu_drm_dp_link *link)
{
	u8 dpcd[DP_RECEIVER_CAP_SIZE], value;
	unsigned int rd_interval;
	int err;

	err = drm_dp_dpcd_read(aux, DP_DPCD_REV, dpcd, sizeof(dpcd));
	if (err < 0)
		return err;

	link->revision = dpcd[DP_DPCD_REV];
	link->max_rate = drm_dp_max_link_rate(dpcd);
	link->max_lanes = drm_dp_max_lane_count(dpcd);
	DRM_DEBUG_KMS("dpcd_rev:%u, dpcd_max_rate:%u, dpcd_max_lanes:%u\n", link->revision, link->max_rate, link->max_lanes);

	link->caps.enhanced_framing = drm_dp_enhanced_frame_cap(dpcd);
	link->caps.tps3_supported = drm_dp_tps3_supported(dpcd);
	link->caps.fast_training = drm_dp_fast_training_cap(dpcd);
	link->caps.channel_coding = drm_dp_channel_coding_supported(dpcd);
	link->caps.max_downspread = drm_dp_max_down_spread(dpcd);

	link->caps.max_downspread = false;

	if (drm_dp_alternate_scrambler_reset_cap(dpcd)) {
		link->caps.alternate_scrambler_reset = true;

		err = drm_dp_dpcd_readb(aux, DP_EDP_DPCD_REV, &value);
		if (err < 0)
			return err;

		if (value >= ARRAY_SIZE(drm_dp_edp_revisions))
			DRM_DEBUG_KMS("unsupported eDP version: %02x\n", value);
		else
			link->edp = drm_dp_edp_revisions[value];
	}

	rd_interval = dpcd[DP_TRAINING_AUX_RD_INTERVAL] & DP_TRAINING_AUX_RD_MASK;

	if (rd_interval > 4) {
		DRM_DEBUG_KMS("AUX interval %u out of range (max. 4)\n", rd_interval);
		rd_interval = 4;
	}

	rd_interval *= 4 * USEC_PER_MSEC;

	if (rd_interval == 0 || link->revision >= DP_DPCD_REV_14)
		link->aux_rd_interval.cr = 100;

	if (rd_interval == 0)
		link->aux_rd_interval.ce = 400;

	link->rate = link->max_rate;
	link->lanes = link->max_lanes;


	if (link->edp >= 0x14) {
		u8 supported_rates[DP_MAX_SUPPORTED_RATES * 2];
		unsigned int i;
		u16 rate;

		err = drm_dp_dpcd_read(aux, DP_SUPPORTED_LINK_RATES,
				supported_rates, sizeof(supported_rates));
		if (err < 0)
			return err;

		for (i = 0; i < DP_MAX_SUPPORTED_RATES; i++) {
			rate = supported_rates[i * 2 + 1] << 8 | supported_rates[i * 2 + 0];

			j9_handle_j9min_peltatifid(link, rate * 200);
		}
	}

	return 0;
}

int j9_handle_j9min_snobbiness(struct drm_dp_aux *aux,
		struct jmgpu_drm_dp_link *link)
{
	u8 value;
	int err;


	if (link->revision < 0x11)
		return 0;

	err = drm_dp_dpcd_readb(aux, DP_SET_POWER, &value);
	if (err < 0)
		return err;

	value &= ~DP_SET_POWER_MASK;
	value |= DP_SET_POWER_D0;

	err = drm_dp_dpcd_writeb(aux, DP_SET_POWER, value);
	if (err < 0)
		return err;

	usleep_range(1000, 2000);

	return 0;
}

int j9_handle_j9maths_forgathers(struct drm_dp_aux *aux,
		struct jmgpu_drm_dp_link *link)
{
	u8 value;
	int err;


	if (link->revision < 0x11)
		return 0;

	err = drm_dp_dpcd_readb(aux, DP_SET_POWER, &value);
	if (err < 0)
		return err;

	value &= ~DP_SET_POWER_MASK;
	value |= DP_SET_POWER_D3;

	err = drm_dp_dpcd_writeb(aux, DP_SET_POWER, value);
	if (err < 0)
		return err;

	return 0;
}

int j9_handle_j9menu_antistatic(struct drm_dp_aux *aux,
		struct jmgpu_drm_dp_link *link)
{
	u8 values[2], value;
	int err;

	if (link->ops && link->ops->configure) {
		err = link->ops->configure(link);
		if (err < 0) {
			DRM_DEBUG_KMS("failed to configure DP link: %d\n", err);
			return err;
		}
	}

	values[0] = drm_dp_link_rate_to_bw_code(link->rate);
	values[1] = link->lanes;

	if (link->caps.max_downspread) {
		drm_dp_dpcd_writeb(aux, DP_DOWNSPREAD_CTRL, DP_SPREAD_AMP_0_5);
	} else {
		drm_dp_dpcd_writeb(aux, DP_DOWNSPREAD_CTRL, 0);
	}

	if (link->caps.enhanced_framing)
		values[1] |= DP_LANE_COUNT_ENHANCED_FRAME_EN;
	err = drm_dp_dpcd_write(aux, DP_LINK_BW_SET, values, sizeof(values));
	if (err < 0)
		return err;

	if (link->caps.channel_coding)
		value = DP_SET_ANSI_8B10B;
	else
		value = 0;

	err = drm_dp_dpcd_writeb(aux, DP_MAIN_LINK_CHANNEL_CODING_SET, value);
	if (err < 0)
		return err;

	if (link->caps.alternate_scrambler_reset) {
		err = drm_dp_dpcd_writeb(aux, DP_EDP_CONFIGURATION_SET,
				DP_ALTERNATE_SCRAMBLER_RESET_ENABLE);
		if (err < 0)
			return err;
	}

	return 0;
}

int j9_handle_j9m_homemakers(struct jmgpu_drm_dp_link *link,
		const struct drm_display_mode *mode,
		const struct drm_display_info *info)
{

	static const unsigned int rates[3] = { 162000, 270000, 540000 };

	static const unsigned int lanes[3] = { 1, 2, 4 };
	unsigned long requirement, capacity;
	unsigned int rate = link->max_rate;
	unsigned int i, j, count = 0;
	u8 bpc;

	bpc = info->bpc;
	if (bpc == 0) {
		bpc = 8;
	}

	requirement = mode->clock * bpc * 3;
	for (i = 0; i < ARRAY_SIZE(lanes) && lanes[i] <= link->max_lanes; i++) {
		for (j = 0; j < ARRAY_SIZE(rates) && rates[j] <= rate; j++) {

			capacity = lanes[i] * rates[j] * 8 * 9 / 10;
			if (capacity >= requirement) {
				DRM_DEBUG_KMS
					("using %u lanes at %u kHz (%lu/%lu kbps)\n",
					 lanes[i], rates[j], requirement, capacity);
				if (count != 0) {
					if (link->rate <= link->config_train[0].training_rate) {
						link->config_train[count].training_lanes = lanes[i];
						link->config_train[count++].training_rate = rates[j];
					}
				} else {
					link->config_train[count].training_lanes = lanes[i];
					link->config_train[count++].training_rate = rates[j];
				}
			}
		}
	}

	link->current_train_index = 0;
	DRM_DEBUG_KMS("current used train configure index = %d\n",
			link->current_train_index);
	DRM_DEBUG_KMS("current available train configure total = %d\n", count);
	link->lanes = link->config_train[link->current_train_index].training_lanes;
	link->rate = link->config_train[link->current_train_index++].training_rate;
	link->available_training_total = count;
	if (link->available_training_total == 0) {
		link->rate = link->max_rate;
		link->lanes = link->max_lanes;
		DRM_DEBUG_KMS("will use max lane and rate configure\n");
	}
	return 0;
}


void j9_handle_j9maths_unbrooding(struct j9_handle_j9_beterschap *train)
{
	struct jmgpu_drm_dp_link_train_set *request = &train->request;
	struct jmgpu_drm_dp_link_train_set *adjust = &train->adjust;
	unsigned int i;

	for (i = 0; i < 4; i++) {
		request->voltage_swing[i] = 0;
		adjust->voltage_swing[i] = 0;

		request->pre_emphasis[i] = 0;
		adjust->pre_emphasis[i] = 0;

		request->post_cursor[i] = 0;
		adjust->post_cursor[i] = 0;
	}

	train->pattern = DP_TRAINING_PATTERN_DISABLE;
	train->clock_recovered = false;
	train->channel_equalized = false;
}

static bool drm_dp_link_train_valid(const struct j9_handle_j9_beterschap *train)
{
	return train->clock_recovered && train->channel_equalized;
}

static int drm_dp_link_apply_training(struct jmgpu_drm_dp_link *link)
{
	struct jmgpu_drm_dp_link_train_set *request = &link->train.request;
	unsigned int lanes = link->lanes, *vs, *pe, *pc, i;
	struct drm_dp_aux *aux = link->aux;
	u8 values[4], pattern = 0;
	int err;

	err = link->ops->apply_training(link);
	if (err < 0) {
		DRM_DEBUG_KMS("failed to apply link training: %d\n", err);
		return err;
	}

	if (link->train.skip_swing == false) {
		vs = request->voltage_swing;
		pe = request->pre_emphasis;
		pc = request->post_cursor;


		for (i = 0; i < lanes; i++)
			values[i] = J9_HANDLE_J9MATHS_UNFEMINISE(vs[i]) |
				J9_HANDLE_J9MENU_INDIGENOUS(pe[i]);

		err = drm_dp_dpcd_write(aux, DP_TRAINING_LANE0_SET, values, lanes);
		if (err < 0) {
			DRM_DEBUG_KMS("failed to set training parameters: %d\n", err);
			return err;
		}
	}
















	if (link->train.pattern != DP_TRAINING_PATTERN_DISABLE)
		pattern |= DP_LINK_SCRAMBLING_DISABLE;

	pattern |= link->train.pattern;

	err = drm_dp_dpcd_writeb(aux, DP_TRAINING_PATTERN_SET, pattern);
	if (err < 0) {
		DRM_DEBUG_KMS("failed to set training pattern: %d\n", err);
		return err;
	}

	return 0;
}

static void drm_dp_link_train_wait(struct jmgpu_drm_dp_link *link)
{
	unsigned long min = 0;

	switch (link->train.pattern) {
	case DP_TRAINING_PATTERN_1:
		min = link->aux_rd_interval.cr;
		break;

	case DP_TRAINING_PATTERN_2:
	case DP_TRAINING_PATTERN_3:
		min = link->aux_rd_interval.ce;
		break;

	default:
		break;
	}

	if (min > 0)
		usleep_range(min, 2 * min);
}

static void drm_dp_link_get_adjustments(struct jmgpu_drm_dp_link *link,
		u8 status[DP_LINK_STATUS_SIZE])
{
	struct jmgpu_drm_dp_link_train_set *adjust = &link->train.adjust;
	unsigned int i;

	for (i = 0; i < link->lanes; i++) {
		adjust->voltage_swing[i] =
			drm_dp_get_adjust_request_voltage(status, i) >>
			DP_TRAIN_VOLTAGE_SWING_SHIFT;

		adjust->pre_emphasis[i] =
			drm_dp_get_adjust_request_pre_emphasis(status, i) >>
			DP_TRAIN_PRE_EMPHASIS_SHIFT;

		adjust->post_cursor[i] =
			drm_dp_get_adjust_request_post_cursor(status, i);
	}
}

static void drm_dp_link_train_adjust(struct j9_handle_j9_beterschap *train)
{
	struct jmgpu_drm_dp_link_train_set *request = &train->request;
	struct jmgpu_drm_dp_link_train_set *adjust = &train->adjust;
	unsigned int i;

	for (i = 0; i < 4; i++) {
		if (request->voltage_swing[i] != adjust->voltage_swing[i]) {
			request->voltage_swing[i] = adjust->voltage_swing[i];
			train->skip_swing = false;
		}
	}

	for (i = 0; i < 4; i++) {
		if (request->pre_emphasis[i] != adjust->pre_emphasis[i]) {
			request->pre_emphasis[i] = adjust->pre_emphasis[i];
			train->skip_swing = false;
		}
	}

	for (i = 0; i < 4; i++)
		if (request->post_cursor[i] != adjust->post_cursor[i]) {
			request->post_cursor[i] = adjust->post_cursor[i];
			train->skip_swing = false;
		}
}

static int drm_dp_link_recover_clock(struct jmgpu_drm_dp_link *link)
{
	u8 status[DP_LINK_STATUS_SIZE];
	int err;

	err = drm_dp_link_apply_training(link);
	if (err < 0)
		return err;

	drm_dp_link_train_wait(link);

	err = drm_dp_dpcd_read_link_status(link->aux, status);
	if (err < 0) {
		DRM_DEBUG_KMS("failed to read link status: %d\n", err);
		return err;
	}

	if (!drm_dp_clock_recovery_ok(status, link->lanes))
		drm_dp_link_get_adjustments(link, status);
	else
		link->train.clock_recovered = true;

	return 0;
}

static int drm_dp_link_clock_recovery(struct jmgpu_drm_dp_link *link)
{
	unsigned int repeat;
	int err;


	link->train.pattern = DP_TRAINING_PATTERN_1;

	for (repeat = 1; repeat < 5; repeat++) {
		err = drm_dp_link_recover_clock(link);
		if (err < 0) {
			DRM_DEBUG_KMS("failed to recover clock: %d\n", err);
			return err;
		}

		if (link->train.clock_recovered)
			break;

		drm_dp_link_train_adjust(&link->train);
	}

	return 0;
}

static int drm_dp_link_equalize_channel(struct jmgpu_drm_dp_link *link)
{
	struct drm_dp_aux *aux = link->aux;
	u8 status[DP_LINK_STATUS_SIZE];
	int err;

	err = drm_dp_link_apply_training(link);
	if (err < 0)
		return err;

	drm_dp_link_train_wait(link);

	err = drm_dp_dpcd_read_link_status(aux, status);
	if (err < 0) {
		DRM_DEBUG_KMS("failed to read link status: %d\n", err);
		return err;
	}

	if (!drm_dp_clock_recovery_ok(status, link->lanes)) {
		DRM_DEBUG_KMS("clock recovery lost while equalizing channel\n");
		link->train.clock_recovered = false;
		return 0;
	}

	if (!drm_dp_channel_eq_ok(status, link->lanes))
		drm_dp_link_get_adjustments(link, status);
	else
		link->train.channel_equalized = true;

	return 0;
}

static int drm_dp_link_channel_equalization(struct jmgpu_drm_dp_link *link)
{
	unsigned int repeat;
	int err;


	if (link->caps.tps3_supported)
		link->train.pattern = DP_TRAINING_PATTERN_3;
	else
		link->train.pattern = DP_TRAINING_PATTERN_2;

	link->train.skip_swing = true;

	for (repeat = 1; repeat < 5; repeat++) {
		err = drm_dp_link_equalize_channel(link);
		if (err < 0) {
			link->train.skip_swing = false;
			DRM_DEBUG_KMS("failed to equalize channel: %d\n", err);
			return err;
		}

		if (link->train.channel_equalized)
			break;

		drm_dp_link_train_adjust(&link->train);
	}
	link->train.skip_swing = false;

	return 0;
}

static int drm_dp_link_upgrade(struct jmgpu_drm_dp_link *link)
{
	if (link->current_train_index >= link->available_training_total) {
		return -EINVAL;
	}
	DRM_DEBUG_KMS("current used train configure index = %d\n",
			link->current_train_index);
	link->rate = link->config_train[link->current_train_index].training_rate;
	link->lanes = link->config_train[link->current_train_index].training_lanes;
	link->current_train_index++;

	return 0;
}

static void drm_dp_link_train_disable(struct jmgpu_drm_dp_link *link)
{
	int err;

	link->train.pattern = DP_TRAINING_PATTERN_DISABLE;

	err = drm_dp_link_apply_training(link);
	if (err < 0)
		DRM_DEBUG_KMS("failed to disable link training: %d\n", err);
}

static int drm_dp_link_train_full(struct jmgpu_drm_dp_link *link)
{
	int err;

retry:
	DRM_DEBUG_KMS("full-training link: %u lane%s at %u MHz\n",
			link->lanes, (link->lanes > 1) ? "s" : "", link->rate / 100);

	err = j9_handle_j9menu_antistatic(link->aux, link);
	if (err < 0) {
		DRM_DEBUG_KMS("failed to configure DP link: %d\n", err);
		return err;
	}

	err = drm_dp_link_clock_recovery(link);
	if (err < 0) {
		DRM_DEBUG_KMS("clock recovery failed: %d\n", err);
		goto out;
	}

	if (!link->train.clock_recovered) {
		DRM_DEBUG_KMS("clock recovery failed, upgrading link\n");

		err = drm_dp_link_upgrade(link);
		if (err < 0)
			goto out;

		goto retry;
	}

	DRM_DEBUG_KMS("clock recovery succeeded\n");

	err = drm_dp_link_channel_equalization(link);
	if (err < 0) {
		DRM_DEBUG_KMS("channel equalization failed: %d\n", err);
		goto out;
	}

	if (!link->train.channel_equalized) {
		DRM_DEBUG_KMS("channel equalization failed, upgrading link\n");

		err = drm_dp_link_upgrade(link);
		if (err < 0)
			goto out;

		goto retry;
	}

	DRM_DEBUG_KMS("channel equalization succeeded\n");

out:
	drm_dp_link_train_disable(link);
	return err;
}

static int drm_dp_link_train_fast(struct jmgpu_drm_dp_link *link)
{
	u8 status[DP_LINK_STATUS_SIZE];
	int err;

	DRM_DEBUG_KMS("fast-training link: %u lane%s at %u MHz\n",
			link->lanes, (link->lanes > 1) ? "s" : "", link->rate / 100);

	err = j9_handle_j9menu_antistatic(link->aux, link);
	if (err < 0) {
		DRM_DEBUG_KMS("failed to configure DP link: %d\n", err);
		return err;
	}


	link->train.pattern = DP_TRAINING_PATTERN_1;

	err = drm_dp_link_apply_training(link);
	if (err < 0)
		goto out;

	usleep_range(500, 1000);


	if (link->caps.tps3_supported)
		link->train.pattern = DP_TRAINING_PATTERN_3;
	else
		link->train.pattern = DP_TRAINING_PATTERN_2;

	err = drm_dp_link_apply_training(link);
	if (err < 0)
		goto out;

	usleep_range(500, 1000);

	err = drm_dp_dpcd_read_link_status(link->aux, status);
	if (err < 0) {
		DRM_DEBUG_KMS("failed to read link status: %d\n", err);
		goto out;
	}

	if (!drm_dp_clock_recovery_ok(status, link->lanes)) {
		DRM_DEBUG_KMS("clock recovery failed\n");
		err = -EIO;
	}

	if (!drm_dp_channel_eq_ok(status, link->lanes)) {
		DRM_DEBUG_KMS("channel equalization failed\n");
		err = -EIO;
	}

out:
	drm_dp_link_train_disable(link);
	return err;
}

int j9_handle_j9_beterschap(struct jmgpu_drm_dp_link *link)
{
	int err;

	j9_handle_j9maths_unbrooding(&link->train);

	if (link->caps.fast_training) {
		if (drm_dp_link_train_valid(&link->train)) {
			err = drm_dp_link_train_fast(link);
			if (err < 0)
				DRM_DEBUG_KMS("fast link training failed: %d\n", err);
			else
				return 0;
		} else {
			DRM_DEBUG_KMS("training parameters not available\n");
		}
	} else {
		DRM_DEBUG_KMS("fast link training not supported\n");
	}

	err = drm_dp_link_train_full(link);
	if (err < 0)
		DRM_DEBUG_KMS("full link training failed: %d\n", err);

	return err;
}


