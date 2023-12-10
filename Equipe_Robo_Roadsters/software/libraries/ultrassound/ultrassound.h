/*
 * ultrassom.h
 *
 *  Created on: 04/12/2023
 *      Author: bruno
 */

#ifndef SOURCES_ULTRASSOUND_H_
#define SOURCES_ULTRASSOUND_H_

/*ARQUIVOS DE CABE�ALHO*/
/*=======================================================================================*/

#include "../../mcu/common.h"

/*FIM: ARQUIVOS DE CABE�ALHO*/
/*=======================================================================================*/

#define MAX_TIME_ECHO	38		// Tempo máximo de espera do echo, em ms
#define	ECHO0			8U
#define ECHO1			2U
#define TRIG0			7U
#define TRIG1			4U
#define	LOW				0U
#define	HIGH			1U

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
void Ultrassound_Init(uint8_t trigPin, uint8_t echoPin);

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
void Ultrassound_InitRadar(void);



#endif /* SOURCES_ULTRASSOUND_H_ */
