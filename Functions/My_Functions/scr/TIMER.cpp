#include "TIMER.h"



TIMER::TIMER(uint8_t _timerName, uint8_t _waveForm, uint8_t _output, uint32_t _prescaler){
	this->timerName = _timerName;
	this->waveForm = _waveForm;
	this->output = _output;
	this->prescaler = _prescaler;
	
	
	this->init();
	
}


TIMER::TIMER(uint8_t _timerName){
	this->timerName = _timerName;
	if( this->timerName == TIM0 || this->timerName == TIM2 ){
		this->waveForm = FAST_PWM;
		this->output = NON_INVERTING;
		this->prescaler = PRESCALER64;
	}
	
	else if( this->timerName == TIM1A || this->timerName == TIM1B || this->timerName == TIM1C \
				|| this->timerName == TIM3A || this->timerName == TIM3B || this->timerName == TIM3C){
		this->waveForm = FAST_PWM;
		this->output = NON_INVERTING;
		this->prescaler = PRESCALER8;
		this->period = 40000 - 1;
	}
	
	
	this->init();
}

void TIMER::init(){
	cli();
	this->setWaveForm();
	this->setOutput();
	this->setPrescaler();
	this->setGPIO();
	this->setPeriod();
	sei();
}

void TIMER::setWaveForm(){
	if( this->timerName == TIM0 ){
		if( this->waveForm ==  NORMAL ){
			TCCR0 = TCCR0 | ( (0<<WGM01) | (0<<WGM00) );
		}
		
		else if( this->waveForm == PHASE_CORRECT ){
			TCCR0 = TCCR0 | ( (0<<WGM01) | (1<<WGM00) );
		}
		
		else if( this->waveForm == CTC ){
			TCCR0 = TCCR0 | ( (1<<WGM01) | (0<<WGM00) );
		}
		
		else if( this->waveForm == FAST_PWM ){
			TCCR0 = TCCR0 | ((1<<WGM01) | (1<<WGM00));
		}
	}
	
	else if( this->timerName == TIM1A || this->timerName == TIM1B ||  this->timerName == TIM1C ){
		if(this->waveForm == NORMAL ){
			TCCR1A = TCCR1A | ((0<<WGM11) | (0<<WGM10));
			TCCR1B = TCCR1B | ((0<<WGM13) | (0<<WGM12));
		}
		
		else if( this->waveForm == PHASE_CORRECT ){
			TCCR1A = TCCR1A | ((1<<WGM11) | (0<<WGM10));
			TCCR1B = TCCR1B | ((1<<WGM13) | (0<<WGM12));
		}
		
		else if (this->waveForm == CTC ){
			TCCR1A = TCCR1A | ((0<<WGM11) | (0<<WGM10));
			TCCR1B = TCCR1B | ((1<<WGM13) | (1<<WGM12));
		}
		
		else if (this->waveForm == FAST_PWM ){
			TCCR1A = TCCR1A | ((1<<WGM11) | (0<<WGM10));
			TCCR1B = TCCR1B | ((1<<WGM13) | (1<<WGM12));
		}
	}
	
	else if( this->timerName == TIM2 ){
		if( this->waveForm ==  NORMAL ){
			TCCR2 = TCCR2 | ( (0<<WGM21) | (0<<WGM20) );
		}
		
		else if( this->waveForm == PHASE_CORRECT ){
			TCCR2 = TCCR2 | (1<<WGM20);
		}
		
		else if( this->waveForm == CTC ){
			TCCR2 = TCCR2 | ((1<<WGM21));
		}
		
		else if( this->waveForm == FAST_PWM ){
			TCCR2 = TCCR2 | ((1<<WGM21) | (1<<WGM20));
		}
	}
	
	else if( this->timerName == TIM3A ||  this->timerName == TIM3B || this->timerName == TIM3C ){
		if(this->waveForm == NORMAL ){
			TCCR3A = TCCR3A | ((0<<WGM31) | (0<<WGM30));
			TCCR3B = TCCR3B | ((0<<WGM33) | (0<<WGM32));
		}
		
		else if( this->waveForm == PHASE_CORRECT ){
			TCCR3A = TCCR3A | ((1<<WGM31) | (0<<WGM30));
			TCCR3B = TCCR3B | ((1<<WGM33) | (0<<WGM32));
		}
		
		else if (this->waveForm == CTC ){
			TCCR3A = TCCR3A | ((0<<WGM31) | (0<<WGM30));
			TCCR3B = TCCR3B | ((1<<WGM33) | (1<<WGM32));
		}
		
		else if (this->waveForm == FAST_PWM ){
			TCCR3A = TCCR3A | ((1<<WGM31) | (0<<WGM30));
			TCCR3B = TCCR3B | ((1<<WGM33) | (1<<WGM32));
		}
	}
}

void TIMER::setOutput(){
	if(this->timerName == TIM0 ){
		if( this->output == DISCONNETED ){
			TCCR0 = TCCR0 | ( (0<<COM01) | (0<<COM00));
		}
		
		else if( this->output == TOGGLE ){
			TCCR0 = TCCR0 | ( (0<<COM01) | (1<<COM00));
		}
		
		else if( this->output == NON_INVERTING ){
			TCCR0 = TCCR0 | ( (1<<COM01) | (0<<COM00));
		}
		
		else if( this->output == INVERTING ){
			TCCR0 = TCCR0 | ( (1<<COM01) | (1<<COM00));
		}
	}
	
	else if( this->timerName == TIM1A ){
		if( this->output == DISCONNETED ){
			TCCR1A = TCCR1A | ((0<<COM1A1) | (0<<COM1A0));
		}
		
		else if( this->output == TOGGLE ){
			TCCR1A = TCCR1A | ((0<<COM1A1) | (1<<COM1A0));
		}
		
		else if( this->output == NON_INVERTING ){
			TCCR1A = TCCR1A | ((1<<COM1A1) | (0<<COM1A0));
		}
		
		else if( this->output == INVERTING ){
			TCCR1A = TCCR1A | ((1<<COM1A1) | (1<<COM1A0));
		}
	}
	
	else if( this->timerName == TIM1B ){
		if( this->output == DISCONNETED ){
			TCCR1A = TCCR1A | ((0<<COM1B1) | (0<<COM1B0));
		}
		
		else if( this->output == TOGGLE ){
			TCCR1A = TCCR1A | ((0<<COM1B1) | (1<<COM1B0));
		}
		
		else if( this->output == NON_INVERTING ){
			TCCR1A = TCCR1A | ((1<<COM1B1) | (0<<COM1B0));
		}
		
		else if( this->output == INVERTING ){
			TCCR1A = TCCR1A | ((1<<COM1B1) | (1<<COM1B0));
		}
	}
	
	else if( this->timerName == TIM1C ){
		if( this->output == DISCONNETED ){
			TCCR1A = TCCR1A | ((0<<COM1C1) | (0<<COM1C0));
		}
		
		else if( this->output == TOGGLE ){
			TCCR1A = TCCR1A | ((0<<COM1C1) | (1<<COM1C0));
		}
		
		else if( this->output == NON_INVERTING ){
			TCCR1A = TCCR1A | ((1<<COM1C1) | (0<<COM1C0));
		}
		
		else if( this->output == INVERTING ){
			TCCR1A = TCCR1A | ((1<<COM1C1) | (1<<COM1C0));
		}
	}
	
	else if( this->timerName == TIM2 ){
		if( this->output == DISCONNETED ){
			TCCR2 = TCCR2 | ( (0<<COM21) | (0<<COM20));
		}
		
		else if( this->output == TOGGLE ){
			TCCR2 = TCCR2 | ( (0<<COM21) | (1<<COM20));
		}
		
		else if( this->output == NON_INVERTING ){
			TCCR2 = TCCR2 | ( (1<<COM21) | (0<<COM20));
		}
		
		else if( this->output == INVERTING ){
			TCCR2 = TCCR2 | ( (1<<COM21) | (1<<COM20));
		}
	}
	
	else if( this->timerName == TIM3A ){
		if( this->output == DISCONNETED ){
			TCCR3A = TCCR3A | ((0<<COM3A1) | (0<<COM3A0));
		}
		
		else if( this->output == TOGGLE ){
			TCCR3A = TCCR3A | ((0<<COM3A1) | (1<<COM3A0));
		}
		
		else if( this->output == NON_INVERTING ){
			TCCR3A = TCCR3A | ((1<<COM3A1) | (0<<COM3A0));
		}
		
		else if( this->output == INVERTING ){
			TCCR3A = TCCR3A | ((1<<COM3A1) | (1<<COM3A0));
		}
	}
	
	else if( this->timerName == TIM3B ){
		if( this->output == DISCONNETED ){
			TCCR3A = TCCR3A | ((0<<COM3B1) | (0<<COM3B0));
		}
		
		else if( this->output == TOGGLE ){
			TCCR3A = TCCR3A | ((0<<COM3B1) | (1<<COM3B0));
		}
		
		else if( this->output == NON_INVERTING ){
			TCCR3A = TCCR3A | ((1<<COM3B1) | (0<<COM3B0));
		}
		
		else if( this->output == INVERTING ){
			TCCR3A = TCCR3A | ((1<<COM3B1) | (1<<COM3B0));
		}
	}
	
	else if( this->timerName == TIM3C ){
		if( this->output == DISCONNETED ){
			TCCR3A = TCCR3A | ((0<<COM3C1) | (0<<COM3C0));
		}
		
		else if( this->output == TOGGLE ){
			TCCR3A = TCCR3A | ((0<<COM3C1) | (1<<COM3C0));
		}
		
		else if( this->output == NON_INVERTING ){
			TCCR3A = TCCR3A | ((1<<COM3C1) | (0<<COM3C0));
		}
		
		else if( this->output == INVERTING ){
			TCCR3A = TCCR3A | ((1<<COM3C1) | (1<<COM3C0));
		}
	}
	
}

void TIMER::setPrescaler(){
	if( this->timerName == TIM0 ){
		if( this->prescaler == PRESCALER0 ){
			TCCR0 = TCCR0 | ( (0<<CS02) | (0<<CS01) | (0<<CS00) );
		}
		
		else if( this->prescaler == PRESCALER1 ){
			TCCR0 = TCCR0 | ( (0<<CS02) | (0<<CS01) | (1<<CS00) );
		}
		
		else if( this->prescaler == PRESCALER8 ){
			TCCR0 = TCCR0 | ( (0<<CS02) | (1<<CS01) | (0<<CS00) );
		}
		
		else if( this->prescaler == PRESCALER32 ){
			TCCR0 = TCCR0 | ( (0<<CS02) | (1<<CS01) | (1<<CS00) );
		}
		
		else if( this->prescaler == PRESCALER64 ){
			TCCR0 = TCCR0 | ( (1<<CS02) | (0<<CS01) | (0<<CS00) );
		}
		
		else if( this->prescaler == PRESCALER128 ){
			TCCR0 = TCCR0 | ( (1<<CS02) | (0<<CS01) | (1<<CS00) );
		}
		
		else if( this->prescaler == PRESCALER256 ){
			TCCR0 = TCCR0 | ( (1<<CS02) | (1<<CS01) | (0<<CS00) );
		}
		
		else if( this->prescaler == PRESCALER1024 ){
			TCCR0 = TCCR0 | ( (1<<CS02) | (1<<CS01) | (1<<CS00) );
		}
	}
	
	else if( this->timerName == TIM1A || this->timerName == TIM1B || this->timerName == TIM1C ){
		
		if( this->prescaler == PRESCALER0 ){
			TCCR1B = TCCR1B | ( (0<<CS12) | (0<<CS11) | (0<<CS10) );
		}
		
		else if( this->prescaler == PRESCALER1 ){
			TCCR1B = TCCR1B | ( (0<<CS12) | (0<<CS11) | (1<<CS10) );
		}
		
		else if( this->prescaler == PRESCALER8 ){
			TCCR1B = TCCR1B | ( (0<<CS12) | (1<<CS11) | (0<<CS10) );
		}
		
		else if( this->prescaler == PRESCALER256 ){
			TCCR1B = TCCR1B | ( (1<<CS12) | (0<<CS11) | (0<<CS10) );
		}
		
		else if( this->prescaler == PRESCALER1024 ){
			TCCR1B = TCCR1B | ( (1<<CS12) | (0<<CS11) | (1<<CS10) );
		}
	}
	
	else if( this->timerName == TIM2 ){
		if( this->prescaler == PRESCALER0 ){
			TCCR2 = TCCR2 | ( (0<<CS22) | (0<<CS21) | (0<<CS20) );
		}
		
		else if( this->prescaler == PRESCALER1 ){
			TCCR2 = TCCR2 | ( (0<<CS22) | (0<<CS21) | (1<<CS20) );
		}
		
		else if( this->prescaler == PRESCALER8 ){
			TCCR2 = TCCR2 | ( (0<<CS22) | (1<<CS21) | (0<<CS20) );
		}
		
		else if( this->prescaler == PRESCALER64 ){
			TCCR2 = TCCR2 | ( (0<<CS22) | (1<<CS21) | (1<<CS20) );
		}
		
		else if( this->prescaler == PRESCALER256 ){
			TCCR2 = TCCR2 | ( (1<<CS22) | (0<<CS21) | (0<<CS20) );
		}
		
		else if( this->prescaler == PRESCALER1024 ){
			TCCR2 = TCCR2 | ( (1<<CS22) | (0<<CS21) | (1<<CS20) );
		}
	}
	
	else if( this->timerName == TIM3A || this->timerName == TIM3B || this->timerName == TIM1C ){
		if( this->prescaler == PRESCALER0 ){
			TCCR3B = TCCR3B | ( (0<<CS32) | (0<<CS31) | (0<<CS30) );
		}
		
		else if( this->prescaler == PRESCALER1 ){
			TCCR3B = TCCR3B | ( (0<<CS32) | (0<<CS31) | (1<<CS30) );
		}
		
		else if( this->prescaler == PRESCALER8 ){
			TCCR3B = TCCR3B | ( (0<<CS32) | (1<<CS31) | (0<<CS30) );
		}
		
		else if( this->prescaler == PRESCALER256 ){
			TCCR3B = TCCR3B | ( (1<<CS32) | (0<<CS31) | (0<<CS30) );
		}
		
		else if( this->prescaler == PRESCALER1024 ){
			TCCR3B = TCCR3B | ( (1<<CS32) | (0<<CS31) | (1<<CS30) );
		}
	}
}

void TIMER::setGPIO(){
	
	if( this->waveForm != 0 ){
		if( this->timerName == TIM0 ){
			DDRB = DDRB | (1<<DDRB4);
		}
		
		else if( this->timerName == TIM1A ){
			DDRB = DDRB | (1<<DDRE5);
		}
		
		else if( this->timerName == TIM1B ){
			DDRB = DDRB | (1<<DDRB6);
		}
		
		else if( this->timerName == TIM1C ){
			DDRB = DDRB | (1<<DDRB7);
		}
		
		else if( this->timerName == TIM2 ){
			DDRB = DDRB | (1<<DDRB7);
		}
		
		else if( this->timerName == TIM3A ){
			DDRE = DDRE | (1<<DDRE3);
		}
		
		else if( this->timerName == TIM3B ){
			DDRE = DDRE | (1<<DDRE4);
		}
		
		else if( this->timerName == TIM3C ){
			DDRE = DDRE | (1<<DDRE5);
		}
	}
}

void TIMER::setPeriod(){
	if( this->timerName == TIM1A || this->timerName == TIM1B || this->timerName == TIM1C \
		|| this->timerName == TIM3A || this->timerName == TIM3B || this->timerName == TIM3C){
		ICR1 = 40000 - 1;
		this->period = 40000 - 1;
	}
	
	else if( this->timerName == TIM0 ){
		this->period = 256 - 1;
	}
}

void TIMER::setPeriod(uint32_t _period){
	if( this->timerName == TIM1A || this->timerName == TIM1B || this->timerName == TIM1C ){
		this->period = _period;
		ICR1 = _period;
	}
	
	else if( this->timerName == TIM0 ){
		this->period = _period;
	}
	
	else if( this->timerName == TIM2 ){
		this->period = _period;
	}
	
	else if( this->timerName == TIM3A || this->timerName == TIM3B || this->timerName == TIM3C){
		this->period = _period;
		ICR3 = _period;
	}
}

void TIMER::pwm(float _pwm){
	if( this->timerName == TIM0 ){
		OCR0 = this->period*_pwm/100.0;
	}
	
	else if( this->timerName == TIM1A ){
		OCR1A = this->period*(_pwm/100.0);
	}
	
	else if( this->timerName == TIM1B ){
		OCR1B = this->period*(_pwm/100.0);
	}
	
	else if( this->timerName == TIM1C ){
		OCR1C = this->period*(_pwm/100.0);
	}
	
	else if( this->timerName == TIM2 ){
		OCR2 = this->period*(_pwm/100.0);
	}
	
	else if( this->timerName == TIM3A ){
		OCR3A = this->period*(_pwm/100.0);
	}
	
	else if( this->timerName == TIM3B ){
		OCR3B = this->period*(_pwm/100.0);
	}
	
	else if( this->timerName == TIM3C ){
		OCR3C = this->period*(_pwm/100.0);
	}
}

void TIMER::servo(float _angle){

	if( this->timerName == TIM1A ){
		OCR1A = 1000.0 + 4000.0*(_angle/180.0);
	}
	
	else if( this->timerName == TIM1B){
		OCR1B = 1000.0 + 4000.0*(_angle/180.0);
	}
	
	else if( this->timerName == TIM1C ){
		OCR1C = 1000.0 + 4000.0*(_angle/180.0);
	}
	
	else if( this->timerName == TIM3A ){
		OCR3A = 1000.0 + 4000.0*(_angle/180.0);
	}
	
	else if( this->timerName == TIM3B ){
		OCR3B = 1000.0 + 4000.0*(_angle/180.0);
	}
	
	else if( this->timerName == TIM3C ){
		OCR3C = 1000.0 + 4000.0*(_angle/180.0);
	}
}