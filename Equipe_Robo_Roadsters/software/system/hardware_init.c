/*
 * hardware_init.c
 *
 *  Created on: 13/06/2023
 *      Author: mathe
 */

#include "../libraries/ultrassound/ultrassound.h"
#include "hardware_init.h"
#include "../mcu/drivers/port/port.h"
#include "../libraries/bluetooth/bluetooth.h"

void System_Hardware_Init( void )
{
	Bluetooth_Init();
	Ultrassound_Init(TRIG1, ECHO1);
	Ultrassound_InitRadar();
}

