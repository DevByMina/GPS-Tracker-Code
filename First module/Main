//Ramez_Emad

#include "tm4c123gh6pm.h"
#include "LEDS_Init.h"
#include "LED_ON.h"
#include "UART_METHODS.h"
#include "SWs_Init.h"
#include "UART_Init.h"
#include "SwitchMethods.h"

int main(){
	LEDs_Init();
	SWs_Init();
	UART_Init();
	while(1){
		set_led();
		clear_led();
	}
}
