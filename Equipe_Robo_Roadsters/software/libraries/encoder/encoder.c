/*
 * encoder.c
 *
 *  Created on: 03/12/2023
 *      Author: junin
 */

#include "encoder.h"
#include "../../mcu/drivers/port/port.h"
#include "../../mcu/drivers/gpio/gpio.h"

static volatile uint16_t pulsos_d0 = 0;
static volatile uint16_t pulsos_d1 = 0;


void ENCODER_Init(){


	/*Inicializa PTB0 para encoder D0*/
	PORT_Init(PORTB);
	PORT_SetMux(PORTB, 0, PORT_MUX_ALT1);
	GPIO_InitInputPin(GPIOB, 0);
	PORT_EnablePull(PORTB, 0);
	NVIC_EnableIRQ(PORTB_IRQn);
	PORT_EnableIRQ(PORTB, 0, PORT_IRQ_ON_FALLING_EDGE);

	/*Inicializa PTA6 para encoder D1*/
	PORT_Init(PORTA);
	PORT_SetMux(PORTA, 7, PORT_MUX_ALT1);
	GPIO_InitInputPin(GPIOA, 7);
	PORT_EnablePull(PORTA, 7);
	NVIC_EnableIRQ(PORTA_IRQn);
	PORT_EnableIRQ(PORTA, 7, PORT_IRQ_ON_FALLING_EDGE);

}


uint16_t ENCODER_get_d0(){

	uint16_t d0 = 0;
	d0 = pulsos_d0;
	pulsos_d0 = 0;

	return d0;
}

uint16_t ENCODER_get_d1(){

	uint16_t d1 = 0;
	d1 = pulsos_d1;
	pulsos_d1 = 0;

	return d1;
}

void PORTA_IRQHandler(void){

	//Checa se a interrupção foi dada pelo PTA6 (Encoder D1)
	if (PORTA->ISFR & 1 << 7){

		//Limpa a Flag
		PORTA->ISFR = 1 << 7;

		//Debounce
		NVIC_DisableIRQ(PORTA_IRQn);

		//Contagem de Pulsos do Encoder
		++pulsos_d1;
	}
}


void PORTB_IRQHandler(void){

	//Checa se a interrupção foi dada pelo PTB0 (Encoder D0)
	if (PORTB->ISFR & 1){

		//Limpa a Flag
		PORTB->ISFR = 1;

		//Debounce
		NVIC_DisableIRQ(PORTB_IRQn);

		//Contagem de Pulsos do Encoder
		++pulsos_d0;
	}
}
