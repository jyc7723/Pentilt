#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/iom128a.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>




#include "GPIO.h"
#include "UART.h"
#include "TIMER.h"


#define LED_PORT PG
#define LED_pin 0
