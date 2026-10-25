#pragma once

#include <stdint.h>

#ifndef F_CPU
#    define F_CPU 16000000UL
#endif

// I2C clock frequency for the SSD1306 OLED.
#define SCL_CLOCK 400000L

#define I2C_READ 1
#define I2C_WRITE 0

void i2c_master_init(void);
uint8_t i2c_master_start(uint8_t address);
void i2c_master_stop(void);
uint8_t i2c_master_write(uint8_t data);
uint8_t i2c_master_read(int ack);
void i2c_reset_state(void);

static inline uint8_t i2c_start_read(uint8_t address) {
    return i2c_master_start((address << 1) | I2C_READ);
}

static inline uint8_t i2c_start_write(uint8_t address) {
    return i2c_master_start((address << 1) | I2C_WRITE);
}
