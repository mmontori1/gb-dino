#include "object.h"

Object player;

void setObject(Object *temp, UINT8 x, UINT8 y, UINT8 startTile, UINT8 numTiles) {
	temp->x = x;
	temp->y = y;
	temp->startTile = startTile;
	temp->numTiles = numTiles;
}
