#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <asm/types.h>

typedef enum Animate {
	CONSTANT,
	DYNAMIC
} Animate;

typedef struct Frames {
	UINT8 numFrames;
	UINT8 *frames;
} Frames;

typedef struct Animator_s {
	Frames **frames;
} Animator;

void initFrames(Frames* frames, UINT8 numFrames, UINT8 *frame_data);

#endif
