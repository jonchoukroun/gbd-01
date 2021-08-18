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

void CALLC_NZ_test()
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

void CALLC_Z_test()
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

void CALLC_NC_test()
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

void CALLC_C_test()
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

void RET_test()
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.SP = 0x8000;
    cpu.memory[0x8000] = 0x80;
    cpu.memory[0x8001] = 0x03;
    RET(&cpu, 0xc9);
    CU_ASSERT_EQUAL(cpu.PC, 0x8003);
    CU_ASSERT_EQUAL(cpu.SP, 0x8002);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void RETI_test()
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.SP = 0x8000;
    cpu.memory[0x8000] = 0x80;
    cpu.memory[0x8001] = 0x03;
    cpu.memory[IME_FLAG] = 0;
    RETI(&cpu, 0xc9);
    CU_ASSERT_EQUAL(cpu.PC, 0x8003);
    CU_ASSERT_EQUAL(cpu.SP, 0x8002);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
    CU_ASSERT_EQUAL(cpu.memory[IME_FLAG], 1);
}

void RETC_NZ_test()
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.SP = 0x8000;
    cpu.memory[0x8000] = 0x80;
    cpu.memory[0x8001] = 0x03;
    // NZ if false
    cpu.registers.F = 0b10000000;
    RETC(&cpu, 0xc0);
    CU_ASSERT_EQUAL(cpu.PC, 0x1000);
    CU_ASSERT_EQUAL(cpu.SP, 0x8000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.F = 0;
    RETC(&cpu, 0xc0);
    CU_ASSERT_EQUAL(cpu.PC, 0x8003);
    CU_ASSERT_EQUAL(cpu.SP, 0x8002);
    CU_ASSERT_EQUAL(cpu.t_cycles, 20);
}

void RETC_Z_test()
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.SP = 0x8000;
    cpu.memory[0x8000] = 0x80;
    cpu.memory[0x8001] = 0x03;
    // Z if false
    cpu.registers.F = 0;
    RETC(&cpu, 0xc8);
    CU_ASSERT_EQUAL(cpu.PC, 0x1000);
    CU_ASSERT_EQUAL(cpu.SP, 0x8000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.F = 0b10000000;
    RETC(&cpu, 0xc8);
    CU_ASSERT_EQUAL(cpu.PC, 0x8003);
    CU_ASSERT_EQUAL(cpu.SP, 0x8002);
    CU_ASSERT_EQUAL(cpu.t_cycles, 20);
}

void RETC_NC_test()
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.SP = 0x8000;
    cpu.memory[0x8000] = 0x80;
    cpu.memory[0x8001] = 0x03;
    // NC if false
    cpu.registers.F = 0b00010000;
    RETC(&cpu, 0xd0);
    CU_ASSERT_EQUAL(cpu.PC, 0x1000);
    CU_ASSERT_EQUAL(cpu.SP, 0x8000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.F = 0;
    RETC(&cpu, 0xd0);
    CU_ASSERT_EQUAL(cpu.PC, 0x8003);
    CU_ASSERT_EQUAL(cpu.SP, 0x8002);
    CU_ASSERT_EQUAL(cpu.t_cycles, 20);
}

void RETC_C_test()
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.SP = 0x8000;
    cpu.memory[0x8000] = 0x80;
    cpu.memory[0x8001] = 0x03;
    // C if false
    cpu.registers.F = 0;
    RETC(&cpu, 0xd8);
    CU_ASSERT_EQUAL(cpu.PC, 0x1000);
    CU_ASSERT_EQUAL(cpu.SP, 0x8000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.F = 0b00010000;
    RETC(&cpu, 0xd8);
    CU_ASSERT_EQUAL(cpu.PC, 0x8003);
    CU_ASSERT_EQUAL(cpu.SP, 0x8002);
    CU_ASSERT_EQUAL(cpu.t_cycles, 20);
}

void RST_test()
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.SP = 0x8000;

    // t = 0
    RST(&cpu, 0xc7);
    CU_ASSERT_EQUAL(cpu.SP, 0x7ffe);
    CU_ASSERT_EQUAL(cpu.memory[0x7fff], 0x10);
    CU_ASSERT_EQUAL(cpu.memory[0x7ffe], 0x00);
    CU_ASSERT_EQUAL(cpu.PC, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // t = 1
    RST(&cpu, 0xcf);
    CU_ASSERT_EQUAL(cpu.SP, 0x7ffc);
    CU_ASSERT_EQUAL(cpu.memory[0x7ffd], 0);
    CU_ASSERT_EQUAL(cpu.memory[0x7ffc], 0);
    CU_ASSERT_EQUAL(cpu.PC, 0x0008);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // t = 2
    RST(&cpu, 0xd7);
    CU_ASSERT_EQUAL(cpu.SP, 0x7ffa);
    CU_ASSERT_EQUAL(cpu.memory[0x7ffb], 0);
    CU_ASSERT_EQUAL(cpu.memory[0x7ffa], 0x08);
    CU_ASSERT_EQUAL(cpu.PC, 0x0010);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // t = 3
    RST(&cpu, 0xdf);
    CU_ASSERT_EQUAL(cpu.SP, 0x7ff8);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff9], 0);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff8], 0x10);
    CU_ASSERT_EQUAL(cpu.PC, 0x18);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // t = 4
    RST(&cpu, 0xe7);
    CU_ASSERT_EQUAL(cpu.SP, 0x7ff6);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff7], 0);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff6], 0x18);
    CU_ASSERT_EQUAL(cpu.PC, 0x20);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // t = 5
    RST(&cpu, 0xef);
    CU_ASSERT_EQUAL(cpu.SP, 0x7ff4);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff5], 0);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff4], 0x20);
    CU_ASSERT_EQUAL(cpu.PC, 0x28);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // t = 6
    RST(&cpu, 0xf7);
    CU_ASSERT_EQUAL(cpu.SP, 0x7ff2);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff3], 0);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff2], 0x28);
    CU_ASSERT_EQUAL(cpu.PC, 0x30);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    // t = 7
    RST(&cpu, 0xff);
    CU_ASSERT_EQUAL(cpu.SP, 0x7ff0);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff1], 0);
    CU_ASSERT_EQUAL(cpu.memory[0x7ff0], 0x30);
    CU_ASSERT_EQUAL(cpu.PC, 0x38);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
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
            "Call Instructions | CALLC_NZ pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC if Z flag is clear",
            CALLC_NZ_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | CALLC_Z pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC if Z flag is set",
            CALLC_Z_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | CALLC_NC pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC if C flag is clear",
            CALLC_NC_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | CALLC_C pushes the PC onto the stack, decrements SP by 2, and sets the next 2 bytes on the PC if C flag is set",
            CALLC_C_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | RET pops the stack onto the PC",
            RET_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | RETI pops the stack onto the PC and enables the Interrupt Master Enable flag",
            RETI_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | RETC_NZ pops the stack onto the PC if the Z flag is clear",
            RETC_NZ_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | RETC_Z pops the stack onto the PC if the Z flag is set",
            RETC_Z_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | RETC_NC pops the stack onto the PC if the C flag is clear",
            RETC_NC_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | RETC_C pops the stack onto the PC if the C flag is set",
            RETC_C_test
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Call Instructions | RST pushes the PC onto the stack and loads the operand's Page 0 memory address into the PC",
            RST_test
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
