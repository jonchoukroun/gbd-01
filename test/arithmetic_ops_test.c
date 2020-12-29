#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_ADC_A_A(void)
{
    // Doubles A when carry flag is cleared
    CPU cpu;
    cpu.registers.A = 0x01;
    ADC_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x02);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    // Doubles A then adds 1 when carry flag is set
    cpu.registers.A = 0x03;
    cpu.registers.F = 0b00010000;
    ADC_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x07);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    // Result is masked to 0xff when > 8bits
    cpu.registers.A = 0xf0;
    cpu.registers.F = 0b00000000;
    ADC_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xe0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // Sets zero flag when result is 0
    cpu.registers.A = 0x80;
    cpu.registers.F = 0b00000000;
    ADC_A_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
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
            "Arithmetic | ADC_A_A adds value in register A plus the carry flag to itself",
            test_ADC_A_A
        ) == NULL) {
        printf("Failed to add test to ADD ops unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
