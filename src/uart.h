/*
 * uart.h
 *
 *  Created on: Oct 19, 2017
 *      Author: otm
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f10x_usart.h"

void initUART(USART_InitTypeDef* USART_InitStructure);
void initUART_GPIO();
void USART_Tx(USART_TypeDef* USARTx, uint8_t Data);

#endif /* UART_H_ */
