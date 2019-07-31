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

void PWM_leftInit(pwm_speed_t pwmSpeed);
void PWM_rightInit(pwm_speed_t pwmSpeed);
void PWM_leftSetDutyCycle(uint8_t DutyCycle);
void PWM_rightSetDutyCycle(uint8_t DutyCycle);
void PWM_leftInitInvMode(pwm_speed_t pwmSpeed);
void PWM_rightInitInvMode(pwm_speed_t pwmSpeed);
#endif /* PWM_PWM_H_ */
