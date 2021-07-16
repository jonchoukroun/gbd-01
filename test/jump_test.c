#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void JP_test()
{
    CPU cpu;
    // assume PC incremented after opcode fetch
    cpu.PC = 0x100;
    cpu.memory[cpu.PC] = 0xab;
    cpu.memory[cpu.PC + 1] = 0xcd;
    JP(&cpu, 0xc3);
    CU_ASSERT_EQUAL(cpu.PC, 0xabcd);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void JPC_NZ_test()
{
    CPU cpu;
    cpu.PC = 0x100;
    cpu.memory[cpu.PC] = 0xab;
    cpu.memory[cpu.PC + 1] = 0xcd;
    // NZ is false
    cpu.registers.F = 0b10000000;
    JPC(&cpu, 0xc2);
    CU_ASSERT_EQUAL(cpu.PC, 0x100);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

    // NZ is true
    cpu.registers.F = 0;
    JPC(&cpu, 0xc2);
    CU_ASSERT_EQUAL(cpu.PC, 0xabcd);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void JPC_Z_test()
{
    CPU cpu;
    cpu.PC = 0x100;
    cpu.memory[cpu.PC] = 0x43;
    cpu.memory[cpu.PC + 1] = 0x21;
    // Z is false
    cpu.registers.F = 0;
    JPC(&cpu, 0xca);
    CU_ASSERT_EQUAL(cpu.PC, 0x100);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

    // Z is true
    cpu.registers.F = 0b10110000;
    JPC(&cpu, 0xca);
    CU_ASSERT_EQUAL(cpu.PC, 0x4321);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void JPC_NC_test()
{
    CPU cpu;
    cpu.PC = 0x100;
    cpu.memory[cpu.PC] = 0x12;
    cpu.memory[cpu.PC + 1] = 0x31;
    // NC is false
    cpu.registers.F = 0b11110000;
    JPC(&cpu, 0xd2);
    CU_ASSERT_EQUAL(cpu.PC, 0x100);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

    // NC is true
    cpu.registers.F = 0b11100000;
    JPC(&cpu, 0xd2);
    CU_ASSERT_EQUAL(cpu.PC, 0x1231);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void JPC_C_test()
{
    CPU cpu;
    cpu.PC = 0x100;
    cpu.memory[cpu.PC] = 0xab;
    cpu.memory[cpu.PC + 1] = 0xcd;
    // C is false
    cpu.registers.F = 0b10000000;
    JPC(&cpu, 0xda);
    CU_ASSERT_EQUAL(cpu.PC, 0x100);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

    // C is true
    cpu.registers.F = 0b01010000;
    JPC(&cpu, 0xda);
    CU_ASSERT_EQUAL(cpu.PC, 0xabcd);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void JR_test()
{
    CPU cpu;
    cpu.PC = 0x481;
    cpu.memory[cpu.PC] = 0x03;
    cpu.registers.F = 0b10100000;
    JR(&cpu, 0x18);
    CU_ASSERT_EQUAL(cpu.PC, 0x485);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);

    cpu.PC = 0x100;
    // e = -1
    cpu.memory[cpu.PC] = 0b11111111;
    JR(&cpu, 0x18);
    CU_ASSERT_EQUAL(cpu.PC, 0x100);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Jump instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
        test_suite,
        "Jump Instructions | JP loads next 2 bytes into PC",
        JP_test
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Jump instructions | JPC_NZ loads next 2 bytes if Z flag is clear",
        JPC_NZ_test
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Jump instructions | JPC_Z loads next 2 bytes if Z flag is set",
        JPC_Z_test
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Jump instructions | JPC_NC loads next 2 bytes if C flag is clear",
        JPC_NC_test
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Jump instructions | JPC_C loads next 2 bytes if C flag is set",
        JPC_C_test
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Jump instructions | JR adds/subtracts immediate signed byte to PC",
        JR_test
    )== NULL) {
        printf("Failed to add test to Jump instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
