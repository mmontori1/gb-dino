#ifndef SELECTOR_H
#define SELECTOR_H

#include "../models/data.h"
#include "../models/dimension.h"
#include "../models/object.h"
#include "../models/frames.h"

void setupSelector(Object *selector, UINT8 x, UINT8 y);
void moveSelector(UINT8 x, UINT8 y);
void setSelectorData();

#endif
