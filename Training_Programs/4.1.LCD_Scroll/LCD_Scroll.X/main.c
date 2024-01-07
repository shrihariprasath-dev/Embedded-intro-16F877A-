/*
 * File:   main.c
 * Author: Shrihariprasath
 *
 * Created on 02 May 2021, 11:45
 */


#include <xc.h> //Initialize Headrer File
#define _XTAL_FREQ 20000000 //Initialize Crytal Range 20MHz 
#define RS   RB4			//LCD RS Connect PORTB-RB4
#define EN 	 RB5			//LCD EN Connect PORTB-RB5
#define DATA PORTD			//LCD DATA Connect PORTD

//////*16*2 LCD Functions Declaration*///////
void lcd_init();					 //LCD Initialize Function
void lcd_command(unsigned char com); //LCD Command Function
void lcd_data(unsigned char data);	 //LCD Data Function
void lcd_cursor(unsigned char row,unsigned char col); //LCD Set row and col 
void lcd_display(const char *word);  //LCD String Display Function
void lcd_clear();					 //LCD Clear Function
int a[20]={0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,
           0xCA,0xcB,0xCC,0XcD,0XCE,0XCF};
int b[20]={0xCF,0xCE,0xCD,0xCC,0xCB,0xCA,0xC9,0xC8,0xC7,0xC6,
           0xC5,0xC4,0xC4,0xC3,0xC2,0xC1,0xC0};
////////////*Main Program*/////////////
void main()					
{
 TRISB = 0X00;				//Make PORTB as O/P PORTB-->TRISB=0x00(Direction Control)
 PORTB = 0x00;				//Make All Pins LOW - PORTB-->PORTB=0x00;
 TRISD = 0X00;				//Make PORTD as O/P PORTD-->TRISD=0x00(Direction Control)
 PORTD = 0x00;				//Make All Pins LOW - PORTD-->PORTD=0x00;
 lcd_init();				//Call LCD Initialize Function

  while (1)							//Loop will be Execute Infinity Times
  { 
    lcd_cursor(0,2);
	lcd_display(" Welcome"); //LCD Display String
    for(int i=0;i<=16;i++)
    {
    lcd_command(b[i]);
    lcd_display("Have a nice day!"); 
    lcd_command(b[i+1]);
    lcd_display(" ");
    __delay_ms(100);
}

	lcd_clear();
  }
}

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