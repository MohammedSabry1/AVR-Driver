/*
 * UART_Program.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "../../Config/UART_Config.h"
#include "UART_Interface.h"




void UART_INIT(){
	//baud rate
	UBRRL = Baud_Rate;
	//number of data bits
	UCSRC &= 0b11111001;
	UCSRC |= NUM_OF_DATA_BITS;
	//select sync
	if(UART_MODE == SYNC){
		SET_BIT(UCSRC,UMREL);
	}else if(UART_MODE == ASYNC){
		CLEAR_BIT(UCSRC,UMREL);
	}
	//num of stop bits
	if(NUM_OF_STOP_BITS == ONE_STOP){
		CLEAR_BIT(UCSRC,USBS);
	}else if(NUM_OF_STOP_BITS == TWO_STOP){
		SET_BIT(UCSRC,USBS);
	}

	//select parity
	UCSRC &= 0b11001111;
	UCSRC |= PARITY_MODE;
	//enable interrupt
	SET_BIT(UCSRB,RXCIE);
	// enable UART
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);



}
void UART_SEND_DATA(u8 data){
	while(!READ_BIT(UCSRA,UDRE));
	UDR = data;

}
u8 UART_RECIVE_DATA(){
	while(!READ_BIT(UCSRA,RXC));

	return UDR;
}
