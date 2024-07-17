/***************************************************************************************************************************************************************************************************

	1-The Ports are responsible for output operations (High if the bit =1  and Low if the Bit = 0)                                                     Note: ATmega32 has 4 Ports 
	2-Registers (DDR) are responsible for the Direction to be Input or Output (Input if bit =0   and Output if bit = 1)                                                   4 Registers
	3-Pins are responsible for the Input operations                                                                                                                       8 Pins in each
	
  *************************************************************************************************************************************************************************************************/
#include "DIO.h"

void GPIO_INIT_PIN(u8 PORT,u8 PIN,u8 dir) 
{
	switch(dir)
	{
		case INPUT :
		{
			switch(PORT)
			{
				case PORT_A : BIT_CLR(DDRA,PIN); break;
				case PORT_B : BIT_CLR(DDRB,PIN); break;
				case PORT_C : BIT_CLR(DDRC,PIN); break;
				case PORT_D : BIT_CLR(DDRD,PIN); break;
			}
		}break ;
		case OUTPUT :  
		{
			switch(PORT)
			{
				case PORT_A : BIT_SET(DDRA,PIN); break;
				case PORT_B : BIT_SET(DDRB,PIN); break;
				case PORT_C : BIT_SET(DDRC,PIN); break;
				case PORT_D : BIT_SET(DDRD,PIN); break;
			}
		}break ;
	}
}




void GPIO_WRITE_PIN(u8 PORT , u8 PIN, u8 value) 
{
		switch(value)
		{
			case LOW :
			{
				switch(PORT)
				{
					case PORT_A : BIT_CLR(PORTA,PIN); break;
					case PORT_B : BIT_CLR(PORTB,PIN); break;
					case PORT_C : BIT_CLR(PORTC,PIN); break;
					case PORT_D : BIT_CLR(PORTD,PIN); break;
				}
			} break ;
			case HIGH :
			{
				switch(PORT)
				{
					case PORT_A : BIT_SET(PORTA,PIN); break;
					case PORT_B : BIT_SET(PORTB,PIN); break;
					case PORT_C : BIT_SET(PORTC,PIN); break;
					case PORT_D : BIT_SET(PORTD,PIN); break;
				}
			}break ;
		}
}



void GPIO_WRITE_PORT(u8 PORT , u8 val) 
{

			switch(PORT)
			{
				case PORT_A :  PORTA = val ;break;
				case PORT_B :  PORTB = val ;break;
				case PORT_C :  PORTC = val; break;
				case PORT_D :  PORTD = val ;break;
			}
	
}


 u8 GPIO_READ_PIN(u8 PORT , u8 PIN) 
 {
	 switch(PORT)
	 {
		 case PORT_A :return BIT_GET(PINA,PIN); break;
		 case PORT_B :return BIT_GET(PINB,PIN); break;
		 case PORT_C :return BIT_GET(PINC,PIN); break;
		 case PORT_D :return BIT_GET(PIND,PIN); break;
	 }
 }
 
 u8 GPIO_READ_PORT(u8 PORT) 
 {
	 	 switch(PORT)
	 	 {
		 	 case PORT_A :return PINA ;break;
		 	 case PORT_B :return PINB ;break;
		 	 case PORT_C :return PINC ;break;
		 	 case PORT_D :return PIND; break;
			 
	 	 }
 }
 void GPIO_INIT_PORT(u8 PORT,u8 dir) {

	 switch(dir)
	 {
		 case INPUT:
		 {
			 switch(PORT)
			 {
				 case PORT_A: DDRA &= 0x00 ; break;
				 case PORT_B: DDRB &= 0x00 ; break;
				 case PORT_C: DDRC &= 0x00 ; break;
				 case PORT_D: DDRD &= 0x00 ; break;
			 }
		 }
		 case OUTPUT: {
			 switch(PORT) {
				 case PORT_A: DDRA |= 0xff; break;
				 case PORT_B: DDRB |= 0xff; break;
				 case PORT_C: DDRC |= 0xff; break;
				 case PORT_D: DDRD |= 0xff; break;
			 }
		 }
	 }
 }
 
 
 
 
 