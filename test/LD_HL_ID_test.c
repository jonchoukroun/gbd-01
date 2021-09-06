#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LD_A_HLI(void)
{
    CPU *cpu = init_cpu();
    uint16_t HL = 0x1234;
    uint8_t value = 0xab;
    cpu->registers.HL = HL;
    cpu->memory[HL] = value;
    LD_A_HLI(cpu, 0x2a);
    CU_ASSERT_EQUAL(cpu->registers.A, value);
    CU_ASSERT_EQUAL(cpu->registers.HL, HL + 1);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_LD_A_HLD(void)
{
    CPU *cpu = init_cpu();
    uint16_t HL = 0x1234;
    uint8_t value = 0xab;
    cpu->registers.HL = HL;
    cpu->memory[HL] = value;
    LD_A_HLD(cpu, 0x3a);
    CU_ASSERT_EQUAL(cpu->registers.A, value);
    CU_ASSERT_EQUAL(cpu->registers.HL, HL - 1);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_LD_HLI_A(void)
{
    CPU *cpu = init_cpu();
    uint16_t HL = 0x1234;
    uint8_t value = 0xdd;
    cpu->registers.HL = HL;
    cpu->registers.A = value;
    LD_HLI_A(cpu, 0x22);
    CU_ASSERT_EQUAL(cpu->memory[HL], value);
    CU_ASSERT_EQUAL(cpu->registers.HL, HL + 1);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_LD_HLD_A(void)
{
    CPU *cpu = init_cpu();
    uint16_t HL = 0x1234;
    uint8_t value = 0xcc;
    cpu->registers.HL = HL;
    cpu->registers.A = value;
    LD_HLD_A(cpu, 0x32);
    CU_ASSERT_EQUAL(cpu->memory[HL], value);
    CU_ASSERT_EQUAL(cpu->registers.HL, HL - 1);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_HL_ID Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_HL_ID Instructions | LD_A_HLI loads byte at address in HL then increments HL",
            test_LD_A_HLI
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_ID Instructions | LD_A_HLD loads byte at address in HL then decrements HL",
            test_LD_A_HLD
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_ID Instructions | LD_HLI_A loads value in A into address in HL then increments HL",
            test_LD_HLI_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_ID Instructions | LD_HLD_A loads value in A into address in HL then decrements HL",
            test_LD_HLD_A
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
