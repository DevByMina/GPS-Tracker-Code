//Mina Sameh

#include "../headers/UART.h"

void init_UART0(void){
    SYSCTL_RCGCUART_R |= 0x0001;
    SYSCTL_RCGCGPIO_R |= 0x0001;
    UART0_CTL_R &= ~(0x0001);
    UART0_IBRD_R = 0x68;
    UART0_FBRD_R = 0xB;
    UART0_LCRH_R = 0x0070;
    UART0_CTL_R = 0x0301;
    GPIO_PORTA_AFSEL_R |= 0x03;
    GPIO_PORTA_PCTL_R |= 0x00000011;
    GPIO_PORTA_DEN_R |=0X03;
    GPIO_PORTA_AMSEL_R &= ~(0X03);
}
void UART2_init(void){
    SYSCTL_RCGCUART_R |= 0x04;
    SYSCTL_RCGCGPIO_R |= 0x08;
    while((SYSCTL_PRGPIO_R & 0x08)==0){}
    GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTD_CR_R |= 0xC0;
    UART2_CTL_R &= ~0x0001;
    UART2_IBRD_R = 0x68;
    UART2_FBRD_R = 0xB;
    UART2_LCRH_R = 0x0070;
    UART2_CTL_R = 0x0301;
    GPIO_PORTD_AFSEL_R |= 0xc0;
    GPIO_PORTD_PCTL_R = (GPIO_PORTA_PCTL_R&0x00FFFFFF)+0x11000000;
    GPIO_PORTD_DEN_R |= 0xC0;
    GPIO_PORTD_AMSEL_R &= ~0xC0;
}

char UART_inChar0(void){
    while ((UART0_FR_R & 0x10) != 0)
    {
    }
    return (char)UART0_DR_R;
}


void UART_outChar0(char c){
    while ((UART0_FR_R & 0x20) != 0)
    {
    }
    UART0_DR_R = c;
}


char UART_inChar2(void){
    while ((UART2_FR_R & 0x10) != 0)
    {
    }
    return (char)UART2_DR_R;
}


void UART_outChar2(char c){
    while ((UART2_FR_R & 0x20) != 0)
    {
    }
    UART2_DR_R = c;
}


void printLine0(char * line){
    while(*line)
    {
        UART_outChar0(*line);
        line++;
    }
}

void UART_Interrupt(void){
	UART0_IM_R |= 0x10;
	NVIC_EN0_R |= 0x20;
	NVIC_PRI1_R = NVIC_PRI1_R & 0xFFFF00FF;
	__enable_irq();
}

