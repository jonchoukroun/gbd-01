#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "instructions.h"

// SLA r
void test_SLA_A(void)
{
    CPU cpu;
    cpu.registers.A = 0b10101010;
    cpu.registers.F = 0b11110000;
    SLA_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0b01010100);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.A = 128;
    cpu.registers.F = 0;
    SLA_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
}

void test_SLA_B(void)
{
    CPU cpu;
    cpu.registers.B = 0b10101010;
    cpu.registers.F = 0b11110000;
    SLA_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0b01010100);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.B = 128;
    cpu.registers.F = 0;
    SLA_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
}

void test_SLA_C(void)
{
    CPU cpu;
    cpu.registers.C = 0b10101010;
    cpu.registers.F = 0b11110000;
    SLA_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0b01010100);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.C = 128;
    cpu.registers.F = 0;
    SLA_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
}

void test_SLA_D(void)
{
    CPU cpu;
    cpu.registers.D = 0b10101010;
    cpu.registers.F = 0b11110000;
    SLA_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0b01010100);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.D = 128;
    cpu.registers.F = 0;
    SLA_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
}

void test_SLA_E(void)
{
    CPU cpu;
    cpu.registers.E = 0b10101010;
    cpu.registers.F = 0b11110000;
    SLA_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0b01010100);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.E = 128;
    cpu.registers.F = 0;
    SLA_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
}

void test_SLA_H(void)
{
    CPU cpu;
    cpu.registers.H = 0b10101010;
    cpu.registers.F = 0b11110000;
    SLA_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0b01010100);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.H = 128;
    cpu.registers.F = 0;
    SLA_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
}

void test_SLA_L(void)
{
    CPU cpu;
    cpu.registers.L = 0b10101010;
    cpu.registers.F = 0b11110000;
    SLA_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0b01010100);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.L = 128;
    cpu.registers.F = 0;
    SLA_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
}

void test_SLA_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x1234;
    cpu.memory[cpu.registers.HL] = 0b10101010;
    cpu.registers.F = 0b11110000;
    SLA_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0b01010100);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    cpu.memory[cpu.registers.HL] = 128;
    cpu.registers.F = 0;
    SLA_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10010000);
}

// SRA r
void test_SRA_A(void)
{
    CPU cpu;
    cpu.registers.A = 129;
    cpu.registers.F = 0b11110000;
    SRA_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRA_B(void)
{
    CPU cpu;
    cpu.registers.B = 129;
    cpu.registers.F = 0b11110000;
    SRA_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRA_C(void)
{
    CPU cpu;
    cpu.registers.C = 129;
    cpu.registers.F = 0b11110000;
    SRA_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRA_D(void)
{
    CPU cpu;
    cpu.registers.D = 129;
    cpu.registers.F = 0b11110000;
    SRA_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRA_E(void)
{
    CPU cpu;
    cpu.registers.E = 129;
    cpu.registers.F = 0b11110000;
    SRA_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRA_H(void)
{
    CPU cpu;
    cpu.registers.H = 129;
    cpu.registers.F = 0b11110000;
    SRA_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRA_L(void)
{
    CPU cpu;
    cpu.registers.L = 129;
    cpu.registers.F = 0b11110000;
    SRA_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRA_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x0100;
    cpu.memory[cpu.registers.HL] = 129;
    cpu.registers.F = 0b11110000;
    SRA_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0xc0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

// SRL r
void test_SRL_A(void)
{
    CPU cpu;
    cpu.registers.A = 129;
    cpu.registers.F = 0b11110000;
    SRL_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRL_B(void)
{
    CPU cpu;
    cpu.registers.B = 129;
    cpu.registers.F = 0b11110000;
    SRL_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRL_C(void)
{
    CPU cpu;
    cpu.registers.C = 129;
    cpu.registers.F = 0b11110000;
    SRL_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRL_D(void)
{
    CPU cpu;
    cpu.registers.D = 129;
    cpu.registers.F = 0b11110000;
    SRL_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRL_E(void)
{
    CPU cpu;
    cpu.registers.E = 129;
    cpu.registers.F = 0b11110000;
    SRL_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRL_H(void)
{
    CPU cpu;
    cpu.registers.H = 129;
    cpu.registers.F = 0b11110000;
    SRL_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRL_L(void)
{
    CPU cpu;
    cpu.registers.L = 129;
    cpu.registers.F = 0b11110000;
    SRL_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_SRL_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x1234;
    cpu.memory[cpu.registers.HL] = 129;
    cpu.registers.F = 0b11110000;
    SRL_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 64);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b00010000);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);
}

// SWAP r
void test_SWAP_A(void)
{
    CPU cpu;
    cpu.registers.A = 0x12;
    cpu.registers.F = 0b11110000;
    SWAP_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0x21);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.A = 0;
    SWAP_A(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.A, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

void test_SWAP_B(void)
{
    CPU cpu;
    cpu.registers.B = 0x12;
    cpu.registers.F = 0b11110000;
    SWAP_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0x21);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.B = 0;
    SWAP_B(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.B, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

void test_SWAP_C(void)
{
    CPU cpu;
    cpu.registers.C = 0x12;
    cpu.registers.F = 0b11110000;
    SWAP_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0x21);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.C = 0;
    SWAP_C(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.C, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

void test_SWAP_D(void)
{
    CPU cpu;
    cpu.registers.D = 0x12;
    cpu.registers.F = 0b11110000;
    SWAP_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0x21);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.D = 0;
    SWAP_D(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.D, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

void test_SWAP_E(void)
{
    CPU cpu;
    cpu.registers.E = 0x12;
    cpu.registers.F = 0b11110000;
    SWAP_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0x21);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.E = 0;
    SWAP_E(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.E, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

void test_SWAP_H(void)
{
    CPU cpu;
    cpu.registers.H = 0x12;
    cpu.registers.F = 0b11110000;
    SWAP_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0x21);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.H = 0;
    SWAP_H(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.H, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

void test_SWAP_L(void)
{
    CPU cpu;
    cpu.registers.L = 0x12;
    cpu.registers.F = 0b11110000;
    SWAP_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0x21);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);

    cpu.registers.L = 0;
    SWAP_L(&cpu);
    CU_ASSERT_EQUAL(cpu.registers.L, 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

void test_SWAP_HL(void)
{
    CPU cpu;
    cpu.registers.HL = 0x1234;
    cpu.memory[cpu.registers.HL] = 0x12;
    cpu.registers.F = 0b11110000;
    SWAP_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0x21);
    CU_ASSERT_EQUAL(cpu.registers.F, 0);
    CU_ASSERT_EQUAL(cpu.t_cycles, 16);

    cpu.memory[cpu.registers.HL] = 0;
    SWAP_HL(&cpu);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], 0);
    CU_ASSERT_EQUAL(cpu.registers.F, 0b10000000);
}

int main()
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("Rotate shift unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "Bit Shift Instruction | SLA_A shifts A to the left with bit 7 into C flag",
            test_SLA_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SLA_B shifts B to the left with bit 7 into C flag",
            test_SLA_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SLA_C shifts C to the left with bit 7 into C flag",
            test_SLA_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SLA_D shifts D to the left with bit 7 into C flag",
            test_SLA_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SLA_E shifts E to the left with bit 7 into C flag",
            test_SLA_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SLA_H shifts H to the left with bit 7 into C flag",
            test_SLA_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SLA_L shifts L to the left with bit 7 into C flag",
            test_SLA_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SLA_HL shifts byte at HL to the left with bit 7 into C flag",
            test_SLA_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRA_A shifts A to the right with bit 0 into C flag and bit 7 preserved",
            test_SRA_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRA_B shifts B to the right with bit 0 into C flag and bit 7 preserved",
            test_SRA_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRA_C shifts C to the right with bit 0 into C flag and bit 7 preserved",
            test_SRA_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRA_D shifts D to the right with bit 0 into C flag and bit 7 preserved",
            test_SRA_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRA_E shifts E to the right with bit 0 into C flag and bit 7 preserved",
            test_SRA_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRA_H shifts H to the right with bit 0 into C flag and bit 7 preserved",
            test_SRA_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRA_L shifts L to the right with bit 0 into C flag and bit 7 preserved",
            test_SRA_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRA_HL shifts HL to the right with bit 0 into C flag and bit 7 preserved",
            test_SRA_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRL_A shifts A to the right with bit 0 into C flag and bit 7 reset",
            test_SRL_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRL_B shifts B to the right with bit 0 into C flag and bit 7 reset",
            test_SRL_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRL_C shifts C to the right with bit 0 into C flag and bit 7 reset",
            test_SRL_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRL_D shifts D to the right with bit 0 into C flag and bit 7 reset",
            test_SRL_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRL_E shifts E to the right with bit 0 into C flag and bit 7 reset",
            test_SRL_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRL_H shifts H to the right with bit 0 into C flag and bit 7 reset",
            test_SRL_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRL_L shifts L to the right with bit 0 into C flag and bit 7 reset",
            test_SRL_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SRL_HL shifts byte at HL to the right with bit 0 into C flag and bit 7 reset",
            test_SRL_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SWAP_A swaps A's upper and lower bits and only affects Z flag",
            test_SWAP_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SWAP_B swaps B's upper and lower bits and only affects Z flag",
            test_SWAP_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SWAP_C swaps C's upper and lower bits and only affects Z flag",
            test_SWAP_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SWAP_D swaps D's upper and lower bits and only affects Z flag",
            test_SWAP_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SWAP_E swaps E's upper and lower bits and only affects Z flag",
            test_SWAP_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SWAP_H swaps H's upper and lower bits and only affects Z flag",
            test_SWAP_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SWAP_L swaps L's upper and lower bits and only affects Z flag",
            test_SWAP_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "Bit Shift Instruction | SWAP_HL swaps byte at HL's upper and lower bits and only affects Z flag",
            test_SWAP_HL
        ) == NULL) {
        printf("Failed to add test to bit shift unit test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
