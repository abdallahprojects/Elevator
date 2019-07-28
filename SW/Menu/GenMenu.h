// Call backs funtion prototypes:
void stubCall(uint8_t init);
// The following callback is for ("Press select \nto start !!") menu item 
void callBack0(uint8_t init);
// The following callback is for ("About ..") menu item 
void callBack1(uint8_t init);
// The following callback is for ("Developed by ..") menu item 
void callBack2(uint8_t init);
// The following callback is for ("Hardware Version\nV2.0") menu item 
void callBack5(uint8_t init);
// The following callback is for ("Digital Motor\nControl ..") menu item 
void callBack8(uint8_t init);
// The following callback is for ("Turn Left") menu item 
void callBack9(uint8_t init);
// The following callback is for ("Turn Right") menu item 
void callBack10(uint8_t init);
// The following callback is for ("Turn OFF") menu item 
void callBack11(uint8_t init);
// The following callback is for ("Turn both ON") menu item 
void callBack12(uint8_t init);
// The following callback is for ("Speed Control ..") menu item 
void callBack13(uint8_t init);
// The following callback is for ("Left ..") menu item 
void callBack14(uint8_t init);
// The following callback is for ("Left ..\n++++++++++") menu item 
void callBack15(uint8_t init);
// The following callback is for ("Left ..\n+") menu item 
void callBack16(uint8_t init);
// The following callback is for ("Left ..\n++") menu item 
void callBack17(uint8_t init);
// The following callback is for ("Left ..\n+++") menu item 
void callBack18(uint8_t init);
// The following callback is for ("Left ..\n++++") menu item 
void callBack19(uint8_t init);
// The following callback is for ("Left ..\n+++++") menu item 
void callBack20(uint8_t init);
// The following callback is for ("Left ..\n++++++") menu item 
void callBack21(uint8_t init);
// The following callback is for ("Left ..\n+++++++") menu item 
void callBack22(uint8_t init);
// The following callback is for ("Left ..\n++++++++") menu item 
void callBack23(uint8_t init);
// The following callback is for ("Left ..\n+++++++++") menu item 
void callBack24(uint8_t init);
// The following callback is for ("Read Current ..") menu item 
void callBack26(uint8_t init);
// The following callback is for ("Elevator ..") menu item 
void callBack27(uint8_t init);
// Defining the menu items structs in flash memory
const menuItem_t menuItems[] 	= {
									{
									 //  This is element number (0) calling -> 1
	 	 	 	 	 	 	 	 	 "Press select \nto start !!",
									 &callBack0,
									 &menuItems[0],
									 &menuItems[0],
									 &menuItems[0],
									 &menuItems[1]
									},
									{
									 //  This is element number (1) calling -> 2
	 	 	 	 	 	 	 	 	 "About ..",
									 &callBack1,
									 &menuItems[0],
									 &menuItems[8],
									 &menuItems[27],
									 &menuItems[2]
									},
									{
									 //  This is element number (2) calling -> 3
	 	 	 	 	 	 	 	 	 "Developed by ..",
									 &callBack2,
									 &menuItems[1],
									 &menuItems[5],
									 &menuItems[7],
									 &menuItems[3]
									},
									{
									 //  This is element number (3) calling -> 3
	 	 	 	 	 	 	 	 	 "Author:\nAbdallah Helal",
									 &stubCall,
									 &menuItems[2],
									 &menuItems[4],
									 &menuItems[4],
									 &menuItems[3]
									},
									{
									 //  This is element number (4) calling -> 4
	 	 	 	 	 	 	 	 	 " SW 3.11 HW V2.0",
									 &stubCall,
									 &menuItems[2],
									 &menuItems[3],
									 &menuItems[3],
									 &menuItems[4]
									},
									{
									 //  This is element number (5) calling -> 6
	 	 	 	 	 	 	 	 	 "Hardware Version\nV2.0",
									 &callBack5,
									 &menuItems[1],
									 &menuItems[7],
									 &menuItems[2],
									 &menuItems[6]
									},
									{
									 //  This is element number (6) calling -> 6
	 	 	 	 	 	 	 	 	 "Version 2.0 ",
									 &stubCall,
									 &menuItems[5],
									 &menuItems[6],
									 &menuItems[6],
									 &menuItems[6]
									},
									{
									 //  This is element number (7) calling -> 7
	 	 	 	 	 	 	 	 	 "Software Version\nV1.1",
									 &stubCall,
									 &menuItems[1],
									 &menuItems[2],
									 &menuItems[5],
									 &menuItems[7]
									},
									{
									 //  This is element number (8) calling -> 9
	 	 	 	 	 	 	 	 	 "Digital Motor\nControl ..",
									 &callBack8,
									 &menuItems[0],
									 &menuItems[13],
									 &menuItems[1],
									 &menuItems[9]
									},
									{
									 //  This is element number (9) calling -> 9
	 	 	 	 	 	 	 	 	 "Turn Left",
									 &callBack9,
									 &menuItems[8],
									 &menuItems[10],
									 &menuItems[12],
									 &menuItems[9]
									},
									{
									 //  This is element number (10) calling -> 10
	 	 	 	 	 	 	 	 	 "Turn Right",
									 &callBack10,
									 &menuItems[8],
									 &menuItems[11],
									 &menuItems[9],
									 &menuItems[10]
									},
									{
									 //  This is element number (11) calling -> 11
	 	 	 	 	 	 	 	 	 "Turn OFF",
									 &callBack11,
									 &menuItems[8],
									 &menuItems[12],
									 &menuItems[10],
									 &menuItems[11]
									},
									{
									 //  This is element number (12) calling -> 12
	 	 	 	 	 	 	 	 	 "Turn both ON",
									 &callBack12,
									 &menuItems[8],
									 &menuItems[9],
									 &menuItems[11],
									 &menuItems[12]
									},
									{
									 //  This is element number (13) calling -> 14
	 	 	 	 	 	 	 	 	 "Speed Control ..",
									 &callBack13,
									 &menuItems[0],
									 &menuItems[25],
									 &menuItems[8],
									 &menuItems[14]
									},
									{
									 //  This is element number (14) calling -> 15
	 	 	 	 	 	 	 	 	 "Left ..",
									 &callBack14,
									 &menuItems[13],
									 &menuItems[14],
									 &menuItems[14],
									 &menuItems[15]
									},
									{
									 //  This is element number (15) calling -> 15
	 	 	 	 	 	 	 	 	 "Left ..\n++++++++++",
									 &callBack15,
									 &menuItems[14],
									 &menuItems[16],
									 &menuItems[24],
									 &menuItems[15]
									},
									{
									 //  This is element number (16) calling -> 16
	 	 	 	 	 	 	 	 	 "Left ..\n+",
									 &callBack16,
									 &menuItems[14],
									 &menuItems[17],
									 &menuItems[15],
									 &menuItems[16]
									},
									{
									 //  This is element number (17) calling -> 17
	 	 	 	 	 	 	 	 	 "Left ..\n++",
									 &callBack17,
									 &menuItems[14],
									 &menuItems[18],
									 &menuItems[16],
									 &menuItems[17]
									},
									{
									 //  This is element number (18) calling -> 18
	 	 	 	 	 	 	 	 	 "Left ..\n+++",
									 &callBack18,
									 &menuItems[14],
									 &menuItems[19],
									 &menuItems[17],
									 &menuItems[18]
									},
									{
									 //  This is element number (19) calling -> 19
	 	 	 	 	 	 	 	 	 "Left ..\n++++",
									 &callBack19,
									 &menuItems[14],
									 &menuItems[20],
									 &menuItems[18],
									 &menuItems[19]
									},
									{
									 //  This is element number (20) calling -> 20
	 	 	 	 	 	 	 	 	 "Left ..\n+++++",
									 &callBack20,
									 &menuItems[14],
									 &menuItems[21],
									 &menuItems[19],
									 &menuItems[20]
									},
									{
									 //  This is element number (21) calling -> 21
	 	 	 	 	 	 	 	 	 "Left ..\n++++++",
									 &callBack21,
									 &menuItems[14],
									 &menuItems[22],
									 &menuItems[20],
									 &menuItems[21]
									},
									{
									 //  This is element number (22) calling -> 22
	 	 	 	 	 	 	 	 	 "Left ..\n+++++++",
									 &callBack22,
									 &menuItems[14],
									 &menuItems[23],
									 &menuItems[21],
									 &menuItems[22]
									},
									{
									 //  This is element number (23) calling -> 23
	 	 	 	 	 	 	 	 	 "Left ..\n++++++++",
									 &callBack23,
									 &menuItems[14],
									 &menuItems[24],
									 &menuItems[22],
									 &menuItems[23]
									},
									{
									 //  This is element number (24) calling -> 24
	 	 	 	 	 	 	 	 	 "Left ..\n+++++++++",
									 &callBack24,
									 &menuItems[14],
									 &menuItems[15],
									 &menuItems[23],
									 &menuItems[24]
									},
									{
									 //  This is element number (25) calling -> 25
	 	 	 	 	 	 	 	 	 "Read Voltage ..",
									 &stubCall,
									 &menuItems[0],
									 &menuItems[26],
									 &menuItems[13],
									 &menuItems[25]
									},
									{
									 //  This is element number (26) calling -> 26
	 	 	 	 	 	 	 	 	 "Read Current ..",
									 &callBack26,
									 &menuItems[0],
									 &menuItems[27],
									 &menuItems[25],
									 &menuItems[26]
									},
									{
									 //  This is element number (27) calling -> 28
	 	 	 	 	 	 	 	 	 "Elevator ..",
									 &callBack27,
									 &menuItems[0],
									 &menuItems[1],
									 &menuItems[26],
									 &menuItems[28]
									},
									{
									 //  This is element number (28) calling -> 28
	 	 	 	 	 	 	 	 	 "To Be defined \nlater!",
									 &stubCall,
									 &menuItems[27],
									 &menuItems[28],
									 &menuItems[28],
									 &menuItems[28]
									}
								  };
