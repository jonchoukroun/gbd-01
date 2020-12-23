#include <stdio.h>
#include "instructions.h"

uint8_t low_overflow(uint8_t a, uint8_t b)
{
    return (a & 0xf) + (b & 0xf) > 0xf;
}

void add(CPU *cpu, uint8_t nibble)
{
    uint16_t value;
    switch (nibble) {
    case 0x0:
        value = cpu->registers.B;
        break;
    case 0x1:
        value = cpu->registers.C;
        break;
    case 0x2:
        value = cpu->registers.D;
        break;
    case 0x3:
        value = cpu->registers.E;
        break;
    case 0x4:
        value = cpu->registers.H;
        break;
    case 0x5:
        value = cpu->registers.L;
        break;
    case 0x6:
        value = cpu->registers.HL;
        break;
    case 0x7:
        value = cpu->registers.A;
        break;
    default:
        printf("ADD failed. Invalid reg: %x\n", nibble);
        return;
    };
    uint16_t result = cpu->registers.A + value;

    if (result == 0) set_flag(cpu, ZERO_FLAG);
    clear_flag(cpu, SUBTRACT_FLAG);
    if (low_overflow(cpu->registers.A, value) == 1) set_flag(cpu, HALF_CARRY_FLAG);
    if (result > 0xff) set_flag(cpu, CARRY_FLAG);

    cpu->registers.A = result & 0xff;
}
