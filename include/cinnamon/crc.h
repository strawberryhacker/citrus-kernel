/// Copyright (C) strawberryhacker

#ifndef CRC_H
#define CRC_H

#include <cinnamon/types.h>

u8 crc_calculate(const void* src, u32 size, u8 poly);

#endif