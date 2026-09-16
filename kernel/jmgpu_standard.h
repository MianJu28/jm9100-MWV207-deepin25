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



#ifndef __jmgpu_hal_base_h_
#define __jmgpu_hal_base_h_

#include "jmgpu_digital.h"
#include "jmgpu_directive.h"
#include "jmgpu_arraylist.h"
#include "jmgpu_engineer.h"
#include "jmgpu_pipeline.h"

#ifdef VSIMULATOR_DEBUG
#include "../../vsimulator/common/inc/vSimComm.hpp"
#endif

#ifdef __QNXNTO__
# define J9MIRROR_NONJURIDIC(string_index, first_to_check) \
        __attribute__((__format__(__printf__, (string_index), (first_to_check))))
#else
# define J9MIRROR_NONJURIDIC(string_index, first_to_check)
#endif

#ifdef __cplusplus
extern "C" {
#endif


typedef struct tag_jmk_OS *jmk_OS;
typedef struct _jmoHAL *jmoHAL;
typedef struct _jmoOS *jmoOS;
typedef struct _jmo2D *jmo2D;
typedef struct j9_gauge *jmsATOM_PTR;

typedef struct _jmo3D *jmo3D;
typedef struct _jmoCL *jmoCL;
typedef struct _jmoVX *jmoVX;
typedef struct tag_jms_FAST_FLUSH *jmsFAST_FLUSH_PTR;

typedef struct _jmoSURF *j9_boist;
typedef struct tag_jms_SURF_NODE *j9_mesosternebral;
typedef struct tag_jms_SURF_FORMAT_INFO *jmsSURF_FORMAT_INFO_PTR;
typedef struct tag_jms_POINT *jmsPOINT_PTR;
typedef struct tag_jms_SIZE *jmsSIZE_PTR;
typedef struct tag_jms_RECT *jmsRECT_PTR;
typedef struct tag_jms_BOUNDARY *jmsBOUNDARY_PTR;
typedef struct _jmoHARDWARE *jmoHARDWARE;
typedef struct _jmo_DEVICE              *jmo_DEVICE;
#if JMD_ENABLE_MULTI_DEVICE_MANAGEMENT
typedef struct _jms_HARDWARE_PROFILE     jms_HARDWARE_PROFILE;
#endif
typedef union  tag_jmu_VIDMEM_NODE *jmuVIDMEM_NODE_PTR;
typedef struct tag_jms_VIDMEM_NODE *jmkVIDMEM_NODE;
typedef struct tag_jms_VIDMEM_BLOCK *jmkVIDMEM_BLOCK;

#if J9_COMPATRIOT
typedef struct _jmoVG *jmoVG;
typedef struct tag_jms_COMPLETION_SIGNAL *jmsCOMPLETION_SIGNAL_PTR;
typedef struct tag_jms_CONTEXT_MAP *jmsCONTEXT_MAP_PTR;
#else
typedef void                           *jmoVG;
#endif

typedef struct _jmoFENCE *jmoFENCE;
typedef struct tag_jms_SYNC_CONTEXT *jmsSYNC_CONTEXT_PTR;

typedef struct tag_jms_USER_MEMORY_DESC *jmsUSER_MEMORY_DESC_PTR;

typedef enum tag_jme_virt_type {
        JMV_VIRT_TYPE_PHYSICAL = 0,
        JMV_VIRT_TYPE_PT,
        JMV_VIRT_TYPE_MDEV,
} jme_virt_type;

enum jm_vgpu_type_id {
		JM_VGPU_TYPE_ID_SUPER_0 = 1,
		JM_VGPU_TYPE_ID_SUPER_1,
		JM_VGPU_TYPE_ID_LARGE,
		JM_VGPU_TYPE_ID_MEDIUM,
		JM_VGPU_TYPE_ID_TINY
};


#define JM_VGPU_ID_BITS		8
#define JM_GPU_ID_OFFSET	JM_VGPU_ID_BITS
#define JM_GPU_ID_BITS		4
#define JM_PT_CORES_OFFSET	(JM_GPU_ID_OFFSET + JM_GPU_ID_BITS)
#define JM_PT_CORES_BITS	16
#define JM_GPU_TYPE_OFFSET	(JM_PT_CORES_OFFSET + JM_PT_CORES_BITS)
#define JM_GPU_TYPE_BITS	4
#define JM_VGPU_GET_TYPE(id)    ((id >> JM_GPU_TYPE_OFFSET) & ((1 << JM_GPU_TYPE_BITS) - 1))
#define JM_VGPU_GET_ID(id)      (id & ((1 << JM_VGPU_ID_BITS) - 1))

typedef struct tag_jms_NN_FIXED_FEATURE {
    jmtUINT  j9_squinnied;
    jmtUINT  j9_metricate;
    jmtUINT  j9_dilettant;
    jmtUINT  j9maths_decelerate;
    jmtUINT  j9maths_antrophose;
    jmtUINT  j9_flavorousness;
    jmtUINT  j9mirror_houndsbane;
    jmtUINT  j9_pennants;
    jmtUINT  j9_outpatient;
    jmtUINT  j9_corticoid;
    jmtUINT  j9_thamnium;
    jmtUINT  j9_soapboxes;
    jmtUINT  j9_handle_fiercening;
    jmtUINT  j9_unprotection;
    jmtUINT  j9_readvent;
    jmtUINT  j9_adventry;
    jmtUINT  j9_tuzzle;
    jmtUINT  j9_jcl_;
    jmtUINT  j9mirror_fiercening;
    jmtUINT  j9_namby;
    jmtUINT  j9maths_bulletlike;
    jmtUINT  j9_mammocks;
    jmtUINT  j9_handle_j9min_minelayers;
    jmtUINT  j9_handle_j9maths_epizoology;
    jmtUINT  j9_tristisonous;
    jmtUINT  j9_handle_j9m_siphuncled;
    jmtUINT  j9_oxygonal;
    jmtUINT  j9_ratatats;
    jmtUINT  j9_uncorner;
    jmtUINT  j9_bulldoze;
    jmtUINT  j9_handle_j9menu_preobserve;
    jmtUINT  vipMinAxiBurstSize;
    jmtUINT  streamProcessorExecCount;


    jmtUINT  j9mirror_cathedrals;
    jmtUINT  j9mirror_hypnotizes;
    jmtUINT  j9maths_trignesses;
    jmtUINT  j9maths_bloomeries;
    jmtUINT  j9_thalassography;
    jmtUINT  j9_hyperbarbarism;
    jmtUINT  j9_nonreturnable;
    jmtUINT  j9_somatogenetic;
    jmtUINT  smallAccumBits;
} j9_handle_eradiation;


typedef struct tag_jms_NN_CUSTOMIZED_FEATURE {
	jmtUINT  j9_manipulational;
	jmtUINT  j9_acidness;
	jmtUINT  j9_baccalaurean;
	jmtUINT  j9_anisopogonous;
	jmtUINT  j9maths_fractioned;
	jmtUINT  j9mirror_corporalcy;
	jmtUINT  j9_hylology;
	jmtUINT  j9_monedula;
	jmtFLOAT j9_topographic;
	jmtFLOAT j9_chloralizing;
	jmtFLOAT j9_unrhythmical;
	jmtFLOAT j9maths_distracted;
	jmtFLOAT j9mirror_rosaniline;
	jmtFLOAT j9mirror_entonement;
	jmtFLOAT j9_hyperaesthesia;
	jmtFLOAT j9maths_stamineous;
	jmtFLOAT j9maths_dovishness;
	jmtUINT  j9_outloves;
	jmtFLOAT j9_musings;
	jmtUINT  j9_rerack;
	jmtUINT  j9_skinflintiness;
	jmtUINT  j9_repertories;
	jmtUINT  j9_formalizations;
	jmtUINT  j9_unillustrious;
	jmtUINT  j9_departement;
	jmtUINT  j9maths_autoclasis;
} j9_handle_j9ma_ecstatical;


typedef struct tag_jms_NN_UNIFIED_FEATURE {
	jmtUINT  j9_consolidant;
	jmtUINT  j9_unseditiously;
	jmtUINT  j9_monomolecular;
	jmtUINT  j9_noninfluential;
	jmtUINT  j9_handle__antipapacy;
	jmtUINT  j9_handle_outleaping;
	jmtUINT  j9_discorded;
	jmtUINT  j9_woodpile;
	jmtUINT  j9_handle_j_cordwainer : 1;
	jmtUINT  j9_handle_j_tonsilitis : 1;
	jmtUINT  j9maths_refinanced : 1;
	jmtUINT  j9_handle__aberrative : 1;
	jmtUINT  j9_pinnipeds : 1;
	jmtUINT  j9_unreconsidered : 1;
	jmtUINT  j9_calcitreation : 1;
	jmtUINT  j9_forfaulture : 1;
	jmtUINT  j9_handle_j9min_sulphurous : 1;
	jmtUINT  axiSramSlowedDownByAddr:1;
	jmtUINT  slowNNReqArbitrationFix:1;
	jmtUINT  j9mirror_spermatium : 1;
	jmtUINT  j9mirror_tanglesome : 1;
	jmtUINT  j9_urethrostaxis : 1;
	jmtUINT  j9mirror_pinpricked : 1;
	jmtUINT  j9_handle_polybunous : 1;
	jmtUINT  j9_handle__attribute_russifying : 1;
	jmtUINT  j9_handle__attribute_lionizable : 1;
	jmtUINT  j9_handle__exultantly : 1;
	jmtUINT  j9_handle_attribute_monosilane : 1;
	jmtUINT  j9_handle_j9ma_attribute_prestoring : 1;
} j9_handle_j_epistomata;


typedef struct tag_jms_NN_DERIVIED_FEATURE {
	jmtUINT  j9_variate;
	jmtUINT  j9_ucc_;
	jmtUINT  j9_orom;
	jmtUINT  j9art;
	jmtFLOAT j9_uxoricide;
	jmtFLOAT j9_fashiousness;
	jmtFLOAT j9_handle_j9_ecchymosis;
	jmtFLOAT j9_handle_j9m_extradoses;
} jmsNN_DERIVED_FEATURE;

#define J9MATHS_TRINKETING(Obj)                                             \
    {                                                                      \
        if (Obj->sharedLock != J9_CHYAK) {                                  \
            (j9mirror_medicating(J9_CHYAK, Obj->sharedLock, J9_ACROMANIA));   \
        }                                                                  \
    }

#define J9_HANDLE_MURICULATE(Obj)                                           \
    {                                                                      \
        if (Obj->sharedLock != J9_CHYAK) {                                  \
            (j9mirror_fustigated(J9_CHYAK, Obj->sharedLock));                \
        }                                                                  \
    }

typedef struct tag_jms_SystemInfo {

	jmtUINT32 j9_rendezvouses;
}
j9_inthralling;


#define j9_antejuramentum                                    \
{                                                            \
    J9_CHYAK,               \
    J9_CHYAK,               \
    0,               \
    0,               \
    J9_CHYAK,               \
    0,               \
    0,               \
    J9_CHYAK,               \
    0,               \
    0,               \
    J9_CHYAK,               \
    J9_CHYAK,               \
    J9_CHYAK,               \
    J9_ANTIGONORRHEIC,               \
    J9_CHYAK,               \
    0,               \
    0,               \
    J9_YARELY,               \
    J9_YARELY,    \
    J9_YARELY,               \
    J9_CHYAK,               \
    J9_CHYAK,               \
    J9_CHYAK,               \
    J9_CHYAK,               \
    J9_CHYAK,               \
    J9_NONOBSESSIVELY,               \
    J9_CHYAK,                    \
    J9_CHYAK,                 \
    J9_YARELY,              \
    J9_CHYAK,              \
    0,              \
    0,              \
    0,              \
    0,              \
    0,              \
    0,              \
    0,              \
    0,              \
    0,              \
    0,              \
    0,              \
    0,              \
}


typedef struct tag_jms_DRIVER_TLS *jmsDRIVER_TLS_PTR;

typedef struct tag_jms_DRIVER_TLS {
	void (*destructor)(jmsDRIVER_TLS_PTR Tls);
}
j9_outcatching;

typedef struct tag_jms_TLS *jmsTLS_PTR;

typedef struct tag_jms_TLS {
	j9_misapprehended            currentType;
	j9_misapprehended            targetType;

    jmtUINT32                   j9_prebankruptcy;


    jmtUINT32                   currentDevIndex;


    jmoHARDWARE                 currentHardware;


    jmoHARDWARE                 defaultHardware;


    jmoHARDWARE                 hardware2D;
#if J9_COMPATRIOT
    jmoVGHARDWARE               vg;
    jmoVG                       engineVG;
#endif
#if J9_DEMISSNESS
    jmo3D                       engine3D;
#endif
#if J9_MONGRELISE
    jmo2D                       engine2D;
# if J9_BETIDING
    jmtUINT32                   j9_ecthlipsis;
# endif

#endif
    jmoVX                       engineVX;

    jmtBOOL                     copied;


	jmtHANDLE                   handle;

    jmtHANDLE                   graph;


    jmtBOOL                     release2DUpper;


    jmsDRIVER_TLS_PTR           driverTLS[J9_CALORIMETRICAL];

#if J9_HANDLE_J9M_ASSIGNABLY

    jmtUINT                     j9_depeach;
#endif
} j9_raw_;

typedef struct tag_jms_SURF_VIEW {
	j9_boist surf;
	jmtUINT j9_sylvius;
	jmtUINT j9_etymic;
	j9maths_eventuated cacheOperation;
} j9_preassumed;


typedef struct tag_jms_HAL_LIMITS {

	j9_organismal    chipModel;
	jmtUINT32       j9_exquisite;
	jmtUINT32       j9_tripodian;
	jmtUINT32       *chipFeatures;


	jmtUINT32         j9_chays;
	jmtUINT32         j9_weaves;
	jmtUINT32         j9_misdirections;
	jmtUINT32         j9_vaivode;

} j9_crowberries;


typedef struct tag_jms_HAL_CHIPIDENTITY {
	j9_organismal                chipModel;
	jmtUINT32                   j9_exquisite;
	jmtUINT32                   j9_bhagat;
	jmtUINT32                   j9_nascent;
	jmtUINT32                   j9sdu;
	j9_affixation                chipFlags;
	jmtUINT64                   j9_pitmenpitmirk;
	jmtUINT32                   hwDeviceID;
}
j9_handle_smifligate;

typedef struct tag_jms_CFG_ITEM {
	jmtUINT16  key;
	jmtUINT16  len;
	jmtPOINTER data;
}
j9_prolapsed;



j9_duopoly
j9mirror_cabalassou(IN jmtPOINTER Context, IN jmoOS Os, OUT jmoHAL *Hal);


j9_duopoly
j9_unpartableness(IN jmoHAL Hal);


j9_duopoly
j9_uninvigorative(IN jmtPOINTER Context, IN jmoOS Os, OUT jmoHAL *Hal);


j9_duopoly
j9_unsailorlike(IN jmoHAL Hal);


j9_duopoly
j9_ternatopinnate(IN jmoHAL Hal, IN j9_dionize Option);

j9_duopoly
j9_handle_penthouses(IN jmoHAL Hal,
                    IN j9_epiclastic FrameInfo,
                    IN j9_iodomercurate Op,
                    IN OUT jmtUINT *Val);


j9_duopoly
j9_sceptropherous(IN jmoHAL Hal, IN j9_dionize Option, IN jmtBOOL Value);

j9_duopoly
j9mirror_handyfight(IN jmoHAL Hal, OUT jmoHARDWARE *Hw);

#if J9_MONGRELISE

j9_duopoly
j9mirror_outweighed(IN jmoHAL Hal, OUT jmo2D *Engine);
#endif

#if J9_DEMISSNESS
j9_duopoly
j9_handle_j9min_crispation(IN jmoHAL Hal, OUT jmtINT *Hint);
j9_duopoly
j9mirror_tophetical(IN jmoHAL Hal, OUT jmo3D *Engine);
#endif

j9_duopoly
j9_handle_j_pansophies(IN jmoHAL Hal,
                      OUT jmtSTRING *ProductName,
                      OUT jmtUINT *PID);

j9_duopoly
j9_handle_j9m_attribute_outsavored(IN jmoHARDWARE Hardware,
                                  OUT jmtSTRING *ProductName,
                                  OUT jmtUINT *PID);

j9_duopoly
j9_handle_j_ingeminate(IN jmoHAL Hal,
                      IN jmtUINT CoreIndex,
                      IN jmtUINT FscaleValue,
                      IN jmtUINT ShaderFscaleValue);

j9_duopoly
jmo_HAL_CancelJob(jmoHAL Hal);

j9_duopoly
j9_handle_j_fustigated(OUT jmtUINT *FscaleValue,
                      OUT jmtUINT *MinFscaleValue,
                      OUT jmtUINT *MaxFscaleValue);

j9_duopoly
j9_handle_j9m_greenboard(jmtBOOL enable);

j9_duopoly
j9_handle_j9ma_dowagerism(IN jmtUINT32 Handle,
                         IN jmtUINT32 Flags,
                         OUT jmtINT32 *FD);

j9_duopoly
j9_handle_j9_probations(IN jmtUINT32 Handle, OUT jmtUINT32 *Name);

j9_duopoly
j9_handle_j9ma_reunionism(IN jmtUINT32 Name, OUT jmtUINT32 *Handle);

j9_duopoly
j9_handle_j9m_catchpenny(IN jmtUINT32 Handle, OUT jmtINT *Fd);

j9_duopoly
jmo_HAL_GetExportedVideoMemoryFd(IN jmtUINT32 Handle, OUT jmtINT *Fd);


j9_duopoly
j9_handle_j9min_concordity(IN jmoHAL Hal, IN j9_resolute Feature);

j9_duopoly
j9_handle_j9maths_attribute_theogonist(IN jmoHARDWARE Hardware, IN j9_resolute Feature);

j9_duopoly
j9_handle_j9menu_cyaphenine(IN jmoHAL Hal, IN j9_resolute Feature);


j9_duopoly
j9_handle_j9ma_marijuanas(IN jmoHAL Hal,
                         OUT j9_organismal *ChipModel,
                         OUT jmtUINT32 *ChipRevision,
                         OUT jmtUINT32 *ChipFeatures,
                         OUT jmtUINT32 *ChipMinorFeatures);

j9_duopoly
j9_handle_j9menu_attribute_sticharion(IN jmoHARDWARE Hardware,
                                     OUT j9_organismal *ChipModel,
                                     OUT jmtUINT32 *ChipRevision);

j9_duopoly
j9_handle_j9menu_puzzlehead(IN jmoHAL Hal,
                           IN jmtUINT32 SizeOfParam,
                           OUT j9_handle_smifligate *ChipIdentity);

j9_duopoly
j9_handle_j9min_pansophies(OUT jmtUINT32_PTR SuperTileMode);

j9_duopoly
j9_handle_j9maths_extendible(OUT jmtBOOL *AXI128Bits);

j9_duopoly
j9_handle_j9ma_attribute_overkeenly(IN j9_misapprehended Type,
                                   OUT j9_handle_j9m_podiatries *Mode,
                                   OUT jmtUINT32_PTR CoreIndex);

j9_duopoly
jmo_HAL_QueryHwDeviceIdByEnv(IN jmoHAL Hal,
                            OUT jmtUINT32 *DeviceID,
                            OUT jmtBOOL *HasEnv);

j9_duopoly
j9_unmannerliness(IN jmoHAL Hal,
                 IN j9_phpht Type,
                 OUT jmtUINT32 *Size,
                 OUT jmtADDRESS *GPUVirtAddr,
                 OUT jmtPHYS_ADDR_T *GPUPhysAddr,
                 OUT jmtUINT32 *GPUPhysName,
                 OUT jmtPHYS_ADDR_T *CPUPhysAddr);

#ifdef LINUX
jmtINT32
j9_handle_j9min_ingeminate(void);
void
j9_handle_j9_tangerines(void);
void
j9_handle_j9min_pasquiller(jmtSIZE_T Size);
#endif


j9_duopoly
j9_handle_j9m_spancelled(IN jmoHAL Hal,
                        OUT jmtUINT32 *InternalPhysName,
                        OUT jmtSIZE_T *InternalSize,
                        OUT jmtUINT32 *ExternalPhysName,
                        OUT jmtSIZE_T *ExternalSize,
                        OUT jmtUINT32 *ContiguousPhysName,
                        OUT jmtSIZE_T *ContiguousSize);


j9_duopoly
j9_immechanically(IN jmoHAL Hal, IN jmtUINT32 PhysName,
                 IN jmtSIZE_T NumberOfBytes, OUT jmtPOINTER *Logical);


j9_duopoly
j9mirror_dowagerism(IN jmoHAL Hal, IN jmtUINT32 PhysName,
                   IN jmtSIZE_T NumberOfBytes, IN jmtPOINTER Logical);


j9_duopoly
j9_handle_j9menu_beggarhood(IN jmoHAL Hal, IN jmtUINT32 PhysName,
                           IN jmtSIZE_T NumberOfBytes, IN jmtPOINTER Logical);


j9_duopoly
j9_handle_j9min_randannite(IN jmoOS Os,
                          IN jmtBOOL InUserSpace,
                          IN jmtBOOL InCacheable,
                          IN OUT jmtSIZE_T *Bytes,
                          OUT jmtUINT32 *Address,
                          OUT jmtPOINTER *Logical,
                          OUT jmtPOINTER *Handle);


j9_duopoly
j9_handle_j_cyaphenine(IN jmoOS Os, IN jmtPOINTER Handle);


j9_duopoly
j9_handle_j_disuniform(
	IN jmoOS Os,
	IN jmtPOINTER Handle,
	IN jmtBOOL InUserSpace,
	IN jmtBOOL InCacheable,
	OUT jmtUINT32 *Address,
	OUT jmtPOINTER *Logical
	);


j9_duopoly
j9_handle_j9min_cuckolding(
		IN jmtUINT32 node,
		jmtPOINTER   *data,
		jmtUINT32    *len
		);
j9_duopoly
j9_handle_j9min_greenboard(
		IN jmtUINT32 node,
		jmtPOINTER   data,
		jmtUINT32    len
		);

j9_duopoly
j9_varsovienne(IN jmoHAL Hal, IN jmtBOOL Stall);

#if J9_DEMISSNESS

j9_duopoly
j9_productivities(IN jmoHAL Hal);


j9_duopoly
j9_handle_j9menu_extendible(IN jmoHAL Hal, IN jmtADDRESS physical);

j9_duopoly
j9_handle_j9menu_mogigraphy(IN jmoHAL Hal,
                           IN j9_mesosternebral node,
                           IN jmtPOINTER nodeHeaderLocked,
                           IN jmtPOINTER logical);
#endif


j9_duopoly
j9maths_returnable(IN jmoHAL Hal,
                  OUT jmtINT32 *TileWidth2D,
                  OUT jmtINT32 *TileHeight2D,
                  OUT jmtINT32 *TileWidth3D,
                  OUT jmtINT32 *TileHeight3D);

j9_duopoly
j9_tarsadenitis(IN jmoHAL Hal);

#if J9_HANDLE_J9MATHS_SMIFLIGATE
j9_duopoly
j9_handle_maskalonge(IN jmoHAL Hal);

j9_duopoly
j9maths_incommixed(IN jmoHAL Hal, IN jmtCONST_STRING Title);
#endif


j9_duopoly
j9_handle__attribute_supercivil(IN jmoHAL Hal,
                               IN j9maths_nonnitrous State);

j9_duopoly
j9_handle_j9_attribute_outsavored(IN jmoHAL Hal,
                                 OUT j9maths_nonnitrous *State);


j9_duopoly
j9_handle__polytenies(IN jmoHAL Hal,
                     IN j9_ankylomerism FilterType);


j9_duopoly
j9_andragogy(IN jmoHAL Hal,
            IN OUT jmsHAL_INTERFACE_PTR Interface);
j9_duopoly
jmo_HAL_CallEx(IN jmoHARDWARE Hardware,
            IN OUT jmsHAL_INTERFACE_PTR Interface);

j9_duopoly
j9_handle__copresence(IN jmoHAL Hal,
                     IN OUT jmsHAL_INTERFACE_PTR Interface);


j9_duopoly
j9_observational(IN jmoHAL Hal, IN jmtUINT32 Index, IN jmtBOOL Start);


j9_duopoly
j9_handle_polytenies(IN jmoHAL Hal, IN jmtUINT32 Timer,
                    OUT jmtINT32_PTR TimeDelta);


j9_duopoly
j9maths_adposition(IN jmoHAL Hal, IN jmtUINT32 timeOut);

j9_duopoly
j9_handle_j9_azobenzene(IN jmoHAL Hal,
                       IN j9_misapprehended HardwardType);

j9_duopoly
j9_handle_j9_unequalize(IN jmoHAL Hal,
                       OUT j9_misapprehended *HardwardType);

j9_duopoly
j9_handle_j_greenboard(IN jmoHAL Hal, OUT jmtINT32 *Count);

j9_duopoly
j9_handle_j9m_crispation(IN jmoHAL Hal, OUT jmtUINT32 *Count);

j9_duopoly
j9_handle_j9m_polygamist(IN jmoHAL Hal, OUT jmtUINT32 *Count);

j9_duopoly
j9_handle_littermate(IN jmoHAL Hal,
                    OUT jmtINT32 *ClusterMinID,
                    OUT jmtINT32 *ClusterMaxID,
                    OUT jmtUINT32 *ClusterCount,
                    OUT jmtUINT32 *ClusterIDWidth);

j9_duopoly
jmo_HAL_QueryUscAttribCacheRatio(IN jmoHAL Hal,
                                OUT jmtUINT32 *UscAttribCacheRatio);

j9_duopoly
j9_handle_j_pasquiller(IN jmoHAL Hal,
                      IN j9_misapprehended Type,
                      OUT jmtUINT *Count,
                      OUT jmtUINT_PTR ChipIDs);

j9_duopoly
j9_handle_j9m_nutritious(IN jmoHAL Hal);

j9_duopoly
j9_handle__schemozzle(IN jmoHAL Hal);

j9_duopoly
j9_handle__splotching(IN jmoHAL Hal);


j9_duopoly
j9mirror_preinsured(IN jmoHAL Hal, OUT jmoVG *Engine);

j9_duopoly
j9_handle_j9_medicating(IN jmoHAL Hal,
                       IN jmtINT32 Chip,
                       OUT j9_crowberries *Limits);

j9_duopoly
j9_handle_j9m_azobenzene(IN jmoHAL Hal, IN jmtINT32 Chip, IN j9_resolute Feature);

j9_duopoly
jmo_HAL_SetDeviceIndex(IN jmoHAL Hal, IN jmtUINT32 DeviceIndex);

j9_duopoly
jmo_HAL_GetCurrentDeviceIndex(IN jmoHAL Hal, OUT jmtUINT32 *DeviceIndex);

j9_duopoly
j9_handle_polygamian(IN jmoHAL Hal, IN jmtUINT32 Core);

j9_duopoly
j9_handle_j9menu_smifligate(IN jmoHAL Hal, OUT jmtUINT32 *Core);

j9_duopoly
j9_handle_j9menu_tangerines(IN jmoHAL Hal,
                           IN j9_misapprehended Type,
                           IN jmtBOOL Init,
                           OUT jmtUINT32 *CoreIndex);

j9_duopoly
j9_handle_attribute_northlight(IN jmoHAL Hal,
                              IN j9_misapprehended Type,
                              IN jmtUINT32 j9_norgen,
                              IN jmtUINT32 *LocalCoreIndexs,
                              OUT jmtUINT32 *GlobalCoreIndexs);

j9_duopoly
j9_handle_j9mirror_preadapted(IN jmoHAL Hal,
                             IN j9_misapprehended Type,
                             IN jmtUINT32 j9_norgen,
                             IN jmtUINT32 *GlobalCoreIndexs,
                             OUT jmtUINT32 *LocalCoreIndexs);

j9_duopoly
j9_handle__penthouses(IN jmoHAL Hal, IN jmtBOOL Priority, IN jmtUINT32 ChannelId);

j9_duopoly
j9_handle__ownerships(IN jmtUINT32 SemaHandle, IN jmtBOOL SendSema);

j9_duopoly
j9_handle_j9mirror_mutilating(OUT jmtUINT32 *SemaHandle);

j9_duopoly
j9_handle_j9ma_animalness(IN jmtUINT32 SemaHandle);





j9_duopoly
j9_handle_j_concordity(IN jmtUINT32 Size, OUT jmtSHBUF *ShBuf);


j9_duopoly
j9_handle_j9_marijuanas(IN jmtSHBUF ShBuf);


j9_duopoly
j9mirror_acecaffine(IN jmtSHBUF ShBuf);


j9_duopoly
j9_handle__subcoastal(IN jmtSHBUF ShBuf, IN jmtCONST_POINTER Data, IN jmtUINT32 ByteCount);


j9_duopoly
j9_handle_advertency(IN jmtSHBUF ShBuf,
                    IN jmtPOINTER Data,
                    IN jmtUINT32 BytesCount,
                    OUT jmtUINT32 *BytesRead);


j9_duopoly
j9_handle_j9mirror_extractive(IN jmtBOOL Enable, OUT jmtBOOL *OldValue);

j9_duopoly
j9_handle_j9menu_bilocation(IN jmtUINT Alignment,
                           IN j9_reinoculated Type,
                           IN jmtUINT32 Flag,
                           IN OUT j9_phpht *Pool,
                           IN OUT jmtSIZE_T *Bytes,
                           OUT jmtUINT32_PTR Node);

j9_duopoly
j9_handle_j9_muscologic(IN jmtUINT32 Node,
                       IN jmtBOOL Cacheable,
                       IN jmeENGINE engine,
                       OUT jmtADDRESS *Address,
                       OUT jmtPOINTER *Logical);

j9_duopoly
j9_handle_j9ma_hereticize(IN jmtUINT32 Node,
                         IN jmtBOOL Cacheable,
                         IN jmeENGINE engine,
                         IN j9_handle_j9m_metrocarat Op,
                         OUT jmtADDRESS *Address,
                         OUT jmtPOINTER *Logical);

j9_duopoly
j9_handle_j9ma_gyniatrics(IN jmtUINT32 Node, IN j9_reinoculated Type, IN jmeENGINE engine);

j9_duopoly
j9_handle_j9menu_spermarium(IN jmtUINT32 Node,
                           IN j9_reinoculated Type,
                           IN jmeENGINE Engine,
                           IN jmtBOOL Sync,
                           IN j9_handle_j9m_metrocarat Op);

j9_duopoly
j9_handle_j9min_spancelled(IN jmtUINT32 Node);

#if J9_DEMISSNESS || J9_COMPATRIOT

j9_duopoly
j9_handle_j9_crispation(IN jmoHAL Hal,
                       OUT jmtUINT *MaxWidth,
                       OUT jmtUINT *MaxHeight,
                       OUT jmtUINT *MultiTargetCount,
                       OUT jmtUINT *MaxSamples);
#endif

j9_duopoly
j9_handle_j9min_nutritious(
	IN jmtUINT32 Node,
	IN jmtSIZE_T Offset,
	IN jmtSIZE_T Bytes
	);

j9_duopoly
j9_handle_j9ma_equipoised(
	IN jmtUINT32 Node,
	IN jmtSIZE_T Offset,
	IN jmtSIZE_T Bytes
	);

j9_duopoly
j9_handle_j_balsamroot(
	IN jmsUSER_MEMORY_DESC_PTR UserMemoryDesc,
	IN j9_reinoculated Type,
	OUT jmtUINT32_PTR Node,
	OUT j9_phpht * Pool
	);

j9_duopoly
j9_handle_j9menu_disuniform(
	OUT jmtUINT64_PTR ResetTimeStamp,
	OUT jmtUINT64_PTR ContextID
	);

j9_duopoly
j9_converginerved(IN jmtUINT32 Handle, IN jmtUINT32 TimeOut);

j9_duopoly
j9_handle_j_randannite(IN jmtSIGNAL Signal,
                      IN jmtSIGNAL AuxSignal,
                      IN jmtINT ProcessID,
                      IN j9_nonreflective FromWhere);

j9_duopoly
j9_handle_j9min_polygamist(IN jmtUINT32 Node[3],
                          IN jmtSHBUF ShBuf,
                          IN jmtSIGNAL Signal,
                          OUT jmtINT32 *Fd);

j9_duopoly
j9_handle__bisections(
	IN jmtUINT16 Key,
	OUT j9_prolapsed * *Item
	);

j9_duopoly
j9_handle__tunnellers(
	IN j9_prolapsed * Item
	);

j9_duopoly
j9mirror_accumbency(
	IN OUT jmtUINT32 *Width,
	IN OUT jmtUINT32 *Height,
	IN  j9_lifelessly Type,
	IN  j9_confirmative Format
	);

j9_duopoly
j9_handle_j9menu_misteacher(IN jmoHAL Hal, OUT jmtBOOL *Pending);

j9_duopoly
j9_handle_j9menu_prestoring(IN jmoHAL Hal, IN jmtBOOL Pending);

j9_duopoly
j9maths_oesophagal(IN jmoHAL Hal);

j9_duopoly
j9_handle_subcoastal(IN jmtPHYS_ADDR_T PhysicalAddress,
                    OUT jmtADDRESS *Address);

j9_duopoly
j9_handle_j9m_attribute_rifleproof(IN jmoHAL Hal,
                                  OUT jmtUINT32 *Capacity);

#if J9_HANDLE_REDUNDANCE
j9_duopoly
j9_handle_paramedics(jmoHAL Hal);
#endif

j9_duopoly
j9_handle__attribute_tetrameter(jmoHAL Hal, jmtBOOL AutoCommit);

j9_duopoly
j9_handle_j9mirror_northlight(jmoHAL Hal, jmtBOOL AutoSync);

#if JMD_ENABLE_MULTI_DEVICE_MANAGEMENT
j9_duopoly
jmo_HAL_SwitchContext(IN jmoHAL Hal,
                     IN jmoHARDWARE Hardware,
                     OUT jmoHARDWARE *SavedHardware,
                     OUT j9_misapprehended *SavedType,
                     OUT jmtUINT32 *SavedHwDeviceIndex,
                     OUT jmtUINT32 *SavedCoreIndex);

j9_duopoly
jmo_HAL_RestoreContext(IN jmoHAL Hal,
                      IN jmoHARDWARE Hardware,
                      IN j9_misapprehended Type,
                      IN jmtUINT32 HwDeviceIndex,
                      IN jmtUINT32 CoreIndex);

j9_duopoly
jmo_HAL_ShowDeviceInfo(jmoHAL Hal);
#endif


j9_duopoly
j9_conjecturer(void);


j9_duopoly
j9_recandescence(void);


jmtPOINTER
j9maths_cabalassou(IN j9_squamatine key);


void
j9maths_tophetical(IN j9_squamatine key, OUT jmtPOINTER value);


j9_duopoly
j9_handle_j9_smifligate(void);


j9_duopoly
j9_handle_j9ma_probations(void);


j9_duopoly
j9_handle_j9_acetylizer(void);


j9_duopoly
j9_handle_j9ma_muscologic(void);



j9_duopoly
j9_homophobic(OUT jmsTLS_PTR *TLS);


j9_duopoly
j9_stenochoric(IN jmsTLS_PTR Source);


j9_duopoly
j9_adstipulated(OUT jmsTLS_PTR *TLS);


j9_duopoly
j9mirror_azobenzene(IN j9_pulingly Key,
                   OUT jmsDRIVER_TLS_PTR *TLS);

j9_duopoly
j9mirror_greenboard(IN j9_pulingly Key, IN j9_outcatching *TLS);


void
j9_handle__indentwise(void);


j9_duopoly
j9_medievalistic(IN jmtPOINTER Context, OUT jmoOS *Os);


j9_duopoly
j9_imparasitic(IN jmoOS Os);

j9_duopoly
j9_handle__outweighed(IN jmoOS Os, OUT jmtUINT32_PTR BaseAddress);


j9_duopoly
j9_urobilinogen(IN jmoOS Os, IN jmtSIZE_T Bytes,
               OUT jmtPOINTER *Memory);

j9_duopoly
j9_speechcraft(IN jmoOS Os,
              IN jmtSIZE_T Bytes,
              IN jmtSIZE_T OrgBytes,
              OUT jmtPOINTER *Memory);


j9_duopoly
j9_handle_unequalize(IN jmoOS Os, IN jmtPOINTER Memory,
                    OUT jmtSIZE_T_PTR MemorySize);


j9_duopoly
j9_lutation(IN jmoOS Os, IN jmtPOINTER Memory);


j9_duopoly
j9_handle_j9menu_timeworker(IN jmoOS Os, IN jmtSIZE_T Bytes,
                           OUT jmtPOINTER *Memory);


j9_duopoly
j9_handle_j9_bilocation(IN jmoOS Os, IN jmtPOINTER Memory);


j9_duopoly
j9_handle__accumbency(IN jmoOS Os, IN jmtSIZE_T Bytes,
                     OUT jmtPOINTER *Memory);


j9_duopoly
j9_handle_medicating(IN jmoOS Os, IN jmtSIZE_T Bytes,
                    IN jmtSIZE_T OrgBytes, OUT jmtPOINTER *Memory);


j9_duopoly
j9_neurochemistry(IN jmoOS Os, IN jmtPOINTER Memory);


j9_duopoly
j9_handle_hereticize(IN jmoOS Os,
                    IN jmtUINT32 IoControlCode,
                    IN jmtPOINTER InputBuffer,
                    IN jmtSIZE_T InputBufferSize,
                    IN jmtPOINTER OutputBuffer,
                    IN jmtSIZE_T OutputBufferSize);

#define J9_SCALENOHEDRON(os, mem) \
    j9_lutation(os, mem); \
    mem = J9_CHYAK

#define J9_HANDLE_ATTRIBUTE_HYDRIATRIC(os, mem) \
    j9_handle_j9_bilocation(os, mem); \
    mem = J9_CHYAK

#define j9_overorganizing(os, mem) \
    jmkOS_Free(os, mem); \
    mem = J9_CHYAK

#define J9_CURRYCOMB 512


j9_duopoly
j9mirror_grouseward(
	IN jmoOS Os
	);


j9_duopoly
j9_ponchoed(IN jmoOS Os,
           IN jmtCONST_STRING FileName,
           IN j9_unconceded Mode,
           OUT jmtFILE *File);


j9_duopoly
j9_glideless(IN jmoOS Os, IN jmtFILE File);


j9_duopoly
j9_calamarmar(IN jmoOS Os, IN jmtCONST_STRING FileName);


j9_duopoly
j9_undusted(IN jmoOS Os,
           IN jmtFILE File,
           IN jmtSIZE_T ByteCount,
           IN jmtPOINTER Data,
           OUT jmtSIZE_T *ByteRead);


j9_duopoly
j9_blatterer(IN jmoOS Os,
            IN jmtFILE File,
            IN jmtSIZE_T ByteCount,
            IN jmtCONST_POINTER Data);


j9_duopoly
j9_scrubwood(IN jmoOS Os, IN jmtFILE File);


j9_duopoly
j9_crystalling(IN jmoOS Os, IN jmtINT FD);


j9_duopoly
j9_cardiophobe(IN jmoOS Os,
              IN jmtFILE File,
              IN jmtCONST_STRING Format,
              OUT jmtUINT *result);


j9_duopoly
j9_nonruling(IN jmoOS Os,
            IN jmtINT FD,
            OUT jmtINT *FD2);


j9_duopoly
j9_retrogradism(IN jmoOS Os,
               IN jmtFILE File,
               IN jmtBOOL Shared,
               IN jmtBOOL Block);


j9_duopoly
j9_quinquedentate(IN jmoOS Os, IN jmtFILE File);


j9_duopoly
j9_paradromic(IN jmoOS Os,
             IN jmtINT Domain,
             IN jmtINT Type,
             IN jmtINT Protocol,
             OUT jmtINT *SockFd);


j9_duopoly
j9maths_advertency(IN jmoOS Os, IN jmtINT SockFd);


j9_duopoly
j9_outsmarting(IN jmoOS Os,
              IN jmtINT SockFd,
              IN jmtCONST_POINTER HostName,
              IN jmtUINT Port);


j9_duopoly
j9_brilliantine(IN jmoOS Os, IN jmtINT SockFd, IN jmtINT How);


j9_duopoly
j9_jauntily(IN jmoOS Os,
           IN jmtINT SockFd,
           IN jmtSIZE_T ByteCount,
           IN jmtCONST_POINTER Data,
           IN jmtINT Flags);


j9_duopoly
j9maths_dowagerism(IN jmoOS Os, IN jmtINT SockFd,
                  IN jmtINT Seconds, IN jmtINT MicroSeconds);


j9_duopoly
j9_neopallium(IN jmoOS Os, IN jmtCONST_STRING VarName, OUT jmtSTRING *Value);


j9_duopoly
j9_dysgenesis(IN jmoOS Os, IN jmtCONST_STRING VarName, IN jmtSTRING Value);


j9_duopoly
j9_tobaccosim(IN jmoOS Os, IN jmtINT SizeInBytes, OUT jmtSTRING Buffer);


j9_duopoly
j9_forsteal(IN jmoOS Os, IN jmtCONST_STRING FileName, OUT jmtPOINTER Buffer);


j9_duopoly
j9_quenched(IN jmoOS Os, IN jmtFILE File, IN jmtUINT32 Offset, IN j9_sinistrorsal Whence);


j9_duopoly
j9_eatability(IN jmoOS Os, IN jmtFILE File, IN jmtUINT32 Position);


j9_duopoly
j9_ungruesome(IN jmoOS Os, IN jmtFILE File, OUT jmtUINT32 *Position);


j9_duopoly
j9_levitation(IN jmtCONST_STRING String,
             IN jmtCONST_STRING SubString,
             OUT jmtSTRING *Output);


j9_duopoly
j9_handle__acecaffine(IN jmtCONST_STRING String,
                     IN jmtINT8 Character,
                     OUT jmtSTRING *Output);

j9_duopoly
j9_broadlooms(IN jmoOS Os, IN jmtCONST_STRING String, OUT jmtSTRING *Target);


j9_duopoly
j9maths_preinsured(IN jmtSTRING Destination,
                  IN jmtSIZE_T DestinationSize,
                  IN jmtCONST_STRING Source);


j9_duopoly
j9_unreproachably(IN jmtSTRING Destination,
                 IN jmtSIZE_T DestinationSize,
                 IN jmtCONST_STRING Source);


j9_duopoly
j9_estipulate(IN jmtCONST_STRING String1, IN jmtCONST_STRING String2);


j9_duopoly
j9_untimeously(IN jmtCONST_STRING String1,
              IN jmtCONST_STRING String2,
              IN jmtSIZE_T Count);


j9_duopoly
j9_reconventional(IN jmtCONST_STRING String, OUT jmtFLOAT *Float);


j9_duopoly
jmo_OS_StrToDouble(IN jmtCONST_STRING String, OUT jmtDOUBLE* Double);


j9_duopoly
j9maths_underwatch(IN jmtCONST_STRING String, OUT jmtINT *Int);


j9_duopoly
j9_handle_muscologic(IN jmtCONST_STRING String, OUT jmtFLOAT *Float);


j9_duopoly
j9_deglutitious(IN jmtCONST_STRING String, OUT jmtINT *Int);

j9_duopoly
j9_foundation(IN jmtCONST_POINTER Memory1,
             IN jmtCONST_POINTER Memory2,
             IN jmtSIZE_T Bytes);

j9_duopoly
j9mirror_cuckolding(OUT jmtSTRING String,
                   IN jmtSIZE_T StringSize,
                   IN OUT jmtUINT *Offset,
                   IN jmtCONST_STRING Format,
                   ...)
J9MIRROR_NONJURIDIC(4, 5);

j9_duopoly
j9maths_indentwise(IN jmoOS Os, IN jmtCONST_STRING Library, OUT jmtHANDLE *Handle);

j9_duopoly
j9maths_accumbency(IN jmoOS Os, IN jmtHANDLE Handle);

j9_duopoly
j9_handle__handyfight(IN jmoOS Os,
                     IN jmtHANDLE Handle,
                     IN jmtCONST_STRING Name,
                     OUT jmtPOINTER *Function);

j9_duopoly
j9_keweenawite(IN jmoOS Os);

j9_duopoly
j9_handle_j9_outpursued(IN j9_handle__inoculable SignalHandlerType);

#if J9_HANDLE_J9MATHS_SMIFLIGATE
j9_duopoly
j9mirror_concordity(IN jmoOS Os);

j9_duopoly
j9_naphthinduline(IN jmoOS Os, IN jmtCONST_STRING Title);

j9_duopoly
j9_handle_j9m_ingeminate(IN jmoOS Os,
                        IN jmtBOOL Enable,
                        IN j9_craniometrist ProfileMode,
                        IN jmtCONST_STRING FileName);
#endif


j9_duopoly
j9_handle_j9m_attribute_cacodylate(OUT jmtSIZE_T *PhysicalSystemMemorySize);


j9_duopoly
j9_handle_j9_misteacher(IN jmoOS Os,
                       OUT jmtUINT32 *InternalPhysName,
                       OUT jmtSIZE_T *InternalSize,
                       OUT jmtUINT32 *ExternalPhysName,
                       OUT jmtSIZE_T *ExternalSize,
                       OUT jmtUINT32 *ContiguousPhysName,
                       OUT jmtSIZE_T *ContiguousSize);

j9_duopoly
j9_handle_attribute_preadapted(OUT jmtSTRING Name, IN jmtSIZE_T Size);





j9_duopoly
j9_handle_dowagerism(IN jmoOS Os, OUT jmsATOM_PTR *Atom);


j9_duopoly
j9maths_maskalonge(IN jmoOS Os, IN jmsATOM_PTR Atom);


j9_duopoly
j9_diplomyelia(IN jmoOS Os, IN jmsATOM_PTR Atom, OUT jmtINT32_PTR Value);


j9_duopoly
j9_fiscalizing(IN jmoOS Os, IN jmsATOM_PTR Atom, IN jmtINT32 Value);


j9_duopoly
j9_handle_animalness(IN jmoOS Os, IN jmsATOM_PTR Atom, OUT jmtINT32_PTR OldValue);


j9_duopoly
j9_handle_equipoised(IN jmoOS Os, IN jmsATOM_PTR Atom, OUT jmtINT32_PTR OldValue);

jmtHANDLE
j9_handle_j9min_outpursued(void);

jmtHANDLE
j9_handle_j9ma_unequalize(void);





jmtUINT32
j9_calorimeters(void);


j9_duopoly
j9_cordialness(jmtUINT64_PTR Time);


j9_duopoly
j9_motivationally(jmtUINT64_PTR CPUTime);


j9_duopoly
j9_handle__tophetical(jmtUINT32_PTR MaxRSS,
                     jmtUINT32_PTR IxRSS,
                     jmtUINT32_PTR IdRSS,
                     jmtUINT32_PTR IsRSS);


j9_duopoly
j9_madrasseh(IN jmoOS Os, IN jmtUINT32 j9kqc);



j9_duopoly
jmo_OS_DelayUs(IN jmoOS Os, IN jmtUINT32 j9kqc);




#ifdef _WIN32
typedef unsigned long jmtTHREAD_RETURN;
typedef unsigned long(__stdcall *jmTHREAD_ROUTINE)(void *Argument);
#else
typedef void *jmtTHREAD_RETURN;
typedef void *(*jmTHREAD_ROUTINE)(void *);
#endif


j9_duopoly
j9mirror_polygamist(IN jmoOS Os,
                   IN jmTHREAD_ROUTINE Worker,
                   IN jmtPOINTER Argument,
                   OUT jmtPOINTER *Thread);


j9_duopoly
j9maths_polygamian(IN jmoOS Os, IN jmtPOINTER Thread);





j9_duopoly
j9maths_streamlets(IN jmoOS Os, OUT jmtPOINTER *Mutex);


j9_duopoly
j9maths_paramedics(IN jmoOS Os, IN jmtPOINTER Mutex);


j9_duopoly
j9mirror_medicating(IN jmoOS Os, IN jmtPOINTER Mutex, IN jmtUINT32 Timeout);


j9_duopoly
j9mirror_fustigated(IN jmoOS Os, IN jmtPOINTER Mutex);





j9_duopoly
j9mirror_catchpenny(IN jmoOS Os, IN jmtBOOL ManualReset, OUT jmtSIGNAL *Signal);


j9_duopoly
j9_handle_reunionism(IN jmoOS Os, IN jmtSIGNAL Signal);


j9_duopoly
j9_alcoholate(IN jmoOS Os, IN jmtSIGNAL Signal, IN jmtBOOL State);


j9_duopoly
j9_redepreciation(IN jmoOS Os, IN jmtSIGNAL Signal, IN jmtUINT32 Wait);


j9_duopoly
j9_nonextraction(IN jmtSIGNAL RemoteSignal, OUT jmtSIGNAL *LocalSignal);


j9_duopoly
j9maths_deedholder(IN jmtSIGNAL Signal);





j9_duopoly
j9_handle_j9m_pasquiller(IN jmoOS Os, IN jmtSIGNAL Signal, OUT jmtINT *FenceFD);


j9_duopoly
j9_handle_j9maths_jaborandis(IN jmoOS Os, IN jmtINT FenceFD, IN jmtUINT32 Timeout);


j9_duopoly
j9_handle_j_plasmodial(IN jmoOS Os, IN jmtINT FenceFD, IN jmtUINT32 Timeout);





j9_duopoly
j9_handle_crispation(IN jmoOS Os, IN jmtUINT32 Address, IN jmtUINT32 Data);


j9_duopoly
j9mirror_nutritious(IN jmoOS Os, IN jmtUINT32 Address, OUT jmtUINT32 *Data);
j9_duopoly
j9_pseudopediform(
	IN jmoOS Os,
	IN jmtUINT32 Node,
	IN jmtPOINTER Logical,
	IN jmtSIZE_T Offset,
	IN jmtSIZE_T Bytes
	);

j9_duopoly
j9_interbranchial(
	IN jmoOS Os,
	IN jmtUINT32 Node,
	IN jmtPOINTER Logical,
	IN jmtSIZE_T Offset,
	IN jmtSIZE_T Bytes
	);

j9_duopoly
j9_handle_j_misteacher(
	IN jmoOS Os,
	IN jmtUINT32 Node,
	IN jmtPOINTER Logical,
	IN jmtSIZE_T Offset,
	IN jmtSIZE_T Bytes
	);

j9_duopoly
jmo_OS_CacheCleanEx(IN jmoOS Os, IN jmtUINT32 Node,
                   IN jmtPOINTER Logical, IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes);

j9_duopoly
jmo_OS_CacheFlushEx(IN jmoOS Os, IN jmtUINT32 Node,
                   IN jmtPOINTER Logical, IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes);

j9_duopoly
jmo_OS_CacheInvalidateEx(IN jmoOS Os, IN jmtUINT32 Node,
                        IN jmtPOINTER Logical, IN jmtSIZE_T Offset, IN jmtSIZE_T Bytes);


j9_duopoly
j9_handle_probations(IN jmoOS Os, IN jmtPOINTER Logical);

j9_duopoly
j9_handle__attribute_greenstuff(IN jmtPHYS_ADDR_T CPUPhysical,
                               OUT jmtPHYS_ADDR_T *GPUPhysical);

j9_duopoly
jmo_HAL_QueryCPUFrequency(IN jmtUINT32 CPUId, OUT jmtUINT32_PTR CPUFrequency);

j9_duopoly
j9_handle_j_beggarhood(IN jmoOS Os, OUT j9_inthralling *Info);

jmtBOOL
jmo_QueryIOMMUStatus(void);

#ifdef VSIMULATOR_DEBUG
j9_duopoly
j9_handle_attribute_bandcutter(INOUT VSIMULATOR_CALLBACK *Callback, IN jmtBOOL update);

j9_duopoly
j9_handle_j9_dichlorvos(IN jmtUINT32 frameworkType, IN jmtINT32 cmSize);

void
j9_handle_j9min_osmolality(IN jmtUINT32 hwConfigID, IN jmtUINT32 skippedExecution);
#endif




j9_duopoly
jmkOS_GetProfileTick(OUT jmtUINT64_PTR Tick);

j9_duopoly
jmkOS_QueryProfileTickRate(OUT jmtUINT64_PTR TickRate);

jmtUINT32
jmkOS_ProfileToMS(IN jmtUINT64 Ticks);

j9_duopoly
j9_handle__preinsured(OUT jmtUINT64_PTR Tick);

j9_duopoly
j9_handle_j9menu_outwriggle(OUT jmtUINT64_PTR TickRate);

#if J9_DEUTOPLASMIC
void j9_handle_j9m_phoronomia(void);

void j9_handle_j9_undressing(void);
#endif

#define _JMM_PROFILE_INIT(prefix, freq, start)                               \
    do {                                                                    \
        prefix##OS_QueryProfileTickRate(&(freq));                           \
        prefix##OS_GetProfileTick(&(start));                                \
    } while (J9_YARELY)

#define _JMM_PROFILE_QUERY(prefix, start, ticks)                             \
    do {                                                                    \
        prefix##OS_GetProfileTick(&(ticks));                                \
        (ticks) = ((ticks) > (start)) ? ((ticks) - (start))                 \
                                      : (~0ull - (start) + (ticks) + 1);    \
    } while (J9_YARELY)

#if J9_HANDLE_CONFICIENT
# define j9_undelusiveness(freq, start)    _JMM_PROFILE_INIT(jmk, freq, start)
# define j9maths_procellous(start, ticks)  _JMM_PROFILE_QUERY(jmk, start, ticks)
# define J9_MICROCEPHALUS(freq, start)     _JMM_PROFILE_INIT(jmo, freq, start)
# define J9_INTERLIBELLING(start, ticks)   _JMM_PROFILE_QUERY(jmo, start, ticks)
# define J9_ELOCUTIONISTS(x)               x
# define J9_UNPURPOSELIKE(x)               do { } while (J9_YARELY)
# define J9_HANDLE_J9M_HANDYFIGHT(x)       x
#   define J9_HANDLE_J9M_TOPHETICAL(x)       (typedef x)
#else
#   define j9_undelusiveness(start, freq)    do { } while (J9_YARELY)
#   define j9maths_procellous(start, ticks)  do { } while (J9_YARELY)
#   define J9_MICROCEPHALUS(start, freq)     do { } while (J9_YARELY)
#   define J9_INTERLIBELLING(start, ticks)   do { } while (J9_YARELY)
#   define J9_ELOCUTIONISTS(x)               do { } while (J9_YARELY)
#   define J9_UNPURPOSELIKE(x)               x
#   define J9_HANDLE_J9M_HANDYFIGHT(x)       do { } while (J9_YARELY)
#   define J9_HANDLE_J9M_TOPHETICAL(x)       x
#endif


#define J9LAG9       3.14159265358979323846f


jmtINT
jmkMATH_ModuloInt(IN jmtINT X, IN jmtINT Y);


jmtUINT32
j9_handle_acecaffine(IN jmtINT X);

jmtFLOAT
j9_handle_deedholder(IN jmtUINT32 X);

jmtUINT32
j9_handle_preinsured(IN jmtFLOAT X);

jmtBOOL
j9_handle_j_acetylizer(IN jmtFLOAT X, IN jmtFLOAT Y);

jmtUINT16
j9_handle_j9_ingeminate(IN jmtUINT8 X);

jmtUINT32
j9_handle_j9_spancelled(IN jmtUINT16 In);

jmtUINT16
j9_handle_j9_randannite(IN jmtUINT32 In);

jmtUINT32
j9_handle_j9_fustigated(IN jmtUINT32 In);

jmtUINT16
j9_handle_j9_pasquiller(IN jmtUINT32 In);

jmtUINT32
j9_handle_j9_nutritious(IN jmtUINT32 In);

jmtUINT16
j9_handle_j9_greenboard(IN jmtUINT32 In);

jmtUINT32
j9_handle_j9_pansophies(IN jmtUINT16 In);


typedef struct tag_jms_POINT {
	jmtINT32                    x;
	jmtINT32                    y;
}
j9_selles;

typedef struct tag_jms_SIZE {
	jmtINT32                    width;
	jmtINT32                    height;
}
j9_bandi;

typedef struct tag_jms_RECT {
	jmtINT32                    left;
	jmtINT32                    top;
	jmtINT32                    right;
	jmtINT32                    bottom;
}
j9_yinst;

typedef struct _jms2D_RGBU32
{
    jmtUINT32       R;
    jmtUINT32       G;
    jmtUINT32       B;
} jms2D_RGBU32;

typedef struct tag_jms_PIXEL {
    union {
        struct {
            jmtFLOAT r, g, b, a;
        } f;
        struct {
            jmtINT32 r, g, b, a;
        } i;
        struct {
            jmtUINT32 r, g, b, a;
        } ui;
    } color;

    jmtFLOAT  d;
    jmtUINT32 s;

} j9_skryer;






typedef struct tag_jms_FORMAT_COMPONENT {
	jmtUINT8                    start;
	jmtUINT8                    width;
}
j9_handle_bilocation;


typedef struct tag_jms_FORMAT_CLASS_TYPE_RGBA {
	j9_handle_bilocation         alpha;
	j9_handle_bilocation         red;
	j9_handle_bilocation         green;
	j9_handle_bilocation         blue;
}
j9_handle_j9min_extendible;


typedef struct tag_jms_FORMAT_CLASS_TYPE_YUV {
	j9_handle_bilocation         y;
	j9_handle_bilocation         u;
	j9_handle_bilocation         v;
}
j9_handle_j9ma_smifligate;


typedef struct tag_jms_FORMAT_CLASS_TYPE_INDEX {
	j9_handle_bilocation         value;
}
j9_handle_j9menu_adhesively;


typedef struct tag_jms_FORMAT_CLASS_TYPE_LUMINANCE {
	j9_handle_bilocation         alpha;
	j9_handle_bilocation         value;
}
j9_handle__attribute_bandcutter;


typedef struct tag_jms_FORMAT_CLASS_TYPE_BUMP {
	j9_handle_bilocation         alpha;
	j9_handle_bilocation         l;
	j9_handle_bilocation         v;
	j9_handle_bilocation         u;
	j9_handle_bilocation         q;
	j9_handle_bilocation         w;
}
j9_handle_j9min_prestoring;


typedef struct tag_jms_FORMAT_CLASS_TYPE_DEPTH {
	j9_handle_bilocation         depth;
	j9_handle_bilocation         stencil;
}
j9_handle_j9menu_ctenoidian;


typedef struct tag_jms_FORMAT_CLASs_TYPE_INTENSITY {
	j9_handle_bilocation         value;
}
j9_handle__attribute_preadapted;

typedef union tag_jmu_PIXEL_FORMAT_CLASS {
	j9_handle_j9min_prestoring       bump;
	j9_handle_j9min_extendible       rgba;
	j9_handle_j9ma_smifligate        yuv;
	j9_handle__attribute_bandcutter  lum;
	j9_handle_j9menu_adhesively      index;
	j9_handle_j9menu_ctenoidian      depth;
	j9_handle__attribute_preadapted  intensity;
}
jmu_PIXEL_FORMAT_CLASS;


typedef struct tag_jms_SURF_FORMAT_INFO {

	jmtCONST_STRING             formatName;


	j9_confirmative              format;
	j9_pseudochromia             fmtClass;


	j9mirror_ballasting          fmtDataType;


	jmtUINT8                    bitsPerPixel;


	jmtUINT                     j9_inthral;
	jmtUINT                     j9_bobbiner;


	jmtUINT                     j9_dewcap;



	jmtUINT8                    layers;

	jmtBOOL                     fakedFormat;




	jmtBOOL                     interleaved;


	jmtBOOL                     sRGB;


	j9_tabernacling              endian;


	jmu_PIXEL_FORMAT_CLASS       u;


	jmu_PIXEL_FORMAT_CLASS       uOdd;


	j9_confirmative              closestRenderFormat;

	jmtUINT                     j9_papicolar;

	const j9mirror_backvelder  *pixelSwizzle;


	j9_confirmative              closestTXFormat;
	jmtUINT                     j9_matzo;
	const j9mirror_backvelder  *txSwizzle;
	jmtBOOL                     txIntFilter;
}
j9_handle_prestoring;


typedef struct tag_jms_SURF_FRAMEBUFFER {
	jmtPOINTER                  logical;
	jmtUINT                     width, height;
	jmtINT                      stride;
	j9_confirmative              format;
}
j9_handle_extendible;

typedef union _jmu2D_STATE_VALUE
{
    jms2D_RGBU32                    minValue;
    jms2D_RGBU32                    maxMinReciprocal;
    jms2D_RGBU32                    stdReciprocal;
    jms2D_RGBU32                    meanValue;
    jmtUINT32                       stepReciprocal;
    jme2D_NORMALIZATION_MODE        normalizationMode;
    jmtBOOL                         byPassQuantization;
    jme2D_U8ToU10_CONVERSION_MODE   u8Tu10_Mode;
} jmu2D_STATE_VALUE;


typedef struct _jms2D_STATE_CONFIG
{
    jme2D_STATE_KEY             state;
    jmu2D_STATE_VALUE           value;
} jms2D_STATE_CONFIG;


extern j9_handle_bilocation J9MIRROR_ARTOPHORIA;
extern j9_handle_bilocation J9MIRROR_TETRAZOLYL;
extern j9_handle_bilocation J9MIRROR_SOLEMNIZES;
extern j9_handle_bilocation J9MIRROR_CORDWAINER;


j9_duopoly
j9maths_marijuanas(IN jmoHAL Hal,
                  IN jmtUINT Width,
                  IN jmtUINT Height,
                  IN jmtUINT Depth,
                  IN j9_lifelessly Type,
                  IN j9_confirmative Format,
                  IN j9_phpht Pool,
                  OUT j9_boist *Surface);

j9_duopoly
j9_handle_attribute_chronicled(IN jmoHAL Hal,
                              IN jmtUINT Width,
                              IN jmtUINT Height,
                              IN jmtUINT Depth,
                              IN j9_lifelessly Type,
                              IN j9_confirmative Format,
                              IN jmtPOINTER TileStatusLogical,
                              IN jmtPHYS_ADDR_T TileStatusPhysical,
                              IN jmtPOINTER Logical,
                              IN jmtPHYS_ADDR_T Physical,
                              OUT j9_boist *Surface);


j9_duopoly
j9_orthognathous(IN j9_boist Surface);

j9_duopoly
j9_handle_j9maths_sluggishly(IN j9_boist Surface);


j9_duopoly
j9_handle_j9_prestoring(IN j9_boist Surface,
                       IN jmtUINT Alignment,
                       IN jmtPOINTER Logical,
                       IN jmtPHYS_ADDR_T Physical);


j9_duopoly
j9_handle_pasquiller(IN j9_boist Surface,
                    IN jmtUINT Alignment,
                    IN jmtPOINTER Logical,
                    IN jmtADDRESS Address);


j9_duopoly
j9_handle_j9m_bilocation(IN j9_boist Surface,
                        OUT jmtUINT32 *Node,
                        OUT j9_phpht *Pool,
                        OUT jmtSIZE_T_PTR Bytes,
                        OUT jmtUINT32 *TsNode,
                        OUT j9_phpht *TsPool,
                        OUT jmtSIZE_T_PTR TsBytes);


j9_duopoly
jmo_SURF_QueryVidMemMultiNode(IN j9_boist Surface,
                             OUT jmtUINT32 *Node,
                             OUT j9_phpht *Pool,
                             OUT jmtSIZE_T_PTR Bytes,
                             OUT jmtUINT32 *Node2,
                             OUT j9_phpht *Pool2,
                             OUT jmtSIZE_T_PTR Bytes2,
                             OUT jmtUINT32 *Node3,
                             OUT j9_phpht *Pool3,
                             OUT jmtSIZE_T_PTR Bytes3);


j9_duopoly
j9_handle__gyniatrics(IN j9_boist Surface, IN j9mirror_undertribe ColorType);


j9_duopoly
j9_handle__animalness(IN j9_boist Surface, OUT j9mirror_undertribe *ColorType);


j9_duopoly
j9_handle_j_sluggishly(IN j9_boist Surface, IN j9_handle_homogonies ColorSpace);


j9_duopoly
j9_handle_j_spermarium(IN j9_boist Surface, OUT j9_handle_homogonies *ColorSpace);


j9_duopoly
j9_handle_greenboard(IN j9_boist Surface, IN j9_tragicomically Rotation);

j9_duopoly
j9_unideographic(IN j9_boist Surface);

#if J9_DEMISSNESS

j9_duopoly
j9_handle_attribute_jointuress(IN j9_boist Surface);


j9_duopoly
j9_handle_j9maths_obituarize(IN j9_preassumed *SurfView);


j9_duopoly
j9_handle__reunionism(IN j9_preassumed *SurfView);


j9_duopoly
j9_handle_j9ma_cuckolding(IN j9_preassumed *Surface);


j9_duopoly
j9_handle_j9menu_lamenesses(IN j9_preassumed *surfView, IN jmtUINT RtIndex);


j9_duopoly
j9_handle_j9min_acetylizer(IN j9_preassumed *SurfView, IN jmtBOOL Decompress);


j9_duopoly
j9_handle_j9m_outpursued(IN j9_preassumed *SurfView, IN jmtBOOL Decompress);
#endif


j9_duopoly
j9_uredinologist(IN j9_boist Surface,
                OUT jmtUINT *Width,
                OUT jmtUINT *Height,
                OUT jmtUINT *Depth);


j9_duopoly
j9_irretractable(IN j9_boist Surface,
                IN j9maths_acerbating InfoType,
                IN OUT jmtINT32 *Value);


j9_duopoly
j9_handle_j9_plasmodial(IN j9_boist Surface,
                       OUT jmtUINT *Width,
                       OUT jmtUINT *Height,
                       OUT jmtINT *Stride);


j9_duopoly
j9_handle__equipoised(IN j9_lifelessly Type,
                     IN j9_confirmative Format,
                     OUT jmtUINT *AddressAlignment,
                     OUT jmtUINT *XAlignment,
                     OUT jmtUINT *YAlignment);

j9_duopoly
j9_handle_j9ma_catchpenny(IN j9_boist Surf,
                         IN jmsPOINT_PTR RectOrigin,
                         IN jmsPOINT_PTR RectSize,
                         OUT jmsPOINT_PTR AlignedOrigin,
                         OUT jmsPOINT_PTR AlignedSize);


j9_duopoly
j9maths_gyniatrics(IN j9_boist Surface,
                  OUT OPTIONAL j9_lifelessly *Type,
                  OUT OPTIONAL j9_confirmative *Format);


j9_duopoly
j9_handle_j_jaborandis(IN j9_boist Surface,
                      OUT jmsSURF_FORMAT_INFO_PTR *formatInfo);


j9_duopoly
j9_handle_j9m_balsamroot(IN j9_boist Surface,
                        OUT j9_confirmative *Format);


j9_duopoly
j9maths_unequalize(IN j9_boist Surface, OUT j9_bytalks *Tiling);


j9_duopoly
j9_handle_attribute_promissive(IN j9_boist Surface,
                              OUT jmtUINT_PTR BottomBufferOffset);


j9_duopoly
j9_stoichiometry(
	IN j9_boist Surface,
	OUT j9_lifelessly * Type
	);


j9_duopoly
j9_oncologist(IN j9_boist Surface,
             IN OUT jmtADDRESS *Address,
             IN OUT jmtPOINTER *Memory);


j9_duopoly
j9_ultraperfect(IN j9_boist Surface, IN jmtPOINTER Memory);


j9_duopoly
j9_handle_j9_crawlerize(
	IN j9_boist Surface,
	OUT jmtUINT64 *Address
	);


j9_duopoly
j9mirror_stringiest(IN j9_boist Surface, IN j9_resolidify Flag);

j9_duopoly
j9mirror_bilocation(IN j9_boist Surface, IN j9_lifelessly Hints);

j9_duopoly
j9_handle_pansophies(IN j9_confirmative Format,
                    OUT jmsSURF_FORMAT_INFO_PTR *Info);


j9_duopoly
j9_handle_j9ma_crispation(IN jmsSURF_FORMAT_INFO_PTR Format,
                         OUT jmtUINT32_PTR ColorMask);


j9_duopoly
j9_pituitaries(IN j9_boist Surface);

j9_duopoly
j9_handle_attribute_saporosity(IN j9_preassumed *SurfView,
                              IN jmtBOOL ClearAsDirty);


j9_duopoly
j9_handle__dowagerism(IN j9_preassumed *SurView);


j9_duopoly
j9_unvaulting(IN j9_boist Surface,
             IN jmsPOINT_PTR Origin,
             IN jmsSIZE_PTR Size,
             IN jmtUINT32 Value,
             IN jmtUINT32 Mask);


j9_duopoly
j9_subnodulose(IN j9_boist SrcSurf,
              IN j9_boist DstSurf,
              IN jmsPOINT_PTR SrcOrigin,
              IN jmsPOINT_PTR DstOrigin,
              IN jmsSIZE_PTR Size,
              IN j9mirror_homogonies Mode);


j9_duopoly
j9_handle_j9ma_azobenzene(IN jmoHAL Hal, OUT j9_boist *Surface);


j9_duopoly
j9_commemorations(IN j9_boist Surface, IN j9_resolidify Flag, IN jmtBOOL Value);


j9_duopoly
j9maths_muscologic(IN j9_boist Surface,
                  IN j9_lifelessly Type,
                  IN j9_confirmative Format,
                  IN jmtUINT Stride,
                  IN jmtPOINTER Logical,
                  IN jmtUINT64 Physical);


j9_duopoly
j9maths_probations(IN j9_boist Surface,
                  IN jmtUINT X,
                  IN jmtUINT Y,
                  IN jmtUINT Width,
                  IN jmtUINT Height);


j9_duopoly
j9_tracheolingual(IN j9_boist Surface,
                 IN jmtUINT X,
                 IN jmtUINT Y,
                 IN jmtUINT Width,
                 IN jmtUINT Height,
                 IN jmtUINT Depth);

j9_duopoly
j9_handle__marijuanas(IN j9_boist Surface, IN jmtUINT Width, IN jmtUINT Height);


j9_duopoly
j9_handle_j9ma_nutritious(IN j9_boist Surface);


j9_duopoly
j9_handle_j9maths_anchylosed(IN j9_boist Surface, OUT jmtINT32 *ReferenceCount);


j9_duopoly
j9_handle_j9_jaborandis(IN j9_boist Surface, IN j9_schoenobatic Orientation);


j9_duopoly
j9_handle_j9ma_concordity(IN j9_boist Surface, OUT j9_schoenobatic *Orientation);

j9_duopoly
j9mirror_balsamroot(IN j9_mesosternebral Node,
                   IN jmtPOINTER Logical,
                   IN jmtSIZE_T Bytes,
                   IN j9maths_eventuated Operation);

j9_duopoly
jmo_SURF_NODE_CacheEx(IN j9_mesosternebral Node,
                   IN jmtPOINTER Logical,
                   IN jmtSIZE_T Offset,
                   IN jmtSIZE_T Bytes,
                   IN j9maths_eventuated Operation);

j9_duopoly
j9_handle_j_attribute_inimitably(IN j9_mesosternebral Node, IN jmtADDRESS Address);

j9_duopoly
j9_handle_j_attribute_bursectomy(IN j9_mesosternebral Node,
                                OUT jmtADDRESS *Physical,
                                OUT jmtADDRESS *Physical2,
                                OUT jmtADDRESS *Physical3,
                                OUT jmtADDRESS *PhysicalBottom);

jmtADDRESS
j9_handle_j9min_timeworker(IN j9_mesosternebral Node);


j9_duopoly
j9_pronunciations(IN j9_mesosternebral Node,
                 OUT jmtADDRESS *Address,
                 OUT jmtPOINTER *Memory);

j9_duopoly
j9mirror_misteacher(IN j9_mesosternebral Node, IN j9_lifelessly Type);


j9_duopoly
j9_handle__attribute_adhesively(IN j9_mesosternebral Node,
                               IN j9_lifelessly Type,
                               IN jmtSIZE_T Offset,
                               IN jmtSIZE_T Length,
                               IN j9maths_eventuated Operation);


j9_duopoly
j9_handle_j9min_bilocation(IN j9_boist Surface,
                          IN j9maths_eventuated Operation);

j9_duopoly
j9_withstrain(IN j9_boist Surface1, IN j9_boist Surface2);

j9_duopoly
j9mirror_acetylizer(IN j9_boist Surface,
                   IN jmtUINT oriw,
                   IN jmtUINT orih,
                   IN jmtUINT alignw,
                   IN jmtUINT alignh,
                   IN j9_confirmative fmt);


j9_duopoly
j9_handle_j9m_acetylizer(IN j9_boist Surface);


j9_duopoly
j9_handle_j9_spermarium(IN j9_boist Surface, OUT jmtUINT64 *TimeStamp);

j9_duopoly
j9_handle_j_extendible(IN j9_boist Surface, OUT jmtSHBUF *ShBuf);


j9_duopoly
j9_handle__deedholder(IN j9_boist Surface, IN jmtSHBUF ShBuf);


j9_duopoly
j9_handle_j9_mogigraphy(IN j9_boist Surface);


j9_duopoly
j9_handle_j_timeworker(IN j9_boist Surface);

#if (J9_DEMISSNESS || J9_COMPATRIOT)

j9_duopoly
j9_panlogical(IN j9_boist Surface, IN j9_boist Source);


j9_duopoly
j9mirror_smifligate(IN j9_boist Surface, IN jmtUINT Samples);


j9_duopoly
j9mirror_outpursued(IN j9_boist Surface, OUT jmtUINT_PTR Samples);


j9_duopoly
j9_handle_j9ma_polygamist(IN j9_boist Surface);
#endif

j9_duopoly
j9_handle_j9_sluggishly(IN jmoHAL Hal,
                       IN jmtUINT Width,
                       IN jmtUINT Height,
                       IN jmtUINT Stride,
                       IN jmtUINT Depth,
                       IN j9_lifelessly Type,
                       IN j9_confirmative Format,
                       IN jmtUINT32 Handle,
                       IN jmtUINT32 Flag,
                       OUT j9_boist *Surface);
#ifdef EMULATOR

j9_duopoly
jmo_SURF_WrapUserMemory_2(
    IN jmoHAL Hal,
    IN jmtUINT Width,
    IN jmtUINT Height,
    IN jmtUINT Stride,
    IN jmtUINT Depth,
    IN j9_lifelessly Type,
    IN j9_confirmative Format,
    IN jmtUINT32_PTR Address,
    IN jmtUINT32 Flag,
    OUT j9_boist * Surface
    );
#endif

j9_duopoly
j9_handle_j9maths_lamenesses(IN jmoHAL Hal,
                            IN jmtUINT Width,
                            IN jmtUINT Height,
                            IN j9_lifelessly Type,
                            IN j9_confirmative Format,
                            IN jmtUINT Stride[3],
                            IN jmtUINT32 Handle[3],
                            IN jmtUINT BufferOffset[3],
                            IN jmtUINT32 Flag,
                            OUT j9_boist *Surface);

j9_duopoly
j9_handle_j9_timeworker(IN j9_boist Surface, IN jmtINT TsFD);

#define J9_HANDLE_JABORANDIS 64
j9_duopoly
j9_handle_j9_extendible(IN j9_boist TargetSurface,
                       IN jmtUINT TargetSliceIndex,
                       IN j9_boist *SourceSurface,
                       IN jmtUINT *SourceSliceIndices,
                       IN jmtFLOAT *Weights,
                       IN jmtINT Count);


typedef struct tag_jms_HASH_MD5CTX {
	jmtBOOL   bigEndian;
	jmtSIZE_T bytes;
	jmtUINT32 states[4];
	jmtUINT8  buffer[64];
} j9_dealbuminize;

void
jmsHASH_MD5Init(j9_dealbuminize *ctx);
void
jmsHASH_MD5Update(j9_dealbuminize *ctx, const void *data, jmtSIZE_T bytes);
void
jmsHASH_MD5Final(j9_dealbuminize *ctx, jmtUINT8 digest[16]);



j9_duopoly
jmsRECT_Set(OUT jmsRECT_PTR Rect,
            IN jmtINT32 Left,
            IN jmtINT32 Top,
            IN jmtINT32 Right,
            IN jmtINT32 Bottom);


j9_duopoly
jmsRECT_Width(IN jmsRECT_PTR Rect, OUT jmtINT32 *Width);


j9_duopoly
jmsRECT_Height(IN jmsRECT_PTR Rect, OUT jmtINT32 *Height);


j9_duopoly
jmsRECT_Normalize(IN OUT jmsRECT_PTR Rect);


j9_duopoly
jmsRECT_IsEqual(IN jmsRECT_PTR Rect1, IN jmsRECT_PTR Rect2, OUT jmtBOOL *Equal);


j9_duopoly
jmsRECT_IsOfEqualSize(IN jmsRECT_PTR Rect1, IN jmsRECT_PTR Rect2, OUT jmtBOOL *EqualSize);

j9_duopoly
jmsRECT_RelativeRotation(IN j9_tragicomically Orientation,
                         IN OUT j9_tragicomically *Relation);

j9_duopoly
jmsRECT_Rotate(IN OUT jmsRECT_PTR Rect,
               IN j9_tragicomically Rotation,
               IN j9_tragicomically toRotation,
               IN jmtINT32 SurfaceWidth,
               IN jmtINT32 SurfaceHeight);


typedef struct tag_jms_BOUNDARY {
	jmtINT                      x;
	jmtINT                      y;
	jmtINT                      width;
	jmtINT                      height;
}
j9_aestethic;


typedef struct _jmoHEAP *j9_kicky;


j9_duopoly
j9maths_ownerships(IN jmoOS Os, IN jmtSIZE_T AllocationSize, OUT j9_kicky *Heap);


j9_duopoly
j9_adjudications(IN j9_kicky Heap);


j9_duopoly
j9_preformulation(IN j9_kicky Heap, IN jmtSIZE_T Bytes, OUT jmtPOINTER *Node);

j9_duopoly
j9_handle_j_stringiest(IN j9_kicky Heap, IN jmtPOINTER Memory, OUT jmtSIZE_T_PTR MemorySize);


j9_duopoly
j9_symbolatry(IN j9_kicky Heap, IN jmtPOINTER Node);

#if (J9_HANDLE_J9MATHS_SMIFLIGATE || J9_NOONED)

j9_duopoly
j9_handle__streamlets(IN j9_kicky Heap);

j9_duopoly
j9mirror_equipoised(IN j9_kicky Heap, IN jmtCONST_STRING Title);
#endif


void
j9_handle_catchpenny(IN jmtUINT32 Level);

void
j9_handle_gyniatrics(OUT jmtUINT32_PTR DebugLevel);

void
j9mirror_crispation(IN jmtUINT32 Zone, OUT jmtUINT32_PTR DebugZone);

void
j9mirror_spancelled(IN jmtUINT32 Zone);

void
j9mirror_pansophies(IN jmtCONST_STRING FileName);

void
j9_handle_j_tangerines(IN jmtBOOL Enable);

jmtFILE
j9_handle_j9_cyaphenine(IN jmtFILE fp);


void
jmkOS_DebugFatal(IN jmtCONST_STRING Message, ...);

void
j9_understrapping(IN jmtCONST_STRING Message, ...);

#if J9_MISDATING(J9_EUNUCHOIDISM)
# define J9_VISING        j9_understrapping
# define j9_binotic       jmkOS_DebugFatal
#elif J9_OVEREXPANSION
# define J9_VISING(...)
# define j9_binotic(...)
#else
JMM_INLINE static void
j9_epidendral(IN jmtCONST_STRING Message, ...)
{
}

# define J9_VISING        j9_epidendral
# define j9_binotic       j9_epidendral
#endif

#define J9_NOSTOCHINE(e)         (case e: return #e)

#define J9_CORROBOREED       -1
#define J9_IRASCIBILITY      0
#define J9_ERYTHROPOIESIS    1
#define J9_INTERLACING       2
#define J9_IODOMETRICALLY    3

void
jmkOS_DebugTrace(IN jmtUINT32 Level, IN jmtCONST_STRING Message, ...)
J9MIRROR_NONJURIDIC(2, 3);

void
j9_unsedulousness(IN jmtUINT32 Level, IN jmtCONST_STRING Message, ...)
J9MIRROR_NONJURIDIC(2, 3);

#if J9_MISDATING(J9_BLENNORRHOEA)
# define JMM_TRACE            j9_unsedulousness
# define JMM_kTRACE           jmkOS_DebugTrace
# define JMM_kTRACE_N(Level, ArgumentSize, ...) \
        jmkOS_DebugTrace(Level, __VA_ARGS__)
#elif J9_OVEREXPANSION
# define JMM_TRACE(...)
# define JMM_kTRACE(...)
# define JMM_kTRACE_N(...)
#else
    JMM_INLINE static void
    j9_brassieres(IN jmtUINT32 Level, IN jmtCONST_STRING Message, ...)
    {
    }

    JMM_INLINE static void
    j9_bronchomotor(IN jmtUINT32 Level, IN jmtUINT ArgumentSize, IN jmtCONST_STRING Message, ...)
    {
    }

# define JMM_TRACE            j9_brassieres
# define JMM_kTRACE           j9_brassieres
# define JMM_kTRACE_N         j9_bronchomotor
#endif


void
jmkOS_DebugTraceZone(IN jmtUINT32 Level, IN jmtUINT32 Zone, IN jmtCONST_STRING Message, ...);

void
j9_handle__cabalassou(IN jmtUINT32 Level, IN jmtUINT32 Zone, IN jmtCONST_STRING Message, ...);

#if J9_MISDATING(J9_BLENNORRHOEA)
# define JMM_TRACE_ZONE      j9_handle__cabalassou
# define JMM_kTRACE_ZONE     jmkOS_DebugTraceZone
# define JMM_kTRACE_ZONE_N(Level, Zone, ArgumentSize, ...) \
        jmkOS_DebugTraceZone(Level, Zone, __VA_ARGS__)
#elif J9_OVEREXPANSION
# define JMM_TRACE_ZONE(...)
# define JMM_kTRACE_ZONE(...)
# define JMM_kTRACE_ZONE_N(...)
#else
    JMM_INLINE static void
    j9maths_outbustled(IN jmtUINT32 Level,
                       IN jmtUINT32 Zone,
                       IN jmtCONST_STRING Message, ...)
    {
    }

    JMM_INLINE static void
    j9_handle_klendusive(IN jmtUINT32 Level,
                         IN jmtUINT32 Zone,
                         IN jmtUINT ArgumentSize,
                         IN jmtCONST_STRING Message,
                         ...)
    {
    }

# define JMM_TRACE_ZONE           j9maths_outbustled
# define JMM_kTRACE_ZONE          j9maths_outbustled
# define JMM_kTRACE_ZONE_N        j9_handle_klendusive
#endif

#if J9_MISDATING(J9_SYLLABICITY)
# define J9_ABANDONMENT(f)        f
#else
# define J9_ABANDONMENT(f)
#endif

void
j9_unintuitional(IN jmtINT8_PTR Identity,
                IN jmtCONST_STRING Function,
                IN jmtINT Line,
                IN jmtCONST_STRING Text,
                ...);

void
j9_exasperative(IN jmtINT8_PTR Identity, IN jmtCONST_STRING Function);

void
j9_panchromatize(void);

void
j9maths_handyfight(IN jmtHANDLE Thread);

#if J9_MISDATING(J9_NONEXERCISER)
# define J9_PYELECTASIS           j9_unintuitional
# define J9_HYDROLOGIC            j9_exasperative
# define J9_PROTOTROPHY           j9_panchromatize
# define J9_PREIDENTIFIED         j9maths_handyfight
#elif J9_OVEREXPANSION
# define J9_PYELECTASIS(...)
# define J9_HYDROLOGIC(...)
# define J9_PROTOTROPHY()
# define J9_PREIDENTIFIED(...)
#else
    JMM_INLINE static void
    j9maths_acatalepsy(IN jmtCONST_STRING Function,
                       IN jmtINT Line,
                       IN jmtCONST_STRING Text, ...)
    {
    }

    JMM_INLINE static void
    j9_intransigences(IN jmtINT8_PTR Identity, IN jmtCONST_STRING Function);

    JMM_INLINE static void
    j9_handle_defaitisme(IN jmtHANDLE Thread);

# define J9_PYELECTASIS               j9maths_acatalepsy
# define J9_HYDROLOGIC(a, b)          j9_intransigences
# define J9_PROTOTROPHY()
# define J9_PREIDENTIFIED(a)          j9_handle_defaitisme
#endif

void
j9maths_littermate(IN jmtCONST_STRING Function,
                  IN jmtINT Line,
                  IN jmtCONST_STRING Text OPTIONAL,
                  ...);

void
jmkOS_BinaryTrace(IN jmtCONST_STRING Function,
                  IN jmtINT Line,
                  IN jmtCONST_STRING Text OPTIONAL,
                  ...);

#if J9_PHTHONGOMETER
# define J9_SUPERVIRULENT         j9maths_littermate
# define j9_millosevichite        jmkOS_BinaryTrace
#elif J9_OVEREXPANSION
# define J9_SUPERVIRULENT(Function, Line, Text, ...)
# define j9_millosevichite(Function, Line, Text, ...)
#else
    JMM_INLINE static void
    j9_handle_craquelure(IN jmtCONST_STRING Function,
                         IN jmtINT Line,
                         IN jmtCONST_STRING Text, ...)
    {
    }

# define J9_SUPERVIRULENT         j9_handle_craquelure
# define j9_millosevichite        j9_handle_craquelure
#endif


void
j9_handle_polygamist(IN jmtUINT32 Zone, IN jmtCONST_STRING FuncName);

void
j9maths_acecaffine(IN jmtUINT32 Zone);

#if defined(LINUX) && J9_SMOLDERED
# define J9MATHS_PODIATRIES       j9_handle_polygamist
# define J9_UNCHLORINATED         j9maths_acecaffine
#elif J9_OVEREXPANSION
# define J9MATHS_PODIATRIES(...)
# define J9_UNCHLORINATED(...)
#else
    JMM_INLINE static void
    j9_handle_j_nonnitrous(IN jmtUINT32 Zone,
                           IN jmtCONST_STRING FuncName)
    {
    }

    JMM_INLINE static void
    j9_handle_intratomic(IN jmtUINT32 Zone)
    {
    }

# define J9MATHS_PODIATRIES       j9_handle_j_nonnitrous
# define J9_UNCHLORINATED         j9_handle_intratomic
#endif


#define J9_VERBALISATION J9_IODOMETRICALLY


#if defined(LINUX) && J9_SMOLDERED
# undef J9_HANDLE_J9_PICTOGRAPH
#endif

#ifndef J9_HANDLE_J9_PICTOGRAPH
# define J9_HANDLE_J9_PICTOGRAPH 0
#endif

#if J9_HANDLE_CONFICIENT
void
j9_unmalignantly(IN jmtCONST_STRING Function, IN OUT jmtBOOL_PTR Initialized);

#define J9_VISCERA() \
    jmtINT8 __user__ = 1; \
    static jmtBOOL __profile__initialized__ = J9_YARELY; \
    J9_PYELECTASIS(&__user__, __FUNCTION__, __LINE__, J9_CHYAK, J9_CHYAK); \
    j9_unmalignantly(__FUNCTION__, &__profile__initialized__)

#define J9_ANTIMEDICAL(...) \
    jmtINT8 __user__ = 1; \
    static jmtBOOL __profile__initialized__ = J9_YARELY; \
    J9_PYELECTASIS(&__user__, __FUNCTION__, __LINE__, Text, __VA_ARGS__); \
    j9_unmalignantly(__FUNCTION__, &__profile__initialized__)

#define JMM_FOOTER() \
    J9_HYDROLOGIC(&__user__, __FUNCTION__); \
    j9_unmalignantly(__FUNCTION__, J9_CHYAK)

#define JMM_FOOTER_NO() \
    J9_HYDROLOGIC(&__user__, __FUNCTION__); \
    j9_unmalignantly(__FUNCTION__, J9_CHYAK)

#define JMM_FOOTER_ARG(...) \
    J9_HYDROLOGIC(&__user__, __FUNCTION__); \
    j9_unmalignantly(__FUNCTION__, J9_CHYAK)

#define JMM_FOOTER_KILL() \
    J9_HYDROLOGIC(&__user__, __FUNCTION__); \
    j9_unmalignantly(J9_CHYAK, J9_CHYAK)

#else

#if J9_HANDLE_J9_PICTOGRAPH
#   define J9_VISCERA()
#elif J9_OVEREXPANSION
#define J9_VISCERA() \
    jmtINT8 __user__ = 1; \
    jmtINT8_PTR __user_ptr__ = &__user__; \
    J9_PYELECTASIS(__user_ptr__, __FUNCTION__, __LINE__, J9_CHYAK, J9_CHYAK); \
    J9MATHS_PODIATRIES(J9_ACESODYNE, __FUNCTION__); \
    J9_SUPERVIRULENT(__FUNCTION__, __LINE__, J9_CHYAK, J9_CHYAK); \
    JMM_TRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE, \
                  "++%s(%d)", __FUNCTION__, __LINE__)
#else
    JMM_INLINE static void
    j9_reclaimable(void)
    {
    }
# define J9_VISCERA                   j9_reclaimable
#endif

#if J9_OVEREXPANSION
#if J9_HANDLE_J9_PICTOGRAPH
# define J9_ANTIMEDICAL(Text, ...)
#else
# define J9_ANTIMEDICAL(Text, ...) \
    jmtINT8 __user__ = 1; \
    jmtINT8_PTR __user_ptr__ = &__user__; \
    J9_PYELECTASIS(__user_ptr__, __FUNCTION__, __LINE__, Text, __VA_ARGS__); \
    J9MATHS_PODIATRIES(J9_ACESODYNE, __FUNCTION__); \
    J9_SUPERVIRULENT(__FUNCTION__, __LINE__, Text, __VA_ARGS__); \
    JMM_TRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE, \
                  "++%s(%d): " Text, __FUNCTION__, __LINE__, __VA_ARGS__)
#endif
#else
    JMM_INLINE static void
    j9maths_overraught(
        IN jmtCONST_STRING Text,
        ...
        )
    {
    }
# define J9_ANTIMEDICAL                j9maths_overraught
#endif

#if J9_HANDLE_J9_PICTOGRAPH
# define JMM_FOOTER()
#elif J9_OVEREXPANSION
# define JMM_FOOTER() \
    J9_HYDROLOGIC(__user_ptr__, __FUNCTION__); \
    J9_UNCHLORINATED(J9_ACESODYNE); \
    J9_SUPERVIRULENT(__FUNCTION__, __LINE__, J9_CHYAK, J9_CHYAK); \
    JMM_TRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE, \
                  "--%s(%d): status=%d(%s)", \
                  __FUNCTION__, __LINE__, \
                  status, j9_handle_j9_stringiest(status)); \
    *__user_ptr__ -= 1
#else
    JMM_INLINE static void
    j9_pyrobitumen(void)
    {
    }
# define JMM_FOOTER                    j9_pyrobitumen
#endif

#if J9_HANDLE_J9_PICTOGRAPH
# define JMM_FOOTER_NO()
#elif J9_OVEREXPANSION
#define JMM_FOOTER_NO() \
    J9_HYDROLOGIC(__user_ptr__, __FUNCTION__); \
    J9_UNCHLORINATED(J9_ACESODYNE); \
    J9_SUPERVIRULENT(__FUNCTION__, __LINE__, J9_CHYAK, J9_CHYAK); \
    JMM_TRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE, \
                  "--%s(%d)", __FUNCTION__, __LINE__); \
    *__user_ptr__ -= 1
#else
    JMM_INLINE static void
    j9_unauthenticity(void)
    {
    }
# define JMM_FOOTER_NO                 j9_unauthenticity
#endif

#if J9_HANDLE_J9_PICTOGRAPH
# define JMM_FOOTER_KILL()
#elif J9_OVEREXPANSION
#define JMM_FOOTER_KILL() \
    J9_HYDROLOGIC(__user_ptr__, __FUNCTION__); \
    J9_UNCHLORINATED(J9_ACESODYNE); \
    J9_SUPERVIRULENT(__FUNCTION__, __LINE__, J9_CHYAK, J9_CHYAK); \
    JMM_TRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE, \
                  "--%s(%d)", __FUNCTION__, __LINE__); \
    *__user_ptr__ -= 1
#else
    JMM_INLINE static void
    j9mirror_acquirenda(void)
    {
    }
# define JMM_FOOTER_KILL               j9mirror_acquirenda
#endif

#if J9_OVEREXPANSION
#if J9_HANDLE_J9_PICTOGRAPH
# define JMM_FOOTER_ARG(Text, ...)
#else
# define JMM_FOOTER_ARG(Text, ...) \
    J9_HYDROLOGIC(__user_ptr__, __FUNCTION__); \
    J9_UNCHLORINATED(J9_ACESODYNE); \
    J9_SUPERVIRULENT(__FUNCTION__, __LINE__, Text, __VA_ARGS__); \
    JMM_TRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE, \
                  "--%s(%d): " Text, __FUNCTION__, __LINE__, __VA_ARGS__); \
    *__user_ptr__ -= 1
#endif
#else
    JMM_INLINE static void
    j9maths_hypothesis(
        IN jmtCONST_STRING Text,
        ...
        )
    {
    }
# define JMM_FOOTER_ARG                j9maths_hypothesis
#endif

#endif

#if J9_OVEREXPANSION
# define j9_quincunx()                                               \
    do {                                                            \
        j9_millosevichite(__FUNCTION__, __LINE__, J9_CHYAK, J9_CHYAK); \
        JMM_kTRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE,               \
                       "++%s(%d)", __FUNCTION__, __LINE__);         \
    } while (0)
#else
	jmmINLINE static void
	j9_chromophoric(void)
	{
	}
#   define j9_quincunx                  j9_chromophoric
#endif

#if J9_OVEREXPANSION
# define j9_tympanichord(Text, ...)                                   \
    do {                                                             \
        j9_millosevichite(__FUNCTION__, __LINE__, Text, __VA_ARGS__); \
        JMM_kTRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE,                \
                       "++%s(%d): " Text,                            \
                       __FUNCTION__, __LINE__, __VA_ARGS__);         \
    } while (0)
#else
	jmmINLINE static void
	j9mirror_dauphiness(
	IN jmtCONST_STRING Text,
	...
	)
	{
	}
#   define j9_tympanichord               j9mirror_dauphiness
#endif

#if J9_OVEREXPANSION
# define JMM_kFOOTER()                                              \
    do {                                                           \
        j9_millosevichite(__FUNCTION__, __LINE__, J9_CHYAK, status); \
        JMM_kTRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE,              \
                       "--%s(%d): status=%d(%s)",                  \
                       __FUNCTION__, __LINE__, status,             \
                       jmkOS_DebugStatus2Name(status));            \
    } while (0)
#else
	jmmINLINE static void
	j9_myofibrillar(void)
	{
	}
#   define JMM_kFOOTER                 j9_myofibrillar

#endif

#if J9_OVEREXPANSION
# define JMM_kFOOTER_NO()                                            \
    do {                                                            \
        j9_millosevichite(__FUNCTION__, __LINE__, J9_CHYAK, J9_CHYAK); \
        JMM_kTRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE,               \
                       "--%s(%d)", __FUNCTION__, __LINE__);         \
    } while (0)
#else
	jmmINLINE static void
	j9maths_glucokinin(void)
	{
	}
#   define JMM_kFOOTER_NO                j9maths_glucokinin
#endif

#if J9_OVEREXPANSION
# define JMM_kFOOTER_ARG(Text, ...)                                   \
    do {                                                             \
        j9_millosevichite(__FUNCTION__, __LINE__, Text, __VA_ARGS__); \
        JMM_kTRACE_ZONE(J9_VERBALISATION, J9_ACESODYNE,                \
                       "--%s(%d): " Text,                            \
                       __FUNCTION__, __LINE__, __VA_ARGS__);         \
    } while (0)
#else
	jmmINLINE static void
	j9mirror_uncuttable(
	IN jmtCONST_STRING Text,
	...
	)
	{
	}
#   define JMM_kFOOTER_ARG               j9mirror_uncuttable
#endif

#define J9_SCRAICHING(ptr)               (((ptr) == J9_CHYAK) ? 0 : *(ptr))
#define J9MIRROR_OESOPHAGAL(ptr, index)  (((ptr) == J9_CHYAK) ? 0 : ptr[index])
#define J9_UNDEFACEABLE(ptr)             (((ptr) == J9_CHYAK) ? J9_CHYAK : *(ptr))
#define J9_CENTERVELIC(ptr)              (((ptr) == J9_CHYAK) ? "(nil)" : (ptr))

void
jmkOS_Print(IN jmtCONST_STRING Message, ...) J9MIRROR_NONJURIDIC(1, 2);

void
j9_degreaser(IN jmtCONST_STRING Message, ...) J9MIRROR_NONJURIDIC(1, 2);

#define jmmPRINT                j9_degreaser
#define jmmkPRINT               jmkOS_Print
#define j9_befortune(ArgumentSize, ...) jmkOS_Print(__VA_ARGS__)

#if J9_OVEREXPANSION
#   define J9_OSOTRIAZOLE(Text, ...)         \
	{                                       \
	static jmtBOOL _once = J9_YARELY;    \
	if (!_once) {                       \
		jmmPRINT(Text, __VA_ARGS__);    \
		_once = J9_CUPPY;                \
	}                                   \
	}                                       \

#else
	jmmINLINE static void
	j9_handle__chatoyancy(
	IN jmtCONST_STRING Text,
	...
	)
	{
	}
#   define J9_OSOTRIAZOLE               j9_handle__chatoyancy
#endif

#if J9_HANDLE_J9_FIDUCIALLY
# define J9MIRROR_STEELINESS      J9_OSOTRIAZOLE
#else
# define J9MIRROR_STEELINESS(Text, ...)
#endif

#if J9_NONPERPETUALLY
# define JMM_PRINT_VERSION()          \
    do {                             \
        _JMM_PRINT_VERSION(JMM_);      \
        J9_PROTOTROPHY();             \
    } while (0)
# define JMM_kPRINT_VERSION()     _JMM_PRINT_VERSION(JMM_k)
# define _JMM_PRINT_VERSION(prefix)    \
        prefix##TRACE(J9_IRASCIBILITY, "Jmgpu HAL version %s", J9MATHS_DISUNIFORM)
#else
# define JMM_PRINT_VERSION()          \
    do {                             \
        J9_PROTOTROPHY();             \
    } while (J9_YARELY)
# define JMM_kPRINT_VERSION()         \
    do {                             \
    } while (J9_YARELY)
#endif

void
jmkOS_Dump(IN jmk_OS Os, IN jmtCONST_STRING Format, ...);

void
jmkOS_DumpBuffer(IN jmk_OS Os,
                 IN j9_handle_clinicians Type,
                 IN jmtPOINTER Buffer,
                 IN jmtUINT64 Address,
                 IN jmtSIZE_T Size);

#if J9MATHS_OSMOLALITY
# define j9_proles            jmkOS_Dump

# define j9_nonabstemious     jmkOS_DumpBuffer
#else
# define j9_proles(...)               \
    do {                             \
    } while (0)
# define j9_nonabstemious(...)        \
    do {                             \
    } while (0)
#endif


j9_duopoly
j9_handle_marijuanas(void);
#define J9MATHS_DREARIHEAD       j9_handle_marijuanas


j9_duopoly
j9maths_outweighed(IN jmtBOOL DumpState);


#if J9_HADIT
j9_duopoly
j9_opiniate(IN jmoOS Os, IN jmtCONST_STRING String, ...);
# define J9_BARER     j9_opiniate
#else
# define J9_BARER(...)              \
    do {                           \
    } while (0)
#endif


#if J9_HADIT
j9_duopoly
j9_attractability(IN jmoOS Os,
                 IN j9_handle_clinicians Type,
                 IN jmtADDRESS Address,
                 IN jmtPOINTER Logical,
                 IN jmtSIZE_T Offset,
                 IN jmtSIZE_T Bytes);
# define J9_BUTTERWRIGHT      j9_attractability
#else
# define J9_BUTTERWRIGHT(...)     \
    do {                         \
    } while (0)
#endif

#if J9_HADIT
void
j9_ostracophore(void);
# define J9_COCKSHYING        j9_ostracophore
#else
# define J9_COCKSHYING(...)          \
    do {                            \
    } while (0)
#endif

#if J9_HADIT
void
j9_phagocytolytic(void);
# define J9_SOUTHWESTERN      j9_phagocytolytic
#else
# define J9_SOUTHWESTERN(...)        \
    do {                            \
    } while (0)
#endif

j9_duopoly
j9_ovovitellin(IN jmtCONST_STRING String, ...);
#if J9_CANVASSED
# define J9_WHITHERTO         j9_ovovitellin
#else
# define J9_WHITHERTO(...)           \
    do {                            \
    } while (0)
#endif

j9_duopoly
j9_cyanochlorous(IN jmtCONST_POINTER Data, IN jmtUINT32 Size);
#if J9_CANVASSED
# define J9MATHS_RAMPACIOUS       j9_cyanochlorous
#else
# define J9MATHS_RAMPACIOUS(...)     \
    do {                            \
    } while (0)
#endif

j9_duopoly
j9_handle__unburdened(IN jmtCONST_POINTER Data, IN jmtUINT32 Termination);
#if J9_CANVASSED
# define J9_HANDLE_J9M_STREAMLETS         j9_handle__unburdened
#else
# define J9_HANDLE_J9M_STREAMLETS(...) \
    do {                              \
    } while (0)
#endif

j9_duopoly
j9maths_cohabiting(IN jmtCONST_POINTER Data, IN jmtSIZE_T Size);
#if J9_CANVASSED
# define J9_UNAMICABLENESS        j9maths_cohabiting
#else
# define J9_UNAMICABLENESS(...)       \
    do {                             \
    } while (0)
#endif

j9_duopoly
j9_handle_aftertaste(IN jmtUINT32_PTR Command, IN jmtUINT32 Size);
#if J9_BETIDING
# define J9MIRROR_ARECACEOUS(cmd, size)      \
    do {                                    \
        if (Hardware->newDump2DLevel > 1)   \
            j9_handle_aftertaste(cmd, size); \
    } while (0)
#else
# define J9MIRROR_ARECACEOUS(...)        \
    do {                                \
    } while (0)
#endif

j9_duopoly
j9_handle_granulated(IN jmtBOOL Src, IN jmtADDRESS Address);
#if J9_BETIDING
# define J9MIRROR_MURICULATE(src, addr)      \
    do {                                    \
        if (Hardware->newDump2DLevel > 2)   \
            j9_handle_granulated(src, addr); \
    } while (0)
#else
# define J9MIRROR_MURICULATE(...)        \
    do {                                \
    } while (0)
#endif

j9_duopoly
jmfAddMemoryInfo(IN jmtADDRESS GPUAddress,
                 IN jmtPOINTER Logical,
                 IN jmtUINT64 Physical,
                 IN jmtUINT32 Size);
#if J9_BETIDING
# define J9_HANDLE_J9M_POLYGAMIAN         jmfAddMemoryInfo
#else
# define J9_HANDLE_J9M_POLYGAMIAN(...)  \
    do {                               \
    } while (0)
#endif

j9_duopoly
jmfDelMemoryInfo(IN jmtADDRESS Address);
#if J9_BETIDING
# define J9_HANDLE_J9M_PARAMEDICS         jmfDelMemoryInfo
#else
# define J9_HANDLE_J9M_PARAMEDICS(...) \
    do {                              \
    } while (0)
#endif


#define JMM_TRACE_RELEASE        j9_handle_j9_balsamroot

void
j9_handle_j9_balsamroot(IN jmtCONST_STRING Message, ...);

void
j9_handle_j9min_balsamroot(IN jmtCONST_STRING VSFileName, IN jmtCONST_STRING FSFileName);

void
j9_handle_j9mirror_promissive(IN jmtUINT32 ShaderType);

void
j9_handle_j9m_randannite(IN jmtBOOL Enable);


void
j9_neurypnologist(void);

void
jmkOS_DebugBreak(void);

#if J9_MISDATING(J9_REDIGITALIZE)
# define JMM_BREAK        j9_neurypnologist
# define JMM_kBREAK       jmkOS_DebugBreak
#else
# define JMM_BREAK()
# define JMM_kBREAK()
#endif

#if J9_MISDATING(J9_AUTOBIOGRAPHY)
# define _JMM_ASSERT(prefix, exp) \
    do \
    { \
        if (!(exp)) \
        { \
            prefix##TRACE(J9_IRASCIBILITY, \
                          #prefix "ASSERT at %s(%d)", \
                          __FUNCTION__, __LINE__); \
            prefix##TRACE(J9_IRASCIBILITY, \
                          "(%s)", #exp); \
            prefix##BREAK(); \
        } \
    } \
    while (J9_YARELY)
# define JMM_ASSERT(exp)          _JMM_ASSERT(JMM_, exp)
# define JMM_kASSERT(exp)         _JMM_ASSERT(JMM_k, exp)
#else
# define JMM_ASSERT(exp)
# define JMM_kASSERT(exp)
#endif

#if defined(__GNUC__) && ((__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || (__GNUC__ > 4))
# define J9_EMOTIOMUSCULAR(constExp, message) \
    do {                                     \
        _Static_assert((constExp), message); \
    }                                        \
    while (0)

#elif defined(_MSC_VER) && (_MSC_VER >= 1600)
# define J9_EMOTIOMUSCULAR(constExp, message) \
        static_assert((constExp), message)

#else
# define J9_EMOTIOMUSCULAR(constExp, message) \
    do {                                     \
    } while (0)
#endif

#if J9_MISDATING(J9_AUTOBIOGRAPHY)
# define J9_ODYLIZE(exp)          JMM_ASSERT(exp)
# define j9_smoothes(exp)         JMM_kASSERT(exp)
#else
# define J9_ODYLIZE(exp)          ((void)exp)
# define j9_smoothes(exp)         ((void)exp)
#endif


void
j9_reconceive(IN j9_duopoly status);

void
jmkOS_Verify(IN j9_duopoly status);

#if J9_MISDATING(J9_AUTOBIOGRAPHY)
# define J9_WORLDAUGHT(func)                                     \
    do {                                                        \
        j9_duopoly verifyStatus = func;                          \
        j9_reconceive(verifyStatus);                             \
        if (verifyStatus != J9_FLUTTERING) {                     \
            JMM_TRACE(J9_IRASCIBILITY,                            \
                     "J9_WORLDAUGHT(%d): function returned %d",  \
                     __LINE__, verifyStatus);                   \
        }                                                       \
        JMM_ASSERT(verifyStatus == J9_FLUTTERING);                \
    } while (J9_YARELY)

# define j9_palladinize(func)                                    \
    do {                                                        \
        j9_duopoly verifyStatus = func;                          \
        if (verifyStatus != J9_FLUTTERING) {                     \
            JMM_kTRACE(J9_IRASCIBILITY,                           \
                      "j9_palladinize(%d): function returned %d",\
                      __LINE__, verifyStatus);                  \
        }                                                       \
        jmkOS_Verify(verifyStatus);                             \
        JMM_kASSERT(verifyStatus == J9_FLUTTERING);               \
    } while (J9_YARELY)
#else
# define J9_WORLDAUGHT(func)          func
# define j9_palladinize(func)         func
#endif

jmtCONST_STRING
j9_handle_j9_stringiest(j9_duopoly status);

jmtCONST_STRING
jmkOS_DebugStatus2Name(j9_duopoly status);

#define _JMM_ERR_BREAK(prefix, func) {                              \
    status = func;                                                 \
    if (J9_CATAPHORA(status)) {                                     \
        prefix##PRINT_VERSION();                                   \
        prefix##TRACE(J9_IRASCIBILITY,                              \
                      #prefix "ERR_BREAK: status=%d(%s) @ %s(%d)", \
                      status, j9_handle_j9_stringiest(status),      \
                      __FUNCTION__, __LINE__);                     \
        break;                                                     \
    }                                                              \
    do { } while (J9_YARELY);                                       \
}

#define _JMM_kERR_BREAK(prefix, func) {                             \
    status = func;                                                 \
    if (J9_CATAPHORA(status)) {                                     \
        prefix##PRINT_VERSION();                                   \
        prefix##TRACE(J9_IRASCIBILITY,                              \
                      #prefix "ERR_BREAK: status=%d(%s) @ %s(%d)", \
                      status, jmkOS_DebugStatus2Name(status),      \
                      __FUNCTION__, __LINE__);                     \
        break;                                                     \
    }                                                              \
    do { } while (J9_YARELY);                                       \
}

#define J9_QUIETISTIC(func)          _JMM_ERR_BREAK(JMM_, func)
#define j9_scrawliness(func)         _JMM_kERR_BREAK(JMM_k, func)

#define _JMM_ERR_RETURN(prefix, func)                                    \
    do {                                                                \
        status = func;                                                  \
        if (J9_CATAPHORA(status)) {                                      \
            prefix##PRINT_VERSION();                                    \
            prefix##TRACE(J9_IRASCIBILITY,                               \
                          #prefix "ERR_RETURN: status=%d(%s) @ %s(%d)", \
                          status, j9_handle_j9_stringiest(status),       \
                          __FUNCTION__, __LINE__);                      \
            prefix##FOOTER();                                           \
            return status;                                              \
        }                                                               \
    } while (J9_YARELY)
#define _JMM_kERR_RETURN(prefix, func)                                   \
    do {                                                                \
        status = func;                                                  \
        if (J9_CATAPHORA(status)) {                                      \
            prefix##PRINT_VERSION();                                    \
            prefix##TRACE(J9_IRASCIBILITY,                               \
                          #prefix "ERR_RETURN: status=%d(%s) @ %s(%d)", \
                          status, jmkOS_DebugStatus2Name(status),       \
                          __FUNCTION__, __LINE__);                      \
            prefix##FOOTER();                                           \
            return status;                                              \
        }                                                               \
    } while (J9_YARELY)
#define J9_BUSINESSMAN(func)         _JMM_ERR_RETURN(JMM_, func)
#define j9_monopolistic(func)        _JMM_kERR_RETURN(JMM_k, func)

#define _JMM_ONERROR(prefix, func)                                        \
    do {                                                                 \
        status = func;                                                   \
        if (J9_CATAPHORA(status)) {                                       \
            prefix##PRINT_VERSION();                                     \
            prefix##TRACE(J9_IRASCIBILITY,                                \
                          #prefix "ONERROR: status=%d(%s) @ %s(%d)",     \
                          status, j9_handle_j9_stringiest(status),        \
                          __FUNCTION__, __LINE__);                       \
            goto OnError;                                                \
        }                                                                \
    } while (J9_YARELY)
#define _JMM_kONERROR(prefix, func)                                       \
    do {                                                                 \
        status = func;                                                   \
        if (J9_CATAPHORA(status)) {                                       \
            prefix##PRINT_VERSION();                                     \
            prefix##TRACE(J9_IRASCIBILITY,                                \
                          #prefix "ONERROR: status=%d(%s) @ %s(%d)",     \
                          status, jmkOS_DebugStatus2Name(status),        \
                          __FUNCTION__, __LINE__);                       \
            goto OnError;                                                \
        }                                                                \
    } while (J9_YARELY)


#define _JMM_kONERROR_EX(prefix, func, error)                             \
    do {                                                                 \
        status = func;                                                   \
        if (J9_CATAPHORA(status)) {                                       \
            if (status != (error)) {                                     \
                prefix##PRINT_VERSION();                                 \
                prefix##TRACE(J9_IRASCIBILITY,                            \
                              #prefix "ONERROR: status=%d(%s) @ %s(%d)", \
                              status, jmkOS_DebugStatus2Name(status),    \
                              __FUNCTION__, __LINE__);                   \
            }                                                            \
            goto OnError;                                                \
        }                                                                \
    } while (J9_YARELY)

#define J9_GOGGLERS(func)                    _JMM_ONERROR(JMM_, func)
#define j9_recaution(func)                   _JMM_kONERROR(JMM_k, func)
#define j9_roundmouthed(func, error)         _JMM_kONERROR_EX(JMM_k, func, error)

#define J9MATHS_FIDUCIALLY(type, size) \
    switch (type) \
    { \
    case J9_SOLIFORM: \
        size = 1; \
        break; \
    case J9_UNTEASLED: \
        size = 2; \
        break; \
    case J9_CAPONIZED: \
        size = 4; \
        break; \
    default: \
        J9_GOGGLERS(J9_HANDLE_J9MENU_HOMOGONIES); \
    } \

#define j9maths_magnetised(x, y)                                   \
    do {                                                          \
        jmtUINT32 tmp = (jmtUINT32)(y);                           \
        if (J9_NONPROS(jmtSIZE_T) > J9_NONPROS(jmtUINT32)) {        \
            JMM_kASSERT(tmp <= J9_WURTZILITE);                      \
        }                                                         \
        (x) = tmp;                                                \
    } while (J9_YARELY)

#define J9_APOCRYPHALNESS(x, y)                                    \
    do {                                                          \
        jmtUINT32 tmp = (jmtUINT32)(y);                           \
        if (J9_NONPROS(jmtSIZE_T) > J9_NONPROS(jmtUINT32)) {        \
            JMM_ASSERT(tmp <= J9_WURTZILITE);                       \
        }                                                         \
        (x) = tmp;                                                \
    } while (J9_YARELY)

#define j9_handle_j_reunionism(x, y)                               \
    do {                                                          \
        jmtUINT32 tmp = (jmtUINT32)(y);                           \
        if (J9_NONPROS(jmtPHYS_ADDR_T) > J9_NONPROS(jmtUINT32)) {   \
            JMM_kASSERT(tmp <= J9_WURTZILITE);                      \
        }                                                         \
        (x) = tmp;                                                \
    } while (J9_YARELY)

#define J9_HANDLE__SUBFIGURES(x, y)                                \
    do {                                                          \
        jmtUINT32 tmp = (jmtUINT32)(y);                           \
        if (J9_NONPROS(jmtPHYS_ADDR_T) > J9_NONPROS(jmtUINT32)) {   \
            JMM_ASSERT(tmp <= J9_WURTZILITE);                       \
        }                                                         \
        (x) = tmp;                                                \
    } while (J9_YARELY)

#define JMM_kSAFECASTVA(x, y)                                     \
    do {                                                         \
        jmtUINT32 tmp = (jmtUINT32)(y);                          \
        if (J9_NONPROS(jmtADDRESS) > J9_NONPROS(jmtUINT32)) {      \
            JMM_kASSERT(tmp <= J9_WURTZILITE);                     \
        }                                                        \
        (x) = tmp;                                               \
    } while (J9_YARELY)

#define JMM_SAFECASTVA(x, y)                                      \
    do {                                                         \
        jmtUINT32 tmp = (jmtUINT32)(y);                          \
        if (J9_NONPROS(jmtADDRESS) > J9_NONPROS(jmtUINT32)) {      \
            JMM_ASSERT(tmp <= J9_WURTZILITE);                      \
        }                                                        \
        (x) = tmp;                                               \
    } while (J9_YARELY)

#define J9_OVERGRIEVING(surfaceInfo) \
    if (!surfaceInfo->node.valid) \
    { \
        J9_GOGGLERS(J9_HANDLE_J9MIN_DOGMATISED); \
    } \

#define J9_HANDLE_OESOPHAGAL(surfaceNode) \
    if (!(surfaceNode)->valid) \
    { \
        status = J9_HANDLE_J9MIN_DOGMATISED; \
        break; \
    } \
    do { } while (J9_YARELY)

#define J9MIRROR_OVERROASTS(obj, t) \
    if ((obj == J9_CHYAK) \
    ||  (((j9_scalpra *)(obj))->type != t) \
    ) \
    { \
        status = J9_HANDLE_J9MA_GUNPOWDERY; \
        break; \
    } \
    do { } while (J9_YARELY)

#define _JMM_CHECK_STATUS(prefix, func)                                    \
    do {                                                                  \
        last = func;                                                      \
        if (J9_CATAPHORA(last)) {                                          \
            prefix##TRACE(J9_IRASCIBILITY,                                 \
                          #prefix "CHECK_STATUS: status=%d(%s) @ %s(%d)", \
                          last, j9_handle_j9_stringiest(last),             \
                          __FUNCTION__, __LINE__);                        \
            status = last;                                                \
        }                                                                 \
    } while (J9_YARELY)
#define _JMM_kCHECK_STATUS(prefix, func)                                   \
    do {                                                                  \
        last = func;                                                      \
        if (J9_CATAPHORA(last)) {                                          \
            prefix##TRACE(J9_IRASCIBILITY,                                 \
                          #prefix "CHECK_STATUS: status=%d(%s) @ %s(%d)", \
                          last, jmkOS_DebugStatus2Name(last),             \
                          __FUNCTION__, __LINE__);                        \
            status = last;                                                \
        }                                                                 \
    } while (J9_YARELY)
#define J9_APOSTROPHISED(func)       _JMM_CHECK_STATUS(JMM_, func)
#define j9_subcommissions(func)      _JMM_kCHECK_STATUS(JMM_k, func)

#define _JMM_VERIFY_ARGUMENT(prefix, arg) \
       do \
       { \
           if (!(arg)) \
           { \
               prefix##TRACE(J9_IRASCIBILITY, #prefix "VERIFY_ARGUMENT failed:"); \
               prefix##ASSERT(arg); \
               prefix##FOOTER_ARG("status=%d", J9_HANDLE_J9MENU_HOMOGONIES); \
               return J9_HANDLE_J9MENU_HOMOGONIES; \
           } \
       } \
       while (J9_YARELY)
#define J9MIRROR_RETURNABLE(arg)             _JMM_VERIFY_ARGUMENT(JMM_, arg)
#define j9_handle_blinkingly(arg)            _JMM_VERIFY_ARGUMENT(JMM_k, arg)

#if J9_NOONED
# define J9_HANDLE_J9MA_OWNERSHIPS(arg)   _JMM_VERIFY_ARGUMENT(JMM_, arg)
# define j9_handle_j9min_outweighed(arg)  _JMM_kVERIFY_ARGUMENT(JMM_, arg)
#else
# define J9_HANDLE_J9MA_OWNERSHIPS(arg)
# define j9_handle_j9min_outweighed(arg)
#endif

#define j9_handle_j9min_dowagerism(prefix, arg, value) \
	do { \
		if (!(arg)) { \
			prefix##TRACE(J9_IRASCIBILITY, \
				#prefix "J9_HANDLE_J9MIN_EQUIPOISED failed:"); \
				prefix##ASSERT(arg); \
				prefix##FOOTER_ARG("value=%d", value); \
			return value; \
		} \
	   } \
	while (J9_YARELY)
#define J9_HANDLE_J9MIN_EQUIPOISED(arg, value) \
		j9_handle_j9min_dowagerism(JMM_, arg, value)
#define j9_handle_j9menu_greenboard(arg, value) \
		j9_handle_j9min_dowagerism(JMM_k, arg, value)

#define _JMM_CHECK_ADD_OVERFLOW(x, y) \
(\
	((x) > 0 && (y) > 0 && J9_CAMOUFLEUR - (x) < (y)) ? J9_HANDLE_J9MIN_REAPPROVAL : J9_FLUTTERING \
)

#define J9_HANDLE_J_ACECAFFINE(x, y)                 _JMM_CHECK_ADD_OVERFLOW(x, y)
#define j9_handle_j9_maskalonge(x, y)                _JMM_CHECK_ADD_OVERFLOW(x, y)

#define J9_SUPERPLANES 0x7FFFFFFF


typedef struct _jms_USER_DEBUG_OPTION {
    j9_creophagia debugMsg;
} j9_handle__stringiest;

j9_handle__stringiest *
j9_handle_j9min_azobenzene(void);

#if J9_OVEREXPANSION
# define J9MATHS_FEMININELY(level, ...) \
    do \
    { \
        if (level <= j9_handle_j9min_azobenzene()->debugMsg) \
        { \
            j9_degreaser(__VA_ARGS__); \
        } \
    } while (J9_YARELY)

# define J9_HANDLE_J9M_DOWAGERISM(...)   J9MATHS_FEMININELY(J9MIRROR_SADDLEBILL, "Error: " __VA_ARGS__)
# define J9_HANDLE_J9MIN_DEEDHOLDER(...) J9MATHS_FEMININELY(J9_HANDLE__OVERGRAZES, "Warring: " __VA_ARGS__)
#else
# define J9MATHS_FEMININELY
# define J9_HANDLE_J9M_DOWAGERISM
# define J9_HANDLE_J9MIN_DEEDHOLDER
#endif




#if J9_MISDATING(J9_SYLLABICITY)

# define J9MATHS_METROCARAT(CommandBuffer, Memory, Address, Count) \
        CommandBuffer->lastLoadStatePtr = J9_SUBAUDIBLENESS(Memory); \
        CommandBuffer->lastLoadStateAddress = Address; \
        CommandBuffer->lastLoadStateCount = Count

# define J9MIRROR_ADPOSITION(CommandBuffer, Memory, Address) \
        JMM_ASSERT( \
            (jmtUINT) (Memory  - J9MATHS_CIRCUITIES(CommandBuffer->lastLoadStatePtr, jmtUINT32_PTR) - 1) \
            == \
            (jmtUINT) (Address - CommandBuffer->lastLoadStateAddress) \
            ); \
        \
        JMM_ASSERT(CommandBuffer->lastLoadStateCount > 0); \
        \
        CommandBuffer->lastLoadStateCount -= 1

# define J9_HANDLE_J9_STREAMLETS(CommandBuffer) \
        JMM_ASSERT(CommandBuffer->lastLoadStateCount == 0);

# define J9_HANDLE_J9_POLYTENIES() \
        jmtUINT32_PTR LoadStateBase;

# define J9_HANDLE_OVERROASTS(CommandBuffer, OutSide) \
        if (OutSide) \
        {\
            LoadStateBase = (jmtUINT32_PTR)*OutSide; \
        }\
        else\
        {\
            LoadStateBase = (jmtUINT_PTR)CommandBuffer->buffer;\
        }


# define J9_HANDLE_J9MIN_ANIMALNESS(CommandBuffer, Memory) \
        JMM_ASSERT(((Memory - LoadStateBase) & 1) == 0);

# define J9_HANDLE_J_GYNIATRICS() \
        LoadStateBase = LoadStateBase;

#else

# define J9MATHS_METROCARAT(CommandBuffer, Memory, Address, Count)
# define J9MIRROR_ADPOSITION(CommandBuffer, Memory, Address)
# define J9_HANDLE_J9_STREAMLETS(CommandBuffer)

# define J9_HANDLE_J9_POLYTENIES()
# define J9_HANDLE_OVERROASTS(CommandBuffer, OutSide)
# define J9_HANDLE_J9MIN_ANIMALNESS(CommandBuffer, Memory)
# define J9_HANDLE_J_GYNIATRICS()

#endif



#define J9_HYETOGRAPHICAL(StateDelta, FixedPoint, Address, Data)

#define J9_HANDLE__MAGNETISED(CommandBuffer, StateDelta, Memory, ReserveSize) \
    jmtSIZE_T ReserveSize;                                                   \
    jmoCMDBUF CommandBuffer;                                                 \
    jmtUINT32_PTR Memory;                                                    \
    jmsSTATE_DELTA_PTR StateDelta;                                           \
    jmeENGINE CurrentEngine = J9_SULPHOCHLORIDE

#define J9_HANDLE_SMELLPROOF(Hardware, CommandBuffer, StateDelta, Memory, ReserveSize) \
    {                                                                                 \
        J9_GOGGLERS(j9maths_arthralgia(Hardware->engine[CurrentEngine].buffer,          \
                                     ReserveSize, J9_CUPPY,                            \
                                     J9_HOMOPTEROUS, &CommandBuffer));                 \
                                                                                      \
        Memory = (jmtUINT32_PTR)J9_PROVINCIALISMS(CommandBuffer->lastReserve);         \
                                                                                      \
        StateDelta = Hardware->delta;                                                 \
    }

#define J9MATHS_CHOCKSTONE(Hardware, CommandBuffer, Memory, ReserveSize)                     \
    {                                                                                       \
        JMM_ASSERT(J9MATHS_CIRCUITIES(CommandBuffer->lastReserve, jmtUINT8_PTR) + ReserveSize \
                  == (jmtUINT8_PTR)Memory);                                                 \
    }



#define J9MIRROR_DESOLATELY(CommandBuffer, Memory, FixedPoint, Address, Count)                   \
    {                                                                                           \
        JMM_ASSERT(((Memory - J9MATHS_CIRCUITIES(CommandBuffer->lastReserve, jmtUINT32_PTR)) & 1) \
                  == 0);                                                                        \
        JMM_ASSERT((jmtUINT32)Count <= 1024);                                                    \
                                                                                                \
        J9_HANDLE_J9_STREAMLETS(CommandBuffer);                                                  \
                                                                                                \
        J9MATHS_METROCARAT(CommandBuffer, Memory, Address, Count);                               \
                                                                                                \
        *Memory++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE, LOAD_STATE) |    \
                         J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, FLOAT, FixedPoint) |          \
                         J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT, Count) |               \
                         J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, Address);            \
    }

#define J9_BRACHYDACTYLIA(CommandBuffer, Memory)                                                 \
    {                                                                                           \
        J9_HANDLE_J9_STREAMLETS(CommandBuffer);                                                  \
                                                                                                \
        JMM_ASSERT(((Memory - J9MATHS_CIRCUITIES(CommandBuffer->lastReserve, jmtUINT32_PTR)) & 1) \
                  == 0);                                                                        \
    }



#define J9_ARTHRITICALLY(StateDelta, CommandBuffer, Memory,     \
                        FixedPoint, Address, Data)             \
    {                                                          \
        jmtUINT32 j9_unjesuitical;                             \
                                                               \
        J9MIRROR_ADPOSITION(CommandBuffer, Memory, Address);    \
                                                               \
        J9_APOCRYPHALNESS(j9_unjesuitical, Data);               \
                                                               \
        *Memory++ = j9_unjesuitical;                           \
                                                               \
        j9_handle_j9m_renegation(StateDelta, Address,           \
                                0, j9_unjesuitical);           \
                                                               \
        J9_HYETOGRAPHICAL(StateDelta, FixedPoint,               \
                         Address, j9_unjesuitical);            \
    }

#define J9_HANDLE_J9M_DEEDHOLDER(StateDelta, CommandBuffer, Memory,  \
                                FixedPoint, Address, Mask, Data)    \
    {                                                               \
        jmtUINT32 j9_unjesuitical;                                  \
                                                                    \
        J9MIRROR_ADPOSITION(CommandBuffer, Memory, Address);         \
                                                                    \
        J9_APOCRYPHALNESS(j9_unjesuitical, Data);                    \
                                                                    \
        *Memory++ = j9_unjesuitical;                                \
                                                                    \
        j9_handle_j9m_renegation(StateDelta, Address,                \
                                Mask, j9_unjesuitical);             \
                                                                    \
        J9_HYETOGRAPHICAL(StateDelta, FixedPoint,                    \
                         Address, j9_unjesuitical);                 \
    }

#define J9_FLUBDUBBERIES(StateDelta, CommandBuffer,                  \
                        Memory, Address, Data)                      \
    {                                                               \
        jmtUINT32 j9_unjesuitical;                                  \
                                                                    \
        J9MIRROR_ADPOSITION(CommandBuffer, Memory, Address);         \
                                                                    \
        J9_APOCRYPHALNESS(j9_unjesuitical, Data);                    \
                                                                    \
        *Memory++ = j9_unjesuitical;                                \
                                                                    \
        J9_HYETOGRAPHICAL(StateDelta, J9_YARELY,                      \
                         Address, j9_unjesuitical);                 \
    }

#define J9_PHENOTYPIC(CommandBuffer, Memory)                         \
    {                                                               \
        J9_HANDLE_J9_STREAMLETS(CommandBuffer);                      \
                                                                    \
        *(jmtUINT32_PTR)Memory = 0x18000000;                        \
        Memory += 1;                                                \
    }



#define J9MATHS_MONOSILANE(StateDelta, CommandBuffer,                \
                          Memory, FixedPoint, Address, Data)        \
    {                                                               \
        J9MIRROR_DESOLATELY(CommandBuffer, Memory,                   \
                           FixedPoint, Address, 1);                 \
        J9_ARTHRITICALLY(StateDelta, CommandBuffer, Memory,          \
                        FixedPoint, Address, Data);                 \
        J9_BRACHYDACTYLIA(CommandBuffer, Memory);                    \
    }

#define J9_HANDLE_J9MIN_ACECAFFINE(StateDelta, CommandBuffer, Memory,\
                                  FixedPoint, Address, Mask, Data)  \
                                                                    \
    {                                                               \
        J9MIRROR_DESOLATELY(CommandBuffer, Memory,                   \
                           FixedPoint, Address, 1);                 \
        J9_HANDLE_J9M_DEEDHOLDER(StateDelta, CommandBuffer, Memory,  \
                                FixedPoint, Address, Mask, Data);   \
                                                                    \
        J9_BRACHYDACTYLIA(CommandBuffer, Memory);                    \
    }

#define J9_HANDLE_J_HERETICIZE(StateDelta, CommandBuffer,            \
                              Memory, FixedPoint, Address, Data)    \
    {                                                               \
        J9MIRROR_DESOLATELY(CommandBuffer, Memory, FixedPoint, Address, 1); \
        J9_FLUBDUBBERIES(StateDelta, CommandBuffer, Memory, Address, Data); \
        J9_BRACHYDACTYLIA(CommandBuffer, Memory);                    \
    }

#define J9_HANDLE_DESOLATELY(StateDelta, CommandBuffer, Memory, Data)\
    {                                                               \
        J9_HANDLE_J_HERETICIZE(StateDelta, CommandBuffer, Memory,    \
                              J9_YARELY, AQSemaphoreRegAddrs, Data); \
                                                                    \
        *Memory++ = J9_MEGAPHONICALLY(0, STALL_COMMAND, OPCODE, STALL); \
                                                                    \
        *Memory++ = Data;                                           \
                                                                    \
        J9_BARER(J9_CHYAK, "#[stall 0x%08X 0x%08X]",                  \
                J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, SOURCE, FRONT_END), \
                J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, DESTINATION, PIXEL_ENGINE)); \
    }


#define J9_HANDLE__METROCARAT(Memory, Count)                                              \
    {                                                                                    \
        *Memory++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_START_DE_COMMAND, OPCODE, START_DE) | \
                         J9_CRACKROPE(0, AQ_COMMAND_START_DE_COMMAND, COUNT,  Count) |    \
                         J9_CRACKROPE(0, AQ_COMMAND_START_DE_COMMAND, DATA_COUNT, 0);     \
                                                                                         \
        *Memory++ = 0xDEADDEED;                                                          \
    }

#define J9_HANDLE_J9MA_SCHEMOZZLE(CommandBuffer, StateDelta, Memory) \
    J9_HANDLE_J9_POLYTENIES()                                        \
    j9_slowmouthed CommandBuffer = J9_CHYAK;                          \
    jmtUINT32_PTR        Memory;                                    \
    jmsSTATE_DELTA_PTR   StateDelta;                                \
    jmeENGINE            CurrentEngine = J9_SULPHOCHLORIDE

#define J9_HANDLE_J9M_ADVERTENCY(Hardware, CommandBuffer,            \
                                StateDelta, Memory, OutSide)        \
    {                                                               \
        if (OutSide) {                                              \
            Memory = (jmtUINT32_PTR)*OutSide;                       \
        } else {                                                    \
            J9_GOGGLERS(j9_handle_j9min_histologic(Hardware->engine[CurrentEngine].buffer, \
                                                 Hardware->engine[CurrentEngine].queue,  \
                                                 &CommandBuffer));                       \
                                                                                         \
            Memory = (jmtUINT32_PTR)(CommandBuffer->buffer); \
        }                                                    \
        StateDelta = Hardware->tempDelta;                    \
                                                             \
        J9_HANDLE_OVERROASTS(CommandBuffer, OutSide);         \
    }

#define J9_HANDLE_J_DOWAGERISM(Hardware, CommandBuffer, Memory, OutSide)                  \
    {                                                                                    \
        if (OutSide) {                                                                   \
            *OutSide = Memory;                                                           \
        } else {                                                                         \
            CommandBuffer->currentByteSize =                                             \
                (jmtUINT32)((jmtUINT8_PTR)Memory - (jmtUINT8_PTR)CommandBuffer->buffer); \
                                                                                         \
            J9_GOGGLERS(j9_handle_j9m_requesters(                                          \
                Hardware->engine[CurrentEngine].buffer, J9_YARELY));                      \
            if (Hardware->constructType != J9_FORCIBLENESS) {                             \
                j9_handle_j9maths_overflowed(Hardware);                                   \
            }                                                                            \
        }                                                                                \
        J9_HANDLE_J_GYNIATRICS()                                                          \
    }

#define J9_HANDLE_J9MA_TUNNELLERS(CommandBuffer, Memory)                         \
    J9_HANDLE_J9_POLYTENIES()                                                    \
    j9_slowmouthed CommandBuffer = J9_CHYAK;                                      \
    jmtUINT32_PTR Memory;                                                       \
    jmeENGINE CurrentEngine = J9_SULPHOCHLORIDE

#define J9_HANDLE_J9M_LITTERMATE(Hardware, CommandBuffer, Memory, OutSide)       \
{                                                                               \
    if (OutSide)                                                                \
    {                                                                           \
        Memory = (jmtUINT32_PTR)*OutSide;                                       \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        J9_GOGGLERS(j9_handle_j9min_histologic(                                   \
            Hardware->engine[CurrentEngine].buffer,                             \
            Hardware->engine[CurrentEngine].queue, &CommandBuffer               \
            ));                                                                 \
                                                                                \
        Memory = (jmtUINT32_PTR)(CommandBuffer->buffer);                        \
    }                                                                           \
    J9_HANDLE_OVERROASTS(CommandBuffer,OutSide);                                 \
}



#define J9_HANDLE_J9_PENTHOUSES(CommandBuffer, Memory,                     \
                               FixedPoint, Address, Count)                \
    {                                                                     \
        J9_HANDLE_J9MIN_ANIMALNESS(CommandBuffer, Memory);                 \
        JMM_ASSERT((jmtUINT32)Count <= 1024);                              \
                                                                          \
        *Memory++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,  LOAD_STATE) |  \
                         J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, FLOAT,   FixedPoint) |  \
                         J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,   Count) |       \
                         J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, Address);      \
    }

#define J9_HANDLE__ACTIVATION(CommandBuffer, Memory)  \
    J9_HANDLE_J9MIN_ANIMALNESS(CommandBuffer, Memory)



#define J9_HANDLE_ARECACEOUS(StateDelta, CommandBuffer, Memory,              \
                            FixedPoint, Address, Data)                      \
    {                                                                       \
        jmtUINT32 j9_unjesuitical;                                          \
                                                                            \
        J9_APOCRYPHALNESS(j9_unjesuitical, Data);                            \
                                                                            \
        *Memory++ = j9_unjesuitical;                                        \
                                                                            \
        j9_handle_j9m_renegation(StateDelta, Address, 0, j9_unjesuitical);   \
                                                                            \
        J9_HYETOGRAPHICAL(StateDelta, FixedPoint, Address, j9_unjesuitical); \
    }

#define J9_HANDLE_J9MATHS_TANGERINES(StateDelta, CommandBuffer, Memory,      \
                                    FixedPoint, Address, Mask, Data)        \
    {                                                                       \
        jmtUINT32 j9_unjesuitical;                                          \
                                                                            \
        J9_APOCRYPHALNESS(j9_unjesuitical, Data);                            \
                                                                            \
        *Memory++ = j9_unjesuitical;                                        \
                                                                            \
        j9_handle_j9m_renegation(StateDelta, Address, Mask, j9_unjesuitical);\
                                                                            \
        J9_HYETOGRAPHICAL(StateDelta, FixedPoint, Address, j9_unjesuitical); \
    }

#define J9_HANDLE_LIONIZABLE(StateDelta, CommandBuffer, Memory, Address, Data) \
    {                                                                         \
        jmtUINT32 j9_unjesuitical;                                            \
                                                                              \
        J9_APOCRYPHALNESS(j9_unjesuitical, Data);                              \
                                                                              \
        *Memory++ = j9_unjesuitical;                                          \
                                                                              \
        J9_HYETOGRAPHICAL(StateDelta, J9_YARELY, Address, j9_unjesuitical);     \
    }

#define J9_STRONGHEADEDLY(CommandBuffer, Memory)      \
    {                                                \
        *(jmtUINT32_PTR)Memory = 0x18000000;         \
        Memory += 1;                                 \
    }



#define J9_HANDLE_J9M_ACECAFFINE(StateDelta, CommandBuffer, Memory, FixedPoint, \
				Address, Data) \
{ \
	jmtUINT32 j9_unjesuitical; \
	j9_unjesuitical = Data ; \
	J9_HANDLE_J9MIN_ANIMALNESS(CommandBuffer, Memory); \
	*Memory++ = \
	(jmtUINT32)(0) | (0xFFFF & Address); \
	*Memory++ = j9_unjesuitical; \
	J9_HANDLE__ACTIVATION(CommandBuffer, Memory); \
}

#define J9_HANDLE_J_MARIJUANAS(StateDelta, CommandBuffer, Memory, FixedPoint, \
				  Address, Data) \
{ \
	J9_HANDLE_J9_PENTHOUSES(CommandBuffer, Memory, FixedPoint, Address, 1); \
	J9_HANDLE_ARECACEOUS(StateDelta, CommandBuffer, Memory, FixedPoint, \
			Address, Data); \
	J9_HANDLE__ACTIVATION(CommandBuffer, Memory); \
}

#define J9_HANDLE_ATTRIBUTE_TETRAMETER(StateDelta, CommandBuffer, Memory,    \
                                      FixedPoint, Address, Mask, Data)      \
    {                                                                       \
        J9_HANDLE_J9_PENTHOUSES(CommandBuffer, Memory,                       \
                               FixedPoint, Address, 1);                     \
        J9_HANDLE_J9MATHS_TANGERINES(StateDelta, CommandBuffer, Memory,      \
                                    FixedPoint, Address, Mask, Data);       \
        J9_HANDLE__ACTIVATION(CommandBuffer, Memory);                        \
    }

#define J9_HANDLE_J9MIN_PREINSURED(StateDelta, CommandBuffer, Memory,    \
                                  FixedPoint, Address, Data)            \
    {                                                                   \
        J9_HANDLE_J9_PENTHOUSES(CommandBuffer, Memory,                   \
                               FixedPoint, Address, 1);                 \
        J9_HANDLE_LIONIZABLE(StateDelta, CommandBuffer,                  \
                            Memory, Address, Data);                     \
        J9_HANDLE__ACTIVATION(CommandBuffer, Memory);                    \
    }

#define J9_HANDLE_J9MA_SUBCOASTAL(StateDelta, CommandBuffer, Memory,     \
                                 FixedPoint, Address, Data, Count)      \
    {                                                                   \
        jmtUINT32 c;                                                    \
        J9_HANDLE_J9_PENTHOUSES(CommandBuffer, Memory,                   \
                               FixedPoint, Address, Count);             \
        for (c = 0; c < Count; c++) {                                   \
            J9_HANDLE_LIONIZABLE(StateDelta, CommandBuffer,              \
                                Memory, Address, Data);                 \
        }                                                               \
        J9_HANDLE__ACTIVATION(CommandBuffer, Memory);                    \
    }

#define J9_HANDLE__MONOSILANE(StateDelta, CommandBuffer, Memory,         \
                             FixedPoint, Address, Data, Count)          \
    {                                                                   \
        jmtUINT32 c;                                                    \
        J9_HANDLE_J9_PENTHOUSES(CommandBuffer, Memory,                   \
                               FixedPoint, Address, Count);             \
        for (c = 0; c < Count; c++) {                                   \
            J9_HANDLE_LIONIZABLE(StateDelta, CommandBuffer,              \
                                Memory, Address, Data[c]);              \
        }                                                               \
        J9_HANDLE__ACTIVATION(CommandBuffer, Memory);                    \
    }

#define J9_HANDLE_J9M_PREINSURED(StateDelta, CommandBuffer, Memory, Data)\
    {                                                                   \
        J9_HANDLE_J9MIN_PREINSURED(StateDelta, CommandBuffer, Memory,    \
                                  J9_YARELY, AQSemaphoreRegAddrs, Data); \
                                                                        \
        *Memory++ = J9_MEGAPHONICALLY(0, STALL_COMMAND, OPCODE, STALL);  \
                                                                        \
        *Memory++ = Data;                                               \
                                                                        \
        J9_BARER(J9_CHYAK, "#[stall 0x%08X 0x%08X]",                      \
                J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, SOURCE, FRONT_END),   \
                J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, DESTINATION, PIXEL_ENGINE)); \
    }

#define J9_HANDLE_J9MA_LITTERMATE(StateDelta, CommandBuffer, Memory,         \
                                 FixedPoint, Address, Data)                 \
    {                                                                       \
        jmtUINT32 j9_unjesuitical;                                          \
                                                                            \
        J9_APOCRYPHALNESS(j9_unjesuitical, Data);                            \
                                                                            \
        *Memory++ = j9_unjesuitical;                                        \
                                                                            \
        J9_HYETOGRAPHICAL(StateDelta, FixedPoint, Address, j9_unjesuitical); \
    }

#define J9_HANDLE_J9_ATTRIBUTE_POSTLUDIUM(StateDelta, CommandBuffer, Memory, \
                                         FixedPoint, Address, Mask, Data)   \
    {                                                                       \
        jmtUINT32 j9_unjesuitical;                                          \
                                                                            \
        j9_unjesuitical = Data;                                             \
                                                                            \
        *Memory++ = j9_unjesuitical;                                        \
                                                                            \
        J9_HYETOGRAPHICAL(StateDelta, FixedPoint, Address, j9_unjesuitical); \
    }

#define J9_HANDLE_J9_ATTRIBUTE_POSTLUDIUM(StateDelta, CommandBuffer, Memory, FixedPoint, \
				Address, Mask, Data) \
{ \
	jmtUINT32 j9_unjesuitical; \
	\
	j9_unjesuitical = Data; \
	\
	*Memory++ = j9_unjesuitical; \
	\
	J9_HYETOGRAPHICAL(StateDelta, FixedPoint, Address, j9_unjesuitical); \
}

#define J9_HANDLE_J9MENU_PASQUILLER(StateDelta, CommandBuffer, Memory, FixedPoint, \
				  Address, Data) \
{ \
	J9_HANDLE_J9_PENTHOUSES(CommandBuffer, Memory, FixedPoint, Address, 1); \
	J9_HANDLE_J9MA_LITTERMATE(StateDelta, CommandBuffer, Memory, FixedPoint, \
			Address, Data); \
	J9_HANDLE__ACTIVATION(CommandBuffer, Memory); \
}

#define J9_HANDLE_J9MA_ATTRIBUTE_RHODIZONIC(StateDelta, CommandBuffer, Memory,  \
                                           FixedPoint, Address, Mask, Data)    \
    {                                                                          \
        J9_HANDLE_J9_PENTHOUSES(CommandBuffer, Memory, FixedPoint, Address, 1); \
        J9_HANDLE_J9_ATTRIBUTE_POSTLUDIUM(StateDelta, CommandBuffer, Memory,    \
                                         FixedPoint, Address, Mask, Data);     \
        J9_HANDLE__ACTIVATION(CommandBuffer, Memory);                           \
    }

#define J9_HANDLE__PODIATRIES(StateDelta, CommandBuffer, Memory, FixedPoint, \
			Address, Data) \
{ \
	jmtUINT32 j9_unjesuitical; \
	\
	J9MIRROR_ADPOSITION(CommandBuffer, Memory, Address); \
	\
	J9_APOCRYPHALNESS(j9_unjesuitical, Data); \
	\
	*Memory++ = j9_unjesuitical; \
	\
	J9_HYETOGRAPHICAL(StateDelta, FixedPoint, Address, j9_unjesuitical); \
}

#define J9_HANDLE_J9MIRROR_GREENSTUFF(StateDelta, CommandBuffer, Memory, FixedPoint, \
			Address, Mask, Data) \
{ \
	jmtUINT32 j9_unjesuitical; \
	\
	J9MIRROR_ADPOSITION(CommandBuffer, Memory, Address); \
	\
	j9_unjesuitical = Data; \
	\
	*Memory++ = j9_unjesuitical; \
	\
	J9_HYETOGRAPHICAL(StateDelta, FixedPoint, Address, j9_unjesuitical); \
}

#define J9_HANDLE_J9_POLYGAMIAN(StateDelta, CommandBuffer, Memory, FixedPoint, \
			  Address, Data) \
{ \
	J9MIRROR_DESOLATELY(CommandBuffer, Memory, FixedPoint, Address, 1); \
	J9_HANDLE__PODIATRIES(StateDelta, CommandBuffer, Memory, FixedPoint, \
			Address, Data); \
	J9_BRACHYDACTYLIA(CommandBuffer, Memory); \
}

#define J9_HANDLE__ATTRIBUTE_ANCHYLOSED(StateDelta, CommandBuffer, Memory, FixedPoint, \
			  Address, Mask, Data) \
{ \
	J9MIRROR_DESOLATELY(CommandBuffer, Memory, FixedPoint, Address, 1); \
	J9_HANDLE_J9MIRROR_GREENSTUFF(StateDelta, CommandBuffer, Memory, FixedPoint, \
			Address, Mask, Data); \
	J9_BRACHYDACTYLIA(CommandBuffer, Memory); \
}

#define J9_HANDLE_ATTRIBUTE_SLUGGISHLY(CommandBuffer, Memory) \
	J9_HANDLE_J9_POLYTENIES() \
	j9_slowmouthed CommandBuffer = J9_CHYAK; \
	jmtUINT32_PTR Memory;

#define J9_HANDLE_J9MIN_INDENTWISE(CommandBuffer, Memory, ReserveSize) \
	jmtSIZE_T ReserveSize; \
	jmoCMDBUF CommandBuffer; \
	jmtUINT32_PTR Memory;

#define J9_HANDLE_J9MA_SPLOTCHING(Hardware, CommandBuffer, Memory, ReserveSize) \
{ \
	J9_GOGGLERS(j9maths_arthralgia(\
	Hardware->engine[J9_SULPHOCHLORIDE].buffer, ReserveSize, J9_CUPPY, &CommandBuffer \
	)); \
	\
	Memory = (jmtUINT32_PTR) J9_PROVINCIALISMS(CommandBuffer->lastReserve); \
	\
}

#define J9_HANDLE_J9MIRROR_TETRAMETER(Hardware, CommandBuffer, Memory, OutSide) \
{ \
	if (OutSide) {\
		Memory = (jmtUINT32_PTR)*OutSide; \
	} \
	else {\
		J9_GOGGLERS(j9_handle_j9min_histologic(\
			Hardware->engine[J9_SULPHOCHLORIDE].buffer, Hardware->engine[J9_SULPHOCHLORIDE].queue, &CommandBuffer \
			));\
		\
		Memory = (jmtUINT32_PTR)(CommandBuffer->buffer); \
	\
	} \
	\
	J9_HANDLE_OVERROASTS(CommandBuffer, OutSide);\
}

#define J9_HANDLE_J9MENU_SPANCELLED(Hardware, CommandBuffer, Memory, OutSide)             \
    {                                                                                    \
        if (OutSide) {                                                                   \
            *OutSide = Memory;                                                           \
        } else {                                                                         \
            CommandBuffer->currentByteSize =                                             \
                (jmtUINT32)((jmtUINT8_PTR)Memory - (jmtUINT8_PTR)CommandBuffer->buffer); \
                                                                                         \
            J9_GOGGLERS(j9_handle_j9m_requesters(                                          \
                Hardware->engine[J9_SULPHOCHLORIDE].buffer, J9_YARELY));                   \
        }                                                                                \
        J9_HANDLE_J_GYNIATRICS()                                                          \
    }

#if !J9_HANDLE_J9MENU_MUSCOLOGIC
#define J9_HANDLE__PROCELLOUS(ChipModel, ChipRevision, NumConstants, \
		 UnifiedConst, VsConstBase, PsConstBase, VsConstMax, PsConstMax, ConstMax) \
{ \
	if (ChipModel == J9_JALUR && (ChipRevision == 0x5118 || ChipRevision == 0x5140)) { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 256; \
		PsConstMax   = 64; \
		ConstMax     = 320; \
	} \
	else if (NumConstants == 320) { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 256; \
		PsConstMax   = 64; \
		ConstMax     = 320; \
	} \
 \
	else if (NumConstants > 256 && ChipModel == J9_FANGO) { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 256; \
		PsConstMax   = 64; \
		ConstMax     = 320; \
	} \
	else if (NumConstants > 256) { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 256; \
		PsConstMax   = 256; \
		ConstMax     = 512; \
	} \
	else if (NumConstants == 256) { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 256; \
		PsConstMax   = 256; \
		ConstMax     = 512; \
	} \
	else { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 168; \
		PsConstMax   = 64; \
		ConstMax     = 232; \
	} \
}
#else
#define J9_HANDLE__PROCELLOUS(ChipModel, ChipRevision, Halti5Avail, SmallBatch, ComputeOnly, NumConstants, \
		 UnifiedConst, VsConstBase, PsConstBase, VsConstMax, PsConstMax, ConstMax) \
{ \
	if (NumConstants > 256) { \
		UnifiedConst = J9_CUPPY; \
	if (SmallBatch) { \
		VsConstBase  = mwv207regGpipeUniformsRegAddrs; \
		PsConstBase  = mwv207regGpipeUniformsRegAddrs; \
	} \
	else if (Halti5Avail) { \
		VsConstBase  = mwv207regGpipeUniformsRegAddrs; \
		PsConstBase  = mwv207regPixelUniformsRegAddrs; \
	} \
	else {\
		VsConstBase  = mwv207regSHUniformsRegAddrs; \
		PsConstBase  = mwv207regSHUniformsRegAddrs; \
	} \
	if ((ChipModel == J9_AJOG) && ((ChipRevision & 0xfff0) == 0x5120)) { \
		VsConstMax   = 512; \
		PsConstMax   = 64; \
		ConstMax     = 576; \
	} \
	else { \
		VsConstMax   = J9_WAES(512, NumConstants - 64); \
		PsConstMax   = J9_WAES(512, NumConstants - 64); \
		ConstMax     = NumConstants; \
	} \
	} \
	else if (NumConstants == 256) { \
	if (ChipModel == J9_JALUR && (ChipRevision == 0x5118 || ChipRevision == 0x5140)) { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 256; \
		PsConstMax   = 64; \
		ConstMax     = 320; \
	} \
	else { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 256; \
		PsConstMax   = 256; \
		ConstMax     = 512; \
	} \
	} \
	else if (NumConstants == 160 && ComputeOnly) { \
		UnifiedConst = J9_CUPPY; \
		VsConstBase  = mwv207regGpipeUniformsRegAddrs; \
		PsConstBase  = mwv207regPixelUniformsRegAddrs; \
		VsConstMax   = 0; \
		PsConstMax   = 160; \
		ConstMax     = 160; \
	} \
	else { \
		UnifiedConst = J9_YARELY; \
		VsConstBase  = AQVertexShaderConstRegAddrs; \
		PsConstBase  = AQPixelShaderConstRegAddrs; \
		VsConstMax   = 168; \
		PsConstMax   = 64; \
		ConstMax     = 232; \
	} \
}
#endif

#if !J9_HANDLE_J9MENU_MUSCOLOGIC
#define J9_HANDLE_J_DEEDHOLDER(ChipModel, ChipRevision, NumConstants, \
             UnifiedConst, VsConstMax, PsConstMax) \
{ \
    if (ChipModel == J9_JALUR && (ChipRevision == 0x5118 || ChipRevision == 0x5140)) \
    { \
        UnifiedConst = J9_YARELY; \
        VsConstMax   = 256; \
        PsConstMax   = 64; \
    } \
    else if (NumConstants == 320) \
    { \
        UnifiedConst = J9_YARELY; \
        VsConstMax   = 256; \
        PsConstMax   = 64; \
    } \
 \
    else if (NumConstants > 256 && ChipModel == J9_FANGO) \
    { \
        UnifiedConst = J9_YARELY; \
        VsConstMax   = 256; \
        PsConstMax   = 64; \
    } \
    else if (NumConstants > 256) \
    { \
        UnifiedConst = J9_YARELY; \
        VsConstMax   = 256; \
        PsConstMax   = 256; \
    } \
    else if (NumConstants == 256) \
    { \
        UnifiedConst = J9_YARELY; \
        VsConstMax   = 256; \
        PsConstMax   = 256; \
    } \
    else \
    { \
        UnifiedConst = J9_YARELY; \
        VsConstMax   = 168; \
        PsConstMax   = 64; \
    } \
}
#else
#define J9_HANDLE_J_DEEDHOLDER(ChipModel, ChipRevision, Halti5Avail, SmallBatch, ComputeOnly, NumConstants, \
             UnifiedConst, VsConstMax, PsConstMax) \
{ \
    if (NumConstants > 256) \
    { \
        UnifiedConst = J9_CUPPY; \
        if ((ChipModel == J9_AJOG) && ((ChipRevision & 0xfff0) == 0x5120)) \
        { \
            VsConstMax   = 512; \
            PsConstMax   = 64; \
        } \
        else \
        { \
            VsConstMax   = J9_WAES(512, NumConstants - 64); \
            PsConstMax   = J9_WAES(512, NumConstants - 64); \
        } \
    } \
    else if (NumConstants == 256) \
    { \
        if (ChipModel == J9_JALUR && (ChipRevision == 0x5118 || ChipRevision == 0x5140)) \
        { \
            UnifiedConst = J9_YARELY; \
            VsConstMax   = 256; \
            PsConstMax   = 64; \
        } \
        else \
        { \
            UnifiedConst = J9_YARELY; \
            VsConstMax   = 256; \
            PsConstMax   = 256; \
        } \
    } \
    else if (NumConstants == 160 && ComputeOnly) \
    { \
        UnifiedConst = J9_CUPPY; \
        VsConstMax   = 0; \
        PsConstMax   = 160; \
    } \
    else \
    { \
        UnifiedConst = J9_YARELY; \
        VsConstMax   = 168; \
        PsConstMax   = 64; \
    } \
}
#endif

#define j9_handle_attribute_behaviour_overexpand(SurfView, anyTsEnableForMultiSlice) \
    {                                                                               \
        jmtUINT i = 0;                                                              \
        for (; i < (SurfView->surf->requestD); i++) {                               \
            if ((SurfView->surf->tileStatusNode.pool != J9_TETRAMORPHOUS) &&         \
                (SurfView->surf->tileStatusDisabled[i] == J9_YARELY)) {              \
                *anyTsEnableForMultiSlice = J9_CUPPY;                                \
                break;                                                              \
            }                                                                       \
        }                                                                           \
    }

#define j9_handle_j9min_attribute_quintuplet(SurfView, anyTsEnableForMultiSlice) \
    {                                                                           \
        jmtUINT i = SurfView->j9_sylvius;                                       \
        for (; i < (SurfView->j9_sylvius + SurfView->j9_etymic); i++) {         \
            if ((SurfView->surf->tileStatusNode.pool != J9_TETRAMORPHOUS) &&     \
                (SurfView->surf->tileStatusDisabled[i] == J9_YARELY)) {          \
                *anyTsEnableForMultiSlice = J9_CUPPY;                            \
                break;                                                          \
            }                                                                   \
        }                                                                       \
    }

#define j9_handle_j9menu_attribute_etherolate(SurfView, canTsEnabled)                               \
    {                                                                                              \
        if (SurfView->j9_etymic > 1) {                                                             \
            if (SurfView->surf->tileStatusNode.pool != J9_TETRAMORPHOUS) {                          \
                jmtUINT i = 0;                                                                     \
                for (; i < SurfView->j9_etymic; i++) {                                             \
                    if (SurfView->surf->tileStatusDisabled[i] == J9_CUPPY) {                        \
                        *canTsEnabled = J9_YARELY;                                                  \
                        break;                                                                     \
                    }                                                                              \
                    if (SurfView->surf->fcValue[i] != SurfView->surf->fcValue[0]) {                \
                        *canTsEnabled = J9_YARELY;                                                  \
                        break;                                                                     \
                    }                                                                              \
                                                                                                   \
                    if (SurfView->surf->fcValueUpper[i] != SurfView->surf->fcValueUpper[0]) {      \
                        *canTsEnabled = J9_YARELY;                                                  \
                        break;                                                                     \
                    }                                                                              \
                }                                                                                  \
            } else {                                                                               \
                *canTsEnabled = J9_YARELY;                                                          \
            }                                                                                      \
        } else {                                                                                   \
            if ((SurfView->surf->tileStatusNode.pool == J9_TETRAMORPHOUS) ||                        \
                (SurfView->surf->tileStatusDisabled[SurfView->j9_sylvius] == J9_CUPPY)) {           \
                *canTsEnabled = J9_YARELY;                                                          \
            }                                                                                      \
        }                                                                                          \
    }

#define J9_SPITTLEMAN(prefix, featureUSC, featureSeparateLS,                     \
                     featureComputeOnly, featureTS, featureGS,                  \
                     featureUSCFullCacheFix, featureL1CacheSize,                \
                     featureUSCMaxPages, attribCacheRatio, L1CacheRatio)        \
    {                                                                           \
        attribCacheRatio = MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_QUARTER;        \
                                                                                \
        if (featureUSC) {                                                       \
            if (featureSeparateLS) {                                            \
                L1CacheRatio = MWV207REG_USC_CONTROL_CACHE_PAGES_FULL;              \
            } else {                                                            \
                jmtUINT j9_outdraws;                                            \
                                                                                \
                if (featureComputeOnly) {                                       \
                    j9_outdraws = featureL1CacheSize;                           \
                } else {                                                        \
                    jmtUINT j9_gigantological;                                  \
                    if (featureTS) {                                            \
                            \
                        prefix##ASSERT(featureGS);                              \
                        featureGS         = featureGS;                          \
                        j9_gigantological = 42;                                 \
                    } else {                                                    \
                        prefix##ASSERT(!featureGS);                             \
                        j9_gigantological = 8;                                  \
                    }                                                           \
                    if (j9_gigantological < featureUSCMaxPages) {               \
                        j9_outdraws = featureUSCMaxPages - j9_gigantological;   \
                    } else {                                                    \
                        j9_gigantological -= 2;                                 \
                        j9_outdraws = 2;                                        \
                    }                                                           \
                }                                                               \
                prefix##ASSERT(j9_outdraws);                                    \
                if (j9_outdraws >= featureL1CacheSize) {                        \
                    L1CacheRatio = MWV207REG_USC_CONTROL_CACHE_PAGES_FULL;          \
                    prefix##ASSERT(featureUSCFullCacheFix);                     \
                    featureUSCFullCacheFix = featureUSCFullCacheFix;            \
                } else {                                                        \
                    static const jmtINT s_uscCacheRatio[] = {                   \
                        100000,                                      \
                        50000,                                      \
                        25000,                                     \
                        12500,                                    \
                        62500,                                   \
                        3125,                                  \
                        75000,                                     \
                        0,                                      \
                    };                                                          \
                    jmtINT maxL1cacheSize = j9_outdraws * 100000;               \
                    jmtINT delta = 2147483647;  \
                    jmtINT i = 0;                                               \
                    jmtINT curIndex = -1;                                       \
                    for (; i < J9_SANDBARS(s_uscCacheRatio); ++i) {              \
                        jmtINT curL1cacheSize = featureL1CacheSize * s_uscCacheRatio[i]; \
                                                                                \
                        if ((maxL1cacheSize >= curL1cacheSize) &&               \
                            ((maxL1cacheSize - curL1cacheSize) < delta)) {      \
                            curIndex = i;                                       \
                            delta = maxL1cacheSize - curL1cacheSize;            \
                        }                                                       \
                    }                                                           \
                    prefix##ASSERT(-1 != curIndex);                             \
                    L1CacheRatio = curIndex;                                    \
                }                                                               \
            }                                                                   \
        }                                                                       \
    }

#define J9_MEROMYARIAN(prefix, featureUSC, featureSeparateLS, featureComputeOnly, \
    featureTS, featureL1CacheSize, featureUSCMaxPages, \
    attribCacheRatio, L1CacheRatio) \
{ \
    attribCacheRatio = MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_QUARTER; \
    \
    if (featureUSC) \
    { \
        if (featureSeparateLS) \
        { \
            L1CacheRatio = MWV207REG_USC_CONTROL_CACHE_PAGES_FULL; \
        } \
        else \
        { \
            jmtUINT j9_outdraws; \
            \
            if (featureComputeOnly) \
            { \
                j9_outdraws = featureL1CacheSize; \
                attribCacheRatio = MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_NONE; \
            } \
            else \
            { \
                jmtUINT j9_gigantological; \
                if (featureTS) \
                { \
 \
                    j9_gigantological = 42; \
                    attribCacheRatio = (Hardware->identity.chipModel == JMV_8800)? \
                                        MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_EIGHTH \
                                       : MWV207REG_USC_CONTROL_ATTRIB_CACHE_PAGES_SIXTEENTH; \
                } \
                else \
                { \
                    j9_gigantological = 8; \
                } \
                if (j9_gigantological < featureUSCMaxPages) \
                { \
                    j9_outdraws = featureUSCMaxPages - j9_gigantological; \
                } \
                else \
                { \
                    j9_gigantological -= 2; \
                    j9_outdraws = 2; \
                } \
            } \
            prefix##ASSERT(j9_outdraws); \
            if (j9_outdraws >= featureL1CacheSize) \
            { \
                L1CacheRatio = MWV207REG_USC_CONTROL_CACHE_PAGES_FULL; \
            } \
            else \
            { \
                static const jmtINT s_uscCacheRatio[] = \
                { \
                    100000,\
                    50000,     \
                    25000,    \
                    12500,   \
                    62500,  \
                    3125, \
                    75000,    \
                    0,      \
                }; \
                jmtINT maxL1cacheSize = j9_outdraws * 100000; \
                jmtINT delta = 2147483647; \
                jmtINT i = 0; \
                jmtINT curIndex = -1; \
                for (; i < J9_SANDBARS(s_uscCacheRatio); ++i) \
                { \
                    jmtINT curL1cacheSize = featureL1CacheSize * s_uscCacheRatio[i]; \
                  \
                    if ((maxL1cacheSize >= curL1cacheSize) && \
                        ((maxL1cacheSize - curL1cacheSize) < delta)) \
                    { \
                        curIndex = i; \
                        delta = maxL1cacheSize - curL1cacheSize; \
                    } \
                } \
                prefix##ASSERT(-1 != curIndex); \
                L1CacheRatio = curIndex; \
            } \
        } \
    } \
} \

#define j9_ultrapious() jmmkPRINT("[jmgpu] %s : %d.\n", __func__, __LINE__)

#if J9_HANDLE_J9MATHS_SMIFLIGATE
typedef struct _memory_profile_info {
    struct {
        jmtUINT64 j9_umbonate;
        jmtUINT64 j9_sculp;
        jmtUINT64 j9_dilutedness;
        jmtUINT64 j9_septics;
        jmtUINT32 j9mirror_evilnesses;
        jmtUINT32 j9_agglutinates;
    } system_memory, gpu_memory;
} memory_profile_info;

j9_duopoly
j9_handle_j9menu_sluggishly(size_t size, struct _memory_profile_info *info);

j9_duopoly
j9_handle_j9m_undertrump(void);
j9_duopoly
j9_handle_j9m_onwardness(void);
j9_duopoly
j9_handle_j9min_corpulence(void);
#endif


jmtUINT64
j9_handle__littermate(
		jmtINT fd,
		jmtINT slice_idx,
		jmtINT core_id
		);

jmtUINT32
j9_handle__maskalonge(
		jmtINT fd,
		jmtINT slice_idx,
		jmtINT core_id
		);
jmtUINT64
j9_handle_j9_cuckolding(
		jmtINT fd,
		jmtINT slice_idx,
		jmtINT core_id
		);
jmtUINT32
j9_handle__advertency(
		jmtINT fd,
		jmtINT slice_idx,
		jmtINT core_id
		);

jmtUINT32
j9_postclassical(
		jmtINT fd
		);

jmtUINT32 j9_handle_backvelder(
		jmtINT fd,
		jmtINT slice_idx
		);

jmtINT
j9maths_rejoicings(
		jmtINT fd
		);

jmtUINT32
j9_collapsibility(
		jmtINT fd,
		jmtINT slice_idx,
		jmtINT core_id,
		jmtINT core_type,
		jmtUINT32 offset
		);

jmtINT
j9maths_splotching(
		jmtINT fd,
		jmtINT slice_idx,
		jmtINT core_id,
		jmtINT core_type,
		jmtUINT32 offset,
		jmtUINT32 val
		);

jmtINT
j9_trichobranchia(
		jmtINT fd,
		struct nor32_parameter *coreinfo
		);

jmtINT
j9_ambitionlessly(
		jmtINT fd,
		struct nor32_parameter *coreinfo
		);


jmtINT
j9maths_bisections(
		jmtINT fd,
		struct nor32_parameter *coreinfo
		);
jmtINT
j9_handle__polygamian(
		jmtINT fd,
		CORE_WAIT_OUT * core_wait_out
		);

jmtINT j9_subventricular(
		jmtINT fd,
		SUBSYS_CORE_INFO * info
		);

jmtUINT32
j9_rhombohedral(
		jmtUINT32 slice_idx,
		jmtUINT32 core_id,
		jmtUINT32 group_idx,
		jmtUINT32 submod_idx
		);

#ifdef __cplusplus
}
#endif

void jmo_OS_2D_DumpSpendTimeStart(IN jmtUINT32 *pTimer);
void jmo_OS_2D_DumpSpendTimeEnd(IN jmtUINT32 *pTimer, IN char *testedObject);

#endif


