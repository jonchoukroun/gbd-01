#include "cpu.h"

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
