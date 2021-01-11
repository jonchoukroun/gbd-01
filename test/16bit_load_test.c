#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LD_BC_nn(void)
{
    CPU cpu;
    uint16_t PC = 0x2001;
    cpu.PC = PC;
    cpu.memory[PC] = 0x69;
    cpu.memory[PC + 1] = 0x96;
    LD_BC_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.BC, 0x6996);
    CU_ASSERT_EQUAL(cpu.PC, PC + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_LD_DE_nn(void)
{
    CPU cpu;
    uint16_t PC = 0x3541;
    cpu.PC = PC;
    cpu.memory[PC] = 0x12;
    cpu.memory[PC + 1] = 0xfa;
    LD_DE_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.DE, 0x12fa);
    CU_ASSERT_EQUAL(cpu.PC, PC + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_LD_HL_nn(void)
{
    CPU cpu;
    uint16_t PC = 0x2345;
    cpu.PC = PC;
    cpu.memory[PC] = 0xba;
    cpu.memory[PC + 1] = 0xfa;
    LD_HL_nn(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0xbafa);
    CU_ASSERT_EQUAL(cpu.PC, PC + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_LD_nn_SP(void)
{
    CPU cpu;
    uint16_t PC = 0x2000;
    uint16_t value = 0xabce;
    cpu.PC = PC;
    cpu.memory[PC] = 0x23;
    cpu.memory[PC + 1] = 0x45;
    cpu.SP = value;
    LD_nn_SP(&cpu);
    CU_ASSERT_EQUAL(read_word(&cpu, 0x2345), value);
    CU_ASSERT_EQUAL(cpu.PC, PC + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 20);
}

void test_LD_SP_HL(void)
{
    CPU cpu;
    uint16_t value = 0xdef0;
    cpu.registers.HL = value;
    LD_SP_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.SP, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_HL_SPe(void)
{
    CPU cpu;
    uint16_t PC = 0x0100;

    // Signed positive; no carries
    int8_t pos_value = 2;
    cpu.PC = PC;
    cpu.memory[PC] = pos_value;
    cpu.SP = 0xfff8;
    LD_HL_SPe(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0xfffa);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

    // Signed negative; 7th bit borrow
    int8_t neg_value = -100;
    cpu.PC = PC;
    cpu.memory[PC] = neg_value;
    cpu.SP = 0x1234;
    LD_HL_SPe(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x11d0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);

    // Unsinged positive, 3rd and 7th bit carries
    uint8_t u_pos = 0x6e;
    cpu.PC = PC;
    cpu.memory[PC] = u_pos;
    cpu.SP = 0x459e;
    LD_HL_SPe(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x460c);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);

    // Unsigned negative, 3rd bit borrow
    uint8_t u_neg = 0xa8;
    cpu.PC = PC;
    cpu.memory[PC] = u_neg;
    cpu.SP = 0xfda1;
    LD_HL_SPe(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0xfd49);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);

    // Zero, no borrow
    u_neg = 0xd3;
    cpu.PC = PC;
    cpu.memory[PC] = u_neg;
    cpu.SP = 0x002d;
    LD_HL_SPe(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
}

void test_PUSH_AF(void)
{
    CPU cpu;
    uint16_t SP = ADDRESS_BUS_SIZE;
    uint16_t value = 0xabcd;
    cpu.SP = SP;
    cpu.registers.AF = value;
    PUSH_AF(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.SP], 0xab);
    CU_ASSERT_EQUAL(cpu.memory[cpu.SP + 1], 0xcd);
    CU_ASSERT_EQUAL(cpu.SP, SP - 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_PUSH_BC(void)
{
    CPU cpu;
    uint16_t SP = ADDRESS_BUS_SIZE;
    uint16_t value = 0xabcd;
    cpu.SP = SP;
    cpu.registers.BC = value;
    PUSH_BC(&cpu);
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
    PUSH_DE(&cpu);
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
    PUSH_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[SP - 1], 0xcd);
    CU_ASSERT_EQUAL(cpu.memory[SP - 2], 0xab);
    CU_ASSERT_EQUAL(cpu.SP, SP - 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_POP_AF(void)
{
    CPU cpu;
    uint16_t SP = 0;
    cpu.SP = SP;
    cpu.memory[SP] = 0x12;
    cpu.memory[SP + 1] = 0x34;
    POP_AF(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.AF, 0x1234);
    CU_ASSERT_EQUAL(cpu.SP, SP + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_POP_BC(void)
{
    CPU cpu;
    uint16_t SP = 0;
    cpu.SP = SP;
    cpu.memory[SP] = 0x12;
    cpu.memory[SP + 1] = 0x34;
    POP_BC(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.BC, 0x1234);
    CU_ASSERT_EQUAL(cpu.SP, SP + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_POP_DE(void)
{
    CPU cpu;
    uint16_t SP = 0;
    cpu.SP = SP;
    cpu.memory[SP] = 0x12;
    cpu.memory[SP + 1] = 0x34;
    POP_DE(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.DE, 0x1234);
    CU_ASSERT_EQUAL(cpu.SP, SP + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_POP_HL(void)
{
    CPU cpu;
    uint16_t SP = 0;
    cpu.SP = SP;
    cpu.memory[SP] = 0x12;
    cpu.memory[SP + 1] = 0x34;
    POP_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0x1234);
    CU_ASSERT_EQUAL(cpu.SP, SP + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("16 bit LD Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "16 bit LD Instructions | LD_BC_nn loads byte pointed to by immediate value into register BC",
            test_LD_BC_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | LD_DE_nn loads byte pointed to by immediate value into register DE",
            test_LD_DE_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | LD_HL_nn loads byte pointed to by immediate value into register HL",
            test_LD_HL_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | LD_nn_SP loads value from SP into address pointed to by immediate data",
            test_LD_nn_SP
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | LD_SP_HL loads value in HL register into SP",
            test_LD_SP_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | LD_HL_SPe adds immediate signed byte to SP and stores in register HL",
            test_LD_HL_SPe
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PUSH | PUSH_AF pushes value from register AF onto stack and decrements SP",
            test_PUSH_AF
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PUSH | PUSH_BC pushes value from register BC onto stack and decrements SP",
            test_PUSH_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "PUSH | PUSH_DE pushes value from register DE onto stack and decrements SP",
            test_PUSH_DE
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | PUSH_HL pushes value from register HL onto stack and decrements SP",
            test_PUSH_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | POP_AF pops value from stack into register AF and increments SP",
            test_POP_AF
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | POP_BC pops value from stack into register BC and increments SP",
            test_POP_BC
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | POP_DE pops value from stack into register DE and increments SP",
            test_POP_DE
        ) == NULL ||
        CU_add_test(
            test_suite,
            "16 bit LD Instructions | POP_HL pops value from stack into register HL and increments SP",
            test_POP_HL
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
