#define F_CPU 16000000UL
#include "GPIO.h"


void GPIO:: pinMode(uint8_t _portName, uint8_t _pinName, uint8_t _mode){
	if( this->portName == PA){
		if(this->pinName == 0)
			DDRA = DDRA | (_mode<<this->pinName);
		else if(this->pinName == 1)
			DDRA = DDRA | (_mode<<this->pinName);
		else if(this->pinName == 2)
			DDRA = DDRA | (_mode<<this->pinName);
		else if(this->pinName == 3)
			DDRA = DDRA | (_mode<<this->pinName);
		else if(this->pinName == 4)
			DDRA = DDRA | (_mode<<this->pinName);
		else if(this->pinName == 5)
			DDRA = DDRA | (_mode<<this->pinName);
		else if(this->pinName == 6)
			DDRA = DDRA | (_mode<<this->pinName);
		else if(this->pinName == 7)
			DDRA = DDRA | (_mode<<this->pinName);
	}
	
	else if(this->portName == PB){
		if(this->pinName == 0)
			DDRB = DDRB | (_mode<<this->pinName);
		else if(this->pinName == 1)
			DDRB = DDRB | (_mode<<this->pinName);
		else if(this->pinName == 2)
			DDRB = DDRB | (_mode<<this->pinName);
		else if(this->pinName == 3)
			DDRB = DDRB | (_mode<<this->pinName);
		else if(this->pinName == 4)
			DDRB = DDRB | (_mode<<this->pinName);
		else if(this->pinName == 5)
			DDRB = DDRB | (_mode<<this->pinName);
		else if(this->pinName == 6)
			DDRB = DDRB | (_mode<<this->pinName);
		else if(this->pinName == 7)
			DDRB = DDRB | (_mode<<this->pinName);
	}
	
	else if(this->portName == PC){
		if(this->pinName == 0)
			DDRC = DDRC | (_mode<<this->pinName);
		else if(this->pinName == 1)
			DDRC = DDRC | (_mode<<this->pinName);
		else if(this->pinName == 2)
			DDRC = DDRC | (_mode<<this->pinName);
		else if(this->pinName == 3)
			DDRC = DDRC | (_mode<<this->pinName);
		else if(this->pinName == 4)
			DDRC = DDRC | (_mode<<this->pinName);
		else if(this->pinName == 5)
			DDRC = DDRC | (_mode<<this->pinName);
		else if(this->pinName == 6)
			DDRC = DDRC | (_mode<<this->pinName);
		else if(this->pinName == 7)
			DDRC = DDRC | (_mode<<this->pinName);
	}
	
	else if(this->portName == PD){
		if(this->pinName == 0)
			DDRD = DDRD | (_mode<<this->pinName);
		else if(this->pinName == 1)
			DDRD = DDRD | (_mode<<this->pinName);
		else if(this->pinName == 2)
			DDRD = DDRD | (_mode<<this->pinName);
		else if(this->pinName == 3)
			DDRD = DDRD | (_mode<<this->pinName);
		else if(this->pinName == 4)
			DDRD = DDRD | (_mode<<this->pinName);
		else if(this->pinName == 5)
			DDRD = DDRD | (_mode<<this->pinName);
		else if(this->pinName == 6)
			DDRD = DDRD | (_mode<<this->pinName);
		else if(this->pinName == 7)
			DDRD = DDRD | (_mode<<this->pinName);
	}
	
	else if(this->portName == PE){
		if(this->pinName == 0)
			DDRE = DDRE | (_mode<<this->pinName);
		else if(this->pinName == 1)
			DDRE = DDRE | (_mode<<this->pinName);
		else if(this->pinName == 2)
			DDRE = DDRE | (_mode<<this->pinName);
		else if(this->pinName == 3)
			DDRE = DDRE | (_mode<<this->pinName);
		else if(this->pinName == 4)
			DDRE = DDRE | (_mode<<this->pinName);
		else if(this->pinName == 5)
			DDRE = DDRE | (_mode<<this->pinName);
		else if(this->pinName == 6)
			DDRE = DDRE | (_mode<<this->pinName);
		else if(this->pinName == 7)
			DDRE = DDRE | (_mode<<this->pinName);
	}
	
	else if(this->portName == PF){
		if(this->pinName == 0)
			DDRF = DDRF | (_mode<<this->pinName);
		else if(this->pinName == 1)
			DDRF = DDRF | (_mode<<this->pinName);
		else if(this->pinName == 2)
			DDRF = DDRF | (_mode<<this->pinName);
		else if(this->pinName == 3)
			DDRF = DDRF | (_mode<<this->pinName);
		else if(this->pinName == 4)
			DDRF = DDRF | (_mode<<this->pinName);
		else if(this->pinName == 5)
			DDRF = DDRF | (_mode<<this->pinName);
		else if(this->pinName == 6)
			DDRF = DDRF | (_mode<<this->pinName);
		else if(this->pinName == 7)
			DDRF = DDRF | (_mode<<this->pinName);
	}
	
	else if(this->portName == PG){
		if(this->pinName == 0)
			DDRG = DDRG | (_mode<<this->pinName);
		else if(this->pinName == 1)
			DDRG = DDRG | (_mode<<this->pinName);
		else if(this->pinName == 2)
			DDRG = DDRG | (_mode<<this->pinName);
		else if(this->pinName == 3)
			DDRG = DDRG | (_mode<<this->pinName);
		else if(this->pinName == 4)
			DDRG = DDRG | (_mode<<this->pinName);
	}
	
	
}

void GPIO::writePin(uint8_t _state){
	this->current_Status = _state;
	if( this->portName == PA ){
		if( this->current_Status == HIGH ){
			PORTA = PORTA | (1<<this->pinName);
		}
		else if(this->current_Status == LOW ){
			PORTA = PORTA ^ (1<<this->pinName);
		}
	}
	
	else if( this->portName == PB ){
		if( this->current_Status == HIGH ){
			PORTB = PORTB | (1<<this->pinName);
		}
		else if(this->current_Status == LOW ){
			PORTB = PORTB ^ (1<<this->pinName);
		}
	}
	
	else if( this->portName == PC ){
		if( this->current_Status == HIGH ){
			PORTC = PORTC | (1<<this->pinName);
		}
		else if(this->current_Status == LOW ){
			PORTC = PORTC ^ (1<<this->pinName);
		}
	}
	
	else if( this->portName == PD ){
		if( this->current_Status == HIGH ){
			PORTD = PORTD | (1<<this->pinName);
		}
		else if(this->current_Status == LOW ){
			PORTD = PORTD ^ (1<<this->pinName);
		}
	}
	
	else if( this->portName == PE ){
		if( this->current_Status == HIGH ){
			PORTE = PORTE | (1<<this->pinName);
		}
		else if(this->current_Status == LOW ){
			PORTE = PORTE ^ (1<<this->pinName);
		}
	}
	
	else if( this->portName == PF ){
		if( this->current_Status == HIGH ){
			PORTF = PORTF | (1<<this->pinName);
		}
		else if(this->current_Status == LOW ){
			PORTF = PORTF ^ (1<<this->pinName);
		}
	}
	
	else if( this->portName == PG ){
		if( this->current_Status == HIGH ){
			PORTG = PORTG | (1<<this->pinName);
		}
		else if(this->current_Status == LOW ){
			PORTG = PORTG ^ (1<<this->pinName);
		}
	}
	

	
	
}

int GPIO::readPin(){
	if( this->portName == PA ){
		return (PINA>>this->pinName) & 0x01;
	}
	
	else if( this->portName == PB ){
		return (PINB>>this->pinName) & 0x01;
	}
	
	else if( this->portName == PC ){
		return (PINC>>this->pinName) & 0x01;
	}
	
	else if( this->portName == PD ){
		return (PIND>>this->pinName) & 0x01;
	}
	
	else if( this->portName == PE ){
		return (PINE>>this->pinName) & 0x01;
	}
	
	else if( this->portName == PF ){
		return (PINF>>this->pinName) & 0x01;
	}
	
	else if( this->portName == PG ){
		return (PING>>this->pinName) & 0x01;
	}
	
	
}

void GPIO::on(){
	this->current_Status = HIGH;
	if( this->portName == PA ){
		PORTA = PORTA | (HIGH<<this->pinName);
	}
	
	else if( this->portName == PB ){
		PORTB = PORTB | (HIGH<<this->pinName);
	}
	
	else if( this->portName == PC ){
		PORTC = PORTC | (HIGH<<this->pinName);
	}
	
	else if( this->portName == PD ){
		PORTD = PORTD | (HIGH<<this->pinName);
	}
	
	else if( this->portName == PE ){
		PORTE = PORTE | (HIGH<<this->pinName);
	}
	
	else if( this->portName == PF ){
		PORTF = PORTF | (HIGH<<this->pinName);
	}
	
	else if( this->portName == PG ){
		PORTG = PORTG | (HIGH<<this->pinName);
	}
	
	
}

void GPIO::off(){
	this->current_Status = LOW;
	if( this->portName == PA ){
		PORTA = PORTA ^ (HIGH<<this->pinName);
	}
	
	else if( this->portName == PB ){
		PORTB = PORTB ^ (HIGH<<this->pinName);
	}
	
	else if( this->portName == PC ){
		PORTC = PORTC ^ (HIGH<<this->pinName);
	}
	
	else if( this->portName == PD ){
		PORTD = PORTD ^ (HIGH<<this->pinName);
	}
	
	else if( this->portName == PE ){
		PORTE = PORTE ^ (HIGH<<this->pinName);
	}
	
	else if( this->portName == PF ){
		PORTF = PORTF ^ (HIGH<<this->pinName);
	}
	
	else if( this->portName == PG ){
		PORTG = PORTG ^ (HIGH<<this->pinName);
	}
}

void GPIO::toggle(){
	if( this->current_Status == HIGH ){
		if( this->portName == PA ){
			PORTA = PORTA ^ (1<<this->pinName);
		}
		
		else if( this->portName == PB ){
			PORTB = PORTB ^ (1<<this->pinName);
		}
		
		else if( this->portName == PC ){
			PORTC = PORTC ^ (1<<this->pinName);
		}
		
		else if( this->portName == PD ){
			PORTD = PORTD ^ (1<<this->pinName);
		}
		
		else if( this->portName == PE ){
			PORTE = PORTE ^ (1<<this->pinName);
		}
		
		else if( this->portName == PF ){
			PORTF = PORTF ^ (1<<this->pinName);
		}
		
		else if( this->portName == PG ){
			PORTG = PORTG ^ (1<<this->pinName);
		}
		this->current_Status = LOW;
	}
	
	else if( this->current_Status == LOW ){
		if( this->portName == PA ){
			PORTA = PORTA | (1<<this->pinName);
		}
		
		else if( this->portName == PB ){
			PORTB = PORTB | (1<<this->pinName);
		}
		
		else if( this->portName == PC ){
			PORTC = PORTC | (1<<this->pinName);
		}
		
		else if( this->portName == PD ){
			PORTD = PORTD | (1<<this->pinName);
		}
		
		else if( this->portName == PE ){
			PORTE = PORTE | (1<<this->pinName);
		}
		
		else if( this->portName == PF ){
			PORTF = PORTF | (1<<this->pinName);
		}
		
		else if( this->portName == PG ){
			PORTG = PORTG | (1<<this->pinName);
		}
		this->current_Status = HIGH;
	}
}