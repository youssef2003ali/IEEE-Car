/*
 * _4_DC.c
 *
 * Created: 7/12/2024 6:28:18 PM
 *  Author: DELL
 */ 

/*
 * DCmotor.c
 *
 * Created: 7/8/2024 2:58:56 PM
 *  Author: DELL
 */ 
#include "4_DC.h"
void Motors_INIT_4D() {
	
	GPIO_INIT_PORT(Motorport , OUTPUT);
	Timer_Init(TIMER0 ,TIMER_MODE_FAST_PWM);
	BIT_SET(TCCR0 , COM01); BIT_CLR(TCCR0 , COM00); // Clear OC0 on compare match, set at BOTTOM // mode for pwm
	Timer_SetPrescaler(TIMER0,TIMER_PRESCALER_8);
	OCR0 = 0;
	// Enable Timer/Counter0 output on OC0 (PD6)
	GPIO_INIT_PIN(PORT_B, 3 , OUTPUT);
	
}
void motor_set_speed(u8 speed) {
	// Set the duty cycle (0-255)
	OCR0 = speed;
}

  
  void motor_set_direction_4D(Direction direction) {
	 switch (direction) {
		 case Forward: {
			
			 
			
 

GPIO_WRITE_PIN(Motorport , Motor1IN1 , LOW);
GPIO_WRITE_PIN(Motorport , Motor1IN2 , HIGH);

GPIO_WRITE_PIN(Motorport , Motor3IN1 , HIGH);
GPIO_WRITE_PIN(Motorport , Motor3IN2 , LOW);
 _delay_ms(10);

		 }break;
		 case Backward: {
			 	
			 	  
			 	 
 

GPIO_WRITE_PIN(Motorport , Motor1IN1 , HIGH);
GPIO_WRITE_PIN(Motorport , Motor1IN2 , LOW);

GPIO_WRITE_PIN(Motorport , Motor3IN1 , LOW);
GPIO_WRITE_PIN(Motorport , Motor3IN2 , HIGH);


 _delay_ms(10);


		 }break;
	 
	 case Left: {
		
		
		
 
		
 GPIO_WRITE_PIN(Motorport , Motor1IN1 , LOW);
 GPIO_WRITE_PIN(Motorport , Motor1IN2 , HIGH);
 
 GPIO_WRITE_PIN(Motorport , Motor3IN1 , LOW);
 GPIO_WRITE_PIN(Motorport , Motor3IN2 , HIGH);
 _delay_ms(10);


	 }
		 break;
		 
		 case Right: {
			 
			
			
			
			
			GPIO_WRITE_PIN(Motorport , Motor1IN1 , HIGH);
			GPIO_WRITE_PIN(Motorport , Motor1IN2 , LOW);

			GPIO_WRITE_PIN(Motorport , Motor3IN1 , HIGH);
			GPIO_WRITE_PIN(Motorport , Motor3IN2 , LOW);
	       _delay_ms(10);
			 
		 } break;
			 
		 }
		 }
			
  void motor_stop_4D() {
	  // Stop the motor by setting both direction pins low
       GPIO_WRITE_PIN(Motorport , Motor1IN1 , LOW);
	   GPIO_WRITE_PIN(Motorport , Motor1IN2 , LOW);
	
	    GPIO_WRITE_PIN(Motorport , Motor3IN1 , LOW);
	    GPIO_WRITE_PIN(Motorport , Motor3IN2 , LOW);
	    
	    
	  // Set PWM duty cycle to 0
	    OCR0 = 0;
  }
						 
  
