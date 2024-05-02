//John_Shoukry



#include "tm4c123gh6pm.h"
#include "SwitchMethods.h"
#include "LED_ON.h"

void set_led(char data){
		GPIO_PORTF_DATA_R |= data;    			 //turn on blue led 		
	
}

void clear_led(char data){
		GPIO_PORTF_DATA_R &=~ data;    //turn off all leds 		
}

void check_DestinationSet(void)
{
	if (Switch2data() == 0)
	{
		set_led(BLUE);
	}
}

void check_DestinationClear(void)
{
	if (Switch1data() == 0)
	{
		clear_led(BLUE);
	}
}

