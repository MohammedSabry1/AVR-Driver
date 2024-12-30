/*
 * ADC_Interface.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Mohamed
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_
/*********************** Prescaler Modes ***********************/

#define ADC_Prescaler_2		0
#define ADC_Prescaler_4		2
#define ADC_Prescaler_8		3
#define ADC_Prescaler_16	4
#define	ADC_Prescaler_32	5
#define ADC_Prescaler_64	6
#define ADC_Prescaler_128	7

/***********************Voltage Reference Modes ***********************/
#define ADC_AREF 		0 //AREF, Internal Vref turned off
#define ADC_AVCC	 	1 //AVCC with external capacitor at AREF pin
#define ADC_Reserved	2 //Reserved
#define ADC_Internal 	3 //Internal 2.56V Voltage Reference with external capacitor at AREF pin

/***********************Channels Modes ***********************/

#define Channel_A0 0
#define Channel_A1 1
#define Channel_A2 2
#define Channel_A3 3
#define Channel_A4 4
#define Channel_A5 5
#define Channel_A6 6
#define Channel_A7 7


void vEnableADC(void);
void vDisableADC(void);
void vADCInit(void);
u16 u16ADCRead(u8 Channel);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
