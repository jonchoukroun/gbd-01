#ifndef Cpu
#define Cpu

#include <stdint.h>
#include "memory.h"

#ifdef __BIG_ENDIAN__
typedef struct Registers {
    union {
        uint16_t AF;
        struct {
            uint8_t A;
            uint8_t F;
        };
    };
    union {
        uint16_t BC;
        struct {
            uint8_t B;
            uint8_t C;
        };
    };
    union {
        uint16_t DE;
        struct {
            uint8_t D;
            uint8_t E;
        };
    };
    union {
        uint16_t HL;
        struct {
            uint8_t H;
            uint8_t L;
        };
    };
    uint16_t PC;
    uint16_t SP;
} Registers;
#else
typedef struct Registers {
    union {
        uint16_t AF;
        struct {
            uint8_t F;
            uint8_t A;
        };
    };
    union {
        uint16_t BC;
        struct {
            uint8_t C;
            uint8_t B;
        };
    };
    union {
        uint16_t DE;
        struct {
            uint8_t E;
            uint8_t D;
        };
    };
    union {
        uint16_t HL;
        struct {
            uint8_t L;
            uint8_t H;
        };
    };
} Registers;
#endif

typedef struct CPU {
    Registers registers;
    uint16_t PC;
    uint16_t SP;
    uint16_t memory[ADDRESS_BUS_SIZE];
    uint8_t t_cycles;
} CPU;

typedef enum {
    Z_FLAG = 7,
    N_FLAG = 6,
    H_FLAG = 5,
    C_FLAG = 4
} FlagPosition;

typedef enum {
    BYTE = 0,
    WORD = 1
} USIZE;

CPU * init_cpu(void);

uint8_t fetch_opcode(CPU *);

uint8_t read_byte(CPU *, uint16_t addr);
uint16_t read_word(CPU *, uint16_t addr);
void write_byte(CPU *, uint8_t byte, uint16_t address);
void write_word(CPU *, uint16_t word, uint16_t address);

uint8_t get_flag(CPU *, FlagPosition);
void set_flag(CPU *, FlagPosition);
void clear_flag(CPU *, FlagPosition);
void reset_flags(CPU *);

// Interrupt Flags
void set_IME(CPU *);
void reset_IME(CPU *);

#endif
