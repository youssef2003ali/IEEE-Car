/*
 * ULTRA_SONIC.h
 *
 * Created: 7/12/2024 12:48:37 AM
 *  Author: Moaaz
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include "DIO.h"
#include "STD.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

#define US_PORT PORTB        // Port where ultrasonic sensors are connected
#define US_PIN  PINB            // Pin register for input
#define US_DDR  DDRB            // Data Direction Register for port

#define US_TRIG1_POS PB0        // Trigger pin for first sensor
#define US_ECHO1_POS PB1        // Echo pin for first sensor

#define US_TRIG2_POS PB5       // Trigger pin for second sensor
#define US_ECHO2_POS PB6       // Echo pin for second sensor

#define US_ERROR        -1
#define US_NO_OBSTACLE  -2

void HCSR04Init();
void HCSR04Trigger(uint8_t trig_pin);
uint16_t GetPulseWidth(uint8_t echo_pin);

#endif /* ULTRA_SONIC_H_ */




