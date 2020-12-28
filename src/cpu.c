#include <stdio.h>
#include "cpu.h"
#include "instructions.h"

uint16_t fetch(CPU *cpu)
{
    if (cpu->PC > ADDRESS_BUS_SIZE) {
        printf("Program Counter is out of memory bounds (%x)\n", cpu->PC);
        return -1;
    }
    return cpu->memory[cpu->PC];
}

void execute(CPU *cpu, uint16_t opcode)
{
    cpu->PC++;
    cpu->t_cycles = 0;
}

uint8_t read_byte(CPU *cpu)
{
    return cpu->memory[cpu->PC - 1];
}

uint16_t read_word(CPU *cpu)
{
    return cpu->memory[cpu->PC - 1] << 8 | cpu->memory[cpu->PC - 2];
}

void write_byte(CPU *cpu, uint8_t byte)
{
    cpu->memory[cpu->PC - 1] = byte;
}

void write_word(CPU *cpu, uint16_t word)
{
    uint8_t upper_byte = (word & 0xff00) >> 8;
    uint8_t lower_byte = word & 0x00ff;
    cpu->memory[cpu->PC - 1] = upper_byte;
    cpu->memory[cpu->PC - 2] = lower_byte;
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
