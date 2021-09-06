#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "cpu.h"

void test_fetch_opcode(void)
{
    CPU *cpu = init_cpu();
    uint16_t PC_start = 0x1000;
    uint8_t opcode = 0xab;
    cpu->memory[PC_start] = opcode;
    cpu->memory[PC_start + 1] = 0xcd;
    cpu->PC = PC_start;
    CU_ASSERT_EQUAL(fetch_opcode(cpu), opcode);
    CU_ASSERT_EQUAL(cpu->PC, PC_start + 1);
}

void test_read_byte(void)
{
    CPU *cpu = init_cpu();
    uint8_t byte = 0xf1;
    uint16_t address = 0x1005;
    cpu->memory[address] = byte;
    CU_ASSERT_EQUAL(read_byte(cpu, address), byte);
}

void test_read_word(void)
{
    CPU *cpu = init_cpu();
    uint16_t word = 0xabcd;
    uint16_t address = 0x3003;
    cpu->memory[address] = 0xab;
    cpu->memory[address + 1] = 0xcd;
    CU_ASSERT_EQUAL(read_word(cpu, address), word);
}

void test_write_byte(void)
{
    CPU *cpu = init_cpu();
    uint8_t byte = 0x16;
    uint16_t address = 0x4000;
    cpu->memory[address] = 0;
    write_byte(cpu, byte, address);
    CU_ASSERT_EQUAL(read_byte(cpu, address), byte);
}

void test_write_word(void)
{
    CPU *cpu = init_cpu();
    uint16_t word = 0x3456;
    uint16_t address = 0x1110;
    cpu->memory[address] = 0;
    cpu->memory[address + 1] = 0;
    write_word(cpu, word, address);
    CU_ASSERT_EQUAL(cpu->memory[address], 0x34);
    CU_ASSERT_EQUAL(cpu->memory[address + 1], 0x56);
}

void test_set_flag(void)
{
    CPU *cpu = init_cpu();

    // Set cleared flags
    cpu->registers.F = 0;
    set_flag(cpu, Z_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);

    cpu->registers.F = 0;
    set_flag(cpu, N_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);

    cpu->registers.F = 0;
    set_flag(cpu, H_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00100000);

    cpu->registers.F = 0;
    set_flag(cpu, C_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);

    // Set existing flags
    cpu->registers.F = 0b10000000;
    set_flag(cpu, Z_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10000000);

    cpu->registers.F = 0b01000000;
    set_flag(cpu, N_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b01000000);

    cpu->registers.F = 0b00100000;
    set_flag(cpu, H_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00100000);

    cpu->registers.F = 0;
    set_flag(cpu, C_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);

    // Ignore other flags
    cpu->registers.F = 0b10110000;
    set_flag(cpu, N_FLAG);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b11110000);
}

void test_IME_flag(void)
{
    CPU *cpu = init_cpu();
    cpu->memory[IME_FLAG] = 0;
    set_IME(cpu);
    CU_ASSERT_EQUAL(cpu->memory[IME_FLAG], 1);
    reset_IME(cpu);
    CU_ASSERT_EQUAL(cpu->memory[IME_FLAG], 0);
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
            "CPU | set_flag sets flag bit and ignores other flag bits",
            test_set_flag
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | set, reset IME flag sets, resets reserved memory",
            test_IME_flag
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
