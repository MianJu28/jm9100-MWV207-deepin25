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
#include "jmgpu_protect.h"
#include "jmgpu_marshal.h"



#define J9_NONGUARANTEE  6

typedef struct tag_jms_PARSER_HANDLER *jmkPARSER_HANDLER;

typedef void (*HandlerFunction)(IN jmkPARSER_HANDLER Handler,
				IN jmtUINT32 Addr, IN jmtUINT32 Data);

typedef struct tag_jms_PARSER_HANDLER {
	jmtUINT32 type;
	jmtUINT32 cmd;
	jmtPOINTER private;
	HandlerFunction function;
} j9maths_outpursued;

typedef struct tag_jms_PARSER *jmkPARSER;
typedef struct tag_jms_PARSER {
	jmtUINT8_PTR currentCmdBufferAddr;


	jmtUINT32 lo;
	jmtUINT32 hi;

	jmtUINT8 cmdOpcode;
	jmtUINT16 cmdAddr;
	jmtUINT32 cmdSize;
	jmtUINT32 cmdRectCount;
	jmtUINT8 skip;
	jmtUINT32 skipCount;

	jmtBOOL allow;
	jmtBOOL stop;


	jmkPARSER_HANDLER commandHandler;
} j9_scapose;

typedef struct tag_jms_MIRROR {
	jmtUINT32_PTR logical[J9_NONGUARANTEE];
	jmtUINT32 bytes;
	jmsSTATE_MAP_PTR map;
	jmtSIZE_T maxState;
} j9_crinose;

typedef struct tag_jms_DELTA {
	jmtUINT64 commitStamp;
	jmtUINT32_PTR command;
	jmtUINT32 commandBytes;
	jmtUINT32_PTR context;
	jmtUINT32 contextBytes;
} j9_nickar;

typedef struct tag_jms_RECORDER {
	jmk_OS os;
	j9_crinose mirror;
	j9_nickar deltas[J9_NONGUARANTEE];


	jmtUINT index;


	jmtUINT num;


	j9maths_outpursued recorderHandler;
	jmkPARSER parser;
} j9_positives;



static void j9_theatricality(IN OUT jmkPARSER Parser)
{
	jmtUINT i;
	jmtUINT32_PTR data = (jmtUINT32_PTR) Parser->currentCmdBufferAddr;
	jmtUINT32 cmdAddr = Parser->cmdAddr;

	if (Parser->commandHandler == J9_CHYAK
	    || Parser->commandHandler->cmd !=
	    AQ_COMMAND_OPCODE_OPCODE_LOAD_STATE) {

		return;
	}

	for (i = 0; i < Parser->cmdSize; i++) {
		Parser->commandHandler->function(Parser->commandHandler,
						 cmdAddr, *data);


		cmdAddr++;
		data++;
	}
}

static void j9_epibatus(IN OUT jmkPARSER Parser)
{
	jmtUINT32 *buffer = (jmtUINT32 *) Parser->currentCmdBufferAddr;

	jmtUINT16 cmdRectCount;
	jmtUINT16 cmdDataCount;

	Parser->hi = buffer[0];
	Parser->lo = buffer[1];

	Parser->cmdOpcode = J9_GLUTINANT(Parser->hi, AQ_COMMAND_OPCODE, OPCODE);
	Parser->cmdRectCount = 1;

	switch (Parser->cmdOpcode) {
	case AQ_COMMAND_OPCODE_OPCODE_LOAD_STATE:

		Parser->cmdSize =
		    J9_GLUTINANT(Parser->hi, AQ_COMMAND_LOAD_STATE_COMMAND,
				 COUNT);
		if (Parser->cmdSize == 0) {

			Parser->cmdSize = 1024;
		}
		Parser->skip = (Parser->cmdSize & 0x1) ? 0 : 1;


		Parser->cmdAddr =
		    J9_GLUTINANT(Parser->hi, AQ_COMMAND_LOAD_STATE_COMMAND,
				 ADDRESS);

		Parser->currentCmdBufferAddr = Parser->currentCmdBufferAddr + 4;
		Parser->skipCount = Parser->cmdSize + Parser->skip;
		break;

	case AQ_COMMAND_OPCODE_OPCODE_DX8_DRAW_PRIMITIVE:
		Parser->cmdSize = AQ_COMMAND_DX8_DRAW_PRIMITIVE_Count;
		Parser->skipCount = J9_PRAWNY(Parser->cmdSize, 2);
		break;

	case AQ_COMMAND_OPCODE_OPCODE_DX8_DRAW_INDEX_PRIMITIVE:
		Parser->cmdSize = AQ_COMMAND_DX8_DRAW_INDEX_PRIMITIVE_Count;
		Parser->skipCount = J9_PRAWNY(Parser->cmdSize, 2);
		break;

	case JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_DRAW_INSTANCED:
		Parser->cmdSize = JMCMD_DRAW_INSTANCED_Count;
		Parser->skipCount = J9_PRAWNY(Parser->cmdSize, 2);
		break;

	case AQ_COMMAND_OPCODE_OPCODE_STALL:
		Parser->cmdSize = STALL_Count;
		Parser->cmdAddr = StallCmdAddrs;
		Parser->skipCount = J9_PRAWNY(Parser->cmdSize, 2);
		break;

	case AQ_COMMAND_OPCODE_OPCODE_START_DE:
		Parser->cmdSize = AQ_COMMAND_START_DE_Count;
		Parser->cmdAddr = AQCommandStartDECmdAddrs;

		cmdRectCount =
		    J9_GLUTINANT(Parser->hi, AQ_COMMAND_START_DE_COMMAND,
				 COUNT);
		cmdDataCount =
		    J9_GLUTINANT(Parser->hi, AQ_COMMAND_START_DE_COMMAND,
				 DATA_COUNT);

		Parser->skipCount = J9_PRAWNY(Parser->cmdSize, 2)
		    + cmdRectCount * 2 + J9_PRAWNY(cmdDataCount, 2);

		Parser->cmdRectCount = cmdRectCount;
		break;

	case AQ_COMMAND_OPCODE_OPCODE_NOP:
		Parser->currentCmdBufferAddr = Parser->currentCmdBufferAddr + 8;
		Parser->skipCount = 0;
		break;

	case AQ_COMMAND_OPCODE_OPCODE_END:
		Parser->currentCmdBufferAddr = Parser->currentCmdBufferAddr + 8;
		Parser->skipCount = 0;
		break;

	case AQ_COMMAND_OPCODE_OPCODE_WAIT:
		Parser->currentCmdBufferAddr = Parser->currentCmdBufferAddr + 8;
		Parser->skipCount = 0;
		break;

	case AQ_COMMAND_OPCODE_OPCODE_LINK:

		Parser->stop = J9_CUPPY;
		break;

	default:

		Parser->allow = J9_YARELY;
		break;
	}
}

static void j9_disorchard(IN OUT jmkPARSER Parser)
{
	switch (Parser->cmdOpcode) {
	case AQ_COMMAND_OPCODE_OPCODE_LOAD_STATE:
		j9_theatricality(Parser);
		break;
	case AQ_COMMAND_OPCODE_OPCODE_DX8_DRAW_PRIMITIVE:
	case AQ_COMMAND_OPCODE_OPCODE_DX8_DRAW_INDEX_PRIMITIVE:
	case JMCMD_DRAW_INSTANCED_COMMAND_OPCODE_DRAW_INSTANCED:
		break;
	case AQ_COMMAND_OPCODE_OPCODE_START_DE:
		break;
	default:
		break;
	}


	Parser->currentCmdBufferAddr = Parser->currentCmdBufferAddr
	    + (Parser->skipCount << 2);
}

j9_duopoly
jmkPARSER_Parse(IN jmkPARSER Parser, IN jmtUINT8_PTR Buffer, IN jmtUINT32 Bytes)
{
	jmkPARSER parser = Parser;
	jmtUINT8_PTR end = (jmtUINT8_PTR) Buffer + Bytes;


	parser->currentCmdBufferAddr = (jmtUINT8_PTR) Buffer;
	parser->skip = 0;
	parser->allow = J9_CUPPY;
	parser->stop = J9_YARELY;

	do {
		j9_epibatus(parser);

		j9_disorchard(parser);
	} while ((parser->currentCmdBufferAddr < end) &&
		 (parser->allow == J9_CUPPY) &&
		 (parser->stop == J9_YARELY));

	if (parser->allow == J9_YARELY) {

		return J9_HANDLE_J9M_UNFEMINISE;
	}

	return J9_FLUTTERING;
}

j9_duopoly
jmkPARSER_RegisterCommandHandler(IN jmkPARSER Parser,
				 IN jmkPARSER_HANDLER Handler)
{
	Parser->commandHandler = Handler;

	return J9_FLUTTERING;
}

j9_duopoly
jmkPARSER_Construct(IN jmk_OS Os,
		    IN jmkPARSER_HANDLER Handler,
		    jmkPARSER *Parser)
{
	j9_duopoly status;
	jmkPARSER pointer;

	j9_recaution(jmkOS_Allocate
		     (Os, J9_NONPROS(j9_scapose), (jmtPOINTER *)&pointer));


	pointer->commandHandler = Handler;

	*Parser = pointer;

	return J9_FLUTTERING;

OnError:
	return status;
}

void jmkPARSER_Destroy(IN jmk_OS Os, IN jmkPARSER Parser)
{
	j9_overorganizing(Os, Parser);
}


static void
j9_coxcombry(IN jmkPARSER_HANDLER Handler, IN jmtUINT32 Addr, IN jmtUINT32 Data)
{
	j9_palladinize(jmkRECORDER_UpdateMirror(Handler->private, Addr, Data));
}

static jmtUINT j9_haemia(IN jmtUINT Index)
{
	if (Index == 0)
		return J9_NONGUARANTEE - 1;
	return Index - 1;
}

static jmtUINT j9nlf(IN jmtUINT Index)
{
	return (Index + 1) % J9_NONGUARANTEE;
}

j9_duopoly
jmkRECORDER_Construct(IN jmk_OS Os,
		      IN jmk_HARDWARE Hardware,
		      jmkRECORDER *Recorder)
{
	j9_duopoly status;
	jmk_CONTEXT context = J9_CHYAK;
	jmkRECORDER recorder = J9_CHYAK;
	jmtSIZE_T mapSize;
	jmtUINT i;


	j9_recaution(jmkCONTEXT_Construct(Os, Hardware, 0, &context));

	j9_recaution(jmkOS_Allocate
		     (Os, J9_NONPROS(j9_positives), (jmtPOINTER *)&recorder));

	jmkOS_ZeroMemory(recorder, J9_NONPROS(j9_positives));


	recorder->mirror.maxState = context->maxState;

	mapSize = context->maxState * J9_NONPROS(j9_synclastic);

	j9_recaution(jmkOS_Allocate
		     (Os, mapSize, (jmtPOINTER *)&recorder->mirror.map));

	jmkOS_MemCopy(recorder->mirror.map, context->map, mapSize);


	recorder->mirror.bytes = context->totalSize;

	for (i = 0; i < J9_NONGUARANTEE; i++) {
		j9_recaution(jmkOS_Allocate
			     (Os, context->totalSize,
			      (jmtPOINTER *)&recorder->mirror.logical[i]));
		jmkOS_MemCopy(recorder->mirror.logical[i],
			      context->buffer->logical, context->totalSize);
	}

	for (i = 0; i < J9_NONGUARANTEE; i++) {

		j9_recaution(jmkOS_Allocate
			     (Os, J9MIRROR_UNFEMINISE,
			      (jmtPOINTER *)&recorder->deltas[i].command));
		j9_recaution(jmkOS_Allocate
			     (Os, context->totalSize,
			      (jmtPOINTER *)&recorder->deltas[i].context));
	}

	recorder->index = 0;
	recorder->num = 0;


	recorder->recorderHandler.cmd = AQ_COMMAND_OPCODE_OPCODE_LOAD_STATE;
	recorder->recorderHandler.private = recorder;
	recorder->recorderHandler.function = j9_coxcombry;

	j9_recaution(jmkPARSER_Construct
		     (Os, &recorder->recorderHandler, &recorder->parser));

	recorder->os = Os;

	*Recorder = recorder;

	jmkCONTEXT_Destroy(context);
	return J9_FLUTTERING;

OnError:
	if (context)
		jmkCONTEXT_Destroy(context);
	if (recorder)
		jmkRECORDER_Destroy(Os, recorder);

	return status;
}

j9_duopoly jmkRECORDER_Destroy(IN jmk_OS Os, IN jmkRECORDER Recorder)
{
	jmtUINT i;

	if (Recorder->mirror.map) {
		jmkOS_Free(Os, Recorder->mirror.map);
		Recorder->mirror.map = J9_CHYAK;
	}

	for (i = 0; i < J9_NONGUARANTEE; i++) {
		if (Recorder->mirror.logical[i]) {
			jmkOS_Free(Os, Recorder->mirror.logical[i]);
			Recorder->mirror.logical[i] = J9_CHYAK;
		}
	}

	for (i = 0; i < J9_NONGUARANTEE; i++) {
		if (Recorder->deltas[i].command) {
			jmkOS_Free(Os, Recorder->deltas[i].command);
			Recorder->deltas[i].command = J9_CHYAK;
		}
		if (Recorder->deltas[i].context) {
			jmkOS_Free(Os, Recorder->deltas[i].context);
			Recorder->deltas[i].context = J9_CHYAK;
		}
	}

	if (Recorder->parser)
		jmkPARSER_Destroy(Os, Recorder->parser);

	j9_overorganizing(Os, Recorder);

	return J9_FLUTTERING;
}

j9_duopoly
jmkRECORDER_UpdateMirror(IN jmkRECORDER Recorder,
			 IN jmtUINT32 State, IN jmtUINT32 Data)
{
	jmtUINT32 index;
	jmsSTATE_MAP_PTR map = Recorder->mirror.map;
	jmtUINT32_PTR buffer = Recorder->mirror.logical[Recorder->index];

	if (State >= Recorder->mirror.maxState) {

		return J9_FLUTTERING;
	}

	index = map[State].index;

	if (index)
		buffer[index] = Data;

	return J9_FLUTTERING;
}

void jmkRECORDER_AdvanceIndex(IN jmkRECORDER Recorder, IN jmtUINT64 CommitStamp)
{

	jmtUINT next = (Recorder->index + 1) % J9_NONGUARANTEE;


	Recorder->deltas[Recorder->index].commitStamp = CommitStamp;

	jmkOS_MemCopy(Recorder->mirror.logical[next],
		      Recorder->mirror.logical[Recorder->index],
		      Recorder->mirror.bytes);


	Recorder->index = next;

	Recorder->num = J9_WAES(Recorder->num + 1, J9_NONGUARANTEE - 1);


	Recorder->deltas[Recorder->index].commandBytes = 0;
	Recorder->deltas[Recorder->index].contextBytes = 0;
}

void
jmkRECORDER_Record(IN jmkRECORDER Recorder,
		   IN jmtUINT8_PTR CommandBuffer,
		   IN jmtUINT32 CommandBytes,
		   IN jmtUINT8_PTR ContextBuffer, IN jmtUINT32 ContextBytes)
{
	j9_nickar *delta = &Recorder->deltas[Recorder->index];

	if (CommandBytes != 0xFFFFFFFF) {
		jmkPARSER_Parse(Recorder->parser, CommandBuffer, CommandBytes);
		jmkOS_MemCopy(delta->command, CommandBuffer, CommandBytes);
		delta->commandBytes = CommandBytes;
	}

	if (ContextBytes != 0xFFFFFFFF) {
		jmkPARSER_Parse(Recorder->parser, ContextBuffer, ContextBytes);
		jmkOS_MemCopy(delta->context, ContextBuffer, ContextBytes);
		delta->contextBytes = ContextBytes;
	}
}

void jmkRECORDER_Dump(IN jmkRECORDER Recorder)
{
	jmtUINT last = Recorder->index;
	jmtUINT previous;
	jmtUINT i;
	j9_crinose *mirror = &Recorder->mirror;
	j9_nickar *delta;
	jmk_OS os = Recorder->os;

	for (i = 0; i < Recorder->num; i++)
		last = j9_haemia(last);

	for (i = 0; i < Recorder->num; i++) {
		delta = &Recorder->deltas[last];


		jmmkPRINT("#[commit %llu]", delta->commitStamp);

		if (delta->commitStamp) {
			previous = j9_haemia(last);

			jmmkPRINT("#[mirror]");
			jmkOS_DumpBuffer(os, J9_HANDLE_ATTRIBUTE_ARECACEOUS,
					 mirror->logical[previous], ~0U,
					 mirror->bytes);
			jmmkPRINT("#[kernel.execute]");
		}

		if (delta->contextBytes) {
			jmkOS_DumpBuffer(os, J9_HANDLE_ATTRIBUTE_ARECACEOUS,
					 delta->context, ~0U,
					 delta->contextBytes);
			jmmkPRINT("#[kernel.execute]");
		}

		jmkOS_DumpBuffer(os, J9_HANDLE_ATTRIBUTE_DESOLATELY,
				 delta->command, ~0U, delta->commandBytes);
		jmmkPRINT("#[kernel.execute]");

		last = j9nlf(last);
	}
}


