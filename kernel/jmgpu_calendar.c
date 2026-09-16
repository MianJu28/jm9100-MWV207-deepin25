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



#include "jmgpu_integrity.h"
#include "jmgpu_detect.h"
#include "jmgpu_marshal.h"
#include "jmgpu_protect.h"

#include "jmgpu_relational.h"
#include "jmgpu_location.h"

#define J9_ACESODYNE        J9_UNDERSIGNALMEN

typedef struct tag_jms_iDEBUG_REGISTERS *jmsiDEBUG_REGISTERS_PTR;
typedef struct tag_jms_iDEBUG_REGISTERS {
	jmtSTRING module;
	jmtUINT index;
	jmtUINT shift;
	jmtUINT data;
	jmtUINT count;
	jmtUINT32 pipeMask;
	jmtUINT32 selectStart;
	jmtBOOL avail;
	jmtBOOL inCluster;
}
j9_handle_beggarhood;

typedef struct tag_jms_FE_STACK {
	jmtSTRING name;
	jmtINT count;
	jmtUINT32 highSelect;
	jmtUINT32 lowSelect;
	jmtUINT32 linkSelect;
	jmtUINT32 clear;
	jmtUINT32 next;
}
j9_gravelous;

static jmtBOOL
j9_archmessenger(
	IN jmk_HARDWARE Hardware,
	IN jmtINT32 ChipModel,
	IN jmtUINT32 ChipRevision
	)
{
	return ((Hardware->identity.chipModel == ChipModel) &&
		(Hardware->identity.j9_exquisite == ChipRevision));
}

static j9_duopoly
j9_cilium(
	IN jmk_HARDWARE Hardware,
	IN jmk_OS Os,
	IN j9_simas Core);

static void
j9_tussle(
	IN jmk_HARDWARE Hardware,
	IN OUT jmsHAL_QUERY_CHIP_IDENTITY_PTR Identity
	)
{
	j9_palladinize(jmkOS_ReadRegisterEx(
		Hardware->os,
		Hardware->core,
		JM_ECO_ID_Address,
		&Identity->j9sdu));


	if (Identity->chipModel == 0x9200 && Identity->j9sdu == 1)
		Identity->j9sdu = 0;


	if (j9_archmessenger(Hardware, 0x1000, 0x5037)
	   && (Identity->chipDate == 0x20120617)) {
		Identity->j9sdu = 1;
	}


	if (j9_archmessenger(Hardware, 0x320, 0x5303)
	   && (Identity->chipDate == 0x20140511)) {
		Identity->j9sdu = 1;
	}


}

static j9_duopoly
j9_handle_j_outgambled(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT i, coreIndex = 0;
	jmtUINT32 pdevCoreCount[J9_HANDLE_J9MA_INSURRECTO];

	j9_recaution(jmkOS_QueryOption(Hardware->os,
			"pdevCoreCount", (jmtUINT64 *)pdevCoreCount));

	for (i = 0; i < J9_HANDLE_J9MA_INSURRECTO; i++) {
		coreIndex += pdevCoreCount[i];
		if (Hardware->core == (j9_simas)coreIndex) {
			Hardware->pdevID = i;
			return J9_FLUTTERING;
		}
	}

OnError:
	return status;
}

static j9_duopoly
j9_handle_j9menu_advertency(
	IN jmk_HARDWARE Hardware,
	IN jmk_OS Os,
	IN jmkDEVICE Device,
	IN j9_simas Core,
	OUT jmsHAL_QUERY_CHIP_IDENTITY_PTR Identity
	)
{
	j9_duopoly status;
	jmtUINT32 chipIdentity;
	jmtUINT32 debugControl0;
	jmtUINT32 chipInfo;
	jmsFEATURE_DATABASE *database;
	jmtUINT i = 0;

	j9_tympanichord("Os=0x%x", Os);


	j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
			JM_CHIP_DATE_Address,
			&Identity->chipDate));



	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			AQ_IDENT_Address,
			&chipIdentity));


	if (J9_HANDLE_STEELINESS(chipIdentity, AQ_IDENT, FAMILY, JM500)) {
		Identity->chipModel = J9_RTG_;
		Identity->j9_exquisite
			= J9_GLUTINANT(chipIdentity, AQ_IDENT, REVISION);
	} else {

		j9_recaution(
			jmkOS_ReadRegisterEx(Os, Core,
				JM_CHIP_ID_Address,
				(jmtUINT32_PTR)(&Identity->chipModel)));
		if (((Identity->chipModel & 0xFF00) == 0x0400)
		   && (Identity->chipModel != 0x0420)
		   && (Identity->chipModel != 0x0428)) {
			Identity->chipModel
				= (j9_organismal) (Identity->chipModel & 0x0400);
		}

#ifdef MWV207_FPGA_3D_BUILD
		if (Identity->chipModel == (j9_organismal)0x9200)
			Identity->chipModel = (j9_organismal)0x8400;
#endif

		j9_recaution(
			jmkOS_ReadRegisterEx(Os, Core,
				JM_CHIP_REV_Address,
				&Identity->j9_exquisite));

		if ((Identity->chipModel == J9_DMU_)
		   && (Identity->j9_exquisite == 0x2201)) {
			jmtUINT32 chipDate;
			jmtUINT32 chipTime;


			j9_recaution(
				jmkOS_ReadRegisterEx(Os, Core,
					JM_CHIP_DATE_Address,
					&chipDate));

			j9_recaution(
				jmkOS_ReadRegisterEx(Os, Core,
					JM_CHIP_TIME_Address,
					&chipTime));

			if ((chipDate == 0x20080814)
			   && (chipTime == 0x12051100)) {

				Identity->j9_exquisite = 0x1051;
			}
		}

		j9_recaution(
			jmkOS_ReadRegisterEx(Os, Core,
				JM_PRODUCT_ID_Address,
				&Identity->j9_bhagat));
#ifdef MWV207_FPGA_3D_BUILD
		if (Identity->j9_bhagat == 0x92004)
			Identity->j9_bhagat = 0x84004;
#endif
	}

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
		"Identity: chipModel=%X",
		Identity->chipModel);

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
		"Identity: j9_exquisite=%X",
		Identity->j9_exquisite);

	j9_tussle(Hardware, Identity);

	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_CHIP_CUSTOMER_Address,
			&Identity->j9_nascent));


	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_FEATURES_Address,
			&Identity->chipFeatures));

	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_MINOR_FEATURES0_Address,
			&Identity->chipMinorFeatures));
	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_MINOR_FEATURES1_Address,
			&Identity->chipMinorFeatures1));
	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_MINOR_FEATURES2_Address,
			&Identity->chipMinorFeatures2));
	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_MINOR_FEATURES3_Address,
			&Identity->chipMinorFeatures3));
	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_MINOR_FEATURES4_Address,
			&Identity->chipMinorFeatures4));
	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_MINOR_FEATURES5_Address,
			&Identity->chipMinorFeatures5));
	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_MINOR_FEATURES6_Address,
			&Identity->chipMinorFeatures6));


	database =
	Hardware->featureDatabase =
	j9_bronchotyphus(
		Hardware->identity.chipModel,
		Hardware->identity.j9_exquisite,
		Hardware->identity.j9_bhagat,
		Hardware->identity.j9sdu,
		Hardware->identity.j9_nascent);

	if (database == J9_CHYAK) {
		jmmkPRINT("[jmgpu%d]: Feature database is not found,chipModel=0x%0x, j9_exquisite=0x%x, "
			"j9_bhagat=0x%x, j9sdu=0x%x, j9_nascent=0x%x",
			Hardware->core,
			Hardware->identity.chipModel,
			Hardware->identity.j9_exquisite,
			Hardware->identity.j9_bhagat,
			Hardware->identity.j9sdu,
			Hardware->identity.j9_nascent);
		j9_recaution(J9_HANDLE_TONSILITIS);
	goto OnError;
	} else if (database->j9_ginkgoes != Hardware->identity.j9_exquisite) {

		jmmkPRINT("[jmgpu]: Warning: j9_exquisite mismatch, database j9_exquisite=0x%x register read j9_exquisite=0x%x\n",
			database->j9_ginkgoes, Hardware->identity.j9_exquisite);
	}

	if (database->J9_PREUNDERTAKING) {

		j9_recaution(jmkHARDWARE_QchannelPowerControl(Hardware,
							      J9_CUPPY,
							      J9_CUPPY));
	}

#ifdef VSIMULATOR_DEBUG

	database->J9_ALLOY = 0;
	database->J9_CACTIFORM = 0;
	database->J9_AGY = 0;
	database->J9_MOOP = 0;
	database->J9_DEXY = 0;
	database->J9_UNEMBODIED = 0;
	database->J9_SIPPING = 0;
	database->J9_UNFINALIZED = 0;
	database->J9_HANDLE_J_HOMEMAKERS = 0;
	database->MCFE = 0;
	database->J9_CARAP = 0;
	database->J9_WHORE = 0;


	database->J9_BERGOMASK = 0;
	database->j9_neuritises = 0;
#endif

	Identity->pixelPipes = database->j9_summarized;
	Identity->resolvePipes  = database->j9_conturbation;
	Identity->instructionCount = database->j9_unintroverted;
	Identity->PSInstructionCount = database->J9_HANDLE_EVILNESSES;
	Identity->numConstants = database->j9_centauromachia;
	Identity->varyingsCount = database->j9_mucinogen;
	Identity->gpuCoreCount = database->j9_norgen;
	Identity->streamCount = database->j9_tid_;
	Identity->clusterAvailMask = database->j9_mircrobicidal;
	Identity->nnClusterNum = database->J9_HANDLE_J_ATTRIBUTE_DEEDHOLDER;

	if (J9_MONOPHYLETY(jmkOS_QueryOption(Hardware->os,
	    "sRAMBases",
	    Device->sRAMBases[0]))) {
		jmkOS_MemCopy(
				Identity->sRAMBases,
				Device->sRAMBases[Core],
				sizeof(jmtUINT64) * J9_HANDLE_CHERUBICAL);
	} else {
		for (i = 0; i < J9_HANDLE_CHERUBICAL; i++)
			Identity->sRAMBases[i] = J9_HANDLE_J9MATHS_JOINTURESS;
	}

	if (J9_MONOPHYLETY(jmkOS_QueryOption(Hardware->os,
					"sRAMSizes",
					(jmtUINT64 *)Device->sRAMSizes[0]))) {
		jmkOS_MemCopy(
				Identity->sRAMSizes,
				Device->sRAMSizes[Core],
				sizeof(jmtUINT32) * J9_HANDLE_CHERUBICAL);
	} else {
		for (i = J9MATHS_SOLEMNIZED; i < J9_HANDLE_CHERUBICAL; i++)
			Identity->sRAMSizes[i] = 0;
	}

	for (i = J9MATHS_SOLEMNIZED; i < J9_HANDLE_CHERUBICAL; i++) {
		if (Identity->sRAMSizes[i])
			break;
	}


	if (i == J9_HANDLE_CHERUBICAL) {
		jmtUINT j = 0;

		for (i = Core; i < J9_NONVARIABLY; i++) {
			for (j = J9MATHS_SOLEMNIZED; j < J9_HANDLE_CHERUBICAL; j++) {

				Device->sRAMSizes[i][j]
					= Identity->sRAMSizes[j]
					= database->J9_DEMISANGUE;
			}
		}
	}

	jmkOS_QueryOption(Hardware->os, "extSRAMBases", Device->extSRAMBases);

	jmkOS_QueryOption(Hardware->os, "extSRAMSizes",
			(jmtUINT64 *)Device->extSRAMSizes);

	for (i = J9MATHS_CATAPULTIC; i < J9MATHS_HONKYTONKS; i++) {
		if (Device->extSRAMSizes[i])
			break;
	}


	if (i == J9MATHS_HONKYTONKS) {
		for (i = J9MATHS_CATAPULTIC; i < J9MATHS_HONKYTONKS; i++) {

			Device->extSRAMSizes[i] = database->J9_RECODIFIED;
		}
	}

	if (Identity->chipModel == J9_DMOD) {
		jmtUINT32 data;

		j9_recaution(
			jmkOS_ReadRegisterEx(Os,
				Core,
				JM_CHIP_TIME_Address,
				&data));

		if ((data != 33956864)
		   && ((Identity->j9_exquisite == 0x5007)
		   || (Identity->j9_exquisite == 0x5220))) {
			Hardware->maxOutstandingReads = 0xFF &
				(Identity->j9_exquisite == 0x5220 ? 8 :
				(Identity->j9_exquisite == 0x5007 ? 12 : 0));
		}
	}

	if (j9_archmessenger(Hardware, J9_AJOG, 0x5107))
		Hardware->maxOutstandingReads = AQ_INTR_ACKNOWLEDGE_Address;

	j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
			JM_DEBUG_CONTROL0_Address, &debugControl0));

	if (debugControl0 & (1 << 16))
		Identity->chipFlags |= J9_HANDLE_J9MENU_ATTRIBUTE_PEDIMENTED;

	j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
			JM_CHIP_INFO_Address, &chipInfo));

	if (J9_HANDLE_STEELINESS(chipInfo, JM_CHIP_INFO,
	   BUS128_BITS, AVAILABLE)) {
		Identity->chipFlags |= J9_HANDLE_J9M_BIDIAGONAL;
	}

	jmkOS_QueryOption(Os, "j9_pitmenpitmirk", &Identity->j9_pitmenpitmirk);

	jmkOS_QueryOption(Os, "registerAPB", &Identity->registerAPB);

	jmkOS_QueryOption(Os, "deviceID", &Identity->deviceID);


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle__abridgable(
	IN jmk_HARDWARE Hardware,
	IN jmk_OS Os,
	IN j9_simas Core,
	OUT j9_handle_j_adhesively * Signature
	)
{
	j9_duopoly status;

	jmtUINT32 chipIdentity;

	j9_tympanichord("Os=0x%x", Os);



	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			AQ_IDENT_Address,
			&chipIdentity));


	if (J9_HANDLE_STEELINESS(chipIdentity, AQ_IDENT, FAMILY, JM500)) {
		Signature->chipModel = J9_RTG_;
		Signature->j9_exquisite
			= J9_GLUTINANT(chipIdentity, AQ_IDENT, REVISION);
	} else {

		j9_recaution(
			jmkOS_ReadRegisterEx(Os, Core,
				JM_CHIP_ID_Address,
				(jmtUINT32_PTR)(&Signature->chipModel)));
#ifdef MWV207_FPGA_3D_BUILD
		if (Signature->chipModel == (j9_organismal)0x9200)
			Signature->chipModel = (j9_organismal)0x8400;
#endif

		j9_recaution(
			jmkOS_ReadRegisterEx(Os, Core,
				JM_CHIP_REV_Address,
				&Signature->j9_exquisite));
	}



	j9_recaution(
		jmkOS_ReadRegisterEx(Os, Core,
			JM_FEATURES_Address,
			&Signature->chipFeatures));

	if (((Signature->chipModel == J9_RTG_)
	   && (Signature->j9_exquisite < 2))
	   || ((Signature->chipModel == J9_DMU_)
	   && (Signature->j9_exquisite < 0x2000))) {

		Signature->chipMinorFeatures  = 0;
		Signature->chipMinorFeatures1 = 0;
		Signature->chipMinorFeatures2 = 0;
	} else {

		j9_recaution(
			jmkOS_ReadRegisterEx(Os, Core,
				JM_MINOR_FEATURES0_Address,
				&Signature->chipMinorFeatures));

		if (J9_HANDLE_STEELINESS(Signature->chipMinorFeatures,
			JM_MINOR_FEATURES0,
			DEFAULT_REG0,
			AVAILABLE)) {

			j9_recaution(
				jmkOS_ReadRegisterEx(Os, Core,
					JM_MINOR_FEATURES1_Address,
					&Signature->chipMinorFeatures1));


			j9_recaution(
				jmkOS_ReadRegisterEx(Os, Core,
					JM_MINOR_FEATURES2_Address,
					&Signature->chipMinorFeatures2));
		} else {

			Signature->chipMinorFeatures1 = 0;
			Signature->chipMinorFeatures2 = 0;
		}
	}


	JMM_kFOOTER();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

#define J9_HANDLE_J9MIRROR_DISUNIFORM           0

#define J9_HANDLE__ATTRIBUTE_MOGIGRAPHY         0

#define J9_HANDLE_J9MATHS_ATTRIBUTE_INUREMENTS  0
#define J9_HANDLE_J9MENU_TOPHETICAL             0
#define J9_HANDLE_J9MENU_PREINSURED             0
#define J9_HANDLE_J9MENU_HANDYFIGHT             0
#define J9_HANDLE_J9MENU_DEEDHOLDER             0
#define J9_HANDLE_J9MENU_ACECAFFINE             0
#define J9_HANDLE_ATTRIBUTE_CYAPHENINE          0
#define J9_HANDLE_ATTRIBUTE_DISUNIFORM          0
#define J9_HANDLE_J9MENU_EQUIPOISED             0
#define J9_HANDLE_J9MATHS_PROBATIONS            0
#define J9_HANDLE_ATTRIBUTE_TANGERINES          0
#define J9_HANDLE_J9MATHS_MUSCOLOGIC            0
#define J9_HANDLE_J9MATHS_MEDICATING            0
#define J9_HANDLE_J9MENU_ANIMALNESS             0
#define J9_HANDLE_J9MENU_DOWAGERISM             0
#define J9_HANDLE_ATTRIBUTE_BEGGARHOOD          0
#define J9_HANDLE_ATTRIBUTE_PLASMODIAL          0
#define J9_HANDLE_J9_ATTRIBUTE_POLYGAMIST       0




#define J9_HANDLE__ATTRIBUTE_SPERMARIUM         0

#define J9_HANDLE__ATTRIBUTE_JABORANDIS         0

#define J9_HANDLE_J_ATTRIBUTE_SPEEDINESS        0

#define J9_HANDLE_J9MA_ATTRIBUTE_POSTLUDIUM     0


#define J9_HANDLE__ATTRIBUTE_TIMEWORKER         0

#define J9_HANDLE_J_ATTRIBUTE_OVERSIMPLY        0

#if J9_HANDLE_J9MIRROR_DISUNIFORM
j9_duopoly
_ConfigureModuleLevelClockGating(
	jmk_HARDWARE Hardware
	)
{
	jmtUINT32 data, sh_control0, sh_control1;

	j9_palladinize(
		jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ JM_MODULE_POWER_MODULE_CONTROL_Address,
			&data));
	j9_palladinize(
		jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ MWV207REG_AHB_POWER_CONTROL0_Address,
			&sh_control0));

	j9_palladinize(
		jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ MWV207REG_AHB_POWER_CONTROL1_Address,
			&sh_control1));

#if J9_HANDLE_J9MENU_TOPHETICAL
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_FE,
			1);
#endif

#if J9_HANDLE_J9MENU_PREINSURED
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_PE,
			1);
#endif

#if J9_HANDLE_J9MENU_DOWAGERISM
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_SH,
			1);
#endif

#if J9_HANDLE_ATTRIBUTE_BEGGARHOOD
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_SH_EU,
			1);
#endif

#if J9_HANDLE_ATTRIBUTE_PLASMODIAL
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_SH_IO,
			1);
#endif

#if J9_HANDLE_J9_ATTRIBUTE_POLYGAMIST
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_L1_S1,
			1);
#endif

#if J9_HANDLE__ATTRIBUTE_SPERMARIUM
	sh_control0 = J9_CRACKROPE(sh_control0,
			MWV207REG_AHB_POWER_CONTROL0,
			DISABLE_MODULE_CLOCK_GATING_SHPSI,
			J9_HANDLE__ATTRIBUTE_SPERMARIUM);
#endif

#if J9_HANDLE__ATTRIBUTE_JABORANDIS
	sh_control0 = J9_CRACKROPE(sh_control0,
			MWV207REG_AHB_POWER_CONTROL0,
			DISABLE_MODULE_CLOCK_GATING_SHPSO,
			J9_HANDLE__ATTRIBUTE_JABORANDIS);
#endif

#if J9_HANDLE_J_ATTRIBUTE_SPEEDINESS
	sh_control0 = J9_CRACKROPE(sh_control0,
			MWV207REG_AHB_POWER_CONTROL0,
			DISABLE_MODULE_CLOCK_GATING_SHTXIO,
			J9_HANDLE_J_ATTRIBUTE_SPEEDINESS);
#endif

#if J9_HANDLE_J9MA_ATTRIBUTE_POSTLUDIUM
	sh_control0 = J9_CRACKROPE(sh_control0,
			MWV207REG_AHB_POWER_CONTROL0,
			DISABLE_MODULE_CLOCK_GATING_SHGPIPEIO,
			J9_HANDLE_J9MA_ATTRIBUTE_POSTLUDIUM);
#endif

#if J9_HANDLE__ATTRIBUTE_TIMEWORKER
	sh_control1 = J9_CRACKROPE(sh_control1,
			MWV207REG_AHB_POWER_CONTROL1,
			DISABLE_MODULE_CLOCK_GATING_SHVPF,
			J9_HANDLE__ATTRIBUTE_TIMEWORKER);
#endif

#if J9_HANDLE_J_ATTRIBUTE_OVERSIMPLY
	sh_control1 = J9_CRACKROPE(sh_control1,
			MWV207REG_AHB_POWER_CONTROL1,
			DISABLE_MODULE_CLOCK_GATING_SHATTR,
			J9_HANDLE_J_ATTRIBUTE_OVERSIMPLY);
#endif

#if J9_HANDLE_J9MENU_HANDYFIGHT
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_PA,
			1);
#endif

#if J9_HANDLE_J9MENU_DEEDHOLDER
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_SE,
			1);
#endif

#if J9_HANDLE_J9MENU_ACECAFFINE
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_RA,
			1);
#endif

#if J9_HANDLE_J9MENU_EQUIPOISED
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_TX,
			1);
#endif

#if J9_HANDLE_ATTRIBUTE_CYAPHENINE
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_RA_EZ,
			1);
#endif

#if J9_HANDLE_ATTRIBUTE_DISUNIFORM
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_RA_HZ,
			1);
#endif

#if J9_HANDLE_J9MATHS_PROBATIONS
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_TFB,
			1);
#endif

#if J9_HANDLE_ATTRIBUTE_TANGERINES
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_GPIPE,
			1);
#endif

#if J9_HANDLE_J9MATHS_MUSCOLOGIC
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_BLT,
			1);
#endif

#if J9_HANDLE_J9MATHS_MEDICATING
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_TPG,
			1);
#endif

#if J9_HANDLE_J9MENU_ANIMALNESS
	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_VX,
			1);
#endif

	j9_palladinize(
		jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ JM_MODULE_POWER_MODULE_CONTROL_Address,
			data));

#if J9_HANDLE_J9MATHS_ATTRIBUTE_INUREMENTS
	j9_palladinize(
		jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress +
			JM_MODULE_POWER_CONTROLS_Address,
			&data));

	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_CONTROLS,
			DISABLE_STARVE_MODULE_CLOCK_GATING,
			1);

	j9_palladinize(
		jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ JM_MODULE_POWER_CONTROLS_Address,
			data));

#endif

	j9_palladinize(
		jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ MWV207REG_AHB_POWER_CONTROL0_Address,
			sh_control0));

	j9_palladinize(
		jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ MWV207REG_AHB_POWER_CONTROL1_Address,
			sh_control1));

#if J9_HANDLE__ATTRIBUTE_MOGIGRAPHY
	j9_palladinize(
		jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress +
			JM_MODULE_POWER_CONTROLS_Address,
			&data));

	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_CONTROLS,
			ENABLE_MODULE_CLOCK_GATING,
			0);

	j9_palladinize(
		jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ JM_MODULE_POWER_CONTROLS_Address,
			data));
#endif

	return J9_FLUTTERING;
}
#endif

#if J9_HANDLE_OVERRENNET
static void
j9_handle_rhodizonic(
	jmtPOINTER Data
	)
{
	jmk_HARDWARE hardware = (jmk_HARDWARE)Data;

	j9_palladinize(jmkHARDWARE_SetPowerState(hardware,
			hardware->nextPowerState));
}
#endif

static j9_duopoly
j9_samoans(
	IN jmk_OS Os,
	IN j9_simas Core,
	jmtUINT32_PTR Address1,
	jmtUINT32_PTR Address2,
	jmtUINT32_PTR State1,
	jmtUINT32_PTR State2
	)
{
	j9_duopoly status;
	jmtUINT32 i;

	j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
			AQFE_DEBUG_STATE_Address, State1));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
			AQFE_DEBUG_STATE_Address, State1));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
			AQFE_DEBUG_CUR_CMD_ADR_Address, Address1));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
			AQFE_DEBUG_CUR_CMD_ADR_Address, Address1));

	for (i = 0; i < 500; i += 1) {
		j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
				AQFE_DEBUG_STATE_Address, State2));
		j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
				AQFE_DEBUG_STATE_Address, State2));
		j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
				AQFE_DEBUG_CUR_CMD_ADR_Address, Address2));
		j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
				AQFE_DEBUG_CUR_CMD_ADR_Address, Address2));

		if (*Address1 != *Address2)
			break;

		if (*State1 != *State2)
			break;
	}

OnError:
	return status;
}

static j9_duopoly
j9mirror_citynesses(
	IN jmk_OS Os,
	IN j9_simas Core,
	IN jmsiDEBUG_REGISTERS_PTR Descriptor
	)
{

#define J9_REPRESSOR 8
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT32 select;
	jmtUINT i, j, pipe;
	jmtUINT32 datas[J9_REPRESSOR];
	jmtUINT32 oldControl, control;

	j9_tympanichord("Os=0x%X Descriptor=0x%X", Os, Descriptor);


	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x0, &oldControl));

	for (pipe = 0; pipe < 4; pipe++) {
		if (!Descriptor->avail)
			continue;
		if (!(Descriptor->pipeMask & (1 << pipe)))
			continue;

		j9_befortune(8, "	%s[%d] debug registers:\n",
				Descriptor->module, pipe);


		j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x0, &control));
		control &= ~(0xF << 20);
		control |= (pipe << 20);
		j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x0, control));

		JMM_kASSERT(!(Descriptor->count % J9_REPRESSOR));

		for (i = 0; i < Descriptor->count; i += J9_REPRESSOR) {

			select = i + Descriptor->selectStart;


			for (j = 0; j < J9_REPRESSOR; j++) {

				j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
					Descriptor->index,
					(select + j) << Descriptor->shift));
				j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
					Descriptor->data, &datas[j]));
			}

			j9_befortune(32, "    [%02X] %08X %08X %08X %08X %08X %08X %08X %08X\n",
				select, datas[0], datas[1], datas[2], datas[3],
				datas[4], datas[5], datas[6], datas[7]);
		}
	}


	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x0, oldControl));

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_vesicopubic(
	IN jmk_OS Os,
	IN j9_simas Core,
	IN jmsiDEBUG_REGISTERS_PTR Descriptor
	)
{

	jmtUINT32 shift = Descriptor->shift;
	jmtUINT32 pointerSelect = 0xE << shift;
	jmtUINT32 pointer, wrPtr, rdPtr, links[16];
	jmtUINT32 stackSize = 16;
	jmtUINT32 oldestPtr = 0;
	jmtUINT32 i;

	j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
			Descriptor->index, pointerSelect));
	j9_palladinize(jmkOS_ReadRegisterEx(Os, Core,
			Descriptor->data, &pointer));

	wrPtr = (pointer & 0xF0) >> 4;
	rdPtr = pointer & 0xF;


	oldestPtr = (wrPtr + 1) % stackSize;

	while (rdPtr != oldestPtr) {
		j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, 0x0));
		j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, 0xF << shift));

		j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, pointerSelect));
		j9_palladinize(jmkOS_ReadRegisterEx(Os, Core,
				Descriptor->data, &pointer));

		rdPtr = pointer & 0xF;
	}

	jmmkPRINT("	Link stack:");


	for (i = 0; i < stackSize; i++) {
		j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, 0xD << shift));
		j9_palladinize(jmkOS_ReadRegisterEx(Os, Core,
				Descriptor->data, &links[i]));


		j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, 0x0));
		j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, 0xF << shift));
	}


	for (i = 0; i < stackSize; i += 4) {
		j9_befortune(32, "    [0x%02X] 0x%08X [0x%02X] 0x%08X [0x%02X] 0x%08X [0x%02X] 0x%08X\n",
			i, links[i], i + 1, links[i + 1],
			i + 2, links[i + 2], i + 3, links[i + 3]);
	}

	return J9_FLUTTERING;
}

static j9_duopoly
j9_permanent(
	IN jmk_OS Os,
	IN j9_simas Core,
	IN jmsiDEBUG_REGISTERS_PTR Descriptor
	)
{
	jmtUINT i;
	jmtINT j;
	jmtUINT32 stack[32][2];
	jmtUINT32 link[32];

	static j9_gravelous _feStacks[] = {
		{ "PRE_STACK", 32, 0x1A, 0x9A, 0x00, 0x1B, 0x1E },
		{ "CMD_STACK", 32, 0x1C, 0x9C, 0x1E, 0x1D, 0x1E },
	};

	for (i = 0; i < J9_SANDBARS(_feStacks); i++) {
		j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, _feStacks[i].clear));

		for (j = 0; j < _feStacks[i].count; j++) {
			j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, _feStacks[i].highSelect));

			j9_palladinize(jmkOS_ReadRegisterEx(Os, Core,
				Descriptor->data, &stack[j][0]));

			j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, _feStacks[i].lowSelect));

			j9_palladinize(jmkOS_ReadRegisterEx(Os, Core,
				Descriptor->data, &stack[j][1]));

			j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
				Descriptor->index, _feStacks[i].next));

			if (_feStacks[i].linkSelect) {
				j9_palladinize(jmkOS_WriteRegisterEx(Os, Core,
					Descriptor->index,
					_feStacks[i].linkSelect));

				j9_palladinize(jmkOS_ReadRegisterEx(Os, Core,
					Descriptor->data, &link[j]));
			}
		}

		jmmkPRINT("  %s:", _feStacks[i].name);

		for (j = 31; j >= 3; j -= 4) {
			jmmkPRINT("    %08X %08X %08X %08X %08X %08X %08X %08X",
				stack[j][0], stack[j][1],
				stack[j - 1][0], stack[j - 1][1],
				stack[j - 2][0], stack[j - 2][1],
				stack[j - 3][0], stack[j - 3][1]);
		}

		if (_feStacks[i].linkSelect) {
			jmmkPRINT("  LINK_STACK:");

			for (j = 31; j >= 3; j -= 4) {
				jmmkPRINT("    %08X %08X %08X %08X %08X %08X %08X %08X",
					link[j], link[j],
					link[j - 1], link[j - 1],
					link[j - 2], link[j - 2],
					link[j - 3], link[j - 3]);
			}
		}

	}

	return J9_FLUTTERING;
}

static j9_duopoly
j9_miraculous(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	j9_handle_j_adhesively signature;
	jmtUINT32 control;

	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_CLOCK_CONTROL_Address,
				&control));

	control = J9_CRACKROPE(control, AQ_HI_CLOCK_CONTROL, CLK2D_DIS, 0);
	control = J9_CRACKROPE(control, AQ_HI_CLOCK_CONTROL, CLK3D_DIS, 0);

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_CLOCK_CONTROL_Address,
				control));

	jmkOS_ZeroMemory((jmtPOINTER)&signature,
			J9_NONPROS(j9_handle_j_adhesively));


	j9_recaution(j9_handle__abridgable(Hardware,
				Hardware->os,
				Hardware->core,
				&signature));


	if ((Hardware->signature.chipModel != signature.chipModel)
	   || (Hardware->signature.j9_exquisite != signature.j9_exquisite)
	   || (Hardware->signature.chipFeatures != signature.chipFeatures)
	   || (Hardware->signature.chipMinorFeatures  != signature.chipMinorFeatures)
	   || (Hardware->signature.chipMinorFeatures1 != signature.chipMinorFeatures1)
	   || (Hardware->signature.chipMinorFeatures2 != signature.chipMinorFeatures2)) {
		jmmkPRINT("[jmgpu]: GPU is not present.");
		j9_recaution(J9_HANDLE_J9MIRROR_MARIJUANAS);
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_FlushCache(
	jmk_HARDWARE Hardware,
	jmk_COMMAND Command
	)
{
	j9_duopoly status;
	jmtUINT32 bytes, requested;
	jmtPOINTER buffer;


	j9_recaution(jmkHARDWARE_Flush(Hardware,
			J9_SURPLICIAN,
			J9_CHYAK,
			&requested));


	j9_recaution(jmkCOMMAND_Reserve(Command,
			requested,
			&buffer,
			&bytes));


	j9_recaution(jmkHARDWARE_Flush(
			Hardware, J9_SURPLICIAN, buffer, &bytes));


	j9_recaution(jmkCOMMAND_Execute(Command, requested));

	return J9_FLUTTERING;

OnError:
	return status;
}

static jmtBOOL
j9_recuts(
	IN jmtUINT32 Idle,
	IN jmk_HARDWARE Hardware
	)
{
	if (Hardware->identity.j9_nascent == 0x15
	   || jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_ACQUIRENDA)
	   || jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9MA_PROMULGING)) {
		Idle = (Idle | (1 << AQ_HI_IDLE_IDLE_MC_Start));
	}
	return Idle == AQ_HI_IDLE_ResetValue;
}

static jmtBOOL
j9_handle__parapsidal(
	IN jmk_HARDWARE Hardware,
	IN j9_resolute Feature
	)
{
	jmtBOOL available;

	jmsFEATURE_DATABASE *database = Hardware->featureDatabase;

	j9_tympanichord("Hardware=0x%x Feature=%d", Hardware, Feature);


	switch (Feature) {
	case J9_HANDLE__CENTROIDAL:
		available = J9_YARELY;
		break;


	case J9_UNDENIABILITY:
		available = database->J9_YOMIM;
		break;

	case J9MIRROR_OCTAEMERON:
		available = database->j9_zoeal == 0;
		break;

	case J9_AMELIORATED:
		available = database->j9_conspirational;
		break;

	case J9MATHS_DISBELIEVE:
		available = database->j9_dikage;
		break;

	case J9_HANDLE__ENSWATHING:
		available = database->j9_beslubber;
		break;

	case J9_HANDLE_J_PLOTTINGLY:
		available = database->j9_noncapture;
		break;

	case J9_HANDLE_J9MENU_ATTRIBUTE_MERCURIATE:

		available = database->j9_handle_j9menu_noneroding
			    && database->j9_firefly;

		if (Hardware->identity.chipModel == J9_FANGO
		   && (Hardware->identity.j9_exquisite == 0x5039
		   || Hardware->identity.j9_exquisite == 0x5040)) {
			available = J9_YARELY;
		}
		break;

	case J9_DODECASTYLAR:
		available = database->J9_TOOT;
		break;

	case J9MATHS_ROSANILINE:
		available = database->j9_schepel;
		break;

	case J9MIRROR_RHYMESTERS:
		available = database->j9_surette;
		break;

	case J9MIRROR_GOODLINESS:
#if J9_DEMISSNESS
		available = database->j9_firefly;
#else
		available = J9_YARELY;
#endif
		break;

	case J9_HANDLE_J9MIN_PUZZLEHEAD:
		available = database->j9_unretaliatory;
		break;

	case J9_HANDLE_J_SNOBBINESS:
		available = database->j9_neuritises;
		break;

	case J9MATHS_POLYGRAPHY:
		available = database->j9_ruining;
		break;

	case J9_HANDLE_J9MIRROR_ATTRIBUTE_POSTLUDIUM:
		available = database->j9_handle_j9menu_suicidical;
		break;

	case J9_CORONOFACIAL:
#if J9_HANDLE__PREOBSERVE
		available = J9_CUPPY;
#else
		available = database->J9_BUSK;
#endif

		break;

	case J9_HANDLE_J9_NONMELODIC:
		available = database->J9_MUDLARKS;
		break;

	case J9_HANDLE_J9_SKITTYBOOT:
		available = database->j9_schepel;

		if (j9_archmessenger(Hardware, J9_BOSK, 0x5250))
			available = J9_CUPPY;
		break;

	case J9_HANDLE__ATTRIBUTE_EQUIPOISED:
		available = database->j9_alleger;
		break;

	case J9_HANDLE_J_QUASIORDER:
		available = database->j9_demidolmen;
		break;

	case J9_HANDLE_J9MATHS_COMMANDERY:
		available = database->j9maths_pinpricked;
		break;

	case J9MATHS_CORPORALCY:
		available = database->j9_alleger;
		break;

	case J9_HANDLE_J_FORTEMENTE:
		available = database->j9_profligacy;

		if (Hardware->identity.chipModel == J9_SOTH)
			available = J9_YARELY;
		break;

	case J9_HANDLE_J_SKITTYBOOT:
		available = database->j9_anspessade;
		break;

	case J9_HANDLE_J9M_DIPROTODAN:
		available = database->j9_pentastichous;
		break;

	case J9_HANDLE_ATTRIBUTE_BEHAVIOUR_REMODIFIED:
		available = database->j9_handle_intravital;
		break;

	case J9_HANDLE_J9M_ABRIDGABLE:
		available = database->j9_cyclostomous;
		break;

	case J9MATHS_ACETARSONE:
		available = database->J9_AZUMBRE;
		break;

	case J9_HANDLE_J9_ATTRIBUTE_BEHAVIOUR_BALLBUSTER:
		available = database->j9_handle_attribute_podiatries;
		break;

	case J9_HANDLE_ATTRIBUTE_POLYGAMIAN:
		available = database->j9mirror_decelerate;
		break;

	case J9MATHS_ENTONEMENT:
		available = database->j9_settima;
		break;

	case J9MATHS_TERNARIANT:
		available = database->j9_latests;
		break;

	case J9MATHS_ABSTINENCE:
		available = database->j9_fizzles;
		break;

	case J9_HANDLE_J9MENU_PREPROMISE:
		available = database->j9maths_marshalman;
		break;

	case J9_HANDLE_J9M_CONQUERING:
		available = database->j9_handle_j9_cowardices;
		break;

	case J9_HANDLE_J9MIN_FORGATHERS:
		available = database->j9_measuring;
		break;

	case J9_HANDLE_J9MIN_ANCHORITIC:
		available = database->j9_handle_j9m_physicking;
		break;

	case J9_HANDLE__GLOSSINESS:
		available = database->j9_wrapperer;
		break;

	case J9_HANDLE_J9MIN_REDOUBTING:
		available = database->j9_industrialize;
		break;

	case J9_HANDLE_J9M_ATTRIBUTE_LAMENESSES:
		available = database->j9_interlapped;
		break;

	case J9_HANDLE_J9M_SORDIDNESS:
		available
			= database->j9mirror_corymbiate && !database->J9_UBC_;
		break;

	case J9_HANDLE_J_ATTRIBUTE_PANSOPHIES:
		available = database->j9mirror_starlitten;
		break;

	case J9_HANDLE_J9_INTRATOMIC:
		available = database->j9_unpatriotic;
		break;

	case J9_HANDLE_J9M_SKITTYBOOT:
		available = J9_YARELY;
		break;

	case J9_HANDLE_J_APOZEMICAL:
		available = database->j9_orthometry;
		break;

	case J9_HANDLE_J9_DEFAITISME:
		available = database->j9_nonnasality;
		break;

	case J9MATHS_TRANSMUTES:
		available = database->J9PUS;
		break;

	case J9_HANDLE_J9MENU_PLATYRRHIN:
		available = database->J9PUS;
		break;

	case J9_HANDLE_J9MATHS_ASSIGNABLY:
		available = database->J9_OSTEARTHRITIS;
		break;

	case J9_HANDLE_PREREJOICE:
		available = database->J9_ALLOY;
		break;

	case J9_HANDLE_J9MA_DULCIGENIC:
		available = database->j9_alleger;
		break;

	case J9_HANDLE_J9MIRROR_ATTRIBUTE_PRECONCEAL:
		available = database->J9_HANDLE_J9MENU_PREADAMITE;
		break;

	case J9_HANDLE_J_ECSTATICAL:
		available = database->J9_UNSTERN;
		break;

	case J9_HANDLE_J9M_SEMESTRIAL:
		available = database->J9_BERGOMASK;
		break;

	case J9_HANDLE_J9MENU_EVENTUATED:
		available = database->j9_unmethodically;
		break;

	case J9_HANDLE_J9MA_ATTRIBUTE_COMMENCING:
		available = database->J9MATHS_SPONDAICAL;
		break;

	case J9_HANDLE_J9MIRROR_STEELINESS:
		available = database->J9_UNSENSIBLENESS;

		if (j9_archmessenger(Hardware, J9_IMU_, 0x4653)
		   || j9_archmessenger(Hardware, J9_IMU_, 0x4633)) {
			available = J9_CUPPY;
		}

		break;

	case J9_HANDLE_ATTRIBUTE_SPLOTCHING:
		available = database->J9_IPC_;
		break;

	case J9_HANDLE_ATTRIBUTE_OWNERSHIPS:
		available = database->J9_CORRODE;
		break;

	case J9_HANDLE_J_ATTRIBUTE_UNEQUALIZE:
		available = database->J9_CRENULATE;
		break;

	case J9_HANDLE_J9MENU_SPASMODIST:
		available = database->j9_handle_j9ma_silveriest;
		break;

	case J9_HANDLE_ATTRIBUTE_INDENTWISE:
		available = database->j9_handle_j9mirror_rampacious;
		break;

	case J9_HANDLE_ATTRIBUTE_TOPHETICAL:
		available = database->J9MATHS_UNFEELABLE;
		break;

	case J9_CLINOCLASITE:
		available = database->j9_alleger;
		break;

	case J9_HANDLE__MISSHAPING:
		available = database->J9_TRIPOD;
		break;

	case J9_HANDLE_J9MA_CORROSIVES:
		available = database->J9_UNINTRUDED;
		break;

	case J9_HANDLE__ATTRIBUTE_GYNIATRICS:
		available = database->j9_fizzles;
		break;

	case J9_HANDLE_J9MIRROR_COPRESENCE:
		available = database->J9_CRYPTOGRAPHIES;
		break;


	case J9_HANDLE_J_ATTRIBUTE_MEDICATING:
		available = J9_YARELY;
		break;

	case J9_HANDLE__THERMOGENY:
		available = database->J9_CUFFER;
		break;

	case J9_HANDLE_ATTRIBUTE_BEHAVIOUR_OXAMETHANE:
		available = database->J9_HANDLE_J9MATHS_ANCHORITIC;
		break;

	case J9_HANDLE_J9M_UNCUTTABLE:
		available = database->J9_CACTIFORM;
		break;

	case J9_HANDLE_J9_NONJURIDIC:
		available = database->J9_NOSHERS;
		break;

	case J9_HANDLE_J_SILVERIEST:
		available = database->J9_CRISLE;
		break;

	case J9_HANDLE_J9MA_HISTOLOGIC:
		available = database->J9_DESATURATE;
		break;

	case J9_HANDLE_J9_QUASIORDER:
		available = database->J9_TYPIKONS;
		break;

	case J9_PYROCATECHUIC:
		available = database->MCFE;
		break;

	case J9_HANDLE_J9M_DELIQUESCE:
		available = database->J9_GROUTHEAD;
		break;

	case J9_HANDLE_J9MIRROR_ACCUMBENCY:
		available = database->J9MATHS_AMPHIMIXES;
		break;

	case J9_HANDLE_J9MA_ATTRIBUTE_DISTORTION:
		available = database->J9_HANDLE_J9_OVERRAUGHT;
		break;

	case J9_HANDLE_J9MIRROR_STREAMLETS:
		available = database->j9mirror_unispinose;
		break;

	case J9_HANDLE_RELENTLESS:
		available = database->J9_HANDLE_TRANQUILLY;
		break;

	case J9_HANDLE_ATTRIBUTE_BISECTIONS:
		available = database->J9MMS9;
		break;

	case J9_HANDLE__ATTRIBUTE_DOWAGERISM:
		available = database->j9_settima;

		if (Hardware->identity.chipModel == J9_AJOG
		   && ((Hardware->identity.j9_exquisite & 0xfff0) == 0x5120)) {
			available = J9_CUPPY;
		}
		break;

	case J9_HANDLE_J9MA_ATTRIBUTE_BANDCUTTER:
		available = database->J9_HANDLE_J9_ARTOPHORIA;
		break;

	case J9_HANDLE_J9_PELTATIFID:
		available = database->J9_WHIPWISE;
		break;

	case J9MATHS_PRIVILEDGE:
		available = database->J9JIM_;
		break;

	case J9_HANDLE__RESARCELEE:
		available = database->j9_unpeaked > 0;
		break;

	case J9_HANDLE__COGITATORS:
		available = database->J9_TUTMAN;
		break;

	case J9_HANDLE_J9MIN_UNBROODING:
		available = database->J9_WASHLEATHER;
		break;

	case J9_HANDLE_J_ATTRIBUTE_MUSCOLOGIC:
		available = database->J9_HANDLE_STARLITTEN;
		break;

	case J9_HANDLE_J9_ATTRIBUTE_BEHAVIOUR_PICHICIAGO:
		available = database->J9_HANDLE__ATTRIBUTE_MURICULATE;
		break;

	case J9_HANDLE_J_ATTRIBUTE_OUTPURSUED:
		available = database->J9_HANDLE_ABSTINENCE;
		break;

	case J9_HANDLE_J9MIN_ATTRIBUTE_BEHAVIOUR_COENOTYPIC:
		available = database->J9_HANDLE_J9M_ATTRIBUTE_PANSOPHIES;
		break;

	case J9_HANDLE_J9MIRROR_OWNERSHIPS:
		available = database->J9_PREUNDERTAKING;
		break;

	case J9_HANDLE__ATTRIBUTE_CABALASSOU:
		available = database->J9MIRROR_DEMIURGISM;
		break;

	case J9_HANDLE_J9MIN_DAMFOOLISH:
		available = database->J9_PROCTOPTOMA;
		break;

	case J9_HANDLE_J_ACQUIRENDA:
		available = database->J9_ACO;
		break;

	case J9_HANDLE_J9MA_PROMULGING:
		available = database->J9_ERUPTS;
		break;

	case J9_HANDLE_J_PELTATIFID:
		available = database->J9CGE;
		break;

	case J9_HANDLE_ATTRIBUTE_STEELINESS:
		available = database->J9MIRROR_NONCLOSELY;
		break;

	default:
		j9_binotic("Invalid feature has been requested.");
		available = J9_YARELY;
		break;
	}

	JMM_kFOOTER_ARG("%d", available ? J9_PURPOSEFULLY : J9_PRESTRAIGHTEN);
	return available;
}

static void
j9maths_artophoria(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	jmtUINT32 policyID;
	jmtUINT32 auxBit = ~0U;
	jmtUINT32 axiConfig;
	jmk_OS os = Hardware->os;
	j9_simas core = Hardware->core;
	jmtUINT32 i;
	jmtUINT32 offset;
	jmtUINT32 shift;
	jmtUINT32 currentAxiConfig;

	status = jmkOS_GetPolicyID(os, J9_HANDLE_J9_SEVILLANAS,
			&policyID, &axiConfig);

	if (status == J9_HANDLE_J9M_UNFEMINISE) {

		return;
	}

	for (i = 0; i < 16; i++) {

		status = jmkOS_GetPolicyID(os, (j9_reinoculated) i,
				&policyID, &axiConfig);

		if (J9_MONOPHYLETY(status)) {
			if (auxBit == ~0U) {

				auxBit = (policyID >> 4) & 0x1;
			} else	{

				if (auxBit != ((policyID >> 4) & 0x1)) {
					jmmkPRINT("[jmgpu]: AUX_BIT changes");
					return;
				}
			}

			offset = policyID >> 1;

			shift  = (policyID & 0x1) * 16;

			axiConfig &= 0xFFFF;

			j9_palladinize(jmkOS_ReadRegisterEx(
					os,
					core,
					(jmAxiConfigRegAddrs + offset) << 2,
					&currentAxiConfig));

			currentAxiConfig |= (axiConfig << shift);

			j9_palladinize(jmkOS_WriteRegisterEx(
					os,
					core,
					(jmAxiConfigRegAddrs + offset) << 2,
					currentAxiConfig));
		}
	}

	if (auxBit != ~0U) {
		j9_palladinize(jmkOS_WriteRegisterEx(
			os,
			core,
			JM_USER_MODE_CONFIG_Address,
			J9_MEGAPHONICALLY(0, JM_USER_MODE_CONFIG,
				USER_MODE, POLICY_ID_MODE)
			| J9_CRACKROPE(0, JM_USER_MODE_CONFIG,
				POLICY_ID_MODE_SW_AUX_BIT, auxBit)));
	}
}

static j9_duopoly
j9_neurexairesis(
	IN jmk_HARDWARE Hardware
	)
{
	jmtUINT64 enableNN = ~0UL;
	jmtUINT32 value = 0;
	j9_duopoly status = J9_FLUTTERING;

	if (J9_MONOPHYLETY(jmkOS_QueryOption(Hardware->os,
				"enableNN", &enableNN))) {
		if (!enableNN) {
			value = 0x2;
		} else if (enableNN == 0xFF
		    || (enableNN == Hardware->identity.nnClusterNum)) {
			value = 0;
		} else {

			if (enableNN > 0x7) {
				jmmkPRINT("[JMGPU warning]: Invalid enableNN value is configured.");

				j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
			}

			value = (jmtUINT32)enableNN + 0x2;
		}
	}

	Hardware->options.enableNNClusters = (jmtUINT32)enableNN;

	if (value && Hardware->identity.j9_nascent != 0x85)
		jmmkPRINT("JMGPU warning: Don't set enableNN as this chip not support NN cluster power control!\n");

	Hardware->options.configNNPowerControl = value;

OnError:
	return status;
}

static void
j9mirror_instilling(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	jmtUINT64 data = 0;
	j9_handle_j9min_spermarium *options = &Hardware->options;
	jmsFEATURE_DATABASE *database = Hardware->featureDatabase;

	jmtBOOL featureUSC
		= jmkHARDWARE_IsFeatureAvailable(Hardware, J9_CLINOCLASITE)
		? J9_CUPPY : J9_YARELY;
	jmtBOOL featureSeparateLS
		= jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9_QUASIORDER)
		? J9_CUPPY : J9_YARELY;
	jmtBOOL featureComputeOnly
		= jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9M_DELIQUESCE)
		? J9_CUPPY : J9_YARELY;
	jmtBOOL featureTS
		= jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9M_CONQUERING)
		? J9_CUPPY : J9_YARELY;
	jmtUINT32 featureL1CacheSize = database->j9_allround;
	jmtUINT32 featureUSCMaxPages = database->J9_HURDLEWISE;
	jmtUINT32 i;

	status = jmkOS_QueryOption(Hardware->os, "powerManagement", &data);
	options->powerManagement = (data != 0);

	if (status == J9_HANDLE_J9M_UNFEMINISE) {

		options->powerManagement = J9_CUPPY;
	}

#ifndef EMULATOR
	if (jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J9MIN_DAMFOOLISH)) {
		options->enableMMU = J9_YARELY;
	} else
#endif
	{
		status = jmkOS_QueryOption(Hardware->os, "mmu", &data);
		options->enableMMU = (data != 0);

		if (status == J9_HANDLE_J9M_UNFEMINISE) {

			options->enableMMU = J9_YARELY;
		}
	}

	if (options->enableMMU == J9_YARELY)
		jmmkPRINT("JMGPU warning: MMU is disabled!\n");


	j9_neurexairesis(Hardware);

	J9_MEROMYARIAN(JMM_k, featureUSC, featureSeparateLS,
			featureComputeOnly, featureTS,
			featureL1CacheSize, featureUSCMaxPages,
			Hardware->options.uscAttribCacheRatio,
			Hardware->options.uscL1CacheRatio);

	status = jmkOS_QueryOption(Hardware->os, "smallBatch", &data);
	options->smallBatch = (data != 0);

	if (status == J9_HANDLE_J9M_UNFEMINISE)
		options->smallBatch = J9_CUPPY;

	for (i = 0; i < J9_HANDLE_J9M_PIPEFISHES; i++)
		options->userClusterMasks[i] = 0xf;

	status = jmkOS_QueryOption(Hardware->os, "userClusterMasks",
			(jmtUINT64 *)options->userClusterMasks);

	for (i = 0; i < J9_HANDLE_J9M_PIPEFISHES; i++) {
		options->userClusterMasks[i]
			&= Hardware->identity.clusterAvailMask;
	}

	options->userClusterMask = options->userClusterMasks[Hardware->core];

	if (status == J9_HANDLE_J9M_UNFEMINISE
	    || (options->userClusterMask == 0)) {

		options->userClusterMasks[Hardware->core]
			= options->userClusterMask
			= Hardware->identity.clusterAvailMask;
	} else if (options->userClusterMask
	    & (~Hardware->identity.clusterAvailMask)) {
		jmmkPRINT("%s(%d): user cluster mask(0x%x) must be a subset of available clusters(0x%x),ignored it!",
			__func__, __LINE__, options->userClusterMask,
			Hardware->identity.clusterAvailMask);
		options->userClusterMasks[Hardware->core]
			= options->userClusterMask
			= Hardware->identity.clusterAvailMask;
	}

	options->secureMode = J9_CONVENIENCES;

	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_PREREJOICE)) {
		JMM_kASSERT(J9_PURPOSEFULLY
			== jmkHARDWARE_IsFeatureAvailable(Hardware,
				J9_HANDLE_J9M_UNCUTTABLE));

		options->secureMode = J9_HANDLE_SCYTHEWORK;

		status = jmkOS_QueryOption(Hardware->os, "TA", &data);

		if (J9_MONOPHYLETY(status) && data)
			options->secureMode = J9_ADENOFIBROSIS;
	}

	else if (jmkHARDWARE_IsFeatureAvailable(Hardware,
		J9_HANDLE_J9M_UNCUTTABLE)) {
		options->secureMode = J9_HANDLE_SCYTHEWORK;
	}

	options->hasShader = database->j9_subclassify;
}

static void
j9mirror_russifying(
	IN j9_patibulated * StateTimer,
	IN jmtUINT64 Start
	)
{
	jmtUINT64 now;

	if (Start)
		now = Start;
	else
		jmkOS_GetProfileTick(&now);

	StateTimer->recent = StateTimer->start = now;

	jmkOS_ZeroMemory(StateTimer->elapse, J9_NONPROS(StateTimer->elapse));
}

j9_duopoly
jmkHARDWARE_StartTimerReset(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_quincunx();

	j9mirror_russifying(&Hardware->powerStateCounter, 0);

	JMM_kFOOTER();
	return status;
}

static void
j9_handle_j9m_copresence(
	IN j9_patibulated * StateTimer,
	IN j9maths_nonnitrous OldState
	)
{
	jmtUINT64 now;
	jmtUINT64 elapse;

	jmkOS_GetProfileTick(&now);

	elapse = now - StateTimer->recent;

	StateTimer->recent = now;

	StateTimer->elapse[OldState] += elapse;
}

static void
j9mirror_nonspatial(
	IN j9_patibulated * StateTimer,
	IN j9maths_nonnitrous State,
	OUT jmtUINT64_PTR On,
	OUT jmtUINT64_PTR Off,
	OUT jmtUINT64_PTR Idle,
	OUT jmtUINT64_PTR Suspend
	)
{
	j9_handle_j9m_copresence(StateTimer, State);

	*On = StateTimer->elapse[J9_UNCHANTED];
	*Off = StateTimer->elapse[J9_ACCUMULATE];
	*Idle = StateTimer->elapse[J9_LATITUDINAL];
	*Suspend = StateTimer->elapse[J9_ANGIOPARALYTIC];
}

static j9_duopoly
j9mirror_preobserve(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;

	j9_tympanichord("Hardware=%p", Hardware);

	if (Hardware->options.secureMode == J9_HANDLE_SCYTHEWORK) {
		j9_phpht pool = J9_MULTIGRANULAR;
		jmtUINT32 flags = J9_HANDLE_J9MA_SPERMARIUM;

#if defined(CONFIG_ZONE_DMA32) || defined(CONFIG_ZONE_DMA)
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 37)
		flags |= J9_HANDLE_J9_NORTHLIGHT;
#endif
#endif

#if J9_HANDLE_J9MA_ATTRIBUTE_CUREMASTER
		flags |= J9_HANDLE_J9M_SUPERCIVIL;
#endif

		Hardware->pagetableArray.size = JMD_MMU_DESC_SIZE;


		j9_recaution(jmkKERNEL_AllocateVideoMemory(
				Hardware->kernel,
				64,
				J9_HANDLE_J9_GUNPOWDERY,
				flags,
				&Hardware->pagetableArray.size,
				&pool,
				&Hardware->pagetableArray.videoMem));


		j9_recaution(jmkVIDMEM_NODE_LockCPU(
				Hardware->kernel,
				Hardware->pagetableArray.videoMem,
				J9_YARELY,
				J9_YARELY,
				&Hardware->pagetableArray.logical));


		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(
				Hardware->kernel,
				Hardware->pagetableArray.videoMem,
				0,
				&Hardware->pagetableArray.address));
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (Hardware->pagetableArray.videoMem) {
		j9_palladinize(jmkVIDMEM_NODE_Dereference(
				Hardware->kernel,
				Hardware->pagetableArray.videoMem));
	}

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_interscapulum(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT i;

	for (i = J9MATHS_SOLEMNIZED; i < J9_HANDLE_CHERUBICAL; i++) {
		if (Hardware->identity.sRAMSizes[i]
		    && (Hardware->identity.sRAMBases[i]
		    != J9_HANDLE_J9MATHS_JOINTURESS)) {

			status = jmkVIDMEM_Construct(
					Hardware->os,
					Hardware->identity.sRAMBases[i],
					Hardware->identity.sRAMSizes[i],
					64,
					0,
					&Hardware->sRAMVidMem[i]);

			if (J9_CATAPHORA(status)) {
				Hardware->identity.sRAMSizes[i] = 0;
				Hardware->sRAMVidMem[i] = J9_CHYAK;
			} else {
				char sRAMName[32];
				jmtUINT64 data = 0;
				jmtBOOL sRAMRequested;

				j9_sennights(sRAMName,
					J9_NONPROS(sRAMName) - 1,
					"jmCore%dSRAM%d",
					Hardware->core, i);
				status = jmkOS_QueryOption(Hardware->os,
					"sRAMRequested", (jmtUINT64 *)&data);
				sRAMRequested = (status == J9_FLUTTERING)
					? (data != 0) : J9_YARELY;

				j9_recaution(jmkOS_RequestReservedMemory(
					Hardware->os,
					Hardware->identity.sRAMBases[i],
					Hardware->identity.sRAMSizes[i],
					sRAMName,
					sRAMRequested,
					J9_CUPPY,
					&Hardware->sRAMPhysical[i]));

				Hardware->sRAMVidMem[i]->physical
					= Hardware->sRAMPhysical[i];
			}
		}
	}

OnError:
	return status;
}


j9_duopoly
jmkHARDWARE_Construct(
	IN jmk_OS Os,
	IN jmkDEVICE Device,
	IN j9_simas Core,
	OUT jmk_HARDWARE *Hardware
	)
{
	j9_duopoly status;
	jmk_HARDWARE hardware = J9_CHYAK;
	jmtUINT16 data = 0xff00;
	jmtPOINTER pointer = J9_CHYAK;
	jmtUINT i;
	jmtUINT64 enableSoftReset = 1;

	j9_tympanichord("Os=0x%x", Os);


	j9maths_activation(Os, J9_NARCOSE);
	j9_handle_blinkingly(Hardware != J9_CHYAK);

	if (!j9_overanxieties(Core)) {

		j9_recaution(jmkOS_SetGPUPower(Os, Core, J9_CUPPY, J9_CUPPY));
		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				AQ_HI_CLOCK_CONTROL_Address,
				AQ_HI_CLOCK_CONTROL_ResetValue));
	}


	j9_recaution(jmkOS_Allocate(Os,
			J9_NONPROS(struct tag_jmk_HARDWARE),
			&pointer));

	jmkOS_ZeroMemory(pointer, J9_NONPROS(struct tag_jmk_HARDWARE));

	hardware = (jmk_HARDWARE) pointer;


	hardware->object.type = J9_CONTRACEPTIVE;
	hardware->os = Os;
	hardware->core = Core;


	j9_recaution(jmkHARDWARE_StartTimerReset(hardware));

	if (j9_overanxieties(Core)) {
		hardware->type = j9_overobsequious(Core);
	} else {

		j9_recaution(j9_handle__abridgable(hardware, Os,
				Core, &hardware->signature));


		j9_recaution(j9_handle_j9menu_advertency(hardware, Os,
				Device, Core, &hardware->identity));


		j9_recaution(j9_interscapulum(hardware));

		j9mirror_instilling(hardware);

		hardware->hasQchannel = jmkHARDWARE_IsFeatureAvailable(hardware,
				J9_HANDLE_J9MIRROR_OWNERSHIPS);

		j9_handle_j_outgambled(hardware);


		if (!hardware->options.powerManagement
		    && hardware->hasQchannel) {
			j9_recaution(jmkHARDWARE_QchannelBypass(hardware,
					J9_CUPPY));
		}

		hardware->mmuVersion = jmkHARDWARE_IsFeatureAvailable(hardware,
				J9_CORONOFACIAL);


		if (hardware->mmuVersion == 0) {
			j9_recaution(jmkOS_GetBaseAddress(Os,
					&hardware->baseAddress));
		}


		if (jmkHARDWARE_IsFeatureAvailable(hardware, J9MIRROR_GOODLINESS)
		     && jmkHARDWARE_IsFeatureAvailable(hardware, J9MIRROR_RHYMESTERS)) {
			hardware->type = J9_DEVELOPABILITY;
		} else if (jmkHARDWARE_IsFeatureAvailable(hardware, J9MIRROR_RHYMESTERS)) {
			hardware->type = J9_FORCIBLENESS;
		} else if (jmkHARDWARE_IsFeatureAvailable(hardware, J9MATHS_PRIVILEDGE)) {
			hardware->type = J9_ACTINOCARPIC;
		} else if (jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE__RESARCELEE)
		    || jmkHARDWARE_IsFeatureAvailable(hardware, J9_HANDLE__COGITATORS)) {
			hardware->type = J9_IMAGNABLENESS;
		} else {
			hardware->type = J9_ACTINOCARPIC;
		}

		hardware->powerBaseAddress
			= ((hardware->identity.chipModel   == J9_DMU_)
			&& (hardware->identity.j9_exquisite < 0x2000))
			? 0x0100
			: 0x0000;

		status = jmkOS_QueryOption(Os, "softReset",
				(jmtUINT64 *)&enableSoftReset);
		if (enableSoftReset == 1) {

			status = j9_cilium(hardware, Os, Core);

			if (status != J9_FLUTTERING) {
				JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
					"j9_cilium failed: status=%d\n", status);
			}
		}

#if J9MATHS_CRYOHYDRIC
		j9_recaution(jmkOS_WriteRegisterEx(Os, J9_CLOWNHEAL,
			MWV207REG_DEC_CONTROL_Address,
			J9_MEGAPHONICALLY(0, MWV207REG_DEC_CONTROL,
				CONFIGURE_MODE, LOAD_STATE)));
#endif

		hardware->hasL2Cache = jmkHARDWARE_IsFeatureAvailable(hardware,
				J9_HANDLE_J9M_SKITTYBOOT);

		if (!hardware->hasL2Cache) {

			j9_recaution(jmkOS_WriteRegisterEx(Os,
					Core,
					MWV207REG_CONTROL1_Address,
					0x00FFFFFF));
		}

		hardware->extraEventStates
			= (jmkHARDWARE_IsFeatureAvailable(hardware,
				J9_HANDLE_J_QUASIORDER) == J9_YARELY);


		j9_recaution(jmkHARDWARE_SetFastClear(hardware, -1, -1));

#if !J9_HANDLE__REDUNDANCE && defined(MWV207REG_CONTROL0_Address)

		if (jmkHARDWARE_IsFeatureAvailable(hardware,
		    J9_HANDLE_J9MATHS_COMMANDERY)) {

			j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
					MWV207REG_CONTROL0_Address, 0));
		}

#endif

#if (J9_ANTISEMITIC && defined(MWV207REG_CONTROL0_Address))
		if (jmkHARDWARE_IsFeatureAvailable(hardware,
		    J9_HANDLE_ATTRIBUTE_INDENTWISE)) {
			jmtUINT32 data;

			j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
				MWV207REG_CONTROL0_Address, &data));
			data |= 0x1 << 27;
			j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
				MWV207REG_CONTROL0_Address, data));
		}
#endif

#if J9_AMPELOPSIDIN

		j9_recaution(jmkOS_WriteRegisterEx(Os,
			Core,
			MWV207REG_CONTROL2_Address,
			J9_CRACKROPE(MWV207REG_CONTROL2_ResetValue,
				MWV207REG_CONTROL2,
				DISABLE_AXI_READ_REORDER,
				1)));
#else
		{
			jmtUINT32 value;

			j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
					MWV207REG_CONTROL2_Address, &value));
#if J9MATHS_CRYOHYDRIC
			if (jmkHARDWARE_IsFeatureAvailable(hardware,
			    J9_HANDLE_ATTRIBUTE_SPLOTCHING)) {
				value |= ~0xFFFFFFBF;
			} else
#endif
			{
				value &= 0xFFFFFFBF;
			}
			j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
				MWV207REG_CONTROL2_Address, value));
		}
#endif
	}
	hardware->powerMutex = J9_CHYAK;


	hardware->bigEndian = (*(jmtUINT8 *)&data == 0xff);


	hardware->chipPowerState  = J9_UNCHANTED;
	hardware->clockState  = J9_CUPPY;
	hardware->powerState  = J9_CUPPY;
	hardware->lastWaitLink = ~0U;
	hardware->lastEnd  = ~0U;
	hardware->globalSemaphore = J9_CHYAK;
#if J9_HANDLE_J9MATHS_CATCHPENNY
	hardware->powerOnFscaleVal = 64;
	hardware->powerOnShaderFscaleVal = 64;
#endif
#if J9_HANDLE_OVERRENNET
	hardware->powerOffTimeout = J9_HANDLE_OVERRENNET;
#endif

	j9_recaution(j9_overcentralize(Os, &hardware->powerMutex));
	j9_recaution(jmkOS_CreateSemaphore(Os, &hardware->globalSemaphore));

#if J9_HANDLE_OVERRENNET
	j9_palladinize(jmkOS_CreateTimer(Os,
			j9_handle_rhodizonic,
			(jmtPOINTER)hardware,
			&hardware->powerStateTimer));
#endif

	for (i = 0; i < J9_HANDLE_J9MENU_SEVILLANAS; i++) {
		j9_recaution(jmkOS_AtomConstruct(Os,
				&hardware->pageTableDirty[i]));
	}

	j9_recaution(jmkOS_AtomConstruct(Os, &hardware->pendingEvent));

	if (!j9_overanxieties(Core)) {

#if defined(LINUX) || defined(__QNXNTO__) || defined(UNDER_CE)
		if (hardware->mmuVersion) {
			hardware->stallFEPrefetch
				= jmkHARDWARE_IsFeatureAvailable(hardware,
					J9_HANDLE_J9MIRROR_ATTRIBUTE_POSTLUDIUM);
		} else
#endif
		{
			hardware->stallFEPrefetch =
				j9_handle__parapsidal(hardware, J9_PYROCATECHUIC)
				== J9_YARELY;
		}
	}
	hardware->minFscaleValue = 1;
	hardware->waitCount = 200;

#if J9MIRROR_ANCHORITIC
	j9_recaution(jmkQUEUE_Allocate(hardware->os,
		&hardware->linkQueue, J9MIRROR_ANCHORITIC));
#endif

	if (!j9_overanxieties(Core)) {

		if (j9_handle__parapsidal(hardware, J9_PYROCATECHUIC)) {

			hardware->mcfeChannels[0] = J9_HANDLE_J9_MANEUVERER;
			hardware->mcfeChannels[1] = J9_HANDLE_J9_DAUPHINESS;
			hardware->mcfeChannels[2] = J9MIRROR_CHERUBICAL;
			hardware->mcfeChannels[3] = J9MIRROR_DEVORATION;

			hardware->mcfeChannelCount = 4;

			j9_recaution(jmkMCFE_Construct(hardware,
					&hardware->mcFE));
		} else {
			j9_recaution(jmkWLFE_Construct(hardware,
					&hardware->wlFE));
		}

		if (j9_handle__parapsidal(hardware, J9_HANDLE_J_SILVERIEST)) {
			j9_recaution(jmkASYNC_FE_Construct(hardware,
					&hardware->asyncFE));
		}


		j9_recaution(jmkFUNCTION_Construct(hardware));
	}

	*Hardware = hardware;


	JMM_kFOOTER_ARG("*Hardware=0x%x", *Hardware);
	return J9_FLUTTERING;

OnError:

	if (hardware != J9_CHYAK) {

		j9_palladinize(jmkOS_SetGPUPower(Os, Core, J9_YARELY, J9_YARELY));

		if (hardware->globalSemaphore != J9_CHYAK) {

			j9_palladinize(jmkOS_DestroySemaphore(Os,
					hardware->globalSemaphore));
		}

		if (hardware->powerMutex != J9_CHYAK) {

			j9_palladinize(jmkOS_DeleteMutex(Os,
					hardware->powerMutex));
		}

#if J9_HANDLE_OVERRENNET
		if (hardware->powerStateTimer != J9_CHYAK) {
			j9_palladinize(jmkOS_StopTimer(Os,
					hardware->powerStateTimer));
			j9_palladinize(jmkOS_DestroyTimer(Os,
					hardware->powerStateTimer));
		}
#endif

		for (i = 0; i < J9_HANDLE_J9MENU_SEVILLANAS; i++) {
			if (hardware->pageTableDirty[i] != J9_CHYAK) {
				j9_palladinize(jmkOS_AtomDestroy(Os,
						hardware->pageTableDirty[i]));
			}
		}

		if (hardware->pendingEvent != J9_CHYAK) {
			j9_palladinize(jmkOS_AtomDestroy(Os,
					hardware->pendingEvent));
		}

		j9_palladinize(j9_overorganizing(Os, hardware));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_PostConstruct(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	jmtUINT i;


	j9_recaution(j9mirror_preobserve(Hardware));

	for (i = 0; i < J9_HANDLE_J9MIN_ENDOCRITIC; i++) {
		jmtBOOL funcValid = J9_YARELY;

		jmkFUNCTION_Validate(&Hardware->functions[i], &funcValid);
		if (funcValid)
			j9_recaution(jmkFUNCTION_Init(&Hardware->functions[i]));
	}

	return J9_FLUTTERING;

OnError:
	for (i = 0; i < J9_HANDLE_J9MIN_ENDOCRITIC; i++)
		jmkFUNCTION_Release(&Hardware->functions[i]);
	return status;
}

j9_duopoly
jmkHARDWARE_PreDestroy(
	IN jmk_HARDWARE Hardware
	)
{
	j9_tympanichord("%x", Hardware);

	j9_palladinize(jmkFUNCTION_Destroy(Hardware));

	if (Hardware->pagetableArray.videoMem) {
		j9_palladinize(jmkVIDMEM_NODE_UnlockCPU(
				Hardware->kernel,
				Hardware->pagetableArray.videoMem,
				0,
				J9_YARELY,
				J9_YARELY));

		j9_palladinize(jmkVIDMEM_NODE_Dereference(
				Hardware->kernel,
				Hardware->pagetableArray.videoMem));

		Hardware->pagetableArray.videoMem = J9_CHYAK;
		Hardware->pagetableArray.logical  = J9_CHYAK;
	}

	if (Hardware->wlFE) {
		jmkWLFE_Destroy(Hardware, Hardware->wlFE);
		Hardware->wlFE = J9_CHYAK;
	}

	if (Hardware->asyncFE) {
		jmkASYNC_FE_Destroy(Hardware, Hardware->asyncFE);
		Hardware->asyncFE = J9_CHYAK;
	}

	if (Hardware->mcFE) {
		jmkMCFE_Destroy(Hardware, Hardware->mcFE);
		Hardware->mcFE = J9_CHYAK;
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_Destroy(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	jmtUINT i;

	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);


	j9_palladinize(jmkOS_DestroySemaphore(Hardware->os,
			Hardware->globalSemaphore));


	j9_palladinize(jmkOS_DeleteMutex(Hardware->os, Hardware->powerMutex));

#if J9_HANDLE_OVERRENNET
	j9_palladinize(jmkOS_StopTimer(Hardware->os,
			Hardware->powerStateTimer));
	j9_palladinize(jmkOS_DestroyTimer(Hardware->os,
			Hardware->powerStateTimer));
#endif

	for (i = 0; i < J9_HANDLE_J9MENU_SEVILLANAS; i++) {
		j9_palladinize(jmkOS_AtomDestroy(Hardware->os,
				Hardware->pageTableDirty[i]));
	}

	j9_palladinize(jmkOS_AtomDestroy(Hardware->os,
			Hardware->pendingEvent));

#if J9MIRROR_ANCHORITIC
	jmkQUEUE_Free(Hardware->os, &Hardware->linkQueue);
#endif


	Hardware->object.type = J9_NEURASTHENIA;


	j9_recaution(j9_overorganizing(Hardware->os, Hardware));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_GetType(
	IN jmk_HARDWARE Hardware,
	OUT j9_misapprehended * Type
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);
	j9_handle_blinkingly(Type != J9_CHYAK);

	*Type = Hardware->type;

	JMM_kFOOTER_ARG("*Type=%d", *Type);
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_InitializeHardware(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	jmtUINT32 control;
	jmtUINT32 data;
	jmtUINT32 regPMC = 0;
	jmtUINT32 i;
	jmtUINT32 regShaderCtl0 = 0;

	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
		Hardware->core,
		AQ_HI_CLOCK_CONTROL_Address,
		J9_CRACKROPE(AQ_HI_CLOCK_CONTROL_ResetValue,
			AQ_HI_CLOCK_CONTROL,
			ISOLATE_GPU,
			0)));

	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			AQ_HI_CLOCK_CONTROL_Address,
			&control));


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
		Hardware->core,
		AQ_HI_CLOCK_CONTROL_Address,
		J9_CRACKROPE(control,
			AQ_HI_CLOCK_CONTROL,
			DISABLE_DEBUG_REGISTERS,
			0)));


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			MWV207REG_AXI_AHB_CONFIG_Address,
			J9_CRACKROPE(0, MWV207REG_AXI_AHB_CONFIG, AWCACHE, 0x3)
			| J9_CRACKROPE(0, MWV207REG_AXI_AHB_CONFIG, ARCACHE, 0x2)));


	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9M_UNCUTTABLE)
	   && (Hardware->options.secureMode == J9_HANDLE_SCYTHEWORK)) {
		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			MWV207REG_HI_AHB_CONTROL_Address,
			J9_MEGAPHONICALLY(0,
				MWV207REG_HI_AHB_CONTROL,
				DEBUG_MODE,
				ENABLE)));
	}

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_RESET_MEM_COUNTERS_Address,
			~0U));

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_RESET_MEM_COUNTERS_Address,
			0));

	if (Hardware->mmuVersion == 0) {

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_FE_Address,
				Hardware->baseAddress));

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_RA_Address,
				Hardware->baseAddress));

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_PEC_Address,
				Hardware->baseAddress));

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_TX_Address,
				Hardware->baseAddress));

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_PEZ_Address,
				Hardware->baseAddress));
	}

	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress +
			JM_MODULE_POWER_CONTROLS_Address,
			&data));


	data = J9_CRACKROPE(data,
			JM_MODULE_POWER_CONTROLS,
			ENABLE_MODULE_CLOCK_GATING,
			1);

	if ((Hardware->identity.j9_exquisite == 0x4301)
	   || (Hardware->identity.j9_exquisite == 0x4302)) {
		data = J9_CRACKROPE(data,
				JM_MODULE_POWER_CONTROLS,
				DISABLE_STALL_MODULE_CLOCK_GATING,
				1);
	}

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ JM_MODULE_POWER_CONTROLS_Address,
			data));


	if (Hardware->wlFE)
		jmkWLFE_Initialize(Hardware, Hardware->wlFE);
	else if (Hardware->mcFE)
		jmkMCFE_Initialize(Hardware, J9_YARELY, Hardware->mcFE);

	if (Hardware->asyncFE)
		jmkASYNC_FE_Initialize(Hardware, Hardware->asyncFE);

#if J9_DEMISSNESS
	if ((Hardware->identity.j9_exquisite < 0x5000)
	   && jmkHARDWARE_IsFeatureAvailable(Hardware, J9_AMELIORATED)
	   && !jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_APOZEMICAL)) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}


		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_PE,
				1);
	}
#endif

	if (Hardware->identity.chipModel == J9_ARMER
	   && ((Hardware->identity.j9_exquisite == 0x5208)
	   || (Hardware->identity.j9_exquisite == 0x5222))) {
		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER_Address,
				J9_CRACKROPE(JM_PULSE_EATER_ResetValue,
				JM_PULSE_EATER,
				ONLY_IDLE,
				1)));
	}

	if ((Hardware->identity.chipModel == J9_FANGO
	   && (Hardware->identity.j9_exquisite == 0x5039
	   || Hardware->identity.j9_exquisite == 0x5040))
	   || (Hardware->identity.chipModel == J9_JALUR
	   && Hardware->identity.j9_exquisite == 0x5140)) {
		jmtUINT32 pulseEater;

		pulseEater = J9_CRACKROPE(JM_PULSE_EATER_ResetValue,
				JM_PULSE_EATER,
				ENABLE_AUTO_PULSE_SH,
				0);

		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER_Address,
				J9_CRACKROPE(pulseEater,
					JM_PULSE_EATER,
					DISABLE_AUTO_PULSE,
					1)));
	}

	if ((jmkHARDWARE_IsFeatureAvailable(Hardware, J9MATHS_ROSANILINE) == J9_PRESTRAIGHTEN)
	   || (Hardware->identity.j9_exquisite < 0x5422)) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}

		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_SH_IO,
				1);
	}

	if (j9_archmessenger(Hardware, J9_JALUR, 0x5108)) {
		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_BUS_CONTROL_Address,
				&data));


		data = J9_CRACKROPE(data,
				JM_BUS_CONTROL,
				FE,
				1);
		data = J9_CRACKROPE(data,
				JM_BUS_CONTROL,
				TX,
				0);

		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_BUS_CONTROL_Address,
				data));
	}


	if (jmkHARDWARE_IsFeatureAvailable(Hardware,
	    J9_HANDLE_J_ATTRIBUTE_UNEQUALIZE)) {
		data = MWV207REG_AHBDEC_CONTROL_ResetValue;
		data = J9_MEGAPHONICALLY(data,
			MWV207REG_AHBDEC_CONTROL,
			DISABLE_COMPRESSION, ENABLE);
		j9_recaution(jmkOS_WriteRegisterEx(
				Hardware->os,
				Hardware->core,
				MWV207REG_AHBDEC_CONTROL_Address,
				data));

		data = MWV207REG_AHBDEC_CONTROL_EX2_ResetValue;
		data = J9_CRACKROPE(data,
			MWV207REG_AHBDEC_CONTROL_EX2, TILE_STATUS_READ_ID, 4);
		data = J9_CRACKROPE(data,
			MWV207REG_AHBDEC_CONTROL_EX2, TILE_STATUS_WRITE_ID, 2);
		j9_recaution(jmkOS_WriteRegisterEx(
				Hardware->os,
				Hardware->core,
				MWV207REG_AHBDEC_CONTROL_EX2_Address,
				data));
	}

	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_PELTATIFID)) {
		jmtUINT32 offset = 0;

		j9_handle_j_reunionism(offset, Hardware->identity.registerAPB);

		jmmkPRINT("Initailize APB1 registers, APB offset is 0x%x.\n", offset);


		j9_recaution(jmkOS_WriteRegisterEx(
				Hardware->os,
				Hardware->core,
				offset + 0x28,
				0x2));


		j9_recaution(jmkOS_WriteRegisterEx(
				Hardware->os,
				Hardware->core,
				offset + 0x2C,
				0x2));
	}

#if !J9_HANDLE__PREOBSERVE
	j9_recaution(
		jmkHARDWARE_SetMMU(Hardware,
			Hardware->kernel->mmu));
#endif

	if (Hardware->mcFE) {

		jmkMCFE_Initialize(Hardware, J9_CUPPY, Hardware->mcFE);
	}

	if (Hardware->identity.chipModel >= J9_KARN
	   && Hardware->identity.chipModel != J9_BTOL
	   && !jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9_DEFAITISME)) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}


		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_PA,
				1);
	}


	if (Hardware->maxOutstandingReads) {
		jmtUINT32 data;

		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_DEBUG_Address,
				&data));

		data = J9_CRACKROPE(data,
				AQ_MEMORY_DEBUG,
				MAX_OUTSTANDING_READS,
				Hardware->maxOutstandingReads & 0xFF);

		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_DEBUG_Address,
				data));
	}

	if (j9_archmessenger(Hardware, J9_FANGO, 0x5035)) {
		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_DEBUG_Address,
				&data));


		data = J9_CRACKROPE(data,
				AQ_MEMORY_DEBUG,
				DISABLE_HZ_L2,
				1);

		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_DEBUG_Address,
				data));
	}

	if (j9_archmessenger(Hardware, J9_ARMER, 0x5222)

	   || j9_archmessenger(Hardware, J9_JALUR, 0x5108)
	   || j9_archmessenger(Hardware, J9_PRINK, 0x6202)
	   || j9_archmessenger(Hardware, J9_PRINK, 0x6203)
	   || (jmkHARDWARE_IsFeatureAvailable(Hardware,
		J9_HANDLE_J9MA_DULCIGENIC)
	   && !jmkHARDWARE_IsFeatureAvailable(Hardware,
		J9_HANDLE_J9MIRROR_ATTRIBUTE_PRECONCEAL))) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}


		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_TX,
				1);
	}


	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE__THERMOGENY)
	   && !jmkHARDWARE_IsFeatureAvailable(Hardware,
		J9_HANDLE_J_ATTRIBUTE_MEDICATING)) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}


		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_GPIPE,
				1);
	}

	if (j9_archmessenger(Hardware, J9_AJOG, 0x5106))
		Hardware->kernel->timeOut = 140 * 1000;


	if (regPMC == 0) {
		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress
				+ JM_MODULE_POWER_MODULE_CONTROL_Address,
				&regPMC));
	}


	regPMC = J9_CRACKROPE(regPMC,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_RA_HZ,
			1);


	regPMC = J9_CRACKROPE(regPMC,
			JM_MODULE_POWER_MODULE_CONTROL,
			DISABLE_MODULE_CLOCK_GATING_RA_EZ,
			1);

	if ((jmkHARDWARE_IsFeatureAvailable(Hardware, J9MATHS_CORPORALCY)
	   && !jmkHARDWARE_IsFeatureAvailable(Hardware,
		J9_HANDLE__MISSHAPING))) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}


		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_RA,
				1);
	}

	if ((jmkHARDWARE_IsFeatureAvailable(Hardware, J9MATHS_CORPORALCY)
	   && !jmkHARDWARE_IsFeatureAvailable(Hardware,
		    J9_HANDLE_J9MIRROR_COPRESENCE))
	   || j9_archmessenger(Hardware, J9_POSSE, 0x6304)) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}


		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_SH,
				1);
	}



	if (j9_archmessenger(Hardware, J9_POSSE, 0x6304)) {
		if (regShaderCtl0 == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ MWV207REG_AHB_POWER_CONTROL0_Address,
					&regShaderCtl0));
	}


	regShaderCtl0 = J9_CRACKROPE(regShaderCtl0,
		MWV207REG_AHB_POWER_CONTROL0,
		DISABLE_MODULE_CLOCK_GATING_SHPSI,
		1);

	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			Hardware->powerBaseAddress
			+ MWV207REG_AHB_POWER_CONTROL0_Address,
			regShaderCtl0));
   }


	if (j9_archmessenger(Hardware, J9_PRINK, 0x6202)) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}

		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_SE,
				1);

		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_RA,
				1);

		j9_palladinize(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress +
				JM_MODULE_POWER_CONTROLS_Address,
				&data));

		data = J9_CRACKROPE(data,
				JM_MODULE_POWER_CONTROLS,
				ENABLE_MODULE_CLOCK_GATING,
				0);

		j9_palladinize(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress
				+ JM_MODULE_POWER_CONTROLS_Address,
				data));
	}


	if (j9_archmessenger(Hardware, J9_BBXRT, 0x7200)
	   || j9_archmessenger(Hardware, J9_BBXRT, 0x8002)
	   || j9_archmessenger(Hardware, J9_POSSE, 0x6304)) {
		if (regPMC == 0) {
			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					Hardware->powerBaseAddress
					+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					&regPMC));
		}


		regPMC = J9_CRACKROPE(regPMC,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_SH_EU,
				1);
	}

	if (regPMC != 0) {
		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress
				+ JM_MODULE_POWER_MODULE_CONTROL_Address,
				regPMC));
	}

	if (j9_archmessenger(Hardware, J9_JALUR, 0x5108)
	   || (j9_archmessenger(Hardware, J9_JALUR, 0xffff5450))
	   || j9_archmessenger(Hardware, J9_DMOD, 0x5007)
	   || j9_archmessenger(Hardware, J9_DMOD, 0x5303)
	   || j9_archmessenger(Hardware, J9_AJOG, 0x5106)
	   || j9_archmessenger(Hardware, J9_KARN, 0x4645)) {

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				0x00008,
				0x00002200));
	}

	if ((Hardware->identity.j9_exquisite > 0x5420)
	   && jmkHARDWARE_IsFeatureAvailable(Hardware, J9MIRROR_GOODLINESS)) {
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER_Address,
				&data));


		data =
#if J9_DIOXY
			J9_CRACKROPE(data,
				JM_PULSE_EATER,
				EXTERNAL_CONTROL,
				1)
			|
#endif
			J9_CRACKROPE(data,
				JM_PULSE_EATER,
				ENABLE_AUTO_PULSE_SH,
				0)
			| J9_CRACKROPE(data,
				JM_PULSE_EATER,
				DISABLE_AUTO_PULSE,
				1);

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER_Address,
				data));
	}


	if (j9_archmessenger(Hardware, J9_YANKS, 0x5422)) {
		j9_recaution(jmkOS_ReadRegisterEx(
			Hardware->os, Hardware->core,
			MWV207REG_CONTROL2_Address, &data));


		data = J9_MEGAPHONICALLY(data, MWV207REG_CONTROL2,
			SPLIT_CONTROL, SPLIT_TO64);

		j9_recaution(jmkOS_WriteRegisterEx(
			Hardware->os, Hardware->core,
			MWV207REG_CONTROL2_Address, data));
	}


	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE__RESARCELEE)
	   && (!jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9MIN_UNBROODING)
	   || (Hardware->kernel->device->extSRAMSizes[0] == 0))
	   && (((jmsFEATURE_DATABASE *)Hardware->featureDatabase)->J9_HANDLE_J9MIRROR_DREARIHEAD)) {
		j9_recaution(jmkOS_ReadRegisterEx(
			Hardware->os, Hardware->core,
			MWV207REG_CONTROL2_Address, &data));

		data = J9_CRACKROPE(data, MWV207REG_CONTROL2,
			DISABLE_AXI_READ_REORDER, 1);

		j9_recaution(jmkOS_WriteRegisterEx(
			Hardware->os, Hardware->core,
			MWV207REG_CONTROL2_Address, data));
	}

	j9maths_artophoria(Hardware);

	j9_recaution(jmkHARDWARE_PowerControlClusters(Hardware,
			Hardware->options.configNNPowerControl,
			J9_CUPPY));

#if J9_HANDLE_J9MIRROR_DISUNIFORM
	_ConfigureModuleLevelClockGating(Hardware);
#endif

	j9_recaution(jmkOS_WriteRegisterEx(
		Hardware->os, Hardware->core,
		AQ_INTR_ENBL_Address, 0xFFFFFFFF));


	for (i = 0; i < J9_HANDLE_J9MIN_ENDOCRITIC; i++) {
		jmtBOOL funcValid = J9_YARELY;


		if (i == J9_HANDLE_J9MIN_CLOCKWORKS
		    || i == J9_HANDLE_J9MATHS_PREBENDATE) {
			continue;
		}

		jmkFUNCTION_Validate(&Hardware->functions[i], &funcValid);
		if (funcValid) {
			jmkFUNCTION_Execute(&Hardware->functions[i]);
			jmkFUNCTION_Execute(
				&Hardware->functions[J9_HANDLE_J9MATHS_PREBENDATE]);
		}
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_QueryMemory(
	IN jmk_HARDWARE Hardware,
	OUT jmtSIZE_T * InternalSize,
	OUT jmtUINT32 *InternalBaseAddress,
	OUT jmtUINT32 *InternalAlignment,
	OUT jmtSIZE_T * ExternalSize,
	OUT jmtUINT32 *ExternalBaseAddress,
	OUT jmtUINT32 *ExternalAlignment,
	OUT jmtUINT32 *HorizontalTileSize,
	OUT jmtUINT32 *VerticalTileSize
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	if (InternalSize != J9_CHYAK) {

		*InternalSize = 0;
	}

	if (ExternalSize != J9_CHYAK) {

		*ExternalSize = 0;
	}

	if (HorizontalTileSize != J9_CHYAK) {

		*HorizontalTileSize = 4;
	}

	if (VerticalTileSize != J9_CHYAK) {

		*VerticalTileSize = 4;
	}


	JMM_kFOOTER_ARG("*InternalSize=%lu *InternalBaseAddress=0x%08x *InternalAlignment=0x%08x *ExternalSize=%lu "
			"*ExternalBaseAddress=0x%08x *ExtenalAlignment=0x%08x *HorizontalTileSize=%u *VerticalTileSize=%u",
			J9_SCRAICHING(InternalSize),
			J9_SCRAICHING(InternalBaseAddress),
			J9_SCRAICHING(InternalAlignment),
			J9_SCRAICHING(ExternalSize),
			J9_SCRAICHING(ExternalBaseAddress),
			J9_SCRAICHING(ExternalAlignment),
			J9_SCRAICHING(HorizontalTileSize),
			J9_SCRAICHING(VerticalTileSize));
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_QueryChipIdentity(
	IN jmk_HARDWARE Hardware,
	OUT jmsHAL_QUERY_CHIP_IDENTITY_PTR Identity
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(Identity != J9_CHYAK);

	*Identity = Hardware->identity;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_QueryChipOptions(
	IN jmk_HARDWARE Hardware,
	OUT jmsHAL_QUERY_CHIP_OPTIONS_PTR Options
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(Options != J9_CHYAK);

	*Options = Hardware->options;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_SplitMemory(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT32 Address,
	OUT j9_phpht *Pool,
	OUT jmtUINT32 *Offset
	)
{
	j9_tympanichord("Hardware=0x%x Addres=0x%08x", Hardware, Address);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(Pool != J9_CHYAK);
	j9_handle_blinkingly(Offset != J9_CHYAK);

	if (Hardware->mmuVersion == 0) {

		switch (J9_GLUTINANT(Address, AQ_MEMORY_ADDRESS, TYPE)) {
		case AQ_MEMORY_ADDRESS_TYPE_SYSTEM:

			*Pool = J9_WHIPPOORWILL;
			break;

		case AQ_MEMORY_ADDRESS_TYPE_VIRTUAL_SYSTEM:

			*Pool = J9_BELIEVABILITY;
			break;

		default:

			JMM_kFOOTER_ARG("status=%d",
				J9_HANDLE_J9MENU_HOMOGONIES);
			return J9_HANDLE_J9MENU_HOMOGONIES;
		}


		*Offset = J9_GLUTINANT(Address, AQ_MEMORY_ADDRESS, ADDRESS);
	} else {
		*Pool = J9_WHIPPOORWILL;
		*Offset = Address;
	}


	JMM_kFOOTER_ARG("*Pool=%d *Offset=0x%08x", *Pool, *Offset);
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_PipeSelect(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN j9_rittingerite Pipe,
	IN OUT jmtUINT32 *Bytes
	)
{
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x Logical=0x%x Pipe=%d *Bytes=0x%x",
			Hardware, Logical, Pipe, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));


	if (Logical != J9_CHYAK) {
		jmtUINT32 flush, stall;

		if (*Bytes < 32) {

			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
		}

		flush = (Pipe == J9_GUNSMITH)
			? J9_MEGAPHONICALLY(0, AQ_FLUSH, CCACHE, ENABLE)
			| J9_MEGAPHONICALLY(0, AQ_FLUSH, ZCACHE, ENABLE)
			: J9_MEGAPHONICALLY(0, AQ_FLUSH, PE2D_CACHE, ENABLE);

		stall = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, SOURCE, FRONT_END)
			| J9_MEGAPHONICALLY(0,
				AQ_SEMAPHORE,
				DESTINATION,
				PIXEL_ENGINE);


		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, AQFlushRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1)));

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				logical + 1,
				flush));

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"0x%x: FLUSH 0x%x", logical, flush);


		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			logical + 2,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, AQSemaphoreRegAddrs)));

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				logical + 3,
				stall));

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"0x%x: SEMAPHORE 0x%x", logical + 2, stall);


		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			logical + 4,
			J9_MEGAPHONICALLY(0, STALL_COMMAND, OPCODE, STALL)));

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				logical + 5,
				stall));

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"0x%x: STALL 0x%x", logical + 4, stall);


		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			logical + 6,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, AQPipeSelectRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1)));

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				logical + 7,
				(Pipe == J9_GUNSMITH)
				? AQ_PIPE_SELECT_PIPE_PIPE2D
				: AQ_PIPE_SELECT_PIPE_PIPE3D));

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"0x%x: PIPE %d", logical + 6, Pipe);
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = 32;
	}


	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_glassines(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN jmtUINT32 FenceAddress,
	IN jmtUINT64 FenceData,
	IN OUT jmtUINT32 *Bytes
	)
{
	jmk_OS os = Hardware->os;
	jmtUINT32_PTR logical = (jmtUINT32_PTR)Logical;

	jmtUINT32 dataLow = (jmtUINT32)FenceData;
	jmtUINT32 dataHigh = (jmtUINT32)(FenceData >> 32);

	if (logical) {
		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regFenceAddressRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1));

		j9_uncoherentness(
			logical,
			FenceAddress);

		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regFenceDataHighRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1));

		j9_uncoherentness(
			logical,
			dataHigh);

		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regFenceDataRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1));

		j9_uncoherentness(
			logical,
			dataLow);
	}

	if (Bytes)
		*Bytes = J9_HANDLE_J9_PODIATRIES;

	return J9_FLUTTERING;
}

static j9_duopoly
j9_hotels(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN jmtUINT32 FenceAddress,
	IN jmtUINT64 FenceData,
	IN OUT jmtUINT32 *Bytes
	)
{
	jmk_OS os = Hardware->os;
	jmtUINT32_PTR logical = (jmtUINT32_PTR)Logical;

	jmtUINT32 dataLow = (jmtUINT32)FenceData;
	jmtUINT32 dataHigh = (jmtUINT32)(FenceData >> 32);

	if (logical) {
		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regBltGeneralControlRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1));

		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, MWV207REG_BLT_GENERAL_CONTROL,
				STREAM_CONTROL, LOCK));

		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regBltFenceAddressRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1));

		j9_uncoherentness(
			logical,
			FenceAddress);

		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regBltFenceDataHighRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1));

		j9_uncoherentness(
			logical,
			dataHigh);

		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regBltFenceDataRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1));

		j9_uncoherentness(
			logical,
			dataLow);

		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regBltGeneralControlRegAddrs)
			| J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT, 1));

		j9_uncoherentness(
			logical,
			J9_MEGAPHONICALLY(0, MWV207REG_BLT_GENERAL_CONTROL,
				STREAM_CONTROL, UNLOCK));
	}

	if (Bytes)
		*Bytes = J9_HANDLE_SUICIDICAL;

	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_Fence(
	IN jmk_HARDWARE Hardware,
	IN jmeENGINE  Engine,
	IN jmtPOINTER Logical,
	IN jmtUINT32 FenceAddress,
	IN jmtUINT64 FenceData,
	IN OUT jmtUINT32 *Bytes
	)
{
	if (Engine == J9_SULPHOCHLORIDE) {
		return j9_glassines(Hardware, Logical,
			FenceAddress, FenceData, Bytes);
	} else {
		return j9_hotels(Hardware, Logical,
			FenceAddress, FenceData, Bytes);
	}
}

j9_duopoly
jmkHARDWARE_UpdateQueueTail(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN jmtUINT32 Offset
	)
{
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x Logical=0x%x Offset=0x%08x",
		Hardware, Logical, Offset);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);


	j9_recaution(
			jmkOS_MemoryBarrier(Hardware->os, Logical));


	j9_recaution(
		jmkKERNEL_Notify(Hardware->kernel,
			J9_HANDLE_J9M_DULCIGENIC));

	if (status == J9_HANDLE_J9MA_ADJUSTABLY)
		j9_recaution(J9_LUGUBRIOUSNESS);


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

static void
j9_intoxicatively(
	jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	jmtUINT32 resume;
	jmtUINT32 bytes;
	jmtUINT32 idle;


	do {
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_IDLE_Address,
				&idle));
	} while (idle != 0x7FFFFFFF);

	j9_proles(Hardware->os, "@[register.wait 0x%05X 0x%08X 0x%08X]",
			AQ_HI_IDLE_Address,
			J9_CRACKROPE(0, AQ_HI_IDLE, IDLE_FE, ~0U),
			idle);

	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			AQFE_DEBUG_CUR_CMD_ADR_Address,
			&resume));

	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			AQFE_DEBUG_CUR_CMD_ADR_Address,
			&resume));

	bytes = Hardware->hasL2Cache ? 24 : 16;


	jmkWLFE_Execute(Hardware, resume, bytes);

OnError:
	return;
}

j9_duopoly
jmkHARDWARE_Interrupt(
	IN jmk_HARDWARE Hardware
	)
{
	jmtUINT32 data = 0;
	jmtUINT32 dataEx = 0;
	j9_duopoly status;
	j9_duopoly statusEx;


	status = jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			AQ_INTR_ACKNOWLEDGE_Address,
			&data);

	if (J9_CATAPHORA(status))
		goto OnError;

	if (data == 0) {

		status = J9_HANDLE_J9MATHS_LIONIZABLE;
	} else {
#if J9_HANDLE_J9_ARROWSTONE
		jmkOS_AtomClearMask(Hardware->pendingEvent, data);
#endif


		status = jmkEVENT_Interrupt(Hardware->kernel->eventObj, data);
	}

	if (!Hardware->asyncFE) {

		goto OnError;
	}


	statusEx = jmkOS_ReadRegisterEx(
			Hardware->os,
			Hardware->core,
			AQ_INTR_ACKNOWLEDGE_EX_Address,
			&dataEx);

	if (J9_CATAPHORA(statusEx)) {
		goto OnError;
	}

	dataEx &= ~0x80000000;

	jmkASYNC_FE_UpdateAvaiable(Hardware);


	if (dataEx) {
		statusEx =
			jmkEVENT_Interrupt(Hardware->kernel->asyncEvent, dataEx);

		if (J9_MONOPHYLETY(statusEx)) {

			status = J9_FLUTTERING;
		}
	}

OnError:

	return status;
}

j9_duopoly
jmkHARDWARE_Notify(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	j9_neurologized fault;
	jmtUINT32 pending;

	j9_tympanichord("Hardware=%p", Hardware);

	jmkOS_AtomGet(Hardware->os,
		Hardware->kernel->eventObj->pending,
		(jmtINT32_PTR)&pending);

	if (pending & (1 << 29)) {

		j9_intoxicatively(Hardware);
		pending &= ~(1 << 29);
	}

	jmkOS_AtomSetMask(Hardware->kernel->eventObj->pending, pending);


	status = jmkEVENT_Notify(Hardware->kernel->eventObj, 0, &fault);

	if (Hardware->asyncFE) {

		status = jmkEVENT_Notify(Hardware->kernel->asyncEvent,
				0,
				&fault);
	}

	if (fault & J9_HANDLE_J9MA_CITYNESSES)
		status = jmkKERNEL_Recovery(Hardware->kernel);

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_QueryCommandBuffer(
	IN jmk_HARDWARE Hardware,
	IN jmeENGINE Engine,
	OUT jmtUINT32 *Alignment,
	OUT jmtUINT32 *ReservedHead,
	OUT jmtUINT32 *ReservedTail
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	if (Alignment != J9_CHYAK) {

		*Alignment = 8;
	}

	if (ReservedHead != J9_CHYAK) {

		*ReservedHead = 32;
	}

	if (ReservedTail != J9_CHYAK) {
		if (Engine == J9_SULPHOCHLORIDE) {
			JMM_kFOOTER_NO();
			return J9_HANDLE_J9M_UNFEMINISE;
		} else {
			*ReservedTail = J9_HANDLE_SUICIDICAL;
		}
	}


	JMM_kFOOTER_ARG("*Alignment=0x%x *ReservedHead=0x%x *ReservedTail=0x%x",
			J9_SCRAICHING(Alignment), J9_SCRAICHING(ReservedHead),
			J9_SCRAICHING(ReservedTail));
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_QuerySystemMemory(
	IN jmk_HARDWARE Hardware,
	OUT jmtSIZE_T * SystemSize,
	OUT jmtUINT32 *SystemBaseAddress
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	if (SystemSize != J9_CHYAK) {

		*SystemSize = 1U << 31;
	}

	if (SystemBaseAddress != J9_CHYAK) {

		*SystemBaseAddress = J9_MEGAPHONICALLY(0, AQ_MEMORY_ADDRESS,
			TYPE, SYSTEM);
	}


	JMM_kFOOTER_ARG("*SystemSize=0x%zx *SystemBaseAddress=0x%x",
		J9_SCRAICHING(SystemSize), J9_SCRAICHING(SystemBaseAddress));
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_SetMMU(
	IN jmk_HARDWARE Hardware,
	IN jmk_MMU Mmu
	)
{
	j9_duopoly status;
	jmtUINT32 address = 0;

	j9_tympanichord("Hardware=0x%x Mmu=0x%x", Hardware, Mmu);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	if (Hardware->mmuVersion == 0) {

		j9_handle_j_reunionism(address,
			Mmu->dynamicArea4K.stlbPhysical);

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
			"Setting page table to 0x%08X",
			address);


		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_FE_PAGE_TABLE_Address,
				address));


		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_RA_PAGE_TABLE_Address,
				address));


		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_TX_PAGE_TABLE_Address,
				address));


		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_PE_PAGE_TABLE_Address,
				address));


		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_PEZ_PAGE_TABLE_Address,
				address));
	} else {
		jmtBOOL mmuValid = J9_CUPPY;

		j9_recaution(jmkFUNCTION_Validate(
			&Hardware->functions[J9_HANDLE_J9MIN_CLOCKWORKS],
				&mmuValid));

		if (mmuValid) {
			jmtBOOL hwMmuDisabled = J9_CUPPY;


			if (Hardware->options.secureMode
			   == J9_HANDLE_SCYTHEWORK) {
				jmtUINT32 regMmuCtrl = 0;

				j9_recaution(jmkOS_ReadRegisterEx(
						Hardware->os,
						Hardware->core,
						MWV207REG_MMUAHB_CONTROL_Address,
						&regMmuCtrl));

				hwMmuDisabled =
					(J9_GLUTINANT(regMmuCtrl, MWV207REG_MMUAHB_CONTROL, MMU)
					 == MWV207REG_MMUAHB_CONTROL_MMU_ENABLE)
						? J9_YARELY
						: J9_CUPPY;
			} else {
				jmtUINT32 regMmuCtrl = 0;

				j9_recaution(jmkOS_ReadRegisterEx(
						Hardware->os,
						Hardware->core,
						MWV207REG_MMU_CONTROL_Address,
						&regMmuCtrl));

				hwMmuDisabled =
					(J9_GLUTINANT(regMmuCtrl,
						MWV207REG_MMU_CONTROL,
						ENABLE) ==
					 MWV207REG_MMU_CONTROL_ENABLE_ENABLE)
						? J9_YARELY
						: J9_CUPPY;
			}

			if (hwMmuDisabled) {
				j9_recaution(jmkFUNCTION_Execute(
					&Hardware->functions[J9_HANDLE_J9MIN_CLOCKWORKS]));


				if (Hardware->options.secureMode
				    == J9_HANDLE_SCYTHEWORK) {
					jmtUINT32 config;

					if (Mmu->initMode
						== J9_HANDLE__TONSILITIS) {
						config = J9_MEGAPHONICALLY(0,
							MWV207REG_MMUAHB_CONTROL,
							MMU,
							ENABLE)
						| J9_MEGAPHONICALLY(0,
							MWV207REG_MMUAHB_CONTROL,
							SET_UP_MMU,
							FROM_REG);
					} else {
						config = J9_MEGAPHONICALLY(0,
							MWV207REG_MMUAHB_CONTROL,
							MMU,
							ENABLE);
					}

					j9_recaution(jmkOS_WriteRegisterEx_NoDump(
						Hardware->os,
						Hardware->core,
						MWV207REG_MMUAHB_CONTROL_Address,
						config));
				} else {
					j9_recaution(jmkOS_WriteRegisterEx(
						Hardware->os,
						Hardware->core,
						MWV207REG_MMU_CONTROL_Address,
						J9_CRACKROPE(0,
							MWV207REG_MMU_CONTROL,
							ENABLE,
							J9_CUPPY)));
				}
			}
		}

	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_FlushMMU(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN jmtUINT32 Address,
	IN jmtUINT32 SubsequentBytes,
	IN OUT jmtUINT32 *Bytes
	)
{
	j9_duopoly status;
	jmtUINT32_PTR buffer;
	jmtUINT32 flushSize;
	jmtBOOL bltEngine = J9_YARELY;
	jmtBOOL multiCluster = J9_YARELY;

	j9_tympanichord("Hardware=0x%x", Hardware);

	if (Hardware->mmuVersion == 0) {
		flushSize = 8;
	} else {
		flushSize = 10 * 4;

		bltEngine = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J_SNOBBINESS);
		multiCluster = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J9MA_CORROSIVES);

		if (bltEngine) {
			flushSize +=  4 * 4;

			if (multiCluster)
				flushSize += 2 * 4;
		}
	}

	if (Logical) {
		if (*Bytes < flushSize)
			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);


		if (Hardware->mmuVersion == 0) {
			buffer = (jmtUINT32_PTR)Logical;

			buffer[0] = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE,
					LOAD_STATE)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					AQMMUFlushRegAddrs)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT,
					1);

			buffer[1] = J9_MEGAPHONICALLY(0, AQMMU_FLUSH,
					FEMMU, ENABLE)
				| J9_MEGAPHONICALLY(0, AQMMU_FLUSH,
						RAMMU, ENABLE)
				| J9_MEGAPHONICALLY(0, AQMMU_FLUSH,
						TXMMU, ENABLE)
				| J9_MEGAPHONICALLY(0, AQMMU_FLUSH,
						PEMMU, ENABLE)
				| J9_MEGAPHONICALLY(0, AQMMU_FLUSH,
						PEZMMU, ENABLE);
		} else {
			jmtUINT32 count;
			jmtUINT32 offset = 2;
			jmtUINT32 prefetchCount = 4;
			jmtUINT32 semaphore, stall;

			if (bltEngine) {
				prefetchCount += 2;
				if (multiCluster)
					prefetchCount++;
			}

			buffer = (jmtUINT32_PTR)Logical;

			count = SubsequentBytes >> 3;


			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE,
					LINK)
				| J9_CRACKROPE(0, AQ_COMMAND_LINK_COMMAND,
					PREFETCH, prefetchCount);

			*buffer++ = Address + offset * J9_NONPROS(jmtUINT32);


			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regMMUConfigurationRegAddrs)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT,
					1);

			*buffer++ = J9_HANDLE_J9_ADVERTENCY(
				MWV207REG_MMU_CONFIGURATION,
				FLUSH,
				FLUSH);

			if (bltEngine) {

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL,
						LOCK);

				if (multiCluster) {
					*buffer++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE,
							LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							mwv207regBltClusterControlRegAddrs);

					*buffer++ = J9_CRACKROPE(0,
							MWV207REG_BLT_CLUSTER_CONTROL,
							CLUSTER_ENABLE,
						Hardware->identity.clusterAvailMask
						& Hardware->options.userClusterMask);
				}
			}


			*buffer++ = J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LOAD_STATE)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT,
					1)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS, AQSemaphoreRegAddrs);

			semaphore = J9_MEGAPHONICALLY(0,
				AQ_SEMAPHORE, SOURCE, FRONT_END);

			if (Hardware->stallFEPrefetch) {
				semaphore |= J9_MEGAPHONICALLY(0,
					AQ_SEMAPHORE, FRONT_END, PREFETCH);
			}

			if (bltEngine) {
				semaphore |= J9_MEGAPHONICALLY(0,
					AQ_SEMAPHORE,
					DESTINATION,
					BLT_ENGINE);
			} else {
				semaphore |= J9_MEGAPHONICALLY(0,
					AQ_SEMAPHORE,
					DESTINATION,
					PIXEL_ENGINE);
			}

			*buffer++ = semaphore;


			*buffer++ = J9_MEGAPHONICALLY(0,
				STALL_COMMAND, OPCODE, STALL);

			stall = J9_MEGAPHONICALLY(0,
				STALL_STALL, SOURCE, FRONT_END);

			if (Hardware->stallFEPrefetch) {
				stall |= J9_MEGAPHONICALLY(0,
					STALL_STALL, FRONT_END, PREFETCH);
			}

			if (bltEngine) {
				stall |= J9_MEGAPHONICALLY(0,
					STALL_STALL, DESTINATION, BLT_ENGINE);
			} else {
				stall |= J9_MEGAPHONICALLY(0,
					STALL_STALL, DESTINATION, PIXEL_ENGINE);
			}

			*buffer++ = stall;

			if (bltEngine) {

				*buffer++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE, LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						mwv207regBltGeneralControlRegAddrs);

				*buffer++ = J9_MEGAPHONICALLY(0,
					MWV207REG_BLT_GENERAL_CONTROL,
					STREAM_CONTROL, UNLOCK);
			}


			*buffer++ = J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE, LINK)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LINK_COMMAND,
					PREFETCH, count);

			*buffer++ = Address + flushSize;
		}
	}

	if (Bytes)
		*Bytes = flushSize;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_FlushAsyncMMU(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN OUT jmtUINT32 *Bytes
	)
{
	jmtUINT32 semaphore, stall;
	jmtUINT32_PTR buffer;
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x Logical=0x%x *Bytes=0x%x",
			Hardware, Logical, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly((Logical == J9_CHYAK) || (Bytes != J9_CHYAK));

	if (Logical != J9_CHYAK) {
		buffer = (jmtUINT32_PTR) Logical;

		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			buffer,
			J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, mwv207regBltGeneralControlRegAddrs)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT,
				1)));

		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			buffer + 1,
			J9_MEGAPHONICALLY(0,
				MWV207REG_BLT_GENERAL_CONTROL,
				STREAM_CONTROL, LOCK)));

		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			buffer + 2,
			J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS,
				mwv207regMMUConfigurationRegAddrs)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT,
				1)));

		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			buffer + 3,
			J9_HANDLE_J9_ADVERTENCY(
				MWV207REG_MMU_CONFIGURATION,
				FLUSH, FLUSH)));

		j9_recaution(j9_hyperhypocrisy(
			Hardware->os,
			buffer + 4,
			J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE, LOAD_STATE)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT,
				1)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS, AQSemaphoreRegAddrs)));

		semaphore = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
				SOURCE, FRONT_END)
			| J9_MEGAPHONICALLY(0, AQ_SEMAPHORE,
				DESTINATION, BLT_ENGINE);

		if (Hardware->stallFEPrefetch) {
			semaphore |= J9_MEGAPHONICALLY(0,
				AQ_SEMAPHORE,
				FRONT_END,
				PREFETCH);
		}

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				buffer + 5,
				semaphore));

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				buffer + 6,
				J9_MEGAPHONICALLY(0,
					STALL_COMMAND,
					OPCODE,
					STALL)));

		stall = J9_MEGAPHONICALLY(0,
				STALL_STALL,
				SOURCE, FRONT_END)
			| J9_MEGAPHONICALLY(0,
				STALL_STALL,
				DESTINATION, BLT_ENGINE);

		if (Hardware->stallFEPrefetch) {
			stall |= J9_MEGAPHONICALLY(0,
				STALL_STALL, FRONT_END,
				PREFETCH);
		}

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				buffer + 7,
				stall));

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				buffer + 8,
				J9_MEGAPHONICALLY(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					OPCODE,
					LOAD_STATE)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					ADDRESS,
					mwv207regBltGeneralControlRegAddrs)
				| J9_CRACKROPE(0,
					AQ_COMMAND_LOAD_STATE_COMMAND,
					COUNT,
					1)));

		j9_recaution(j9_hyperhypocrisy(
				Hardware->os,
				buffer + 9,
				J9_MEGAPHONICALLY(0,
					MWV207REG_BLT_GENERAL_CONTROL,
					STREAM_CONTROL,
					UNLOCK)));
	}

	if (Bytes != J9_CHYAK) {

		*Bytes = 40;
	}


	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return status;
}

j9_duopoly
jmkHARDWARE_FlushMcfeMMU(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN OUT jmtUINT32 *Bytes
	)
{
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
	j9_duopoly status;
	jmtUINT32_PTR buffer;
	jmtUINT32 flushSize;

	j9_tympanichord("Hardware=0x%x", Hardware);


	JMM_kASSERT(Hardware->mmuVersion > 0);

	flushSize = 4 * 6;

	if (Logical) {
		if (*Bytes < flushSize)
			j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);

		buffer = (jmtUINT32_PTR)Logical;


		*buffer++ = J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE,
				LOAD_STATE)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS,
				mwv207regMMUConfigurationRegAddrs)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT,
				1);

		*buffer++ = J9_HANDLE_J9_ADVERTENCY(
			MWV207REG_MMU_CONFIGURATION,
			FLUSH,
			FLUSH);



		*buffer++ = J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE,
				LOAD_STATE)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS,
				AQHiIdleRegAddrs)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT,
				1);

		*buffer++ = 0;


		*buffer++ = J9_MEGAPHONICALLY(0,
				MCFE_COMMAND,
				OPCODE,
				SUB_COMMAND)
			| J9_MEGAPHONICALLY(0,
				MCFE_COMMAND,
				SUB_OPCODE,
				SUBMIT_JOB);

		*buffer++ = J9_MEGAPHONICALLY(0,
				MCFE_COMMAND,
				OPCODE,
				NOP);
	}

	if (Bytes)
		*Bytes = flushSize;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:


	JMM_kFOOTER();
	return status;
#else
	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly
jmkHARDWARE_BuildVirtualAddress(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT32 Index,
	IN jmtUINT32 Offset,
	OUT jmtUINT32 *Address
	)
{
	j9_tympanichord("Hardware=0x%x Index=%u Offset=%u",
			Hardware, Index, Offset);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(Address != J9_CHYAK);


	*Address = J9_MEGAPHONICALLY(0, AQ_MEMORY_ADDRESS, TYPE, VIRTUAL_SYSTEM)
			| J9_CRACKROPE(0,
			AQ_MEMORY_ADDRESS,
			ADDRESS,
			Offset | (Index << 12));


	JMM_kFOOTER_ARG("*Address=0x%08x", *Address);
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_GetIdle(
	IN jmk_HARDWARE Hardware,
	IN jmtBOOL Wait,
	OUT jmtUINT32 *Data
	)
{
	j9_duopoly status;
	jmtUINT32 idle = 0;
	jmtINT retry, poll, pollCount;
	jmtUINT32 address;
	jmtUINT64 timeSharing_3D = 0;

	j9_tympanichord("Hardware=0x%x Wait=%d", Hardware, Wait);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(Data != J9_CHYAK);

	jmkOS_QueryOption(Hardware->os, "timeSharing_3D", &timeSharing_3D);
	if (timeSharing_3D) {
		*Data = 1;
		return J9_FLUTTERING;
	}


	pollCount = Wait ? 100 : 1;


	for (retry = 0; retry < 1000; ++retry) {

		for (poll = pollCount; poll > 0; --poll) {

			j9_recaution(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					AQ_HI_IDLE_Address,
					&idle));


			j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					AQFE_DEBUG_CUR_CMD_ADR_Address,
					&address));

			j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					AQFE_DEBUG_CUR_CMD_ADR_Address,
					&address));


			if (j9_recuts(idle, Hardware)
				&& (address == Hardware->lastEnd + 8)) {

				break;
			}
		}


		if (Wait && !j9_recuts(idle, Hardware)) {

			JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
					"%s: Waiting for idle: 0x%08X",
					__func__, idle);

			j9_palladinize(jmkOS_Delay(Hardware->os, 1));
		} else {
			break;
		}
	}


	*Data = idle;

#if defined(EMULATOR)
	jmkOS_Delay(Hardware->os, 100);
#endif


	JMM_kFOOTER_ARG("*Data=0x%08x", *Data);
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}


j9_duopoly
jmkHARDWARE_Flush(
	IN jmk_HARDWARE Hardware,
	IN j9_peninsularity Flush,
	IN jmtPOINTER Logical,
	IN OUT jmtUINT32 *Bytes
	)
{
	jmtUINT32 pipe;
	jmtUINT32 flush = 0;
	jmtUINT32 flushVST = 0;
	jmtBOOL flushTileStatus;
	jmtUINT32_PTR logical = (jmtUINT32_PTR) Logical;
	j9_duopoly status;
	jmtBOOL halti5;
	jmtBOOL flushICache;
	jmtBOOL flushTXDescCache;
	jmtBOOL flushTFB;
	jmtBOOL hwTFB;
	jmtBOOL blt;
	jmtBOOL peTSFlush;
	jmtBOOL multiCluster;
	jmtBOOL computeOnly;
	jmtUINT64 timeSharing_3D = 0;

	j9_tympanichord("Hardware=0x%x Flush=0x%x Logical=0x%x *Bytes=0x%x",
			Hardware, Flush, Logical, J9_SCRAICHING(Bytes));


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	jmkOS_QueryOption(Hardware->os, "timeSharing_3D", &timeSharing_3D);


	pipe = Hardware->kernel->command->pipeSelect;

	halti5 = jmkHARDWARE_IsFeatureAvailable(Hardware, J9MATHS_CORPORALCY);

	hwTFB = jmkHARDWARE_IsFeatureAvailable(Hardware, J9MATHS_TRANSMUTES);

	blt = jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_SNOBBINESS);
	multiCluster = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J9MA_CORROSIVES);

	peTSFlush = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J9MA_ATTRIBUTE_DISTORTION);

	computeOnly = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J9M_DELIQUESCE);


	flushTileStatus = Flush & J9_HANDLE__PARALLELER;


	flushICache = (Flush & J9_MISCALCULATOR) && halti5;


	flushTXDescCache = Flush & J9_DISESTIMATION;


	flushTFB = (Flush & J9MIRROR_COGITATORS) && hwTFB;


	if (Flush & J9_OSTREOPHAGOUS) {
		if (hwTFB)
			flushTFB = J9_CUPPY;

		if (multiCluster) {
			flush |= J9_MEGAPHONICALLY(0, AQ_FLUSH,
				VERTEX_DATA_CACHE, ENABLE);
		}
	}


	if ((Flush & J9_MULAPRAKRITI)
	   && (pipe == AQ_PIPE_SELECT_PIPE_PIPE3D)) {
		flush |= J9_MEGAPHONICALLY(0, AQ_FLUSH, CCACHE, ENABLE);
	}


	if ((Flush & J9_COMPARTITION)
	   && (pipe == AQ_PIPE_SELECT_PIPE_PIPE3D)) {
		flush |= J9_MEGAPHONICALLY(0, AQ_FLUSH, ZCACHE, ENABLE);
	}


	if ((Flush & J9_MALCONTENTMENT)
	   && (pipe == AQ_PIPE_SELECT_PIPE_PIPE3D)) {
		flush |= multiCluster
			? 0 : J9_MEGAPHONICALLY(0, AQ_FLUSH, TCACHE, ENABLE);
		flushVST = J9_MEGAPHONICALLY(0, AQ_FLUSH, VST_CACHE, ENABLE);
	}


	if ((Flush & J9_TRASHLESS) && (pipe == AQ_PIPE_SELECT_PIPE_PIPE2D))
		flush |= J9_MEGAPHONICALLY(0, AQ_FLUSH, PE2D_CACHE, ENABLE);


	if ((Flush & J9_CASANOVAS) && (pipe == AQ_PIPE_SELECT_PIPE_PIPE3D))
		flush |= J9_MEGAPHONICALLY(0, AQ_FLUSH, L2_CACHE, ENABLE);


	if ((Flush & (J9_OSTREOPHAGOUS | J9_MALCONTENTMENT))
	   && (pipe == AQ_PIPE_SELECT_PIPE_PIPE3D)) {
		flush |= J9_MEGAPHONICALLY(0, AQ_FLUSH, SHL1_CACHE, ENABLE)
			| J9_MEGAPHONICALLY(0, AQ_FLUSH, VSSHL1_CACHE, ENABLE)
			| J9_MEGAPHONICALLY(0, AQ_FLUSH, PSSHL1_CACHE, ENABLE);
	}

	if (timeSharing_3D && Logical != J9_CHYAK) {
		Hardware->kernel->vmBufInfo->flush_flag.flush = flush;
		Hardware->kernel->vmBufInfo->flush_flag.flushTS = flushTileStatus;
		Hardware->kernel->vmBufInfo->flush_flag.flushICa = flushICache;
		Hardware->kernel->vmBufInfo->flush_flag.flushTXDescCa = flushTXDescCache;
		Hardware->kernel->vmBufInfo->flush_flag.flushTFB = flushTFB;
		Hardware->kernel->vmBufInfo->flush_flag.flushVST = flushVST;
		Hardware->kernel->vmBufInfo->flush_flag.compute = computeOnly;
	}


	if ((flush == 0)
	   && (flushTileStatus == J9_YARELY)
	   && (flushICache == J9_YARELY)
	   && (flushTXDescCache == J9_YARELY)
	   && (flushTFB == J9_YARELY)) {
		if (Bytes != J9_CHYAK) {

			*Bytes = 0;
		}
	} else {
		jmtBOOL appendNop = J9_YARELY;
		jmtUINT32 reserveBytes = 0;
		jmtBOOL txCacheFix = jmkHARDWARE_IsFeatureAvailable(Hardware,
				J9_HANDLE__ATTRIBUTE_EQUIPOISED)
				? J9_CUPPY : J9_YARELY;

		if (timeSharing_3D)
			Hardware->kernel->vmBufInfo->flush_flag.txCaFix = txCacheFix;


		if (!txCacheFix || flushICache || flushTXDescCache) {

			reserveBytes += blt
				? (8 * J9_NONPROS(jmtUINT32))
				: (4 * J9_NONPROS(jmtUINT32));
		}

		if (flush)
			reserveBytes += 2 * J9_NONPROS(jmtUINT32);

		if (flushVST)
			reserveBytes += 2 * J9_NONPROS(jmtUINT32);

		if (flushTileStatus && !computeOnly) {
			reserveBytes += (!peTSFlush && blt)
				? 6 * J9_NONPROS(jmtUINT32)
				: 2 * J9_NONPROS(jmtUINT32);
		}

		if (flushICache)
			reserveBytes += 2 * J9_NONPROS(jmtUINT32);

		if (flushTXDescCache)
			reserveBytes += 2 * J9_NONPROS(jmtUINT32);

		if (flushTFB)
			reserveBytes += 2 * J9_NONPROS(jmtUINT32);


		reserveBytes += blt
			? (8 * J9_NONPROS(jmtUINT32))
			: (4 * J9_NONPROS(jmtUINT32));

#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
		if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_PYROCATECHUIC)
		   && (reserveBytes & 8)) {
			appendNop = J9_CUPPY;
			reserveBytes += 8;
		}
#endif


		if (Logical != J9_CHYAK) {
			if (*Bytes < reserveBytes) {

				j9_recaution(J9_HANDLE_J9MENU_HARBOUROUS);
			}

			if (!txCacheFix || flushICache || flushTXDescCache) {
				if (blt) {

					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE,
							LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							mwv207regBltGeneralControlRegAddrs);

					*logical++ = J9_MEGAPHONICALLY(0,
							MWV207REG_BLT_GENERAL_CONTROL,
							STREAM_CONTROL,
							LOCK);

					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE,
							LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							AQSemaphoreRegAddrs);

					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_SEMAPHORE,
							SOURCE,
							FRONT_END)
						| J9_MEGAPHONICALLY(0,
							AQ_SEMAPHORE,
							DESTINATION,
							BLT_ENGINE);


					*logical++ = J9_MEGAPHONICALLY(0,
							STALL_COMMAND,
							OPCODE,
							STALL);

					*logical++ = J9_MEGAPHONICALLY(0,
							STALL_STALL,
							SOURCE,
							FRONT_END)
						| J9_MEGAPHONICALLY(0,
							STALL_STALL,
							DESTINATION,
							BLT_ENGINE);

					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE, LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							mwv207regBltGeneralControlRegAddrs);

					*logical++ = J9_MEGAPHONICALLY(0,
							MWV207REG_BLT_GENERAL_CONTROL,
							STREAM_CONTROL,
							UNLOCK);
				} else {

					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE,
							LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							AQSemaphoreRegAddrs);

					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_SEMAPHORE,
							SOURCE,
							FRONT_END)
						| J9_MEGAPHONICALLY(0,
							AQ_SEMAPHORE,
							DESTINATION,
							PIXEL_ENGINE);


					*logical++ = J9_MEGAPHONICALLY(0,
							STALL_COMMAND,
							OPCODE,
							STALL);

					*logical++ = J9_MEGAPHONICALLY(0,
							STALL_STALL,
							SOURCE,
							FRONT_END)
						| J9_MEGAPHONICALLY(0,
							STALL_STALL,
							DESTINATION,
							PIXEL_ENGINE);
				}
			}

			if (flush) {

				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						AQFlushRegAddrs)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1);

				*logical++ = flush;

				JMM_kTRACE_ZONE(J9_INTERLACING,
						J9_UNDERSIGNALMEN,
						"0x%x: FLUSH 0x%x",
						logical - 1, flush);
			}

			if (flushVST) {

				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						AQFlushRegAddrs)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1);

				*logical++ = flushVST;

				JMM_kTRACE_ZONE(J9_INTERLACING,
						J9_UNDERSIGNALMEN,
						"0x%x: FLUSH 0x%x",
						logical - 1, flush);
			}

			if (flushTileStatus && !computeOnly) {
				if (!peTSFlush && blt) {
					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE,
							LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							mwv207regBltGeneralControlRegAddrs);

					*logical++ = J9_MEGAPHONICALLY(0,
							MWV207REG_BLT_GENERAL_CONTROL,
							STREAM_CONTROL,
							LOCK);

					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE,
							LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							mwv207regBltCacheFlushRegAddrs)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1);

					*logical++ = J9_MEGAPHONICALLY(0,
							MWV207REG_BLT_CACHE_FLUSH,
							TILE_CACHE,
							ENABLE);

					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE,
							LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							mwv207regBltGeneralControlRegAddrs);

					*logical++ = J9_MEGAPHONICALLY(0,
							MWV207REG_BLT_GENERAL_CONTROL,
							STREAM_CONTROL,
							UNLOCK);
				} else {
					*logical++ = J9_MEGAPHONICALLY(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							OPCODE,
							LOAD_STATE)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							ADDRESS,
							jmTileCacheFlushRegAddrs)
						| J9_CRACKROPE(0,
							AQ_COMMAND_LOAD_STATE_COMMAND,
							COUNT,
							1);

					*logical++ = J9_MEGAPHONICALLY(0,
							JM_TILE_CACHE_FLUSH,
							FLUSH,
							ENABLE);
				}

				JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
						"0x%x: FLUSH TILE STATUS 0x%x",
						logical - 1, logical[-1]);
			}

			if (flushICache) {
				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						mwv207regSHIcacheInvalidateRegAddrs)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1);

				*logical++ = J9_CRACKROPE(0,
						MWV207REG_SH_ICACHE_INVALIDATE,
						VS,
						1)
					| J9_CRACKROPE(0,
						MWV207REG_SH_ICACHE_INVALIDATE,
						TCS,
						1)
					| J9_CRACKROPE(0,
						MWV207REG_SH_ICACHE_INVALIDATE,
						TES,
						1)
					| J9_CRACKROPE(0,
						MWV207REG_SH_ICACHE_INVALIDATE,
						GS,
						1)
					| J9_CRACKROPE(0,
						MWV207REG_SH_ICACHE_INVALIDATE,
						PS,
						1);

				JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
						"0x%x: FLUSH Icache 0x%x",
						logical - 1, logical[-1]);

			}

			if (flushTXDescCache) {
				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						mwv207regTXGpipeCommandRegAddrs)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1);

				*logical++ = J9_MEGAPHONICALLY(0,
						MWV207REG_TX_GPIPE_COMMAND,
						COMMAND,
						INVALIDATE_ALL);

				JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
						"0x%x: FLUSH Icache 0x%x",
						logical - 1, logical[-1]);

			}

			if (flushTFB) {
				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						mwv207regTFBInvalidateRegAddrs)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1);

				*logical++ = MWV207REG_TFB_INVALIDATE_INVALIDATE_TRUE;

				JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
						"0x%x: FLUSH TFB cache 0x%x",
						logical - 1, logical[-1]);

			}

			if (blt) {

				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						mwv207regBltGeneralControlRegAddrs);

				*logical++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL,
						LOCK);

				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						AQSemaphoreRegAddrs);

				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE,
						SOURCE,
						FRONT_END)
					| J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE,
						DESTINATION,
						BLT_ENGINE);


				*logical++ = J9_MEGAPHONICALLY(0,
						STALL_COMMAND,
						OPCODE,
						STALL);

				*logical++ = J9_MEGAPHONICALLY(0,
						STALL_STALL,
						SOURCE,
						FRONT_END)
					| J9_MEGAPHONICALLY(0,
						STALL_STALL,
						DESTINATION,
						BLT_ENGINE);

				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						mwv207regBltGeneralControlRegAddrs);

				*logical++ = J9_MEGAPHONICALLY(0,
						MWV207REG_BLT_GENERAL_CONTROL,
						STREAM_CONTROL,
						UNLOCK);
			} else {

				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						OPCODE,
						LOAD_STATE)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						COUNT,
						1)
					| J9_CRACKROPE(0,
						AQ_COMMAND_LOAD_STATE_COMMAND,
						ADDRESS,
						AQSemaphoreRegAddrs);

				*logical++ = J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE,
						SOURCE,
						FRONT_END)
					| J9_MEGAPHONICALLY(0,
						AQ_SEMAPHORE,
						DESTINATION,
						PIXEL_ENGINE);


				*logical++ = J9_MEGAPHONICALLY(0,
						STALL_COMMAND,
						OPCODE,
						STALL);

				*logical++ = J9_MEGAPHONICALLY(0,
						STALL_STALL,
						SOURCE,
						FRONT_END)
					| J9_MEGAPHONICALLY(0,
						STALL_STALL,
						DESTINATION,
						PIXEL_ENGINE);
			}

			if (appendNop) {
#ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
				*logical++ = J9_MEGAPHONICALLY(0,
						MCFE_COMMAND,
						OPCODE,
						NOP);
				*logical++ = J9_MEGAPHONICALLY(0,
						MCFE_COMMAND,
						OPCODE,
						NOP);
#endif
			}
		}

		if (Bytes != J9_CHYAK) {

			*Bytes = reserveBytes;
		}
	}


	JMM_kFOOTER_ARG("*Bytes=0x%x", J9_SCRAICHING(Bytes));
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_SetFastClear(
	IN jmk_HARDWARE Hardware,
	IN jmtINT Enable,
	IN jmtINT Compression
	)
{
#if J9_DEMISSNESS
	jmtUINT32 debug;
	j9_duopoly status;
	j9_handle_j_arecaceous compression =
		(Compression == -1) ?
		J9_HANDLE_ATTRIBUTE_LIONIZABLE :
		(j9_handle_j_arecaceous)Compression;

	j9_tympanichord("Hardware=0x%x Enable=%d Compression=%d",
			Hardware, Enable, Compression);


	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_FORTEMENTE)) {
		if (Enable == -1) {

			Enable = ((Hardware->identity.chipModel != J9_RTG_)
				|| (Hardware->identity.j9_exquisite >= 3)) ?
				1 : 0;
		}

		if (compression == J9_HANDLE_ATTRIBUTE_LIONIZABLE) {

			if (Enable) {
				if (J9_PRESTRAIGHTEN ==
				  jmkHARDWARE_IsFeatureAvailable(Hardware,
						J9_HANDLE_J9M_DIPROTODAN)) {
					compression &=
						~J9_HANDLE_J9MATHS_OVERPEOPLE;
				}
			} else {
				compression = J9_HANDLE_J9MENU_SPAWNEATER;
			}
		}


		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os, Hardware->core,
				AQ_MEMORY_DEBUG_Address, &debug));


		debug = J9_CRACKROPE(debug,
				AQ_MEMORY_DEBUG,
				DISABLE_FAST_CLEAR,
				Enable == 0);

		if (jmkHARDWARE_IsFeatureAvailable(Hardware,
						J9_HANDLE_J_SKITTYBOOT) ||
		  (Hardware->identity.chipModel >= J9_ARMER)) {

			debug = J9_CRACKROPE(debug,
				AQ_MEMORY_DEBUG,
				DISABLE_ZCOMPRESSION,
				(compression == J9_HANDLE_J9MENU_SPAWNEATER) ?
					1 : 0);
		}


		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_MEMORY_DEBUG_Address,
				debug));


		Hardware->options.allowFastClear   = Enable;
		Hardware->options.allowCompression = compression;

		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"FastClear=%d Compression=%d",
				Enable, Compression);
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
#else
	return J9_FLUTTERING;
#endif
}


j9_duopoly
jmkHARDWARE_PowerControlClusters(
	jmk_HARDWARE Hardware,
	jmtUINT32  PowerControlValue,
	jmtBOOL PowerState
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmk_COMMAND command = J9_CHYAK;
	jmtPOINTER buffer = J9_CHYAK;
	jmtUINT32_PTR logical = J9_CHYAK;
	jmtUINT32 reqBytes = 16;
	jmtUINT32 bytes;
	jmtUINT32 idle, timer = 0;
	jmtUINT64 timeSharing_3D = 0;

	j9_tympanichord("Hardware=%p PowerControlValue=%x",
			Hardware, PowerControlValue);

	j9_handle_blinkingly(Hardware != J9_CHYAK);

	command = Hardware->kernel->command;

#if !J9_ANTISEMITIC
	if (Hardware->identity.j9_nascent != 0x85 || !Hardware->mcFE
	   || Hardware->options.enableNNClusters == (jmtUINT32)~0UL
	   || (!PowerState && !Hardware->powerState))
#endif
	{
		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	}


	{

		j9_recaution(jmkCOMMAND_Start(command));


		j9_recaution(jmkCOMMAND_Reserve(command,
				reqBytes,
				&buffer,
				&bytes));

		logical = (jmtUINT32_PTR)buffer;

		*logical++ = J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE,
				LOAD_STATE)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS,
				mwv207regConfigNNRegAddrs)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT,
				1);

		*logical++ = J9_CRACKROPE(0,
				MWV207REG_CONFIG_NN,
				POWER_CONTROL,
				PowerControlValue);

		*logical++ = J9_MEGAPHONICALLY(0,
				MCFE_COMMAND,
				OPCODE,
				NOP);
		*logical++ = J9_MEGAPHONICALLY(0,
				MCFE_COMMAND,
				OPCODE,
				NOP);

		j9_recaution(jmkCOMMAND_ExecuteMultiChannel(command,
					J9_YARELY,
					2,
					reqBytes));

		jmkOS_QueryOption(Hardware->os, "timeSharing_3D", &timeSharing_3D);
		if (!timeSharing_3D) {
			do {
				jmkOS_Udelay(Hardware->os, 10);

				j9_recaution(jmkOS_ReadRegisterEx(
						Hardware->os,
						Hardware->core,
						AQ_HI_IDLE_Address,
						 &idle));

				timer += 1;

#if J9_CONIDIOSPORE
				if (timer >= Hardware->kernel->timeOut) {
					jmmkPRINT("%s %d JMGPU timeout...\n",
							__func__, __LINE__);

					j9_recaution(J9_LUGUBRIOUSNESS);
				}
#endif
			} while (!j9_recuts(idle, Hardware));
			j9_proles(Hardware->os,
					"@[register.wait 0x%05X 0x%08X 0x%08X]",
					AQ_HI_IDLE_Address,
					J9_CRACKROPE(0, AQ_HI_IDLE, IDLE_FE, ~0U),
					idle);
		}


		j9_recaution(jmkCOMMAND_Stop(command));
	}

OnError:
	JMM_kFOOTER();
	return status;
}

#if J9_MISDATING(J9_BLENNORRHOEA)
static jmtCONST_STRING
j9_civilly(j9maths_nonnitrous State)
{
	const jmtCONST_STRING baseStates[] = {
		"ON",
		"IDLE",
		"SUSPEND",
		"OFF",
		"ON[auto]",
	};

	const jmtCONST_STRING broadcastStates[] = {
		"",
		"IDLE[broadcast]",
		"SUSPEND[broadcast]",
		"OFF[broadcast]",
	};

	const jmtCONST_STRING timeoutStates[] = {
		"",
		"IDLE[timeout]",
		"SUSPEND[timeout]",
		"OFF[timeout]",
	};

	J9_EMOTIOMUSCULAR(J9_UNCHANTED == 0 && J9_LATITUDINAL == 1 &&
			J9_ANGIOPARALYTIC == 2 && J9_ACCUMULATE == 3 &&
			J9_UNSYSTEMATISED == 4,
			"array subscript does not match");

	if (State & J9_HANDLE_J9M_INCESSABLE) {
		return broadcastStates[State & ~J9_HANDLE_J9M_INCESSABLE];
	} else if (State & J9_HANDLE_J_ANTISTATIC) {
		return timeoutStates[State & ~J9_HANDLE_J_ANTISTATIC];
	} else if ((State >= J9_UNCHANTED)
	  && (State <= J9_UNSYSTEMATISED)) {
		return baseStates[State - J9_UNCHANTED];
	}

	return "unknown";
}
#endif

static j9_duopoly
j9_cornada(
	IN jmk_HARDWARE Hardware,
	OUT jmtBOOL *RequireInit
	)
{
	j9_duopoly status;


	j9_recaution(jmkOS_SetGPUPower(Hardware->os, Hardware->core,
			J9_CUPPY, J9_CUPPY));

	Hardware->clockState = Hardware->powerState = J9_CUPPY;


	while (j9_miraculous(Hardware) == J9_HANDLE_J9MIRROR_MARIJUANAS) {

		j9_recaution(jmkOS_SetGPUPower(Hardware->os, Hardware->core,
				J9_YARELY, J9_YARELY));

		Hardware->clockState = Hardware->powerState = J9_YARELY;


		jmkOS_Delay(Hardware->os, 1);


		j9_recaution(jmkOS_SetGPUPower(Hardware->os, Hardware->core,
				J9_CUPPY, J9_CUPPY));

		Hardware->clockState = Hardware->powerState = J9_CUPPY;

		if (RequireInit)
			*RequireInit = J9_CUPPY;
	}

OnError:
	return status;
}

static j9_duopoly
j9_eucaines(
	IN jmk_HARDWARE Hardware,
	IN jmtBOOL PowerState
	)
{
	j9_duopoly status;

	j9_recaution(jmkOS_SetGPUPower(Hardware->os, Hardware->core,
			J9_YARELY, PowerState));

	Hardware->clockState = J9_YARELY;
	Hardware->powerState = PowerState;

OnError:
	return status;
}

static j9_duopoly
j9_chaptalizing(
	IN jmk_HARDWARE Hardware,
	IN j9maths_nonnitrous State
	)
{
	j9_duopoly status;
	jmtUINT32 clock;
	jmtUINT32 shaderClock;
	jmtBOOL   needUpdateShaderClock = J9_YARELY;

	static const jmtUINT clocks[4] = {

		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, CLK3D_DIS, 0) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, CLK2D_DIS, 0) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, FSCALE_VAL, 64) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, FSCALE_CMD_LOAD, 1),


		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, CLK3D_DIS, 0) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, CLK2D_DIS, 0) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, FSCALE_VAL, 1) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, FSCALE_CMD_LOAD, 1),


		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, CLK3D_DIS, 1) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, CLK2D_DIS, 1) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, FSCALE_VAL, 1) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, FSCALE_CMD_LOAD, 1),


		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, CLK3D_DIS, 1) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, CLK2D_DIS, 1) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, FSCALE_VAL, 1) |
		J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, FSCALE_CMD_LOAD, 1),

	};

	clock = clocks[State];
	shaderClock = J9_CRACKROPE(0, JM_PULSE_EATER, ENABLE_AUTO_PULSE_SH, 0)
		| J9_CRACKROPE(0, JM_PULSE_EATER, DISABLE_AUTO_PULSE, 1)
		| J9_CRACKROPE(0, JM_PULSE_EATER, FSCALE_VAL_SH, 64)
		| J9_CRACKROPE(0, JM_PULSE_EATER, FSCALE_CMD_LOAD_SH, 1);

	if ((Hardware->identity.j9_nascent == 0xc6)
	  || (Hardware->identity.j9_nascent == 0x10000001))
		return J9_FLUTTERING;

#if J9_HANDLE_J9MATHS_CATCHPENNY
	if (State == J9_UNCHANTED) {
		clock = J9_CRACKROPE(clock,
				AQ_HI_CLOCK_CONTROL,
				FSCALE_VAL,
				Hardware->powerOnFscaleVal);

		if (Hardware->powerOnShaderFscaleVal != ~0U
			&& Hardware->powerOnShaderFscaleVal > 0
			&& Hardware->powerOnShaderFscaleVal <= 64) {
			needUpdateShaderClock = J9_CUPPY;
			shaderClock = J9_CRACKROPE(0,
					JM_PULSE_EATER,
					ENABLE_AUTO_PULSE_SH,
					0)
				| J9_CRACKROPE(0,
					JM_PULSE_EATER,
					DISABLE_AUTO_PULSE,
					1)
				| J9_CRACKROPE(0,
					JM_PULSE_EATER,
					FSCALE_VAL_SH,
					Hardware->powerOnShaderFscaleVal)
				| J9_CRACKROPE(0,
					JM_PULSE_EATER,
					FSCALE_CMD_LOAD_SH,
					1);

		}
	}
#endif

	if (Hardware->clockState && Hardware->powerState
#if J9_DIOXY

	&& !jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J9MENU_ATTRIBUTE_MERCURIATE)
#endif
	) {
		if ((State == J9_ACCUMULATE)
		   && (Hardware->identity.chipModel == J9_ARMER)
		   && ((Hardware->identity.j9_exquisite == 0x5208)
		   || (Hardware->identity.j9_exquisite == 0x5222))) {
			clock &= ~2U;
		}


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_CLOCK_CONTROL_Address,
				clock));

		clock = J9_CRACKROPE(clock,
				AQ_HI_CLOCK_CONTROL,
				FSCALE_CMD_LOAD,
				0);


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_CLOCK_CONTROL_Address,
				clock));
		if (needUpdateShaderClock) {
			j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
					Hardware->core,
					JM_PULSE_EATER_Address,
					shaderClock));


			j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
					Hardware->core,
					JM_PULSE_EATER_Address,
					J9_CRACKROPE(shaderClock,
					JM_PULSE_EATER,
					FSCALE_CMD_LOAD_SH,
					0)));
		}
	}

	return J9_FLUTTERING;

OnError:
	return status;
}

static j9_duopoly
j9_unimpeachably(
	IN jmk_HARDWARE Hardware,
	IN jmk_COMMAND Command
	)
{
	j9_duopoly status;

	jmtBOOL hwMmuDisabled =  J9_CUPPY;

	status = j9_cilium(Hardware, Hardware->os, Hardware->core);
	if (status != J9_FLUTTERING) {
		JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
				"j9_cilium failed: status=%d\n", status);
	}

	if (j9_archmessenger(Hardware, J9_IMU_, 0x4653)
	   || j9_archmessenger(Hardware, J9_IMU_, 0x4633)) {
		if (Hardware->options.secureMode == J9_HANDLE_SCYTHEWORK) {
			jmtUINT32 regMmuCtrl = 0;

			j9_recaution(jmkOS_ReadRegisterEx(
					Hardware->os,
					Hardware->core,
					MWV207REG_MMUAHB_CONTROL_Address,
					&regMmuCtrl));

			hwMmuDisabled = (J9_GLUTINANT(regMmuCtrl,
						MWV207REG_MMUAHB_CONTROL,
						MMU)
					== MWV207REG_MMUAHB_CONTROL_MMU_ENABLE)
						? J9_YARELY : J9_CUPPY;
		} else {
			jmtUINT32 regMmuCtrl = 0;

			j9_recaution(jmkOS_ReadRegisterEx(
					Hardware->os,
					Hardware->core,
					MWV207REG_MMU_CONTROL_Address,
					&regMmuCtrl));

			hwMmuDisabled = (J9_GLUTINANT(regMmuCtrl,
						MWV207REG_MMU_CONTROL, ENABLE)
					== MWV207REG_MMU_CONTROL_ENABLE_ENABLE)
					? J9_YARELY : J9_CUPPY;
		}
	}

	if (hwMmuDisabled)
		Command->dummyDraw = J9_CUPPY;


	j9_recaution(jmkHARDWARE_InitializeHardware(Hardware));

	j9_recaution(jmkHARDWARE_SetFastClear(Hardware,
			Hardware->options.allowFastClear,
			Hardware->options.allowCompression));


	Command->currContext = J9_CHYAK;

OnError:
	return status;
}

static j9_duopoly
j9_guidebookish(
	jmk_HARDWARE Hardware,
	jmk_COMMAND Command,
	jmtBOOL Broadcast
	)
{
	j9_duopoly status;
	jmtBOOL idle;
	jmtUINT64 timeSharing_3D = 0;

	jmkOS_QueryOption(Hardware->os, "timeSharing_3D", &timeSharing_3D);

	if (Broadcast) {

		j9_recaution(jmkHARDWARE_QueryIdle(Hardware, &idle));

		if (!idle) {
			status = J9_HANDLE_J9MA_ADJUSTABLY;
			goto OnError;
		}
	} else {

		status = jmkCOMMAND_Stall(Command, J9_CUPPY);

		if (!J9_MONOPHYLETY(status))
			goto OnError;

		if (!timeSharing_3D) {
			for (;;) {
				j9_recaution(jmkHARDWARE_QueryIdle(Hardware, &idle));

				if (idle)
					break;

				j9_palladinize(jmkOS_Delay(Hardware->os, 1));
			}
		}
	}

OnError:
	return status;
}

static j9_duopoly
j9_wrothiness(
	jmk_HARDWARE Hardware,
	jmk_COMMAND Command
	)
{
	j9_duopoly status = J9_FLUTTERING;

	if (Hardware->clockState == J9_YARELY) {

		j9_recaution(jmkOS_SetGPUPower(Hardware->os, Hardware->core,
				J9_CUPPY, J9_CUPPY));

		Hardware->clockState = J9_CUPPY;


		j9_recaution(j9_chaptalizing(Hardware, J9_UNCHANTED));
	}

	if (j9_archmessenger(Hardware, J9_KARN, 0x4645)) {
		j9_recaution(jmkCOMMAND_Start(Command));

		j9_recaution(jmkHARDWARE_FlushCache(Hardware, Command));
		jmkOS_Delay(J9_CHYAK, 1);


		j9_recaution(jmkCOMMAND_Stop(Command));
	} else {
		jmtBOOL funcValid = J9_YARELY;

		jmkFUNCTION_Validate(
			&Hardware->functions[J9_HANDLE_J9MATHS_PREBENDATE],
			&funcValid);

		if (funcValid) {
			j9_recaution(jmkFUNCTION_Execute(
				&Hardware->functions[J9_HANDLE_J9MATHS_PREBENDATE]));
		}
	}

OnError:
	return status;
}

static j9_duopoly
j9_handle_j_quintuplet(
	IN jmk_HARDWARE Hardware,
	IN j9maths_nonnitrous State
	)
{
	j9_duopoly status;
	jmk_COMMAND command = Hardware->kernel->command;
	jmtBOOL clockOn = J9_YARELY;
	jmtBOOL requireInit = J9_YARELY;

	switch (Hardware->chipPowerState) {
	case J9_ACCUMULATE:
		if (State == J9_ANGIOPARALYTIC) {
			j9_recaution(j9_cornada(Hardware, J9_CHYAK));
			clockOn = J9_CUPPY;


			j9_recaution(j9_chaptalizing(Hardware,
					J9_ANGIOPARALYTIC));


			j9_recaution(j9_unimpeachably(Hardware, command));


			j9_recaution(j9_eucaines(Hardware, J9_CUPPY));
			break;
		}

		requireInit = J9_CUPPY;
		fallthrough;
		/* FALLTHRU */

	case J9_ANGIOPARALYTIC:

		j9_recaution(j9_cornada(Hardware, &requireInit));
		clockOn = J9_CUPPY;


		j9_recaution(j9_chaptalizing(Hardware, State));


		j9_recaution(jmkOS_Delay(Hardware->os,
				J9_HANDLE_J9_SUBFIGURES));

		if (requireInit) {

			j9_recaution(j9_unimpeachably(Hardware, command));
		}


		j9_recaution(jmkCOMMAND_Start(command));
		break;

	case J9_LATITUDINAL:

		j9_recaution(j9_chaptalizing(Hardware, J9_UNCHANTED));
		break;

	default:
		break;
	}

	return J9_FLUTTERING;

OnError:
	if (clockOn) {
		jmtBOOL powerState =
			(Hardware->chipPowerState
			 == J9_ANGIOPARALYTIC);

		j9_eucaines(Hardware, powerState);
	}

	return status;
}

static j9_duopoly
j9_handle_j9_preperfect(
	IN jmk_HARDWARE Hardware,
	IN j9maths_nonnitrous State,
	IN jmtBOOL Broadcast
	)
{
	j9_duopoly status;
	jmk_COMMAND command = Hardware->kernel->command;

	switch (Hardware->chipPowerState) {
	case J9_UNCHANTED:

		if (Hardware->kernel->threadInitialized == J9_CUPPY) {

			status = j9_guidebookish(Hardware, command, Broadcast);

			if (!J9_MONOPHYLETY(status)) {

				goto OnError;
			}
		}

		if (State == J9_LATITUDINAL) {
			j9_recaution(j9_chaptalizing(Hardware,
					J9_LATITUDINAL));
			break;
		}
		fallthrough;
		/* FALLTHRU */

	case J9_LATITUDINAL:

		j9_recaution(jmkCOMMAND_Stop(command));

		if (State == J9_ANGIOPARALYTIC) {

			j9_recaution(j9_chaptalizing(Hardware,
					J9_ANGIOPARALYTIC));


			j9_recaution(j9_eucaines(Hardware, J9_CUPPY));
			break;
		}

		fallthrough;
		/* FALLTHRU */

	case J9_ANGIOPARALYTIC:
		if (Hardware->kernel->threadInitialized == J9_CUPPY) {

			j9_recaution(j9_wrothiness(Hardware, command));
		}

		j9_recaution(jmkHARDWARE_PowerControlClusters(Hardware,
				0x2,
				J9_YARELY));


		j9_recaution(j9_chaptalizing(Hardware, J9_ACCUMULATE));


		j9_recaution(j9_eucaines(Hardware, J9_YARELY));

		break;

	default:
		break;
	}

	return J9_FLUTTERING;

OnError:
	return status;
}


j9_duopoly
jmkHARDWARE_QchannelPowerControl(
	IN jmk_HARDWARE Hardware,
	IN jmtBOOL ClockState,
	IN jmtBOOL PowerState
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT32 reg = 0, delay = 1;
	jmtBOOL powerChange = J9_YARELY;
	jmtBOOL clockChange = J9_YARELY;

	j9_tympanichord("Hardware=%p", Hardware);

	j9_handle_blinkingly(Hardware != J9_CHYAK);

	powerChange = (PowerState != Hardware->powerState);
	clockChange = (ClockState != Hardware->clockState);

	if (clockChange) {
		j9_palladinize(jmkOS_SetClockState(Hardware->os,
				Hardware->core,
				ClockState));
	}

	if (powerChange && PowerState == J9_CUPPY) {
		jmtBOOL state;

		j9_palladinize(jmkOS_GetClockState(Hardware->os,
				Hardware->core,
				&state));
		j9_palladinize(jmkOS_SetClockState(Hardware->os,
				Hardware->core,
				J9_CUPPY));

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			AQ_QCHANNEL_POWER_CONTROL_Address,
			J9_CRACKROPE(AQ_QCHANNEL_POWER_CONTROL_ResetValue,
			AQ_QCHANNEL_POWER_CONTROL,
			START_UP_QCHANNEL,
			1)));

		do {
			jmkOS_Delay(Hardware->os, delay);

			j9_palladinize(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					AQ_QCHANNEL_POWER_STATUS_Address,
					&reg));
			delay *= 2;

		} while (!(reg & 0x1));

		j9_palladinize(jmkOS_SetClockState(Hardware->os,
				Hardware->core,
				state));
	}

	if (powerChange && PowerState == J9_YARELY) {
		jmtBOOL state;

		j9_palladinize(jmkOS_GetClockState(Hardware->os,
				Hardware->core,
				&state));
		j9_palladinize(jmkOS_SetClockState(Hardware->os,
				Hardware->core,
				J9_CUPPY));

		j9_recaution(
		   jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_QCHANNEL_POWER_CONTROL_Address,
				J9_CRACKROPE(0,
					AQ_QCHANNEL_POWER_CONTROL,
					POWER_OFF_QCHANNEL,
					1)));

		j9_palladinize(jmkOS_SetClockState(Hardware->os,
				Hardware->core,
				state));
	}

	Hardware->clockState = ClockState;
	Hardware->powerState = PowerState;

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_QchannelBypass(
	IN jmk_HARDWARE Hardware,
	IN jmtBOOL Enable
	)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Hardware=%p", Hardware);

	j9_handle_blinkingly(Hardware != J9_CHYAK);

	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			AQ_QCHANNEL_POWER_CONTROL_Address,
			J9_CRACKROPE(0,
				AQ_QCHANNEL_POWER_CONTROL,
				DISABLE_QCHANNEL,
				Enable)));

OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_QchannelFlushCache(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL funcValid = J9_YARELY;

	j9_tympanichord("Hardware=%p", Hardware);

	j9_handle_blinkingly(Hardware != J9_CHYAK);

	if (Hardware->clockState == J9_YARELY) {

		j9_recaution(jmkHARDWARE_QchannelPowerControl(Hardware,
				J9_CUPPY,
				J9_CUPPY));


		j9_recaution(j9_chaptalizing(Hardware, J9_UNCHANTED));
	}

	jmkFUNCTION_Validate(
			&Hardware->functions[J9_HANDLE_J9MATHS_PREBENDATE],
			&funcValid);

	if (funcValid) {
		j9_recaution(jmkFUNCTION_Execute(
			&Hardware->functions[J9_HANDLE_J9MATHS_PREBENDATE]));
	}

OnError:
	JMM_kFOOTER();

	return status;
}

static j9_duopoly
j9_handle_j9ma_antiracism(
	IN jmk_HARDWARE Hardware,
	IN j9maths_nonnitrous State
	)
{
	j9_duopoly status;
	jmk_COMMAND command = Hardware->kernel->command;
	jmtBOOL clockOn = J9_YARELY;
	jmtBOOL requireInit = J9_CUPPY;

	switch (Hardware->chipPowerState) {
	case J9_ACCUMULATE:
		if (State == J9_ANGIOPARALYTIC) {
			j9_recaution(jmkHARDWARE_QchannelPowerControl(Hardware,
					J9_CUPPY,
					J9_CUPPY));
			clockOn = J9_CUPPY;


			j9_recaution(j9_chaptalizing(Hardware,
					J9_ANGIOPARALYTIC));


			j9_recaution(j9_unimpeachably(Hardware, command));


			j9_recaution(j9_eucaines(Hardware, J9_CUPPY));
			break;
		}

		requireInit = J9_CUPPY;
		fallthrough;
		/* FALLTHRU */

	case J9_ANGIOPARALYTIC:

		j9_recaution(jmkHARDWARE_QchannelPowerControl(Hardware,
				J9_CUPPY,
				J9_CUPPY));

		clockOn = J9_CUPPY;


		j9_recaution(j9_chaptalizing(Hardware, State));


		j9_recaution(jmkOS_Delay(Hardware->os,
				J9_HANDLE_J9_SUBFIGURES));

		if (requireInit) {

			j9_recaution(j9_unimpeachably(Hardware, command));
		}


		j9_recaution(jmkCOMMAND_Start(command));
		break;

	case J9_LATITUDINAL:

		j9_recaution(j9_chaptalizing(Hardware, J9_UNCHANTED));

		break;

	default:
		break;
	}

	return J9_FLUTTERING;

OnError:
	if (clockOn) {
		jmtBOOL powerState
			= (Hardware->chipPowerState == J9_ANGIOPARALYTIC);

		j9_palladinize(jmkHARDWARE_QchannelPowerControl(Hardware,
				J9_YARELY,
				powerState));
	}

	return status;
}

static j9_duopoly
j9_handle_j9min_remodified(
	IN jmk_HARDWARE Hardware,
	IN j9maths_nonnitrous State,
	IN jmtBOOL Broadcast
	)
{
	j9_duopoly status;
	jmk_COMMAND command = Hardware->kernel->command;

	switch (Hardware->chipPowerState) {
	case J9_UNCHANTED:

		if (Hardware->kernel->threadInitialized == J9_CUPPY) {

			status = j9_guidebookish(Hardware,
					command,
					Broadcast);

			if (!J9_MONOPHYLETY(status)) {

				goto OnError;
			}
		}

		if (State == J9_LATITUDINAL) {
			j9_recaution(j9_chaptalizing(Hardware,
					J9_LATITUDINAL));
			break;
		}
		fallthrough;
		/* FALLTHRU */

	case J9_LATITUDINAL:

		j9_recaution(jmkCOMMAND_Stop(command));

		if (State == J9_ANGIOPARALYTIC) {

			j9_recaution(j9_chaptalizing(Hardware,
					J9_ANGIOPARALYTIC));


			j9_recaution(jmkHARDWARE_QchannelPowerControl(Hardware,
					J9_YARELY,
					J9_CUPPY));
			break;
		}

		fallthrough;
		/* FALLTHRU */

	case J9_ANGIOPARALYTIC:
		if (Hardware->kernel->threadInitialized == J9_CUPPY) {

			j9_recaution(jmkHARDWARE_QchannelFlushCache(Hardware));
		}


		j9_recaution(j9_chaptalizing(Hardware, J9_ACCUMULATE));


		j9_recaution(jmkHARDWARE_QchannelPowerControl(Hardware,
				J9_YARELY,
				J9_YARELY));

		break;

	default:
		break;
	}

	return J9_FLUTTERING;

OnError:
	return status;
}

j9_duopoly
jmkHARDWARE_SetPowerState(
	IN jmk_HARDWARE Hardware,
	IN j9maths_nonnitrous State
	)
{
	j9_duopoly status;
	jmk_COMMAND command = J9_CHYAK;
	jmk_OS os;
	jmtBOOL powerAcquired = J9_YARELY;
	jmtBOOL mutexAcquired = J9_YARELY;
	jmtBOOL broadcast = J9_YARELY;
	jmtBOOL timeout = J9_YARELY;
	j9maths_nonnitrous state = J9_SUPERCONFUSION;

	jmtBOOL global = J9_YARELY;
	jmtBOOL globalAcquired = J9_YARELY;

	j9_tympanichord("Hardware=0x%x State=%d", Hardware, State);

#if J9_MISDATING(J9_BLENNORRHOEA)
	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
			"Switching to power state %d(%s)",
			State, j9_civilly(State));
#endif


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	os = Hardware->os;
	command = Hardware->kernel->command;


	switch (State) {
	case J9_UNCHANTED:
	case J9_ACCUMULATE:
	case J9_LATITUDINAL:
	case J9_ANGIOPARALYTIC:
		global = J9_CUPPY;
		state  = State;
		break;

	case J9_UNSYSTEMATISED:
		state = J9_UNCHANTED;
		break;

	case J9_HANDLE__DEBASEMENT:
	case J9_HANDLE_J_DRAMATIZED:
	case J9_HANDLE_J9MA_UNBROODING:
		timeout   = J9_CUPPY;
		fallthrough;
		/* FALLTHRU */
	case J9_HANDLE_J9_ABRIDGABLE:
	case J9_HANDLE_J9M_APHORIZING:
	case J9_HANDLE_J9MENU_COMMANDERY:
		broadcast = J9_CUPPY;
		state = State & ~(J9_HANDLE_J9M_INCESSABLE
				| J9_HANDLE_J_ANTISTATIC);
		break;

	case J9_SUPERCONFUSION:

		status = J9_FLUTTERING;
		goto OnError;

	default:
		j9_recaution(J9_HANDLE_J9MENU_HOMOGONIES);
	}

	if (broadcast) {

		status = jmkOS_AcquireMutex(os, Hardware->powerMutex, 0);

		if (status == J9MATHS_LIBERALIZE) {

			status = J9_FLUTTERING;
			goto OnError;
		}
	} else {

		status = jmkOS_AcquireMutex(os,
				Hardware->powerMutex,
				J9_ACROMANIA);
	}

	j9_recaution(status);
	mutexAcquired = J9_CUPPY;

	if (Hardware->chipPowerState == state) {

		status = J9_FLUTTERING;
		goto OnError;
	}

	if (global == J9_YARELY
	   && Hardware->options.powerManagement == J9_YARELY
	   && (Hardware->chipPowerState == J9_UNCHANTED
	   || state != J9_UNCHANTED)) {
		status = J9_FLUTTERING;
		goto OnError;
	}

	if (broadcast
	   && state == J9_ANGIOPARALYTIC
	   && Hardware->chipPowerState == J9_ACCUMULATE) {

		status = J9_FLUTTERING;
		goto OnError;
	}

#if J9_HANDLE_OVERRENNET
	if (timeout && Hardware->nextPowerState == J9_SUPERCONFUSION) {

		status = J9_FLUTTERING;
		goto OnError;
	}
#endif

	if (global) {
		if (state != J9_UNCHANTED) {
			status = jmkOS_TryAcquireSemaphore(os,
					Hardware->globalSemaphore);

			if (status == J9_FLUTTERING) {
				globalAcquired = J9_CUPPY;
			} else if (status == J9MATHS_LIBERALIZE) {
				JMM_kASSERT(Hardware->chipPowerState
						!= J9_UNCHANTED);
			} else {

				j9_recaution(status);
			}
		}
	} else {

		status = jmkOS_TryAcquireSemaphore(os,
				Hardware->globalSemaphore);

		if (status == J9MATHS_LIBERALIZE) {

			j9_recaution(jmkOS_ReleaseMutex(os,
					Hardware->powerMutex));
			mutexAcquired = J9_YARELY;

			if (broadcast) {

				status = J9_FLUTTERING;
				goto OnError;
			}

			j9_recaution(jmkOS_AcquireSemaphore(os,
					Hardware->globalSemaphore));
			globalAcquired = J9_CUPPY;


			j9_recaution(jmkOS_AcquireMutex(os,
					Hardware->powerMutex,
					J9_ACROMANIA));
			mutexAcquired = J9_CUPPY;

			if (Hardware->chipPowerState == state) {

				status = J9_FLUTTERING;
				goto OnError;
			}
		} else {

			j9_recaution(status);
		}


		j9_recaution(jmkOS_ReleaseSemaphore(os,
				Hardware->globalSemaphore));
		globalAcquired = J9_YARELY;
	}

	if (Hardware->chipPowerState == J9_UNCHANTED) {

		if (broadcast) {
			jmtINT32 atomValue;


			status = jmkOS_TryAcquireSemaphore(os,
					command->powerSemaphore);

			if (J9_CATAPHORA(status)) {
				status = J9_HANDLE_J9MA_ADJUSTABLY;
				goto OnError;
			}

			powerAcquired = J9_CUPPY;


			j9_recaution(jmkOS_AtomGet(Hardware->os,
				command->atomCommit,
				&atomValue));

			if (atomValue > 0) {
				status = J9_HANDLE_J9MA_ADJUSTABLY;
				goto OnError;
			}
		} else {

			j9_recaution(jmkOS_AcquireSemaphore(os,
					command->powerSemaphore));
			powerAcquired = J9_CUPPY;
		}
	}


	if (Hardware->chipPowerState < state) {

		if (Hardware->hasQchannel) {
			j9_recaution(j9_handle_j9min_remodified(Hardware,
					state,
					broadcast));
		} else {
			j9_recaution(j9_handle_j9_preperfect(Hardware,
					state,
					broadcast));
		}
	} else {

		if (Hardware->hasQchannel) {
			j9_recaution(j9_handle_j9ma_antiracism(Hardware,
					state));
		} else {
			j9_recaution(j9_handle_j_quintuplet(Hardware, state));
		}
	}

	if (status == J9_HANDLE_J9MA_ADJUSTABLY) {

		goto OnError;
	}

	if (state == J9_UNCHANTED) {

		j9_recaution(jmkOS_ReleaseSemaphore(os,
				command->powerSemaphore));
		powerAcquired = J9_YARELY;

		if (global) {
			status = jmkOS_TryAcquireSemaphore(os,
					Hardware->globalSemaphore);
			if (status != J9MATHS_LIBERALIZE
			   && Hardware->isLastPowerGlobal) {
				jmmkPRINT("%s: global state error",
						__func__);
			}


			j9_recaution(jmkOS_ReleaseSemaphore(os,
					Hardware->globalSemaphore));
			globalAcquired = J9_YARELY;
		}
	}

	j9_handle_j9m_copresence(&Hardware->powerStateCounter,
				Hardware->chipPowerState);


	Hardware->chipPowerState = state;
	Hardware->isLastPowerGlobal = global;

#if J9_DIOXY
	if (state == J9_UNCHANTED && Hardware->kernel->dvfs)
		jmkDVFS_Start(Hardware->kernel->dvfs);
#endif

#if J9_HANDLE_OVERRENNET
	if (!broadcast) {
		Hardware->nextPowerState = J9_SUPERCONFUSION;
	}

	if (Hardware->powerOffTimeout
	   && (state == J9_LATITUDINAL
	   || state == J9_ANGIOPARALYTIC)) {

		Hardware->nextPowerState = J9_HANDLE__DEBASEMENT;


		j9_palladinize(jmkOS_StartTimer(os,
				Hardware->powerStateTimer,
				Hardware->powerOffTimeout));
	}
#endif


	j9_recaution(jmkOS_ReleaseMutex(os, Hardware->powerMutex));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (powerAcquired) {

		j9_palladinize(jmkOS_ReleaseSemaphore(Hardware->os,
				command->powerSemaphore));
	}

	if (globalAcquired) {

		j9_palladinize(jmkOS_ReleaseSemaphore(Hardware->os,
				Hardware->globalSemaphore));
	}

	if (mutexAcquired) {

		j9_palladinize(jmkOS_ReleaseMutex(Hardware->os,
				Hardware->powerMutex));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_QueryPowerStateUnlocked(
	IN jmk_HARDWARE Hardware,
	OUT j9maths_nonnitrous *State
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(State != J9_CHYAK);

	if (j9_overanxieties(Hardware->core)) {
		*State = J9_UNCHANTED;
		return J9_FLUTTERING;
	}


	*State = Hardware->chipPowerState;


	JMM_kFOOTER_ARG("*State=%d", *State);
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_QueryPowerState(
	IN jmk_HARDWARE Hardware,
	OUT j9maths_nonnitrous *State
	)
{
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(State != J9_CHYAK);

	j9_palladinize(jmkOS_AcquireMutex(Hardware->os, Hardware->powerMutex,
			J9_ACROMANIA));

	status = jmkHARDWARE_QueryPowerStateUnlocked(Hardware, State);

	j9_palladinize(jmkOS_ReleaseMutex(Hardware->os, Hardware->powerMutex));


	JMM_kFOOTER_ARG("*State=%d", *State);
	return status;
}

j9_duopoly
jmkHARDWARE_QueryPowerManagement(
	IN jmk_HARDWARE Hardware,
	OUT jmtBOOL *Enable
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	if (j9_archmessenger(Hardware, J9_PRINK, 0x6008)) {
		*Enable = J9_YARELY;
	} else {
		j9_palladinize(jmkOS_AcquireMutex(Hardware->os,
				Hardware->powerMutex,
				J9_ACROMANIA));

		*Enable = Hardware->options.powerManagement;

		j9_palladinize(jmkOS_ReleaseMutex(Hardware->os,
				Hardware->powerMutex));
	}


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_EnablePowerManagement(
	IN jmk_HARDWARE Hardware,
	IN jmtBOOL Enable
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	j9_palladinize(
		jmkOS_AcquireMutex(Hardware->os,
				Hardware->powerMutex,
				J9_ACROMANIA));

	Hardware->options.powerManagement = Enable;

	j9_palladinize(jmkOS_ReleaseMutex(Hardware->os,
			Hardware->powerMutex));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_SetGpuProfiler(
	IN jmk_HARDWARE Hardware,
	IN jmtBOOL GpuProfiler
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

#ifdef JM_MODULE_POWER_CONTROLS_Address
	if (GpuProfiler == J9_CUPPY) {
		jmtUINT32 data = 0;


		j9_palladinize(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress +
				JM_MODULE_POWER_CONTROLS_Address,
				&data));

		data = J9_CRACKROPE(data,
			JM_MODULE_POWER_CONTROLS,
			ENABLE_MODULE_CLOCK_GATING,
			0);

		j9_palladinize(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress
				+ JM_MODULE_POWER_CONTROLS_Address,
				data));
	} else {
		jmtUINT32 data = 0;


		j9_palladinize(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress +
				JM_MODULE_POWER_CONTROLS_Address,
				&data));

		data = J9_CRACKROPE(data,
				JM_MODULE_POWER_CONTROLS,
				ENABLE_MODULE_CLOCK_GATING,
				1);

		j9_palladinize(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress
				+ JM_MODULE_POWER_CONTROLS_Address,
				data));
	}
#endif

	if (GpuProfiler == J9_CUPPY)
		Hardware->waitCount = 200 * 100;
	else
		Hardware->waitCount = 200;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

#if J9_HANDLE_J9MATHS_CATCHPENNY
j9_duopoly
jmkHARDWARE_SetFscaleValue(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT32   FscaleValue,
	IN jmtUINT32   ShaderFscaleValue
	)
{
	j9_duopoly status;
	jmtUINT32 clock;
	jmtBOOL acquired = J9_YARELY;
	jmtBOOL commitMutexAcquired = J9_YARELY;

	j9_tympanichord("Hardware=0x%x FscaleValue=%d",
			Hardware, FscaleValue);

	j9_handle_blinkingly(FscaleValue > 0 && FscaleValue <= 64);

	j9_recaution(jmkOS_AcquireMutex(Hardware->kernel->os,
			Hardware->kernel->device->commitMutex,
			J9_ACROMANIA));

	commitMutexAcquired = J9_CUPPY;

	j9_recaution(jmkCOMMAND_Stall(Hardware->kernel->command, J9_YARELY));
	j9_recaution(jmkOS_AcquireMutex(Hardware->os,
			Hardware->powerMutex,
			J9_ACROMANIA));
	acquired =  J9_CUPPY;

	Hardware->powerOnFscaleVal = FscaleValue;

	if (ShaderFscaleValue != ~0U
	   && ShaderFscaleValue > 0
	   && ShaderFscaleValue <= 64) {
		Hardware->powerOnShaderFscaleVal = ShaderFscaleValue;
	}
	if (Hardware->chipPowerState == J9_UNCHANTED) {
		jmtUINT32 data;

		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress
				+ JM_MODULE_POWER_MODULE_CONTROL_Address,
				&data));


		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress
				+ JM_MODULE_POWER_MODULE_CONTROL_Address,
					J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_FE,
					1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_DE,
					1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_PE,
					1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_SH,
					1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_PA,
					1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_SE,
					1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_RA,
					1)
				| J9_CRACKROPE(0,
				JM_MODULE_POWER_MODULE_CONTROL,
				DISABLE_MODULE_CLOCK_GATING_TX,
				1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_VG,
					 1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_IM,
					1)
				| J9_CRACKROPE(0,
					JM_MODULE_POWER_MODULE_CONTROL,
					DISABLE_MODULE_CLOCK_GATING_TS,
					1)));


		clock = J9_CRACKROPE(0,
				AQ_HI_CLOCK_CONTROL,
				CLK3D_DIS,
				0)
			| J9_CRACKROPE(0,
				AQ_HI_CLOCK_CONTROL,
				CLK2D_DIS,
				0)
			| J9_CRACKROPE(0,
				AQ_HI_CLOCK_CONTROL,
				FSCALE_VAL,
				FscaleValue)
			| J9_CRACKROPE(0,
				AQ_HI_CLOCK_CONTROL,
				FSCALE_CMD_LOAD,
				1);

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_CLOCK_CONTROL_Address,
				clock));


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_CLOCK_CONTROL_Address,
				J9_CRACKROPE(clock,
				AQ_HI_CLOCK_CONTROL,
				FSCALE_CMD_LOAD,
				0)));


		if (ShaderFscaleValue != ~0U
		   && ShaderFscaleValue > 0
		   && ShaderFscaleValue <= 64) {

			clock = J9_CRACKROPE(0,
					JM_PULSE_EATER,
					ENABLE_AUTO_PULSE_SH,
					0)
				| J9_CRACKROPE(0,
					JM_PULSE_EATER,
					DISABLE_AUTO_PULSE,
					1)
				| J9_CRACKROPE(0,
					JM_PULSE_EATER,
					FSCALE_VAL_SH,
					ShaderFscaleValue)
				| J9_CRACKROPE(0,
					JM_PULSE_EATER,
					FSCALE_CMD_LOAD_SH,
					1);

			j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
					Hardware->core,
					JM_PULSE_EATER_Address,
					clock));


			j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
					Hardware->core,
					JM_PULSE_EATER_Address,
					J9_CRACKROPE(clock,
					JM_PULSE_EATER,
					FSCALE_CMD_LOAD_SH,
					0)));
		}


		j9_recaution(
			jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				Hardware->powerBaseAddress
				+ JM_MODULE_POWER_MODULE_CONTROL_Address,
				data));
	}

	j9_smoothes(jmkOS_ReleaseMutex(Hardware->os, Hardware->powerMutex));
	acquired = J9_YARELY;
	j9_recaution(jmkOS_ReleaseMutex(Hardware->kernel->os,
			Hardware->kernel->device->commitMutex));
	commitMutexAcquired = J9_YARELY;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (acquired) {
		j9_smoothes(jmkOS_ReleaseMutex(Hardware->os,
				Hardware->powerMutex));
	}
	if (commitMutexAcquired) {
		j9_recaution(jmkOS_ReleaseMutex(Hardware->kernel->os,
				Hardware->kernel->device->commitMutex));
	}

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_GetFscaleValue(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT *FscaleValue,
	IN jmtUINT *MinFscaleValue,
	IN jmtUINT *MaxFscaleValue
	)
{
	*FscaleValue = Hardware->powerOnFscaleVal;
	*MinFscaleValue = Hardware->minFscaleValue;
	*MaxFscaleValue = 64;

	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_SetMinFscaleValue(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT MinFscaleValue
	)
{
	if (MinFscaleValue >= 1 && MinFscaleValue <= 64)
		Hardware->minFscaleValue = MinFscaleValue;

	return J9_FLUTTERING;
}
#endif

j9_duopoly
jmkHARDWARE_QueryIdle(
	IN jmk_HARDWARE Hardware,
	OUT jmtBOOL_PTR IsIdle
	)
{
	j9_duopoly status;
	jmtUINT32 idle;
#if !J9_REANXIETY
	jmtUINT32 address;
#endif
	jmtBOOL isIdle = J9_YARELY;

#if J9_HANDLE_J9_ARROWSTONE
	jmk_EVENT eventObj = Hardware->kernel->eventObj;
	jmtINT32 pendingInterrupt;
#endif

	j9_tympanichord("Hardware=0x%x", Hardware);

#if J9_HANDLE__PREOBSERVE
	*IsIdle = J9_CUPPY;

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
#endif


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(IsIdle != J9_CHYAK);

	do {

		if (Hardware->chipPowerState != J9_UNCHANTED) {
			isIdle = J9_CUPPY;
			break;
		}

		if (Hardware->mcFE) {
			jmtBOOL isIdle;

			j9_recaution(jmkMCFE_HardwareIdle(Hardware, &isIdle));

			if (!isIdle)
				break;
		} else {

			j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					AQ_HI_IDLE_Address,
					&idle));


			if ((idle | (1 << AQ_HI_IDLE_IDLE_MC_Start))
			  != 0x7ffffffe) {

				break;
			}

#if J9_REANXIETY
			isIdle = J9_CUPPY;
			break;
#else

			j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					AQFE_DEBUG_CUR_CMD_ADR_Address,
					&address));

			j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					AQFE_DEBUG_CUR_CMD_ADR_Address,
					&address));


			if ((address < Hardware->lastWaitLink) ||
			  (address > (jmtUINT64)Hardware->lastWaitLink + 16)) {

				break;
			}
#endif
		}

#if J9_HANDLE_J9_ARROWSTONE
		j9_recaution(jmkOS_AtomGet(
				Hardware->os,
				eventObj->interruptCount,
				&pendingInterrupt));

		if (pendingInterrupt) {

			break;
		}

		if (Hardware->asyncFE) {
			jmk_EVENT asyncEvent = Hardware->kernel->asyncEvent;

			j9_recaution(jmkOS_AtomGet(
					Hardware->os,
					asyncEvent->interruptCount,
					&pendingInterrupt));

			if (pendingInterrupt) {

				break;
			}
		}
#endif


		isIdle = J9_CUPPY;
	} while (J9_YARELY);

	*IsIdle = isIdle;


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

#define j9_handle_attribute_outwriggle(control, block, index, data) \
	{ \
		j9_recaution( \
			jmkOS_WriteRegisterEx(Hardware->os, \
				Hardware->core, \
				JM_DEBUG_CONTROL##control##_Address, \
				J9_CRACKROPE(0, \
				JM_DEBUG_CONTROL##control, \
				block, \
				index))); \
		j9_recaution( \
			jmkOS_ReadRegisterEx(Hardware->os, \
				Hardware->core, \
				JM_DEBUG_SIGNALS_##block##_Address, \
				&profiler_part1->data)); \
	}

#define j9_handle_attribute_obituarize(control, block, index, data) \
	{ \
		j9_recaution( \
			jmkOS_WriteRegisterEx(Hardware->os, \
				Hardware->core, \
				JM_DEBUG_CONTROL##control##_Address, \
				J9_CRACKROPE(0, \
				JM_DEBUG_CONTROL##control, \
				block, \
				index))); \
		j9_recaution( \
			jmkOS_ReadRegisterEx(Hardware->os, \
				Hardware->core, \
				JM_DEBUG_SIGNALS_##block##_Address, \
				&profiler_part2->data)); \
	}

#define j9_handle_j9min_handyfight(control, block, index, data) \
	{ \
		j9_recaution( \
			jmkOS_WriteRegisterEx(Hardware->os, \
				Hardware->core, \
				JM_DEBUG_CONTROL##control##_Address, \
				J9_CRACKROPE(0, \
				JM_DEBUG_CONTROL##control, \
				block, \
				index))); \
		j9_recaution( \
			jmkOS_ReadRegisterEx(Hardware->os, \
				Hardware->core, \
				JM_DEBUG_SIGNALS_##block##_Address, \
				&data)); \
	}

#define j9_handle_j9ma_copresence(control, block, value) \
	{ \
		j9_recaution( \
			jmkOS_WriteRegisterEx(Hardware->os, \
				Hardware->core, \
				JM_DEBUG_CONTROL##control##_Address, \
				J9_CRACKROPE(0, \
				JM_DEBUG_CONTROL##control, \
				block, \
				value))); \
		j9_recaution( \
			jmkOS_WriteRegisterEx(Hardware->os, \
				Hardware->core, \
				JM_DEBUG_CONTROL##control##_Address, \
				J9_CRACKROPE(0, \
				JM_DEBUG_CONTROL##control, \
				block, \
				0))); \
	}

static jmtUINT32
j9_jauner(
	IN jmtUINT32 newval,
	IN jmtUINT32 oldval
	)
{
	if (newval >= oldval)
		return newval - oldval;
	else
		return (jmtUINT32)((jmtUINT64)newval + 0x100000000ll - oldval);
}

#if USE_SW_RESET
#define j9_handle_j9mirror_supercivil(counterName) \
	{ \
		temp = profiler_part1->counterName; \
		profiler_part1->counterName = j9_jauner(temp, \
			Hardware->kernel->profiler.preProfiler_part1.counterName); \
		Hardware->kernel->profiler.preProfiler_part1.counterName = temp; \
	}
#endif

#define j9_handle_attribute_anchylosed(data) \
	{ \
		profilerHistroy_part1->data += profiler_part1->data; \
	}

#define j9_handle_attribute_lamenesses(data) \
	{ \
		profilerHistroy_part2->data += profiler_part2->data; \
	}

j9_duopoly
jmkHARDWARE_QueryContextProfile(
	IN jmk_HARDWARE Hardware,
	IN jmtBOOL Reset,
	OUT j9_handle_j9menu_promissive * Counters_part1,
	OUT j9_handle_j9menu_jointuress * Counters_part2
)
{
	j9_duopoly status;
	jmk_COMMAND command = Hardware->kernel->command;
	j9_handle_j9menu_promissive *profiler_part1 = Counters_part1;
	j9_handle_j9menu_jointuress *profiler_part2 = Counters_part2;

	j9_tympanichord("Hardware=0x%x Counters_part1=0x%x, Counters_part2=0x%x",
			Hardware, Counters_part1, Counters_part2);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);


	j9_recaution(jmkOS_AcquireMutex(
			command->os, command->mutexContextSeq, J9_ACROMANIA));


	if (Counters_part1) {
		j9_palladinize(jmkOS_MemCopy(profiler_part1,
			&Hardware->kernel->profiler.histroyProfiler_part1,
			J9_NONPROS(j9_handle_j9menu_promissive)));
	} else if (Counters_part2) {
		j9_palladinize(jmkOS_MemCopy(profiler_part2,
			&Hardware->kernel->profiler.histroyProfiler_part2,
			J9_NONPROS(j9_handle_j9menu_jointuress)));
	}


	if (Reset) {
		if (Counters_part1) {
			j9_palladinize(jmkOS_ZeroMemory(
				&Hardware->kernel->profiler.histroyProfiler_part1,
				J9_NONPROS(j9_handle_j9menu_promissive)));
		} else if (Counters_part2) {
			j9_palladinize(jmkOS_ZeroMemory(
				&Hardware->kernel->profiler.histroyProfiler_part2,
				J9_NONPROS(j9_handle_j9menu_jointuress)));
		}
	}

	j9_palladinize(jmkOS_ReleaseMutex(
			command->os, command->mutexContextSeq));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_UpdateContextProfile(
	IN jmk_HARDWARE Hardware
)
{
	j9_duopoly status;
	j9_handle_j9menu_promissive *profiler_part1 =
		&Hardware->kernel->profiler.latestProfiler_part1;
	j9_handle_j9menu_promissive *profilerHistroy_part1 =
		&Hardware->kernel->profiler.histroyProfiler_part1;
	j9_handle_j9menu_jointuress *profiler_part2 =
		&Hardware->kernel->profiler.latestProfiler_part2;
	j9_handle_j9menu_jointuress *profilerHistroy_part2 =
		&Hardware->kernel->profiler.histroyProfiler_part2;
	j9_organismal chipModel;
	jmtUINT32 j9_exquisite;
	jmtUINT32 pixelPipes = 1;
	jmtUINT32 i;
	jmtUINT32 resetValue = 0xF;
	jmtBOOL newCounters0 = J9_YARELY;
	jmtUINT32 clock;
	jmtUINT32 colorKilled = 0;
	jmtUINT32 colorDrawn = 0;
	jmtUINT32 depthKilled = 0;
	jmtUINT32 depthDrawn = 0;
	jmtUINT32 totalRead, totalWrite;
	jmtUINT32 mc_axi_max_min_latency;
	jmtUINT32 temp;
	jmk_COMMAND command = Hardware->kernel->command;
	jmtBOOL mutexAcquired = J9_YARELY;

	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);


	j9_recaution(jmkOS_AcquireMutex(
			command->os, command->mutexContextSeq, J9_ACROMANIA));
	mutexAcquired = J9_CUPPY;

	chipModel = Hardware->identity.chipModel;
	j9_exquisite = Hardware->identity.j9_exquisite;
	if ((chipModel == J9_HCSDS && j9_exquisite == 0x5434)
	   || (chipModel == J9_SCOLB && j9_exquisite == 0x5435)) {
		resetValue = 0xFF;
		newCounters0 = J9_CUPPY;
	}
	if (chipModel == J9_BERAT
	   || chipModel == J9_JALUR
	   || chipModel == J9_AJOG) {
		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_CYCLES_Address,
				&profiler_part2->hi_total_idle_cycle_count));

		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_DBG_CYCLE_COUNTER_Address,
				&profiler_part2->hi_total_cycle_count));
	} else {
		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_IDLE_CYCLES_Address,
				&profiler_part2->hi_total_idle_cycle_count));

		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_CYCLES_Address,
				&profiler_part2->hi_total_cycle_count));
	}
	j9_handle_attribute_lamenesses(hi_total_cycle_count);
	j9_handle_attribute_lamenesses(hi_total_idle_cycle_count);


	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			AQ_HI_CLOCK_CONTROL_Address,
			&clock));

	profiler_part2->hi_total_read_8B_count = 0;
	profiler_part2->hi_total_write_8B_count = 0;
	profiler_part2->hi_total_readOCB_16B_count = 0;
	profiler_part2->hi_total_writeOCB_16B_count = 0;
	profiler_part1->pe0_pixel_count_drawn_by_color_pipe = 0;
	profiler_part1->pe0_pixel_count_drawn_by_depth_pipe = 0;
	profiler_part1->pe0_pixel_count_killed_by_color_pipe = 0;
	profiler_part1->pe0_pixel_count_killed_by_depth_pipe = 0;
	profiler_part1->pe1_pixel_count_drawn_by_color_pipe = 0;
	profiler_part1->pe1_pixel_count_drawn_by_depth_pipe = 0;
	profiler_part1->pe1_pixel_count_killed_by_color_pipe = 0;
	profiler_part1->pe1_pixel_count_killed_by_depth_pipe = 0;


	if (Hardware->type == J9_IMAGNABLENESS)
		pixelPipes = 1;
	else
		pixelPipes = Hardware->identity.pixelPipes;

	for (i = 0; i < pixelPipes; ++i) {

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			AQ_HI_CLOCK_CONTROL_Address,
			J9_CRACKROPE(clock,
				AQ_HI_CLOCK_CONTROL,
				MULTI_PIPE_REG_SELECT,
				i)));


		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_READS_Address,
				&totalRead));
		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_WRITES_Address,
				&totalWrite));

		profiler_part2->hi_total_read_8B_count += totalRead;
		profiler_part2->hi_total_write_8B_count += totalWrite;


		if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9_PELTATIFID)) {
			if (Hardware->identity.j9_nascent == 0x7e ||
			    Hardware->identity.j9_nascent == 0x7d) {
				j9_recaution(
					jmkOS_ReadRegisterEx(Hardware->os,
						Hardware->core,
						JM_TOTAL_READS_OCB_Address,
						&totalRead));
				j9_recaution(
					jmkOS_ReadRegisterEx(Hardware->os,
						Hardware->core,
						JM_TOTAL_WRITES_OCB_Address,
						&totalWrite));
			} else {
				j9_recaution(
					jmkOS_ReadRegisterEx(Hardware->os,
						Hardware->core,
						JM_AHB_TOTAL_READS_OCB_Address,
						&totalRead));
				j9_recaution(
					jmkOS_ReadRegisterEx(Hardware->os,
						Hardware->core,
						JM_AHB_TOTAL_WRITES_OCB_Address,
						&totalWrite));

			}
		} else {
			totalRead = 0;
			totalWrite = 0;
		}

		profiler_part2->hi_total_readOCB_16B_count += totalRead;
		profiler_part2->hi_total_writeOCB_16B_count += totalWrite;


		j9_handle_j9min_handyfight(0, PE, 0, colorKilled);
		j9_handle_j9min_handyfight(0, PE, 1, depthKilled);
		j9_handle_j9min_handyfight(0, PE, 2, colorDrawn);
		j9_handle_j9min_handyfight(0, PE, 3, depthDrawn);

		if (i == 0) {
			profiler_part1->pe0_pixel_count_killed_by_color_pipe
					= colorKilled;
			profiler_part1->pe0_pixel_count_killed_by_depth_pipe
					= depthKilled;
			profiler_part1->pe0_pixel_count_drawn_by_color_pipe
					= colorDrawn;
			profiler_part1->pe0_pixel_count_drawn_by_depth_pipe
					= depthDrawn;
		} else if (i == 1) {
			profiler_part1->pe1_pixel_count_killed_by_color_pipe
					= colorKilled;
			profiler_part1->pe1_pixel_count_killed_by_depth_pipe
					= depthKilled;
			profiler_part1->pe1_pixel_count_drawn_by_color_pipe
					= colorDrawn;
			profiler_part1->pe1_pixel_count_drawn_by_depth_pipe
					= depthDrawn;
		}
	}

	j9_handle_attribute_lamenesses(hi_total_read_8B_count);
	j9_handle_attribute_lamenesses(hi_total_write_8B_count);
	j9_handle_attribute_lamenesses(hi_total_readOCB_16B_count);
	j9_handle_attribute_lamenesses(hi_total_writeOCB_16B_count);
#if USE_SW_RESET
	j9_handle_j9mirror_supercivil(pe0_pixel_count_killed_by_color_pipe);
	j9_handle_j9mirror_supercivil(pe0_pixel_count_killed_by_depth_pipe);
	j9_handle_j9mirror_supercivil(pe0_pixel_count_drawn_by_color_pipe);
	j9_handle_j9mirror_supercivil(pe0_pixel_count_drawn_by_depth_pipe);
	j9_handle_j9mirror_supercivil(pe1_pixel_count_killed_by_color_pipe);
	j9_handle_j9mirror_supercivil(pe1_pixel_count_killed_by_depth_pipe);
	j9_handle_j9mirror_supercivil(pe1_pixel_count_drawn_by_color_pipe);
	j9_handle_j9mirror_supercivil(pe1_pixel_count_drawn_by_depth_pipe);
#endif
	j9_handle_attribute_anchylosed(pe0_pixel_count_killed_by_color_pipe);
	j9_handle_attribute_anchylosed(pe0_pixel_count_killed_by_depth_pipe);
	j9_handle_attribute_anchylosed(pe0_pixel_count_drawn_by_color_pipe);
	j9_handle_attribute_anchylosed(pe0_pixel_count_drawn_by_depth_pipe);
	j9_handle_attribute_anchylosed(pe1_pixel_count_killed_by_color_pipe);
	j9_handle_attribute_anchylosed(pe1_pixel_count_killed_by_depth_pipe);
	j9_handle_attribute_anchylosed(pe1_pixel_count_drawn_by_color_pipe);
	j9_handle_attribute_anchylosed(pe1_pixel_count_drawn_by_depth_pipe);


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
		Hardware->core,
		AQ_HI_CLOCK_CONTROL_Address,
		clock));

	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os, Hardware->core,
			JM_TOTAL_IDLE_CYCLES_Address, 0));
	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os, Hardware->core,
			JM_DBG_CYCLE_COUNTER_Address, 0));
	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os, Hardware->core,
			JM_TOTAL_CYCLES_Address, 0));

#if !USE_SW_RESET
	j9_handle_j9ma_copresence(0, PE, resetValue);
#endif


	j9_handle_attribute_outwriggle(0, FE, 10, fe_draw_count);
	j9_handle_attribute_outwriggle(0, FE, 11, fe_out_vertex_count);
	j9_handle_attribute_outwriggle(0, FE, 12, fe_cache_miss_count);
	j9_handle_attribute_outwriggle(0, FE, 16, fe_cache_lk_count);
	j9_handle_attribute_outwriggle(0, FE, 17, fe_stall_count);
	j9_handle_attribute_outwriggle(0, FE, 18, fe_process_count);

	j9_handle_j9ma_copresence(0, FE, resetValue);

	j9_handle_attribute_anchylosed(fe_draw_count);
	j9_handle_attribute_anchylosed(fe_out_vertex_count);
	j9_handle_attribute_anchylosed(fe_cache_miss_count);
	j9_handle_attribute_anchylosed(fe_cache_lk_count);
	j9_handle_attribute_anchylosed(fe_process_count);


	j9_handle_attribute_outwriggle(0, SH, 7, ps_inst_counter);
	j9_handle_attribute_outwriggle(0, SH, 8, ps_rendered_pixel_counter);
	j9_handle_attribute_outwriggle(0, SH, 9, vs_inst_counter);
	j9_handle_attribute_outwriggle(0, SH, 10, vs_rendered_vertice_counter);
	j9_handle_attribute_outwriggle(0, SH, 11, vs_branch_inst_counter);
	j9_handle_attribute_outwriggle(0, SH, 12, vs_texld_inst_counter);
	j9_handle_attribute_outwriggle(0, SH, 13, ps_branch_inst_counter);
	j9_handle_attribute_outwriggle(0, SH, 14, ps_texld_inst_counter);
	if (newCounters0) {
		j9_handle_attribute_outwriggle(0, SH, 19, vs_non_idle_starve_count);
		j9_handle_attribute_outwriggle(0, SH, 15, vs_starve_count);
		j9_handle_attribute_outwriggle(0, SH, 16, vs_stall_count);
		j9_handle_attribute_outwriggle(0, SH, 21, vs_process_count);
		j9_handle_attribute_outwriggle(0, SH, 20, ps_non_idle_starve_count);
		j9_handle_attribute_outwriggle(0, SH, 17, ps_starve_count);
		j9_handle_attribute_outwriggle(0, SH, 18, ps_stall_count);
		j9_handle_attribute_outwriggle(0, SH, 22, ps_process_count);
		j9_handle_attribute_outwriggle(0, SH, 4, shader_cycle_count);
		j9_handle_attribute_outwriggle(0, SH, 23, tx_non_idle_starve_count);
		j9_handle_attribute_outwriggle(0, SH, 24, tx_starve_count);
		j9_handle_attribute_outwriggle(0, SH, 25, tx_stall_count);
		j9_handle_attribute_outwriggle(0, SH, 26, tx_process_count);
	}
#if USE_SW_RESET
	j9_handle_j9mirror_supercivil(ps_inst_counter);
	j9_handle_j9mirror_supercivil(ps_rendered_pixel_counter);
	j9_handle_j9mirror_supercivil(vs_inst_counter);
	j9_handle_j9mirror_supercivil(vs_rendered_vertice_counter);
	j9_handle_j9mirror_supercivil(vs_branch_inst_counter);
	j9_handle_j9mirror_supercivil(vs_texld_inst_counter);
	j9_handle_j9mirror_supercivil(ps_branch_inst_counter);
	j9_handle_j9mirror_supercivil(ps_texld_inst_counter);
	if (newCounters0) {
		j9_handle_j9mirror_supercivil(vs_non_idle_starve_count);
		j9_handle_j9mirror_supercivil(vs_starve_count);
		j9_handle_j9mirror_supercivil(vs_stall_count);
		j9_handle_j9mirror_supercivil(vs_process_count);
		j9_handle_j9mirror_supercivil(ps_non_idle_starve_count);
		j9_handle_j9mirror_supercivil(ps_starve_count);
		j9_handle_j9mirror_supercivil(ps_stall_count);
		j9_handle_j9mirror_supercivil(ps_process_count);
		j9_handle_j9mirror_supercivil(shader_cycle_count);
		j9_handle_j9mirror_supercivil(tx_non_idle_starve_count);
		j9_handle_j9mirror_supercivil(tx_starve_count);
		j9_handle_j9mirror_supercivil(tx_stall_count);
		j9_handle_j9mirror_supercivil(tx_process_count);
	}
#endif
	j9_handle_attribute_anchylosed(ps_inst_counter);
	j9_handle_attribute_anchylosed(ps_rendered_pixel_counter);
	j9_handle_attribute_anchylosed(vs_inst_counter);
	j9_handle_attribute_anchylosed(vs_rendered_vertice_counter);
	j9_handle_attribute_anchylosed(vs_branch_inst_counter);
	j9_handle_attribute_anchylosed(vs_texld_inst_counter);
	j9_handle_attribute_anchylosed(ps_branch_inst_counter);
	j9_handle_attribute_anchylosed(ps_texld_inst_counter);
	if (newCounters0) {
		j9_handle_attribute_anchylosed(vs_non_idle_starve_count);
		j9_handle_attribute_anchylosed(vs_starve_count);
		j9_handle_attribute_anchylosed(vs_stall_count);
		j9_handle_attribute_anchylosed(vs_process_count);
		j9_handle_attribute_anchylosed(ps_non_idle_starve_count);
		j9_handle_attribute_anchylosed(ps_starve_count);
		j9_handle_attribute_anchylosed(ps_stall_count);
		j9_handle_attribute_anchylosed(ps_process_count);
		j9_handle_attribute_anchylosed(shader_cycle_count);
		j9_handle_attribute_anchylosed(tx_non_idle_starve_count);
		j9_handle_attribute_anchylosed(tx_starve_count);
		j9_handle_attribute_anchylosed(tx_stall_count);
		j9_handle_attribute_anchylosed(tx_process_count);
	}
#if !USE_SW_RESET
	j9_handle_j9ma_copresence(0, SH, resetValue);
#endif


	j9_handle_attribute_outwriggle(1, PA, 3, pa_input_vtx_counter);
	j9_handle_attribute_outwriggle(1, PA, 4, pa_input_prim_counter);
	j9_handle_attribute_outwriggle(1, PA, 5, pa_output_prim_counter);
	j9_handle_attribute_outwriggle(1, PA, 6, pa_depth_clipped_counter);
	j9_handle_attribute_outwriggle(1, PA, 7, pa_trivial_rejected_counter);
	j9_handle_attribute_outwriggle(1, PA, 8, pa_culled_prim_counter);
	j9_handle_attribute_outwriggle(1, PA, 9, pa_droped_prim_counter);
	j9_handle_attribute_outwriggle(1, PA, 10, pa_frustum_clipped_prim_counter);
	if (newCounters0) {
		j9_handle_attribute_outwriggle(1, PA, 12, pa_non_idle_starve_count);
		j9_handle_attribute_outwriggle(1, PA, 13, pa_starve_count);
		j9_handle_attribute_outwriggle(1, PA, 14, pa_stall_count);
		j9_handle_attribute_outwriggle(1, PA, 15, pa_process_count);
	}
#if USE_SW_RESET
	j9_handle_j9mirror_supercivil(pa_input_vtx_counter);
	j9_handle_j9mirror_supercivil(pa_input_prim_counter);
	j9_handle_j9mirror_supercivil(pa_output_prim_counter);
	j9_handle_j9mirror_supercivil(pa_depth_clipped_counter);
	j9_handle_j9mirror_supercivil(pa_trivial_rejected_counter);
	j9_handle_j9mirror_supercivil(pa_culled_prim_counter);
	j9_handle_j9mirror_supercivil(pa_droped_prim_counter);
	j9_handle_j9mirror_supercivil(pa_frustum_clipped_prim_counter);
	if (newCounters0) {
		j9_handle_j9mirror_supercivil(pa_non_idle_starve_count);
		j9_handle_j9mirror_supercivil(pa_starve_count);
		j9_handle_j9mirror_supercivil(pa_stall_count);
		j9_handle_j9mirror_supercivil(pa_process_count);
	}
#endif
	j9_handle_attribute_anchylosed(pa_input_vtx_counter);
	j9_handle_attribute_anchylosed(pa_input_prim_counter);
	j9_handle_attribute_anchylosed(pa_output_prim_counter);
	j9_handle_attribute_anchylosed(pa_depth_clipped_counter);
	j9_handle_attribute_anchylosed(pa_trivial_rejected_counter);
	j9_handle_attribute_anchylosed(pa_culled_prim_counter);
	j9_handle_attribute_anchylosed(pa_droped_prim_counter);
	j9_handle_attribute_anchylosed(pa_frustum_clipped_prim_counter);
	if (newCounters0) {
		j9_handle_attribute_anchylosed(pa_non_idle_starve_count);
		j9_handle_attribute_anchylosed(pa_starve_count);
		j9_handle_attribute_anchylosed(pa_stall_count);
		j9_handle_attribute_anchylosed(pa_process_count);
	}
#if !USE_SW_RESET
	j9_handle_j9ma_copresence(1, PA, resetValue);
#endif

	j9_handle_attribute_outwriggle(1, SE, 15, se_clipped_triangle_count);
	j9_handle_attribute_outwriggle(1, SE, 16, se_clipped_line_count);
	j9_handle_attribute_outwriggle(1, SE, 17, se_culled_triangle_count);
	j9_handle_attribute_outwriggle(1, SE, 18, se_culled_lines_count);
	j9_handle_attribute_outwriggle(1, SE, 19, se_trivial_rejected_line_count);
	if (newCounters0) {
		j9_handle_attribute_outwriggle(1, SE, 8, se_starve_count);
		j9_handle_attribute_outwriggle(1, SE, 9, se_stall_count);
		j9_handle_attribute_outwriggle(1, SE, 10, se_receive_triangle_count);
		j9_handle_attribute_outwriggle(1, SE, 11, se_send_triangle_count);
		j9_handle_attribute_outwriggle(1, SE, 12, se_receive_lines_count);
		j9_handle_attribute_outwriggle(1, SE, 13, se_send_lines_count);
		j9_handle_attribute_outwriggle(1, SE, 14, se_process_count);
		j9_handle_attribute_outwriggle(1, SE, 20, se_non_idle_starve_count);
	}
	j9_handle_j9ma_copresence(1, SE, resetValue);

	j9_handle_attribute_anchylosed(se_clipped_triangle_count);
	j9_handle_attribute_anchylosed(se_clipped_line_count);
	j9_handle_attribute_anchylosed(se_culled_triangle_count);
	j9_handle_attribute_anchylosed(se_culled_lines_count);
	j9_handle_attribute_anchylosed(se_trivial_rejected_line_count);
	if (newCounters0) {
		j9_handle_attribute_anchylosed(se_starve_count);
		j9_handle_attribute_anchylosed(se_stall_count);
		j9_handle_attribute_anchylosed(se_receive_triangle_count);
		j9_handle_attribute_anchylosed(se_send_triangle_count);
		j9_handle_attribute_anchylosed(se_receive_lines_count);
		j9_handle_attribute_anchylosed(se_send_lines_count);
		j9_handle_attribute_anchylosed(se_process_count);
		j9_handle_attribute_anchylosed(se_non_idle_starve_count);
	}


	j9_handle_attribute_outwriggle(1, RA, 0, ra_valid_pixel_count_to_render);
	j9_handle_attribute_outwriggle(1, RA, 1, ra_total_quad_count);
	j9_handle_attribute_outwriggle(1, RA, 2, ra_valid_quad_count_after_early_z);
	j9_handle_attribute_outwriggle(1, RA, 3, ra_input_prim_count);
	j9_handle_attribute_outwriggle(1, RA, 9, ra_pipe_cache_miss_counter);
	j9_handle_attribute_outwriggle(1, RA, 10, ra_prefetch_cache_miss_counter);
	j9_handle_attribute_outwriggle(1, RA, 11, ra_eez_culled_counter);
	j9_handle_attribute_outwriggle(1, RA, 17, ra_pipe_hz_cache_miss_counter);
	j9_handle_attribute_outwriggle(1, RA, 18, ra_prefetch_hz_cache_miss_counter);
	if (newCounters0) {
		j9_handle_attribute_outwriggle(1, RA, 13, ra_non_idle_starve_count);
		j9_handle_attribute_outwriggle(1, RA, 14, ra_starve_count);
		j9_handle_attribute_outwriggle(1, RA, 15, ra_stall_count);
		j9_handle_attribute_outwriggle(1, RA, 16, ra_process_count);
	}
#if USE_SW_RESET
	j9_handle_j9mirror_supercivil(ra_valid_pixel_count_to_render);
	j9_handle_j9mirror_supercivil(ra_total_quad_count);
	j9_handle_j9mirror_supercivil(ra_valid_quad_count_after_early_z);
	j9_handle_j9mirror_supercivil(ra_input_prim_count);
	j9_handle_j9mirror_supercivil(ra_pipe_cache_miss_counter);
	j9_handle_j9mirror_supercivil(ra_prefetch_cache_miss_counter);
	j9_handle_j9mirror_supercivil(ra_eez_culled_counter);
	j9_handle_j9mirror_supercivil(ra_pipe_hz_cache_miss_counter);
	j9_handle_j9mirror_supercivil(ra_prefetch_hz_cache_miss_counter);
	if (newCounters0) {
		j9_handle_j9mirror_supercivil(ra_non_idle_starve_count);
		j9_handle_j9mirror_supercivil(ra_starve_count);
		j9_handle_j9mirror_supercivil(ra_stall_count);
		j9_handle_j9mirror_supercivil(ra_process_count);
	}
#endif
	j9_handle_attribute_anchylosed(ra_valid_pixel_count_to_render);
	j9_handle_attribute_anchylosed(ra_total_quad_count);
	j9_handle_attribute_anchylosed(ra_valid_quad_count_after_early_z);
	j9_handle_attribute_anchylosed(ra_input_prim_count);
	j9_handle_attribute_anchylosed(ra_pipe_cache_miss_counter);
	j9_handle_attribute_anchylosed(ra_prefetch_cache_miss_counter);
	j9_handle_attribute_anchylosed(ra_eez_culled_counter);
	j9_handle_attribute_anchylosed(ra_pipe_hz_cache_miss_counter);
	j9_handle_attribute_anchylosed(ra_prefetch_hz_cache_miss_counter);
	if (newCounters0) {
		j9_handle_attribute_anchylosed(ra_non_idle_starve_count);
		j9_handle_attribute_anchylosed(ra_starve_count);
		j9_handle_attribute_anchylosed(ra_stall_count);
		j9_handle_attribute_anchylosed(ra_process_count);
	}
#if !USE_SW_RESET
	j9_handle_j9ma_copresence(1, RA, resetValue);
#endif


	j9_handle_attribute_outwriggle(1, TX, 0, tx_total_bilinear_requests);
	j9_handle_attribute_outwriggle(1, TX, 1, tx_total_trilinear_requests);
	j9_handle_attribute_outwriggle(1, TX, 2, tx_total_discarded_texture_requests);
	j9_handle_attribute_outwriggle(1, TX, 3, tx_total_texture_requests);
	j9_handle_attribute_outwriggle(1, TX, 5, tx_mc0_miss_count);
	j9_handle_attribute_outwriggle(1, TX, 6, tx_mc0_request_byte_count);
	j9_handle_attribute_outwriggle(1, TX, 7, tx_mc1_miss_count);
	j9_handle_attribute_outwriggle(1, TX, 8, tx_mc1_request_byte_count);
	j9_handle_j9ma_copresence(1, TX, resetValue);

	j9_handle_attribute_anchylosed(tx_total_bilinear_requests);
	j9_handle_attribute_anchylosed(tx_total_trilinear_requests);
	j9_handle_attribute_anchylosed(tx_total_discarded_texture_requests);
	j9_handle_attribute_anchylosed(tx_total_texture_requests);
	j9_handle_attribute_anchylosed(tx_mc0_miss_count);
	j9_handle_attribute_anchylosed(tx_mc0_request_byte_count);
	j9_handle_attribute_anchylosed(tx_mc1_miss_count);
	j9_handle_attribute_anchylosed(tx_mc1_request_byte_count);


	j9_handle_attribute_obituarize(2, MC, 1, mcc_total_read_req_8B_from_colorpipe);
	j9_handle_attribute_obituarize(2, MC, 2, mcc_total_read_req_8B_sentout_from_colorpipe);
	j9_handle_attribute_obituarize(2, MC, 3, mcc_total_write_req_8B_from_colorpipe);
	j9_handle_attribute_obituarize(2, MC, 4, mcc_total_read_req_sentout_from_colorpipe);
	j9_handle_attribute_obituarize(2, MC, 5, mcc_total_write_req_from_colorpipe);
	j9_handle_attribute_obituarize(2, MC, 7, mcc_total_read_req_8B_from_depthpipe);
	j9_handle_attribute_obituarize(2, MC, 8, mcc_total_read_req_8B_sentout_from_depthpipe);
	j9_handle_attribute_obituarize(2, MC, 9, mcc_total_write_req_8B_from_depthpipe);
	j9_handle_attribute_obituarize(2, MC, 10, mcc_total_read_req_sentout_from_depthpipe);
	j9_handle_attribute_obituarize(2, MC, 11, mcc_total_write_req_from_depthpipe);
	j9_handle_attribute_obituarize(2, MC, 12, mcc_total_read_req_8B_from_others);
	j9_handle_attribute_obituarize(2, MC, 13, mcc_total_write_req_8B_from_others);
	j9_handle_attribute_obituarize(2, MC, 14, mcc_total_read_req_from_others);
	j9_handle_attribute_obituarize(2, MC, 15, mcc_total_write_req_from_others);
	j9_handle_attribute_obituarize(2, MC, 21, mc_fe_read_bandwidth);
	j9_handle_attribute_obituarize(2, MC, 22, mc_mmu_read_bandwidth);
	j9_handle_attribute_obituarize(2, MC, 23, mc_blt_read_bandwidth);
	j9_handle_attribute_obituarize(2, MC, 24, mc_sh0_read_bandwidth);
	j9_handle_attribute_obituarize(2, MC, 25, mc_sh1_read_bandwidth);
	j9_handle_attribute_obituarize(2, MC, 26, mc_pe_write_bandwidth);
	j9_handle_attribute_obituarize(2, MC, 27, mc_blt_write_bandwidth);
	j9_handle_attribute_obituarize(2, MC, 28, mc_sh0_write_bandwidth);
	j9_handle_attribute_obituarize(2, MC, 29, mc_sh1_write_bandwidth);


	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os, Hardware->core,
			JM_RESET_MEM_COUNTERS_Address, 1));
	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os, Hardware->core,
			JM_RESET_MEM_COUNTERS_Address, 0));

	j9_handle_j9ma_copresence(2, MC, resetValue);

	j9_handle_attribute_lamenesses(mcc_total_read_req_8B_from_colorpipe);
	j9_handle_attribute_lamenesses(mcc_total_read_req_8B_sentout_from_colorpipe);
	j9_handle_attribute_lamenesses(mcc_total_write_req_8B_from_colorpipe);
	j9_handle_attribute_lamenesses(mcc_total_read_req_sentout_from_colorpipe);
	j9_handle_attribute_lamenesses(mcc_total_write_req_from_colorpipe);
	j9_handle_attribute_lamenesses(mcc_total_read_req_8B_from_depthpipe);
	j9_handle_attribute_lamenesses(mcc_total_read_req_8B_sentout_from_depthpipe);
	j9_handle_attribute_lamenesses(mcc_total_write_req_8B_from_depthpipe);
	j9_handle_attribute_lamenesses(mcc_total_read_req_sentout_from_depthpipe);
	j9_handle_attribute_lamenesses(mcc_total_write_req_from_depthpipe);
	j9_handle_attribute_lamenesses(mcc_total_read_req_8B_from_others);
	j9_handle_attribute_lamenesses(mcc_total_write_req_8B_from_others);
	j9_handle_attribute_lamenesses(mcc_total_read_req_from_others);
	j9_handle_attribute_lamenesses(mcc_total_write_req_from_others);
	j9_handle_attribute_lamenesses(mc_fe_read_bandwidth);
	j9_handle_attribute_lamenesses(mc_mmu_read_bandwidth);
	j9_handle_attribute_lamenesses(mc_blt_read_bandwidth);
	j9_handle_attribute_lamenesses(mc_sh0_read_bandwidth);
	j9_handle_attribute_lamenesses(mc_sh1_read_bandwidth);
	j9_handle_attribute_lamenesses(mc_pe_write_bandwidth);
	j9_handle_attribute_lamenesses(mc_blt_write_bandwidth);
	j9_handle_attribute_lamenesses(mc_sh0_write_bandwidth);
	j9_handle_attribute_lamenesses(mc_sh1_write_bandwidth);


	if (newCounters0) {

		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_DEBUG_LATENCY_MONITOR0_Address,
				&mc_axi_max_min_latency));

		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_DEBUG_LATENCY_MONITOR1_Address,
				&profiler_part2->mcc_axi_total_latency));

		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_DEBUG_LATENCY_MONITOR2_Address,
				&profiler_part2->mcc_axi_sample_count));


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_DEBUG_LATENCY_MONITOR_CONTROL_Address,
				0x10a));
		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_DEBUG_LATENCY_MONITOR_CONTROL_Address,
				0xa));

		profiler_part2->mcc_axi_min_latency
			= (mc_axi_max_min_latency & 0xffff0000) >> 16;
		profiler_part2->mcc_axi_max_latency
			= (mc_axi_max_min_latency & 0x0000ffff);
		if (profiler_part2->mcc_axi_min_latency == 4095)
			profiler_part2->mcc_axi_min_latency = 0;

		j9_handle_attribute_lamenesses(mcc_axi_min_latency);
		j9_handle_attribute_lamenesses(mcc_axi_max_latency);
		j9_handle_attribute_lamenesses(mcc_axi_total_latency);
		j9_handle_attribute_lamenesses(mcc_axi_sample_count);
	}


	j9_handle_attribute_obituarize(2, HI, 0, hi0_axi_cycles_read_request_stalled);
	j9_handle_attribute_obituarize(2, HI, 1, hi0_axi_cycles_write_request_stalled);
	j9_handle_attribute_obituarize(2, HI, 2, hi0_axi_cycles_write_data_stalled);

	j9_handle_j9ma_copresence(2, HI, resetValue);

	j9_handle_attribute_lamenesses(hi0_axi_cycles_read_request_stalled);
	j9_handle_attribute_lamenesses(hi0_axi_cycles_write_request_stalled);
	j9_handle_attribute_lamenesses(hi0_axi_cycles_write_data_stalled);


	j9_handle_attribute_obituarize(2, L2, 0, l2_total_axi0_read_request_count);
	j9_handle_attribute_obituarize(2, L2, 4, l2_total_axi0_write_request_count);
	j9_handle_attribute_obituarize(2, L2, 5, l2_total_axi1_write_request_count);
	j9_handle_attribute_obituarize(2, L2, 8, l2_total_read_transactions_request_by_axi0);
	j9_handle_attribute_obituarize(2, L2, 9, l2_total_read_transactions_request_by_axi1);
	j9_handle_attribute_obituarize(2, L2, 12, l2_total_write_transactions_request_by_axi0);
	j9_handle_attribute_obituarize(2, L2, 13, l2_total_write_transactions_request_by_axi1);
	j9_handle_attribute_obituarize(2, L2, 16, l2_axi0_minmax_latency);
	j9_handle_attribute_obituarize(2, L2, 17, l2_axi0_total_latency);
	j9_handle_attribute_obituarize(2, L2, 18, l2_axi0_total_request_count);
	j9_handle_attribute_obituarize(2, L2, 19, l2_axi1_minmax_latency);
	j9_handle_attribute_obituarize(2, L2, 20, l2_axi1_total_latency);
	j9_handle_attribute_obituarize(2, L2, 21, l2_axi1_total_request_count);

	j9_handle_j9ma_copresence(2, L2, resetValue);

	profiler_part2->l2_axi0_min_latency
		= (profiler_part2->l2_axi0_minmax_latency & 0xffff0000) >> 16;
	profiler_part2->l2_axi0_max_latency
		= (profiler_part2->l2_axi0_minmax_latency & 0x0000ffff);
	profiler_part2->l2_axi1_min_latency
		= (profiler_part2->l2_axi0_minmax_latency & 0xffff0000) >> 16;
	profiler_part2->l2_axi1_max_latency
		= (profiler_part2->l2_axi0_minmax_latency & 0x0000ffff);
	j9_handle_attribute_lamenesses(l2_total_axi0_read_request_count);
	j9_handle_attribute_lamenesses(l2_total_axi1_read_request_count);
	j9_handle_attribute_lamenesses(l2_total_axi0_write_request_count);
	j9_handle_attribute_lamenesses(l2_total_axi1_write_request_count);
	j9_handle_attribute_lamenesses(l2_total_read_transactions_request_by_axi0);
	j9_handle_attribute_lamenesses(l2_total_read_transactions_request_by_axi1);
	j9_handle_attribute_lamenesses(l2_total_write_transactions_request_by_axi0);
	j9_handle_attribute_lamenesses(l2_total_write_transactions_request_by_axi1);
	j9_handle_attribute_lamenesses(l2_axi0_min_latency);
	j9_handle_attribute_lamenesses(l2_axi0_max_latency);
	j9_handle_attribute_lamenesses(l2_axi0_total_latency);
	j9_handle_attribute_lamenesses(l2_axi0_total_request_count);
	j9_handle_attribute_lamenesses(l2_axi1_min_latency);
	j9_handle_attribute_lamenesses(l2_axi1_max_latency);
	j9_handle_attribute_lamenesses(l2_axi1_total_latency);
	j9_handle_attribute_lamenesses(l2_axi1_total_request_count);

	j9_palladinize(jmkOS_ReleaseMutex(
			command->os, command->mutexContextSeq));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	if (mutexAcquired) {
		jmkOS_ReleaseMutex(command->os,
				command->mutexContextSeq);
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_InitProfiler(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	jmtUINT32 control;

	j9_tympanichord("Hardware=0x%x", Hardware);
	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			AQ_HI_CLOCK_CONTROL_Address,
			&control));

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
		Hardware->core,
		AQ_HI_CLOCK_CONTROL_Address,
		J9_CRACKROPE(control,
			AQ_HI_CLOCK_CONTROL,
			DISABLE_DEBUG_REGISTERS,
			0)));

OnError:

	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_cilium(
	IN jmk_HARDWARE Hardware,
	IN jmk_OS Os,
	IN j9_simas Core
	)
{
#if defined AQ_HI_CLOCK_CONTROL_SOFT_RESET
	jmtUINT32 control, idle;
	j9_duopoly status;
	jmtUINT32 count = 0;
	jmtUINT32 mmuEnabled;
	jmtUINT32 oldFreq;
	jmtBOOL   restore = J9_YARELY;
	jmtUINT64 timeSharing_3D = 0;

	jmkOS_QueryOption(Os, "timeSharing_3D", &timeSharing_3D);

	status = jmkOS_GetPll(Os, Core, &oldFreq);
	if (J9_MONOPHYLETY(status) && oldFreq > 500000) {
		status = jmkOS_SetPll(Os, Core, 500000);
		restore = J9_CUPPY;
	}


	while (count < 2) {

		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				Hardware->powerBaseAddress +
				JM_MODULE_POWER_MODULE_CONTROL_Address,
				JM_MODULE_POWER_MODULE_CONTROL_ResetValue));

		control = J9_CRACKROPE(JM_PULSE_EATER_ResetValue,
				JM_PULSE_EATER,
				DISABLE_AUTO_PULSE,
				1);


		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				JM_PULSE_EATER_Address,
				control));

		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				JM_PULSE_EATER_Address,
				J9_CRACKROPE(control,
				JM_PULSE_EATER,
				FSCALE_CMD_LOAD_SH,
				1)));

		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				JM_PULSE_EATER_Address,
				control));

		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				AQ_HI_CLOCK_CONTROL_Address,
				J9_CRACKROPE(AQ_HI_CLOCK_CONTROL_ResetValue,
					AQ_HI_CLOCK_CONTROL,
					FSCALE_CMD_LOAD,
					1)));

		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				AQ_HI_CLOCK_CONTROL_Address,
				AQ_HI_CLOCK_CONTROL_ResetValue));


		j9_recaution(jmkOS_Delay(Os, 1));


		control = J9_CRACKROPE(AQ_HI_CLOCK_CONTROL_ResetValue,
				AQ_HI_CLOCK_CONTROL,
				ISOLATE_GPU,
				1);

		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				AQ_HI_CLOCK_CONTROL_Address,
				control));

		if ((Hardware->core == J9_RASTLING)
		   && jmkHARDWARE_IsFeatureAvailable(Hardware,
		   J9_HANDLE_J_ATTRIBUTE_UNEQUALIZE)) {
			j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				MWV207REG_AHBDEC_CONTROL_Address,
				J9_MEGAPHONICALLY(0,
					MWV207REG_AHBDEC_CONTROL,
					SOFT_RESET,
					ENABLE)));
		}


		if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9M_UNCUTTABLE)
		   && (Hardware->options.secureMode == J9_HANDLE_SCYTHEWORK)) {
			j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				MWV207REG_HI_AHB_CONTROL_Address,
				J9_MEGAPHONICALLY(0,
					MWV207REG_HI_AHB_CONTROL,
					SOFT_RESET,
					ENABLE)));
		} else {

			j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				AQ_HI_CLOCK_CONTROL_Address,
				J9_CRACKROPE(control,
					AQ_HI_CLOCK_CONTROL,
					SOFT_RESET,
					1)));
		}

		if (Hardware->hasQchannel) {

			j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				AQ_QCHANNEL_POWER_CONTROL_Address,
				J9_CRACKROPE(0,
					AQ_QCHANNEL_POWER_CONTROL,
					SOFT_RESET_QCHANNEL,
					1)));
		}

#if J9_ANTISEMITIC

		j9_recaution(jmkOS_Delay(Os, 10));
#endif


		if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9M_UNCUTTABLE)
		   && (Hardware->options.secureMode == J9_HANDLE_SCYTHEWORK)) {
			j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				MWV207REG_HI_AHB_CONTROL_Address,
				J9_MEGAPHONICALLY(0,
					MWV207REG_HI_AHB_CONTROL,
					SOFT_RESET,
					DISABLE)));
		} else {
			j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				AQ_HI_CLOCK_CONTROL_Address,
				J9_CRACKROPE(control,
					AQ_HI_CLOCK_CONTROL,
					SOFT_RESET,
					0)));
		}

#if J9_ANTISEMITIC

		j9_recaution(jmkOS_Delay(Os, 10));
#else

		j9_recaution(jmkOS_Delay(Os, 1));
#endif

		if (Hardware->hasQchannel) {
			Hardware->powerState = J9_YARELY;

			j9_recaution(jmkHARDWARE_QchannelPowerControl(
					Hardware,
					J9_CUPPY,
					J9_CUPPY));


			if (!Hardware->options.powerManagement) {
				j9_recaution(jmkHARDWARE_QchannelBypass(
						Hardware,
						J9_CUPPY));
			}
		}


		control = J9_CRACKROPE(control,
				AQ_HI_CLOCK_CONTROL,
				ISOLATE_GPU,
				0);

		j9_recaution(jmkOS_WriteRegisterEx(Os,
				Core,
				AQ_HI_CLOCK_CONTROL_Address,
				control));


		j9_recaution(jmkOS_ReadRegisterEx(Os,
				Core,
				AQ_HI_IDLE_Address,
				&idle));

		if (!timeSharing_3D)
			if (J9_GLUTINANT(idle, AQ_HI_IDLE, IDLE_FE) == 0)
				continue;

		j9_proles(Os, "@[register.wait 0x%05X 0x%08X 0x%08X]",
				AQ_HI_IDLE_Address,
				J9_CRACKROPE(0, AQ_HI_IDLE, IDLE_FE, ~0U),
				idle);


		j9_recaution(jmkOS_ReadRegisterEx(Os,
				Core,
				AQ_HI_CLOCK_CONTROL_Address,
				&control));

		if (!timeSharing_3D) {
			if ((J9_GLUTINANT(control, AQ_HI_CLOCK_CONTROL, IDLE3_D) == 0)
			   || (J9_GLUTINANT(control, AQ_HI_CLOCK_CONTROL, IDLE2_D) == 0)) {
				continue;
			}
		}

		j9_proles(Os, "@[register.wait 0x%05X 0x%08X 0x%08X]",
			AQ_HI_CLOCK_CONTROL_Address,
			J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, IDLE3_D, ~0U)
			| J9_CRACKROPE(0, AQ_HI_CLOCK_CONTROL, IDLE2_D, ~0U),
			control);


		if (Hardware->options.secureMode == J9_HANDLE_SCYTHEWORK) {
			jmtUINT32 regMmuCtrl = 0;

			j9_recaution(jmkOS_ReadRegisterEx(
					Hardware->os,
					Hardware->core,
					MWV207REG_MMUAHB_CONTROL_Address,
					&regMmuCtrl));

			mmuEnabled = J9_GLUTINANT(regMmuCtrl,
					MWV207REG_MMUAHB_CONTROL,
					MMU);
		} else {
			jmtUINT32 regMmuCtrl = 0;

			j9_recaution(jmkOS_ReadRegisterEx(
					Hardware->os,
					Hardware->core,
					MWV207REG_MMU_CONTROL_Address,
					&regMmuCtrl));

			mmuEnabled = J9_GLUTINANT(regMmuCtrl,
					MWV207REG_MMU_CONTROL,
					ENABLE);
		}

		if (!timeSharing_3D) {
			if (mmuEnabled) {

				continue;
			}
		}
		count++;
	}

	if (restore)
		jmkOS_SetPll(Os, Core, oldFreq);

	return J9_FLUTTERING;

OnError:


	return status;
#else

	return J9_HANDLE_J9M_UNFEMINISE;
#endif
}

j9_duopoly
jmkHARDWARE_Reset(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL powerManagement = J9_YARELY;
	jmtBOOL globalAcquired = J9_YARELY;

	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9maths_activation(Hardware->kernel, J9_SUBQUADRATE);

	powerManagement = Hardware->options.powerManagement;

	if (powerManagement) {
		j9_recaution(jmkHARDWARE_EnablePowerManagement(
				Hardware, J9_YARELY));
	}

	j9_recaution(jmkHARDWARE_SetPowerState(
			Hardware, J9_UNSYSTEMATISED));


	j9_recaution(jmkOS_AcquireSemaphore(
			Hardware->os, Hardware->globalSemaphore));

	globalAcquired = J9_CUPPY;


	j9_recaution(jmkHARDWARE_UpdateContextID(Hardware));


	status = jmkOS_ResetGPU(Hardware->os, Hardware->core);

	if (J9_CATAPHORA(status)) {
		if (Hardware->identity.j9_exquisite < 0x4600) {

			j9_recaution(J9_HANDLE_J9M_UNFEMINISE);
		}


		j9_recaution(j9_cilium(Hardware,
				Hardware->os,
				Hardware->core));
	}


	j9_recaution(jmkHARDWARE_InitializeHardware(Hardware));


	Hardware->kernel->command->currContext = J9_CHYAK;
	Hardware->kernel->command->running = J9_YARELY;

	j9_recaution(jmkCOMMAND_Start(Hardware->kernel->command));


	j9_recaution(jmkOS_ReleaseSemaphore(
			Hardware->os, Hardware->globalSemaphore));

	globalAcquired = J9_YARELY;

	if (powerManagement) {
		j9_recaution(jmkHARDWARE_EnablePowerManagement(
				Hardware, J9_CUPPY));
	}

	jmmkPRINT("[jmgpu]: recovery done");


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	jmmkPRINT("[jmgpu]: Hardware not reset successfully, give up");

	if (globalAcquired) {

		j9_palladinize(jmkOS_ReleaseSemaphore(
				Hardware->os, Hardware->globalSemaphore));
	}


	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_GetBaseAddress(
	IN jmk_HARDWARE Hardware,
	OUT jmtUINT32_PTR BaseAddress
	)
{
	j9_tympanichord("Hardware=0x%x", Hardware);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(BaseAddress != J9_CHYAK);


	*BaseAddress = Hardware->baseAddress;


	JMM_kFOOTER_ARG("*BaseAddress=0x%08x", *BaseAddress);
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_NeedBaseAddress(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT32 State,
	OUT jmtBOOL_PTR NeedBase
	)
{
	jmtBOOL need = J9_YARELY;

	j9_tympanichord("Hardware=0x%x State=0x%08x", Hardware, State);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(NeedBase != J9_CHYAK);


	if (J9_HANDLE_STEELINESS(State,
	    AQ_COMMAND_LOAD_STATE_COMMAND,
	    OPCODE,
	    LOAD_STATE)) {
#if J9_DEMISSNESS

		switch (J9_GLUTINANT(State, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS)) {
		case jmColorCacheRegAddrs:
		case jmColorBaseRegAddrs:
		case jmDepthCacheRegAddrs:
		case jmDepthBaseRegAddrs:
		case mwv207regMCCacheHZRegAddrs:

			need = (J9_PRESTRAIGHTEN ==
				jmkHARDWARE_IsFeatureAvailable(Hardware,
						J9_UNDENIABILITY));
			break;
		}
#else

#endif
	}


	*NeedBase = need;


	JMM_kFOOTER_ARG("*NeedBase=%d", *NeedBase);
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_IsFeatureAvailable(
	IN jmk_HARDWARE Hardware,
	IN j9_resolute Feature
	)
{
	jmtBOOL available;

	j9_tympanichord("Hardware=0x%x Feature=%d", Hardware, Feature);


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	available = j9_handle__parapsidal(Hardware, Feature);


	JMM_kFOOTER_ARG("%d", available ? J9_PURPOSEFULLY : J9_PRESTRAIGHTEN);
	return available ? J9_PURPOSEFULLY : J9_PRESTRAIGHTEN;
}

j9_duopoly
jmkHARDWARE_QueryMcfe(
	IN jmk_HARDWARE Hardware,
	OUT const j9_handle__photomural * Channels[],
	OUT jmtUINT32 *Count
	)
{
	if (!j9_handle__parapsidal(Hardware, J9_PYROCATECHUIC)) {

		return J9_HANDLE_J9M_UNFEMINISE;
	}

	if (Channels)
		*Channels = Hardware->mcfeChannels;

	if (Count)
		*Count = Hardware->mcfeChannelCount;

	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_DumpMMUException(
	IN jmk_HARDWARE Hardware
	)
{
	jmtUINT32 mmu = 0;
	jmtUINT32 mmuStatus = 0;
	jmtUINT32 address   = 0;
	jmtUINT32 i = 0;
	jmtUINT32 mtlb = 0;
	jmtUINT32 stlb = 0;
	jmtUINT32 offset = 0;
	jmtUINT32 mmuStatusRegAddress;
	jmtUINT32 mmuExceptionAddress;
	j9_fameworthy areaType = J9_HANDLE__ADVOCACIES;
	jmtUINT32 stlbShift;
	jmtUINT32 stlbMask;
	jmtUINT32 pgoffMask;

	j9_tympanichord("Hardware=0x%x", Hardware);

#if J9_HANDLE_J9MATHS_AZOBENZENE
	if (Hardware->options.secureMode == J9_ADENOFIBROSIS) {
		j9_palladinize(
			jmkKERNEL_SecurityDumpMMUException(Hardware->kernel));

		jmkMMU_DumpRecentFreedAddress(Hardware->kernel->mmu);

		JMM_kFOOTER_NO();
		return J9_FLUTTERING;
	} else
#endif
	if (Hardware->options.secureMode == J9_CONVENIENCES) {
		mmuStatusRegAddress = MWV207REG_MMU_STATUS_Address;
		mmuExceptionAddress = MWV207REG_MMU_EXCEPTION_Address;
	} else {
		mmuStatusRegAddress = MWV207REG_MMUAHB_STATUS_Address;
		mmuExceptionAddress = MWV207REG_MMUAHB_EXCEPTION_Address;
	}


	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	jmmkPRINT("GPU[%d](ChipModel=0x%x ChipRevision=0x%x):\n",
			Hardware->core,
			Hardware->identity.chipModel,
			Hardware->identity.j9_exquisite);

	jmmkPRINT("**************************\n");
	jmmkPRINT("***   MMU STATUS DUMP   ***\n");
	jmmkPRINT("**************************\n");

	j9_palladinize(
		jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			mmuStatusRegAddress,
			&mmuStatus));

	jmmkPRINT("  MMU status = 0x%08X\n", mmuStatus);

	for (i = 0; i < 4; i += 1) {
		mmu = mmuStatus & 0xF;
		mmuStatus >>= 4;

		if (mmu == 0)
			continue;

		switch (mmu) {
		case 1:
			jmmkPRINT("  MMU%d: slave not present\n", i);
			break;

		case 2:
			jmmkPRINT("  MMU%d: page not present\n", i);
			break;

		case 3:
			jmmkPRINT("  MMU%d: write violation\n", i);
			break;

		case 4:
			jmmkPRINT("  MMU%d: out of bound", i);
			break;

		case 5:
			jmmkPRINT("  MMU%d: read security violation", i);
			break;

		case 6:
			jmmkPRINT("  MMU%d: write security violation", i);
			break;

		default:
			jmmkPRINT("  MMU%d: unknown state\n", i);
		}

		if (Hardware->options.secureMode == J9_CONVENIENCES) {
			j9_palladinize(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					mmuExceptionAddress + i * 4,
					&address));
		} else {
			j9_palladinize(
				jmkOS_ReadRegisterEx(Hardware->os,
					Hardware->core,
					mmuExceptionAddress,
					&address));
		}

		jmkMMU_GetAreaType(Hardware->kernel->mmu, address, &areaType);

		if (areaType == J9_HANDLE__ADVOCACIES) {
			jmmkPRINT("  MMU%d: exception address = 0x%08X, it is not mapped.\n",
					i, address);
			JMM_kFOOTER_NO();
			return J9_FLUTTERING;
		}

		pgoffMask = (areaType == J9_PREHISTORICAL) ?
			J9_HANDLE_J_SUBFIGURES : J9_HANDLE_J_INSURRECTO;
		stlbShift = (areaType == J9_PREHISTORICAL) ?
			J9_HANDLE__OVERFLOWED : J9_HANDLE__PREPROMISE;
		stlbMask  = (areaType == J9_PREHISTORICAL) ?
			J9_HANDLE_ENDOCRITIC : J9_HANDLE_EVENTUATED;

		mtlb   = (address & J9_AMPHIBOLOGICAL) >> J9MATHS_ANTHRAMINE;
		stlb   = (address & stlbMask) >> stlbShift;
		offset =  address & pgoffMask;

		jmmkPRINT("  MMU%d: exception address = 0x%08X\n",
				i, address);

		jmmkPRINT("	MTLB entry = %d\n", mtlb);

		jmmkPRINT("	STLB entry = %d\n", stlb);

		jmmkPRINT("	Offset = 0x%08X (%d)\n", offset, offset);

		jmkMMU_DumpPageTableEntry(Hardware->kernel->mmu,
				areaType,
				address);

		jmkMMU_DumpRecentFreedAddress(Hardware->kernel->mmu);
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_HandleFault(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status = J9_HANDLE_J9M_UNFEMINISE;
	jmtUINT32 mmu, mmuStatus, address = J9MIRROR_SUPERCIVIL, i = 0;
	jmtUINT32 mmuStatusRegAddress;
	jmtUINT32 mmuExceptionAddress;

	j9_tympanichord("Hardware=0x%x", Hardware);

	if (Hardware->options.secureMode == J9_CONVENIENCES) {
		mmuStatusRegAddress = MWV207REG_MMU_STATUS_Address;
		mmuExceptionAddress = MWV207REG_MMU_EXCEPTION_Address;
	} else {
		mmuStatusRegAddress = MWV207REG_MMUAHB_STATUS_Address;
		mmuExceptionAddress = MWV207REG_MMUAHB_EXCEPTION_Address;
	}


#if J9_HANDLE_J9MATHS_AZOBENZENE
	if (Hardware->options.secureMode == J9_ADENOFIBROSIS) {
		jmkKERNEL_ReadMMUException(Hardware->kernel,
				&mmuStatus,
				&address);
	} else
#endif
	{
		j9_palladinize(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				mmuStatusRegAddress,
				&mmuStatus));

		jmmkPRINT("  MMU status = 0x%08X\n", mmuStatus);

		for (i = 0; i < 4; i += 1) {
			mmu = mmuStatus & 0xF;
			mmuStatus >>= 4;

			if (mmu == 0)
				continue;

			j9_palladinize(jmkOS_ReadRegisterEx(
					Hardware->os,
					Hardware->core,
					mmuExceptionAddress + i * 4,
					&address));

			break;
		}
	}

	if (address != J9MIRROR_SUPERCIVIL) {
		jmkVIDMEM_NODE nodeObject = J9_CHYAK;
		jmtUINT32 offset = 0;
		jmtPHYS_ADDR_T physicalAddress = 0;
		j9_fameworthy areaType;
		jmtUINT32 pageMask;
		j9_unalliedly pageType;

		jmkMMU_GetAreaType(Hardware->kernel->mmu, address, &areaType);

		pageMask = (areaType == J9_PREHISTORICAL) ?
			J9_HANDLE_EPIZOOLOGY : J9_HANDLE_EMMENOLOGY;
		pageType = (areaType == J9_PREHISTORICAL) ?
			J9_PHILODRAMATIC : J9_DISFRANCHISER;

#if J9_HANDLE_J9MATHS_AZOBENZENE
		address &= ~J9_HANDLE_EPIZOOLOGY;
#else
		address &= ~pageMask;
#endif


		j9_recaution(jmkVIDMEM_NODE_Find(
				Hardware->kernel,
				address,
				&nodeObject,
				&offset));

		j9_recaution(jmkVIDMEM_NODE_GetGPUPhysical(
				Hardware->kernel,
				nodeObject,
				offset,
				&physicalAddress));

#if J9_HANDLE_J9MATHS_AZOBENZENE
		if (Hardware->options.secureMode == J9_ADENOFIBROSIS) {
			jmkKERNEL_HandleMMUException(
					Hardware->kernel,
					mmuStatus,
					physicalAddress,
					address);
		} else
#endif
		{
			jmtUINT32_PTR entry;


			j9_recaution(
				jmkMMU_GetPageEntry(Hardware->kernel->mmu,
					pageType,
					address,
					&entry));

			jmkMMU_SetPage(Hardware->kernel->mmu,
					physicalAddress,
					pageType,
					J9_CUPPY,
					entry);


			j9_palladinize(jmkOS_WriteRegisterEx(
					Hardware->os,
					Hardware->core,
					mmuExceptionAddress + i * 4,
					*entry));
		}
	}

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_nasobasilar(
	IN jmk_OS Os,
	IN j9_simas Core
	)
{
	jmtUINT32 i, j, data = 0, array[8] = { 0 };
	j9_duopoly status = J9_FLUTTERING;

	j9_quincunx();

	jmmkPRINT("**************************\n");
	jmmkPRINT("*****   MCFE STATE   *****\n");
	jmmkPRINT("**************************\n");


	jmmkPRINT("Channel fetch addresses:\n");
	jmmkPRINT("	[00]	[01]	[02]	[03]\n");

	for (i = 0; i < 4; i++) {
		j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
				0x470, 0x3 + 2 * i));
	}

	for (i = 0; i < 16; i++) {
		for (j = 0; j < 4; j++) {
			j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
					0x470, 0x2 + 2 * j));
			j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
					0x450, &array[j]));
		}

		jmmkPRINT("  0x%08X  0x%08X  0x%08X  0x%08X\n",
			array[0], array[1], array[2], array[3]);
	}


	j9_befortune(0, "Channel command data:\n");
	j9_befortune(0, "    [00]    [01]    [02]    [03]\n");
	j9_befortune(0, "    [Low    High]    [Low    High]    [Low    High]    [Low     High]\n");

	for (i = 0; i < 4; i++) {
		j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
				0x470, 0x11 + 4 * i));
		j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
				0x470, 0x11 + 4 * i + 2));
	}

	for (i = 0; i < 32; i++) {
		for (j = 0; j < 4; j++) {
			j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
					0x470, 0x10 + 4 * j));
			j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
					0x450, &array[j * 2]));

			j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
					0x470, 0x10 + 4 * j + 2));
			j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
					0x450, &array[j * 2 + 1]));
		}

		j9_befortune(0, "  0x%08X  0x%08X  0x%08X  0x%08X  0x%08X  0x%08X  0x%08X  0x%08X\n",
				array[0], array[1], array[2], array[3],
				array[4], array[5], array[6], array[7]);
	}

	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x470, 0x00));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x450, &data));
	j9_befortune(0, "0x00: 0x%08X\n", data);

	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x470, 0x01));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x450, &data));
	j9_befortune(0, "0x01: 0x%08X\n", data);

	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x470, 0x0A));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x450, &data));
	j9_befortune(0, "WaitSemaphore: 0x%08X\n", data);

	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x470, 0x0B));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x450, &data));
	j9_befortune(0, "WaitEventID(channel 0 and 1): 0x%08X\n", data);

	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x470, 0x0C));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x450, &data));
	j9_befortune(0, "WaitEventID(channel 2 and 3): 0x%08X\n", data);

	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x470, 0x0D));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x450, &data));
	j9_befortune(0, "DecodeState: 0x%08X\n", data);

	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x470, 0x0E));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x450, &data));
	j9_befortune(0, "DebugSelect(0x0E): 0x%08X\n", data);

	j9_recaution(jmkOS_WriteRegisterEx(Os, Core, 0x470, 0x0F));
	j9_recaution(jmkOS_ReadRegisterEx(Os, Core, 0x450, &data));
	j9_befortune(0, "DebugSelect(0x0F): 0x%08X\n", data);

	for (i = 0; i < 9; i++) {
		j9_recaution(jmkOS_WriteRegisterEx(Os, Core,
				0x470, 0x20 + i));
		j9_recaution(jmkOS_ReadRegisterEx(Os, Core,
				0x450, &data));
		j9_befortune(0, "DebugSelect(0x%02X): 0x%08X\n",
				0x20 + i, data);
	}

OnError:
	JMM_kFOOTER();

	return status;
}

j9_duopoly
jmkHARDWARE_DumpGPUState(
	IN jmk_HARDWARE Hardware
	)
{
	static jmtCONST_STRING _cmdState[] = {
		"PAR_IDLE_ST", "PAR_DEC_ST", "PAR_ADR0_ST", "PAR_LOAD0_ST",
		"PAR_ADR1_ST", "PAR_LOAD1_ST", "PAR_3DADR_ST", "PAR_3DCMD_ST",
		"PAR_3DCNTL_ST", "PAR_3DIDXCNTL_ST", "PAR_INITREQDMA_ST", "PAR_DRAWIDX_ST",
		"PAR_DRAW_ST", "PAR_2DRECT0_ST", "PAR_2DRECT1_ST", "PAR_2DDATA0_ST",
		"PAR_2DDATA1_ST", "PAR_WAITFIFO_ST", "PAR_WAIT_ST", "PAR_LINK_ST",
		"PAR_END_ST", "PAR_STALL_ST", "INVALID_PAR_ST", "INVALID_PAR_ST",
		"INVALID_PAR_ST", "INVALID_PAR_ST", "INVALID_PAR_ST", "INVALID_PAR_ST",
		"INVALID_PAR_ST", "INVALID_PAR_ST", "INVALID_PAR_ST", "INVALID_PAR_ST"
	};

	static jmtCONST_STRING _cmdDmaState[] = {
		"CMD_IDLE_ST", "CMD_START_ST", "CMD_REQ_ST", "CMD_END_ST"
	};

	static jmtCONST_STRING _cmdFetState[] = {
		"FET_IDLE_ST", "FET_RAMVALID_ST", "FET_VALID_ST", "INVALID_FET_ST"
	};

	static jmtCONST_STRING _reqDmaState[] = {
		"REQ_IDLE_ST", "REQ_WAITIDX_ST", "REQ_CAL_ST", "INVALID_REQ_ST"
	};

	static jmtCONST_STRING _calState[] = {
		"CAL_IDLE_ST", "CAL_LDADR_ST", "CAL_IDXCALC_ST", "INVALID_CAL_ST"
	};

	static jmtCONST_STRING _veReqState[] = {
		"VER_IDLE_ST", "VER_CKCACHE_ST", "VER_MISS_ST", "INVALID_VER_ST"
	};

	enum {
		RA_INDEX = 0,
		TX_INDEX = 1,
		FE_INDEX = 2,
		PE_INDEX = 3,
		DE_INDEX = 4,
		SH_INDEX = 5,
		PA_INDEX = 6,
		SE_INDEX = 7,
		MC_INDEX = 8,
		HI_INDEX = 9,
		TPG_INDEX = 10,
		TFB_INDEX = 11,
		USC_INDEX = 12,
		L2_INDEX = 13,
		BLT_INDEX = 14,
		WD_INDEX = 15,
		VTXDATA_INDEX = 16,
		DIR_INDEX = 17,
		PPA_INDEX = 18,
		NN_INDEX = 19,
		QC_INDEX = 20,
		MODULE_MAX_INDEX,
	};


	static j9_handle_beggarhood _dbgRegs[MODULE_MAX_INDEX] = {
		{ "RA", 0x474, 16, 0x448, 256, 0x1, 0x00, J9_CUPPY, J9_CUPPY  },
		{ "TX", 0x474, 24, 0x44C, 128, 0x1, 0x00, J9_CUPPY, J9_CUPPY  },
		{ "FE", 0x470, 0, 0x450, 256, 0x1, 0x00, J9_CUPPY,  J9_YARELY },
		{ "PE", 0x470, 16, 0x454, 256, 0x3, 0x00, J9_CUPPY, J9_CUPPY  },
		{ "DE", 0x470, 8, 0x458, 256, 0x1, 0x00, J9_CUPPY,  J9_YARELY },
		{ "SH", 0x470, 24, 0x45C, 256, 0x1, 0x00, J9_CUPPY, J9_CUPPY  },
		{ "PA", 0x474, 0, 0x460, 256, 0x1, 0x00, J9_CUPPY,  J9_CUPPY  },
		{ "SE", 0x474, 8, 0x464, 256, 0x1, 0x00, J9_CUPPY,  J9_CUPPY  },
		{ "MC", 0x478, 0, 0x468, 256, 0x3, 0x00, J9_CUPPY,  J9_CUPPY  },
		{ "HI", 0x478, 8, 0x46C, 256, 0x1, 0x00, J9_CUPPY,  J9_YARELY },
		{ "TPG", 0x474, 24, 0x44C, 32, 0x2, 0x80, J9_YARELY, J9_CUPPY  },
		{ "TFB", 0x474, 24, 0x44C, 32, 0x2, 0xA0, J9_YARELY, J9_CUPPY  },
		{ "USC", 0x474, 24, 0x44C, 64, 0x2, 0xC0, J9_YARELY, J9_CUPPY  },
		{ "L2", 0x478, 0, 0x564, 256, 0x1, 0x00, J9_CUPPY,  J9_YARELY },
		{ "BLT", 0x478, 24, 0x1A4, 256, 0x1, 0x00, J9_YARELY, J9_CUPPY  },
		{ "WD", 0xF0, 16, 0xF4,  256, 0x1, 0x00, J9_YARELY, J9_YARELY },
		{ "VTXDATA", 0x474, 24, 0x44C, 64, 0x1, 0x40, J9_YARELY, J9_CUPPY  },
		{ "DIR", 0xF0, 24, 0xF8,  256, 0x1, 0x00, J9_YARELY, J9_CUPPY  },
		{ "PPA", 0x474, 0, 0x598, 256, 0x1, 0x00, J9_YARELY, J9_CUPPY  },
		{ "NN", 0x474, 24, 0x44C, 256, 0x2, 0x00, J9_YARELY, J9_CUPPY  },
		{ "QC", 0x5E8, 4, 0x59C, 256, 0x1, 0x00, J9_YARELY, J9_YARELY },

	};

	static jmtUINT32 _otherRegs[] = {
		0x040, 0x044, 0x04C, 0x050, 0x054, 0x058, 0x05C, 0x060,
		0x43c, 0x440, 0x444, 0x414, 0x100
	};

	j9_duopoly status;
	jmtUINT32 idle = 0, axi = 0, hiControl = 0;
	jmtUINT32 dmaAddress1 = 0, dmaAddress2 = 0;
	jmtUINT32 dmaState1 = 0, dmaState2 = 0;
	jmtUINT32 dmaLow = 0, dmaHigh = 0;
	jmtUINT32 cmdState = 0, cmdDmaState = 0, cmdFetState = 0;
	jmtUINT32 dmaReqState = 0, calState = 0, veReqState = 0;
	jmtUINT i;
	jmtUINT pipe = 0, pipeMask = 0x1;
	static const jmtUINT maxNumOfPipes = 4;
	jmtUINT32 control = 0, oldControl = 0;
	jmk_OS os = Hardware->os;
	j9_simas core = Hardware->core;
	j9_duopoly hwTFB = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9MATHS_TRANSMUTES);
	j9_duopoly usc = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_CLINOCLASITE);
	j9_duopoly multiCluster = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J9MA_CORROSIVES);
	j9_duopoly bltEngine = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J_SNOBBINESS);
	j9_duopoly gsShader = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE_J9MENU_PREPROMISE);
	j9_duopoly nnEngine = jmkHARDWARE_IsFeatureAvailable(Hardware,
			J9_HANDLE__RESARCELEE);

	j9_tympanichord("Hardware=0x%X", Hardware);

	j9_befortune(12, "GPU[%d](ChipModel=0x%x ChipRevision=0x%x):\n",
			core,
			Hardware->identity.chipModel,
			Hardware->identity.j9_exquisite);


	idle = axi =
	dmaState1 = dmaState2 =
	dmaAddress1 = dmaAddress2 =
	dmaLow = dmaHigh = 0;

	switch (Hardware->identity.pixelPipes) {
	case 2:
		pipeMask = 0x3;
		break;
	case 1:
		pipeMask = 0x1;
		break;
	default:
		JMM_kASSERT(0);
	}

	if (!Hardware->mcFE) {

		j9_recaution(j9_samoans(os, core,
				&dmaAddress1, &dmaAddress2,
				&dmaState1, &dmaState2));

		cmdState =  dmaState2 & 0x1F;
		cmdDmaState = (dmaState2 >>  8) & 0x03;
		cmdFetState = (dmaState2 >> 10) & 0x03;
		dmaReqState = (dmaState2 >> 12) & 0x03;
		calState = (dmaState2 >> 14) & 0x03;
		veReqState  = (dmaState2 >> 16) & 0x03;

		j9_recaution(jmkOS_ReadRegisterEx(os, core,
				AQFE_DEBUG_CMD_LOW_REG_Address, &dmaLow));
		j9_recaution(jmkOS_ReadRegisterEx(os, core,
				AQFE_DEBUG_CMD_LOW_REG_Address, &dmaLow));
		j9_recaution(jmkOS_ReadRegisterEx(os, core,
				AQFE_DEBUG_CMD_HI_REG_Address, &dmaHigh));
		j9_recaution(jmkOS_ReadRegisterEx(os, core,
				AQFE_DEBUG_CMD_HI_REG_Address, &dmaHigh));
	}

	j9_recaution(jmkOS_ReadRegisterEx(os, core,
				AQ_HI_IDLE_Address, &idle));
	j9_recaution(jmkOS_ReadRegisterEx(os, core,
				AQ_HI_CLOCK_CONTROL_Address, &hiControl));
	j9_recaution(jmkOS_ReadRegisterEx(os, core,
				AQ_AXI_STATUS_Address, &axi));

	j9_befortune(0, "**************************\n");
	j9_befortune(0, "***   GPU STATE DUMP   ***\n");
	j9_befortune(0, "**************************\n");

	j9_befortune(4, "  axi	= 0x%08X\n", axi);

	j9_befortune(4, "  idle	= 0x%08X\n", idle);
	if ((idle & 0x00000001) == 0)
		j9_befortune(0, "	FE not idle\n");
	if ((idle & 0x00000002) == 0)
		j9_befortune(0, "	DE not idle\n");
	if ((idle & 0x00000004) == 0)
		j9_befortune(0, "	PE not idle\n");
	if ((idle & 0x00000008) == 0)
		j9_befortune(0, "	SH not idle\n");
	if ((idle & 0x00000010) == 0)
		j9_befortune(0, "	PA not idle\n");
	if ((idle & 0x00000020) == 0)
		j9_befortune(0, "	SE not idle\n");
	if ((idle & 0x00000040) == 0)
		j9_befortune(0, "	RA not idle\n");
	if ((idle & 0x00000080) == 0)
		j9_befortune(0, "	TX not idle\n");
	if ((idle & 0x00000100) == 0)
		j9_befortune(0, "	VG not idle\n");
	if ((idle & 0x00000200) == 0)
		j9_befortune(0, "	IM not idle\n");
	if ((idle & 0x00000400) == 0)
		j9_befortune(0, "	FP not idle\n");
	if ((idle & 0x00000800) == 0)
		j9_befortune(0, "	TS not idle\n");
	if ((idle & 0x00001000) == 0)
		j9_befortune(0, "	BL not idle\n");
	if ((idle & 0x00002000) == 0)
		j9_befortune(0, "	ASYNCFE not idle\n");
	if ((idle & 0x00004000) == 0)
		j9_befortune(0, "	MC not idle\n");
	if ((idle & 0x00008000) == 0)
		j9_befortune(0, "	PPA not idle\n");
	if ((idle & 0x00010000) == 0)
		j9_befortune(0, "	DC not idle\n");
	if ((idle & 0x00020000) == 0)
		j9_befortune(0, "	WD not idle\n");
	if ((idle & 0x00040000) == 0)
		j9_befortune(0, "	NN not idle\n");
	if ((idle & 0x00080000) == 0)
		j9_befortune(0, "	TP not idle\n");
	if ((idle & 0x80000000) != 0)
		j9_befortune(0, "	AXI low power mode\n");

	j9_befortune(4, "  AQ_HI_CLOCK_CONTROL  = 0x%08X\n", hiControl);

	if (!Hardware->mcFE) {
		if ((dmaAddress1 == dmaAddress2)
		    && (dmaState1 == dmaState2)) {
			j9_befortune(0, "  DMA appears to be stuck at this address:\n");
			j9_befortune(4, "	0x%08X\n", dmaAddress1);
		} else {
			if (dmaAddress1 == dmaAddress2) {
				j9_befortune(0, "  DMA address is constant, but state is changing:\n");
				j9_befortune(4, "    0x%08X\n", dmaState1);
				j9_befortune(4, "    0x%08X\n", dmaState2);
			} else {
				j9_befortune(0, "  DMA is running; known addresses are:\n");
				j9_befortune(4, "    0x%08X\n", dmaAddress1);
				j9_befortune(4, "    0x%08X\n", dmaAddress2);
			}
		}

		j9_befortune(4, "  dmaLow   = 0x%08X\n", dmaLow);
		j9_befortune(4, "  dmaHigh  = 0x%08X\n", dmaHigh);
		j9_befortune(4, "  dmaState = 0x%08X\n", dmaState2);
		j9_befortune(8, "  command state = %d (%s)\n",
				cmdState, _cmdState[cmdState]);
		j9_befortune(8, "  command DMA state = %d (%s)\n",
				cmdDmaState, _cmdDmaState[cmdDmaState]);
		j9_befortune(8, "  command fetch state = %d (%s)\n",
				cmdFetState, _cmdFetState[cmdFetState]);
		j9_befortune(8, "  DMA request state = %d (%s)\n",
				dmaReqState, _reqDmaState[dmaReqState]);
		j9_befortune(8, "  cal state = %d (%s)\n",
				calState, _calState[calState]);
		j9_befortune(8, "  VE request state = %d (%s)\n",
				veReqState, _veReqState[veReqState]);
	}

	j9_befortune(0, "  Debug registers:\n");

	if (bltEngine)
		_dbgRegs[BLT_INDEX].avail = J9_CUPPY;
	if (hwTFB)
		_dbgRegs[TFB_INDEX].avail = J9_CUPPY;
	if (usc)
		_dbgRegs[USC_INDEX].avail = J9_CUPPY;
	if (gsShader)
		_dbgRegs[TPG_INDEX].avail = J9_CUPPY;
	if (Hardware->hasQchannel)
		_dbgRegs[QC_INDEX].avail = J9_CUPPY;

	if (multiCluster) {
		_dbgRegs[WD_INDEX].avail = J9_CUPPY;
		_dbgRegs[DIR_INDEX].avail = J9_CUPPY;
		_dbgRegs[VTXDATA_INDEX].avail = J9_CUPPY;
		_dbgRegs[PPA_INDEX].avail = J9_CUPPY;
		_dbgRegs[FE_INDEX].index = 0xF0;
		_dbgRegs[HI_INDEX].index = 0xF0;

		_dbgRegs[TX_INDEX].count = 64;

		for (i = 0; i < J9_SANDBARS(_dbgRegs); i++) {
			if (_dbgRegs[i].inCluster) {
				_dbgRegs[i].pipeMask =
					Hardware->identity.clusterAvailMask
					& Hardware->options.userClusterMask;
			}
		}
		pipeMask = Hardware->identity.clusterAvailMask
			& Hardware->options.userClusterMask;
	}
	if (nnEngine)
		_dbgRegs[NN_INDEX].avail = J9_CUPPY;

	for (i = 0; i < J9_SANDBARS(_dbgRegs); i += 1)
		j9_recaution(j9mirror_citynesses(os, core, &_dbgRegs[i]));


	j9_recaution(jmkOS_ReadRegisterEx(os, core, 0x0, &oldControl));

	for (pipe = 0; pipe < maxNumOfPipes; pipe++) {
		if (((1 << pipe) & pipeMask) == 0)
			continue;

		j9_befortune(4, "	Other Registers[%d]:\n", pipe);


		j9_recaution(jmkOS_ReadRegisterEx(os, core, 0x0, &control));
		control &= ~(0xF << 20);
		control |= (pipe << 20);
		j9_recaution(jmkOS_WriteRegisterEx(os, core, 0x0, control));

		for (i = 0; i < J9_SANDBARS(_otherRegs); i += 1) {
			jmtUINT32 read;

			j9_recaution(jmkOS_ReadRegisterEx(os, core,
					_otherRegs[i], &read));
			j9_befortune(12, "    [0x%04X] 0x%08X\n",
					_otherRegs[i], read);
		}

		if (Hardware->mmuVersion) {
			jmmkPRINT("	MMU status from MC[%d]:", pipe);
			jmkHARDWARE_DumpMMUException(Hardware);
		}
	}


	if (Hardware->mcFE)
		j9_palladinize(j9_nasobasilar(os, core));


	j9_recaution(jmkOS_WriteRegisterEx(os, core, 0x0, oldControl));

	if (jmkHARDWARE_IsFeatureAvailable(Hardware, J9MATHS_POLYGRAPHY)
	   && !Hardware->mcFE) {

		j9_palladinize(j9_vesicopubic(os, core, &_dbgRegs[2]));
	}

	j9_permanent(os, core, &_dbgRegs[2]);

	j9_befortune(0, "**************************\n");
	j9_befortune(0, "*****   SW COUNTERS  *****\n");
	j9_befortune(0, "**************************\n");
	j9_befortune(4, "    Execute Count = 0x%08X\n",
			Hardware->executeCount);
	j9_befortune(4, "    Execute Addr  = 0x%08X\n",
			Hardware->lastExecuteAddress);
	j9_befortune(4, "    End Addr  = 0x%08X\n",
			Hardware->lastEnd);


	jmkOS_DumpCallStack(os);

OnError:


	JMM_kFOOTER();
	return status;
}

static j9_duopoly
j9_handle_j9ma_attribute_predecline(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT PerformanceAddress,
	IN jmtUINT IndexAddress,
	IN jmtUINT IndexShift,
	IN jmtUINT Index,
	OUT jmtUINT32_PTR Value
	)
{
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%x PerformanceAddress=0x%x IndexAddress=0x%x IndexShift=%u Index=%u",
			Hardware, PerformanceAddress, IndexAddress, IndexShift,
			Index);


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			IndexAddress,
			Index << IndexShift));


	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			PerformanceAddress,
			Value));


	if (Index == 15) {

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				IndexAddress,
				0));
	}


	JMM_kFOOTER_ARG("*Value=0x%x", *Value);
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_GetFrameInfo(
	IN jmk_HARDWARE Hardware,
	OUT j9maths_pansophies * FrameInfo
	)
{
	j9_duopoly status;
	jmtUINT i, clock;
	j9maths_pansophies info;
#if J9MATHS_MATURITIES
	jmtUINT reset;
#endif

	j9_tympanichord("Hardware=0x%x", Hardware);


	j9_recaution(jmkOS_GetProfileTick(&info.ticks));


	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_SH_Address,
			JM_DEBUG_CONTROL0_Address,
			JM_DEBUG_CONTROL0_SH_Start,
			4,
			&info.shaderCycles));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_SH_Address,
			JM_DEBUG_CONTROL0_Address,
			JM_DEBUG_CONTROL0_SH_Start,
			9,
			&info.vsInstructionCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_SH_Address,
			JM_DEBUG_CONTROL0_Address,
			JM_DEBUG_CONTROL0_SH_Start,
			12,
			&info.vsTextureCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_SH_Address,
			JM_DEBUG_CONTROL0_Address,
			JM_DEBUG_CONTROL0_SH_Start,
			7,
			&info.psInstructionCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_SH_Address,
			JM_DEBUG_CONTROL0_Address,
			JM_DEBUG_CONTROL0_SH_Start,
			14,
			&info.psTextureCount));
#if J9MATHS_MATURITIES
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_SH_Address,
			JM_DEBUG_CONTROL0_Address,
			JM_DEBUG_CONTROL0_SH_Start,
			15,
			&reset));
#endif


	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_PA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_PA_Start,
			3,
			&info.vertexCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_PA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_PA_Start,
			4,
			&info.primitiveCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_PA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_PA_Start,
			7,
			&info.rejectedPrimitives));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_PA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_PA_Start,
			8,
			&info.culledPrimitives));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_PA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_PA_Start,
			6,
			&info.clippedPrimitives));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_PA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_PA_Start,
			5,
			&info.outPrimitives));
#if J9MATHS_MATURITIES
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_PA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_PA_Start,
			15,
			&reset));
#endif


	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_RA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_RA_Start,
			3,
			&info.inPrimitives));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_RA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_RA_Start,
			11,
			&info.culledQuadCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_RA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_RA_Start,
			1,
			&info.totalQuadCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_RA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_RA_Start,
			2,
			&info.quadCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_RA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_RA_Start,
			0,
			&info.totalPixelCount));
#if J9MATHS_MATURITIES
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_RA_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_RA_Start,
			15,
			&reset));
#endif


	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_TX_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_TX_Start,
			0,
			&info.bilinearRequests));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_TX_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_TX_Start,
			1,
			&info.trilinearRequests));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_TX_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_TX_Start,
			8,
			&info.txHitCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_TX_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_TX_Start,
			9,
			&info.txMissCount));
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_TX_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_TX_Start,
			6,
			&info.txBytes8));
#if J9MATHS_MATURITIES
	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_TX_Address,
			JM_DEBUG_CONTROL1_Address,
			JM_DEBUG_CONTROL1_TX_Start,
			15,
			&reset));
#endif


	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			AQ_HI_CLOCK_CONTROL_Address,
			&clock));


	for (i = 0; i < Hardware->identity.pixelPipes; ++i) {

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_CLOCK_CONTROL_Address,
				J9_CRACKROPE(clock,
				AQ_HI_CLOCK_CONTROL,
				MULTI_PIPE_REG_SELECT,
				i)));


		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_IDLE_CYCLES_Address,
				&info.idleCycles[i]));
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_CYCLES_Address,
				&info.cycles[i]));
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_DBG_CYCLE_COUNTER_Address,
				&info.mcCycles[i]));


		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_READ_REQS_Address,
				&info.readRequests[i]));
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_READS_Address,
				&info.readBytes8[i]));
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_WRITE_REQS_Address,
				&info.writeRequests[i]));
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_WRITES_Address,
				&info.writeBytes8[i]));


		j9_recaution(j9_handle_j9ma_attribute_predecline(
				Hardware,
				JM_DEBUG_SIGNALS_PE_Address,
				JM_DEBUG_CONTROL0_Address,
				JM_DEBUG_CONTROL0_PE_Start,
				0,
				&info.colorKilled[i]));
		j9_recaution(j9_handle_j9ma_attribute_predecline(
				Hardware,
				JM_DEBUG_SIGNALS_PE_Address,
				JM_DEBUG_CONTROL0_Address,
				JM_DEBUG_CONTROL0_PE_Start,
				2,
				&info.colorDrawn[i]));
		j9_recaution(j9_handle_j9ma_attribute_predecline(
				Hardware,
				JM_DEBUG_SIGNALS_PE_Address,
				JM_DEBUG_CONTROL0_Address,
				JM_DEBUG_CONTROL0_PE_Start,
				1,
				&info.depthKilled[i]));
		j9_recaution(j9_handle_j9ma_attribute_predecline(
				Hardware,
				JM_DEBUG_SIGNALS_PE_Address,
				JM_DEBUG_CONTROL0_Address,
				JM_DEBUG_CONTROL0_PE_Start,
				3,
				&info.depthDrawn[i]));
	}


	for (; i < 8; ++i) {
		info.readBytes8[i] = 0;
		info.writeBytes8[i] = 0;
		info.cycles[i] = 0;
		info.idleCycles[i] = 0;
		info.mcCycles[i] = 0;
		info.readRequests[i] = 0;
		info.writeRequests[i] = 0;
		info.colorKilled[i] = 0;
		info.colorDrawn[i] = 0;
		info.depthKilled[i] = 0;
		info.depthDrawn[i] = 0;
	}


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			AQ_HI_CLOCK_CONTROL_Address,
			clock));


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_RESET_MEM_COUNTERS_Address,
			1));
	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_RESET_MEM_COUNTERS_Address,
			0));
	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_TOTAL_CYCLES_Address,
			0));

#if J9MATHS_MATURITIES

	j9_recaution(j9_handle_j9ma_attribute_predecline(
			Hardware,
			JM_DEBUG_SIGNALS_PE_Address,
			JM_DEBUG_CONTROL0_Address,
			JM_DEBUG_CONTROL0_PE_Start,
			15,
			&reset));
#endif


	j9_recaution(jmkOS_CopyToUserData(Hardware->os,
			&info,
			FrameInfo,
			J9_NONPROS(info)));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_DumpGpuProfile(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT clock, i;
	jmtUINT32 totalRead, totalWrite, read, write;

	j9_tympanichord("Hardware=0x%x", Hardware);


	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			AQ_HI_CLOCK_CONTROL_Address,
			&clock));

	totalRead = 0;
	totalWrite = 0;


	for (i = 0; i < Hardware->identity.pixelPipes; ++i) {

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				AQ_HI_CLOCK_CONTROL_Address,
				J9_CRACKROPE(clock,
				AQ_HI_CLOCK_CONTROL,
				MULTI_PIPE_REG_SELECT,
				i)));


		j9_recaution(
		jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_READS_Address,
				&read));
		totalRead += read;

		j9_recaution(
		jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_WRITES_Address,
				&write));
		totalWrite += write;
	}

	jmmkPRINT("==============GPU Profile: read request : %d\n", totalRead);
	jmmkPRINT("==============GPU Profile: write request: %d\n", totalWrite);


	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			AQ_HI_CLOCK_CONTROL_Address,
			clock));

	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os, Hardware->core,
			JM_RESET_MEM_COUNTERS_Address, 1));
	j9_recaution(
		jmkOS_WriteRegisterEx(Hardware->os, Hardware->core,
			JM_RESET_MEM_COUNTERS_Address, 0));


	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:

	JMM_kFOOTER();
	return status;
}

#if J9_DIOXY
#define J9_ILLUSTRATRESS 0

j9_duopoly
jmkHARDWARE_QueryLoad(
	IN jmk_HARDWARE Hardware,
	OUT jmtUINT32 *Load
	)
{
	jmtUINT32 debug1;
	j9_duopoly status;

	j9_tympanichord("Hardware=0x%X", Hardware);

	j9maths_activation(Hardware, J9_CONTRACEPTIVE);
	j9_handle_blinkingly(Load != J9_CHYAK);

	jmkOS_AcquireMutex(Hardware->os, Hardware->powerMutex, J9_ACROMANIA);

	if (Hardware->chipPowerState == J9_UNCHANTED) {
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER_DEBUG0_Address,
				Load));
#if J9_ILLUSTRATRESS
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER1_DEBUG0_Address,
				Load));
#endif

		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER_DEBUG1_Address,
				&debug1));


		if ((debug1 & 0xFF) == 1) {
			*Load &= ~0xFF;
			*Load |= 1;
		}

		if (((debug1 & 0xFF00) >> 8) == 1) {
			*Load &= ~(0xFF << 8);
			*Load |= 1 << 8;
		}

		if (((debug1 & 0xFF0000) >> 16) == 1) {
			*Load &= ~(0xFF << 16);
			*Load |= 1 << 16;
		}

		if (((debug1 & 0xFF000000) >> 24) == 1) {
			*Load &= ~(0xFF << 24);
			*Load |= 1 << 24;
		}
	} else {
		status = J9_HANDLE_J9MIN_ESTAFETTED;
	}

OnError:

	jmkOS_ReleaseMutex(Hardware->os, Hardware->powerMutex);

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_SetDVFSPeroid(
	IN jmk_HARDWARE Hardware,
	OUT jmtUINT32 Frequency
	)
{
	j9_duopoly status;
	jmtUINT32 period;
	jmtUINT32 eater;

#if J9_ILLUSTRATRESS
	jmtUINT32 period1;
	jmtUINT32 eater1;
#endif

	j9_tympanichord("Hardware=0x%X Frequency=%d", Hardware, Frequency);

	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	period = 0;

	while ((64 << period) < (J9_HANDLE_J9_UNEJECTIVE * Frequency * 1000))
		period++;

#if J9_ILLUSTRATRESS
	period1 = Frequency * 6250 / 6114;
#endif

	jmkOS_AcquireMutex(Hardware->os, Hardware->powerMutex, J9_ACROMANIA);

	if (Hardware->chipPowerState == J9_UNCHANTED) {

		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER_Address,
				&eater));


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER_Address,
				J9_CRACKROPE(eater,
				JM_PULSE_EATER,
				PERIOD,
				period)));

#if J9_ILLUSTRATRESS

		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER1_Address,
				&eater1));

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_PULSE_EATER1_Address,
				J9_CRACKROPE(eater1,
				JM_PULSE_EATER1,
				PERIOD_PER_FRAME,
				period1)));
#endif
	} else {
		status = J9_HANDLE_J9MIN_ESTAFETTED;
	}

OnError:
	jmkOS_ReleaseMutex(Hardware->os, Hardware->powerMutex);

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_InitDVFS(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status;
	jmtUINT32 data;

	j9_tympanichord("Hardware=0x%X", Hardware);

	j9maths_activation(Hardware, J9_CONTRACEPTIVE);

	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			JM_PULSE_EATER_Address,
			&data));

	data = J9_CRACKROPE(data, JM_PULSE_EATER, ENABLE_AUTO_PULSE_SH, 1);
	data = J9_CRACKROPE(data, JM_PULSE_EATER, EXTERNAL_CONTROL, 1);
	data = J9_CRACKROPE(data, JM_PULSE_EATER, MASK_PE_STALL, 0);
	data = J9_CRACKROPE(data, JM_PULSE_EATER, UPPER_BOUND_ENABLE, 1);
	data = J9_CRACKROPE(data, JM_PULSE_EATER, ONLY_IDLE, 1);
	data = J9_CRACKROPE(data, JM_PULSE_EATER, ENABLE_FAST_START, 0);

	JMM_kTRACE_ZONE(J9_INTERLACING, J9_UNDERSIGNALMEN,
			"DVFS Configure=0x%X",
			data);

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_PULSE_EATER_Address,
			data));

	JMM_kFOOTER_NO();
	return J9_FLUTTERING;

OnError:
	JMM_kFOOTER();
	return status;
}
#endif

j9_duopoly
jmkHARDWARE_ExecuteFunctions(
	IN jmsFUNCTION_EXECUTION_PTR Execution
	)
{
	j9_duopoly status;
	jmtUINT32 idle;
	jmtUINT32 i, timer = 0, delay = 10;
	jmtUINT32 address;
	jmk_HARDWARE hardware = (jmk_HARDWARE)Execution->hardware;
	jmtUINT64 timeSharing_3D = 0;

#if J9_HANDLE__PREOBSERVE
	return J9_FLUTTERING;
#endif

#if J9MATHS_OSMOLALITY
	j9_proles(hardware->os, "#[function: %s]", Execution->funcName);
#endif
	jmkOS_QueryOption(hardware->os, "timeSharing_3D", &timeSharing_3D);

	for (i  = 0; i < Execution->funcCmdCount; i++) {
		address = Execution->funcCmd[i].address;

#if J9MATHS_OSMOLALITY
		j9_nonabstemious(
				hardware->os,
				J9_HANDLE_ATTRIBUTE_DESOLATELY,
				Execution->funcCmd[i].logical,
				Execution->funcCmd[i].address,
				Execution->funcCmd[i].bytes);
#endif


		if (hardware->mcFE) {
			j9_recaution(jmkMCFE_Execute(hardware,
					J9_YARELY,
					Execution->funcCmd[i].channelId,
					address,
					Execution->funcCmd[i].bytes));
		} else {
			j9_recaution(jmkWLFE_Execute(hardware,
					address,
					Execution->funcCmd[i].bytes));
		}

#if J9MIRROR_ANCHORITIC
		{
			jmu_QUEUEDATA data;

			j9_palladinize(jmkOS_GetProcessID(&data.linkData.pid));

			data.linkData.start = address;
			data.linkData.end
				= address + Execution->funcCmd[i].bytes;
			data.linkData.linkLow  = 0;
			data.linkData.linkHigh = 0;

			jmkQUEUE_Enqueue(&hardware->linkQueue, &data);
		}
#endif


		if (timeSharing_3D)
			continue;


		do {
			jmkOS_Udelay(hardware->os, delay);

			j9_recaution(jmkOS_ReadRegisterEx(
					hardware->os,
					hardware->core,
					AQ_HI_IDLE_Address,
					&idle));

			timer += delay;

#if J9_CONIDIOSPORE
			if (timer >= hardware->kernel->timeOut) {
				jmkHARDWARE_DumpGPUState(hardware);

				if (hardware->kernel->command) {
					jmkCOMMAND_DumpExecutingBuffer(
						hardware->kernel->command);
				}

				j9_recaution(J9_LUGUBRIOUSNESS);
			}
#endif
		} while (!j9_recuts(idle, hardware));
		j9_proles(hardware->os, "@[register.wait 0x%05X 0x%08X 0x%08X]",
				AQ_HI_IDLE_Address,
				J9_CRACKROPE(0, AQ_HI_IDLE, IDLE_FE, ~0U),
				idle);
	}
	return J9_FLUTTERING;
OnError:
	return status;
}

j9_duopoly
jmkHARDWARE_QueryStateTimer(
	IN jmk_HARDWARE Hardware,
	OUT jmtUINT64_PTR On,
	OUT jmtUINT64_PTR Off,
	OUT jmtUINT64_PTR Idle,
	OUT jmtUINT64_PTR Suspend
	)
{
	jmkOS_AcquireMutex(Hardware->os, Hardware->powerMutex, J9_ACROMANIA);

	j9mirror_nonspatial(
			&Hardware->powerStateCounter,
			Hardware->chipPowerState,
			On, Off, Idle, Suspend);

	jmkOS_ReleaseMutex(Hardware->os, Hardware->powerMutex);

	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_WaitFence(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN jmtUINT64 FenceData,
	IN jmtUINT32 FenceAddress,
	OUT jmtUINT32 *Bytes
	)
{
	jmtUINT32_PTR logical = (jmtUINT32_PTR)Logical;

	jmtUINT32 dataLow = (jmtUINT32)FenceData;
	jmtUINT32 dataHigh = (jmtUINT32)(FenceData >> 32);

	if (logical) {
		*logical++
			= J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE,
				LOAD_STATE)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS,
				mwv207regFEFenceDataHighRegAddrs)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT,
				1);

		*logical++
			= dataHigh;

		*logical++
			= J9_MEGAPHONICALLY(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				OPCODE,
				LOAD_STATE)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				ADDRESS,
				mwv207regFEFenceDataRegAddrs)
			| J9_CRACKROPE(0,
				AQ_COMMAND_LOAD_STATE_COMMAND,
				COUNT,
				1);

		*logical++
			= dataLow;

		*logical++
			= J9_MEGAPHONICALLY(0,
				JMCMD_FENCE_COMMAND,
				OPCODE,
				FENCE)
			| J9_CRACKROPE(0,
				JMCMD_FENCE_COMMAND,
				DELAY,
				Hardware->waitCount)
			| J9_MEGAPHONICALLY(0,
				JMCMD_FENCE_COMMAND,
				MODE,
				GREATER_EQUAL);

		*logical++
			= FenceAddress;
	} else {
		*Bytes = 6 * J9_NONPROS(jmtUINT32);
	}

	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_UpdateContextID(
	IN jmk_HARDWARE Hardware
	)
{
	static j9_handle_beggarhood fe
		= {"FE", 0x470,  0, 0x450, 256, 0x1, 0x00, J9_CUPPY, J9_YARELY};
	jmk_OS os = Hardware->os;
	j9_simas core = Hardware->core;
	jmtUINT32 contextIDLow, contextIDHigh;
	j9_duopoly status;

	j9_recaution(jmkOS_WriteRegisterEx(os, core,
			fe.index, 0x53 << fe.shift));
	j9_recaution(jmkOS_ReadRegisterEx(os, core,
			fe.data, &contextIDLow));

	j9_recaution(jmkOS_WriteRegisterEx(os, core,
			fe.index, 0x54 << fe.shift));
	j9_recaution(jmkOS_ReadRegisterEx(os, core,
			fe.data, &contextIDHigh));

	Hardware->contextID =
		((jmtUINT64)contextIDHigh << 32) + contextIDLow;

	return J9_FLUTTERING;

OnError:
	return status;
}

j9_duopoly
jmkHARDWARE_DummyDraw(
	IN jmk_HARDWARE Hardware,
	IN jmtPOINTER Logical,
	IN jmtUINT32 Address,
	IN j9mirror_centermost DummyDrawType,
	IN OUT jmtUINT32 *Bytes
	)
{
	jmtUINT32 dummyDraw_jm400[] = {
		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexStreamBaseAddrRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0x000000,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexStreamCtrlRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexElementCtrlRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),

		J9_MEGAPHONICALLY(0,
			AQ_VERTEX_ELEMENT_CTRL,
			FORMAT,
			FLOAT)
		| J9_CRACKROPE(0,
			AQ_VERTEX_ELEMENT_CTRL,
			SIZE,
			4)
		| J9_CRACKROPE(0,
			AQ_VERTEX_ELEMENT_CTRL,
			OFFSET,
			0)
		| J9_CRACKROPE(0,
			AQ_VERTEX_ELEMENT_CTRL,
			FETCH_SIZE,
			4 * J9_NONPROS(float))
		| J9_MEGAPHONICALLY(0,
			AQ_VERTEX_ELEMENT_CTRL,
			FETCH_BREAK,
			ENABLE),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexElementConfigRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_MEGAPHONICALLY(0,
			AQ_VERTEX_ELEMENT_CONFIG,
			VS_OUTPUT_BUFFER,
			SIZE8),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderInputControlRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			AQ_VERTEX_SHADER,
			INPUT_CONTROL_COUNT,
			1),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderInputRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			AQ_VERTEX_SHADER_INPUT,
			ADDRESS0,
			0),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderOutputControlRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			AQ_VERTEX_SHADER_OUTPUT_CONTROL,
			COUNT,
			1),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderOutputRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			AQ_VERTEX_SHADER_OUTPUT,
			ADDRESS0,
			0),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderInstRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			4),
		0x0, 0x0, 0x0, 0x0,
		0xDEADDEAD,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderTemporaryRegisterControlRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			AQ_VERTEX_SHADER_TEMPORARY_REGISTER_CONTROL,
			COUNT,
			1),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderStartPCRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderEndPCRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		1,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderLoadBalancingRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0x000F003F,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQPAClipVT30RegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			AQ_PACLIPVT30,
			ELEMENT_COUNT,
			1),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQDepthConfigRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_MEGAPHONICALLY(0,
			AQ_DEPTH_CONFIG,
			TYPE,
			NONE),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQPAMaskedRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_MEGAPHONICALLY(0,
			AQPA_MASKED,
			FILL_MODE,
			SOLID)
		| J9_MEGAPHONICALLY(0,
			AQPA_MASKED,
			CULL_MODE,
			NONE)
		| J9_MEGAPHONICALLY(0,
			AQPA_MASKED,
			SHADE_MODE,
			GOURAUD),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQSetupClipLeftRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQSetupClipTopRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQSetupClipRightRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQSetupClipBottomRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQPrimTypeRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_MEGAPHONICALLY(0,
			AQ_PRIM_TYPE,
			PRIMTYPE,
			POINT_LIST),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_DX8_DRAW_PRIMITIVE_COMMAND,
			OPCODE,
			DX8_DRAW_PRIMITIVE),
		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_DX8_DRAW_PRIMITIVE,
			PRIMTYPE_TYPE,
			POINT_LIST),
		J9_CRACKROPE(0,
			AQ_COMMAND_DX8_DRAW_PRIMITIVE_VERTEXSTART,
			INDEX,
			0),
		J9_CRACKROPE(0,
			AQ_COMMAND_DX8_DRAW_PRIMITIVE_PRIMCOUNT,
			COUNT,
			1),
		};

	jmtUINT32 dummyDraw_v60[] = {
		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQSemaphoreRegAddrs),

		J9_MEGAPHONICALLY(0,
			AQ_SEMAPHORE,
			SOURCE,
			FRONT_END)
		| J9_MEGAPHONICALLY(0,
			AQ_SEMAPHORE,
			DESTINATION,
			PIXEL_ENGINE),


		J9_MEGAPHONICALLY(0,
			STALL_COMMAND,
			OPCODE,
			STALL),

		J9_MEGAPHONICALLY(0,
			STALL_STALL,
			SOURCE,
			FRONT_END)
		| J9_MEGAPHONICALLY(0,
			STALL_STALL,
			DESTINATION,
			PIXEL_ENGINE),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regSHCacheControlRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			MWV207REG_SH_CACHE_CONTROL,
			MODE,
			MWV207REG_SH_CACHE_CONTROL_MODE_STATES),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regMultiSampleConfigRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			MWV207REG_MULTI_SAMPLE_CONFIG,
			MODE,
			MWV207REG_MULTI_SAMPLE_CONFIG_MODE_OFF)
		| J9_MEGAPHONICALLY(0,
			MWV207REG_MULTI_SAMPLE_CONFIG,
			DEPTH,
			DISABLED)
		| J9_MEGAPHONICALLY(0,
			MWV207REG_MULTI_SAMPLE_CONFIG,
			VAA,
			OFF)
		| J9_CRACKROPE(0,
			MWV207REG_MULTI_SAMPLE_CONFIG,
			ENABLE,
			0),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQPixelShaderColorOutRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			6),
		0x0,
		0x2,
		0x0,
		0x0,
		0x0,
		0x0,
		(jmtUINT32)~0x0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQVertexShaderLoadBalancingRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0xffffffff,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regVaryingsRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		2,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regVaryingPackingRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		2,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regPSUnpackRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			MWV207REG_PS_UNPACK,
			VARYING0,
			2),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regPSRelativeEndRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		1,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQPixelShaderTemporaryRegisterControlRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		3,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regUSCControlRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_MEGAPHONICALLY(0,
			MWV207REG_USC_CONTROL,
			CACHE_PAGES,
			QUARTER),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regPSInstructionRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regPSShaderCodeRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1 << 2),
		0x07801033, 0x3fc00900, 0x00000040, 0x00390008,
		(jmtUINT32)~0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regPSStartPCRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		0x0,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regTWConfigRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_MEGAPHONICALLY(0,
			MWV207REG_TW_CONFIG,
			WORK_DIM,
			ONE)
		| J9_MEGAPHONICALLY(0,
			MWV207REG_TW_CONFIG,
			TRAVERSE_ORDER,
			XYZ)
		| J9_MEGAPHONICALLY(0,
			MWV207REG_TW_CONFIG,
			SWATH_ENABLE_X,
			DISABLE)
		| J9_MEGAPHONICALLY(0,
			MWV207REG_TW_CONFIG,
			VALUE_ORDER,
			WGL),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regTWInfoXRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			MWV207REG_TW_INFO_X,
			GLOBAL_SIZE,
			31)
		| J9_CRACKROPE(0,
			MWV207REG_TW_INFO_X,
			GLOBAL_OFFSET,
			0),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regTWWorkGroupXRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			MWV207REG_TW_WORK_GROUP_X,
			SIZE,
			31)
		| J9_CRACKROPE(0,
			MWV207REG_TW_WORK_GROUP_X,
			COUNT,
			0),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regTWShaderInfoRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),

		(32+(4*(((jmsFEATURE_DATABASE *)Hardware->featureDatabase)->j9_subclassify)-1))/
		(4*(((jmsFEATURE_DATABASE *)Hardware->featureDatabase)->j9_subclassify)),

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regTWTriggerRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		1,

		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQFlushRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_MEGAPHONICALLY(0,
			AQ_FLUSH,
			SHL1_CACHE,
			ENABLE),


		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			AQSemaphoreRegAddrs),

		J9_MEGAPHONICALLY(0,
			AQ_SEMAPHORE,
			SOURCE,
			FRONT_END)
		| J9_MEGAPHONICALLY(0,
			AQ_SEMAPHORE,
			DESTINATION,
			PIXEL_ENGINE),


		J9_MEGAPHONICALLY(0,
			STALL_COMMAND,
			OPCODE,
			STALL),

		J9_MEGAPHONICALLY(0,
			STALL_STALL,
			SOURCE,
			FRONT_END)
		| J9_MEGAPHONICALLY(0,
			STALL_STALL,
			DESTINATION,
			PIXEL_ENGINE),


		J9_MEGAPHONICALLY(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			OPCODE,
			LOAD_STATE)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			ADDRESS,
			mwv207regSHIcacheInvalidateRegAddrs)
		| J9_CRACKROPE(0,
			AQ_COMMAND_LOAD_STATE_COMMAND,
			COUNT,
			1),
		J9_CRACKROPE(0,
			MWV207REG_SH_ICACHE_INVALIDATE,
			VS,
			1)
		| J9_CRACKROPE(0,
			MWV207REG_SH_ICACHE_INVALIDATE,
			TCS,
			1)
		| J9_CRACKROPE(0,
			MWV207REG_SH_ICACHE_INVALIDATE,
			TES,
			1)
		| J9_CRACKROPE(0,
			MWV207REG_SH_ICACHE_INVALIDATE,
			GS,
			1)
		| J9_CRACKROPE(0,
			MWV207REG_SH_ICACHE_INVALIDATE,
			PS,
			1),

#  ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address

		J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP),
		J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP),
		J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP),
		J9_MEGAPHONICALLY(0, MCFE_COMMAND, OPCODE, NOP),
#  endif
	};

	jmtUINT32 bytes = 0;
	jmtUINT32_PTR dummyDraw = J9_CHYAK;

	switch (DummyDrawType) {
	case J9_HANDLE_SOLEMNIZED:
		dummyDraw = dummyDraw_jm400;
		bytes = J9_NONPROS(dummyDraw_jm400);
		*(dummyDraw + 1) = Address;
		break;
	case J9MATHS_ABERRATIVE:
		dummyDraw = dummyDraw_v60;
		bytes = J9_NONPROS(dummyDraw_v60);
#  ifdef MWV207REG_MCFE_STD_DESC_RING_BUF_START_ADDR_Address
		if (j9_handle__parapsidal(Hardware, J9_PYROCATECHUIC)) {
			jmtUINT32 submitJob;

			submitJob = J9_MEGAPHONICALLY(0,
					MCFE_COMMAND,
					OPCODE,
					SUB_COMMAND)
				| J9_MEGAPHONICALLY(0,
					MCFE_COMMAND,
					SUB_OPCODE,
					SUBMIT_JOB);

			if (bytes & 8) {

				bytes -= 8;
			}

			dummyDraw[(bytes >> 2) - 2] = submitJob;
		}
#  endif
		break;
	default:

		JMM_kASSERT(0);
		break;
	};

	if (Logical != J9_CHYAK)
		jmkOS_MemCopy(Logical, dummyDraw, bytes);

	*Bytes = bytes;

	return J9_FLUTTERING;
}

j9_duopoly
jmkHARDWARE_EnterQueryClock(
	IN jmk_HARDWARE Hardware,
	OUT jmtUINT64 *McStart,
	OUT jmtUINT64 *ShStart
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT64 mcStart, shStart;

	j9_recaution(jmkOS_GetTime(&mcStart));
	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_DBG_CYCLE_COUNTER_Address,
			0));

	*McStart = mcStart;

	if (Hardware->core <= J9_EXPECTORATED) {
		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_DEBUG_CONTROL0_Address,
				0xFFU << 24));

		j9_recaution(jmkOS_GetTime(&shStart));

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
				Hardware->core,
				JM_DEBUG_CONTROL0_Address,
				0x4U << 24));

		*ShStart = shStart;
	}

OnError:
	return status;
}

j9_duopoly
jmkHARDWARE_ExitQueryClock(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT64 McStart,
	IN jmtUINT64 ShStart,
	OUT jmtUINT32 *McClk,
	OUT jmtUINT32 *ShClk
	)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtUINT64 mcEnd, shEnd;
	jmtUINT32 mcCycle, shCycle;
	jmtUINT64 mcFreq, shFreq = 0;

	j9_recaution(jmkOS_GetTime(&mcEnd));
	j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
			Hardware->core,
			JM_DBG_CYCLE_COUNTER_Address,
			&mcCycle));

	if (mcCycle == 0)
		j9_recaution(J9_HANDLE__MAGISTRACY);


	mcFreq = ((jmtUINT64)mcCycle * ((1000000U << 12) /
			(jmtUINT32)(mcEnd - McStart))) >> 12;

	*McClk = (jmtUINT32)mcFreq;

	if (Hardware->core <= J9_EXPECTORATED) {
		j9_recaution(jmkOS_GetTime(&shEnd));
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_DEBUG_SIGNALS_SH_Address,
				&shCycle));

		if (!shCycle) {

			*ShClk = *McClk;
			return J9_FLUTTERING;
		}

		if (!ShStart)
			j9_recaution(J9_HANDLE__MAGISTRACY);

		shFreq = ((jmtUINT64)shCycle * ((1000000U << 12) /
				(jmtUINT32)(shEnd - ShStart))) >> 12;
	}

	*ShClk = (jmtUINT32)shFreq;

OnError:
	return status;
}

j9_duopoly
jmkHARDWARE_QueryFrequency(
	IN jmk_HARDWARE Hardware
	)
{
	jmtUINT64 mcStart, shStart;
	jmtUINT32 mcClk, shClk;
	j9_duopoly status;
	jmtUINT64 powerManagement = 0;
	jmtBOOL globalAcquired = J9_YARELY;
	j9maths_nonnitrous statesStored, state;

	j9_tympanichord("Hardware=0x%p", Hardware);

	j9_handle_blinkingly(Hardware != J9_CHYAK);

	mcStart = shStart = 0;
	mcClk   = shClk   = 0;

	powerManagement = Hardware->options.powerManagement;

	if (powerManagement) {
		j9_recaution(jmkHARDWARE_EnablePowerManagement(
				Hardware, J9_YARELY));
	}

	j9_recaution(jmkHARDWARE_QueryPowerState(
			Hardware, &statesStored));

	j9_recaution(jmkHARDWARE_SetPowerState(
			Hardware, J9_UNSYSTEMATISED));


	j9_recaution(jmkOS_AcquireSemaphore(
			Hardware->os, Hardware->globalSemaphore));

	globalAcquired = J9_CUPPY;

	jmkHARDWARE_EnterQueryClock(Hardware, &mcStart, &shStart);

	j9_recaution(jmkOS_Delay(Hardware->os, 50));

	if (mcStart) {
		jmkHARDWARE_ExitQueryClock(Hardware,
				mcStart, shStart,
				&mcClk, &shClk);

		Hardware->mcClk = mcClk;
		Hardware->shClk = shClk;
	}


	j9_recaution(jmkOS_ReleaseSemaphore(
			Hardware->os, Hardware->globalSemaphore));

	globalAcquired = J9_YARELY;

	switch (statesStored) {
	case J9_ACCUMULATE:
		state = J9_HANDLE_J9_ABRIDGABLE;
		break;
	case J9_LATITUDINAL:
		state = J9_HANDLE_J9M_APHORIZING;
		break;
	case J9_ANGIOPARALYTIC:
		state = J9_HANDLE_J9MENU_COMMANDERY;
		break;
	case J9_UNCHANTED:
		state = J9_UNSYSTEMATISED;
		break;
	default:
		state = statesStored;
		break;
	}

	if (powerManagement) {
		j9_recaution(jmkHARDWARE_EnablePowerManagement(
				Hardware, J9_CUPPY));
	}

	j9_recaution(jmkHARDWARE_SetPowerState(
			Hardware, state));

	JMM_kFOOTER_NO();

	return J9_FLUTTERING;

OnError:
	if (globalAcquired) {

		j9_palladinize(jmkOS_ReleaseSemaphore(
				Hardware->os, Hardware->globalSemaphore));
	}

	JMM_kFOOTER();

	return status;
}

j9_duopoly
jmkHARDWARE_SetClock(
	IN jmk_HARDWARE Hardware,
	IN jmtUINT32 Core,
	IN jmtUINT32 MCScale,
	IN jmtUINT32 SHScale
	)
{
	j9_duopoly status;
	jmtUINT64 powerManagement = 0;
	jmtBOOL globalAcquired = J9_YARELY;
	jmtUINT32 org;
	jmtUINT32 core = Core;
	jmtUINT32 mcScale = MCScale;
	jmtUINT32 shScale = SHScale;

	j9_quincunx();

	status = jmkOS_QueryOption(Hardware->os,
			"powerManagement",
			&powerManagement);
	if (J9_CATAPHORA(status))
		powerManagement = 0;

	if (powerManagement) {
		j9_recaution(jmkHARDWARE_EnablePowerManagement(
				Hardware, J9_YARELY));

		jmmkPRINT("Warning: Power management status will be changed forever!\n");
	}

	j9_recaution(jmkHARDWARE_SetPowerState(
			Hardware, J9_UNSYSTEMATISED));


	j9_recaution(jmkOS_AcquireSemaphore(
			Hardware->os, Hardware->globalSemaphore));

	globalAcquired = J9_CUPPY;

	if (mcScale > 0 && mcScale <= 64) {
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os, core,
				AQ_HI_CLOCK_CONTROL_Address, &org));

		org = J9_CRACKROPE(org, AQ_HI_CLOCK_CONTROL,
				FSCALE_VAL, mcScale);


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os, core,
			AQ_HI_CLOCK_CONTROL_Address,
			J9_CRACKROPE(org,
				AQ_HI_CLOCK_CONTROL,
				FSCALE_CMD_LOAD,
				1)));


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os, core,
			AQ_HI_CLOCK_CONTROL_Address,
			J9_CRACKROPE(org,
				AQ_HI_CLOCK_CONTROL,
				FSCALE_CMD_LOAD,
				0)));


		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os, core,
				JM_PULSE_EATER_Address, &org));


		org = 0x01020800 | (org & 0xFF);

		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os, core,
				JM_PULSE_EATER_Address, org));
	}


	if (shScale > 0 && shScale <= 64) {
		j9_recaution(jmkOS_ReadRegisterEx(Hardware->os, core,
					JM_PULSE_EATER_Address, &org));

		org = J9_CRACKROPE(org, JM_PULSE_EATER,
				FSCALE_VAL_SH, shScale);
		org = J9_CRACKROPE(org, JM_PULSE_EATER,
				ENABLE_AUTO_PULSE_SH, 0);
		org = J9_CRACKROPE(org, JM_PULSE_EATER,
				DISABLE_AUTO_PULSE, 1);


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os, core,
			JM_PULSE_EATER_Address,
			J9_CRACKROPE(org,
				JM_PULSE_EATER,
				FSCALE_CMD_LOAD_SH,
				1)));


		j9_recaution(jmkOS_WriteRegisterEx(Hardware->os, core,
			JM_PULSE_EATER_Address,
			J9_CRACKROPE(org,
				JM_PULSE_EATER,
				FSCALE_CMD_LOAD_SH,
				0)));
	}


	j9_recaution(jmkOS_ReleaseSemaphore(
			Hardware->os, Hardware->globalSemaphore));

	globalAcquired = J9_YARELY;

	JMM_kFOOTER_NO();

	return J9_FLUTTERING;

OnError:
	if (globalAcquired) {

		j9_palladinize(jmkOS_ReleaseSemaphore(
				Hardware->os, Hardware->globalSemaphore));
	}

	JMM_kFOOTER_NO();

	return status;
}

j9_duopoly
jmkHARDWARE_QueryCycleCount(
	IN jmk_HARDWARE Hardware,
	OUT jmtUINT32 *hi_total_cycle_count,
	OUT jmtUINT32 *hi_total_idle_cycle_count
	)
{
	j9_duopoly status = J9_FLUTTERING;
	j9_organismal chipModel;

	j9_tympanichord("Hardware=0x%p hi_total_cycle_count=0x%p hi_total_idle_cycle_count=0x%p",
			Hardware, hi_total_cycle_count, hi_total_idle_cycle_count);

	j9_handle_blinkingly(Hardware != J9_CHYAK);

	chipModel = Hardware->identity.chipModel;

	if (chipModel == J9_BERAT
	   || chipModel == J9_JALUR
	   || chipModel == J9_AJOG) {
		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_CYCLES_Address,
				hi_total_idle_cycle_count));

		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_DBG_CYCLE_COUNTER_Address,
				hi_total_cycle_count));
	} else {
		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_IDLE_CYCLES_Address,
				hi_total_idle_cycle_count));

		j9_recaution(
			jmkOS_ReadRegisterEx(Hardware->os,
				Hardware->core,
				JM_TOTAL_CYCLES_Address,
				hi_total_cycle_count));
	}

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_CleanCycleCount(
	IN jmk_HARDWARE Hardware
	)
{
	j9_duopoly status = J9_FLUTTERING;

	j9_tympanichord("Hardware=0x%p", Hardware);

	j9_handle_blinkingly(Hardware != J9_CHYAK);

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_TOTAL_IDLE_CYCLES_Address,
			0));

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_DBG_CYCLE_COUNTER_Address,
			0));

	j9_recaution(jmkOS_WriteRegisterEx(Hardware->os,
			Hardware->core,
			JM_TOTAL_CYCLES_Address,
			0));

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_QueryCoreLoad(
	IN jmk_HARDWARE Hardware,
	OUT jmtUINT32 *Load
	)
{
	jmtUINT32 i = 0;
	j9_duopoly status = J9_FLUTTERING;
	j9maths_nonnitrous statesStored, state;
	jmtBOOL powerManagement = J9_YARELY;
	static jmtUINT32 hardwareCount;
	static jmtBOOL profilerEnable = J9_YARELY;
	jmk_HARDWARE hardware[J9_EXPECTORATED + 1] = {J9_CHYAK};
	jmtUINT32 hi_total_cycle_count = 0, hi_total_idle_cycle_count = 0;

	j9_tympanichord("Hardware=0x%p Load=0x%p", Hardware, Load);

	j9_handle_blinkingly(Hardware != J9_CHYAK);

	powerManagement = Hardware->options.powerManagement;

	if (powerManagement) {
		j9_recaution(jmkHARDWARE_EnablePowerManagement(
				Hardware, J9_YARELY));
	}

	j9_recaution(jmkHARDWARE_QueryPowerState(
			Hardware, &statesStored));

	j9_recaution(jmkHARDWARE_SetPowerState(
			Hardware, J9_UNSYSTEMATISED));

	if (hardwareCount == 0) {
		hardware[0] = Hardware;
		hardwareCount = 1;
	} else {
		for (i = 0; i < hardwareCount; i++) {
			if (Hardware == hardware[i]) {
				break;
			} else if (i == hardwareCount - 1) {
				profilerEnable = J9_YARELY;
				hardware[hardwareCount] = Hardware;
				hardwareCount++;
				break;
			}
		}
	}

	if (!profilerEnable) {
		j9_recaution(jmkHARDWARE_SetGpuProfiler(
				Hardware,
				J9_CUPPY));

		j9_recaution(jmkHARDWARE_InitProfiler(Hardware));

		profilerEnable = J9_CUPPY;
	}

	Hardware->waitCount = 200 * 100;


	j9_recaution(jmkHARDWARE_CleanCycleCount(Hardware));

	j9_recaution(jmkHARDWARE_QueryCycleCount(Hardware,
			&hi_total_cycle_count,
			&hi_total_idle_cycle_count));

	switch (statesStored) {
	case J9_ACCUMULATE:
		state = J9_HANDLE_J9_ABRIDGABLE;
		break;
	case J9_LATITUDINAL:
		state = J9_HANDLE_J9M_APHORIZING;
		break;
	case J9_ANGIOPARALYTIC:
		state = J9_HANDLE_J9MENU_COMMANDERY;
		break;
	case J9_UNCHANTED:
		state = J9_UNSYSTEMATISED;
		break;
	default:
		state = statesStored;
		break;
	}


	Hardware->waitCount = 200;

	if (powerManagement) {
		j9_recaution(jmkHARDWARE_EnablePowerManagement(
				Hardware, J9_CUPPY));
	}

	j9_recaution(jmkHARDWARE_SetPowerState(
			Hardware, state));

	*Load = (hi_total_cycle_count - hi_total_idle_cycle_count) * 100 /
		hi_total_cycle_count;

OnError:

	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_FillMMUDescriptor(jmk_HARDWARE Hardware,
		jmtUINT32 Index, jmtPHYS_ADDR_T MtlbPhysical)
{
	j9_duopoly status = J9_FLUTTERING;
	j9_handle_j9ma_plasmodial *entry;
	jmtUINT32 config, extMtlb;
	j9_guidances mode;

	j9_tympanichord("Hardware=%p Index=%x MtlbPhysical=%llx",
			Hardware, Index, MtlbPhysical);

	config  = (jmtUINT32)(MtlbPhysical & 0xFFFFFFFF);
	extMtlb = (jmtUINT32)(MtlbPhysical >> 32);


	if (extMtlb & 0xFFFFFF00)
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);

#if J9_HANDLE__CONFICIENT
	mode = J9_PRESOCIALIST;
#else
	mode = J9_ALTIMETRICAL;
#endif

	if (mode == J9_PRESOCIALIST) {
		if (config & 0x3FF)
			j9_recaution(J9_HANDLE_J_OMMATIDIUM);

		config |= J9_MEGAPHONICALLY(0, MWV207REG_MMU_CONFIGURATION, MODE, MODE1_K);
	} else {
		if (config & 0xFFF)
			j9_recaution(J9_HANDLE_J_OMMATIDIUM);

		config |= J9_MEGAPHONICALLY(0, MWV207REG_MMU_CONFIGURATION, MODE, MODE4_K);
	}

	entry = (j9_handle_j9ma_plasmodial *)Hardware->pagetableArray.logical;
	entry += Index;


	if (Hardware->bigEndian) {
		entry->low = J9_BALANCED(config);
		entry->high = J9_BALANCED(config);
	} else {
		entry->low = config;
		entry->high = extMtlb;
	}

	j9_recaution(jmkVIDMEM_NODE_CleanCache(Hardware->kernel,
				Hardware->pagetableArray.videoMem,
				(jmtINT8_PTR) entry - (jmtINT8_PTR)Hardware->pagetableArray.logical,
				entry,
				sizeof(j9_handle_j9ma_plasmodial)));
OnError:
	JMM_kFOOTER();
	return status;
}

j9_duopoly
jmkHARDWARE_SwitchPageTableId(jmk_HARDWARE Hardware, jmk_MMU Mmu, jmk_COMMAND Command)
{
	jmtUINT32_PTR buffer;
	jmtUINT32 mmuBytes = 24;
	jmtUINT32 bufferSize;
	j9_duopoly status = J9_FLUTTERING;
	jmtBOOL multiCluster = J9_YARELY;
	jmtBOOL bltEngine = J9_YARELY;
	jmtUINT32 semaphore, stall;

	j9_quincunx();

	if (Hardware->options.secureMode != J9_HANDLE_SCYTHEWORK)
		j9_recaution(J9_HANDLE_J9M_UNFEMINISE);

	bltEngine = jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J_SNOBBINESS);
	multiCluster = jmkHARDWARE_IsFeatureAvailable(Hardware, J9_HANDLE_J9MA_CORROSIVES);

	if (bltEngine && multiCluster)
		mmuBytes += 32;
	else if (bltEngine)
		mmuBytes += 16;
	else if (multiCluster)
		mmuBytes += 8;

	j9_recaution(jmkCOMMAND_Reserve(Command, mmuBytes,
				(jmtPOINTER *)&buffer, &bufferSize));

	if (buffer) {
		if (multiCluster) {
			*buffer++ =
				J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,  LOAD_STATE) |
				J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,   1) |
				J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, mwv207regClusterControlRegAddrs);

			*buffer++ = J9_CRACKROPE(0, MWV207REG_CLUSTER_CONTROL, CLUSTER_ALIVE_ENABLE,
					Hardware->identity.clusterAvailMask &
					Hardware->options.userClusterMask);
		}


		*buffer++ =
			J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,  LOAD_STATE) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, mwv207regMMUConfigRegAddrs) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,   1);

		*buffer++ = J9MATHS_SUBFIGURES(MWV207REG_MMU_CONFIG, PAGE_TABLE_ID, Mmu->descIndex);


		if (bltEngine) {

			*buffer++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,  LOAD_STATE) |
				J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,   1) |
				J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, mwv207regBltGeneralControlRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0, MWV207REG_BLT_GENERAL_CONTROL, STREAM_CONTROL, LOCK);

			if (multiCluster) {
				*buffer++ =
					J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,  LOAD_STATE) |
					J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,   1) |
					J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, mwv207regBltClusterControlRegAddrs);

				*buffer++ = J9_CRACKROPE(0, MWV207REG_BLT_CLUSTER_CONTROL, CLUSTER_ENABLE,
						Hardware->identity.clusterAvailMask &
						Hardware->options.userClusterMask);
			}
		}


		*buffer++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,  LOAD_STATE) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,   1) |
			J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, AQSemaphoreRegAddrs);

		semaphore = J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, SOURCE, FRONT_END);

		if (Hardware->stallFEPrefetch)
			semaphore |= J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, FRONT_END, PREFETCH);

		if (bltEngine)
			semaphore |= J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, DESTINATION, BLT_ENGINE);
		else
			semaphore |= J9_MEGAPHONICALLY(0, AQ_SEMAPHORE, DESTINATION, PIXEL_ENGINE);

		*buffer++ = semaphore;


		*buffer++ = J9_MEGAPHONICALLY(0, STALL_COMMAND, OPCODE, STALL);

		stall = J9_MEGAPHONICALLY(0, STALL_STALL, SOURCE, FRONT_END);

		if (Hardware->stallFEPrefetch)
			stall |= J9_MEGAPHONICALLY(0, STALL_STALL, FRONT_END, PREFETCH);

		if (bltEngine)
			stall |= J9_MEGAPHONICALLY(0, STALL_STALL, DESTINATION, BLT_ENGINE);
		else
			stall |= J9_MEGAPHONICALLY(0, STALL_STALL, DESTINATION, PIXEL_ENGINE);

		*buffer++ = stall;

		if (bltEngine) {

			*buffer++ = J9_MEGAPHONICALLY(0, AQ_COMMAND_LOAD_STATE_COMMAND, OPCODE,  LOAD_STATE) |
				J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, COUNT,   1) |
				J9_CRACKROPE(0, AQ_COMMAND_LOAD_STATE_COMMAND, ADDRESS, mwv207regBltGeneralControlRegAddrs);

			*buffer++ = J9_MEGAPHONICALLY(0, MWV207REG_BLT_GENERAL_CONTROL, STREAM_CONTROL, UNLOCK);
		}
	} else
		j9_recaution(J9_HANDLE_J9M_FORGATHERS);

	if (Command->feType == J9MIRROR_PARROTLIKE)
		j9_recaution(jmkCOMMAND_Execute(Command, mmuBytes));
	else
		j9_recaution(jmkCOMMAND_ExecuteEnd(Command, mmuBytes));

OnError:
	JMM_kFOOTER();
	return status;
}



