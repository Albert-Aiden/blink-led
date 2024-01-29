#include "stm32f4xx_hal.h"

void Delay_ms(uint16_t time)
{
	uint32_t time_n = time * 12000;
	    while (time_n != 0){ time_n--;}
}


int main(void)
{
	RCC->AHB1ENR |=1;
	RCC->AHB1ENR |=0x040;
	GPIOG->MODER |= 0x010000000;
	while(1)
	{
		if(GPIOA->IDR&1)
			GPIOG->BSRR = 0x40000000;
		else GPIOG->BSRR = 0x4000;
	}
}
