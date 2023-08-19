#include "gpio.h"
#include "dc_motor.h"
#include "pwm.h"


/* this function set pin direction*/
void DcMotor_Init(void){
GPIO_setupPinDirection(MOTOR_PORT, MOTOR_PIN1,PIN_OUTPUT);
GPIO_setupPinDirection(MOTOR_PORT, MOTOR_PIN2,PIN_OUTPUT);
GPIO_setupPinDirection(MOTOR_PORT, MOTOR_ENABLE_PIN,PIN_OUTPUT);
}

/* this function write the value of the pin*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	GPIO_writePin(MOTOR_PORT, MOTOR_PIN1,(state)&1);
	GPIO_writePin(MOTOR_PORT, MOTOR_PIN2,(state)&(1<<1));

	PWM_Timer0_Start(speed);

}
