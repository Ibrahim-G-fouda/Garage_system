/*
 * led_drives.c
 *
 * Created: 19/05/2023 02:38:35 م
 *  Author: handsa
 */ 
#include <avr/io.h>
#include "DIO_drives.h"
void led_init(char port,char pin)
{
	dio_set_pin(port,pin,1);
	
}
void led_on(char port,char pin)
{
	dio_write_pin(port ,pin,1);
	
}
void led_off(char port,char pin)
{
	dio_write_pin(port ,pin,0);
	
}
void led_toggle(char port,char pin)
{
	dio_toggle_pin(port,pin);
}
unsigned char led_status(char port,char pin)
{
	return dio_read_pin(port,pin);
}
void led_port_init(unsigned char port)
{
	dio_set_port(port,255);
}
void led_port_on( char port)
{
	dio_write_port(port,255);
}
void led_port_off( char port)
{
	dio_write_port(port,0);
}