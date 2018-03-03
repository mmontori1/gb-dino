#ifndef MAIN_H
#define MAIN_H

#include <gb/gb.h>
#include <stdio.h>

#include "helpers/global.h"

#include "models/data.h"
#include "models/gameState.h"
#include "models/object.h"

#include "controllers/input.h"
#include "controllers/start.h"

void vblCallback();
void init();

#endif
