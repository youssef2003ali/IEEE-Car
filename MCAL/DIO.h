/*************************************		DIO.H			********************************/


#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD.h"


/************************************************************************************************/ 



/******************* PORTS *********************/
#define PORT_A 1
#define PORT_B 2
#define PORT_C 3
#define PORT_D 4
/*********************************************/
#define INPUT 0
#define OUTPUT 1
#define LOW 0
#define HIGH 1
/**************  Declration of functions *****************/

void GPIO_INIT_PORT(u8 PORT,u8 dir); /*  init data direction of port */

void GPIO_INIT_PIN(u8 PORT,u8 PIN,u8 dir); /*  init data direction of pin */

void GPIO_WRITE_PIN(u8 PORT , u8 PIN, u8 value) ; /*   write logical value on pin */

void GPIO_WRITE_PORT(u8 PORT , u8 val) ;/*   write logical value on PORT */

u8 GPIO_READ_PIN(u8 PORT , u8 PIN) ; /* Read logical value from pin */

u8 GPIO_READ_PORT(u8 PORT) ; /* Read logical value from PORT */

u8 GPIO_TGL_PIN(u8 PORT , u8 PIN);

/*********************************************************/
#endif /* DIO_H */