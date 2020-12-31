#include <stdio.h>
#include "cpu.h"
#include "instructions.h"

uint8_t fetch_opcode(CPU *cpu)
{
    if (cpu->PC > ADDRESS_BUS_SIZE) {
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

void clear_flag(CPU *cpu, FlagPosition flag)
{
    cpu->registers.F &= ~(0b1 << flag);
}

void set_flag(CPU *cpu, FlagPosition flag)
{
    cpu->registers.F |= (0b1 << flag);
}

void toggle_zero_flag(CPU *cpu, uint16_t value)
{
    uint8_t bit = value == 0;
    uint8_t mask = cpu->registers.F & 0b01110000;
    cpu->registers.F = mask | (bit << ZERO_FLAG);
}

void toggle_hcarry_flag(CPU *cpu, uint16_t a, uint16_t b, USIZE size)
{
    uint8_t overflow;
    if (size == BYTE) {
        overflow = (a & 0xf) + (b & 0xf) > 0xf;
    } else {
        overflow = (a & 0xf00) + (b & 0xf00) > 0x400;
    }
    uint8_t mask = cpu->registers.F & 0b11010000;
    cpu->registers.F = mask | (overflow << HALF_CARRY_FLAG);
}

void toggle_carry_flag(CPU *cpu, uint32_t value, USIZE size)
{
    uint8_t overflow;
    if (size == BYTE) {
        overflow = value > 0xff;
    } else {
        overflow = value > 0xffff;
    }
    uint8_t mask = cpu->registers.F & 0b11100000;
    cpu->registers.F = mask | (overflow << CARRY_FLAG);
}
