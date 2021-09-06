#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_CP_A(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x05;
    CP_r(cpu, 0xbf);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x05);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b11000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_CP_B(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x08;
    cpu->registers.B = 0x03;
    CP_r(cpu, 0xb8);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x08);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_CP_C(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x10;
    cpu->registers.C = 0x0a;
    CP_r(cpu, 0xb9);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x10);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_CP_D(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x2e;
    cpu->registers.D = 0xfd;
    CP_r(cpu, 0xba);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x2e);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_CP_E(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x22;
    cpu->registers.E = 0x55;
    CP_r(cpu, 0xbb);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x22);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01110000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_CP_H(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0xa0;
    cpu->registers.H = 0x0a;
    CP_r(cpu, 0xbc);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xa0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_CP_L(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x10;
    cpu->registers.L = 0x0a;
    CP_r(cpu, 0xbd);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x10);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 4);
}

void test_CP_n(void)
{
    CPU *cpu = init_cpu();
    cpu->PC = 0x0100;
    cpu->memory[0x0100] = 0x06;
    cpu->registers.A = 0x12;
    CP_n(cpu, 0xfe);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x12);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_CP_HL(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.HL = 0x0300;
    cpu->memory[0x0300] = 0x0c;
    cpu->registers.A = 0x0f;
    CP_HL(cpu, 0xbe);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x0f);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8 bit CP Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit CP Instructions | CP_A leaves A as is",
            test_CP_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit CP Instructions | CP_B sets A to bitwise or with B",
            test_CP_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit CP Instructions | CP_C sets A to bitwise or with C",
            test_CP_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit CP Instructions | CP_D sets A to bitwise or with D",
            test_CP_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit CP Instructions | CP_E sets A to bitwise or with E",
            test_CP_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit CP Instructions | CP_H sets A to bitwise or with H",
            test_CP_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit CP Instructions | CP_L sets A to bitwise or with L",
            test_CP_L
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit CP Instructions | CP_n sets A to bitwise or with immediate value",
        //     test_CP_n
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit CP Instructions | CP_HL sets A to bitwise or with byte in address at HL",
        //     test_CP_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit CP Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
