

/* 
 * File: header file for LCD1602A  
 * Author: Patrick Nkwari
 * Comments: triple L 
 * Revision history: 
 */



#define _XTAL_FREQ 8000000

#include "common.h"
#include <util/delay.h>
#include <avr/io.h>
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

void LCD_Write ( unsigned char c ) {

    *(lcd.PORT) &= ~(1 << lcd.RS); // => RS = 0
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
    LCD_Write(0x03);
    _delay_ms(20);
    LCD_Write(0x03);
    _delay_ms(64);
    LCD_Write(0x03);

    // Specify the data lenght to 4 bits
    LCD_Write(0x02);

    // Set interface data length to 8 bits, number of display lines to 2 and font to 5x8 dots
    LCD_Cmd(0x28);

    // Set cursor to move from left to right
    LCD_Cmd(0x06);

    LCD_Display(true, false, false); // Turn on display and set cursor off

    LCD_Clear();
    
    return true;
}

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
