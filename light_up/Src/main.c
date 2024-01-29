   /*========================================================================
*                        INCLUDE FILES
==========================================================================*/
#include<stdio.h>
#include<stdint.h>

/*========================================================================
*                        DETINITISION
==========================================================================*/

#define RRC_ADDRESS								0x40023800


#define PORTA_ADDRESS							0x40020000
#define PORTB_ADDRESS							0x40020400
#define PORTC_ADDRESS							0x40020800
#define PORTD_ADDRESS							0x40020C00
#define PORTE_ADDRESS							0x40021000
#define PORTF_ADDRESS							0x40021400
#define PORTG_ADDRESS							0x40021800
#define PORTH_ADDRESS							0x40021C00
#define PORTI_ADDRESS							0x40022000
#define PORTJ_ADDRESS							0x40022400
#define PORTK_ADDRESS							0x40022800

/*========================================================================
*                        LOCAL FUNSION PROTOTYPES
==========================================================================*/

void Delay_ms(uint16_t time);
void GPIO_Configuration();

/*========================================================================
*                        LOCAL TYPEDEFS (STRUCTURE, UNIONS, ENUMS)
==========================================================================*/
/* creat a struct for RRC register */

struct My_RRC_Type
{
	uint32_t My_RC;
	uint32_t My_PLLCFGR;
	uint32_t My_CFGR;
	uint32_t My_CIR;
	uint32_t My_AHB1RSTR;
	uint32_t My_AHB2RSTR;
	uint32_t My_AHB3RSTR;
	uint32_t A;						//0x1C
	uint32_t My_APB1RSTR;
	uint32_t My_APB2RSTR;
	uint32_t B;						//0x28
	uint32_t C;						//0x2C
	uint32_t My_AHB1ENR;
	uint32_t My_AHB2ENR;
	uint32_t My_AHB3ENR;
	uint32_t D;						//0x3C
	uint32_t My_APB1ENR;
	uint32_t My_APB2ENR;
	uint32_t E;						//0x44
	uint32_t F;						//0x48
	uint32_t My_AHB1LPENR;
	uint32_t My_AHB2LPENR;
	uint32_t My_AHB3LPENR;
	uint32_t G;						//0x50
	uint32_t My_APB1LPENR;
	uint32_t My_APB2LPENR;
	uint32_t H;						//0x5C
	uint32_t I;						//0x60
	uint32_t My_BDCR;
	uint32_t My_CSR;
	uint32_t K;						//0x6C
	uint32_t L;						//0x70
	uint32_t My_SSCGR;
	uint32_t My_PLLI2SCFGR;

};

/* creat a struct for GPIO register */

struct My_GPIO_Type
{
	uint32_t My_MODER;
	uint32_t My_OTYPER;
	uint32_t My_OSPEEDR;
	uint32_t My_PUPDR;
	uint32_t My_IDR;
	uint32_t My_ODR;
	uint32_t My_BSRR;
	uint32_t My_LCKR;
	uint32_t My_AFRL;
	uint32_t My_AFRH;

};

/*========================================================================
*                        LOCAL VARIABLES
==========================================================================*/

struct My_RRC_Type * My_RRC = (struct My_RRC_Type *)RRC_ADDRESS;
struct My_GPIO_Type * PORTG = (struct My_GPIO_Type *)PORTG_ADDRESS;
struct My_GPIO_Type * PORTA = (struct My_GPIO_Type *)PORTA_ADDRESS;

/*========================================================================
*                        LOCAL FUNCTIONS
==========================================================================*/

void GPIO_Configuration(void)
{
//My_RRC->My_AHB1ENR |= 0x01;  // open clock GPIOA
My_RRC->My_AHB1ENR |= 0x040; // OPEN CLOCK GPIOG
PORTG->My_MODER |= 0x04000000; // OPEN PIN 13 GPIO G


};
void Delay_ms(uint16_t time)
{
	uint32_t time_n = time*1200;
	    while (time_n != 0){ time_n--;}
}

/*========================================================================
*                        GLOBAL FUNCTIONS
==========================================================================*/
int main(void)
{
	GPIO_Configuration();

	while(1)
	{
		PORTG->My_BSRR = 0x2000;  // bat den
		Delay_ms(1000);
		PORTG->My_BSRR = 0X20000000; //tat den
		Delay_ms(1000);
	}
}

