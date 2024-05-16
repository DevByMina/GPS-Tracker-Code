//Ramez Emad

#include "Switches.h"

void Switches_init(void){
	SYSCTL_RCGCGPIO_R|=0x20;
	while ((SYSCTL_PRGPIO_R & 0x20)==0);
	GPIO_PORTF_LOCK_R=GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R|=0x11;
	GPIO_PORTF_DEN_R|=0x11;
	GPIO_PORTF_AMSEL_R &= ~(0x11);
	GPIO_PORTF_AFSEL_R &= ~(0x11);
	GPIO_PORTF_PCTL_R &= 0xFFF0FFF0;
	GPIO_PORTF_DIR_R &= ~(0x11);
	GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTF_IS_R &= ~(0x10);
	GPIO_PORTF_IBE_R &= ~(0x10);
	GPIO_PORTF_IEV_R &= ~0x10;
	GPIO_PORTF_IM_R |= 0x10;
	NVIC_EN0_R |= 0x40000000;
	NVIC_PRI7_R |= (NVIC_PRI7_R & 0xFF00FFFF) | (2<<21);
	__enable_irq();
}



char s2_read(void){
	return GPIO_PORTF_DATA_R & 0x01;
}

