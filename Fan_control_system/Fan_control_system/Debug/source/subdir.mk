################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/adc.c \
../source/dc_motor.c \
../source/gpio.c \
../source/lcd.c \
../source/lm35_sensor.c \
../source/main.c \
../source/pwm.c 

OBJS += \
./source/adc.o \
./source/dc_motor.o \
./source/gpio.o \
./source/lcd.o \
./source/lm35_sensor.o \
./source/main.o \
./source/pwm.o 

C_DEPS += \
./source/adc.d \
./source/dc_motor.d \
./source/gpio.d \
./source/lcd.d \
./source/lm35_sensor.d \
./source/main.d \
./source/pwm.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


