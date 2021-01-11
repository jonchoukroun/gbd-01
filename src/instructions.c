#include <stdio.h>
#include <limits.h>
#include "instructions.h"

// *************************************
// 8-bit Arithmetic/Logical Instructions
// *************************************

void add_A_8(CPU *cpu, uint16_t value)
{
    uint8_t A = cpu->registers.A;
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (((A + value) & 0xff) == 0) set_flag(cpu, Z_FLAG);
    if ((A & 0xf) + (value & 0xf) > 0xf) set_flag(cpu, H_FLAG);
    if (0xff - A <= value) set_flag(cpu, C_FLAG);

    cpu->registers.A += value;
}

// ADD A, r8
void ADD_A_A(CPU *cpu)
{
    add_A_8(cpu, cpu->registers.A);
    cpu->t_cycles = 4;
}

void ADD_A_B(CPU *cpu)
{
    add_A_8(cpu, cpu->registers.B);
    cpu->t_cycles = 4;
}

void ADD_A_C(CPU *cpu)
{
    add_A_8(cpu, cpu->registers.C);
    cpu->t_cycles = 4;
}

void ADD_A_D(CPU *cpu)
{
    add_A_8(cpu, cpu->registers.D);
    cpu->t_cycles = 4;
}

void ADD_A_E(CPU *cpu)
{
    add_A_8(cpu, cpu->registers.E);
    cpu->t_cycles = 4;
}

void ADD_A_H(CPU *cpu)
{
    add_A_8(cpu, cpu->registers.H);
    cpu->t_cycles = 4;
}

void ADD_A_L(CPU *cpu)
{
    add_A_8(cpu, cpu->registers.L);
    cpu->t_cycles = 4;
}

void ADD_A_HL(CPU *cpu)
{
    add_A_8(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

void ADD_A_n(CPU *cpu)
{
    add_A_8(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

// ADC A, r8
void ADC_A_A(CPU *cpu)
{
    uint16_t value = cpu->registers.A + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_B(CPU *cpu)
{
    uint16_t value = cpu->registers.B + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_C(CPU *cpu)
{
    uint16_t value = cpu->registers.C + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_D(CPU *cpu)
{
    uint16_t value = cpu->registers.D + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_E(CPU *cpu)
{
    uint16_t value = cpu->registers.E + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_H(CPU *cpu)
{
    uint16_t value = cpu->registers.H + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_L(CPU *cpu)
{
    uint16_t value = cpu->registers.L + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_HL(CPU *cpu)
{
    uint16_t value = read_byte(cpu, cpu->registers.HL) + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 8;
}

void ADC_A_n(CPU *cpu)
{
    uint8_t value = fetch_opcode(cpu) + get_flag(cpu, C_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 8;
}

// SUB A, r8
void sub_A_8(CPU *cpu, uint8_t r)
{
    clear_flag(cpu, Z_FLAG);
    set_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if ((r & 0xf) > (cpu->registers.A & 0xf)) set_flag(cpu, H_FLAG);
    if (r > cpu->registers.A) set_flag(cpu, C_FLAG);

    cpu->registers.A -= r;

    if (cpu->registers.A == 0) set_flag(cpu, Z_FLAG);
}

void SUB_A_A(CPU *cpu)
{
    sub_A_8(cpu, cpu->registers.A);
    cpu->t_cycles = 4;
}

void SUB_A_B(CPU *cpu)
{
    sub_A_8(cpu, cpu->registers.B);
    cpu->t_cycles = 4;
}

void SUB_A_C(CPU *cpu)
{
    sub_A_8(cpu, cpu->registers.C);
    cpu->t_cycles = 4;
}

void SUB_A_D(CPU *cpu)
{
    sub_A_8(cpu, cpu->registers.D);
    cpu->t_cycles = 4;
}

void SUB_A_E(CPU *cpu)
{
    sub_A_8(cpu, cpu->registers.E);
    cpu->t_cycles = 4;
}

void SUB_A_H(CPU *cpu)
{
    sub_A_8(cpu, cpu->registers.H);
    cpu->t_cycles = 4;
}

void SUB_A_L(CPU *cpu)
{
    sub_A_8(cpu, cpu->registers.L);
    cpu->t_cycles = 4;
}

void SUB_A_n(CPU *cpu)
{
    sub_A_8(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void SUB_A_HL(CPU *cpu)
{
    sub_A_8(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

void SBC_A_A(CPU *cpu)
{
    uint8_t value = cpu->registers.A + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void SBC_A_B(CPU *cpu)
{
    uint8_t value = cpu->registers.B + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void SBC_A_C(CPU *cpu)
{
    uint8_t value = cpu->registers.C + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void SBC_A_D(CPU *cpu)
{
    uint8_t value = cpu->registers.D + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void SBC_A_E(CPU *cpu)
{
    uint8_t value = cpu->registers.E + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void SBC_A_H(CPU *cpu)
{
    uint8_t value = cpu->registers.H + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void SBC_A_L(CPU *cpu)
{
    uint8_t value = cpu->registers.L + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void SBC_A_n(CPU *cpu)
{
    uint8_t value = fetch_opcode(cpu) + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 8;
}

void SBC_A_HL(CPU *cpu)
{
    uint8_t value = read_byte(cpu, cpu->registers.HL) + get_flag(cpu, C_FLAG);
    sub_A_8(cpu, value);
    cpu->t_cycles = 8;
}

// AND A, r8
void AND_A_8(CPU *cpu, uint8_t r)
{
    cpu->registers.A &= r;
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    set_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);
    if (cpu->registers.A == 0) set_flag(cpu, Z_FLAG);
}

void AND_A_A(CPU *cpu)
{
    AND_A_8(cpu, cpu->registers.A);
    cpu->t_cycles = 4;
}

void AND_A_B(CPU *cpu)
{
    AND_A_8(cpu, cpu->registers.B);
    cpu->t_cycles = 4;
}

void AND_A_C(CPU *cpu)
{
    AND_A_8(cpu, cpu->registers.C);
    cpu->t_cycles = 4;
}

void AND_A_D(CPU *cpu)
{
    AND_A_8(cpu, cpu->registers.D);
    cpu->t_cycles = 4;
}

void AND_A_E(CPU *cpu)
{
    AND_A_8(cpu, cpu->registers.E);
    cpu->t_cycles = 4;
}

void AND_A_H(CPU *cpu)
{
    AND_A_8(cpu, cpu->registers.H);
    cpu->t_cycles = 4;
}

void AND_A_L(CPU *cpu)
{
    AND_A_8(cpu, cpu->registers.L);
    cpu->t_cycles = 4;
}

void AND_A_n(CPU *cpu)
{
    AND_A_8(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void AND_A_HL(CPU *cpu)
{
    AND_A_8(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

// XOR A, r8

void XOR_A_8(CPU *cpu, uint8_t r)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    cpu->registers.A ^= r;
    if (cpu->registers.A == 0) set_flag(cpu, Z_FLAG);
}

void XOR_A_A(CPU *cpu)
{
    XOR_A_8(cpu, cpu->registers.A);
    cpu->t_cycles = 4;
}

void XOR_A_B(CPU *cpu)
{
    XOR_A_8(cpu, cpu->registers.B);
    cpu->t_cycles = 4;
}

void XOR_A_C(CPU *cpu)
{
    XOR_A_8(cpu, cpu->registers.C);
    cpu->t_cycles = 4;
}

void XOR_A_D(CPU *cpu)
{
    XOR_A_8(cpu, cpu->registers.D);
    cpu->t_cycles = 4;
}

void XOR_A_E(CPU *cpu)
{
    XOR_A_8(cpu, cpu->registers.E);
    cpu->t_cycles = 4;
}

void XOR_A_H(CPU *cpu)
{
    XOR_A_8(cpu, cpu->registers.H);
    cpu->t_cycles = 4;
}

void XOR_A_L(CPU *cpu)
{
    XOR_A_8(cpu, cpu->registers.L);
    cpu->t_cycles = 4;
}

void XOR_A_n(CPU *cpu)
{
    XOR_A_8(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void XOR_A_HL(CPU *cpu)
{
    XOR_A_8(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

// OR A, r8
void or_A_8(CPU *cpu, uint8_t r)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    cpu->registers.A |= r;
    if (cpu->registers.A == 0) set_flag(cpu, Z_FLAG);
}

void OR_A_A(CPU *cpu)
{
    or_A_8(cpu, cpu->registers.A);
    cpu->t_cycles = 4;
}

void OR_A_B(CPU *cpu)
{
    or_A_8(cpu, cpu->registers.B);
    cpu->t_cycles = 4;
}

void OR_A_C(CPU *cpu)
{
    or_A_8(cpu, cpu->registers.C);
    cpu->t_cycles = 4;
}

void OR_A_D(CPU *cpu)
{
    or_A_8(cpu, cpu->registers.D);
    cpu->t_cycles = 4;
}

void OR_A_E(CPU *cpu)
{
    or_A_8(cpu, cpu->registers.E);
    cpu->t_cycles = 4;
}

void OR_A_H(CPU *cpu)
{
    or_A_8(cpu, cpu->registers.H);
    cpu->t_cycles = 4;
}

void OR_A_L(CPU *cpu)
{
    or_A_8(cpu, cpu->registers.L);
    cpu->t_cycles = 4;
}

void OR_A_n(CPU *cpu)
{
    or_A_8(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void OR_A_HL(CPU *cpu)
{
    or_A_8(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

void cp_A_8(CPU *cpu, uint8_t r)
{
    clear_flag(cpu, Z_FLAG);
    set_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if ((r & 0xf) > (cpu->registers.A & 0xf)) set_flag(cpu, H_FLAG);
    if (r > cpu->registers.A) set_flag(cpu, C_FLAG);
    if (cpu->registers.A == r) set_flag(cpu, Z_FLAG);
}

// CP A, r8
void CP_A_A(CPU *cpu)
{
    cp_A_8(cpu, cpu->registers.A);
    cpu->t_cycles = 4;
}

void CP_A_B(CPU *cpu)
{
    cp_A_8(cpu, cpu->registers.B);
    cpu->t_cycles = 4;
}

void CP_A_C(CPU *cpu)
{
    cp_A_8(cpu, cpu->registers.C);
    cpu->t_cycles = 4;
}

void CP_A_D(CPU *cpu)
{
    cp_A_8(cpu, cpu->registers.D);
    cpu->t_cycles = 4;
}

void CP_A_E(CPU *cpu)
{
    cp_A_8(cpu, cpu->registers.E);
    cpu->t_cycles = 4;
}

void CP_A_H(CPU *cpu)
{
    cp_A_8(cpu, cpu->registers.H);
    cpu->t_cycles = 4;
}

void CP_A_L(CPU *cpu)
{
    cp_A_8(cpu, cpu->registers.L);
    cpu->t_cycles = 4;
}

void CP_A_n(CPU *cpu)
{
    cp_A_8(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void CP_A_HL(CPU *cpu)
{
    cp_A_8(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

// INC r
void handle_INC_flags(CPU *cpu, uint8_t value)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);

    if (value == 0xff) set_flag(cpu, Z_FLAG);
    if ((value & 0xf) == 0xf) set_flag(cpu, H_FLAG);
}

void INC_A(CPU *cpu)
{
    handle_INC_flags(cpu, cpu->registers.A);
    cpu->registers.A++;
    cpu->t_cycles = 4;
}

void INC_B(CPU *cpu)
{
    handle_INC_flags(cpu, cpu->registers.B);
    cpu->registers.B++;
    cpu->t_cycles = 4;
}

void INC_C(CPU *cpu)
{
    handle_INC_flags(cpu, cpu->registers.C);
    cpu->registers.C++;
    cpu->t_cycles = 4;
}

void INC_D(CPU *cpu)
{
    handle_INC_flags(cpu, cpu->registers.D);
    cpu->registers.D++;
    cpu->t_cycles = 4;
}

void INC_E(CPU *cpu)
{
    handle_INC_flags(cpu, cpu->registers.E);
    cpu->registers.E++;
    cpu->t_cycles = 4;
}

void INC_H(CPU *cpu)
{
    handle_INC_flags(cpu, cpu->registers.H);
    cpu->registers.H++;
    cpu->t_cycles = 4;
}

void INC_L(CPU *cpu)
{
    handle_INC_flags(cpu, cpu->registers.L);
    cpu->registers.L++;
    cpu->t_cycles = 4;
}

void INC_nHL(CPU *cpu)
{
    handle_INC_flags(cpu, cpu->memory[cpu->registers.HL]);
    cpu->memory[cpu->registers.HL]++;
    cpu->t_cycles = 12;
}

// DEC r
void handle_DEC_flags(CPU *cpu, uint8_t value)
{
    clear_flag(cpu, Z_FLAG);
    set_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);

    if (value == 0x1) set_flag(cpu, Z_FLAG);
    if ((value & 0xf) == 0) set_flag(cpu, H_FLAG);
}

void DEC_A(CPU *cpu)
{
    handle_DEC_flags(cpu, cpu->registers.A);
    cpu->registers.A--;
    cpu->t_cycles = 4;
}

void DEC_B(CPU *cpu)
{
    handle_DEC_flags(cpu, cpu->registers.B);
    cpu->registers.B--;
    cpu->t_cycles = 4;
}

void DEC_C(CPU *cpu)
{
    handle_DEC_flags(cpu, cpu->registers.C);
    cpu->registers.C--;
    cpu->t_cycles = 4;
}

void DEC_D(CPU *cpu)
{
    handle_DEC_flags(cpu, cpu->registers.D);
    cpu->registers.D--;
    cpu->t_cycles = 4;
}

void DEC_E(CPU *cpu)
{
    handle_DEC_flags(cpu, cpu->registers.E);
    cpu->registers.E--;
    cpu->t_cycles = 4;
}

void DEC_H(CPU *cpu)
{
    handle_DEC_flags(cpu, cpu->registers.H);
    cpu->registers.H--;
    cpu->t_cycles = 4;
}

void DEC_L(CPU *cpu)
{
    handle_DEC_flags(cpu, cpu->registers.L);
    cpu->registers.L--;
    cpu->t_cycles = 4;
}

void DEC_nHL(CPU *cpu)
{
    handle_DEC_flags(cpu, cpu->memory[cpu->registers.HL]);
    cpu->memory[cpu->registers.HL]--;
    cpu->t_cycles = 12;
}


// **************************************
// 16-bit Arithmetic/Logical Instructions
// **************************************

void add_HL_16(CPU *cpu, uint16_t value)
{
    uint16_t HL = cpu->registers.HL;
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if ((HL & 0xf00) + (value & 0xf00) > 0x400) set_flag(cpu, H_FLAG);
    if (0xffff - HL <= value) set_flag(cpu, C_FLAG);

    cpu->registers.HL += value;
}

// ADD HL, r16
void ADD_HL_BC(CPU *cpu)
{
    add_HL_16(cpu, cpu->registers.BC);
    cpu->t_cycles = 8;
}

void ADD_HL_DE(CPU *cpu)
{
    add_HL_16(cpu, cpu->registers.DE);
    cpu->t_cycles = 8;
}

void ADD_HL_HL(CPU *cpu)
{
    add_HL_16(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void ADD_HL_SP(CPU *cpu)
{
    add_HL_16(cpu, cpu->SP);
    cpu->t_cycles = 8;
}

void ADD_SP_e(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    uint8_t n = fetch_opcode(cpu);
    if (0b10000000 & n) {
        n = (~n) + 1;
        if ((cpu->SP & 0xf) < (n & 0xf)) set_flag(cpu, H_FLAG);
        if ((cpu->SP & 0xff) < n) set_flag(cpu, C_FLAG);

        cpu->SP -= n;
    } else {
        if ((cpu->SP & 0xf) + (n & 0xf) > 0xf) set_flag(cpu, H_FLAG);
        if ((cpu->SP & 0xff) + n > 0xff) set_flag(cpu, C_FLAG);

        cpu->SP += n;
    }

    cpu->t_cycles = 16;
}

// INC rr
void INC_BC(CPU *cpu)
{
    cpu->registers.BC++;
    cpu->t_cycles = 8;
}

void INC_DE(CPU *cpu)
{
    cpu->registers.DE++;
    cpu->t_cycles = 8;
}

void INC_HL(CPU *cpu)
{
    cpu->registers.HL++;
    cpu->t_cycles = 8;
}

void INC_SP(CPU *cpu)
{
    cpu->SP++;
    cpu->t_cycles = 8;
}

// DEC rr
void DEC_BC(CPU *cpu)
{
    cpu->registers.BC--;
    cpu->t_cycles = 8;
}

void DEC_DE(CPU *cpu)
{
    cpu->registers.DE--;
    cpu->t_cycles = 8;
}

void DEC_HL(CPU *cpu)
{
    cpu->registers.HL--;
    cpu->t_cycles = 8;
}

void DEC_SP(CPU *cpu)
{
    cpu->SP--;
    cpu->t_cycles = 8;
}


// ***********************
// 8-bit Load Instructions
// ***********************

// LD r, r*: load 2nd register's value into 1st
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

// LD r, n: Load byte from next PC into register
void LD_A_n(CPU *cpu)
{
    cpu->registers.A = fetch_opcode(cpu);
    cpu->t_cycles = 8;
}

void LD_B_n(CPU *cpu)
{
    cpu->registers.B = fetch_opcode(cpu);
    cpu->t_cycles = 8;
}

void LD_C_n(CPU *cpu)
{
    cpu->registers.C = fetch_opcode(cpu);
    cpu->t_cycles = 8;
}

void LD_D_n(CPU *cpu)
{
    cpu->registers.D = fetch_opcode(cpu);
    cpu->t_cycles = 8;
}

void LD_E_n(CPU *cpu)
{
    cpu->registers.E = fetch_opcode(cpu);
    cpu->t_cycles = 8;
}

void LD_H_n(CPU *cpu)
{
    cpu->registers.H = fetch_opcode(cpu);
    cpu->t_cycles = 8;
}

void LD_L_n(CPU *cpu)
{
    cpu->registers.L = fetch_opcode(cpu);
    cpu->t_cycles = 8;
}

// LD r, (HL): Load value in memory at address in HL into register
void LD_A_HL(CPU *cpu)
{
    cpu->registers.A = read_byte(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_B_HL(CPU *cpu)
{
    cpu->registers.B = read_byte(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_C_HL(CPU *cpu)
{
    cpu->registers.C = read_byte(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_D_HL(CPU *cpu)
{
    cpu->registers.D = read_byte(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_E_HL(CPU *cpu)
{
    cpu->registers.E = read_byte(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_H_HL(CPU *cpu)
{
    cpu->registers.H = read_byte(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_L_HL(CPU *cpu)
{
    cpu->registers.L = read_byte(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

// LD (HL), r: Write value in register to byte at address pointed to by register HL
void LD_HL_A(CPU *cpu)
{
    write_byte(cpu, cpu->registers.A, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_HL_B(CPU *cpu)
{
    write_byte(cpu, cpu->registers.B, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_HL_C(CPU *cpu)
{
    write_byte(cpu, cpu->registers.C, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_HL_D(CPU *cpu)
{
    write_byte(cpu, cpu->registers.D, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_HL_E(CPU *cpu)
{
    write_byte(cpu, cpu->registers.E, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_HL_H(CPU *cpu)
{
    write_byte(cpu, cpu->registers.H, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_HL_L(CPU *cpu)
{
    write_byte(cpu, cpu->registers.L, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_HL_n(CPU *cpu)
{
    uint8_t byte = fetch_opcode(cpu);
    write_byte(cpu, byte, cpu->registers.HL);
    cpu->t_cycles = 12;
}

void LD_A_BC(CPU *cpu)
{
    cpu->registers.A = read_byte(cpu, cpu->registers.BC);
    cpu->t_cycles = 8;
}

void LD_A_DE(CPU *cpu)
{
    cpu->registers.A = read_byte(cpu, cpu->registers.DE);
    cpu->t_cycles = 8;
}

void LD_BC_A(CPU *cpu)
{
    write_byte(cpu, cpu->registers.A, cpu->registers.BC);
    cpu->t_cycles = 8;
}

void LD_DE_A(CPU *cpu)
{
    write_byte(cpu, cpu->registers.A, cpu->registers.DE);
    cpu->t_cycles = 8;
}

void LD_A_nn(CPU *cpu)
{
    uint16_t address = (fetch_opcode(cpu) << 8) | fetch_opcode(cpu);
    cpu->registers.A = read_byte(cpu, address);
    cpu->t_cycles = 16;
}

void LD_nn_A(CPU *cpu)
{
    uint16_t address = (fetch_opcode(cpu) << 8) | fetch_opcode(cpu);
    write_byte(cpu, cpu->registers.A, address);
    cpu->t_cycles = 16;
}

void LDH_A_C(CPU *cpu)
{
    uint16_t address = (0xff << 8) | cpu->registers.C;
    cpu->registers.A = cpu->memory[address];
    cpu->t_cycles = 8;
}

void LDH_C_A(CPU *cpu)
{
    uint16_t address = (0xff << 8) | cpu->registers.C;
    write_byte(cpu, cpu->registers.A, address);
    cpu->t_cycles = 8;
}

void LDH_A_n(CPU *cpu)
{
    uint16_t address = (0xff << 8) | fetch_opcode(cpu);
    cpu->registers.A = cpu->memory[address];
    cpu->t_cycles = 12;
}

void LDH_n_A(CPU *cpu)
{
    uint16_t address = (0xff << 8) | fetch_opcode(cpu);
    write_byte(cpu, cpu->registers.A, address);
    cpu->t_cycles = 12;
}

void LD_A_HLI(CPU *cpu)
{
    cpu->registers.A = read_byte(cpu, cpu->registers.HL);
    cpu->registers.HL++;
    cpu->t_cycles = 8;
}

void LD_A_HLD(CPU *cpu)
{
    cpu->registers.A = read_byte(cpu, cpu->registers.HL);
    cpu->registers.HL--;
    cpu->t_cycles = 8;
}

void LD_HLI_A(CPU *cpu)
{
    write_byte(cpu, cpu->registers.A, cpu->registers.HL);
    cpu->registers.HL++;
    cpu->t_cycles = 8;
}

void LD_HLD_A(CPU *cpu)
{
    write_byte(cpu, cpu->registers.A, cpu->registers.HL);
    cpu->registers.HL--;
    cpu->t_cycles = 8;
}


// ************************
// 16-bit Load Instructions
// ************************

// LD rr, nn
void LD_BC_nn(CPU *cpu)
{
    cpu->registers.BC = fetch_opcode(cpu) << 8 | fetch_opcode(cpu);
    cpu->t_cycles = 12;
}

void LD_DE_nn(CPU *cpu)
{
    cpu->registers.DE = fetch_opcode(cpu) << 8 | fetch_opcode(cpu);
    cpu->t_cycles = 12;
}

void LD_HL_nn(CPU *cpu)
{
    cpu->registers.HL = fetch_opcode(cpu) << 8 | fetch_opcode(cpu);
    cpu->t_cycles = 12;
}

void LD_nn_SP(CPU *cpu)
{
    uint16_t address = fetch_opcode(cpu) << 8 | fetch_opcode(cpu);
    write_word(cpu, cpu->SP, address);
    cpu->t_cycles = 20;
}

void LD_SP_HL(CPU *cpu)
{
    cpu->SP = cpu->registers.HL;
    cpu->t_cycles = 8;
}

void LD_HL_SPe(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    uint8_t n = fetch_opcode(cpu);
    uint16_t result;
    if ((0b10000000 & n) != 0) {
        n = (~n) + 1;
        if ((cpu->SP & 0xf) < (n & 0xf)) set_flag(cpu, H_FLAG);
        if ((cpu->SP & 0xff) < n) set_flag(cpu, C_FLAG);
        result = cpu->SP - n;
    } else {
        if ((cpu->SP & 0xf) + (n & 0xf) > 0xf) set_flag(cpu, H_FLAG);
        if ((cpu->SP & 0x00ff) + n > 0xff) set_flag(cpu, C_FLAG);
        result = cpu->SP + n;
    }

    cpu->registers.HL = result;
    cpu->t_cycles = 12;
}

// PUSH rr
void PUSH_AF(CPU *cpu)
{
    cpu->SP--;
    cpu->memory[cpu->SP] = cpu->registers.F;
    cpu->SP--;
    cpu->memory[cpu->SP] = cpu->registers.A;
    cpu->t_cycles = 16;
}

void PUSH_BC(CPU *cpu)
{
    cpu->SP--;
    cpu->memory[cpu->SP] = cpu->registers.C;
    cpu->SP--;
    cpu->memory[cpu->SP] = cpu->registers.B;
    cpu->t_cycles = 16;
}

void PUSH_DE(CPU *cpu)
{
    cpu->SP--;
    cpu->memory[cpu->SP] = cpu->registers.E;
    cpu->SP--;
    cpu->memory[cpu->SP] = cpu->registers.D;
    cpu->t_cycles = 16;
}

void PUSH_HL(CPU *cpu)
{
    cpu->SP--;
    cpu->memory[cpu->SP] = cpu->registers.L;
    cpu->SP--;
    cpu->memory[cpu->SP] = cpu->registers.H;
    cpu->t_cycles = 16;
}

void POP_AF(CPU *cpu)
{
    cpu->registers.A = cpu->memory[cpu->SP];
    cpu->SP++;
    cpu->registers.F = cpu->memory[cpu->SP];
    cpu->SP++;
    cpu->t_cycles = 12;
}

void POP_BC(CPU *cpu)
{
    cpu->registers.B = cpu->memory[cpu->SP];
    cpu->SP++;
    cpu->registers.C = cpu->memory[cpu->SP];
    cpu->SP++;
    cpu->t_cycles = 12;
}

void POP_DE(CPU *cpu)
{
    cpu->registers.D = cpu->memory[cpu->SP];
    cpu->SP++;
    cpu->registers.E = cpu->memory[cpu->SP];
    cpu->SP++;
    cpu->t_cycles = 12;
}

void POP_HL(CPU *cpu)
{
    cpu->registers.H = cpu->memory[cpu->SP];
    cpu->SP++;
    cpu->registers.L = cpu->memory[cpu->SP];
    cpu->SP++;
    cpu->t_cycles = 12;
}


// *************************
// Rotate Shift Instructions
// *************************
uint8_t rotate_left_carry(uint8_t n)
{
    return (n << 1) | (n >> 7);
}

uint8_t rotate_right_carry(uint8_t n)
{
    return (n >> 1) | (n << 7);
}

void RLCA(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.A & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.A = rotate_left_carry(cpu->registers.A);
    cpu->t_cycles = 4;
}

void RLA(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.A & 0b10000000) set_flag(cpu, C_FLAG);
    cpu->registers.A <<= 1;
    cpu->t_cycles = 4;
}

void RRCA(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.A & 1) set_flag(cpu, C_FLAG);

    cpu->registers.A = rotate_right_carry(cpu->registers.A);
    cpu->t_cycles = 4;
}

void RRA(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.A & 1) set_flag(cpu, C_FLAG);
    cpu->registers.A >>= 1;
    cpu->t_cycles = 4;
}

// RLC r
void RLC_A(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.A & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.A = rotate_left_carry(cpu->registers.A);
    if (cpu->registers.A == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RLC_B(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.B & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.B = rotate_left_carry(cpu->registers.B);
    if (cpu->registers.B == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RLC_C(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.C & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.C = rotate_left_carry(cpu->registers.C);
    if (cpu->registers.C == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RLC_D(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.D & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.D = rotate_left_carry(cpu->registers.D);
    if (cpu->registers.D == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RLC_E(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.E & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.E = rotate_left_carry(cpu->registers.E);
    if (cpu->registers.E == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RLC_H(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.H & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.H = rotate_left_carry(cpu->registers.H);
    if (cpu->registers.H == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RLC_L(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.L & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.L = rotate_left_carry(cpu->registers.L);
    if (cpu->registers.L == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RLC_HL(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & 0b10000000) set_flag(cpu, C_FLAG);

    write_byte(cpu, rotate_left_carry(byte), cpu->registers.HL);
    if (read_byte(cpu, cpu->registers.HL) == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 16;
}

void RL_A(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.A & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.A <<= 1;
    if (cpu->registers.A == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RL_B(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.B & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.B <<= 1;
    if (cpu->registers.B == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RL_C(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.C & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.C <<= 1;
    if (cpu->registers.C == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RL_D(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.D & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.D <<= 1;
    if (cpu->registers.D == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RL_E(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.E & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.E <<= 1;
    if (cpu->registers.E == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RL_H(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.H & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.H <<= 1;
    if (cpu->registers.H == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RL_L(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    if (cpu->registers.L & 0b10000000) set_flag(cpu, C_FLAG);

    cpu->registers.L <<= 1;
    if (cpu->registers.L == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 8;
}

void RL_HL(CPU *cpu)
{
    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);

    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & 0b10000000) set_flag(cpu, C_FLAG);

    write_byte(cpu, byte << 1, cpu->registers.HL);
    if (read_byte(cpu, cpu->registers.HL) == 0) set_flag(cpu, Z_FLAG);

    cpu->t_cycles = 16;
}


// *****************************
// Misc. Arithmetic Instructions
// *****************************

void DAA(CPU *cpu)
{
    uint8_t A = cpu->registers.A;
    uint8_t half_carry = get_flag(cpu, H_FLAG);
    uint8_t carry = get_flag(cpu, C_FLAG);

    if (get_flag(cpu, N_FLAG) == 0) {
        if (carry == 1 || A > 0x99) {
            cpu->registers.A += 0x60;
            set_flag(cpu, C_FLAG);
        }
        if (half_carry == 1 || (A & 0x0f) > 0x09) cpu->registers.A += 0x06;
    } else {
        if (carry == 1) cpu->registers.A -= 0x60;
        if (half_carry == 1) cpu->registers.A -= 0x06;
    }

    if (cpu->registers.A == 0) set_flag(cpu, Z_FLAG);
    clear_flag(cpu, H_FLAG);

    cpu->t_cycles = 4;
}

void CPL(CPU *cpu)
{
    cpu->registers.A = ~cpu->registers.A;
    set_flag(cpu, N_FLAG);
    set_flag(cpu, H_FLAG);

    cpu->t_cycles = 4;
}

void UNDEF(CPU *cpu)
{
    printf("Opcode instruction undefined (%x)\n", cpu->memory[cpu->PC--]);
}
