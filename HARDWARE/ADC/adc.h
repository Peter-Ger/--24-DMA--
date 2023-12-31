#ifndef __ADC_H
#define __ADC_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32H7开发板
//ADC驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2017/8/13
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

extern ADC_HandleTypeDef ADC1_Handler;//ADC句柄

void MY_ADC1_Init(void); 				//ADC通道初始化
void MY_ADC3_Init(void);
u16 Get_Adc(ADC_HandleTypeDef ADCx,u32 ch);	//获得某个通道值 
u16 Get_Adc_Average(ADC_HandleTypeDef ADCx,u32 ch,u8 times);//得到某个通道给定次数采样的平均值
short Get_Temprate(void);
#endif 
