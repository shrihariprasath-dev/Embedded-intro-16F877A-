#include <xc.h>  			
#include "sys.h"
#include "lcd.h"
#include "adc.h"
////////////*Main Program*/////////////
void volt(void);
void temp(void);
void main()					 
{
 TRISB = 0X00;				
 PORTB = 0x00;				
 TRISD = 0X00;				
 PORTD = 0x00;
 
 BUZZ = 0;
 RLY = 0;
 lcd_init();				
 adc_init();				
  while (1)							
  { 
      volt();
      temp();
  }
}
void volt(void)
{ 
    unsigned int voltage = 0;
    ADC_CH(0);				
  	lcd_cursor(0,0);			
	lcd_display("RA0->Volt:"); 
    lcd_cursor(0,10);
    voltage=((adc_value/1023.0)*5*10);
    disp_dig3(voltage);				
	lcd_cursor(0,15);			
	lcd_display("V");  
    if (voltage >= 40)
    {
        BUZZ= 1;
    }
    else
    {
        BUZZ= 0;
    } 
}

void temp(void)
{
    unsigned int temperature;
	ADC_CH(1);
   	lcd_cursor(1,0);			
	lcd_display("RA1->temp:");
    lcd_cursor(1,10);
    temperature=((adc_value/1023.0)*5*100);
    disp_dig2(temperature);
	lcd_cursor(1,12);			
	lcd_display("'C");
    if ((temperature >= 40))
    {
        RLY=1;
    }
    else
    {
        RLY=0;
    }
}