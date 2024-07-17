/*
 * Line_Tracker.c
 *
 * Created: 7/8/2024 11:04:17 PM
 *  Author: DELL
 */ 
#include "Line_Tracker.h"

void Line_Track_INIT() {
	 
	GPIO_INIT_PIN(IR_PORT,IR_Right,INPUT);    // Right IR
	GPIO_INIT_PIN(IR_PORT,IR_Left ,INPUT);    // Right IR

	
}

void Follow_Line() 
{
	
    motor_set_speed(138);
	
    
		if(GPIO_READ_PIN(IR_PORT, IR_Right) == LOW && GPIO_READ_PIN(IR_PORT, IR_Left) == LOW) {
		
		motor_set_direction_4D(Forward);
		 
		}
	

		if(GPIO_READ_PIN(IR_PORT, IR_Right) == HIGH && GPIO_READ_PIN(IR_PORT, IR_Left) == LOW) {
		motor_set_speed(160);
		motor_set_direction_4D(Right); 
		
		 }

	
		if(GPIO_READ_PIN(IR_PORT, IR_Right) == LOW && GPIO_READ_PIN(IR_PORT, IR_Left) == HIGH) {
		motor_set_speed(160);
		motor_set_direction_4D(Left);
		//_delay_ms(10);
		 }

	
	 if (GPIO_READ_PIN(IR_PORT, IR_Right) == HIGH && GPIO_READ_PIN(IR_PORT, IR_Left) == HIGH  )
	 {
		motor_stop_4D();
	 //_delay_ms(10);
	}
}

void Self_Drive()
{
	HCSR04Init();
	
	HCSR04Trigger(US_TRIG1_POS);
	
	u16 distance1 = GetPulseWidth(US_ECHO1_POS)*0.03521;
	
	if (distance1<=40 && distance1>20)
	{
		motor_set_speed(138);
		Follow_Line();
		
		GPIO_WRITE_PIN(PORT_A,1,HIGH);
		
		
		
	}
	else if (distance1<=20) {
		
		GPIO_WRITE_PIN(PORT_A,2,HIGH);
		motor_stop_4D();
	}
	else{
		GPIO_WRITE_PIN(PORT_A,0,HIGH);
		
		Follow_Line();
	}
		
					
				}