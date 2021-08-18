#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "instructions.h"

CPU * init_cpu(void)
{
    CPU *cpu = calloc(1, sizeof *cpu);
    cpu->PC = 0;

    return cpu;
}

uint8_t fetch_opcode(CPU *cpu)
{
    if (cpu->PC > ADDRESS_BUS_SIZE - 1) {
        printf("PC is out of memory bounds (%x)\n", cpu->PC);
        return -1;
    }
    uint8_t opcode = read_byte(cpu, cpu->PC);
    cpu->PC++;
    return opcode;
}

uint8_t read_byte(CPU *cpu, uint16_t address)
{
    return cpu->memory[address];
}

uint16_t read_word(CPU *cpu, uint16_t address)
{
    return cpu->memory[address] << 8 | cpu->memory[address + 1];
}

void write_byte(CPU *cpu, uint8_t byte, uint16_t address)
{
    cpu->memory[address] = byte;
}

void write_word(CPU *cpu, uint16_t word, uint16_t address)
{
    uint8_t upper_byte = (word & 0xff00) >> 8;
    uint8_t lower_byte = word & 0x00ff;
    cpu->memory[address] = upper_byte;
    cpu->memory[address + 1] = lower_byte;
}

uint8_t get_flag(CPU *cpu, FlagPosition flag)
{
    return (cpu->registers.F >> flag) & 0b1;
}

void set_flag(CPU *cpu, FlagPosition flag)
{
    uint8_t mask;
    switch (flag) {
        case Z_FLAG:
            mask = cpu->registers.F & 0b01110000;
            break;
        case N_FLAG:
            mask = cpu->registers.F & 0b10110000;
            break;
        case H_FLAG:
            mask = cpu->registers.F & 0b11010000;
            break;
        case C_FLAG:
            mask = cpu->registers.F & 0b11100000;
            break;
        default:
            printf("Invalid flag: %d", flag);
            return;
    }

    cpu->registers.F = mask | (0b1 << flag);
}

void clear_flag(CPU *cpu, FlagPosition flag)
{
    cpu->registers.F &= ~(0b1 << flag);
}

void reset_flags(CPU *cpu)
{
    cpu->registers.F = 0;
}

void set_IME(CPU *cpu)
{
    cpu->memory[IME_FLAG] = 1;
}

void reset_IME(CPU *cpu)
{
    cpu->memory[IME_FLAG] = 0;
}
