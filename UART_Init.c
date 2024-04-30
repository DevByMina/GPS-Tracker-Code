//Mina_Sameh

#include "tm4c123gh6pm.h"
#include "UART_Init.h"

void UART_Init(void){
	SYSCTL_RCGCUART_R |= 0x0001; 					//activate Uart 0
	SYSCTL_RCGCGPIO_R |= 0x0001; 					//activate PortA
	while((SYSCTL_PRGPIO_R &0x0001)==0);	//check PortA activation
	UART0_CTL_R &=~ 0x0001;								//disable Uart
	UART0_IBRD_R = 520;
	UART0_FBRD_R = 53;
	UART0_LCRH_R = 0x0070;								//ENABLE 8 bit word and fifo
	UART0_CTL_R = 0x0301;									//enable RXE TXE UART
	GPIO_PORTA_AFSEL_R |= 0x03; 					//Enable alternate function
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+ 0x00000011; //UART for PA0 and PA1
	GPIO_PORTA_DEN_R |= 0x03; 						//digital I/O PA0 PA1
	GPIO_PORTA_AMSEL_R &=~ 0x03; 					//disable analog PA0 PA1
}
