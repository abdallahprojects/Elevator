/*
 * ADC.h
 *
 *  Created on: Jun 30, 2019
 *      Author: asere
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

typedef enum ADC_CH{
	MOTOR_VOLT1 = 1,
	MOTOR_VOLT2,
	MOTOR_CURRENT
}adc_ch_t;



typedef enum ADC_STAT{
	BUSY = 1,
	OK,
	NOK
}adc_status_t;


void ADC_init(void);
adc_status_t ADC_read(uint8_t *ADC_H,uint8_t *ADC_L);


#endif /* ADC_ADC_H_ */
