////ADC.h - Header File*///////
void adc_init();
void ADC_CH(unsigned int channel);
void disp_dig4(unsigned int val1);
void disp_dig3(unsigned int val1);
void disp_dig2(unsigned int val1);
void Serial_dig4(unsigned int val1);
void Serial_dig3(unsigned int val1);
void Serial_dig2(unsigned int val1);

unsigned int adc_value,val2,val3,val4,val5,val6,val7;

void adc_init()	//ADC initialise
{
 ADCON1=0X80; 	// 1 0 0 0 0 0 0 0	//ADC Right justify and PORTA/PORTE using analogy pins 	
}

void ADC_CH(unsigned int channel)	//ADC channel selection
{
    switch (channel)
    {
        case 0:
            ADCON0=0XC5;
            while(GO_DONE==1);
            adc_value=(ADRESL+(ADRESH*256));
            break;
        case 1:
            ADCON0=0XCD;
            while(GO_DONE==1);
            adc_value=(ADRESL+(ADRESH*256));
            break;
        case 2:
            ADCON0=0XD5;
            while(GO_DONE==1);
            adc_value=(ADRESL+(ADRESH*256));
            break;
        default:
            ADCON0=0X00;
            while(GO_DONE==1);
            adc_value=(ADRESL+(ADRESH*256));
            break;
            
    }       
}

void disp_dig4(unsigned int val1)	//4Digit Character Value send To LCD
{
 val2=val1/1000;
 val3=val1%1000;
 val4=val3/100;
 val5=val3%100;
 val6=val5/10;
 val7=val5%10;
 lcd_data(val2+0x30); 
 lcd_data(val4+0x30); 
 lcd_data(val6+0x30);
 lcd_data('.');
 lcd_data(val7+0x30);
}

void disp_dig3(unsigned int val1)	//3Digit Character Value send To LCD
{
 val2=val1/1000;
 val3=val1%1000;
 val4=val3/100;
 val5=val3%100;
 val6=val5/10;
 val7=val5%10;
 lcd_data(val4+0x30); 
 lcd_data(val6+0x30);
 lcd_data('.');
 lcd_data(val7+0x30);
}
void disp_dig2(unsigned int val1)	//2Digit Character Value send To LCD
{
 val2=val1/1000;
 val3=val1%1000;
 val4=val3/100;
 val5=val3%100;
 val6=val5/10;
 val7=val5%10; 
 lcd_data(val6+0x30);
 lcd_data(val7+0x30);
}

void Serial_dig4(unsigned int val1)	//4Digit Character Value send To LCD
{
 val2=val1/1000;
 val3=val1%1000;
 val4=val3/100;
 val5=val3%100;
 val6=val5/10;
 val7=val5%10;
 UART_Write(val2+0x30); 
 UART_Write(val4+0x30); 
 UART_Write(val6+0x30);
 UART_Write('.');
 UART_Write(val7+0x30);
}

void Serial_dig3(unsigned int val1)	//3Digit Character Value send To LCD
{
 val2=val1/1000;
 val3=val1%1000;
 val4=val3/100;
 val5=val3%100;
 val6=val5/10;
 val7=val5%10;
 UART_Write(val4+0x30); 
 UART_Write(val6+0x30);
 UART_Write('.');
 UART_Write(val7+0x30);
}
void Serial_dig2(unsigned int val1)	//2Digit Character Value send To LCD
{
 val2=val1/1000;
 val3=val1%1000;
 val4=val3/100;
 val5=val3%100;
 val6=val5/10;
 val7=val5%10; 
 UART_Write(val6+0x30);
 UART_Write(val7+0x30);
}