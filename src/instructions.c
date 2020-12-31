#include <stdio.h>
#include "instructions.h"

void add_A_8(CPU *cpu, uint16_t value)
{
    uint8_t A = cpu->registers.A;
    toggle_zero_flag(cpu, (A + value) & 0xff);
    clear_flag(cpu, SUBTRACT_FLAG);
    toggle_hcarry_flag(cpu, A, value, BYTE);
    toggle_carry_flag(cpu, A + value, BYTE);

    cpu->registers.A += (value & 0xff);
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
    add_A_8(cpu, cpu->memory[cpu->registers.HL]);
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
    uint16_t value = cpu->registers.A + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_B(CPU *cpu)
{
    uint16_t value = cpu->registers.B + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_C(CPU *cpu)
{
    uint16_t value = cpu->registers.C + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_D(CPU *cpu)
{
    uint16_t value = cpu->registers.D + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_E(CPU *cpu)
{
    uint16_t value = cpu->registers.E + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_H(CPU *cpu)
{
    uint16_t value = cpu->registers.H + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_L(CPU *cpu)
{
    uint16_t value = cpu->registers.L + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 4;
}

void ADC_A_HL(CPU *cpu)
{
    uint16_t value = read_byte(cpu, cpu->registers.HL) + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 8;
}

void ADC_A_n(CPU *cpu)
{
    uint8_t value = fetch_opcode(cpu) + get_flag(cpu, CARRY_FLAG);
    add_A_8(cpu, value);
    cpu->t_cycles = 8;
}

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
void UNDEF(CPU *cpu)
{
    printf("Opcode instruction undefined (%x)\n", cpu->memory[cpu->PC--]);
}
