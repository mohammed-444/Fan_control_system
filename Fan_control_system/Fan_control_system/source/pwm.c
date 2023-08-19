#include "pwm.h"
#include "avr/io.h"

void PWM_Timer0_Start(uint8 duty_cycle){
	/*
	 * FOC0=0 PWM MODE
	 * WGM00 & WGM01 =1 FAST PWM
	 * COM01 =1 NON INVERTING MODE
	 * CS01=1 PRESCALER 8
	 * */
	TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);
	OCR0=255*duty_cycle/100;

}
