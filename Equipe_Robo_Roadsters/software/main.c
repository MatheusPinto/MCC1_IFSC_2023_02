/*
 * automatico.c
 *
 *  Created on: 15/11/2023
 *      Author: Bruno Camargo, Cícero Eduardo Dick Junior e Marcelo Zampieri Pereira da Silva
 */



#include <MKL05Z4.h>
#include <system/system.h>
#include "automatico.h"


// ver com o professor sobre o uso de static no caso de utilização de IRQs para alterar estados
static volatile estado_t currentState;

int main(void)
{
	System_Init();

	for (;;) {

		switch (currentState) {
		case (AGUARDANDO_MODO_DE_OPERACAO):
			if (Automatico_IsCommandAutomatic()) {
				currentState = CONFIGURAR_SENSORES_DO_AUTONOMO;
			}
			// Adicionar novos modos de operação
			else
			break;
		case (CONFIGURAR_SENSORES_DO_AUTONOMO):
			Automatico_HabilitaSensores();
			if (Automatico_IsCommandGoBack()) {
				currentState = AGUARDANDO_MODO_DE_OPERACAO;
				Automatico_DesabilitaSensores();
			}
			else if (Automatico_IsSensoresOk()) {
				currentState = AGUARDANDO_DESTINO;
			}
			break;
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
