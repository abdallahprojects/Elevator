/*
 * main.c
 *
 *  Created on: Apr 14, 2019
 *      Author: Abdallah Helal
 */

#include <avr/io.h> // Standard include for AVR
#include <util/delay.h> // Delay functions


#define sbi(x, y) x |= _BV(y)                // set bit - using bitwise OR operator
#define cbi(x, y) x &= ~(_BV(y))             // clear bit - using bitwise AND operator
#define tbi(x, y) x ^= _BV(y)                // toggle bit - using bitwise XOR operator
#define is_high(x, y) (x & _BV(y) == _BV(y)) // check if the y'th bit of register 'x' is high


int main(void)
{
    DDRB = 0xff;  // PORTB as OUTPUT
    PORTB = 0x00; // All pins of PORTB LOW

    while(1) // Infinite loop
    {
        _delay_ms(500);  // Delay for 500 ms
        tbi(PORTB, PB0); // the toggling takes place here
    }

    return 0;
}
