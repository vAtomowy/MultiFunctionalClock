#include "gpio.h" 

error_t InitPin(cfg_pin_t * cfg_pin){ 

    // turn clock / callback 

    // set MODE(MODER) 
    volatile uint32_t * moder_address = (uint32_t*)(cfg_pin->port);
    uint32_t moder_mask = ~((cfg_pin->mode) << ((cfg_pin->pin) * PTR_MASK));
    uint32_t reg = *moder_address;
    reg = (reg & moder_mask);
    *moder_address = reg;

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

