//John Emile

#ifndef Switches_h
#define Switches_h

#include "tm4c123gh6pm.h"
#include  "RGB.h"
#include "EEPROM.h"
#include "UART.h"
#include "Systick.h"
#include "LCD.h"
extern uint32_t block;
extern uint32_t offset;


void Switches_init(void);
char s2_read(void);


#endif
