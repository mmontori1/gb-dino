#ifndef MTIME_H
#define MTIME_H

#include <asm/types.h>

BOOLEAN intervalCheck(UINT16 *currentTime, UINT8 rate);
BOOLEAN deltaWait(UINT16 *time, UINT8 diff);
void setWait(UINT8 val);
UINT8 getRand();
clock_t getClock();

#endif
