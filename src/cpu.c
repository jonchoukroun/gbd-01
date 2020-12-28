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
