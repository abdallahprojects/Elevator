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
int ADC_read(char channel);
uint32_t ADC_AVG(uint8_t steps,uint8_t chnl);
bool_t GetCurrValue(uint8_t steps,uint8_t chnl,uint16_t * CVmA,uint8_t *CVmA10th);

#endif /* ADC_ADC_H_ */
