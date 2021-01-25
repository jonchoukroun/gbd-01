#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_LD_B_B(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = test_value;
    LD_r_r(&cpu, 0x40);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_B_C(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = 0;
    cpu.registers.C = test_value;
    LD_r_r(&cpu, 0x41);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_B_D(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = 0;
    cpu.registers.D = test_value;
    LD_r_r(&cpu, 0x42);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_B_E(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = 0;
    cpu.registers.E = test_value;
    LD_r_r(&cpu, 0x43);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_B_H(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = 0;
    cpu.registers.H = test_value;
    LD_r_r(&cpu, 0x44);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_B_L(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = 0;
    cpu.registers.L = test_value;
    LD_r_r(&cpu, 0x45);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_B_A(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = 0;
    cpu.registers.A = test_value;
    LD_r_r(&cpu, 0x47);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_B(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.B = test_value;
    LD_r_r(&cpu, 0x48);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_C(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = test_value;
    LD_r_r(&cpu, 0x49);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_D(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.D = test_value;
    LD_r_r(&cpu, 0x4a);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_E(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.E = test_value;
    LD_r_r(&cpu, 0x4b);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_H(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.H = test_value;
    LD_r_r(&cpu, 0x4c);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_L(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.L = test_value;
    LD_r_r(&cpu, 0x4d);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_A(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.A = test_value;
    LD_r_r(&cpu, 0x4f);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_B(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.B = test_value;
    LD_r_r(&cpu, 0x50);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_C(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.C = test_value;
    LD_r_r(&cpu, 0x51);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_D(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.D = test_value;
    LD_r_r(&cpu, 0x52);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_E(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.E = test_value;
    LD_r_r(&cpu, 0x53);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_H(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.H = test_value;
    LD_r_r(&cpu, 0x54);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_L(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.L = test_value;
    LD_r_r(&cpu, 0x55);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_A(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.A = test_value;
    LD_r_r(&cpu, 0x57);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_B(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.B = test_value;
    LD_r_r(&cpu, 0x58);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_C(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.C = test_value;
    LD_r_r(&cpu, 0x59);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_D(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.D = test_value;
    LD_r_r(&cpu, 0x5a);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_E(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.E = test_value;
    LD_r_r(&cpu, 0x5b);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_H(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.H = test_value;
    LD_r_r(&cpu, 0x5c);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_L(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.L = test_value;
    LD_r_r(&cpu, 0x5d);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_A(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.A = test_value;
    LD_r_r(&cpu, 0x5f);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_B(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.B = test_value;
    LD_r_r(&cpu, 0x60);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_C(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.C = test_value;
    LD_r_r(&cpu, 0x61);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_D(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.D = test_value;
    LD_r_r(&cpu, 0x62);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_E(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.E = test_value;
    LD_r_r(&cpu, 0x63);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_H(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.H = test_value;
    LD_r_r(&cpu, 0x64);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_L(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.L = test_value;
    LD_r_r(&cpu, 0x65);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_A(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.A = test_value;
    LD_r_r(&cpu, 0x67);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_B(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.B = test_value;
    LD_r_r(&cpu, 0x68);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_C(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.C = test_value;
    LD_r_r(&cpu, 0x69);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_D(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.D = test_value;
    LD_r_r(&cpu, 0x6a);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_E(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.E = test_value;
    LD_r_r(&cpu, 0x6b);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_H(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.H = test_value;
    LD_r_r(&cpu, 0x6c);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_L(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.L = test_value;
    LD_r_r(&cpu, 0x6d);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_A(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.A = test_value;
    LD_r_r(&cpu, 0x6f);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_A_B(void)
{
    CPU cpu;
    uint8_t test_value = 0x23;
    cpu.registers.A = 0;
    cpu.registers.B = test_value;
    LD_r_r(&cpu, 0x78);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_A_C(void)
{
    CPU cpu;
    uint8_t test_value = 0x23;
    cpu.registers.A = 0;
    cpu.registers.C = test_value;
    LD_r_r(&cpu, 0x78);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_A_D(void)
{
    CPU cpu;
    uint8_t test_value = 0x23;
    cpu.registers.A = 0;
    cpu.registers.D = test_value;
    LD_r_r(&cpu, 0x78);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_A_E(void)
{
    CPU cpu;
    uint8_t test_value = 0x23;
    cpu.registers.A = 0;
    cpu.registers.E = test_value;
    LD_r_r(&cpu, 0x78);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_A_H(void)
{
    CPU cpu;
    uint8_t test_value = 0x23;
    cpu.registers.A = 0;
    cpu.registers.H = test_value;
    LD_r_r(&cpu, 0x78);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_A_L(void)
{
    CPU cpu;
    uint8_t test_value = 0x23;
    cpu.registers.A = 0;
    cpu.registers.L = test_value;
    LD_r_r(&cpu, 0x78);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_A_A(void)
{
    CPU cpu;
    uint8_t test_value = 0x23;
    cpu.registers.A = 0;
    cpu.registers.A = test_value;
    LD_r_r(&cpu, 0x78);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD_r_r Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_B_B loadss register B value into register B and sets cycles",
            test_LD_B_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_B_C loads register C value into register B and sets cycles",
            test_LD_B_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_B_D loads register D value into register B and sets cycles",
            test_LD_B_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_B_E loads register E value into register B and sets cycles",
            test_LD_B_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_B_H loads register H value into register B and sets cycles",
            test_LD_B_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_B_L loads register L value into register B and sets cycles",
            test_LD_B_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_B_A loads register A value into register B and sets cycles",
            test_LD_B_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_C_B loads register B value into register C and sets cycles",
            test_LD_C_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_C_C loads register C value into register C and sets cycles",
            test_LD_C_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_C_D loads register D value into register C and sets cycles",
            test_LD_C_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_C_E loads register E value into register C and sets cycles",
            test_LD_C_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_C_H loads register H value into register C and sets cycles",
            test_LD_C_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_C_L loads register L value into register C and sets cycles",
            test_LD_C_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_C_A loads register A value into register C and sets cycles",
            test_LD_C_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_D_B loads register B value into register D and sets cycles",
            test_LD_D_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_D_C loads register C value into register D and sets cycles",
            test_LD_D_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_D_D loads register D value into register D and sets cycles",
            test_LD_D_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_D_E loads register E value into register D and sets cycles",
            test_LD_D_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_D_H loads register H value into register D and sets cycles",
            test_LD_D_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_D_L loads register L value into register D and sets cycles",
            test_LD_D_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_D_A loads register A value into register D and sets cycles",
            test_LD_D_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_E_B loads register B value into register E and sets cycle",
            test_LD_E_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_E_C loads register C value into register E and sets cycle",
            test_LD_E_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_E_D loads register D value into register E and sets cycle",
            test_LD_E_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_E_E loads register E value into register E and sets cycle",
            test_LD_E_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_E_H loads register H value into register E and sets cycle",
            test_LD_E_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_E_L loads register L value into register E and sets cycle",
            test_LD_E_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_E_A loads register A value into register E and sets cycle",
            test_LD_E_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_H_B loads register B value into register H and sets cycle",
            test_LD_H_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_H_C loads register C value into register H and sets cycle",
            test_LD_H_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_H_D loads register D value into register H and sets cycle",
            test_LD_H_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_H_E loads register E value into register H and sets cycle",
            test_LD_H_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_H_H loads register H value into register H and sets cycle",
            test_LD_H_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_H_L loads register L value into register H and sets cycle",
            test_LD_H_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_H_A loads register A value into register H and sets cycle",
            test_LD_H_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_L_B loads register B value into register L and sets cycle",
            test_LD_L_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_L_C loads register C value into register L and sets cycle",
            test_LD_L_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_L_D loads register D value into register L and sets cycle",
            test_LD_L_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_L_E loads register E value into register L and sets cycle",
            test_LD_L_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_L_H loads register H value into register L and sets cycle",
            test_LD_L_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_L_L loads register L value into register L and sets cycle",
            test_LD_L_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_L_A loads register A value into register L and sets cycle",
            test_LD_L_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_A_B loads register B value into register A and sets cycle",
            test_LD_A_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_A_C loads register C value into register A and sets cycle",
            test_LD_A_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_A_D loads register D value into register A and sets cycle",
            test_LD_A_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_A_E loads register E value into register A and sets cycle",
            test_LD_A_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_A_H loads register H value into register A and sets cycle",
            test_LD_A_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_A_L loads register L value into register A and sets cycle",
            test_LD_A_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD_r_r Instructions | LD_A_A loads register A value into register A and sets cycle",
            test_LD_A_A
        ) == NULL) {
        printf("Failed to add test to LD_r_r unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}

