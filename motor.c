/*
 * motor.c
 *
 * Created: 18-07-2015 16:40:38
 *  Author: Admin
 */ 


#include <avr/io.h>
#include <util/delay.h>

void main()
{ char d;
	DDRA=0x00;
	DDRD=0xff;
	//PORTC=0xff;
	while(1)
	{//PORTC=0xff;
		d=(PINA&0b00000011);
		if (d==0b00000001)
		{PORTD=0b00000001;
			
		_delay_ms(30);}

		
		if(d==0b00000010)
		{
			PORTD=0b00000100;
			_delay_ms(30);
		}
		
		if(d==0b00000011)
		{
			PORTD=0b00000101;
			_delay_ms(30);
		}
		if (d==0b00000000)
		{
			PORTD=0b00000000;
			_delay_ms(30);
		}
		
		
		
		/*
		if(PINC==0xfb)
		{
			while(1){ /
				PORTD=0x05;
				//PORTD=0xf4;
				_delay_ms(30);
				if (PINC==0xff)
			goto A;}
		}


		if(PINC==0xf7)
		{while(1){
			PORTD=0x0a;
			_delay_ms(30);
			if(PINC==0xff)
			goto A;
		}
	}
*/
}
}

