#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void BIT_tester(uint8_t opcode)
{
    CPU cpu;
    uint8_t r = opcode & 0b111;
    uint8_t bit = (opcode & 0b111000) >> 3;
    RegSet_8 set_R = R_TABLE_8[r];

    set_R(&cpu, 0);
    cpu.registers.F = 0;
    BIT(&cpu, opcode);
    CU_ASSERT_EQUAL(fetch_r8(&cpu, r), 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    set_R(&cpu, 0xff);
    cpu.registers.F = 0b11110000;
    BIT(&cpu, opcode);
    CU_ASSERT_EQUAL(fetch_r8(&cpu, r), 0xff);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    // Set only the bit to check
    set_R(&cpu, (1 << bit));
    cpu.registers.F = 0;
    BIT(&cpu, opcode);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    // Clear only the bit to check
    set_R(&cpu, ~(1 << bit));
    cpu.registers.F = 0b11110000;
    BIT(&cpu, opcode);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void BIT_HL_tester(uint8_t opcode)
{
    CPU cpu;
    cpu.registers.HL = 0x1234;
    uint8_t bit = (opcode & 0b111000) >> 3;

    cpu.memory[cpu.registers.HL] = 0;
    cpu.registers.F = 0;
    BIT_HL(&cpu, opcode);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

    cpu.memory[cpu.registers.HL] = 0xff;
    cpu.registers.F = 0b11110000;
    BIT_HL(&cpu, opcode);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0xff);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

    // Set only the bit to check
    cpu.memory[cpu.registers.HL] = 1 << bit;
    cpu.registers.F = 0;
    BIT_HL(&cpu, opcode);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);

    // Clear only the bit to check
    cpu.memory[cpu.registers.HL] = ~(1 << bit);
    cpu.registers.F = 0b11110000;
    BIT_HL(&cpu, opcode);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

void SET_tester(uint8_t opcode)
{
    CPU cpu;
    uint8_t r = opcode & 0b111;
    uint8_t bit = (opcode & 0b111000) >> 3;
    RegSet_8 set_R = R_TABLE_8[r];

    set_R(&cpu, 0);
    cpu.registers.F = 0;
    SET(&cpu, opcode);
    CU_ASSERT_EQUAL(fetch_r8(&cpu, r), 1 << bit);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    set_R(&cpu, 0xff);
    cpu.registers.F = 0b11110000;
    SET(&cpu, opcode);
    CU_ASSERT_EQUAL(fetch_r8(&cpu, r), 0xff);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11110000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    set_R(&cpu, 0xff ^ (1 << bit));
    cpu.registers.F = 0;
    SET(&cpu, opcode);
    CU_ASSERT_EQUAL(fetch_r8(&cpu, r), 0xff);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void SET_HL_tester(uint8_t opcode)
{
    CPU cpu;
    cpu.registers.HL = 0x0721;
    uint8_t bit = (opcode & 0b111000) >> 3;

    cpu.memory[cpu.registers.HL] = 0;
    cpu.registers.F = 0b10100000;
    SET_HL(&cpu, opcode);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 1 << bit);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void RES_tester(uint8_t opcode)
{
    CPU cpu;
    uint8_t r = opcode & 0b111;
    uint8_t bit = (opcode & 0b111000) >> 3;
    RegSet_8 set_R = R_TABLE_8[r];

    set_R(&cpu, 0);
    cpu.registers.F = 0;
    RES(&cpu, opcode);
    CU_ASSERT_EQUAL(fetch_r8(&cpu, r), 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void RES_HL_tester(uint8_t opcode)
{
    CPU cpu;
    cpu.registers.HL = 0x2121;
    cpu.memory[cpu.registers.HL] = 0;
    cpu.registers.F = 0b10100000;
    RES_HL(&cpu, opcode);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

void test_BIT(void)
{
    printf("\n");
    for (uint8_t i = 0x40; i <= 0x7f; i++) {
        uint8_t nibble = i & 0b111;
        if (nibble != 0x6 && nibble != 0xe) {
            printf("\tBit instructions | opcode 0x%x\n", i);
            BIT_tester(i);
        } else {
            printf("\tBit instructions | opcode 0x%x (HL)\n", i);
            BIT_HL_tester(i);
        }
    }
    printf("\t...");
}

void test_SET(void)
{
    printf("\n");
    for (int i = 0xc0; i <= 0xff; i++) {
        uint8_t nibble = i & 0b111;
        if (nibble != 0x6 && nibble != 0xe) {
            printf("\tSet instructions | opcode 0x%x\n", i);
            SET_tester(i);
        } else {
            printf("\tSet instructions | opcode 0x%x (HL)\n", i);
            SET_HL_tester(i);
        }
    }
    printf("\t...");
}

void test_RES(void)
{
    printf("\n");
    for (int i = 0x80; i <= 0xBf; i++) {
        uint8_t nibble = i & 0b111;
        if (nibble != 0x6 && nibble != 0xe) {
            printf("\tReset instructions | opcode 0x%x\n", i);
            RES_tester(i);
        } else {
            printf("\tReset instructions | opcode 0x%x (HL)\n", i);
            RES_HL_tester(i);
        }
    }
    printf("\t...");
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Bit instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "BIT instructions | ",
            test_BIT) == NULL ||
        CU_add_test(
            test_suite,
            "SET instructions | ",
            test_SET) == NULL ||
        CU_add_test(
            test_suite,
            "RES instructions | ",
            test_RES) == NULL) {
        printf("Failed to add test to Bit instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
