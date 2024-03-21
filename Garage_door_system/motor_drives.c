/*
 * motor_drives.c
 *
 * Created: 09/03/2024 07:17:16 م
 *  Author: handsa
 */ 
#include "DIO_drives.h"
#include "motor_drives.h"
void motor_selective_mode_init(unsigned char port)
{
	#if defined sellective_mode1
	{
		dio_set_pin(port,in11,1);
		dio_set_pin(port,in12,1);	
	}

#endif
}
void clockwise(unsigned char port)
{
	#if defined sellective_mode1
	{
		dio_write_pin(port,in11,1);
		dio_write_pin(port,in12,0);
	}
	#endif

}
void anti_clockwise(unsigned char port)
{
	
	#if defined sellective_mode1
	{
		dio_write_pin(port,in11,0);
		dio_write_pin(port,in12,1);
	}
	#endif
}	
void stop_motor(unsigned char port)
{
	
	#if defined sellective_mode1
	{
		dio_write_pin(port,in11,0);
		dio_write_pin(port,in12,0);
	}
	#endif
}
	