#include <avr/io.h>
#include <avr/iom128a.h>

#define HIGH 1
#define LOW 0

#define INPUT 0
#define OUTPUT 1

#define PA 0
#define PB 1
#define PC 2
#define PD 3
#define PE 4
#define PF 5
#define PG 6


class GPIO
{
	private:
		uint8_t portName;
		uint8_t pinName;
		uint8_t current_Status;
		uint8_t mode;
		
	public:
		GPIO(uint8_t _portName, uint8_t _pinName, uint8_t _mode){
			this->portName = _portName;
			this->pinName = _pinName;
			this->mode = _mode;
			this->pinMode(this->portName, this->pinName, _mode);
		}
		
		void pinMode(uint8_t _portName, uint8_t _pinName, uint8_t _mode);
		void writePin(uint8_t _state);
		int readPin();
		void on();
		void off();
		void toggle();
};
