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


#include "jmgpu_minimum.h"

#ifdef __linux__
#include <linux/ioctl.h>
#else
#define _IOC_NRBITS	8
#define _IOC_TYPEBITS	8
#define _IOC_SIZEBITS	14
#define _IOC_DIRBITS	2

#define _IOC_NRMASK	((1 << _IOC_NRBITS)-1)
#define _IOC_TYPEMASK	((1 << _IOC_TYPEBITS)-1)
#define _IOC_SIZEMASK	((1 << _IOC_SIZEBITS)-1)
#define _IOC_DIRMASK	((1 << _IOC_DIRBITS)-1)

#define _IOC_NRSHIFT	0
#define _IOC_TYPESHIFT	(_IOC_NRSHIFT+_IOC_NRBITS)
#define _IOC_SIZESHIFT	(_IOC_TYPESHIFT+_IOC_TYPEBITS)
#define _IOC_DIRSHIFT	(_IOC_SIZESHIFT+_IOC_SIZEBITS)
#define _IOC_NONE	0U
#define _IOC_WRITE	1U
#define _IOC_READ	2U

#define _IOC(dir,type,nr,size) \
	 (((dir) << _IOC_DIRSHIFT) | \
	 ((type) << _IOC_TYPESHIFT) | \
	 ((nr)   << _IOC_NRSHIFT) | \
	 ((size) << _IOC_SIZESHIFT))
#define _IOC_TYPECHECK(t) (sizeof(t))

#define _IO(type,nr)		_IOC(_IOC_NONE,(type),(nr),0)
#define _IOR(type,nr,size)	_IOC(_IOC_READ,(type),(nr),(_IOC_TYPECHECK(size)))
#define _IOW(type,nr,size)	_IOC(_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))
#define _IOWR(type,nr,size)	_IOC(_IOC_READ|_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))
#endif

#ifndef __63d8622f_H_
#define __63d8622f_H_

#ifdef __cplusplus
extern "C" {
#endif

#define J9_CUSTOMIZED  (1UL << 0)
#define J9_HARLOTRIES  (1UL << 1)
#define J9_FILAMENTOID (1UL << 2)

#define J9_FASCICULI   (1UL << 0)
#define J9_EUCAIRITE   (1UL << 1)
#define J9_NONDECISIVE (1UL << 2)
#define J9_PEACHING    (1UL << 3)
#define J9_REDODOING   (1UL << 4)
#define J9_DEMONESS    (1UL << 5)
#define J9_ELEVENSES   (1UL << 6)


	enum CoreType {

		HW_DECODER = 0,
		HW_DECODERJ,
		HW_BIGOCEAN,
		HW_VCMD,
		HW_MMU,
		HW_MMU_WR,
		HW_DEC400,
		HW_L2CACHE,
		HW_SHAPER,


		HW_NOC,
		HW_AXIFE,
		HW_APBFILTER,
		HW_CORE_MAX
	};

	struct core_desc {
		jmtUINT32 id;
		jmtUINT32 type;
		jmtUINT32 *regs;
		jmtUINT32 size;
		jmtUINT32 reg_id;
	};

	struct regsize_desc {
		jmtUINT32 slice;
		jmtUINT32 id;
		jmtUINT32 type;
		jmtUINT32 size;
	};

	struct core_param {
		jmtUINT32 slice;
		jmtUINT32 id;
		jmtUINT32 type;
		jmtUINT32 size;
		jmtUINT32 asic_id;
	};

	struct subsys_desc {
		jmtUINT32 subsys_num;
		jmtUINT32 subsys_vcmd_num;
	};


#define J9_PLECTOGNATHOUS  'l'


#define J9MIRROR_SPAWNEATER         _IO(J9_PLECTOGNATHOUS, 1)
#define J9_HANDLE_J_PICTOGRAPH      _IO(J9_PLECTOGNATHOUS, 2)
#define J9_HANDLE_UNFEMINISE        _IOR(J9_PLECTOGNATHOUS,  3, unsigned long *)
#define J9_HANDLE_BETUCKERED        _IOR(J9_PLECTOGNATHOUS,  4, struct regsize_desc *)
#define J9_UNDERWRITING             _IO(J9_PLECTOGNATHOUS,  5)
#define J9_ROUGHHOUSING             _IO(J9_PLECTOGNATHOUS,  6)
#define J9_HANDLE_J_DREARIHEAD      _IOR(J9_PLECTOGNATHOUS, 7, unsigned long *)
#define J9_HANDLE_FORGATHERS        _IOR(J9_PLECTOGNATHOUS, 8, unsigned int *)
#define J9_HANDLE_J9MA_CHOCKSTONE   _IOW(J9_PLECTOGNATHOUS, 9, struct core_desc *)
#define J9_HANDLE_J9M_PICTOGRAPH    _IOW(J9_PLECTOGNATHOUS, 10, struct core_desc *)
#define J9_HANDLE_J9M_TRAVERSALS    _IO(J9_PLECTOGNATHOUS, 11)
#define J9_HANDLE_J9M_RAMPACIOUS    _IO(J9_PLECTOGNATHOUS, 12)
#define J9_HANDLE_J9_CLINICIANS     _IO(J9_PLECTOGNATHOUS, 13)
#define J9_HANDLE_J9_HARBOUROUS     _IO(J9_PLECTOGNATHOUS, 14)
#define J9_HANDLE__UNBROODING       _IOWR(J9_PLECTOGNATHOUS, 15, struct core_desc *)
#define J9_HANDLE_UNBROODING        _IOWR(J9_PLECTOGNATHOUS, 16, struct core_desc *)
#define J9_HANDLE_J9MA_DREARIHEAD   _IOWR(J9_PLECTOGNATHOUS, 17, struct core_desc *)
#define J9_HANDLE_J9M_UNEJECTIVE    _IOWR(J9_PLECTOGNATHOUS, 18, struct core_desc *)
#define J9_HANDLE_J_RAMPACIOUS      _IOR(J9_PLECTOGNATHOUS, 19, int *)
#define J9MIRROR_REDUNDANCE         _IOWR(J9_PLECTOGNATHOUS, 20, struct core_param *)
#define J9_HANDLE_PUZZLEHEAD        _IOR(J9_PLECTOGNATHOUS, 21, unsigned long)
#define J9_HANDLE_J9MIN_SMOOTHBACK  _IOW(J9_PLECTOGNATHOUS, 22, struct core_desc *)
#define J9_HANDLE_J9MA_FIDUCIALLY   _IOWR(J9_PLECTOGNATHOUS, 23, struct core_desc *)
#define J9_HANDLE_J9MA_ASSIGNABLY   _IOWR(J9_PLECTOGNATHOUS, 24, jmtUINT32 *)
#define J9MATHS_SULPHUROUS          _IOWR(J9_PLECTOGNATHOUS, 25, struct subsys_desc *)
#define J9_ICHTHYOGRAPHIA           _IO(J9_PLECTOGNATHOUS, 26)
#define J9_HANDLE_PREOBSERVE        _IO(J9_PLECTOGNATHOUS, 29)
#define J9_DISILLUSIONISE 29



	struct addr_desc {
		void *virtual_address;
		unsigned int bus_address;
		unsigned int size;
	};

#define J9_BARBELLULATE  'm'

#define J9_HANDLE_J9M_UNDEBARRED    _IOWR(J9_BARBELLULATE, 1, struct addr_desc *)
#define J9_HANDLE_J9MIN_PHYTOMETRY  _IOWR(J9_BARBELLULATE, 2, struct addr_desc *)
#define J9_HANDLE_J_CHOCKSTONE      _IOWR(J9_BARBELLULATE, 3, unsigned int *)
#define J9_HANDLE__FORGATHERS 3


#define J9_UNKET (4)
	typedef enum {
		CORE_FLAG = 0,
		VCMD_FLAG = 0x10,
		DEC400_FLAG = 0x20,
		CACHE_FLAG = 0x30,
		MMU0_FLAG = 0x40,
		MMU1_FLAG = 0x41,
	} SUB_NODE;

	typedef enum {
		CODEC_DEC_FLAG = 0,
		CODEC_ENC_FLAG = 1,
	} CODEC_GROUP;

	enum {
		CORE_ENC = 0,
		CORE_ENCJ = 1,
		CORE_CUTREE = 2,
		CORE_DEC400 = 3,
		CORE_MMU = 4,
		CORE_L2CACHE = 5,
		CORE_AXIFE = 6,
		CORE_APBFT = 7,
		CORE_MMU_1 = 8,
		CORE_AXIFE_1 = 9,
		CORE_TYPE_MAX
	};

	struct nor32_parameter {
		jmtUINT32 data;
		jmtUINT32 id;
	};

	typedef union tag_jmu_ioctl_id {
		jmtUINT32 data;
		struct id_par {
			unsigned int sub_mod_idx:8;
			unsigned int codec_idx:8;
			unsigned int group_idx:8;
			unsigned int node_idx:8;
		} ID_PAR;
	} jmu_hd_ioctl_id;

	typedef struct {
		unsigned int type_info;
		unsigned long offset[CORE_TYPE_MAX];
		unsigned long regSize[CORE_TYPE_MAX];
		int irq[CORE_TYPE_MAX];
		jmtUINT32 id;
	} SUBSYS_CORE_INFO;

	typedef struct CoreWaitOut {
		jmtUINT32 job_id[J9_UNKET];
		jmtUINT32 irq_status[J9_UNKET];
		jmtUINT32 irq_num;
		jmtUINT32 id;
	} CORE_WAIT_OUT;

	typedef struct tag_jms_hd_enc_reg {
		jmtUINT32 slice_idx;
		jmtUINT32 core_id;
		jmtUINT32 core_type;
		jmtUINT32 offset;
		jmtUINT32 val;
	} j9_unperforate;

#define J9_OVERSOLICITOUS 'e'
#define J9MIRROR_GUNPOWDERY J9_OVERSOLICITOUS

#define J9MIRROR_PUZZLEHEAD              _IO(J9MIRROR_GUNPOWDERY, 1)
#define J9_HANDLE_J_FLIMSILYST           _IOR(J9MIRROR_GUNPOWDERY, 2, jmtUINT64 *)
#define J9_HANDLE_J_SUPERDUPER           _IOWR(J9MIRROR_GUNPOWDERY, 3, jmtUINT32 *)
#define J9_HANDLE_J9M_CLINICIANS         _IOR(J9MIRROR_GUNPOWDERY, 4, jmtUINT64 *)
#define J9_HANDLE_J9MA_TRAVERSALS        _IOR(J9MIRROR_GUNPOWDERY, 5, jmtUINT32 *)
#define J9_HANDLE_J9MIN_PREBENDATE       _IOWR(J9MIRROR_GUNPOWDERY, 6, struct nor32_parameter *)
#define J9_HANDLE_J9MIN_INSURRECTO       _IOW(J9MIRROR_GUNPOWDERY, 7, struct nor32_parameter *)
#define J9_HANDLE_J9_CENTERMOST          _IO(J9MIRROR_GUNPOWDERY, 8)
#define J9_HANDLE_J9M_UNDERREALM         _IOWR(J9MIRROR_GUNPOWDERY, 9, struct nor32_parameter *)
#define J9_HANDLE_J9M_BALLASTING         _IOR(J9MIRROR_GUNPOWDERY, 10, SUBSYS_CORE_INFO *)
#define J9_HANDLE_J9MENU_POLYGAMIAN      _IOR(J9MIRROR_GUNPOWDERY, 11, CORE_WAIT_OUT *)
#define J9_HANDLE_DELINEAVIT             _IO(J9MIRROR_GUNPOWDERY, 12)
#define J9_HANDLE_J9M_COMMANDERY         _IO(J9MIRROR_GUNPOWDERY, 13)
#define J9_HANDLE_J9_BALLASTING          _IOR(J9MIRROR_GUNPOWDERY, 14, j9_unperforate *)
#define J9_HANDLE_J9M_HARBOUROUS         _IOW(J9MIRROR_GUNPOWDERY, 15, j9_unperforate *)

#ifdef __cplusplus
}
#endif
#endif


