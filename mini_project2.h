 /******************************************************************************
 *
 * Module: Common - Macros-function
 *
 * File Name: Mini_H
 *
 * Description: Macros and function used in project
 *
 * Author: Osama Sharabs
 *
 *******************************************************************************/

#ifndef Mini_H
#define Mini_H

#include "adc.h"
#include "lcd.h"
#define POT PA0
#define EN1 PA3
#define IN1 PB0
#define IN2 PB1
void PWM_Timer0_Init(uint8 set_duty_cycle);
void INT1_Init(void);

#endif
