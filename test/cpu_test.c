#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "cpu.h"

void test_registers(void)
{
    CPU cpu;
    cpu.registers.AF = 0x1234;
    cpu.registers.B = 0xab;
    cpu.registers.C = 0xcd;
    CU_ASSERT_EQUAL(cpu.registers.A, 0x12);
    CU_ASSERT_EQUAL(cpu.registers.F, 0x34);
    CU_ASSERT_EQUAL(cpu.registers.BC, 0xabcd);
}

void test_zero_flag(void)
{
    CPU cpu;
    cpu.registers.F = 0b10000000;
    CU_ASSERT_EQUAL(zero_flag(&cpu), 1);

    cpu.registers.F = 0b01111111;
    CU_ASSERT_EQUAL(zero_flag(&cpu), 0);
}

void test_subtract_flag(void)
{
    CPU cpu;
    cpu.registers.F = 0b01000000;
    CU_ASSERT_EQUAL(subtract_flag(&cpu), 1);

    cpu.registers.F = 0b10111111;
    CU_ASSERT_EQUAL(subtract_flag(&cpu), 0);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("CPU unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite, "CPU | registers respect endianness", test_registers
        ) == NULL ||
        CU_add_test(
            test_suite, "CPU | zero flag fetches 1st bit", test_zero_flag
        ) == NULL ||
        CU_add_test(
            test_suite, "CPU | subtract flag fetches 2nd bit", test_subtract_flag
        ) == NULL) {
        printf("Failed to add test to CPU unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
