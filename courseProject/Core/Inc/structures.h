/*
 * structures.h
 *
 *  Created on: Dec 8, 2023
 *      Author: 38097
 */

#ifndef INC_STRUCTURES_H_
#define INC_STRUCTURES_H_

struct Measurements {
	float temperature;
	float humidity;
} measurements = {0.0, 0.0};

struct State {
	uint8_t timesClicked;
} buttonState = {0};

typedef struct Mesure {
	float avg;
	float max;
	float min;
	float sum;
} Mesure;

#endif /* INC_STRUCTURES_H_ */
