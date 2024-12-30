/*
 * EEPROM_Program.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../Config/EEPROM_Config.h"
#include "../../MCAL/I2C/I2C_Interface.h"
#include "EEPROM_Interface.h"
#include <util/delay.h>

void EEPROM_Init(){
	vI2C_Init();

}
void EEPROM_WriteData(u16 address,u8 data){
	//start condition
	vI2C_StartCondition();
	//send address w write
	vI2C_SendAddressWithWrite(0b1010000 | address >> 8);
	//send word address
	vI2CSendData((u8)address);
	//send data
	vI2CSendData(data);
	//stop condition
	vI2C_StopCondition();
	_delay_ms(5);

}
void EEPROM_ReadData(u16 address , u8*data){
	//start condition
	vI2C_StartCondition();
	//send address w write
	vI2C_SendAddressWithWrite(0b1010000 | address >> 8);
	//send word address
	vI2CSendData((u8)address);
	//repeated start
	vI2C_ReStart();
	//send address w read
	vI2C_SendAddressWithRead(0b1010000 | address >> 8);
	//receive data
	* data = u8I2C_ReciveData(WITHOUT_ACK);
	//stop condition
	vI2C_StopCondition();
	_delay_ms(5);

}
