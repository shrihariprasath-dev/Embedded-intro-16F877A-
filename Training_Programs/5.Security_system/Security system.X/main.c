#include <xc.h>  			//Initialize Headrer File
#include "sys.h"
#include "lcd.h"
////////////*Main Program*/////////////
void main()					
{
 TRISB = 0X01;				    //Make PORTB as O/P PORTB-->TRISB=0x00(Direction Control)
 PORTB = 0x01;				    //Make All Pins LOW - PORTB-->PORTB=0x00;
 TRISD = 0X00;				    //Make PORTD as O/P PORTD-->TRISD=0x00(Direction Control)
 PORTD = 0x00;				    //Make All Pins LOW - PORTD-->PORTD=0x00;
 lcd_init();				    //Call LCD Initialize Function
 lcd_cursor(0,0);				//LCD set Row and Coloum
 lcd_display("Welcome to PIC"); //LCD Display String
 lcd_cursor(1,2);				//LCD set Row and Coloum
 lcd_display("Hello BITS");     //LCD Display String
 __delay_ms(1000);				//1 Sec Delay
 lcd_clear();
 while (1)							//Loop will be Execute Infinity Times
  { 
    if(PIR==1)				//if PIR sensor Detect Buzzer will be High
        {
        BUZZ=1;				//Buzzer On Condition
        RLY=1;
        lcd_cursor(0,2);				//LCD set Row and Coloum
        lcd_display("HUMAN DETECTED");      //LCD Display String
        lcd_cursor(1,0);				//LCD set Row and Coloum
        lcd_display("ALARAM TRIGGERED");      //LCD Display String
	    __delay_ms(1000);	
        lcd_clear();
        }
        else					//If Not detect any human buzzer condition will be off
        {
        BUZZ=0;				//Buzzer Off Condition
        RLY=0;
        lcd_cursor(0,2);				//LCD set Row and Coloum
        lcd_display("YOR R SAFE");      //LCD Display String
        lcd_cursor(1,0);				//LCD set Row and Coloum
        lcd_display("ALARM OFF");      //LCD Display String
	    __delay_ms(1000);
        lcd_clear();
        }
   }
    lcd_display("");
	lcd_clear();
  }

