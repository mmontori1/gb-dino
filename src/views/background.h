#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <asm/types.h>

#include "../models/gameState.h"
#include "../models/data.h"

void clearBkg();
void drawBkg(Backdrop **bkg, UINT8 numBkg);

#endif
