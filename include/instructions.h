#ifndef Instructions
#define Instructions

#include "cpu.h"

typedef void (*OpcodeInstruction)(CPU *, uint8_t);

void LD_r_r1(CPU *, uint8_t);

void UNDEF(CPU *, uint8_t);

static const OpcodeInstruction OPCODE_TABLE[256] = {
/*            0x0       0x1       0x2       0x3       0x4       0x5       0x6       0x7       0x8       0x9       0xa       0xb       0xc       0xd       0xe       0xf */
/* 0 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* 1 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* 2 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* 3 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* 4 */   &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,   &UNDEF,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,   &UNDEF,  &LD_r_r1,
/* 5 */   &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,   &UNDEF,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,   &UNDEF,  &LD_r_r1,
/* 5 */   &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,   &UNDEF,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,  &LD_r_r1,   &UNDEF,  &LD_r_r1,
/* 7 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* 8 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* 9 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* a */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* b */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* c */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* d */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* e */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* f */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
};

#endif
