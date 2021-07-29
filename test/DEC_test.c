#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_DEC_A(void)
{
    CPU cpu;
    cpu.registers.A = 0;
    cpu.registers.F = 0;
    DEC_r(&cpu, 0x3d);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xff);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_DEC_B(void)
{
    CPU cpu;
    cpu.registers.B = 0x05;
    cpu.registers.F = 0b00010000;
    DEC_r(&cpu, 0x05);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x04);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_DEC_C(void)
{
    CPU cpu;
    cpu.registers.C = 0x0f;
    cpu.registers.F = 0;
    DEC_r(&cpu, 0x0d);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x0e);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_DEC_D(void)
{
    CPU cpu;
    cpu.registers.D = 0xf0;
    cpu.registers.F = 0;
    DEC_r(&cpu, 0x15);
    CU_ASSERT_EQUAL(cpu.registers.D, 0xef);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_DEC_E(void)
{
    CPU cpu;
    cpu.registers.E = 0x01;
    cpu.registers.F = 0;
    DEC_r(&cpu, 0x1d);
    CU_ASSERT_EQUAL(cpu.registers.E, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_DEC_H(void)
{
    CPU cpu;
    cpu.registers.H = 0x05;
    cpu.registers.F = 0b00010000;
    DEC_r(&cpu, 0x25);
    CU_ASSERT_EQUAL(cpu.registers.H, 0x04);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_DEC_L(void)
{
    CPU cpu;
    cpu.registers.L = 0x04;
    cpu.registers.F = 0;
    DEC_r(&cpu, 0x2d);
    CU_ASSERT_EQUAL(cpu.registers.L, 0x03);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_DEC_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x0200;
    cpu.memory[0x0200] = 0x0a;
    cpu.registers.F = 0;
    DEC_HL(&cpu, 0x35);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x09);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8-bit DEC Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit DEC Instructions | DEC_A decrements value in register A",
            test_DEC_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit DEC Instructions | DEC_B decrements value in register A",
            test_DEC_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit DEC Instructions | DEC_C decrements value in register A",
            test_DEC_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit DEC Instructions | DEC_D decrements value in register A",
            test_DEC_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit DEC Instructions | DEC_E decrements value in register A",
            test_DEC_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit DEC Instructions | DEC_H decrements value in register A",
            test_DEC_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit DEC Instructions | DEC_L decrements value in register A",
            test_DEC_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit DEC Instructions | DEC_HL decrements memory contents at address pointed to by register HL",
            test_DEC_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit DEC Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}


