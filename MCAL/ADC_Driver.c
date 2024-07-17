/*
 * ADC_Driver.c
 *
 * Created: 5/25/2024 7:25:30 AM
 *  Author: Mostafa_Salem
 */
#include <avr/io.h>
#include "ADC_Driver.h"

void ADC_INIT (u8 VOLTREF, u8 PRESC)
{   // Choose reference_voltage
    switch (VOLTREF)
    {
        case AREF    : ADMUX&= ~(1<<REFS0);            break;
        case AVCC    : ADMUX|=  (1<<REFS0);            break;
        case INTERNAL: ADMUX|=  (1<<REFS0)|(1<<REFS1); break;
    }

    // Choose pre_scalar
    // DIV_num --> DIV2 --> divition factor of the clock = 2      divide the system clock frequency to provide a suitable clock frequency
    switch (PRESC)
    {
        case DIV2   : ADCSRA &= ~(1<<ADPS0); ADCSRA &= ~(1<<ADPS1); ADCSRA &= ~(1<<ADPS2); break;
        case DIV4   : ADCSRA &= ~(1<<ADPS0); ADCSRA |=  (1<<ADPS1); ADCSRA &= ~(1<<ADPS2); break;
        case DIV8   : ADCSRA |=  (1<<ADPS0); ADCSRA |=  (1<<ADPS1); ADCSRA &= ~(1<<ADPS2); break;
        case DIV16  : ADCSRA &= ~(1<<ADPS0); ADCSRA &= ~(1<<ADPS1); ADCSRA |=  (1<<ADPS2); break;
        case DIV32  : ADCSRA |=  (1<<ADPS0); ADCSRA &= ~(1<<ADPS1); ADCSRA |=  (1<<ADPS2); break;
        case DIV64  : ADCSRA &= ~(1<<ADPS0); ADCSRA |=  (1<<ADPS1); ADCSRA |=  (1<<ADPS2); break;
        case DIV128 : ADCSRA |=  (1<<ADPS0); ADCSRA |=  (1<<ADPS1); ADCSRA |=  (1<<ADPS2); break;
    }

    // Enable ADC
    ADCSRA  |= (1 << ADEN);
}

int ADC_READ (int ADC_PIN)
{
    //Choose channel (which PIN to use form ADC PINs)
    ADC_PIN &=0b00000111;       //PIN 0-->7
    ADMUX   &=0xf8;
    ADMUX   |=ADC_PIN;  

    //Start conversion
    ADCSRA  |=(1<<ADSC);

    //Wait till the end of conversion
    while(ADCSRA & (1<<ADSC)); 

    //Return ADC Digital value
    return(ADCL|(ADCH<<8));
}