// Call backs funtion implementation:
// The following callback is for ("Press select \nto start !!") menu item 
void callBack0(void){
	currentMenuItem = &menuItems[1];
}
// The following callback is for ("About ..") menu item 
void callBack1(void){
	currentMenuItem = &menuItems[2];
}
// The following callback is for ("Developed by ..") menu item 
void callBack2(void){
	currentMenuItem = &menuItems[3];
}
// The following callback is for ("Hardware Version\nV2.0") menu item 
void callBack5(void){
	currentMenuItem = &menuItems[6];
}
// The following callback is for ("Motor Control ..") menu item 
void callBack8(void){
	MotorEnable;
	currentMenuItem = &menuItems[9];
}
// The following callback is for ("Turn Left") menu item 
void callBack9(void){
	MotorOnLeft;
	currentMenuItem = &menuItems[9];
}
// The following callback is for ("Turn Right") menu item 
void callBack10(void){
	MotorOnRight;
	currentMenuItem = &menuItems[10];
}
// The following callback is for ("Turn OFF") menu item 
void callBack11(void){
	MotorOff;
	currentMenuItem = &menuItems[11];
}
// The following callback is for ("Turn both ON") menu item 
void callBack12(void){
	MotorHold;
	currentMenuItem = &menuItems[12];
}
// The following callback is for ("Read Voltage ..") menu item 
void callBack13(void){
	currentMenuItem = &menuItems[13];
}
// The following callback is for ("Read Current ..") menu item 
void callBack14(void){
	currentMenuItem = &menuItems[14];
}
// The following callback is for ("Elevator ..") menu item 
void callBack15(void){
	currentMenuItem = &menuItems[16];
}
