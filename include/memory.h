#include <stdint.h>

#define ROM00_START 0x0000
#define ROM00_END 0x3fff
// TODO: switchable 01-NN if MB
#define ROM01_START 0x4000
#define ROM01_END 0x7fff

#define VRAM_START 0x8000
#define VRAM_END 0x9fff

#define EXTERNAL_RAM_START 0xa000
#define EXTERNAL_RAM_END 0xbfff

#define WORK_RAM0_START 0xc000
#define WORK_RAM0_END 0xcfff
// TODO: switchable bank 1~7 in CGB mode
#define WORK_ROM1_START 0xd000
#define WORK_ROM1_END 0xdfff

#define ECHO_RAM_START 0xe000
#define ECHO_RAM_END 0xfdff

#define SPRITE_TABLE_START 0xfe00
#define SPRITE_TABLE_END 0xfe9f

#define UNUSABLE_START 0xfea0
#define UNUSABLE_END 0xfeff

#define IO_REGISTERS_START 0xff00
#define IO_REGISTERS_END 0xff7f

#define HIGH_RAM_START 0xff80
#define HIGH_RAM_END 0xfffe

#define IE_REGISTER 0xffff

typedef struct Memory {
    uint16_t *AddressBus;
} Memory
