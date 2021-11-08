/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the pulse width modulation(PWM) driver
 *
 * Author: Chady Achraf
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_

#include"std_types.h"
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Start the timer: Generate a PWM signal with frequency 500Hz
 * 500 = 1Mhz/(256*N)--> N = 8
 * Pre-scaler will be FCPU/8
 * Duty cycle value will be updated in the compare register
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
