//John Shoukry

#ifndef EEPROM_h
#define EEPROM_h

#include "tm4c123gh6pm.h"
#include "Systick.h"
#include "UART.h"
#include "stdio.h"

void EEPROM_Init(void);
void EEPROM_Write(float data);
float EEPROM_Read(uint32_t read_block, uint32_t read_offset);
void EEPROM_Write_NoINC(uint32_t write_block, uint32_t write_offset,float data);
void EEPROM_to_UART(void);









#endif
