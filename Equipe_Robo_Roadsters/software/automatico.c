/*
 * automatico.c
 *
 *  Created on: 15/11/2023
 *      Author: Bruno Camargo, Cícero Eduardo Dick Junior e Marcelo Zampieri Pereira da Silva
 */

# include "automatico.h"
# include <stdbool.h>

// Eventos
_Bool IsCommandAutomatic();
_Bool IsCommandGoBack();
_Bool IsCoordinatesOk();
_Bool IsOnDestination();
_Bool IsSensorsOk();
_Bool Obstacles();


// Tratamento de eventos
void Automatico_DesabilitaSensores(void);
void Automatico_HabilitaSensoresSensores(void);
void Automatico_ControlePID(void);
