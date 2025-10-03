# MICROCONTROLLER - MICROPROCESSOR  
## LABORATORY 2: LAB2_TIMER
## Source Folder Structure
The main code for each exercise is organized in the Core/Src/ directory as follows:
text
Core/
│
├── Src/                        # Main embedded source code
│   ├── ex1.c                   # Exercise 1 implementation
│   ├── ex2.c                   # Exercise 2 implementation
│   ├── ex3_4.c                 # Shared implementation for exercises 3 and 4
│   ├── ex5_6.c                 # Shared implementation for exercises 5 and 6
│   ├── ex7_8.c                 # Shared implementation for exercises 7 and 8
│   ├── ex9.c                   # Exercise 9 implementation
│   ├── ex10.c                  # Exercise 10 implementation
│   ├── software_timer.c        # Common software timer module
│   ├── display7SEG.c           # Common 7-segment display module
│   ├── main.c                  # Entry point, macro to select exercise
│   ├── stm32f1xx_hal_msp.c     # HAL MSP init
│   ├── stm32f1xx_it.c          # Interrupt handlers
│   ├── syscalls.c              # System call stubs
│   ├── sysmem.c                # System memory allocation
│   └── system_stm32f1xx.c      # System clock/config
│
├── Inc/                        # Header files for each exercise and main
│   ├── ex1.h
│   ├── ex2.h
│   ├── ex3_4.h                 # Shared header for exercises 3 and 4
│   ├── ex5_6.h                 # Shared header for exercises 5 and 6   
│   ├── ex7_8.h                 # Shared header for exercises 7 and 8
│   ├── ex9.h
│   ├── ex10.h
│   ├── software_timer.h        # Common software timer header
│   ├── display7SEG.h           # Common 7-segment display header
│   ├── main.h
│   ├── stm32f1xx_hal_conf.h
│   └── stm32f1xx_it.h
│
└── Startup/
    └── startup_stm32f103c6ux.s   # Startup assembly code
