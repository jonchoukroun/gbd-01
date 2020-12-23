#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_add(void)
{
    CPU cpu;
    uint8_t source_value = 0x3;
    cpu.registers.A = 0x2;
    cpu.registers.B = source_value;
    add(&cpu, 0x00);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x5);
    CU_ASSERT_EQUAL(cpu.registers.B, source_value);
}

void test_add_zero_flag(void)
{
    CPU cpu;
    cpu.registers.A = 0x1;
    cpu.registers.C = 0x3;
    add(&cpu, 0x01);
    CU_ASSERT_EQUAL(get_flag(&cpu, ZERO_FLAG), 0);

    cpu.registers.A = 0;
    cpu.registers.D = 0;
    add(&cpu, 0x02);
    CU_ASSERT_EQUAL(get_flag(&cpu, ZERO_FLAG), 1);
}

void test_add_subtract_flag(void)
{
    CPU cpu;
    cpu.registers.A = 0x4;
    cpu.registers.E = 0x5;
    add(&cpu, 0x03);
    CU_ASSERT_EQUAL(get_flag(&cpu, SUBTRACT_FLAG), 0);

    set_flag(&cpu, SUBTRACT_FLAG);
    add(&cpu, 0x03);
    CU_ASSERT_EQUAL(get_flag(&cpu, SUBTRACT_FLAG), 0);
}

void test_add_half_carry_flag(void)
{
    CPU cpu;
    cpu.registers.A = 0xf;
    cpu.registers.B = 0x1;
    add(&cpu, 0x00);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x10);
    CU_ASSERT_EQUAL(get_flag(&cpu, HALF_CARRY_FLAG), 1);

    cpu.registers.A = 0x3;
    cpu.registers.L = 0x1;
    clear_flag(&cpu, HALF_CARRY_FLAG);
    add(&cpu, 0x05);
    CU_ASSERT_EQUAL(get_flag(&cpu, HALF_CARRY_FLAG), 0);
}

void test_add_carry_flag(void)
{
    CPU cpu;
    cpu.registers.A = 0x3;
    cpu.registers.H = 0x8;
    add(&cpu, 0x04);
    CU_ASSERT_EQUAL(get_flag(&cpu, CARRY_FLAG), 0);

    cpu.registers.A = 0xfe;
    add(&cpu, 0x04);
    CU_ASSERT_EQUAL(get_flag(&cpu, CARRY_FLAG), 1);
}

void test_add_carry(void)
{
    CPU cpu;
    cpu.registers.A = 0xa;
    cpu.registers.B = 0x2;
    clear_flag(&cpu, CARRY_FLAG);
    add(&cpu, 0x08);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xc);

    cpu.registers.A = 0x5;
    set_flag(&cpu, CARRY_FLAG);
    add(&cpu, 0x08);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x8);
    CU_ASSERT_EQUAL(get_flag(&cpu, CARRY_FLAG), 0);

    cpu.registers.A = 0x23;
    cpu.registers.HL = 0x1234;
    set_flag(&cpu, CARRY_FLAG);
    add(&cpu, 0x0e);
    CU_ASSERT_EQUAL(cpu.registers.A, (0x1258 & 0xff));
    CU_ASSERT_EQUAL(get_flag(&cpu, CARRY_FLAG), 1);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "Instructions | ADD add register value to A and leaves source register unchanged",
            test_add
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Instructions | ADD sets zero flag if result is 0",
            test_add_zero_flag
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Instructions | ADD clears subtract flag",
            test_add_subtract_flag
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Instructions | ADD sets half carry flag if lower bit overflows into upper bit",
            test_add_half_carry_flag
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Instructions | ADD sets carry flag if result is greater than 0xff",
            test_add_carry_flag
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Instructions | ADC adds register value and carry flag to A",
            test_add_carry
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
