/*
 * port.cpp
 *
 * Created: 2021-04-21(수) 오후 8:31:14
 *  Author: winje
 */ 

#include "port.h"

void pinMode(unsigned char pin, bool mode)
{
	// PORTA
	if     (pin == A0 && mode)	DDRA |= (1<<DDRA0);
	else if(pin == A1 && mode)	DDRA |= (1<<DDRA1);
	else if(pin == A2 && mode)	DDRA |= (1<<DDRA2);
	else if(pin == A3 && mode)	DDRA |= (1<<DDRA3);
	else if(pin == A4 && mode)	DDRA |= (1<<DDRA4);
	else if(pin == A5 && mode)	DDRA |= (1<<DDRA5);
	else if(pin == A6 && mode)	DDRA |= (1<<DDRA6);
	else if(pin == A7 && mode)	DDRA |= (1<<DDRA7);
	
	// PORTB
	else if(pin == B0 && mode)	DDRB |= (1<<DDRB0);
	else if(pin == B1 && mode)	DDRB |= (1<<DDRB1);
	else if(pin == B2 && mode)	DDRB |= (1<<DDRB2);
	else if(pin == B3 && mode)	DDRB |= (1<<DDRB3);
	else if(pin == B4 && mode)	DDRB |= (1<<DDRB4);
	else if(pin == B5 && mode)	DDRB |= (1<<DDRB5);
	else if(pin == B6 && mode)	DDRB |= (1<<DDRB6);
	else if(pin == B7 && mode)	DDRB |= (1<<DDRB7);
	
	// PORTC
	else if(pin == C0 && mode)	DDRC |= (1<<DDRC0);
	else if(pin == C1 && mode)	DDRC |= (1<<DDRC1);
	else if(pin == C2 && mode)	DDRC |= (1<<DDRC2);
	else if(pin == C3 && mode)	DDRC |= (1<<DDRC3);
	else if(pin == C4 && mode)	DDRC |= (1<<DDRC4);
	else if(pin == C5 && mode)	DDRC |= (1<<DDRC5);
	else if(pin == C6 && mode)	DDRC |= (1<<DDRC6);
	else if(pin == C7 && mode)	DDRC |= (1<<DDRC7);
	
	// PORTD
	else if(pin == D0 && mode)	DDRD |= (1<<DDRD0);
	else if(pin == D1 && mode)	DDRD |= (1<<DDRD1);
	else if(pin == D2 && mode)	DDRD |= (1<<DDRD2);
	else if(pin == D3 && mode)	DDRD |= (1<<DDRD3);
	else if(pin == D4 && mode)	DDRD |= (1<<DDRD4);
	else if(pin == D5 && mode)	DDRD |= (1<<DDRD5);
	else if(pin == D6 && mode)	DDRD |= (1<<DDRD6);
	else if(pin == D7 && mode)	DDRD |= (1<<DDRD7);
	
	// PORTE
	else if(pin == E0 && mode)	DDRE |= (1<<DDRE0);
	else if(pin == E1 && mode)	DDRE |= (1<<DDRE1);
	else if(pin == E2 && mode)	DDRE |= (1<<DDRE2);
	else if(pin == E3 && mode)	DDRE |= (1<<DDRE3);
	else if(pin == E4 && mode)	DDRE |= (1<<DDRE4);
	else if(pin == E5 && mode)	DDRE |= (1<<DDRE5);
	else if(pin == E6 && mode)	DDRE |= (1<<DDRE6);
	else if(pin == E7 && mode)	DDRE |= (1<<DDRE7);
	
	// PORTF
	else if(pin == F0 && mode)	DDRF |= (1<<DDRF0);
	else if(pin == F1 && mode)	DDRF |= (1<<DDRF1);
	else if(pin == F2 && mode)	DDRF |= (1<<DDRF2);
	else if(pin == F3 && mode)	DDRF |= (1<<DDRF3);
	else if(pin == F4 && mode)	DDRF |= (1<<DDRF4);
	else if(pin == F5 && mode)	DDRF |= (1<<DDRF5);
	else if(pin == F6 && mode)	DDRF |= (1<<DDRF6);
	else if(pin == F7 && mode)	DDRF |= (1<<DDRF7);
	
	// PORTG
	else if(pin == G0 && mode)	DDRG |= (1<<DDRG0);
	else if(pin == G1 && mode)	DDRG |= (1<<DDRG1);
	else if(pin == G2 && mode)	DDRG |= (1<<DDRG2);
	else if(pin == G3 && mode)	DDRG |= (1<<DDRG3);
	else if(pin == G4 && mode)	DDRG |= (1<<DDRG4);
}

void digitalWrite(unsigned char pin, bool mode)
{
	// PORTA
	if     (pin == A0 && mode)	PORTA |= (1<<PORTA0);
	else if(pin == A1 && mode)	PORTA |= (1<<PORTA1);
	else if(pin == A2 && mode)	PORTA |= (1<<PORTA2);
	else if(pin == A3 && mode)	PORTA |= (1<<PORTA3);
	else if(pin == A4 && mode)	PORTA |= (1<<PORTA4);
	else if(pin == A5 && mode)	PORTA |= (1<<PORTA5);
	else if(pin == A6 && mode)	PORTA |= (1<<PORTA6);
	else if(pin == A7 && mode)	PORTA |= (1<<PORTA7);
	
	else if(pin == A0 && !mode)	PORTA &= ~(1<<PORTA0);
	else if(pin == A1 && !mode)	PORTA &= ~(1<<PORTA1);
	else if(pin == A2 && !mode)	PORTA &= ~(1<<PORTA2);
	else if(pin == A3 && !mode)	PORTA &= ~(1<<PORTA3);
	else if(pin == A4 && !mode)	PORTA &= ~(1<<PORTA4);
	else if(pin == A5 && !mode)	PORTA &= ~(1<<PORTA5);
	else if(pin == A6 && !mode)	PORTA &= ~(1<<PORTA6);
	else if(pin == A7 && !mode)	PORTA &= ~(1<<PORTA7);
	
	// PORTB
	else if(pin == B0 && mode)	PORTB |= (1<<PORTB0);
	else if(pin == B1 && mode)	PORTB |= (1<<PORTB1);
	else if(pin == B2 && mode)	PORTB |= (1<<PORTB2);
	else if(pin == B3 && mode)	PORTB |= (1<<PORTB3);
	else if(pin == B4 && mode)
	{
		if(TCCR0 != 0x00)
		{
			TCCR0 = 0x00;
			OCR0  = 0;
		}
		PORTB |= (1<<PORTB4);
	}
	else if(pin == B5 && mode)
	{
		if(TCCR1A != 0x00 || TCCR1B != 0x00 || TCCR1C != 0x00)
		{
			TCCR1A = 0x00;
			TCCR1B = 0x00;
			TCCR1C = 0x00;
			ICR1   = 0;
			OCR1A  = 0;
		}
		PORTB |= (1<<PORTB5);
	}
	else if(pin == B6 && mode)
	{
		if(TCCR1A != 0x00 || TCCR1B != 0x00 || TCCR1C != 0x00)
		{
			TCCR1A = 0x00;
			TCCR1B = 0x00;
			TCCR1C = 0x00;
			ICR1   = 0;
			OCR1B  = 0;
		}
		PORTB |= (1<<PORTB6);
	}
	else if(pin == B7 && mode)
	{
		if(TCCR1A != 0x00 || TCCR1B != 0x00 || TCCR1C != 0x00)
		{
			TCCR1A = 0x00;
			TCCR1B = 0x00;
			TCCR1C = 0x00;
			ICR1   = 0;
			OCR1C  = 0;
		}
		PORTB |= (1<<PORTB7);
	}
	else if(pin == B0 && !mode)	PORTB &= ~(1<<PORTB0);
	else if(pin == B1 && !mode)	PORTB &= ~(1<<PORTB1);
	else if(pin == B2 && !mode)	PORTB &= ~(1<<PORTB2);
	else if(pin == B3 && !mode)	PORTB &= ~(1<<PORTB3);
	else if(pin == B4 && !mode)
	{
		if(TCCR0 != 0x00)
		{
			TCCR0 = 0x00;
			OCR0  = 0;
		}
		PORTB &= ~(1<<PORTB4);
	}
	else if(pin == B5 && !mode)
	{
		if(TCCR1A != 0x00 || TCCR1B != 0x00 || TCCR1C != 0x00)
		{
			TCCR1A = 0x00;
			TCCR1B = 0x00;
			TCCR1C = 0x00;
			ICR1   = 0;
			OCR1A  = 0;
		}
		PORTB &= ~(1<<PORTB5);
	}
	else if(pin == B6 && !mode)
	{
		if(TCCR1A != 0x00 || TCCR1B != 0x00 || TCCR1C != 0x00)
		{
			TCCR1A = 0x00;
			TCCR1B = 0x00;
			TCCR1C = 0x00;
			ICR1   = 0;
			OCR1B  = 0;
		}
		PORTB &= ~(1<<PORTB6);
	}
	else if(pin == B7 && !mode)
	{
		if(TCCR1A != 0x00 || TCCR1B != 0x00 || TCCR1C != 0x00)
		{
			TCCR1A = 0x00;
			TCCR1B = 0x00;
			TCCR1C = 0x00;
			ICR1   = 0;
			OCR1C  = 0;
		}
		PORTB &= ~(1<<PORTB7);
	}
	
	// PORTC
	else if(pin == C0 && mode)	PORTC |= (1<<PORTC0);
	else if(pin == C1 && mode)	PORTC |= (1<<PORTC1);
	else if(pin == C2 && mode)	PORTC |= (1<<PORTC2);
	else if(pin == C3 && mode)	PORTC |= (1<<PORTC3);
	else if(pin == C4 && mode)	PORTC |= (1<<PORTC4);
	else if(pin == C5 && mode)	PORTC |= (1<<PORTC5);
	else if(pin == C6 && mode)	PORTC |= (1<<PORTC6);
	else if(pin == C7 && mode)	PORTC |= (1<<PORTC7);
	
	else if(pin == C0 && !mode)	PORTC &= ~(1<<PORTC0);
	else if(pin == C1 && !mode)	PORTC &= ~(1<<PORTC1);
	else if(pin == C2 && !mode)	PORTC &= ~(1<<PORTC2);
	else if(pin == C3 && !mode)	PORTC &= ~(1<<PORTC3);
	else if(pin == C4 && !mode)	PORTC &= ~(1<<PORTC4);
	else if(pin == C5 && !mode)	PORTC &= ~(1<<PORTC5);
	else if(pin == C6 && !mode)	PORTC &= ~(1<<PORTC6);
	else if(pin == C7 && !mode)	PORTC &= ~(1<<PORTC7);
	
	// PORTD
	else if(pin == D0 && mode)	PORTD |= (1<<PORTD0);
	else if(pin == D1 && mode)	PORTD |= (1<<PORTD1);
	else if(pin == D2 && mode)	PORTD |= (1<<PORTD2);
	else if(pin == D3 && mode)	PORTD |= (1<<PORTD3);
	else if(pin == D4 && mode)	PORTD |= (1<<PORTD4);
	else if(pin == D5 && mode)	PORTD |= (1<<PORTD5);
	else if(pin == D6 && mode)	PORTD |= (1<<PORTD6);
	else if(pin == D7 && mode)	PORTD |= (1<<PORTD7);
	
	else if(pin == D0 && !mode)	PORTD &= ~(1<<PORTD0);
	else if(pin == D1 && !mode)	PORTD &= ~(1<<PORTD1);
	else if(pin == D2 && !mode)	PORTD &= ~(1<<PORTD2);
	else if(pin == D3 && !mode)	PORTD &= ~(1<<PORTD3);
	else if(pin == D4 && !mode)	PORTD &= ~(1<<PORTD4);
	else if(pin == D5 && !mode)	PORTD &= ~(1<<PORTD5);
	else if(pin == D6 && !mode)	PORTD &= ~(1<<PORTD6);
	else if(pin == D7 && !mode)	PORTD &= ~(1<<PORTD7);
	
	// PORTE
	else if(pin == E0 && mode)	PORTE |= (1<<PORTE0);
	else if(pin == E1 && mode)	PORTE |= (1<<PORTE1);
	else if(pin == E2 && mode)	PORTE |= (1<<PORTE2);
	else if(pin == E3 && mode)
	{
		if(TCCR3A != 0x00 || TCCR3B != 0x00 || TCCR3C != 0x00)
		{
			TCCR3A = 0x00;
			TCCR3B = 0x00;
			TCCR3C = 0x00;
			ICR3   = 0;
			OCR3A  = 0;
		}
		PORTE |= (1<<PORTE3);
	}
	else if(pin == E4 && mode)
	{
		if(TCCR3A != 0x00 || TCCR3B != 0x00 || TCCR3C != 0x00)
		{
			TCCR3A = 0x00;
			TCCR3B = 0x00;
			TCCR3C = 0x00;
			ICR3   = 0;
			OCR3B  = 0;
		}
		PORTE |= (1<<PORTE4);
	}
	else if(pin == E5 && mode)
	{
		if(TCCR3A != 0x00 || TCCR3B != 0x00 || TCCR3C != 0x00)
		{
			TCCR3A = 0x00;
			TCCR3B = 0x00;
			TCCR3C = 0x00;
			ICR3   = 0;
			OCR3C  = 0;
		}
		PORTE |= (1<<PORTE5);
	}
	else if(pin == E6 && mode)	PORTE |= (1<<PORTE6);
	else if(pin == E7 && mode)	PORTE |= (1<<PORTE7);
	
	else if(pin == E0 && !mode)	PORTE &= ~(1<<PORTE0);
	else if(pin == E1 && !mode)	PORTE &= ~(1<<PORTE1);
	else if(pin == E2 && !mode)	PORTE &= ~(1<<PORTE2);
	else if(pin == E3 && !mode)
	{
		if(TCCR3A != 0x00 || TCCR3B != 0x00 || TCCR3C != 0x00)
		{
			TCCR3A = 0x00;
			TCCR3B = 0x00;
			TCCR3C = 0x00;
			ICR3   = 0;
			OCR3A  = 0;
		}
		PORTE &= ~(1<<PORTE3);
	}
	else if(pin == E4 && !mode)
	{
		if(TCCR3A != 0x00 || TCCR3B != 0x00 || TCCR3C != 0x00)
		{
			TCCR3A = 0x00;
			TCCR3B = 0x00;
			TCCR3C = 0x00;
			ICR3   = 0;
			OCR3B  = 0;
		}
		PORTE &= ~(1<<PORTE4);
	}
	else if(pin == E5 && !mode)
	{
		if(TCCR3A != 0x00 || TCCR3B != 0x00 || TCCR3C != 0x00)
		{
			TCCR3A = 0x00;
			TCCR3B = 0x00;
			TCCR3C = 0x00;
			ICR3   = 0;
			OCR3C  = 0;
		}
		PORTE &= ~(1<<PORTE5);
	}
	else if(pin == E6 && !mode)	PORTE &= ~(1<<PORTE6);
	else if(pin == E7 && !mode)	PORTE &= ~(1<<PORTE7);
	
	// PORTF
	else if(pin == F0 && mode)	PORTF |= (1<<PORTF0);
	else if(pin == F1 && mode)	PORTF |= (1<<PORTF1);
	else if(pin == F2 && mode)	PORTF |= (1<<PORTF2);
	else if(pin == F3 && mode)	PORTF |= (1<<PORTF3);
	else if(pin == F4 && mode)	PORTF |= (1<<PORTF4);
	else if(pin == F5 && mode)	PORTF |= (1<<PORTF5);
	else if(pin == F6 && mode)	PORTF |= (1<<PORTF6);
	else if(pin == F7 && mode)	PORTF |= (1<<PORTF7);
	
	else if(pin == F0 && !mode)	PORTF &= ~(1<<PORTF0);
	else if(pin == F1 && !mode)	PORTF &= ~(1<<PORTF1);
	else if(pin == F2 && !mode)	PORTF &= ~(1<<PORTF2);
	else if(pin == F3 && !mode)	PORTF &= ~(1<<PORTF3);
	else if(pin == F4 && !mode)	PORTF &= ~(1<<PORTF4);
	else if(pin == F5 && !mode)	PORTF &= ~(1<<PORTF5);
	else if(pin == F6 && !mode)	PORTF &= ~(1<<PORTF6);
	else if(pin == F7 && !mode)	PORTF &= ~(1<<PORTF7);
	
	// PORTG
	else if(pin == G0 && mode)	PORTG |= (1<<PORTF0);
	else if(pin == G1 && mode)	PORTG |= (1<<PORTF1);
	else if(pin == G2 && mode)	PORTG |= (1<<PORTF2);
	else if(pin == G3 && mode)	PORTG |= (1<<PORTF3);
	else if(pin == G4 && mode)	PORTG |= (1<<PORTF4);
	
	else if(pin == G0 && !mode)	PORTG &= ~(1<<PORTF0);
	else if(pin == G1 && !mode)	PORTG &= ~(1<<PORTF1);
	else if(pin == G2 && !mode)	PORTG &= ~(1<<PORTF2);
	else if(pin == G3 && !mode)	PORTG &= ~(1<<PORTF3);
	else if(pin == G4 && !mode)	PORTG &= ~(1<<PORTF4);
	else{}
}

bool digitalRead(unsigned char pin)
{
	bool state;
	
	// PORTA
	if     (pin == A0) state = PINA&(1<<PINA0);
	else if(pin == A1) state = PINA&(1<<PINA1);
	else if(pin == A2) state = PINA&(1<<PINA2);
	else if(pin == A3) state = PINA&(1<<PINA3);
	else if(pin == A4) state = PINA&(1<<PINA4);
	else if(pin == A5) state = PINA&(1<<PINA5);
	else if(pin == A6) state = PINA&(1<<PINA6);
	else if(pin == A7) state = PINA&(1<<PINA7);
	
	// PORTB
	else if(pin == B0) state = PINB&(1<<PINB0);
	else if(pin == B1) state = PINB&(1<<PINB1);
	else if(pin == B2) state = PINB&(1<<PINB2);
	else if(pin == B3) state = PINB&(1<<PINB3);
	else if(pin == B4) state = PINB&(1<<PINB4);
	else if(pin == B5) state = PINB&(1<<PINB5);
	else if(pin == B6) state = PINB&(1<<PINB6);
	else if(pin == B7) state = PINB&(1<<PINB7);
	
	// PORTC
	else if(pin == C0) state = PINC&(1<<PINC0);
	else if(pin == C1) state = PINC&(1<<PINC1);
	else if(pin == C2) state = PINC&(1<<PINC2);
	else if(pin == C3) state = PINC&(1<<PINC3);
	else if(pin == C4) state = PINC&(1<<PINC4);
	else if(pin == C5) state = PINC&(1<<PINC5);
	else if(pin == C6) state = PINC&(1<<PINC6);
	else if(pin == C7) state = PINC&(1<<PINC7);
	
	// PORTD
	else if(pin == D0) state = PIND&(1<<PIND0);
	else if(pin == D1) state = PIND&(1<<PIND1);
	else if(pin == D2) state = PIND&(1<<PIND2);
	else if(pin == D3) state = PIND&(1<<PIND3);
	else if(pin == D4) state = PIND&(1<<PIND4);
	else if(pin == D5) state = PIND&(1<<PIND5);
	else if(pin == D6) state = PIND&(1<<PIND6);
	else if(pin == D7) state = PIND&(1<<PIND7);
	
	// PORTE
	else if(pin == E0) state = PINE&(1<<PINE0);
	else if(pin == E1) state = PINE&(1<<PINE1);
	else if(pin == E2) state = PINE&(1<<PINE2);
	else if(pin == E3) state = PINE&(1<<PINE3);
	else if(pin == E4) state = PINE&(1<<PINE4);
	else if(pin == E5) state = PINE&(1<<PINE5);
	else if(pin == E6) state = PINE&(1<<PINE6);
	else if(pin == E7) state = PINE&(1<<PINE7);
	
	// PORTF
	else if(pin == F0) state = PINF&(1<<PINF0);
	else if(pin == F1) state = PINF&(1<<PINF1);
	else if(pin == F2) state = PINF&(1<<PINF2);
	else if(pin == F3) state = PINF&(1<<PINF3);
	else if(pin == F4) state = PINF&(1<<PINF4);
	else if(pin == F5) state = PINF&(1<<PINF5);
	else if(pin == F6) state = PINF&(1<<PINF6);
	else if(pin == F7) state = PINF&(1<<PINF7);
	
	// PORTG	
	else if(pin == G0) state = PING&(1<<PING0);
	else if(pin == G1) state = PING&(1<<PING1);
	else if(pin == G2) state = PING&(1<<PING2);
	else if(pin == G3) state = PING&(1<<PING3);
	else if(pin == G4) state = PING&(1<<PING4);
	else{}
	
	return state;
}

void ADC_init(void)
{
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	ADMUX  |= (1<<REFS0);
}

void analogWrite(unsigned char pin, unsigned char _value)
{
	if(pin == B4)
	{
		if(_value != 0)
		{
			if(TCCR0 == 0x00)
			{
				TCCR0 |= (1<<CS02) | (1<<WGM00) | (1<<WGM01) | (1<<COM01);
				TCNT0  = 0;
				OCR0   = 0;
			}
			OCR0  = _value;
		}
		else digitalWrite(pin, LOW);
	}
	else if(pin == B5)
	{
		if(TCCR1A == 0x00 || TCCR1B == 0x00 || TCCR1C == 0x00)
		{
			TCCR1A |= (1<<COM1A1) | (1<<WGM11);
			TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS10);
			
			ICR1 = 16000-1;
		}
		OCR1A = map(_value, 0, 255, 0, 15999);
	}
	else if(pin == B6)
	{
		if(TCCR1A == 0x00 || TCCR1B == 0x00 || TCCR1C == 0x00)
		{
			TCCR1A |= (1<<COM1B1) | (1<<WGM11);
			TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS10);
			
			ICR1 = 16000-1;
		}
		OCR1B = map(_value, 0, 255, 0, 15999);
	}
	else if(pin == B7)
	{
		if(TCCR1A == 0x00 || TCCR1B == 0x00 || TCCR1C == 0x00)
		{
			TCCR1A |= (1<<COM1C1) | (1<<WGM11);
			TCCR1B |= (1<<WGM12) | (1<<WGM13) | (1<<CS10);
			
			ICR1 = 16000-1;
		}
		OCR1C = map(_value, 0, 255, 0, 15999);
	}
	else if(pin == E3)
	{
		if(TCCR3A == 0x00 || TCCR3B == 0x00 || TCCR3C == 0x00)
		{
			TCCR3A |= (1<<COM3A1) | (1<<WGM31);
			TCCR3B |= (1<<WGM32) | (1<<WGM33) | (1<<CS30);
			
			ICR3 = 16000-1;
		}
		OCR3A = map(_value, 0, 255, 0, 15999);
	}
	else if(pin == E4)
	{
		if(TCCR3A == 0x00 || TCCR3B == 0x00 || TCCR3C == 0x00)
		{
			TCCR3A |= (1<<COM3B1) | (1<<WGM31);
			TCCR3B |= (1<<WGM32) | (1<<WGM33) | (1<<CS30);
			
			ICR3 = 16000-1;
		}
		OCR3B = map(_value, 0, 255, 0, 15999);
	}
	else if(pin == E5)
	{
		if(TCCR3A == 0x00 || TCCR3B == 0x00 || TCCR3C == 0x00)
		{
			TCCR3A |= (1<<COM3C1) | (1<<WGM31);
			TCCR3B |= (1<<WGM32) | (1<<WGM33) | (1<<CS30);
			
			ICR3 = 16000-1;
		}
		OCR3C = map(_value, 0, 255, 0, 15999);
	}
	else{}
}

unsigned short analogRead(unsigned char pin)
{
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	ADMUX  |= (1<<REFS0);
	
	ADMUX  &= 0xF8;
	ADMUX  |= pin;
	
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	
	ADCSRA = 0x00;
	ADMUX  = 0x00;
	
	return ADCW;
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}