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
}cfg_pin_t;

error_t InitPin(cfg_pin_t * cfg_pin);

error_t DeInitPin(cfg_pin_t cfg_pin); 

error_t WritePin(pin_t pin, state_t state); 

error_t ReadPin(pin_t pin, state_t state);





