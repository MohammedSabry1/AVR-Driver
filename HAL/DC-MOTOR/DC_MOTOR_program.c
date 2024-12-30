/*
 * DC_MOTOR_program.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include "DC_MOTOR_Interface.h"
#include "../../Config/DC_MOTOR_config.h"

void DCMotorON(){
	vSetPinDirection(RelayPort,RelayPin,output);
	vPinValue(RelayPort,RelayPin,HIGH);
}

void DCMotorOFF(){
	vSetPinDirection(RelayPort,RelayPin,output);
	vPinValue(RelayPort,RelayPin,LOW);
}
