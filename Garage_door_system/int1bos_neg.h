/*
 * int1bos_neg.h
 *
 * Created: 29/06/2023 10:44:51 ص
 *  Author: handsa
 */ 


#ifndef INT1BOS_NEG_H_
#define INT1BOS_NEG_H_

SREG|=(1<<7) ; //sei();
set_bit(MCUCR,ISC10);
clr_bit(MCUCR,ISC11);
GICR=GICR|(1<<INT1);





#endif /* INT1BOS_NEG_H_ */