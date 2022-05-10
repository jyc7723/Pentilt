#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/iom128a.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <math.h>

#define UART0 0
#define UART1 1

#define NO_PARITY 0
#define ODD_PARITY 2
#define EVEN_PARITY 3

int usartTxChar(char, FILE*);

class UART{
	private:
		uint8_t uartName;
		uint32_t buadRate;
		uint8_t size;
		uint8_t parity;
		uint8_t stop;
		
	public:
		UART(uint8_t _uartName, uint32_t _buadRate, uint8_t _size, uint8_t _parity , uint8_t _stop);
		UART();
		
		int data0[64] = {NULL,};		// 문자를 저장할 배열
		int outData[64] = {NULL,};		// 문자를 숫자로 저장할 배열 
		int idx = 0;					// 숫자 한 뭉치
		uint8_t len = 0;				// 들어온 데이터 길이
		uint8_t lngth = 0;				// asciiToint에서 사용할 데이터 길이
		bool complite = false;			// 데이터의 끝을 알리는 변수
		
		void init();
		void setBuadRate();
		void setSize();
		void setParity();
		void setStop();
		
		int* asciiToint();
		uint8_t available();
		int* getData();
		
	};

