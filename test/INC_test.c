#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_INC_A(void)
{
    CPU cpu;
    cpu.registers.A = 0;
    cpu.registers.F = 0;
    INC_r(&cpu, 0x3c);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x01);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_INC_B(void)
{
    CPU cpu;
    cpu.registers.B = 0x05;
    cpu.registers.F = 0b00010000;
    INC_r(&cpu, 0x04);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x06);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_INC_C(void)
{
    CPU cpu;
    cpu.registers.C = 0x0f;
    cpu.registers.F = 0;
    INC_r(&cpu, 0x0c);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x10);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_INC_D(void)
{
    CPU cpu;
    cpu.registers.D = 0xff;
    cpu.registers.F = 0;
    INC_r(&cpu, 0x14);
    CU_ASSERT_EQUAL(cpu.registers.D, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_INC_E(void)
{
    CPU cpu;
    cpu.registers.E = 0x05;
    cpu.registers.F = 0;
    INC_r(&cpu, 0x1c);
    CU_ASSERT_EQUAL(cpu.registers.E, 0x06);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_INC_H(void)
{
    CPU cpu;
    cpu.registers.H = 0x05;
    cpu.registers.F = 0b00010000;
    INC_r(&cpu, 0x24);
    CU_ASSERT_EQUAL(cpu.registers.H, 0x06);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_INC_L(void)
{
    CPU cpu;
    cpu.registers.L = 0x0f;
    cpu.registers.F = 0;
    INC_r(&cpu, 0x2c);
    CU_ASSERT_EQUAL(cpu.registers.L, 0x10);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_INC_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x0200;
    cpu.memory[0x0200] = 0x0a;
    cpu.registers.F = 0;
    INC_HL(&cpu, 0x34);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x0b);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8-bit INC Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit INC Instructions | INC_A adds value in register A plus the carry flag to itself",
            test_INC_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit INC Instructions | INC_B adds B register value and carry flag to A register value",
            test_INC_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit INC Instructions | INC_C adds C register value and carry flag to A register value",
            test_INC_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit INC Instructions | INC_D adds D register value and carry flag to A register value",
            test_INC_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit INC Instructions | INC_E adds E register value and carry flag to A register value",
            test_INC_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit INC Instructions | INC_H adds H register value and carry flag to A register value",
            test_INC_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit INC Instructions | INC_L adds L register value and carry flag to A register value",
            test_INC_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit INC Instructions | INC_HL adds value pointed to from HL register and carry flag to A register value",
            test_INC_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit INC Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

