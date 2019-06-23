/*
 * Menu.h
 *
 *  Created on: Jun 13, 2019
 *      Author: asere
 */

#ifndef MENU_MENU_H_
#define MENU_MENU_H_

typedef struct menuItem_s{
	const char * string;
	void (*actionListener)(void);
	const struct menuItem_s * parent;
	const struct menuItem_s * next;
	const struct menuItem_s * prev;
}menuItem_t;



void initMenu(void);
void mainMenu_scroll(buttonType_t direction);

void processMenu(void);

#endif /* MENU_MENU_H_ */
