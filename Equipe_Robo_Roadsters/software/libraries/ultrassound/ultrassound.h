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

/*INICIO: DEFINES*/
/*=======================================================================================*/

#define MAX_TIME_ECHO	38		// Tempo máximo de espera do echo, em ms
#define	ECHO0			1U
#define ECHO1			11U
#define TRIG0			8U
#define TRIG1			10U
#define	LOW				0U
#define	HIGH			1U

/*FIM: DEFINES*/
/*=======================================================================================*/


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
void Ultrassound_FinishRadar(void);

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
uint8_t Ultrassound_Measure(void);

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
uint8_t Ultrassom_EchoTime(void);



#endif /* SOURCES_ULTRASSOUND_H_ */
