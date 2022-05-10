#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/iom128a.h>
#include <avr/interrupt.h>

#define TIM0 0
#define TIM1A 1
#define TIM1B 2
#define TIM1C 3
#define TIM2 4
#define TIM3A 5
#define TIM3B 6
#define TIM3C 7

#define NORMAL 0
#define PHASE_CORRECT 1
#define CTC 2
#define FAST_PWM 3

#define DISCONNETED 0
#define TOGGLE 1
#define NON_INVERTING 2
#define INVERTING 3

#define PRESCALER0 0
#define PRESCALER1 1
#define PRESCALER8 8
#define PRESCALER32 32
#define PRESCALER64 64
#define PRESCALER128 128
#define PRESCALER256 256
#define PRESCALER1024 1024




class TIMER{
	private:
		uint8_t timerName;
		uint8_t waveForm;
		uint8_t output;
		uint32_t prescaler;
		uint32_t period;
			
	public:
	
	TIMER(uint8_t _timerName, uint8_t _waveForm, uint8_t _output, uint32_t _prescaler);
	TIMER(uint8_t _timerName);
	
	void init();
	void setWaveForm();
	void setOutput();
	void setPrescaler();
	void setGPIO();
	void setPeriod();
	void setPeriod(uint32_t _period);
	void pwm(float _pwm);
	void servo(float _angle);
	
	};