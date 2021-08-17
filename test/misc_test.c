#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void CPL_test()
{
    CPU cpu;
    cpu.registers.A = 0x35;
    cpu.registers.F = 0;
    CPL(&cpu, 0x2f);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xca);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 0b10000001;
    cpu.registers.F = 0b11110000;
    CPL(&cpu, 0x2f);
    CU_ASSERT_EQUAL(cpu.registers.A, 0b01111110);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 0xff;
    CPL(&cpu, 0x2f);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Misc instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
        test_suite,
        "CPL Instruction | sets A to its 1's complement, sets N, H flags",
        CPL_test
    ) == NULL) {
        printf("Failed to add test to Misc instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
