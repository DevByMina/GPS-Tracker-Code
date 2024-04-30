//Ahmed_Mohamed

#include "tm4c123gh6pm.h"
#include "SWs_Init.h"

void SWs_Init(void){
	GPIO_PORTF_LOCK_R |=GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |=PF04_mask; 					//allow changes to pf0 pf4 
	GPIO_PORTF_DIR_R &=~(PF04_mask) ;
	GPIO_PORTF_AFSEL_R &=~(PF04_mask);
	GPIO_PORTF_PUR_R |=PF04_mask ;
	GPIO_PORTF_DEN_R |=PF04_mask;
	GPIO_PORTF_AMSEL_R &=~(PF04_mask);
	GPIO_PORTF_PCTL_R &=~(0x000F000F);
	GPIO_PORTF_DATA_R &=~(PF04_mask);			//to ensure switches clear at first
}
