
/*
 * File:   configuration.c
 * Author: Shrihariprasath
 *
 * Created on 17 April 2021, 00:10
 */
#define _XTAL_FREQ 20000000

#include <xc.h>

void main() 
{
    TRISB = 0b00000000;
    TRISA = 0b00000000;
    
    while(1)
    {
        PORTB = 0xAA;
        PORTAbits.RA0 = 0;
        __delay_ms(100);
        PORTB = 0x55;
        PORTAbits.RA0 = 1;
        __delay_ms(100);
    }
    
    
}
