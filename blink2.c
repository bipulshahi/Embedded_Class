#define F_CPU 8000000UL //define clock speed of the MCU
#include <avr/io.h>      //include avr header file
#include <util/delay.h>  //include delay header file
 

void USARTInit(unsigned int ubrr_value)  //USART initialize
{
/*
Baud rate = 9600
Data bits =8
Parity = None
Stop bits = 1
Flow Control = None
Transmission Mode = Asynchronous
USART Reciever = ON
USART Transmitter = ON
U2X = 0
UBRR value = 51
ATMega8 Calibrated Internal RC Oscilator Frequency = 12 MHz
*/

   UBRRL = ubrr_value;    
   UBRRH = 0;
  UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
  UCSRB=(1<<RXEN)|(1<<TXEN);     // Enable Receiver & Transmitter
   }

unsigned char USARTReadChar()        //UART recieving function
{
while(!(UCSRA & (1<<RXC)));      // Wait till the receiving  is not completed.
return UDR;            // Return the received data
}
void USARTTransmitChar(unsigned char data) //UART transmit function
{
 while(!(UCSRA & (1<<UDRE)));   // Wait till the data  register is not Empty.
 UDR=data;          // Put the data to be transfer
}
void main()           //main function
{
DDRB=0b00001111; //declare Port B as a output port connected to the motors
DDRD=0b00000000; //declare Port D as a input port connected to the bluetooth
unsigned char command;
USARTInit(51);  // 9600-Baud Rate at 12Mhz  
while(1) 
  {   
 command=USARTReadChar();   // waiting to receive new command
     
if((command=='f')||(command=='F'))
	{	 
 PORTB=0b00001001;         //  Move Forward
    	}
if((command=='b')||(command=='B'))
	{	 
   	PORTB=0b00000110;        //  Move Backward
    }
if((command=='r')||(command=='R'))
	 {	 
	  PORTB=0b00000001;        //  Turning Right
	  }
if((command=='l')||(command=='L'))
	 {	 
	  PORTB=0b00001000;       //  Turning Left
	}
if((command=='s')||(command=='S'))
	 {	 
	  PORTB=0b00000000;       //  Stop
	  }
}
}
