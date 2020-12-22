#include <stdio.h>
#include "instructions.h"

uint8_t low_overflow(uint8_t a, uint8_t b)
{
    return (a & 0xf) + (b & 0xf) > 0xf;
}

void add(CPU *cpu, uint16_t opcode)
{
    Registers8 reg = B;
    uint8_t value;
    switch (reg)
    {
    case B:
        value = cpu->registers.B;
        break;
    case C:
        value = cpu->registers.C;
        break;
    case D:
        value = cpu->registers.D;
        break;
    case H:
        value = cpu->registers.H;
        break;
    case L:
        value = cpu->registers.L;
        break;
    default:
        printf("ADD failed. Invalid register: %x\n", reg);
        return;
    }
    uint16_t result = cpu->registers.A + value;
    if (result == 0) set_flag(cpu, ZERO_FLAG);
    clear_flag(cpu, SUBTRACT_FLAG);
    if (low_overflow(cpu->registers.A, value) == 1) set_flag(cpu, HALF_CARRY_FLAG);
    if (result > 0xff) set_flag(cpu, CARRY_FLAG);

    cpu->registers.A = result & 0xff;
}
