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
    LD_rr_nn(&cpu, 0x01);
    CU_ASSERT_EQUAL(cpu.registers.BC, 0x6996);
    CU_ASSERT_EQUAL(cpu.PC, PC + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_LD_DE_nn(void)
{
    CPU cpu;
    uint16_t PC = 0x3541;
    cpu.PC = PC;
    cpu.memory[PC] = 0x3a;
    cpu.memory[PC + 1] = 0x5b;
    LD_rr_nn(&cpu, 0x11);
    CU_ASSERT_EQUAL(cpu.registers.D, 0x3a);
    CU_ASSERT_EQUAL(cpu.registers.E, 0x5b);
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
    LD_rr_nn(&cpu, 0x21);
    CU_ASSERT_EQUAL(cpu.registers.HL, 0xbafa);
    CU_ASSERT_EQUAL(cpu.PC, PC + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void test_LD_SP_nn(void)
{
    CPU cpu;
    uint16_t PC = 0x0100;
    cpu.PC = PC;
    cpu.memory[PC] = 0xab;
    cpu.memory[PC + 1] = 0xcd;
    LD_rr_nn(&cpu, 0x31);
    CU_ASSERT_EQUAL(cpu.SP, 0xabcd);
    CU_ASSERT_EQUAL(cpu.PC, PC + 2);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

}

void test_LD_SP_HL(void)
{
    CPU cpu;
    uint16_t value = 0xdef0;
    cpu.registers.HL = value;
    LD_SP_HL(&cpu, 0xf9);
    CU_ASSERT_EQUAL(cpu.SP, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

// void test_LD_nn_SP(void)
// {
//     CPU cpu;
//     uint16_t PC = 0x2000;
//     uint16_t value = 0xabce;
//     cpu.PC = PC;
//     cpu.memory[PC] = 0x23;
//     cpu.memory[PC + 1] = 0x45;
//     cpu.SP = value;
//     LD_nn_SP(&cpu);
//     CU_ASSERT_EQUAL(read_word(&cpu, 0x2345), value);
//     CU_ASSERT_EQUAL(cpu.PC, PC + 2);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 20);
// }

// void test_LD_HL_SPe(void)
// {
//     CPU cpu;
//     uint16_t PC = 0x0100;

//     // Signed positive; no carries
//     int8_t pos_value = 2;
//     cpu.PC = PC;
//     cpu.memory[PC] = pos_value;
//     cpu.SP = 0xfff8;
//     LD_HL_SPe(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.HL, 0xfffa);
//     CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
//     CU_ASSERT_EQUAL(cpu.PC, PC + 1);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 12);

//     // Signed negative; 7th bit borrow
//     int8_t neg_value = -100;
//     cpu.PC = PC;
//     cpu.memory[PC] = neg_value;
//     cpu.SP = 0x1234;
//     LD_HL_SPe(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.HL, 0x11d0);
//     CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
//     CU_ASSERT_EQUAL(cpu.PC, PC + 1);

//     // Unsinged positive, 3rd and 7th bit carries
//     uint8_t u_pos = 0x6e;
//     cpu.PC = PC;
//     cpu.memory[PC] = u_pos;
//     cpu.SP = 0x459e;
//     LD_HL_SPe(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.HL, 0x460c);
//     CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);

//     // Unsigned negative, 3rd bit borrow
//     uint8_t u_neg = 0xa8;
//     cpu.PC = PC;
//     cpu.memory[PC] = u_neg;
//     cpu.SP = 0xfda1;
//     LD_HL_SPe(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.HL, 0xfd49);
//     CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);

//     // Zero, no borrow
//     u_neg = 0xd3;
//     cpu.PC = PC;
//     cpu.memory[PC] = u_neg;
//     cpu.SP = 0x002d;
//     LD_HL_SPe(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.HL, 0);
//     CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
// }

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_rr_nn Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_BC_nn loads 2 immediate bytes into register BC",
            test_LD_BC_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_DE_nn loads 2 immediate bytes into register DE",
            test_LD_DE_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_HL_nn loads 2 immediate bytes into register HL",
            test_LD_HL_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_SP_nn loads 2 immediate bytes into SP",
            test_LD_SP_nn
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_rr_nn Instructions | LD_SP_HL loads value in HL register into SP",
            test_LD_SP_HL
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "LD_rr_nn Instructions | LD_nn_SP loads value from SP into address pointed to by immediate data",
        //     test_LD_nn_SP
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "LD_rr_nn Instructions | LD_HL_SPe adds immediate signed byte to SP and stores in register HL",
        //     test_LD_HL_SPe
        ) == NULL) {
        printf("Failed to add test to LD_rr_nn unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
