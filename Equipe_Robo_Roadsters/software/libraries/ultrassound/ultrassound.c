/*
 * ultrassom.c
 *
 *  Created on: 04/12/2023
 *      Author: bruno
 */

#include "ultrassound.h"
#include "../../mcu/drivers/port/port.h"
#include "../../mcu/drivers/tpm/tpm.h"
#include "../../mcu/drivers/gpio/gpio.h"


static volatile uint8_t g_ultrassoundCounter;		// Contador do ultrassom
static volatile uint8_t g_gerarPulso;
static uint8_t g_trigPin, g_echoPin;


/** Funcao : Ultrassom_Init
  *
  * Descricao : Inicia o hardware necessário para o radar ultrassom.
  *
  * Entradas : trigPin e echoPin são os pinos de trig e echo ao qual o módulo está conectado
  *
  * Saidas : Vazia.
  *
  * Comentarios : Nenhum.
 */
void Ultrassound_Init(uint8_t trigPin, uint8_t echoPin){

	const uint16_t tpmPwmModulo = 6226;

	// Salva os pinos escolhidos pelo usuário
	g_trigPin=trigPin;
	g_echoPin=echoPin;

	// Seleciona o clock do contador
	TPM_SetCounterClkSrc(TPM0, TPM_CNT_CLOCK_FLL);

	/* Inicializa TPM0, dividindo clock de entrada por 128, resultando em um clock
	 * do contador de 20.971520 MHz /128 = 163840 Hz. A contagem toal deve ser de 38ms,
	 * dessa forma, o módulo de contagem deve ser de aproximadamente 6226 tpmPwmModulo
	 */
	TPM_Init(TPM0, tpmPwmModulo, TPM_PRESCALER_DIV_128);

	// talvez seja melhor iniciar os ports tudo junto no system init
	PORT_Init(PORTB);

	// Inicialização dos pinos de I/O
	GPIO_InitInputPin(GPIOB, trigPin);
	GPIO_InitOutputPin(GPIOB, echoPin, 0);
}

/** Funcao : Ultrassom_InitRadar
  *
  * Descricao : Inicia o contador TPM0 com IRQ a cada 38 ms.
  *
  * Entradas : Vazia
  *
  * Saidas : Vazia.
  *
  * Comentarios : Nenhum.
 */
void Ultrassound_InitRadar(void){
	TPM_InitCounter(TPM0); //Inicia contador com clok interno;
	TPM_EnableIRQ(TPM0); //Habilita interrupção no overflow de contagem
	NVIC_EnableIRQ( PORTB_IRQn ); // Habilita a IRQ do PORTB poelo NVIC

	// Inicia variáveis de controle do radar
	g_ultrassoundCounter=0;
	g_gerarPulso=0;
}

void PORTA_IRQHandler(void){
	if (PORT_GetIRQFlag(PORTB, ECHO0)){
		TPM_ClearIRQFlag(TPM0);
		g_gerarPulso=1;
	}
}



