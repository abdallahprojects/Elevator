// Call backs funtion prototypes:
void stubCall(void);
// The following callback is for ("Press select \nto start !!") menu item 
void callBack0(void);
// The following callback is for ("About ..") menu item 
void callBack1(void);
// The following callback is for ("Developed by ..") menu item 
void callBack2(void);
// The following callback is for ("Hardware Version\nV2.0") menu item 
void callBack5(void);
// The following callback is for ("Motor Control ..") menu item 
void callBack8(void);
// The following callback is for ("Turn Left") menu item 
void callBack9(void);
// The following callback is for ("Turn Right") menu item 
void callBack10(void);
// The following callback is for ("Turn OFF") menu item 
void callBack11(void);
// The following callback is for ("Turn both ON") menu item 
void callBack12(void);
// The following callback is for ("Read Voltage ..") menu item 
void callBack13(void);
// The following callback is for ("Read Current ..") menu item 
void callBack14(void);
// The following callback is for ("Elevator ..") menu item 
void callBack15(void);
// Defining the menu items structs in flash memory
const menuItem_t menuItems[] 	= {
									{
									 //  This is element number (0) calling -> 1
	 	 	 	 	 	 	 	 	 "Press select \nto start !!",
									 &callBack0,
									 &menuItems[0],
									 &menuItems[0],
									 &menuItems[0],
									},
									{
									 //  This is element number (1) calling -> 2
	 	 	 	 	 	 	 	 	 "About ..",
									 &callBack1,
									 &menuItems[0],
									 &menuItems[8],
									 &menuItems[15],
									},
									{
									 //  This is element number (2) calling -> 3
	 	 	 	 	 	 	 	 	 "Developed by ..",
									 &callBack2,
									 &menuItems[1],
									 &menuItems[5],
									 &menuItems[7],
									},
									{
									 //  This is element number (3) calling -> 3
	 	 	 	 	 	 	 	 	 "Author:\nAbdallah Helal",
									 &stubCall,
									 &menuItems[2],
									 &menuItems[4],
									 &menuItems[4],
									},
									{
									 //  This is element number (4) calling -> 4
	 	 	 	 	 	 	 	 	 " SW 3.11 HW V2.0",
									 &stubCall,
									 &menuItems[2],
									 &menuItems[3],
									 &menuItems[3],
									},
									{
									 //  This is element number (5) calling -> 6
	 	 	 	 	 	 	 	 	 "Hardware Version\nV2.0",
									 &callBack5,
									 &menuItems[1],
									 &menuItems[7],
									 &menuItems[2],
									},
									{
									 //  This is element number (6) calling -> 6
	 	 	 	 	 	 	 	 	 "Version 2.0 ",
									 &stubCall,
									 &menuItems[5],
									 &menuItems[6],
									 &menuItems[6],
									},
									{
									 //  This is element number (7) calling -> 7
	 	 	 	 	 	 	 	 	 "Software Version\nV1.1",
									 &stubCall,
									 &menuItems[1],
									 &menuItems[2],
									 &menuItems[5],
									},
									{
									 //  This is element number (8) calling -> 9
	 	 	 	 	 	 	 	 	 "Motor Control ..",
									 &callBack8,
									 &menuItems[0],
									 &menuItems[13],
									 &menuItems[1],
									},
									{
									 //  This is element number (9) calling -> 9
	 	 	 	 	 	 	 	 	 "Turn Left",
									 &callBack9,
									 &menuItems[8],
									 &menuItems[10],
									 &menuItems[12],
									},
									{
									 //  This is element number (10) calling -> 10
	 	 	 	 	 	 	 	 	 "Turn Right",
									 &callBack10,
									 &menuItems[8],
									 &menuItems[11],
									 &menuItems[9],
									},
									{
									 //  This is element number (11) calling -> 11
	 	 	 	 	 	 	 	 	 "Turn OFF",
									 &callBack11,
									 &menuItems[8],
									 &menuItems[12],
									 &menuItems[10],
									},
									{
									 //  This is element number (12) calling -> 12
	 	 	 	 	 	 	 	 	 "Turn both ON",
									 &callBack12,
									 &menuItems[8],
									 &menuItems[9],
									 &menuItems[11],
									},
									{
									 //  This is element number (13) calling -> 13
	 	 	 	 	 	 	 	 	 "Read Voltage ..",
									 &callBack13,
									 &menuItems[0],
									 &menuItems[14],
									 &menuItems[8],
									},
									{
									 //  This is element number (14) calling -> 14
	 	 	 	 	 	 	 	 	 "Read Current ..",
									 &callBack14,
									 &menuItems[0],
									 &menuItems[15],
									 &menuItems[13],
									},
									{
									 //  This is element number (15) calling -> 16
	 	 	 	 	 	 	 	 	 "Elevator ..",
									 &callBack15,
									 &menuItems[0],
									 &menuItems[1],
									 &menuItems[14],
									},
									{
									 //  This is element number (16) calling -> 16
	 	 	 	 	 	 	 	 	 "To Be defined \nlater!",
									 &stubCall,
									 &menuItems[15],
									 &menuItems[16],
									 &menuItems[16],
									}
								  };
