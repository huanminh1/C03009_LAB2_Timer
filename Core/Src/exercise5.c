/*
 * exercise5.c
 *
 *  Created on: Sep 17, 2025
 *      Author: admin
 */


#include "exercise1.h" // using display7SEG and enable_seg
#include "exercise3.h" // using ex3_init and update7SEG
#include "exercise5.h"

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG	1

#define TIMER_7SEG 0
#define TIME_7SEG 250

#define TIMER_LED_BLINKING 1
#define	TIME_LED_BLINKING 1000

#define TIMER_TWO_LEDS_BLINKING 2
#define TIME_TWO_LEDS_BLINKING 1000


/**
  * @brief Use for testing all GPIOs necessary
  */
void ex5_init(){
	ex3_init();
	updateClockBuffer();
}

/**
  * @brief Use for display 4 integer numbers of an array in fourth 7 SEG
  */

int hour = 23, minute = 59, second = 55;
void ex5_run(){

	if(isFlag(TIMER_7SEG)){
		update7SEG(index_led++);

		if(index_led >= MAX_LED){
			index_led = 0;
		}
		setTimer(TIMER_7SEG, TIME_7SEG);
	}


	//LED Blinking
	if(isFlag(TIMER_LED_BLINKING)){
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		setTimer(TIMER_LED_BLINKING, TIME_LED_BLINKING);
	}

	//Two LEDS Blinking

	if(isFlag(TIMER_TWO_LEDS_BLINKING)){
		second++;
		if(second >= 60){
			second = 0;
			minute++;
		}
		if(minute >= 60){
			minute = 0;
			hour++;
		}
		if(hour >= 24){
			hour = 0;
		}
		updateClockBuffer();

		HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
		setTimer(TIMER_TWO_LEDS_BLINKING, TIME_TWO_LEDS_BLINKING);
	}


}

void updateClockBuffer(){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}
