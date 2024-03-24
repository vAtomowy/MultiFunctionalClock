#include "stm32l4xx.h" 
#include "stm32l431xx.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_hal_i2c.h" 

#define DRIVER_COUNT 2
#define DRIVER_LED_TOTAL 144
#define DRIVER_ADDR_1 0b1010000

#define ISSI_ADDR_DEFAULT 0xA0

#define ISSI_ADDR_DEF_READ 0xA1
#define ISSI_ADDR_DEF_WRITE ISSI_ADDR_DEFAULT

#define ISSI_COMMANDREGISTER 0xFD
#define ISSI_COMMANDREGISTER_WRITELOCK 0xFE
#define ISSI_INTERRUPTMASKREGISTER 0xF0
#define ISSI_INTERRUPTSTATUSREGISTER 0xF1

#define ISSI_PAGE_LEDCONTROL 0x00  // PG0
#define ISSI_PAGE_PWM 0x01         // PG1
#define ISSI_PAGE_AUTOBREATH 0x02  // PG2
#define ISSI_PAGE_FUNCTION 0x03    // PG3

#define ISSI_REG_CONFIGURATION 0x00  // PG3
#define ISSI_REG_GLOBALCURRENT 0x01  // PG3
#define ISSI_REG_RESET 0x11          // PG3
#define ISSI_REG_SWPULLUP 0x0F       // PG3
#define ISSI_REG_CSPULLUP 0x10       // PG3

#define ISSI_REG_CONFIG 0x00      //ok

#define ISSI_COMMANDREGISTER 0xFD // ok
#define ISSI_BANK_FUNCTIONREG 0x03 // helpfully called 'page nine'
#define ISSI_REG_CONFIG_PICTUREMODE 0x00
#define ISSI_REG_PICTUREFRAME 0x01

uint8_t selectBank(uint8_t bank);
uint8_t write_register8(uint8_t addr, uint8_t reg, uint8_t data) ; 
uint8_t readRegister8(uint8_t bank, uint8_t reg); 
uint8_t beggin(uint8_t addr); 
void clear(void); 
void i2c_setup(void); 
void i2c_loop(void); 