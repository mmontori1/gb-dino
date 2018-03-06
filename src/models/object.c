#include "object.h"

Animator player_animator;
Object player;
Object enemyOne;
Object enemyTwo;

void setObject(Object *temp, UINT8 x, UINT8 y, UINT8 startTile, UINT8 numTiles, UINT8 width, UINT8 height, Animator* animator) {
	temp->x = x;
	temp->y = y;
	temp->startTile = startTile;
	temp->numTiles = numTiles;
	temp->width = width;
	temp->height = height;
	temp->animator = animator;
}
