/*
 * great_safe_project.c
 *
 * Created: 13/07/2023 09:55:11 ص
 *  Author: handsa
 */ 

#include "prog init.h"
#define DOOR_OPEN 0x20
#define DOOR_CLOSE 0x21


#define max 2

char str[10];
volatile char latch1=0,flag=0,latch3=0,latch4=0,latch5=0,door_status=0;
volatile signed char car_count=0;
  //#include "motor_drives.h"
int main(void)
{

   #include "int0pos_e.h"
   #include "int1pos_e.h"
   #include "int2pos_e.h"
 
   flag=1;
  unsigned short dist;
  motor_selective_mode_init('b');
 
  button_init('a',6);
 lcd_init();
 lcd_send_cmd(disp_on_cursor_off);
 i2c_clock_init(50000);

	i2c_start();
	i2c_adress(0b10100000);
i2c_data(0x21);
i2c_stop();
dm(100);
while(1)
{
	
	
	while(flag==1)
	{
	i2c_start();
	i2c_adress(0b10100000);
	i2c_data(0x21);
	i2c_stop();
	dm(100);
	
	i2c_start();
	i2c_adress(0b10100000);
	i2c_data(car_count+48);
	i2c_stop();
	dm(100);
lcd_move_cursor(1,1);
lcd_send_string("distance:");
		lcd_move_cursor(1,10);
		dist=ultra_sonic_read();
		tostring(str,dist);
		lcd_send_string(str);
		lcd_send_char(0x20);
		lcd_send_char(0x20);
		lcd_send_char(0x20);
		lcd_send_char(0x20);
		lcd_send_char(0x20);
		lcd_send_char(0x20);
			lcd_send_char(0x20);
			lcd_send_char(0x20);
		if ((dist<=20))
		{
	anti_clockwise('b');
	flag=0;
	lcd_move_cursor(2,1);
	lcd_send_string("Door open...");
	
	
	door_status=0x20;
	//dm(500);
	
		}
		
	
		}
		
while((flag==0)&&(latch1==1))	//while((flag==0)&&(latch1==0)&&(latch3==1))//door close region 
	{
		if(button_read('a',6)==1)
		{
			
			clockwise('b');
			//flag=1;
			
				lcd_clrscrean();
				lcd_send_string("door close...");
					
			
		latch1=0;
		latch3=1;
		latch4=1;
		car_count++;
		dm(750);/*to ensure that the close limit switch will not stop
		 the motor until close door push button is pressed*/
		
		
		
		 }		
		
		}
		

	
	//while flah ==1
	if (car_count<=max)
	{
		
	
		i2c_start();
		i2c_adress(0b10100000);
		i2c_data(car_count+48);
		i2c_stop();
		dm(150);
		if (car_count==max)
		{
		 lcd_send_cmd(clr_screen);
		 lcd_send_string("The garage is full");
		
		i2c_start();
		i2c_adress(0b10100000);
		i2c_data(0x21);
		i2c_stop();
		dm(100);  while(car_count==max)
		  {
			  
			  
		  }
		}
		
	
	}

i2c_start();
	i2c_adress(0b10100000);
	i2c_data(door_status);
	i2c_stop();
	dm(100);
	}			 
	
	}
	ISR(INT0_vect)//close direction limit switch
		{
	if (latch3==1)	//if ((latch4==1)&&(latch5==1))
		{
		stop_motor('b');
		//latch1=1;
		flag=1;
		latch3=0;
		latch4=0;
		//latch5=0;
		door_status=0x21;
		}
		
	}
	ISR(INT1_vect)//open direction limit switch
	{
		if ((flag==0)&&(latch4==0))
		{
		stop_motor('b');
		dm(1000);
latch1=1;

	//	latch3=1;
		//latch4=1;
		}
		/*to ensure that the close limit switch will not restart the operation until
	open limit switch  is pressed*/		
		
			
	
			
	}
	ISR(INT2_vect)
	{
	car_count--;
	if (car_count<0)
	{
	car_count=0;
	}
	
	
	
	}