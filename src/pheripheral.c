/*
 * pheripheral.c
 *
 *  Created on: Oct 26, 2017
 *      Author: otm
 */

#include "platform_config.h"
#include "pheripheral.h"
#include "uart.h"

void initPheripheralInput(pheripheralInputTypedef* pheripheral)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(INPUT_PB_CLK_APB2 , ENABLE);
	RCC_APB2PeriphClockCmd(INPUT_PA_CLK_APB2 , ENABLE);
	RCC_APB2PeriphClockCmd(INPUT_PC_CLK_APB2 , ENABLE);

	  pheripheral[1].pinuC = INPUT_PH1_PIN;
	  pheripheral[1].portuC = INPUT_PH1_PORT;
	  pheripheral[2].pinuC = INPUT_PH2_PIN;
	  pheripheral[2].portuC = INPUT_PH2_PORT;
	  pheripheral[3].pinuC = INPUT_PH3_PIN;
	  pheripheral[3].portuC = INPUT_PH3_PORT;
	  pheripheral[4].pinuC = INPUT_PH4_PIN;
	  pheripheral[4].portuC = INPUT_PH4_PORT;
	  pheripheral[5].pinuC = INPUT_PH5_PIN;
	  pheripheral[5].portuC = INPUT_PH5_PORT;
	  pheripheral[6].pinuC = INPUT_PH6_PIN;
	  pheripheral[6].portuC = INPUT_PH6_PORT;
	  pheripheral[7].pinuC = INPUT_PH7_PIN;
	  pheripheral[7].portuC = INPUT_PH7_PORT;
	  pheripheral[8].pinuC = INPUT_PH8_PIN;
	  pheripheral[8].portuC = INPUT_PH8_PORT;
	  pheripheral[9].pinuC = INPUT_PH9_PIN;
	  pheripheral[9].portuC = INPUT_PH9_PORT;
	  pheripheral[10].pinuC = INPUT_PH10_PIN;
	  pheripheral[10].portuC = INPUT_PH10_PORT;
	  pheripheral[11].pinuC = INPUT_PH11_PIN;
	  pheripheral[11].portuC = INPUT_PH11_PORT;
	  pheripheral[12].pinuC = INPUT_PH12_PIN;
	  pheripheral[12].portuC = INPUT_PH12_PORT;

#define PHERIPH_INIT_LOOP
#ifdef PHERIPH_INIT_LOOP
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;

	  /* Configure INPUT_PH1_PIN to INPUT_PH12_PIN as in floating */
	  for(uint8_t i = 1; i < PHERIPHERAL_AMOUNT; i++) {
		  GPIO_InitStructure.GPIO_Pin = pheripheral[i].pinuC;
		  GPIO_Init(pheripheral[i].portuC, &GPIO_InitStructure);
	  }
#else

	  /* Configure INPUT_PH1_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = pheripheral[1].pinuC;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	  GPIO_Init(INPUT_PH1_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH2_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH2_PIN;
	  GPIO_Init(INPUT_PH2_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH3_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH3_PIN;
	  GPIO_Init(INPUT_PH3_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH4_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH4_PIN;
	  GPIO_Init(INPUT_PH4_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH5_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH5_PIN;
	  GPIO_Init(INPUT_PH5_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH6_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH6_PIN;
	  GPIO_Init(INPUT_PH6_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH7_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH7_PIN;
	  GPIO_Init(INPUT_PH7_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH8_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH8_PIN;
	  GPIO_Init(INPUT_PH8_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH9_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH9_PIN;
	  GPIO_Init(INPUT_PH9_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH10_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH10_PIN;
	  GPIO_Init(INPUT_PH10_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH11_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH11_PIN;
	  GPIO_Init(INPUT_PH11_PORT, &GPIO_InitStructure);

	  /* Configure INPUT_PH12_PIN as in floating */
	  GPIO_InitStructure.GPIO_Pin = INPUT_PH12_PIN;
	  GPIO_Init(INPUT_PH12_PORT, &GPIO_InitStructure);
#endif
	  for (uint8_t i = 1; i < PHERIPHERAL_AMOUNT; i++) {
		  pheripheral[i].pin = i;
	  }
}

void readAllPheripheral(pheripheralInputTypedef* pheripheral)
{
	//uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)

	//pheripheral[0].state = GPIO_ReadInputDataBit(pheripheral[0].portuC, pheripheral[0].pinuC);

	for (uint8_t i = 1; i < PHERIPHERAL_AMOUNT; i++) {
		pheripheral[i].state = GPIO_ReadInputDataBit(pheripheral[i].portuC, pheripheral[i].pinuC);
	}
}

void printPheripheralState(pheripheralInputTypedef* pheripheral)
{

	for (uint8_t i = 1; i < PHERIPHERAL_AMOUNT; i++) {
		uart_printf("Pheripheral %u state %u\n\r",
				pheripheral[i].pin, pheripheral[i].state );
	}


}
