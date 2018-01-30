#ifndef GLOBAL_H
#define GLOBAL_H

enum Flag{START, GAME, CLEAR};

#include <asm/types.h>

#define screen_wrap_width 32
#define screen_width 20
#define screen_height 18

#define ground_height 2

extern UINT16 a;
extern UINT8 i;
extern UINT8 j;
extern INT8 p;
extern INT8 q;
extern UINT8 x;
extern UINT8 y;
extern UINT16 t;
extern UINT16 frame1;
extern UINT16 frame2;

#endif
