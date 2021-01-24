#ifndef Instructions
#define Instructions

#include "cpu.h"

typedef void (*OpcodeInstruction)(CPU *, uint8_t);

// ***********************
// 8-bit load instructions
// ***********************

/**
 * Load into 1st register 2nd register's value
 * No flag effects
 * 4 t cycles
 **/
void LD_r_r(CPU *, uint8_t);

/**
 * Load into register immediate unsigned value
 * No flag effects
 * 8 t cycles
 **/
void LD_r_n(CPU *, uint8_t);

void UNDEF(CPU *, uint8_t);

static const OpcodeInstruction OPCODE_TABLE[256] = {
/*            0x0       0x1       0x2       0x3       0x4       0x5       0x6       0x7       0x8       0x9       0xa       0xb       0xc       0xd       0xe       0xf */
/* 0 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 1 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 2 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 3 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 4 */   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,
/* 5 */   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,
/* 5 */   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,
/* 7 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,
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
