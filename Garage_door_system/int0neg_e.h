/*
 * in0neg_e.h
 *
 * Created: 29/06/2023 09:32:48 ص
 *  Author: handsa
 */ 


#ifndef IN0NEG_E_H_
#define IN0NEG_E_H_


SREG|=(1<<7) ; //sei();
set_bit(MCUCR,ISC01);
GICR=GICR|(1<<INT0);




#endif /* IN0NEG_E_H_ */