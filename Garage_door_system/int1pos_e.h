/*
 * int1pos_e.h
 *
 * Created: 29/06/2023 10:39:40 ص
 *  Author: handsa
 */ 


#ifndef INT1POS_E_H_
#define INT1POS_E_H_

MCUCR=MCUCR|(1<<ISC10)|(1<<ISC11);
GICR=GICR|(1<<INT1);
sei();




#endif /* INT1POS_E_H_ */