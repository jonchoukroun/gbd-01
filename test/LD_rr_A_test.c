#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LDH_C_A(void)
{
    CPU *cpu = init_cpu();
    uint8_t low_bit = 0x43;
    uint16_t address = 0xff43;
    uint8_t value = 0xcb;
    cpu->registers.C = low_bit;
    cpu->registers.A = value;
    cpu->memory[address] = 0;
    LD_rr_A(cpu, 0xe2);
    CU_ASSERT_EQUAL(cpu->memory[address], value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_LDH_n_A(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x1000;
    uint8_t value = 0x32;
    cpu->PC = PC;
    cpu->memory[PC] = 0x89;
    cpu->registers.A = value;
    LD_rr_A(cpu, 0xe0);
    CU_ASSERT_EQUAL(cpu->memory[0xff89], value);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
    CU_ASSERT_EQUAL(cpu->t_cycles, 12);
}

void test_LD_nn_A(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x2010;
    cpu->PC = PC;
    uint8_t value = 0xfa;
    cpu->memory[PC] = 0x12;
    cpu->memory[PC + 1] = 0x34;
    cpu->registers.A = value;
    LD_rr_A(cpu, 0xea);
    CU_ASSERT_EQUAL(read_byte(cpu, 0x1234), value);
    CU_ASSERT_EQUAL(cpu->PC, PC + 2);
    CU_ASSERT_EQUAL(cpu->t_cycles, 16);
}

void test_LD_BC_A(void)
{
    CPU *cpu = init_cpu();
    uint16_t address = 0x4f18;
    uint8_t value = 0x12;
    cpu->registers.A = value;
    cpu->memory[address] = 0;
    cpu->registers.BC = address;
    LD_rr_A(cpu, 0x02);
    CU_ASSERT_EQUAL(cpu->memory[cpu->registers.BC], value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_LD_DE_A(void)
{
    CPU *cpu = init_cpu();
    uint16_t address = 0x34ba;
    uint8_t value = 0x8c;
    cpu->registers.A = value;
    cpu->memory[address] = 0;
    cpu->registers.DE = address;
    LD_rr_A(cpu, 0x12);
    CU_ASSERT_EQUAL(cpu->memory[cpu->registers.DE], value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_rr_A Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_rr_A Instructions | LDCH_C_A loads value in register A into byte pointed to by register C",
            test_LDH_C_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_A Instructions | LDH_n_A loads value in register A into byte pointed to by extended address from next PC",
            test_LDH_n_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_A Instructions | LD_nn_A loads value in register A into byte pointed to by immediate value",
            test_LD_nn_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_A Instructions | LD_BC_A loads value in register A into byte pointed to by register BC",
            test_LD_BC_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_A Instructions | LD_DE_A loads value in register A into byte pointed to by register DE",
            test_LD_DE_A
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
