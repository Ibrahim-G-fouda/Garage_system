/*
 * prog_init.h
 *
 * Created: 02/06/2023 11:01:29 ص
 *  Author: handsa
 */ 


#ifndef PROG INIT_H_
#define PROG INIT_H_

#include <avr/io.h>
#define  F_CPU  8000000Ul

#include <util/delay.h>

#include "led_drives.h"
#include "putton_drives.h"
#include "DIO_drives.h"
#include "std_macros1.h"
#include <avr/interrupt.h>
#define dm _delay_ms
#include "lcd.h"
//#include "keyPad_drives.h"
#include "EEPROM drives.h"
#include "ultrasonic_read.h"
#include "I2c_drives.h"
#include "motor_drives.h"
#endif /* PROG INIT_H_ */