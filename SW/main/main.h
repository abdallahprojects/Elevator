/*
 * main.h
 *
 *  Created on: Jun 6, 2019
 *      Author: asere
 */

#ifndef MAIN_MAIN_H_
#define MAIN_MAIN_H_


typedef	enum state_e{
	Init,
	mainMenu
}state_t;

#define PressSelectToStart() do{\
		LCD_Clear();\
		_delay_ms(200);\
		LCD_puts("Press Select to start !!");\
		_delay_ms(2000);\
		LCD_Clear();\
		_delay_ms(200);\
		LCD_puts("Elevator Project!");\
	}while(0)

#endif /* MAIN_MAIN_H_ */
