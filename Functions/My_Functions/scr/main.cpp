#include "main.h"

UART uart1;
TIMER myServo1(TIM1A);
TIMER myServo2(TIM1B);
GPIO LED(LED_PORT,LED_pin,OUTPUT);

int *data;



int main(void)
{
	printf("SYSTEM OPERATE SETUP..\n");	
    while (1) 
    {
		if(uart1.available()){
			data = uart1.asciiToint();
			myServo1.servo(data[0]);
			myServo2.servo(data[1]);
		}
		
		
		
	}
}



