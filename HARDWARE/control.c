#include "control.h"
void moto_init()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	    //使能PC端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			    //LED0-->PC.8 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     //初始化GPIOC.8
  GPIO_SetBits(GPIOC,GPIO_Pin_8);					//PC.8 输出高
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	    //使能PC端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			    //LED0-->PC.9 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     //初始化GPIOC.9
  GPIO_SetBits(GPIOC,GPIO_Pin_9);					//PBC.9 输出高
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	    //使能PB端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;			    //LED0-->PB.9 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     //初始化GPIOB.9
  GPIO_SetBits(GPIOC,GPIO_Pin_10);					//PB.9 输出高
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	    //使能PB端口时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;			    //LED0-->PB.9 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);			     //初始化GPIOB.9
  GPIO_SetBits(GPIOC,GPIO_Pin_11);					//PB.9 输出高
	
	
}
 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }
void left_go()//IN1->0;IN2->1
{
	  GPIO_ResetBits(GPIOC,GPIO_Pin_8);					//PC.8 输出0
	  GPIO_SetBits(GPIOC,GPIO_Pin_9);					//PC.9 输出1
}
void right_go()//IN4->0;IN3->1
{
	    GPIO_ResetBits(GPIOC,GPIO_Pin_11);        //PC.11 输出0
			GPIO_SetBits(GPIOC,GPIO_Pin_10);					//PC.10 输出1
}
void left_back()//IN1->1;IN2->0
{
	  GPIO_ResetBits(GPIOC,GPIO_Pin_9);					//PC.9 输出0
	  GPIO_SetBits(GPIOC,GPIO_Pin_8);					//PC.8 输出1
}
void right_back()//IN4->1;IN3->0
{
	    GPIO_ResetBits(GPIOC,GPIO_Pin_10);        //PC.10 输出0
			GPIO_SetBits(GPIOC,GPIO_Pin_11);					//PC.11 输出1
}


