/*
 * exercise2.c
 *
 *  Created LED_ON: Sep 15, 2025
 *      Author: Huan Minh
 */

#include "exercise2.h"
#include "exercise1.h" // using display7SEG and enable_seg
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

typedef enum{
	INIT,
	LED1,
	LED2,
	LED3,
	LED4
}LedState;

LedState ledState_ex2 = INIT;
/**
  * @brief Use for testing all GPIOs necessary
  */
void ex2_init(){
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

//	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_LED_BLINKING,TIME_LED_BLINKING);
	setTimer(TIMER_TWO_LEDS_BLINKING, TIME_TWO_LEDS_BLINKING);

}

void ex2_run(){
	switch(ledState_ex2){
		case INIT:
			ledState_ex2 = LED1;
			setTimer(TIMER_7SEG, TIME_7SEG);
			break;

		case LED1:
			display7SEG(1);
			enable_seg(0);

			if(isFlag(TIMER_7SEG)){
				ledState_ex2 = LED2;
				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED2:
			display7SEG(2);
			enable_seg(1);

			if(isFlag(TIMER_7SEG)){
				ledState_ex2 = LED3;
				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED3:
			display7SEG(3);
			enable_seg(2);

			if(isFlag(TIMER_7SEG)){
				ledState_ex2 = LED4;
				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED4:
				display7SEG(0);
				enable_seg(3);

				if(isFlag(TIMER_7SEG)){
					ledState_ex2 = LED1;
					setTimer(TIMER_7SEG, TIME_7SEG);
				}
				break;
		default:
			break;
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


