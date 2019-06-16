/*
 * main.c
 *
 *  Created on: Apr 21, 2019
 *      Author: Abdallah Helal
 */

#include <avr/io.h>
#include <util/delay.h>
#include "common.h"
#include "lcd1602A.h"
#include "motor.h"

#include "button.h"

int main(void){
	LCD board1_lcd = {(&PORTC),6,4,5,3,2,1,0};
	uint8_t counter = 0;
	// initialization sequence
	DDRA = 0x00;
	PORTA = 0xff;

	LCD_Init(board1_lcd);

	_delay_ms(80);
	INIT_Buttons();


	/* initializing the motor */

	InitMotor;

	LCD_puts("Elevator Project!");

	while(1)
	{
		if(DebouncedPressed(b_select)){
			counter++;
			if(counter < 10){
					LCD_Clear();
					_delay_ms(20);
					LCD_putc(48+counter);
				}else{
					counter = 0;
				}
		}



	}



	return 0;
}


