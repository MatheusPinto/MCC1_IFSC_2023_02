/*
 * software_init.c
 *
 *  Created on: 13/06/2023
 *      Author: mathe
 */

#include "software_init.h"

void System_Software_Init( void )
{
	// Inicialização dos pinos de TX e RX
	PORT_Init(PORTB);
	PORT_SetMux( PORTB, UART_TX, PORT_MUX_ALT2 );
	PORT_SetMux( PORTB, UART_RX, PORT_MUX_ALT2 );

	UART_SetClkSrc( UART0, UART_CLOCK_FLL ); // Setando o clk src do módulo UART(memso clk src do PWM)
	UART_Init( UART0, BAUD_RATE_HC05, UART_TX_RX_ENABLE, UART_NO_PARITY, UART_ONE_STOP_BIT );
}


