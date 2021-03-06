#ifndef MAIN_H
#define MAIN_H

#include <gb/gb.h>
#include <stdio.h>

#include "helpers/global.h"
#include "helpers/clear.h"

#include "models/data.h"
#include "models/gameState.h"
#include "models/object.h"

#include "controllers/input.h"
#include "controllers/start.h"
#include "controllers/selector.h"
#include "controllers/game.h"
#include "controllers/over.h"

#include "views/background.h"
#include "views/window.h"
#include "views/sprites.h"

void vblCallback();
void init();

#endif
