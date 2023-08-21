 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                          type deceleration                                  *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,HALF_AVCC=3
}ADC_ReferenceVolatge;



typedef enum{
	DIVIDE_BY_2=1,DIVIDE_BY_4,DIVIDE_BY_8,DIVIDE_BY_16,DIVIDE_BY_32,DIVIDE_BY_64,DIVIDE_BY_128
}ADC_Prescaler;



typedef struct{
ADC_ReferenceVolatge ref_volt;
ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
