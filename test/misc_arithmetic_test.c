#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_DAA(void)
{
    // ****** N = 0 ******
    // Both nibbles <= 9
    CPU cpu;
    cpu.registers.A = 0x15;
    cpu.registers.F = 0;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x15);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    // High nibble < 9, low nibble > 9
    cpu.registers.A = 0x8a;
    cpu.registers.F = 0;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x90);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    // High nibble <= 9, low nibble <= 3; HC set
    cpu.registers.A = 0x23;
    cpu.registers.F = 0b00100000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x29);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00000000);

    // High nibble > 9, low nibble <= 9
    cpu.registers.A = 0xc7;
    cpu.registers.F = 0;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x27);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // High nibble >= 9, low nibble > 9
    cpu.registers.A = 0x9d;
    cpu.registers.F = 0;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x03);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // High nibble > 9, low nibble <= 3; HC set
    cpu.registers.A = 0xf2;
    cpu.registers.F = 0b00100000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x58);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // High nibble < 3, low nibble <= 9; C set
    cpu.registers.A = 0x16;
    cpu.registers.F = 0b00010000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x76);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // High nibble < 3, low nibble > 9; C set
    cpu.registers.A = 0x2b;
    cpu.registers.F = 0b00010000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x91);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // High nibble <= 3, low nibble <= 3; HC, C set
    cpu.registers.A = 0x33;
    cpu.registers.F = 0b00110000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x99);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);

    // ****** N = 1 ******
    // Both nibbles <= 9
    cpu.registers.A = 0x00;
    cpu.registers.F = 0b01000000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x00);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11000000);

    // High nibble < 9, low nibble >= 6; HC set
    cpu.registers.A = 0x6a;
    cpu.registers.F = 0b01100000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x64)
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01000000);

    // High nibble > 6, low nibble <= 9; C set
    cpu.registers.A = 0xd5;
    cpu.registers.F = 0b01010000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x75);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01010000);

    // Both nibbles >= 6; HC, C set
    cpu.registers.A = 0xff;
    cpu.registers.F = 0b01110000;
    DAA(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x99);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01010000);
}

void test_CPL(void)
{
    CPU cpu;
    cpu.registers.A = 0x35;
    cpu.registers.F = 0;
    CPL(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xca);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b01100000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);

    cpu.registers.A = 0xfa;
    cpu.registers.F = 0b10010000;
    CPL(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x05);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b11110000);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Misc. Arithmetic unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "Misc. Arithmetic | DAA adjusts register A value for BCD representation",
            test_DAA
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Misc. Arithmetic | CPL sets A to its 1s complement and sets the subtract and half-carry flags",
            test_CPL
        ) == NULL) {
        printf("Failed to add test to arithmetic unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

