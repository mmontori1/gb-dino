#ifndef MTIME_H
#define MTIME_H

#include <asm/types.h>

BOOLEAN intervalCheck(UINT16 *currentTime, UINT8 rate);
BOOLEAN deltaWait(UINT16 *wait, UINT16 *time, UINT8 diff);
UINT8 getRand();
clock_t getClock();

#endif
