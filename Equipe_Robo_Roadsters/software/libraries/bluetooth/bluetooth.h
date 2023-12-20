/*
 * bluetooth.h
 *
 *  Created on: 09/12/2023
 *      Author: bruno
 */

#ifndef SOURCES_BLUETOOTH_H_
#define SOURCES_BLUETOOTH_H_

/*ARQUIVOS DE CABE�ALHO*/
/*=======================================================================================*/

#include "../../mcu/common.h"

/*FIM: ARQUIVOS DE CABE�ALHO*/
/*=======================================================================================*/

//Tamanho máximo do buffer. A quantidade máxima de dados que ele recebe é 2, as coordenadas x e y
#define	MAX_SIZE		2
//Pinos do HC05
#define UART_RX			2U
#define UART_TX			1U
// BR padrão do hc05
#define BAUD_RATE_HC05	9600U


/** Funcao : Bluetooth_Init
  *
  * Descricao : Inicia os pinos do HC05 e a pilha de da dados recebidos via UART.
  *
  * Entradas : Vazia
  *
  * Saidas : vazia
  *
  * Comentarios : Nenhum.
 */
void Bluetooth_Init(void);

/** Funcao : Bluetooth_Refresh
  *
  * Descricao : Atualiza o buffer se houver dados para receber.
  *
  * Entradas : Vazia
  *
  * Saidas : vazia
  *
  * Comentarios : Nenhum.
 */
_Bool Bluetooth_Refresh(void);

/** Funcao : Bluetooth_IsThereElement
  *
  * Descricao : Verifica se há elementos na pilha.
  *
  * Entradas : Vazia
  *
  * Saidas : 0 se não houver dados na pilha e !0 caso contrário
  *
  * Comentarios : Nenhum.
 */
_Bool Bluetooth_IsThereElement(void);

/** Funcao : Bluetooth_GetElement
  *
  * Descricao : Retorna o elemento atual da pilha.
  *
  * Entradas : Vazia
  *
  * Saidas : retorna o elemento atual da pilha
  *
  * Comentarios : Nenhum.
 */
uint8_t Bluetooth_GetElement(void);

/** Funcao : Bluetooth_Unstack
  *
  * Descricao : Desempilha um dado da pilha.
  *
  * Entradas : Vazia
  *
  * Saidas : Vazia
  *
  * Comentarios : Nenhum.
 */
void Bluetooth_Unstack(void);


#endif /* SOURCES_BLUETOOTH_H_ */
