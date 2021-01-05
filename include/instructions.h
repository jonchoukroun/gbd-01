#ifndef Instructions
#define Instructions

#include "cpu.h"

typedef void (*OpcodeInstruction)(CPU *);

// ***********************************
// 8-bit Arithmetic/Logical Operations
// ***********************************

// ADD A, r8: Add value in r8 to register A
void ADD_A_A(CPU *);
void ADD_A_B(CPU *);
void ADD_A_C(CPU *);
void ADD_A_D(CPU *);
void ADD_A_E(CPU *);
void ADD_A_H(CPU *);
void ADD_A_L(CPU *);

void ADD_A_n(CPU *);
void ADD_A_HL(CPU *);

// ADC A, r8: Add value in r8 + carry flag to register A
void ADC_A_A(CPU *);
void ADC_A_B(CPU *);
void ADC_A_C(CPU *);
void ADC_A_D(CPU *);
void ADC_A_E(CPU *);
void ADC_A_H(CPU *);
void ADC_A_L(CPU *);

void ADC_A_n(CPU *);
void ADC_A_HL(CPU *);

// SUB A, r8: Subtract value in r8 from register A
void SUB_A_A(CPU *);
void SUB_A_B(CPU *);
void SUB_A_C(CPU *);
void SUB_A_D(CPU *);
void SUB_A_E(CPU *);
void SUB_A_H(CPU *);
void SUB_A_L(CPU *);

void SUB_A_n(CPU *);
void SUB_A_HL(CPU *);

// SBC A, r8: Subtract value in r8 and carry from register A
void SBC_A_A(CPU *);
void SBC_A_B(CPU *);
void SBC_A_C(CPU *);
void SBC_A_D(CPU *);
void SBC_A_E(CPU *);
void SBC_A_H(CPU *);
void SBC_A_L(CPU *);

void SBC_A_n(CPU *);
void SBC_A_HL(CPU *);

// AND A, r8: Set A to bitwise & between A and r8
void AND_A_A(CPU *);
void AND_A_B(CPU *);
void AND_A_C(CPU *);
void AND_A_D(CPU *);
void AND_A_E(CPU *);
void AND_A_H(CPU *);
void AND_A_L(CPU *);

void AND_A_n(CPU *);
void AND_A_HL(CPU *);

// XOR A, r8: Set A to bitwise xor between A and r8
void XOR_A_A(CPU *);
void XOR_A_B(CPU *);
void XOR_A_C(CPU *);
void XOR_A_D(CPU *);
void XOR_A_E(CPU *);
void XOR_A_H(CPU *);
void XOR_A_L(CPU *);

void XOR_A_n(CPU *);
void XOR_A_HL(CPU *);

// OR A, r8: Set A to bitwise or between A and r8
void OR_A_A(CPU *);
void OR_A_B(CPU *);
void OR_A_C(CPU *);
void OR_A_D(CPU *);
void OR_A_E(CPU *);
void OR_A_H(CPU *);
void OR_A_L(CPU *);

void OR_A_n(CPU *);
void OR_A_HL(CPU *);

// CP A, r8: Compare A and register values
void CP_A_A(CPU *);
void CP_A_B(CPU *);
void CP_A_C(CPU *);
void CP_A_D(CPU *);
void CP_A_E(CPU *);
void CP_A_H(CPU *);
void CP_A_L(CPU *);

void CP_A_n(CPU *);
void CP_A_HL(CPU *);

// ************************************
// 16-bit Arithmetic/Logical Operations
// ************************************

// ADD HL, r16: Add value in r8 to register HL
void ADD_HL_BC(CPU *);
void ADD_HL_DE(CPU *);
void ADD_HL_HL(CPU *);

void ADD_HL_SP(CPU *);

// ADD SP, nn: Add signed immediate value to stack pointer
void ADD_SP_nn(CPU *);


// *********************
// 8-bit Load Operations
// *********************

// LD r, r*
void LD_B_A(CPU *);
void LD_B_B(CPU *);
void LD_B_C(CPU *);
void LD_B_D(CPU *);
void LD_B_E(CPU *);
void LD_B_H(CPU *);
void LD_B_L(CPU *);
void LD_C_A(CPU *);
void LD_C_B(CPU *);
void LD_C_C(CPU *);
void LD_C_D(CPU *);
void LD_C_E(CPU *);
void LD_C_H(CPU *);
void LD_C_L(CPU *);
void LD_D_A(CPU *);
void LD_D_B(CPU *);
void LD_D_C(CPU *);
void LD_D_D(CPU *);
void LD_D_E(CPU *);
void LD_D_H(CPU *);
void LD_D_L(CPU *);
void LD_E_A(CPU *);
void LD_E_B(CPU *);
void LD_E_C(CPU *);
void LD_E_D(CPU *);
void LD_E_E(CPU *);
void LD_E_H(CPU *);
void LD_E_L(CPU *);
void LD_H_A(CPU *);
void LD_H_B(CPU *);
void LD_H_C(CPU *);
void LD_H_D(CPU *);
void LD_H_E(CPU *);
void LD_H_H(CPU *);
void LD_H_L(CPU *);
void LD_L_A(CPU *);
void LD_L_B(CPU *);
void LD_L_C(CPU *);
void LD_L_D(CPU *);
void LD_L_E(CPU *);
void LD_L_H(CPU *);
void LD_L_L(CPU *);

// LD r, u8
void LD_A_n(CPU *);
void LD_B_n(CPU *);
void LD_C_n(CPU *);
void LD_D_n(CPU *);
void LD_E_n(CPU *);
void LD_H_n(CPU *);
void LD_L_n(CPU *);

// LD r, (HL)
void LD_A_HL(CPU *);
void LD_B_HL(CPU *);
void LD_C_HL(CPU *);
void LD_D_HL(CPU *);
void LD_E_HL(CPU *);
void LD_H_HL(CPU *);
void LD_L_HL(CPU *);

// LD (HL), r
void LD_HL_A(CPU *);
void LD_HL_B(CPU *);
void LD_HL_C(CPU *);
void LD_HL_D(CPU *);
void LD_HL_E(CPU *);
void LD_HL_H(CPU *);
void LD_HL_L(CPU *);

// LD (HL), n
void LD_HL_n(CPU *);

void LD_A_BC(CPU *);
void LD_A_DE(CPU *);

void LD_BC_A(CPU *);
void LD_DE_A(CPU *);

void LD_A_nn(CPU *);
void LD_nn_A(CPU *);

void LDH_A_C(CPU *);
void LDH_C_A(CPU *);
void LDH_A_n(CPU *);
void LDH_n_A(CPU *);

// LD A, (HL+/-): Load into A data from address stored in HL, then increment/decrement HL
void LD_A_HLI(CPU *);
void LD_A_HLD(CPU *);

// LD (HL+/-), A: Load into address stored in HL from register A, then increment/decrement HL
void LD_HLI_A(CPU *);
void LD_HLD_A(CPU *);


// **********************
// 16-bit Load Operations
// **********************

// LD rr, nn: Load 16 bit data into 16 bit register
void LD_BC_nn(CPU *);
void LD_DE_nn(CPU *);
void LD_HL_nn(CPU *);

void LD_nn_SP(CPU *);
void LD_SP_HL(CPU *);

// PUSH rr: Push to stack from register rr
void PUSH_AF(CPU *);
void PUSH_BC(CPU *);
void PUSH_DE(CPU *);
void PUSH_HL(CPU *);

// POP rr: Pop to register rr from stack
void POP_AF(CPU *);
void POP_BC(CPU *);
void POP_DE(CPU *);
void POP_HL(CPU *);

void UNDEF(CPU *);

static const OpcodeInstruction opcode_table[256] = {
/*             0x0        0x1        0x2       0x3       0x4       0x5        0x6       0x7         0x8         0x9        0xa       0xb       0xc       0xd        0xe       0xf */
/* 0 */     &UNDEF, &LD_BC_nn,  &LD_BC_A,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_B_n,   &UNDEF,  &LD_nn_SP, &ADD_HL_BC,  &LD_A_BC,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_C_n,   &UNDEF,
/* 1 */     &UNDEF, &LD_DE_nn,  &LD_DE_A,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_D_n,   &UNDEF,     &UNDEF, &ADD_HL_DE,  &LD_A_DE,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_E_n,   &UNDEF,
/* 2 */     &UNDEF, &LD_HL_nn, &LD_HLI_A,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_H_n,   &UNDEF,     &UNDEF, &ADD_HL_HL, &LD_A_HLI,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_L_n,   &UNDEF,
/* 3 */     &UNDEF,    &UNDEF, &LD_HLD_A,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_HL_n,   &UNDEF,     &UNDEF, &ADD_HL_SP, &LD_A_HLD,   &UNDEF,   &UNDEF,   &UNDEF,   &LD_A_n,   &UNDEF,
/* 4 */    &LD_B_B,   &LD_B_C,   &LD_B_D,  &LD_B_E,  &LD_B_H,  &LD_B_L,  &LD_B_HL,  &LD_B_A,    &LD_C_B,    &LD_C_C,   &LD_C_D,  &LD_C_E,  &LD_C_H,  &LD_C_L,  &LD_C_HL,  &LD_C_A,
/* 5 */    &LD_D_B,   &LD_D_C,   &LD_D_D,  &LD_D_E,  &LD_D_H,  &LD_D_L,  &LD_D_HL,  &LD_D_A,    &LD_E_B,    &LD_E_C,   &LD_E_D,  &LD_E_E,  &LD_E_H,  &LD_E_L,  &LD_E_HL,  &LD_E_A,
/* 6 */    &LD_H_B,   &LD_H_C,   &LD_H_D,  &LD_H_E,  &LD_H_H,  &LD_H_L,  &LD_H_HL,  &LD_H_A,    &LD_L_B,    &LD_L_C,   &LD_L_D,  &LD_L_E,  &LD_L_H,  &LD_L_L,  &LD_L_HL,  &LD_L_A,
/* 7 */   &LD_HL_B,  &LD_HL_C,  &LD_HL_D, &LD_HL_E, &LD_HL_H, &LD_HL_L,    &UNDEF, &LD_HL_A,     &UNDEF,     &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_A_HL,   &UNDEF,
/* 8 */   &ADD_A_B,  &ADD_A_C,  &ADD_A_D, &ADD_A_E, &ADD_A_H, &ADD_A_L, &ADD_A_HL, &ADD_A_A,   &ADC_A_B,   &ADC_A_C,  &ADC_A_D, &ADC_A_E, &ADC_A_H, &ADC_A_L, &ADC_A_HL, &ADC_A_A,
/* 9 */   &SUB_A_B,  &SUB_A_C,  &SUB_A_D, &SUB_A_E, &SUB_A_H, &SUB_A_L, &SUB_A_HL, &SUB_A_A,   &SBC_A_B,   &SBC_A_C,  &SBC_A_D, &SBC_A_E, &SBC_A_H, &SBC_A_L, &SBC_A_HL, &SBC_A_A,
/* a */   &AND_A_B,  &AND_A_C,  &AND_A_D, &AND_A_E, &AND_A_H, &AND_A_L, &AND_A_HL, &AND_A_A,   &XOR_A_B,   &XOR_A_C,  &XOR_A_D, &XOR_A_E, &XOR_A_H, &XOR_A_L, &XOR_A_HL, &XOR_A_A,
/* b */    &OR_A_B,   &OR_A_C,   &OR_A_D,  &OR_A_E,  &OR_A_H,  &OR_A_L,  &OR_A_HL,  &OR_A_A,    &CP_A_B,    &CP_A_C,   &CP_A_D,  &CP_A_E,  &CP_A_H,  &CP_A_L,  &CP_A_HL,  &CP_A_A,
/* c */     &UNDEF,   &POP_BC,    &UNDEF,   &UNDEF,   &UNDEF, &PUSH_BC,  &ADD_A_n,   &UNDEF,     &UNDEF,     &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &ADC_A_n,   &UNDEF,
/* d */     &UNDEF,   &POP_DE,    &UNDEF,   &UNDEF,   &UNDEF, &PUSH_DE,  &SUB_A_n,   &UNDEF,     &UNDEF,     &UNDEF,    &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &SBC_A_n,   &UNDEF,
/* e */   &LDH_n_A,   &POP_HL,  &LDH_C_A,   &UNDEF,   &UNDEF, &PUSH_HL,  &AND_A_n,   &UNDEF, &ADD_SP_nn,     &UNDEF,  &LD_nn_A,   &UNDEF,   &UNDEF,   &UNDEF,  &XOR_A_n,   &UNDEF,
/* f */   &LDH_A_n,   &POP_AF,  &LDH_A_C,   &UNDEF,   &UNDEF, &PUSH_AF,   &OR_A_n,   &UNDEF,     &UNDEF,  &LD_SP_HL,  &LD_A_nn,   &UNDEF,   &UNDEF,   &UNDEF,   &CP_A_n,   &UNDEF,
};

#endif
