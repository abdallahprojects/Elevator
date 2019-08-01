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
	if(init){
		MotorDisable;
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Turn Left") menu item 
void callBack9(uint8_t init){
// ---------- Manual Code Start --------------------
	uint8_t i;
	uint32_t ADCValue,tmp;
	if(init == true)
	{
		MotorEnable;
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
		PWM_leftInit(pwm_32ms);
		PWM_leftSetDutyCycle(0);
	}

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++++++++++") menu item 
void callBack15(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(100);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+") menu item 
void callBack16(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(10);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++") menu item 
void callBack17(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(20);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+++") menu item 
void callBack18(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(30);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++++") menu item 
void callBack19(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(40);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+++++") menu item 
void callBack20(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(50);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++++++") menu item 
void callBack21(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(60);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+++++++") menu item 
void callBack22(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(70);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n++++++++") menu item 
void callBack23(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(80);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Left ..\n+++++++++") menu item 
void callBack24(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		PWM_leftSetDutyCycle(90);
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..") menu item 
void callBack25(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		// initialize the DDR pin
		InitMotor;
		MotorEnable;
		MotorOff; // clear the other pin to set as GND
		PWM_rightInit(pwm_32ms);
		PWM_rightSetDutyCycle(0);
	}


// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n+") menu item 
void callBack26(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(10);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n++") menu item 
void callBack27(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(20);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n+++") menu item 
void callBack28(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(30);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n++++") menu item 
void callBack29(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(40);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n+++++") menu item 
void callBack30(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(50);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n++++++") menu item 
void callBack31(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(60);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n+++++++") menu item 
void callBack32(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(70);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n++++++++") menu item 
void callBack33(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(80);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n+++++++++") menu item 
void callBack34(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(90);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Right ..\n++++++++++") menu item 
void callBack35(uint8_t init){
// ---------- Manual Code Start --------------------
	PWM_rightSetDutyCycle(100);
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Testing 50% dc\n in inv&non-inv modes") menu item 
void callBack36(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		// initialize the DDR pin
		InitMotor;
		MotorEnable;
		MotorOff; // clear the other pin to set as GND
		PWM_leftInit(pwm_32ms);
		PWM_leftSetDutyCycle(50);
		PWM_leftInitInvMode(pwm_32ms);
		PWM_leftSetDutyCycle(50);
	}

// ---------- Manual Code End   --------------------

}
// The following callback is for ("Current Monitor ..") menu item 
void callBack38(uint8_t init){
// ---------- Manual Code Start --------------------
	if(init){
		MotorDisable;
	}
// ---------- Manual Code End   --------------------

}
// The following callback is for ("Read Current ..") menu item 
void callBack39(uint8_t init){
// ---------- Manual Code Start --------------------
	uint8_t i;
	uint32_t sum = 0;
	uint32_t tmp[50];
	uint32_t mean_by_5;
	//uint32_t volt_10th_ACS;
	static uint8_t counter;
	//static uint32_t lcdcounter;
	//LCD_Clear();
	if(init)
	{
		MotorEnable;
		MotorOnLeft;
		LCD_Clear();
		LCD_putrs("Current Monitor");
		_delay_ms(200);
		counter = 0;
	}
	for(i=0;i<50;i++){
		tmp[i] = (uint32_t)ADC_read(3);
	}
	for(i=0;i<50;i++){
		sum+= tmp[i];
	}
	mean_by_5 = (sum/50);
	//mean_by_5 = 103;
	//volt_10th_ACS  = ((mean_by_5*500)/1024);
	if(mean_by_5 > 520)
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
void callBack40(uint8_t init){
// ---------- Manual Code Start --------------------

// ---------- Manual Code End   --------------------

}
