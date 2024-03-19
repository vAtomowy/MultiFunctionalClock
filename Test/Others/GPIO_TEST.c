#include "GPIO_TEST.h"

void delay(uint32_t n)
{ 
    for (int i = 0; i < n; i++)
    {
       i=i; 
    }
}

void GPIO_TEST(void)
{ 
    cfg_pin_t PINA; 
    PINA.mode = ALT_FUN;
    PINA.alt_val = AF4;
    PINA.pin = PIN10|PIN11; 
    PINA.type = OPEN_DRAIN;
    PINA.pull = NO_PULL; 
    PINA.port = PORTB;   
    PINA.speed = S_V_HIGH;
    InitPin(&PINA); 

    // cfg_pin_t PINEK;
    // PINEK.pin = PIN13 | PIN14; 
    // PINEK.type = PUSH_PULL;
    // PINEK.port = PORTB;
    // PINEK.mode = OUT;  
    // InitPin(&PINEK); 

    //DeInitPin(&PINEK); 

    // while (1)
    // {
    //     WritePin(PORTB, (PIN13 | PIN14), LOW);
    //     state_t x = ReadPin(PORTB, PIN14);
    //     x=x; 
    //     delay(80000);
    //     WritePin(PORTB, (PIN13 | PIN14), HIGH);
    //     x = ReadPin(PORTB, PIN14);
    //     x=x; 
    //     delay(80000);
    // }

}