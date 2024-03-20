#include "stm32f10x.h"
// Cau hinh LED
void configLED(void)
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
// Cau hinh time
void configTIME(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_TimeBaseInitTypeDef timerInit;
	
	timerInit.TIM_CounterMode=TIM_CounterMode_Up;
	timerInit.TIM_Period=100-1; //10KHz
	timerInit.TIM_Prescaler=72-1;
	TIM_TimeBaseInit(TIM2,&timerInit);
	TIM_Cmd(TIM2,ENABLE);
}
// Ham delay
void delay_ms(unsigned int ms)
{
	while(ms)
	{
		TIM_SetCounter(TIM2,0);
		while(TIM_GetCounter(TIM2)<1000)
		{
		}
		ms--;
	}
}
void confifuart(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	USART_InitTypeDef uartInit;
	uartInit.USART_BaudRate=9600;
	uartInit.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	uartInit.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	uartInit.USART_Parity=USART_Parity_No;
	uartInit.USART_StopBits=USART_StopBits_1;
	uartInit.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART3,&uartInit);
	USART_Cmd(USART3,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef gpio;
	/*TX PB10*/
	gpio.GPIO_Mode= GPIO_Mode_AF_PP;
	gpio.GPIO_Pin=GPIO_Pin_10;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&gpio);
	/*RX PB11*/
	gpio.GPIO_Mode= GPIO_Mode_IN_FLOATING;
	gpio.GPIO_Pin=GPIO_Pin_11;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&gpio);
}
int main(void)
{
	configLED();
	configTIME();
	while(1)
	{
		
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		delay_ms(1000);
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		//GPIO_SetBits(GPIOC,GPIO_Pin_14);
		//delay_ms(1000);
		//GPIO_ResetBits(GPIOC,GPIO_Pin_14);
		//GPIO_SetBits(GPIOC,GPIO_Pin_15);
		//delay_ms(1000);
		//GPIO_ResetBits(GPIOC,GPIO_Pin_15);
	}
	/*
	confifuart();
	USART_SendData(USART3,0x19);
	while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)==RESET	)
	{
	}
	*/
}
