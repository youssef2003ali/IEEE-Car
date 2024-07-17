/*
 * Car_Modes.c
 *
 * Created: 7/9/2024 6:22:19 PM
 *  Author: Moaaz
 */ 
#include "Car_Modes.h"


u8 Normal_CAR_MOD()
{
	


 u8 Ch;
 
// Ch = Read_char();
 
 while(1) {
	 Ch = Read_char();
	 _delay_ms(50);
	 Send_char(Ch);
	 _delay_ms(20);
	 Send_char('\n');
 switch (Ch) {
	 
	 case 'w' : {
 		motor_set_speed(200);
         motor_set_direction_4D(Forward);
		 
		 } break;
		 
	 case 'a' : {
 		motor_set_speed(150);
	 motor_set_direction_4D(Left);
		 
	 }break;
	 
	  case 's' : {
 		motor_set_speed(200);
		  motor_set_direction_4D(Backward);

	  }break;
	  
	   case 'd' : {
 		motor_set_speed(150);
 		
		   motor_set_direction_4D(Right);

	   }break;
	   
	    
		case 'e' : {
			
			motor_stop_4D();
			
			}break;
		case 'x' :{
		motor_stop_4D();
		return 'x';
		    }
           }
		 }

		}



	
		
	
		


	
		
		
		
		u8 Auto_Pilot_MODE()
{
			
		   while(1) {
			   if (uart_available()) {
				   u8 Char = Read_char();
				   _delay_ms(50);
				   Send_char(Char);
				   _delay_ms(20);
				   Send_char('\n');
				   if (Char=='x') 
				   return 'x';
			   }
			
			Self_Drive();
		}
		}

			
		
u8 High_Way_MODE() {
	

			
	HCSR04Init();
	
	while(1) {
	if (uart_available())
	 {
		u8 Char = Read_char();
		_delay_ms(50);
		Send_char(Char);
		_delay_ms(20);
		Send_char('\n');
		if (Char=='x')
		return 'x';
	}
	
	
	
	HCSR04Trigger(US_TRIG1_POS);
	HCSR04Trigger(US_TRIG2_POS);
	
	u16 distance1 = GetPulseWidth(US_ECHO1_POS)*0.03521;
	u16 distance2 = GetPulseWidth(US_ECHO2_POS)*0.03521;
	
	if (distance1 <= 20 && distance2 > 20 ) 
	{
		
			GPIO_WRITE_PIN(PORT_A,2,LOW);
			GPIO_WRITE_PIN(PORT_A,0,LOW);
			GPIO_WRITE_PIN(PORT_A,1,HIGH);
			
			
			motor_set_speed(160);
			motor_set_direction_4D(Right);
			_delay_ms(250);
			motor_set_speed(138);
			motor_set_direction_4D(Forward);
			_delay_ms(250);
			motor_set_speed(160);
			motor_set_direction_4D(Left);
			_delay_ms(250);
Follow_Line();			
		}
		else if (distance1 <= 20 && distance2 <= 20){
			GPIO_WRITE_PIN(PORT_A,2,HIGH);
			GPIO_WRITE_PIN(PORT_A,0,LOW);
			GPIO_WRITE_PIN(PORT_A,1,LOW);
			motor_stop_4D();
		}
	
	else if (distance1 > 20 )
	{
	GPIO_WRITE_PIN(PORT_A,2,LOW);
	GPIO_WRITE_PIN(PORT_A,0,HIGH);
	GPIO_WRITE_PIN(PORT_A,1,LOW);
	   motor_set_speed(180);
        Follow_Line();
	
}
}
}

	 
		
		


















	