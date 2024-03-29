#include "gpio.h" 

error_t InitPin(cfg_pin_t * cfg_pin){ 

    // error flag
    error_t error = OK;
 
    // Which pins have to set ? 
    // In other words: In which position [X] we have to apply cfg_pin settings ? 
    // ex. REGISTER = (0b00X0100X)  
    for(uint16_t position=0; position<16; ++position)
    { 
        if (cfg_pin->pin & (1 << position))
        {
            // check turning on clock & enable + checking errors
            if(OK != SetGpioClock(cfg_pin->port)) return CLK_SET_ERR;

            // set MODE(MODER) 
            volatile uint32_t * address = (uint32_t*)(cfg_pin->port); //+ 0U;
            uint32_t bits_mask = ((0x3U) << ((position) * 0x2U));
            uint32_t set_mask = ((cfg_pin->mode) << ((position) * 0x2U));
            uint32_t clear_mask = (set_mask ^ bits_mask);
            WriteReg(address, clear_mask, set_mask);                                     

            // set TYPE(OTYPER): PP/OD 
            address = ((uint32_t*)(cfg_pin->port)) + 1U;
            bits_mask = ((0x1U) << ((position) * 0x1U));
            set_mask = ((cfg_pin->type) << ((position) * 0x1U));
            clear_mask = (set_mask ^ bits_mask);
            WriteReg(address, clear_mask, set_mask);                                   

            // set SPEED(OSPEEDR) 
            address = ((uint32_t*)(cfg_pin->port)) + 2U;
            bits_mask = ((0x3U) << ((position) * 0x2U));
            set_mask = ((cfg_pin->speed) << ((position) * 0x2U));
            clear_mask = (set_mask ^ bits_mask);
            WriteReg(address, clear_mask, set_mask);                                    

            // set PU(PUPDR) 
            address = ((uint32_t*)(cfg_pin->port)) + 3U;
            bits_mask = ((0x3U) << ((position) * 0x2U));
            set_mask = ((cfg_pin->pull) << ((position) * 0x2U));
            clear_mask = (set_mask ^ bits_mask);
            WriteReg(address, clear_mask, set_mask);   

            // set LOCK(later) - unused 
            // address = ((uint32_t*)(cfg_pin->port)) + 7U;
            // bits_mask = ((0x1U) << ((position) * 0x1U));
            // set_mask = ((cfg_pin->lock) << ((position) * 0x1U));
            // uint32_t clear_mask = (set_mask ^ bits_mask);
            // WriteReg(address, clear_mask, set_mask);    

            // set ALTERNATIVE_FUNC(AFRL and AFRH) 
            if(position < 8)
            { 
                address = ((uint32_t*)(cfg_pin->port)) + 8U;  // AFRL
                bits_mask = ((0xFU) << ((position) * 0x4U));
                set_mask = ((cfg_pin->alt_val) << ((position) * 0x4U));
                clear_mask = (set_mask ^ bits_mask);
                WriteReg(address, clear_mask, set_mask);   
            }
            else 
            { 
                address = ((uint32_t*)(cfg_pin->port)) + 9U;  // AFRH
                bits_mask = ((0xFU) << ((position-0x8U) * 0x4U));
                set_mask = ((cfg_pin->alt_val) << ((position-0x8U) * 0x4U));
                clear_mask = (set_mask ^ bits_mask);
                WriteReg(address, clear_mask, set_mask);  
            }

            // check settings
            WritePin((cfg_pin->port), (cfg_pin->pin), (cfg_pin->default_state));
            if (ReadPin(cfg_pin->port,cfg_pin->pin) != cfg_pin->default_state) error = ERR1; 
        }
    }
    return error; 
}

error_t DeInitPin(cfg_pin_t * cfg_pin)
{     
    error_t error = OK;

    for(uint16_t position=0; position<16; ++position)
    { 
        if (cfg_pin->pin & (1 << position))
        {
            // reset MODE(MODER) 
            volatile uint32_t * address = (uint32_t*)(cfg_pin->port); //+ 0U;
            uint32_t bits_mask = ((0x3U) << ((position) * 0x2U));
            WriteReg(address, 0x0U, bits_mask); //set bits   

            // reset ALTERNATIVE_FUNC(AFRL and AFRH) 
            if(position < 8)
            { 
                address = ((uint32_t*)(cfg_pin->port)) + 8U;  // AFRL
                bits_mask = ((0xFU) << ((position) * 0x4U));
                WriteReg(address, bits_mask, 0x0U);   
            }
            else 
            { 
                address = ((uint32_t*)(cfg_pin->port)) + 9U;  // AFRH
                bits_mask = ((0xFU) << ((position-0x8U) * 0x4U));
                WriteReg(address, bits_mask, 0x0U);   
            }

            // reset PU(PUPDR) 
            address = ((uint32_t*)(cfg_pin->port)) + 3U;
            bits_mask = ((0x3U) << ((position) * 0x2U));
            WriteReg(address, bits_mask, 0x0U);     

            // set SPEED(OSPEEDR) 
            address = ((uint32_t*)(cfg_pin->port)) + 2U;
            bits_mask = ((0x3U) << ((position) * 0x2U));
            WriteReg(address, bits_mask, 0x0U);       

            // set TYPE(OTYPER): PP/OD 
            address = ((uint32_t*)(cfg_pin->port)) + 1U;
            bits_mask = ((0x1U) << ((position) * 0x1U));
            WriteReg(address, bits_mask, 0x0U);    
        } 
    }
    if(OK != ResetGpioClock(cfg_pin->port)) return CLK_SET_ERR;
    return error;
} 

error_t InitPort(cfg_pin_t * cfg_pin, port_t P){ 

    // The function sets absolutley all pins of single port agreed with cfg_pin structure
    // The function sets all indicates pin agreed with cfg_pin structure  
    // In this func field port inside cfg_pin structure is irrelevant 
    // The role of the settable port is taken over by port_t P; 
    error_t err = OK;

    uint16_t i = 0U;
    const uint16_t max = 16U;

    // modify port in cfg structure
    cfg_pin->port = P;
    
    // fill port with settings from cfg_pin
    for(i;i<max;i++)
    { 
        cfg_pin->pin = i;  
        if(InitPin(cfg_pin) > 0) break;
    }
    return err; 
}

error_t DeInitPort(cfg_pin_t * cfg_pin, port_t P){ 
    // making is comming :)  
    return OK;
}

error_t WritePin(port_t P, uint16_t pin, state_t state){ 
    // using ODR
    for(uint16_t position=0; position<16; ++position)
    { 
        if (pin & (1 << position))
        { 
            volatile uint32_t *address = ((uint32_t*)(P)) + 5U;
            uint32_t mask_1bit = ((0x1U) << ((position) * 0x1U));
            uint32_t set_mask = ((state) << ((position) * 0x1U));
            uint32_t clear_mask = set_mask ^ mask_1bit;
            WriteReg(address, clear_mask, set_mask);
        }
    }
    return OK; 
} 

state_t ReadPin(port_t P, uint16_t pin){ 
    volatile uint32_t *address = ((uint32_t*)(P)) + 5U;
    uint32_t res = *address;
    return ((res & pin) > 0) ? HIGH : LOW;  
}

error_t WritePort(port_t P, uint32_t port_val){ 
    uint32_t *address = ((uint32_t*)(P)) + 5U;
    WriteReg(address, 0x0U, port_val);
    return OK;
}

uint32_t ReadPort(port_t P){ 
    uint32_t *address = ((uint32_t*)(P)) + 5U;
    uint32_t res = *address;
    return (res); 
}

int GetPortIndex(port_t port) {
    switch (port) {
        case PORTA: return 0;
        case PORTB: return 1;
        case PORTC: return 2;
        case PORTD: return 3;
        case PORTE: return 4;
        case PORTH: return 5;
        default: return -1; 
    }
}


error_t SetGpioClock(port_t P) 
{ 
    do { 
        int index_port = GetPortIndex(P);
        if(index_port < 0)
        { 
            return CLK_SET_ERR; 
        }
        else 
        { 
            volatile uint32_t *reg = GPIO_RCC;
            volatile uint32_t mirror_reg = *reg;
            gpio_rcc_pin_t gpio_rcc_pin = (gpio_rcc_pin_t)(RCC_AHB2ENR_GPIOAEN + index_port);
            mirror_reg |= gpio_rcc_pin;
            *reg = mirror_reg;  
            __DSB();
        }   
    } while(0); 
    return OK;
}

//TODO: remove repetitions ! 
error_t ResetGpioClock(port_t P) 
{ 
    do { 
        int index_port = GetPortIndex(P);
        if(index_port < 0)
        { 
            return CLK_SET_ERR; 
        }
        else 
        { 
            volatile uint32_t *reg = GPIO_RCC;
            volatile uint32_t mirror_reg = *reg;
            gpio_rcc_pin_t gpio_rcc_pin = (gpio_rcc_pin_t)(RCC_AHB2ENR_GPIOAEN + index_port);
            mirror_reg &= ~ gpio_rcc_pin;
            *reg = mirror_reg;  
            __DSB();
        }   
    } while(0); 
    return OK;
}

static void WriteReg(uint32_t * reg, uint32_t clear_mask, uint32_t set_mask)
{ 
    volatile uint32_t mirror_reg = *reg;
    mirror_reg = (((mirror_reg) & (~(clear_mask))) | (set_mask));
    *reg = mirror_reg;
}



