#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "state.h"

#include "../helpers/mtime.h"
#include "../models/data.h"
#include "../models/gameState.h"
#include "../models/object.h"
#include "../models/backdrop.h"
#include "../models/frames.h"

void initGame();
void setupGame(State *state);
void setGameData();
void gameLoop();


void jumpCheck();
void jumpEnd();
void playerDown();
void beginJump();

void enemyMovement();
void checkX(INT16 *val);
void pickEnemy(Object *enemy);
void setCactus(Object *enemy);
void setFly(Object *enemy);

#endif
