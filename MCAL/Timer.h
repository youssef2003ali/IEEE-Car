/*
 * Timer.h
 *
 * Created: 7/3/2024 1:35:38 AM
 *  Author: DELL
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD.h"
// Enumeration for Timer Modes
typedef enum {
	TIMER_MODE_NORMAL,
	TIMER_MODE_CTC,
	TIMER_MODE_FAST_PWM,
	TIMER_MODE_PHASE_CORRECT_PWM
} TimerMode;

// Enumeration for Timer Numbers
typedef enum {
	TIMER0,
	TIMER1,
	TIMER2
} TimerNumber;

// Enumeration for Timer Pre-scalers
typedef enum {
	TIMER_NO_CLOCK,
	TIMER_PRESCALER_1,
	TIMER_PRESCALER_8,
	TIMER_PRESCALER_64,
	TIMER_PRESCALER_256,
	TIMER_PRESCALER_1024,
	TIMER_EXTERNAL_FALLING,
	TIMER_EXTERNAL_RISING
} TimerPrescaler;

// Function prototypes
void Timer_Init(TimerNumber timer, TimerMode mode);
void Timer_SetPrescaler(TimerNumber timer, TimerPrescaler prescaler);
void Timer_SetCTCValue(TimerNumber timer, u16 value);
void Timer_SetPWMValue(TimerNumber timer, u8 value);


#endif /* TIMER_H_ */




/*

time calculations:
- we have three  parameters : compare val. - freq - prescale 
- Main rule : time = ctc* 1/f * pre_scale   
- for easier calculations assume the ctc or thr freq and get the other from the equation all of that while 
  the time = 1 sec
- DO NOT FORGET TO SET THE FREQUANCY ON PROTUS 
- set the CKSEL fuses to : ext clock */