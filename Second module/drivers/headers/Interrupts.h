//Khaled Mohamed

#ifndef Interrupts_h
#define Interrupts_h

#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "EEPROM.h"
#include "RGB.h"

void GPIOF_Handler(void);
void hundred_meter_Handler(void);
void UART0_Handler(void);

#endif
