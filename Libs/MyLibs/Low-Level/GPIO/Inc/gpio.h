#include "gpio_types.h"

#define GPIO_RCC RCC_AHB2ENR
#define RCC_AHB2ENR 0x4002104C 

typedef struct{ 
    pin_t pin; 
    port_t port;
    mode_t mode;
    type_t type; 
    speed_t speed; 
    pull_t pull; 
    // lock_t lock; 
    alt_val_t alt_val; 
    state_t default_state; // state after default
    state_t state;  
} __attribute__((packed)) cfg_pin_t;

// methods for user (developer)
error_t InitPin(cfg_pin_t * cfg_pin);

error_t DeInitPin(cfg_pin_t * cfg_pin); 

error_t InitPort(cfg_pin_t * cfg_pin, port_t P);

error_t DeInitPort(cfg_pin_t * cfg_pin, port_t P);
// OK
error_t WritePin(port_t P, uint16_t pin, state_t state); 
// ok
state_t ReadPin(port_t P, uint16_t pin);
// ok
error_t WritePort(port_t P, uint32_t port_val);
// ok
uint32_t ReadPort(port_t P);


// internal method 
static void WriteReg(uint32_t * reg, uint32_t clear_mask, uint32_t set_mask);
static void SetGpioClock(port_t P); 

