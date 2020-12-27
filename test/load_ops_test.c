#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"


void test_LD_B_A(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = 0;
    cpu.registers.A = test_value;
    LD_B_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_B_B(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = test_value;
    LD_B_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_B_C(void)
{
    CPU cpu;
    uint8_t test_value = 0xa;
    cpu.registers.B = 0;
    cpu.registers.C = test_value;
    LD_B_C(&cpu);
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
    LD_B_D(&cpu);
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
    LD_B_E(&cpu);
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
    LD_B_H(&cpu);
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
    LD_B_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_A(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.A = test_value;
    LD_C_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_B(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.B = test_value;
    LD_C_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.B, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_C(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = test_value;
    LD_C_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_C_D(void)
{
    CPU cpu;
    uint8_t test_value = 0x5c;
    cpu.registers.C = 0;
    cpu.registers.D = test_value;
    LD_C_D(&cpu);
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
    LD_C_E(&cpu);
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
    LD_C_H(&cpu);
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
    LD_C_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_A(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.A = test_value;
    LD_D_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_D_B(void)
{
    CPU cpu;
    uint8_t test_value = 0x01;
    cpu.registers.D = 0;
    cpu.registers.B = test_value;
    LD_D_B(&cpu);
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
    LD_D_C(&cpu);
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
    LD_D_D(&cpu);
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
    LD_D_E(&cpu);
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
    LD_D_H(&cpu);
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
    LD_D_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_A(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.A = test_value;
    LD_E_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_E_B(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.E = 0;
    cpu.registers.B = test_value;
    LD_E_B(&cpu);
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
    LD_E_C(&cpu);
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
    LD_E_D(&cpu);
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
    LD_E_E(&cpu);
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
    LD_E_H(&cpu);
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
    LD_E_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_A(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.A = test_value;
    LD_H_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_H_B(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.H = 0;
    cpu.registers.B = test_value;
    LD_H_B(&cpu);
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
    LD_H_C(&cpu);
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
    LD_H_D(&cpu);
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
    LD_H_E(&cpu);
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
    LD_H_H(&cpu);
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
    LD_H_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_A(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.A = test_value;
    LD_L_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.A, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_L_B(void)
{
    CPU cpu;
    uint8_t test_value = 0xee;
    cpu.registers.L = 0;
    cpu.registers.B = test_value;
    LD_L_B(&cpu);
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
    LD_L_C(&cpu);
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
    LD_L_D(&cpu);
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
    LD_L_E(&cpu);
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
    LD_L_H(&cpu);
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
    LD_L_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.registers.L, test_value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 4);
}

void test_LD_A_n(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.memory[cpu.PC - 1] = 0x06af;
    cpu.registers.A = 0;
    LD_A_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xaf);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_B_n(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.memory[cpu.PC - 1] = 0x06af;
    cpu.registers.B = 0;
    LD_B_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0xaf);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_C_n(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.memory[cpu.PC - 1] = 0x06af;
    cpu.registers.C = 0;
    LD_C_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0xaf);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_D_n(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.memory[cpu.PC - 1] = 0x06af;
    cpu.registers.D = 0;
    LD_D_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0xaf);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_E_n(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.memory[cpu.PC - 1] = 0x06af;
    cpu.registers.E = 0;
    LD_E_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0xaf);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_H_n(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.memory[cpu.PC - 1] = 0x06af;
    cpu.registers.H = 0;
    LD_H_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0xaf);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_L_n(void)
{
    CPU cpu;
    cpu.PC = 0x1000;
    cpu.memory[cpu.PC - 1] = 0x06af;
    cpu.registers.L = 0;
    LD_L_n(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0xaf);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("LD Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "LD Instructions | LD_B_A loads register A value into register B and sets cycles",
            test_LD_B_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_B_B loadss register B value into register B and sets cycles",
            test_LD_B_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_B_C loads register C value into register B and sets cycles",
            test_LD_B_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_B_D loads register D value into register B and sets cycles",
            test_LD_B_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_B_E loads register E value into register B and sets cycles",
            test_LD_B_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_B_H loads register H value into register B and sets cycles",
            test_LD_B_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_B_L loads register L value into register B and sets cycles",
            test_LD_B_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_C_A loads register A value into register C and sets cycles",
            test_LD_C_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_C_B loads register B value into register C and sets cycles",
            test_LD_C_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_C_C loads register C value into register C and sets cycles",
            test_LD_C_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_C_D loads register D value into register C and sets cycles",
            test_LD_C_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_C_E loads register E value into register C and sets cycles",
            test_LD_C_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_C_H loads register H value into register C and sets cycles",
            test_LD_C_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_C_L loads register L value into register C and sets cycles",
            test_LD_C_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_D_A loads register A value into register D and sets cycles",
            test_LD_D_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_D_B loads register B value into register D and sets cycles",
            test_LD_D_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_D_C loads register C value into register D and sets cycles",
            test_LD_D_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_D_D loads register D value into register D and sets cycles",
            test_LD_D_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_D_E loads register E value into register D and sets cycles",
            test_LD_D_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_D_H loads register H value into register D and sets cycles",
            test_LD_D_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_D_L loads register L value into register D and sets cycles",
            test_LD_D_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_E_A loads register A value into register E and sets cycle",
            test_LD_E_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_E_B loads register B value into register E and sets cycle",
            test_LD_E_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_E_C loads register C value into register E and sets cycle",
            test_LD_E_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_E_D loads register D value into register E and sets cycle",
            test_LD_E_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_E_E loads register E value into register E and sets cycle",
            test_LD_E_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_E_H loads register H value into register E and sets cycle",
            test_LD_E_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_E_L loads register L value into register E and sets cycle",
            test_LD_E_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_H_A loads register A value into register H and sets cycle",
            test_LD_H_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_H_B loads register B value into register H and sets cycle",
            test_LD_H_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_H_C loads register C value into register H and sets cycle",
            test_LD_H_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_H_D loads register D value into register H and sets cycle",
            test_LD_H_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_H_E loads register E value into register H and sets cycle",
            test_LD_H_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_H_H loads register H value into register H and sets cycle",
            test_LD_H_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_H_L loads register L value into register H and sets cycle",
            test_LD_H_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_A_n loads immediate value into register be and sets cycles",
            test_LD_A_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_B_n loads immediate value into register be and sets cycles",
            test_LD_B_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_C_n loads immediate value into register be and sets cycles",
            test_LD_C_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_D_n loads immediate value into register be and sets cycles",
            test_LD_D_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_E_n loads immediate value into register be and sets cycles",
            test_LD_E_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_H_n loads immediate value into register be and sets cycles",
            test_LD_H_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "LD Instructions | LD_L_n loads immediate value into register be and sets cycles",
            test_LD_L_n
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
