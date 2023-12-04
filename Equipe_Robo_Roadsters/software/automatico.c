/*
 * automatico.c
 *
 *  Created on: 15/11/2023
 *      Author: Bruno Camargo, CÃ­cero Eduardo Dick Junior e Marcelo Zampieri Pereira da Silva
 */

#include "automatico.h"
#include "pid_ctrl.h"
#include "mcu/drivers/uart/uart.h"
#include <stdbool.h>
#include <stdint.h>

static volatile pidCtrlHandle_t handleAngulo;
static volatile pidCtrlHandle_t handleMag;
static volatile uint8_t objective[2];		// distância de 0 a 255 em x e y

// Eventos

/** Funcao : Automatico_IsComandAutomatic
  *
  * Descricao : Verifica se o comando automatico foi passado via bluetooth.
  *
  * Entradas : Vazia
  *
  * Saidas : 0 se o comando nao foi passado e !0 caso contrário.
  *
  * Comentarios : Nenhum.
 */
_Bool Automatico_IsComandAutomatic(void){

	if (UART_IsRXAvailable(UART0) && UART_Read(UART0)=='A') {
		return TRUE;
	}

	return FALSE;
}

/** Funcao : Automatico_IsCommandGoBack
  *
  * Descricao : Verifica se o comando voltar foi passado via bluetooth.
  *
  * Entradas : Vazia
  *
  * Saidas : 0 se o comando nao foi passado e !0 caso contrário.
  *
  * Comentarios : Nenhum.
 */
_Bool Automatico_IsCommandGoBack(void){

	if (UART_IsRxAvailable(UART0) && UART_Read(UART0)=='R') {
		return TRUE;
	}

	return FALSE;
}

/** Funcao : Automatico_IsCoordinatesOk
  *
  * Descricao : Verifica se dados chegaram e, se sim obtem os dados do objetivo
  *
  * Entradas : Vazia
  *
  * Saidas : 0 se o comando nao foi passado e !0 caso contrário.
  *
  * Comentarios : Nenhum.
 */
_Bool Automatico_IsCoordinatesOk(void) {
	// Se tiver dado para receber
	if (UART_IsRxAvailable(UART0)) {
		// Recebe x
		objective[0] = UART_Read(UART0);
		while (!UART_IsRxAvailable(UART0));
		// Recebe y
		objective[1] = UART_Read(UART0);
		return TRUE;
	}

	// Se não, retorna falso
	else return FALSE;
}


_Bool Automatico_IsOnDestination(){

	/* Implementar Odometria (Encoders)
	 * Comparar Objective com localization
	 */
}

// Implementar Encoders e Ultrassonico
_Bool Obstacles();


// Tratamento de eventos
void Automatico_DesabilitaSensores(void){
	/*
	 * Deve desabilitar interrupções
	 */
}



void Automatico_ConfiguraPID(void){

	/*Cria variável de configuração do controle PID para distancia*/
	pidCtrlConfig_t* configMag = CtrlPID_CreateConfig();

	configMag->gainP = 15;
	configMag->gainI = 0;
	configMag->gainD = 0;
	configMag->delthaTime = 0.2;
	configMag->lastTime = 0;
	configMag->lastError = 0;
	configMag->ErrorD = 0;
	configMag->ErrorI = 0;


	/*Cria variável de configuração do controle PID para angulo*/
	pidCtrlConfig_t* configAngulo = CtrlPID_CreateConfig();

	configAngulo->gainP = 15;
	configAngulo->gainI = 0;
	configAngulo->gainD = 0;
	configAngulo->delthaTime = 0.2;
	configAngulo->lastTime = 0;
	configAngulo->lastError = 0;
	configAngulo->ErrorD = 0;
	configAngulo->ErrorI = 0;

	/*Cria a variavel handle para os controles PID*/
	handleMag = CtrlPID_Init(configMag);
	handleAngulo = CtrlPID_Init(configAngulo);


	/*Inicializar Sensor Ultrassônico*/

};

void Automatico_ControlePID(uint8_t x, uint8_t y){

	/*Tempo de Intervalo*/
	float timeInterval = 0.2;

	float erroAngulo = CalculaErroAngulo();
	float erroMag = CalculaErroMag();

	CtrlPID_CalculateWithInterval(handleAngulo, erroAngulo, timeInterval);
	CtrlPID_CalculateWithInterval(handleMag, erroMag, timeInterval);


};
