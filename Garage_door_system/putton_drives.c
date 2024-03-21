/*
 * putton_drives.c
 *
 * Created: 19/05/2023 10:21:10 م
 *  Author: handsa
 */ 
#include "DIO_drives.h"
void button_init(char port ,char pin)
{
	dio_set_pin(port,pin,0);
}
unsigned char button_read(char port ,char pin)
{
	return dio_read_pin(port,pin);
}
