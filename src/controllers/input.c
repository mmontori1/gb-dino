#include "input.h"

void checkInput(State *state){
	if(start_button && START_PRESS) (*start_button)(state);
	if(select_button && SELECT_PRESS) (*select_button)(state);
	if(up_button && UP_PRESS) (*up_button)();
	if(left_button && LEFT_PRESS) (*left_button)();
	if(right_button && RIGHT_PRESS) (*right_button)();
	if(down_button && DOWN_PRESS) (*down_button)();
	if(a_button && A_PRESS) (*a_button)();
	if(b_button && B_PRESS) (*b_button)();
}

void clearInputs(){
	start_button = NULL;
	select_button = NULL;
	up_button = NULL;
	left_button = NULL;
	right_button = NULL;
	down_button = NULL;
	a_button = NULL;
	b_button = NULL;
}

void (*start_button) (State *);
void (*select_button) (State *);
void (*up_button) ();
void (*left_button) ();
void (*right_button) ();
void (*down_button) ();
void (*a_button) ();
void (*b_button) ();
