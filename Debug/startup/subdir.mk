################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"/Users/florianuhlemann/eclipseWorkspace/mikromedia/inc" -I"/Users/florianuhlemann/eclipseWorkspace/mikromedia/CMSIS/core" -I"/Users/florianuhlemann/eclipseWorkspace/mikromedia/CMSIS/device" -I"/Users/florianuhlemann/eclipseWorkspace/mikromedia/StdPeriph_Driver/inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


