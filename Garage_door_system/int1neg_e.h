/*
 * int1neg_e.h
 *
 * Created: 29/06/2023 10:41:44 ص
 *  Author: handsa
 */ 


#ifndef INT1NEG_E_H_
#define INT1NEG_E_H_
SREG|=(1<<7) ; //sei();
set_bit(MCUCR,ISC11);
clr_bit(MCUCR,ISC10);
GICR=GICR|(1<<INT1);






#endif /* INT1NEG_E_H_ */