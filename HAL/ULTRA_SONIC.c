/*
 * ULTRA_SONIC.c
 *
 * Created: 7/12/2024 12:45:45 AM
 *  Author: Moaaz
 */ 

#include "ULTRA_SONIC.h"

void HCSR04Init() {
    // Set trigger pins as output
    US_DDR |= (1 << US_TRIG1_POS) | (1 << US_TRIG2_POS);
    // Set echo pins as input
    US_DDR &= ~((1 << US_ECHO1_POS) | (1 << US_ECHO2_POS));
    // Initialize trigger pins to low
    US_PORT &= ~((1 << US_TRIG1_POS) | (1 << US_TRIG2_POS));
}

void HCSR04Trigger(uint8_t trig_pin) {
    // Send a 10uS pulse on trigger line
    US_PORT |= (1 << trig_pin);   // High
    _delay_us(15);                // Wait 15uS
    US_PORT &= ~(1 << trig_pin);  // Low
}

uint16_t GetPulseWidth(uint8_t echo_pin) {
    uint32_t i, result;

    // Wait for echo pin to go high
    for (i = 0; i < 600000; i++) {
        if (!(US_PIN & (1 << echo_pin)))
            continue;  // Line is still low, so wait
        else
            break;     // High edge detected, so break
    }

    if (i == 600000)
        return US_ERROR;  // Indicates time out
    
    // High edge found
    // Setup Timer1
    TCCR1A = 0x00;
    TCCR1B = (1 << CS11);  // Prescaler = 8
    TCNT1 = 0x00;          // Start counting time

    // Wait for echo pin to go low
    for (i = 0; i < 600000; i++) {
        if (US_PIN & (1 << echo_pin)) {
            if (TCNT1 > 60000) break; else continue;  // If TCNT1 > 60000, no object in range
        }
        else
            break;
    }

    if (i == 600000)
        return US_NO_OBSTACLE;  // Indicates time out

    // Falling edge found
    result = TCNT1;  // Store pulse width

    // Stop Timer
    TCCR1B = 0x00;

    if (result > 60000)
        return US_NO_OBSTACLE;  // No obstacle
    else
        return (result >> 1);

}

