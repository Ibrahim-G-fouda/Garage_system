/*
 * int2neg_e.h
 *
 * Created: 29/06/2023 10:54:42 ص
 *  Author: handsa
 */ 


#ifndef INT2NEG_E_H_
#define INT2NEG_E_H_
SREG|=(1<<7) ; //sei();
clr_bit(MCUCSR,ISC2);
GICR=GICR|(1<<INT2);






#endif /* INT2NEG_E_H_ */