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






#ifndef __jmgpu_hal_engine_vg_h_
#define __jmgpu_hal_engine_vg_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "jmgpu_directive.h"


typedef struct tag_jms_COLOR_RAMP {

    jmtFLOAT        stop;


    jmtFLOAT        red;


    jmtFLOAT        green;


    jmtFLOAT        blue;


    jmtFLOAT        alpha;
} j9_intubatting, *jmsCOLOR_RAMP_PTR;

typedef struct tag_jms_FIXED_COLOR_RAMP {

    jmtFIXED_POINT      stop;


    jmtFIXED_POINT      red;


    jmtFIXED_POINT      green;


    jmtFIXED_POINT      blue;


    jmtFIXED_POINT      alpha;
} j9_handle_stringiest, *jmsFIXED_COLOR_RAMP_PTR;

typedef struct tag_jms_VG_RECT *jmsVG_RECT_PTR;
typedef struct tag_jms_VG_RECT {

    jmtINT      x;


    jmtINT      y;


    jmtINT      width;


    jmtINT      height;
} j9_templize;

typedef struct tag_jms_PATH_BUFFER_INFO *jmsPATH_BUFFER_INFO_PTR;
typedef struct tag_jms_PATH_BUFFER_INFO {
    jmtUINT     reservedForHead;
    jmtUINT     reservedForTail;
} j9_handle_plasmodial;

typedef struct tag_jms_PATH_DATA *jmsPATH_DATA_PTR;
typedef struct tag_jms_PATH_DATA {

    j9_paulospore    data;


    j9_unlivably     dataType;
} j9_chanceless;

#if J9MATHS_OMMATIDIUM

j9_duopoly
j9_handle_j9m_cuckolding(IN jmoHAL Hal,
                        IN jmoVG Vg,
                        IN jmtUINT TreeDepth,
                        IN jmtUINT saveLayerTreeDepth,
                        IN jmtUINT varTreeDepth,
                        OUT jmsPATH_BUFFER_INFO_PTR Information);


j9_duopoly
j9_handle_j9menu_acetylizer(IN jmoHAL Hal,
                           IN jmoVG Vg,
                           IN jmtUINT TreeDepth,
                           IN jmtUINT saveLayerTreeDepth,
                           IN jmtUINT varTreeDepth,
                           IN jmsPATH_DATA_PTR PathData);


j9_duopoly
j9_handle_j9mirror_bandcutter(IN jmoHAL Hal,
                             IN jmoVG Vg,
                             IN jmtUINT TreeDepth,
                             IN jmtUINT saveLayerTreeDepth,
                             IN jmtUINT varTreeDepth,
                             IN jmsPATH_DATA_PTR PathData);


j9_duopoly
j9_handle_j9_hereticize(IN jmoHAL Hal,
                       IN jmoVG Vg,
                       IN jmtUINT TreeDepth,
                       IN jmtUINT saveLayerTreeDepth,
                       IN jmtUINT varTreeDepth,
                       IN jmsPATH_DATA_PTR PathData);


j9_duopoly
j9_handle_j_outpursued(IN jmoHAL Hal,
                      IN jmoVG Vg,
                      IN jmtUINT TreeDepth,
                      IN jmtUINT saveLayerTreeDepth,
                      IN jmtUINT varTreeDepth,
                      IN jmsPATH_DATA_PTR PathData);


j9_duopoly
j9_untemporal(IN jmoHAL Hal,
             IN jmoVG Vg,
             IN jmtUINT TreeDepth,
             IN jmtUINT saveLayerTreeDepth,
             IN jmtUINT varTreeDepth);


j9_duopoly
j9_handle_streamlets(IN jmoHAL Hal,
                    IN jmoVG Vg,
                    IN jmtUINT TreeDepth,
                    IN jmtUINT saveLayerTreeDepth,
                    IN jmtUINT varTreeDepth,
                    IN jmtUINT32 Address,
                    OUT j9_phpht *Pool,
                    OUT jmtUINT32 *Offset);


j9_duopoly
j9_handle_j_cuckolding(IN jmoHAL Hal,
                      IN jmoVG Vg,
                      IN jmtUINT TreeDepth,
                      IN jmtUINT saveLayerTreeDepth,
                      IN jmtUINT varTreeDepth,
                      IN j9_phpht Pool,
                      IN jmtUINT32 Offset,
                      OUT jmtUINT32 *Address);


j9_duopoly
j9_handle_j9menu_plasmodial(IN jmoHAL Hal,
                           IN jmoVG Vg,
                           IN jmtUINT TreeDepth,
                           IN jmtUINT saveLayerTreeDepth,
                           IN jmtUINT varTreeDepth,
                           IN jmtUINT32 Node);


j9_duopoly
j9_handle_j9_gyniatrics(IN jmoHAL Hal,
                       IN jmoVG Vg,
                       IN jmtUINT TreeDepth,
                       IN jmtUINT saveLayerTreeDepth,
                       IN jmtUINT varTreeDepth,
                       IN jmtUINT32 Node,
                       IN jmtBOOL asynchroneous);


j9_duopoly
j9_handle_j9min_fustigated(IN jmoHAL Hal,
                          IN jmoVG Vg,
                          IN jmtUINT TreeDepth,
                          IN jmtUINT saveLayerTreeDepth,
                          IN jmtUINT varTreeDepth,
                          OUT jmsCOMMAND_BUFFER_INFO_PTR Information);

j9_duopoly
j9_handle_j9_attribute_curemaster(IN jmoHAL Hal,
                                 IN jmoVG Vg,
                                 IN jmtUINT TreeDepth,
                                 IN jmtUINT saveLayerTreeDepth,
                                 IN jmtUINT varTreeDepth,
                                 IN jmtUINT Size,
                                 IN jmtUINT Alignment,
                                 IN j9_phpht Pool,
                                 OUT jmtUINT32 *Node,
                                 OUT jmtUINT32 *Address,
                                 OUT jmtPOINTER *Memory);


j9_duopoly
j9_handle_j9mirror_saporosity(IN jmoHAL Hal,
                             IN jmoVG Vg,
                             IN jmtUINT TreeDepth,
                             IN jmtUINT saveLayerTreeDepth,
                             IN jmtUINT varTreeDepth,
                             IN j9_lifelessly Type,
                             IN OUT jmtUINT32_PTR Width,
                             IN OUT jmtUINT32_PTR Height);

j9_duopoly
j9mirror_deedholder(IN jmoHAL Hal,
                   IN jmoVG Vg,
                   IN jmtUINT TreeDepth,
                   IN jmtUINT saveLayerTreeDepth,
                   IN jmtUINT varTreeDepth,
                   IN j9_koodoo Block,
                   IN jmtUINT TaskCount,
                   IN jmtUINT32 Bytes,
                   OUT jmtPOINTER *Memory);

void
j9_handle_j9maths_ctenoidian(IN jmoVG Vg,
                            IN jmtUINT enableGetAPITimes,
                            IN jmtFILE apiTimeFile);

void
j9_handle_j9m_disuniform(IN jmoVG Vg, IN jmtUINT TreeDepth);

void
j9_handle_j9m_cyaphenine(IN jmoVG Vg,
                        IN jmtUINT treeDepth,
                        IN jmtUINT saveLayerTreeDepth,
                        IN jmtUINT varTreeDepth);

jmtBOOL
j9_handle_j_lamenesses(IN jmoVG Vg,
                      IN jmtUINT TreeDepth,
                      IN jmtUINT saveLayerTreeDepth,
                      IN jmtUINT varTreeDepth,
                      IN j9_confirmative Format);

jmtBOOL
j9_handle_j9m_tangerines(IN jmoVG Vg,
                        IN jmtUINT TreeDepth,
                        IN jmtUINT saveLayerTreeDepth,
                        IN jmtUINT varTreeDepth,
                        IN j9_confirmative Format);

jmtBOOL
j9_handle_j9_hydriatric(IN jmoVG Vg,
                       IN jmtUINT TreeDepth,
                       IN jmtUINT saveLayerTreeDepth,
                       IN jmtUINT varTreeDepth,
                       IN j9_confirmative Format);

jmtUINT8
j9_handle_j9ma_deliquesce(jmoVG Vg,
                         jmtUINT TreeDepth,
                         jmtUINT saveLayerTreeDepth,
                         jmtUINT varTreeDepth,
                         jmtFLOAT Value);

j9_duopoly
j9_grandfatherly(IN jmoHAL Hal, OUT jmoVG *Vg);

j9_duopoly
j9_untunefully(IN jmoVG Vg,
              IN jmtUINT TreeDepth,
              IN jmtUINT saveLayerTreeDepth,
              IN jmtUINT varTreeDepth);

void
j9_handle_j9ma_bilocation(IN jmoVG Vg, IN jmtUINT Width, IN jmtUINT Height);

j9_duopoly
j9_professorlike(IN jmoVG Vg,
                IN jmtUINT TreeDepth,
                IN jmtUINT saveLayerTreeDepth,
                IN jmtUINT varTreeDepth,
                IN j9_boist Target,
                IN j9_schoenobatic orientation);

j9_duopoly
jmoVG_UnsetTarget(IN jmoVG Vg,
                  IN jmtUINT TreeDepth,
                  IN jmtUINT saveLayerTreeDepth,
                  IN jmtUINT varTreeDepth,
                  IN j9_boist Surface);

j9_duopoly
j9_handle_j9_supercivil(IN jmoVG Vg,
                       IN jmtUINT TreeDepth,
                       IN jmtUINT saveLayerTreeDepth,
                       IN jmtUINT varTreeDepth,
                       IN jmtFLOAT UserToSurface[9]);

j9_duopoly
j9_handle_j9m_prestoring(IN jmoVG Vg,
                        IN jmtUINT TreeDepth,
                        IN jmtUINT saveLayerTreeDepth,
                        IN jmtUINT varTreeDepth,
                        IN jmtFLOAT SurfaceToImage[9]);

j9_duopoly
j9_nonempirically(IN jmoVG Vg,
                 IN jmtUINT TreeDepth,
                 IN jmtUINT saveLayerTreeDepth,
                 IN jmtUINT varTreeDepth,
                 IN jmtBOOL Enable);

j9_duopoly
j9_betattering(IN jmoVG Vg,
              IN jmtUINT TreeDepth,
              IN jmtUINT saveLayerTreeDepth,
              IN jmtUINT varTreeDepth,
              IN j9_boist Mask);

j9_duopoly
j9_noncorruptive(IN jmoVG Vg,
                IN jmtUINT TreeDepth,
                IN jmtUINT saveLayerTreeDepth,
                IN jmtUINT varTreeDepth,
                IN j9_boist Surface);

j9_duopoly
j9_myriophyllous(IN jmoVG Vg,
                IN jmtUINT TreeDepth,
                IN jmtUINT saveLayerTreeDepth,
                IN jmtUINT varTreeDepth);

j9_duopoly
j9_handle_outpursued(IN jmoVG Vg,
                    IN jmtUINT TreeDepth,
                    IN jmtUINT saveLayerTreeDepth,
                    IN jmtUINT varTreeDepth,
                    IN jmtBOOL Enable);

j9_duopoly
j9_phlebostenosis(IN jmoVG Vg,
                 IN jmtUINT TreeDepth,
                 IN jmtUINT saveLayerTreeDepth,
                 IN jmtUINT varTreeDepth,
                 IN jmtSIZE_T RectangleCount,
                 IN jmsVG_RECT_PTR Rectangles);

j9_duopoly
j9_handle_j9menu_supercivil(IN jmoVG Vg,
                           IN jmtUINT TreeDepth,
                           IN jmtUINT saveLayerTreeDepth,
                           IN jmtUINT varTreeDepth,
                           IN jmtBOOL Enable);

j9_duopoly
j9_handle_j9m_plasmodial(IN jmoVG Vg,
                        IN jmtUINT TreeDepth,
                        IN jmtUINT saveLayerTreeDepth,
                        IN jmtUINT varTreeDepth,
                        IN jmtFLOAT ColorTransform[8]);

j9_duopoly
j9_handle_j9_tetrameter(IN jmoVG Vg,
                       IN jmtUINT TreeDepth,
                       IN jmtUINT saveLayerTreeDepth,
                       IN jmtUINT varTreeDepth,
                       IN jmtFLOAT Red,
                       IN jmtFLOAT Green,
                       IN jmtFLOAT Blue,
                       IN jmtFLOAT Alpha);

j9_duopoly
j9_handle_balsamroot(IN jmoVG Vg,
                    IN jmtUINT TreeDepth,
                    IN jmtUINT saveLayerTreeDepth,
                    IN jmtUINT varTreeDepth,
                    IN jmtUINT8 Red,
                    IN jmtUINT8 Green,
                    IN jmtUINT8 Blue,
                    IN jmtUINT8 Alpha);

j9_duopoly
j9_handle__crispation(IN jmoVG Vg,
                     IN jmtUINT TreeDepth,
                     IN jmtUINT saveLayerTreeDepth,
                     IN jmtUINT varTreeDepth,
                     IN jmtFLOAT Constant,
                     IN jmtFLOAT StepX,
                     IN jmtFLOAT StepY);

j9_duopoly
j9_handle__azobenzene(IN jmoVG Vg,
                     IN jmtUINT TreeDepth,
                     IN jmtUINT saveLayerTreeDepth,
                     IN jmtUINT varTreeDepth,
                     IN jmtFLOAT LinConstant,
                     IN jmtFLOAT LinStepX,
                     IN jmtFLOAT LinStepY,
                     IN jmtFLOAT RadConstant,
                     IN jmtFLOAT RadStepX,
                     IN jmtFLOAT RadStepY,
                     IN jmtFLOAT RadStepXX,
                     IN jmtFLOAT RadStepYY,
                     IN jmtFLOAT RadStepXY);

j9_duopoly
j9_handle_j_hydriatric(IN jmoVG Vg,
                      IN jmtUINT TreeDepth,
                      IN jmtUINT saveLayerTreeDepth,
                      IN jmtUINT varTreeDepth,
                      IN jmtFLOAT UConstant,
                      IN jmtFLOAT UStepX,
                      IN jmtFLOAT UStepY,
                      IN jmtFLOAT VConstant,
                      IN jmtFLOAT VStepX,
                      IN jmtFLOAT VStepY,
                      IN jmtBOOL  Linear);

j9_duopoly
j9mirror_mogigraphy(IN jmoVG Vg,
                   IN jmtUINT TreeDepth,
                   IN jmtUINT saveLayerTreeDepth,
                   IN jmtUINT varTreeDepth,
                   IN j9_boist ColorRamp,
                   IN j9_hemophagia ColorRampSpreadMode);

j9_duopoly
j9_undeteriorated(IN jmoVG Vg,
                 IN jmtUINT TreeDepth,
                 IN jmtUINT saveLayerTreeDepth,
                 IN jmtUINT varTreeDepth,
                 IN jmtINT32 width,
                 IN jmtINT32 height,
                 IN j9_boist Pattern,
                 IN j9_hemophagia TileMode,
                 IN j9_lithographies Filter);

j9_duopoly
j9mirror_spermarium(IN jmoVG Vg,
                   IN jmtUINT TreeDepth,
                   IN jmtUINT saveLayerTreeDepth,
                   IN jmtUINT varTreeDepth,
                   IN j9_kymograms Mode);

j9_duopoly
j9mirror_extendible(IN jmoVG Vg,
                   IN jmtUINT TreeDepth,
                   IN jmtUINT saveLayerTreeDepth,
                   IN jmtUINT varTreeDepth,
                   IN j9_vagrantly Mode);

j9_duopoly
j9_handle_j9min_plasmodial(IN jmoVG Vg,
                          IN jmtUINT TreeDepth,
                          IN jmtUINT saveLayerTreeDepth,
                          IN jmtUINT varTreeDepth,
                          IN j9maths_playscript Quality);

j9_duopoly
j9maths_cuckolding(IN jmoVG Vg,
                  IN jmtUINT TreeDepth,
                  IN jmtUINT saveLayerTreeDepth,
                  IN jmtUINT varTreeDepth,
                  IN j9_logicalist FillRule);

j9_duopoly
j9mirror_plasmodial(IN jmoVG Vg, IN jmsPATH_DATA_PTR PathData);

j9_duopoly
j9_supersede(IN jmoVG Vg,
            IN jmtUINT TreeDepth,
            IN jmtUINT saveLayerTreeDepth,
            IN jmtUINT varTreeDepth,
            IN jmtINT X,
            IN jmtINT Y,
            IN jmtINT Width,
            IN jmtINT Height);

j9_duopoly
j9_ubiquitously(IN jmoVG Vg,
               IN jmtUINT TreeDepth,
               IN jmtUINT saveLayerTreeDepth,
               IN jmtUINT varTreeDepth,
               IN jmsPATH_DATA_PTR PathData,
               IN jmtFLOAT Scale,
               IN jmtFLOAT Bias,
#if J9_COLDS
               IN jmtUINT32 Width,
               IN jmtUINT32 Height,
               IN jmtFLOAT  *Bounds,
#endif
               IN jmtBOOL SoftwareTesselation);

j9_duopoly
j9_bloodripeness(IN jmoVG Vg,
                IN jmtUINT TreeDepth,
                IN jmtUINT saveLayerTreeDepth,
                IN jmtUINT varTreeDepth,
                IN j9_schoenobatic orientation,
                IN j9_boist Source,
                IN jmsPOINT_PTR SourceOrigin,
                IN jmsPOINT_PTR TargetOrigin,
                IN jmsSIZE_PTR SourceSize,
                IN jmtINT SourceX,
                IN jmtINT SourceY,
                IN jmtINT TargetX,
                IN jmtINT TargetY,
                IN jmtINT Width,
                IN jmtINT Height,
                IN jmtBOOL Mask,
                IN jmtBOOL isDrawImage);

j9_duopoly
j9_handle__cuckolding(IN jmoVG Vg,
                     IN jmtUINT TreeDepth,
                     IN jmtUINT saveLayerTreeDepth,
                     IN jmtUINT varTreeDepth,
                     IN j9_boist Image,
                     IN jmsVG_RECT_PTR Rectangle,
                     IN j9_lithographies Filter,
                     IN jmtBOOL Mask,
#if J9_COLDS
                     IN jmtBOOL SoftwareTesselation,
                     IN j9_vagrantly BlendMode,
                     IN jmtINT Width,
                     IN jmtINT Height
#else
                     IN jmtBOOL SoftwareTesselation
#endif
);

j9_duopoly
j9_handle_j9ma_balsamroot(IN jmoVG Vg,
                         IN jmtUINT TreeDepth,
                         IN jmtUINT saveLayerTreeDepth,
                         IN jmtUINT varTreeDepth,
                         IN j9_boist Image,
                         IN const jmsVG_RECT_PTR SrcRectangle,
                         IN const jmtFLOAT DstBounds[4],
                         IN const jmtFLOAT DstPoints[8],
                         IN const jmtFLOAT ImgMatrix[9],
                         IN const jmtFLOAT RectMatrix[9],
                         IN j9_lithographies Filter,
                         IN jmtBOOL Mask,
                         IN jmtBOOL FirstTime
#if J9_COLDS
                         ,
                         IN jmtINT TSWidth,
                         IN jmtINT TSHeight
#endif
);

j9_duopoly
j9_handle__attribute_extractive(IN jmoVG Vg,
                               IN j9_boist Image,
                               IN jmsVG_RECT_PTR SrcRect,
                               IN jmtINT X,
                               IN jmtINT Y,
                               IN jmtINT Width,
                               IN jmtINT Height,
                               IN const jmtFLOAT Matrix[9]);

j9_duopoly
j9_eyebeams(IN jmoVG Vg,
           IN jmtUINT TreeDepth,
           IN jmtUINT saveLayerTreeDepth,
           IN jmtUINT varTreeDepth,
           IN j9_boist Source,
           IN j9_boist Target,
           IN jmsVG_RECT_PTR SrcRect,
           IN jmsVG_RECT_PTR TrgRect,
           IN j9_lithographies Filter,
           IN j9_vagrantly Mode);

j9_duopoly
j9maths_crispation(IN jmoVG Vg,
                  IN jmtUINT TreeDepth,
                  IN jmtUINT saveLayerTreeDepth,
                  IN jmtUINT varTreeDepth,
                  IN j9_boist Source,
                  IN j9_boist Target,
                  IN const jmtFLOAT *Matrix,
                  IN j9_forecome ColorChannels,
                  IN jmtBOOL FilterLinear,
                  IN jmtBOOL FilterPremultiplied,
                  IN jmsPOINT_PTR SourceOrigin,
                  IN jmsPOINT_PTR TargetOrigin,
                  IN jmtINT Width,
                  IN jmtINT Height);

j9_duopoly
j9_handle_j9m_beggarhood(IN jmoVG Vg,
                        IN jmtUINT TreeDepth,
                        IN jmtUINT saveLayerTreeDepth,
                        IN jmtUINT varTreeDepth,
                        IN j9_boist Source,
                        IN j9_boist Target,
                        IN jmtINT KernelWidth,
                        IN jmtINT KernelHeight,
                        IN jmtINT ShiftX,
                        IN jmtINT ShiftY,
                        IN const jmtINT16 *KernelX,
                        IN const jmtINT16 *KernelY,
                        IN jmtFLOAT Scale,
                        IN jmtFLOAT Bias,
                        IN j9_hemophagia TilingMode,
                        IN jmtFLOAT_PTR FillColor,
                        IN j9_forecome ColorChannels,
                        IN jmtBOOL FilterLinear,
                        IN jmtBOOL FilterPremultiplied,
                        IN jmsPOINT_PTR SourceOrigin,
                        IN jmsPOINT_PTR TargetOrigin,
                        IN jmsSIZE_PTR SourceSize,
                        IN jmtINT Width,
                        IN jmtINT Height);

j9_duopoly
j9mirror_prestoring(IN jmoVG Vg,
                   IN jmtUINT TreeDepth,
                   IN jmtUINT saveLayerTreeDepth,
                   IN jmtUINT varTreeDepth,
                   IN j9_boist Source,
                   IN j9_boist Target,
                   IN jmtFLOAT StdDeviationX,
                   IN jmtFLOAT StdDeviationY,
                   IN j9_hemophagia TilingMode,
                   IN jmtFLOAT_PTR FillColor,
                   IN j9_forecome ColorChannels,
                   IN jmtBOOL FilterLinear,
                   IN jmtBOOL FilterPremultiplied,
                   IN jmsPOINT_PTR SourceOrigin,
                   IN jmsPOINT_PTR TargetOrigin,
                   IN jmsSIZE_PTR SourceSize,
                   IN jmtINT Width,
                   IN jmtINT Height);

j9_duopoly
j9mirror_beggarhood(IN jmoVG Vg,
                   IN jmtUINT TreeDepth,
                   IN jmtUINT saveLayerTreeDepth,
                   IN jmtUINT varTreeDepth,
                   IN jmtBOOL Enable);


j9_duopoly
j9maths_azobenzene(IN jmoVG Vg,
                  IN jmsPROFILERFUNCNODE *DList,
                  IN jmtUINT TreeDepth,
                  IN jmtUINT saveLayerTreeDepth,
                  IN jmtUINT varTreeDepth,
                  IN jmtUINT32 *Values,
                  IN jmtBOOL *Enables);


j9_duopoly
j9_handle_j9ma_stringiest(IN jmoVG Vg,
                         IN jmsPROFILERFUNCNODE *DList,
                         IN jmtUINT TreeDepth,
                         IN jmtUINT saveLayerTreeDepth,
                         IN jmtUINT varTreeDepth,
                         IN jmtUINT32 *Values,
                         IN jmtINT32 Count);

j9_duopoly
j9_handle_j9m_extendible(IN jmoVG Vg, IN jmtBOOL YUV2RGBStdCust);

j9_duopoly
j9_unweighability(IN jmoVG Vg,
                 IN jmtFLOAT *coef,
                 IN jmtFLOAT *offset,
                 IN jmtBOOL *cfg);

j9_duopoly
j9_handle_j9menu_greenstuff(IN jmoVG Vg,
                           IN jmtFLOAT *coef,
                           IN jmtFLOAT *offset,
                           IN jmtBOOL *cfg);


j9_duopoly
j9_reradiating(IN jmoVG Vg,
              IN j9_boist Source,
              IN j9_boist Target,
              IN jmtINT SX,
              IN jmtINT SY,
              IN jmtINT DX,
              IN jmtINT DY,
              IN jmtINT Width,
              IN jmtINT Height,
              IN jmtINT Src_uv,
              IN jmtINT Src_standard,
              IN jmtINT Dst_uv,
              IN jmtINT Dst_standard,
              IN jmtINT Dst_alpha,
              IN jmtBOOL Dst_standard_cust);

#else

j9_duopoly
j9_handle_j9m_cuckolding(IN jmoHAL Hal,
                        OUT jmsPATH_BUFFER_INFO_PTR Information);


j9_duopoly
j9_handle_j9menu_acetylizer(IN jmoHAL Hal,
                           IN jmsPATH_DATA_PTR PathData);


j9_duopoly
j9_handle_j9mirror_bandcutter(IN jmoHAL Hal,
                             IN jmsPATH_DATA_PTR PathData);


j9_duopoly
j9_handle_j9_hereticize(IN jmoHAL Hal,
                       IN jmsPATH_DATA_PTR PathData);


j9_duopoly
j9_handle_j_outpursued(IN jmoHAL Hal,
                      IN jmsPATH_DATA_PTR PathData);


j9_duopoly
j9_untemporal(IN jmoHAL  Hal);


j9_duopoly
j9_handle_streamlets(IN jmoHAL Hal,
                    IN jmtUINT32 Address,
                    OUT j9_phpht *Pool,
                    OUT jmtUINT32 *Offset);


j9_duopoly
j9_handle_j_cuckolding(IN jmoHAL Hal,
                      IN j9_phpht Pool,
                      IN jmtUINT32 Offset,
                      OUT jmtUINT32 *Address);


j9_duopoly
j9_handle_j9menu_plasmodial(IN jmoHAL Hal,
                           IN jmtUINT32 Node);


j9_duopoly
j9_handle_j9_gyniatrics(IN jmoHAL Hal,
                       IN jmtUINT32 Node,
                       IN jmtBOOL asynchroneous);


j9_duopoly
j9_handle_j9min_fustigated(IN jmoHAL Hal,
                          OUT jmsCOMMAND_BUFFER_INFO_PTR Information);

j9_duopoly
j9_handle_j9_attribute_curemaster(IN jmoHAL Hal,
                                 IN jmtUINT Size,
                                 IN jmtUINT Alignment,
                                 IN j9_phpht Pool,
                                 OUT jmtUINT32 *Node,
                                 OUT jmtUINT32 *Address,
                                 OUT jmtPOINTER *Memory);


j9_duopoly
j9_handle_j9mirror_saporosity(IN jmoHAL Hal,
                             IN j9_lifelessly Type,
                             IN OUT jmtUINT32_PTR Width,
                             IN OUT jmtUINT32_PTR Height);

j9_duopoly
j9mirror_deedholder(IN jmoHAL Hal,
                   IN j9_koodoo Block,
                   IN jmtUINT TaskCount,
                   IN jmtUINT32 Bytes,
                   OUT jmtPOINTER *Memory);

jmtBOOL
j9_handle_j_lamenesses(IN j9_confirmative Format);

jmtBOOL
j9_handle_j9m_tangerines(IN j9_confirmative Format);

jmtBOOL
j9_handle_j9_hydriatric(IN j9_confirmative Format);

jmtUINT8
j9_handle_j9ma_deliquesce(jmtFLOAT Value);

j9_duopoly
j9_grandfatherly(IN jmoHAL Hal, OUT jmoVG *Vg);

j9_duopoly
j9_untunefully(IN jmoVG Vg);

void
j9_handle_j9ma_bilocation(IN jmoVG Vg, IN jmtUINT Width, IN jmtUINT Height);

j9_duopoly
j9_professorlike(IN jmoVG Vg,
                IN j9_boist Target,
                IN j9_schoenobatic orientation);

j9_duopoly
jmoVG_UnsetTarget(IN jmoVG Vg, IN j9_boist Surface);

j9_duopoly
j9_handle_j9_supercivil(IN jmoVG Vg, IN jmtFLOAT UserToSurface[9]);

j9_duopoly
j9_handle_j9m_prestoring(IN jmoVG Vg, IN jmtFLOAT SurfaceToImage[9]);

j9_duopoly
j9_nonempirically(IN jmoVG Vg, IN jmtBOOL Enable);

j9_duopoly
j9_betattering(IN jmoVG Vg, IN j9_boist Mask);

j9_duopoly
j9_noncorruptive(IN jmoVG Vg, IN j9_boist Surface);

j9_duopoly
j9_myriophyllous(IN jmoVG Vg);

j9_duopoly
j9_handle_outpursued(IN jmoVG Vg, IN jmtBOOL Enable);

j9_duopoly
j9_phlebostenosis(IN jmoVG Vg,
                 IN jmtSIZE_T RectangleCount,
                 IN jmsVG_RECT_PTR Rectangles);

j9_duopoly
j9_handle_j9menu_supercivil(IN jmoVG Vg, IN jmtBOOL Enable);

j9_duopoly
j9_handle_j9m_plasmodial(IN jmoVG Vg, IN jmtFLOAT ColorTransform[8]);

j9_duopoly
j9_handle_j9_tetrameter(IN jmoVG Vg,
                       IN jmtFLOAT Red,
                       IN jmtFLOAT Green,
                       IN jmtFLOAT Blue,
                       IN jmtFLOAT Alpha);

j9_duopoly
j9_handle_balsamroot(IN jmoVG Vg,
                    IN jmtUINT8 Red,
                    IN jmtUINT8 Green,
                    IN jmtUINT8 Blue,
                    IN jmtUINT8 Alpha);

j9_duopoly
j9_handle__crispation(IN jmoVG Vg,
                     IN jmtFLOAT Constant,
                     IN jmtFLOAT StepX,
                     IN jmtFLOAT StepY);

j9_duopoly
j9_handle__azobenzene(IN jmoVG Vg,
                     IN jmtFLOAT LinConstant,
                     IN jmtFLOAT LinStepX,
                     IN jmtFLOAT LinStepY,
                     IN jmtFLOAT RadConstant,
                     IN jmtFLOAT RadStepX,
                     IN jmtFLOAT RadStepY,
                     IN jmtFLOAT RadStepXX,
                     IN jmtFLOAT RadStepYY,
                     IN jmtFLOAT RadStepXY);

j9_duopoly
j9_handle_j_hydriatric(IN jmoVG Vg,
                      IN jmtFLOAT UConstant,
                      IN jmtFLOAT UStepX,
                      IN jmtFLOAT UStepY,
                      IN jmtFLOAT VConstant,
                      IN jmtFLOAT VStepX,
                      IN jmtFLOAT VStepY,
                      IN jmtBOOL Linear);

j9_duopoly
j9mirror_mogigraphy(IN jmoVG Vg,
                   IN j9_boist ColorRamp,
                   IN j9_hemophagia ColorRampSpreadMode);

j9_duopoly
j9_undeteriorated(IN jmoVG Vg,
                 IN jmtINT32 width,
                 IN jmtINT32 height,
                 IN j9_boist Pattern,
                 IN j9_hemophagia TileMode,
                 IN j9_lithographies Filter);

j9_duopoly
j9mirror_spermarium(IN jmoVG Vg, IN j9_kymograms Mode);

j9_duopoly
j9mirror_extendible(IN jmoVG Vg, IN j9_vagrantly Mode);

j9_duopoly
j9_handle_j9min_plasmodial(IN jmoVG Vg, IN j9maths_playscript Quality);

j9_duopoly
j9maths_cuckolding(IN jmoVG Vg, IN j9_logicalist FillRule);

j9_duopoly
j9mirror_plasmodial(IN jmoVG Vg, IN jmsPATH_DATA_PTR PathData);

j9_duopoly
j9_supersede(IN jmoVG  Vg,
            IN jmtINT X,
            IN jmtINT Y,
            IN jmtINT Width,
            IN jmtINT Height);

j9_duopoly
j9_ubiquitously(IN jmoVG Vg,
               IN jmsPATH_DATA_PTR PathData,
               IN jmtFLOAT Scale,
               IN jmtFLOAT Bias,
#if J9_COLDS
               IN jmtUINT32 Width,
               IN jmtUINT32 Height,
               IN jmtFLOAT *Bounds,
#endif
               IN jmtBOOL SoftwareTesselation);

j9_duopoly
j9_bloodripeness(IN jmoVG Vg,
                IN j9_schoenobatic orientation,
                IN j9_boist Source,
                IN jmsPOINT_PTR SourceOrigin,
                IN jmsPOINT_PTR TargetOrigin,
                IN jmsSIZE_PTR SourceSize,
                IN jmtINT SourceX,
                IN jmtINT SourceY,
                IN jmtINT TargetX,
                IN jmtINT TargetY,
                IN jmtINT Width,
                IN jmtINT Height,
                IN jmtBOOL Mask,
                IN jmtBOOL isDrawImage);

j9_duopoly
j9_handle__cuckolding(IN jmoVG Vg,
                     IN j9_boist Image,
                     IN jmsVG_RECT_PTR Rectangle,
                     IN j9_lithographies Filter,
                     IN jmtBOOL Mask,
#if J9_COLDS
                     IN jmtBOOL SoftwareTesselation,
                     IN j9_vagrantly BlendMode,
                     IN jmtINT Width,
                     IN jmtINT Height
#else
                     IN jmtBOOL SoftwareTesselation
#endif
);

j9_duopoly
j9_handle_j9ma_balsamroot(IN jmoVG Vg,
                         IN j9_boist Image,
                         IN const jmsVG_RECT_PTR SrcRectangle,
                         IN const jmtFLOAT DstBounds[4],
                         IN const jmtFLOAT DstPoints[8],
                         IN const jmtFLOAT ImgMatrix[9],
                         IN const jmtFLOAT RectMatrix[9],
                         IN j9_lithographies Filter,
                         IN jmtBOOL Mask,
                         IN jmtBOOL FirstTime
#if J9_COLDS
                         ,
                         IN jmtINT TSWidth,
                         IN jmtINT TSHeight
#endif
);

j9_duopoly
j9_handle__attribute_extractive(IN jmoVG Vg,
                               IN j9_boist Image,
                               IN jmsVG_RECT_PTR SrcRect,
                               IN jmtINT X,
                               IN jmtINT Y,
                               IN jmtINT Width,
                               IN jmtINT Height,
                               IN const jmtFLOAT Matrix[9]);

j9_duopoly
j9_eyebeams(IN jmoVG Vg,
           IN j9_boist Source,
           IN j9_boist Target,
           IN jmsVG_RECT_PTR SrcRect,
           IN jmsVG_RECT_PTR TrgRect,
           IN j9_lithographies Filter,
           IN j9_vagrantly Mode);

j9_duopoly
j9maths_crispation(IN jmoVG Vg,
                  IN j9_boist Source,
                  IN j9_boist Target,
                  IN const jmtFLOAT *Matrix,
                  IN j9_forecome ColorChannels,
                  IN jmtBOOL FilterLinear,
                  IN jmtBOOL FilterPremultiplied,
                  IN jmsPOINT_PTR SourceOrigin,
                  IN jmsPOINT_PTR TargetOrigin,
                  IN jmtINT Width,
                  IN jmtINT Height);

j9_duopoly
j9_handle_j9m_beggarhood(IN jmoVG Vg,
                        IN j9_boist Source,
                        IN j9_boist Target,
                        IN jmtINT KernelWidth,
                        IN jmtINT KernelHeight,
                        IN jmtINT ShiftX,
                        IN jmtINT ShiftY,
                        IN const jmtINT16 *KernelX,
                        IN const jmtINT16 *KernelY,
                        IN jmtFLOAT Scale,
                        IN jmtFLOAT Bias,
                        IN j9_hemophagia TilingMode,
                        IN jmtFLOAT_PTR FillColor,
                        IN j9_forecome ColorChannels,
                        IN jmtBOOL FilterLinear,
                        IN jmtBOOL FilterPremultiplied,
                        IN jmsPOINT_PTR SourceOrigin,
                        IN jmsPOINT_PTR TargetOrigin,
                        IN jmsSIZE_PTR SourceSize,
                        IN jmtINT Width,
                        IN jmtINT Height);

j9_duopoly
j9mirror_prestoring(IN jmoVG Vg,
                   IN j9_boist Source,
                   IN j9_boist Target,
                   IN jmtFLOAT StdDeviationX,
                   IN jmtFLOAT StdDeviationY,
                   IN j9_hemophagia TilingMode,
                   IN jmtFLOAT_PTR FillColor,
                   IN j9_forecome ColorChannels,
                   IN jmtBOOL FilterLinear,
                   IN jmtBOOL FilterPremultiplied,
                   IN jmsPOINT_PTR SourceOrigin,
                   IN jmsPOINT_PTR TargetOrigin,
                   IN jmsSIZE_PTR SourceSize,
                   IN jmtINT Width,
                   IN jmtINT Height);

j9_duopoly
j9mirror_beggarhood(IN jmoVG Vg, IN jmtBOOL Enable);


j9_duopoly
j9maths_azobenzene(IN jmoVG Vg,
                  IN jmtUINT32 *Values,
                  IN jmtBOOL *Enables);


j9_duopoly
j9_handle_j9ma_stringiest(IN jmoVG Vg,
                         IN jmtUINT32 *Values,
                         IN jmtINT32 Count);

j9_duopoly
j9_handle_j9m_extendible(IN jmoVG Vg, IN jmtBOOL YUV2RGBStdCust);

j9_duopoly
j9_unweighability(IN jmoVG Vg,
                 IN jmtFLOAT *coef,
                 IN jmtFLOAT *offset,
                 IN jmtBOOL *cfg);

j9_duopoly
j9_handle_j9menu_greenstuff(IN jmoVG Vg,
                           IN jmtFLOAT *coef,
                           IN jmtFLOAT *offset,
                           IN jmtBOOL *cfg);


j9_duopoly
j9_reradiating(IN jmoVG Vg,
              IN j9_boist Source,
              IN j9_boist Target,
              IN jmtINT SX,
              IN jmtINT SY,
              IN jmtINT DX,
              IN jmtINT DY,
              IN jmtINT Width,
              IN jmtINT Height,
              IN jmtINT Src_uv,
              IN jmtINT Src_standard,
              IN jmtINT Dst_uv,
              IN jmtINT Dst_standard,
              IN jmtINT Dst_alpha,
              IN jmtBOOL Dst_standard_cust);
#endif

#ifdef __cplusplus
}
#endif

#endif


