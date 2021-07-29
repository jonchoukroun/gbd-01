#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_SUB_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x05;
    SUB_r(&cpu, 0x97);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SUB_B(void)
{
    CPU cpu;
    cpu.registers.A = 0x08;
    cpu.registers.B = 0x03;
    SUB_r(&cpu, 0x90);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x05);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SUB_C(void)
{
    CPU cpu;
    cpu.registers.A = 0x10;
    cpu.registers.C = 0x0a;
    SUB_r(&cpu, 0x91);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x06);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SUB_D(void)
{
    CPU cpu;
    cpu.registers.A = 0x2e;
    cpu.registers.D = 0xfd;
    SUB_r(&cpu, 0x92);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x31);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SUB_E(void)
{
    CPU cpu;
    cpu.registers.A = 0x22;
    cpu.registers.E = 0x55;
    SUB_r(&cpu, 0x93);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xcd);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SUB_H(void)
{
    CPU cpu;
    cpu.registers.A = 0xa0;
    cpu.registers.H = 0x0a;
    SUB_r(&cpu, 0x94);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x96);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SUB_L(void)
{
    CPU cpu;
    cpu.registers.A = 0x10;
    cpu.registers.L = 0x0a;
    SUB_r(&cpu, 0x95);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x06);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SUB_n(void)
{
    CPU cpu;
    cpu.PC = 0x0100;
    cpu.memory[0x0100] = 0x06;
    cpu.registers.A = 0x12;
    SUB_n(&cpu, 0xd6);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0c);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SUB_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x0300;
    cpu.memory[0x0300] = 0x0c;
    cpu.registers.A = 0x0f;
    SUB_HL(&cpu, 0x96);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x03);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8-bit SUB Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_A adds value in register A plus the carry flag to itself",
            test_SUB_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_B adds B register value and carry flag to A register value",
            test_SUB_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_C adds C register value and carry flag to A register value",
            test_SUB_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_D adds D register value and carry flag to A register value",
            test_SUB_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_E adds E register value and carry flag to A register value",
            test_SUB_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_H adds H register value and carry flag to A register value",
            test_SUB_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_L adds L register value and carry flag to A register value",
            test_SUB_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_n adds immediate value and carry flag to A register value",
            test_SUB_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SUB Instructions | SUB_HL adds value pointed to from HL register and carry flag to A register value",
            test_SUB_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit SUB Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

