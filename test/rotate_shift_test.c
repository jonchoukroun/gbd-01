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
