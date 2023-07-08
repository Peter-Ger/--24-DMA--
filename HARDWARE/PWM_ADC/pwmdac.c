#include "pwmdac.h"
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

TIM_HandleTypeDef TIM15_Handler;            //��ʱ��15 PWM��� 
TIM_OC_InitTypeDef TIM15_CH2Handler;	    //��ʱ��15ͨ��4���

//PWM DAC��ʼ��(Ҳ����TIM2ͨ��4��ʼ��)
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM15_CH2_PWM_Init(u16 arr,u16 psc)
{ 
    TIM15_Handler.Instance=TIM15;           //��ʱ��15
    TIM15_Handler.Init.Prescaler=psc;       //��ʱ����Ƶ
    TIM15_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//���ϼ���ģʽ
    TIM15_Handler.Init.Period=arr;          //�Զ���װ��ֵ
    TIM15_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
    HAL_TIM_PWM_Init(&TIM15_Handler);       //��ʼ��PWM
    
    TIM15_CH2Handler.OCMode=TIM_OCMODE_PWM1; //ģʽѡ��PWM1
    TIM15_CH2Handler.Pulse=arr/2;            //���ñȽ�ֵ,��ֵ����ȷ��ռ�ձȣ�
                                            //Ĭ�ϱȽ�ֵΪ�Զ���װ��ֵ��һ��,��ռ�ձ�Ϊ50%
    TIM15_CH2Handler.OCPolarity=TIM_OCPOLARITY_HIGH; //����Ƚϼ���Ϊ��
    HAL_TIM_PWM_ConfigChannel(&TIM15_Handler,&TIM15_CH2Handler,TIM_CHANNEL_2);//����TIM15ͨ��2
    HAL_TIM_PWM_Start(&TIM15_Handler,TIM_CHANNEL_2);//����PWMͨ��2
}

//��ʱ���ײ�������ʱ��ʹ�ܣ���������
//�˺����ᱻHAL_TIM_PWM_Init()����
//htim:��ʱ�����
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    GPIO_InitTypeDef GPIO_Initure;
	__HAL_RCC_TIM15_CLK_ENABLE();			//ʹ�ܶ�ʱ��15
    __HAL_RCC_GPIOA_CLK_ENABLE();			//����GPIOAʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_3;           	//PA3
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	//�����������
    GPIO_Initure.Pull=GPIO_PULLUP;          //����
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_VERY_HIGH;     //����
	GPIO_Initure.Alternate= GPIO_AF4_TIM15;	//PA3����ΪTIM15_CH2
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
}

//����TIMͨ��4��ռ�ձ�
//TIM_TypeDef:��ʱ��
//compare:�Ƚ�ֵ
void TIM_SetTIM15Compare2(u32 compare)
{
	TIM15->CCR2=compare;
}

