#include "sys.h"

char UART_Init(const long int baudrate);
void UART_Write(unsigned char data);
void UART_Write_Text(char *text);
char UART_TX_Empty();
char UART_Data_Ready();
char UART_Read();
void UART_Read_Text(unsigned char *Output, unsigned int length);

char UART_Init(const long int baudrate)
{
	unsigned int x;
	x = (_XTAL_FREQ - baudrate*64)/(baudrate*64);
	if(x>255)
	{
		x = (_XTAL_FREQ - baudrate*16)/(baudrate*16);
		BRGH = 1;
	}
	if(x<256)
	{
	  SPBRG = x;
      TRISC7 = 1;
      TRISC6 = 1;
      SYNC = 0;		    	// asynchronous mode
	  SPEN = 1;		    	// serial port enable
	  RCIE = 1;				// interrupt set
	  CREN = 1;		    	// Rx ENable
	  TXEN = 1;				// Tx enable
	  GIE=1;              // Global Interrupt enable 
	  PEIE=1;				// Peripherals Interrupt enable
	  return 1;
	}
	return 0;
}

void UART_Write(unsigned char data)
{
  while(!TRMT);
  TXREG = data;
  while(!TXIF);
  TXIF = 0; 
  
}

void UART_Write_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
	  UART_Write(text[i]);
}

char UART_TX_Empty()
{
  return TRMT;
}

char UART_Data_Ready()
{
   return RCIF;
}

char UART_Read()
{
 
  while(!RCIF);
  return RCREG;
}

void UART_Read_Text(unsigned char *Output, unsigned int length)
{
	unsigned int i;
	for(int i=0;i<length;i++)
		Output[i] = UART_Read();
}



