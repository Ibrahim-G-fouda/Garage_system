/*
 * led_drives.h
 *
 * Created: 19/05/2023 02:39:01 م
 *  Author: handsa
 */ 


#ifndef LED_DRIVES_H_
#define LED_DRIVES_H_
void led_init(char port,char pin);
void led_on(char port,char pin);
void led_off(char port,char pin);
void led_toggle(char port,char pin);
void led_port_init(char port);
unsigned char led_status(char port,char pin);
void led_port_on(unsigned char port);
void led_port_off( char port);
#endif /* LED_DRIVES_H_ */