#ifndef BACKDROP_H
#define BACKDROP_H

#include <asm/types.h>
#include "dimension.h"

typedef struct Backdrop_s {
	Dimension *dimension;
	unsigned char *tiles;
} Backdrop;

#endif
