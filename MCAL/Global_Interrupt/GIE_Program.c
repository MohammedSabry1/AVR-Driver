/*
 * GIE_Program.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "GIE_Interface.h"

void ENABLE_GIE(){
	SET_BIT(SREG,I);

}
void DISABLE_GIE(){
	CLEAR_BIT(SREG,I);

}
