/*
 * Menu.h
 *
 *  Created on: Jun 13, 2019
 *      Author: asere
 */

#ifndef MENU_MENU_H_
#define MENU_MENU_H_

#define INIT 1
#define CYCLIC 0
// ADC value iterations
#define RES 20


typedef struct menuItem_s{
	const char * string;
	void (*actionListener)(uint8_t init);
	const struct menuItem_s * parent;
	const struct menuItem_s * next;
	const struct menuItem_s * prev;
	const struct menuItem_s * select;
}menuItem_t;



void initMenu(void);
void mainMenu_scroll(buttonType_t direction);

void processMenu(void);

#endif /* MENU_MENU_H_ */
