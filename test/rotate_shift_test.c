#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_RLCA(void)
{
    CPU cpu;
    cpu.registers.A = 0x85;
    cpu.registers.F = 0;
    RLCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0b);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 0xff;
    cpu.registers.F = 0;
    RLCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xff);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    cpu.registers.A = 0x31;
    cpu.registers.F = 0b00010000;
    RLCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);

    cpu.registers.A = 128;
    cpu.registers.F = 0;
    RLCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 1);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    cpu.registers.A = 129;
    cpu.registers.F = 0b00010000;
    RLCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 3);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RLA(void)
{
    CPU cpu;
    cpu.registers.A = 128;
    cpu.registers.F = 0;
    RLA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 128;
    cpu.registers.F = 0b00010000;
    RLA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 1);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    cpu.registers.A = 64;
    cpu.registers.F = 0;
    RLA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 128);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RRCA(void)
{
    CPU cpu;
    cpu.registers.A = 1;
    cpu.registers.F = 0b00010000;
    RRCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 128);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 0x3b;
    cpu.registers.F = 0;
    RRCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x9d);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    cpu.registers.A = 0;
    cpu.registers.F = 0b11110000;
    RRCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RRA(void)
{
    CPU cpu;
    cpu.registers.A = 1;
    cpu.registers.F = 0;
    RRA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 0x81;
    cpu.registers.F = 0b00010000;
    RRA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    cpu.registers.A = 1;
    cpu.registers.F = 0b00010000;
    RRA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 128);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RLC_A(void)
{
    CPU cpu;
    cpu.registers.A = 0b10101010;
    cpu.registers.F = 0;
    RLC_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0b01010101);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.A = 0x10;
    cpu.registers.F = 0b00010000;
    RLC_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x20);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RLC_B(void)
{
    CPU cpu;
    cpu.registers.B = 0;
    cpu.registers.F = 0;
    RLC_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.B = 0x10;
    cpu.registers.F = 0b00010000;
    RLC_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x20);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RLC_C(void)
{
    CPU cpu;
    cpu.registers.C = 1;
    cpu.registers.F = 0;
    RLC_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0b10);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.C = 0x10;
    cpu.registers.F = 0b00010000;
    RLC_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x20);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RLC_D(void)
{
    CPU cpu;
    cpu.registers.D = 2;
    cpu.registers.F = 0;
    RLC_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 4);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.D = 0x10;
    cpu.registers.F = 0b00010000;
    RLC_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0x20);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RLC_E(void)
{
    CPU cpu;
    cpu.registers.E = 4;
    cpu.registers.F = 0;
    RLC_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 8);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.E = 0x10;
    cpu.registers.F = 0b00010000;
    RLC_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0x20);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RLC_H(void)
{
    CPU cpu;
    cpu.registers.H = 32;
    cpu.registers.F = 0;
    RLC_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.H = 0x10;
    cpu.registers.F = 0b00010000;
    RLC_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0x20);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RLC_L(void)
{
    CPU cpu;
    cpu.registers.L = 128;
    cpu.registers.F = 0;
    RLC_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 1);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.L = 0x10;
    cpu.registers.F = 0b00010000;
    RLC_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0x20);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RLC_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x1234;
    cpu.registers.F = 0;
    cpu.memory[cpu.registers.HL] = 0x85;
    RLC_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x0b);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    cpu.memory[cpu.registers.HL] = 0x10;
    cpu.registers.F = 0b00010000;
    RLC_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x20);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RL_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x80;
    cpu.registers.F = 0;
    RL_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.A = 0x40;
    cpu.registers.F = 0b00010000;
    RL_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x81);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RL_B(void)
{
    CPU cpu;
    cpu.registers.B = 0x80;
    cpu.registers.F = 0;
    RL_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.B = 0x40;
    cpu.registers.F = 0b00010000;
    RL_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x81);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RL_C(void)
{
    CPU cpu;
    cpu.registers.C = 0x80;
    cpu.registers.F = 0;
    RL_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.C = 0x40;
    cpu.registers.F = 0b00010000;
    RL_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x81);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RL_D(void)
{
    CPU cpu;
    cpu.registers.D = 0x80;
    cpu.registers.F = 0;
    RL_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.D = 0x40;
    cpu.registers.F = 0b00010000;
    RL_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0x81);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RL_E(void)
{
    CPU cpu;
    cpu.registers.E = 0x80;
    cpu.registers.F = 0;
    RL_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.E = 0x40;
    cpu.registers.F = 0b00010000;
    RL_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0x81);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RL_H(void)
{
    CPU cpu;
    cpu.registers.H = 0x80;
    cpu.registers.F = 0;
    RL_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.H = 0x40;
    cpu.registers.F = 0b00010000;
    RL_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0x81);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RL_L(void)
{
    CPU cpu;
    cpu.registers.L = 0x80;
    cpu.registers.F = 0;
    RL_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.L = 0x40;
    cpu.registers.F = 0b00010000;
    RL_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0x81);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RL_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x4312;
    cpu.memory[cpu.registers.HL] = 0x11;
    cpu.registers.F = 0;
    RL_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x22);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    cpu.memory[cpu.registers.HL] = 0x40;
    cpu.registers.F = 0b00010000;
    RL_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x81);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RRC_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x11;
    cpu.registers.F = 0;
    RRC_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RRC_B(void)
{
    CPU cpu;
    cpu.registers.B = 0x11;
    cpu.registers.F = 0;
    RRC_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RRC_C(void)
{
    CPU cpu;
    cpu.registers.C = 0x11;
    cpu.registers.F = 0;
    RRC_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RRC_D(void)
{
    CPU cpu;
    cpu.registers.D = 0x11;
    cpu.registers.F = 0;
    RRC_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RRC_E(void)
{
    CPU cpu;
    cpu.registers.E = 0x11;
    cpu.registers.F = 0;
    RRC_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RRC_H(void)
{
    CPU cpu;
    cpu.registers.H = 0x11;
    cpu.registers.F = 0;
    RRC_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RRC_L(void)
{
    CPU cpu;
    cpu.registers.L = 0x11;
    cpu.registers.F = 0;
    RRC_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RRC_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x2222;
    cpu.registers.F = 0;
    cpu.memory[cpu.registers.HL] = 0x11;
    RRC_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    cpu.memory[cpu.registers.HL] = 0;
    cpu.registers.F = 0b00010000;
    RRC_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

void test_RR_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x01;
    cpu.registers.F = 0;
    RR_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.A = 0x11;
    cpu.registers.F = 0b00010000;
    RR_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RR_B(void)
{
    CPU cpu;
    cpu.registers.B = 0x01;
    cpu.registers.F = 0;
    RR_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.B = 0x11;
    cpu.registers.F = 0b00010000;
    RR_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RR_C(void)
{
    CPU cpu;
    cpu.registers.C = 0x01;
    cpu.registers.F = 0;
    RR_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.C = 0x11;
    cpu.registers.F = 0b00010000;
    RR_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RR_D(void)
{
    CPU cpu;
    cpu.registers.D = 0x01;
    cpu.registers.F = 0;
    RR_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.D = 0x11;
    cpu.registers.F = 0b00010000;
    RR_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RR_E(void)
{
    CPU cpu;
    cpu.registers.E = 0x01;
    cpu.registers.F = 0;
    RR_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.E = 0x11;
    cpu.registers.F = 0b00010000;
    RR_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RR_H(void)
{
    CPU cpu;
    cpu.registers.H = 0x01;
    cpu.registers.F = 0;
    RR_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.H = 0x11;
    cpu.registers.F = 0b00010000;
    RR_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RR_L(void)
{
    CPU cpu;
    cpu.registers.L = 0x01;
    cpu.registers.F = 0;
    RR_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.L = 0x11;
    cpu.registers.F = 0b00010000;
    RR_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RR_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x5432;
    cpu.registers.F = 0;
    cpu.memory[cpu.registers.HL] = 0x8a;
    RR_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x45);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    cpu.memory[cpu.registers.HL] = 0x11;
    cpu.registers.F = 0b00010000;
    RR_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x88);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Rotate shift unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "Rotate Shift | RLCA rotates A to the left with bit 7 into bit 0 and the C flag",
            test_RLCA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLA rotates A register to the left with C flag into bit 0 and bit 7 into the C flag",
            test_RLA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRCA rotates A to the right with bit 0 into bit 7 and into the C flag",
            test_RRCA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRA rotates A to the right with the C flag into bit 7 and bit 0 into C flag",
            test_RRA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_A rotates A to the left with bit 7 into bit 0 and also into C flag",
            test_RLC_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_B rotates B to the left with bit 7 into bit 0 and also into C flag",
            test_RLC_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_C rotates C to the left with bit 7 into bit 0 and also into C flag",
            test_RLC_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_D rotates D to the left with bit 7 into bit 0 and also into C flag",
            test_RLC_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_E rotates E to the left with bit 7 into bit 0 and also into C flag",
            test_RLC_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_H rotates H to the left with bit 7 into bit 0 and also into C flag",
            test_RLC_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_L rotates L to the left with bit 7 into bit 0 and also into C flag",
            test_RLC_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_B rotates byte at HL to the left with bit 7 into bit 0 and also into C flag",
            test_RLC_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_A rotates A to the left with C flag into bit 0 and bit 7 into C flag",
            test_RL_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_B rotates B to the left with C flag into bit 0 and bit 7 into C flag",
            test_RL_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_C rotates C to the left with C flag into bit 0 and bit 7 into C flag",
            test_RL_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_D rotates D to the left with C flag into bit 0 and bit 7 into C flag",
            test_RL_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_E rotates E to the left with C flag into bit 0 and bit 7 into C flag",
            test_RL_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_H rotates H to the left with C flag into bit 0 and bit 7 into C flag",
            test_RL_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_L rotates L to the left with C flag into bit 0 and bit 7 into C flag",
            test_RL_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_HL rotates HL to the left with C flag into bit 0 and bit 7 into C flag",
            test_RL_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRC_A rotates A to the right with bit 0 moved to bit 7 and into the C flag",
            test_RRC_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRC_B rotates B to the right with bit 0 moved to bit 7 and into the C flag",
            test_RRC_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRC_C rotates C to the right with bit 0 moved to bit 7 and into the C flag",
            test_RRC_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRC_D rotates D to the right with bit 0 moved to bit 7 and into the C flag",
            test_RRC_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRC_E rotates E to the right with bit 0 moved to bit 7 and into the C flag",
            test_RRC_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRC_H rotates H to the right with bit 0 moved to bit 7 and into the C flag",
            test_RRC_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRC_L rotates L to the right with bit 0 moved to bit 7 and into the C flag",
            test_RRC_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRC_HL rotates byte at HL to the right with bit 0 moved to bit 7 and into the C flag",
            test_RRC_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RR_A rotates A to the right with the C flag into bit 7 and bit 0 into the C flag",
            test_RR_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RR_B rotates B to the right with the C flag into bit 7 and bit 0 into the C flag",
            test_RR_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RR_C rotates C to the right with the C flag into bit 7 and bit 0 into the C flag",
            test_RR_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RR_D rotates D to the right with the C flag into bit 7 and bit 0 into the C flag",
            test_RR_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RR_E rotates E to the right with the C flag into bit 7 and bit 0 into the C flag",
            test_RR_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RR_H rotates H to the right with the C flag into bit 7 and bit 0 into the C flag",
            test_RR_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RR_L rotates L to the right with the C flag into bit 7 and bit 0 into the C flag",
            test_RR_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RR_HL rotates byte at HL to the right with the C flag into bit 7 and bit 0 into the C flag",
            test_RR_HL
        ) == NULL) {
        printf("Failed to add test to rotate shift unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
