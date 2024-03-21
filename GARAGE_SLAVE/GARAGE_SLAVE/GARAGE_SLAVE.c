/*
 * GARAGE_SLAVE.c
 *
 * Created: 20/03/2024 03:27:40 م
 *  Author: handsa
 */ 

#include "prog init.h"
#define DOOR_OPEN 0x20
#define DOOR_CLOSE 0x21
#include <avr/io.h>

int main(void)
{
		
   unsigned char x='0';
   i2c_set_address(0b10100001);

   lcd_init();
 lcd_send_cmd(disp_on_cursor_off);
    while(1)
    {
       x=i2c_slave_read();
	   
	   if ((x==DOOR_CLOSE))
	   {

	      lcd_move_cursor(1,2);
  	  lcd_send_string("door cls");
	   }
	  if((x==DOOR_OPEN))
	   {
		   
  	  lcd_move_cursor(1,2);
  	  lcd_send_string("door opn");
    }
if (x=='1')
{
lcd_move_cursor(2,2);
lcd_send_string("car num=");
	lcd_send_char('1');
}
else if (x=='2')
{
	lcd_move_cursor(2,2);
	lcd_send_string("car num=");
		lcd_send_char('2');
}
else if (x=='3')
{
	lcd_move_cursor(2,2);
	lcd_send_string("car num=");
		lcd_send_char('3');
}
else if (x=='4')
{
	lcd_move_cursor(2,2);
	lcd_send_string("car num=");
	lcd_send_char('4');
}
else if (x=='0')
{
	lcd_move_cursor(2,2);
	lcd_send_string("car num=");
	lcd_send_char('0');
}
}
}