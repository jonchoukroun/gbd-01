#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_OR_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x23;
    OR_r(&cpu, 0xb7);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x23);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_OR_B(void)
{
    CPU cpu;
    cpu.registers.A = 0xaa;
    cpu.registers.B = 0x11;
    OR_r(&cpu, 0xb0);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_OR_C(void)
{
    CPU cpu;
    cpu.registers.A = 0xaa;
    cpu.registers.C = 0x11;
    OR_r(&cpu, 0xb1);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_OR_D(void)
{
    CPU cpu;
    cpu.registers.A = 0xaa;
    cpu.registers.D = 0x11;
    OR_r(&cpu, 0xb2);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_OR_E(void)
{
    CPU cpu;
    cpu.registers.A = 0xaa;
    cpu.registers.E = 0x11;
    OR_r(&cpu, 0xb3);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_OR_H(void)
{
    CPU cpu;
    cpu.registers.A = 0xaa;
    cpu.registers.H = 0x11;
    OR_r(&cpu, 0xb4);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_OR_L(void)
{
    CPU cpu;
    cpu.registers.A = 0xaa;
    cpu.registers.L = 0x11;
    OR_r(&cpu, 0xb5);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_OR_n(void)
{
    CPU cpu;
    cpu.registers.A = 0x0;
    cpu.PC = 0x500;
    cpu.memory[cpu.PC] = 0x5;
    OR_n(&cpu, 0xf6);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x5);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_OR_HL(void)
{
    CPU cpu;
    uint8_t value = 0x5a;
    uint16_t address = 0x1200;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    cpu.registers.A = 0x12;
    OR_HL(&cpu, 0xb6);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x5a)
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8 bit OR Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_A leaves A as is",
            test_OR_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_B sets A to bitwise or with B",
            test_OR_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_C sets A to bitwise or with C",
            test_OR_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_D sets A to bitwise or with D",
            test_OR_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_E sets A to bitwise or with E",
            test_OR_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_H sets A to bitwise or with H",
            test_OR_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_L sets A to bitwise or with L",
            test_OR_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_n sets A to bitwise or with immediate value",
            test_OR_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit OR Instructions | OR_HL sets A to bitwise or with byte in address at HL",
            test_OR_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit OR Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
