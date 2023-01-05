################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/portable/MemMang/heap_1.c 

OBJS += \
./Source/portable/MemMang/heap_1.o 

C_DEPS += \
./Source/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
Source/portable/MemMang/%.o: ../Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\College\2023\4th Year\1st\Embedded\Workspace\test_rtos\Source\portable\GCC\ATMega323" -I"E:\College\2023\4th Year\1st\Embedded\Workspace\test_rtos\Source\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


