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
void AND_r(CPU *, uint8_t);

/**
 * Store logical AND of register A and immediate value into register A
 * Set H flag, clear N and C flgs, conditionally set Z flag
 * 8 T-cycles
 **/
void AND_n(CPU *, uint8_t);

/**
 * Store logical AND of register A and memory contents at address in HL into register A
 * Set H flag, clear N and C flgs, conditionally set Z flag
 * 8 T-cycles
 **/
void AND_HL(CPU *, uint8_t);

/**
 * Store logical OR of register A and register value into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 4 T-cycles
 **/
void OR_r(CPU *, uint8_t);

/**
 * Store logical OR of register A and immediate value into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 8 T-Cycles
 **/
void OR_n(CPU *, uint8_t);

/**
 * Store logical OR of register A and memory contents at address in HL into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 8 T-Cycles
 **/
void OR_HL(CPU *, uint8_t);

/**
 * Store logical XOR of register A and register value into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 4 T-cycles
 **/
void XOR_r(CPU *, uint8_t);

/**
 * Store logical XOR of register A and immediate value into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 8 T-Cycles
 **/
void XOR_n(CPU *, uint8_t);

/**
 * Store logical XOR of register A and memory contents at address in HL into register A
 * Clear N, H, and C flags, conditionally set Z flag
 * 8 T-Cycles
 **/
void XOR_HL(CPU *, uint8_t);

/**
 * Compare difference between register A and register value (don't store)
 * Set N flag, conditionally set Z, H, and C flags
 * 4 T-cycles
 **/
void CP_r(CPU *, uint8_t);

/**
 * Compare difference between register A and immediate value (don't store)
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void CP_n(CPU *, uint8_t);

/**
 * Compare difference between register A and memory contents add address in HL (don't store)
 * Set N flag, conditionally set Z, H, and C flags
 * 8 T-cycles
 **/
void CP_HL(CPU *, uint8_t);

/**
 * Increment register value by 1
 * Clear N flag, ignore C flag, conditionally set Z and H flags
 * 4 T-cycles
 **/
void INC_r(CPU *, uint8_t);

/**
 * Increment memory contents at address in HL by 1
 * Clear N flag, ignore C flag, conditionally set Z and H flags
 * 8 T-cycles
 **/
void INC_HL(CPU *, uint8_t);

/**
 * Decrement register value by 1
 * Set N flag, ignore C flag, conditionally set Z and H flags
 * 4 T-cycles
 **/
void DEC_r(CPU *, uint8_t);

/**
 * Decrement memory contents at address in HL by 1
 * Set N flag, ignore C flag, conditionally set Z and H flags
 * 8 T-cycles
 **/
void DEC_HL(CPU *, uint8_t);


// **************************************************
// 16-bit arithmetic instructions
// **************************************************

/**
 * Add register pair value to register HL
 * Clear N flag, ignore Z flag, conditionally Z and H flag
 * 8 T-cycles
 **/
void ADD_rr(CPU *, uint8_t);

/**
 * Add immediate signed value to SP
 * Clears Z and N flags, conditionally sets H and C flags
 * 16 T-cycles
 **/
void ADD_e(CPU *, uint8_t);

/**
 * Increment the value in register pair
 * Ignore all flags
 * 8 T-cycles
 **/
void INC_rr(CPU *, uint8_t);

/**
 * Decrement the value in register pair
 * Ignore all flags
 * 8 T-cycles
 **/
void DEC_rr(CPU *, uint8_t);


// **************************************************
// Rotate shift instructions
// **************************************************

/**
 * Rotate contents of register A to the left
 * Place bit 7 in C flag and bit 0
 * Clear Z, N, and H flags
 * 4 T-cycles
 **/
void RLCA(CPU *, uint8_t);

/**
 * Rotate contents of register A to the left
 * Place C flag into bit 0 and bit 7 in C flag
 * Clear Z, N, and H flags
 * 4 T-cycles
 **/
void RLA(CPU *, uint8_t);

/**
 * Rotate contents of register A to the right
 * Place bit 1 into C flag and bit 7
 * Clear Z, N, and H flags
 * 4 T-cycles
 **/
void RRCA(CPU *, uint8_t);

/**
 * Rotate contents of register A to the right
 * Place bit 1 into C flag and C flag into bit 7
 * Clear Z, N, and H flags
 * 4 T-cycles
 **/
void RRA(CPU *, uint8_t);

/**
 * Rotate contents of register to the left
 * Place bit 7 into C flag and bit 0
 * Clear N and H flags, conditionally set Z flag
 * 8 T-cycles, prefixed opcode table
 **/
void RLC(CPU *, uint8_t);

/**
 * Rotate memory contents at address pointed to by HL to the left
 * Place bit 7 into C flag and bit 0
 * Clear N and H flags, conditionally set Z flag
 * 12 T-cycles, prefixed opcode table
 **/
void RLC_HL(CPU *, uint8_t);

/**
 * Rotate contents of register to the left
 * Place C flag into bit 0 and bit 7 into C flag
 * Clear N and H flags, conditionally set Z flag
 * 8 T-cycles, prefixed opcode table
 **/
void RL(CPU *, uint8_t);

/**
 * Rotate memory contents at address pointed to by HL to the left
 * Place C flag into bit 0 and bit 7 into C flag
 * Clear N and H flags, conditionally set Z flag
 * 16 T-cycles, prefixed opcode table
 **/
void RL_HL(CPU *, uint8_t);

/**
 * Rotate contents of register to the right
 * Place bit 0 into C flag and bit 7
 * Clear H and H flags, conditionally set Z flag
 * 8 T-cycles, prefixed opcode table
 **/
void RRC(CPU *, uint8_t);

/**
 * Rotate memory contents at address pointed to by HL to the right
 * Place bit 0 in C flag and bit 7
 * Clear N and H flags, conditionally set Z flag
 * 12 T-cycles, prefixed opcode table
 **/
void RRC_HL(CPU *, uint8_t);

/**
 * Rotate contents of register to the right
 * Place C flag into bit 7 and bit 0 into C flag
 * Clear N and H flags, conditionally set Z flag
 * 8 T-cycles, prefixed opcode table
 **/
void RR(CPU *, uint8_t);

/**
 * Rotate memory contents at address pointed to by HL to the right
 * Place C flag into bit 7 and bit 0 into C flag
 * Clear N and H flags, conditionally set Z flag
 * 16 T-cycles, prefixed opcode table
 **/
void RR_HL(CPU *, uint8_t);

/**
 * Shift the contents of register left
 * Place bit 7 in C flag and reset bit 0
 * Clear N and H flags, conditionally set Z flag
 * 8 T-cycles, prefixed opcode table
 **/
void SLA(CPU *, uint8_t);

/**
 * Shift the memory contents at address pointed to by HL left
 * Place bit 7 in C flag and reset bit 0
 * Reset N and H flags, conditionally set Z flag
 * 16 T-cycles, prefixed opcode table
 **/
void SLA_HL(CPU *, uint8_t);

/**
 * Arithmetic shift the contents of register right
 * Place bit 0 in C flag, leave original value in bit 7
 * Reset N and H flags, conditionally set Z flag
 * 8 T-cycles, prefixed opcode table
 **/
void SRA(CPU *, uint8_t);

/**
 * Arithmetic shift the memory contents at address pointed to by HL right
 * Place bit 0 in C flag, leave original value in bit 7
 * Reset N and H flags, conditionally set Z flag
 * 16 T-cycles, prefixed opcode table
 **/
void SRA_HL(CPU *, uint8_t);

/**
 * Logical shift the contents of register right
 * Place bit 0 in C flag, reset bit 7
 * Reset N and H flags, conditionally set Z flag
 * 8 T-cycles, prefixed opcode table
 **/
void SRL(CPU *, uint8_t);

/**
 * Logical shift the memory contents at address pointed to by HL right
 * Place bit 0 in C flag, reset bit 7
 * Reset N and H flags, conditionally set Z flag
 * 16 T-cycles, prefixed opcode table
 **/
void SRL_HL(CPU *, uint8_t);


/**
 * Swap the lower order bits with the upper order bits in register r
 * Reset all flags except Z flag
 * 8 T-cycles, prefixed opcode table
 **/
void SWAP(CPU *, uint8_t);

/**
 * Swap the nibbles of the contents pointed at address in register HL
 * Reset all flags except Z flag
 * 16 T-cycles, prefixed opcode table
 **/
void SWAP_HL(CPU *, uint8_t);

// **************************************************
// Bit instructions
// **************************************************

/**
 * Set the complement of the bit in the register
 * Reset N flag, set H flag, and ignore C flag
 * 8 T-cycles, prefixed opcode table
 **/
void BIT(CPU *, uint8_t);

/**
 * Set the complement of tbe bit in memory at the address in HL
 * Reset N flag, set H flag, and ignore C flag
 * 12 T-cycles, prefixed opcode table
 **/
void BIT_HL(CPU *, uint8_t);

/**
 * Set the bit in the register
 * Ignore all flags
 * 8 T-cycles, prefixed opcode table
 **/
void SET(CPU *, uint8_t);

/**
 * Set the bit in memory at the address in HL
 * Ignore all flags
 * 16 T-cycles, prefixed opcode table
 **/
void SET_HL(CPU *, uint8_t);

/**
 * Reset the bit in the register
 * Ignore all flags
 * 8 T-Cycles, prefixed opcode table
 **/
void RES(CPU *, uint8_t);

/**
 * Reset the bit in memory at the address in HL
 * Ignore all flags
 * 16 T-Cycles, prefixed opcode table
 **/
void RES_HL(CPU *, uint8_t);

void UNDEF(CPU *, uint8_t);

static const OpcodeInstruction OPCODE_TABLE[256] = {
/*            0x0        0x1        0x2       0x3       0x4       0x5        0x6       0x7       0x8        0x9        0xa       0xb       0xc       0xd        0xe       0xf */
/* 0 */      &SET, &LD_rr_nn,  &LD_rr_A,  &INC_rr,   &INC_r,   &DEC_r,   &LD_r_n,    &RLCA,   &UNDEF,   &ADD_rr,  &LD_A_rr,  &DEC_rr,   &INC_r,   &DEC_r,   &LD_r_n,    &RRCA,
/* 1 */    &UNDEF, &LD_rr_nn,  &LD_rr_A,  &INC_rr,   &INC_r,   &DEC_r,   &LD_r_n,     &RLA,   &UNDEF,   &ADD_rr,  &LD_A_rr,  &DEC_rr,   &INC_r,   &DEC_r,   &LD_r_n,     &RRA,
/* 2 */    &UNDEF, &LD_rr_nn, &LD_HLI_A,  &INC_rr,   &INC_r,   &DEC_r,   &LD_r_n,   &UNDEF,   &UNDEF,   &ADD_rr, &LD_A_HLI,  &DEC_rr,   &INC_r,   &DEC_r,   &LD_r_n,   &UNDEF,
/* 3 */    &UNDEF, &LD_rr_nn, &LD_HLD_A,  &INC_rr,  &INC_HL,  &DEC_HL,    &UNDEF,   &UNDEF,   &UNDEF,   &ADD_rr, &LD_A_HLD,  &DEC_rr,   &INC_r,   &DEC_r,   &LD_r_n,   &UNDEF,
/* 4 */   &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,  &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,
/* 5 */   &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,  &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,
/* 5 */   &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,  &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,
/* 7 */   &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,  &LD_r_r,   &LD_r_r,   &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_r,  &LD_r_HL,  &LD_r_r,
/* 8 */    &ADD_r,    &ADD_r,    &ADD_r,   &ADD_r,   &ADD_r,   &ADD_r,   &ADD_HL,   &ADD_r,   &ADC_r,    &ADC_r,    &ADC_r,   &ADC_r,   &ADC_r,   &ADC_r,   &ADC_HL,   &ADC_r,
/* 9 */    &SUB_r,    &SUB_r,    &SUB_r,   &SUB_r,   &SUB_r,   &SUB_r,   &SUB_HL,   &SUB_r,   &SBC_r,    &SBC_r,    &SBC_r,   &SBC_r,   &SBC_r,   &SBC_r,   &SBC_HL,   &SBC_r,
/* a */    &AND_r,    &AND_r,    &AND_r,   &AND_r,   &AND_r,   &AND_r,   &AND_HL,   &AND_r,   &XOR_r,    &XOR_r,    &XOR_r,   &XOR_r,   &XOR_r,   &XOR_r,   &XOR_HL,   &XOR_r,
/* b */     &OR_r,     &OR_r,     &OR_r,    &OR_r,    &OR_r,    &OR_r,    &OR_HL,    &OR_r,    &CP_r,     &CP_r,     &CP_r,    &CP_r,    &CP_r,    &CP_r,    &CP_HL,    &CP_r,
/* c */    &UNDEF,   &POP_rr,    &UNDEF,   &UNDEF,   &UNDEF, &PUSH_rr,    &ADD_n,   &UNDEF,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &ADC_n,   &UNDEF,
/* d */    &UNDEF,   &POP_rr,    &UNDEF,   &UNDEF,   &UNDEF, &PUSH_rr,    &SUB_n,   &UNDEF,   &UNDEF,    &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,    &SBC_n,   &UNDEF,
/* e */  &LD_rr_A,   &POP_rr,  &LD_rr_A,   &UNDEF,   &UNDEF, &PUSH_rr,    &AND_n,   &UNDEF,   &ADD_e,    &UNDEF,  &LD_rr_A,   &UNDEF,   &UNDEF,   &UNDEF,    &XOR_n,   &UNDEF,
/* f */  &LD_A_rr,   &POP_rr,  &LD_A_rr,   &UNDEF,   &UNDEF, &PUSH_rr,     &OR_n,   &UNDEF,   &UNDEF, &LD_SP_HL,  &LD_A_rr,   &UNDEF,   &UNDEF,   &UNDEF,     &CP_n,   &UNDEF,
};

static const OpcodeInstruction PREFIXED_TABLE[256] = {
/*            0x0        0x1        0x2       0x3       0x4       0x5        0x6       0x7       0x8        0x9        0xa       0xb       0xc       0xd        0xe       0xf */
/* 0 */      &RLC,      &RLC,      &RLC,     &RLC,     &RLC,     &RLC,   &RLC_HL,     &RLC,     &RRC,      &RRC,      &RRC,     &RRC,     &RRC,     &RRC,   &RRC_HL,     &RRC,
/* 1 */       &RL,       &RL,       &RL,      &RL,      &RL,      &RL,    &RL_HL,      &RL,      &RR,       &RR,       &RR,      &RR,      &RR,      &RR,    &RR_HL,      &RR,
/* 2 */      &SLA,      &SLA,      &SLA,     &SLA,     &SLA,     &SLA,   &SLA_HL,     &SLA,     &SRA,      &SRA,      &SRA,     &SRA,     &SRA,     &SRA,   &SRA_HL,     &SRA,
/* 3 */     &SWAP,     &SWAP,     &SWAP,    &SWAP,    &SWAP,    &SWAP,  &SWAP_HL,    &SWAP,     &SRL,      &SRL,      &SRL,     &SRL,     &SRL,     &SRL,   &SRL_HL,     &SRL,
/* 4 */      &BIT,      &BIT,      &BIT,     &BIT,     &BIT,     &BIT,   &BIT_HL,     &BIT,     &BIT,      &BIT,      &BIT,     &BIT,     &BIT,     &BIT,   &BIT_HL,     &BIT,
/* 5 */      &BIT,      &BIT,      &BIT,     &BIT,     &BIT,     &BIT,   &BIT_HL,     &BIT,     &BIT,      &BIT,      &BIT,     &BIT,     &BIT,     &BIT,   &BIT_HL,     &BIT,
/* 6 */      &BIT,      &BIT,      &BIT,     &BIT,     &BIT,     &BIT,   &BIT_HL,     &BIT,     &BIT,      &BIT,      &BIT,     &BIT,     &BIT,     &BIT,   &BIT_HL,     &BIT,
/* 7 */      &BIT,      &BIT,      &BIT,     &BIT,     &BIT,     &BIT,   &BIT_HL,     &BIT,     &BIT,      &BIT,      &BIT,     &BIT,     &BIT,     &BIT,   &BIT_HL,     &BIT,
/* 8 */      &RES,      &RES,      &RES,     &RES,     &RES,     &RES,   &RES_HL,     &RES,     &RES,      &RES,      &RES,     &RES,     &RES,     &RES,   &RES_HL,     &RES,
/* 9 */      &RES,      &RES,      &RES,     &RES,     &RES,     &RES,   &RES_HL,     &RES,     &RES,      &RES,      &RES,     &RES,     &RES,     &RES,   &RES_HL,     &RES,
/* a */      &RES,      &RES,      &RES,     &RES,     &RES,     &RES,   &RES_HL,     &RES,     &RES,      &RES,      &RES,     &RES,     &RES,     &RES,   &RES_HL,     &RES,
/* b */      &RES,      &RES,      &RES,     &RES,     &RES,     &RES,   &RES_HL,     &RES,     &RES,      &RES,      &RES,     &RES,     &RES,     &RES,   &RES_HL,     &RES,
/* c */      &SET,      &SET,      &SET,     &SET,     &SET,     &SET,   &SET_HL,     &SET,     &SET,      &SET,      &SET,     &SET,     &SET,     &SET,   &SET_HL,     &SET,
/* d */      &SET,      &SET,      &SET,     &SET,     &SET,     &SET,   &SET_HL,     &SET,     &SET,      &SET,      &SET,     &SET,     &SET,     &SET,   &SET_HL,     &SET,
/* e */      &SET,      &SET,      &SET,     &SET,     &SET,     &SET,   &SET_HL,     &SET,     &SET,      &SET,      &SET,     &SET,     &SET,     &SET,   &SET_HL,     &SET,
/* f */      &SET,      &SET,      &SET,     &SET,     &SET,     &SET,   &SET_HL,     &SET,     &SET,      &SET,      &SET,     &SET,     &SET,     &SET,   &SET_HL,     &SET,
};

// Exported to make testing easier
uint8_t fetch_r8(CPU *, uint8_t);
typedef void (*RegSet_8)(CPU *, uint8_t value);
void set_B(CPU *cpu, uint8_t n);
void set_C(CPU *cpu, uint8_t n);
void set_D(CPU *cpu, uint8_t n);
void set_E(CPU *cpu, uint8_t n);
void set_H(CPU *cpu, uint8_t n);
void set_L(CPU *cpu, uint8_t n);
void set_at_HL(CPU *cpu, uint8_t n);
void set_A(CPU *cpu, uint8_t n);

static const RegSet_8 R_TABLE_8[8] = {
    &set_B, &set_C, &set_D, &set_E,
    &set_H, &set_L, &set_at_HL, &set_A
};

#endif
