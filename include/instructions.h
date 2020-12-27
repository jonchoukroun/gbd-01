#ifndef Instructions
#define Instructions

#include "cpu.h"

typedef void (*OpcodeInstruction)(CPU *);

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

void UNDEF(CPU *);

static const OpcodeInstruction opcode_table[256] = {
/*             0x0       0x1       0x2       0x3       0x4       0x5       0x6       0x7      0x8      0x9      0xa      0xb      0xc      0xd       0xe      0xf */
/* 0 */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &LD_B_n,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &LD_C_n,  &UNDEF,
/* 1 */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* 2 */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* 3 */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF, &LD_HL_n,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* 4 */    &LD_B_B,  &LD_B_C,  &LD_B_D,  &LD_B_E,  &LD_B_H,  &LD_B_L, &LD_B_HL,  &LD_B_A, &LD_C_B, &LD_C_C, &LD_C_D, &LD_C_E, &LD_C_H, &LD_C_L, &LD_C_HL, &LD_C_A,
/* 5 */    &LD_D_B,  &LD_D_C,  &LD_D_D,  &LD_D_E,  &LD_D_H,  &LD_D_L, &LD_D_HL,  &LD_D_A, &LD_E_B, &LD_E_C, &LD_E_D, &LD_E_E, &LD_E_H, &LD_E_L, &LD_E_HL, &LD_E_A,
/* 6 */    &LD_H_B,  &LD_H_C,  &LD_H_D,  &LD_H_E,  &LD_H_H,  &LD_H_L, &LD_H_HL,  &LD_H_A, &LD_L_B, &LD_L_C, &LD_L_D, &LD_L_E, &LD_L_H, &LD_L_L, &LD_L_HL, &LD_L_A,
/* 7 */   &LD_HL_B, &LD_HL_C, &LD_HL_D, &LD_HL_E, &LD_HL_H, &LD_HL_L,   &UNDEF, &LD_HL_A,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF, &LD_A_HL,  &UNDEF,
/* 8 */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* 9 */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* a */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* b */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* c */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* d */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* e */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
/* f */     &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,   &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,  &UNDEF,   &UNDEF,  &UNDEF,
};

#endif
