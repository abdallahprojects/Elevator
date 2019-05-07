/*
 * main.c
 *
 *  Created on: Apr 21, 2019
 *      Author: Abdallah Helal
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd1602A.h"
#include "motor.h"

int main(void){
	LCD board1_lcd = {(&PORTC),6,4,5,3,2,1,0};
	unsigned char trigger = 0;
	// initialization sequence
	DDRA = 0x00;
	PORTA = 0xff;

	LCD_Init(board1_lcd);

	_delay_ms(80);



	/* initializing the motor */

	InitMotor;

	LCD_puts("Elevator Project!");

	while (trigger == 0 )
	{
		if(!(PINA&(PA1)))
		{
			trigger = 1;
		}
	}
	while(1)
	{



		while(trigger==1)
		{

			LCD_Clear();
			_delay_ms(200);
			LCD_puts("FW Direction !!");

			MotorDisable;
			MotorOff;
			_delay_ms(1000);
			MotorEnable;
			MotorOnLeft;

			while(trigger==1)
			{
				if(!(PINA&(PA1)))
				{
					trigger = 2;

				}

			}

		}
		while (trigger == 2 )
		{

			LCD_Clear();
			_delay_ms(200);
			LCD_puts("BW Direction !!");

			MotorDisable;
			MotorOff;
			_delay_ms(1000);

			MotorEnable;
			MotorOnRight;


			while(trigger ==2)
			{


				if(!(PINA&(PA1)))
				{
					trigger = 1;


				}
			}
		}



	}



	return 0;
}


