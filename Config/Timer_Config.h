/*
 * Timer_Config.h
 *
 *  Created on: Sep 14, 2024
 *      Author: Mohamed
 */

#ifndef CONFIG_TIMER_CONFIG_H_
#define CONFIG_TIMER_CONFIG_H_


#define TimerMODE TIMER_1
/*Select mode {Timer_StopCounter - Timer_NoPrescaller - Timer_Prescaller_8
  			   Timer0_Prescaller_64 - Timer0_Prescaller_256 - Timer0_Prescaller_1024
  			   Timer0_Falling_Edge - Timer0_Raising_Edge} */
#define Timer0PrescallerMode Timer_NoPrescaller
/*Select mode {Timer_StopCounter - Timer_NoPrescaller - Timer_Prescaller_8
  			   Timer2_Prescaller_32 - Timer2_Prescaller_64 - Timer2_Prescaller_128
  			   Timer2_Prescaller_256 - Timer2_Prescaller_1024} */
#define Timer2PrescallerMode Timer2_Prescaller_1024

/*Select mode {Timer_StopCounter - Timer_NoPrescaller - Timer_Prescaller_8
  			   Timer1_Prescaller_64 - Timer1_Prescaller_256 - Timer1_Prescaller_1024
  			    Timer1_Ex_Falling_Edge - Timer1_Ex_Raising_Edge} */
#define Timer1PrescallerMode Timer1_Prescaller_256
/*Select Mode { Timer0_Normal_Mode - Timer0_PWM_Mode(Phase correct)
 * 				Timer0_CTC_Mode - Timer0_FastPWM_Mode}*/
#define Timer0Mode Timer0_Normal_Mode
/*Select Mode { Timer2_Normal_Mode - Timer2_PWM_Mode(Phase correct)
 * 				Timer2_CTC_Mode - Timer2_FastPWM_Mode}*/
#define Timer2Mode Timer2_Normal_Mode
	 /* TCCR1A_NormalMode  -  TCCR1A_PhaseCorrect_8Bits  -  TCCR1A_PhaseCorrect_9Bits
 TCCR1A_PhaseCorrect_10Bits  -  TCCR1A_CTC_OCR1A  -  TCCR1A_FastPWM_8Bits
 TCCR1A_FastPWM_9Bits  -  TCCR1A_FastPWM_10Bits  -  TCCR1A_PWM_1CR1
 TCCR1A_PWM_OCR1A  -  TCCR1A_Phase_Correct_ICR1  -  TCCR1A_Phase_Correct_OCR1A
 TCCR1A_CTC_ICR1  -  TCCR1A_FastPWM_ICR1  -  TCCR1A_FastPWM_OCR1A

 TCCR1A Same as TCCR1B
 */
#define Timer1ModeTCCR1A TCCR1A_FastPWM_ICR1
#define Timer1ModeTCCR1B TCCR1B_FastPWM_ICR1

/*
 select compare mode(DISCONNEDTED-Reserved-non_inverting-inverting)
 */
#define Timer0_CompMode non_inverting
#define Timer1_CompMode Timer1_non_inverting
#define Timer2_CompMode non_inverting









#endif /* CONFIG_TIMER_CONFIG_H_ */
