/*
 * ADC.c
 *
 *  Created on: Jun 30, 2019
 *      Author: asere
 */

#include <avr/io.h>
#include <stdint.h>
#include "common.h"
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
uint32_t ADC_AVG(uint8_t steps,uint8_t chnl){
	uint8_t i;
	uint32_t ADCValue,tmp;
		tmp = 0;
		for(i=0;i<steps;i++)
		{
			tmp += ADC_read(chnl);
		}
		ADCValue = tmp/steps;
		return ADCValue;
}
/*
 * This function will return the amount of consumed current in milliAmps for example:
 * if the consumed current 131.5 milliAmps, CVmA will be 131 and CVmA10th will be 5 respectively.
 * if the return value is false, the current direction is positive,
 * if true the cuurent direction is negative
 */
bool_t GetCurrValue(uint8_t steps,uint8_t chnl,uint16_t * CVmA,uint8_t *CVmA10th){
	bool_t CurrentDirection = 0;
	uint32_t ADCValue;
	uint16_t ADCCurrent;
	uint32_t CurrentValueMilAmp;
	uint32_t CurrentValue10thMilAmp;

		ADCValue =ADC_AVG(steps,chnl);
		ADCCurrent = (ADCValue <512)?(512-ADCValue):(ADCValue-512);
		CurrentValueMilAmp = 26*ADCCurrent;
		CurrentValue10thMilAmp = 3*ADCCurrent;
		CurrentValueMilAmp += CurrentValue10thMilAmp/10;
		CurrentValue10thMilAmp %= 10;
		*CVmA = CurrentValueMilAmp;
		*CVmA10th = CurrentValue10thMilAmp;
		return CurrentDirection;
}
