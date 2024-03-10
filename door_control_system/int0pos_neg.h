/*
 * int0pos_neg.h
 *
 * Created: 29/06/2023 09:41:51 ص
 *  Author: handsa
 */ 


#ifndef INT0POS_NEG_H_
#define INT0POS_NEG_H_

SREG|=(1<<7) ; //sei();
set_bit(MCUCR,ISC00);
clr_bit(MCUCR,ISC01);
GICR=GICR|(1<<INT0);



#endif /* INT0POS_NEG_H_ */