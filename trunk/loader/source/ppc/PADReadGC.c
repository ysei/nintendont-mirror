#include "../../../common/include/CommonConfig.h"
#include "global.h"
#define PAD_CHAN0_BIT				0x80000000

static u32 chan, MaxPads;
static vu32 PADButtonsStick, PADTriggerCStick;
static u32 stubsize = 0x1800;
static vu32 *stubdest = (u32*)0xC1330000;
static vu32 *stubsrc = (u32*)0xD3011810;
static vu16* const _dspReg = (u16*)0xCC005000;
static vu32* const _siReg = (u32*)0xCD006400;
static vu32* const MotorCommand = (u32*)0xD3003010;
static vu32* reset = (u32*)0xC0002F54;
u32 regs[29];
const s8 DEADZONE = 0x1A;
void _start()
{
	asm volatile(
		"mflr %r5\n"
		"lis %r6, regs@h\n"
		"ori %r6, %r6, regs@l\n"
		"stw %r0, 0(%r6)\n"
		"stw %r1, 4(%r6)\n"
		"stw %r2, 8(%r6)\n"
		"stw %r3, 12(%r6)\n"
		"stw %r4, 16(%r6)\n"
		"stw %r5, 20(%r6)\n"
		"stw %r9, 24(%r6)\n"
		"stw %r10, 28(%r6)\n"
		"stw %r11, 32(%r6)\n"
		"stw %r12, 36(%r6)\n"
		"stw %r13, 40(%r6)\n"
		"stw %r14, 44(%r6)\n"
		"stw %r15, 48(%r6)\n"
		"stw %r16, 52(%r6)\n"
		"stw %r17, 56(%r6)\n"
		"stw %r18, 60(%r6)\n"
		"stw %r19, 64(%r6)\n"
		"stw %r20, 68(%r6)\n"
		"stw %r21, 72(%r6)\n"
		"stw %r22, 76(%r6)\n"
		"stw %r23, 80(%r6)\n"
		"stw %r24, 84(%r6)\n"
		"stw %r25, 88(%r6)\n"
		"stw %r26, 92(%r6)\n"
		"stw %r27, 96(%r6)\n"
		"stw %r28, 100(%r6)\n"
		"stw %r29, 104(%r6)\n"
		"stw %r30, 108(%r6)\n"
		"stw %r31, 112(%r6)\n"
	);
	PADStatus *Pad = (PADStatus*)(0x93002800); //PadBuff
	MaxPads = ((NIN_CFG*)0xD3002900)->MaxPads;
	if ((MaxPads > NIN_CFG_MAXPAD) || (MaxPads == 0))
		MaxPads = NIN_CFG_MAXPAD;
	for (chan = 0; chan < MaxPads; ++chan)
	{
		/* transfer the actual data */
		u32 x;
		u32 addr = 0xCD006400 + (0x0c * chan);
		asm volatile("lwz %0,0(%1) ; sync" : "=r"(x) : "b"(addr));
		//we just needed the first read to clear the status
		asm volatile("lwz %0,4(%1) ; sync" : "=r"(x) : "b"(addr));
		PADButtonsStick = x;
		asm volatile("lwz %0,8(%1) ; sync" : "=r"(x) : "b"(addr));
		PADTriggerCStick = x;
		/* convert data to PADStatus */
		Pad[chan].button = ((PADButtonsStick>>16)&0xFFFF);
		if(Pad[chan].button & 0x8000) /* controller not enabled */
		{
			u32 psize = sizeof(PADStatus);
			u8 *CurPad = (u8*)(&Pad[chan]);
			while(psize--) *CurPad++ = 0;
			Pad[chan].err = -1;
			continue;
		}
		Pad[chan].err = 0;
		Pad[chan].stickX = ((PADButtonsStick>>8)&0xFF)-128;
		Pad[chan].stickY = ((PADButtonsStick>>0)&0xFF)-128;
		Pad[chan].substickX = ((PADTriggerCStick>>24)&0xFF)-128;
		Pad[chan].substickY = ((PADTriggerCStick>>16)&0xFF)-128;

		/* Calculate left trigger with deadzone */
		u8 tmp_triggerL = ((PADTriggerCStick>>8)&0xFF);
		if(tmp_triggerL > DEADZONE)
			Pad[chan].triggerLeft = (tmp_triggerL - DEADZONE) * 1.11f;
		else
			Pad[chan].triggerLeft = 0;
		/* Calculate right trigger with deadzone */
		u8 tmp_triggerR = ((PADTriggerCStick>>0)&0xFF);
		if(tmp_triggerR > DEADZONE)
			Pad[chan].triggerRight = (tmp_triggerR - DEADZONE) * 1.11f;
		else
			Pad[chan].triggerRight = 0;

		/* shutdown by pressing B,Z,R,PAD_BUTTON_DOWN */
		if((Pad[chan].button&0x234) == 0x234)
		{
			/* stop audio dma */
			_dspReg[27] = (_dspReg[27]&~0x8000);
			/* reset status 1 */
			*reset = 0x1DEA;
			while(*reset == 0x1DEA) ;
			/* load in stub */
			u32 a = (u32)stubdest;
			u32 end = (u32)(stubdest + stubsize);
			for ( ; a < end; a += 32)
			{
				u8 b;
				for(b = 0; b < 4; ++b)
					*stubdest++ = *stubsrc++;
				__asm("dcbi 0,%0 ; sync ; icbi 0,%0" : : "b"(a));
			}
			__asm(
				"sync ; isync\n"
				"lis %r3, 0x8133\n"
				"mtlr %r3\n"
				"blr\n"
			);
		}
		/* clear unneeded button attributes */
		Pad[chan].button &= 0x9F7F;
		/* set current command */
		_siReg[chan*3] = (MotorCommand[chan]&0x3) | 0x00400300;
	}
	/* transfer all commands */
	_siReg[14] = 0x80000000;
	asm volatile(
		"lis %r6, regs@h\n"
		"ori %r6, %r6, regs@l\n"
		"lwz %r0, 0(%r6)\n"
		"lwz %r1, 4(%r6)\n"
		"lwz %r2, 8(%r6)\n"
		"lwz %r3, 12(%r6)\n"
		"lwz %r4, 16(%r6)\n"
		"lwz %r5, 20(%r6)\n"
		"lwz %r9, 24(%r6)\n"
		"lwz %r10, 28(%r6)\n"
		"lwz %r11, 32(%r6)\n"
		"lwz %r12, 36(%r6)\n"
		"lwz %r13, 40(%r6)\n"
		"lwz %r14, 44(%r6)\n"
		"lwz %r15, 48(%r6)\n"
		"lwz %r16, 52(%r6)\n"
		"lwz %r17, 56(%r6)\n"
		"lwz %r18, 60(%r6)\n"
		"lwz %r19, 64(%r6)\n"
		"lwz %r20, 68(%r6)\n"
		"lwz %r21, 72(%r6)\n"
		"lwz %r22, 76(%r6)\n"
		"lwz %r23, 80(%r6)\n"
		"lwz %r24, 84(%r6)\n"
		"lwz %r25, 88(%r6)\n"
		"lwz %r26, 92(%r6)\n"
		"lwz %r27, 96(%r6)\n"
		"lwz %r28, 100(%r6)\n"
		"lwz %r29, 104(%r6)\n"
		"lwz %r30, 108(%r6)\n"
		"lwz %r31, 112(%r6)\n"
		"mtlr %r5\n"
	);
	return;
}