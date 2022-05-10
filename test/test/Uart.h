/* 
* Uart.h
*
* Created: 2021-04-25 오후 3:09:13
* Author: 박창순
*/


#ifndef __UART_H__
#define __UART_H__
#include <avr/io.h>
#include <avr/iom128a.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <util/delay.h>

class Uart
{
//variables
public:

//functions
public:
	Uart();
	~Uart();

private:
	
	void TxByte(char data);
public:
	void begin(unsigned long baudrate);
	unsigned int available(void);
	char read(void);
	long parseInt(void);
	float parseFloat(void);
	
	void print(char str);
	void print(char str[]);
	void print(const char *str);
	void print(int n, unsigned char base = 10);
	void print(unsigned int n, unsigned char base = 10);
	void print(long n, unsigned char base = 10);
	void print(unsigned long n, unsigned char base = 10);
	void print(float f, unsigned char f_NoD = 2);
	void print(double f, unsigned char f_NoD = 2);
	
	void println(void);
	void println(char str);
	void println(char str[]);
	void println(const char *str);
	void println(int n, unsigned char base = 10);
	void println(unsigned int n, unsigned char base = 10);
	void println(long n, unsigned char base = 10);
	void println(unsigned long n, unsigned char base = 10);
	void println(float f, unsigned char f_NoD = 2);
	void println(double f, unsigned char f_NoD = 2);

}; //Uart

#endif //__UART_H__
