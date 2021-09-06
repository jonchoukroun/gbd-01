#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void LD_HL_SPe_test()
{
    CPU *cpu = init_cpu();
    cpu->SP = 0xfff8;
    cpu->PC = 0x1000;
    cpu->memory[cpu->PC] = 0x02;
    LD_HL_SPe(cpu, 0xf8);
    CU_ASSERT_EQUAL(cpu->registers.HL, 0xfffa);
    CU_ASSERT_EQUAL(cpu->SP, 0xfff8);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 12);

    // -0x7c, -124
    cpu->memory[cpu->PC] = 0b10000100;
    cpu->SP = 0xff55;
    LD_HL_SPe(cpu, 0xf8);
    CU_ASSERT_EQUAL(cpu->registers.HL, 0xfed9);
    CU_ASSERT_EQUAL(cpu->SP, 0xff55);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 12);
}

void LD_nn_SP_test()
{
    CPU *cpu = init_cpu();
    cpu->SP = 0xfff8;
    cpu->PC = 0x10aa;
    cpu->memory[cpu->PC] = 0xc1;
    cpu->memory[cpu->PC + 1] = 0x00;
    LD_nn_SP(cpu, 0x08);
    CU_ASSERT_EQUAL(cpu->memory[0xc100], 0xf8);
    CU_ASSERT_EQUAL(cpu->memory[0xc101], 0xff);
    CU_ASSERT_EQUAL(cpu->SP, 0xfff8);
    CU_ASSERT_EQUAL(cpu->PC, 0x10ac);
    CU_ASSERT_EQUAL(cpu->t_cycles, 20);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD HL SP Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_HL_SPe Instruction | Stores the sum of the signed operand and stack pointer in HL",
            LD_HL_SPe_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_nn_SP Instruction | Stores the stack pointer in the address indicated by 16-bit operand",
            LD_nn_SP_test
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

