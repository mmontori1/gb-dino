#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "state.h"

#include "../models/data.h"
#include "../models/gameState.h"
#include "../models/object.h"
#include "../models/animator.h"

extern Object player;
extern Object enemyOne;
extern Object enemyTwo;

extern Animator player_animator;

void setupGame();
void setGameData();

#endif
