#ifndef GLOBAL_H
#define GLOBAL_H

#include <gb/gb.h>
#include <stdio.h>
#include <asm/types.h>

extern UBYTE VBL_FLAG;
#define VBL_FLAG_ON VBL_FLAG |= (1 << 0);
#define VBL_FLAG_OFF VBL_FLAG &= ~(1 << 0);

#endif
