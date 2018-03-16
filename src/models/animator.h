#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <asm/types.h>

typedef enum Animate {
	CONSTANT,
	DYNAMIC
} Animate;

typedef struct Animator_s {
	Animate *type;	// should be of size of num sprites
	UINT8 numFrames;
	UINT8 **frames;	// should be 2d arr of size [num dynamic sprites][numFrames]
} Animator;

#endif
