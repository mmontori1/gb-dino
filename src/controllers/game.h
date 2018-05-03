#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "state.h"

#include "../helpers/mtime.h"
#include "../models/data.h"
#include "../models/gameState.h"
#include "../models/object.h"
#include "../models/backdrop.h"
#include "../models/animator.h"

void initGame();
void setupGame(State *state);
void setGameData();
void pickEnemy(Object *enemy);
void setCactus(Object *enemy);
void setFly(Object *enemy);

#endif
