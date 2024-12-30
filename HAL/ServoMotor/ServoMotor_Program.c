/*
 * ServoMotor_Program.c
 *
 *  Created on: Nov 27, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer/Timer_Interface.h"
#include "ServoMotor_Interface.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
void SERVO_ANGLE(s8 angle){
	 SET_BIT(TCCR1A,COM1A1);
	   CLEAR_BIT(TCCR1A,COM1A0);

	   // SELECT TIMEFR1 MODE 14
	   CLEAR_BIT(TCCR1A,WGM10);
	   SET_BIT(TCCR1A , WGM11);
	   SET_BIT(TCCR1B,WGM12);
	   SET_BIT(TCCR1B,WGM13);
	   // SELECT PRESCALLER 256
	   CLEAR_BIT(TCCR1B,CS10);
	   CLEAR_BIT(TCCR1B,CS11);
	   SET_BIT(TCCR1B,CS12);

	   ICR1 = 1250;
	   OCR1A =angle ;
}

