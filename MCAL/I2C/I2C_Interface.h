/*
 * I2C_Interface.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Mohamed
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

#define WITH_ACK 0
#define WITHOUT_ACK 1

void vI2C_Init();

void vI2C_StartCondition();

void vI2C_ReStart();

void vI2C_SendAddressWithWrite(u8 ADD);

void vI2C_SendAddressWithRead(u8 ADD);

void vI2CSendData(u8 Data);

u8 u8I2C_ReciveData(u8 ack);

void vI2C_StopCondition();

#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
