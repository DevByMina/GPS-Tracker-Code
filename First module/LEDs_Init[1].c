//John_Emile

#include "tm4c123gh6pm.h"
#include "LEDS_Init.h"

void LEDs_Init(void)
{
	SYSCTL_RCGCGPIO_R |= PF_mask;
	while ((SYSCTL_PRGPIO_R & PF_mask) == 0);
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |= PF123_mask;
	GPIO_PORTF_AMSEL_R &= ~(PF123_mask);
	GPIO_PORTF_AFSEL_R &= ~(PF123_mask);
	GPIO_PORTF_DEN_R |= PF123_mask;
	GPIO_PORTF_PCTL_R &= ~(0x0000FFF0);
	GPIO_PORTF_DIR_R |= PF123_mask;
	GPIO_PORTF_DATA_R &= ~(PF123_mask);
}
