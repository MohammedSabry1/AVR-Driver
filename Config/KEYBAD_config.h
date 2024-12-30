/*
 * KEYBAD_config.h
 *
 *  Created on: Aug 30, 2024
 *      Author: Mohamed
 */

#ifndef HAL_KEYBAD_KEYBAD_CONFIG_H_
#define HAL_KEYBAD_KEYBAD_CONFIG_H_

//***********************Column Config ***********************

#define COL1_PORT  PORT_C
#define COL1_PIN   PIN_2

#define COL2_PORT PORT_C
#define COL2_PIN   PIN_3

#define COL3_PORT PORT_C
#define COL3_PIN   PIN_4

#define COL4_PORT PORT_C
#define COL4_PIN  PIN_5


//***********************ROW Config ***********************

#define ROW1_PORT   PORT_B
#define ROW1_PIN   PIN_4

#define ROW2_PORT   PORT_B
#define ROW2_PIN    PIN_5

#define ROW3_PORT    PORT_B
#define ROW3_PIN   PIN_6

#define ROW4_PORT     PORT_B
#define ROW4_PIN	PIN_7



u8 KeyPadArray[4][4] ={
		{'7','8','9','/'},
		{'4','5','6','x'},
		{'1','2','3','-'},
		{'c','0','=','+'}





//		{'/','x','+','-'},
//		{'0','8','2','5'},
//		{'=','9','3','6'},
//		{'c','7','1','4'}
};
#endif /* HAL_KEYBAD_KEYBAD_CONFIG_H_ */
