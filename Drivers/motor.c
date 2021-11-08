/******************************************************************************
 *
 * Module: MOTOR
 *
 * File Name: motor.c
 *
 * Description: Source file for the motor driver
 *
 * Author: Chady Achraf
 *
 *******************************************************************************/
#include"pwm.h"
#include"motor.h"
#include"gpio.h"
#include "avr/io.h" /* To use the IO Ports Registers */
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Initialize the motor.
 * 1. Setup the motor pins Direction as output pins.
 * 2. Set the motor initial state to Stopped
 */
void DcMotor_Init(void) {
	/*setting PinB0 and PinB1 as output pins--> input to the H-Bridge*/
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	/* Motor is Stopped at the beginning */
	PORTB &= ~(1 << PIN0_ID) & ~(1 << PIN1_ID);
}
/*
 * Description :
 * Rotate the motor: CW / A-CW / STOP
 * 1. Rotate the motor according to the motor state
 * 2. Send the speed to the PWM driver to control it
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	/*Set the current motor state*/
	if (state == STOP) {
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	}
	if (state == CW) {
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
	}
	if(state == ACW){
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	}
	/*Send the required speed of the motor*/
// pass the motor speed as percentage to the PWM function
	speed = (uint8)(speed*255/100);
	PWM_Timer0_Start(speed);

}
