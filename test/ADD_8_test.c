#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_ADD_A_B(void)
{
    CPU cpu;
    cpu.registers.A = 0x34;
    cpu.registers.B = 0x0f;
    ADD_A_r(&cpu, 0x80);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x43);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADD_A_C(void)
{
    CPU cpu;
    cpu.registers.A = 0xfe;
    cpu.registers.C = 0x0a;
    ADD_A_r(&cpu, 0x81);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x08);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
}

void test_ADD_A_D(void)
{
    CPU cpu;
    cpu.registers.A = 0x31;
    cpu.registers.D = 0x13;
    ADD_A_r(&cpu, 0x82);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x44);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_ADD_A_E(void)
{
    CPU cpu;
    cpu.registers.A = 0xee;
    cpu.registers.E = 0xdd;
    ADD_A_r(&cpu, 0xcb);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xcb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
}

void test_ADD_A_H(void)
{
    CPU cpu;
    cpu.registers.A = 0xee;
    cpu.registers.H = 0xdd;
    ADD_A_r(&cpu, 0xcb);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xcb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
}

void test_ADD_A_L(void)
{
    CPU cpu;
    cpu.registers.A = 0xee;
    cpu.registers.L = 0xdd;
    ADD_A_r(&cpu, 0xcb);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xcb);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
}

void test_ADD_A_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x80;
    ADD_A_r(&cpu, 0x87);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADD_A_n(void)
{
    CPU cpu;
    uint16_t PC = 0x0100;
    cpu.PC = PC;
    cpu.memory[PC] = 0xda;
    cpu.registers.A = 0xef;
    cpu.registers.F = 0b11110000;
    ADD_A_n(&cpu, 0xc6);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xc9);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_A_HL(void)
{
    CPU cpu;
    uint16_t addr = 0x0100;
    cpu.registers.A = 0x12;
    cpu.registers.HL = addr;
    cpu.registers.F = 0b00000000;
    cpu.memory[cpu.registers.HL] = 0x23;
    ADD_A_HL(&cpu, 0x86);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x35);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8-bit ADD Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8-bit ADD Instructions | ADD_A_B adds value in register B to register A",
            test_ADD_A_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8-bit ADD Instructions | ADD_A_C adds C into A and sets carry flag when result is over 0xff",
            test_ADD_A_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8-bit ADD Instructions | ADD_A_D adds D into A",
            test_ADD_A_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8-bit ADD Instructions | ADD_A_E adds E into A",
            test_ADD_A_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8-bit ADD Instructions | ADD_A_H adds H into A",
            test_ADD_A_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8-bit ADD Instructions | ADD_A_L adds L into A",
            test_ADD_A_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8-bit ADD Instructions | ADD_A_A doubles A register value and ignores carry flag",
            test_ADD_A_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_A_n adds immediate value to register A",
            test_ADD_A_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_A_HL adds value in register HL to register A",
            test_ADD_A_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit ADD Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
