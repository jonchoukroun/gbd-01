#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LD_A_BC(void)
{
    CPU *cpu = init_cpu();
    uint16_t address = 0xabcd;
    uint8_t value = 0x0f;
    cpu->registers.BC = address;
    cpu->memory[address] = value;
    LD_A_rr(cpu, 0x0a);
    CU_ASSERT_EQUAL(cpu->registers.A, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_LD_A_DE(void)
{
    CPU *cpu = init_cpu();
    uint16_t address = 0xabcd;
    uint8_t value = 0x0f;
    cpu->registers.A = 0;
    cpu->memory[address] = value;
    cpu->registers.DE = address;
    LD_A_rr(cpu, 0x1a);
    CU_ASSERT_EQUAL(cpu->registers.A, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_LDH_A_C(void)
{
    CPU *cpu = init_cpu();
    uint8_t low_bit = 0x43;
    uint16_t address = 0xff43;
    uint8_t value = 0x1a;
    cpu->registers.C = low_bit;
    cpu->memory[address] = value;
    cpu->registers.A = 0;
    LD_A_rr(cpu, 0xf2);
    CU_ASSERT_EQUAL(cpu->registers.A, value);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_LDH_A_n(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x2020;
    uint8_t value = 0x69;
    cpu->PC = PC;
    cpu->memory[PC] = 0x12;
    cpu->memory[0xff12] = value;
    LD_A_rr(cpu, 0xf0);
    CU_ASSERT_EQUAL(cpu->registers.A, value);
    CU_ASSERT_EQUAL(cpu->PC, PC + 1);
    CU_ASSERT_EQUAL(cpu->t_cycles, 12);
}

void test_LD_A_nn(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC = 0x1001;
    cpu->PC = PC;
    uint8_t value = 0x23;
    cpu->memory[PC] = 0xab;
    cpu->memory[PC + 1] = 0xcd;
    cpu->memory[0xabcd] = value;
    LD_A_rr(cpu, 0xfa);
    CU_ASSERT_EQUAL(cpu->registers.A, value);
    CU_ASSERT_EQUAL(cpu->PC, PC + 2);
    CU_ASSERT_EQUAL(cpu->t_cycles, 16);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_A_rr Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_A_rr Instructions | LD_A_BC loads byte pointed to by BC register into register A",
            test_LD_A_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_A_rr Instructions | LD_A_DE loads byte pointed to by DE register into register A",
            test_LD_A_DE
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_A_rr Instructions | LDH_A_C loads byte pointed to by register C into register A",
            test_LDH_A_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_0xFFn loads byte at extended address from next PC into A",
            test_LDH_A_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_nn loads byte pointed to by immediate value into register A",
            test_LD_A_nn
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
