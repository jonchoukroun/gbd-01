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
}

void test_RLA(void)
{
    CPU cpu;
    cpu.registers.A = 128;
    RLA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 64;
    RLA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 128);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_RRCA(void)
{
    CPU cpu;
    cpu.registers.A = 1;
    RRCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 128);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 0x3b;
    RRCA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x9d);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RRA(void)
{
    CPU cpu;
    cpu.registers.A = 1;
    RRA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 0x81;
    RRA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x40);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_RLC_A(void)
{
    CPU cpu;
    cpu.registers.A = 0b10101010;
    RLC_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0b01010101);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RLC_B(void)
{
    CPU cpu;
    cpu.registers.B = 0;
    RLC_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RLC_C(void)
{
    CPU cpu;
    cpu.registers.C = 1;
    RLC_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0b10);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RLC_D(void)
{
    CPU cpu;
    cpu.registers.D = 2;
    RLC_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 4);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RLC_E(void)
{
    CPU cpu;
    cpu.registers.E = 4;
    RLC_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 8);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RLC_H(void)
{
    CPU cpu;
    cpu.registers.H = 32;
    RLC_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RLC_L(void)
{
    CPU cpu;
    cpu.registers.L = 128;
    RLC_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 1);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RLC_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x1234;
    cpu.memory[cpu.registers.HL] = 0x85;
    RLC_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x0b);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_RL_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x80;
    RL_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RL_B(void)
{
    CPU cpu;
    cpu.registers.B = 0x80;
    RL_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RL_C(void)
{
    CPU cpu;
    cpu.registers.C = 0x80;
    RL_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RL_D(void)
{
    CPU cpu;
    cpu.registers.D = 0x80;
    RL_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RL_E(void)
{
    CPU cpu;
    cpu.registers.E = 0x80;
    RL_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RL_H(void)
{
    CPU cpu;
    cpu.registers.H = 0x80;
    RL_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RL_L(void)
{
    CPU cpu;
    cpu.registers.L = 0x80;
    RL_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_RL_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x4312;
    cpu.memory[cpu.registers.HL] = 0x11;
    RL_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x22);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
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
            "Rotate Shift | RLCA shifts register A's bits left once and wraps, places bit 7 into C flag",
            test_RLCA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLA shifts register A's bits left once, places bit 7 into C flag",
            test_RLA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRCA shifts register A's bits right once and wraps, places bit 0 into C flag",
            test_RRCA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RRA shifts register A's bits right once, places bit 0 into C flag",
            test_RRA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_A shifts value in A left by one and wraps, sets bit 7 into C flag",
            test_RLC_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_B shifts value in B left by one and wraps, sets bit 7 into C flag",
            test_RLC_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_C shifts value in C left by one and wraps, sets bit 7 into C flag",
            test_RLC_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_D shifts value in D left by one and wraps, sets bit 7 into C flag",
            test_RLC_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_E shifts value in E left by one and wraps, sets bit 7 into C flag",
            test_RLC_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_H shifts value in H left by one and wraps, sets bit 7 into C flag",
            test_RLC_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_L shifts value in L left by one and wraps, sets bit 7 into C flag",
            test_RLC_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RLC_HL rotates byte in memory pointed to from HL and wraps, sets bit 7 into C flag",
            test_RLC_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_A rotates value in A left by 1, sets carry and zero bits conditionally",
            test_RL_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_B rotates value in B left by 1, sets carry and zero bits conditionally",
            test_RL_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_C rotates value in C left by 1, sets carry and zero bits conditionally",
            test_RL_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_D rotates value in D left by 1, sets carry and zero bits conditionally",
            test_RL_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_E rotates value in E left by 1, sets carry and zero bits conditionally",
            test_RL_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_H rotates value in H left by 1, sets carry and zero bits conditionally",
            test_RL_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_L rotates value in L left by 1, sets carry and zero bits conditionally",
            test_RL_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Rotate Shift | RL_HL rotates byte in memory pointed to from HL, sets Z and C flags conditionally",
            test_RL_HL
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
