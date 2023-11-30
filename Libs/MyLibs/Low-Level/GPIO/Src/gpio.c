
#include "gpio.h" 

error_t InitPin(cfg_pin_t * cfg_pin){ 

    // turn clock / callback 

    // set MODE(MODER) 
     
    uint32_t moder_address = (cfg_pin->port) * 0x400; 
    //*moder_address = ((uint16_t)(cfg_pin->mode) << (uint16_t)(cfg_pin->port)); 

    // set TYPE(OTYPER): PP/OD 

    // set SPEED(OSPEEDR) 

    // set PULL(PUPDR) 

    // set LOCK(later) - unused 

    // set ALTERNATIVE_FUNC(AFRL and AFRH) 

    // set DEFAULT VAL (BSRR and BRR)

    return OK; 

}

error_t DeInitPin(cfg_pin_t cfg_pin){ 
    return OK;
} 

error_t WritePin(pin_t pin, state_t state){ 
    return OK; 
} 

error_t ReadPin(pin_t pin, state_t state){ 
    return OK; 
}

