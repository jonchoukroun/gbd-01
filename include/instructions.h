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
 * 4 T-cycles (8 when looading into/from memory byte pointed to from HL)
 **/
void LD_r_r(CPU *, uint8_t);

/**
 * Load into register immediate unsigned value
 * No flag effects
 * 8 T-cycles (12 when loading from memory byte pointed to from HL)
 **/
void LD_r_n(CPU *, uint8_t);

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
void LD_IR_A(CPU *, uint8_t);

/**
 * Convert immediate value to internal RAM address (0xff00 - 0xffff) and load into register A
 * No flag effects
 * 8 T-cycles
 **/
void LD_A_nn(CPU *, uint8_t);

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

void UNDEF(CPU *, uint8_t);

static const OpcodeInstruction OPCODE_TABLE[256] = {
/*            0x0       0x1       0x2       0x3       0x4       0x5       0x6       0x7       0x8       0x9        0xa       0xb       0xc       0xd       0xe       0xf */
/* 0 */    &UNDEF,   &UNDEF, &LD_IR_A,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 1 */    &UNDEF,   &UNDEF, &LD_IR_A,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 2 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,   &UNDEF,   &UNDEF, &LD_A_HLI,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 3 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF, &LD_A_HLD,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_r_n,   &UNDEF,
/* 4 */   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,
/* 5 */   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,
/* 5 */   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,
/* 7 */   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &UNDEF,  &LD_r_r,  &LD_r_r,  &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,
/* 8 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* 9 */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* a */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* b */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* c */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* d */    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* e */  &LD_IR_A,   &UNDEF, &LD_IR_A,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
/* f */  &LD_A_rr,   &UNDEF, &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,
};

#endif
