#include <stdint.h>

#define REGISTERS_COUNT 4

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
    uint16_t PC;
    uint16_t SP;
} Registers;
#endif

typedef struct CPU {
    Registers registers;
} CPU;

typedef enum {
    ZERO_FLAG_POSITION = 7,
    SUBTRACT_FLAG_POSITION = 6,
    HALF_CARRY_FLAG_POSITION = 5,
    CARRY_FLAG_POSITION = 4
} FLAG_POSITION;

uint8_t zero_flag(CPU *);
uint8_t subtract_flag(CPU *);
uint8_t half_carry_flag(CPU *);
uint8_t carry_flag(CPU *);
