/*
 * main.c
 *
 *  Created on: Apr21, 2019
 *      Author: AbdallahHelal
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "lcd1602A.h"
#include "common.h"
#include "motor.h"
#include "Buttons.h"
#include "main.h"
#include "Menu.h"
int main(void){
	state_t state = Init;
	LCD board1_lcd = {(&PORTC),6,4,5,3,2,1,0};
	uint8_t buttonState[b_max]={0,0,0,0};
	buttonType_t button;

	// main application
while(true){
	switch(state){
	/************************************************************
	*   Initial state is to print the project name and move     *
	*   to the main menu.									    *
	*   						                                *
	*************************************************************/
	case Init:
		// initialization sequence
		INIT_Buttons(); // init buttons
		LCD_Init(board1_lcd);
		_delay_ms(80);
		/* initializing the motor */
		InitMotor;
		LCD_puts("Elevator Project!");
		state = mainMenu;
		break;

		/************************************************************
		*   Main state and main menu, pressing select is required   *
		*   to start the main menu and the display the              *
		*   system options.          			                    *
		*************************************************************/
	case mainMenu:
		// Check all buttons if they are pressed
		for(button=b_select;button<=b_right;button++)
			{
				buttonState[button] |= (DebouncedPressed(button)&&buttonState[button]);
				buttonState[button] |= DebouncedRelease(button)<<1;

			}
		if(buttonState[b_left]==PRESSED_DOWN){
			mainMenu_scroll(b_left);
			buttonState[b_left]=0;
		}
		if(buttonState[b_right]==PRESSED_DOWN){
			mainMenu_scroll(b_right);
			buttonState[b_right]=PRESS_RESET;
		}if(buttonState[b_back]==3){
			mainMenu_scroll(b_back);
			buttonState[b_back]=PRESS_RESET;
		}
		if(buttonState[b_select]==PRESSED_DOWN){
			mainMenu_scroll(b_select);
			buttonState[b_select]=PRESS_RESET;
		}
		state = mainMenu;
		break;
	default:
		break;
		//do nothing
	}
}

	return 0;
}


