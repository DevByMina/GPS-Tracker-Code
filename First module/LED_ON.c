//John_Shoukry

#include "tm4c123gh6pm.h"
#include "SwitchMethods.h"
#include "LED_ON.h"

void set_led(void){
	if(Switch2data() == 0){
		GPIO_PORTF_DATA_R |= BLUE;    			 //turn on blue led 		
	}
}

void clear_led(void){
	if((Switch1data() == 0) && (Switch2data() == 1)){
		GPIO_PORTF_DATA_R &=~ PF123_mask;    //turn off all leds 		
	}
}
