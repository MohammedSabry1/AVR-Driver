/*
 * KEYBAD_program.c
 *
 *  Created on: Aug 30, 2024
 *      Author: Mohamed
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include <avr/delay.h>
#include "../../Config/KEYBAD_config.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "KEYBAD_Interface.h"
u8 ArrColPort[4] = { COL1_PORT, COL2_PORT, COL3_PORT, COL4_PORT };
u8 ArrColPins[4] = { COL1_PIN, COL2_PIN, COL3_PIN, COL4_PIN };

u8 ArrRowPort[4] = { ROW1_PORT, ROW2_PORT, ROW3_PORT, ROW4_PORT };
u8 ArrRowPins[4] = { ROW1_PIN, ROW2_PIN, ROW3_PIN, ROW4_PIN };

void vKeyPadInit(void){

	vSetPinDirection(ROW1_PORT,ROW1_PIN,input);
	vSetPinDirection(ROW2_PORT,ROW2_PIN,input);
	vSetPinDirection(ROW3_PORT,ROW3_PIN,input);
	vSetPinDirection(ROW4_PORT,ROW4_PIN,input);

	vSetPinDirection(COL1_PORT,COL1_PIN,output);
	vSetPinDirection(COL2_PORT,COL2_PIN,output);
	vSetPinDirection(COL3_PORT,COL3_PIN,output);
	vSetPinDirection(COL4_PORT,COL4_PIN,output);

	vPinValue(ROW1_PORT,ROW1_PIN,HIGH);
	vPinValue(ROW2_PORT,ROW2_PIN,HIGH);
	vPinValue(ROW3_PORT,ROW3_PIN,HIGH);
	vPinValue(ROW4_PORT,ROW4_PIN,HIGH);

	vPinValue(COL1_PORT,COL1_PIN,HIGH);
	vPinValue(COL2_PORT,COL2_PIN,HIGH);
	vPinValue(COL3_PORT,COL3_PIN,HIGH);
	vPinValue(COL4_PORT,COL4_PIN,HIGH);



}
u8 u8KeyPressed(){
	u8 flag = 0;
	u8 ReturnValue = NoKey;  // Assuming NoKey is a defined constant representing no key press

	for (u8 i = 0; i < 4; i++) {
		vPinValue(ArrColPort[i], ArrColPins[i], LOW);
		for (u8 j = 0; j < 4; j++) {
			if (u8ReadPin(ArrRowPort[j], ArrRowPins[j]) == 0) {
				ReturnValue = KeyPadArray[i][j];
				flag = 1;


				while(u8ReadPin(ArrRowPort[j], ArrRowPins[j]) == 0);
				_delay_ms(50);
				break;
			}
		}
		vPinValue(ArrColPort[i], ArrColPins[i], HIGH);
		if (flag == 1) {
			break;
		}
	}

	return ReturnValue;
}
