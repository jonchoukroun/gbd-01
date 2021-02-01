#ifndef Instructions
#define Instructions

#include "cpu.h"

typedef void (*OpcodeInstruction)(CPU *, uint8_t opcode);

// **************************************************
// 8-bit load instructions
// **************************************************

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


// **************************************************
// 16-bit load instructions
// **************************************************

/**
 * Load 2 bytes of immediate data into register rr
 * No flag effects
 * 12 T-cycles
 **/
void LD_rr_nn(CPU *, uint8_t);

/**
 * Load HL value into SP
 * No flag effects
 * 8 T-cycles
 **/
void LD_SP_HL(CPU *, uint8_t);

/**
 * Pushes contents of register pair onto memory stack.
 * No flag effects
 * 16 T-cycles
 **/
void PUSH_rr(CPU *, uint8_t);

/**
 * Pops contents of memory stack onto register pair.
 * NO flag effects
 * 16 T-cycles
 **/
void POP_rr(CPU *, uint8_t);


// **************************************************
// 8-bit ALU instructions
// **************************************************

/**
 * Add value in register r to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 4 T-cycles
 **/
void ADD_A_r(CPU *, uint8_t);

/**
 * Add immediate value to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 8 T-cycles
 **/
void ADD_A_n(CPU *, uint8_t);

/**
 * Add memory contents at address in HL to A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 8 T-cycles
 **/
void ADD_A_HL(CPU *, uint8_t);

/**
 * Add value in register r and C flag to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 4 T-cycles
 **/
void ADC_A_r(CPU *, uint8_t);

/**
 * Add immediate value and C flag to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 8 T-cycles
 **/
void ADC_A_n(CPU *, uint8_t);

/**
 * Add memory contents at address in HL and C flag to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 8 T-cycles
 **/
void ADC_A_HL(CPU *, uint8_t);

/**
 * Subtract value in register from register A
 * Set N flag, conditionally set Z, H, and C flags
 * 4 T-cycles
 **/
void SUB_A_r(CPU *, uint8_t);

/**
 * Subtract immediate value from register A
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void SUB_A_n(CPU *, uint8_t);

/**
 * Subtract memory contents at address in HL from register A
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void SUB_A_HL(CPU *, uint8_t);

void UNDEF(CPU *, uint8_t);

static const OpcodeInstruction OPCODE_TABLE[256] = {
/*            0x0        0x1        0x2       0x3       0x4       0x5        0x6       0x7       0x8        0x9        0xa       0xb       0xc       0xd        0xe       0xf */
/* 0 */    &UNDEF, &LD_rr_nn,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_r_n,   &UNDEF,   &UNDEF,    &UNDEF,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_r_n,   &UNDEF,
/* 1 */    &UNDEF, &LD_rr_nn,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_r_n,   &UNDEF,   &UNDEF,    &UNDEF,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_r_n,   &UNDEF,
/* 2 */    &UNDEF, &LD_rr_nn, &LD_HLI_A,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_r_n,   &UNDEF,   &UNDEF,    &UNDEF, &LD_A_HLI,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_r_n,   &UNDEF,
/* 3 */    &UNDEF, &LD_rr_nn, &LD_HLD_A,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF, &LD_A_HLD,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_r_n,   &UNDEF,
/* 4 */   &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,  &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,
/* 5 */   &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,  &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,
/* 5 */   &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,  &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,
/* 7 */   &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,  &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,
/* 8 */  &ADD_A_r,  &ADD_A_r,  &ADD_A_r, &ADD_A_r, &ADD_A_r, &ADD_A_r, &ADD_A_HL, &ADD_A_r, &ADC_A_r,  &ADC_A_r,  &ADC_A_r, &ADC_A_r, &ADC_A_r, &ADC_A_r, &ADC_A_HL, &ADC_A_r,
/* 9 */  &SUB_A_r,  &SUB_A_r,  &SUB_A_r, &SUB_A_r, &SUB_A_r, &SUB_A_r, &SUB_A_HL, &SUB_A_r,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,
/* a */    &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,
/* b */    &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,
/* c */    &UNDEF,   &POP_rr,    &UNDEF,   &UNDEF,   &UNDEF, &PUSH_rr,  &ADD_A_n,   &UNDEF,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &ADC_A_n,   &UNDEF,
/* d */    &UNDEF,   &POP_rr,    &UNDEF,   &UNDEF,   &UNDEF, &PUSH_rr,  &SUB_A_n,   &UNDEF,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,
/* e */  &LD_rr_A,   &POP_rr,  &LD_rr_A,   &UNDEF,   &UNDEF, &PUSH_rr,    &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,
/* f */  &LD_A_rr,   &POP_rr,  &LD_A_rr,   &UNDEF,   &UNDEF, &PUSH_rr,    &UNDEF,   &UNDEF,   &UNDEF, &LD_SP_HL,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,    &UNDEF,   &UNDEF,
};

#endif
