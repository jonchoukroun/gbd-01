#include "cpu.h"

uint8_t zero_flag(CPU *cpu) {
    return (cpu->registers.F >> ZERO_FLAG_POSITION) & 0b1;
}

uint8_t subtract_flag(CPU *cpu) {
    return (cpu->registers.F >> SUBTRACT_FLAG_POSITION) & 0b1;
}

uint8_t half_carry_flag(CPU *cpu) {
    return (cpu->registers.F >> HALF_CARRY_FLAG_POSITION) & 0b1;
}

uint8_t carry_flag(CPU *cpu) {
    return (cpu->registers.F >> CARRY_FLAG_POSITION) & 0b1;
}
