//Mina Sameh

#include "Systick.h"

void systic_init(void){
	NVIC_ST_CTRL_R &=0;									// disbale timer
	NVIC_ST_RELOAD_R =0x00FFFFFF;				// to wait 0.5 sec
	NVIC_ST_CURRENT_R=0;								// to clear its value
	NVIC_ST_CTRL_R |=5;									// enable timer and clk source 
}

void systic_wait(uint32_t delay){
	NVIC_ST_CTRL_R =0;	
	NVIC_ST_RELOAD_R =delay - 1;			
	NVIC_ST_CURRENT_R=0;		
	NVIC_ST_CTRL_R =5;
	while((NVIC_ST_CTRL_R &0x010000)==0); 	// Busy wait until the o.5 sec finish	
}

//delay 10ms 
void delay(uint32_t time_delay){
	volatile uint32_t i;
	for(i=0;i<time_delay;i++){							// to wait a time multiple of 0.5min
			systic_wait(160000);
	}
}

//dealy 1ms
void delayMs(uint32_t time_delay){
	volatile uint32_t i;
	for(i=0;i<time_delay;i++){							// to wait a time multiple of 0.5min
			systic_wait(16000);
	}
}

//dealy 1us
void delayUs(uint32_t time_delay){
	volatile uint32_t i;
	for(i=0;i<time_delay;i++){							// to wait a time multiple of 0.5min
			systic_wait(16);
	}
}
