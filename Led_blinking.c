// Project name : Times_LED_Blinking
// Compile Date : 20/02/2014 Time : (13:10)
// Complied by 	: R&D Team, Times Globacom Pvt. Ltd.,
// Designed By 	: Times Globacom Pvt. Ltd.
//                http://www.timts.edu.in

/* Program for "LED_Blinkingr"that blinks 4 LED's connected on PB0, PB1, PB2 and PB3"
___________________________________________________________________________________________________

Connection Settings of the Kit

LEDs---@------------->PB0
LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
*/
#define F_CPU 12000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB=0b11111111;	//set PORT B as output Port
	
    while(1)			//create infinite loop
    {
     PORTB=0b00001111;	//Glows LED's connected at PB0, PB1, PB2, PB3	
     _delay_ms(1000);
	 PORTB=0b00000000;	//Turns off LED's connected at PB0, PB1, PB2, PB3
	 _delay_ms(1000);
    }
}
