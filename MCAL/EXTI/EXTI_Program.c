/*
 * EXTI_Program.c
 *
 *  Created on: Sep 6, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "EXTI_Interface.h"
#include "../../Config/EXTI_Config.h"


void vEnable_EXTI(EXTI_T INT) {

	switch(INT){
	case EXTI0:	SET_BIT(GICR,INT0); break;
	case EXTI1:	SET_BIT(GICR,INT1); break;
	case EXTI2:	SET_BIT(GICR,INT2); break;

	}

}

void vDisable_EXTI(EXTI_T INT){

	switch(INT){
	case EXTI0:	CLEAR_BIT(GICR,INT0); break;
	case EXTI1:	CLEAR_BIT(GICR,INT1); break;
	case EXTI2:	CLEAR_BIT(GICR,INT2); break;
	}
}

void vMod_EXTI(EXTI_T INT, u8 MODE){
	switch(INT){
	case EXTI0:
		switch(MODE){
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC01);
			CLEAR_BIT(MCUCR,ISC00);
			break;
		case LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		}
		break;
		case EXTI1:
			switch(MODE){
			case LOW_LEVEL:
				CLEAR_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;
			case LOGIC_CHANGE:
				SET_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;
			case FALLING_EDGE:
				CLEAR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
			case RISING_EDGE:
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
			}
			break;
			case EXTI2:
				switch(MODE){
				case FALLING_EDGE:
					CLEAR_BIT(MCUCSR,ISC2);
					break;
				case RISING_EDGE:
					SET_BIT(MCUCSR,ISC2);
					break;
				}
				break;
	}
}
