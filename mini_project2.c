
 /******************************************************************************
 *
 * Module: function definition
 *
 * File Name: mini_project2.h
 *
 * Description: Macros and function used in project
 *
 * Author: Osama Sharabs
 *
 *******************************************************************************/
#include "mini_project2.h"
void PWM_Timer0_Init(uint8 set_duty_cycle)
{

	TCNT0 = 0; //Set Timer Initial value

	OCR0  = set_duty_cycle; // Set Compare Value

	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

ISR(INT1_vect)
{
	/*CHANGE STATE OF MOTOR */
	TOGGLE_BIT(PORTB,0);
    TOGGLE_BIT(PORTB,1);
}

/* External INT1 enable and configuration function */
void INT1_Init(void)
{
	SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD3));  // Configure INT1/PD3 as input pin

	GICR  |= (1<<INT1);    // Enable external interrupt pin INT1
	// Trigger INT1 with the RAISING edge
	MCUCR |= (1<<ISC11)|(1<<ISC10);

	SREG  |= (1<<7);       // Enable interrupts by setting I-bit
}
