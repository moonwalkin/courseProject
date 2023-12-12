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

typedef enum {
	currentMeasurements,
	maxMeasurements,
	minMeasurements,
	avgMeasurements,
} mode;

#endif /* INC_STRUCTURES_H_ */
