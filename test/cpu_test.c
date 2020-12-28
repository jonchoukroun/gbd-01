#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "cpu.h"

void test_fetch(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    CU_ASSERT_EQUAL(fetch(&cpu), 0);

    uint16_t address = 0x0050;
    uint16_t value = 0x1234;
    cpu.memory[address] = value;
    cpu.PC = address;
    CU_ASSERT_EQUAL(fetch(&cpu), value);
}

void test_read_byte(void)
{
    CPU cpu;
    uint8_t byte = 0xf1;
    uint16_t PC = 0x1001;
    cpu.PC = PC;
    cpu.memory[PC - 1] = byte;
    CU_ASSERT_EQUAL(read_byte(&cpu), byte);
    CU_ASSERT_EQUAL(cpu.PC, PC);
}

void test_read_word(void)
{
    CPU cpu;
    uint16_t word = 0xabcd;
    uint16_t PC = 0x3003;
    cpu.PC = PC;
    cpu.memory[PC - 2] = 0xab;
    cpu.memory[PC - 1] = 0xcd;
    CU_ASSERT_EQUAL(read_word(&cpu), word);
    CU_ASSERT_EQUAL(cpu.PC, PC);
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
            "CPU | fetch returns 16bit value from memory address",
            test_fetch
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | read_byte fetches byte in memory at location of previous PC",
            test_read_byte
        ) == NULL ||
        CU_add_test(
            test_suite,
            "CPU | read_word combines adjacent bytes in memory at location of previous 2 PC",
            test_read_word
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
