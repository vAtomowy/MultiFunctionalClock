#include "gpio.h" 

error_t InitPin(cfg_pin_t * cfg_pin){ 

    // check turn clock & enable  

    // set MODE(MODER) 
    volatile uint32_t * address = (uint32_t*)(cfg_pin->port); //+ 0UL;
    uint32_t mask = ~((cfg_pin->mode) << ((cfg_pin->pin) * 0x2UL));
    WriteReg(address, mask, mask);

    // set TYPE(OTYPER): PP/OD 
    address = ((uint32_t*)(cfg_pin->port)) + 1UL;
    mask = ~((cfg_pin->type) << ((cfg_pin->pin) * 0x1UL));
    WriteReg(address, mask, mask);

    // set SPEED(OSPEEDR) 
    address = ((uint32_t*)(cfg_pin->port)) + 2UL;
    mask = ~((cfg_pin->speed) << ((cfg_pin->pin) * 0x2UL));
    WriteReg(address, mask, mask);

    // set PULL(PUPDR) 
    address = ((uint32_t*)(cfg_pin->port)) + 3UL;
    mask = ~((cfg_pin->pull) << ((cfg_pin->pin) * 0x2UL));
    WriteReg(address, mask, mask);

    // set LOCK(later) - unused 
    // address = ((uint32_t*)(cfg_pin->port)) + 7UL ;
    // mask = ~((cfg_pin->type) << ((cfg_pin->pin) * 0x1UL));
    // WriteReg(address, mask, mask);

    // set ALTERNATIVE_FUNC(AFRL and AFRH) 
    
    //TODO: alt val !!! i przesuenicie ! 
    address = ((uint32_t*)(cfg_pin->port)) + 8UL;
    mask = ~((cfg_pin->alt_val) << ((cfg_pin->pin) * 0x4UL));
    WriteReg(address, mask, mask);

    address = ((uint32_t*)(cfg_pin->port)) + 9UL;
    mask = ~((cfg_pin->alt_val) << ((cfg_pin->pin) * 0x4UL));
    WriteReg(address, mask, mask);

    // set DEFAULT VAL (BSRR and BRR)
    WritePin((cfg_pin->port), (cfg_pin->pin), LOW); 

    return OK; 

}

error_t DeInitPin(cfg_pin_t * cfg_pin){ 
    return OK;
} 

error_t InitPinsTheSame(cfg_pin_t * cfg_pin, uint16_t SET_PIN_MASK){ 

    // The function sets all indicates pin agreed with cfg_pin structure  
    // In this func field pin inside cfg_pin structure is irrelevant 
    // The role of the settable pins is taken over by  SET_PIN_MASK 
    // ex. cfg_pin uses its structure to set the pins SET_PIN MASK: 
    // SET_PIN_MASK = 0x13   Pins 0, 1 and 4 will be setting !  
    error_t err = OK;

    uint32_t value = 0;
    value = SET_PIN_MASK;
    uint16_t thr = 32U - (__CLZ(value) - 16U);
    uint16_t i =0U;

    for(i;i<thr;i++){ 

        cfg_pin->pin = thr;
        err = InitPin(cfg_pin);
        if(err > 0){ 
            return err;
        }
    }
    return err; 

}

error_t DeInitPinsTheSame(cfg_pin_t * cfg_pin, uint16_t SET_PIN_MASK){ 
    // making is comming :) 
    return OK;
}

error_t InitPort(cfg_pin_t * cfg_pin, port_t P){ 

    // The function sets absolutley all pins of single port agreed with cfg_pin structure
    error_t err = OK;

    uint16_t i = 0U;
    const uint16_t max = 16U;
    cfg_pin->port = P;
    
    for(i;i<max;i++){ 

        cfg_pin->pin = i;  
        err = InitPin(cfg_pin);
        if(err > 0){ 
            return err;
        }
    }
    return err; 
}

error_t DeInitPort(cfg_pin_t * cfg_pin, port_t P){ 
    // making is comming :)  
    return OK;
}

error_t WritePin(port_t P, pin_t pin, state_t state){ 
    // using ODR
    uint32_t *address = ((uint32_t*)(P)) + 5UL;
    uint32_t mask = ~((state) << ((pin) * 0x1UL));
    WriteReg(address, mask, mask);
    return OK; 
} 

state_t ReadPin(port_t P, pin_t pin, state_t state){ 
    uint32_t *address = ((uint32_t*)(P)) + 4UL;
    uint32_t mask = ~((state) << ((pin) * 0x1UL));
    uint32_t res = *address;
    return ((res & mask)); 
}

error_t WritePort(port_t P, uint32_t port_val){ 
    uint32_t *address = ((uint32_t*)(P)) + 4UL;
    WriteReg(address, port_val, port_val);
    return OK;
}

uint32_t ReadPort(port_t P){ 
    uint32_t *address = ((uint32_t*)(P)) + 4UL;
    uint32_t res = *address;
    return (res); 
}

static void WriteReg(uint32_t * reg, uint32_t clear_mask, uint32_t set_mask){ 
    // Method_1    
    uint32_t mirror_reg = *reg;
    mirror_reg = ~(mirror_reg ^ clear_mask);
    *reg = mirror_reg;
    // Method 2
    //MODIFY_REG(reg, clear_mask, set_mask); 
}
