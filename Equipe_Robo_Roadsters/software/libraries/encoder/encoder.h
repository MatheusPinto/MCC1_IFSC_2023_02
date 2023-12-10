/*
 * encoder.h
 *
 *  Created on: 03/12/2023
 *      Author: junin
 */

#ifndef SOURCES_ENCODER_H_
#define SOURCES_ENCODER_H_

#include "../../mcu/common.h"

void ENCODER_Init(void);

uint16_t ENCODER_get_d0(void);

uint16_t ENCODER_get_d1(void);

void PORTA_IRQHandler(void);

void PORTB_IRQHandler(void);

#endif /* SOURCES_ENCODER_H_ */
