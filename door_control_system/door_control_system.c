/*
 * great_safe_project.c
 *
 * Created: 13/07/2023 09:55:11 ص
 *  Author: handsa
 */ 

#include "prog init.h"
#define prom_status 0x20
#define prom_loc_1 0x21
#define  prom_loc_2 0x22
#define prom_loc_3 0x23
#define prom_loc_4 0x24
#define prom_loc_5 0x25
#define max_tries 2
#define NOTPRESSED 0xff
char arr[5];
volatile char latch1=0,flag=0,latch3=0,latch4=0,latch5=0;
  #include "motor_drives.h"
int main(void)
{

   #include "int0pos_e.h"
   #include "int1pos_e.h"
   char value= NOTPRESSED;
   char i=0;
   char tries=max_tries;
   flag=1;
  
  motor_selective_mode_init('b');
  //// led_init('a',4);
  //  led_init('a',5);
  button_init('a',6);
 lcd_init();
   keypad_init('c');
   if (EEPROM_read(prom_status)==NOTPRESSED)
   {
   lcd_send_string("set pass:");
   for (i=0;i<=4;i++)//we have 5 digit
   {
  do 
  {
  value=keypad_read('c');
  } while (value==NOTPRESSED);
 EEPROM_write(prom_loc_1+i,value);
lcd_send_char(value);
dm(250);
lcd_move_cursor(1,10+i);
lcd_send_char('*');
 }
   EEPROM_write(prom_status,0x00);
   }
while(1)
{
	while(flag==1)
	{
		arr[0]=	arr[1]=	arr[2]=	arr[3]=	arr[4]=0xff;
		lcd_send_cmd(clr_screen);;
		lcd_send_string("enter pass:");
		for (i=0;i<=4;i++)
		{
			do
			{
				arr[i]=keypad_read('c');
			} while (arr[i]==NOTPRESSED);
			lcd_send_char(arr[i]);
			dm(250);
			lcd_move_cursor(1,12+i);
			lcd_send_char('*');
			
		}
		if (EEPROM_read(prom_loc_1)==arr[0]&&EEPROM_read(prom_loc_2)==arr[1]&&EEPROM_read(prom_loc_3)==arr[2]&&EEPROM_read(prom_loc_4)==arr[3]&&EEPROM_read(prom_loc_5)==arr[4])
		{
			lcd_send_cmd(clr_screen);;
			lcd_send_string("right pass");
			dm(1000);
			//led_on('a',4);
			anti_clockwise('b');
		lcd_move_cursor(2,1);
			lcd_send_string("Door open...");
			dm(1000);
			lcd_send_cmd(cursor_off_disp_off);
			dm(600);
			lcd_send_cmd(disp_on_cursor_off);
			dm(600);
			lcd_send_cmd(cursor_off_disp_off);
			dm(600);
			lcd_send_cmd(disp_on_cursor_off);
			dm(600);
			lcd_send_cmd(cursor_off_disp_off);
			dm(600);
			lcd_send_cmd(disp_on_cursor_off);
			
			flag=0;
			latch1=0;
		}
		else
		{
			tries--;
			if (tries>0)
			{
				lcd_send_cmd(clr_screen);;
				lcd_send_string("wrong pass try again");
				lcd_move_cursor(2,1);
				lcd_send_string("tries left:");
				lcd_send_char(tries+48);
				dm(1000);

				
			}


			else
			{
				lcd_send_cmd(clr_screen);;
				lcd_send_string("permanent locked");
				dm(1000);
				lcd_send_cmd(cursor_off_disp_off);
				dm(600);
				lcd_send_cmd(disp_on_cursor_off);
				dm(600);
				lcd_send_cmd(cursor_off_disp_off);
				dm(600);
				lcd_send_cmd(disp_on_cursor_off);
				dm(600);
				lcd_send_cmd(cursor_off_disp_off);
				dm(600);
				lcd_send_cmd(disp_on_cursor_off);
			
				flag=2;
				//led_on('a',5);
			}
		}
	}
	while((flag==0)&&(latch1==0)&&(latch3==1))//door close region 
	{
		if(button_read('a',6)==1)
		{
			
			clockwise('b');
			//flag=1;
			
				lcd_send_cmd(clr_screen);;
				lcd_send_string("door close...");
				dm(1000);
				lcd_send_cmd(cursor_off_disp_off);
				dm(600);
				lcd_send_cmd(disp_on_cursor_off);
				dm(600);
				lcd_send_cmd(cursor_off_disp_off);
				dm(600);
				lcd_send_cmd(disp_on_cursor_off);
				dm(600);
				lcd_send_cmd(cursor_off_disp_off);
				dm(600);
				lcd_send_cmd(disp_on_cursor_off);
		latch3=0;
		latch5=1;/*to ensure that the close limit switch will not stop
		 the motor until close door push button is pressed*/
		}
		
}
}
	}
	ISR(INT0_vect)//close direction limit switch
		{
		if ((latch4==1)&&(latch5==1))
		{
		stop_motor('b');
		latch1=1;
		flag=1;
		latch4=0;
		latch5=0;
		}
		
	}
	ISR(INT1_vect)//open direction limit switch
	{
			stop_motor('b');
		dm(1000);
		latch3=1;
		latch4=1;/*to ensure that the close limit switch will not restart the operation until
	open limit switch  is pressed*/
			
	}