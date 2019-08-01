/*
 * Menu.c
 *
 *  Created on: Jun 13, 2019
 *      Author: asere
 */
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "common.h"
#include "Buttons.h"
#include "Menu.h"
#include "motor.h"
#include "LCD_1602A.h"
#include "ADC.h"
#include "GenMenu.h"  // generated list of the menu, do not modify manually
#include "PWM.h"

static const menuItem_t *currentMenuItem = &menuItems[0];
static const menuItem_t *prevMenuItem = NULL;

void initMenu(void){

}
void mainMenu_scroll(buttonType_t direction){

	if(direction == b_left){
		currentMenuItem = currentMenuItem->prev;
	}else if(direction == b_right)
	{
		currentMenuItem = currentMenuItem->next;
	}else if(direction == b_select)
	{
		currentMenuItem = currentMenuItem->select;
	}else if(direction == b_back)
	{
		currentMenuItem = currentMenuItem->parent;
	}else{
		//keep executing the current action
		currentMenuItem->actionListener(CYCLIC);
	}
}

void processMenu(void){

	if ( currentMenuItem != prevMenuItem)
		{
			LCD_Clear();
			_delay_ms(50);
			LCD_putrs(currentMenuItem->string);
			prevMenuItem = currentMenuItem;
			currentMenuItem->actionListener(INIT);
		}else{
			currentMenuItem->actionListener(CYCLIC);
		}
}
//generated C file
#include "GenMenu.c"

void stubCall(uint8_t init){
// nothing to be done for now, later to be implemented
}
