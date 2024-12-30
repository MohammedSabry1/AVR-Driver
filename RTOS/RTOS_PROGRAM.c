/*
 * RTOS_PROGRAM.c
 *
 *  Created on: Oct 17, 2024
 *      Author: Mahmoud
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/Global_Interrupt/GIE_Interface.h"
#include "RTOS_PRAIVET.h"
#include "RTOS_CONFG.h"
#include "RTOS_INTERFACE.h"


TASk_t RTOS_SCHEDULR_ARRAY[NUM_OF_TASK];

void START_RTOS()
{

	// INIT TIMER
	vTimerInit();

	// SELECT MODE // CTC  TO SELECT SYSTICK

	vOCR_Timer(249);  // SYSTICK  =  1MS



	// CALLBACK(SHEDULAR)
	CALLBACK_OCR0_TIMER0(&RTOS_SCHADULAR);



	// ENEBLE GIE
	ENABLE_GIE();

	// ENEBLE TIMER

	vENALBE_TIMER();

}

BOOL_t CREATE_RTOS_TASK(void(*FPTR)(void),u8 PERIORTY,u16 PERIODICITY)
{
	if(PERIORTY<NUM_OF_TASK && FPTR !=NULLPTR && RTOS_SCHEDULR_ARRAY[PERIORTY].ptr ==NULLPTR  )
	{
	RTOS_SCHEDULR_ARRAY[PERIORTY].ptr = FPTR;
	RTOS_SCHEDULR_ARRAY[PERIORTY].periodicty = PERIODICITY;
	RTOS_SCHEDULR_ARRAY[PERIORTY].STATE = RESUME;

//	vSetPinDirection(PORT_A,PIN_0,OUTPUT);
//		TOG_BIT(PORTA,0);
     return TRUE;
	}
	return FALSE;

}


static void RTOS_SCHADULAR()
{
	static u32 rtos_tick = 0;
	rtos_tick ++;
	u8 i = 0;

	for(i=0;i<NUM_OF_TASK;i++)
	{
		if (RTOS_SCHEDULR_ARRAY[i].STATE == RESUME){

		if(rtos_tick % RTOS_SCHEDULR_ARRAY[i].periodicty==0 && RTOS_SCHEDULR_ARRAY[i].ptr != NULLPTR )
		{
			RTOS_SCHEDULR_ARRAY[i].ptr();
		}
		}
	}

}

void SUSPEND_TASK(u8 PERIORTY){
	RTOS_SCHEDULR_ARRAY[PERIORTY].STATE = SUSPEND;

}
void RESUME_TASK(u8 PERIORTY){
	RTOS_SCHEDULR_ARRAY[PERIORTY].STATE = RESUME;

}
void DELETE_TASK(u8 PERIORTY){


	RTOS_SCHEDULR_ARRAY[PERIORTY].ptr == NULLPTR;
}
