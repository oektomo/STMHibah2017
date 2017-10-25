/*
 * platform_config.h
 *
 *  Created on: Oct 19, 2017
 *      Author: otm
 */

#ifndef PLATFORM_CONFIG_H_
#define PLATFORM_CONFIG_H_

  #define USARTrPi                   USART1
  #define USARTrPi_GPIO              GPIOA
  #define USARTrPi_CLK               RCC_APB2Periph_USART1
  #define USARTrPi_GPIO_CLK          RCC_APB2Periph_GPIOA
  #define USARTrPi_RxPin             GPIO_Pin_10
  #define USARTrPi_TxPin             GPIO_Pin_9
  #define USARTrPi_IRQn              USART1_IRQn
  #define USARTrPi_IRQHandler        USART1_IRQHandler

  #define USARTm8                   USART3
  #define USARTm8_GPIO              GPIOB
  #define USARTm8_CLK               RCC_APB1Periph_USART3
  #define USARTm8_GPIO_CLK          RCC_APB2Periph_GPIOB
  #define USARTm8_RxPin             GPIO_Pin_11
  #define USARTm8_TxPin             GPIO_Pin_10
  #define USARTm8_IRQn              USART3_IRQn
  #define USARTm8_IRQHandler        USART3_IRQHandler

  #define USARTdbg                   USART2
  #define USARTdbg_GPIO              GPIOA
  #define USARTdbg_CLK               RCC_APB1Periph_USART2
  #define USARTdbg_GPIO_CLK          RCC_APB2Periph_GPIOA
  #define USARTdbg_RxPin             GPIO_Pin_3
  #define USARTdbg_TxPin             GPIO_Pin_2
  #define USARTdbg_IRQn              USART2_IRQn
  #define USARTdbg_IRQHandler        USART2_IRQHandler

#endif /* PLATFORM_CONFIG_H_ */
