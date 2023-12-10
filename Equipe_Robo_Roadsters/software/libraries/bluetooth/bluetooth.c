/*
 * bluetooth.c
 *
 *  Created on: 09/12/2023
 *      Author: bruno
 */

#include "bluetooth.h"
#include "../../mcu/drivers/port/port.h"
#include "../../mcu/drivers/uart/uart.h"

// buffer genérico para receber números e letras
static volatile uint8_t g_genericBuffer[MAX_SIZE];
static volatile uint8_t g_element;



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
void Bluetooth_Init(void){

	PORT_Init(PORTB);
	// Inicialização dos pinos de TX e RX
	PORT_SetMux( PORTB, UART_TX, PORT_MUX_ALT2 );
	PORT_SetMux( PORTB, UART_RX, PORT_MUX_ALT2 );

	// Inicializando o módulo UART
	UART_SetClkSrc( UART0, UART_CLOCK_FLL ); // Setando o clk src do módulo UART(memso clk src do PWM)
	UART_Init( UART0, BAUD_RATE_HC05, UART_TX_RX_ENABLE, UART_NO_PARITY, UART_ONE_STOP_BIT );

	// iniciando o buffer genérico de dados
	g_element=0U;
}

/** Funcao : Bluetooth_Refresh
  *
  * Descricao : Atualiza o buffer se houver dados para receber.
  *
  * Entradas : Vazia
  *
  * Saidas : 0 não houve atualização e !0 caso contrário
  *
  * Comentarios : Nenhum.
 */
_Bool Bluetooth_Refresh(void){
	uint8_t debugger;
	debugger = UART_IsRxAvailable(UART0);
	if (debugger){
		g_genericBuffer[g_element]=UART_Read(UART0);
		g_element++;
		return true;
	}
	return false;
}

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
_Bool Bluetooth_IsThereElement(void){
	//Atualiza a pilha
	Bluetooth_Refresh();

	if (g_element==0U) return false;
	else return true;
}

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
uint8_t Bluetooth_GetElement(void){
	return g_genericBuffer[g_element];
}

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
void Bluetooth_Unstack(void){
	g_element--;
}





