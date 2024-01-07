#include <xc.h>  			//Initialize Headrer File
#define _XTAL_FREQ 20000000 //Initialize Crytal Range 20MHz 
#define LED PORTC

void main()					//Main Program
{
 TRISC = 0X00;				//Make PORTC as O/P PORTC-->TRISC=0x00(Direction Control)
 LED = 0x00;				//Make All Pins LOW - PORTC-->PORTC=0x00;
  while (1)					//Loop will be Execute Infinity Times
  { 
	LED =0X01;
	__delay_ms(100);		//1 Sec Delay				
	LED =0X02;			
	__delay_ms(300);		//1 Sec Delay	
	LED =0X04;			
	__delay_ms(800);		//1 Sec Delay
	LED =0X00;
	__delay_ms(1000);		//1 Sec Delay
  }
}
