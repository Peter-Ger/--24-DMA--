#ifndef __PWMDAC_H
#define __PWMDAC_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F7������
//PWM DAC��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/12/28
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

extern TIM_HandleTypeDef TIM15_Handler;         //��ʱ��15 PWM��� 

void TIM15_CH2_PWM_Init(u16 arr,u16 psc);	
void TIM_SetTIM15Compare2(u32 compare);
#endif
