#include "stm32l4xx.h" 
#include "stm32l431xx.h"

#define MODER_MASK 0x3UL
#define PTR_MASK 0x2UL

// ERROR TYPE
typedef enum { 
    OK = 0, 
    ERR1, 
    ERR2, 
    ERR3 
}error_t;


// PIN 
typedef enum { 
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
}pin_t;

//PORT
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

//TODO: zmeinic nawzy na bez podłogi & odpecić z HAL-a
typedef enum {
    AF_0 = 0,
    AF_1,
    AF_2,
    AF_3,
    AF_4,
    AF_5,
    AF_6,
    AF_7,
    AF_8,
    AF_9,
    AF_10,
    AF_11,
    AF_12,
    AF_13,
    AF_14,
    AF_15
} alt_val_t;
