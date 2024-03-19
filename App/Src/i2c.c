#include "i2c.h" 

extern I2C_HandleTypeDef i2c2; 

uint8_t selectBank(uint8_t bank) {
  uint8_t tab[2] = {ISSI_COMMANDREGISTER, bank};
  HAL_I2C_Master_Transmit(&i2c2, ISSI_ADDR_DEFAULT, &tab, 2, 1000);  
  return 1;
}

uint8_t write_register8(uint8_t addr, uint8_t reg, uint8_t data) 
{
  uint8_t tab[2] = {reg, data};
  HAL_I2C_Master_Transmit(&i2c2, addr, &tab, 2, 1000);
  HAL_Delay(20); 
  return 1;
}

uint8_t readRegister8(uint8_t bank, uint8_t reg) {
 
  uint8_t reading = 0xFF;
  selectBank(bank);
  HAL_Delay(5);
  
  HAL_I2C_Master_Transmit(&i2c2, ISSI_ADDR_DEFAULT, &reg, 1, 1000);

    while(1) {
        // Sprawdź, czy dane są dostępne do odbioru
        if(HAL_I2C_Master_Receive(&i2c2, ISSI_ADDR_DEF_READ, &reading, 1, 1000) == 0x00) {
            return reading;
        }
    }
  return -1;
}

uint8_t beggin(uint8_t addr) {

    // Unlock the command register.
    write_register8(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5);

    // Select PG0
    write_register8(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_LEDCONTROL);
    // Turn off all LEDs.
    for (int i = 0x00; i <= 0x17; i++) {
        write_register8(addr, i, 0xFF);
    }

    // Unlock the command register.
    write_register8(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5);

    // Select PG1
    write_register8(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_PWM);
    // Set PWM on all LEDs to 0
    // No need to setup Breath registers to PWM as that is the default.
    for (int i = 0x00; i <= 0xBF; i++) {
        write_register8(addr, i, 0x06);
    }

    // Unlock the command register.
    write_register8(addr, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5);

    // Select PG3
    write_register8(addr, ISSI_COMMANDREGISTER, ISSI_PAGE_FUNCTION);
    // Set global current to maximum.
    write_register8(addr, ISSI_REG_GLOBALCURRENT, 0xFF);
    // Disable software shutdown.
    write_register8(addr, ISSI_REG_CONFIGURATION, 0x01);

    return 1;

}

void clear(void) {

    write_register8(ISSI_ADDR_DEFAULT, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5);
    write_register8(ISSI_ADDR_DEFAULT, ISSI_COMMANDREGISTER, ISSI_PAGE_LEDCONTROL);
    // Turn off all LEDs.
    for (int i = 0x00; i <= 0x17; i++) {
        write_register8(ISSI_ADDR_DEFAULT, i, 0x00);
    }
}

void i2c_setup(void) {
  beggin(0x50);
  HAL_Delay(20); 
}

void i2c_loop(void) {

    uint8_t erasebuf[25] = { 0x00,0x00,0xFF,0xFF,0x00,0x00,0x1C,0x14,0x14,0x0C,0x14,0x14,0x14,0x1C,0x00,0x00,
    0x2A,0x12,0x2E,0x11,0x2A,0x12,0x2E,0x3B};
    
  while(1)
  {
    HAL_Delay(1000); 
        // Unlock the command register.
    write_register8(ISSI_ADDR_DEFAULT, ISSI_COMMANDREGISTER_WRITELOCK, 0xC5);
    write_register8(ISSI_ADDR_DEFAULT, ISSI_COMMANDREGISTER, ISSI_PAGE_LEDCONTROL);
    // Turn off all LEDs.
    for (int i = 0x00; i <= 0x17; i++) {
        write_register8(ISSI_ADDR_DEFAULT, i, erasebuf[i]);
    }

  }

}