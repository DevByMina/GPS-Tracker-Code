//John Shoukry

#include "EEPROM.h"

uint32_t block = 0;
uint32_t offset =2;


void EEPROM_Init(void) {
	volatile int i;
    // Enable the EEPROM0 peripheral
    SYSCTL_RCGCEEPROM_R = SYSCTL_RCGCEEPROM_R0;
// Insert a small delay to ensure the EEPROM peripheral is enabled
    for ( i = 0; i < 1000; i++);

}
void EEPROM_Write(float data) {
		union {
        float f;
        uint32_t u;
    } data_to_store;

    // Wait for the EEPROM to be ready
    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING);

    // Set the block and offset for the write operation
    EEPROM_EEBLOCK_R = block;
    EEPROM_EEOFFSET_R = offset;

    // Convert float to uint32_t for storage
    data_to_store.f = data;

    // Write the data to the EEPROM
    EEPROM_EERDWR_R = data_to_store.u;

    // Wait for the EEPROM to finish the write operation
    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING);
	
		offset++;
		if (offset == 16){
			offset=0;
			block++;
		}
		if (block == 32){
			offset=15;
			block=32;
		}
}

void EEPROM_Write_NoINC(uint32_t write_block, uint32_t write_offset,float data) {

    union {
        float f;
        uint32_t u;
    } data_to_store;

    // Wait for the EEPROM to be ready
    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING);

    // Set the block and offset for the write operation
    EEPROM_EEBLOCK_R = write_block;
    EEPROM_EEOFFSET_R = write_offset;

    // Convert float to uint32_t for storage
    data_to_store.f = data;

    // Write the data to the EEPROM
    EEPROM_EERDWR_R = data_to_store.u;

    // Wait for the EEPROM to finish the write operation
    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING);
    
}



float EEPROM_Read(uint32_t read_block, uint32_t read_offset) {
		union {
        uint32_t u;
        float f;
    } data_to_return;
		uint32_t data_read;
    // Wait for the EEPROM to be ready
    while (EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING);

    // Set the block and offset for the read operation
    EEPROM_EEBLOCK_R = read_block;
    EEPROM_EEOFFSET_R = read_offset;

    // Read the data from the EEPROM
    data_read = EEPROM_EERDWR_R;

    // Convert uint32_t back to float
    
    data_to_return.u = data_read;

    return data_to_return.f;
}

void EEPROM_to_UART(void){
	uint16_t i=0,j;
	char temp[10];

		for (j=2;j<16;j+=2){
			sprintf(temp,"%f",EEPROM_Read(i,j));
			printLine0(temp);
			UART_outChar0(',');
			sprintf(temp,"%f",EEPROM_Read(i,j+1));
			printLine0(temp);
			printLine0("\n");
	}
	for (i=1;i<block;i++){
		for (j=0;j<16;j+=2){
			sprintf(temp,"%f",EEPROM_Read(i,j));
			printLine0(temp);
			UART_outChar0(',');
			sprintf(temp,"%f",EEPROM_Read(i,j+1));
			printLine0(temp);
			printLine0("\n");
		}
	}
	for (j=0;j<offset;j+=2){
		sprintf(temp,"%f",EEPROM_Read(i,j));
			printLine0(temp);
			UART_outChar0(',');
			sprintf(temp,"%f",EEPROM_Read(i,j+1));
			printLine0(temp);
			printLine0("\n");
	}
	printLine0("end\n");
			
	
}
