#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_ADC_A_B(void)
{
    CPU cpu;
    cpu.registers.A = 0x0a;
    cpu.registers.B = 0xfa;
    cpu.registers.F = 0b00010000;
    ADC_A_r(&cpu, 0x88);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x05);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_C(void)
{
    CPU cpu;
    cpu.registers.A = 0xfe;
    cpu.registers.C = 0x01;
    cpu.registers.F = 0b00010000;
    ADC_A_r(&cpu, 0x89);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_D(void)
{
    CPU cpu;
    cpu.registers.A = 0xdd;
    cpu.registers.D = 0x23;
    cpu.registers.F = 0b00000000;
    ADC_A_r(&cpu, 0x8a);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_E(void)
{
    CPU cpu;
    cpu.registers.A = 0xdd;
    cpu.registers.E = 0x23;
    cpu.registers.F = 0b00000000;
    ADC_A_r(&cpu, 0x8b);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_H(void)
{
    CPU cpu;
    cpu.registers.A = 0xdd;
    cpu.registers.H = 0x23;
    cpu.registers.F = 0b00000000;
    ADC_A_r(&cpu, 0x8c);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_L(void)
{
    CPU cpu;
    cpu.registers.A = 0xdd;
    cpu.registers.L = 0x23;
    cpu.registers.F = 0b00000000;
    ADC_A_r(&cpu, 0x8d);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_A(void)
{
    // Doubles A when carry flag is cleared
    CPU cpu;
    cpu.registers.A = 0x01;
    cpu.registers.F = 0b00000000;
    ADC_A_r(&cpu, 0x8f);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x02);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    // Doubles A then adds 1 when carry flag is set
    cpu.registers.A = 0x03;
    cpu.registers.F = 0b00010000;
    ADC_A_r(&cpu, 0x8f);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x07);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    // Sets carry flag and result is masked to 0xff when greater than 8bits
    cpu.registers.A = 0xf0;
    cpu.registers.F = 0b00000000;
    ADC_A_r(&cpu, 0x8f);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xe0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    // Sets zero flag when result is 0
    cpu.registers.A = 0x80;
    cpu.registers.F = 0b00000000;
    ADC_A_r(&cpu, 0x8f);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_n(void)
{
    CPU cpu;
    uint16_t PC = 0x0100;
    cpu.PC = PC;
    cpu.memory[PC] = 0xdc;
    cpu.registers.A = 0x23;
    cpu.registers.F = 0b00010000;
    ADC_A_n(&cpu, 0xce);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

void test_ADC_A_HL(void)
{
    CPU cpu;
    cpu.registers.A = 0xdc;
    cpu.registers.HL = 0x1000;
    cpu.memory[cpu.registers.HL] = 0x23;
    cpu.registers.F = 0b00010000;
    ADC_A_HL(&cpu, 0x8e);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8-bit ADC Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit ADC Instructions | ADC_A_A adds value in register A plus the carry flag to itself",
            test_ADC_A_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ADC Instructions | ADC_A_B adds B register value and carry flag to A register value",
            test_ADC_A_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ADC Instructions | ADC_A_C adds C register value and carry flag to A register value",
            test_ADC_A_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ADC Instructions | ADC_A_D adds D register value and carry flag to A register value",
            test_ADC_A_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ADC Instructions | ADC_A_E adds E register value and carry flag to A register value",
            test_ADC_A_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ADC Instructions | ADC_A_H adds H register value and carry flag to A register value",
            test_ADC_A_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ADC Instructions | ADC_A_L adds L register value and carry flag to A register value",
            test_ADC_A_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADC_A_n adds immediate value and carry flag to A register value",
            test_ADC_A_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADC_A_HL adds value pointed to from HL register and carry flag to A register value",
            test_ADC_A_HL
        ) == NULL) {
        printf("Failed to add test to 8-bit ADC Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

