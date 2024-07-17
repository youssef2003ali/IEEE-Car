/*
 * bluetooth.c
 *
 * Created: 7/8/2024 1:20:26 PM
 *  Author: DELL
 */ 

#include "Bluetooth.h"
#define Baudrate   9600
void Bluetooth_INIT() {
	
u16 Baud_PreScale = (((F_CPU / (Baudrate * 16UL))) - 1);
//BIT_CLR(UCSRC, UPM0);
//BIT_CLR(UCSRC, UPM1);
//BIT_CLR(UCSRC , UMSEL);
UCSRB |= (1 << RXEN) | (1 << TXEN);/* Turn on transmission and reception */
UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
UBRRL = Baud_PreScale;	/* Load lower 8-bits of the baud rate value */
UBRRH = (Baud_PreScale >> 8);	/* Load upper 8-bits*/ 

}

 // BAUD_PRESCALE = (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
 // according to the frequency
 
 void Send_char(u8 Ch) {
	  /* Wait for empty transmit buffer */
	
	while (! (UCSRA & (1<<UDRE)));  
	 UDR = Ch ;          // UDR is holding the data
 }	
 
 u8 Read_char(void) {
	 while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
	 return(UDR);			/* Return the byte*/
 }
 
 void Send_String(u8* TheString) {
	 u8 i = 0;
	 
	 while (TheString[i] != '\0') {
		 Send_char(TheString[i]);
		 i++;
	 }
 }
 
 void Send_Num(s32 TheNum) {
	 char data[10];
	 itoa( TheNum,data,10);
	 Send_String(data);
 }
 
 unsigned char uart_available(void) {
	 return (UCSRA & (1<<RXC)) ? 1 : 0;
 }
 
 int uart_read_num(void) {
	 char buffer[10];  // Buffer to hold the input string
	 unsigned char i = 0;
	 char ch;

	 // Read characters until newline or buffer is full
	 while (1) {
		 ch = Read_char();  // Read a character
		 if (ch == '\n' || ch == '\r' || i >= sizeof(buffer) - 1) {
			 break;  // Stop reading on newline, carriage return, or buffer full
		 }
		 buffer[i++] = ch;  // Store character in buffer
	 }

	 buffer[i] = '\0';  // Null-terminate the string

	 return atoi(buffer);  // Convert string to integer and return
 }