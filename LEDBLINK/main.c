#include "stm32f10x.h"
void config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef gpio;
	
	gpio.GPIO_Mode= GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_13;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&gpio);
	
	gpio.GPIO_Mode= GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_14;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&gpio);
	
	gpio.GPIO_Mode= GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_15;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&gpio);
}
void delay(unsigned int TIME)
{
	unsigned int i;
	for(i=0;i<TIME;i++)
	{
		__NOP();
	}
}
int main(void)
{
	config();
	while(1)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		delay(1000000);
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		delay(1000000);
		GPIO_SetBits(GPIOC,GPIO_Pin_14);
		delay(1000000);
		GPIO_ResetBits(GPIOC,GPIO_Pin_14);
		delay(1000000);
		GPIO_SetBits(GPIOC,GPIO_Pin_15);
		delay(1000000);
		GPIO_ResetBits(GPIOC,GPIO_Pin_15);
		delay(1000000);
	}
}
