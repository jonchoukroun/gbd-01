#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "cpu.h"

void test_fetch_opcode(void)
{
    CPU cpu;
    uint16_t PC_start = 0x1000;
    uint8_t opcode = 0xab;
    cpu.memory[PC_start] = opcode;
    cpu.memory[PC_start + 1] = 0xcd;
    cpu.PC = PC_start;
    CU_ASSERT_EQUAL(fetch_opcode(&cpu), opcode);
    CU_ASSERT_EQUAL(cpu.PC, PC_start + 1);
}

void test_read_byte(void)
{
    CPU cpu;
    uint8_t byte = 0xf1;
    uint16_t address = 0x1005;
    cpu.memory[address] = byte;
    CU_ASSERT_EQUAL(read_byte(&cpu, address), byte);
}

void test_read_word(void)
{
    CPU cpu;
    uint16_t word = 0xabcd;
    uint16_t address = 0x3003;
    cpu.memory[address] = 0xab;
    cpu.memory[address + 1] = 0xcd;
    CU_ASSERT_EQUAL(read_word(&cpu, address), word);
}

void test_write_byte(void)
{
    CPU cpu;
    uint8_t byte = 0x16;
    uint16_t address = 0x4000;
    cpu.memory[address] = 0;
    write_byte(&cpu, byte, address);
    CU_ASSERT_EQUAL(read_byte(&cpu, address), byte);
}

void test_write_word(void)
{
    CPU cpu;
    uint16_t word = 0x3456;
    uint16_t address = 0x1110;
    cpu.memory[address] = 0;
    cpu.memory[address + 1] = 0;
    write_word(&cpu, word, address);
    CU_ASSERT_EQUAL(cpu.memory[address], 0x34);
    CU_ASSERT_EQUAL(cpu.memory[address + 1], 0x56);
}

void test_toggle_zero_flag(void)
{
    CPU cpu;
    uint16_t value = 0;
    cpu.registers.F = 0b00000000;
    toggle_zero_flag(&cpu, value);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);

    cpu.registers.F = 0b10000000;
    toggle_zero_flag(&cpu, value);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);

    cpu.registers.F = 0b01110000;
    toggle_zero_flag(&cpu, value);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11110000);

    value = 1;
    cpu.registers.F = 0b00000000;
    toggle_zero_flag(&cpu, value);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    cpu.registers.F = 0b10000000;
    toggle_zero_flag(&cpu, value);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    cpu.registers.F = 0b01110000;
    toggle_zero_flag(&cpu, value);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01110000);
}

void test_toggle_hcarry_flag(void)
{
    CPU cpu;
    // Does not set bit when there is no overflow
    cpu.registers.F = 0b00000000;
    toggle_hcarry_flag(&cpu, 0x01, 0x02, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    // Sets bit when 3rd bit overflows on an 8bit value
    cpu.registers.F = 0b00000000;
    toggle_hcarry_flag(&cpu, 0x0f, 0x05, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);

    // Clears bit if there is no overflow
    cpu.registers.F = 0b00100000;
    toggle_hcarry_flag(&cpu, 0x01, 0x3, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    // Leaves bit set if there is overflow
    cpu.registers.F = 0b00100000;
    toggle_hcarry_flag(&cpu, 0x0d, 0x0f, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);

    // Doesn't affect existing bits
    cpu.registers.F = 0b11010000;
    toggle_hcarry_flag(&cpu, 0x05, 0x0f, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11110000);

    // Sets flag on 11th bit overflow, for 16bit values
    cpu.registers.F = 0b00000000;
    toggle_hcarry_flag(&cpu, 0x0400, 0x0400, WORD);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00100000);
}

void test_toggle_carry_flag(void)
{
    CPU cpu;
    // Sets carry bit on overflow
    cpu.registers.F = 0b00000000;
    toggle_carry_flag(&cpu, 0x0123, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // Does not set bit when there is no overflow
    cpu.registers.F = 0b00000000;
    toggle_carry_flag(&cpu, 0x23, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    // Clears bit if there is no overflow
    cpu.registers.F = 0b00010000;
    toggle_carry_flag(&cpu, 0x23, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    // Leaves bit set on overflow
    cpu.registers.F = 0b00010000;
    toggle_carry_flag(&cpu, 0x2134, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // Doesn't affect set bits
    cpu.registers.F = 0b11100000;
    toggle_carry_flag(&cpu, 0x4f, BYTE);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11100000);

    // Sets flag on 15th bit overflow, for 16bit values
    cpu.registers.F = 0b00000000;
    toggle_carry_flag(&cpu, 0xf000 + 0xf000, WORD);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("CPU unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "CPU | fetch_opcode returns 8bit value from memory address at PC and increments PC",
            test_fetch_opcode
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | read_byte fetches byte from memory at location",
            test_read_byte
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | read_word fetches and combines adjacent bytes from memory",
            test_read_word
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | write_byte writes byte into memory at previous PC",
            test_write_byte
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | write_word writes word into adjacent memory locations at previous 2 PC",
            test_write_word
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | toggle_zero_flag sets zero flag bit if value is zero or clears it if value is 0",
            test_toggle_zero_flag
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | toggle_hcarry_flag sets half carry bit if bit 3 overflows or clears it if there is no overflow",
            test_toggle_hcarry_flag
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | toggle_carry_flag set carry bit if bit 7 overflows or clears it if there is no overflow",
            test_toggle_carry_flag
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
