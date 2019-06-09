/*
 * main.c
 *
 *  Created on: Apr 21, 2019
 *      Author: Abdallah Helal
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "lcd1602A.h"
#include "common.h"
#include "motor.h"
#include "main.h"
int main(void){
	state_t state = Init;
	button_t Button;
	unsigned char Debounce_Button;
	LCD board1_lcd = {(&PORTC),6,4,5,3,2,1,0};
	unsigned char trigger = 0;


	// main application
	switch(state){
	/************************************************************
	*   Initial state is to print the project name and wait     *
	*   for the user to press the select button, otherwise      *
	*   instructing him to do so.                               *
	*************************************************************/
	case Init:
		// initialization sequence
		INIT_Buttons(); // init buttons
		LCD_Init(board1_lcd);
		_delay_ms(80);
		/* initializing the motor */
		InitMotor;
		LCD_puts("Elevator Project!");
		state = InitToMain;
		break;

	/************************************************************
	*   Initial state to main menu, pressing select is required *
	*   to go from initial state to the main menu and the       *
	*   system options.          			                    *
	*************************************************************/
	case InitToMain:
		if(DebouncedPressed(b_select)){
				state = mainMenu;
		}
		if(DebouncedPressed(b_left)||DebouncedPressed(b_right)||DebouncedPressed(b_back)){
			PressSelectToStart();
		}
		break;

	case mainMenu:
		if(DebouncedPressed(b_left)){
			mainMenu_scroll(b_left);
		}
		if(DebouncedPressed(b_right)){
			mainMenu_scroll(b_right);
		}if(DebouncedPressed(b_back)){
			state = Init;
		}
		if(DebouncedPressed(b_select)){
			state = option[selected];
		}
	default:
		break;
		//do nothing
	}




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


