#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void CALL_test()
{
    CPU cpu;
    // Assume PC incremented when fetching CALL instruction
    cpu.PC = 0x8001;
    cpu.memory[cpu.PC] = 0x12;
    cpu.memory[cpu.PC + 1] = 0x34;
    cpu.SP = 0xfffe;
    CALL(&cpu, 0xcd);
    CU_ASSERT_EQUAL(cpu.PC, 0x1234);
    CU_ASSERT_EQUAL(cpu.memory[0xfffd], 0x80);
    CU_ASSERT_EQUAL(cpu.memory[0xfffc], 0x03);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffc);
    CU_ASSERT_EQUAL(cpu.t_cycles, 24);
}

void CALL_C_NZ_test()
{
    CPU cpu;
    cpu.PC = 0x7ffd;
    cpu.memory[0x8001] = 0x12;
    cpu.memory[0x8002] = 0x34;
    cpu.SP = 0xfffe;
    cpu.registers.F = 0b10000000;
    // NZ is false
    CALLC(&cpu, 0xc4);
    CU_ASSERT_EQUAL(cpu.PC, 0x7ffd);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffe);

    // Mock opcode fetch for CALLC instruction
    cpu.PC += 4;
    CU_ASSERT_EQUAL(cpu.PC, 0x8001);
    cpu.registers.F = 0;
    CALLC(&cpu, 0xc4);
    CU_ASSERT_EQUAL(cpu.PC, 0x1234);
    CU_ASSERT_EQUAL(cpu.memory[0xfffd], 0x80);
    CU_ASSERT_EQUAL(cpu.memory[0xfffc], 0x03);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffc);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 24);
}

void CALL_C_Z_test()
{
    CPU cpu;
    cpu.PC = 0x7ffd;
    cpu.memory[0x8001] = 0x12;
    cpu.memory[0x8002] = 0x34;
    cpu.SP = 0xfffe;
    cpu.registers.F = 0;
    // Z is false
    CALLC(&cpu, 0xcc);
    CU_ASSERT_EQUAL(cpu.PC, 0x7ffd);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffe);

    // Mock opcode fetch for CALLC instruction
    cpu.PC += 4;
    CU_ASSERT_EQUAL(cpu.PC, 0x8001);
    cpu.registers.F = 0b10000000;
    CALLC(&cpu, 0xcc);
    CU_ASSERT_EQUAL(cpu.PC, 0x1234);
    CU_ASSERT_EQUAL(cpu.memory[0xfffd], 0x80);
    CU_ASSERT_EQUAL(cpu.memory[0xfffc], 0x03);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffc);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 24);
}

void CALL_C_NC_test()
{
    CPU cpu;
    cpu.PC = 0x7ffd;
    cpu.memory[0x8001] = 0x12;
    cpu.memory[0x8002] = 0x34;
    cpu.SP = 0xfffe;
    cpu.registers.F = 0b00010000;
    // NC is false
    CALLC(&cpu, 0xd4);
    CU_ASSERT_EQUAL(cpu.PC, 0x7ffd);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffe);

    // Mock opcode fetch for CALLC instruction
    cpu.PC += 4;
    CU_ASSERT_EQUAL(cpu.PC, 0x8001);
    cpu.registers.F = 0;
    CALLC(&cpu, 0xd4);
    CU_ASSERT_EQUAL(cpu.PC, 0x1234);
    CU_ASSERT_EQUAL(cpu.memory[0xfffd], 0x80);
    CU_ASSERT_EQUAL(cpu.memory[0xfffc], 0x03);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffc);
    CU_ASSERT_EQUAL(cpu.t_cycles, 24);
}

void CALL_C_C_test()
{
    CPU cpu;
    cpu.PC = 0x7ffd;
    cpu.memory[0x8001] = 0x12;
    cpu.memory[0x8002] = 0x34;
    cpu.SP = 0xfffe;
    cpu.registers.F = 0;
    // C is false
    CALLC(&cpu, 0xdc);
    CU_ASSERT_EQUAL(cpu.PC, 0x7ffd);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffe);

    // Mock opcode fetch for CALLC instruction
    cpu.PC += 4;
    CU_ASSERT_EQUAL(cpu.PC, 0x8001);
    cpu.registers.F = 0b00010000;
    CALLC(&cpu, 0xdc);
    CU_ASSERT_EQUAL(cpu.PC, 0x1234);
    CU_ASSERT_EQUAL(cpu.memory[0xfffd], 0x80);
    CU_ASSERT_EQUAL(cpu.memory[0xfffc], 0x03);
    CU_ASSERT_EQUAL(cpu.SP, 0xfffc);
    CU_ASSERT_EQUAL(cpu.t_cycles, 24);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Call instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "Call Instructions | CALL pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC",
            CALL_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | CALL_C_NZ pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC if Z flag is clear",
            CALL_C_NZ_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | CALL_C_Z pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC if Z flag is set",
            CALL_C_Z_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | CALL_C_NC pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC if C flag is clear",
            CALL_C_NC_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | CALL_C_C pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC if C flag is set",
            CALL_C_C_test
        )== NULL) {
        printf("Failed to add test to Call instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
