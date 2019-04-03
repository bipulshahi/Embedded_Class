/*
 * switchinput.c
 *
 * Created: 03-04-2019 10:29:04
 *  Author: vipul
 */ 


#include <avr/io.h>

int main(void)
{
	DDRD=0b00000000;
	DDRB=0b11111111;
	
    while(1)
    {
        int x= (PIND&0b00000011);
		if (x==0b00000001){				// PD0 - Switch 1
			PORTB=0b00000011;			// O/P LED - PB0-PB3 
		}
		else if (x==0b00000010){        // PD1 - Switch 2
			PORTB=0b00001100;
		}else{
			PORTB=0b00001111;
		}
		    }
}