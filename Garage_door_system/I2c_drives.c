/*
 * I2c_drives.c
 *
 * Created: 20/10/2023 02:04:51 م
 *  Author: handsa
 */ #include "prog init.h"
#define prescaller 1
void i2c_clock_init(unsigned long scl)
{
	TWBR=(unsigned char) (((F_CPU/scl)-16)/(2*prescaller));
	if (prescaller==1)
	{
	TWSR=0;
	}
else if (prescaller==4)
{
TWSR=1;
}
else if (prescaller==16)
{
	TWSR=2;
}
else if (prescaller==64)
{
	TWSR=3;
}
}
void i2c_start(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|((1<<TWSTA));
	while(read_bit(TWCR,TWINT)==0);
	while((TWSR &0xf8)!=0x08); 
//clr_bit(TWCR,TWSTA);
}
void i2c_adress(unsigned char address)
{

TWDR=address;
TWCR=(1<<TWINT)|(1<<TWEN);
		while(read_bit(TWCR,TWINT)==0);
//while(1);
	//lcd_clrscrean();
		while((TWSR &0xf8)!=0x18); 
		//lcd_clrscrean();
}
void i2c_data(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(read_bit(TWCR,TWINT)==0);
	while((TWSR &0xf8)!=0x28);
	
	
}
void i2c_stop(void)
{
TWCR=(1<<TWINT)|(1<<TWEN)|((1<<TWSTO));	
}
void i2c_set_address(unsigned char addres)
{
	TWAR=addres;

}
unsigned char i2c_slave_read(void)
{
		TWCR=(1<<TWINT)|(1<<TWEN)|((1<<TWEA));
			while(read_bit(TWCR,TWINT)==0);
			while((TWSR &0xf8)!=0x60);
			TWCR=(1<<TWINT)|(1<<TWEN)|((1<<TWEA));
			while(read_bit(TWCR,TWINT)==0);
				while((TWSR &0xf8)!=0x80);
				return TWDR;
		
}