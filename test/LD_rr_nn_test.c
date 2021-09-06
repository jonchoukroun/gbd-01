#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LD_BC_nn(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x2001;
    cpu->PC = PC;
    cpu->memory[PC] = 0x69;
    cpu->memory[PC + 1] = 0x96;
    LD_rr_nn(cpu, 0x01);
    CU_ASSERT_EQUAL(cpu->registers.BC, 0x6996);
    CU_ASSERT_EQUAL(cpu->PC, PC + 2);
    CU_ASSERT_EQUAL(cpu->t_cycles, 12);
}

void test_LD_DE_nn(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x3541;
    cpu->PC = PC;
    cpu->memory[PC] = 0x3a;
    cpu->memory[PC + 1] = 0x5b;
    LD_rr_nn(cpu, 0x11);
    CU_ASSERT_EQUAL(cpu->registers.D, 0x3a);
    CU_ASSERT_EQUAL(cpu->registers.E, 0x5b);
    CU_ASSERT_EQUAL(cpu->PC, PC + 2);
    CU_ASSERT_EQUAL(cpu->t_cycles, 12);
}

void test_LD_HL_nn(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x2345;
    cpu->PC = PC;
    cpu->memory[PC] = 0xba;
    cpu->memory[PC + 1] = 0xfa;
    LD_rr_nn(cpu, 0x21);
    CU_ASSERT_EQUAL(cpu->registers.HL, 0xbafa);
    CU_ASSERT_EQUAL(cpu->PC, PC + 2);
    CU_ASSERT_EQUAL(cpu->t_cycles, 12);
}

void test_LD_SP_nn(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x0100;
    cpu->PC = PC;
    cpu->memory[PC] = 0xab;
    cpu->memory[PC + 1] = 0xcd;
    LD_rr_nn(cpu, 0x31);
    CU_ASSERT_EQUAL(cpu->SP, 0xabcd);
    CU_ASSERT_EQUAL(cpu->PC, PC + 2);
    CU_ASSERT_EQUAL(cpu->t_cycles, 12);

}

void test_LD_SP_HL(void)
{
    CPU *cpu = init_cpu();
    uint16_t value = 0xdef0;
    cpu->registers.HL = value;
    LD_SP_HL(cpu, 0xf9);
    CU_ASSERT_EQUAL(cpu->SP, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_rr_nn Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_BC_nn loads 2 immediate bytes into register BC",
            test_LD_BC_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_DE_nn loads 2 immediate bytes into register DE",
            test_LD_DE_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_HL_nn loads 2 immediate bytes into register HL",
            test_LD_HL_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_SP_nn loads 2 immediate bytes into SP",
            test_LD_SP_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_SP_HL loads value in HL register into SP",
            test_LD_SP_HL
        ) == NULL) {
        printf("Failed to add test to LD_rr_nn unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
