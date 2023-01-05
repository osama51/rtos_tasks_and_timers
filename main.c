#include <avr/io.h>

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#define NUM_TIMERS 3

TimerHandle_t xTimers[ NUM_TIMERS ];

void Task1_Func(void);
TaskHandle_t task1ptr;

void Task2_Func(void);
TaskHandle_t task2ptr;

void Task3_Func(void);
TaskHandle_t task3ptr;


int main(void)
{
	DDRC  = 0xFF;	// Configure all PORTC pins as output pins

	/*########################### SOFTWARE TIMER ###############################*/

	 xTimers[ 0 ] = xTimerCreate( "Timer1", pdMS_TO_TICKS( 100 ), pdTRUE, ( void * ) 0, Task1_Func);
	 xTimers[ 1 ] = xTimerCreate( "Timer2", pdMS_TO_TICKS( 50 ), pdTRUE, ( void * ) 0, Task2_Func);
	 xTimers[ 2 ] = xTimerCreate( "Timer3", pdMS_TO_TICKS( 20 ), pdTRUE, ( void * ) 0, Task3_Func);

	 xTimerStart( xTimers[ 0 ], pdMS_TO_TICKS( 100 ) );
	 xTimerStart( xTimers[ 1 ], pdMS_TO_TICKS( 50 ) );
	 xTimerStart( xTimers[ 2 ], pdMS_TO_TICKS( 20 ) );

//	 vTaskStartScheduler();

	 /*##########################################################################*/

	 /*########################### TASKS CREATION ###############################*/
//	xTaskCreate(Task1_Func,"first",configMINIMAL_STACK_SIZE,NULL,0,&task1ptr);
//	xTaskCreate(Task2_Func,"second",configMINIMAL_STACK_SIZE,NULL,0,&task2ptr);
//	xTaskCreate(Task3_Func,"third",configMINIMAL_STACK_SIZE,NULL,0,&task3ptr);

	 /*##########################################################################*/

	vTaskStartScheduler();
	while(1){}
}


void Task1_Func(void)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS( 100 );
	xLastWakeTime = xTaskGetTickCount();
//	while(1)
//	{
		PORTC ^= (1u<<5);
//		vTaskDelayUntil( &xLastWakeTime, xPeriod );
//		vTaskDelay( 100 );
//	}
//		xTimerStop( xTimers[ 0 ], pdMS_TO_TICKS( 100 ) );
}



void Task2_Func(void)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS( 50 );
	xLastWakeTime = xTaskGetTickCount();
//	while(1)
//	{
		PORTC ^= (1u<<3);
//		vTaskDelayUntil( &xLastWakeTime, xPeriod );
//	}
//		xTimerStop( xTimers[ 1 ], pdMS_TO_TICKS( 50 ) );
}

void Task3_Func(void)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS( 20 );
	xLastWakeTime = xTaskGetTickCount();
//	while(1)
//	{
		PORTC ^= (1u<<1);
//		vTaskDelayUntil( &xLastWakeTime, xPeriod );
//	}
//		xTimerStop( xTimers[ 2 ], pdMS_TO_TICKS( 20 ) );
}


//vTaskDelay( 30 );//pdMS_TO_TICKS( 20 )
