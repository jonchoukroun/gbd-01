#ifndef Instructions
#define Instructions

#include "cpu.h"

typedef void (*OpcodeInstruction)(CPU *, uint8_t opcode);

// ***********************
// 8-bit load instructions
// ***********************

/**
 * Load into 1st register 2nd register's value
 * No flag effects
 * 4 T-cycles
 **/
void LD_r_r(CPU *, uint8_t);

/**
 * Load into register immediate unsigned value
 * No flag effects
 * 8 T-cycles
 **/
void LD_r_n(CPU *, uint8_t);

/**
 * Load memory contents pointed to from register HL into register
 * No flag effects
 * 8 T-cyles
 **/
void LD_r_HL(CPU *, uint8_t);

/**
 * Load into memory at address pointed to from HL, the contents of register r
 * No flag effects
 * 8 T-cycles
 **/
void LD_HL_r(CPU *, uint8_t);

/**
 * Load memory contents into register A
 * No flag effects
 * 8 T-cycles
 **/
void LD_A_rr(CPU *, uint8_t);

/**
 * Load A register value into internal RAM
 * No flag effects
 * 8 T-cycles
 **/
void LD_rr_A(CPU *, uint8_t);

/**
 * Load memory contents pointed to by HL into register A then incrment HL
 * No flag effects
 * 8 T-cycles
 **/
void LD_A_HLI(CPU *, uint8_t);

/**
 * Load memory contents pointed to by HL into register A then decrement HL
 * No flag effects
 * 8 T-cycles
 **/
void LD_A_HLD(CPU *, uint8_t);

/**
 * Load register A into memory at the address in HL then increment HL
 * No flag effects
 * 8 T-cycles
 **/
void LD_HLI_A(CPU *, uint8_t);

/**
 * Load register A into memory at the address in HL then decrement HL
 * No flag effects
 * 8 T-cycles
 **/
void LD_HLD_A(CPU *, uint8_t);

void UNDEF(CPU *, uint8_t);

static const OpcodeInstruction OPCODE_TABLE[256] = {
/*            0x0       0x1        0x2       0x3       0x4       0x5       0x6       0x7       0x8       0x9        0xa       0xb       0xc       0xd       0xe       0xf */
/* 0 */    &UNDEF,   &UNDEF,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 1 */    &UNDEF,   &UNDEF,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 2 */    &UNDEF,   &UNDEF, &LD_HLI_A,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF, &LD_A_HLI,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 3 */    &UNDEF,   &UNDEF, &LD_HLD_A,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF, &LD_A_HLD,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 4 */   &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r, &LD_r_HL,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r, &LD_r_HL,  &LD_r_r,
/* 5 */   &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r, &LD_r_HL,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r, &LD_r_HL,  &LD_r_r,
/* 5 */   &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r, &LD_r_HL,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r, &LD_r_HL,  &LD_r_r,
/* 7 */   &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r, &LD_r_HL,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r, &LD_r_HL,  &LD_r_r,
/* 8 */    &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* 9 */    &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* a */    &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* b */    &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* c */    &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* d */    &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* e */  &LD_rr_A,   &UNDEF,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* f */  &LD_A_rr,   &UNDEF,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
};

#endif
