# MICROCONTROLLER - MICROPROCESSOR  
## LABORATORY 2: LAB2_TIMER

## 1. Schematic
The code was simulated in **Proteus 8.10** using STM32F103C6. Here are the simulation of all 10 exercises.

![Proteus Simulation](https://github.com/huanminh1/C03009_LAB2_Timer/blob/main/Images/FULL_EXERCISE.png?raw=true)

## 2. How to Run the Code
Each exercise is implemented in separate `.c` and `.h` files under `./Core/Src/` and `./Core/Inc/`. There are 2 ways to run the Code:

### 2.1. Clone this Project and Run:
If you clone this project to your local device, you only need to change `RUN_EXERCISE` in `./Core/Src/main.c` to the exercise number you want to run (from `1` to `10`).
```c
#define RUN_EXERCISE 10
```
### 2.2. Run Specific Exercise
1. Ensure that all hardware connections are correct as the Proteus schematic images.
2. Download the header and source files for the specific exercise you want to run, place them in the appropriate directories, and include the header in `./Core/Src/main.c` as follows:
```c
#include "exercise10.h"
```
3. Each exercises has two main functions: `exercise-_init()` ensure all necessary pins are available; and `exercise-_run()` to execute the exercise requirements.
4. Run the code. You should palce `exercise-_init()` in between:
```c
/* USER CODE BEGIN 2 */
// TODO
/* USER CODE END 2 */
```
You should place `exercise-_run()` functions within the `while` loop in the `main()` function.
```c
/* USER CODE BEGIN WHILE */
  while (1)
{
// TODO
/* USER CODE END WHILE */

/* USER CODE BEGIN 3 */
}
```
## 3. Source Folder Structure
The main code for each exercise is organized in the Core/Src/ directory as follows:
```text
Core/
│
├── Src/                        # Main embedded source code
│   ├── exercise1.c             # Exercise 1 implementation
│   ├── exercise2.c             # Exercise 2 implementation
│   ├── exercise3.c             # Exercise 3 implementation
│   ├── exercise4.c             # Exercise 4 implementation
│   ├── exercise5.c             # Exercise 5 implementation
│   ├── exercise6.c             # Exercise 6 implementation
│   ├── exercise7.c             # Exercise 7 implementation
│   ├── exercise8.c             # Exercise 8 implementation
│   ├── exercise9.c             # Exercise 9 implementation
│   ├── exercise10.c            # Exercise 10 implementation
│   ├── software_timer.c        # Common software timer module
│   ├── main.c                  # Entry point, macro to select exercise
│   ├── stm32f1xx_hal_msp.c     # HAL MSP init
│   ├── stm32f1xx_it.c          # Interrupt handlers
│   ├── syscalls.c              # System call stubs
│   ├── sysmem.c                # System memory allocation
│   └── system_stm32f1xx.c      # System clock/config
│
├── Inc/                        # Header files for each exercise and main
│   ├── exercise1.h
│   ├── exercise2.h
│   ├── exercise3.h
│   ├── exercise4.h
│   ├── exercise5.h
│   ├── exercise6.h
│   ├── exercise7.h
│   ├── exercise8.h
│   ├── exercise9.h
│   ├── exercise10.h
│   ├── software_timer.h        # Common software timer header
│   ├── main.h
│   ├── stm32f1xx_hal_conf.h
│   └── stm32f1xx_it.h
│
└── Startup/
    └── startup_stm32f103c6ux.s   # Startup assembly code
```
## 4. NOTE
1. Ensure correct clock configuration in STM32CubeIDE before building.
2. The .gitignore is set up to exclude build outputs and temporary files, so only source code and important project files remain in the repository.
