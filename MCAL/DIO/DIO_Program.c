/*
 * DIO_Program.c
 *
 *  Created on: Aug 16, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include"DIO_Interface.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include <util/delay.h>
void vSetPinDirection(u8 copyu8_PORT , u8 copyu8_PIN , u8 copyu8_DIRECTION)
{
	switch(copyu8_DIRECTION){
	case output :
		switch(copyu8_PORT){
		case PORT_A:SET_BIT(DDRA,copyu8_PIN); break;
		case PORT_B:SET_BIT(DDRB,copyu8_PIN); break;
		case PORT_C:SET_BIT(DDRC,copyu8_PIN); break;
		case PORT_D:SET_BIT(DDRD,copyu8_PIN); break;

		}
		break;
		case input :
			switch(copyu8_PORT){
			case PORT_A:CLEAR_BIT(DDRA,copyu8_PIN); break;
			case PORT_B:CLEAR_BIT(DDRB,copyu8_PIN); break;
			case PORT_C:CLEAR_BIT(DDRC,copyu8_PIN); break;
			case PORT_D:CLEAR_BIT(DDRD,copyu8_PIN); break;
			}
			break;
	}
}

void vPinValue(u8 copyu8_PORT , u8 copyu8_PIN , u8 copyu8_OutputValue){
	switch(copyu8_OutputValue){
	case HIGH :
		switch(copyu8_PORT){
		case PORT_A:SET_BIT(PORTA,copyu8_PIN); break;
		case PORT_B:SET_BIT(PORTB,copyu8_PIN); break;
		case PORT_C:SET_BIT(PORTC,copyu8_PIN); break;
		case PORT_D:SET_BIT(PORTD,copyu8_PIN); break;

		}
		break;
		case LOW :
			switch(copyu8_PORT){
			case PORT_A:CLEAR_BIT(PORTA,copyu8_PIN); break;
			case PORT_B:CLEAR_BIT(PORTB,copyu8_PIN); break;
			case PORT_C:CLEAR_BIT(PORTC,copyu8_PIN); break;
			case PORT_D:CLEAR_BIT(PORTD,copyu8_PIN); break;
			}
			break;
	}
}
u8 u8ReadPin(u8 copyu8_PORT , u8 copyu8_PIN){
	u8 Local_Get = 0;

	switch (copyu8_PORT){
	case PORT_A: Local_Get = READ_BIT(PINA,copyu8_PIN);break;
	case PORT_B: Local_Get = READ_BIT(PINB,copyu8_PIN);break;
	case PORT_C: Local_Get = READ_BIT(PINC,copyu8_PIN);break;
	case PORT_D: Local_Get = READ_BIT(PIND,copyu8_PIN);break;
	}
	return Local_Get;
}
void vTogglePin(u8 copyu8_PORT ,u8 copyu8_PIN){
	switch(copyu8_PORT){
	case PORT_A:
		SET_BIT(DDRA,copyu8_PIN);
		for(u8 i = 0; i < 9; i++) {
			TOG_BIT(PORTA,copyu8_PIN);
			_delay_ms(300);
		}
		break;
	case PORT_B:
		SET_BIT(DDRB,copyu8_PIN);
		for(u8 i = 0; i < 9; i++) {
			TOG_BIT(PORTB,copyu8_PIN);
			_delay_ms(300);
		}
		break;
	case PORT_C:
		SET_BIT(DDRC,copyu8_PIN);
		for(u8 i = 0; i < 9; i++) {
			TOG_BIT(PORTC,copyu8_PIN);
			_delay_ms(300);
		}
		break;
	case PORT_D:
		SET_BIT(DDRD,copyu8_PIN);
		for(u8 i = 0; i < 9; i++) {
			TOG_BIT(PORTD,copyu8_PIN);
			_delay_ms(300);
		}
		break;
	}
}
void vSetPortDirection(u8 copyu8_PORT,u8 ValueDirection){
	switch (copyu8_PORT) {
	case PORT_A: DDRA = ValueDirection; break;
	case PORT_B: DDRB = ValueDirection; break;
	case PORT_C: DDRC = ValueDirection; break;
	case PORT_D: DDRD = ValueDirection; break;
	}
}
void vSetPortValue(u8 copyu8_PORT, u8 Value) {
	switch (copyu8_PORT) {
	case PORT_A: PORTA = Value; break;
	case PORT_B: PORTB = Value; break;
	case PORT_C: PORTC = Value; break;
	case PORT_D: PORTD = Value; break;
	}
}

void vTogglePort(u8 copyu8_PORT){
	switch(copyu8_PORT){
	case PORT_A:
		DDRA = PortStatusOutput;
		PORTA ^= PortStatusOutput;break;
	case PORT_B:
		DDRB = PortStatusOutput;
		PORTB ^= PortStatusOutput;break;
	case PORT_C:
		DDRC = PortStatusOutput;
		PORTC ^= PortStatusOutput;break;
	case PORT_D:
		DDRD = PortStatusOutput;
		PORTD ^= PortStatusOutput;break;
	}
}

