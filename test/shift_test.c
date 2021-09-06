#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

void test_SLA_B(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.B = 0x80;
    cpu->registers.F = 0;
    SLA(cpu, 0x20);
    CU_ASSERT_EQUAL(cpu->registers.B, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.B = 0x01;
    cpu->registers.F = 0b11110000;
    SLA(cpu, 0x20);
    CU_ASSERT_EQUAL(cpu->registers.B, 0x02);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SLA_C(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.C = 0x80;
    cpu->registers.F = 0;
    SLA(cpu, 0x21);
    CU_ASSERT_EQUAL(cpu->registers.C, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.C = 0x01;
    cpu->registers.F = 0b11110000;
    SLA(cpu, 0x21);
    CU_ASSERT_EQUAL(cpu->registers.C, 0x02);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SLA_D(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.D = 0x80;
    cpu->registers.F = 0;
    SLA(cpu, 0x22);
    CU_ASSERT_EQUAL(cpu->registers.D, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.D = 0x01;
    cpu->registers.F = 0b11110000;
    SLA(cpu, 0x22);
    CU_ASSERT_EQUAL(cpu->registers.D, 0x02);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SLA_E(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.E = 0x80;
    cpu->registers.F = 0;
    SLA(cpu, 0x23);
    CU_ASSERT_EQUAL(cpu->registers.E, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.E = 0x01;
    cpu->registers.F = 0b11110000;
    SLA(cpu, 0x23);
    CU_ASSERT_EQUAL(cpu->registers.E, 0x02);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SLA_H(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.H = 0x80;
    cpu->registers.F = 0;
    SLA(cpu, 0x24);
    CU_ASSERT_EQUAL(cpu->registers.H, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.H = 0x01;
    cpu->registers.F = 0b11110000;
    SLA(cpu, 0x24);
    CU_ASSERT_EQUAL(cpu->registers.H, 0x02);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SLA_L(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.L = 0x80;
    cpu->registers.F = 0;
    SLA(cpu, 0x25);
    CU_ASSERT_EQUAL(cpu->registers.L, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.L = 0x01;
    cpu->registers.F = 0b11110000;
    SLA(cpu, 0x25);
    CU_ASSERT_EQUAL(cpu->registers.L, 0x02);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SLA_A(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x80;
    cpu->registers.F = 0;
    SLA(cpu, 0x27);
    CU_ASSERT_EQUAL(cpu->registers.A, 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);

    cpu->registers.A = 0x01;
    cpu->registers.F = 0b11110000;
    SLA(cpu, 0x27);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x02);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00000000);
}

void test_SLA_HL(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.HL = 0x1234;
    cpu->memory[cpu->registers.HL] = 0xff;
    cpu->registers.F = 0;
    SLA_HL(cpu, 0x26);
    CU_ASSERT_EQUAL(cpu->registers.HL, 0x1234);
    CU_ASSERT_EQUAL(cpu->memory[cpu->registers.HL], 0xfe);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 16);
}

void test_SRA_B(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.B = 0x8a;
    cpu->registers.F = 0;
    SRA(cpu, 0x28);
    CU_ASSERT_EQUAL(cpu->registers.B, 0xc5);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRA_C(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.C = 0x8a;
    cpu->registers.F = 0;
    SRA(cpu, 0x29);
    CU_ASSERT_EQUAL(cpu->registers.C, 0xc5);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRA_D(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.D = 0x8a;
    cpu->registers.F = 0;
    SRA(cpu, 0x2a);
    CU_ASSERT_EQUAL(cpu->registers.D, 0xc5);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRA_E(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.E = 0x8a;
    cpu->registers.F = 0;
    SRA(cpu, 0x2b);
    CU_ASSERT_EQUAL(cpu->registers.E, 0xc5);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRA_H(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.H = 0x8a;
    cpu->registers.F = 0;
    SRA(cpu, 0x2c);
    CU_ASSERT_EQUAL(cpu->registers.H, 0xc5);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRA_L(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.L = 0x8a;
    cpu->registers.F = 0;
    SRA(cpu, 0x2d);
    CU_ASSERT_EQUAL(cpu->registers.L, 0xc5);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRA_A(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x8a;
    cpu->registers.F = 0;
    SRA(cpu, 0x2f);
    CU_ASSERT_EQUAL(cpu->registers.A, 0xc5);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRA_HL(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.HL = 0x2342;
    cpu->memory[cpu->registers.HL] = 0x01;
    cpu->registers.F = 0;
    SRA_HL(cpu, 0x2e);
    CU_ASSERT_EQUAL(cpu->registers.HL, 0x2342);
    CU_ASSERT_EQUAL(cpu->memory[cpu->registers.HL], 0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 16);
}

void test_SRL_B(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.B = 0x8a;
    cpu->registers.F = 0;
    SRL(cpu, 0x38);
    CU_ASSERT_EQUAL(cpu->registers.B, 0x45);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRL_C(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.C = 0x8a;
    cpu->registers.F = 0;
    SRL(cpu, 0x39);
    CU_ASSERT_EQUAL(cpu->registers.C, 0x45);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRL_D(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.D = 0x8a;
    cpu->registers.F = 0;
    SRL(cpu, 0x3a);
    CU_ASSERT_EQUAL(cpu->registers.D, 0x45);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRL_E(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.E = 0x8a;
    cpu->registers.F = 0;
    SRL(cpu, 0x3b);
    CU_ASSERT_EQUAL(cpu->registers.E, 0x45);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRL_H(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.H = 0x8a;
    cpu->registers.F = 0;
    SRL(cpu, 0x3c);
    CU_ASSERT_EQUAL(cpu->registers.H, 0x45);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRL_L(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.L = 0x8a;
    cpu->registers.F = 0;
    SRL(cpu, 0x3d);
    CU_ASSERT_EQUAL(cpu->registers.L, 0x45);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRL_A(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.A = 0x8a;
    cpu->registers.F = 0;
    SRL(cpu, 0x3f);
    CU_ASSERT_EQUAL(cpu->registers.A, 0x45);
    CU_ASSERT_EQUAL(cpu->registers.F, 0);
    CU_ASSERT_EQUAL(cpu->t_cycles, 8);
}

void test_SRL_HL(void)
{
    CPU *cpu = init_cpu();
    cpu->registers.HL = 0x2341;
    cpu->memory[cpu->registers.HL] = 0x01;
    cpu->registers.F = 0;
    SRL_HL(cpu, 0x3e);
    CU_ASSERT_EQUAL(cpu->memory[cpu->registers.HL], 0x0);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b10010000);
    CU_ASSERT_EQUAL(cpu->t_cycles, 16);

    cpu->memory[cpu->registers.HL] = 0xff;
    SRL_HL(cpu, 0x3e);
    CU_ASSERT_EQUAL(cpu->memory[cpu->registers.HL], 0x7f);
    CU_ASSERT_EQUAL(cpu->registers.F, 0b00010000);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Shift instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
        test_suite,
        "Shift instructions | SLA_B shifts contents in register B left and into C flag",
        test_SLA_B
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SLA_C shifts contents in register C left and into C flag",
        test_SLA_C
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SLA_D shifts contents in register D left and into C flag",
        test_SLA_D
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SLA_E shifts contents in register E left and into C flag",
        test_SLA_E
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SLA_H shifts contents in register H left and into C flag",
        test_SLA_H
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SLA_L shifts contents in register L left and into C flag",
        test_SLA_L
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SLA_A shifts contents in register A left and into C flag",
        test_SLA_A
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SLA_HL shifts contents in register HL left and into C flag",
        test_SLA_HL
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRA_B shifts contents in register B right and into C flag",
        test_SRA_B
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRA_C shifts contents in register C right and into C flag",
        test_SRA_C
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRA_D shifts contents in register D right and into C flag",
        test_SRA_D
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRA_E shifts contents in register E right and into C flag",
        test_SRA_E
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRA_H shifts contents in register H right and into C flag",
        test_SRA_H
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRA_L shifts contents in register L right and into C flag",
        test_SRA_L
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRA_A shifts contents in register A right and into C flag",
        test_SRA_A
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRA_HL shifts contents in register HL right and into C flag",
        test_SRA_HL
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRL_B shifts contents in register B right and into C flag",
        test_SRL_B
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRL_C shifts contents in register C right and into C flag",
        test_SRL_C
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRL_D shifts contents in register D right and into C flag",
        test_SRL_D
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRL_E shifts contents in register E right and into C flag",
        test_SRL_E
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRL_H shifts contents in register H right and into C flag",
        test_SRL_H
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRL_L shifts contents in register L right and into C flag",
        test_SRL_L
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRL_A shifts contents in register A right and into C flag",
        test_SRL_A
    ) == NULL ||
    CU_add_test(
        test_suite,
        "Shift instructions | SRL_HL shifts contents in register HL right and into C flag",
        test_SRL_HL
    ) == NULL) {
        printf("Failed to add test to Shift instructions unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
