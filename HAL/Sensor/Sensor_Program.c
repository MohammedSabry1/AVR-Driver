/*
 * Sensor.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Config/Sensor_Config.h"
#include "../../MCAL/Timer/Timer_Interface.h"
#include "Sensor_Interface.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../../MCAL/ADC/ADC_Interface.h"


u16 u16ADCVoltRead(u8 Channel){
	u16 volt =0;
	volt = (((u32)5000*u16ADCRead(Channel))/1023);
	return volt;

}
u16 u16ADCTempRead(u8 Channel){
	u16 temp = 0;
	temp = u16ADCVoltRead(Channel) /10;
	return temp;
}
u8 u8DigitalFlameRead(){
	u8 Read =0;
	vSetPinDirection(DIGITAL_PORT,DIGITAL_PIN,input);
	Read = u8ReadPin(DIGITAL_PORT,DIGITAL_PIN);

	return Read;
}
void vUltraSonicInit(void){

	vSetPinDirection(TrigPort,TrigPin,output);
	vSetPinDirection(EchoPort,EchoPin,input);
	vPinValue(TrigPort, TrigPin, LOW);

}

u32 u32UltraSonicMeasure(){
	u32 pulse_width=0;
	//vUltraSonicInit();
	vPinValue(TrigPort, TrigPin, LOW);
	_delay_us(2);
	vPinValue(TrigPort, TrigPin, HIGH);
	_delay_us(10);
	vPinValue(TrigPort, TrigPin, LOW);
	//trigter the trig pin

	// wait for echo to become high
	while (!u8ReadPin(EchoPort, EchoPin));
	//reset timer 0
	vPreload_Timer(0);

	//wait echo to become low
	while (u8ReadPin(EchoPort, EchoPin));
	//read the pulse
	pulse_width= (TCNT0 +((u32)255* 1))*0.0625;	//convert it to mm
	u32 distance_mm = ((u32)pulse_width*1000) / 58;  // For no prescaler and system clock


	return distance_mm;

}
