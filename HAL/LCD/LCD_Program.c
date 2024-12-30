/*
 * LCD_Program.c
 *
 *  Created on: Aug 23, 2024
 *      Author: Mohamed
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"LCD_Interface.h"
#include "../../Config/LCD_config.h"
#include <util/delay.h>

#if LDC_MODE == MODE_4
void LcdInit(void){
	vSetPinDirection(PORT_D7,PIN_D7,output);
	vSetPinDirection(PORT_D6,PIN_D6,output);
	vSetPinDirection(PORT_D5,PIN_D5,output);
	vSetPinDirection(PORT_D4,PIN_D4,output);
	vSetPinDirection(PORT_RS,PIN_RS,output);
	vSetPinDirection(PORT_RW,PIN_RW,output);
	vSetPinDirection(PORT_E,PIN_E,output);
	_delay_ms(35);
	LcdWriteCommand(0b00000010);
	LcdWriteCommand(0b00101000);
	_delay_us(45);
	LcdWriteCommand(0b00001111);
	_delay_us(45);
	LcdWriteCommand(0b00000001);
	_delay_ms(3);
	LcdWriteCommand(0b00000110);

}

void LcdWriteCommand(u8 command){
	vPinValue(PORT_RS,PIN_RS,LOW);
	vPinValue(PORT_RW,PIN_RW,LOW);

	vPinValue(PORT_D7,PIN_D7,READ_BIT(command,7));
	vPinValue(PORT_D6,PIN_D6,READ_BIT(command,6));
	vPinValue(PORT_D5,PIN_D5,READ_BIT(command,5));
	vPinValue(PORT_D4,PIN_D4,READ_BIT(command,4));

	vPinValue(PORT_E,PIN_E,HIGH);
	_delay_us(500);
	vPinValue(PORT_E,PIN_E,LOW);

	vPinValue(PORT_D7,PIN_D7,READ_BIT(command,3));
	vPinValue(PORT_D6,PIN_D6,READ_BIT(command,2));
	vPinValue(PORT_D5,PIN_D5,READ_BIT(command,1));
	vPinValue(PORT_D4,PIN_D4,READ_BIT(command,0));

	vPinValue(PORT_E,PIN_E,HIGH);
	_delay_us(500);
	vPinValue(PORT_E,PIN_E,LOW);

}
void LcdWriteData(u8 data){
	vPinValue(PORT_RS,PIN_RS,HIGH);
	vPinValue(PORT_RW,PIN_RW,LOW);

	vPinValue(PORT_D7,PIN_D7,READ_BIT(data,7));
	vPinValue(PORT_D6,PIN_D6,READ_BIT(data,6));
	vPinValue(PORT_D5,PIN_D5,READ_BIT(data,5));
	vPinValue(PORT_D4,PIN_D4,READ_BIT(data,4));

	vPinValue(PORT_E,PIN_E,HIGH);
	_delay_us(500);
	vPinValue(PORT_E,PIN_E,LOW);

	vPinValue(PORT_D7,PIN_D7,READ_BIT(data,3));
	vPinValue(PORT_D6,PIN_D6,READ_BIT(data,2));
	vPinValue(PORT_D5,PIN_D5,READ_BIT(data,1));
	vPinValue(PORT_D4,PIN_D4,READ_BIT(data,0));

	vPinValue(PORT_E,PIN_E,HIGH);
	_delay_us(500);
	vPinValue(PORT_E,PIN_E,LOW);

}
#elif LDC_MODE == MODE_8

void LcdInit(void){
	vSetPortDirection(PORT_DATA,PortStatusOutput);
	vSetPinDirection(PORT_RS,PIN_RS,output);
	vSetPinDirection(PORT_RW,PIN_RW,output);
	vSetPinDirection(PORT_E,PIN_E,output);
	_delay_ms(35);
#if Function_Set == Two_Lines
	LcdWriteCommand(Two_Lines);
#elif Function_Set == One_Line
	LcdWriteCommand(One_Line);
#endif
	_delay_us(45);
#if DisplayControl == CursorOn
	LcdWriteCommand(CursorOn);

#elif DisplayControl == CursorOFF
	LcdWriteCommand(CursorOFF);
#endif
	_delay_us(45);
	LcdWriteCommand(DisplayClear);
	_delay_ms(4);
	LcdWriteCommand(EntryMode);



}

void LcdWriteCommand(u8 command){
	vPinValue(PORT_RS,PIN_RS,LOW);
	vPinValue(PORT_RW,PIN_RW,LOW);
	vSetPortValue(PORT_DATA,command);

	vPinValue(PORT_E,PIN_E,HIGH);
	_delay_us(500);
	vPinValue(PORT_E,PIN_E,LOW);

}
void LcdWriteData(u8 data){
	vPinValue(PORT_RS,PIN_RS,HIGH);
	vPinValue(PORT_RW,PIN_RW,LOW);
	vSetPortValue(PORT_DATA,data);
	vPinValue(PORT_E,PIN_E,HIGH);
	_delay_us(500);
	vPinValue(PORT_E,PIN_E,LOW);
}
#endif
void vLcdWriteString(u8 * str){
	u8 i = 0;
	while(str[i]){
		LcdWriteData(str[i]);
		i++;
	}

	//	for(u8 i =0; i <= str[i]; i++){
	//		LcdWriteData(str[i]);
	//	}
}
void vClearDisplay(void){
	LcdWriteCommand(0b00000001);
	_delay_ms(1);
}

void vSetCursor(u8 Row, u8 Colum){
	if(Row <= 2 && Row >=1&& Colum <= 40 && Colum >=1){
		if(Row == 1){
			LcdWriteCommand(ROW_1+Colum);
		}else if (Row == 2){
			LcdWriteCommand(ROW_2+Colum);

		}
	}
}
void vConvertNumbersToString(s32 num){
	if(num == 0){
		LcdWriteData('0');
		return ;

	}
	if(num > 0){
		u8 Digit =0;
		u32 num1 = num;
		u8 i =0;
		while( num1 !=0){
			//		Digit = num1%10;
			num1 = num1/10;
			i++;
		}
		u8 str[i+1];


		for(s8 j = i-1; j >=0; j--){
			Digit = (num % 10) + '0';//"ASCII Number"
			str[j]= Digit;
			num = num/10;
		}
		str[i]='\0';
		vLcdWriteString(str);
	} if(num < 0){
		LcdWriteData('-');
		num *=-1;
		s8 Digit =0;
		s32 num1 = num;
		s8 i =0;
		while( num1 !=0){
			//		Digit = num1%10;
			num1 = num1/10;
			i++;
		}
		s8 str[i+1];


		for(s8 j = i-1; j >=0; j--){
			Digit = (num % 10) + '0';//"ASCII Number"
			str[j]= Digit;
			num = num/10;
		}
		str[i]='\0';
		vLcdWriteString(str);

	}

}
