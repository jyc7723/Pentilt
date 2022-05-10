#include "UART.h"

FILE* fpStdio = fdevopen(usartTxChar, NULL);

extern UART uart1;


UART::UART(uint8_t _uartName, uint32_t _buadRate, uint8_t _size, uint8_t _parity , uint8_t _stop){
	this->uartName = _uartName;
	this->buadRate = _buadRate;
	this->size = _size;
	this->parity = _parity;
	this->stop = _stop;

	this->init();
}

UART::UART(){
	this->uartName = UART0;
	this->buadRate = 9600;
	this->size = 8;
	this->parity = NO_PARITY;
	this->stop = 1;

	this->init();
}

void UART::init(){
	cli();
	if( this->uartName == UART0 ){
		UCSR0B = UCSR0B | ((1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0));
		DDRE = DDRE | ( 1<<DDRE1 );
	}
	
	else if( this->uartName == UART1 ){
		UCSR1B = UCSR1B | ((1<<RXCIE1) | (1<<RXEN1) | (1<<TXEN1));
		DDRD = DDRD | (1<<DDRD3);
	}
	this->setBuadRate();
	this->setSize();
	this->setParity();
	this->setStop();
	sei();
}

void UART::setBuadRate(){
	if( this->uartName == UART0 ){
		if( this->buadRate == 9600 ){
			UBRR0L = 103;
		}
		
		else if( this->buadRate == 19200){
			UBRR0L = 51;
		}
		
		else if( this->buadRate == 38400 ){
			UBRR0L = 25;
		}
		
		else if( this->buadRate == 57600 ){
			UBRR0L = 16;
		}
		
		else if( this->buadRate == 115200 ){
			UBRR0L = 8;
		}
	}
	
	else if( this->uartName == UART1 ){
		if( this->buadRate == 9600 ){
			UBRR1L = 103;
		}
		
		else if( this->buadRate == 19200){
			UBRR1L = 51;
		}
		
		else if( this->buadRate == 38400 ){
			UBRR1L = 25;
		}
		
		else if( this->buadRate == 57600 ){
			UBRR1L = 16;
		}
		
		else if( this->buadRate == 115200 ){
			UBRR1L = 8;
		}
	}
}

void UART::setSize(){
	if( this->uartName == UART0 ){
		UCSR0B = UCSR0B | (0<<UCSZ02);
		UCSR0C = UCSR0C |( (1<<UCSZ01) | (1<<UCSZ00) );
	}
	
	else if( this->uartName == UART1 ){
		UCSR1B = UCSR1B | (0<<UCSZ12);
		UCSR1C = UCSR1C |( (1<<UCSZ11) | (1<<UCSZ10) );
	}
}

void UART::setParity(){
	if( this->uartName == UART0 ){
		if( this->parity == NO_PARITY ){
			UCSR0C = UCSR0C | (this->parity<<UPM00);
		}
		
		else if( this->parity == EVEN_PARITY ){
			UCSR0C = UCSR0C | (this->parity<<UPM00);
		}
		
		else if( this->parity == ODD_PARITY ){
			UCSR0C = UCSR0C | (this->parity<<UPM00);
		}
	}
	
	else if( this->uartName == UART0 ){
		if( this->parity == NO_PARITY ){
			UCSR1C = UCSR1C | (this->parity<<UPM10);
		}
		
		else if( this->parity == EVEN_PARITY ){
			UCSR1C = UCSR1C | (this->parity<<UPM10);
		}
		
		else if( this->parity == ODD_PARITY ){
			UCSR1C = UCSR1C | (this->parity<<UPM10);
		}
	}
}

void UART::setStop(){
	if( this->uartName == UART0 ){
		if( this->stop == 1 ){
			UCSR0C = UCSR0C | (0<<USBS0);
		}
		
		else if( this->stop == 2){
			UCSR0C = UCSR0C | (1<<USBS0);
		}
	}
	
	else if( this->uartName == UART1 ){
		if( this->stop == 1 ){
			UCSR1C = UCSR1C | (0<<USBS1);
		}
		
		else if( this->stop == 2 ){
			UCSR1C = UCSR1C | (1<<USBS1);
		}
	}
}


uint8_t UART::available(){
	/*
	*	데이터가 있는지 없는지 판단하는 함수
	*	데이터가 있으면 1 반환 없으면 0
	*/
	
	if(this->len != 0){
		return 1;
	}
	else if(this->len == 0){
		return 0;
	}
}

int* UART::getData(){
	/*################################################################################################################
	*	문자열 데이터를 그대로 반환하는 함수
	*	알고리즘
	*	1.	데이터가 다 들어왔으면 -> 작업 시작
	*	2.		들어온 데이터 길이부터 배열의 끝가지 반복
	*	3.			새로 들어온 데이터만 냅두고 뒤에 오래된 데이터는 Null로 초기화  [ new new old old old ] old만 Null이됨
	*	3.	새로 들어온 데이터를 위해 길이를 초기화, 완료 변수도 초기화
	*	4.	저장한 new 데이터 배열을 반환
	##################################################################################################################*/
	
	if(this->complite){
		
		for(int i = this->len;i<63;i++){
			this->data0[i] = NULL;
		}
		this->len = 0;
		this->complite = false;
		
		return uart1.data0; 
	}
}

int* UART::asciiToint(){
	/* ##############################################################################################################
	*	문자를 숫자로 바꾸고 자릿수도 계산해 높은 숫자를 만드는 함수
	*	cntNut    숫자의 자릿수    [ 5334 ] -> 4
	*	idx    숫자들 개수    [ 12 1332 1247 7 ] -> 4
	*	num    문자를 숫자로 바꺼 저장할 변수
	*	
	*	알고리즘
	*	1.	문자 배열 개수 만큼 반복
	*	2.		자릿수 증가, 저장할 변수 초기화
	*	3.		1에서 반복하면서 찾은 문자가 공백이거나 줄바꿈이면 -> 증가된 자릿수 만큼 숫자라 봄
	*	4.			공백이나 줄바꿈은 계산에서 제외 시키위해 자릿수를 하나 뺌
	*	5.			숫자 자릿수 만큼 반복 
	*	6.			탐색한 숫자가 아스키 코드로 숫자면 -> 계산을 시작함
	*	7.				숫자를 각 자릿수만큼 제곱을하고 더해서 숫자를 완성함
	*	8.		자릿수 초기화, 출력할 배열에 완성된 숫자 저장하고 인덱스를 증가
	*	9.	출력할 배열에 새로 들어온 값 뒤에 것들은 초기화   [ new new new old old old old old ]에서  old는 Null로 바뀜
	*	10. 새로 들어올 데이터를 위해 데이터 길이 변수 초기화, 작업이 끝났으니 완료 변수도 초기화
	*
	################################################################################################################*/
	
	if(this->complite){
		int cntNum = 0;			// 구분된 숫자의 자릿 수
		this->idx = 0;			// 나누어진 숫자 덩어리 개수
		int num = 0;			// 문자를 숫자로 바꺼서 저장할 변수
		
		for(int i = 0; i < uart1.lngth; i++){
			cntNum++;
			num = 0;
			
			if( this->data0[i] == 0x20  || this->data0[i] == 0x0a){
				cntNum = cntNum -1;
				for( int j = 0 ; j<cntNum; j++){
					if( this->data0[i-cntNum + j] >=48 && this->data0[i-cntNum + j]<=57){
						num = num + ( this->data0[i-cntNum + j] - 48 ) * (int)round( pow(10.0,cntNum -  ( j % cntNum ) - 1));
					}
				}
				cntNum = 0;
				outData[this->idx++] = num;
			}
		}
		
		for(int i = idx; i<64;i++){
			this->outData[i] = NULL;
		}
		
		this->len = 0;
		this->complite = false;
		return this->outData;
	}
}

int usartTxChar(char ch, FILE *fp) {
	while (!(UCSR0A & (1 << UDRE0)));

	UDR0 = ch;
	return 0;
}


uint8_t index = 0;
ISR(USART0_RX_vect){
	/*############################################################
	*	데이터 한줄을 알아내는 함수
	*	알고리즘
	*	1.	들어오는 데이터를 모두 배열에 저장
	*	2.	지금 들어온 데이터가 줄바꿈이면 -> 데이터 한줄이 끝났다 판단
	*	3.		들어온 데이터의 길이를 저장
	*	4.		증가시킨 인덱스 초기화
	*	5.		데이터가 다 들어왔다는 뜻으로 완료 변수 설정
	############################################################*/
	while (!(UCSR0A & (1 << UDRE0)));
	uart1.data0[index++] = UDR0;
	if(uart1.data0[index-1] == 0x0a){
		uart1.len = index;
		uart1.lngth = index ;
		index = 0;
		uart1.complite = true;
	}
}







