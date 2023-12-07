/***************************************************************************************
 * @file motor.h
 * @version 1.0
 * @date 28/11/2023
 * @brief File with implementations of the Timer/PWM (TPM) Modules for the RoboRoadsters project.
 * @details None.
 * @author Cicero Eduardo Dick Junior
 ***************************************************************************************/

#include "motor.h"
#include "Drivers/tpm/tpm.h"
#include "Drivers/port/port.h"


void MOTOR_Init(){

	/*Configura o modulo do PWM para ~1ms*/
	/*Utilizando o clock de 20,971520 MHz/4 = 5,242880 MHz*/
	/*A frequência do PWM é de 5,242880 MHz/tpmPwmModulo = 1000 Hz*/
	const uint16_t tpmPwmModulo = 5243;

	/*Configuração do Clock que para o temporizador*/
	TPM_SetCounterClkSrc(TPM0, TPM_CNT_CLOCK_FLL);

	TPM_SetCounterClkSrc(TPM1, TPM_CNT_CLOCK_FLL);

	/*Inicializa o Módulo PWM*/
	TPM_Init(TPM0, tpmPwmModulo, TPM_PRESCALER_DIV_4);

	TPM_Init(TPM0, tpmPwmModulo, TPM_PRESCALER_DIV_4);

	/*Configuração do pino de saída*/
	PORT_Init(PORTB);
	PORT_Init(PORTA);
	PORT_SetMux(PORTB, 6, PORT_MUX_ALT2);
	PORT_SetMux(PORTA, 12, PORT_MUX_ALT2);
	PORT_SetMux(PORTA, 5, PORT_MUX_ALT2);
	PORT_SetMux(PORTB, 5, PORT_MUX_ALT2);

	/*Inicializa o canal como Saída*/
	TPM_InitChannel(TPM0, 3, TPM_EDGE_PWM_MODE, TPM_PWM_HIGH_TRUE_CONFIG); //M1
	TPM_InitChannel(TPM1, 0, TPM_EDGE_PWM_MODE, TPM_PWM_HIGH_TRUE_CONFIG); //M1N
	TPM_InitChannel(TPM0, 5, TPM_EDGE_PWM_MODE, TPM_PWM_HIGH_TRUE_CONFIG); //M2
	TPM_InitChannel(TPM1, 1, TPM_EDGE_PWM_MODE, TPM_PWM_HIGH_TRUE_CONFIG); //M2N

	TPM_SetChMatch(TPM0, 3, 0); //M1
	TPM_SetChMatch(TPM1, 0, 0); //M1N
	TPM_SetChMatch(TPM0, 5, 0); //M2
	TPM_SetChMatch(TPM1, 1, 0); //M2N


	/*Inicia o contador*/
	TPM_InitCounter(TPM0);
	TPM_InitCounter(TPM1);

}

void MOTOR_Forward(uint16_t speed){

	TPM_SetChMatch(TPM1, 1, 0);	 	//M2N
	TPM_SetChMatch(TPM1, 0, 0); 	//M1N
	TPM_SetChMatch(TPM0, 5, speed); //M2
	TPM_SetChMatch(TPM0, 3, speed); //M1

}

void MOTOR_Stop(void){

	TPM_SetChMatch(TPM0, 3, 0); //M1
	TPM_SetChMatch(TPM1, 0, 0); //M1N
	TPM_SetChMatch(TPM0, 5, 0); //M2
	TPM_SetChMatch(TPM1, 1, 0); //M2N
}

void MOTOR_Backward(uint16_t speed){

	TPM_SetChMatch(TPM0, 3, 0); 	//M1
	TPM_SetChMatch(TPM0, 5, 0); 	//M2
	TPM_SetChMatch(TPM1, 1, speed); //M2N
	TPM_SetChMatch(TPM1, 0, speed); //M1N
}

void MOTOR_Left(uint16_t speed){

	TPM_SetChMatch(TPM1, 1, 0); 	//M2N
	TPM_SetChMatch(TPM0, 3, 0); 	//M1
	TPM_SetChMatch(TPM1, 0, speed); //M1N
	TPM_SetChMatch(TPM0, 5, speed); //M2

}

void MOTOR_Right(uint16_t speed){

	TPM_SetChMatch(TPM1, 1, speed); //M2N
	TPM_SetChMatch(TPM0, 3, speed); //M1
	TPM_SetChMatch(TPM1, 0, 0); 	//M1N
	TPM_SetChMatch(TPM0, 5, 0);		//M2

}
