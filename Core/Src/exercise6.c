/*
 * exercise6.c
 *
 *  Created on: Sep 17, 2025
 *      Author: admin
 */


#include <exercise6.h>

#define TIMER_LED_BLINKING 0
#define	TIME_LED_BLINKING 10

void ex6_init(){
//	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	setTimer(TIMER_LED_BLINKING, TIME_LED_BLINKING);
}

void ex6_run(){
	if(isFlag(TIMER_LED_BLINKING)){
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		setTimer(TIMER_LED_BLINKING,TIME_LED_BLINKING);
	}

}
