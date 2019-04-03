/*
 * edge_avoider.c
 *
 * Created: 21-07-2015 22:31:07
 *  Author: Admin
 */ 


#include <avr/io.h>

#include <util/delay.h>

void main()
{ char d;
	DDRD=0x00;
	DDRB=0xff;
	//PORTC=0xff;
	while(1)
	{//PORTC=0xff;
		d=(PIND&0b00000001);
		if (d==0b00000001)
		{PORTB=0b00000101;
			
		}

		
		
			
		if (d==0b00000000)
		{
			PORTB=0b00001000;
			_delay_ms(40000);
			//PORTB=0b00000001;
			//_delay_ms(1000);
			
		}
		
		
		
		/*
		if(PINC==0xfb)
		{
			while(1){ /
				PORTB=0x05;
				//PORTB=0xf4;
				_delay_ms(30);
				if (PINC==0xff)
			goto A;}
		}


		if(PINC==0xf7)
		{while(1){
			PORTB=0x0a;
			_delay_ms(30);
			if(PINC==0xff)
			goto A;
		}
	}
*/
}
}

