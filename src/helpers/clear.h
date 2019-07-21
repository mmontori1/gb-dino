#ifndef CLEAR_H
#define CLEAR_H

#include <asm/types.h>

#include "../models/data.h"

void clearAll(UINT8 numTiles);
void clearBkg();
void clearSprite(Object *sprite, UINT8 start, UINT8 end);
void clearSprites(UINT8 start, UINT8 end);
void clearWin();

#endif
