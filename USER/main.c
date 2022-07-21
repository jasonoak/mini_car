#include "stm32f10x.h"
#include "control.h"
#include "pwm.h"
#include "delay.h"
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOB,GPIO_Pin_5);						 //PB.5 输出高

}
 int main(void)
 {	
	 u16 led0pwmval=100;
	 u8 dir=1;	
	delay_init();
  moto_init();
 	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	 LED_Init();	
 	TIM3_PWM_Init(899,0);	 //不分频。PWM频率=72000000/900=80Khz
  while(1)
	{
	  left_go();
	 	right_go();
	//left_back();
	//right_back();
		
				delay_ms(10);							 
			TIM_SetCompare2(TIM3,400);	
			delay_ms(10);	
			TIM_SetCompare3(TIM3,400);	
	}
 }
