/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 6, 2024
 *      Author: Mohamed
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum{
	EXTI0 =0,
	EXTI1,
	EXTI2
}EXTI_T;

#define LOW_LEVEL		0
#define LOGIC_CHANGE	1
#define FALLING_EDGE	2
#define RISING_EDGE		3

void vEnable_EXTI(EXTI_T INT);
void vDisable_EXTI(EXTI_T INT);
void vMod_EXTI(EXTI_T INT, u8 MODE);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
