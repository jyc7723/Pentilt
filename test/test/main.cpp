/*
 * test.cpp
 *
 * Created: 2021-04-21(수) 오후 7:10:02
 * Author : winje
 */ 

#include <avr/io.h>
#include <avr/iom128a.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "port.h"
#include "Servo.h"
#include "Uart.h"

#define delay(d) _delay_ms(d)

Uart Serial;
Servo servo1;
Servo servo2;

void setup(void)
{
	Serial.begin(250000);
	servo1.attach(B5);
	servo2.attach(B6);
	pinMode(F0, OUTPUT);
	digitalWrite(F0, HIGH);
}

void loop(void)
{
	if(Serial.available() > 1)
	{
		char c = Serial.read();
		if(c == 'x')
		{
			int a = Serial.parseInt();
			servo1.write(a);
		}
		if(c == 'y')
		{
			int a = Serial.parseInt();
			servo2.write(a);
		}
	}
}


int main(void)
{
	setup();
	
	while (1) 
    {
		loop();
	}
	return 0;
}