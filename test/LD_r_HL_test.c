#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LD_B_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.B = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_HL(&cpu, 0x46);
    CU_ASSERT_EQUAL(cpu.registers.B, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_C_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.C = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_HL(&cpu, 0x4e);
    CU_ASSERT_EQUAL(cpu.registers.C, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_D_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.D = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_HL(&cpu, 0x56);
    CU_ASSERT_EQUAL(cpu.registers.D, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_E_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.E = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_HL(&cpu, 0x5e);
    CU_ASSERT_EQUAL(cpu.registers.E, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_H_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_HL(&cpu, 0x66);
    CU_ASSERT_EQUAL(cpu.registers.H, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_L_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_HL(&cpu, 0x6e);
    CU_ASSERT_EQUAL(cpu.registers.L, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_A_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.A = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_HL(&cpu, 0x7e);
    CU_ASSERT_EQUAL(cpu.registers.A, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_r_HL Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_r_HL Instructions | LD_B_HL loads value in address stored in HL, to register B and sets cycles",
            test_LD_B_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_HL Instructions | LD_C_HL loads value in address stored in HL, to register C and sets cycles",
            test_LD_C_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_HL Instructions | LD_D_HL loads value in address stored in HL, to register D and sets cycles",
            test_LD_D_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_HL Instructions | LD_E_HL loads value in address stored in HL, to register E and sets cycles",
            test_LD_E_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_HL Instructions | LD_H_HL loads value in address stored in HL, to register H and sets cycles",
            test_LD_H_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_HL Instructions | LD_L_HL loads value in address stored in HL, to register L and sets cycles",
            test_LD_L_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_HL loads value in address stored in HL, to register A and sets cycles",
            test_LD_A_HL
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
