/*
 * ADC.c
 *
 * Created: 04-04-2019 10:14:06
 *  Author: vipul
 */ 


#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>


void ADC_init(void);
unsigned int ADC_read(unsigned int ch);
unsigned int adc_result;

int main(void)
{
	DDRB=0b11111111;
	
	ADMUX=(1<<REFS0); // AVcc with external capacitor at AREF
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	
	PORTB=0xFF;
    while(1)
    {
		adc_result=ADC_read(0);
		PORTB=adc_result;
        //TODO:: Please write your application code 
    }
}

//void ADC_init(void) // Initialization of ADC
//{
	//ADMUX=(1<<REFS0); // AVcc with external capacitor at AREF
	//ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	// Enable ADC and set Prescaler division factor as 128
//}

unsigned int ADC_read(unsigned int ch)
{
	ch= ch & 0b00000111; // channel must be b/w 0 to 7
	ADMUX |= ch; // selecting channel
	
	ADCSRA|=(1<<ADSC); // start conversion
	while(!(ADCSRA & (1<<ADIF))); // waiting for ADIF, conversion complete
	ADCSRA|=(1<<ADIF); // clearing of ADIF, it is done by writing 1 to it
	
	return (ADC);
}