#ifndef SPRITES_H
#define SPRITES_H

#include <stdio.h>
#include <asm/types.h>
#include "../helpers/mtime.h"
#include "../models/gameState.h"

void drawSprites(Object **sprites, UINT8 size);
BOOLEAN inFrameX(INT16 x);

#endif
