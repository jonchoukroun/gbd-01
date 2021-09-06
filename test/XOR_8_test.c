#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_XOR_A(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x23;
    XOR_r(cpu, 0xaf);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x23);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_XOR_B(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0xaa;
    cpu->registers.B = 0x11;
    XOR_r(cpu, 0xa8);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_XOR_C(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0xaa;
    cpu->registers.C = 0x11;
    XOR_r(cpu, 0xa9);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_XOR_D(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0xaa;
    cpu->registers.D = 0x11;
    XOR_r(cpu, 0xaa);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_XOR_E(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0xaa;
    cpu->registers.E = 0x11;
    XOR_r(cpu, 0xab);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_XOR_H(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0xaa;
    cpu->registers.H = 0x11;
    XOR_r(cpu, 0xac);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_XOR_L(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0xaa;
    cpu->registers.L = 0x11;
    XOR_r(cpu, 0xad);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xbb);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_XOR_n(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x0;
    cpu->PC = 0x500;
    cpu->memory[cpu->PC] = 0x5;
    XOR_n(cpu, 0xee);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x5);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_XOR_HL(void)
{
    CPU *cpu = init_cpu();
    uint8_t value = 0x5a;
    uint16_t address = 0x1200;
    cpu->registers.HL = address;
    cpu->memory[address] = value;
    cpu->registers.A = 0x12;
    XOR_HL(cpu, 0xae);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x5a)
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8 bit XOR Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_A leaves A as is",
            test_XOR_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_B sets A to bitwise or with B",
            test_XOR_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_C sets A to bitwise or with C",
            test_XOR_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_D sets A to bitwise or with D",
            test_XOR_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_E sets A to bitwise or with E",
            test_XOR_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_H sets A to bitwise or with H",
            test_XOR_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_L sets A to bitwise or with L",
            test_XOR_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_n sets A to bitwise or with immediate value",
            test_XOR_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit XOR Instructions | XOR_HL sets A to bitwise or with byte in address at HL",
            test_XOR_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit XOR Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
