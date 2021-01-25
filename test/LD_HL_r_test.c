#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LD_HL_B(void)
{
    CPU cpu;
    uint16_t address = 0x3000;
    uint8_t value = 0xaa;
    cpu.registers.HL = address;
    cpu.registers.B = value;
    LD_HL_r(&cpu, 0x70);
    CU_ASSERT_EQUAL(cpu.registers.HL, address);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_HL_C(void)
{
    CPU cpu;
    uint16_t address = 0x3000;
    uint8_t value = 0xaa;
    cpu.registers.HL = address;
    cpu.registers.C = value;
    LD_HL_r(&cpu, 0x71);
    CU_ASSERT_EQUAL(cpu.registers.HL, address);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_HL_D(void)
{
    CPU cpu;
    uint16_t address = 0x3000;
    uint8_t value = 0xaa;
    cpu.registers.HL = address;
    cpu.registers.D = value;
    LD_HL_r(&cpu, 0x72);
    CU_ASSERT_EQUAL(cpu.registers.HL, address);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_HL_E(void)
{
    CPU cpu;
    uint16_t address = 0x3000;
    uint8_t value = 0xaa;
    cpu.registers.HL = address;
    cpu.registers.E = value;
    LD_HL_r(&cpu, 0x73);
    CU_ASSERT_EQUAL(cpu.registers.HL, address);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_HL_H(void)
{
    CPU cpu;
    uint16_t address = 0x1234;
    uint8_t value = 0x12;
    cpu.registers.HL = address;
    cpu.registers.H = value;
    LD_HL_r(&cpu, 0x74);
    CU_ASSERT_EQUAL(cpu.registers.HL, address);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_HL_L(void)
{
    CPU cpu;
    uint16_t address = 0xabcd;
    uint8_t value = 0xcd;
    cpu.registers.HL = address;
    cpu.registers.L = value;
    LD_HL_r(&cpu, 0x75);
    CU_ASSERT_EQUAL(cpu.registers.HL, address);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_HL_A(void)
{
    CPU cpu;
    uint16_t address = 0x3000;
    uint8_t value = 0xaa;
    cpu.registers.HL = address;
    cpu.registers.A = value;
    LD_HL_r(&cpu, 0x77);
    CU_ASSERT_EQUAL(cpu.registers.HL, address);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_HL_r Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_HL_r Instructions | LD_HL_B loads register B value into byte pointed to by register HL",
            test_LD_HL_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_r Instructions | LD_HL_C loads register C value into byte pointed to by register HL",
            test_LD_HL_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_r Instructions | LD_HL_D loads register D value into byte pointed to by register HL",
            test_LD_HL_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_r Instructions | LD_HL_E loads register E value into byte pointed to by register HL",
            test_LD_HL_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_r Instructions | LD_HL_H loads register H value into byte pointed to by register HL",
            test_LD_HL_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_r Instructions | LD_HL_L loads register L value into byte pointed to by register HL",
            test_LD_HL_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_HL_r Instructions | LD_HL_A loads register A value into byte pointed to by register HL",
            test_LD_HL_A
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
