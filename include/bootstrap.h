#include <stdint.h>

#define BOOT_ROM_SIZE 0xf

uint8_t boot_rom[] = {
    0x31,   // LD SP, 0xfffe
    0xff,
    0xfe,
    0xae,   // XOR A
    0x21,   // LD HL, 0x9fff
    0x9f,
    0xff,
    0x32,   // LD (HL-), A
    0xcb,   // BIT 7, H
    0x7c,
    0x20,   // JRNZ, 0xfb
    0xfb,
    0x21,   // LD HL, 0xff26
    0xff,
    0x26
};
