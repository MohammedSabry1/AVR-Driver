/*
 * LCD_config.h
 *
 *  Created on: Aug 23, 2024
 *      Author: Mohamed
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


//***********************ldc mode***********************

#define MODE_4 0
#define MODE_8 1
#define LDC_MODE MODE_4 // Edit here to change mode

//*********************** DDRAM ROWS***********************

#define ROW_1 0x80
#define ROW_2 0xc0


#if LDC_MODE == MODE_8
//***********************8-Bit Control Pin***********************

#define PORT_RS PORT_B
#define PIN_RS PIN_1

#define PORT_RW PORT_B
#define PIN_RW PIN_2

#define PORT_E PORT_B
#define PIN_E PIN_3

//***********************8-Bit Data Pin***********************

#define PORT_DATA PORT_A

//***********************8-Bit Function Set***********************
#define One_Line 0b00110000
#define Two_Lines 0b00111000
#define Function_Set Two_Lines // Edit here to change mode

//***********************8-Bit Display on/off***********************

#define CursorOn 0b00001111
#define CursorOFF 0b00001101
#define DisplayControl CursorOn // Edit here to change mode
//***********************8-Bit DISPLAY CLEAR ***********************

#define DisplayClear 0b00000001

//***********************8-Bit ENTRY MODE ***********************

#define EntryMode 0b00000110

#elif LDC_MODE == MODE_4

//***********************4-Bit Mode Pins ***********************

#define PIN_D7 PIN_7
#define PIN_D6 PIN_6
#define PIN_D5 PIN_5
#define PIN_D4 PIN_4

#define PIN_RS PIN_1
#define PIN_RW PIN_2
#define PIN_E PIN_3
//***********************4-Bit Mode Ports ***********************
#define PORT_D7 PORT_A
#define PORT_D6 PORT_A
#define PORT_D5 PORT_A
#define PORT_D4 PORT_A

#define PORT_RS PORT_B
#define PORT_RW PORT_B
#define PORT_E PORT_B
//***********************4-Setfun ***********************
#define Mode4Trig1 0b00000010
#define Mode4Trig_two_line 0b00101000
#define Mode4Trig_one_line 0b00100000
#define Function_Set Mode4Trig_two_line


#endif
#endif /* HAL_LCD_LCD_CONFIG_H_ */
