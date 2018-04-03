#ifndef INPUT_H
#define INPUT_H

#include "../models/gameState.h"

void checkInput(State *);
void clearInputs();

extern void (*start_button) (State *);
extern void (*select_button) (State *);
extern void (*up_button) (State *);
extern void (*left_button) (State *);
extern void (*right_button) (State *);
extern void (*down_button) (State *);
extern void (*a_button) (State *);
extern void (*b_button) (State *);

#endif
