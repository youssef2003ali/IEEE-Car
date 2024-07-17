/*
 * Bluetooth.h
 *
 * Created: 7/8/2024 1:20:14 PM
 *  Author: DELL
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#define F_CPU 8000000UL		/* Define frequency here its 8MHz */




#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD.h"
#include "DIO.h"

void Bluetooth_INIT();

u8 Read_char(void);

void Send_char (u8 Ch);

void Send_String(u8* TheString);

void Send_Num (s32 TheNum);

unsigned char uart_available(void);

 int uart_read_num(void);
 
#endif /* BLUETOOTH_H_ */