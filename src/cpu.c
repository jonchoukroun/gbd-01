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
