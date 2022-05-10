/* 
* Uart.cpp
*
* Created: 2021-04-25 오후 3:09:13
* Author: 박창순
*/

#include "Uart.h"

char Rx_Data[1000] = "";
unsigned int Rx_count = 0;

ISR(USART0_RX_vect)
{
	while(!(UCSR0A & (1<<UDRE0)));
	Rx_Data[Rx_count++] = UDR0;
	Rx_Data[Rx_count] = '\0';
}


// default constructor
Uart::Uart()
{
} //Uart

// default destructor
Uart::~Uart()
{
} //~Uart

void Uart::begin(unsigned long baudrate)
{
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);
	UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);
		
	if(baudrate == 2400)
	{
		UBRR0H = 1;
		UBRR0L = 160;
	}
	else if(baudrate == 4800)	 UBRR0L = 207;
	else if(baudrate == 9600)	 UBRR0L = 103;
	else if(baudrate == 14400)	 UBRR0L = 68;
	else if(baudrate == 19200)	 UBRR0L = 51;
	else if(baudrate == 28800)	 UBRR0L = 34;
	else if(baudrate == 38400)	 UBRR0L = 25;
	else if(baudrate == 57600)	 UBRR0L = 16;
	else if(baudrate == 76800)	 UBRR0L = 12;
	else if(baudrate == 115200)	 UBRR0L = 8;
	//else if(baudrate == 230400)	UBRR0L = 3;
	else if(baudrate == 250000)	 UBRR0L = 3;
	else if(baudrate == 500000)	 UBRR0L = 1;
	else if(baudrate == 1000000) UBRR0L = 0;
	else{}
	
	sei();
}

unsigned int Uart::available(void)
{
	return Rx_count;
}

void Uart::TxByte(char data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

char Uart::read(void)
{
	char data = Rx_Data[0];
		
	for(unsigned int i=0; i<Rx_count; i++)
		Rx_Data[i] = Rx_Data[i+1];
	Rx_count--;
		
	if(Rx_count<0) Rx_count = 0;
	
	return data;
}

long Uart::parseInt(void)
{
	bool isNegative = false;
	char c = '0';
	long value = 0;
	
	while((c >= '0' && c <= '9') || c == '-')
	{
		c = read();
		if(c == '-')
			isNegative = true;
		else if((c >= '0' && c <= '9'))
			value = value*10 + c-'0';
		_delay_us(50);
	}
	
	if(isNegative)
		value = -value;
	
	return value;
}

float Uart::parseFloat(void)
{
	bool isNegative = false;
	bool isFraction = false;
	char c = '0';
	float value = 0.0;
	float fraction = 1.0;
	
	while((c >= '0' && c <= '9') || (c == '.' && isFraction) || c == '-')
	{
		c = read();
		if(c == '-')
			isNegative = true;
		else if(c == '.')
			isFraction = true;
		else if((c >= '0' && c <= '9'))
		{
			value = value*10 + c-'0';
			if(isFraction)
				fraction *= 0.1;
		}
		_delay_us(50);
	}
	
	if(isNegative)
		value = -value;
	if(isFraction)
		return value * fraction;
	else
		return value;
}

void Uart::print(char str)
{
	TxByte(str);
}

void Uart::print(char str[])
{
	for(int i=0; str[i]; i++)
		TxByte(str[i]);
}

void Uart::print(const char *str)
{
	for(int i=0; str[i]; i++)
		TxByte(str[i]);
}

void Uart::print(int n, unsigned char base)
{
	if(base < 2) base = 10;
	if(n==0)
		TxByte('0');
	else
	{
		int n_tmp = n;
		unsigned char NoD = 0;
		
		while(n_tmp != 0)
		{
			n_tmp /= base;
			NoD++;
		}
		
		n_tmp = n;
		char *c = (char*)malloc(sizeof(char) * NoD);
		for(int i=NoD-1; i>=0; i--)
		{
			if(n_tmp < 0)	c[i] = (char)(-1*(n_tmp%base));
			else			c[i] = (char)(n_tmp % base);
			n_tmp /= base;
		}
		
		if(n < 0) TxByte('-');
		for(int i=0; i<NoD; i++)
			TxByte((c[i] + '0'));
		free(c);
	}
}

void Uart::print(unsigned int n, unsigned char base)
{
	if(base < 2) base = 10;
	if(n==0)
		TxByte('0');
	else
	{
		int n_tmp = n;
		unsigned char NoD = 0;
		
		while(n_tmp != 0)
		{
			n_tmp /= base;
			NoD++;
		}
		
		n_tmp = n;
		char *c = (char*)malloc(sizeof(char) * NoD);
		for(int i=NoD-1; i>=0; i--)
		{
			c[i] = (char)(n_tmp % base);
			n_tmp /= base;
		}
		
		for(int i=0; i<NoD; i++)
			TxByte((c[i] + '0'));
		free(c);
	}
}

void Uart::print(long n, unsigned char base)
{
	if(base < 2) base = 10;
	if(n==0)
		TxByte('0');
	else
	{	
		long n_tmp = n;
		unsigned char NoD = 0;
		
		while(n_tmp != 0)
		{
			n_tmp /= 10;
			NoD++;
		}
		
		n_tmp = n;
		char *c = (char*)malloc(sizeof(char) * NoD);
		for(int i=NoD-1; i>=0; i--)
		{
			if(n_tmp < 0)	c[i] = (char)(-1*(n_tmp%10));
			else			c[i] = (char)(n_tmp % 10);
			
			n_tmp /= 10;
		}
		
		if(n < 0) TxByte('-');
		for(int i=0; i<NoD; i++)
			TxByte((c[i] + '0'));
		free(c);
	}
}

void Uart::print(unsigned long n, unsigned char base)
{
	if(base < 2) base = 10;
	if(n==0)
		TxByte('0');
	else
	{
		unsigned long n_tmp = n;
		unsigned char NoD = 0;
		
		while(n_tmp != 0)
		{
			n_tmp /= 10;
			NoD++;
		}
		
		n_tmp = n;
		char *c = (char*)malloc(sizeof(char) * NoD);
		for(int i=NoD-1; i>=0; i--)
		{
			if(n_tmp < 0)	c[i] = (char)(-1*(n_tmp%10));
			else			c[i] = (char)(n_tmp % 10);
			
			n_tmp /= 10;
		}
		
		if(n < 0) TxByte('-');
		for(int i=0; i<NoD; i++)
			TxByte((c[i] + '0'));
		free(c);
	}
}

void Uart::print(float f, unsigned char f_NoD)
{
	if (f == 0)
		TxByte('0');
	else
	{
		float f_tmp;
		long i_tmp;
		unsigned char d_tmp;
		unsigned char count = 0;

		f_tmp = f;
		d_tmp = f_NoD;
		
		while (d_tmp != 0)
		{
			f_tmp *= 10;
			d_tmp--;
		}
		
		i_tmp = (long)f_tmp;
		while (i_tmp != 0)
		{
			i_tmp /= 10;
			count++;
		}

		i_tmp = (long)f_tmp;
		char* c = (char*)malloc(sizeof(char) * count);
		for (int i = count - 1; i >= 0; i--)
		{
			if(i_tmp < 0.0)	c[i] = (char)(-1*(i_tmp%10));
			else			c[i] = (char)(i_tmp % 10);
			i_tmp /= 10;
		}
		
		if (f < 0) TxByte('-');
		for (int i = 0; i < count; i++)
		{
			if (count-f_NoD == i) TxByte('.');
			TxByte(c[i] + '0');
		}
		free(c);
	}
}

void Uart::print(double f, unsigned char f_NoD)
{
	print((float)f, f_NoD);
}

void Uart::println(void)
{
	TxByte('\r');
	TxByte('\n');
}

void Uart::println(char str)
{
	print(str);
	TxByte('\r');
	TxByte('\n');
}

void Uart::println(char str[])
{
	print(str);
	TxByte('\r');
	TxByte('\n');
}

void Uart::println(const char *str)
{
	print(str);
	TxByte('\r');
	TxByte('\n');
}

void Uart::println(int n, unsigned char base)
{
	print(n, base);
	TxByte('\r');
	TxByte('\n');
}
void Uart::println(long n, unsigned char base)
{
	print(n, base);
	TxByte('\r');
	TxByte('\n');
}

void Uart::println(float f, unsigned char f_NoD)
{
	print(f, f_NoD);
	TxByte('\r');
	TxByte('\n');
}

void Uart::println(double f, unsigned char f_NoD)
{
	print((float)f, f_NoD);
	TxByte('\r');
	TxByte('\n');
}

void Uart::println(unsigned int n, unsigned char base)
{
	print(n, base);
	TxByte('\r');
	TxByte('\n');
}

void Uart::println(unsigned long n, unsigned char base)
{
	print(n, base);
	TxByte('\r');
	TxByte('\n');
}