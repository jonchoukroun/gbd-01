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

void UNDEF(CPU *);

const OpcodeInstruction opcode_table[256] = {
/*           0x0     0x1     0x2     0x3     0x4     0x5      0x6     0x7     0x8     0x9     0xa     0xb     0xc     0xd      0xe     0xf */
/* 0 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &LD_B_n, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &LD_C_n, &UNDEF,
/* 1 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* 2 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* 3 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* 4 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* 5 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* 6 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* 7 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* 8 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* 9 */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* a */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* b */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* c */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* d */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* e */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
/* f */   &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF, &UNDEF,  &UNDEF, &UNDEF,
};

#endif
