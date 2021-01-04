#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_ADD_A_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x80;
    cpu.registers.F = 0b00010000;
    ADD_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADD_A_B(void)
{
    CPU cpu;
    cpu.registers.A = 0x34;
    cpu.registers.B = 0x0f;
    cpu.registers.F = 0b00000000;
    ADD_A_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x43);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADD_A_C(void)
{
    CPU cpu;
    cpu.registers.A = 0xfe;
    cpu.registers.C = 0x0a;
    cpu.registers.F = 0b00000000;
    ADD_A_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x08);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
}

void test_ADD_A_HL(void)
{
    CPU cpu;
    uint16_t addr = 0x0100;
    cpu.registers.A = 0x12;
    cpu.registers.HL = addr;
    cpu.registers.F = 0b00000000;
    cpu.memory[cpu.registers.HL] = 0x23;
    ADD_A_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x35);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_A_n(void)
{
    CPU cpu;
    uint16_t PC = 0x0100;
    cpu.PC = PC;
    cpu.memory[PC] = 0xda;
    cpu.registers.A = 0xef;
    cpu.registers.F = 0b11110000;
    ADD_A_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xc9);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_HL_BC(void)
{
    CPU cpu;
    cpu.registers.HL = 0x1234;
    cpu.registers.BC = 0x4321;
    cpu.registers.F = 0;
    ADD_HL_BC(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x5555);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_HL_DE(void)
{
    CPU cpu;
    cpu.registers.HL = 0x07f3;
    cpu.registers.DE = 0x0711;
    cpu.registers.F = 0;
    ADD_HL_DE(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0xf04);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_HL_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0xabcd;
    cpu.registers.F = 0;
    ADD_HL_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x579a);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_HL_SP(void)
{
    CPU cpu;
    cpu.registers.HL = 0x0101;
    cpu.SP = 0x1010;
    cpu.registers.F = 0;
    ADD_HL_SP(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x1111);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_SP_nn(void)
{
    // Signed positive
    CPU cpu;
    uint16_t PC = 0x0100;
    uint16_t SP = 1000;
    int8_t pos_value = 59;
    cpu.PC = PC;
    cpu.memory[PC] = pos_value;
    cpu.SP = SP;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 1059);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // Signed negative
    int8_t neg_value = -59;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = neg_value;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 941);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // Unsigned negative
    uint8_t u_neg = 0xa8;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = u_neg;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 912);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_ADD_SP_nn_zero(void)
{
    CPU cpu;
    uint16_t PC = 0x100;
    uint16_t SP = 0x0000a;
    int8_t value = -0xa;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = value;
    cpu.registers.F = 0;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    SP = 0x1000;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = value;
    cpu.registers.F = 0;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0xff6);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
}

void test_ADD_SP_nn_subtract(void)
{
    CPU cpu;
    uint16_t PC = 0x100;
    uint16_t SP = 0x1000;
    int8_t value = -0xa;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = value;
    cpu.registers.F = 0b00000000;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0xff6);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
}

void test_ADD_SP_nn_hcarry(void)
{
    CPU cpu;
    uint16_t PC = 0x100;
    uint16_t SP = 0x100f;
    uint8_t value = 0xf;
    cpu.PC = PC;
    cpu.memory[PC] = value;
    cpu.SP = SP;
    cpu.registers.F = 0b00000000;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0x101e);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);

    SP = 0x1000;
    value = 0x1;
    cpu.PC = PC;
    cpu.memory[PC] = value;
    cpu.SP = SP;
    cpu.registers.F = 0b00000000;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0x1001);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
}

void test_ADD_SP_nn_carry(void)
{
    CPU cpu;
    uint16_t PC = 0x100;
    uint16_t SP = 0x10a0;
    uint8_t value = 0x70;
    cpu.PC = PC;
    cpu.memory[PC] = value;
    cpu.SP = SP;
    cpu.registers.F = 0b00000000;
    ADD_SP_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0x1110);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_ADC_A_A(void)
{
    // Doubles A when carry flag is cleared
    CPU cpu;
    cpu.registers.A = 0x01;
    cpu.registers.F = 0b00000000;
    ADC_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x02);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    // Doubles A then adds 1 when carry flag is set
    cpu.registers.A = 0x03;
    cpu.registers.F = 0b00010000;
    ADC_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x07);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    // Sets carry flag and result is masked to 0xff when greater than 8bits
    cpu.registers.A = 0xf0;
    cpu.registers.F = 0b00000000;
    ADC_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xe0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    // Sets zero flag when result is 0
    cpu.registers.A = 0x80;
    cpu.registers.F = 0b00000000;
    ADC_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_B(void)
{
    CPU cpu;
    cpu.registers.A = 0x0a;
    cpu.registers.B = 0xfa;
    cpu.registers.F = 0b00010000;
    ADC_A_B(&cpu);
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
    ADC_A_C(&cpu);
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
    ADC_A_D(&cpu);
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
    ADC_A_E(&cpu);
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
    ADC_A_H(&cpu);
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
    ADC_A_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_ADC_A_HL(void)
{
    CPU cpu;
    cpu.registers.A = 0xdc;
    cpu.registers.HL = 0x1000;
    cpu.memory[cpu.registers.HL] = 0x23;
    cpu.registers.F = 0b00010000;
    ADC_A_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADC_A_n(void)
{
    CPU cpu;
    uint16_t PC = 0x0100;
    cpu.PC = PC;
    cpu.memory[PC] = 0xdc;
    cpu.registers.A = 0x23;
    cpu.registers.F = 0b00010000;
    ADC_A_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Arithmetic unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "Arithmetic | ADD_A_A doubles A register value and ignore carry flag",
            test_ADD_A_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_A_B adds value in register B to register A",
            test_ADD_A_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_A_C adds C into A and sets carry flag when result is over 0xff",
            test_ADD_A_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_A_HL adds value in register HL to register A",
            test_ADD_A_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_A_n adds immediate value to register A",
            test_ADD_A_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_HL_BC adds value from register BC to register HL",
            test_ADD_HL_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_HL_DE adds value from register DE to register HL",
            test_ADD_HL_DE
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_HL_HL adds value from register HL to register HL",
            test_ADD_HL_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_HL_SP adds value from SP to register HL",
            test_ADD_HL_SP
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_SP_nn adds signed 8bit immediate value to SP",
            test_ADD_SP_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_SP_nn clears zero flag even when result is 0",
            test_ADD_SP_nn_zero
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_SP_nn clears subtract flag even when operand is negative",
            test_ADD_SP_nn_subtract
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_SP_nn sets half carry flag on 3rd bit overflow",
            test_ADD_SP_nn_hcarry
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADD_SP_nn sets carry flag on 7th bit overflow",
            test_ADD_SP_nn_carry
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_A adds value in register A plus the carry flag to itself",
            test_ADC_A_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_B adds B register value and carry flag to A register value",
            test_ADC_A_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_C adds C register value and carry flag to A register value",
            test_ADC_A_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_D adds D register value and carry flag to A register value",
            test_ADC_A_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_E adds E register value and carry flag to A register value",
            test_ADC_A_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_H adds H register value and carry flag to A register value",
            test_ADC_A_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_L adds L register value and carry flag to A register value",
            test_ADC_A_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_HL adds value pointed to from HL register and carry flag to A register value",
            test_ADC_A_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Arithmetic | ADC_A_n adds immediate value and carry flag to A register value",
            test_ADC_A_n
        ) == NULL) {
        printf("Failed to add test to arithmetic unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
