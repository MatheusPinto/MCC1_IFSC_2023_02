/*
 * irqs.c
 *
 *  Created on: 12/12/2023
 *      Author: bruno
 */

#include "irqs.h"
#include "../../mcu/drivers/port/port.h"
#include "../../mcu/common.h"
#include "../../automatico.h"



/*void PORTA_IRQHandler(void){
	if (){

	}
}*/

/*void PORTB_IRQHandler(void){
	if (){

	}
}*/

void PIT_IRQHandler(void) {

	/* Timer para atualizar o radar(38ms + coeficiente de cagaço "críticamente técnico"= 50ms ) */
	// Limpar o flag de interrupção
	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;

	// Atualiza a variável de controle do radar
	g_isToRefreshRadar=true;
}
