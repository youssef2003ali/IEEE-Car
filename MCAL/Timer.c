/*
 * Timer.c
 *
 * Created:  7/3/2024 1:35:38 AM
 * Author: DELL
*/


		  


#include "Timer.h"

// Function to initialize the timer
void Timer_Init(TimerNumber timer, TimerMode mode) {
	switch (timer) {
		case TIMER0:
		switch (mode) {
			case TIMER_MODE_NORMAL:
			BIT_SET(TCCR0 , FOC0);
			BIT_CLR(TCCR0, WGM00); // Normal mode
			BIT_CLR(TCCR0, WGM01);
			break;
			case TIMER_MODE_CTC:
			BIT_SET(TCCR0 , FOC0);
			BIT_CLR(TCCR0, WGM00);
			BIT_SET(TCCR0, WGM01);
			// CTC mode
			break;
			case TIMER_MODE_FAST_PWM:
			BIT_SET(TCCR0, WGM00);
			BIT_SET(TCCR0, WGM01);
			// Fast PWM mode
			break;
			case TIMER_MODE_PHASE_CORRECT_PWM:
			BIT_SET(TCCR0, WGM00);
			BIT_CLR(TCCR0, WGM01);
			// Phase Correct PWM mode
			break;
		}
		break;
		case TIMER1:
		switch (mode) {
			case TIMER_MODE_NORMAL:
			TCCR1A = 0; // Normal mode
			TCCR1B = (1 << FOC1A) | (1 << FOC1B);
			break;
			case TIMER_MODE_CTC:
			TCCR1A = 0;
			TCCR1B = (1 << WGM12) | (1 << FOC1A) | (1 << FOC1B); // CTC mode
			break;
			case TIMER_MODE_FAST_PWM:
			TCCR1A = (1 << WGM10) | (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1); // Fast PWM mode
			TCCR1B = (1 << WGM12) | (1 << WGM13);
			break;
			case TIMER_MODE_PHASE_CORRECT_PWM:
			TCCR1A = (1 << WGM10) | (1 << COM1A1) | (1 << COM1B1); // Phase Correct PWM mode
			TCCR1B = 0;
			break;
		}
		break;
		case TIMER2:
		 switch (mode) {
			 case TIMER_MODE_NORMAL:
			 BIT_SET(TCCR2 , FOC2);
			 BIT_CLR(TCCR2, WGM20); // Normal mode
			 BIT_CLR(TCCR2, WGM21);
			 break;
			 case TIMER_MODE_CTC:
			 BIT_SET(TCCR2 , FOC2);
			 BIT_CLR(TCCR2, WGM20);
			 BIT_SET(TCCR2, WGM21);
			 // CTC mode
			 break;
			 case TIMER_MODE_FAST_PWM:
			 BIT_SET(TCCR2, WGM20);
			 BIT_SET(TCCR2, WGM21);
			 // Fast PWM mode
			 break;
			 case TIMER_MODE_PHASE_CORRECT_PWM:
			 BIT_SET(TCCR2, WGM20);
			 BIT_CLR(TCCR2, WGM21);
			 // Phase Correct PWM mode
			 break;
		 }
		 break;
	}
}

// Function to set the prescaler
void Timer_SetPrescaler(TimerNumber timer, TimerPrescaler prescaler) {
	switch (timer) {
		case TIMER0:
		TCCR0 = (TCCR0 & 0xF8) | (prescaler & 0x07);
		                               
		break;   
		case TIMER1:
		TCCR1B = (TCCR1B & 0xF8) | (prescaler & 0x07);
		break;
		case TIMER2:
		TCCR2 = (TCCR2 & 0xF8) | (prescaler & 0x07 );
		break;
	}
}

// Function to set the CTC value
void Timer_SetCTCValue(TimerNumber timer, u16 value) {
	switch (timer) {
		case TIMER0:
		OCR0 = (u8)value;
		break;
		case TIMER1:
		OCR1A = value;
		break;
		case TIMER2:
		OCR2 = (u8)value;
		break;
	}
}

// Function to set the PWM value
void Timer_SetPWMValue(TimerNumber timer, u8 value) {
	switch (timer) {
		case TIMER0:
		OCR0 = value;
		break;
		case TIMER1:
		OCR1A = value;
		break;
		case TIMER2:
		OCR2 = value;
		break;
	}
}
