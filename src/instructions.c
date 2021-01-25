#include <stdio.h>
#include <limits.h>
#include "instructions.h"

/**
 * Access register bitmaps directly
 **/
typedef enum {
    reg_B, reg_C, reg_D, reg_E,
    reg_H, reg_L, reg_HL, reg_A,
    reg_BC, reg_DE
} REGISTER_MAP;

/**
 * Return value in registers based on bit code from opcode
 **/
uint8_t fetch_r(CPU *cpu, uint8_t r)
{
    uint8_t registers[] = {
        cpu->registers.B,
        cpu->registers.C,
        cpu->registers.D,
        cpu->registers.E,
        cpu->registers.H,
        cpu->registers.L,
        0,
        cpu->registers.A,
    };

    return registers[r];
}

/**
 * Set values to 8-bit registers
 * and memory pointed to by address in HL.
 * Accessible as function pointers in bitmap below.
 **/
typedef void (*RegisterSet)(CPU *, uint8_t value);
void set_B(CPU *cpu, uint8_t n) { cpu->registers.B = n; }
void set_C(CPU *cpu, uint8_t n) { cpu->registers.C = n; }
void set_D(CPU *cpu, uint8_t n) { cpu->registers.D = n; }
void set_E(CPU *cpu, uint8_t n) { cpu->registers.E = n; }
void set_H(CPU *cpu, uint8_t n) { cpu->registers.H = n; }
void set_L(CPU *cpu, uint8_t n) { cpu->registers.L = n; }
void set_HL(CPU *cpu, uint8_t n) {
    write_byte(cpu, n, cpu->registers.HL);
    cpu->t_cycles += 4;
}
void set_A(CPU *cpu, uint8_t n) { cpu->registers.A = n; }

static const RegisterSet R_TABLE[8] = {
    &set_B, &set_C, &set_D, &set_E,
    &set_H, &set_L, &set_HL, &set_A
};

void LD_r_r(CPU *cpu, uint8_t opcode)
{
    uint8_t dest_code = ((opcode & 0b00111000) >> 3);
    uint8_t src_code = opcode & (0b00000111);
    uint8_t src = fetch_r(cpu, src_code);

    RegisterSet set_R = R_TABLE[dest_code];
    set_R(cpu, src);

    cpu->t_cycles = 4;
}

void LD_r_HL(CPU *cpu, uint8_t opcode)
{
    uint8_t dest_code = ((opcode & 0b00111000) >> 3);
    RegisterSet set_R = R_TABLE[dest_code];
    set_R(cpu, read_byte(cpu, cpu->registers.HL));

    cpu->t_cycles = 8;
}

void LD_r_n(CPU *cpu, uint8_t opcode)
{
    uint8_t r = (opcode & 0b00111000) >> 3;
    RegisterSet set_R = R_TABLE[r];
    set_R(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
    if (r == reg_HL) cpu->t_cycles += 4;
}

void LD_A_rr(CPU *cpu, uint8_t opcode)
{
    cpu->t_cycles = 0;
    uint8_t byte = 0;
    switch (0xff & opcode) {
        case 0x0a:
            byte = fetch_r(cpu, reg_BC);
            break;
        case 0x1a:
            byte = fetch_r(cpu, reg_DE);
            break;
        case 0xf0:
            byte = read_byte(cpu, 0xff00 + fetch_opcode(cpu));
            cpu->t_cycles += 12;
            break;
        case 0xf2:
            byte = read_byte(cpu, 0xff00 + fetch_r(cpu, reg_C));
            cpu->t_cycles += 4;
            break;
        case 0xfa: {
            uint16_t addr = (fetch_opcode(cpu) << 8) | fetch_opcode(cpu);
            byte = read_byte(cpu, addr);
            cpu->t_cycles += 16;
            break;
        }
        default:
            printf("Invalid read source\n");
            break;
    }

    set_A(cpu, byte);
}

void LD_IR_A(CPU *cpu, uint8_t opcode)
{
    cpu->t_cycles = 0;
    uint16_t addr = 0;
    switch (0xff & opcode) {
        case 0x02:
            addr = cpu->registers.BC;
            cpu->t_cycles += 4;
            break;
        case 0x12:
            addr = cpu->registers.DE;
            cpu->t_cycles += 4;
            break;
        case 0xe0:
            addr = 0xff00 + fetch_opcode(cpu);
            cpu->t_cycles += 8;
            break;
        case 0xe2:
            addr = 0xff00 + fetch_r(cpu, reg_C);
            break;
        case 0xea:
            addr = (fetch_opcode(cpu) << 8) | fetch_opcode(cpu);
            cpu->t_cycles += 12;
            break;
        default:
            printf("Invalid write destination\n");
            break;
    }
    write_byte(cpu, fetch_r(cpu, reg_A), addr);
}

void LD_A_HLI(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    cpu->t_cycles = 0;
    set_A(cpu, fetch_r(cpu, reg_HL));
    cpu->registers.HL++;
}

void LD_A_HLD(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    cpu->t_cycles = 0;
    set_A(cpu, fetch_r(cpu, reg_HL));
    cpu->registers.HL--;
}

void UNDEF(CPU *cpu, uint8_t opcode)
{
    (void)cpu;
    printf("opcode 0x%x is undefined\n", opcode);
}
