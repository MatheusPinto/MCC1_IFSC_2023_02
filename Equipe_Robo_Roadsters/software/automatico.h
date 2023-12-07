/*
 * automatico.h
 *
 *  Created on: 15/11/2023
 *      Author: Bruno Camargo, Cícero Eduardo Dick Junior e Marcelo Zampieri Pereira da Silva
 */

#ifndef SOURCES_AUTOMATICO_H_
#define SOURCES_AUTOMATICO_H_

#define TRUE 	1
#define FALSE 	0

/*PROTOTIPOS - FUNCOES PUBLICAS*/
/*=======================================================================================*/

/*EVENTOS DA FSM*/
/*=======================================================================================*/

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
_Bool Automatico_IsComandAutomatic(void);

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
_Bool Automatico_IsCommandGoBack(void);

/** Funcao : Automatico_IsCoordinatesOk
  *
  * Descricao : Verifica se coordenadas reais foram passadas.
  *
  * Entradas : Vazia
  *
  * Saidas : 0 se o comando nao foi passado e !0 caso contrário.
  *
  * Comentarios : Nenhum.
 */
_Bool Automatico_IsCoordinatesOk(void);

/** Funcao : Automatico_IsOnDestination
  *
  * Descricao : Verifica se já chegou nas coordenadas passadas.
  *
  * Entradas : Vazia
  *
  * Saidas : 0 se não chegou no destino e !0 caso contrário.
  *
  * Comentarios : Nenhum.
 */
_Bool Automatico_IsOnDestination(void);

/** Funcao : Automatico_IsSensorsOk
  *
  * Descricao : Verifica se os sensores estão configurados.
  *
  * Entradas : Vazia
  *
  * Saidas : 0 se os sensores estão ok e !0 caso contrário.
  *
  * Comentarios : Nenhum.
 */
_Bool Automatico_IsSensorsOk(void);

/** Funcao : Automatico_Obstacles
  *
  * Descricao : Verifica se há obstáculos via ultrassom.
  *
  * Entradas : Vazia
  *
  * Saidas : 0 se não houver obstáculos e !0 caso contrário.
  *
  * Comentarios : Nenhum.
 */
_Bool Automatico_Obstacles(void);

/*FIM EVENTOS DA FSM*/
/*=======================================================================================*/

/*TRATAMENTO DE EVENTOS DA FSM*/
/*=======================================================================================*/

/** Funcao : Automatico_DesabilitaSensores
  *
  * Descricao : Desabilita sensores do modo automático.
  *
  * Entradas : Vazia
  *
  * Saidas : Vazia.
  *
  * Comentarios : Nenhum.
 */
void Automatico_DesabilitaSensores(void);

/** Funcao : Automatico_HabilitaSensores
  *
  * Descricao : Habilita sensores do modo automático.
  *
  * Entradas : Vazia
  *
  * Saidas : Vazia.
  *
  * Comentarios : Nenhum.
 */
void Automatico_ConfiguraPID(void);

/** Funcao : Automatico_ControlePID
  *
  * Descricao : Faz o controle PID do robô.
  *
  * Entradas : Vazia
  *
  * Saidas : Vazia.
  *
  * Comentarios : Nenhum.
 */
void Automatico_ControlePID(void);

/*FIM TRATAMENTO DE EVENTOS DA FSM*/
/*=======================================================================================*/

/*FIM PROTOTIPOS - FUNCOES PUBLICAS*/
/*=======================================================================================*/

#endif /* SOURCES_AUTOMATICO_H_ */
