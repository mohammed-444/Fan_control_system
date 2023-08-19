#include "dc_motor.h"
#include "lm35_sensor.h"
#include "lcd.h"
#include "adc.h"


int main(int argc, char **argv) {
	/* Configuring the prescaler and the reference voltage*/
	ADC_ConfigType config={HALF_AVCC,DIVIDE_BY_8};
	uint8 temp;

	/*Initialize all used peripheral*/
	ADC_init(&config);
	LCD_init();
	DcMotor_Init();
	LCD_displayStringRowColumn(0,2,"FAN IS ");
	LCD_displayStringRowColumn(1,2,"TEMP =   C");

	while(1){
		temp=LM35_getTemperature();


		if(temp<30){
			LCD_displayStringRowColumn(0,9,"OFF   ");
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp);
			DcMotor_Rotate(stop,0);
			LCD_displayCharacter(' ');
		}
		else if(temp<60){
			LCD_displayStringRowColumn(0,9,"25% ON ");
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp);
			DcMotor_Rotate(clockwise,25);
			LCD_displayCharacter(' ');
		}
		else if(temp<90){
					LCD_displayStringRowColumn(0,9,"50% ON ");
					LCD_moveCursor(1,8);
					LCD_intgerToString(temp);
					DcMotor_Rotate(clockwise,50);
					LCD_displayCharacter(' ');
				}
		else if(temp<120){
					LCD_displayStringRowColumn(0,9,"75% ON ");
					LCD_moveCursor(1,8);
					LCD_intgerToString(temp);
					DcMotor_Rotate(clockwise,75);
					LCD_displayCharacter(' ');
				}
		else {
					LCD_displayStringRowColumn(0,9,"100% ON ");
					LCD_moveCursor(1,8);
					LCD_intgerToString(temp);
					DcMotor_Rotate(clockwise,100);

				}

	}
}
