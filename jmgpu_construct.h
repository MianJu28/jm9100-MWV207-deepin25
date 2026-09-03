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



#ifndef __jmgpu_hal_engine_h_
#define __jmgpu_hal_engine_h_

#include "jmgpu_directive.h"
#include "jmgpu_digital.h"

#if J9_DEMISSNESS && J9_COMPATRIOT
#include "jmgpu_solving.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct tag_jms_SURF_RESOLVE_ARGS {
		j9mirror_underrealm version;

    union _jmsSURF_RESOLVE_ARGS_UNION {
			struct tag_jms_SURF_RESOLVE_ARG_v2 {
            jmtBOOL   yInverted;
            jmtBOOL   directCopy;
            jmtBOOL   resample;
            jmtBOOL   bUploadTex;
            jmtBOOL   bSwap;
            jmtBOOL   visualizeDepth;
            j9_selles  srcOrigin;
            j9_selles  dstOrigin;
            j9_selles  rectSize;
            jmtUINT   j9_etymic;
            jmeENGINE engine;
            jmtBOOL   gpuOnly;

            jmtBOOL   dump;
            jmtBOOL   srcSwizzle;
            jmtBOOL   dstSwizzle;
            jmtBOOL   srcCompressed;
            jmtBOOL   dstCompressed;
            jmtUINT   blitToSelf;

            jmtUINT   rotate;
        } v2;
    } uArgs;
} j9_handle__ingeminate;

typedef struct _gscBUFFER_VIEW {
    jmtUINT32 cmd;
} jmsBUFFER_VIEW, *jmsBUFFER_VIEW_PTR;

	typedef struct tag_jms_IMAGE_VIEW {
		jmtUINT32 cmd;
	} j9_uneffectual, *jmsIMAGE_VIEW_PTR;

#if J9_DEMISSNESS

	typedef struct _jmoSTREAM *jmoSTREAM;
	typedef struct _jmoVERTEX *jmoVERTEX;
	typedef struct _jmoTEXTURE *jmoTEXTURE;
	typedef struct _jmoINDEX *jmoINDEX;
	typedef struct tag_jms_VERTEX_ATTRIBUTES *jmsVERTEX_ATTRIBUTES_PTR;
	typedef struct _jmoVERTEXARRAY *jmoVERTEXARRAY;
	typedef struct _jmoBUFOBJ *jmoBUFOBJ;

# define J9MIRROR_BETUCKERED              32
# define J9_HANDLE_J9MIRROR_TIMEWORKER    32

# define J9_HANDLE_ORTHOEPIES             128
# define J9_HANDLE__OVERRENNET            16
# define J9_HANDLE__ACERBATING  \
    ((J9_HANDLE_ORTHOEPIES + J9_HANDLE__OVERRENNET - 1) / J9_HANDLE__OVERRENNET)

# define J9_HANDLE_J9_PROMISSIVE (J9_HANDLE_J9MATHS_BLINKINGLY | \
                                 J9_HANDLE_J9MA_REDUNDANCE    | \
                                 J9_HANDLE_J9MA_CONFICIENT    | \
                                 J9_HANDLE_ATTRIBUTE_HERETICIZE)


j9_duopoly
j9_handle_j9_catchpenny(IN jmoHAL   Hal,
                       OUT jmtUINT *UnifiedUniforms,
                       OUT jmtUINT *VertUniforms,
                       OUT jmtUINT *FragUniforms,
                       OUT jmtUINT *Varyings,
                       OUT jmtUINT *ShaderCoreCount,
                       OUT jmtUINT *j9_shellful,
                       OUT jmtUINT *VertInstructionCount,
                       OUT jmtUINT *FragInstructionCount);

j9_duopoly
j9_handle_j9m_concordity(IN jmoHAL Hal,
                        OUT jmtUINT32 *VertexCount,
                        OUT jmtINT_PTR VertexBase,
                        OUT jmtUINT32 *FragmentCount,
                        OUT jmtINT_PTR FragmentBase);

j9_duopoly
j9_handle_j9m_pansophies(IN jmoHAL Hal, OUT jmtUINT32 *VertexBase,
                        OUT jmtUINT32 *FragmentBase);

j9_duopoly
j9_handle_j9m_fustigated(IN jmoHAL Hal,
                        OUT jmtUINT *MaxWidth,
                        OUT jmtUINT *MaxHeight,
                        OUT jmtUINT *MaxDepth,
                        OUT jmtBOOL *Cubic,
                        OUT jmtBOOL *NonPowerOfTwo,
                        OUT jmtUINT *VertexSamplers,
                        OUT jmtUINT *PixelSamplers);

j9_duopoly
j9_handle_j9maths_mogigraphy(IN jmoHAL Hal, OUT jmtUINT *MaxAnisoValue);

j9_duopoly
j9_handle_j9_polygamist(IN jmoHAL Hal,
                       OUT jmtUINT32 *MaxAttributes,
                       OUT jmtUINT32 *MaxStreamStride,
                       OUT jmtUINT32 *NumberOfStreams,
                       OUT jmtUINT32 *Alignment,
                       OUT jmtUINT32 *MaxAttribOffset);




	typedef struct tag_jms_SURF_BLIT_ARGS {
    j9_boist     srcSurface;
    jmtINT      srcX, srcY, srcZ;
    jmtINT      srcWidth, srcHeight, srcDepth;
    j9_boist     dstSurface;
    jmtINT      dstX, dstY, dstZ;
    jmtINT      dstWidth, dstHeight, dstDepth;
    jmtBOOL     xReverse;
    jmtBOOL     yReverse;
    jmtBOOL     scissorTest;
    j9_yinst     scissor;
    jmtUINT     flags;
    jmtUINT     srcNumSlice, dstNumSlice;
    jmtBOOL     needDecode;
    jmtBOOL     readSwap;
    jmtBOOL     writeSwap;
} j9maths_bilocation;

	typedef struct tag_jms_SURF_CLEAR_ARGS {
    struct {
        jmu_VALUE r;
        jmu_VALUE g;
        jmu_VALUE b;
        jmu_VALUE a;

        j9_melanoblast valueType;
    } color;

    jmu_VALUE depth;
    jmtUINT  stencil;

    jmtUINT8        stencilMask;
    jmtBOOL         depthMask;
    jmtUINT8        colorMask;
    jmsRECT_PTR     clearRect;
    j9_posnet        flags;

    jmtUINT32 offset;

} j9mirror_activistic, *jmsSURF_CLEAR_ARGS_PTR;

typedef struct _gscSURF_BLITDRAW_BLIT {
    j9_boist             srcSurface;
    j9_boist             dstSurface;
    j9_yinst             srcRect;
    j9_yinst             dstRect;
    j9maths_pyrethroid   filterMode;
    jmtBOOL             xReverse;
    jmtBOOL             yReverse;
    jmtBOOL             scissorEnabled;
    j9_yinst             scissor;
} gscSURF_BLITDRAW_BLIT;

typedef j9_duopoly (*jmtSPLIT_DRAW_FUNC_PTR)(IN jmtPOINTER gc,
                                            IN jmtPOINTER instantDraw,
                                            IN jmtPOINTER splitDrawInfo);

	typedef struct tag_jms_SPLIT_DRAW_INFO {
    j9mirror_clinicians     splitDrawType;
    jmtSPLIT_DRAW_FUNC_PTR splitDrawFunc;

    union _jmsSPLIT_DRAW_UNION {

        struct __jmsSPLIT_DRAW_INFO_TCS {
            jmtPOINTER      indexPtr;
            jmtUINT         indexPerPatch;
        } info_tcs;

        struct __jmsSPLIT_DRAW_INFO_INDEX_FETCH {
            jmtSIZE_T       instanceCount;
            jmtSIZE_T       splitCount;
            j9_deaspirate    splitPrimMode;
            jmtSIZE_T       splitPrimCount;
        } info_index_fetch;
    } u;
} j9mirror_eradiation, *jmsSPLIT_DRAW_INFO_PTR;

typedef struct _gscSURF_BLITDRAW_ARGS {

    j9mirror_underrealm version;

    union _jmsSURF_BLITDRAW_ARGS_UNION {
        struct _gscSURF_BLITDRAW_ARG_v1 {

				j9_reintegrations type;

            union _gscSURF_BLITDRAW_UNION {
                gscSURF_BLITDRAW_BLIT blit;

                struct _gscSURF_BLITDRAW_CLEAR {
                    j9mirror_activistic clearArgs;
                    j9_boist            rtSurface;
                    j9_boist            dsSurface;
                } clear;
            } u;
        } v1;
    } uArgs;
} jmsSURF_BLITDRAW_ARGS;

	typedef struct tag_jms_SURF_BLITBLT_ARGS {
		jmtCONST_POINTER buf;
		j9_confirmative format;
		jmtUINT32 stride;
		j9_boist dstSurf;
		j9_selles dstOrigin;
		j9_selles rectSize;
		jmtUINT32 dstOffset;
	} j9_handle__randannite;


j9_duopoly
j9_confessorship(j9maths_bilocation *args);


j9_duopoly
j9mirror_ingeminate(IN j9_preassumed *SrcView,
                   IN j9_preassumed *DstView,
                   IN j9_handle__ingeminate *Args);


j9_duopoly
j9_subuncinate(IN j9_preassumed *SurfView,
              IN jmsSURF_CLEAR_ARGS_PTR ClearArgs);


j9_duopoly
j9_denationalized(IN j9_boist SrcSurf,
                 IN j9_boist DstSurf,
                 IN jmsRECT_PTR MaskRect);


j9_duopoly
depr_jmoSURF_Resolve(IN j9_boist SrcSurface,
                     IN j9_boist DestSurface,
                     IN jmtADDRESS DestAddress,
                     IN jmtPOINTER DestBits,
                     IN jmtINT DestStride,
                     IN j9_lifelessly DestType,
                     IN j9_confirmative DestFormat,
                     IN jmtUINT DestWidth,
                     IN jmtUINT DestHeight);

j9_duopoly
depr_jmoSURF_ResolveRect(IN j9_boist SrcSurface,
                         IN j9_boist DstSurface,
                         IN jmtADDRESS DstAddress,
                         IN jmtPOINTER DstBits,
                         IN jmtINT DstStride,
                         IN j9_lifelessly DstType,
                         IN j9_confirmative DstFormat,
                         IN jmtUINT DstWidth,
                         IN jmtUINT DstHeight,
                         IN jmsPOINT_PTR SrcOrigin,
                         IN jmsPOINT_PTR j9_boist,
                         IN jmsPOINT_PTR RectSize);


	 j9_duopoly
		j9_unsignificancy(IN j9_boist SrcSurf,
				  IN j9_boist DstSurf, IN jmtBOOL sRGBDecode);


	 j9_duopoly j9_handle_j9_beggarhood(IN j9_preassumed * View);


	 j9_duopoly
		jmo_SURF_SetCacheOperation(IN j9_preassumed * SurfView,
					   IN j9maths_eventuated cacheOperation);

	 j9_duopoly
		jmo_SURF_GetCacheOperation(IN j9_preassumed * SurfView,
					   IN j9maths_eventuated * cacheOperation);


j9_duopoly
j9_handle_spancelled(IN j9_preassumed *SrcView,
                    IN j9_preassumed *DstView,
                    IN j9_handle__ingeminate *Args);

j9_duopoly
j9_handle_j9maths_outwriggle(IN j9_boist Surface,
                            OUT jmtUINT *originX,
                            OUT jmtUINT *originY,
                            OUT jmtUINT *sizeX,
                            OUT jmtUINT *sizeY);

j9_duopoly
j9_handle_j9m_stringiest(IN j9_boist SrcSurf,
                        IN j9_boist DstSurf,
                        IN jmsPOINT_PTR SrcOrigin,
                        IN jmsPOINT_PTR DstOrigin,
                        IN jmsPOINT_PTR RectSize);


j9_duopoly
j9_handle_j9ma_fustigated(IN j9_boist Surface, IN jmtBOOL Resolvable);

j9_duopoly
j9_handle__hereticize(IN j9_boist Surface);

j9_duopoly
j9_handle__attribute_ctenoidian(IN j9_boist Surface);

j9_duopoly
j9_handle_j9menu_cryohydric(IN jmoHAL Hal, IN jmtUINT TargetIndex, IN jmoBUFOBJ BufObj);

j9_duopoly
j9mirror_streamlets(IN jmoBUFOBJ BufObj, IN jmeFENCE_TYPE Type);

j9_duopoly
j9_handle_copresence(IN jmoBUFOBJ BufObj, IN jmeFENCE_TYPE Type);

j9_duopoly
j9_handle_j9ma_acecaffine(IN jmoBUFOBJ BufObj);

j9_duopoly
j9_prothonotaries(IN j9_boist Surface, IN jmeFENCE_TYPE Type);

j9_duopoly
j9maths_medicating(IN j9_boist Surface);

j9_duopoly
j9mirror_randannite(IN jmoSTREAM stream);

j9_duopoly
j9_handle_fustigated(IN jmoSTREAM stream);

j9_duopoly
j9maths_tunnellers(IN jmoINDEX Index);

j9_duopoly
j9mirror_hereticize(IN jmoINDEX Index, IN jmeFENCE_TYPE Type);

j9_duopoly
j9_overfurnishing(j9_preassumed *SrcView,
                 j9_preassumed *DstView,
                 gscSURF_BLITDRAW_BLIT *Args);

j9_duopoly
j9_handle_j_mogigraphy(j9_preassumed *SrcView,
                      j9_preassumed *DstView,
                      gscSURF_BLITDRAW_BLIT *Args);

j9_duopoly
jmo_SURF_ComputeBlit(j9_preassumed *SrcView,
                    j9_preassumed *DstView,
                    gscSURF_BLITDRAW_BLIT *Args);



j9_duopoly
j9mirror_animalness(IN jmoHAL Hal, OUT jmoINDEX *Index);


j9_duopoly
j9_oversolemnness(IN jmoINDEX Index);


j9_duopoly
j9_incaptivate(IN jmoINDEX Index,
              OUT jmtADDRESS *Address,
              OUT jmtPOINTER *Memory);


j9_duopoly
j9_countertrends(IN jmoINDEX Index);


j9_duopoly
j9_hippodromes(IN jmoINDEX Index,
              IN j9_reappraised IndexType,
              IN jmtUINT32 IndexCount,
              IN jmtPOINTER IndexBuffer);


j9_duopoly
j9_byssiferous(IN jmoINDEX Index, IN j9_reappraised Type);


j9_duopoly
j9_handle_accumbency(IN jmoINDEX Index,
                    IN j9_reappraised Type,
                    IN jmtSIZE_T Offset);


j9_duopoly
j9_haematocyst(IN jmoINDEX Index);


j9_duopoly
j9_telencephalic(IN jmoINDEX Index,
                IN jmtCONST_POINTER Buffer,
                IN jmtSIZE_T Bytes);


j9_duopoly
j9_handle_j_bilocation(IN jmoINDEX Index,
                      IN jmtSIZE_T Offset,
                      IN jmtCONST_POINTER Buffer,
                      IN jmtSIZE_T Bytes);


j9_duopoly
j9_divaricating(IN jmoINDEX Index1, IN jmoINDEX Index2);


jmtBOOL
j9_handle_cabalassou(IN jmoINDEX Index,
                    IN j9_reappraised Type,
                    IN jmtINT Count,
                    IN jmtUINT32 Indices);


j9_duopoly
j9mirror_reunionism(OUT jmtBOOL *Index8,
                   OUT jmtBOOL *Index16,
                   OUT jmtBOOL *Index32,
                   OUT jmtUINT *MaxIndex);


j9_duopoly
j9_handle_j9_concordity(IN jmoINDEX Index,
                       IN j9_reappraised Type,
                       IN jmtSIZE_T Offset,
                       IN jmtUINT32 Count,
                       OUT jmtUINT32 *MinimumIndex,
                       OUT jmtUINT32 *MaximumIndex);


j9_duopoly
j9_handle_indentwise(IN jmoINDEX Index,
                    IN jmtSIZE_T Bytes,
                    IN jmtUINT Buffers);

j9_duopoly
j9_handle_j9m_medicating(void);


	 j9_duopoly
		j9_alternatingly(IN jmoHAL Hal,
				 IN jmtBOOL Robust, OUT jmo3D * Engine);


	 j9_duopoly j9_quantimeter(IN jmo3D Engine);


	 j9_duopoly j9_oblateness(IN jmo3D Engine, IN j9_mzee ApiType);


	 j9_duopoly j9_automatist(IN jmo3D Engine, OUT j9_mzee * ApiType);

	 j9_duopoly
		j9_deceivability(IN jmo3D Engine,
				 IN jmtUINT32 TargetIndex,
				 IN j9_preassumed *SurfView,
				 IN jmtUINT32 LayerIndex);

	 j9_duopoly
		j9maths_blinkingly(IN jmo3D Engine,
				   IN jmtUINT32 TargetIndex, IN j9_boist Surface);

	 j9_duopoly
		j9_handle_j9ma_handyfight(IN jmo3D Engine,
					  IN jmtINT32 * psOutputMapping);

	 j9_duopoly
		j9_handle_j9_deedholder(IN jmo3D Engine,
					IN jmtBOOL Enable, IN jmtUINT MaxLayers);

	 j9_duopoly j9_handle_j9_equipoised(IN jmo3D Engine, IN jmtBOOL Enable);

	 j9_duopoly j9_handle_j9m_reunionism(IN jmo3D Engine);


	 j9_duopoly
		j9_fractionated(IN jmo3D Engine, IN j9_preassumed *SurfView);


	 j9_duopoly j9_prophecymonger(IN jmo3D Engine, IN j9_boist Surface);


	 j9_duopoly
		j9maths_russifying(IN jmo3D Engine,
				   IN jmtINT32 Left,
				   IN jmtINT32 Top,
				   IN jmtINT32 Right, IN jmtINT32 Bottom);


	 j9_duopoly
		j9maths_nonspatial(IN jmo3D Engine,
				   IN jmtINT32 Left,
				   IN jmtINT32 Top,
				   IN jmtINT32 Right, IN jmtINT32 Bottom);


	 j9_duopoly
		j9_handle_returnable(IN jmo3D Engine,
				 IN jmtUINT8 Red,
				 IN jmtUINT8 Green,
				 IN jmtUINT8 Blue, IN jmtUINT8 Alpha);


	 j9_duopoly
		j9_handle__russifying(IN jmo3D Engine,
				  IN jmtFIXED_POINT Red,
				  IN jmtFIXED_POINT Green,
				  IN jmtFIXED_POINT Blue,
				  IN jmtFIXED_POINT Alpha);


	 j9_duopoly
		j9_handle__nonspatial(IN jmo3D Engine,
				  IN jmtFLOAT Red,
				  IN jmtFLOAT Green,
				  IN jmtFLOAT Blue, IN jmtFLOAT Alpha);


	 j9_duopoly
		j9_handle__lionizable(IN jmo3D Engine, IN jmtFIXED_POINT Depth);


	 j9_duopoly j9_handle__blinkingly(IN jmo3D Engine, IN jmtFLOAT Depth);


	 j9_duopoly
		j9_handle_j_probations(IN jmo3D Engine, IN jmtUINT32 Stencil);


	 j9_duopoly j9_transferential(IN jmo3D Engine, IN j9_mopstick Shading);


	 j9_duopoly j9_handle__principium(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly
		j9_handle_j9_tophetical(IN jmo3D Engine,
					IN j9_enzymolysis Unit,
					IN j9maths_overflowed FunctionRGB,
					IN j9maths_overflowed FunctionAlpha);


	 j9_duopoly
		j9mirror_schemozzle(IN jmo3D Engine,
				IN j9_cantaloupes ModeRGB,
				IN j9_cantaloupes ModeAlpha);


	 j9_duopoly
		j9_handle_j9maths_beggarhood(IN jmo3D Engine,
					 IN jmtUINT Index, IN jmtBOOL Enable);


	 j9_duopoly
		j9_handle_attribute_ctenoidian(IN jmo3D Engine,
					   IN jmtUINT Index,
					   IN j9_enzymolysis Unit,
					   IN j9maths_overflowed FunctionRGB,
					   IN j9maths_overflowed FunctionAlpha);


	 j9_duopoly
		j9_handle_j9min_gyniatrics(IN jmo3D Engine,
					   IN jmtUINT Index,
					   IN j9_cantaloupes ModeRGB,
					   IN j9_cantaloupes ModeAlpha);


	 j9_duopoly
		j9_handle_incommixed(IN jmo3D Engine,
				 IN jmtUINT Red,
				 IN jmtUINT Green,
				 IN jmtUINT Blue, IN jmtUINT Alpha);


	 j9_duopoly
		j9_handle__smellproof(IN jmo3D Engine,
				  IN jmtFIXED_POINT Red,
				  IN jmtFIXED_POINT Green,
				  IN jmtFIXED_POINT Blue,
				  IN jmtFIXED_POINT Alpha);


	 j9_duopoly
		j9_handle__politicise(IN jmo3D Engine,
				  IN jmtFLOAT Red,
				  IN jmtFLOAT Green,
				  IN jmtFLOAT Blue, IN jmtFLOAT Alpha);


	 j9_duopoly j9_rehospitalizes(IN jmo3D Engine, IN j9_clast Mode);


	 j9_duopoly
		j9_handle_j9ma_tophetical(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly jmo_3D_SetFixPointSize(IN jmo3D Engine, IN jmtFLOAT ptSize);


	 j9_duopoly j9_handle__muriculate(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly
		j9_handle_j9menu_stringiest(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly j9_buttonholer(IN jmo3D Engine, IN j9_arrha Mode);


	 j9_duopoly
		j9_handle_j_medicating(IN jmo3D Engine, IN j9_slabness Compare);


	 j9_duopoly j9_handle_j9_paramedics(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly
		j9mirror_penthouses(IN jmo3D Engine, IN j9_petitionary Mode);


	 j9_duopoly
		j9_handle__arecaceous(IN jmo3D Engine,
				  IN j9_petitionary Mode,
				  IN jmtFIXED_POINT Near,
				  IN jmtFIXED_POINT Far);


	 j9_duopoly
		j9_handle__desolately(IN jmo3D Engine,
				  IN j9_petitionary Mode,
				  IN jmtFLOAT Near, IN jmtFLOAT Far);


	 j9_duopoly
		j9_handle_j9ma_outweighed(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly
		j9_handle_j9ma_indentwise(IN jmo3D Engine,
					  IN jmtFIXED_POINT DepthScale,
					  IN jmtFIXED_POINT DepthBias);

	 j9_duopoly
		j9_handle_j9ma_cabalassou(IN jmo3D Engine,
					  IN jmtFLOAT DepthScale,
					  IN jmtFLOAT DepthBias);


	 j9_duopoly
		j9_handle__overroasts(IN jmo3D Engine,
				  IN jmtFLOAT Near, IN jmtFLOAT Far);


	 j9_duopoly j9mirror_bisections(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly j9_handle_adposition(IN jmo3D Engine, IN jmtUINT8 Enable);


	 j9_duopoly
		j9_handle_j9menu_outpursued(IN jmo3D Engine,
					IN jmtUINT Index, IN jmtUINT8 Enable);


	 j9_duopoly j9_handle_rejoicings(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly
		j9_handle_j9maths_plasmodial(IN jmo3D Engine, IN jmtBOOL Disable);

	 j9_duopoly
		j9_handle_j9menu_balsamroot(IN jmo3D Engine,
					IN jmtBOOL EarlyDepthFromAPP);

	 j9_duopoly
		j9_handle_j_catchpenny(IN jmo3D Engine,
				   IN jmtBOOL Disable,
				   IN jmtBOOL psReadZ, IN jmtBOOL psReadW);

	 j9_duopoly
		j9_handle_j9_preinsured(IN jmo3D Engine, IN jmtINT PatchVertices);


	 j9_duopoly j9_handle_j9m_attribute_postludium(IN jmo3D Engine);


	 j9_duopoly
		j9_handle_j9ma_attribute_palmettoes(IN jmo3D Engine,
						IN jmtBOOL Disable);


	 j9_duopoly j9mirror_polytenies(IN jmo3D Engine, IN jmtBOOL Enable);

	typedef struct tag_jms_STENCIL_INFO *jmsSTENCIL_INFO_PTR;
	typedef struct tag_jms_STENCIL_INFO {
		j9_abstractively mode;

		jmtUINT8 maskFront;
		jmtUINT8 maskBack;
		jmtUINT8 writeMaskFront;
		jmtUINT8 writeMaskBack;

		jmtUINT8 referenceFront;

		j9_slabness compareFront;
		j9_handle__scapulette passFront;
		j9_handle__scapulette failFront;
		j9_handle__scapulette depthFailFront;

		jmtUINT8 referenceBack;
		j9_slabness compareBack;
		j9_handle__scapulette passBack;
		j9_handle__scapulette failBack;
		j9_handle__scapulette depthFailBack;
	} j9_preconvincing;


	 j9_duopoly
		j9_handle__incommixed(IN jmo3D Engine, IN j9_abstractively Mode);


	 j9_duopoly j9_handle__oesophagal(IN jmo3D Engine, IN jmtUINT8 Mask);


	 j9_duopoly
		j9_handle_j9ma_preinsured(IN jmo3D Engine, IN jmtUINT8 Mask);


	 j9_duopoly
		j9_handle_j9min_probations(IN jmo3D Engine, IN jmtUINT8 Mask);


	 j9_duopoly
		j9_handle_attribute_coruscated(IN jmo3D Engine, IN jmtUINT8 Mask);


	 j9_duopoly
		j9_handle_j9min_muscologic(IN jmo3D Engine,
					   IN jmtUINT8 Reference, IN jmtBOOL Front);


	 j9_duopoly
		j9_handle_j9m_muscologic(IN jmo3D Engine,
					 IN j9_thundershowers Where,
					 IN j9_slabness Compare);


	 j9_duopoly
		j9_handle__returnable(IN jmo3D Engine,
				  IN j9_thundershowers Where,
				  IN j9_handle__scapulette Operation);


	 j9_duopoly
		j9_handle__steeliness(IN jmo3D Engine,
				  IN j9_thundershowers Where,
				  IN j9_handle__scapulette Operation);


	 j9_duopoly
		j9_handle_j9min_unequalize(IN jmo3D Engine,
					   IN j9_thundershowers Where,
					   IN j9_handle__scapulette Operation);


	 j9_duopoly
		j9_handle_splotching(IN jmo3D Engine, IN jmsSTENCIL_INFO_PTR Info);

	typedef struct tag_jms_ALPHA_INFO *jmsALPHA_INFO_PTR;
	typedef struct tag_jms_ALPHA_INFO {

		jmtBOOL test;
		j9_slabness compare;
		jmtUINT8 reference;
		jmtFLOAT floatReference;


		jmtBOOL blend[J9_HANDLE_ANCHORITIC];

		j9maths_overflowed srcFuncColor[J9_HANDLE_ANCHORITIC];
		j9maths_overflowed srcFuncAlpha[J9_HANDLE_ANCHORITIC];
		j9maths_overflowed trgFuncColor[J9_HANDLE_ANCHORITIC];
		j9maths_overflowed trgFuncAlpha[J9_HANDLE_ANCHORITIC];

		j9_cantaloupes modeColor[J9_HANDLE_ANCHORITIC];
		j9_cantaloupes modeAlpha[J9_HANDLE_ANCHORITIC];

		jmtUINT32 color;

		jmtBOOL anyBlendEnabled;
	} j9_saltatorily;


	 j9_duopoly j9mirror_ownerships(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly
		j9_handle_j_muscologic(IN jmo3D Engine, IN j9_slabness Compare);


	 j9_duopoly
		j9_handle_j9m_hereticize(IN jmo3D Engine,
					 IN jmtUINT8 Reference,
					 IN jmtFLOAT FloatReference);


	 j9_duopoly
		j9_handle_j9ma_accumbency(IN jmo3D Engine,
					  IN jmtFIXED_POINT Reference);


	 j9_duopoly
		j9_handle_j9ma_paramedics(IN jmo3D Engine, IN jmtFLOAT Reference);

#if J9_HANDLE_J9M_HOMOGONIES
	 j9_duopoly
		j9mirror_splotching(IN jmo3D Engine,
				IN jmtBOOL AlphaKill, IN jmtBOOL ColorKill);
#endif


	 j9_duopoly j9_handle_j9_outweighed(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly
		j9_handle_j9_indentwise(IN jmo3D Engine, IN jmtUINT TexSlot);


	 j9_duopoly j9_handle__phytometry(IN jmo3D Engine, IN jmtFLOAT Width);


	 j9_duopoly
		j9_handle__femininely(IN jmo3D Engine,
				  IN j9_deaspirate Type,
				  IN jmtSIZE_T StartVertex,
				  IN jmtSIZE_T PrimitiveCount);

	 j9_duopoly
		j9_handle_j9mirror_ctenoidian(IN jmo3D Engine,
					  IN j9_deaspirate Type,
					  IN jmtBOOL DrawIndex,
					  IN jmtINT BaseOffset,
					  IN jmoBUFOBJ BufObj);

	 j9_duopoly
		j9_handle_j9m_attribute_besmutting(IN jmo3D Engine,
						   IN j9_deaspirate Type,
						   IN jmtBOOL DrawIndex,
						   IN jmtINT BaseOffset,
						   IN jmtINT DrawCount,
						   IN jmtINT Stride,
						   IN jmoBUFOBJ BufObj);

	 j9_duopoly
		j9_handle_attribute_supercivil(IN jmo3D Engine,
					   IN j9_deaspirate Type,
					   IN jmtBOOL DrawIndex,
					   IN jmtINT StartVertex,
					   IN jmtSIZE_T StartIndex,
					   IN jmtSIZE_T PrimitiveCount,
					   IN jmtSIZE_T VertexCount,
					   IN jmtSIZE_T InstanceCount);

	 j9_duopoly j9_handle_j9ma_advertency(IN jmo3D Engine);

	 j9_duopoly
		j9_handle_j9min_reunionism(IN jmo3D Engine,
					   IN j9_deaspirate Type,
					   IN jmtINT *StartVertex,
					   IN jmtSIZE_T *VertexCount,
					   IN jmtSIZE_T PrimitiveCount);


	 j9_duopoly
		j9_handle_j9menu_randannite(IN jmo3D Engine,
					IN j9_deaspirate Type,
					IN jmtINT32 StartOffset,
					IN jmtSIZE_T PrimitiveCount);


	 j9_duopoly
		j9_handle_j9maths_cyaphenine(IN jmo3D Engine,
					 IN j9_deaspirate Type,
					 IN jmtSIZE_T BaseVertex,
					 IN jmtSIZE_T StartIndex,
					 IN jmtSIZE_T PrimitiveCount);


	 j9_duopoly
		j9_handle_j9m_attribute_parapsidal(IN jmo3D Engine,
						   IN j9_deaspirate Type,
						   IN jmtINT32 BaseOffset,
						   IN jmtINT32 StartOffset,
						   IN jmtSIZE_T PrimitiveCount);


	 j9_duopoly
		j9maths_smoothback(IN jmo3D Engine,
				   IN jmsFAST_FLUSH_PTR FastFlushInfo);


	 j9_duopoly j9mirror_tunnellers(IN jmo3D Engine, IN jmtBOOL Enable);


	 j9_duopoly j9_semidivisively(IN jmo3D Engine, IN jmtUINT32 Samples);


	 j9_duopoly
		j9maths_lionizable(IN jmo3D Engine,
				   IN jmtCONST_POINTER Data,
				   IN jmtSIZE_T Bytes, IN jmtBOOL Aligned);


	 j9_duopoly
		j9_mastigophobia(IN jmo3D Engine,
				 IN j9_unbarb From,
				 IN j9_unbarb To, IN j9_ast_ How);


	 j9_duopoly j9_subconsulship(IN jmo3D Engine);


	 j9_duopoly j9_handle__reclimbing(IN jmo3D Engine);


	 j9_duopoly
		j9mirror_copresence(IN jmo3D Engine,
				IN jmtUINT32 Index, IN jmtPOINTER Centroids);


	 j9_duopoly
		j9_handle_j_unequalize(IN jmo3D Engine,
				   IN jmtUINT32 SampleIndex,
				   IN jmtBOOL yInverted,
				   OUT jmtFLOAT_PTR Coords);

	 j9_duopoly j9_disquietedness(IN jmo3D Engine, IN jmtUINT8 Rop);

	 j9_duopoly
		j9_invertebrate(IN jmo3D Engine,
				IN jmtUINT32 QueryHeader,
				IN j9_impetulant Type,
				IN jmtBOOL Enable, IN jmtUINT32 Index);

	 j9_duopoly
		j9_hyperostosis(IN jmo3D Engine,
				IN j9_impetulant Type,
				IN j9_mesosternebral Node,
				IN jmtUINT32 Size,
				IN jmtPOINTER Locked,
				IN jmtUINT32 IndexedId, OUT jmtINT32 * Index);

	 j9_duopoly j9mirror_advertency(IN jmo3D Engine, IN jmtUINT32 Physical);

	 j9_duopoly
		j9mirror_littermate(IN jmo3D Engine,
				IN jmtUINT32 Index,
				IN jmtUINT32 BufferAddr,
				IN jmtUINT32 BufferStride,
				IN jmtUINT32 j9_riflers);

	 j9_duopoly j9_pretranscribe(IN jmo3D Engine, IN j9_squares Cmd);

	 j9_duopoly j9_handle_j9_acecaffine(IN jmo3D Engine, IN jmtBOOL Enable);

	 j9_duopoly
		j9_handle_j9_handyfight(IN jmo3D Engine,
					IN jmtUINT32 ColorOutCount);

	 j9_duopoly j9_handle_j9m_marijuanas(IN jmo3D Engine);

	 j9_duopoly j9maths_smellproof(IN jmo3D Engine);

	 j9_duopoly j9_handle_ownerships(IN jmo3D Engine);

	 j9_duopoly j9maths_phytometry(OUT jmo3D * Engine);

	 j9_duopoly
		j9_transcendently(IN jmo3D Engine, OUT jmtBOOL_PTR Innocent);

j9_duopoly
jmo_3D_SetBlitCPUPatchFuncPtr(
    IN jmo3D Engine,
    IN jmtPOINTER funcPtr
    );


	typedef struct tag_jms_THREAD_WALKER_INFO *jmsTHREAD_WALKER_INFO_PTR;
	typedef struct tag_jms_THREAD_WALKER_INFO {
    jmtUINT32   dimensions;
    jmtUINT32   traverseOrder;
    jmtUINT32   enableSwathX;
    jmtUINT32   enableSwathY;
    jmtUINT32   enableSwathZ;
    jmtUINT32   swathSizeX;
    jmtUINT32   swathSizeY;
    jmtUINT32   swathSizeZ;
    jmtUINT32   valueOrder;

    jmtUINT32   globalSizeX;
    jmtUINT32   globalOffsetX;
    jmtUINT32   globalSizeY;
    jmtUINT32   globalOffsetY;
    jmtUINT32   globalSizeZ;
    jmtUINT32   globalOffsetZ;

    jmtUINT32   globalScaleX;
    jmtUINT32   globalScaleY;
    jmtUINT32   globalScaleZ;

    jmtUINT32   workGroupSizeX;
    jmtUINT32   workGroupCountX;
    jmtUINT32   workGroupSizeY;
    jmtUINT32   workGroupCountY;
    jmtUINT32   workGroupSizeZ;
    jmtUINT32   workGroupCountZ;

    jmtUINT32   threadAllocation;
    jmtBOOL     barrierUsed;
    jmtUINT32   memoryAccessFlag;
    jmtBOOL     indirect;
    jmtUINT32   groupNumberUniformIdx;
    jmtADDRESS  baseAddress;
    jmtBOOL     bDual16;
    jmtBOOL     bVipSram;
} j9_handle_j_northlight;

#if J9_DEMISSNESS && J9_NAOLOGY

	typedef struct tag_jms_VX_THREAD_WALKER_PARAMETERS
		*jmsVX_THREAD_WALKER_PARAMETERS_PTR;

	typedef struct tag_jms_VX_THREAD_WALKER_PARAMETERS {
    jmtUINT32   valueOrder;
    jmtUINT32   workDim;

    jmtUINT32   workGroupSizeX;
    jmtUINT32   workGroupCountX;

    jmtUINT32   workGroupSizeY;
    jmtUINT32   workGroupCountY;

    jmtUINT32   globalOffsetX;
    jmtUINT32   globalScaleX;

    jmtUINT32   globalOffsetY;
    jmtUINT32   globalScaleY;

#  if J9_RECOUNTENANCE > 1
    jmtBOOL tileMode;
#  endif
} j9_handle__attribute_jointuress;

	typedef struct tag_jms_VX_IMAGE_INFO *jmsVX_IMAGE_INFO_PTR;

	typedef struct tag_jms_VX_IMAGE_INFO {
    jmtUINT32       format;
    jmtUINT32       rect[4];
    jmtSIZE_T       width;
    jmtSIZE_T       height;


    jmtSIZE_T       arraySize;
    jmtUINT64       sliceSize;

    jmtUINT32       bpp;
    jmtUINT32       planes;
    jmtUINT32       componentCount;
    jmtBOOL         isFloat;

    jmtUINT32       uPixels;
    jmtUINT32       vPixels;
    j9_confirmative  internalFormat;
    jmtUINT32       border;


	jmtUINT32 imagepatch[8 * 3];
    void            *base_addr[3];

    jmtUINT64       stride[3];

    jmtPOINTER      logicals[3];
    jmtADDRESS      physicals[3];
    jmtUINT32       bytes;

    j9_mesosternebral nodes[3];

    jmtBOOL         isVXC;
#  if J9_RECOUNTENANCE
    jmtUINT32       uniformData[3][4];
#  endif

    jmtUINT32       uniformSaveDataType;
} j9_unaffrightedly;
	typedef struct tag_jms_VX_DISTRIBUTION_INFO
		*jmsVX_DISTRIBUTION_INFO_PTR;

	typedef struct tag_jms_VX_DISTRIBUTION_INFO {
    jmtUINT32       logical;
    jmtADDRESS      physical;
    jmtUINT32       bytes;

	j9_mesosternebral node;
} j9_handle_j9m_tetrameter;
# endif


	 j9_duopoly
		j9_handle_j9ma_streamlets(IN jmo3D Engine,
					  IN jmsTHREAD_WALKER_INFO_PTR Info);

	 j9_duopoly
		j9_handle_j9mirror_adhesively(IN jmo3D Engine,
					  IN j9_confirmative InFormat,
					  OUT j9_confirmative *OutFormat);


	 j9_duopoly j9_handle__adposition(IN jmo3D Engine, IN jmtBOOL Enable);

	 j9_duopoly
		j9_handle__smoothback(IN jmo3D Engine, OUT jmtBOOL *Enable);

	 j9_duopoly j9_handle_j_polygamist(IN jmo3D Engine, IN jmtFLOAT Value);

	 j9_duopoly
		j9_handle_j_crispation(IN jmo3D Engine, IN jmtFIXED_POINT Value);

	 j9_duopoly j9_handle__rejoicings(IN jmo3D Engine, IN jmtFLOAT Value);

	 j9_duopoly
		j9_handle_j9_cabalassou(IN jmo3D Engine,
					IN jmtBOOL PrimitiveRestart);

	 j9_duopoly
		j9maths_politicise(IN jmo3D Engine,
				   IN j9_handle__archivault StageBits,
				   IN jmtPOINTER ProgramState);

	 j9_duopoly
		j9_handle_j9maths_disuniform(IN jmo3D Engine, IN jmtBOOL Enable);

	 j9_duopoly
		j9_handle_j9menu_ingeminate(IN jmo3D Engine, IN jmtBOOL Enable);

	 j9_duopoly
		j9_handle_j9mirror_coruscated(IN jmo3D Engine,
					  IN jmtFLOAT CoverageValue,
					  IN jmtBOOL Invert);

	 j9_duopoly j9_handle_j9_accumbency(IN jmo3D Engine, IN jmtBOOL Enable);

	 j9_duopoly
		j9_handle_bisections(IN jmo3D Engine, IN jmtUINT32 SampleMask);

	 j9_duopoly
		j9_handle_j9min_marijuanas(IN jmo3D Engine, IN jmtBOOL Enable);

	 j9_duopoly
		j9_handle__attribute_hydriatric(IN jmo3D Engine,
						IN jmtFLOAT MinSampleShadingValue);

	 j9_duopoly
		j9_handle_j9_dowagerism(IN jmo3D Engine,
					IN jmtBOOL Enable,
					IN jmtBOOL IsSampleIn,
					IN jmtFLOAT SampleShadingValue);

	 j9_duopoly
		j9_handle_j9min_hereticize(IN jmo3D Engine,
					   IN jmtBOOL Enable,
					   IN jmtINT SampleMaskLoc);





	 j9_duopoly
		j9_handle__attribute_lamenesses(IN jmo3D Engine,
						IN jmtBOOL ColorFromStream,
						IN jmtBOOL EnableFog,
						IN jmtBOOL EnableSmoothPoint,
						IN jmtUINT32 ClipPlanes);


	 j9_duopoly
		j9_handle_j9ma_polygamian(IN jmo3D Engine,
					  IN jmtINT Stage, IN jmtBOOL Enable);


	 j9_duopoly
		j9_handle_j9min_catchpenny(IN jmo3D Engine,
					   IN jmtINT Stage,
					   IN jmtBOOL ColorEnabled,
					   IN jmtBOOL AlphaEnabled);


	 j9_duopoly
		j9_handle_j9min_medicating(IN jmo3D Engine,
					   IN jmtINT Stage,
					   IN jmtBOOL ColorEnabled,
					   IN jmtBOOL AlphaEnabled);


	 j9_duopoly
		j9_handle_j9m_unequalize(IN jmo3D Engine,
					 IN jmtFIXED_POINT Red,
					 IN jmtFIXED_POINT Green,
					 IN jmtFIXED_POINT Blue,
					 IN jmtFIXED_POINT Alpha);

	 j9_duopoly
		j9_handle_j9m_gyniatrics(IN jmo3D Engine,
					 IN jmtFLOAT Red,
					 IN jmtFLOAT Green,
					 IN jmtFLOAT Blue, IN jmtFLOAT Alpha);


	 j9_duopoly
		j9mirror_maskalonge(IN jmo3D Engine,
				IN jmtFIXED_POINT Red,
				IN jmtFIXED_POINT Green,
				IN jmtFIXED_POINT Blue,
				IN jmtFIXED_POINT Alpha);

	 j9_duopoly
		j9mirror_subcoastal(IN jmo3D Engine,
				IN jmtFLOAT Red,
				IN jmtFLOAT Green,
				IN jmtFLOAT Blue, IN jmtFLOAT Alpha);


	 j9_duopoly
		j9_handle_j9_reunionism(IN jmo3D Engine,
					IN jmtINT Stage,
					IN jmtFIXED_POINT Red,
					IN jmtFIXED_POINT Green,
					IN jmtFIXED_POINT Blue,
					IN jmtFIXED_POINT Alpha);

	 j9_duopoly
		j9_handle_j9_animalness(IN jmo3D Engine,
					IN jmtINT Stage,
					IN jmtFLOAT Red,
					IN jmtFLOAT Green,
					IN jmtFLOAT Blue, IN jmtFLOAT Alpha);


	 j9_duopoly
		j9_handle_attribute_adhesively(IN jmo3D Engine,
					   IN jmtINT Stage,
					   IN j9_handle_amidstream Function,
					   IN j9maths_boardwalks Source0,
					   IN j9mirror_amidstream Channel0,
					   IN j9maths_boardwalks Source1,
					   IN j9mirror_amidstream Channel1,
					   IN j9maths_boardwalks Source2,
					   IN j9mirror_amidstream Channel2,
					   IN jmtINT Scale);


	 j9_duopoly
		j9_handle_attribute_greenstuff(IN jmo3D Engine,
					   IN jmtINT Stage,
					   IN j9_handle_amidstream Function,
					   IN j9maths_boardwalks Source0,
					   IN j9mirror_amidstream Channel0,
					   IN j9maths_boardwalks Source1,
					   IN j9mirror_amidstream Channel1,
					   IN j9maths_boardwalks Source2,
					   IN j9mirror_amidstream Channel2,
					   IN jmtINT Scale);


	typedef struct tag_jms_TEXTURE {

    j9_handle_j_incommixed       s;
    j9_handle_j_incommixed       t;
    j9_handle_j_incommixed       r;

    j9mirror_backvelder          swizzle[J9_HANDLE_J9MA_OVERRENNET];


    jmtUINT8                    border[J9_HANDLE_J9MA_OVERRENNET];


    j9maths_pyrethroid           minFilter;
    j9maths_pyrethroid           magFilter;
    j9maths_pyrethroid           mipFilter;
    jmtUINT                     anisoFilter;


    jmtFLOAT                    lodBias;
    jmtFLOAT                    lodMin;
    jmtFLOAT                    lodMax;


    jmtINT32                    baseLevel;
    jmtINT32                    maxLevel;


    j9_handle_j9m_unartistic     compareMode;
    j9_slabness                  compareFunc;

    j9_handle_j9_superstate      dsTextureMode;

    j9mirror_teniasises          dsMode;


    j9_handle_j_cloacaline       sRGB;

    jmu_VALUE                    borderColor[4];
    jmtBOOL                     descDirty;


    jmtINT                      stage;
} j9_apprizer, *jmsTEXTURE_PTR;

	typedef struct tag_jms_TEXTURE_BINDTEXTS_ARGS {

    j9mirror_underrealm          version;

} j9_handle_j9min_outwriggle;


j9_duopoly
j9_handle__muscologic(IN jmoHAL Hal, OUT jmoTEXTURE *Texture);


j9_duopoly
j9_handle_j9_anchylosed(IN jmoHAL Hal, IN j9_prequarantine Type, OUT jmoTEXTURE *Texture);


j9_duopoly
j9_handle_j9min_smifligate(IN jmoHAL Hal,
                          IN j9_confirmative Format,
                          IN j9_bytalks Tiling,
                          IN jmtUINT Width,
                          IN jmtUINT Height,
                          IN jmtUINT Depth,
                          IN jmtUINT Faces,
                          IN jmtUINT MipMapCount,
                          IN j9_phpht Pool,
                          OUT jmoTEXTURE *Texture);


j9_duopoly
j9mirror_tangerines(IN jmoTEXTURE Texture);


j9_duopoly
j9_handle_j9_attribute_unequalize(
    IN j9_confirmative srcFormat,
    IN j9_confirmative dstFormat
);


j9_duopoly
j9maths_catchpenny(IN jmoTEXTURE Texture,
                  IN jmtINT MipMap,
                  IN j9_antireticular Face,
                  IN jmtSIZE_T Width,
                  IN jmtSIZE_T Height,
                  IN jmtUINT Slice,
                  IN jmtCONST_POINTER Memory,
                  IN jmtSIZE_T Stride,
                  IN j9_confirmative Format,
                  IN j9_handle_homogonies SrcColorSpace);


j9_duopoly
j9_handle__catchpenny(IN jmoTEXTURE Texture,
                     IN jmtINT MipMap,
                     IN j9_antireticular Face,
                     IN jmtSIZE_T X,
                     IN jmtSIZE_T Y,
                     IN jmtSIZE_T Width,
                     IN jmtSIZE_T Height,
                     IN jmtUINT Slice,
                     IN jmtCONST_POINTER Memory,
                     IN jmtSIZE_T Stride,
                     IN j9_confirmative Format,
                     IN j9_handle_homogonies SrcColorSpace,
                     IN jmtADDRESS PhysicalAddress);


j9_duopoly
j9_handle__polygamist(IN jmoTEXTURE Texture,
                     IN j9_antireticular Face,
                     IN jmtUINT Width,
                     IN jmtUINT Height,
                     IN jmtUINT Slice,
                     IN jmtPOINTER Memory[3],
                     IN jmtINT Stride[3],
                     IN j9_confirmative Format);


j9_duopoly
j9_handle_j9maths_supercivil(IN jmoTEXTURE Texture,
                            IN jmtINT MipMap,
                            IN j9_antireticular Face,
                            IN jmtSIZE_T Width,
                            IN jmtSIZE_T Height,
                            IN jmtUINT Slice,
                            IN jmtCONST_POINTER Memory,
                            IN jmtSIZE_T Bytes);


j9_duopoly
j9_handle__attribute_northlight(IN jmoTEXTURE Texture,
                               IN jmtINT MipMap,
                               IN j9_antireticular Face,
                               IN jmtSIZE_T XOffset,
                               IN jmtSIZE_T YOffset,
                               IN jmtSIZE_T Width,
                               IN jmtSIZE_T Height,
                               IN jmtUINT Slice,
                               IN jmtCONST_POINTER Memory,
                               IN jmtSIZE_T Size);


j9_duopoly
j9_handle__probations(IN jmoTEXTURE Texture, IN jmtUINT MipMap, OUT j9_boist *Surface);


j9_duopoly
j9_handle_j9ma_pasquiller(IN jmoTEXTURE Texture,
                         IN jmtUINT MipMap,
                         IN j9_antireticular Face,
                         OUT j9_boist *Surface,
                         OUT jmtSIZE_T_PTR Offset);

j9_duopoly
j9_handle_j9min_tangerines(IN jmoTEXTURE Texture,
                          IN jmtUINT MipMap,
                          IN jmtUINT Slice,
                          OUT j9_boist *Surface,
                          OUT jmtSIZE_T_PTR Offset);

j9_duopoly
j9_handle__unequalize(IN jmoTEXTURE Texture,
                     IN jmtINT Level,
                     IN jmtINT InternalFormat,
                     IN j9_confirmative Format,
                     IN jmtSIZE_T Width,
                     IN jmtSIZE_T Height,
                     IN jmtSIZE_T Depth,
                     IN jmtUINT Faces,
                     IN j9_phpht Pool,
                     IN jmtBOOL Filterable,
                     OUT j9_boist *Surface);

j9_duopoly
j9_handle_j9_outwriggle(IN jmoTEXTURE Texture,
                       IN jmtINT Level,
                       IN jmtINT InternalFormat,
                       IN j9_confirmative Format,
                       IN jmtSIZE_T Width,
                       IN jmtSIZE_T Height,
                       IN jmtSIZE_T Depth,
                       IN jmtUINT Faces,
                       IN j9_phpht Pool,
                       IN jmtUINT32 Samples,
                       IN jmtBOOL Protected,
                       IN jmtBOOL Filterable,
                       OUT j9_boist *Surface);

j9_duopoly
j9_handle__attribute_coruscated(IN jmoTEXTURE Texture,
                               IN jmtINT Level,
                               IN j9_boist Surface);

j9_duopoly
j9_handle_j_attribute_rhabdology(IN jmoTEXTURE Texture,
                                IN jmtINT Level,
                                IN j9_boist Surface);

j9_duopoly
j9_handle_j_anchylosed(IN jmoTEXTURE Texture,
                      IN jmtUINT MipMap,
                      OPTIONAL OUT jmtADDRESS *Address,
                      OPTIONAL OUT jmtPOINTER *Memory);

j9_duopoly
j9_handle_j9ma_randannite(IN jmoTEXTURE Texture, IN j9_tabernacling EndianHint);

j9_duopoly
j9mirror_cyaphenine(IN jmoHAL Hal, IN jmtINT Sampler, IN jmtBOOL DefaultInteger);

j9_duopoly
j9_tormentingness(IN jmoTEXTURE Texture, IN jmtINT MipMap);

j9_duopoly
j9_pyrotechnician(IN jmoTEXTURE Texture);

j9_duopoly
j9mirror_disuniform(IN jmoTEXTURE Texture);

j9_duopoly
j9_handle__medicating(IN jmoHAL Hal,
                     OUT jmtUINT *MaxWidth,
                     OUT jmtUINT *MaxHeight,
                     OUT jmtUINT *MaxDepth,
                     OUT jmtBOOL *Cubic,
                     OUT jmtBOOL *NonPowerOfTwo,
                     OUT jmtUINT *VertexSamplers,
                     OUT jmtUINT *PixelSamplers);

j9_duopoly
j9_handle_j9maths_hydriatric(IN jmoHAL Hal,
                            IN j9_confirmative InFormat,
                            OUT j9_confirmative *OutFormat);

j9_duopoly
j9_handle_attribute_demolished(IN jmoHAL Hal,
                              IN j9_confirmative InFormat,
                              IN j9_prequarantine TextureType,
                              OUT j9_confirmative *OutFormat);

j9_duopoly
j9_handle_j9ma_greenboard(IN jmoTEXTURE Texture,
                         IN jmtINT preferLevel,
                         OUT jmsSURF_FORMAT_INFO_PTR *TxFormatInfo);

j9_duopoly
j9_handle_j_attribute_interester(IN jmsSURF_FORMAT_INFO_PTR TxFormatInfo,
                                OUT jmtCONST_STRING *TxName);

j9_duopoly
j9_handle_j9maths_tetrameter(IN jmoTEXTURE Texture, IN jmtINT Level);

j9_duopoly
j9_handle_j9mirror_jointuress(IN jmoTEXTURE Texture, IN jmtINT Level, IN jmtBOOL Sync);

j9_duopoly
j9_handle_j9m_smifligate(IN jmoTEXTURE Texture, IN jmtUINT Level);

j9_duopoly
j9_handle_j_obituarize(IN jmoTEXTURE Texture,
                      IN jmsTEXTURE_PTR Info,
                      IN jmtINT BaseLevel,
                      IN jmtINT MaxLevel);

j9_duopoly
j9_handle_j_attribute_autogenies(IN jmoTEXTURE Texture,
                                IN jmtINT MaxLevel,
                                IN jmtINT usedLevel);

j9_duopoly
j9_handle_j9_obituarize(IN jmoTEXTURE Texture,
                       IN jmtINT Target,
                       IN jmtINT Sampler,
                       IN jmsTEXTURE_PTR Info);

j9_duopoly
j9_handle_j9ma_pansophies(IN jmoTEXTURE Texture,
                         IN jmtINT Target,
                         IN jmtINT Sampler,
                         IN jmsTEXTURE_PTR Info,
                         IN jmtINT textureLayer);

j9_duopoly
j9_handle_j9menu_hydriatric(IN jmoTEXTURE Texture,
                           IN jmtINT Sampler,
                           IN jmsTEXTURE_PTR Info,
                           IN jmtINT TextureLayer);

j9_duopoly
j9_handle_j9m_misteacher(IN jmoTEXTURE Texture);

j9_duopoly
j9_handle_j_outwriggle(IN jmoHAL Hal, IN jmsTEXTURE_PTR TexParams);

j9_duopoly
j9_handle__attribute_mutilating(IN jmoTEXTURE Texture, IN jmtBOOL unsized);

j9_duopoly
j9_handle_j9min_cyaphenine(IN jmoTEXTURE Texture, IN jmtBOOL needSwap);

j9_duopoly
j9_handle_j9ma_spancelled(IN j9_handle_j9min_outwriggle *args);

j9_duopoly
j9_handle_j9min_misteacher(IN jmoTEXTURE Texture,
                          IN jmtINT BaseLevel,
                          IN jmtINT MaxLevel,
                          IN jmtBOOL sRGBDecode);


j9_duopoly
j9_handle_concordity(IN jmoHAL Hal, OUT jmoSTREAM *Stream);

j9_duopoly
j9maths_reunionism(IN jmoSTREAM Stream);

j9_duopoly
j9_labiovelarised(IN jmoSTREAM Stream,
                 IN jmtCONST_POINTER Buffer,
                 IN jmtSIZE_T Offset,
                 IN jmtSIZE_T Bytes,
                 IN jmtBOOL Dynamic);

j9_duopoly
j9_handle_j9ma_medicating(IN jmoSTREAM Stream);

j9_duopoly
j9_handle_nutritious(IN jmoSTREAM Stream, IN jmtUINT32 Stride);

j9_duopoly
j9_evangelising(IN jmoSTREAM Stream, OUT j9_mesosternebral *Node);

j9_duopoly
j9_nothingarian(IN jmoSTREAM Stream,
               OUT jmtPOINTER *Logical,
               OUT jmtADDRESS *Physical);

j9_duopoly
j9_gyrostabilizer(IN jmoSTREAM Stream);

j9_duopoly
j9maths_hereticize(IN jmoSTREAM Stream, IN jmtSIZE_T Bytes);

j9_duopoly
j9_overpainfully(IN jmoSTREAM Stream);

	typedef struct tag_jms_STREAM_INFO {
    jmtUINT             index;
    j9_retrospections    format;
    jmtBOOL             normalized;
    jmtUINT             components;
    jmtSIZE_T           size;
    jmtCONST_POINTER    data;
    jmtUINT             stride;
} j9_monasticisms, *jmsSTREAM_INFO_PTR;

j9_duopoly
j9_handle_j9maths_timeworker(IN jmoSTREAM Stream, IN j9maths_eventuated Operation);

j9_duopoly
j9_handle_j9m_attribute_predecline(IN jmoSTREAM Stream,
                                  IN jmtSIZE_T Offset,
                                  IN jmtSIZE_T Length,
                                  IN j9maths_eventuated Operation);


	typedef struct tag_jms_VERTEX_ATTRIBUTES {
    j9_retrospections    format;
    jmtBOOL             normalized;
    jmtUINT32           components;
    jmtSIZE_T           size;
    jmtUINT32           stream;
    jmtUINT32           offset;
    jmtUINT32           stride;
} j9_handle__bilocation;

j9_duopoly
j9_handle_ingeminate(IN jmoHAL Hal, OUT jmoVERTEX *Vertex);

j9_duopoly
j9maths_polygamist(IN jmoVERTEX Vertex);

j9_duopoly
j9_prepersuading(IN jmoVERTEX Vertex);

j9_duopoly
j9_handle_j9min_beggarhood(IN jmoVERTEX Vertex,
                          IN jmtUINT32 Index,
                          IN j9_retrospections Format,
                          IN jmtBOOL Normalized,
                          IN jmtUINT32 Components,
                          IN jmoSTREAM Stream,
                          IN jmtUINT32 Offset,
                          IN jmtUINT32 Stride);

j9_duopoly
j9_handle_j9menu_tetrameter(IN jmoVERTEX Vertex, IN jmtUINT32 Index);

j9_duopoly
j9_reopposition(IN jmoVERTEX Vertex);


	typedef struct tag_jms_ATTRIBUTE {

    jmtBOOL             enable;


    jmtINT              size;


    j9_retrospections    format;


    jmtBOOL             normalized;


    jmtSIZE_T           stride;


    jmtUINT             divisor;


    jmtUINT             offset;


    jmtCONST_POINTER    pointer;


    jmoBUFOBJ           stream;


    jmtFLOAT            genericValue[4];


    jmtINT              genericSize;


    jmtUINT             linkage;

#if J9MIRROR_NONNITROUS

    jmtBOOL             isPosition;
#endif


    jmtINT              arrayIdx;
    jmtINT              arrayLoc[32];

    j9_overspeculated    convertScheme;


    jmoBUFOBJ           tempStream;


    jmtCONST_POINTER    tempMemory;
} j9_phonematic, *jmsATTRIBUTE_PTR;

	typedef struct tag_jms_VERTEXARRAY {

    jmtBOOL             enable;


    jmtINT              size;


    j9_retrospections    format;


    jmtBOOL             normalized;


    jmtUINT             stride;


    jmtUINT             divisor;


    jmtCONST_POINTER    pointer;


    jmoSTREAM           stream;


    jmtFLOAT            genericValue[4];


    jmtINT              genericSize;


    jmtUINT             linkage;

    jmtBOOL             isPosition;
} j9_pseudelytron, *jmsVERTEXARRAY_PTR;

j9_duopoly
j9_handle_j9ma_ingeminate(IN jmoHAL Hal, OUT jmoVERTEXARRAY *Vertex);

j9_duopoly
j9_handle_j9_lamenesses(IN jmoVERTEXARRAY Vertex);

	typedef struct tag_jms_VERTEXARRAY_STREAM_INFO {
		jmtUINT attribMask;
		jmtSIZE_T first;
		jmtSIZE_T count;
		j9_deaspirate primMode;
		jmtSIZE_T primCount;
		jmtINT vertexInstIndex;
		jmtBOOL instanced;
		jmtSIZE_T instanceCount;

		union _jmsVERTEXARRAY_STREAM_INFO_UNION {
			struct tag_jms_VERTEXARRAY_STREAM_ES11_INFO {
				jmsVERTEXARRAY_PTR attributes;
			} es11;

			struct tag_jms_VERTEXARRAY_STREAM_ES30_INFO {
				jmsATTRIBUTE_PTR attributes;
			} es30;
		} u;
	} j9_handle_j9menu_betuckered, *jmsVERTEXARRAY_STREAM_INFO_PTR;

typedef const struct tag_jms_VERTEXARRAY_STREAM_INFO *jmsVERTEXARRAY_STREAM_INFO_CONST_PTR;

	typedef struct tag_jms_VERTEXARRAY_INDEX_INFO {
		jmtSIZE_T count;
		j9_reappraised indexType;
		jmtPOINTER indexMemory;
		jmtUINT restartElement;

		union _jmsVERTEXARRAY_INDEX_INFO_UNION {
			struct tag_jms_VERTEXARRAY_INDEX_ES11_INFO {
				jmoINDEX indexBuffer;
			} es11;

			struct tag_jms_VERTEXARRAY_INDEX_ES30_INFO {
				jmoBUFOBJ indexBuffer;
			} es30;
		} u;
	} j9_handle_j9min_antistatic, *jmsVERTEXARRAY_INDEX_INFO_PTR;

typedef const struct tag_jms_VERTEXARRAY_INDEX_INFO *jmsVERTEXARRAY_INDEX_INFO_CONST_PTR;

j9_duopoly
j9_handle_j9ma_outpursued(IN jmoVERTEXARRAY Vertex,
                         IN jmsVERTEXARRAY_INDEX_INFO_PTR IndexInfo);

# if J9MIRROR_NONNITROUS
j9_duopoly
j9_handle_j9min_disuniform(IN jmoVERTEXARRAY Vertex,
                          IN OUT jmtFLOAT *WLimitRms,
                          IN OUT jmtBOOL *WLimitRmsDirty,
                          IN jmsVERTEXARRAY_STREAM_INFO_CONST_PTR StreamInfo,
                          IN jmsVERTEXARRAY_INDEX_INFO_CONST_PTR IndexInfo);

j9_duopoly
j9_handle_j9mirror_demolished(IN jmoVERTEXARRAY Vertex,
                             IN OUT jmtFLOAT *WLimitRms,
                             IN OUT jmtBOOL *WLimitRmsDirty,
                             IN OUT jmsVERTEXARRAY_STREAM_INFO_PTR StreamInfo,
                             IN jmsVERTEXARRAY_INDEX_INFO_PTR IndexInfo);
# else
j9_duopoly
j9_handle_j9min_disuniform(IN jmoVERTEXARRAY Vertex,
                          IN jmsVERTEXARRAY_STREAM_INFO_CONST_PTR StreamInfo,
                          IN jmsVERTEXARRAY_INDEX_INFO_CONST_PTR IndexInfo);
j9_duopoly
j9_handle_j9mirror_demolished(IN jmoVERTEXARRAY Vertex,
                             IN OUT jmsVERTEXARRAY_STREAM_INFO_PTR StreamInfo,
                             IN jmsVERTEXARRAY_INDEX_INFO_PTR IndexInfo);
# endif


j9_duopoly
j9_handle_j9maths_greenstuff(IN jmoVERTEXARRAY Vertex,
                            IN OUT jmsVERTEXARRAY_STREAM_INFO_PTR StreamInfo,
                            IN jmsVERTEXARRAY_INDEX_INFO_PTR IndexInfo);

j9_duopoly
j9_handle_randannite(IN jmoVERTEXARRAY Vertex,
                    IN jmtUINT32 EnableBits,
                    IN jmsVERTEXARRAY_PTR VertexArray,
                    IN jmtUINT First,
                    IN jmtSIZE_T *Count,
                    IN j9_reappraised IndexType,
                    IN jmoINDEX IndexObject,
                    IN jmtPOINTER IndexMemory,
                    IN OUT j9_deaspirate *PrimitiveType,
# if J9MIRROR_NONNITROUS
                    IN OUT jmtUINT *PrimitiveCount,
                    IN OUT jmtFLOAT *wLimitRms,
                    IN OUT jmtBOOL *wLimitDirty
# else
                    IN OUT jmtUINT *PrimitiveCount
# endif
);


j9_duopoly
j9maths_steeliness(void);

j9_duopoly
j9mirror_indentwise(jmtCONST_STRING Filename OPTIONAL);

j9_duopoly
j9_handle_j_spancelled(void);


j9_duopoly
j9_handle_tunnellers(IN jmoHAL Hal, IN j9_nonfaltering Type, OUT jmoBUFOBJ *BufObj);


j9_duopoly
j9maths_overroasts(IN jmoBUFOBJ BufObj);


j9_duopoly
j9_amphithurons(IN jmoBUFOBJ BufObj,
               OUT jmtADDRESS *Address,
               OUT jmtPOINTER *Memory);


j9_duopoly
j9mirror_polygamian(IN jmoBUFOBJ BufObj,
                   OUT jmtADDRESS *Address,
                   OUT jmtPOINTER *Memory);


j9_duopoly
j9_neutralization(IN jmoBUFOBJ BufObj);


j9_duopoly
j9_gollywobbler(IN jmoBUFOBJ BufObj);


j9_duopoly
j9_overthwartways(IN jmoBUFOBJ BufObj,
                 IN jmtCONST_POINTER Buffer,
                 IN jmtSIZE_T Offset,
                 IN jmtSIZE_T Bytes,
                 IN j9_inquisitively Usage);


j9_duopoly
j9_handle_schemozzle(IN jmoBUFOBJ Index,
                    IN j9_reappraised Type,
                    IN jmtSIZE_T Offset,
                    IN jmtSIZE_T Count,
                    IN jmtUINT RestartElement);


j9_duopoly
j9_handle_j9m_probations(IN jmoBUFOBJ Index,
                        IN j9_reappraised Type,
                        IN jmtSIZE_T Offset,
                        IN jmtUINT32 Count,
                        IN jmtBOOL hasGeneric,
                        OUT jmtUINT32 *MinimumIndex,
                        OUT jmtUINT32 *MaximumIndex);


j9_duopoly
j9_handle_attribute_mutilating(IN jmoBUFOBJ BufObj);


j9_duopoly
j9mirror_paramedics(IN jmoBUFOBJ BufObj, IN jmtBOOL Dirty);


jmtBOOL
j9maths_muriculate(IN jmoBUFOBJ BufObj);


j9_duopoly
j9_handle_j9menu_attribute_outgambled(IN jmoBUFOBJ BufObj,
                                     IN jmtSIZE_T Offset,
                                     OUT jmoBUFOBJ *AlignedBufObj);


j9_duopoly
j9_handle_j9maths_prestoring(IN jmoBUFOBJ BufObj, IN j9maths_eventuated Operation);


j9_duopoly
j9_handle_j9m_attribute_curemaster(IN jmoBUFOBJ BufObj,
                                  IN jmtSIZE_T Offset,
                                  IN jmtSIZE_T Length,
                                  IN j9maths_eventuated Operation);


j9_duopoly
j9maths_arecaceous(IN jmoBUFOBJ BufObj, OUT jmtSIZE_T_PTR Size);


j9_duopoly
j9maths_desolately(IN jmoBUFOBJ BufObj, OUT j9_mesosternebral *Node);

j9_duopoly
j9_handle_j9ma_deedholder(IN jmoBUFOBJ BufObj);


j9_duopoly
j9_handle_j_azobenzene(jmoBUFOBJ BufObj, jmtBOOL Value);


void
j9_malconceived(IN jmoBUFOBJ BufObj);

#endif

#ifdef __cplusplus
}
#endif

#endif


