/*
 * automatico.c
 *
 *  Created on: 15/11/2023
 *      Author: Bruno Camargo, CÃ­cero Eduardo Dick Junior e Marcelo Zampieri Pereira da Silva
 */

# include "automatico.h"
# include <stdbool.h>
# include "pid_ctrl.h"

static volatile pidCtrlHandle_t handleAngulo;
static volatile pidCtrlHandle_t handleMag;

// Eventos

// Implementar UART para HC-05
_Bool IsCommandAutomatic(){

	/*Ler comando no serial Bluetooth*/
	/*
	 * Se o comando for = A, retorna verdadeiro
	 *
	 * */



};
// Implementar UART para HC-05
_Bool IsCommandGoBack(){

	/*Ler comando no serial Bluetooth*/
	/*
	 * Se o comando for = voltar, retorna verdadeiro
	 *
	 * */


};


_Bool IsCoordinatesOk();
_Bool IsOnDestination(); // Implementar Odometria (Encoders)
//_Bool IsSensorsOk();	 // Implementar Encoders e Ultrassonico
_Bool Obstacles();		 // Implementar Ultrassonico


// Tratamento de eventos
void Automatico_DesabilitaSensores(void);



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
