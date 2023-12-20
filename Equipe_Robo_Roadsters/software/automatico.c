/*
 * automatico.c
 *
 *  Created on: 15/11/2023
 *      Author: Bruno Camargo, CÃ­cero Eduardo Dick Junior e Marcelo Zampieri Pereira da Silva
 */

#include "automatico.h"
#include "libraries/pid_ctrl/pid_ctrl.h"
#include "libraries/ultrassound/ultrassound.h"
#include "libraries/bluetooth/bluetooth.h"
#include "libraries/motor/motor.h"
#include "libraries/encoder/encoder.h"
#include <stdbool.h>
#include <stdint.h>

static volatile pidCtrlHandle_t handleAngulo;
static volatile pidCtrlHandle_t handleMag;
static volatile uint8_t objective[2];		// distância de 0 a 255 cm em x e y
volatile _Bool g_isToRefreshRadar;		//A IRQ diz se ta na hora de varrer o perímetro novamente



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
_Bool Automatico_IsCommandAutomatic(void){

	//Se houver elemento na pilha e for o comando for 'A', desempilha o dado e retorna TRUE;
	if (Bluetooth_IsThereElement() && Bluetooth_GetElement()=='A'){
		Bluetooth_Unstack();
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

	//Atualiza a pilha e se houver o comando 'R', desempilha o dado e retorna TRUE;
	if (Bluetooth_IsThereElement() && Bluetooth_GetElement()=='R') {
		Bluetooth_Unstack();
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

	// Se houver dado na pilha, recebe as coordenadas x,y
	if (Bluetooth_IsThereElement()) {
		//Recebe x
		objective[0] = Bluetooth_GetElement();
		//Desempilha o x
		Bluetooth_Unstack();
		//Espera a coordenada y ser atualizada na pilha e a recebe.
		while (!Bluetooth_IsThereElement());
		// Recebe y
		objective[1] = Bluetooth_GetElement();
		Bluetooth_Unstack();
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
// Se o objeto estiver a 30cm, retorna verdadeiro
_Bool Automatico_Obstacles(){

	// se timer de 48ms, atualiza a distância e retorna se objeto está muito perto
	if (g_isToRefreshRadar){
		g_isToRefreshRadar = FALSE;

		uint8_t distancia = Ultrassound_Measure();
		//Se distancia do objeto menor que uma distancia critica
		if (distancia<=DISTANCIA_CRITICA) return TRUE;
	}
	else return FALSE;
}


// Tratamento de eventos


void Automatico_DesabilitaSensores(void){
	/*
	 * Deve desabilitar interrupções
	 */
	Ultrassound_FinishRadar();
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

	// Inicia variáveis de controle e contadores do radar ultrassom
	Ultrassound_InitRadar();


};

void Automatico_ControlePID(uint8_t x, uint8_t y){

	/*Tempo de Intervalo*/
	float timeInterval = 0.2;

	float erroAngulo = CalculaErroAngulo();
	float erroMag = CalculaErroMag();

	CtrlPID_CalculateWithInterval(handleAngulo, erroAngulo, timeInterval);
	CtrlPID_CalculateWithInterval(handleMag, erroMag, timeInterval);


};
