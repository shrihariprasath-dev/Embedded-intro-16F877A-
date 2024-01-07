#include "sys.h"
//////*16*2 LCD Functions Declaration*///////
void lcd_init();					 //LCD Initialize Function
void lcd_command(unsigned char com); //LCD Command Function
void lcd_data(unsigned char data);	 //LCD Data Function
void lcd_cursor(unsigned char row,unsigned char col); //LCD Set row and col Function
void lcd_display(const char *word);  //LCD String Display Function
void lcd_clear();					 //LCD Clear Function

void lcd_init()						//LCD Initialize
{
lcd_command(0x01);				    //Clear Display
lcd_command(0x06);					//Right To Left Print(Data Entry Mode)
lcd_command(0x0c);					//LCDCursor Off and Backlight On
lcd_command(0x38);					//LCD 2 Lines Print
}
void lcd_command(unsigned char com) //LCD Command Function
{
DATA=com;							//Command Send to PORTD
RS=0;								//Command Mode
EN=1;								//Enable On
__delay_ms(10);						//1 Sec Delay
EN=0;								//Enable Off
__delay_ms(10);						//1 Sec Delay
}
void lcd_data(unsigned char data) //LCD Data Function
{
DATA=data;						 //Command Send to PORTD
RS=1;							 //Data Mode
EN=1;							 //Enable On
__delay_ms(10);					 //1 Sec Delay
EN=0;						     //Enable	
__delay_ms(10);					 //1 Sec Delay
}
void lcd_display(const char *word) //LCD Display Function
{
while(*word)						//Check Condition
{
lcd_data(*word++);					//String Send to lcd_data-->PORTD
__delay_ms(1);						//1 Sec Delay	
}
}
void lcd_clear()				//LCD Clear Function	
{
	lcd_command(0x01);			//LCD Display Clear
}
void lcd_cursor(unsigned char row,unsigned char col) //LCD Set row and col Function
{
	if(row==0){lcd_command(0x80);lcd_command(0x80+col);} //Make LCD row and coloum
	if(row==1){lcd_command(0xc0);lcd_command(0xc0+col);} //Make LCD row and coloum
}