#ifndef Systick_h
#define Systick_h

#include "stdint.h"
#include "tm4c123gh6pm.h"


void systic_init(void);
void systic_wait(uint32_t delay);
void delay(uint32_t time_delay);




#endif


