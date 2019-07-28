// Call backs funtion implementation:
// The following callback is for ("Press select \nto start !!") menu item 
void callBack0(uint8_t init){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------

}
// The following callback is for ("About ..") menu item 
void callBack1(uint8_t init){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Developed by ..") menu item 
void callBack2(uint8_t init){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Hardware Version\nV2.0") menu item 
void callBack5(uint8_t init){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Digital Motor\nControl ..") menu item 
void callBack8(uint8_t init){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Turn Left") menu item 
void callBack9(uint8_t init){
// ---------- Manual Code Start --------------------
	uint8_t i;
	uint32_t ADCValue,tmp;
	if(init == true)
	{
		MotorOnLeft;
	}else{
		tmp = 0;
		for(i=0;i<RES;i++)
		{
			tmp += ADC_read(MOTOR_CRNT_SENS_CHNL);
		}
		ADCValue = tmp/RES;
		LCD_Seond_Line();
		LCD_putNum(ADCValue);
	}

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Turn Right") menu item 
void callBack10(uint8_t init){
// ---------- Manual Code Start --------------------

	uint8_t i;
	uint32_t ADCValue,tmp;
	if(init == true)
	{
		MotorOnRight;
	}else{
		tmp = 0;
		for(i=0;i<RES;i++)
		{
			tmp += ADC_read(MOTOR_CRNT_SENS_CHNL);
		}
		ADCValue = tmp/RES;
		LCD_Seond_Line();
		LCD_putNum(ADCValue);
	}

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Turn OFF") menu item 
void callBack11(uint8_t init){
// ---------- Manual Code Start --------------------

	uint8_t i;
	uint32_t ADCValue,tmp;
	if(init == true)
	{
		MotorOff;
	}else{
		tmp = 0;
		for(i=0;i<RES;i++)
		{
			tmp += ADC_read(MOTOR_CRNT_SENS_CHNL);
		}
		ADCValue = tmp/RES;
		LCD_Seond_Line();
		LCD_putNum(ADCValue);
	}

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Turn both ON") menu item 
void callBack12(uint8_t init){
// ---------- Manual Code Start --------------------

	uint8_t i;
	uint32_t ADCValue,tmp;
	if(init == true)
	{
		MotorHold;
	}else{
		tmp = 0;
		for(i=0;i<RES;i++)
		{
			tmp += ADC_read(MOTOR_CRNT_SENS_CHNL);
		}
		ADCValue = tmp/RES;
		LCD_Seond_Line();
		LCD_putNum(ADCValue);
	}

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Speed Control ..") menu item 
void callBack13(uint8_t init){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..") menu item 
void callBack14(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		// initialize the DDR pin
		InitMotor;
		MotorEnable;
		MotorOff; // clear the other pin to set as GND
		PWM_init(pwm_32ms);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++++++++++") menu item 
void callBack15(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(100);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+") menu item 
void callBack16(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(10);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++") menu item 
void callBack17(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(20);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+++") menu item 
void callBack18(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(30);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++++") menu item 
void callBack19(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(40);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+++++") menu item 
void callBack20(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(50);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++++++") menu item 
void callBack21(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(60);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+++++++") menu item 
void callBack22(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(70);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++++++++") menu item 
void callBack23(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(80);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+++++++++") menu item 
void callBack24(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_setDutyCycle(90);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Read Current ..") menu item 
void callBack26(uint8_t init){
// ---------- Manual Code Start --------------------
	uint8_t i;
	uint32_t sum = 0;
	uint32_t tmp[20];
	uint32_t mean_by_5;
	//uint32_t volt_10th_ACS;
	static uint8_t counter;
	//static uint32_t lcdcounter;
	//LCD_Clear();
	if(init)
	{
		MotorOnLeft;
		LCD_Clear();
		LCD_putrs("Current Monitor");
		_delay_ms(2000);
		counter = 0;
	}
	for(i=0;i<20;i++){
		tmp[i] = (uint32_t)ADC_read(3);
	}
	for(i=0;i<20;i++){
		sum+= tmp[i];
	}
	mean_by_5 = (sum/20);
	//mean_by_5 = 103;
	//volt_10th_ACS  = ((mean_by_5*500)/1024);
	if(mean_by_5 > 518)
	{
		MotorOff;
		LCD_Seond_Line();
		LCD_putrs("Current Limit");
		counter = 1;
	}
	if(!counter){

		LCD_Seond_Line();
		LCD_putNum(mean_by_5);
	}

	//if(volt_10th_ACS<999){
	//	LCD_putNum(mean_by_5);
		//LCD_putc('.');
		//LCD_putNum(volt_10th_ACS%100);
//	}
//	else
	//	LCD_putrs("Something went \nwrong !!");
	//_delay_ms(2000);

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Elevator ..") menu item 
void callBack27(uint8_t init){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------

}
