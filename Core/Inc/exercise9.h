/*
 * exercise9.h
 *
 *  Created on: Sep 17, 2025
 *      Author: admin
 */

#ifndef INC_EXERCISE9_H_
#define INC_EXERCISE9_H_

#include "main.h"
#include "software_timer.h"

void enableRow(int index);
void updateLEDMatrix(int index);
void displayRow(uint8_t buffer_data);
void ex9_init();
void ex9_run();

#endif /* INC_EXERCISE9_H_ */
