/*
 * BIT_MATH.h
 *
 * Created: 6/24/2024 9:21:30 AM
 *  Author: DELL
 */ 

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define BIT_SET(VAR,POS) VAR |= (1<<POS)    // required bit 1
#define BIT_CLR(VAR,POS) VAR &= ~(1<<POS)  // required bit 0
#define BIT_TGL(VAR,POS) VAR ^= (1<<POS)   // required toggled
#define BIT_GET(VAR,POS) (1&(VAR>>POS))
#define BIT_IS_SET(PORT,PIN) ( PORT & (1<<PIN) )
#define BIT_IS_CLEAR(PORT,PIN) ( !(PORT & (1<<PIN)) )
#endif // BIT_MATH_H_
