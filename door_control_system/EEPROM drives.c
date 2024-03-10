/*
 * EEPROM.c
 *
 * Created: 14/06/2023 09:03:01 ص
 *  Author: handsa
 */ 
#include <avr/io.h>	
#include "std_macros1.h"
void EEPROM_write(const unsigned short address,unsigned char data)
{
	EEAR=address;
	EEDR=data;
	set_bit(EECR,EEMWE);
	set_bit(EECR,EEWE);
	while(read_bit(EECR,EEWE)==1);
	{
		
	}
}
unsigned char EEPROM_read(const unsigned short address)
{
EEAR=address;
set_bit(EECR,EERE);
return EEDR;
	
}