//Khaled Mohamed

#include "../headers/Interrupts.h"

void GPIOF_Handler(void){
	if(GPIO_PORTF_MIS_R & 0x10){
		setLed(0x04);
		GPIO_PORTB_DATA_R |= 0x02;
		delay(200);
		LCD4bits_Cmd(0x80);
		LCD_WriteString("    Arrived     ");
		EEPROM_Write_NoINC(0,0,block);
		EEPROM_Write_NoINC(0,1,offset);
		
		GPIO_PORTB_DATA_R |= 0x02;
		delay(10);
		GPIO_PORTB_DATA_R &= ~0x02;
		while(1);
	}
}

void hundred_meter_Handler(void){
		setLed(0x08);
		GPIO_PORTB_DATA_R |= 0x02;
		LCD4bits_Cmd(0x80);
		LCD_WriteString(" reached 100 m  ");
		GPIO_PORTB_DATA_R |= 0x02;
		delay(300);
		GPIO_PORTB_DATA_R &= ~0x02;
}

void UART0_Handler(void){
	char temp;
	if (UART0_MIS_R & 0x10){
		temp=UART_inChar0();
		if(temp=='U'){
				block=EEPROM_Read(0,0);
				offset=EEPROM_Read(0,1);
				EEPROM_to_UART();
		}
		UART0_ICR_R |= 0x10;
	}
	
}
