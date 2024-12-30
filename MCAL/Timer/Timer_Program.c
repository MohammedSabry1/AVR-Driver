/*
 * Timer_Program.c
 *
 *  Created on: Sep 14, 2024
 *      Author: Mohamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "Timer_Interface.h"
#include "../../Config/Timer_Config.h"


void (*PTR_OVF)(void)  = NULLPTR;

void (*PTR_OCR)(void)  = NULLPTR;

void vTimerInit(void){
#if TimerMODE == Timer_0
	//Set time mode
	TCCR0 &= ClearMode;
	TCCR0 |= Timer0Mode;

	//Select the prescaller


	vENABLE_INTERRUPT_Timer();
	//sellect compare match mode
	if(Timer0Mode != Timer0_Normal_Mode){
		TCCR0 &= ClearComp;
		TCCR0 |= Timer0_CompMode;
	}
#elif TimerMODE == TIMER_2
	TCCR2 &= ClearMode;
	TCCR2 |= Timer2Mode;


	vENABLE_INTERRUPT_Timer();

	TCCR2 &= ClearComp;
	TCCR2 |= Timer2_CompMode;
	if(Timer2Mode != Timer2_Normal_Mode){
		TCCR2 &= ClearComp;
		TCCR2 |= Timer2_CompMode;
	}
#elif TimerMODE == TIMER_1
	//select mode
	//FastPWM top ICR1
	TCCR1A &= ClearModeTCCR1A;
	TCCR1A |= Timer1ModeTCCR1A;
	TCCR1B &= ClearModeTCCR1B;
	TCCR1B |= Timer1ModeTCCR1B;
	//select compare mode
	//non-inverting
	TCCR1A &=ClearTimer1Comp;
	TCCR1A |= Timer1_CompMode;


	vENABLE_INTERRUPT_Timer();
	if(Timer1ModeTCCR1A != TCCR1A_NormalMode && Timer1ModeTCCR1B != TCCR1B_NormalMode){
		TCCR1A &=ClearTimer1Comp;
		TCCR1A |= Timer1_CompMode;
	}
#endif

}
void vPreload_Timer(u8 value){
	//set the preload
#if TimerMODE == TIMER_0
	TCNT0 = value;
#elif TimerMODE == TIMER_2
	TCNT2 = value;
#elif TimerMODE == TIMER_1
	TCNT1 = value;
#endif
}
void vOCR_Timer( u8 value){
#if TimerMODE == TIMER_0
	OCR0= value;
#elif TimerMODE == TIMER_2
	OCR2= value;
#elif TimerMODE == TIMER_1
	OCR1A= value;

#endif
}


void vDISAPLE_INTERRUPT_Timer(void){
#if TimerMODE == TIMER_0
	TIMSK&=0b11111100;
#elif TimerMODE == TIMER_2
	TIMSK&=0b00111111;
#elif TimerMODE == TIMER_1
	TIMSK&=0b11000011;

#endif
}

void vENABLE_INTERRUPT_Timer (void){
#if TimerMODE == TIMER_0
	if(Timer0Mode == Timer0_Normal_Mode){
		SET_BIT(TIMSK,TOIE0);

	}else{
		SET_BIT(TIMSK,OCIE0);

	}
#elif TimerMODE == TIMER_2
	if(Timer2Mode == Timer2_Normal_Mode){
		SET_BIT(TIMSK,TOIE2);

	}else{
		SET_BIT(TIMSK,OCIE2);

	}
#elif TimerMODE == TIMER_1
	if(Timer1ModeTCCR1A == TCCR1A_NormalMode && Timer1ModeTCCR1B == TCCR1B_NormalMode){

		SET_BIT(TIMSK,TOIE1);

	}else{
		SET_BIT(TIMSK,OCIE1A);
		SET_BIT(TIMSK,OCIE1B);


	}
#endif
}
void vENALBE_TIMER (void){
#if TimerMODE == TIMER_0
	TCCR0 &= ClearPrescaller;
	TCCR0 |= Timer0PrescallerMode;
#elif  TimerMODE == TIMER_1
	TCCR1B&= ClearPrescaller;
		TCCR1B |= Timer1PrescallerMode;
#elif  TimerMODE == TIMER_2
		TCCR2 &= ClearPrescaller;
		TCCR2 |= Timer2PrescallerMode;

#endif
}
void vDISAPLE_TIMER (void){
#if TimerMODE == TIMER_0
	TCCR0 &= ClearPrescaller;
#elif TimerMODE == TIMER_2
	TCCR2 &= ClearPrescaller;
#elif TimerMODE == TIMER_1
	TCCR1B &= ClearPrescaller;

#endif
}
void vSet_ICR1( u8 value){
	ICR1 = value;
}
void CALLBACK_TOV_TIMER0(void (*FPTR)(void))//&TASK1
{


		PTR_OVF= FPTR;



}

void CALLBACK_OCR0_TIMER0(void (*FPTR)(void))
{
	PTR_OCR = FPTR;
}




void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_11 (void){

	if(PTR_OVF != NULLPTR)
	{
		PTR_OVF();
	}


}



void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ;\
void __vector_10 (void){

	if(PTR_OCR != NULLPTR)
	{
		PTR_OCR();
	}



}
