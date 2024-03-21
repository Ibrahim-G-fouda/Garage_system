/*
 * ultrasonic_read.c
 *
 * Created: 20/03/2024 02:33:25 ص
 *  Author: handsa
 */ 
#include <avr/io.h>
#define  F_CPU  8000000Ul

#include <util/delay.h>
#include "std_macros1.h"
#include "i_to_string.h"
unsigned short A,B,HIGH,DISTANCE;
extern char arr[10];
unsigned short ultra_sonic_read(void)
{
	TCCR1A=0;
	TIFR|=(1<<ICF1);
	set_bit(DDRC,2);
	TIFR|=(1<<ICF1);
	set_bit(PORTC,2);
	_delay_us(50);
	clr_bit(PORTC,2);
	_delay_us(50);
	TCCR1B=0xc1;
	while((TIFR&(1<<ICF1))==0);//wait for rising edge
	A=ICR1;
	TIFR|=(1<<ICF1);
	TCCR1B=0x81;
		while((TIFR&(1<<ICF1))==0);//wait for falling edge
		B=ICR1;
			TIFR|=(1<<ICF1);
			TCCR1B=0;
			TCNT0=0;
			HIGH=B-A;
			DISTANCE=((34600*HIGH)/(F_CPU*2));
		return DISTANCE;
	
	
}