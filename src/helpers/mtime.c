#include "mtime.h"
#include <rand.h>
#include <time.h>
#include <stdio.h>

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

BOOLEAN deltaWait(UINT16 *wait, UINT16 *time, UINT8 diff){
	if(*wait < 255) ++*wait;
	else {
		*wait = (*wait - *time);
		*time = 0;
	}
	if(*time + diff == *wait){
		*time = *wait;
		return 1;
	}
	return 0;
}

UINT8 getRand(){
	return rand();
}

clock_t getClock(){
	return clock();
}
