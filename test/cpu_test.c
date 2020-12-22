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

void test_get_zero_flag(void)
{
    CPU cpu;
    cpu.registers.F = 0b10000000;
    CU_ASSERT_EQUAL(get_flag(&cpu, ZERO_FLAG), 1);

    cpu.registers.F = 0b01111111;
    CU_ASSERT_EQUAL(get_flag(&cpu, ZERO_FLAG), 0);
}

void test_get_subtract_flag(void)
{
    CPU cpu;
    cpu.registers.F = 0b01000000;
    CU_ASSERT_EQUAL(get_flag(&cpu, SUBTRACT_FLAG), 1);

    cpu.registers.F = 0b10111111;
    CU_ASSERT_EQUAL(get_flag(&cpu, SUBTRACT_FLAG), 0);
}

void test_get_half_carry_flag(void)
{
    CPU cpu;
    cpu.registers.F = 0b00100000;
    CU_ASSERT_EQUAL(get_flag(&cpu, HALF_CARRY_FLAG), 1);

    cpu.registers.F = 0b11011111;
    CU_ASSERT_EQUAL(get_flag(&cpu, HALF_CARRY_FLAG), 0);
}

void test_get_carry_flag(void)
{
    CPU cpu;
    cpu.registers.F = 0b00010000;
    CU_ASSERT_EQUAL(get_flag(&cpu, CARRY_FLAG), 1);

    cpu.registers.F = 0b11101111;
    CU_ASSERT_EQUAL(get_flag(&cpu, CARRY_FLAG), 0);
}

void test_set_flag(void)
{
    CPU cpu;
    uint8_t reset = 0b00000000;
    cpu.registers.F = reset;
    set_flag(&cpu, CARRY_FLAG);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    cpu.registers.F = reset;
    set_flag(&cpu, SUBTRACT_FLAG);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);
}

void test_clear_flag(void)
{
    CPU cpu;
    cpu.registers.F = 0b10000000;
    clear_flag(&cpu, ZERO_FLAG);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    cpu.registers.F = 0b00110000;
    clear_flag(&cpu, HALF_CARRY_FLAG);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
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
            test_suite, "CPU | get_flag fetches zero flag bit", test_get_zero_flag
        ) == NULL ||
        CU_add_test(
            test_suite, "CPU |  get_flag fetches subtract flag bit", test_get_subtract_flag
        ) == NULL ||
        CU_add_test(
            test_suite, "CPU | get_flag fetches half carry flag bit", test_get_half_carry_flag
        ) == NULL ||
        CU_add_test(
            test_suite, "CPU | get_flag fetches carry bit", test_get_carry_flag
        ) == NULL ||
        CU_add_test(
            test_suite, "CPU | set_flag sets bit at correct flag position", test_set_flag
        ) == NULL ||
        CU_add_test(
            test_suite, "CPU | clear_flag clears bit at correct flag position", test_clear_flag
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
