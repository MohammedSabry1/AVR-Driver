/*
 * ADC_Program.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "../../Config/ADC_Config.h"
#include "ADC_Interface.h"

void vEnableADC(void){
	SET_BIT(ADCSRA,ADIF);
}

void vDisableADC(void){
	CLEAR_BIT(ADCSRA,ADEN);
}

void vADCInit(void){

	/*SET THE VOLTAGEREF TO MODE*/
	ADMUX &= 0b00111111; //Clear The Voltage Bits
	ADMUX |= ADC_VOLTAGE_MODE<<6;

	/*SET THE PRESCALLER ACORDING TO MODE*/
	ADCSRA &= 0b11111000; //CLear The Prescaller Bits
	ADCSRA |= ADC_PRESCALER_MODE;

	/*ENABLE THE ADC*/
	SET_BIT(ADCSRA,ADEN);
}

u16 u16ADCRead(u8 Channel){

	//SELECT CHANNEL
	ADMUX &= 0b11100000; //Clear MUX BITS
	ADMUX |= Channel;

	//START CONVERSION
	SET_BIT(ADCSRA,ADSC);

	//STUCK THE HARDWARE FLAG
	while(READ_BIT(ADCSRA,ADIF)==0);

	//CLEAR THE HARDWARE FLAG
	SET_BIT(ADCSRA,ADIF);
	return ADCL_REG;
}




