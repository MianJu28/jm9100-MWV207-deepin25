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



#ifndef __8dacd4bc_H_
#define __8dacd4bc_H_
#define J9MIRROR_PREADAPTED                     0
#define J9_HANDLE_TIMEWORKER                    1
#define J9_HANDLE_J9M_NORTHLIGHT		2
#define J9MATHS_HYDRIATRIC                      3
#define J9_HANDLE__PLASMODIAL					4
#define J9MIRROR_BANDCUTTER                     5
#define J9_HANDLE_SLUGGISHLY                    6
#define J9_HANDLE_J9M_EXTRACTIVE			7
#define J9MATHS_TETRAMETER                      8
#define J9_HANDLE__PRESTORING					9
#define J9_HANDLE_J_CHRONICLED		10
#define J9_PREINOCULATION                       11
#define J9_SUPPORTABILITY                       12
#define J9_PSEUDOAPOPLEXY                       12
	typedef enum pol_param {
	POSITIVE = 0,
	NEGATIVE = 1,
} e_pol;

typedef struct _outputmode_param {
	s32 htotal;
	s32 hactive;
	s32 hfrontporch;
	s32 hsync;
	s32 hrightborder;
	s32 vtotal;
	s32 vactive;
	s32 vfrontporch;
	s32 vsync;
	s32 vrightborder;
	s32 framerate;
	s32 vpol;
	s32 hpol;
} outputmode_param;

void mwv207_output_set_mode(jmk_GALDEVICE gal_dev, u32 screen_offset);

void j9_handle_j9_downloaded(jmk_GALDEVICE gal_dev, u32 screen_offset,
			     s32 screenid, s32 width, s32 height);


#define J9_EARED(H_TOTAL, H_ACTIVE, H_FRONT_PORCH, H_SYNC, H_RIGHT_BORDER, V_TOTAL, V_ACTIVE, V_FRONT_PORCH, V_SYNC, V_BOTTOM_BORDER, FRAMERATE, HPOL, VPOL) \
	{H_TOTAL, H_ACTIVE, H_FRONT_PORCH, H_SYNC, H_RIGHT_BORDER, V_TOTAL, V_ACTIVE, V_FRONT_PORCH, V_SYNC, V_BOTTOM_BORDER, FRAMERATE, HPOL, VPOL}

#define J9_HANDLE_J9M_ADHESIVELY 3

#define J9_HANDLE_J9M_OUTSAVORED	0x990000
#define J9MIRROR_RHABDOLOGY			0x9B0000

#define J9_IMPOSABLENESS			0x200

#define J9_SACCHARIMETER			0x300

#define J9_VOLITIONALIST			0x400

#define J9_PARLIAMENTEER			0x500

#define J9_AMBILATERALITY(index)	(J9_HANDLE_J9M_OUTSAVORED+((((index&0x2)<<2)|(index&0x1))<<8))
#define J9_ARTHROPOMATOUS(index)	(J9_HANDLE_J9M_OUTSAVORED+((((index&0x2)<<2)|(index&0x1))<<8))
#define J9_NEUROPARALYTIC(index)	(J9_HANDLE_J9M_OUTSAVORED+(((0x000E*(index>>1))|(index&0x1))<<8))

#define J9_WAREHOUSEMAN			0x000
#define J9_GODDAMNEDEST			0x004
#define J9MATHS_INTERESTER		0x008

#define J9_HERPETOGRAPHY		0x00C
#define J9_BIREFRINGENCE		0x010
#define J9_MATSTER				0x014
#define J9_HANDLE__UNCONTRITE	0x018
#define J9_PENITENT				0x01C
#define J9_PRECISIANISTIC		0x020
#define J9_MCCONNELLSBURG		0x024
#define J9_REHANDICAP			0x028
#define J9_HANDLE_PARAPSIDAL	0x02C
#define J9_UNTRANSFERABLE		0x030
#define J9MIRROR_BRAZENNESS		0x034
#define J9_GASTALDITE			0x038
#define J9_SEASONABLENESS		0x03C
#define J9MATHS_RIFLEPROOF		0x040
#define J9_HANDLE_J9_UNICYCLIST		0x044

#define J9_HANDLE_J9_TONGUELESS		0x048

#define J9MATHS_INIMITABLY			0x04C

#define J9_HANDLE_J9_EVENTUATED		0x050

#define J9_HANDLE_ATTRIBUTE_INGEMINATE		0x054

#define J9_HANDLE__SORDIDNESS				0x058

#define J9MATHS_40000					0x05C

#define J9MATHS_MASTECTOMY					0x060

#define J9_HANDLE_J9MA_SHOWERIEST			0x064

#define J9_LONGITUDINALLY					0x068

#define J9_HANDLE_APHORIZING				0x06C

#define J9_HANDLE_J9M_RIFLEPROOF			0x070

#define J9_HANDLE__GROUNDWAVE				0x074

#define J9_MENTALIZATION					0x078

#define J9_HANDLE_40000				0x07C

#define J9_POLYARTHRITIC					0x080

#define J9_HANDLE_J9_40000				0x084

#define J9_HANDLE_J9M_CHORIOMATA			0x088

#define J9_HANDLE_J9_OUTGAMBLED				0x08C

#define J9_HANDLE__40000				0x090

#define J9_HANDLE_OVERKEENLY				0x094

#define J9_HANDLE__PLOTTINGLY				0x098

#define J9_HANDLE__RHODIZONIC				0x09C

#define J9_HANDLE_J_CELIBATIST				0x0A0

#define J9_HANDLE_J_GROUNDWARD				0x0A4

#define J9_DEFLECTOMETER			0x0A8

#define J9_RETROACTIVELY			0x0AC

#define J9_IMPERVIOUS			0x0B0

#define J9_INTUITIVENESS			0x0B4

#define J9_DETOXIFICATION			0x0B8

#define J9MIRROR_40000			0x0BC

#define J9MATHS_COENOTYPIC			0x0C0

#define J9_QUARTERBACKED			0x0C4

#define J9_UNCONTORTIONED			0x0C8

#define J9MIRROR_UNABLENESS			0x0CC

#define J9_PALMILOBATE			0x0D0

#define J9MIRROR_CLEANLIEST			0x0E0

#define J9MIRROR_PLOTTINGLY			0x0E4

#define J9_HANDLE_J9M_PALMETTOES			0x67C

#define J9_MISCONCLUSION		0x200

#define J9_HANDLE_DELIQUESCE	0x204

#define J9_UNAFFIRMATION		0x208

#define J9_HANDLE_J9MENU_OXAMETHANE		0x20C

#define J9_HANDLE_J9MENU_REMODIFIED		0x210

#define J9_HANDLE_J9MIN_40000		0x214

#define J9_HANDLE_J9_COENOTYPIC			0x218

#define J9_HANDLE_J9_UNABLENESS			0x21C

#define J9_COUNTERVAILS					0x220

#define J9_HANDLE_J9_UNHONESTLY			0x224

#define J9MATHS_RHABDOLOGY				0x228

#define J9_VASSALLESS					0x22C

#define J9MIRROR_BESMUTTING				0x230


#define J9_HANDLE_J_COFFEETIME			0x234

#define J9_HANDLE_J_QUINOPYRIN			0x238

#define J9_HANDLE_J9MA_QUINTUPLET		0x23C

#define J9_HANDLE_J9MA_COFFEETIME		0x240

#define J9_HANDLE_J9MA_QUINOPYRIN		0x244

#define J9_HANDLE__ILLUCIDATE			0x248

#define J9MIRROR_CUREMASTER				0x24C

#define J9_HANDLE__RHABDOLOGY			0x250

#define J9MIRROR_OUTSAVORED				0x254

#define J9_HANDLE_J9MATHS_CROSSBENCH	0x258

#define J9_CEPHALOTRACTOR				0x25C

#define J9MATHS_EXECUTONIS				0x260

#define J9MATHS_DETACHEDLY				0x264

#define J9MIRROR_QUINOPYRIN				0x268

#define J9_INSOLUBLENESS				0x26C

#define J9_HANDLE_J9_TACTOMETER			0x270

#define J9_SUPERSANGUINE				0x274

#define J9_HANDLE_J9_INDURATION		0x278

#define J9_PREEXPOSITION				0x27C

#define J9_HANDLE_J9_QUINOPYRIN		0x280

#define J9_HANDLE_J9M_UNABLENESS		0x284

#define J9_HANDLE_J9MENU_UNABLENESS		0x288

#define J9_HANDLE_J9MENU_LITTERMATE		0x28C

#define J9_HANDLE__MERCURIATE			0x290
#define j9_malalignment    0x2A0

#define j9_handle__apozemical   0x2A4

#define j9_handle_j9m_eventuated   0x2A8

#define j9_handle_j_redoubting   0x2AC

#define j9_handle_j9m_nonnitrous   0x2B0

#define j9maths_cordwainer   0x2B4

#define j9_handle_j_emmenology   0x2B8

#define j9_handle_j_damfoolish   0x2BC

#define j9_handle_j9min_undertribe   0x2C0

#define j9maths_prepiously   0x2C4

#define J9_OPHTHALMOTROPE				0x400

#define J9_HANDLE__INDIGENOUS			0x404

#define J9_INEVASIBLENESS				0x408

#define J9_HANDLE_J9MATHS_OVEREXPAND	0x40C

#define J9_HANDLE_J9MATHS_LEPROLOGIC	0x410

#define J9_HANDLE_J9MENU_40000		0x414

#define J9_HANDLE_J9M_HOUSESMITH		0x418

#define J9_HANDLE_J9M_COENOTYPIC		0x41C

#define J9_LUXURIATES					0x420

#define J9_KATAPLEXY					0x424

#define J9_ASSUMPSIT					0x428

#define J9_BUTTER						0x42C

#define J9_UNEXPLOSIVELY				0x430

#define J9_ACCOMPLICESHIP				0x434

#define J9_VERSIFICATOR					0x438

#define J9MIRROR_PREPERFECT				0x43C

#define J9_HANDLE_J9_CELIOSCOPY			0x440

#define J9_HANDLE_POSTLUDIUM			0x444

#define J9_HANDLE_J_CELIOSCOPY			0x448

#define J9_HANDLE_BESMUTTING			0x44C

#define J9_HANDLE_J9_OVERKEENLY			0x450

#define J9_SCOREKEEPING					0x454

#define J9_HANDLE_J_ATTRIBUTE_PHLEBOLOGY	0x458

#define J9_HANDLE_J_ATTRIBUTE_CALCIFUGAL	0x45C



#define J9_URUGUAYANS					0x460

#define J9_UNRECOUNTABLE				0x464

#define J9_UNTAKEN						0x468

#define J9_ALOCHIA						0x918

#define J9_UNLUMINOUSNESS				0x46C

#define J9_UNREBELLIOUSLY				0x470

#define J9_UNRESIDUAL					0x474

#define J9_HANDLE_INKINESSES			0x478

#define J9_HANDLE_J9MATHS_INUREMENTS	0x47C

#define J9_HANDLE_J9MA_CHORIOMATA		0x480

#define J9_HANDLE_J9MENU_OUTGAMBLED		0x484

#define J9_HANDLE_J9MA_PALMETTOES		0x488

#define J9_HANDLE_J9MATHS_REMODIFIED	0x48C

#define J9_HANDLE_J9MATHS_THEOGONIST	0x490

#define J9_HANDLE_J9MA_PREPERFECT		0x494

#define J9_HANDLE_J9MENU_TONGUELESS		0x498

#define J9_HANDLE_J9MA_OVERKEENLY		0x49C

#define J9_HANDLE_J9MATHS_EXTRANEOUS	0x4A0

#define J9_HANDLE_J9M_EPIZOOLOGY		0x4A4

#define J9_ANTEAMBULATE					0x4A8

#define J9_HANDLE_TURNAROUND			0x4AC

#define J9_SEMITEXTURALLY				0x4B0

#define J9_HANDLE_J_PREPROMISE			0x4B4

#define J9_HANDLE_J9MATHS_MORBIDNESS	0x4C8

#define J9_HANDLE_J9MA_BRAZENNESS		0x4CC

#define J9_HANDLE_J9MENU_UNICYCLIST		0x4D0

#define J9_HANDLE_J9MA_CELIOSCOPY		0x4D4

#define J9_HANDLE_J9MATHS_TARTRONATE	0x4D8

#define J9_HANDLE_J9MATHS_SEVENPENCE	0x4DC

#define J9_HANDLE_J9MA_INSTILLING		0x4E0

#define J9_HANDLE_J9MENU_UNHONESTLY		0x4E4

#define J9_HANDLE_J9MA_PRECONCEAL		0x4E8

#define J9_HANDLE_J9MATHS_MISQUALITY	0x4EC

#define J9_HANDLE_J9M_INDURATION		0x4F0

#define J9_HANDLE_J9_OVERFLOWED			0x4F4

#define j9_stockholdings			0x4F8
#define J9_SEMIPEDANTIC							0x600

#define J9_FLICKERING							0x604

#define J9_HANDLE__CORROSIVES					0x608

#define J9_HANDLE__POSTMEATAL					0x60C

#define J9_HANDLE_J_THEOGONIST					0x610

#define J9MATHS_PRECONCEAL						0x614

#define J9MATHS_CHORIOMATA						0x618

#define J9_HANDLE_J9MENU_TARTRONATE				0x61C

#define J9_HANDLE_J9MENU_EXTRANEOUS				0x620

#define J9_HANDLE__BRAZENNESS					0x624

#define J9MATHS_PREPERFECT						0x628

#define J9MATHS_BRAZENNESS						0x62C

#define J9_HANDLE_J9MENU_INUREMENTS				0x630

#define J9_HANDLE_J9MENU_MISQUALITY				0x634

#define J9_HANDLE__INSTILLING					0x638

#define J9_UNGULLIBILITY						0x63C

#define J9_MONOSEXUALITY						0x640

#define J9_CYCLOOLEFIN						0x680

#define J9_ACKMEN						0x7F0

#define J9_MURRHAS						0x7F4

#define J9_FOOTCLOTHS						0X7F8

#define J9_SUPERINGENUITY				0x800

#define J9_SOCIORELIGIOUS				0x804

#define J9_ALBUMINIZING					0x808

#define J9MATHS_BURSECTOMY				0x848

#define J9MATHS_AUTOGENIES				0x888

#define J9_HANDLE__TANGERINES(index)	(index<<6)

#define J9_AFTERTHOUGHTS				0x928

#define J9MIRROR_SILVERIEST				0x92C

#endif


