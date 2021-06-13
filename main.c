
 /******************************************************************************
 *
 * Module: main project file
 *
 * File Name: main.c
 *
 * Description:  Control the motor speed through the potentiometer.
 * The potentiometer is connected through the ADC driver and motor speed is controlled
 * though the PWM sign Also activate INT1 with raising it should revert
 * the motor direction whatever the speed of the motor.
 *
 * Author: Osama Sharabas
 *
 *******************************************************************************/
#include "mini_project2.h"


int main(void)
{

   /* clear POT AS INPUT PIN*/
	CLEAR_BIT(DDRA,POT);
   /* SET IN1 AS OUTPUT PIN */
	SET_BIT(DDRB,IN1);
	/* SET IN2 AS OUTPUT PIN */
	SET_BIT(DDRB,IN2);
	/* 16 bit VARIABLE WHERE I SAVE THE OUTPUT OF ADC 10 bit 0--->1024 */
    uint16 set_duty_cycle;
    /* 8 bit variable where i save the 16 bit set_duty_cycle as 8 bit 0--->256*/
    uint8 duty_cycle_8bit;

	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */
	INT1_Init(); /* initialize INT1*/
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("PWM Value = ");
	/*Rotate the motor --> clock wise*/
	 CLEAR_BIT(PORTB,1);
     SET_BIT(PORTB,0);


	while(1)
	{
        /* ADC read the analog signal POT 0V-->5V AND TRANSFER IT TO DIGITAL VALUE 0-->1023*/
		set_duty_cycle=ADC_readChannel(POT);
		/*  TRANSFER DIGITALE adc output value 0-->1023 to 0-->255*/
		duty_cycle_8bit=set_duty_cycle/4;
		/* send duty_cycle to PWM TO SET MOTOR VALUE EN1*/
		PWM_Timer0_Init(duty_cycle_8bit);

        /* SET CURSER POSITION WHERE I DISPLAY */
		LCD_goToRowColumn(0,12);
		/* DISPLAY DUTY_CYCLE VALUE ON LCD*/
		LCD_intgerToString(duty_cycle_8bit);
	}
}
