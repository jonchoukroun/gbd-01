#include <stdio.h>
#include <limits.h>
#include "instructions.h"

uint8_t fetch_r(CPU *cpu, uint8_t r)
{
    uint8_t registers[] = {
        cpu->registers.B,
        cpu->registers.C,
        cpu->registers.D,
        cpu->registers.E,
        cpu->registers.H,
        cpu->registers.L,
        cpu->memory[cpu->registers.HL],
        cpu->registers.A,
    };
    if (r == 6) cpu->t_cycles += 4;

    return registers[r];
}

typedef void (*RegisterSet)(CPU *, uint8_t);
void set_B(CPU *cpu, uint8_t n) { cpu->registers.B = n; }
void set_C(CPU *cpu, uint8_t n) { cpu->registers.C = n; }
void set_D(CPU *cpu, uint8_t n) { cpu->registers.D = n; }
void set_E(CPU *cpu, uint8_t n) { cpu->registers.E = n; }
void set_H(CPU *cpu, uint8_t n) { cpu->registers.H = n; }
void set_L(CPU *cpu, uint8_t n) { cpu->registers.L = n; }
void set_HL(CPU *cpu, uint8_t n)
{
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
    cpu->t_cycles = 0;
    uint8_t dest_code = ((opcode & 0b00111000) >> 3);
    uint8_t src_code = opcode & (0b00000111);
    uint8_t src = fetch_r(cpu, src_code);

    RegisterSet fn = R_TABLE[dest_code];
    fn(cpu, src);

    cpu->t_cycles += 4;
}

void LD_r_n(CPU *cpu, uint8_t opcode)
{
    cpu->t_cycles = 0;
    uint8_t r_code = ((opcode & 0b00111000) >> 3);
    cpu->t_cycles += 8;

    RegisterSet fn = R_TABLE[r_code];
    fn(cpu, fetch_opcode(cpu));
}

void LD_A_rr(CPU *cpu, uint8_t opcode)
{
    uint8_t byte;
    switch (0xff & opcode) {
        case 0xa:
            byte = read_byte(cpu, cpu->registers.BC);
            break;
        case 0x1a:
            byte = read_byte(cpu, cpu->registers.DE);
            break;
        case 0xf2:
            byte = read_byte(cpu, (0xff00 + cpu->registers.C));
            break;
        default:
            printf("Invalid register\n");
            break;
    }

    set_A(cpu, byte);

    cpu->t_cycles = 8;
}

void UNDEF(CPU *cpu, uint8_t opcode)
{
    printf("opcode 0x%x is undefined\n", opcode);
}
