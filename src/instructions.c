#include <stdio.h>
#include "instructions.h"

// **************************************************
// Utility Functions
// **************************************************

/**
 * Access register bitmaps directly
 * Note: reg_HL is invalid
 **/
typedef enum {
    reg_B, reg_C, reg_D, reg_E,
    reg_H, reg_L, reg_HL, reg_A,
} REGISTER_MAP;

/**
 * Return value in 8-bit registers based on bit code from opcode
 **/
uint8_t fetch_r8(CPU *cpu, uint8_t r)
{
    uint8_t registers[] = {
        cpu->registers.B,
        cpu->registers.C,
        cpu->registers.D,
        cpu->registers.E,
        cpu->registers.H,
        cpu->registers.L,
        0,
        cpu->registers.A,
    };

    return registers[r];
}

/**
 * Set values to 8-bit registers
 * and memory pointed to by address in HL.
 * Accessible as function pointers in RegSet_8 bitmap.
 **/
typedef void (*RegSet_8)(CPU *, uint8_t value);
void set_B(CPU *cpu, uint8_t n) { cpu->registers.B = n; }
void set_C(CPU *cpu, uint8_t n) { cpu->registers.C = n; }
void set_D(CPU *cpu, uint8_t n) { cpu->registers.D = n; }
void set_E(CPU *cpu, uint8_t n) { cpu->registers.E = n; }
void set_H(CPU *cpu, uint8_t n) { cpu->registers.H = n; }
void set_L(CPU *cpu, uint8_t n) { cpu->registers.L = n; }
void set_at_HL(CPU *cpu, uint8_t n) {
    write_byte(cpu, n, cpu->registers.HL);
    cpu->t_cycles += 4;
}
void set_A(CPU *cpu, uint8_t n) { cpu->registers.A = n; }

static const RegSet_8 R_TABLE_8[8] = {
    &set_B, &set_C, &set_D, &set_E,
    &set_H, &set_L, &set_at_HL, &set_A
};

/**
 * Masks for decoding opcode into registers
 **/
#define DEST_MASK 56     // 0b00 111 000
#define SRC_MASK   7     // 0b00 000 111
#define MASK_R16  48     // 0b00 110 000


// **************************************************
// 8-bit load instructions
// **************************************************

void LD_r_r(CPU *cpu, uint8_t opcode)
{
    uint8_t dest_code = ((opcode & DEST_MASK) >> 3);
    uint8_t src_code = opcode & SRC_MASK;
    uint8_t src = fetch_r8(cpu, src_code);

    RegSet_8 set_R = R_TABLE_8[dest_code];
    set_R(cpu, src);

    cpu->t_cycles = 4;
}

void LD_r_HL(CPU *cpu, uint8_t opcode)
{
    uint8_t dest_code = ((opcode & DEST_MASK) >> 3);
    RegSet_8 set_R = R_TABLE_8[dest_code];
    set_R(cpu, read_byte(cpu, cpu->registers.HL));

    cpu->t_cycles = 8;
}

void LD_r_n(CPU *cpu, uint8_t opcode)
{
    cpu->t_cycles = 8;
    uint8_t r = (opcode & DEST_MASK) >> 3;
    RegSet_8 set_R = R_TABLE_8[r];
    set_R(cpu, fetch_opcode(cpu));
}

void LD_HL_r(CPU *cpu, uint8_t opcode)
{
    uint8_t r_code = opcode & SRC_MASK;
    write_byte(cpu, fetch_r8(cpu, r_code), cpu->registers.HL);
    cpu->t_cycles = 8;
}

void LD_A_rr(CPU *cpu, uint8_t opcode)
{
    cpu->t_cycles = 8;
    uint8_t byte = 0;
    switch (0xff & opcode) {
        case 0x0a:
            byte = read_byte(cpu, cpu->registers.BC);
            break;
        case 0x1a:
            byte = read_byte(cpu, cpu->registers.DE);
            break;
        case 0xf0:
            byte = read_byte(cpu, 0xff00 + fetch_opcode(cpu));
            cpu->t_cycles += 4;
            break;
        case 0xf2:
            byte = read_byte(cpu, 0xff00 + fetch_r8(cpu, reg_C));
            break;
        case 0xfa: {
            uint16_t addr = (fetch_opcode(cpu) << 8) | fetch_opcode(cpu);
            byte = read_byte(cpu, addr);
            cpu->t_cycles += 8;
            break;
        }
        default:
            printf("Invalid read source\n");
            break;
    }

    set_A(cpu, byte);
}

void LD_rr_A(CPU *cpu, uint8_t opcode)
{
    cpu->t_cycles = 8;
    uint16_t addr = 0;
    switch (0xff & opcode) {
        case 0x02:
            addr = cpu->registers.BC;
            break;
        case 0x12:
            addr = cpu->registers.DE;
            break;
        case 0xe0:
            addr = 0xff00 + fetch_opcode(cpu);
            cpu->t_cycles += 4;
            break;
        case 0xe2:
            addr = 0xff00 + fetch_r8(cpu, reg_C);
            break;
        case 0xea:
            addr = (fetch_opcode(cpu) << 8) | fetch_opcode(cpu);
            cpu->t_cycles += 8;
            break;
        default:
            printf("Invalid write destination\n");
            break;
    }
    write_byte(cpu, fetch_r8(cpu, reg_A), addr);
}

void LD_A_HLI(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    set_A(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->registers.HL++;
    cpu->t_cycles = 8;
}

void LD_A_HLD(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    set_A(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->registers.HL--;
    cpu->t_cycles = 8;
}

void LD_HLI_A(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    write_byte(cpu, fetch_r8(cpu, reg_A), cpu->registers.HL);
    cpu->registers.HL++;
    cpu->t_cycles = 8;
}

void LD_HLD_A(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    write_byte(cpu, fetch_r8(cpu, reg_A), cpu->registers.HL);
    cpu->registers.HL--;
    cpu->t_cycles = 8;
}


// **************************************************
// 16-bit load instructions
// **************************************************

/**
 * Return value in 16-bit registers based on bit code from opcode
 **/
uint16_t fetch_r16(CPU *cpu, uint8_t r)
{
    uint16_t registers[] = {
        cpu->registers.BC,
        cpu->registers.DE,
        cpu->registers.HL,
        cpu->registers.AF
    };

    return registers[r];
}

/**
 * Set values to 16-bit registers.
 * Accessible as function pointers in RegSet_16 bitmap.
 **/
typedef void (*RegSet_16)(CPU *, uint16_t value);
void set_BC(CPU *cpu, uint16_t nn) { cpu->registers.BC = nn; }
void set_DE(CPU *cpu, uint16_t nn) { cpu->registers.DE = nn; }
void set_HL(CPU *cpu, uint16_t nn) { cpu->registers.HL = nn; }
void set_SP(CPU *cpu, uint16_t nn) { cpu->SP = nn; }

static const RegSet_16 R_TABLE_16[] = {
    &set_BC, &set_DE, &set_HL, &set_SP
};

void LD_rr_nn(CPU *cpu, uint8_t opcode)
{
    uint16_t nn = (fetch_opcode(cpu) << 8) | fetch_opcode(cpu);
    RegSet_16 set_RR = R_TABLE_16[(opcode & MASK_R16) >> 4];
    set_RR(cpu, nn);
    cpu->t_cycles = 12;
}

void LD_SP_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    set_SP(cpu, cpu->registers.HL);
    cpu->t_cycles = 8;
}

void PUSH_rr(CPU *cpu, uint8_t opcode)
{
    uint16_t rr = fetch_r16(cpu, (opcode & MASK_R16) >> 4);
    cpu->SP--;
    cpu->memory[cpu->SP] = rr & 0xff;
    cpu->SP--;
    cpu->memory[cpu->SP] = (rr & 0xff00) >> 8;

    cpu->t_cycles = 16;
}

void POP_rr(CPU *cpu, uint8_t opcode)
{
    uint8_t low = cpu->memory[cpu->SP];
    cpu->SP++;
    uint8_t high = cpu->memory[cpu->SP];
    cpu->SP++;
    RegSet_16 set_RR = R_TABLE_16[(opcode & MASK_R16) >> 4];
    set_RR(cpu, (high << 8) | low);

    cpu->t_cycles = 12;
}


// **************************************************
// 8-bit ALU instructions
// **************************************************

/**
 * Add value n into register A
 * Set Z flag if sum is 0 (or 0xff + 1)
 * Clear N flag
 * Set H flag on carry from 3rd bit (> 0xf)
 * Set C flag on carry from 7th bit (> 0xff)
 **/
void add_n(CPU *cpu, uint8_t n)
{
    uint8_t A = fetch_r8(cpu, reg_A);

    reset_flags(cpu);
    if (((A + n) & 0xff) == 0) set_flag(cpu, Z_FLAG);
    if ((A & 0xf) + (n & 0xf) > 0xf) set_flag(cpu, H_FLAG);
    if (0xff - A <= n) set_flag(cpu, C_FLAG);

    set_A(cpu, A + n);
}

void ADD_r(CPU *cpu, uint8_t opcode)
{
    add_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void ADD_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    add_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void ADD_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    add_n(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

void ADC_r(CPU *cpu, uint8_t opcode)
{
    uint8_t carry = get_flag(cpu, C_FLAG);
    add_n(cpu, fetch_r8(cpu, opcode & SRC_MASK) + carry);
    cpu->t_cycles = 4;
}

void ADC_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t carry = get_flag(cpu, C_FLAG);
    add_n(cpu, fetch_opcode(cpu) + carry);
    cpu->t_cycles = 8;
}

void ADC_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t carry = get_flag(cpu, C_FLAG);
    add_n(cpu, read_byte(cpu, cpu->registers.HL) + carry);
    cpu->t_cycles = 8;
}

/**
 * Return difference between register A and value n
 * Set N flag
 * Set Z flag if difference is 0
 * Set H flag on borrow from 4rd bit
 * Set C flag if n is greater than A
 **/
uint8_t sub_n(CPU *cpu, uint8_t n)
{
    uint8_t A = fetch_r8(cpu, reg_A);

    reset_flags(cpu);
    set_flag(cpu, N_FLAG);
    if (A == n) set_flag(cpu, Z_FLAG);
    if ((n & 0xf) > (A & 0xf)) set_flag(cpu, H_FLAG);
    if (n > A) set_flag(cpu, C_FLAG);

    return A - n;
}

void SUB_r(CPU *cpu, uint8_t opcode)
{
    uint8_t diff = sub_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    set_A(cpu, diff);
    cpu->t_cycles = 4;
}

void SUB_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t diff = sub_n(cpu, fetch_opcode(cpu));
    set_A(cpu, diff);
    cpu->t_cycles = 8;
}

void SUB_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t diff = sub_n(cpu, read_byte(cpu, cpu->registers.HL));
    set_A(cpu, diff);
    cpu->t_cycles = 8;
}

void SBC_A_r(CPU *cpu, uint8_t opcode)
{
    uint8_t diff = sub_n(cpu, fetch_r8(cpu, opcode & SRC_MASK) + get_flag(cpu, C_FLAG));
    set_A(cpu, diff);
    cpu->t_cycles = 4;
}

void SBC_A_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t diff = sub_n(cpu, fetch_opcode(cpu) + get_flag(cpu, C_FLAG));
    set_A(cpu, diff);
    cpu->t_cycles = 8;
}

void SBC_A_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t diff = sub_n(cpu, read_byte(cpu, cpu->registers.HL) + get_flag(cpu, C_FLAG));
    set_A(cpu, diff);
    cpu->t_cycles = 8;
}

/**
 * Set logical AND of register A and n
 * Clear N and C flags
 * Set H flag
 * Set Z flag if A & n is 0
 **/
void and_n(CPU *cpu, uint8_t n)
{
    uint8_t A = fetch_r8(cpu, reg_A);

    reset_flags(cpu);
    set_flag(cpu, H_FLAG);
    if ((n & A) == 0) set_flag(cpu, Z_FLAG);

    set_A(cpu, n & A);
}

void AND_A_r(CPU *cpu, uint8_t opcode)
{
    and_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void AND_A_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    and_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void AND_A_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    and_n(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

/**
 * Set logical OR of register A and n
 * Clear N, H, and C flags
 * Set Z flag if A & n is 0
 **/
void or_n(CPU *cpu, uint8_t n)
{
    uint8_t A = fetch_r8(cpu, reg_A);

    reset_flags(cpu);
    if ((A | n) == 0) set_flag(cpu, Z_FLAG);

    set_A(cpu, A | n);
}

void OR_A_r(CPU *cpu, uint8_t opcode)
{
    or_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void OR_A_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    or_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void OR_A_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    or_n(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

/**
 * Set logical XOR of register A and n
 * Clear N, H, and C flags
 * Set Z flag if A & n is 0
 **/
void xor_n(CPU *cpu, uint8_t n)
{
    uint8_t A = fetch_r8(cpu, reg_A);

    reset_flags(cpu);
    if ((A ^ n) == 0) set_flag(cpu, Z_FLAG);

    set_A(cpu, A | n);
}

void XOR_A_r(CPU *cpu, uint8_t opcode)
{
    or_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void XOR_A_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    or_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void XOR_A_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    or_n(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

void CP_A_r(CPU *cpu, uint8_t opcode)
{
    sub_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void CP_A_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    sub_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void CP_A_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    sub_n(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

void UNDEF(CPU *cpu, uint8_t opcode)
{
    (void)cpu;
    printf("Opcode 0x%x is undefined\n", opcode);
}
