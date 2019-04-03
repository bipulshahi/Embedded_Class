/*
 * _3irsensor_motor.c
 *
 * Created: 23-07-2015 11:18:44
 *  Author: Admin
 */ 



#include <avr/io.h>
#include <util/delay.h>

void main()
{ char d;
	DDRA=0x00;
	DDRD=0xff;
	
	while(1)
	{
		d=(PINA&0b00000111);
		if (d==0b00000000)
		{PORTD=0b00001010;
			
		}

		
		if(d==0b00000001)
		{
			PORTD=0b00001010;
			
		}
		
		if(d==0b00000010)
		{
			PORTD=0b00000010;
			
		}
		if (d==0b00000011)
		{
			PORTD=0b00000010;
		
		}
		
		if (d==0b00000100)
		{PORTD=0b00001000;
			
		}

		
		if(d==0b00000101)
		{
			PORTD=0b00001010;
			
		}
		
		if(d==0b00000110)
		{
			PORTD=0b00001000;
			
		}
		if (d==0b00000111)
		{
			PORTD=0b00000010;
			
		}
		
	
}
}