/**
 * @file sfe_psram.h
 *
 * @brief Header file for a function that is used to detect and initialize PSRAM on
 *  SparkFun rp2350 boards.
 * 
 * Adapted for Pimoroni Tufty 2350, original version can be found here:
 *   https://github.com/sparkfun/sparkfun-pico/tree/main/sparkfun_pico
 */

/*
The MIT License (MIT)

Copyright (c) 2024 SparkFun Electronics

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions: The
above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED
"AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef _SFE_PSRAM_H_
#define _SFE_PSRAM_H_
#include <stdint.h>
#include <stdlib.h>

#define PSRAM_BASE ((void*)0x11000000)

extern void *psram;

#ifdef __cplusplus
extern "C"
{
#endif
/// @brief The psram_setup function - note that this is not in flash
void psram_setup(uint psram_cs_pin);

/// @brief The psram_set_timing function - note that this is not in flash
///
/// @note - updates the PSRAM QSPI timing - call if the system clock is changed after PSRAM is initialized
///
void psram_set_timing(void);
#ifdef __cplusplus
}
#endif

#endif