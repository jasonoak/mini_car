#ifndef  _CONTROL_H
#define  _CONTROL_H

#include "sys.h" 
void moto_init(void);
void Delay(u32 count);
void left_go(void);
void right_go(void);
void left_back(void);//IN1->1;IN2->0
void right_back(void);//IN4->1;IN3->0

#endif
