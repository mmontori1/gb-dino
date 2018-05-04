#include "mtime.h"
#include <rand.h>
#include <time.h>

UINT16 t;

BOOLEAN intervalCheck(UINT16 *currentTime, UINT8 rate){
	t = clock();
	if(rate > 0) t = t / rate;
	if(t != *currentTime){
		*currentTime = t;
		return 1;
	}
	return 0;
}

UINT8 getRand(){
	return rand();
}
