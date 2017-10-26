/*
 * pheripheral.h
 *
 *  Created on: Oct 26, 2017
 *      Author: otm
 */

#ifndef PHERIPHERAL_H_
#define PHERIPHERAL_H_

#define PHERIPHERAL_ON	1
#define PHERIPHERAL_OFF	0
#define PHERIPHERAL_AMOUNT 13

typedef struct pheripheralInputTypedef {
	GPIO_TypeDef* portuC;
	uint8_t pinuC;
	uint8_t pin;
	uint8_t state;
} pheripheralInputTypedef;

void initPheripheralInput(pheripheralInputTypedef* pheripheral);
void readAllPheripheral(pheripheralInputTypedef* pheripheral);
void printPheripheralState(pheripheralInputTypedef* pheripheral);

#endif /* PHERIPHERAL_H_ */
