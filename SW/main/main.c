/*
 * main.c
 *
 *  Created on: Apr 21, 2019
 *      Author: Abdallah Helal
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd1602A.h"


int main(void){
	LCD board1_lcd = {(&PORTC),6,4,5,3,2,1,0};
	unsigned char trigger = 0;
// initialization sequence
	DDRA = 0x00;



	LCD_Init(board1_lcd);
	_delay_ms(80);
	LCD_puts("Forward Direction !!");

	/* initializing the motor */

	DDRB=0xff;
	DDRD=0xff;


	PORTB |= (1<<PB0) | (1<<PB3);

	PORTD &= ~(1<<PD7);


	while(1){
		if(PINA&(PA1))
		{
			trigger |= 1;
		}
		if(trigger == 1)
		{
			trigger = 3; // trigger = 11
			LCD_Clear();
			_delay_ms(80);
			LCD_puts("Backward Direction !!");
			PORTB &= ~(1<<PB0);
			_delay_ms(4000);

			PORTB |= (1<<PB0);

			PORTB &= ~(1<<PB3);

			PORTD |= (1<<PD7);



		}


	}


	return 0;
}
