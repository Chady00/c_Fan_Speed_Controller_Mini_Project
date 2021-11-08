/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the pulse width modulation (PWM) driver
 *
 * Author: Chady Achraf
 *
 *******************************************************************************/
#include"pwm.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "common_macros.h"
#include <avr/io.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Start the timer: Generate a PWM signal with frequency 500Hz
 * 500 = 1Mhz/(256*N)--> N = 8
 * Pre-scaler will be FCPU/8
 * Duty cycle value will be updated in the compare register
 */
void PWM_Timer0_Start(uint8 duty_cycle){
	{
		TCNT0 = 0; // Set Timer Initial Value to 0

		OCR0  = duty_cycle; // Set Compare Value

		DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

		/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
		 */
		TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	}

}

