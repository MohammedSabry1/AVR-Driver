/*
 * Timer_Interface.h
 *
 *  Created on: Sep 14, 2024
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_


#define TIMER_0 0
#define TIMER_1 1
#define TIMER_2 2


/*************Clear Reg****************/
#define ClearMode			 0b10110111
#define ClearPrescaller		 0b11111000
#define ClearComp			 0b11001111
#define ClearModeTCCR1A		 0b11111100
#define ClearModeTCCR1B		 0b11100111
#define ClearTimer1Comp		 0b00111111

/************Timer Modes************/
//timer 0
#define Timer0_Normal_Mode  0b00000000
#define Timer0_PWM_Mode	 	0b01000000
#define Timer0_CTC_Mode		0b00001000
#define Timer0_FastPWM_Mode 0b01001000
//timer2
#define Timer2_Normal_Mode  0b00000000
#define Timer2_PWM_Mode	 	0b01000000
#define Timer2_CTC_Mode		0b00001000
#define Timer2_FastPWM_Mode 0b01001000
//timer 1
//TCCR1A
#define TCCR1A_NormalMode 			0b00000000
#define TCCR1A_PhaseCorrect_8Bits 	0b00000001
#define TCCR1A_PhaseCorrect_9Bits 	0b00000010
#define TCCR1A_PhaseCorrect_10Bits 	0b00000011
#define TCCR1A_CTC_OCR1A 			0b00000000
#define TCCR1A_FastPWM_8Bits 		0b00000001
#define TCCR1A_FastPWM_9Bits 		0b00000010
#define TCCR1A_FastPWM_10Bits 		0b00000011
#define TCCR1A_PWM_1CR1 			0b00000000
#define TCCR1A_PWM_OCR1A			0b00000001
#define TCCR1A_Phase_Correct_ICR1	0b00000010
#define TCCR1A_Phase_Correct_OCR1A	0b00000011
#define TCCR1A_CTC_ICR1				0b00000000
#define TCCR1A_FastPWM_ICR1 		0b00000010
#define TCCR1A_FastPWM_OCR1A		0b00000011
//TCCR1B
#define TCCR1B_NormalMode 			0b00000000
#define TCCR1B_PhaseCorrect_8Bits 	0b00000000
#define TCCR1B_PhaseCorrect_9Bits 	0b00000000
#define TCCR1B_PhaseCorrect_10Bits 	0b00000000
#define TCCR1B_CTC_OCR1A 			0b00001000
#define TCCR1B_FastPWM_8Bits 		0b00001000
#define TCCR1B_FastPWM_9Bits 		0b00001000
#define TCCR1B_FastPWM_10Bits 		0b00001000
#define TCCR1B_PWM_1CR1 			0b00010000
#define TCCR1B_PWM_OCR1A			0b00010000
#define TCCR1B_Phase_Correct_ICR1	0b00010000
#define TCCR1B_Phase_Correct_OCR1A	0b00010000
#define TCCR1B_CTC_ICR1				0b00011000
#define TCCR1B_FastPWM_ICR1 		0b00011000
#define TCCR1B_FastPWM_OCR1A		0b00011000
/**************Timer Prescaller*********************/
//timer 0
#define Timer_StopCounter		 0
#define	Timer_NoPrescaller		 1
#define Timer_Prescaller_8		 2
#define Timer0_Prescaller_64 	 3
#define Timer0_Prescaller_256  	 4
#define Timer0_Prescaller_1024 	 5
#define Timer0_Falling_Edge    	 6
#define Timer0_Raising_Edge		 7
//timer 2
#define Timer2_Prescaller_32 	3
#define Timer2_Prescaller_64 	4
#define Timer2_Prescaller_128 	5
#define Timer2_Prescaller_256 	6
#define Timer2_Prescaller_1024 	7
//timer 1
#define Timer1_Prescaller_64 	 3
#define Timer1_Prescaller_256  	 4
#define Timer1_Prescaller_1024 	 5
#define Timer1_Ex_Falling_Edge   6
#define Timer1_Ex_Raising_Edge	 7

/******************CTC MODES***************************/
// Compare Output Mode, Fast PWM Mode
#define DISCONNEDTED 	 0b00000000
#define Reserved		 0b00010000
#define non_inverting 	 0b00100000 //Ton = OCR0
#define inverting		 0b00110000 //Toff = OCR0

/*ctc timer 1 modes*/
#define Timer1_DISCONNEDTED 	 0b00000000
#define Timer1_Reserved			 0b01000000
#define Timer1_non_inverting 	 0b10000000
#define Timer1_inverting		 0b11000000

void vTimerInit(void);
void vPreload_Timer(u8 value);
void vOCR_Timer( u8 value);
void vDISAPLE_INTERRUPT_Timer (void);
void vENABLE_INTERRUPT_Timer (void);
void vDISAPLE_TIMER (void);
void vENALBE_TIMER (void);
void vSet_ICR1( u8 value);




void CALLBACK_TOF_TIMER0(void (*FPTR)(void));

void CALLBACK_OCR0_TIMER0(void (*FPTR)(void));
#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
