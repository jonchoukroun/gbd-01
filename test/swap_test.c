#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_SWAP_B(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.B = 0;
    cpu->registers.F = 0;
    SWAP(cpu, 0x30);
    CU_ASSERT_EQUAL(cpu->registers.B, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.B = 0xab;
    cpu->registers.F = 0b11110000;
    SWAP(cpu, 0x30);
    CU_ASSERT_EQUAL(cpu->registers.B, 0xba);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SWAP_C(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.C = 0;
    cpu->registers.F = 0;
    SWAP(cpu, 0x31);
    CU_ASSERT_EQUAL(cpu->registers.C, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.C = 0xab;
    cpu->registers.F = 0b11110000;
    SWAP(cpu, 0x31);
    CU_ASSERT_EQUAL(cpu->registers.C, 0xba);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SWAP_D(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.D = 0;
    cpu->registers.F = 0;
    SWAP(cpu, 0x32);
    CU_ASSERT_EQUAL(cpu->registers.D, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.D = 0xab;
    cpu->registers.F = 0b11110000;
    SWAP(cpu, 0x32);
    CU_ASSERT_EQUAL(cpu->registers.D, 0xba);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SWAP_E(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.E = 0;
    cpu->registers.F = 0;
    SWAP(cpu, 0x33);
    CU_ASSERT_EQUAL(cpu->registers.E, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.E = 0xab;
    cpu->registers.F = 0b11110000;
    SWAP(cpu, 0x33);
    CU_ASSERT_EQUAL(cpu->registers.E, 0xba);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SWAP_H(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.H = 0;
    cpu->registers.F = 0;
    SWAP(cpu, 0x34);
    CU_ASSERT_EQUAL(cpu->registers.H, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.H = 0xab;
    cpu->registers.F = 0b11110000;
    SWAP(cpu, 0x34);
    CU_ASSERT_EQUAL(cpu->registers.H, 0xba);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SWAP_L(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.L = 0;
    cpu->registers.F = 0;
    SWAP(cpu, 0x35);
    CU_ASSERT_EQUAL(cpu->registers.L, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.L = 0xab;
    cpu->registers.F = 0b11110000;
    SWAP(cpu, 0x35);
    CU_ASSERT_EQUAL(cpu->registers.L, 0xba);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SWAP_HL(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.HL = 0x2222;
    cpu->memory[cpu->registers.HL] = 0x21;
    cpu->registers.F = 0;
    SWAP_HL(cpu, 0x36);
    CU_ASSERT_EQUAL(cpu->memory[cpu->registers.HL], 0x12);
    CU_ASSERT_EQUAL(cpu->registers.HL, 0x2222);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 16);
}

void test_SWAP_A(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0;
    cpu->registers.F = 0;
    SWAP(cpu, 0x37);
    CU_ASSERT_EQUAL(cpu->registers.A, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.A = 0xab;
    cpu->registers.F = 0b11110000;
    SWAP(cpu, 0x37);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xba);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Swap instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "Swap instructions | SWAP_B swaps upper, lower nibbles of register B",
            test_SWAP_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Swap instructions | SWAP_C swaps upper, lower nibbles of register C",
            test_SWAP_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Swap instructions | SWAP_D swaps upper, lower nibbles of register D",
            test_SWAP_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Swap instructions | SWAP_E swaps upper, lower nibbles of register E",
            test_SWAP_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Swap instructions | SWAP_H swaps upper, lower nibbles of register H",
            test_SWAP_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Swap instructions | SWAP_L swaps upper, lower nibbles of register L",
            test_SWAP_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Swap instructions | SWAP_HL swaps upper, lower nibbles of memory contents at address in register HL",
            test_SWAP_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Swap instructions | SWAP_A swaps upper, lower nibbles of register A",
            test_SWAP_A
        ) == NULL) {
        printf("Failed to add test to Swap instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
