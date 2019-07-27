#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "state.h"

#include "../helpers/mtime.h"
#include "../helpers/clear.h"

#include "../models/data.h"
#include "../models/gameState.h"
#include "../models/object.h"
#include "../models/backdrop.h"
#include "../models/frames.h"

void initGame();
void setupGame();
void setGameData();
void gameLoop();
void jumpCheck();
void jumpEnd();
void beginJump();
void playerDown();
void switchTank();
void turnSwitchBack();
void enemyMovement();
void checkDimensions();
void checkX(INT16 *val);
void checkPlayerY(UINT8 *val);
BOOLEAN checkCollisions(Dimension *first, Dimension *second);
void increaseScore();
void pickEnemy(Object *enemy);
void setHacker();
void setTank();
void setCactus(Object *enemy);
void setFly(Object *enemy);
void gameOver();

#endif
