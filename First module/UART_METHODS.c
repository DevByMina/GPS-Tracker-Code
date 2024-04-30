//Youssef_Ehab

#include "tm4c123gh6pm.h"
#include "UART_METHODS.h"

char UART_recieve(void){
	while((UART0_FR_R &0x10)!=0); 			// check that FIFO is not empty
	return (char) UART0_DR_R ;
}

void UART_transmit(unsigned char data){
	while((UART0_FR_R &0x20)!=0); 			 // check that FIFO is not full
	UART0_DR_R |= data;
}
