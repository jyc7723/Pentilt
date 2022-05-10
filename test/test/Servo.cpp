/* 
* Servo.cpp
*
* Created: 2021-04-24 오후 7:00:47
* Author: 박창순
*/


#include "Servo.h"

// default constructor
Servo::Servo()
{
	PIN = 0;
	ICR = 0;
} //Servo

// default destructor
Servo::~Servo()
{
} //~Servo

void Servo::attach(unsigned char pin)
{
	PIN = pin;
	ICR = 40000-1;
	if(pin == B5)
	{
		pinMode(B5, OUTPUT);
		TCCR1A |= (1<<COM1A1) | (1<<WGM11);
		TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11);
		
		ICR1 = 40000-1;
	}
	if(pin == B6)
	{
		pinMode(B6, OUTPUT);
		TCCR1A |= (1<<COM1B1) | (1<<WGM11);
		TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11);
		
		ICR1 = 40000-1;
	}
	if(pin == B7)
	{
		pinMode(B7, OUTPUT);
		TCCR1A |= (1<<COM1C1) | (1<<WGM11);
		TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11);
		
		ICR1 = 40000-1;
	}
	if(pin == E3)
	{
		pinMode(E3, OUTPUT);
		TCCR1A |= (1<<COM3A1) | (1<<WGM11);
		TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11);
		
		ICR3 = 40000-1;
	}
	if(pin == E4)
	{
		pinMode(E4, OUTPUT);
		TCCR1A |= (1<<COM3B1) | (1<<WGM11);
		TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11);
		
		ICR3 = 40000-1;
	}
	if(pin == E5)
	{
		pinMode(E5, OUTPUT);
		TCCR1A |= (1<<COM3C1) | (1<<WGM11);
		TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS11);
		
		ICR3 = 40000-1;
	}
}

void Servo::write(unsigned char angle)
{
	if(angle > 180) angle = 180;
	if(angle < 0)   angle = 0;
	if(PIN == B5) OCR1A = (unsigned int)(1000+(4000*((float)angle/180)));
	if(PIN == B6) OCR1B = (unsigned int)(1000+(4000*((float)angle/180)));
	if(PIN == B7) OCR1C = (unsigned int)(1000+(4000*((float)angle/180)));
	if(PIN == E3) OCR3A = (unsigned int)(1000+(4000*((float)angle/180)));
	if(PIN == E4) OCR3B = (unsigned int)(1000+(4000*((float)angle/180)));
	if(PIN == E5) OCR3C = (unsigned int)(1000+(4000*((float)angle/180)));
}