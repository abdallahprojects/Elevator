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
// The following callback is for ("Right ..") menu item 
void callBack25(uint8_t init);
// The following callback is for ("Right ..\n+") menu item 
void callBack26(uint8_t init);
// The following callback is for ("Right ..\n++") menu item 
void callBack27(uint8_t init);
// The following callback is for ("Right ..\n+++") menu item 
void callBack28(uint8_t init);
// The following callback is for ("Right ..\n++++") menu item 
void callBack29(uint8_t init);
// The following callback is for ("Right ..\n+++++") menu item 
void callBack30(uint8_t init);
// The following callback is for ("Right ..\n++++++") menu item 
void callBack31(uint8_t init);
// The following callback is for ("Right ..\n+++++++") menu item 
void callBack32(uint8_t init);
// The following callback is for ("Right ..\n++++++++") menu item 
void callBack33(uint8_t init);
// The following callback is for ("Right ..\n+++++++++") menu item 
void callBack34(uint8_t init);
// The following callback is for ("Right ..\n++++++++++") menu item 
void callBack35(uint8_t init);
// The following callback is for ("Testing 50% dc\n in inv&non-inv modes") menu item 
void callBack36(uint8_t init);
// The following callback is for ("Current Monitor ..") menu item 
void callBack38(uint8_t init);
// The following callback is for ("Read Current ..") menu item 
void callBack39(uint8_t init);
// The following callback is for ("Elevator ..") menu item 
void callBack40(uint8_t init);
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
									 &menuItems[40],
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
									 &menuItems[37],
									 &menuItems[8],
									 &menuItems[14]
									},
									{
									 //  This is element number (14) calling -> 15
	 	 	 	 	 	 	 	 	 "Left ..",
									 &callBack14,
									 &menuItems[13],
									 &menuItems[25],
									 &menuItems[36],
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
									 //  This is element number (25) calling -> 26
	 	 	 	 	 	 	 	 	 "Right ..",
									 &callBack25,
									 &menuItems[13],
									 &menuItems[36],
									 &menuItems[14],
									 &menuItems[26]
									},
									{
									 //  This is element number (26) calling -> 26
	 	 	 	 	 	 	 	 	 "Right ..\n+",
									 &callBack26,
									 &menuItems[25],
									 &menuItems[27],
									 &menuItems[35],
									 &menuItems[26]
									},
									{
									 //  This is element number (27) calling -> 27
	 	 	 	 	 	 	 	 	 "Right ..\n++",
									 &callBack27,
									 &menuItems[25],
									 &menuItems[28],
									 &menuItems[26],
									 &menuItems[27]
									},
									{
									 //  This is element number (28) calling -> 28
	 	 	 	 	 	 	 	 	 "Right ..\n+++",
									 &callBack28,
									 &menuItems[25],
									 &menuItems[29],
									 &menuItems[27],
									 &menuItems[28]
									},
									{
									 //  This is element number (29) calling -> 29
	 	 	 	 	 	 	 	 	 "Right ..\n++++",
									 &callBack29,
									 &menuItems[25],
									 &menuItems[30],
									 &menuItems[28],
									 &menuItems[29]
									},
									{
									 //  This is element number (30) calling -> 30
	 	 	 	 	 	 	 	 	 "Right ..\n+++++",
									 &callBack30,
									 &menuItems[25],
									 &menuItems[31],
									 &menuItems[29],
									 &menuItems[30]
									},
									{
									 //  This is element number (31) calling -> 31
	 	 	 	 	 	 	 	 	 "Right ..\n++++++",
									 &callBack31,
									 &menuItems[25],
									 &menuItems[32],
									 &menuItems[30],
									 &menuItems[31]
									},
									{
									 //  This is element number (32) calling -> 32
	 	 	 	 	 	 	 	 	 "Right ..\n+++++++",
									 &callBack32,
									 &menuItems[25],
									 &menuItems[33],
									 &menuItems[31],
									 &menuItems[32]
									},
									{
									 //  This is element number (33) calling -> 33
	 	 	 	 	 	 	 	 	 "Right ..\n++++++++",
									 &callBack33,
									 &menuItems[25],
									 &menuItems[34],
									 &menuItems[32],
									 &menuItems[33]
									},
									{
									 //  This is element number (34) calling -> 34
	 	 	 	 	 	 	 	 	 "Right ..\n+++++++++",
									 &callBack34,
									 &menuItems[25],
									 &menuItems[35],
									 &menuItems[33],
									 &menuItems[34]
									},
									{
									 //  This is element number (35) calling -> 35
	 	 	 	 	 	 	 	 	 "Right ..\n++++++++++",
									 &callBack35,
									 &menuItems[25],
									 &menuItems[26],
									 &menuItems[34],
									 &menuItems[35]
									},
									{
									 //  This is element number (36) calling -> 36
	 	 	 	 	 	 	 	 	 "Testing 50% dc\n in inv&non-inv modes",
									 &callBack36,
									 &menuItems[13],
									 &menuItems[14],
									 &menuItems[25],
									 &menuItems[36]
									},
									{
									 //  This is element number (37) calling -> 37
	 	 	 	 	 	 	 	 	 "Voltage Monitor ..",
									 &stubCall,
									 &menuItems[0],
									 &menuItems[38],
									 &menuItems[13],
									 &menuItems[37]
									},
									{
									 //  This is element number (38) calling -> 39
	 	 	 	 	 	 	 	 	 "Current Monitor ..",
									 &callBack38,
									 &menuItems[0],
									 &menuItems[40],
									 &menuItems[37],
									 &menuItems[39]
									},
									{
									 //  This is element number (39) calling -> 39
	 	 	 	 	 	 	 	 	 "Read Current ..",
									 &callBack39,
									 &menuItems[38],
									 &menuItems[39],
									 &menuItems[39],
									 &menuItems[39]
									},
									{
									 //  This is element number (40) calling -> 41
	 	 	 	 	 	 	 	 	 "Elevator ..",
									 &callBack40,
									 &menuItems[0],
									 &menuItems[1],
									 &menuItems[38],
									 &menuItems[41]
									},
									{
									 //  This is element number (41) calling -> 41
	 	 	 	 	 	 	 	 	 "To Be defined \nlater!",
									 &stubCall,
									 &menuItems[40],
									 &menuItems[41],
									 &menuItems[41],
									 &menuItems[41]
									}
								  };
