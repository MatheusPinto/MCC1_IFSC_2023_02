/*
 * teste.c
 *
 *  Created on: 28/11/2023
 *      Author: junin
 */

#include <MKL05Z4.h>
#include "motor.h"
#include "Libraries/delay/delay.h"



int main(void){

	MOTOR_Init();
	Delay_Init();

	uint16_t speed = 2500;
	for(;;){

		Delay_Waitms(5000);
		MOTOR_Forward(speed);

		Delay_Waitms(5000);
		MOTOR_Backward(speed);

		Delay_Waitms(5000);
		MOTOR_Left(speed);

		Delay_Waitms(5000);
		MOTOR_Right(speed);

		Delay_Waitms(5000);
		MOTOR_Stop();

	}
}


