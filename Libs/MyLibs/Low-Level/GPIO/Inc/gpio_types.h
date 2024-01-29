#include "stm32l4xx.h" 
#include "stm32l431xx.h"

// ERROR TYPE
typedef enum {  
    // ERR2 = -2, 
    // ERR1 = -1, 
    OK = 0, 
    ERR1, 
    ERR2, 
    ERR3 
}error_t;

// CLOCK BITS 
typedef enum { 
GPIOAEN = RCC_AHB2ENR_GPIOAEN,
GPIOBEN = RCC_AHB2ENR_GPIOBEN, 
GPIOCEN = RCC_AHB2ENR_GPIOCEN, 
GPIODEN = RCC_AHB2ENR_GPIODEN,
GPIOEEN = RCC_AHB2ENR_GPIOEEN, 
GPIOHEN = RCC_AHB2ENR_GPIOHEN   
} gpio_rcc_pin_t;

// PIN 
typedef enum { 
    PIN0  = (1 << 0),
    PIN1  = (1 << 1),
    PIN2  = (1 << 2),
    PIN3  = (1 << 3),
    PIN4  = (1 << 4),
    PIN5  = (1 << 5),
    PIN6  = (1 << 6),
    PIN7  = (1 << 7),
    PIN8  = (1 << 8),
    PIN9  = (1 << 9),
    PIN10 = (1 << 10),
    PIN11 = (1 << 11),
    PIN12 = (1 << 12),
    PIN13 = (1 << 13),
    PIN14 = (1 << 14),
    PIN15 = (1 << 15)
} pin_t;


// PORT
typedef enum{ 
    PORTA = GPIOA_BASE, 
    PORTB = GPIOB_BASE,   
    PORTC = GPIOC_BASE, 
    PORTD = GPIOD_BASE,  
    PORTE = GPIOE_BASE,  
    PORTH = GPIOH_BASE 
}port_t;

// PIN PARAMETERS 
typedef enum { 
    IN = 0, 
    OUT, 
    ALT_FUN, 
    ANALOG  
}mode_t; 

typedef enum { 
    PUSH_PULL = 0, 
    OPEN_DRAIN  
}type_t;

typedef enum { 
    S_LOW = 0,
    S_MED, 
    S_HIGH, 
    S_V_HIGH 
}speed_t; 

typedef enum { 
    NO_PULL = 0, 
    PULL_UP, 
    PULL_DW 
}pull_t;

// is comming ? 
// typedef enum lock_t { 
//     NO_LOCK = 0,
//     LOCK  
// }LOCK; 

typedef enum{ 
    LOW = 0,  
    HIGH, 
    UNDEF 
}state_t;

typedef enum {
    AF0 = 0,
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7,
    AF8,
    AF9,
    AF10,
    AF11,
    AF12,
    AF13,
    AF14,
    AF15
} alt_val_t;
