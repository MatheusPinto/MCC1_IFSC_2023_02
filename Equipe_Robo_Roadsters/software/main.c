/*
 *  	Created on: 15/11/2023
 *      Author: Bruno Camargo, Cícero Eduardo Dick Junior e Marcelo Zampieri Pereira da Silva
 */

#include <MKL05Z4.h>
#include "automatico.h"
#include "system/system.h"

/*TIPOS ENUMERADOS*/
/*=======================================================================================*/

/* Possíveis estados da FSM */
typedef enum {
	AGUARDANDO_MODO_DE_OPERACAO = 0U,
	AGUARDANDO_DESTINO,
	CONTROLE_PID,
	DESVIA_OBJETO,
} estado_t;

/*FIM: TIPOS ENUMERADOS*/
/*=======================================================================================*/

static volatile estado_t g_currentState;





int main(void)
{
	System_Init();

	/* Estado inicial */
	g_currentState=AGUARDANDO_MODO_DE_OPERACAO;

	for (;;) {

		switch (g_currentState) {
		case (AGUARDANDO_MODO_DE_OPERACAO):
			if (Automatico_IsCommandAutomatic()) {
				Automatico_ConfiguraPID();
				g_currentState = AGUARDANDO_DESTINO;
			} else
				break;
		case (AGUARDANDO_DESTINO):
			if (Automatico_IsCommandGoBack()) {
				g_currentState = AGUARDANDO_MODO_DE_OPERACAO;
				//Automatico_DesabilitaSensores();
			} else if (Automatico_IsCoordinatesOk() /*&& !Automatico_IsOnDestination()*/) {
				g_currentState = CONTROLE_PID;
			}
			break;
		case (CONTROLE_PID):
			if (Automatico_IsCommandGoBack()) {
				g_currentState = AGUARDANDO_MODO_DE_OPERACAO;
				//Automatico_DesabilitaSensores();
			}
			else {
				//Automatico_ControlePID();
			}
			break;
		case (DESVIA_OBJETO):
			if (Automatico_IsCommandGoBack()) {
				g_currentState = AGUARDANDO_MODO_DE_OPERACAO;
				//Automatico_DesabilitaSensores();
			}
			break;
		}
	}

	return 0;
}
