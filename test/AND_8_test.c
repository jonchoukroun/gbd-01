#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_AND_A(void)
{
    CPU cpu;
    uint8_t A = 0x1a;
    cpu.registers.A = A;
    cpu.registers.F = 0;
    AND_r(&cpu, 0xa7);
    CU_ASSERT_EQUAL(cpu.registers.A, A);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    A = 0;
    cpu.registers.A = A;
    AND_r(&cpu, 0xa7);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);
}

void test_AND_B(void)
{
    CPU cpu;
    cpu.registers.A = 0x23;
    cpu.registers.B = 0x45;
    AND_r(&cpu, 0xa0);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x01);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_AND_C(void)
{
    CPU cpu;
    cpu.registers.A = 0x4c;
    cpu.registers.C = 0xff;
    AND_r(&cpu, 0xa1);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x4c);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_AND_D(void)
{
    CPU cpu;
    cpu.registers.A = 0x4c;
    cpu.registers.D = 0xff;
    AND_r(&cpu, 0xa2);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x4c);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_AND_E(void)
{
    CPU cpu;
    cpu.registers.A = 0x4c;
    cpu.registers.E = 0xff;
    AND_r(&cpu, 0xa3);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x4c);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_AND_H(void)
{
    CPU cpu;
    cpu.registers.A = 0x4c;
    cpu.registers.H = 0xff;
    AND_r(&cpu, 0xa4);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x4c);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_AND_L(void)
{
    CPU cpu;
    cpu.registers.A = 0x4c;
    cpu.registers.L = 0xff;
    AND_r(&cpu, 0xa5);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x4c);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_AND_n(void)
{
    CPU cpu;
    cpu.registers.A = 0xca;
    cpu.PC = 0x100;
    cpu.memory[cpu.PC] = 0x31;
    AND_n(&cpu, 0xe6);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_AND_HL(void)
{
    CPU cpu;
    uint8_t n = 0x0a;
    uint16_t address = 0x2400;
    cpu.registers.HL = address;
    cpu.memory[address] = n;
    cpu.registers.A = 0x04;
    AND_HL(&cpu, 0xa6);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8-bit AND Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_A adds value in register A plus the carry flag to itself",
            test_AND_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_B adds B register value and carry flag to A register value",
            test_AND_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_C adds C register value and carry flag to A register value",
            test_AND_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_D adds D register value and carry flag to A register value",
            test_AND_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_E adds E register value and carry flag to A register value",
            test_AND_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_H adds H register value and carry flag to A register value",
            test_AND_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_L adds L register value and carry flag to A register value",
            test_AND_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_n adds immediate value and carry flag to A register value",
            test_AND_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit AND Instructions | AND_HL adds value pointed to from HL register and carry flag to A register value",
            test_AND_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit AND Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

