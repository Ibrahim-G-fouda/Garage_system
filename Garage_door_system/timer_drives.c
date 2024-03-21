/*
 * timer_drives.c
 *
 * Created: 01/09/2023 03:56:09 م
 *  Author: handsa
 */ 
#include "DIO_drives.h"
#include "std_macros1.h"
#define  F_CPU  8000000Ul

#include <util/delay.h>
#include <avr/interrupt.h>
void timer_ctc_init(void)
{
	set_bit(TCCR0,WGM01);
	OCR0=80;
	set_bit(TCCR0,CS00);
	set_bit(TCCR0,CS02);
	sei();
	set_bit(TIMSK,OCIE0);
}
void pwm_ctc(unsigned short freq,unsigned short prescaller)
{
	char ocr;
	dio_set_pin('b',3,1);
	set_bit(TCCR0,WGM01);
	ocr=((float)(F_CPU/(2*prescaller*freq))-1);
OCR0=ocr;
	set_bit(TCCR0,CS00);
	set_bit(TCCR0,CS02);
	set_bit(TCCR0,COM00);
}
void timer2_ovf_sec_init(void)
{
	set_bit(ASSR,AS2);//clock sellect from TCSC1,TCST2
	set_bit(TCCR2,CS20);//prescaller 128
	set_bit(TCCR2,CS22);
	sei();
	set_bit(TIMSK,TOIE2);
	
	
	
	
	
}
void tim0_fast_pwm(unsigned char oocr)
{
	sei();//enable interrupt
	set_bit(TIMSK,TOIE0);//enable overflow interrupt
	
	//set_bit(DDRB,3);//set oc1 as output
	set_bit(TCCR0,WGM00);
		set_bit(TCCR0,WGM01);
		OCR0=64;// duty cycle =25%
		set_bit(TCCR0,CS00);/*prescaller =1024
		*/
		set_bit(TCCR0,CS02);
			set_bit(TCCR0,COM01);
				

}
