//Mina Sameh

#ifndef UART_h
#define UART_h

#include "tm4c123gh6pm.h"
#include "EEPROM.h"
extern uint32_t block;
extern uint32_t offset;
void init_UART0(void);
void UART2_init(void);
char UART_inChar0(void);
void UART_outChar0(char c);
char UART_inChar2(void);
void UART_outChar2(char c);
void printLine0(char * line);
void UART_Interrupt(void);


#endif
