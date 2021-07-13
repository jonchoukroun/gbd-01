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
 * Specific to register pair fetches for 8-bit operations
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

void SBC_r(CPU *cpu, uint8_t opcode)
{
    uint8_t diff = sub_n(cpu, fetch_r8(cpu, opcode & SRC_MASK) + get_flag(cpu, C_FLAG));
    set_A(cpu, diff);
    cpu->t_cycles = 4;
}

void SBC_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t diff = sub_n(cpu, fetch_opcode(cpu) + get_flag(cpu, C_FLAG));
    set_A(cpu, diff);
    cpu->t_cycles = 8;
}

void SBC_HL(CPU *cpu, uint8_t opcode)
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

void AND_r(CPU *cpu, uint8_t opcode)
{
    and_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void AND_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    and_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void AND_HL(CPU *cpu, uint8_t opcode)
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

void OR_r(CPU *cpu, uint8_t opcode)
{
    or_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void OR_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    or_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void OR_HL(CPU *cpu, uint8_t opcode)
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

void XOR_r(CPU *cpu, uint8_t opcode)
{
    or_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void XOR_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    or_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void XOR_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    or_n(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

void CP_r(CPU *cpu, uint8_t opcode)
{
    sub_n(cpu, fetch_r8(cpu, opcode & SRC_MASK));
    cpu->t_cycles = 4;
}

void CP_n(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    sub_n(cpu, fetch_opcode(cpu));
    cpu->t_cycles = 8;
}

void CP_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    sub_n(cpu, read_byte(cpu, cpu->registers.HL));
    cpu->t_cycles = 8;
}

void INC_r(CPU *cpu, uint8_t opcode)
{
    uint8_t r_code = (opcode & DEST_MASK) >> 3;
    uint8_t r = fetch_r8(cpu, r_code);

    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    if ((r & 0xf) == 0xf) set_flag(cpu, H_FLAG);
    if (r == 0xff) set_flag(cpu, Z_FLAG);

    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r + 1);

    cpu->t_cycles = 4;
}

void INC_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t byte = read_byte(cpu, cpu->registers.HL);

    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    if ((byte & 0xf) == 0xf) set_flag(cpu, H_FLAG);
    if (byte == 0xff) set_flag(cpu, Z_FLAG);

    write_byte(cpu, byte + 1, cpu->registers.HL);

    cpu->t_cycles = 8;
}

void DEC_r(CPU *cpu, uint8_t opcode)
{
    uint8_t r_code = (opcode & DEST_MASK) >> 3;
    uint8_t r = fetch_r8(cpu, r_code);

    clear_flag(cpu, Z_FLAG);
    clear_flag(cpu, H_FLAG);
    set_flag(cpu, N_FLAG);
    if (r == 0x1) set_flag(cpu, Z_FLAG);
    if ((r & 0xf) == 0) set_flag(cpu, H_FLAG);

    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r - 1);

    cpu->t_cycles = 4;
}

void DEC_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t byte = read_byte(cpu, cpu->registers.HL);

    clear_flag(cpu, Z_FLAG);
    set_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    if ((byte & 0xf) == 0) set_flag(cpu, H_FLAG);
    if (byte == 0x1) set_flag(cpu, Z_FLAG);

    write_byte(cpu, byte - 1, cpu->registers.HL);

    cpu->t_cycles = 8;
}


// **************************************************
// 16-bit load instructions
// **************************************************

/**
 * Return value in 16-bit registers based on bit code from opcode
 * Specific to register pair fetches for 16-bit operations
 **/
uint16_t fetch_register_pairs(CPU *cpu, uint8_t rr) {
    uint16_t REGISTER_PAIRS[] = {
            cpu->registers.BC,
            cpu->registers.DE,
            cpu->registers.HL,
            cpu->SP
    };

    return REGISTER_PAIRS[rr];
}

void ADD_rr(CPU *cpu, uint8_t opcode)
{
    uint16_t rr = fetch_register_pairs(cpu, (opcode & MASK_R16) >> 4);
    uint16_t HL = cpu->registers.HL;

    clear_flag(cpu, N_FLAG);
    clear_flag(cpu, H_FLAG);
    clear_flag(cpu, C_FLAG);
    if ((rr & 0xf00) + (HL & 0xf00) > 0xf00) set_flag(cpu, H_FLAG);
    if (0xffff - rr < HL) set_flag(cpu, C_FLAG);

    set_HL(cpu, rr + cpu->registers.HL);

    cpu->t_cycles = 8;
}

void ADD_e(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);

    uint8_t e = fetch_opcode(cpu);
    if (0b10000000 & e) {
        e = (~e) + 1;
        if ((cpu->SP & 0xf) < (e & 0xf)) set_flag(cpu, H_FLAG);
        if ((cpu->SP & 0xff) < e) set_flag(cpu, C_FLAG);

        cpu->SP -= e;
    } else {
        if ((cpu->SP & 0xf) + (e & 0xf) > 0xf) set_flag(cpu, H_FLAG);
        if (0xff - e < (cpu->SP & 0xff)) set_flag(cpu, C_FLAG);

        cpu->SP += e;
    }

    cpu->t_cycles = 16;
}


void INC_rr(CPU *cpu, uint8_t opcode)
{
    uint8_t rr_code = (opcode & MASK_R16) >> 4;
    uint16_t rr = fetch_register_pairs(cpu, rr_code);
    RegSet_16 set_RR = R_TABLE_16[rr_code];
    set_RR(cpu, rr + 1);

    cpu->t_cycles = 8;
}

void DEC_rr(CPU *cpu, uint8_t opcode)
{
    uint8_t rr_code = (opcode & MASK_R16) >> 4;
    uint16_t rr = fetch_register_pairs(cpu, rr_code);
    RegSet_16 set_RR = R_TABLE_16[rr_code];
    set_RR(cpu, rr - 1);

    cpu->t_cycles = 8;
}


// **************************************************
// Rotate shift instructions
// **************************************************

/**
 * Bit masks for 8-bit value
 **/
#define BIT_7_MASK 128
#define BIT_0_MASK 1

void RLCA(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);
    uint8_t A = fetch_r8(cpu, reg_A);
    if (A & BIT_7_MASK) set_flag(cpu, C_FLAG);
    set_A(cpu, (A << 1 | A >> 7));
    cpu->t_cycles = 4;
}

void RLA(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t carry = get_flag(cpu, C_FLAG);
    reset_flags(cpu);
    uint8_t A = fetch_r8(cpu, reg_A);
    if (A & BIT_7_MASK) set_flag(cpu, C_FLAG);
    A <<= 1;
    A |= carry;
    set_A(cpu, A);
    cpu->t_cycles = 4;
}

void RRCA(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);
    uint8_t A = fetch_r8(cpu, reg_A);
    if (A & BIT_0_MASK) set_flag(cpu, C_FLAG);
    set_A(cpu, (A << 7 | A >> 1));
    cpu->t_cycles = 4;
}

void RRA(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t carry = get_flag(cpu, C_FLAG);
    reset_flags(cpu);
    uint8_t A = fetch_r8(cpu, reg_A);
    if (A & BIT_0_MASK) set_flag(cpu, C_FLAG);
    A >>= 1;
    A |= (carry << 7);
    set_A(cpu, A);
    cpu->t_cycles = 4;
}

void RLC(CPU *cpu, uint8_t opcode)
{
    reset_flags(cpu);
    uint8_t r_code = opcode & SRC_MASK;
    uint8_t r = fetch_r8(cpu, r_code);
    if (r & BIT_7_MASK) set_flag(cpu, C_FLAG);
    RegSet_8 set_R = R_TABLE_8[r_code];
    r = (r << 1 | r >> 7);
    if (r == 0) set_flag(cpu, Z_FLAG);
    set_R(cpu, r);

    cpu->t_cycles = 8;
}

void RLC_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & BIT_7_MASK) set_flag(cpu, C_FLAG);
    byte = (byte << 1 | byte >> 7);
    if (byte == 0) set_flag(cpu, Z_FLAG);
    write_byte(cpu, byte, cpu->registers.HL);

    cpu->t_cycles = 16;
}

void RL(CPU *cpu, uint8_t opcode)
{
    uint8_t carry = get_flag(cpu, C_FLAG);
    reset_flags(cpu);
    uint8_t r_code = (opcode & SRC_MASK);
    uint8_t r = fetch_r8(cpu, r_code);
    if (r & BIT_7_MASK) set_flag(cpu, C_FLAG);
    r <<= 1;
    r |= carry;
    if (r == 0) set_flag(cpu, Z_FLAG);
    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r);
    cpu->t_cycles = 8;
}

void RL_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t carry = get_flag(cpu, C_FLAG);
    reset_flags(cpu);
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & BIT_7_MASK) set_flag(cpu, C_FLAG);
    byte <<= 1;
    byte |= carry;
    if (byte == 0) set_flag(cpu, Z_FLAG);
    write_byte(cpu, byte, cpu->registers.HL);
    cpu->t_cycles = 16;
}

void RRC(CPU *cpu, uint8_t opcode)
{
    reset_flags(cpu);
    uint8_t r_code = opcode & SRC_MASK;
    uint8_t r = fetch_r8(cpu, r_code);
    if (r & BIT_0_MASK) set_flag(cpu, C_FLAG);
    RegSet_8 set_R = R_TABLE_8[r_code];
    r = (r << 7 | r >> 1);
    if (r == 0) set_flag(cpu, Z_FLAG);
    set_R(cpu, r);

    cpu->t_cycles = 8;
}

void RRC_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & BIT_0_MASK) set_flag(cpu, C_FLAG);
    byte = (byte << 7 | byte >> 1);
    if (byte == 0) set_flag(cpu, Z_FLAG);
    write_byte(cpu, byte, cpu->registers.HL);

    cpu->t_cycles = 16;
}

void RR(CPU *cpu, uint8_t opcode)
{
    uint8_t carry = get_flag(cpu, C_FLAG);
    reset_flags(cpu);
    uint8_t r_code = (opcode & SRC_MASK);
    uint8_t r = fetch_r8(cpu, r_code);
    if (r & BIT_0_MASK) set_flag(cpu, C_FLAG);
    r >>= 1;
    r |= (carry << 7);
    if (r == 0) set_flag(cpu, Z_FLAG);
    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r);
    cpu->t_cycles = 8;
}

void RR_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t carry = get_flag(cpu, C_FLAG);
    reset_flags(cpu);
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & BIT_0_MASK) set_flag(cpu, C_FLAG);
    byte >>= 1;
    byte |= (carry << 7);
    if (byte == 0) set_flag(cpu, Z_FLAG);
    write_byte(cpu, byte, cpu->registers.HL);
    cpu->t_cycles = 16;
}

void SLA(CPU *cpu, uint8_t opcode)
{
    reset_flags(cpu);
    uint8_t r_code = (opcode & SRC_MASK);
    uint8_t r = fetch_r8(cpu, r_code);
    if (r & BIT_7_MASK) set_flag(cpu, C_FLAG);
    r <<= 1;
    if (r == 0) set_flag(cpu, Z_FLAG);
    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r);
    cpu->t_cycles = 8;
}

void SLA_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & BIT_7_MASK) set_flag(cpu, C_FLAG);
    byte <<= 1;
    if (byte == 0) set_flag(cpu, Z_FLAG);
    write_byte(cpu, byte, cpu->registers.HL);
    cpu->t_cycles = 16;
}

void SRA(CPU *cpu, uint8_t opcode)
{
    reset_flags(cpu);
    uint8_t r_code = (opcode & SRC_MASK);
    uint8_t r = fetch_r8(cpu, r_code);
    if (r & BIT_0_MASK) set_flag(cpu, C_FLAG);
    uint8_t bit_7 = r & BIT_7_MASK;
    r >>= 1;
    r ^= bit_7;
    if (r == 0) set_flag(cpu, Z_FLAG);
    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r);
    cpu->t_cycles = 8;
}

void SRA_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & BIT_0_MASK) set_flag(cpu, C_FLAG);
    uint8_t bit_7 = byte & BIT_7_MASK;
    byte >>= 1;
    byte ^= bit_7;
    if (byte == 0) set_flag(cpu, Z_FLAG);
    write_byte(cpu, byte, cpu->registers.HL);
    cpu->t_cycles = 16;
}

void SRL(CPU *cpu, uint8_t opcode)
{
    reset_flags(cpu);
    uint8_t r_code = (opcode & SRC_MASK);
    uint8_t r = fetch_r8(cpu, r_code);
    if (r & BIT_0_MASK) set_flag(cpu, C_FLAG);
    r >>= 1;
    if (r == 0) set_flag(cpu, Z_FLAG);
    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r);
    cpu->t_cycles = 8;
}

void SRL_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    if (byte & BIT_0_MASK) set_flag(cpu, C_FLAG);
    byte >>= 1;
    if (byte == 0) set_flag(cpu, Z_FLAG);
    write_byte(cpu, byte, cpu->registers.HL);
    cpu->t_cycles = 16;
}

void SWAP(CPU *cpu, uint8_t opcode)
{
    reset_flags(cpu);
    uint8_t r_code = opcode & SRC_MASK;
    uint8_t r = fetch_r8(cpu, r_code);
    uint8_t upper = (r & 0b11110000) >> 4;
    uint8_t lower = r & 0b00001111;
    r = ((lower << 4) ^ upper);
    if (r == 0) set_flag(cpu, Z_FLAG);
    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r);
    cpu->t_cycles = 8;
}

void SWAP_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    reset_flags(cpu);
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    uint8_t upper = (byte & 0b11110000) >> 4;
    uint8_t lower = byte & 0b00001111;
    byte = (lower << 4) ^ upper;
    if (byte == 0) set_flag(cpu, Z_FLAG);
    write_byte(cpu, byte, cpu->registers.HL);
    cpu->t_cycles = 16;
}

// **************************************************
// Bit instructions
// **************************************************

void BIT(CPU *cpu, uint8_t opcode)
{
    uint8_t r_code = opcode & SRC_MASK;
    uint8_t r = fetch_r8(cpu, r_code);
    uint8_t bit = (opcode & DEST_MASK) >> 3;
    clear_flag(cpu, N_FLAG);
    set_flag(cpu, H_FLAG);
    uint8_t value = (r & (1 << bit)) >> bit;
    if (value == 0) {
        set_flag(cpu, Z_FLAG);
    } else {
        clear_flag(cpu, Z_FLAG);
    }
    cpu->t_cycles = 8;
}

void BIT_HL(CPU *cpu, uint8_t opcode)
{
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    uint8_t bit = (opcode & DEST_MASK) >> 3;
    clear_flag(cpu, N_FLAG);
    set_flag(cpu, H_FLAG);
    uint8_t value = (byte & (1 << bit)) >> bit;
    if (value == 0) {
        set_flag(cpu, Z_FLAG);
    } else {
        clear_flag(cpu, Z_FLAG);
    }
    cpu->t_cycles = 12;
}

void SET(CPU *cpu, uint8_t opcode)
{
    uint8_t r_code = opcode & SRC_MASK;
    uint8_t r = fetch_r8(cpu, r_code);
    uint8_t bit = (opcode & DEST_MASK) >> 3;
    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r | (1 << bit));
    cpu->t_cycles = 8;
}

void SET_HL(CPU *cpu, uint8_t opcode)
{
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    uint8_t bit = (opcode & DEST_MASK) >> 3;
    write_byte(cpu, byte | (1 << bit), cpu->registers.HL);
    cpu->t_cycles = 16;
}

void RES(CPU *cpu, uint8_t opcode)
{
    uint8_t r_code = opcode & SRC_MASK;
    uint8_t r = fetch_r8(cpu, r_code);
    uint8_t bit = (opcode & DEST_MASK) >> 3;
    RegSet_8 set_R = R_TABLE_8[r_code];
    set_R(cpu, r & ~(0b1 << bit));
    cpu->t_cycles = 8;
}

void RES_HL(CPU *cpu, uint8_t opcode)
{
    (void)opcode;
    uint8_t byte = read_byte(cpu, cpu->registers.HL);
    uint8_t bit = (opcode & DEST_MASK) >> 3;
    write_byte(cpu, byte & ~(0b1 << bit), cpu->registers.HL);
    cpu->t_cycles = 16;
}

void UNDEF(CPU *cpu, uint8_t opcode)
{
    (void)cpu;
    printf("Opcode 0x%x is undefined\n", opcode);
}
