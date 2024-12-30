/*
 * DIO_Interface.h
 *
 *  Created on: Aug 16, 2024
 *      Author: Mohamed
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

// ***********************Direction***********************
#define input 0
#define output 1

// ***********************Ports***********************
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

// ***********************Pins***********************
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
// ***********************Value Status***********************
#define LOW 0
#define HIGH 1

// ***********************PORT Status***********************
#define PortStatusOutput 0xff
#define PortStatusInput 0x00

void vSetPinDirection(u8 copyu8_PORT , u8 copyu8_PIN , u8 copyu8_DIRECTION);// FUN TO SET PIN VALUE INPUT OR OUTPUT
void vPinValue(u8 copyu8_PORT , u8 copyu8_PIN , u8 copyu8_OutputValue);// FUN TO SET PIN VALUE HIGH OR LOW
u8 u8ReadPin(u8 copyu8_PORT , u8 copyu8_PIN);
void vTogglePin(u8 copyu8_PORT ,u8 copyu8_PIN);
void vSetPortDirection(u8 copyu8_PORT,u8 ValueDirection);
void vSetPortValue(u8 copyu8_PORT,u8 Value);
void vTogglePort(u8 copyu8_PORT);
#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
