#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void DAA_a_test()
{
    CPU cpu;
    cpu.registers.F = 0;
    cpu.registers.A = 0;
    DAA(&cpu, 0x27);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void DAA_b_test()
{
    CPU cpu;
    cpu.registers.A = 0x45;
    cpu.registers.B = 0x38;
    // Add B into A
    ADD_r(&cpu, 0x80);
    DAA(&cpu, 0x27);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x83);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void DAA_c_test()
{
    CPU cpu;
    cpu.registers.A = 0x83;
    cpu.registers.B = 0x38;
    // Subtract B from A
    SUB_r(&cpu, 0x80);
    DAA(&cpu, 0x27);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("DAA instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "DAA Instructions | DAA after ADD when C = 0, H = 0, upper bits: 0 <= A <= 0x0, lower bits: 0 <= A <= 0x9, adds 0, sets C = 0",
            DAA_a_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "DAA Instructions | DAA after ADD when C = 0, H = 0, A = 0x45, B = 0x38, sets A to 0x83, and clears C flag",
            DAA_b_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "DAA Instructions | DAA after SUB when C = 0, H = 0, A = 0x45, B = 0x38, sets A to 0x45, clears C flag, and leaves N flag",
            DAA_c_test
        ) == NULL) {
        printf("Failed to add test to Call instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
