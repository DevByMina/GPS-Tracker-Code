//Khaled Mohamed
#include "tm4c123gh6pm.h"
#include "SwitchMethods.h"

char Switch2data(void){
	return (GPIO_PORTF_DATA_R &0x01);
}
char Switch1data(void){
	return (GPIO_PORTF_DATA_R &0x10);
}
