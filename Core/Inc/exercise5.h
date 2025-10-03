/*
 * exercise5.h
 *
 *  Created on: Sep 17, 2025
 *      Author: admin
 */

#ifndef INC_EXERCISE5_H_
#define INC_EXERCISE5_H_

#include "main.h"
#include "software_timer.h"

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4] ;
extern int hour, minute,second;

void ex5_init();
void ex5_run();
void updateClockBuffer();
#endif /* INC_EXERCISE5_H_ */
