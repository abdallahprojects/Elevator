/*
 * ADC.c
 *
 *  Created on: Jun 30, 2019
 *      Author: asere
 */

#include <avr/io.h>
#include <stdint.h>
#include "ADC.h"

void ADC_init(void){
	//ADMUX |= (1<<ADLAR); // Left adjust
	ADMUX &= ~((1<<REFS1)|(1<<REFS0));

	ADMUX |= (1<<MUX0) | (1<<MUX1); // SET channel 3 for motor current sensor

	ADMUX &= ~((1<<MUX2)|(1<<MUX3)|(1<<MUX4)); // CLEAR the remaining part

	ADCSRA |= (7<<ADPS0);  //SET ADPS0, ADPS1 AND ADPS2 at the same time by shiftting 111 zero time to left



	ADCSRA |= (1<<ADEN); // enable ADC controller
}

int ADC_read(char channel){
	int Ain,AinLow;

	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */

//	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and
					Multiply with weight */
	Ain = Ain + AinLow;
	return(Ain);			/* Return digital value*/
}
