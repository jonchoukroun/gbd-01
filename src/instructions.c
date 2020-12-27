#include <stdio.h>
#include "instructions.h"

// LD r, r*
void LD_B_A(CPU *cpu)
{
    cpu->registers.B = cpu->registers.A;
    cpu->t_cycles = 4;
}

void LD_B_B(CPU *cpu)
{
    cpu->registers.B = cpu->registers.B;
    cpu->t_cycles = 4;
}

void LD_B_C(CPU *cpu)
{
    cpu->registers.B = cpu->registers.C;
    cpu->t_cycles = 4;
}

void LD_B_D(CPU *cpu)
{
    cpu->registers.B = cpu->registers.D;
    cpu->t_cycles = 4;
}

void LD_B_E(CPU *cpu)
{
    cpu->registers.B = cpu->registers.E;
    cpu->t_cycles = 4;
}

void LD_B_H(CPU *cpu)
{
    cpu->registers.B = cpu->registers.H;
    cpu->t_cycles = 4;
}

void LD_B_L(CPU *cpu)
{
    cpu->registers.B = cpu->registers.L;
    cpu->t_cycles = 4;
}

void LD_C_A(CPU *cpu)
{
    cpu->registers.C = cpu->registers.A;
    cpu->t_cycles = 4;
}

void LD_C_B(CPU *cpu)
{
    cpu->registers.C = cpu->registers.B;
    cpu->t_cycles = 4;
}

void LD_C_C(CPU *cpu)
{
    cpu->registers.C = cpu->registers.C;
    cpu->t_cycles = 4;
}

void LD_C_D(CPU *cpu)
{
    cpu->registers.C = cpu->registers.D;
    cpu->t_cycles = 4;
}

void LD_C_E(CPU *cpu)
{
    cpu->registers.C = cpu->registers.E;
    cpu->t_cycles = 4;
}

void LD_C_H(CPU *cpu)
{
    cpu->registers.C = cpu->registers.H;
    cpu->t_cycles = 4;
}

void LD_C_L(CPU *cpu)
{
    cpu->registers.C = cpu->registers.L;
    cpu->t_cycles = 4;
}

void LD_D_A(CPU *cpu)
{
    cpu->registers.D = cpu->registers.A;
    cpu->t_cycles = 4;
}

void LD_D_B(CPU *cpu)
{
    cpu->registers.D = cpu->registers.B;
    cpu->t_cycles = 4;
}

void LD_D_C(CPU *cpu)
{
    cpu->registers.D = cpu->registers.C;
    cpu->t_cycles = 4;
}

void LD_D_D(CPU *cpu)
{
    cpu->registers.D = cpu->registers.D;
    cpu->t_cycles = 4;
}

void LD_D_E(CPU *cpu)
{
    cpu->registers.D = cpu->registers.E;
    cpu->t_cycles = 4;
}

void LD_D_H(CPU *cpu)
{
    cpu->registers.D = cpu->registers.H;
    cpu->t_cycles = 4;
}

void LD_D_L(CPU *cpu)
{
    cpu->registers.D = cpu->registers.L;
    cpu->t_cycles = 4;
}

void LD_E_A(CPU *cpu)
{
    cpu->registers.E = cpu->registers.A;
    cpu->t_cycles = 4;
}

void LD_E_B(CPU *cpu)
{
    cpu->registers.E = cpu->registers.B;
    cpu->t_cycles = 4;
}

void LD_E_C(CPU *cpu)
{
    cpu->registers.E = cpu->registers.C;
    cpu->t_cycles = 4;
}

void LD_E_D(CPU *cpu)
{
    cpu->registers.E = cpu->registers.D;
    cpu->t_cycles = 4;
}

void LD_E_E(CPU *cpu)
{
    cpu->registers.E = cpu->registers.E;
    cpu->t_cycles = 4;
}

void LD_E_H(CPU *cpu)
{
    cpu->registers.E = cpu->registers.H;
    cpu->t_cycles = 4;
}

void LD_E_L(CPU *cpu)
{
    cpu->registers.E = cpu->registers.L;
    cpu->t_cycles = 4;
}

void LD_H_A(CPU *cpu)
{
    cpu->registers.H = cpu->registers.A;
    cpu->t_cycles = 4;
}

void LD_H_B(CPU *cpu)
{
    cpu->registers.H = cpu->registers.B;
    cpu->t_cycles = 4;
}

void LD_H_C(CPU *cpu)
{
    cpu->registers.H = cpu->registers.C;
    cpu->t_cycles = 4;
}

void LD_H_D(CPU *cpu)
{
    cpu->registers.H = cpu->registers.D;
    cpu->t_cycles = 4;
}

void LD_H_E(CPU *cpu)
{
    cpu->registers.H = cpu->registers.E;
    cpu->t_cycles = 4;
}

void LD_H_H(CPU *cpu)
{
    cpu->registers.H = cpu->registers.H;
    cpu->t_cycles = 4;
}

void LD_H_L(CPU *cpu)
{
    cpu->registers.H = cpu->registers.L;
    cpu->t_cycles = 4;
}

void LD_L_A(CPU *cpu)
{
    cpu->registers.L = cpu->registers.A;
    cpu->t_cycles = 4;
}

void LD_L_B(CPU *cpu)
{
    cpu->registers.L = cpu->registers.B;
    cpu->t_cycles = 4;
}

void LD_L_C(CPU *cpu)
{
    cpu->registers.L = cpu->registers.C;
    cpu->t_cycles = 4;
}

void LD_L_D(CPU *cpu)
{
    cpu->registers.L = cpu->registers.D;
    cpu->t_cycles = 4;
}

void LD_L_E(CPU *cpu)
{
    cpu->registers.L = cpu->registers.E;
    cpu->t_cycles = 4;
}

void LD_L_H(CPU *cpu)
{
    cpu->registers.L = cpu->registers.H;
    cpu->t_cycles = 4;
}

void LD_L_L(CPU *cpu)
{
    cpu->registers.L = cpu->registers.L;
    cpu->t_cycles = 4;
}

// LD r, n
void LD_A_n(CPU *cpu)
{
    uint8_t n = cpu->memory[cpu->PC - 1];
    cpu->registers.A = n;
    cpu->t_cycles = 8;
}

void LD_B_n(CPU *cpu)
{
    uint8_t n = cpu->memory[cpu->PC - 1];
    cpu->registers.B = n;
    cpu->t_cycles = 8;
}

void LD_C_n(CPU *cpu)
{
    uint8_t n = cpu->memory[cpu->PC - 1];
    cpu->registers.C = n;
    cpu->t_cycles = 8;
}

void LD_D_n(CPU *cpu)
{
    uint8_t n = cpu->memory[cpu->PC - 1];
    cpu->registers.D = n;
    cpu->t_cycles = 8;
}

void LD_E_n(CPU *cpu)
{
    uint8_t n = cpu->memory[cpu->PC - 1];
    cpu->registers.E = n;
    cpu->t_cycles = 8;
}

void LD_H_n(CPU *cpu)
{
    uint8_t n = cpu->memory[cpu->PC - 1];
    cpu->registers.H = n;
    cpu->t_cycles = 8;
}

void LD_L_n(CPU *cpu)
{
    uint8_t n = cpu->memory[cpu->PC - 1];
    cpu->registers.L = n;
    cpu->t_cycles = 8;
}

void LD_A_HL(CPU *cpu)
{
    cpu->registers.A = cpu->memory[cpu->registers.HL];
    cpu->t_cycles = 8;
}

void LD_B_HL(CPU *cpu)
{
    cpu->registers.B = cpu->memory[cpu->registers.HL];
    cpu->t_cycles = 8;
}

void LD_C_HL(CPU *cpu)
{
    cpu->registers.C = cpu->memory[cpu->registers.HL];
    cpu->t_cycles = 8;
}

void LD_D_HL(CPU *cpu)
{
    cpu->registers.D = cpu->memory[cpu->registers.HL];
    cpu->t_cycles = 8;
}

void LD_E_HL(CPU *cpu)
{
    cpu->registers.E = cpu->memory[cpu->registers.HL];
    cpu->t_cycles = 8;
}

void LD_H_HL(CPU *cpu)
{
    cpu->registers.H = cpu->memory[cpu->registers.HL];
    cpu->t_cycles = 8;
}

void LD_L_HL(CPU *cpu)
{
    cpu->registers.L = cpu->memory[cpu->registers.HL];
    cpu->t_cycles = 8;
}

// LD (HL), r
void LD_HL_A(CPU *cpu)
{
    cpu->memory[cpu->registers.HL] = cpu->registers.A;
    cpu->t_cycles = 8;
}

void LD_HL_B(CPU *cpu)
{
    cpu->memory[cpu->registers.HL] = cpu->registers.B;
    cpu->t_cycles = 8;
}

void LD_HL_C(CPU *cpu)
{
    cpu->memory[cpu->registers.HL] = cpu->registers.C;
    cpu->t_cycles = 8;
}

void LD_HL_D(CPU *cpu)
{
    cpu->memory[cpu->registers.HL] = cpu->registers.D;
    cpu->t_cycles = 8;
}

void LD_HL_E(CPU *cpu)
{
    cpu->memory[cpu->registers.HL] = cpu->registers.E;
    cpu->t_cycles = 8;
}

void LD_HL_H(CPU *cpu)
{
    cpu->memory[cpu->registers.HL] = cpu->registers.H;
    cpu->t_cycles = 8;
}

void LD_HL_L(CPU *cpu)
{
    cpu->memory[cpu->registers.HL] = cpu->registers.L;
    cpu->t_cycles = 8;
}

void LD_HL_n(CPU *cpu)
{
    cpu->memory[cpu->registers.HL] = cpu->memory[cpu->PC - 1];
    cpu->t_cycles = 12;
}

void UNDEF(CPU *cpu)
{
    printf("Opcode instruction undefined (%x)\n", cpu->memory[cpu->PC--]);
}
