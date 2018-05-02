#include "interval.h"
#include <time.h>

UINT16 t;

BOOLEAN intervalCheck(UINT16 *currentTime, UINT8 rate){
	t = clock() / rate;
	if(t != *currentTime){
		*currentTime = t;
		return 1;
	}
	return 0;
}
