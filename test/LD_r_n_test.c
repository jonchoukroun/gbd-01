#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LD_B_n(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x1010;
    uint8_t value = 0xab;
    cpu->memory[PC] = value;
    cpu->PC = PC;
    LD_r_n(cpu, 0x06);
    CU_ASSERT_EQUAL(cpu->registers.B, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
}

void test_LD_C_n(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x2000;
    uint8_t value = 0xab;
    cpu->memory[PC] = value;
    cpu->PC = PC;
    LD_r_n(cpu, 0x0e);
    CU_ASSERT_EQUAL(cpu->registers.C, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
}

void test_LD_D_n(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu->memory[PC] = value;
    cpu->PC = PC;
    LD_r_n(cpu, 0x16);
    CU_ASSERT_EQUAL(cpu->registers.D, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
}

void test_LD_E_n(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu->memory[PC] = value;
    cpu->PC = PC;
    LD_r_n(cpu, 0x1e);
    CU_ASSERT_EQUAL(cpu->registers.E, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
}

void test_LD_H_n(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu->memory[PC] = value;
    cpu->PC = PC;
    LD_r_n(cpu, 0x26);
    CU_ASSERT_EQUAL(cpu->registers.H, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
}

void test_LD_L_n(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu->memory[PC] = value;
    cpu->PC = PC;
    LD_r_n(cpu, 0x2e);
    CU_ASSERT_EQUAL(cpu->registers.L, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
}

void test_LD_A_n(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu->memory[PC] = value;
    cpu->PC = PC;
    LD_r_n(cpu, 0x3e);
    CU_ASSERT_EQUAL(cpu->registers.A, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
}

void test_LD_HL_n(void)
{
    CPU *cpu = init_cpu();
    cpu->PC = 0x0100;
    cpu->registers.HL = 0x5fba;
    cpu->registers.F = 0b10100000;
    cpu->memory[cpu->registers.HL] = 0xfb;
    cpu->memory[cpu->PC] = 0x3a;
    LD_HL_n(cpu, 0x36);
    CU_ASSERT_EQUAL(cpu->PC, 0x0101);
    CU_ASSERT_EQUAL(cpu->registers.HL, 0x5fba);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10100000);
    CU_ASSERT_EQUAL(cpu->memory[cpu->registers.HL], 0x3a);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_r_n Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_r_n Instructions | LD_A_n loads immediate value into register be and sets cycles",
            test_LD_A_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_n Instructions | LD_B_n loads immediate value into register be and sets cycles",
            test_LD_B_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_n Instructions | LD_C_n loads immediate value into register be and sets cycles",
            test_LD_C_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_n Instructions | LD_D_n loads immediate value into register be and sets cycles",
            test_LD_D_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_n Instructions | LD_E_n loads immediate value into register be and sets cycles",
            test_LD_E_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_n Instructions | LD_H_n loads immediate value into register be and sets cycles",
            test_LD_H_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_n Instructions | LD_L_n loads immediate value into register be and sets cycles",
            test_LD_L_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_n Instructions | LD_HL_n loads immediate value into address stored in HL",
            test_LD_HL_n
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
