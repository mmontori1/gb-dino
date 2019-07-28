#ifndef SCORE_H
#define SCORE_H

#include "../helpers/loop.h"
#include "../helpers/mtime.h"
#include "../models/gameState.h"

#define score_size 4
extern unsigned char score_map[score_size];

void increaseScore(Backdrop *score);
void updateScoreTiles();
void resetScoreMap();

#endif
