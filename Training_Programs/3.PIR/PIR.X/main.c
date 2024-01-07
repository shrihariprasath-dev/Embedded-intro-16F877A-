#include <xc.h>  			//Initialize Headrer File
#define _XTAL_FREQ 20000000 //Initialize Crytal Range 20MHz 
#define PIR RD2				//PIR Connect PORTD-RD2
#define BUZZER RC0			//Buzzer Connect PORTC-RC0
//////*Main Program*//////////
void main()				
{
TRISD=0x04;				//Make RD2 as I/P-->TRISD=0x04(Direction Control) 00000100
PORTD=0x00;				//Make All Pins LOW - PORTD-->PORTD=0x00;
TRISC=0X00;				//Make RC0 as O/P-->TRISC=0x00(Direction Control)
PORTC=0x00;				//Make All Pins LOW - PORTC-->PORTC=0x00;
while(1)				//Loop will be Execute Infinity Times
{
if(PIR==1)				//if PIR sensor Detect Buzzer will be High
{
BUZZER=0;				//Buzzer On Condition
}
else					//If Not detect any human buzzer codition will be off
{
BUZZER=1;				//Buzzer Off Condition
}
}
} 
