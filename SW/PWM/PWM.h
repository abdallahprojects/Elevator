/*
 * PWM.h
 *
 *  Created on: Jul 28, 2019
 *      Author: asere
 */

#ifndef PWM_PWM_H_
#define PWM_PWM_H_

typedef enum PWM_Speed_E{
	pwm_stop,
	pwm_32us,
	pwm_256us,
	pwm_2ms,
	pwm_8ms,
	pwm_32ms,
	ext_pin0_falling,
	ext_pin0_rising
}pwm_speed_t;

void PWM_init(pwm_speed_t pwmSpeed);
void PWM_setDutyCycle(uint8_t DutyCycle);

#endif /* PWM_PWM_H_ */
