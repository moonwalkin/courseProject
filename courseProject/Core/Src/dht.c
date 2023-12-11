/*
 * dht.c
 *
 *  Created on: Dec 12, 2023
 *      Author: 38097
 */
#include "dht.h"

uint8_t read() {
	uint8_t result;
	for(uint8_t i = 0; i < 8; i++) {
		pMillis = HAL_GetTick();
		cMillis = HAL_GetTick();
		while(!(HAL_GPIO_ReadPin (GPIOC, DTH22_Pin)) && pMillis + 2 > cMillis) {
			cMillis = HAL_GetTick();
		}
		microDelay(40);
		if (!(HAL_GPIO_ReadPin(GPIOC, DTH22_Pin)))
			result&= ~(1 << (7 - i));
		else
			result|= (1 << (7 - i));
		pMillis = HAL_GetTick();
		cMillis = HAL_GetTick();
		while((HAL_GPIO_ReadPin(GPIOC, DTH22_Pin)) && pMillis + 2 > cMillis) {
		  cMillis = HAL_GetTick();
		}
	}
	return result;
}

uint8_t start() {
	uint8_t Response = 0;
	GPIO_InitTypeDef GPIO_InitStructPrivate = {0};
	GPIO_InitStructPrivate.Pin = DTH22_Pin;
	GPIO_InitStructPrivate.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructPrivate.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStructPrivate.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructPrivate);
	HAL_GPIO_WritePin (GPIOC, DTH22_Pin, 0);
	microDelay (1300);
	HAL_GPIO_WritePin (GPIOC, DTH22_Pin, 1);
	microDelay (30);
	GPIO_InitStructPrivate.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructPrivate.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructPrivate);
	microDelay (40);
	if(!(HAL_GPIO_ReadPin (GPIOC, DTH22_Pin))) {
		microDelay (80);
    if ((HAL_GPIO_ReadPin (GPIOC, DTH22_Pin))) Response = 1;
	}
	pMillis = HAL_GetTick();
	cMillis = HAL_GetTick();
	while((HAL_GPIO_ReadPin(GPIOC, DTH22_Pin)) && pMillis + 2 > cMillis) {
		cMillis = HAL_GetTick();
	}
	return Response;
}

