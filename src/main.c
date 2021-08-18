#include <stdio.h>
#include "cpu.h"
#include "instructions.h"

uint8_t load_rom(CPU *);

int main()
{
    CPU *cpu = init_cpu();

    if (load_rom(cpu) == 0) return 0;

    uint8_t running = 1;
    uint8_t counter = 0;
    // TODO: update instruction returns to boolean for runloop
    while (running) {
        // TODO: handle input

        // Fetch, decode, execute instruction
        uint8_t opcode = fetch_opcode(cpu);
        OpcodeInstruction instruction;
        // Prefixed opcode, fetch next and get instruction from 2nd table
        if (opcode == 0xcb) {
            opcode = fetch_opcode(cpu);
            instruction = PREFIXED_TABLE[opcode];
        } else {
            instruction = OPCODE_TABLE[opcode];
        }
        instruction(cpu, opcode);

        // TODO: adjust system clock

        // TODO: sound

        // TODO: video

        counter++;
        running = counter < 10 ? 1 : 0;
    }

    printf("OUTPUT:\n");
    printf("\tA: %x\n", cpu->registers.A);
    printf("\tC: %x\n", cpu->registers.C);
    printf("\tF: %x\n", cpu->registers.F);

    return 1;
}

uint8_t load_rom(CPU *cpu)
{
    if (cpu->PC != 0) {
        printf("Failed to load ROM: PC not at valid address\n");
        return 0;
    }

    uint8_t rom_size = 5;
    uint16_t rom[] = {
        0x3e,   // LD A, n
        0x56,   // n = 55
        0x0e,   // LD C, n
        0x3a,   // n = 3a
        0x81,   // ADD A, C
    };

    for (uint8_t i = 0; i < rom_size; i++) {
        cpu->memory[cpu->PC + i] = rom[i];
    }

    return 1;
}
