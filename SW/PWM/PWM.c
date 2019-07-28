/*
 * PWM.c
 *
 *  Created on: Jul 28, 2019
 *      Author: asere
 */


#include <avr/io.h>
#include <stdint.h>

#include "PWM.h"
void PWM_init(pwm_speed_t pwmSpeed)
{
	TCCR0 |= (1<<WGM00)|(1<<WGM01); // fast PWM mode
	TCCR0 |= (1<<COM01); // non - inverting mode
	TCCR0 &= ~(1<<COM00);
	TCCR0 |= (uint8_t)(pwmSpeed & 0b00000111);
// TCCR initialization end
}

void PWM_setDutyCycle(uint8_t DutyCycle){
	if(DutyCycle == 0)
	{
		TCCR0 &= ~((1<<COM00)|(1<<COM01));
	}else{
		TCCR0 |= (1<<COM01); // non - inverting mode
		OCR0 = (DutyCycle * 255)/100;
	}
}
