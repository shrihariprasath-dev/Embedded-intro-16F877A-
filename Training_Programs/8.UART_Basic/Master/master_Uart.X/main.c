#include <xc.h>  			
#include "sys.h"
#include "uart.h"
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
 UART_Init(9600);
 UART_Write_Text("Serial Interface in 16F877A");
 UART_Write(0x0d);
 lcd_init();				
 adc_init();				
  while (1)							
  { 
      volt();
      temp();
      if (UART_Data_Ready())
      {
          if (UART_Read() == '1')
          {
              RLY = 1;
          }
          else if (UART_Read() == '0')
          {
              RLY = 0;
          }
      }
      
  }
}
void volt(void)
{ 
    unsigned int voltage = 0;
    ADC_CH(0);				
  	lcd_cursor(0,0);			
	lcd_display("RA0->Volt:"); 
    UART_Write_Text("The voltage at RA0:");
    lcd_cursor(0,10);
    voltage=((adc_value/1023.0)*5*10);
    disp_dig3(voltage);	
    Serial_dig3(voltage);	
	lcd_cursor(0,15);			
	lcd_display("V"); 
    UART_Write_Text("V");
    UART_Write(0x0d);
    
}

void temp(void)
{
    unsigned int temperature;
	ADC_CH(1);
   	lcd_cursor(1,0);			
	lcd_display("RA1->temp:");
    UART_Write_Text("The Room Temperature:");
    lcd_cursor(1,10);
    temperature=((adc_value/1023.0)*5*100);
    disp_dig2(temperature);
    Serial_dig2(temperature);
	lcd_cursor(1,12);			
	lcd_display("'C");
    UART_Write_Text("'C");
    UART_Write(0x0d);
}




