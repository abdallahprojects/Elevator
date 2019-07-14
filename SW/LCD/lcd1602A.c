

/* 
 * File: header file for LCD1602A  
 * Author: Patrick Nkwari
 * Comments: triple L 
 * Revision history: 
 */



#define _XTAL_FREQ 8000000

#include "common.h"
#include <util/delay.h>
#include <stdint.h>
#include <avr/io.h>
#include <math.h>
#include "lcd1602A.h"

LCD lcd;

void LCD_Out ( char c ) {
    
    if ( c & 1 ){
        *(lcd.PORT) |= 1 << lcd.D4;
    }
    else {
         *(lcd.PORT) &= ~(1 << lcd.D4);
    }

    if ( c & 2 ) {
        *(lcd.PORT) |= 1 << lcd.D5;
    }
    else {
        *(lcd.PORT) &= ~(1 << lcd.D5);
    }

    if ( c & 4 ) {
        *(lcd.PORT) |= 1 << lcd.D6;
    }
    else {
        *(lcd.PORT) &= ~(1 << lcd.D6);
    }

    if ( c & 8 ) {
         *(lcd.PORT) |= 1 << lcd.D7;
    }
    else {
         *(lcd.PORT) &= ~(1 << lcd.D7);
    }

}

// Write into DDRAM (Data RAM) Instruction
void LCD_Write ( unsigned char c ) {

    *(lcd.PORT) &= ~(1 << lcd.RS); // => RS = 0 Instruction
    *(lcd.PORT) &= ~(1 << lcd.WR); // Write operation
    LCD_Out(c);

    *(lcd.PORT) |= 1 << lcd.EN;    // => E = 1
    _delay_ms(16);
    *(lcd.PORT) &= ~(1 << lcd.EN); // => E = 0

}

unsigned char LCD_Init ( LCD display ) {

    lcd = display;

    /*
     * TODO:
     * The function should clear only the appropriate bits, not the whole PORT
     *
     * TODO:
     * "#if defined" needs to support more microcontrollers that have PORTD and PORTE
     */
    if ( lcd.PORT == &PORTA ) {
        DDRA = 0xFF;
    }
    else if ( lcd.PORT == &PORTB ) {
        DDRB = 0xFF;
    }
    else if ( lcd.PORT == &PORTC ) {
        DDRC = 0xFF;
    }
    else if ( lcd.PORT == &PORTD ) {
        DDRD = 0xFF;
    }
    else {
        return false;
    }

    // Give some time to the LCD to start function properly
    _delay_ms(80);

    // Send reset signal to the LCD
    LCD_Write(0x03); //Function Reset, set to 8 bit initially according to datasheet
    _delay_ms(1); // wait for > 37 us


    // Set interface data length to 4 bits, number of display lines to 2 and font to 5x8 dots
    LCD_Cmd(0x28); // 00101000

    _delay_ms(1); // wait for >37 us

    // Set interface data length to 4 bits, number of display lines to 2 and font to 5x8 dots
    // Repeat because it's required by the Datasheet
    LCD_Cmd(0x28); // 00101000

    _delay_ms(1); // wait for >37 us

    // Turn Cursor off - Display On - Blink off
    LCD_Cmd(0x0C);
    _delay_ms(1);

    // Dispaly Clear
    LCD_Cmd(0x01);
    _delay_ms(1);

    // Set cursor to move from left to right
    LCD_Cmd(0x06);

   // LCD_Display(true, false, false); // Turn on display and set cursor off

    //LCD_Clear();
    
    return true;
}

// Write Data to LCD
void LCD_putc ( char c ) {

   *(lcd.PORT) |= 1 << lcd.RS;   // => RS = 1
    LCD_Out((c & 0xF0) >> 4);    //Data transfer

    *(lcd.PORT) |= 1 << lcd.EN;
    _delay_us(160);
    *(lcd.PORT) &= ~(1 << lcd.EN);

    LCD_Out(c & 0x0F);

    *(lcd.PORT) |= 1 << lcd.EN;
    _delay_us(160);
    *(lcd.PORT) &= ~(1 << lcd.EN);

}

void LCD_puts ( char *a ) {

    for ( int i = 0; a[i] != '\0'; ++i ) {
        LCD_putc(a[i]);
    }

}

void LCD_putrs ( const char *a ) {

    for ( int i = 0; a[i] != '\0'; ++i ) {
    	if(a[i] == '\n')
    		LCD_Seond_Line();
    	else
    		LCD_putc(a[i]);
    }

}

void LCD_putNum(uint32_t number){
	char str[6];
	uint8_t i;
	uint8_t numOfDigits=0;
	str[5] = '\0';
	////
	for(i=0;i<5;i++)
	{
		if(number < (pow(10,i+1)))
		{
			str[i+1]='\0';
			numOfDigits = i+1;
			break;
		}
		//str[i] = ((number % (uint32_t)pow(10,i+1))/((uint32_t)pow(10,i)))+48;
	}
	for(i=numOfDigits;i>0;i--){
		LCD_putc((char)((number % (uint32_t)(pow(10,i)+0.5))/((uint32_t)pow(10,i-1)))+48);
	}
	//LCD_putrs(str);
}
void SendLCD_DDRAM_ADD(uint8_t Address){
	uint8_t command;
	uint8_t code = 0;
	code |= (1<<7); // this is the code to write in the DDRAM address space in the LCD
	command = code | Address;
	LCD_Cmd(command);
}
// the CGRAM address is only 5 bits, other bits will be ignored
void SendLCD_CGRAM_ADD(uint8_t Address){
	uint8_t command;
	uint8_t code = 0;
	Address &= ~(3<<6);
	code |= (1<<6); // this is the code to write in the CGRAM address space in the LCD
	command = code | Address;
	LCD_Cmd(command);
}
