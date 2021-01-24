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

void test_LD_B_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.B = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_r(&cpu, 0x46);
    CU_ASSERT_EQUAL(cpu.registers.B, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
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

void test_LD_C_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.C = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_r(&cpu, 0x4e);
    CU_ASSERT_EQUAL(cpu.registers.C, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
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

void test_LD_D_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.D = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_r(&cpu, 0x56);
    CU_ASSERT_EQUAL(cpu.registers.D, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
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

void test_LD_E_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.E = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_r(&cpu, 0x5e);
    CU_ASSERT_EQUAL(cpu.registers.E, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
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

void test_LD_H_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_r(&cpu, 0x66);
    CU_ASSERT_EQUAL(cpu.registers.H, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
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

void test_LD_L_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_r(&cpu, 0x6e);
    CU_ASSERT_EQUAL(cpu.registers.L, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
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

void test_LD_A_HL(void)
{
    CPU cpu;
    uint16_t address = 0x1000;
    uint8_t value = 0xda;
    cpu.registers.A = 0;
    cpu.registers.HL = address;
    cpu.memory[address] = value;
    LD_r_r(&cpu, 0x7e);
    CU_ASSERT_EQUAL(cpu.registers.A, value);
    CU_ASSERT_EQUAL(cpu.memory[address], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
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

void test_LD_HL_B(void)
{
    CPU cpu;
    uint16_t address = 0x3000;
    uint8_t value = 0xaa;
    cpu.registers.HL = address;
    cpu.registers.B = value;
    LD_r_r(&cpu, 0x70);
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
    LD_r_r(&cpu, 0x71);
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
    LD_r_r(&cpu, 0x72);
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
    LD_r_r(&cpu, 0x73);
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
    LD_r_r(&cpu, 0x74);
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
    LD_r_r(&cpu, 0x75);
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
    LD_r_r(&cpu, 0x77);
    CU_ASSERT_EQUAL(cpu.registers.HL, address);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
}

void test_LD_B_n(void)
{
    CPU cpu;
    uint16_t PC = 0x1010;
    uint8_t value = 0xab;
    cpu.memory[PC] = value;
    cpu.PC = PC;
    LD_r_n(&cpu, 0x06);
    CU_ASSERT_EQUAL(cpu.registers.B, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

void test_LD_C_n(void)
{
    CPU cpu;
    uint16_t PC = 0x2000;
    uint8_t value = 0xab;
    cpu.memory[PC] = value;
    cpu.PC = PC;
    LD_r_n(&cpu, 0x0e);
    CU_ASSERT_EQUAL(cpu.registers.C, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

void test_LD_D_n(void)
{
    CPU cpu;
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu.memory[PC] = value;
    cpu.PC = PC;
    LD_r_n(&cpu, 0x16);
    CU_ASSERT_EQUAL(cpu.registers.D, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

void test_LD_E_n(void)
{
    CPU cpu;
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu.memory[PC] = value;
    cpu.PC = PC;
    LD_r_n(&cpu, 0x1e);
    CU_ASSERT_EQUAL(cpu.registers.E, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

void test_LD_H_n(void)
{
    CPU cpu;
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu.memory[PC] = value;
    cpu.PC = PC;
    LD_r_n(&cpu, 0x26);
    CU_ASSERT_EQUAL(cpu.registers.H, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

void test_LD_L_n(void)
{
    CPU cpu;
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu.memory[PC] = value;
    cpu.PC = PC;
    LD_r_n(&cpu, 0x2e);
    CU_ASSERT_EQUAL(cpu.registers.L, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

void test_LD_A_n(void)
{
    CPU cpu;
    uint16_t PC = 0x1000;
    uint8_t value = 0xab;
    cpu.memory[PC] = value;
    cpu.PC = PC;
    LD_r_n(&cpu, 0x3e);
    CU_ASSERT_EQUAL(cpu.registers.A, value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 8);
    CU_ASSERT_EQUAL(cpu.PC, PC + 1);
}

void test_LD_HL_n(void)
{
    CPU cpu;
    uint16_t address = 0x1234;
    uint8_t value = 0x1e;
    cpu.memory[address] = value;
    cpu.registers.HL = address;
    cpu.PC = address;
    LD_r_n(&cpu, 0x36);
    CU_ASSERT_EQUAL(cpu.memory[cpu.registers.HL], value);
    CU_ASSERT_EQUAL(cpu.t_cycles, 12);
}

// void test_LD_A_BC(void)
// {
//     CPU cpu;
//     uint16_t address = 0xabcd;
//     uint8_t value = 0x0f;
//     cpu.registers.A = 0;
//     cpu.memory[address] = value;
//     cpu.registers.BC = address;
//     LD_A_BC(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.A, value);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LD_A_DE(void)
// {
//     CPU cpu;
//     uint16_t address = 0xabcd;
//     uint8_t value = 0x0f;
//     cpu.registers.A = 0;
//     cpu.memory[address] = value;
//     cpu.registers.DE = address;
//     LD_A_DE(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.A, value);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LD_BC_A(void)
// {
//     CPU cpu;
//     uint16_t address = 0x4f18;
//     uint8_t value = 0x12;
//     cpu.registers.A = value;
//     cpu.memory[address] = 0;
//     cpu.registers.BC = address;
//     LD_BC_A(&cpu);
//     CU_ASSERT_EQUAL(cpu.memory[cpu.registers.BC], value);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LD_DE_A(void)
// {
//     CPU cpu;
//     uint16_t address = 0x4f18;
//     uint8_t value = 0x12;
//     cpu.registers.A = value;
//     cpu.memory[address] = 0;
//     cpu.registers.DE = address;
//     LD_DE_A(&cpu);
//     CU_ASSERT_EQUAL(cpu.memory[cpu.registers.DE], value);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LD_A_nn(void)
// {
//     CPU cpu;
//     uint16_t PC = 0x1001;
//     cpu.PC = PC;
//     uint8_t value = 0x23;
//     cpu.memory[PC] = 0xab;
//     cpu.memory[PC + 1] = 0xcd;
//     cpu.memory[0xabcd] = value;
//     LD_A_nn(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.A, value);
//     CU_ASSERT_EQUAL(cpu.PC, PC + 2);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 16);
// }

// void test_LD_nn_A(void)
// {
//     CPU cpu;
//     uint16_t PC = 0x2010;
//     cpu.PC = PC;
//     uint8_t value = 0xfa;
//     cpu.memory[PC] = 0x12;
//     cpu.memory[PC + 1] = 0x34;
//     cpu.registers.A = value;
//     LD_nn_A(&cpu);
//     CU_ASSERT_EQUAL(read_byte(&cpu, 0x1234), value);
//     CU_ASSERT_EQUAL(cpu.PC, PC + 2);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 16);
// }

// void test_LDH_A_C(void)
// {
//     CPU cpu;
//     uint8_t low_bit = 0x43;
//     uint16_t address = 0xff43;
//     uint8_t value = 0x1a;
//     cpu.registers.C = low_bit;
//     cpu.memory[address] = value;
//     cpu.registers.A = 0;
//     LDH_A_C(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.A, value);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LDH_C_A(void)
// {
//     CPU cpu;
//     uint8_t low_bit = 0x43;
//     uint16_t address = 0xff43;
//     uint8_t value = 0x1a;
//     cpu.registers.C = low_bit;
//     cpu.registers.A = value;
//     cpu.memory[address] = 0;
//     LDH_C_A(&cpu);
//     CU_ASSERT_EQUAL(cpu.memory[address], value);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LDH_A_n(void)
// {
//     CPU cpu;
//     uint16_t PC = 0x2020;
//     uint8_t value = 0x69;
//     cpu.PC = PC;
//     cpu.memory[PC] = 0x12;
//     cpu.memory[0xff12] = value;
//     LDH_A_n(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.A, value);
//     CU_ASSERT_EQUAL(cpu.PC, PC + 1);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 12);
// }

// void test_LDH_n_A(void)
// {
//     CPU cpu;
//     uint16_t PC = 0x1000;
//     uint8_t value = 0x32;
//     cpu.PC = PC;
//     cpu.memory[PC] = 0x89;
//     cpu.registers.A = value;
//     LDH_n_A(&cpu);
//     CU_ASSERT_EQUAL(cpu.memory[0xff89], value);
//     CU_ASSERT_EQUAL(cpu.PC, PC + 1);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 12);
// }

// void test_LD_A_HLI(void)
// {
//     CPU cpu;
//     uint16_t HL = 0x1234;
//     uint8_t value = 0xab;
//     cpu.registers.HL = HL;
//     cpu.memory[HL] = value;
//     LD_A_HLI(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.A, value);
//     CU_ASSERT_EQUAL(cpu.registers.HL, HL + 1);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LD_A_HLD(void)
// {
//     CPU cpu;
//     uint16_t HL = 0x1234;
//     uint8_t value = 0xab;
//     cpu.registers.HL = HL;
//     cpu.memory[HL] = value;
//     LD_A_HLD(&cpu);
//     CU_ASSERT_EQUAL(cpu.registers.A, value);
//     CU_ASSERT_EQUAL(cpu.registers.HL, HL - 1);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LD_HLI_A(void)
// {
//     CPU cpu;
//     uint16_t HL = 0x1234;
//     uint8_t value = 0xdd;
//     cpu.registers.HL = HL;
//     cpu.registers.A = value;
//     LD_HLI_A(&cpu);
//     CU_ASSERT_EQUAL(cpu.memory[HL], value);
//     CU_ASSERT_EQUAL(cpu.registers.HL, HL + 1);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

// void test_LD_HLD_A(void)
// {
//     CPU cpu;
//     uint16_t HL = 0x1234;
//     uint8_t value = 0xcc;
//     cpu.registers.HL = HL;
//     cpu.registers.A = value;
//     LD_HLD_A(&cpu);
//     CU_ASSERT_EQUAL(cpu.memory[HL], value);
//     CU_ASSERT_EQUAL(cpu.registers.HL, HL - 1);
//     CU_ASSERT_EQUAL(cpu.t_cycles, 8);
// }

int main(void)
{
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to initialize CUnit\n");
        return CU_get_error();
    }

    CU_Suite *test_suite = CU_add_suite("8 bit LD Instructions unit tests", NULL, NULL);
    if (test_suite == NULL) {
        printf("Failed to add test suite\n");
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_B loadss register B value into register B and sets cycles",
            test_LD_B_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_C loads register C value into register B and sets cycles",
            test_LD_B_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_D loads register D value into register B and sets cycles",
            test_LD_B_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_E loads register E value into register B and sets cycles",
            test_LD_B_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_H loads register H value into register B and sets cycles",
            test_LD_B_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_L loads register L value into register B and sets cycles",
            test_LD_B_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_HL loads value in address stored in HL, to register B and sets cycles",
            test_LD_B_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_A loads register A value into register B and sets cycles",
            test_LD_B_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_B loads register B value into register C and sets cycles",
            test_LD_C_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_C loads register C value into register C and sets cycles",
            test_LD_C_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_D loads register D value into register C and sets cycles",
            test_LD_C_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_E loads register E value into register C and sets cycles",
            test_LD_C_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_H loads register H value into register C and sets cycles",
            test_LD_C_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_L loads register L value into register C and sets cycles",
            test_LD_C_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_HL loads value in address stored in HL, to register C and sets cycles",
            test_LD_C_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_A loads register A value into register C and sets cycles",
            test_LD_C_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_B loads register B value into register D and sets cycles",
            test_LD_D_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_C loads register C value into register D and sets cycles",
            test_LD_D_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_D loads register D value into register D and sets cycles",
            test_LD_D_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_E loads register E value into register D and sets cycles",
            test_LD_D_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_H loads register H value into register D and sets cycles",
            test_LD_D_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_L loads register L value into register D and sets cycles",
            test_LD_D_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_HL loads value in address stored in HL, to register D and sets cycles",
            test_LD_D_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_A loads register A value into register D and sets cycles",
            test_LD_D_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_B loads register B value into register E and sets cycle",
            test_LD_E_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_C loads register C value into register E and sets cycle",
            test_LD_E_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_D loads register D value into register E and sets cycle",
            test_LD_E_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_E loads register E value into register E and sets cycle",
            test_LD_E_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_H loads register H value into register E and sets cycle",
            test_LD_E_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_L loads register L value into register E and sets cycle",
            test_LD_E_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_HL loads value in address stored in HL, to register E and sets cycles",
            test_LD_E_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_A loads register A value into register E and sets cycle",
            test_LD_E_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_B loads register B value into register H and sets cycle",
            test_LD_H_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_C loads register C value into register H and sets cycle",
            test_LD_H_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_D loads register D value into register H and sets cycle",
            test_LD_H_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_E loads register E value into register H and sets cycle",
            test_LD_H_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_H loads register H value into register H and sets cycle",
            test_LD_H_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_L loads register L value into register H and sets cycle",
            test_LD_H_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_HL loads value in address stored in HL, to register H and sets cycles",
            test_LD_H_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_A loads register A value into register H and sets cycle",
            test_LD_H_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_B loads register B value into register L and sets cycle",
            test_LD_L_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_C loads register C value into register L and sets cycle",
            test_LD_L_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_D loads register D value into register L and sets cycle",
            test_LD_L_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_E loads register E value into register L and sets cycle",
            test_LD_L_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_H loads register H value into register L and sets cycle",
            test_LD_L_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_L loads register L value into register L and sets cycle",
            test_LD_L_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_HL loads value in address stored in HL, to register L and sets cycles",
            test_LD_L_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_A loads register A value into register L and sets cycle",
            test_LD_L_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_B loads register B value into register A and sets cycle",
            test_LD_A_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_C loads register C value into register A and sets cycle",
            test_LD_A_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_D loads register D value into register A and sets cycle",
            test_LD_A_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_E loads register E value into register A and sets cycle",
            test_LD_A_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_H loads register H value into register A and sets cycle",
            test_LD_A_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_L loads register L value into register A and sets cycle",
            test_LD_A_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_HL loads value in address stored in HL, to register A and sets cycles",
            test_LD_A_HL
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_A loads register A value into register A and sets cycle",
            test_LD_A_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_A_n loads immediate value into register be and sets cycles",
            test_LD_A_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_B_n loads immediate value into register be and sets cycles",
            test_LD_B_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_C_n loads immediate value into register be and sets cycles",
            test_LD_C_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_D_n loads immediate value into register be and sets cycles",
            test_LD_D_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_E_n loads immediate value into register be and sets cycles",
            test_LD_E_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_H_n loads immediate value into register be and sets cycles",
            test_LD_H_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_L_n loads immediate value into register be and sets cycles",
            test_LD_L_n
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_HL_B loads register B value into byte pointed to by register HL",
            test_LD_HL_B
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_HL_C loads register C value into byte pointed to by register HL",
            test_LD_HL_C
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_HL_D loads register D value into byte pointed to by register HL",
            test_LD_HL_D
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_HL_E loads register E value into byte pointed to by register HL",
            test_LD_HL_E
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_HL_H loads register H value into byte pointed to by register HL",
            test_LD_HL_H
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_HL_L loads register L value into byte pointed to by register HL",
            test_LD_HL_L
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_HL_A loads register A value into byte pointed to by register HL",
            test_LD_HL_A
        ) == NULL ||
        CU_add_test(
            test_suite,
            "8 bit LD Instructions | LD_HL_n loads immediate value into address stored in HL",
            test_LD_HL_n
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_A_BC loads byte pointed to by BC register into register A",
        //     test_LD_A_BC
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_A_DE loads byte pointed to by DE register into register A",
        //     test_LD_A_DE
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_BC_A loads value in register A into byte pointed to by register BC",
        //     test_LD_BC_A
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_DE_A loads value in register A into byte pointed to by register DE",
        //     test_LD_DE_A
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_A_nn loads byte pointed to by immediate value into register A",
        //     test_LD_A_nn
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_nn_A loads value in register A into byte pointed to by immediate value",
        //     test_LD_nn_A
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LDH_A_C loads byte pointed to by register C into register A",
        //     test_LDH_A_C
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LDH_C_A loads value in register A into byte pointed to by register C",
        //     test_LDH_C_A
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LDH_A_n loads byte at extended address from next PC into A",
        //     test_LDH_A_n
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LDH_n_A loads value in register A into byte pointed to by extended address from next PC",
        //     test_LDH_n_A
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_A_HLI loads byte at address in HL then increments HL",
        //     test_LD_A_HLI
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_A_HLD loads byte at address in HL then decrements HL",
        //     test_LD_A_HLD
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_HLI_A loads value in A into address in HL then increments HL",
        //     test_LD_HLI_A
        // ) == NULL ||
        // CU_add_test(
        //     test_suite,
        //     "8 bit LD Instructions | LD_HLD_A loads value in A into address in HL then decrements HL",
        //     test_LD_HLD_A
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
