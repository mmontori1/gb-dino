#ifndef INPUT_H
#define INPUT_H

#include "../models/gameState.h"

#define START_PRESS joypad() & J_START
#define SELECT_PRESS joypad() & J_SELECT
#define UP_PRESS joypad() & J_UP
#define LEFT_PRESS joypad() & J_LEFT
#define RIGHT_PRESS joypad() & J_RIGHT
#define DOWN_PRESS joypad() & J_DOWN
#define A_PRESS joypad() & J_A
#define B_PRESS joypad() & J_B

void checkInput(State *);
void clearInputs();

extern void (*start_button) (State *);
extern void (*select_button) (State *);
extern void (*up_button) ();
extern void (*left_button) ();
extern void (*right_button) ();
extern void (*down_button) ();
extern void (*a_button) ();
extern void (*b_button) ();

#endif
