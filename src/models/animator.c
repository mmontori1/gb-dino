#include "animator.h"

void initFrames(Frames* frames, UINT8 numFrames, UINT8 *frame_data){
	frames->numFrames = numFrames;
	frames->frames = frame_data;
}
