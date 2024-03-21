/*
 * timer_drives.h
 *
 * Created: 01/09/2023 03:56:32 م
 *  Author: handsa
 */ 


#ifndef TIMER_DRIVES_H_
#define TIMER_DRIVES_H_
void timer_ctc_init(void);
//volatile unsigned int timer_count=0;
void pwm_ctc(unsigned short freq,unsigned short prescaller);
void timer2_ovf_sec_init(void);
void tim0_fast_pwm(unsigned char oocr);
#endif /* TIMER_DRIVES_H_ */