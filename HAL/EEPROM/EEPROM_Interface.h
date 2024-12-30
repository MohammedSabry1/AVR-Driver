/*
 * EEPROM_Interface.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mohamed
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_Init();
void EEPROM_WriteData(u16 address,u8 data);
void EEPROM_ReadData(u16 address , u8*data);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
