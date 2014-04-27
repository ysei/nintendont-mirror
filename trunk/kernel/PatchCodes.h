#ifndef __PATCHCODES_H__
#define __PATCHCODES_H__

#include "global.h"

#if 1

#ifndef EXIPATCH

#include "asm/__CARDSync.h"
#include "asm/CARDCheck.h"
#include "asm/CARDCheckAsync.h"
#include "asm/CARDCheckEX.h"
#include "asm/CARDClose.h"
#include "asm/CARDCreate.h"
#include "asm/CARDDelete.h"
#include "asm/CARDFastOpen.h"
#include "asm/CARDFreeBlocks.h"
#include "asm/CARDGetEncoding.h"
#include "asm/CARDGetMemSize.h"
#include "asm/CARDGetSerialNo.h"
#include "asm/CARDGetStats.h"
#include "asm/CARDMount.h"
#include "asm/CARDMountAsync.h"
#include "asm/CARDOpen.h"
#include "asm/CARDProbe.h"
#include "asm/CARDProbeEX.h"
#include "asm/CARDRead.h"
#include "asm/CARDSetStats.h"
#include "asm/CARDWrite.h"
#include "asm/CARDGetResultCode.h"
#include "asm/CARDGetXferredBytes.h"
#include "asm/CARDFastDelete.h"
#include "asm/CARDRename.h"


#else

#include "asm/EXIImm.h"
#include "asm/EXISelect.h"
#include "asm/EXILock.h"
#include "asm/EXIDMA.h"
#include "asm/EXIProbe.h"
#include "asm/EXIGetID.h"
#include "asm/__CARDReadStatus.h"
#include "asm/__CARDEraseSector.h"

#endif

#include "asm/SITransfer.h"

#include "asm/ARQPostRequest.h"
#include "asm/AXSetVoiceState.h"
#include "asm/AXSetVoiceAdr.h"
#include "asm/ARInit.h"
#include "asm/ARGetBaseAddress.h"
#include "asm/ARStartDMA.h"
#include "asm/SIGetType.h"
#include "asm/__OSInitSRAM.h"
#include "asm/__OSReadROM.h"
#include "asm/FakeInterrupt.h"
#include "asm/TCIntrruptHandler.h"
//#include "asm/FakeAIInterrupt.h"
#include "asm/APRCallback.h"
#include "asm/PADRead.h"
#include "asm/PADControlMotor.h"
#include "asm/DCInvalidateRange.h"

unsigned char SRAM[64] =
{
    0x42, 0x8B,
	0xBD, 0x71,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x17, 0xCA, 0x2A, 0x85, 
    0x00,
	0x00,
	0x00,
	0x3C,
	0x9B, 0x58, 0x5A, 0xB5,		0xB6,0xC7, 0x92, 0xB7,		0x55,0x49, 0xC6, 0x0B, 
    0x4A, 0x09, 0x00, 0x45,		0x0D,0x00, 0xB2, 0x1D,		0x41,0x03, 0x88, 0x1D,
	0x49, 0x41, 0x50, 0x04,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0x00, 0x00,
	0xFE,
	0x00,
	0xC8, 0xC8,
	0x01, 0x05,
	0x57, 0x28, 
} ;

const u32 __GXSetVAT_patch[31] = {
	/*0x8122ce00,*/ 0x39400000, 0x896904f2, 0x7d284b78,
	0x556007ff, 0x41820050, 0x38e00008, 0x3cc0cc01,
	0x98e68000, 0x61400070, 0x61440080, 0x61430090,
	0x98068000, 0x38000000, 0x80a8001c, 0x90a68000,
	0x98e68000, 0x98868000, 0x8088003c, 0x90868000,
	0x98e68000, 0x98668000, 0x8068005c, 0x90668000,
	0x98068000, 0x556bf87f, 0x394a0001, 0x39080004,
	0x4082ffa0, 0x38000000, 0x980904f2, 0x4e800020
};

const u8 GXMObjects[][0x3C] =
{
	{	// GXPal528IntDf
		0x00, 0x00, 0x00, 0x04, 0x02, 0x80, 0x02, 0x10, 0x02, 0x10, 0x00, 0x28, 0x00, 0x17, 0x02, 0x80, 
		0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x08, 0x08, 0x0A, 0x0C, 0x0A, 0x08, 0x08, 0x00, 0x00, 0x00, 
	},

	{	// GXEurgb60Hz480IntDf
		0x00, 0x00, 0x00, 0x14, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x28, 0x00, 0x00, 0x02, 0x80, 
		0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x08, 0x08, 0x0A, 0x0C, 0x0A, 0x08, 0x08, 0x00, 0x00, 0x00, 
	},

	{	// GXMpal480IntDf
		0x00, 0x00, 0x00, 0x08, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x28, 0x00, 0x00, 0x02, 0x80, 
		0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x08, 0x08, 0x0A, 0x0C, 0x0A, 0x08, 0x08, 0x00, 0x00, 0x00, 
	},

	{	// GXNtsc480IntDf
		0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x28, 0x00, 0x00, 0x02, 0x80, 
		0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x08, 0x08, 0x0A, 0x0C, 0x0A, 0x08, 0x08, 0x00, 0x00, 0x00, 
	},

	{	// GXNtsc480Int
		0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x28, 0x00, 0x00, 0x02, 0x80, 
		0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x00, 0x00, 0x15, 0x16, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 
	},

	{	// GXNtsc480Prog
		0x00, 0x00, 0x00, 0x02, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x28, 0x00, 0x00, 0x02, 0x80, 
		0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x00, 0x00, 0x15, 0x16, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 
	},

	{	// GXPal528Prog
		0x00, 0x00, 0x00, 0x06, 0x02, 0x80, 0x02, 0x10, 0x02, 0x10, 0x00, 0x28, 0x00, 0x17, 0x02, 0x80, 
		0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x00, 0x00, 0x15, 0x16, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 
	},

	{	// GXEurgb60Hz480Prog
		0x00, 0x00, 0x00, 0x16, 0x02, 0x80, 0x01, 0xE0, 0x01, 0xE0, 0x00, 0x28, 0x00, 0x00, 0x02, 0x80, 
		0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		0x06, 0x06, 0x00, 0x00, 0x15, 0x16, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 
	},
};

const unsigned char patch_fwrite_GC[144] =	// actually wii
{
    0x7C, 0x85, 0x21, 0xD7, 0x40, 0x81, 0x00, 0x84, 0x3C, 0xE0, 0xCD, 0x00, 0x3D, 0x40, 0xCD, 0x00, 
    0x3D, 0x60, 0xCD, 0x00, 0x60, 0xE7, 0x68, 0x14, 0x61, 0x4A, 0x68, 0x24, 0x61, 0x6B, 0x68, 0x20, 
    0x38, 0xC0, 0x00, 0x00, 0x7C, 0x06, 0x18, 0xAE, 0x54, 0x00, 0xA0, 0x16, 0x64, 0x08, 0xB0, 0x00, 
    0x38, 0x00, 0x00, 0xD0, 0x90, 0x07, 0x00, 0x00, 0x7C, 0x00, 0x06, 0xAC, 0x91, 0x0A, 0x00, 0x00, 
    0x7C, 0x00, 0x06, 0xAC, 0x38, 0x00, 0x00, 0x19, 0x90, 0x0B, 0x00, 0x00, 0x7C, 0x00, 0x06, 0xAC, 
    0x80, 0x0B, 0x00, 0x00, 0x7C, 0x00, 0x04, 0xAC, 0x70, 0x09, 0x00, 0x01, 0x40, 0x82, 0xFF, 0xF4, 
    0x80, 0x0A, 0x00, 0x00, 0x7C, 0x00, 0x04, 0xAC, 0x39, 0x20, 0x00, 0x00, 0x91, 0x27, 0x00, 0x00, 
    0x7C, 0x00, 0x06, 0xAC, 0x74, 0x09, 0x04, 0x00, 0x41, 0x82, 0xFF, 0xB8, 0x38, 0xC6, 0x00, 0x01, 
    0x7F, 0x86, 0x20, 0x00, 0x40, 0x9E, 0xFF, 0xA0, 0x7C, 0xA3, 0x2B, 0x78, 0x4E, 0x80, 0x00, 0x20, 
};

// Audio streaming replacement functions copied from Swiss r92
const u32 __dvdLowAudioStatusNULL[17] = {
        // execute function(1); passed in on r4
        0x9421FFC0,     //  stwu        sp, -0x0040 (sp)
        0x7C0802A6,     //  mflr        r0
        0x90010000,     //  stw         r0, 0 (sp)
        0x7C8903A6,     //  mtctr       r4
        0x3C80CC00,     //  lis         r4, 0xCC00
        0x2E830000,     //  cmpwi       cr5, r3, 0
        0x4196000C,     //  beq-        cr5, +0xC ?
        0x38600001,     //  li          r3, 1
        0x48000008,     //  b           +0x8 ?
        0x38600000,     //  li          r3, 0
        0x90646020,     //  stw         r3, 0x6020 (r4)
        0x38600001,     //  li          r3, 1
        0x4E800421,     //  bctrl
        0x80010000,     //  lwz         r0, 0 (sp)
        0x7C0803A6,     //  mtlr        r0
        0x38210040,     //  addi        sp, sp, 64
        0x4E800020      //  blr
};

const u32 __dvdLowAudioConfigNULL[10] = {
        // execute callback(1); passed in on r5 without actually touching the drive!
        0x9421FFC0,     //  stwu        sp, -0x0040 (sp)
        0x7C0802A6,     //  mflr        r0
        0x90010000,     //  stw         r0, 0 (sp)
        0x7CA903A6,     //  mtctr       r5
        0x38600001,     //  li          r3, 1
        0x4E800421,     //  bctrl
        0x80010000,     //  lwz         r0, 0 (sp)
        0x7C0803A6,     //  mtlr        r0
        0x38210040,     //  addi        sp, sp, 64
        0x4E800020      //  blr
};

const u32 __dvdLowReadAudioNULL[] = {
        // execute callback(1); passed in on r6 without actually touching the drive!
        0x9421FFC0,     //  stwu        sp, -0x0040 (sp)
        0x7C0802A6,     //  mflr        r0
        0x90010000,     //  stw         r0, 0 (sp)
        0x7CC903A6,     //  mtctr       r6
        0x38600001,     //  li          r3, 1
        0x4E800421,     //  bctr;
        0x80010000,     //  lwz         r0, 0 (sp)
        0x7C0803A6,     //  mtlr        r0
        0x38210040,     //  addi        sp, sp, 64
        0x4E800020
};

const unsigned char DVDInquiryAsync[] = {

	0x94, 0x21, 0xFF, 0xF0, 	0x7C, 0x08, 0x02, 0xA6, 	0x90, 0x01, 0x00, 0x08, 	0x38, 0x00, 0x00, 0x00, 
	0x90, 0x03, 0x00, 0x00, 	0x90, 0x03, 0x00, 0x04, 	0x90, 0x03, 0x00, 0x0C, 	0x90, 0x03, 0x00, 0x10, 
	0x38, 0x00, 0x00, 0x02, 	0x90, 0x03, 0x00, 0x08, 	0x38, 0x00, 0x00, 0x20, 	0x90, 0x03, 0x00, 0x1C, 
	0x90, 0x03, 0x00, 0x20, 	0x90, 0x03, 0x00, 0x14, 	0x90, 0x83, 0x00, 0x18, 	0x90, 0xA3, 0x00, 0x28, 
	0x38, 0x00, 0x00, 0x00, 	0x7C, 0x00, 0x23, 0xAC, 	0x38, 0x00, 0x00, 0x00, 	0xB0, 0x04, 0x00, 0x02, 
	0x2C, 0x05, 0x00, 0x00, 	0x41, 0x82, 0x00, 0x14, 	0x7C, 0xA9, 0x03, 0xA6, 	0x7C, 0x64, 0x1B, 0x78, 
	0x38, 0x60, 0x00, 0x20, 	0x4E, 0x80, 0x04, 0x21, 	0x38, 0x60, 0x00, 0x01, 	0x80, 0x01, 0x00, 0x08, 
	0x7C, 0x08, 0x03, 0xA6, 	0x38, 0x21, 0x00, 0x10, 	0x4E, 0x80, 0x00, 0x20	
};

const unsigned char DVDSeekAbsAsyncPrio[] = {

	0x94, 0x21, 0xFF, 0xF0, 	0x7C, 0x08, 0x02, 0xA6, 	0x90, 0x01, 0x00, 0x08, 	0x38, 0x00, 0x00, 0x00, 
	0x90, 0x03, 0x00, 0x00, 	0x90, 0x03, 0x00, 0x04, 	0x90, 0x03, 0x00, 0x1C, 	0x38, 0x00, 0x00, 0x02, 
	0x90, 0x03, 0x00, 0x08, 	0x38, 0x00, 0x00, 0x00, 	0x90, 0x03, 0x00, 0x0C, 	0x90, 0x83, 0x00, 0x10, 
	0x90, 0xA3, 0x00, 0x28, 	0x2C, 0x05, 0x00, 0x00, 	0x41, 0x82, 0x00, 0x14, 	0x7C, 0xA9, 0x03, 0xA6, 
	0x7C, 0x64, 0x1B, 0x78, 	0x38, 0x60, 0x00, 0x00, 	0x4E, 0x80, 0x04, 0x21, 	0x38, 0x60, 0x00, 0x01, 
	0x80, 0x01, 0x00, 0x08, 	0x7C, 0x08, 0x03, 0xA6, 	0x38, 0x21, 0x00, 0x10, 	0x4E, 0x80, 0x00, 0x20
	
};

const unsigned char DVDReadAbsAsyncPrio[] = {

	0x94, 0x21, 0xFF, 0xF0, 	0x7C, 0x08, 0x02, 0xA6, 	0x90, 0x01, 0x00, 0x08, 	0x7F, 0xA3, 0xEB, 0x78, 
	0x80, 0x83, 0x00, 0x18, 	0x38, 0x00, 0x00, 0x00, 	0x3D, 0x00, 0xC0, 0x00, 	0x39, 0x08, 0x2F, 0x00, 
	0x7C, 0x00, 0x43, 0xAC, 	0x54, 0xA8, 0xD9, 0x7E, 	0x7D, 0x09, 0x03, 0xA6, 	0x7C, 0x88, 0x23, 0x78, 
	0x7C, 0x00, 0x43, 0xAC, 	0x39, 0x08, 0x00, 0x20, 	0x42, 0x00, 0xFF, 0xF8, 	0x3D, 0x00, 0xC0, 0x00, 
	0x3C, 0x00, 0xA7, 0x00, 	0x90, 0x08, 0x2F, 0x08, 	0x54, 0xC0, 0xF0, 0xBE, 	0x90, 0x08, 0x2F, 0x0C, 
	0x90, 0x88, 0x2F, 0x14, 	0x90, 0xA8, 0x2F, 0x10, 	0x90, 0xA8, 0x2F, 0x18, 	0x90, 0x68, 0x2F, 0x24, 
	0x38, 0x00, 0x00, 0x03, 	0x90, 0x08, 0x2F, 0x1C, 	0x90, 0xA3, 0x00, 0x1C, 	0x90, 0xA3, 0x00, 0x14, 
	0x90, 0xA3, 0x00, 0x20, 	0x80, 0x01, 0x00, 0x08, 	0x7C, 0x08, 0x03, 0xA6, 	0x38, 0x21, 0x00, 0x10, 
	0x4E, 0x80, 0x00, 0x20	
};


const u32 DVDGetDriveStatus[] = {
        0x38600000,     //  li		r3, 0
        0x4E800020
};

const u32 __OSDispatchInterruptPattern1[] =
{
	0x5483077A, 0x28030000, 0x41820008, 0x64002000
};
const u32 __OSDispatchInterruptPattern2[] =
{
	0x57C0077A, 0x28000000, 0x41820008, 0x67FF2000
};

const unsigned char DVDRead[] = {

	0x94, 0x21, 0xFF, 0xF0, 	0x7C, 0x08, 0x02, 0xA6, 	0x90, 0x01, 0x00, 0x08, 	0x38, 0x00, 0x00, 0x00, 
	0x3C, 0xE0, 0xC0, 0x00, 	0x38, 0xE7, 0x2F, 0x00, 	0x7C, 0x00, 0x3B, 0xAC, 	0x54, 0xA7, 0xD9, 0x7E, 
	0x7C, 0xE9, 0x03, 0xA6, 	0x7C, 0x87, 0x23, 0x78, 	0x7C, 0x00, 0x3B, 0xAC, 	0x38, 0xE7, 0x00, 0x20, 
	0x42, 0x00, 0xFF, 0xF8, 	0x3C, 0xE0, 0xC0, 0x00, 	0x3C, 0x00, 0xA8, 0x00, 	0x90, 0x07, 0x2F, 0x08, 
	0x80, 0x03, 0x00, 0x30, 	0x7C, 0xC0, 0x32, 0x14, 	0x54, 0xC0, 0xF0, 0xBE, 	0x90, 0x07, 0x2F, 0x0C, 
	0x90, 0x87, 0x2F, 0x14, 	0x90, 0xA7, 0x2F, 0x10, 	0x90, 0xA7, 0x2F, 0x18, 	0x38, 0x00, 0x00, 0x03, 
	0x90, 0x07, 0x2F, 0x1C, 	0x80, 0x07, 0x2F, 0x1C, 	0x2C, 0x00, 0x00, 0x03, 	0x41, 0x82, 0xFF, 0xF8, 
	0x80, 0x07, 0x2F, 0x30, 	0x70, 0x00, 0x00, 0x14, 	0x2C, 0x00, 0x00, 0x00, 	0x41, 0x82, 0xFF, 0xF4, 
	0x38, 0x00, 0x00, 0x00, 	0x90, 0x03, 0x00, 0x00, 	0x90, 0x03, 0x00, 0x04, 	0x90, 0x03, 0x00, 0x0C, 
	0x38, 0x00, 0x00, 0x01, 	0x90, 0x03, 0x00, 0x08, 	0x90, 0xC3, 0x00, 0x10, 	0x90, 0x83, 0x00, 0x18, 
	0x90, 0xA3, 0x00, 0x1C, 	0x90, 0xA3, 0x00, 0x14, 	0x90, 0xA3, 0x00, 0x20, 	0x7C, 0xA3, 0x2B, 0x78, 
	0x80, 0x01, 0x00, 0x08, 	0x7C, 0x08, 0x03, 0xA6, 	0x38, 0x21, 0x00, 0x10, 	0x4E, 0x80, 0x00, 0x20
	
};

const unsigned char DVDReadAsync[] = {

	0x94, 0x21, 0xFF, 0xF0, 	0x7C, 0x08, 0x02, 0xA6, 	0x90, 0x01, 0x00, 0x08, 	0x90, 0xE3, 0x00, 0x28, 
	0x38, 0x00, 0x00, 0x00, 	0x3C, 0xE0, 0xC0, 0x00, 	0x38, 0xE7, 0x2F, 0x00, 	0x7C, 0x00, 0x3B, 0xAC, 
	0x54, 0xA7, 0xD9, 0x7E, 	0x7C, 0xE9, 0x03, 0xA6, 	0x7C, 0x87, 0x23, 0x78, 	0x7C, 0x00, 0x3B, 0xAC, 
	0x38, 0xE7, 0x00, 0x20, 	0x42, 0x00, 0xFF, 0xF8, 	0x3C, 0xE0, 0xC0, 0x00, 	0x3C, 0x00, 0xA9, 0x00, 
	0x90, 0x07, 0x2F, 0x08, 	0x80, 0x03, 0x00, 0x30, 	0x7C, 0xC0, 0x32, 0x14, 	0x54, 0xC0, 0xF0, 0xBE, 
	0x90, 0x07, 0x2F, 0x0C, 	0x90, 0x87, 0x2F, 0x14, 	0x90, 0xA7, 0x2F, 0x10, 	0x90, 0xA7, 0x2F, 0x18, 
	0x38, 0x00, 0x00, 0x03, 	0x90, 0x07, 0x2F, 0x1C, 	0x80, 0x07, 0x2F, 0x1C, 	0x2C, 0x00, 0x00, 0x03, 
	0x41, 0x82, 0xFF, 0xF8, 	0x80, 0x07, 0x2F, 0x30, 	0x70, 0x00, 0x00, 0x14, 	0x2C, 0x00, 0x00, 0x00, 
	0x41, 0x82, 0xFF, 0xF4, 	0x38, 0x00, 0x00, 0x00, 	0x90, 0x03, 0x00, 0x00, 	0x90, 0x03, 0x00, 0x04, 
	0x90, 0x03, 0x00, 0x0C, 	0x38, 0x00, 0x00, 0x01, 	0x90, 0x03, 0x00, 0x08, 	0x90, 0xC3, 0x00, 0x10, 
	0x90, 0xA3, 0x00, 0x1C, 	0x80, 0x03, 0x00, 0x34, 	0x90, 0x03, 0x00, 0x14, 	0x90, 0x03, 0x00, 0x20, 
	0x90, 0x83, 0x00, 0x18, 	0x81, 0x83, 0x00, 0x28, 	0x2C, 0x0C, 0x00, 0x00, 	0x41, 0x82, 0x00, 0x14, 
	0x7D, 0x89, 0x03, 0xA6, 	0x7C, 0x64, 0x1B, 0x78, 	0x7C, 0xA3, 0x2B, 0x78, 	0x4E, 0x80, 0x04, 0x21, 
	0x38, 0x60, 0x00, 0x01, 	0x80, 0x01, 0x00, 0x08, 	0x7C, 0x08, 0x03, 0xA6, 	0x38, 0x21, 0x00, 0x10, 
	0x4E, 0x80, 0x00, 0x20	
};

#endif

#endif
