/*
 * exercise3.c
 *
 *  Created on: Sep 17, 2025
 *      Author: admin
 */

#include "exercise1.h" // using display7SEG and enable_seg
#include "exercise3.h"

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG	1

#define TIMER_7SEG 0
#define TIME_7SEG 500

#define TIMER_LED_BLINKING 1
#define	TIME_LED_BLINKING 1000

#define TIMER_TWO_LEDS_BLINKING 2
#define TIME_TWO_LEDS_BLINKING 1000


const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {6,7,8,9};
/**
  * @brief Use for testing all GPIOs necessary
  */

void ex3_init(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	HAL_GPIO_TogglePin(GPIOA, EN0_Pin);
	HAL_GPIO_TogglePin(GPIOA, EN1_Pin);
	HAL_GPIO_TogglePin(GPIOA, EN2_Pin);
	HAL_GPIO_TogglePin(GPIOA, EN3_Pin);

	HAL_GPIO_TogglePin(GPIOB, SEG0_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG2_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG3_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG5_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG6_Pin);

	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_LED_BLINKING,TIME_LED_BLINKING);
	setTimer(TIMER_TWO_LEDS_BLINKING, TIME_TWO_LEDS_BLINKING);
}

/**
  * @brief Use for display 4 integer numbers of an array in fourth 7 SEG
  */



void ex3_run(){
	update7SEG(index_led);
	if(isFlag(TIMER_7SEG)){
		index_led++;

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
		HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
		setTimer(TIMER_TWO_LEDS_BLINKING, TIME_TWO_LEDS_BLINKING);
	}
}

void update7SEG(int index){
	switch(index){
		case 0:
			display7SEG(led_buffer[0]);
			enable_seg(0);
			break;
		case 1:
			display7SEG(led_buffer[1]);
			enable_seg(1);
			break;
		case 2:
			display7SEG(led_buffer[2]);
			enable_seg(2);
			break;
		case 3:
			display7SEG(led_buffer[3]);
			enable_seg(3);
			break;
		default:
			break;
	}
}

