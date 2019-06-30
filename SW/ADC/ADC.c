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
	ADMUX |= (1<<ADLAR);
	ADMUX &= ~((1<<REFS1)|(1<<REFS0));

	ADMUX |= (1<<MUX0) | (1<<MUX1); // SET channel 3 for motor current sensor

	ADMUX &= ~((1<<MUX2)|(1<<MUX3)|(1<<MUX4)); // CLEAR the remaining part

	ADCSRA |= (7<<ADPS0);  //SET ADPS0, ADPS1 AND ADPS2 at the same time by shiftting 111 zero time to left



	ADCSRA |= (1<<ADEN); // enable ADC controller
}

adc_status_t ADC_read(uint8_t *ADC_H,uint8_t *ADC_L){
	adc_status_t ret=NOK;

	if(!(ADCSRA &&(1<<ADSC))){
		// adc is ready
		ADCSRA |= (1<<ADSC); // Starting new conv
		while((ADCSRA&&(1<<ADSC)));  //wait for ADSC to be 0
		*ADC_H = ADCH;
		*ADC_L = ADCL;
		ret = OK;
	}else{ // adc is busy
		ret = BUSY;
	}
	return ret;
}
