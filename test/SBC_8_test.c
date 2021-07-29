#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_SBC_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x05;
    cpu.registers.F = 0;
    SBC_r(&cpu, 0x9f);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SBC_B(void)
{
    CPU cpu;
    cpu.registers.A = 0x08;
    cpu.registers.B = 0x03;
    cpu.registers.F = 0;
    SBC_r(&cpu, 0x98);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x05);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SBC_C(void)
{
    CPU cpu;
    cpu.registers.A = 0x10;
    cpu.registers.C = 0x0a;
    cpu.registers.F = 0;
    SBC_r(&cpu, 0x99);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x06);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SBC_D(void)
{
    CPU cpu;
    cpu.registers.A = 0x2e;
    cpu.registers.D = 0xfd;
    cpu.registers.F = 0;
    SBC_r(&cpu, 0x9a);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x31);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SBC_E(void)
{
    CPU cpu;
    cpu.registers.A = 0x22;
    cpu.registers.E = 0x55;
    cpu.registers.F = 0b11110000;
    SBC_r(&cpu, 0x9b);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xcc);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SBC_H(void)
{
    CPU cpu;
    cpu.registers.A = 0x3b;
    cpu.registers.H = 0x2a;
    cpu.registers.F = 0b00010000;
    SBC_r(&cpu, 0x9c);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x10);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SBC_L(void)
{
    CPU cpu;
    cpu.registers.A = 0x10;
    cpu.registers.L = 0x0a;
    cpu.registers.F = 0;
    SBC_r(&cpu, 0x9d);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x06);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_SBC_n(void)
{
    CPU cpu;
    cpu.PC = 0x0100;
    cpu.memory[0x0100] = 0x06;
    cpu.registers.A = 0x12;
    cpu.registers.F = 0;
    SBC_n(&cpu, 0xde);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0c);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SBC_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x0300;
    cpu.memory[0x0300] = 0x4f;
    cpu.registers.A = 0x3b;
    cpu.registers.F = 0b11110000;
    SBC_HL(&cpu, 0x9e);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xeb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8-bit SBC Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_A adds value in register A plus the carry flag to itself",
            test_SBC_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_B adds B register value and carry flag to A register value",
            test_SBC_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_C adds C register value and carry flag to A register value",
            test_SBC_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_D adds D register value and carry flag to A register value",
            test_SBC_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_E adds E register value and carry flag to A register value",
            test_SBC_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_H adds H register value and carry flag to A register value",
            test_SBC_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_L adds L register value and carry flag to A register value",
            test_SBC_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_n adds immediate value and carry flag to A register value",
            test_SBC_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit SBC Instructions | SBC_HL adds value pointed to from HL register and carry flag to A register value",
            test_SBC_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit SBC Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

