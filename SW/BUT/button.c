/*
 * button.c
 *
 *  Created on: Jun 16, 2019
 *      Author: asere
 */

#define _BUTTON_C_FILE_
#include "common.h"

#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>

#include "button.h"

static button_t Button;
static const uint8_t button_map[b_max] = {PA0,PA6,PA4,PA5};

bool_t DebouncedPressed(buttonType_t BT){
	bool_t DebouncedPress = false;
	for(Button.debounce[BT] = 0;(Button.debounce[BT]<20)&&(Button_Pressed(BT));Button.debounce[BT]++)
	_delay_ms(2);
	if(Button.debounce[BT] == 20)
		DebouncedPress = true;
	return DebouncedPress; }

	bool_t DebouncedUnpressed(buttonType_t BT){
		bool_t DebouncedPress = false;
		for(Button.debounce[BT] = 0;(Button.debounce[BT]<20)&&(!Button_Pressed(BT));Button.debounce[BT]++)
		_delay_ms(2);
		if(Button.debounce[BT] == 20)
			DebouncedPress = true;
		return DebouncedPress;

}
