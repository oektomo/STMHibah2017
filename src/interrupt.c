/*
 * interrupt.c
 *
 *  Created on: Oct 28, 2017
 *      Author: otm2
 */

#include "interrupt.h"
#include "uart.h"
#include "platform_config.h"

//extern uint8_t RxBuffer;

void
NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

void
USART1_IRQHandler(void)
{
	// check if Receive Data Register not empty
	if( USART_GetITStatus(USARTrPi, USART_IT_RXNE) ) {
		uint8_t RxBuffer = USART_ReceiveData(USARTrPi);
		RxBuffer++;
		USART_Tx(USARTrPi, RxBuffer);

	}
}

