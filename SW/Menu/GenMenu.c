// Call backs funtion implementation:
// The following callback is for ("Press select \nto start !!") menu item 
void callBack0(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[1];

}
// The following callback is for ("About ..") menu item 
void callBack1(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[2];

}
// The following callback is for ("Developed by ..") menu item 
void callBack2(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[3];

}
// The following callback is for ("Hardware Version\nV2.0") menu item 
void callBack5(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[6];

}
// The following callback is for ("Motor Control ..") menu item 
void callBack8(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[9];

}
// The following callback is for ("Turn Left") menu item 
void callBack9(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[9];

}
// The following callback is for ("Turn Right") menu item 
void callBack10(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[10];

}
// The following callback is for ("Turn OFF") menu item 
void callBack11(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[11];

}
// The following callback is for ("Turn both ON") menu item 
void callBack12(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[12];

}
// The following callback is for ("Read Voltage ..") menu item 
void callBack13(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[13];

}
// The following callback is for ("Read Current ..") menu item 
void callBack14(void){
// ---------- Manual Code Start --------------------
	uint8_t read_adch[10],read_adcl[10],i;
	uint32_t sum = 0;
	uint16_t mean_by_5;
	uint8_t volt_10th_ACS;
	LCD_Clear();
	for(i=0;i<10;i++){
		ADC_read(&read_adch[i],&read_adcl[i]);
	}
	for(i=0;i<10;i++){
		sum+= read_adch[i];
	}
	mean_by_5 = (sum*2);

	volt_10th_ACS  = (mean_by_5 *10)/1024;

	if(volt_10th_ACS<99)
		LCD_putNum(volt_10th_ACS);
	else
		LCD_putrs("Something went wrong !!");
	_delay_ms(2000);

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[14];
}
// The following callback is for ("Elevator ..") menu item 
void callBack15(void){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------
	currentMenuItem = &menuItems[16];

}
