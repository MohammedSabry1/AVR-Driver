/*
 * I2C_Program.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "../../Config/I2C_Config.h"
#include "I2C_Interface.h"
void vI2C_Init(){
	//select frequency at 400khz
	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	TWBR =12;
	//enable acknowledge
	SET_BIT(TWCR,TWEA);
	//ENABLE I2C
	SET_BIT(TWCR,TWEN);

}


void vI2C_StartCondition(){


	//START COND
	SET_BIT(TWCR,TWSTA);
	//CLEAR HW FLAG
	SET_BIT(TWCR,TWINT);
	//WAIT FOR FLAG
	while(!(READ_BIT(TWCR,TWINT)));
	//CHECK STATS CODE
	while(TWSR & 0xf8 != 0x08);


}

void vI2C_ReStart(){
	//START COND
	SET_BIT(TWCR,TWSTA);
	//CLEAR HW FLAG

	SET_BIT(TWCR,TWINT);
	//WAIT FOR FLAG
	while(!(READ_BIT(TWCR,TWINT)));
	//CHECK STATS CODE
	while(TWSR & 0xf8 != 0x10);
}

void vI2C_SendAddressWithWrite(u8 ADD){

	if(ADD <128){
		u8 adress =ADD<<1;
		CLEAR_BIT(adress,0);
		TWDR= adress;

		CLEAR_BIT(TWCR,TWSTA);
		//CLEAR HW FLAG
		SET_BIT(TWCR,TWINT);
		//WAIT FOR FLAG
		while(!(READ_BIT(TWCR,TWINT)));
		//CHECK STATS CODE
		while(TWSR & 0xf8 != 0x18);

	}
}

void vI2C_SendAddressWithRead(u8 ADD){
	if(ADD <127){
		u8 adress =ADD <<1;
		SET_BIT(adress,0);
		TWDR= adress;
		CLEAR_BIT(TWCR,TWSTA);

		//CLEAR HW FLAG
		SET_BIT(TWCR,TWINT);
		//WAIT FOR FLAG
		while(!(READ_BIT(TWCR,TWINT)));
		//CHECK STATS CODE
		while(TWSR & 0xf8 != 0x40);

	}

}

void vI2CSendData(u8 Data){
	if(Data <256){
		TWDR = Data;
		//CLEAR HW FLAG
		SET_BIT(TWCR,TWINT);
		while(!(READ_BIT(TWCR,TWINT)));
		//CHECK STATS CODE
		while(TWSR & 0xf8 != 0x28);
	}

}

u8 u8I2C_ReciveData(u8 ack){
	if (ack == WITH_ACK)
	{
		SET_BIT(TWCR,TWEA);
	}
	else if(ack == WITHOUT_ACK)
	{
		CLEAR_BIT(TWCR,TWEA);
	}
	//CLEAR HW FLAG
	SET_BIT(TWCR,TWINT);
	while(!(READ_BIT(TWCR,TWINT)));
	//CHECK STATS CODE
	while(TWSR & 0xf8 != 0x50);
	SET_BIT(TWCR,TWEA);
	return TWDR;
}

void vI2C_StopCondition(){
	SET_BIT(TWCR,TWSTO);
	//CLEAR HW FLAG
	SET_BIT(TWCR,TWINT);
}
