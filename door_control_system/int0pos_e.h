/*
 * int0pos_e.h
 *
 * Created: 29/06/2023 09:22:26 ص
 *  Author: handsa
 */ 


#ifndef INT0POS_E_H_
#define INT0POS_E_H_


sei();//SREG|=(1<<7) ; 
MCUCR=MCUCR|(1<<ISC00)|(1<<ISC00);
GICR=GICR|(1<<INT0);




#endif /* INT0POS_E_H_ */