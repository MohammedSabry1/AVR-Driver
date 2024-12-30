/*
 * RTOS_INTERFACE.h
 *
 *  Created on: Oct 17, 2024
 *      Author: Mahmoud
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_


typedef struct {
	u16 periodicty;
	void (*ptr)(void);
	u8 STATE;

}TASk_t;


typedef enum
{

	FALSE,
	TRUE
}BOOL_t;

#define SUSPEND 	0
#define RESUME	 	1

void START_RTOS();

BOOL_t CREATE_RTOS_TASK(void(*FPTR)(void),u8 PERIORTY,u16 PERIODICITY);

void SUSPEND_TASK(u8 PERIORTY);
void RESUME_TASK(u8 PERIORTY);
void DELETE_TASK(u8 PERIORTY);


#endif /* RTOS_RTOS_INTERFACE_H_ */
