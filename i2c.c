#include <util/twi.h>
#include <avr/io.h>
#include <stdbool.h>
#include "i2c.h"

#ifdef USE_I2C

// Bound every TWI wait so a missing or disconnected OLED cannot hang the scan loop.
#define I2C_LOOP_TIMEOUT ((uint16_t)(10UL * (F_CPU / SCL_CLOCK) / 8UL))

static bool i2c_wait(void) {
    uint16_t limit = 0;
    while (!(TWCR & _BV(TWINT)) && limit < I2C_LOOP_TIMEOUT) {
        ++limit;
    }
    return (TWCR & _BV(TWINT)) != 0;
}

void i2c_master_init(void) {
    TWSR = 0; // No prescaler.
    TWBR = ((F_CPU / SCL_CLOCK) - 16) / 2;
    TWCR = _BV(TWEN);
}

// Start a transaction with an already-shifted address and R/W bit.
// Returns 0 on success and 1 on timeout or NACK.
uint8_t i2c_master_start(uint8_t address) {
    TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTA);
    if (!i2c_wait() || (TW_STATUS != TW_START && TW_STATUS != TW_REP_START)) {
        return 1;
    }

    TWDR = address;
    TWCR = _BV(TWINT) | _BV(TWEN);
    if (!i2c_wait()) {
        return 1;
    }

    return (TW_STATUS == TW_MT_SLA_ACK || TW_STATUS == TW_MR_SLA_ACK) ? 0 : 1;
}

void i2c_master_stop(void) {
    TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTO);

    // TWSTO is cleared by hardware after the STOP condition has completed.
    uint16_t limit = 0;
    while ((TWCR & _BV(TWSTO)) && limit < I2C_LOOP_TIMEOUT) {
        ++limit;
    }
}

// Returns 0 on ACK and 1 on timeout or NACK.
uint8_t i2c_master_write(uint8_t data) {
    TWDR = data;
    TWCR = _BV(TWINT) | _BV(TWEN);
    if (!i2c_wait()) {
        return 1;
    }
    return TW_STATUS == TW_MT_DATA_ACK ? 0 : 1;
}

uint8_t i2c_master_read(int ack) {
    TWCR = _BV(TWINT) | _BV(TWEN) | (ack ? _BV(TWEA) : 0);
    if (!i2c_wait()) {
        return 0;
    }
    return TWDR;
}

void i2c_reset_state(void) {
    TWCR = 0;
}

#endif
