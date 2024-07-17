

#include <avr/io.h>
#include <util/delay.h>
#include "ADC_Driver.h"
#include "Timer.h"
#include "Bluetooth.h"
#include "ULTRA_SONIC.h"
#include "Car_Modes.h"
#define F_CPU 8000000UL
#include "Line_Tracker.h"

//
typedef enum {
	RemoteControl,
	AutoPilot,
	HighWay,
	Parking
} MODES ;

int main(void){
	
	Line_Track_INIT();
	Bluetooth_INIT();
	
	GPIO_INIT_PIN(PORT_A,0,OUTPUT); //green
	GPIO_INIT_PIN(PORT_A,1,OUTPUT); //yellow
	GPIO_INIT_PIN(PORT_A,2,OUTPUT); //RED
	Motors_INIT_4D();
	MODES The_Selected = RemoteControl ;
	u8 Char;
	Send_char('\n');
	Send_String("Welcome");
	Send_char('\n');
	while (1) {
		if(uart_available()) {
		Char = Read_char();
		_delay_ms(20);
		Send_char(Char);
		_delay_ms(10);
		Send_char('\n');
		}
		if (Char == 'x') {
			

			Send_String("           select mode.... R:Remote   A:Auto-Pilot  H:HighWay  P:Parking      ");
			_delay_ms(10);
			Send_char('\n');
			Char = Read_char();
			_delay_ms(20);
			Send_char(Char);
			_delay_ms(10);
			Send_char('\n');
			switch(Char){
				case 'R' : The_Selected = RemoteControl;  break;
				case 'A' : The_Selected = AutoPilot;      break;
				case 'H' : The_Selected = HighWay;        break;
				case 'P' : The_Selected = Parking;        break;
				
			}
			
			
			switch(The_Selected) {
				case RemoteControl: {
					_delay_ms(10);
					Send_char('\n');
					_delay_ms(10);
					Send_String("     To exit the mode : press x     ");
					_delay_ms(10);
					Send_char('\n');
					_delay_ms(10);
					Char = 		Normal_CAR_MOD();
					
				}break;
				
				case AutoPilot: {
					
					_delay_ms(10);
					Send_String("       Auto Pilot Activated      ");
					Send_char('\n');
					_delay_ms(10);
				
					Char = 			Auto_Pilot_MODE();
					
				}break;
				
				case HighWay: {
					
					_delay_ms(10);
					Send_String("      High Way Mode Activated     ");
					_delay_ms(10);
					Send_char('\n');
					_delay_ms(10);
					
					Char = 		High_Way_MODE();
					
					
				}break;
				
				
			}
			
			
		}
		
		
	}
return 0; }
