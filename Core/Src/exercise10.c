/*
 * exercise10.c
 *
 *  Created on: Sep 26, 2025
 *      Author: admin
 */
#include "exercise10.h"
#include "exercise9.h"


#define TIMER_LED_MATRIX 3
#define TIME_LED_MATRIX 50

#define TIMER_ANIMATION 4
#define TIME_ANIMATION 800

extern const int MAX_LED_MATRIX;
extern int index_led_matrix;
extern uint8_t matrix_buffer[8];

void ex10_init(){
	HAL_GPIO_TogglePin(GPIOA, ENM0_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM1_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM2_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM3_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM4_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM5_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM6_Pin);
	HAL_GPIO_TogglePin(GPIOA, ENM7_Pin);

	HAL_GPIO_TogglePin(GPIOB, ROW0_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW1_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW2_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW3_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW4_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW5_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW6_Pin);
	HAL_GPIO_TogglePin(GPIOB, ROW7_Pin);

	setTimer(TIMER_LED_MATRIX, TIME_LED_MATRIX);
	setTimer(TIMER_ANIMATION, TIME_ANIMATION);
}

void ex10_run(){
    if (isFlag(TIMER_LED_MATRIX)){
        updateLEDMatrix(index_led_matrix);
        ++index_led_matrix;
        if (index_led_matrix >= MAX_LED_MATRIX){
            index_led_matrix = 0;
        }
        setTimer(TIMER_LED_MATRIX, TIME_LED_MATRIX);
    }

    if (isFlag(TIMER_ANIMATION)) {
        shiftMatrixLeft();
        setTimer(TIMER_ANIMATION, TIME_ANIMATION);
    }
}

void shiftMatrixLeft() {
	for (int i = 0; i < MAX_LED_MATRIX; ++i){
		matrix_buffer[i] = (matrix_buffer[i] << 1) | (matrix_buffer[i] >> 7);
	}
}
