/*
 * uart.c
 *
 *  Created on: Oct 19, 2017
 *      Author: otm
 */

#include "platform_config.h"
#include "uart.h"

/*
 * to initialize our UART we need 3 things
 * RCC UART
 * UART configuration
 *
 * RCC GPIO
 * GPIO AF configuration
 */
void initUART(USART_InitTypeDef* USART_InitStructure)
{


	  /* Enable USARTy Clock */
	  RCC_APB1PeriphClockCmd(USARTrPi_CLK, ENABLE);

	  USART_InitStructure->USART_BaudRate = 9600;
	  USART_InitStructure->USART_WordLength = USART_WordLength_8b;
	  USART_InitStructure->USART_StopBits = USART_StopBits_1;
	  USART_InitStructure->USART_Parity = USART_Parity_No;
	  USART_InitStructure->USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	  USART_InitStructure->USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

}

void initUART_GPIO(uint32_t RCC_APB2Periph)
{
	  /* Enable GPIO UART clock */
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph , ENABLE);
}
