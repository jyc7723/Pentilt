/*
 * port.h
 *
 * Created: 2021-04-21(수) 오후 8:13:30
 *  Author: winje
 */ 


#ifndef PORT_H_
#define PORT_H_

#include <avr/io.h>

#define OUTPUT true
#define INPUT  false
#define HIGH   true
#define LOW    false

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5
#define A6 6
#define A7 7

#define B0 10
#define B1 11
#define B2 12
#define B3 13
#define B4 14
#define B5 15
#define B6 16
#define B7 17

#define C0 20
#define C1 21
#define C2 22
#define C3 23
#define C4 24
#define C5 25
#define C6 26
#define C7 27

#define D0 30
#define D1 31
#define D2 32
#define D3 33
#define D4 34
#define D5 35
#define D6 36
#define D7 37

#define E0 40
#define E1 41
#define E2 42
#define E3 43
#define E4 44
#define E5 45
#define E6 46
#define E7 47

#define F0 50
#define F1 51
#define F2 52
#define F3 53
#define F4 54
#define F5 55
#define F6 56
#define F7 57

#define G0 60
#define G1 61
#define G2 62
#define G3 63
#define G4 64

void pinMode(unsigned char pin, bool mode);
void digitalWrite(unsigned char pin, bool mode);
bool digitalRead(unsigned char pin);
void ADC_init(void);
void analogWrite(unsigned char pin, unsigned char _value);
unsigned short analogRead(unsigned char pin);
long map(long x, long in_min, long in_max, long out_min, long out_max);


#endif /* PORT_H_ */