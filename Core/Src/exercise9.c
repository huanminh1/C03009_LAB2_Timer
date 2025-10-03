/*
 * exercise9.c
 *
 *  Created on: Sep 17, 2025
 *      Author: admin
 */


#include "exercise9.h"


#define ENABLE 0
#define DISABLE	1

#define TIMER_LED_MATRIX 3
#define TIME_LED_MATRIX 60

#define ROW0_ON HAL_GPIO_WritePin(GPIOB, ROW0_Pin, ENABLE )
#define ROW1_ON HAL_GPIO_WritePin(GPIOB, ROW1_Pin, ENABLE )
#define ROW2_ON HAL_GPIO_WritePin(GPIOB, ROW2_Pin, ENABLE )
#define ROW3_ON HAL_GPIO_WritePin(GPIOB, ROW3_Pin, ENABLE )
#define ROW4_ON HAL_GPIO_WritePin(GPIOB, ROW4_Pin, ENABLE )
#define ROW5_ON HAL_GPIO_WritePin(GPIOB, ROW5_Pin, ENABLE )
#define ROW6_ON HAL_GPIO_WritePin(GPIOB, ROW6_Pin, ENABLE )
#define ROW7_ON HAL_GPIO_WritePin(GPIOB, ROW7_Pin, ENABLE )

#define ROW0_OFF HAL_GPIO_WritePin(GPIOB, ROW0_Pin, DISABLE)
#define ROW1_OFF HAL_GPIO_WritePin(GPIOB, ROW1_Pin, DISABLE)
#define ROW2_OFF HAL_GPIO_WritePin(GPIOB, ROW2_Pin, DISABLE)
#define ROW3_OFF HAL_GPIO_WritePin(GPIOB, ROW3_Pin, DISABLE)
#define ROW4_OFF HAL_GPIO_WritePin(GPIOB, ROW4_Pin, DISABLE)
#define ROW5_OFF HAL_GPIO_WritePin(GPIOB, ROW5_Pin, DISABLE)
#define ROW6_OFF HAL_GPIO_WritePin(GPIOB, ROW6_Pin, DISABLE)
#define ROW7_OFF HAL_GPIO_WritePin(GPIOB, ROW7_Pin, DISABLE)

// PORT_OF_ROW : GPIOB
uint16_t PIN_OF_ROW[8] = {
		ROW0_Pin,
		ROW1_Pin,
		ROW2_Pin,
		ROW3_Pin,
		ROW4_Pin,
		ROW5_Pin,
		ROW6_Pin,
		ROW7_Pin
};
// PORT_OF_COL : GPIOA
uint16_t PIN_OF_COL[8] = {
		ENM0_Pin,
		ENM1_Pin,
		ENM2_Pin,
		ENM3_Pin,
		ENM4_Pin,
		ENM5_Pin,
		ENM6_Pin,
		ENM7_Pin
};


const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;

uint8_t matrix_buffer[8] =
{
		0b00011000,
		0b00111100,
		0b01100110,
		0b01100110,
		0b01111110,
		0b01111110,
		0b01100110,
		0b01100110
};


void ex9_init(){
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

}

void ex9_run(){
	if (isFlag(TIMER_LED_MATRIX)){
			updateLEDMatrix(index_led_matrix);
			++index_led_matrix;

			if (index_led_matrix >= MAX_LED_MATRIX){
				index_led_matrix = 0;
			}

			setTimer(TIMER_LED_MATRIX, TIME_LED_MATRIX);
		}
}


void updateLEDMatrix(int index) {
    switch(index){
    	case 0:
			// Display the ROW0 with matrix_buffer[0]
			enableRow(0);
			displayRow(matrix_buffer[0]);
			break;
		case 1:
			// Display the ROW1 with matrix_buffer[1]
			enableRow(1);
			displayRow(matrix_buffer[1]);
			break;
		case 2:
			// Display the ROW2 with matrix_buffer[2]
			enableRow(2);
			displayRow(matrix_buffer[2]);
			break;
		case 3:
			// Display the ROW3 with matrix_buffer[3]
			enableRow(3);
			displayRow(matrix_buffer[3]);
			break;
		case 4:
			// Display the ROW4 with matrix_buffer[4]
			enableRow(4);
			displayRow(matrix_buffer[4]);
			break;
		case 5:
			// Display the ROW5 with matrix_buffer[5]
			enableRow(5);
			displayRow(matrix_buffer[5]);
			break;
		case 6:
			// Display the ROW6 with matrix_buffer[6]
			enableRow(6);
			displayRow(matrix_buffer[6]);
			break;
		case 7:
			// Display the ROW7 with matrix_buffer[7]
			enableRow(7);
			displayRow(matrix_buffer[7]);
			break;
		default:
			break;
    }
}

void displayRow(uint8_t buffer_data)
{
	uint8_t temp;
	for (int i = 0; i < 8; ++i){
		temp = buffer_data & 0b10000000;
		if (temp == 0b10000000){
			HAL_GPIO_WritePin(GPIOA, PIN_OF_COL[i], ENABLE);
		}

		if (temp == 0b00000000){
			HAL_GPIO_WritePin(GPIOA, PIN_OF_COL[i], DISABLE);
		}
		buffer_data = buffer_data << 1;
	}
}
void enableRow(int index){
	switch (index) {
			case 0:
				ROW0_ON;
				ROW1_OFF;
				ROW2_OFF;
				ROW3_OFF;
				ROW4_OFF;
				ROW5_OFF;
				ROW6_OFF;
				ROW7_OFF;
				break;
			case 1:
				ROW0_OFF;
				ROW1_ON;
				ROW2_OFF;
				ROW3_OFF;
				ROW4_OFF;
				ROW5_OFF;
				ROW6_OFF;
				ROW7_OFF;
				break;
			case 2:
				ROW0_OFF;
				ROW1_OFF;
				ROW2_ON;
				ROW3_OFF;
				ROW4_OFF;
				ROW5_OFF;
				ROW6_OFF;
				ROW7_OFF;
				break;
			case 3:
				ROW0_OFF;
				ROW1_OFF;
				ROW2_OFF;
				ROW3_ON;
				ROW4_OFF;
				ROW5_OFF;
				ROW6_OFF;
				ROW7_OFF;
				break;
			case 4:
				ROW0_OFF;
				ROW1_OFF;
				ROW2_OFF;
				ROW3_OFF;
				ROW4_ON;
				ROW5_OFF;
				ROW6_OFF;
				ROW7_OFF;
				break;
			case 5:
				ROW0_OFF;
				ROW1_OFF;
				ROW2_OFF;
				ROW3_OFF;
				ROW4_OFF;
				ROW5_ON;
				ROW6_OFF;
				ROW7_OFF;
				break;
			case 6:
				ROW0_OFF;
				ROW1_OFF;
				ROW2_OFF;
				ROW3_OFF;
				ROW4_OFF;
				ROW5_OFF;
				ROW6_ON;
				ROW7_OFF;
				break;
			case 7:
				ROW0_OFF;
				ROW1_OFF;
				ROW2_OFF;
				ROW3_OFF;
				ROW4_OFF;
				ROW5_OFF;
				ROW6_OFF;
				ROW7_ON;
				break;
			default:
				break;
		}
}
