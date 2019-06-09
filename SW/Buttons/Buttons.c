/*
 * Buttons.c
 *
 *  Created on: Jun 8, 2019
 *      Author: asere
 */
#define _BUTTONS_C_FILE_

#include "common.h"
#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>


#include "Buttons.h"

static button_t Button;


bool_t DebouncedPressed(buttonType_t BT){
	bool_t DebouncedPress = false;
	for(Button.debounce[BT] = 0;(Button.debounce[BT]<20)&&(Button_Pressed(BT));Button.debounce[BT]++)
	_delay_ms(20);
	if(Button.debounce[BT] == 20)
		DebouncedPress = true;
	return DebouncedPress;

}
