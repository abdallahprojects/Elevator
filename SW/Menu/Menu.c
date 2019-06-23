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
#include "lcd1602A.h"
#include "GenMenu.h"  // generated list of the menu, do not modify manually

static const menuItem_t *currentMenuItem = &menuItems[0];

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
		currentMenuItem->actionListener();
	}else if(direction == b_back)
	{
		currentMenuItem = currentMenuItem->parent;
	}else{
		//keep executing the current action
		currentMenuItem->actionListener();
	}
	processMenu();
}

void processMenu(void){
	LCD_Clear();
	_delay_ms(50);
	LCD_putrs(currentMenuItem->string);
}
//generated C file
#include "GenMenu.c"

void stubCall(void){
	LCD_Clear();
	LCD_putrs("Press back\n to return!!");
	_delay_ms(2000);
	LCD_Clear();
	LCD_putrs(currentMenuItem->string);
}
