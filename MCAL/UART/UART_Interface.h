/*
 * UART_Interface.h
 *
 *  Created on: Sep 27, 2024
 *      Author: Mohamed
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#define ONE_STOP	0
#define TWO_STOP	1

#define PARITY_DISCONNECTED 0b00000000
#define PARITY_EVEN			0b00100000
#define PARITY_ODD			0b00110000

#define BIT_5 		0b00000000
#define BIT_6 		0b00000010
#define BIT_7 		0b00000100
#define BIT_8 		0b00000110

#define SYNC 	1
#define ASYNC	0

#define Single_Speed	0
#define Double_Speed	1

#define ENABLE_INTERRUPT 	1
#define DISABLE_INTERRUPT 	0

void UART_INIT();
void UART_SEND_DATA(u8 data);
u8 UART_RECIVE_DATA();

#endif /* MCAL_UART_UART_INTERFACE_H_ */
