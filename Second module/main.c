//Youssef Ehab

#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <stdint.h>
#include "drivers/headers/GPS.h"
#include "drivers/headers/UART.h"
#include "drivers/headers/RGB.h"
#include "drivers/headers/Systick.h"
#include "drivers/headers/LCD.h" 
#include "drivers/headers/Switches.h"
#include "drivers/headers/EEPROM.h"
#include "drivers/headers/Interrupts.h"


float prevlat;
float prevlong;
float currentlat;
float currentlong;
float templat;
float templong;
uint8_t hundredMeterFlag=1;	

int main() {
  double inst_distance=0;
	double total_distance=0;
  char LCD_String[20];
	RGB_init();
  init_UART0();
  UART2_init();
	Switches_init();
	LCD4bits_Init();
	UART_Interrupt();
	setLed(0x02);
	LCD4bits_Init();
	EEPROM_Init();
	
	LCD_WriteString("Please wait...");
	LCD4bits_Cmd(0xC0);					//to begin at 2nd line
	LCD_WriteString("initializing GPS");
	
	lineparsing();
	LCD4bits_Cmd(0x01);					//Clear LCD display
	LCD4bits_Cmd(0x80);					//to begin at 1st line
	LCD_WriteString(" click to start ");

	while(s2_read()==0x01);					//Press Switch 2 to start
	lineparsing();						//get first point from GPS
	sprintf(LCD_String,"total distance :");
	LCD4bits_Cmd(0x80);  
	LCD_WriteString(LCD_String);
	sprintf(LCD_String,"   %f",total_distance);
	LCD4bits_Cmd(0xC0);
	LCD_WriteString(LCD_String);
	EEPROM_Write(currentlat);
	delay(2);
	EEPROM_Write(currentlong);
	delay(2);

	while(1){
		delay(100);
		prevlat=currentlat;
		prevlong=currentlong;
		lineparsing();
		inst_distance=distance(prevlat,prevlong,currentlat,currentlong);
		EEPROM_Write(currentlat);
		delay(2);
		EEPROM_Write(currentlong);
		delay(2);
		total_distance+=inst_distance;
		sprintf(LCD_String,"total distance :");
		LCD4bits_Cmd(0x01);
		LCD_WriteString(LCD_String);
		sprintf(LCD_String,"   %f",total_distance);
		LCD4bits_Cmd(0xC0);
		LCD_WriteString(LCD_String);
		
		if (total_distance>100 && hundredMeterFlag==1){
			hundred_meter_Handler();
			hundredMeterFlag=0;
		}
	}
}
