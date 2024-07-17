/*
 * Line_Tracker.h
 *
 * Created: 7/8/2024 11:04:00 PM
 *  Author: DELL
 */ 


#ifndef LINE_TRACKER_H_
#define LINE_TRACKER_H_


#include "STD.h"
#include "DIO.h"
#include "4_DC.h"
#include "ULTRA_SONIC.h"

#define IR_PORT   PORT_A
#define IR_Right  6
#define IR_Left   7

void Line_Track_INIT();
void Follow_Line();
void Self_Drive();



#endif /* LINE_TRACKER_H_ */