#include "stm32f10x.h"
#include "control.h"
#include "pwm.h"
#include "delay.h"
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 GPIO_SetBits(GPIOB,GPIO_Pin_5);						 //PB.5 �����

}
 int main(void)
 {	
	 u16 led0pwmval=100;
	 u8 dir=1;	
	delay_init();
  moto_init();
 	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	 LED_Init();	
 	TIM3_PWM_Init(899,0);	 //����Ƶ��PWMƵ��=72000000/900=80Khz
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
