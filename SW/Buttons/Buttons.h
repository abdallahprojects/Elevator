/*
 * Button.h
 *
 *  Created on: Jun 8, 2019
 *      Author: asere
 */

#ifndef BUTTONS_BUTTONS_H_
#define BUTTONS_BUTTONS_H_

#ifdef _BUTTONS_C_FILE_
#define EXTERN
#else
#define EXTERN extern
#endif

#define PRESSED_DOWN 3
#define PRESS_RESET 0

typedef enum buttonType_e{
	b_select,
	b_back,
	b_left,
	b_right,
	b_max
}buttonType_t;

//this array is used to map the button to it's corresponding bit field in the AVR PORT


typedef struct button_s{
	buttonType_t Type;
	uint8_t debounce[b_max];
}button_t;

#define Button_Pressed(PA) (!(PINA&(1<<button_map[PA])))

#define BUT_init() do{\
		DDRA &= ~((1<<PA0)|(1<<PA4)|(1<<PA5)|(1<<PA6)); \
		PORTA |= (1<<PA0)|(1<<PA4)|(1<<PA5)|(1<<PA6); \
	}while(0)



bool_t DebouncedPressed(buttonType_t BT);
bool_t DebouncedRelease(buttonType_t BT);
extern uint8_t button_map[b_max];
#endif /* BUTTONS_BUTTONS_H_ */
