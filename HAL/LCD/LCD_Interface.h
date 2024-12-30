/*
 * LCD_Interface.h
 *
 *  Created on: Aug 23, 2024
 *      Author: Mohamed
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

void LcdInit(void);
void LcdWriteCommand(u8 command);
void LcdWriteData(u8 data);
void vLcdWriteString(u8 * str); // call this function
void vClearDisplay(void);
void vSetCursor(u8 Row, u8 Colum);
void vConvertNumbersToString(s32 num);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
