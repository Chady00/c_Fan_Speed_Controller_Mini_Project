/*
 ============================================================================
 Name        : MiniProject3.c
 Author      : Chady Achraf
 Copyright   : Your copyright notice
 Description : Mini_Project_3
 ============================================================================
 */
#include"lcd.h"
#include"adc.h"
#include"motor.h"
#include"common_macros.h"

int main() {

	LCD_init();/*initializing the LCD driver*/
	DcMotor_Init();/*initializing the Motor driver*/
	/*
	 * set the ref voltage to internal 2.56
	 *set the ADC freq to Fcpu/8
	 */
	ADC_ConfigType type = { internal_2_56, ADC_8 };
	ADC_init(&type);/*initializing the ADC driver*/

	while (1) {
		int temp = LM35_getTemperature(); /*read the temperature from the sensor*/
		/*if temp <30 the fan is off,else the fan speed increases accordingly in CW motion*/
		if (temp < 30) {
			DcMotor_Rotate(STOP, 0);
		}
		if (temp >= 30 && temp < 60) {
			DcMotor_Rotate(CW, 25);
		}
		if (temp >= 60 && temp < 90) {
			DcMotor_Rotate(CW, 50);
		}
		if (temp >= 90 && temp < 120) {
			DcMotor_Rotate(CW, 75);
		}
		if (temp >= 120) {
			DcMotor_Rotate(CW, 100);
		}
		/*moving cursor position and displaying the fixed string on LCD*/
		LCD_moveCursor(0, 4);
		if (temp < 30) {

			LCD_displayString("FAN is OFF");
		} else {
			LCD_displayString("FAN is ON ");
		}
		LCD_moveCursor(1, 4);
		LCD_displayString("Temp = ");
		LCD_intgerToString(temp);
		/*Prevent LCD string overlapping (going higher-->lower)*/
		if (temp < 100) {
			LCD_displayString(" ");
		}
	}
	return 0;
}
