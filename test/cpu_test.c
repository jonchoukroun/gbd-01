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
    printf("F: %x\t", cpu.registers.F);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    cpu.registers.F = 0b10000000;
    toggle_zero_flag(&cpu, value);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    cpu.registers.F = 0b01110000;
    toggle_zero_flag(&cpu, value);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01110000);
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
