#include <xc.h>  			//Initialize Headrer File
#define _XTAL_FREQ 20000000 //Initialize Crytal Range 20MHz 
#define RS   RB4			//LCD RS Connect PORTB-RB4
#define EN 	 RB5			//LCD EN Connect PORTB-RB5
#define DATA PORTD			//LCD DATA Connect PORTD

//////*16*2 LCD Functions Declaration*///////
void lcd_init();					 //LCD Initialize Function
void lcd_command(unsigned char com); //LCD Command Function
void lcd_data(unsigned char data);	 //LCD Data Function 'A'
void lcd_cursor(unsigned char row,unsigned char col); //LCD Set row and col Function
void lcd_display(const char *word);  //LCD String Display Function
void lcd_clear();					 //LCD Clear Function

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
	lcd_cursor(0,0);				//LCD set Row and Coloum
	lcd_display("Welcome to PIC"); //LCD Display String
	lcd_cursor(1,2);				//LCD set Row and Coloum
    lcd_display("Hello BITS"); //LCD Display String
	__delay_ms(1000);				//1 Sec Delay
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
__delay_ms(10);						//10 Sec Delay
EN=0;								//Enable Off
__delay_ms(10);						//1Sec Delay
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

void lcd_display(const char *word) //LCD Display Function"hello"
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
