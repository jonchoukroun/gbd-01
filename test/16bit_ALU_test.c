#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

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
    ADD_SP_e(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0x0423);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // Signed negative
    int8_t neg_value = -59;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = neg_value;
    ADD_SP_e(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 941);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // Unsigned negative
    uint8_t u_neg = 0xa8;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = u_neg;
    ADD_SP_e(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 912);
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
    ADD_SP_e(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    SP = 0x1000;
    cpu.PC = PC;
    cpu.SP = SP;
    cpu.memory[PC] = value;
    cpu.registers.F = 0;
    ADD_SP_e(&cpu);
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
    ADD_SP_e(&cpu);
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
    ADD_SP_e(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0x101e);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);

    SP = 0x1000;
    value = 0x1;
    cpu.PC = PC;
    cpu.memory[PC] = value;
    cpu.SP = SP;
    cpu.registers.F = 0b00000000;
    ADD_SP_e(&cpu);
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
    ADD_SP_e(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0x1110);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
}

void test_INC_BC(void)
{
    CPU cpu;
    cpu.registers.BC = 0x3425;
    cpu.registers.F = 0;
    INC_BC(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.BC, 0x3426);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    uint8_t flags = 0b11110000;
    cpu.registers.F = flags;
    INC_BC(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.BC, 0x3427);
    CU_ASSERT_EQUAL(cpu.registers.F, flags);

    cpu.registers.BC = 0xffff;
    cpu.registers.F = 0;
    INC_BC(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.BC, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
}

void test_INC_SP(void)
{
    CPU cpu;
    cpu.SP = 0x1212;
    cpu.registers.F = 0;
    INC_SP(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0x1213);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_DEC_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x0001;
    cpu.registers.F = 0;
    DEC_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.HL = 0x0000;
    cpu.registers.F = 0;
    DEC_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0xffff);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
}

void test_DEC_SP(void)
{
    CPU cpu;
    cpu.SP = 0x3410;
    cpu.registers.F = 0;
    DEC_SP(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, 0x340f);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("16 bit ALU unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit ALU | ADD_HL_BC adds value from register BC to register HL",
            test_ADD_HL_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_HL_DE adds value from register DE to register HL",
            test_ADD_HL_DE
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_HL_HL adds value from register HL to register HL",
            test_ADD_HL_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_HL_SP adds value from SP to register HL",
            test_ADD_HL_SP
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_SP_e adds signed 8bit immediate value to SP",
            test_ADD_SP_e
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_SP_e clears zero flag even when result is 0",
            test_ADD_SP_e_zero
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_SP_e clears subtract flag even when operand is negative",
            test_ADD_SP_e_subtract
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_SP_e sets half carry flag on 3rd bit overflow",
            test_ADD_SP_e_hcarry
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit ALU | ADD_SP_e sets carry flag on 7th bit overflow",
            test_ADD_SP_e_carry
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit ALU | INC_BC increments value in register BC and ignores flags",
            test_INC_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit ALU | INC_SP increments stack pointer and ignores flags",
            test_INC_SP
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit ALU | DEC_HL decrements value in register HL and ignores flags",
            test_DEC_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit ALU | DEC_SP decrements stack pointer and ignores flags",
            test_DEC_SP
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
