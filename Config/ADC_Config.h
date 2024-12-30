/*
 * ADC_Config.h5985
 *
 *  Created on: Sep 7, 2024
 *      Author: Mohamed
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/***********************USER CONFIG ***********************/




//SELECT MODE(ADC_Prescaler_2 - ADC_Prescaler_4
//			- ADC_Prescaler_8 - ADC_Prescaler_16
//		   	  ADC_Prescaler_32 -ADC_Prescaler_64
//			  ADC_Prescaler_128)
#define ADC_PRESCALER_MODE	 ADC_Prescaler_128

//SELECT MODE (ADC_AREF - ADC_AVCC - ADC_Reserved - ADC_Internal)
#define ADC_VOLTAGE_MODE   	 ADC_AVCC

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
