#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void print_F(CPU *cpu)
{
    uint8_t z = get_flag(cpu, Z_FLAG);
    uint8_t n = get_flag(cpu, N_FLAG);
    uint8_t h = get_flag(cpu, H_FLAG);
    uint8_t c = get_flag(cpu, C_FLAG);
    printf(" Z: %d, N: %d, H: %d, C: %d ", z, n, h, c);
}

void DAA_test_add()
{
    CPU *cpu = init_cpu();
    uint8_t i, j;
    // Results in bounds
    for (i = 0; i <= 0x09; i++) {
        for (j = 0; j <= 0x09; j++) {
            uint8_t a = (i << 4) | j;
            // No carry, half-carry
            cpu->registers.A = a;
            cpu->registers.F = 0;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a);
            if (a == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Half-carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b00100000;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a + 0x06);
            CU_ASSERT_EQUAL(cpu->registers.F, 0);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b00010000;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a + 0x60);
            CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry and half-carry
            cpu->registers.A = a;
            cpu->registers.F = 0b00110000;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a + 0x66);
            CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);
        }
    }

    // Lower bits out of bounds
    for (i = 0; i < 0x09; i++) {
        for (j = 0x0a; j <= 0x0f; j++) {
            uint8_t a = (i << 4) | j;
            // No carry, half-carry
            cpu->registers.A = a;
            cpu->registers.F = 0;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a + 0x06);
            CU_ASSERT_EQUAL(cpu->registers.F, 0);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Half-carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b00100000;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a + 0x06);
            CU_ASSERT_EQUAL(cpu->registers.F, 0);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b00010000;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a + 0x66);
            CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry and half-carry
            cpu->registers.A = a;
            cpu->registers.F = 0b00110000;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a + 0x66);
            CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);
        }
    }

    // Upper bits out of bounds
    for (i = 0x0a; i <= 0x0f; i++) {
        for (j = 0; j <= 0x09; j++) {
            uint8_t a = (i << 4) | j;
            // No carry, half-carry
            cpu->registers.A = a;
            cpu->registers.F = 0;
            DAA(cpu, 0x27);
            uint8_t expected = (a + 0x60) & 0xff;
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            if (cpu->registers.A == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Half-carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b00100000;
            DAA(cpu, 0x27);
            expected = (a + 0x66) & 0xff;
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b00010000;
            DAA(cpu, 0x27);
            expected = (a + 0x60) & 0xff;
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            if (cpu->registers.A == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry and half-carry
            cpu->registers.A = a;
            cpu->registers.F = 0b00110000;
            DAA(cpu, 0x27);
            expected = (a + 0x66) & 0xff;
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);
        }
    }

    // Results entirely out of bound
    for (i = 0x0a; i <= 0x0f; i++) {
        for (j = 0x0a; j <= 0x0f; j++) {
            uint8_t a = (i << 4) | j;
            // No carry, half-carry
            cpu->registers.A = a;
            cpu->registers.F = 0;
            DAA(cpu, 0x27);
            uint8_t expected = (a + 0x66) & 0xff;
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            if (cpu->registers.A == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Half-carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b00100000;
            DAA(cpu, 0x27);
            expected = (a + 0x66) & 0xff;
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b00010000;
            DAA(cpu, 0x27);
            expected = (a + 0x66) & 0xff;
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            if (cpu->registers.A == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry and half-carry
            cpu->registers.A = a;
            cpu->registers.F = 0b00110000;
            DAA(cpu, 0x27);
            expected = (a + 0x66) & 0xff;
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);
        }
    }
}

void DAA_test_sub()
{
    CPU *cpu = init_cpu();

    for (uint8_t i = 0; i <= 0x0f; i++) {
        for (uint8_t j = 0; j <= 0x0f; j++) {
            uint8_t a = (i << 4) | j;
            // No half-carry or carry
            cpu->registers.A = a;
            cpu->registers.F = 0b01000000;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, a);
            if (cpu->registers.A == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b11000000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Half-carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b01100000;
            uint8_t expected = a - 0x06;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            if (cpu->registers.A == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b11000000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Carry only
            cpu->registers.A = a;
            cpu->registers.F = 0b01010000;
            expected = a - 0x60;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            if (cpu->registers.A == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b11010000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b01010000);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);

            // Half-carry and carry
            cpu->registers.A = a;
            cpu->registers.F = 0b01110000;
            expected = a - 0x66;
            DAA(cpu, 0x27);
            CU_ASSERT_EQUAL(cpu->registers.A, expected);
            if (cpu->registers.A == 0) {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b11010000);
            } else {
                CU_ASSERT_EQUAL(cpu->registers.F, 0b01010000);
            }
            CU_ASSERT_EQUAL(cpu->t_cycles, 4);
        }
    }
}

//------------------------------------------------------------
// Testing for chart in Programming manual (Z80?)
//------------------------------------------------------------

// void DAA_test_add_A()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x0);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x9;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x9);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x90;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x90);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x99;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x99);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_B()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0;
//     cpu->registers.A = 0x0a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x10);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x0f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x15);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x8a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x90);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x8f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x95);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_C()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x06);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0x03;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x09);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0x90;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x96);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0x93;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x99);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_D()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0;
//     cpu->registers.A = 0xa0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xa9;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x09);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xf0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x50);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xf9;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x59);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_E()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0;
//     cpu->registers.A = 0x9a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x9f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x05);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xfa;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x60);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xff;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x65);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_F()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0xa0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x6);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0xa3;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x9);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0xf0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x56);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0xf3;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x59);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_G()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x60);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x09;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x69);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x20;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x80);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x29;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x89);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_I()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00110000;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x66);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00110000;
//     cpu->registers.A = 0x03;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x69);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00110000;
//     cpu->registers.A = 0x30;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x96);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00110000;
//     cpu->registers.A = 0x33;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x99);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_H()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x0a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x70);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x0f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x75);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x2a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x90);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x2f;
//     DAA(cpu, 0x27);
//     }
// }

// void DAA_test_add_A()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x0);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x9;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x9);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x90;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x90);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x99;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x99);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_B()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0;
//     cpu->registers.A = 0x0a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x10);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x0f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x15);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x8a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x90);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x8f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x95);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_C()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x06);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0x03;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x09);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0x90;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x96);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0x93;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x99);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_D()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0;
//     cpu->registers.A = 0xa0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xa9;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x09);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xf0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x50);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xf9;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x59);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_E()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0;
//     cpu->registers.A = 0x9a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0x9f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x05);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xfa;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x60);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0;
//     cpu->registers.A = 0xff;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x65);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_F()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0xa0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x6);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0xa3;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x9);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0xf0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x56);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00100000;
//     cpu->registers.A = 0xf3;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x59);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_G()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x60);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x09;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x69);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x20;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x80);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x29;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x89);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_I()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00110000;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x66);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00110000;
//     cpu->registers.A = 0x03;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x69);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00110000;
//     cpu->registers.A = 0x30;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x96);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00110000;
//     cpu->registers.A = 0x33;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x99);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_add_H()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x0a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x70);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x0f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x75);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x2a;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x90);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);

//     cpu->registers.F = 0b00010000;
//     cpu->registers.A = 0x2f;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x95);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu->t_cycles, 4);
// }

// void DAA_test_sub_A()
// {
//     CPU *cpu = init_cpu();
//     cpu->registers.F = 0b01000000;
//     cpu->registers.A = 0;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b11000000);

//     cpu->registers.F = 0b01000000;
//     cpu->registers.A = 0x09;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x09);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);

//     cpu->registers.F = 0b01000000;
//     cpu->registers.A = 0x90;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x90);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);

//     cpu->registers.F = 0b01000000;
//     cpu->registers.A = 0x99;
//     DAA(cpu, 0x27);
//     CU_ASSERT_EQUAL(cpu->registers.A, 0x99);
//     CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);
// }

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("DAA instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "DAA Instruction | adjusts register A after addition if half-carry or carry occured, or result is out of bounds",
            DAA_test_add
        ) == NULL ||
        CU_add_test(
            test_suite,
            "DAA Instruction | adjusts register A after subtraction if half-carry or carry occured",
            DAA_test_sub
        ) == NULL) {
        printf("Failed to add test to Call instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
