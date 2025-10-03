/*
 * exercise1.c
 *
 *  Created LED_ON: Sep 15, 2025
 *      Author: Huan Minh
 */

#include "exercise1.h"

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG	1

#define TIMER_7SEG 0
#define TIME_7SEG 500

#define TIMER_LED_BLINKING 1
#define	TIME_LED_BLINKING 1000

typedef enum{
	INIT,
	LED1,
	LED2
}LedState;

LedState ledState_ex1 = INIT;
/**
  * @brief Use for testing all GPIOs necessary
  */
void ex1_init(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	HAL_GPIO_TogglePin(GPIOA, EN0_Pin);
	HAL_GPIO_TogglePin(GPIOA, EN1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG0_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG1_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG2_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG3_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG4_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG5_Pin);
	HAL_GPIO_TogglePin(GPIOB, SEG6_Pin);

//	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_LED_BLINKING,TIME_LED_BLINKING);

}

void ex1_run(){
	switch(ledState_ex1){
		case INIT:
			ledState_ex1 = LED1;
			setTimer(TIMER_7SEG, TIME_7SEG);
			break;

		case LED1:
			display7SEG(1);
			enable_seg(0);

			if(isFlag(TIMER_7SEG)){
				ledState_ex1 = LED2;
				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED2:
			display7SEG(2);
			enable_seg(1);

			if(isFlag(TIMER_7SEG)){
				ledState_ex1 = LED1;
				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		default:
			break;
	}

	if(isFlag(TIMER_LED_BLINKING)){
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		setTimer(TIMER_LED_BLINKING, TIME_LED_BLINKING);
	}
}

void display7SEG (int num){
	switch(num) {
	    case 0:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_OFF);
	        break;

	    case 1:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_OFF);
	        break;

	    case 2:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_ON);
	        break;

	    case 3:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_ON);
	        break;

	    case 4:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_ON);
	        break;

	    case 5:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_ON);
	        break;

	    case 6:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_ON);
	        break;

	    case 7:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_OFF);
	        break;

	    case 8:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_ON);
	        break;

	    case 9:
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_ON);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_ON);
	        break;

	    default:
	        // Tắt hết
	        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, LED_OFF);
	        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, LED_OFF);
	        break;
	}
}

void enable_seg(int num){
	switch(num){
		case 0:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, DISABLE_SEG);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, DISABLE_SEG);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, DISABLE_SEG);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, ENABLE_SEG);
			break;
		default:
			break;

	}
}


