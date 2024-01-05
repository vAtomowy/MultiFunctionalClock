#include "gpio_types.h"

typedef struct{ 
    pin_t pin; 
    port_t port;
    mode_t mode;
    type_t type; 
    speed_t speed; 
    pull_t pull; 
    // lock_t lock; 
    alt_val_t alt_val; 
    state_t default_state; // stan po inicjalizacji - domyślny 
    state_t state;  
} __attribute__((packed)) cfg_pin_t;

// methods for user (developer)
error_t InitPin(cfg_pin_t * cfg_pin);

error_t DeInitPin(cfg_pin_t * cfg_pin); 

error_t InitPinsTheSame(cfg_pin_t * cfg_pin, uint16_t SET_PIN_MASK); 

error_t DeInitPinsTheSame(cfg_pin_t * cfg_pin, uint16_t SET_PIN_MASK);

error_t InitPort(cfg_pin_t * cfg_pin, port_t P);

error_t DeInitPort(cfg_pin_t * cfg_pin, port_t P);

error_t WritePin(port_t P, pin_t pin, state_t state); 

state_t ReadPin(port_t P, pin_t pin, state_t state);

error_t WritePort(port_t P, uint32_t port_val);

uint32_t ReadPort(port_t P);


// internal method 
static void WriteReg(uint32_t * reg, uint32_t clear_mask, uint32_t set_mask);





