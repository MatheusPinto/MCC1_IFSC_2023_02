/*
 * ultrassom.c
 *
 *  Created on: 04/12/2023
 *      Author: bruno
 */

#include "ultrassound.h"
#include <MKL05Z4.h>
#include "../../mcu/drivers/port/port.h"
#include "../../mcu/drivers/tpm/tpm.h"
#include "../../mcu/drivers/gpio/gpio.h"
#include "../delay/delay.h"


uint8_t g_trigPin, g_echoPin;



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

	// Salva os pinos escolhidos pelo usuário
	g_trigPin=trigPin;
	g_echoPin=echoPin;

	PORT_Init(PORTB);

	// Inicialização dos pinos de I/O
	GPIO_InitInputPin(GPIOB, echoPin);
	GPIO_InitOutputPin(GPIOB, trigPin, 0);
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

	// Configura um timer PIT
    // Ativar o clock do sistema para o PIT(48MHz)
    SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;

    // Configurar o PIT para gerar interrupções periódicas

    PIT->MCR = 0;  // Habilitar o PIT

    // Configurar o canal 0 do PIT com o valor de contagem calculado([Tdesejado/Tclk]-1)
    /* Valor de contagem deve levar em conta 38ms de espera do echo + 10us de ativação do trig +
     * coeficiente de cagaço técnico(12ms)= 50 ms:
     * ([50ms*48MHz]-1)=2399999.
     */
    PIT->CHANNEL[0].LDVAL = 2399999;

    // Habilitar o contador
    PIT->CHANNEL[0].TCTRL = PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK;

    // Configurar a interrupção para o PIT
    NVIC_EnableIRQ(PIT_IRQn);
}

/** Funcao : Ultrassound_FinishRadar
  *
  * Descricao : Finaliza as irqs relacionadas ao ultrassom.
  *
  * Entradas : Vazia
  *
  * Saidas : Vazia.
  *
  * Comentarios : Nenhum.
 */
void Ultrassound_FinishRadar(void){
    // Desabilitar o contador e a irq
    PIT->CHANNEL[0].TCTRL = 0;

    // Desabilitar a irq interrupção para o PIT
    NVIC_EnableIRQ(PIT_IRQn);
}

/** Funcao : Ultrassound_Measure
  *
  * Descricao : Mede a distância de um objeto.
  *
  * Entradas : Vazia
  *
  * Saidas : Distância do objeto mais próximo.
  *
  * Comentarios : Nenhum.
 */
uint8_t Ultrassound_Measure(void){

	uint8_t distancia;
	// Seta o pino por 10ms para gerar onda sonora de mapeamento do radar
	// Pulsos devem ser atomicos
	__disable_irq();
	GPIO_WritePin(GPIOB, g_trigPin, HIGH);
	Delay_Waitus(10);
	GPIO_WritePin(GPIOB, g_trigPin, LOW);

	// A contagem do tempo de retorno no ECHO também deve ser atômica
	distancia=Ultrassom_EchoTime();
	__enable_irq();

	// Distancia = (Speed x Time) / 2 = (34cm/ms x Time) / 2. Velocidade= velocidade dosom e
	// 1/2 porquê queremos o tempo da onda do carrinho até o objeto, e não do carrino - onjeto - carrinho
	distancia=17*distancia;
	return distancia;

}

/** Funcao : Ultrassom_EchoTime
  *
  * Descricao : Calcula o tempo de nível lógico alto do ECHO.
  *
  * Entradas : Vazia
  *
  * Saidas : Tempo de nível lógico alto do ECHO.
  *
  * Comentarios : Nenhum.
 */
uint8_t Ultrassom_EchoTime(void){
	// A contagem é top down
	uint32_t tempoAtualCiclos=PIT->CHANNEL[0].CVAL;
	uint8_t tempoAtual;

	// Se 2399999[ciclos]=0% e 0[ciclos]=100%(50ms), então contagem%=(tempoAtual[ciclos]/2399999)-1
	// logo, tempoAtual[ms]=contagem%*50ms=((tempoAtual[ciclos]/2399999)-1)*50ms
	tempoAtual=50*((tempoAtualCiclos/2399999)-1); //tempoAtual em ms

	while(GPIO_ReadPin(GPIOB, g_echoPin)); //Enquanto não houver borda de decida no echoPin

	// Necessário proteção para o case de a contagem mais atual ter reiniciado a contagem, ex: tempoAtual=3-21323
	// Podemos somar o valor máximo de contagem +1 ao tempo mais atual, pegando sempre apenas
	// a contagem sobressalente do contador
	tempoAtual=(50*((tempoAtualCiclos/2399999)-1)+256)-tempoAtual; //Calcula o tempo em que ficou em nível lógico alto

	return tempoAtual;
}
