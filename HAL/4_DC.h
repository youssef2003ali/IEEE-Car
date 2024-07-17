/*
 * _4_DC.h
 *
 * Created: 7/12/2024 6:28:33 PM
 *  Author: DELL
 */ 


 /*  3        1 
 
     4        2
              */
#ifndef DC_H_
#define DC_H_

#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD.h"
#include "DIO.h"
#include "Timer.h"
#include <util/delay.h>
#define  Motorport PORT_C
#define  Motor1IN1 0
#define  Motor1IN2 1
#define  Motor3IN1 6
#define  Motor3IN2 7




typedef enum {
	Forward,
	Backward,
	Left	,
	Right	
} Direction ;

void Motors_INIT_4D();
void motor_set_direction_4D(Direction direction);
void motor_stop_4D();
void motor_set_speed(u8 speed);




#endif /* 4_DC_H_ */