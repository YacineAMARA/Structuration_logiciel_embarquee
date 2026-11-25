#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "util.h"

#include "One_Wire.h"

ONEWIRE_PINOUT slave = {
		.port = GPIOC,
		.pin = 10
};

uint8_t slave_present = 0 ;

int main(void)
{
	FPU_Init();
	GPIO_Init();
	USART2_Init();
	SYSTICK_Init();
	TIM2_Init();

	while(1){
		//SYSTICK_Delay(100);
		GPIOA->ODR ^= 1<<5;
		//printf("Hello\r\n");



		if((GPIOC->IDR & 1<<13) != (1<<13)) //BP B1 enfoncer
		{
			printf("t'es la ?\r\n");

			slave_present = ONEWIRE_Reset(&slave);

			if (slave_present)
			{
				printf("je suis vivant !\r\n");
			}
			else
			{
				printf("dead !\r\n");
			}

		}

	}
}
