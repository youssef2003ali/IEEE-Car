/*
 * ADC_Driver.h
 *
 * Created: 5/25/2024 7:25:30 AM
 *  Author: Mostafa_Salem
 */

#ifndef ADC_H_
#define ADC_H_

#include "STD.h"

typedef enum
{
	AREF = 0,
	AVCC = 1,
	INTERNAL = 2,
}VOLTREF;

typedef enum
{
	DIV2   = 2,
	DIV4   = 4,
	DIV8   = 8,
	DIV16  = 16,
	DIV32  = 32,
	DIV64  = 64,
	DIV128 = 128,

}PRESC;



void ADC_INIT(u8 VOLTREF, u8 PRESC);

int ADC_READ(int ADC_PIN);

#endif