#ifndef SELECTOR_H
#define SELECTOR_H

#include "../models/data.h"
#include "../models/dimension.h"
#include "../models/object.h"
#include "../models/frames.h"

#define option_size 2
typedef enum Option {
	OPTION_1,
	OPTION_2
} Option;

extern UINT8 selectorPosition;

void setupSelector(Object *selector, UINT8 x, UINT8 y);
void moveSelector(UINT8 x, UINT8 y);
void setSelectorData();
void updateSelector(void (*action)(), UINT8 x, UINT8 y);

#endif
