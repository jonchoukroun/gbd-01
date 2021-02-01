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
void ADD_r(CPU *, uint8_t);

/**
 * Add immediate value to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 8 T-cycles
 **/
void ADD_n(CPU *, uint8_t);

/**
 * Add memory contents at address in HL to A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 8 T-cycles
 **/
void ADD_HL(CPU *, uint8_t);

/**
 * Add value in register r and C flag to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 4 T-cycles
 **/
void ADC_r(CPU *, uint8_t);

/**
 * Add immediate value and C flag to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 8 T-cycles
 **/
void ADC_n(CPU *, uint8_t);

/**
 * Add memory contents at address in HL and C flag to register A
 * Clears N flag, conditionally sets Z, H, and C flags
 * 8 T-cycles
 **/
void ADC_HL(CPU *, uint8_t);

/**
 * Subtract value in register from register A
 * Set N flag, conditionally set Z, H, and C flags
 * 4 T-cycles
 **/
void SUB_r(CPU *, uint8_t);

/**
 * Subtract immediate value from register A
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void SUB_n(CPU *, uint8_t);

/**
 * Subtract memory contents at address in HL from register A
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void SUB_HL(CPU *, uint8_t);

/**
 * Subtract value in register and C flag from register A
 * Set N flag, conditionally set Z, H, and C flag
 * 4 T-cycles
 **/
void SBC_r(CPU *, uint8_t);

/**
 * Subtract immediate value and C flag from register A
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void SBC_n(CPU *, uint8_t);

/**
 * Subtract memory contents at address in HL and C flag from register A
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void SBC_HL(CPU *, uint8_t);

/**
 * Set logical AND of register value and register A
 * Set H flag, clear N and C flgs, conditionally set Z flag
 * 4 T-cycles
 **/
void AND_A_r(CPU *, uint8_t);

/**
 * Store logical AND of register A and immediate value into register A
 * Set H flag, clear N and C flgs, conditionally set Z flag
 * 8 T-cycles
 **/
void AND_A_n(CPU *, uint8_t);

/**
 * Store logical AND of register A and memory contents at address in HL into register A
 * Set H flag, clear N and C flgs, conditionally set Z flag
 * 8 T-cycles
 **/
void AND_A_HL(CPU *, uint8_t);

/**
 * Store logical OR of register A and register value into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 4 T-cycles
 **/
void OR_A_r(CPU *, uint8_t);

/**
 * Store logical OR of register A and immediate value into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 8 T-Cycles
 **/
void OR_A_n(CPU *, uint8_t);

/**
 * Store logical OR of register A and memory contents at address in HL into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 8 T-Cycles
 **/
void OR_A_HL(CPU *, uint8_t);

/**
 * Store logical XOR of register A and register value into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 4 T-cycles
 **/
void XOR_A_r(CPU *, uint8_t);

/**
 * Store logical XOR of register A and immediate value into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 8 T-Cycles
 **/
void XOR_A_n(CPU *, uint8_t);

/**
 * Store logical XOR of register A and memory contents at address in HL into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 8 T-Cycles
 **/
void XOR_A_HL(CPU *, uint8_t);

/**
 * Compare difference between register A and register value (don't store)
 * Set N flag, conditionally set Z, H, and C flags
 * 4 T-cycles
 **/
void CP_A_r(CPU *, uint8_t);

/**
 * Compare difference between register A and immediate value (don't store)
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void CP_A_n(CPU *, uint8_t);

/**
 * Compare difference between register A and memory contents add address in HL (don't store)
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void CP_A_HL(CPU *, uint8_t);

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
/* 8 */    &ADD_r,    &ADD_r,    &ADD_r,   &ADD_r,   &ADD_r,   &ADD_r,   &ADD_HL,   &ADD_r,   &ADC_r,    &ADC_r,    &ADC_r,   &ADC_r,   &ADC_r,   &ADC_r,   &ADC_HL,   &ADC_r,
/* 9 */    &SUB_r,    &SUB_r,    &SUB_r,   &SUB_r,   &SUB_r,   &SUB_r,   &SUB_HL,   &SUB_r,   &SBC_r,    &SBC_r,    &SBC_r,   &SBC_r,   &SBC_r,   &SBC_r,   &SBC_HL,   &SBC_r,
/* a */  &AND_A_r,  &AND_A_r,  &AND_A_r, &AND_A_r, &AND_A_r, &AND_A_r, &AND_A_HL, &AND_A_r, &XOR_A_r,  &XOR_A_r,  &XOR_A_r, &XOR_A_r, &XOR_A_r, &XOR_A_r, &XOR_A_HL, &XOR_A_r,
/* b */   &OR_A_r,   &OR_A_r,   &OR_A_r,  &OR_A_r,  &OR_A_r,  &OR_A_r,  &OR_A_HL,  &OR_A_r,  &CP_A_r,   &CP_A_r,   &CP_A_r,  &CP_A_r,  &CP_A_r,  &CP_A_r,  &CP_A_HL,  &CP_A_r,
/* c */    &UNDEF,   &POP_rr,    &UNDEF,   &UNDEF,   &UNDEF, &PUSH_rr,    &ADD_n,   &UNDEF,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &ADC_n,   &UNDEF,
/* d */    &UNDEF,   &POP_rr,    &UNDEF,   &UNDEF,   &UNDEF, &PUSH_rr,    &SUB_n,   &UNDEF,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &SBC_n,   &UNDEF,
/* e */  &LD_rr_A,   &POP_rr,  &LD_rr_A,   &UNDEF,   &UNDEF, &PUSH_rr,  &AND_A_n,   &UNDEF,   &UNDEF,    &UNDEF,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,  &XOR_A_n,   &UNDEF,
/* f */  &LD_A_rr,   &POP_rr,  &LD_A_rr,   &UNDEF,   &UNDEF, &PUSH_rr,   &OR_A_n,   &UNDEF,   &UNDEF, &LD_SP_HL,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,   &CP_A_n,   &UNDEF,
};

#endif
