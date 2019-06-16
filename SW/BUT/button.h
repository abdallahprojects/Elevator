/*
 * button.h
 *
 *  Created on: Jun 16, 2019
 *      Author: asere
 */

#ifndef BUT_BUTTON_H_
#define BUT_BUTTON_H_


#ifdef _BUTTON_C_FILE_
#define EXTERN
#else
#define EXTERN extern
#endif

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


#define INIT_Buttons() do{\
		DDRA &= ~((1<<PA0)|(1<<PA4)|(1<<PA5)|(1<<PA6)); \
		PORTA |= (1<<PA0)|(1<<PA4)|(1<<PA5)|(1<<PA6); \
	}while(0)



bool_t DebouncedPressed(buttonType_t BT);
bool_t DebouncedUnpressed(buttonType_t BT);


#endif /* BUT_BUTTON_H_ */
