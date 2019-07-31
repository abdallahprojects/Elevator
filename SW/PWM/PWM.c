/*
 * PWM.c
 *
 *  Created on: Jul 28, 2019
 *      Author: asere
 */


#include <avr/io.h>
#include <stdint.h>

#include "PWM.h"
void PWM_leftInit(pwm_speed_t pwmSpeed)
{
	TCCR0 |= (1<<WGM00)|(1<<WGM01); // fast PWM mode
	TCCR0 |= (1<<COM01); // non - inverting mode
	TCCR0 &= ~(1<<COM00);
	TCCR0 |= (uint8_t)(pwmSpeed & 0b00000111);
// TCCR initialization end
}
void PWM_leftInitInvMode(pwm_speed_t pwmSpeed)
{
	TCCR0 |= (1<<WGM00)|(1<<WGM01); // fast PWM mode
	TCCR0 |= (1<<COM01); // non - inverting mode
	TCCR0 |= (1<<COM00);
	TCCR0 |= (uint8_t)(pwmSpeed & 0b00000111);
// TCCR initialization end
}
void PWM_rightInitInvMode(pwm_speed_t pwmSpeed)
{
	TCCR2 |= (1<<WGM20)|(1<<WGM21); // fast PWM mode
	TCCR2 |= (1<<COM21); // non - inverting mode
	TCCR2 |= (1<<COM20);
	TCCR2 |= (uint8_t)(pwmSpeed & 0b00000111);
// TCCR initialization end
}

void PWM_rightInit(pwm_speed_t pwmSpeed)
{
	TCCR2 |= (1<<WGM20)|(1<<WGM21); // fast PWM mode
	TCCR2 |= (1<<COM21); // non - inverting mode
	TCCR2 &= ~(1<<COM20);
	TCCR2 |= (uint8_t)(pwmSpeed & 0b00000111);
// TCCR initialization end
}

void PWM_leftSetDutyCycle(uint8_t DutyCycle){
	if(DutyCycle == 0)
	{
		TCCR0 &= ~((1<<COM00)|(1<<COM01)); // No PWM >> Normal Pin
	}else{
		TCCR0 |= (1<<COM01); // non - inverting mode
		OCR0 = (DutyCycle * 255)/100;
	}
}

void PWM_rightSetDutyCycle(uint8_t DutyCycle){
	if(DutyCycle == 0)
	{
		TCCR2 &= ~((1<<COM20)|(1<<COM21)); // No PWM >> Normal Pin
	}else{
		TCCR2 |= (1<<COM21); // non - inverting mode
		OCR2 = (DutyCycle * 255)/100;
	}
}
