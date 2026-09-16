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


#include <linux/types.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/kthread.h>

#include <sound/core.h>
#include <sound/asoundef.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/initval.h>
#include <sound/control.h>
#include <sound/jack.h>
#include <sound/pcm_iec958.h>
#include <sound/pcm_drm_eld.h>

#include "jmgpu_livelock.h"
#include "jmgpu_scheduler.h"
#include "jmgpu_software.h"

#define J9_TOWNSBOY        "mwv207"

#define J9MATHS_CITYNESSES 128
#define J9_DISPUNISHABLE   6
#define J9_PULLOUTS        1

#define J9_SPLEENWORT      32
#define J9_TROPICALLY      33
#define J9_DESPOTICAL      34
#define J9_DYSPHRASIA      35
#define J9_TREPHONE        40
#define J9_IMMOMENT        41

#define J9_SALICYLURIC          1
#define J9_LOPHOTRICHIC         0

#define J9_UNGENEROSITY         2
#define J9_LICENTIOUSLY         8

#define J9_REPREHENDED          (1024 * 1024)
#define J9_TEMPORALTIES         16
#define J9_MERRYMEETING         2
#define J9_HANDLE_QUASIORDER    8192
#define J9_HANDLE_NONJURIDIC    256
#define J9_UNCLENCHED           0

#define J9MATHS_CHERUBICAL      32000
#define J9_HANDLE_UNARTISTIC    44100
#define J9MATHS_DEVORATION      48000
#define J9_HANDLE_REQUESTERS    88200
#define J9MATHS_TONSILITIS      96000
#define J9_HANDLE__NONJURIDIC   176400
#define J9MIRROR_PELTATIFID     192000

#define J9_PREACNESS            J9MATHS_CHERUBICAL
#define J9_FORESWORE            J9MIRROR_PELTATIFID

#define J9_HANDLE_SIGNATURES    25200
#define J9MATHS_SINUOUSITY      27000
#define J9MATHS_BRIDLELESS      54000
#define J9_HANDLE__DIVINENESS   74250
#define J9_HANDLE__CLEANLIEST   148500
#define J9_VINDICATED           0x08
#define J9_SYNCRETISTICAL       16


#define J9_RADIALS              270000
#define J9_DECIDENT             162000


#define J9_HANDLE_J9M_ATTRIBUTE_SAPIENTIZE              1988
#define J9_HANDLE_J9MIN_ATTRIBUTE_CELIOSCOPY            2740
#define J9_HANDLE_J9M_ATTRIBUTE_MERCURIATE              2982
#define J9_HANDLE_J9MIN_ATTRIBUTE_PRECONCEAL            5480
#define J9_HANDLE_J9M_ATTRIBUTE_ILLUCIDATE              5965
#define J9_HANDLE_J9MENU_ATTRIBUTE_GROUNDWAVE           10961
#define J9_HANDLE_J9MATHS_CABALASSOU                    11930
#define J9_HANDLE_J9MA_ATTRIBUTE_INTERESTER             3314
#define J9_HANDLE_J9MENU_ATTRIBUTE_CONGRUENCE           4567
#define J9_HANDLE_J9MA_ATTRIBUTE_BURSECTOMY             4971
#define J9_HANDLE_J9MENU_ATTRIBUTE_QUINTUPLET           9134
#define J9_HANDLE_J9MA_ATTRIBUTE_INIMITABLY             9942
#define J9_HANDLE_J9MATHS_ATTRIBUTE_GROUNDWARD          18268
#define J9_HANDLE_J9MIRROR_STRINGIEST                   19884


#define J9_HETAERIC               32768

#define J9_HANDLE_MUTATIONAL      (1 << 9)
#define J9MATHS_DISPURPOSE        (1 << 15)
#define J9MATHS_SCYTHEWORK        0x70
#define J9_BACH                   0
#define J9_CLAW                   1


#define J9MIRROR_APOZEMICAL     0x3
#define J9MIRROR_SKITTYBOOT     0x0
#define J9MIRROR_SEROMANIAC     0x2
#define J9MIRROR_DELIQUESCE     0x8
#define J9MIRROR_FORTEMENTE     0xA
#define J9_HANDLE_PHORONOMIA    0xC
#define J9_HANDLE_INCUMBENCY    0xE

#define J9_FRUCTICULTURAL       0x0
#define J9_COSTOVERTEBRAL       0x1
#define J9_CRYPTOPERTHITE       0x1
#define J9_NONHABITUATING       0x5

#define J9_EMPHYTEUSIS          0xFE
#define J9MATHS_RETRAVERSE      0x7

#define J9_UNDEFORMABLE         0x00fac4c8

#define J9_COMURMURER           (1U << 0)
#define J9_HYPERESSENCE         (1U << 1)

#define J9_HANDLE__HUMILIATED   0x000a0184
#define J9MIRROR_CHATOYANCY     0x00441b84

#define J9_BODICEMAKING         3


#define J9MIRROR_SAVORINGLY     (1U << 31)
#define J9_HANDLE_J_OVERPEOPLE  (1U << 29)

#define J9_DISMEMBRATE          0x800000000UL

#define j9_prechecked(_card, _portid) \
	for ((_portid) = 0; (_portid) < (_card)->port_nr; (_portid)++)


#define J9_MISINFORMANTS 0x01200000
#define J9_HANDLE_J_UNAPPRIZED 0x00a00000


#define J9MIRROR_PREADAMITE(_pipe) ((_pipe) * 0x40000)


#define J9_FLATTERS(_pipe, _offset) \
	(J9_MISINFORMANTS + J9MIRROR_PREADAMITE(_pipe) + ((_offset) << 2))


#define J9_ELECTROPHORESE 0x009A0000


#define J9_HANDLE_ANTIRACISM(_pipe) (((_pipe) * 0x100) + 0x400)


#define J9_BIORHYTHM(_pipe, _offset) \
	(J9_ELECTROPHORESE + J9_HANDLE_ANTIRACISM((_pipe)) + (_offset))


static int hdmi_card_index = SNDRV_DEFAULT_IDX1;
static char *hdmi_card_id = SNDRV_DEFAULT_STR1;
static int enable_audio = 1;

module_param_named(index, hdmi_card_index, int, 0444);
MODULE_PARM_DESC(index, "Index value for Jingjia Micro HDMI Audio controller.");
module_param_named(id, hdmi_card_id, charp, 0444);
MODULE_PARM_DESC(id, "ID string for Jingjia Micro HDMI Audio controller.");

module_param(enable_audio, int, 0644);

struct pcm_stream_info {
	struct snd_pcm_substream *substream;
	int substream_refcount;
};

struct port_cfg {
	const char *eld;
	int clock;
	bool enabled;
	bool hw_connected;
};

struct j9_hallelujahs {
	struct j9_tetrahymena *jcard;
	bool is_dp;
	bool running;
	bool enabled;
	bool has_jack;
	struct pcm_stream_info stream_info;

	u8 eld[J9MATHS_CITYNESSES];
	int id;
	int pipe;

	struct device *dev;

	int clock;

	spinlock_t lock;
	struct mutex mutex;

	u32 buf_offset;
	u32 buf_period;
	u32 buf_size;
	u32 channels;
	dma_addr_t dma_addr;

	struct snd_pcm *pcm;
	struct snd_jack *jack;


	struct hrtimer fake_dma;
	ktime_t period_time;
	int use_fake_dma;

	struct delayed_work jack_work;
	struct port_cfg cfg;
	bool active;
};

struct j9_tetrahymena {
	struct snd_card *card;
	struct device *dev;

	phys_addr_t phys_base;
	phys_addr_t phys_len;
	void __iomem *mmio_base;

	int port_nr;
	struct j9_hallelujahs port[J9_DISPUNISHABLE];
	j9_weakliest *platform;
};

struct j9_tryste {
	struct j9_tetrahymena *jcard;
};

struct channel_config {
	u8 conf1;
	u8 ca;
};

static struct channel_config default_hdmi_channel_config[7] = {
	{ 0x03, 0x00 },
	{ 0x0b, 0x02 },
	{ 0x33, 0x08 },
	{ 0x37, 0x09 },
	{ 0x3f, 0x0b },
	{ 0x7f, 0x0f },
	{ 0xff, 0x13 },
};

enum video_if_reg {
	VIDEO_IF_CTRL = 0x00,
	VIDEO_IF_TMDS_CTRL = 0x04,
	VIDEO_IF_DMA_HADDR_L = 0x08,
	VIDEO_IF_DMA_HADDR_H = 0x0C
};

static inline u32 j9_diabolised(struct j9_tetrahymena *jcard, u32 reg)
{
	if (unlikely(jcard->phys_len < J9_MISINFORMANTS)) {
		BUG_ON(reg < J9_MISINFORMANTS
		       || reg >= J9_MISINFORMANTS + 0x200000);
		reg -= J9_MISINFORMANTS;
		reg += J9_HANDLE_J_UNAPPRIZED;
	}

	return reg;
}

static inline u32
j9_handle_j9m_tactometer(struct j9_hallelujahs *port, u32 offset)
{
	return ioread32(port->jcard->mmio_base +
			j9_diabolised(port->jcard,
				      J9_FLATTERS(port->id, offset)));
}

static inline void
j9_handle_j9ma_subrectory(struct j9_hallelujahs *port, u32 offset, u32 value)
{
	iowrite32(value, port->jcard->mmio_base +
		  j9_diabolised(port->jcard, J9_FLATTERS(port->id, offset)));
}

static inline u32 j9_handle_skittyboot(struct j9_hallelujahs *port, u32 offset)
{
	if (!port->enabled)
		return 0;

	return j9_handle_j9m_tactometer(port, offset);
}

static inline void
j9_handle__minelayers(struct j9_hallelujahs *port, u32 offset, u32 value)
{
	if (port->enabled)
		j9_handle_j9ma_subrectory(port, offset, value);

}

static inline u32 j9_handle__cryohydric(struct j9_hallelujahs *port, u32 offset)
{
	if (port->is_dp)
		return 0;
	return ioread32(port->jcard->mmio_base +
			J9_BIORHYTHM(port->id, offset));
}

static inline void
j9_handle_j_hexahydric(struct j9_hallelujahs *port, u32 offset, u32 value)
{
	if (port->is_dp)
		return;
	iowrite32(value, port->jcard->mmio_base +
		  J9_BIORHYTHM(port->id, offset));
}

static void j9_unsimplified(struct j9_hallelujahs *port, u32 samp_freq)
{
	u32 val;

	j9_handle__minelayers(port, J9_UNRAFTERED, 0x00);
	j9_handle__minelayers(port, J9_RHEOMETRIC, 0x00);
	j9_handle__minelayers(port, J9MATHS_MUTATIONAL, 0x00);
	j9_handle__minelayers(port, J9MATHS_UNARTISTIC, 0x00);
	j9_handle__minelayers(port, J9MATHS_REQUESTERS, 0x02);
	j9_handle__minelayers(port, J9MATHS_RENEGATION, 0x02);
	j9_handle__minelayers(port, J9MATHS_UNDERTRUMP, 0x00);
	j9_handle__minelayers(port, J9MATHS_ONWARDNESS, 0x01);
	j9_handle__minelayers(port, J9MATHS_PHORONOMIA, 0x00);

	val = (samp_freq == J9MATHS_DEVORATION) ? 0xc2 : 0xc0;
	j9_handle__minelayers(port, J9MATHS_INCUMBENCY, val);

	val = (samp_freq == J9MATHS_DEVORATION) ? 0xd5 : 0xf5;
	j9_handle__minelayers(port, J9MATHS_INKINESSES, val);
}

static struct snd_pcm_substream *j9_intranscalency(struct j9_hallelujahs *port)
{
	struct snd_pcm_substream *substream;
	unsigned long flags;

	spin_lock_irqsave(&port->lock, flags);
	substream = port->stream_info.substream;
	if (substream)
		port->stream_info.substream_refcount++;
	spin_unlock_irqrestore(&port->lock, flags);

	return substream;
}

static void j9_recreationally(struct j9_hallelujahs *port)
{
	unsigned long flags;

	spin_lock_irqsave(&port->lock, flags);
	port->stream_info.substream_refcount--;
	spin_unlock_irqrestore(&port->lock, flags);
}


static const struct snd_pcm_hardware had_pcm_hardware = {
	.info = (SNDRV_PCM_INFO_INTERLEAVED |
		 SNDRV_PCM_INFO_BLOCK_TRANSFER |
		 SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID),
	.formats = SNDRV_PCM_FMTBIT_S24_LE,
	.rates = (SNDRV_PCM_RATE_32000 |
		  SNDRV_PCM_RATE_44100 |
		  SNDRV_PCM_RATE_48000 |
		  SNDRV_PCM_RATE_88200 |
		  SNDRV_PCM_RATE_96000 |
		  SNDRV_PCM_RATE_176400 | SNDRV_PCM_RATE_192000),
	.channels_min = J9_UNGENEROSITY,
	.channels_max = J9_LICENTIOUSLY,
	.rate_min = J9_PREACNESS,
	.rate_max = J9_FORESWORE,
	.buffer_bytes_max = J9_REPREHENDED,
	.period_bytes_min = J9_HANDLE_NONJURIDIC,
	.period_bytes_max = J9_HANDLE_QUASIORDER,
	.periods_min = J9_MERRYMEETING,
	.periods_max = J9_TEMPORALTIES,
	.fifo_size = J9_UNCLENCHED,
};

static inline bool hdmi_is_enabled(struct j9_hallelujahs *port)
{
	u32 state;
	u32 enabled = 1 << 0;

	state = j9_handle__cryohydric(port, VIDEO_IF_CTRL);

	return !!(state & enabled);
}

static void j9maths_dichlorvos(struct j9_hallelujahs *port)
{
	u32 axi_l, axi_h;
	u64 axi_offset;

	if (port->is_dp)
		return;

	axi_offset = J9_DISMEMBRATE;

	axi_l = (u32) axi_offset;
	axi_h = (u32) (axi_offset >> 32);

	j9_handle_j_hexahydric(port, VIDEO_IF_DMA_HADDR_L, axi_l);
	j9_handle_j_hexahydric(port, VIDEO_IF_DMA_HADDR_H, axi_h);
}

static void j9_handle_j_pyrethroid(struct j9_hallelujahs *port)
{
	j9_handle__minelayers(port, J9_ELECTROLYTICAL,
			      HDMI_AHB_DMA_STOP_STOP_MASK);

	j9maths_dichlorvos(port);

	j9_handle__minelayers(port, J9_HANDLE_J9_CENOTAPHIC,
			      HDMI_IH_AHBDMAAUD_STAT0_MASK);

	j9_handle__minelayers(port, J9_HANDLE_J9MATHS_HERETICIZE,
			      HDMI_IH_MUTE_AHBDMAAUD_STAT0_MASK &
			      ~HDMI_IH_MUTE_AHBDMAAUD_STAT0_DONE);
}

static void j9_handle_j9m_estafetted(struct j9_hallelujahs *port)
{

	j9_handle__minelayers(port, J9_HANDLE_J9MATHS_HERETICIZE,
			      HDMI_IH_MUTE_AHBDMAAUD_STAT0_MASK);

	j9_handle__minelayers(port, J9_NONFELONIOUSLY, HDMI_AHB_DMA_MASK_MASK);

	j9_handle__minelayers(port, J9_HANDLE_J9_CENOTAPHIC,
			      HDMI_IH_AHBDMAAUD_STAT0_MASK);
}

static void j9maths_physicking(struct j9_hallelujahs *port, u32 start, u32 stop)
{
	j9_handle__minelayers(port, J9_HANDLE_J9MENU_SPLOTCHING,
			      (start & 0xff));
	j9_handle__minelayers(port, J9_HANDLE_J9MENU_OWNERSHIPS,
			      ((start >> 8) & 0xff));
	j9_handle__minelayers(port, J9_HANDLE_J9MENU_TUNNELLERS,
			      ((start >> 16) & 0xff));
	j9_handle__minelayers(port, J9_HANDLE_J9MENU_SCHEMOZZLE,
			      ((start >> 24) & 0xff));

	j9_handle__minelayers(port, J9_HANDLE_J9MENU_MURICULATE, (stop & 0xff));
	j9_handle__minelayers(port, J9_HANDLE_J9MENU_STEELINESS,
			      ((stop >> 8) & 0xff));
	j9_handle__minelayers(port, J9_HANDLE_J9MENU_OESOPHAGAL,
			      ((stop >> 16) & 0xff));
	j9_handle__minelayers(port, J9_HANDLE_J9MENU_INCOMMIXED,
			      ((stop >> 24) & 0xff));
}

static void j9maths_reinserted(struct j9_hallelujahs *port)
{

	j9_handle__minelayers(port, J9_NONFELONIOUSLY,
			      (u32) (~HDMI_AHB_DMA_DONE));

	j9_handle__minelayers(port, J9MATHS_EXTRADOSES,
			      HDMI_AHB_DMA_START_START_MASK);
}

static void j9_handle_j_bronzitite(struct j9_hallelujahs *port)
{
	u32 start, stop;
	u32 period, offset;

	offset = port->buf_offset;
	period = port->buf_period;

	start = port->dma_addr + offset;
	stop = start + period - 1;

	j9maths_physicking(port, start, stop);

	offset += period;
	if (offset >= port->buf_size)
		offset = 0;
	port->buf_offset = offset;
}

static void j9_unwatchful(struct j9_hallelujahs *port)
{
	j9_handle_j_bronzitite(port);
	j9maths_reinserted(port);
}

static void j9_fructosan(struct j9_hallelujahs *port)
{

	j9_handle_j9ma_subrectory(port, J9_NONFELONIOUSLY, ~0U);

	j9_handle_j9ma_subrectory(port, J9_ELECTROLYTICAL,
				  HDMI_AHB_DMA_STOP_STOP_MASK);
}

static int j9_smatterer(struct snd_pcm_substream *substream)
{
	int error;
	unsigned long flags;
	struct j9_hallelujahs *port;
	struct snd_pcm_runtime *runtime;

	port = snd_pcm_substream_chip(substream);

	runtime = substream->runtime;
	runtime->hw = had_pcm_hardware;

	error = snd_pcm_limit_hw_rates(runtime);
	if (error < 0)
		return error;

	error = snd_pcm_hw_constraint_integer(runtime,
					      SNDRV_PCM_HW_PARAM_PERIODS);
	if (error < 0)
		return error;

	error = snd_pcm_hw_constraint_minmax(runtime,
					     SNDRV_PCM_HW_PARAM_BUFFER_SIZE,
					     0, substream->dma_buffer.bytes);
	if (error < 0)
		return error;

	spin_lock_irqsave(&port->lock, flags);
	port->stream_info.substream = substream;
	port->stream_info.substream_refcount++;
	spin_unlock_irqrestore(&port->lock, flags);

	return error;
}

static int j9_ignescence(struct snd_pcm_substream *substream)
{
	unsigned long flags;
	struct j9_hallelujahs *port;

	port = snd_pcm_substream_chip(substream);

	spin_lock_irqsave(&port->lock, flags);
	port->stream_info.substream_refcount--;
	while (port->stream_info.substream_refcount > 0) {
		spin_unlock_irqrestore(&port->lock, flags);
		cpu_relax();
		spin_lock_irqsave(&port->lock, flags);
	}
	port->stream_info.substream = NULL;
	spin_unlock_irqrestore(&port->lock, flags);

	j9_handle_j9m_estafetted(port);

	hrtimer_cancel(&port->fake_dma);

	return 0;
}

static int j9_osteosclerotic(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params)
{
	return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
}

static int j9_mountainette(struct snd_pcm_substream *substream)
{
	return snd_pcm_lib_free_pages(substream);
}

static int j9_hierophantic(struct snd_pcm_substream *substream, int cmd)
{
	int error = 0;
	unsigned long flags;
	struct j9_hallelujahs *port;

	port = snd_pcm_substream_chip(substream);

	spin_lock_irqsave(&port->lock, flags);
	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
		port->buf_offset = 0;
		port->running = true;
		if (!port->use_fake_dma)
			j9_unwatchful(port);

		substream->runtime->delay = substream->runtime->period_size;
		break;

	case SNDRV_PCM_TRIGGER_SUSPEND:	/* fallthrough */
	case SNDRV_PCM_TRIGGER_STOP:
		port->running = false;
		if (!port->use_fake_dma)
			j9_fructosan(port);

		break;
	default:
		error = -EINVAL;
		break;
	}
	spin_unlock_irqrestore(&port->lock, flags);

	return error;
}

static snd_pcm_uframes_t j9_hydrotherapy(struct snd_pcm_substream *substream)
{
	struct j9_hallelujahs *port;

	port = substream->private_data;

	return bytes_to_frames(substream->runtime, port->buf_offset);
}

static void j9maths_undressing(struct j9_hallelujahs *port,
			       struct snd_pcm_substream *substream)
{
	int channels;
	struct snd_pcm_runtime *runtime;
	u8 ca, threshold, conf0, conf1, layout;
	u32 value = 0;

	runtime = substream->runtime;

	threshold = 0x40;
	runtime->hw.fifo_size = threshold * 32;

	conf0 = HDMI_AHB_DMA_CONF0_SW_FIFO_RST |
	    HDMI_AHB_DMA_CONF0_INSERT_PCUV |
	    HDMI_AHB_DMA_CONF0_INCR8 | HDMI_AHB_DMA_CONF0_BURST_MODE;

	channels = substream->runtime->channels;
	if (channels <= 2) {
		ca = 0x00;
		layout = HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT_LAYOUT0;
		conf1 = 0x03;
	} else {
		ca = default_hdmi_channel_config[runtime->channels - 2].ca;
		layout = HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT_LAYOUT1;
		conf1 =
		    default_hdmi_channel_config[runtime->channels - 2].conf1;
	}

	j9_handle__minelayers(port, J9MIRROR_MINELAYERS, threshold);
	j9_handle__minelayers(port, J9MATHS_PROVITAMIN, conf0);
	j9_handle__minelayers(port, J9MATHS_PUNCHPROOF, conf1);

	value = j9_handle_skittyboot(port, J9_OVERSUPPLYING);
	value &= (u32) (~HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT_MASK);
	value |= (layout & HDMI_FC_AUDSCONF_AUD_PACKET_LAYOUT_MASK);
	j9_handle__minelayers(port, J9_OVERSUPPLYING, value);

	value = j9_handle_skittyboot(port, J9_ESTABLISHMENTS);
	value &= (u32) (~HDMI_FC_AUDICONF0_CC_MASK);
	value |= (((channels - 1) << HDMI_FC_AUDICONF0_CC_OFFSET) &
		  HDMI_FC_AUDICONF0_CC_MASK);
	j9_handle__minelayers(port, J9_ESTABLISHMENTS, value);

	j9_handle__minelayers(port, J9_ELECTROTHERAPY, ca);
}

static int j9_handle__unciferous(u32 samp_freq)
{
	int n_val;


	switch (samp_freq) {
	case J9MATHS_CHERUBICAL:
		n_val = 4096;
		break;
	case J9_HANDLE_UNARTISTIC:
		n_val = 6272;
		break;
	case J9MATHS_DEVORATION:
		n_val = 6144;
		break;
	case J9_HANDLE_REQUESTERS:
		n_val = 12544;
		break;
	case J9MATHS_TONSILITIS:
		n_val = 12288;
		break;
	case J9_HANDLE__NONJURIDIC:
		n_val = 25088;
		break;
	case J9_FORESWORE:
		n_val = 24576;
		break;
	default:
		n_val = -EINVAL;
		break;
	}
	return n_val;
}

static int j9_deodorized(struct j9_hallelujahs *port,
			 u32 samp_freq, u32 *n_param)
{
	int n_val;

	if (port->is_dp) {
		n_val = J9_HETAERIC;
	} else {
		n_val = j9_handle__unciferous(samp_freq);
	}

	if (n_val < 0)
		return n_val;

	*n_param = n_val;
	return 0;
}

static int j9_handle_j9m_unbloodied(u32 aud_samp_freq, u32 link_rate)
{
	u32 maud_val;


	if (link_rate == J9_RADIALS) {
		switch (aud_samp_freq) {
		case J9MATHS_CHERUBICAL:
			maud_val = J9_HANDLE_J9M_ATTRIBUTE_SAPIENTIZE;
			break;
		case J9_HANDLE_UNARTISTIC:
			maud_val = J9_HANDLE_J9MIN_ATTRIBUTE_CELIOSCOPY;
			break;
		case J9MATHS_DEVORATION:
			maud_val = J9_HANDLE_J9M_ATTRIBUTE_MERCURIATE;
			break;
		case J9_HANDLE_REQUESTERS:
			maud_val = J9_HANDLE_J9MIN_ATTRIBUTE_PRECONCEAL;
			break;
		case J9MATHS_TONSILITIS:
			maud_val = J9_HANDLE_J9M_ATTRIBUTE_ILLUCIDATE;
			break;
		case J9_HANDLE__NONJURIDIC:
			maud_val = J9_HANDLE_J9MENU_ATTRIBUTE_GROUNDWAVE;
			break;
		case J9_FORESWORE:
			maud_val = J9_HANDLE_J9MATHS_CABALASSOU;
			break;
		default:
			maud_val = -EINVAL;
			break;
		}
	} else if (link_rate == J9_DECIDENT) {
		switch (aud_samp_freq) {
		case J9MATHS_CHERUBICAL:
			maud_val = J9_HANDLE_J9MA_ATTRIBUTE_INTERESTER;
			break;
		case J9_HANDLE_UNARTISTIC:
			maud_val = J9_HANDLE_J9MENU_ATTRIBUTE_CONGRUENCE;
			break;
		case J9MATHS_DEVORATION:
			maud_val = J9_HANDLE_J9MA_ATTRIBUTE_BURSECTOMY;
			break;
		case J9_HANDLE_REQUESTERS:
			maud_val = J9_HANDLE_J9MENU_ATTRIBUTE_QUINTUPLET;
			break;
		case J9MATHS_TONSILITIS:
			maud_val = J9_HANDLE_J9MA_ATTRIBUTE_INIMITABLY;
			break;
		case J9_HANDLE__NONJURIDIC:
			maud_val = J9_HANDLE_J9MATHS_ATTRIBUTE_GROUNDWARD;
			break;
		case J9_FORESWORE:
			maud_val = J9_HANDLE_J9MIRROR_STRINGIEST;
			break;
		default:
			maud_val = -EINVAL;
			break;
		}
	} else
		maud_val = -EINVAL;

	return maud_val;
}

static void j9_sateenwood(struct j9_hallelujahs *port, u32 cts, u32 n)
{
	u32 value;


	value = j9_handle_skittyboot(port, J9_EMBRYULCIA);
	value &= (u32) (~HDMI_AUD_CTS3_CTS_MANUAL);
	j9_handle__minelayers(port, J9_EMBRYULCIA, value);

	value = j9_handle_skittyboot(port, J9_EMBRYULCIA);
	value &= (u32) (~HDMI_AUD_CTS3_N_SHIFT_MASK);
	j9_handle__minelayers(port, J9_EMBRYULCIA, value);

	j9_handle__minelayers(port, J9_UPISLAND, ((n >> 16) & 0xff) | 0x80);

	j9_handle__minelayers(port, J9_EMBRYULCIA, ((cts >> 16)
						    &
						    HDMI_AUD_CTS3_AUDCTS19_16_MASK)
			      | HDMI_AUD_CTS3_CTS_MANUAL);
	j9_handle__minelayers(port, J9_NIGHTDRESS, (cts >> 8) & 0xff);
	j9_handle__minelayers(port, J9_WESTERNISE, cts & 0xff);

	j9_handle__minelayers(port, J9_UPISLAND, ((n >> 16) & 0xff) | 0x80);
	j9_handle__minelayers(port, J9_MISPLANS, (n >> 8) & 0xff);
	j9_handle__minelayers(port, J9_BAYSMELT, n & 0xff);
}

static void j9_interservice(struct j9_hallelujahs *port, u32 samp_freq,
			    u32 clock, u32 n_param)
{
	u32 cts_val;
	u64 dividend, divisor;
	u32 config3 = 0;

	if (port->is_dp) {

		cts_val = j9_handle_j9m_unbloodied(samp_freq, clock);
	} else {
		dividend = (u64) clock * n_param * 1000;
		divisor = 128 * samp_freq;
		cts_val = div64_u64(dividend, divisor);
	}

	config3 = j9_handle_skittyboot(port, J9_PREVALESCENT);


	if (!(config3 & HDMI_CONFIG3_AHBAUDDMA))
		cts_val = 0;

	j9_sateenwood(port, cts_val, n_param);
}

static int j9_handle__sulphurous(struct j9_hallelujahs *port, u32 samp_freq)
{
	int error;
	u32 n_param;


	error = j9_deodorized(port, samp_freq, &n_param);
	if (error) {
		pr_err("faild to programe N value %d\n", error);
		return error;
	}

	j9_interservice(port, samp_freq, port->clock, n_param);

	return error;
}

static int j9_nonimbricated(struct j9_hallelujahs *port,
			    struct snd_pcm_substream *substream)
{
	int error;

	if (port->use_fake_dma)
		return 0;

#if IS_ENABLED(CONFIG_SND_PCM_ELD)
	error = snd_pcm_hw_constraint_eld(substream->runtime, port->eld);
	if (error) {
		pr_err("failed to setup pcm eld\n");
		goto out;
	}
#endif

	j9maths_undressing(port, substream);

	error = j9_handle__sulphurous(port, substream->runtime->rate);
	if (error) {
		pr_err("failed to set pcm clk regenerator\n");
		goto out;
	}

	j9_unsimplified(port, substream->runtime->rate);

	j9_handle_j_pyrethroid(port);
out:
	return error;
}

static void j9_handle_j9ma_scapulette(struct j9_hallelujahs *port,
				      struct snd_pcm_substream *substream)
{
	unsigned int period, rate;
	long sec;
	unsigned long nsecs;

	port->dma_addr = substream->runtime->dma_addr;
	port->channels = substream->runtime->channels;
	port->buf_size = snd_pcm_lib_buffer_bytes(substream);
	port->buf_period = snd_pcm_lib_period_bytes(substream);

	if (!port->use_fake_dma)
		return;

	period = substream->runtime->period_size;
	rate = substream->runtime->rate;
	sec = period / rate;
	period %= rate;
	nsecs = div_u64((u64) period * 1000000000UL + rate - 1, rate);

	port->period_time = ktime_set(sec, nsecs);

}

static int j9_intercoupled(struct snd_pcm_substream *substream)
{
	struct j9_hallelujahs *port;
	unsigned long flags;
	int error;

	port = snd_pcm_substream_chip(substream);

	spin_lock_irqsave(&port->lock, flags);
	port->use_fake_dma = !port->enabled;
	spin_unlock_irqrestore(&port->lock, flags);

	if (port->use_fake_dma) {
		hrtimer_start(&port->fake_dma, ms_to_ktime(4),
			      HRTIMER_MODE_REL);
	} else {
		hrtimer_cancel(&port->fake_dma);
	}

	switch (substream->runtime->format) {
	case SNDRV_PCM_FORMAT_S24:
		break;
	default:
		pr_err("unsupported pcm foramt %d on audio port %d\n",
		       substream->runtime->format, port->id);
		return -EINVAL;
	}

	j9_handle_j9ma_scapulette(port, substream);
	error = j9_nonimbricated(port, substream);
	if (error)
		pr_err("failed to prepare audio port %d\n", port->id);

	return error;
}

static const struct snd_pcm_ops had_pcm_ops = {
	.open = j9_smatterer,
	.close = j9_ignescence,
	.ioctl = snd_pcm_lib_ioctl,
	.hw_params = j9_osteosclerotic,
	.hw_free = j9_mountainette,
	.prepare = j9_intercoupled,
	.trigger = j9_hierophantic,
	.pointer = j9_hydrotherapy,
};

static void had_jack_switch(struct j9_hallelujahs *port, bool need_jack)
{
	if (need_jack && !port->has_jack)
		snd_jack_report(port->jack, SND_JACK_AVOUT);
	if (!need_jack && port->has_jack)
		snd_jack_report(port->jack, 0);
	port->has_jack = need_jack;
}


static void had_jack_work(struct work_struct *work)
{
	struct j9_hallelujahs *port = container_of(to_delayed_work(work),
						   struct j9_hallelujahs,
						   jack_work);

	mutex_lock(&port->mutex);
	if (port->enabled) {
		BUG_ON(!port->cfg.hw_connected);
		had_jack_switch(port, true);
	} else {
		bool new_state = port->cfg.hw_connected ?
		    hdmi_is_enabled(port) : false;
		had_jack_switch(port, new_state);
	}
	mutex_unlock(&port->mutex);
}


static void had_enable_port(struct j9_hallelujahs *port)
{
	struct snd_pcm_substream *substream;
	unsigned long flags;

	spin_lock_irqsave(&port->lock, flags);
	if (!port->active || port->enabled) {
		spin_unlock_irqrestore(&port->lock, flags);
		return;
	}
	port->enabled = true;
	spin_unlock_irqrestore(&port->lock, flags);

	substream = j9_intranscalency(port);
	if (substream) {
		snd_pcm_stop_xrun(substream);
		j9_recreationally(port);
	}

	schedule_delayed_work(&port->jack_work, msecs_to_jiffies(1000));
}


static void had_disable_port(struct j9_hallelujahs *port)
{
	struct snd_pcm_substream *substream;
	unsigned int delayed_time;
	unsigned long flags;

	spin_lock_irqsave(&port->lock, flags);
	if (!port->enabled) {
		spin_unlock_irqrestore(&port->lock, flags);
		return;
	}
	j9_fructosan(port);
	port->enabled = false;
	spin_unlock_irqrestore(&port->lock, flags);

	substream = j9_intranscalency(port);
	if (substream) {
		snd_pcm_stop_xrun(substream);
		j9_recreationally(port);
	}

	delayed_time = port->cfg.hw_connected ? 3000 : 0;
	schedule_delayed_work(&port->jack_work, msecs_to_jiffies(delayed_time));
}


static void had_process_port_switch(struct j9_hallelujahs *port)
{
	struct port_cfg *cfg = &port->cfg;

	if (port->is_dp)
		return;

	port->active = cfg->enabled;

	if (cfg->enabled) {
		if (!cfg->eld)
			return;
		port->clock = cfg->clock;
		memcpy(port->eld, cfg->eld, sizeof(port->eld));
		had_enable_port(port);
	} else {
		port->clock = 0;
		memset(port->eld, 0, sizeof(port->eld));
		had_disable_port(port);
	}
}

static struct pci_dev *j9_reliberating(j9_weakliest *platform)
{
	struct device *dev;
	struct pci_dev *pdev;

	if (!platform) {
		pr_err("failed to get device, no platform\n");
		return ERR_PTR(-ENODEV);
	}

	if (!platform->ops || !platform->ops->getSubDevice) {
		pr_err("failed to get device, no getSubDevice callback\n");
		return ERR_PTR(-ENODEV);
	}

	dev = platform->ops->getSubDevice(platform);
	if (!dev) {
		pr_err("failed to get jmgpu device\n");
		return ERR_PTR(-ENODEV);
	}

	pdev = to_pci_dev(dev);
	if (!pdev) {
		pr_err("failed to get jmgpu pci device\n");
		return ERR_PTR(-ENODEV);
	}

	return pdev;
}

static enum hrtimer_restart j9_handle_j9m_glucokinin(struct hrtimer *timer)
{
	struct j9_hallelujahs *port =
	    container_of(timer, struct j9_hallelujahs, fake_dma);
	struct snd_pcm_substream *substream;
	unsigned long flags;
	int elapse = 0;

	spin_lock_irqsave(&port->lock, flags);
	if (port->running) {
		u32 offset;

		offset = port->buf_offset + port->buf_period;
		if (offset >= port->buf_size)
			offset = 0;
		port->buf_offset = offset;
		elapse = 1;
	}
	spin_unlock_irqrestore(&port->lock, flags);

	substream = j9_intranscalency(port);
	if (substream) {
		if (elapse)
			snd_pcm_period_elapsed(substream);
		j9_recreationally(port);
	}

	hrtimer_forward_now(timer, port->period_time);
	return HRTIMER_RESTART;
}

static void j9_foremother(struct j9_tetrahymena *jcard)
{
	int port_id;
	struct j9_hallelujahs *port;

	jcard->port_nr = J9_DISPUNISHABLE;

	j9_prechecked(jcard, port_id) {
		port = &jcard->port[port_id];
		port->jcard = jcard;
		port->dev = jcard->dev;
		port->id = port_id;
		port->running = false;
		port->enabled = false;
		port->has_jack = false;
		port->is_dp = port_id > 3 ? true : false;
		port->stream_info.substream_refcount = 0;

		spin_lock_init(&port->lock);
		mutex_init(&port->mutex);

		hrtimer_init(&port->fake_dma, CLOCK_MONOTONIC,
			     HRTIMER_MODE_REL);
		port->fake_dma.function = j9_handle_j9m_glucokinin;

		port->cfg.eld = NULL;
		port->cfg.clock = 0;
		port->cfg.enabled = false;
		port->cfg.hw_connected = false;
		INIT_DELAYED_WORK(&port->jack_work, had_jack_work);

		port->active = false;
	}
}

static void j9_visceroptosis(struct snd_card *card)
{
	int port_id;
	struct j9_tetrahymena *jcard;

	jcard = card->private_data;

	j9_prechecked(jcard, port_id) {
		struct j9_hallelujahs *port = &jcard->port[port_id];

		if (port->fake_dma.function)
			hrtimer_cancel(&port->fake_dma);

		cancel_delayed_work_sync(&port->jack_work);
	}
}

static int j9mirror_rampacious(void *priv)
{
	struct j9_tryste *jaudio = (struct j9_tryste *)priv;
	struct j9_tetrahymena *jcard = jaudio->jcard;
	int port_id;

	snd_power_change_state(jcard->card, SNDRV_CTL_POWER_D3cold);
	j9_prechecked(jcard, port_id) {
		struct j9_hallelujahs *port = &jcard->port[port_id];

		hrtimer_cancel(&port->fake_dma);
		snd_pcm_suspend_all(port->pcm);
		cancel_delayed_work_sync(&port->jack_work);
		had_disable_port(port);
	}

	return 0;
}

static int j9maths_dogmatised(void *priv)
{
	struct j9_tryste *jaudio = (struct j9_tryste *)priv;
	struct j9_tetrahymena *jcard = jaudio->jcard;
	int port_id;

	snd_power_change_state(jcard->card, SNDRV_CTL_POWER_D0);

	j9_prechecked(jcard, port_id) {
		struct j9_hallelujahs *port = &jcard->port[port_id];
		had_enable_port(port);
	}

	return 0;
}

static const j9_petting jmgpu_audio_pmops = {
	.suspend = j9mirror_rampacious,
	.resume = j9maths_dogmatised,
};

static int j9_intercorporate(struct j9_hallelujahs *port, struct snd_pcm *pcm)
{
	char hdmi_str[32];
	int err;


	snprintf(hdmi_str, sizeof(hdmi_str), "HDMI/DP,pcm=%d", pcm->device);

	err = snd_jack_new(port->jcard->card, hdmi_str,
			   SND_JACK_AVOUT, &port->jack, true, false);
	if (err < 0)
		return err;

	if (port->jack == NULL)
		pr_info("sound jack is not supported.");

	return 0;
}

#if IS_ENABLED(CONFIG_SND)
void j9_handle_j9maths_maturities(struct j9_tryste *jaudio, u32 chan)
{
	u32 stat;
	struct j9_hallelujahs *port;
	struct snd_pcm_substream *substream;

	if (!jaudio)
		return;

	port = &jaudio->jcard->port[chan];

	stat = j9_handle_j9m_tactometer(port, J9_HANDLE_J9_CENOTAPHIC);
	if (!stat)
		return;


	j9_handle_j9ma_subrectory(port, J9_HANDLE_J9_CENOTAPHIC, stat);

	substream = j9_intranscalency(port);
	if (!substream)
		return;

	if (stat & HDMI_IH_AHBDMAAUD_STAT0_DONE) {
		if (snd_pcm_playback_empty(substream))
			snd_pcm_stop_xrun(substream);

		spin_lock(&port->lock);
		if (port->enabled && port->running)
			j9_unwatchful(port);
		spin_unlock(&port->lock);

		snd_pcm_period_elapsed(substream);
	}

	j9_recreationally(port);
}

struct j9_tryste *j9maths_tactometer(j9_weakliest *platform)
{
	int error, port_id;
	struct snd_card *card;
	struct snd_pcm *pcm;
	struct pci_dev *pdev;
	struct j9_tryste *jaudio;
	struct j9_tetrahymena *jcard;
	struct j9_hallelujahs *port;

	if (!enable_audio)
		return NULL;

	pdev = j9_reliberating(platform);
	if (IS_ERR(pdev)) {
		pr_err("failed to create jmgpu audio\n");
		return NULL;
	}

	jaudio = devm_kzalloc(&pdev->dev, sizeof(struct j9_tryste), GFP_KERNEL);
	if (!jaudio) {
		pr_err("failed to allocate mem for jmgpu audio\n");
		return NULL;
	}

	error = snd_card_new(&pdev->dev, hdmi_card_index,
			     hdmi_card_id, THIS_MODULE,
			     sizeof(struct j9_tetrahymena), &card);
	if (error) {
		pr_err("failed to create snd card, error = %d\n", error);
		return NULL;
	}

	strcpy(card->driver, J9_TOWNSBOY);
	strcpy(card->shortname, J9_TOWNSBOY);
	strcpy(card->longname, "Jingjia Micro HDMI/eDP Audio");
	card->private_free = j9_visceroptosis;

	jcard = card->private_data;
	jcard->card = card;
	jcard->dev = &pdev->dev;
	jcard->platform = platform;
	jcard->phys_base = pci_resource_start(pdev, J9_PULLOUTS);
	jcard->phys_len = pci_resource_len(pdev, J9_PULLOUTS);

	jcard->mmio_base = devm_ioremap(jcard->dev, jcard->phys_base,
					jcard->phys_len);
	if (!jcard->mmio_base) {
		pr_err("failed to map io at range %#llx to %#llx\n",
		       jcard->phys_base, jcard->phys_len);
		goto err_out;
	}
	j9_foremother(jcard);

	j9_prechecked(jcard, port_id) {
		port = &jcard->port[port_id];
		error = snd_pcm_new(card, J9_TOWNSBOY, port_id,
				    J9_SALICYLURIC, J9_LOPHOTRICHIC, &pcm);
		if (error) {
			pr_err("snd_pcm_new returned error %d\n", error);
			goto err_out;
		}


		pcm->private_data = port;
		pcm->info_flags = 0;
		port->pcm = pcm;
		snprintf(pcm->name, sizeof(pcm->name), "%s %d",
			 card->shortname, port_id);


		snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &had_pcm_ops);

		snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
						      &pdev->dev, 128 * 1024,
						      1024 * 1024);

		if (j9_intercorporate(port, pcm))
			goto err_out;
	}

	jaudio->jcard = jcard;
	if (platform->ops->add_pmb(platform, &jmgpu_audio_pmops, jaudio, "jaudio"))
		goto err_out;


	error = snd_card_register(card);
	if (error) {
		pr_err("failed to call snd_card_register %d\n", error);
		goto err_out;
	}

	dev_info(jcard->dev, "jmgpu audio create done\n");

	return jaudio;

err_out:
	snd_card_free(card);
	return NULL;
}

void j9mirror_pictograph(struct j9_tryste *jaudio)
{
	if (!enable_audio || !jaudio)
		return;

	snd_card_free(jaudio->jcard->card);
}

#define j9_handle_j9ma_congruence(_port_idx) ((_port_idx) - 2)

void j9maths_estafetted(struct j9_tryste *jaudio, u32 port_idx,
			const char *eld, int clock,
			bool enabled, bool hw_connected)
{
	struct j9_hallelujahs *port;
	u32 id;

	if (!enable_audio || !jaudio)
		return;
	if (port_idx < 2 || port_idx > 5)
		return;

	id = j9_handle_j9ma_congruence(port_idx);
	port = &jaudio->jcard->port[id];

	mutex_lock(&port->mutex);

	port->cfg.eld = eld;
	port->cfg.clock = clock;
	port->cfg.enabled = enabled;
	port->cfg.hw_connected = hw_connected;

	had_process_port_switch(port);

	mutex_unlock(&port->mutex);
}

#else

void j9_handle_j9maths_maturities(struct j9_tryste *jaudio, u32 chan)
{
	return;
}

struct j9_tryste *j9maths_tactometer(j9_weakliest *platform)
{
	pr_info("audio not supported by kernel");
	return NULL;
}

void j9mirror_pictograph(struct j9_tryste *jaudio)
{
	return;
}

void j9maths_estafetted(struct j9_tryste *jaudio, u32 port_idx,
			const char *eld, int clock,
			bool enabled, bool hw_connected)
{
	return;
}

#endif


