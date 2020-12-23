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

void test_execute(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.memory[0x1000] = 0x0801;
    cpu.registers.A = 0x1;
    cpu.registers.C = 0xa;
    uint16_t opcode = fetch(&cpu);
    execute(&cpu, opcode);
    printf(" A %x ", cpu.registers.A);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xb);
    CU_ASSERT_EQUAL(cpu.registers.C, 0xa);
    CU_ASSERT_EQUAL(cpu.PC, 0x1001);
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
            test_suite, "CPU | fetch returns 16bit value from memory address", test_fetch
        ) == NULL ||
        CU_add_test(
            test_suite, "CPU | execute updates CPU as expected", test_execute
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
