/* 
* Servo.h
*
* Created: 2021-04-24 오후 7:00:47
* Author: 박창순
*/


#ifndef __SERVO_H__
#define __SERVO_H__

#include "port.h"

class Servo
{
//variables
public:
	unsigned char PIN;
	unsigned int ICR;

//functions
public:
	Servo();
	~Servo();
public:
	void attach(unsigned char pin);
	void write(unsigned char angle);

}; //Servo

#endif //__SERVO_H__
