#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_ADD_HL_BC(void)
{
    CPU cpu;
    cpu.registers.HL = 0x8a23;
    cpu.registers.BC = 0x0605;
    cpu.registers.F = 0;
    ADD_rr(&cpu, 0x09);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x9028);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_HL_DE(void)
{
    CPU cpu;
    cpu.registers.HL = 0;
    cpu.registers.DE = 0x0711;
    cpu.registers.F = 0b10000000;
    ADD_rr(&cpu, 0x19);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x0711);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_HL_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x8a23;
    cpu.registers.F = 0;
    ADD_rr(&cpu, 0x29);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x1446);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_HL_SP(void)
{
    CPU cpu;
    cpu.registers.HL = 0x0101;
    cpu.SP = 0x1010;
    cpu.registers.F = 0;
    ADD_rr(&cpu, 0x39);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x1111);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_ADD_SP_e(void)
{
    // Signed positive, H, C carry
    CPU cpu;
    uint16_t PC = 0x0100;
    uint16_t SP = 0x03e8;
    int8_t pos_value = 0x3b;
    cpu.PC = PC;
    cpu.memory[PC] = pos_value;
    cpu.SP = SP;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 0x0423);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // Signed negative
    int8_t neg_value = -59;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = neg_value;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 941);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // Unsigned negative
    uint8_t u_neg = 0xa8;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = u_neg;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 912);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    pos_value = 2;
    cpu.SP = 0xfff8;
    cpu.PC = PC;
    cpu.memory[PC] = pos_value;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffa);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_ADD_SP_e_zero(void)
{
    CPU cpu;
    uint16_t PC = 0x100;
    uint16_t SP = 0x0000a;
    int8_t value = -0xa;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = value;
    cpu.registers.F = 0;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    SP = 0x1000;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = value;
    cpu.registers.F = 0;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 0xff6);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
}

void test_ADD_SP_e_subtract(void)
{
    CPU cpu;
    uint16_t PC = 0x100;
    uint16_t SP = 0x1000;
    uint8_t value = 0xc4;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = value;
    cpu.registers.F = 0b00000000;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 0x0fc4);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
}

void test_ADD_SP_e_hcarry(void)
{
    CPU cpu;
    uint16_t PC = 0x100;
    uint16_t SP = 0x100f;
    uint8_t value = 0xf;
    cpu.PC = PC;
    cpu.memory[PC] = value;
    cpu.SP = SP;
    cpu.registers.F = 0b00000000;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 0x101e);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);

    SP = 0x1000;
    value = 0x1;
    cpu.PC = PC;
    cpu.memory[PC] = value;
    cpu.SP = SP;
    cpu.registers.F = 0b00000000;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 0x1001);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
}

void test_ADD_SP_e_carry(void)
{
    CPU cpu;
    uint16_t PC = 0x100;
    uint16_t SP = 0x10a0;
    uint8_t value = 0x70;
    cpu.PC = PC;
    cpu.memory[PC] = value;
    cpu.SP = SP;
    cpu.registers.F = 0b00000000;
    ADD_e(&cpu, 0xe8);
    CU_ASSERT_EQUAL(cpu.SP, 0x1110);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("16-bit ADD Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "16-bit ALU Instructions | ADD_HL_BC adds value from register BC to register HL",
            test_ADD_HL_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16-bit ALU Instructions | ADD_HL_DE adds value from register DE to register HL",
            test_ADD_HL_DE
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16-bit ALU Instructions | ADD_HL_HL adds value from register HL to register HL",
            test_ADD_HL_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16-bit ALU Instructions | ADD_HL_SP adds value from SP to register HL",
            test_ADD_HL_SP
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16-bit ADD Instructions | ADD_SP_e adds signed 8bit immediate value to SP",
            test_ADD_SP_e
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16-bit ADD Instructions | ADD_SP_e clears zero flag even when result is 0",
            test_ADD_SP_e_zero
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16-bit ADD Instructions | ADD_SP_e clears subtract flag even when operand is negative",
            test_ADD_SP_e_subtract
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16-bit ADD Instructions | ADD_SP_e sets half carry flag on 3rd bit overflow",
            test_ADD_SP_e_hcarry
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16-bit ADD Instructions | ADD_SP_e sets carry flag on 7th bit overflow",
            test_ADD_SP_e_carry
        ) == NULL) {
        printf("Failed to add test to 16-bit ADD Instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

