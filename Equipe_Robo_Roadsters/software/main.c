/*
 *  	Created on: 15/11/2023
 *      Author: Bruno Camargo, Cícero Eduardo Dick Junior e Marcelo Zampieri Pereira da Silva
 */

#include <MKL05Z4.h>
#include "automatico.h"

/*TIPOS ENUMERADOS*/
/*=======================================================================================*/

/* Possíveis estados da FSM */
typedef enum {
	AGUARDANDO_MODO_DE_OPERACAO = 0U,
	AGUARDANDO_DESTINO,
//	CONFIGURAR_SENSORES_DO_AUTONOMO,
	CONTROLE_PID,
	DESVIA_OBJETO,
} estado_t;

/*FIM: TIPOS ENUMERADOS*/
/*=======================================================================================*/

// ver com o professor sobre o uso de static no caso de utilização de IRQs para alterar estados
static volatile estado_t currentState;

int main(void)
{
	//System_Init();

	//medir_distancia();

	for (;;) {

		switch (currentState) {
		case (AGUARDANDO_MODO_DE_OPERACAO):
			if (Automatico_IsCommandAutomatic()) {
				Automatico_ConfiguraPID();
				currentState = AGUARDANDO_DESTINO;
			}
			// Adicionar novos modos de operação
			else
			break;
//		case (CONFIGURAR_SENSORES_DO_AUTONOMO):
//			Automatico_HabilitaSensores();
//			if (Automatico_IsCommandGoBack()) {
//				currentState = AGUARDANDO_MODO_DE_OPERACAO;
//				Automatico_DesabilitaSensores();
//			}
//			else if (Automatico_IsSensoresOk()) {
//
//				currentState = AGUARDANDO_DESTINO;
//			}
//			break;
		case (AGUARDANDO_DESTINO):
			if (Automatico_IsCommandGoBack()) {
				currentState = AGUARDANDO_MODO_DE_OPERACAO;
				Automatico_DesabilitaSensores();
			}
			else if (Automatico_IsCoordinatesOk() && !Automatico_IsOnDestination()){
				currentState = CONTROLE_PID;
			}
			break;
		case (CONTROLE_PID):
			if (Automatico_IsCommandGoBack()) {
				currentState = AGUARDANDO_MODO_DE_OPERACAO;
				Automatico_DesabilitaSensores();
			}
			else {
				Automatico_ControlePID();
			}
			break;
		case (DESVIA_OBJETO):
			if (Automatico_IsCommandGoBack()) {
				currentState = AGUARDANDO_MODO_DE_OPERACAO;
				Automatico_DesabilitaSensores();
			}
			break;
		}
	}

	return 0;
}
