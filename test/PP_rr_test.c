#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_PUSH_BC(void)
{
    CPU cpu;
    uint16_t SP = 0xfffe;
    cpu.SP = SP;
    cpu.registers.BC = 0xabcd;
    PUSH_rr(&cpu, 0xc5);
    CU_ASSERT_EQUAL(cpu.memory[SP - 1], 0xcd);
    CU_ASSERT_EQUAL(cpu.memory[SP - 2], 0xab);
    CU_ASSERT_EQUAL(cpu.SP, SP - 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_PUSH_DE(void)
{
    CPU cpu;
    uint16_t SP = ADDRESS_BUS_SIZE;
    uint16_t value = 0xabcd;
    cpu.SP = SP;
    cpu.registers.DE = value;
    PUSH_rr(&cpu, 0xd5);
    CU_ASSERT_EQUAL(cpu.memory[SP - 1], 0xcd);
    CU_ASSERT_EQUAL(cpu.memory[SP - 2], 0xab);
    CU_ASSERT_EQUAL(cpu.SP, SP - 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_PUSH_HL(void)
{
    CPU cpu;
    uint16_t SP = ADDRESS_BUS_SIZE;
    uint16_t value = 0xabcd;
    cpu.SP = SP;
    cpu.registers.HL = value;
    PUSH_rr(&cpu, 0xe5);
    CU_ASSERT_EQUAL(cpu.memory[SP - 1], 0xcd);
    CU_ASSERT_EQUAL(cpu.memory[SP - 2], 0xab);
    CU_ASSERT_EQUAL(cpu.SP, SP - 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_PUSH_AF(void)
{
    CPU cpu;
    uint16_t SP = ADDRESS_BUS_SIZE;
    uint16_t value = 0xabcd;
    cpu.SP = SP;
    cpu.registers.AF = value;
    PUSH_rr(&cpu, 0xf5);
    CU_ASSERT_EQUAL(cpu.memory[cpu.SP], 0xab);
    CU_ASSERT_EQUAL(cpu.memory[cpu.SP + 1], 0xcd);
    CU_ASSERT_EQUAL(cpu.SP, SP - 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_POP_BC(void)
{
    CPU cpu;
    uint16_t SP = 0xfffc;
    cpu.SP = SP;
    cpu.memory[SP] = 0x5f;
    cpu.memory[SP + 1] = 0x3c;
    POP_rr(&cpu, 0xc1);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x3c);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x5f);
    CU_ASSERT_EQUAL(cpu.SP, SP + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_POP_DE(void)
{
    CPU cpu;
    uint16_t SP = 0xfffc;
    cpu.SP = SP;
    cpu.memory[SP] = 0x5f;
    cpu.memory[SP + 1] = 0x3c;
    POP_rr(&cpu, 0xd1);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x3c);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x5f);
    CU_ASSERT_EQUAL(cpu.SP, SP + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_POP_HL(void)
{
    CPU cpu;
    uint16_t SP = 0xfffc;
    cpu.SP = SP;
    cpu.memory[SP] = 0x5f;
    cpu.memory[SP + 1] = 0x3c;
    POP_rr(&cpu, 0xe1);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x3c);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x5f);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_POP_AF(void)
{
    CPU cpu;
    uint16_t SP = 0xfffc;
    cpu.SP = SP;
    cpu.memory[SP] = 0x5f;
    cpu.memory[SP + 1] = 0x3c;
    POP_rr(&cpu, 0xf1);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x3c);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x5f);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("PP_rr Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "PP_rr Instructions | PUSH_BC pushes value from register BC onto stack and decrements SP",
            test_PUSH_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PP_rr Instructions | PUSH_DE pushes value from register DE onto stack and decrements SP",
            test_PUSH_DE
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PP_rr Instructions | PUSH_HL pushes value from register HL onto stack and decrements SP",
            test_PUSH_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PP_rr Instructions | PUSH_AF pushes value from register AF onto stack and decrements SP",
            test_PUSH_AF
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PP_rr Instructions | POP_BC pops value from stack into register BC and increments SP",
            test_POP_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PP_rr Instructions | POP_DE pops value from stack into register DE and increments SP",
            test_POP_DE
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PP_rr Instructions | POP_HL pops value from stack into register HL and increments SP",
            test_POP_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PP_rr Instructions | POP_AF pops value from stack into register AF and increments SP",
            test_POP_AF
        ) == NULL) {
        printf("Failed to add test to PP_rr unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
