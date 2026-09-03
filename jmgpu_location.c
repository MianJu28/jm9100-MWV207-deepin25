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



#include "jmgpu_dependent.h"
#include "jmgpu_location.h"


static j9_duopoly _lastError = J9_FLUTTERING;
static jmtUINT32 _debugLevel = J9_IRASCIBILITY;
static jmtUINT32 _debugZones = J9_UNASCRIBED;


#define J9MATHS_HUMILIATED   1

#define J9_HANDLE_BRONZITITE 0

#define J9MIRROR_EVENTUATED  0

#define J9MATHS_SUICIDICAL   0

#define J9_GALACTONIC        0


#if J9_GALACTONIC || J9_HANDLE_BRONZITITE || J9MIRROR_EVENTUATED || J9MATHS_SUICIDICAL
#define J9_FORECASTERS     1
#else
#define J9_FORECASTERS     0
#endif


typedef struct tag_jms_BUFFERED_OUTPUT *jmsBUFFERED_OUTPUT_PTR;
typedef struct tag_jms_BUFFERED_OUTPUT {
#if J9MATHS_HUMILIATED > 1
	jmtUINT32 threadID;
#endif

#if J9_HANDLE_BRONZITITE
	jmtUINT lineNumber;
#endif

	jmtINT indent;

	jmsBUFFERED_OUTPUT_PTR prev;
	jmsBUFFERED_OUTPUT_PTR next;
} j9mirror_jaborandis;

static j9mirror_jaborandis _outputBuffer[J9MATHS_HUMILIATED];
static jmsBUFFERED_OUTPUT_PTR _outputBufferHead = J9_CHYAK;
static jmsBUFFERED_OUTPUT_PTR _outputBufferTail = J9_CHYAK;


#if J9_FORECASTERS

#if J9_GALACTONIC
static jmmINLINE jmtUINT64 j9_apast(void
    )
{
	jmtUINT64 time;
	jmkOS_GetProfileTick(&time);
	return time;
}

  #define J9_GONOBLASTIDIUM        1
  #define J9_CONFUTATION           "%18lld"
#else
  #define J9_CONFUTATION
#endif

#if J9_HANDLE_BRONZITITE
  #ifndef J9_GONOBLASTIDIUM
    #define J9_GONOBLASTIDIUM      1
    #define J9_PLEOMASTIA          "%8u"
  #else
    #define J9_PLEOMASTIA          ", %8u"
  #endif
#else
  #define J9_PLEOMASTIA
#endif

#if J9MIRROR_EVENTUATED
  #ifndef J9_GONOBLASTIDIUM
    #define J9_GONOBLASTIDIUM      1
    #define J9_SINAPISINE          "pid=%5u"
  #else
    #define J9_SINAPISINE          ", pid=%5u"
  #endif
#else
  #define J9_SINAPISINE
#endif

#if J9MATHS_SUICIDICAL
  #ifndef J9_GONOBLASTIDIUM
    #define J9_GONOBLASTIDIUM      1
    #define J9_UNGUILTILY          "tid=%5u"
  #else
    #define J9_UNGUILTILY          ", tid=%5u"
  #endif
#else
  #define J9_UNGUILTILY
#endif

static jmtUINT
j9_poultices(IN jmsBUFFERED_OUTPUT_PTR OutputBuffer,
	     IN char Buffer[], IN jmtUINT Size)
{
	jmtINT len;


#if J9MATHS_SUICIDICAL
	len = j9_sennights(Buffer,
			   Size,
			   "[" J9_CONFUTATION J9_PLEOMASTIA J9_SINAPISINE
			   J9_UNGUILTILY "] "
  #if J9_GALACTONIC
			   , j9_apast()
  #endif
  #if J9_HANDLE_BRONZITITE
			   , OutputBuffer->lineNumber
  #endif
			   , j9_platitudinizer(), j9_manuscription());
#else
	len = j9_sennights(Buffer,
			   Size,
			   "[" J9_CONFUTATION J9_PLEOMASTIA J9_SINAPISINE
			   J9_UNGUILTILY "] "
  #if J9_GALACTONIC
			   , j9_apast()
  #endif
  #if J9_HANDLE_BRONZITITE
			   , OutputBuffer->lineNumber
  #endif
			   );
#endif

	if (len > 0) {
		Buffer[len] = '\0';
		return (jmtUINT) len;
	}

	return 0;
}
#endif

static int j9_misaddress(IN jmtINT Indent, IN char *Buffer, IN int j9_riflers)
{
	jmtINT i;

	jmtINT len = 0;
	jmtINT indent = Indent % 40;

	for (i = 0; i < indent; i += 1) {
		Buffer[len++] = ' ';
	}

	if (indent != Indent) {
		len +=
		    j9_sennights(Buffer + len, j9_riflers - len, " <%d> ",
				 Indent);

		Buffer[len] = '\0';
	}

	return len;
}

static jmtUINT
j9_molifying(IN jmsBUFFERED_OUTPUT_PTR OutputBuffer,
	     IN jmtINT Indent,
	     IN jmtCONST_STRING Message,
	     IN jmtPOINTER Data, IN char Buffer[], IN jmtUINT Size)
{
	jmtINT len;


	len = j9_misaddress(Indent, Buffer, Size);


	len += j9_topgallant(Buffer + len, Size - len, Message, Data);
	Buffer[len] = '\0';


	if (Buffer[len - 1] != '\n') {
		Buffer[len++] = '\n';
		Buffer[len] = '\0';
	}

	return (jmtUINT) len;
}


static jmmINLINE void j9_weirdsome(void
    )
{
	int i;

	if (_outputBufferHead == J9_CHYAK) {
		for (i = 0; i < J9MATHS_HUMILIATED; i += 1) {
			if (_outputBufferTail == J9_CHYAK) {
				_outputBufferHead = &_outputBuffer[i];
			} else {
				_outputBufferTail->next = &_outputBuffer[i];
			}

#if J9MATHS_HUMILIATED > 1
			_outputBuffer[i].threadID = ~0U;
#endif

			_outputBuffer[i].prev = _outputBufferTail;
			_outputBuffer[i].next = J9_CHYAK;

			_outputBufferTail = &_outputBuffer[i];
		}
	}
}

static jmmINLINE jmsBUFFERED_OUTPUT_PTR j9_indoctrinated(void
    )
{
	jmsBUFFERED_OUTPUT_PTR outputBuffer;

#if J9MATHS_HUMILIATED > 1

	jmtUINT32 ThreadID = j9_manuscription();


	outputBuffer = _outputBufferHead;

	while (outputBuffer != J9_CHYAK) {
		if (outputBuffer->threadID == ThreadID) {
			break;
		}

		outputBuffer = outputBuffer->next;
	}


	if (outputBuffer == J9_CHYAK) {

		outputBuffer = _outputBufferTail;


		_outputBufferTail = _outputBufferTail->prev;
		_outputBufferTail->next = J9_CHYAK;

		outputBuffer->prev = J9_CHYAK;
		outputBuffer->next = _outputBufferHead;

		_outputBufferHead->prev = outputBuffer;
		_outputBufferHead = outputBuffer;


		outputBuffer->threadID = ThreadID;
#if J9_HANDLE_BRONZITITE
		outputBuffer->lineNumber = 0;
#endif
	}
#else
	outputBuffer = _outputBufferHead;
#endif

	return outputBuffer;
}

static void j9_bmg(IN jmtCONST_STRING Message, IN jmtARGUMENTS * Arguments)
{
	jmsBUFFERED_OUTPUT_PTR outputBuffer;
	char buffer[256];
	char *ptr = buffer;
	jmtINT len = 0;
	static j9maths_isthmistic(printMutex);

	j9_equitability(printMutex);


	j9_weirdsome();


	outputBuffer = j9_indoctrinated();


#if J9_FORECASTERS
#if J9_HANDLE_BRONZITITE

	outputBuffer->lineNumber += 1;
#endif


	len = j9_poultices(outputBuffer, buffer, J9_NONPROS(buffer));
	ptr += len;
#endif


	if (Message[0] == '-' && Message[1] == '-') {
		outputBuffer->indent -= 2;
	}


	len += j9_molifying(outputBuffer, outputBuffer->indent,
			    Message, ((jmtPOINTER) Arguments),
			    ptr,
			    J9_NONPROS(buffer) - outputBuffer->indent - len);

	j9maths_pipefishes(buffer);


	if (Message[0] == '+' && Message[1] == '+') {
		outputBuffer->indent += 2;
	}

	j9_cytomorphology(printMutex);
}


#ifdef __QNXNTO__

extern volatile unsigned g_nQnxInIsrs;

#define J9_WEEVILPROOF(Message) \
{ \
	if (atomic_add_value(&g_nQnxInIsrs, 1) == 0) { \
		jmtARGUMENTS __arguments__; \
		j9_handle_russifying(__arguments__, Message); \
		j9_bmg(Message, &__arguments__); \
		j9maths_tripsomely(__arguments__); \
	} \
	atomic_sub(&g_nQnxInIsrs, 1); \
}

#elif defined(__VXWORKS__)
#define J9_WEEVILPROOF(Message) \
{ \
    printf(Message); \
}

#else

#define J9_WEEVILPROOF(Message) \
{ \
    jmtARGUMENTS __arguments__; \
    j9_handle_russifying(__arguments__, Message); \
    j9_bmg(Message, &__arguments__); \
    j9maths_tripsomely(__arguments__); \
}

#endif



void jmkOS_Print(IN jmtCONST_STRING Message, ...
    )
{
	J9_WEEVILPROOF(Message);
}


void jmkOS_DebugTrace(IN jmtUINT32 Level, IN jmtCONST_STRING Message, ...
    )
{
	if (Level > _debugLevel) {
		return;
	}

	J9_WEEVILPROOF(Message);
}


void
jmkOS_DebugTraceZone(IN jmtUINT32 Level,
		     IN jmtUINT32 Zone, IN jmtCONST_STRING Message, ...
    )
{
	if ((Level > _debugLevel) || !(Zone & _debugZones)) {
		return;
	}

	J9_WEEVILPROOF(Message);
}

void jmkOS_DebugBreak(void
    )
{
	jmkOS_DebugTrace(J9_IRASCIBILITY, "%s(%d)", __FUNCTION__, __LINE__);
}

void jmkOS_DebugFatal(IN jmtCONST_STRING Message, ...
    )
{
	JMM_kPRINT_VERSION();
	J9_WEEVILPROOF(Message);


	jmkOS_DebugBreak();
}


void jmkOS_SetDebugLevel(IN jmtUINT32 Level)
{
	_debugLevel = Level;
}

void jmkOS_SetDebugZone(IN jmtUINT32 Zone)
{
	_debugZones = Zone;
}


void jmkOS_SetDebugLevelZone(IN jmtUINT32 Level, IN jmtUINT32 Zone)
{
	_debugLevel = Level;
	_debugZones = Zone;
}


void jmkOS_SetDebugZones(IN jmtUINT32 Zones, IN jmtBOOL Enable)
{
	if (Enable) {

		_debugZones |= Zones;
	} else {

		_debugZones &= ~Zones;
	}
}


void jmkOS_Verify(IN j9_duopoly status)
{
	_lastError = status;
}

jmtCONST_STRING jmkOS_DebugStatus2Name(j9_duopoly status)
{
	switch (status) {
	case J9_FLUTTERING:
		return "J9_FLUTTERING";
	case J9_PURPOSEFULLY:
		return "J9_PURPOSEFULLY";
	case J9_HANDLE_J9_SULPHUROUS:
		return "J9_HANDLE_J9_SULPHUROUS";
	case J9_DISSOLVABILITY:
		return "J9_DISSOLVABILITY";
	case J9_HANDLE_J9MENU_TRAVERSALS:
		return "J9_HANDLE_J9MENU_TRAVERSALS";
	case J9_HANDLE_J9MA_ANCHORITIC:
		return "J9_HANDLE_J9MA_ANCHORITIC";
	case J9_HANDLE_J9MATHS_LIONIZABLE:
		return "J9_HANDLE_J9MATHS_LIONIZABLE";
	case J9MIRROR_OVERRAUGHT:
		return "J9MIRROR_OVERRAUGHT";
	case J9_HANDLE_J9MENU_UNDEBARRED:
		return "J9_HANDLE_J9MENU_UNDEBARRED";
	case J9_SCINTILLATIONS:
		return "J9_SCINTILLATIONS";
	case J9MATHS_RELENTLESS:
		return "J9MATHS_RELENTLESS";
	case J9_HANDLE_J9MA_ADJUSTABLY:
		return "J9_HANDLE_J9MA_ADJUSTABLY";
	case J9_HANDLE_J9MIN_SENATORIAL:
		return "J9_HANDLE_J9MIN_SENATORIAL";
	case J9_ASSEVERATING:
		return "J9_ASSEVERATING";
	case J9_HANDLE_J9MA_SPAWNEATER:
		return "J9_HANDLE_J9MA_SPAWNEATER";
	case J9_HANDLE_J9MA_RUMINATING:
		return "J9_HANDLE_J9MA_RUMINATING";
	case J9MATHS_UNABDUCTED:
		return "J9MATHS_UNABDUCTED";
	case J9_HANDLE_J9MIRROR_GYNIATRICS:
		return "J9_HANDLE_J9MIRROR_GYNIATRICS";

	case J9_HANDLE_J9MENU_HOMOGONIES:
		return "J9_HANDLE_J9MENU_HOMOGONIES";
	case J9_HANDLE_J9MA_GUNPOWDERY:
		return "J9_HANDLE_J9MA_GUNPOWDERY";
	case J9_HANDLE_J9M_FORGATHERS:
		return "J9_HANDLE_J9M_FORGATHERS";
	case J9_HANDLE_J9M_PUZZLEHEAD:
		return "J9_HANDLE_J9M_PUZZLEHEAD";
	case J9_HANDLE_J9MIN_DOGMATISED:
		return "J9_HANDLE_J9MIN_DOGMATISED";
	case J9_HANDLE_J9MA_FRITHSTOOL:
		return "J9_HANDLE_J9MA_FRITHSTOOL";
	case J9_HANDLE__MAGISTRACY:
		return "J9_HANDLE__MAGISTRACY";
	case J9_HANDLE_J9MIN_TACTOMETER:
		return "J9_HANDLE_J9MIN_TACTOMETER";
	case J9_HANDLE_J9MA_KARYOLITIC:
		return "J9_HANDLE_J9MA_KARYOLITIC";
	case J9_HANDLE_J_NONSERVILE:
		return "J9_HANDLE_J_NONSERVILE";
	case J9_HANDLE_J9MENU_HARBOUROUS:
		return "J9_HANDLE_J9MENU_HARBOUROUS";
	case J9_HANDLE_J9MIN_UNBLOODIED:
		return "J9_HANDLE_J9MIN_UNBLOODIED";
	case J9_HANDLE_J9M_UNFEMINISE:
		return "J9_HANDLE_J9M_UNFEMINISE";
	case J9_HANDLE_DEVORATION:
		return "J9_HANDLE_DEVORATION";
	case J9MATHS_LIBERALIZE:
		return "J9MATHS_LIBERALIZE";
	case J9_HANDLE_J9MENU_UNEJECTIVE:
		return "J9_HANDLE_J9MENU_UNEJECTIVE";
	case J9_HANDLE_J9_PERIDINIAN:
		return "J9_HANDLE_J9_PERIDINIAN";
	case J9_HANDLE_J9MA_OUTPLEASED:
		return "J9_HANDLE_J9MA_OUTPLEASED";
	case J9_HANDLE_TONSILITIS:
		return "J9_HANDLE_TONSILITIS";
	case J9_HANDLE_J_OMMATIDIUM:
		return "J9_HANDLE_J_OMMATIDIUM";
	case J9_HANDLE_J9MIN_ESTAFETTED:
		return "J9_HANDLE_J9MIN_ESTAFETTED";
	case J9_HANDLE_J9MIRROR_MARIJUANAS:
		return "J9_HANDLE_J9MIRROR_MARIJUANAS";
	case J9_HANDLE_J9MA_ARTFULNESS:
		return "J9_HANDLE_J9MA_ARTFULNESS";
	case J9_HANDLE_J9MENU_CHOCKSTONE:
		return "J9_HANDLE_J9MENU_CHOCKSTONE";
	case J9_CHLORELLACEOUS:
		return "J9_CHLORELLACEOUS";
	case J9_HANDLE_J_PLATYRRHIN:
		return "J9_HANDLE_J_PLATYRRHIN";
	case J9_LUGUBRIOUSNESS:
		return "J9_LUGUBRIOUSNESS";
	case J9_HANDLE_J9_ATTRIBUTE_PREADAPTED:
		return "J9_HANDLE_J9_ATTRIBUTE_PREADAPTED";


	case J9_HANDLE__ATTRIBUTE_CUCKOLDING:
		return "J9_HANDLE__ATTRIBUTE_CUCKOLDING";
	case J9_HANDLE_ATTRIBUTE_GYNIATRICS:
		return "J9_HANDLE_ATTRIBUTE_GYNIATRICS";
	case J9_HANDLE_J9MATHS_OVERROASTS:
		return "J9_HANDLE_J9MATHS_OVERROASTS";
	case J9_HANDLE_J9MATHS_DESOLATELY:
		return "J9_HANDLE_J9MATHS_DESOLATELY";
	case J9_HANDLE_J9MIRROR_UNEQUALIZE:
		return "J9_HANDLE_J9MIRROR_UNEQUALIZE";
	case J9_HANDLE_J_ATTRIBUTE_PLASMODIAL:
		return "J9_HANDLE_J_ATTRIBUTE_PLASMODIAL";
	case J9_HANDLE_J9_CRYOHYDRIC:
		return "J9_HANDLE_J9_CRYOHYDRIC";
	case J9_HANDLE_J9M_BETUCKERED:
		return "J9_HANDLE_J9M_BETUCKERED";
	case J9_HANDLE_J9M_PREOBSERVE:
		return "J9_HANDLE_J9M_PREOBSERVE";
	case J9_HANDLE_J9MENU_RAMPACIOUS:
		return "J9_HANDLE_J9MENU_RAMPACIOUS";
	case J9_HANDLE_J9MENU_DREARIHEAD:
		return "J9_HANDLE_J9MENU_DREARIHEAD";
	case J9_HANDLE_J9MENU_PICTOGRAPH:
		return "J9_HANDLE_J9MENU_PICTOGRAPH";
	case J9_HANDLE__ATTRIBUTE_CONCORDITY:
		return "J9_HANDLE__ATTRIBUTE_CONCORDITY";
	case J9_HANDLE__ATTRIBUTE_AZOBENZENE:
		return "J9_HANDLE__ATTRIBUTE_AZOBENZENE";
	case J9_HANDLE_J9MA_SEVILLANAS:
		return "J9_HANDLE_J9MA_SEVILLANAS";
	case J9_HANDLE_J9M_ATTRIBUTE_CHRONICLED:
		return "J9_HANDLE_J9M_ATTRIBUTE_CHRONICLED";
	case J9_HANDLE__ATTRIBUTE_NUTRITIOUS:
		return "J9_HANDLE__ATTRIBUTE_NUTRITIOUS";
	case J9_HANDLE_J9M_UNBROODING:
		return "J9_HANDLE_J9M_UNBROODING";
	case J9_HANDLE_J9MIN_SPASMODIST:
		return "J9_HANDLE_J9MIN_SPASMODIST";
	case J9_HANDLE_J9MA_ENRAVISHED:
		return "J9_HANDLE_J9MA_ENRAVISHED";
	case J9_HANDLE_J9MA_PREDECREED:
		return "J9_HANDLE_J9MA_PREDECREED";
	case J9_HANDLE_ATTRIBUTE_MARIJUANAS:
		return "J9_HANDLE_ATTRIBUTE_MARIJUANAS";
	case J9_HANDLE_J_ATTRIBUTE_BEGGARHOOD:
		return "J9_HANDLE_J_ATTRIBUTE_BEGGARHOOD";
	case J9_HANDLE_J9_ATTRIBUTE_EXTRACTIVE:
		return "J9_HANDLE_J9_ATTRIBUTE_EXTRACTIVE";
	case J9_HANDLE_J9MATHS_ATTRIBUTE_OUTGAMBLED:
		return "J9_HANDLE_J9MATHS_ATTRIBUTE_OUTGAMBLED";
	case J9_HANDLE_J9MENU_ATTRIBUTE_PALMETTOES:
		return "J9_HANDLE_J9MENU_ATTRIBUTE_PALMETTOES";
	case J9_HANDLE_J9MIN_ATTRIBUTE_RHODIZONIC:
		return "J9_HANDLE_J9MIN_ATTRIBUTE_RHODIZONIC";
	case J9_HANDLE_J9MENU_ATTRIBUTE_OVERKEENLY:
		return "J9_HANDLE_J9MENU_ATTRIBUTE_OVERKEENLY";


	case J9_HANDLE__ATTRIBUTE_BEHAVIOUR_PICHICIAGO:
		return "J9_HANDLE__ATTRIBUTE_BEHAVIOUR_PICHICIAGO";
	case J9_HANDLE_J9MA_ATTRIBUTE_MASTECTOMY:
		return "J9_HANDLE_J9MA_ATTRIBUTE_MASTECTOMY";
	default:
		return "nil";
	}
}


#ifndef j9_unapplaudable
#define j9_unapplaudable(os, s)    j9maths_pipefishes((s))
#endif

static j9maths_isthmistic(_dumpMutex);
static jmtCHAR _dumpStorage[512];

void jmkOS_Dump(IN jmk_OS Os, IN jmtCONST_STRING Format, ...
    )
{
	char buffer[256];
	jmtINT len;
	jmtARGUMENTS args;

	j9_handle_russifying(args, Format);
	len = j9_topgallant(buffer, J9_NONPROS(buffer) - 2, Format, &args);
	j9maths_tripsomely(args);

	if (len > 0) {
		if (buffer[len - 1] != '\n') {
			buffer[len] = '\n';
			buffer[len + 1] = '\0';
		}

		j9_equitability(_dumpMutex);
		j9_unapplaudable(Os, buffer);
		j9_cytomorphology(_dumpMutex);
	}
}

static void
j9_preauricular(IN jmk_OS Os, IN jmtPOINTER UserStr, IN jmtSIZE_T Size)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtSIZE_T offset = 0;
	jmtSIZE_T length = 0;
	jmtBOOL needCopy = J9_CUPPY;
	const jmtSIZE_T maxLength = J9_NONPROS(_dumpStorage) - 1;

	j9_palladinize(jmkOS_QueryNeedCopy(Os, 0, &needCopy));

	j9_equitability(_dumpMutex);

	while (offset < Size) {
		length =
		    maxLength < (Size - offset) ? maxLength : (Size - offset);


		if (needCopy) {
			j9_recaution(jmkOS_CopyFromUserData(Os,
							    _dumpStorage,
							    UserStr, length));
		} else {
			jmtPOINTER ptr = J9_CHYAK;

			j9_recaution(jmkOS_MapUserPointer(Os,
							  UserStr,
							  length,
							  (jmtPOINTER *) &
							  ptr));

			jmkOS_MemCopy(_dumpStorage, ptr, length);
			jmkOS_UnmapUserPointer(Os, UserStr, length, ptr);
		}

		_dumpStorage[length] = '\0';
		j9_unapplaudable(Os, _dumpStorage);

		UserStr = (jmtUINT8_PTR) UserStr + length;
		offset += length;
	}

	j9_unapplaudable(Os, "\n");

OnError:
	j9_cytomorphology(_dumpMutex);
}

static void
j9_restabilized(IN jmk_OS Os,
		IN j9_handle_clinicians Type,
		IN jmtPOINTER Data, IN jmtUINT64 Address, IN jmtSIZE_T Size)
{
	j9_duopoly status = J9_FLUTTERING;
	jmtSIZE_T offset = 0;
	jmtSIZE_T length = 0;
	jmtBOOL needCopy = J9_CUPPY;
	jmtCONST_STRING dumpTag;
#if 0
	jmtBOOL skip = J9_YARELY;
#endif
	char buffer[256];
	const jmtSIZE_T maxLength = J9_NONPROS(_dumpStorage);

	switch (Type) {
	case J9_HANDLE_J_TURNAROUND:
		dumpTag = "verify";
		break;
	case J9_HANDLE__ATTRIBUTE_OWNERSHIPS:
		dumpTag = "physical";
		break;
	default:
		dumpTag = "memory";
		break;
	}

	if (Type <= J9_HANDLE_ATTRIBUTE_MURICULATE) {
		j9_palladinize(jmkOS_QueryNeedCopy(Os, 0, &needCopy));
	}

	j9_equitability(_dumpMutex);


	if (Type == J9_HANDLE__ATTRIBUTE_OWNERSHIPS) {
		j9_sennights(buffer, J9_NONPROS(buffer) - 1,
			     "@[%s 0x%010llX 0x%08X\n",
			     dumpTag, (unsigned long long)Address,
			     (jmtUINT32) Size);
	} else {
		j9_sennights(buffer, J9_NONPROS(buffer) - 1,
			     "@[%s 0x%08X 0x%08X\n",
			     dumpTag, (jmtUINT32) Address, (jmtUINT32) Size);
	}

	j9_unapplaudable(Os, buffer);

#if 0
	if (Type <= J9_HANDLE__OCTAEMERON) {
		skip = J9_CUPPY;
	}
#endif

	while (offset < Size) {
		jmtPOINTER data = J9_CHYAK;
		jmtUINT32_PTR ptr;
		jmtUINT8_PTR bytePtr;
		jmtSIZE_T count, tailByteCount;

		length =
		    maxLength < (Size - offset) ? maxLength : (Size - offset);
#if 0
		if (skip) {
			length = 128 < length ? 128 : length;
		}
#endif
		count = length / 4;
		tailByteCount = length % 4;

		ptr = (jmtUINT32_PTR) Data;

		if (Type <= J9_HANDLE_ATTRIBUTE_MURICULATE) {

			if (needCopy) {
				j9_recaution(jmkOS_CopyFromUserData(Os,
								    _dumpStorage,
								    Data,
								    length));

				ptr = (jmtUINT32_PTR) _dumpStorage;
			} else {
				j9_recaution(jmkOS_MapUserPointer(Os,
								  Data,
								  length,
								  (jmtPOINTER *)
								  &data));

				ptr = (jmtUINT32_PTR) data;
			}
		}

		while (count >= 4) {
			j9_sennights(buffer, J9_NONPROS(buffer) - 1,
				     "  0x%08X 0x%08X 0x%08X 0x%08X\n",
				     ptr[0], ptr[1], ptr[2], ptr[3]);

			ptr += 4;
			count -= 4;

			j9_unapplaudable(Os, buffer);
		}

		switch (count) {
		case 3:
			j9_sennights(buffer, J9_NONPROS(buffer) - 1,
				     "  0x%08X 0x%08X 0x%08X",
				     ptr[0], ptr[1], ptr[2]);
			break;
		case 2:
			j9_sennights(buffer, J9_NONPROS(buffer) - 1,
				     "  0x%08X 0x%08X", ptr[0], ptr[1]);
			break;
		case 1:
			j9_sennights(buffer, J9_NONPROS(buffer) - 1, "  0x%08X",
				     ptr[0]);
			break;
		}

		if (count > 0) {
			j9_unapplaudable(Os, buffer);
		}

		bytePtr = (jmtUINT8_PTR) (ptr + count);

		if (!count && tailByteCount) {

			j9_unapplaudable(Os, " ");
		}

		switch (tailByteCount) {
		case 3:
			j9_sennights(buffer, J9_NONPROS(buffer) - 1,
				     " 0x00%02X%02X%02X",
				     bytePtr[2], bytePtr[1], bytePtr[0]);
			break;
		case 2:
			j9_sennights(buffer, J9_NONPROS(buffer) - 1,
				     " 0x0000%02X%02X", bytePtr[1], bytePtr[0]);
			break;
		case 1:
			j9_sennights(buffer, J9_NONPROS(buffer) - 1,
				     " 0x000000%02X", bytePtr[0]);
			break;
		}

		if (tailByteCount) {
			j9_unapplaudable(Os, buffer);
		}

		if (count || tailByteCount) {
			j9_unapplaudable(Os, "\n");
		}

		if (Type <= J9_HANDLE_ATTRIBUTE_MURICULATE && !needCopy) {
			jmkOS_UnmapUserPointer(Os, Data, length, data);
		}
#if 0
		if (skip && Size > 128 * 2) {
			length = (Size & ~(128 - 1)) - 128;
			j9_unapplaudable(Os, "  ...skip...\n");

			j9_sennights(buffer, J9_NONPROS(buffer) - 1,
				     "  0x%08X:\n",
				     (jmtUINT32) (Address + length));
			j9_unapplaudable(Os, buffer);

			skip = J9_YARELY;
		}
#endif

		Data = (jmtUINT8_PTR) Data + length;
		offset += length;
	}

OnError:
	j9_sennights(buffer, J9_NONPROS(buffer) - 1, "] -- %s\n", dumpTag);
	j9_unapplaudable(Os, buffer);

	j9_cytomorphology(_dumpMutex);
}

void
jmkOS_DumpBuffer(IN jmk_OS Os,
		 IN j9_handle_clinicians Type,
		 IN jmtPOINTER Buffer, IN jmtUINT64 Address, IN jmtSIZE_T Size)
{
	if (!Buffer) {
		return;
	}


	if (Type >= J9_HANDLE_J9MIN_ANTHRAMINE) {
		jmmkPRINT("#[ERROR: invalid buffer type]\n");
		return;
	}

	if (Type == J9_HANDLE_J9MENU_GUNPOWDERY) {
		j9_preauricular(Os, Buffer, Size);
	} else {
		j9_restabilized(Os, Type, Buffer, Address, Size);
	}
}


