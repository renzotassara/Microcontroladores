################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Base_de_Datos.c \
../Core/Src/Funcion_Delay.c \
../Core/Src/Homing.c \
../Core/Src/Manejo_Interrupciones.c \
../Core/Src/Matriz.c \
../Core/Src/Movimiento_Motores.c \
../Core/Src/Movimiento_Servo.c \
../Core/Src/Texto.c \
../Core/Src/lcd.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/Base_de_Datos.o \
./Core/Src/Funcion_Delay.o \
./Core/Src/Homing.o \
./Core/Src/Manejo_Interrupciones.o \
./Core/Src/Matriz.o \
./Core/Src/Movimiento_Motores.o \
./Core/Src/Movimiento_Servo.o \
./Core/Src/Texto.o \
./Core/Src/lcd.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/Base_de_Datos.d \
./Core/Src/Funcion_Delay.d \
./Core/Src/Homing.d \
./Core/Src/Manejo_Interrupciones.d \
./Core/Src/Matriz.d \
./Core/Src/Movimiento_Motores.d \
./Core/Src/Movimiento_Servo.d \
./Core/Src/Texto.d \
./Core/Src/lcd.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Base_de_Datos.cyclo ./Core/Src/Base_de_Datos.d ./Core/Src/Base_de_Datos.o ./Core/Src/Base_de_Datos.su ./Core/Src/Funcion_Delay.cyclo ./Core/Src/Funcion_Delay.d ./Core/Src/Funcion_Delay.o ./Core/Src/Funcion_Delay.su ./Core/Src/Homing.cyclo ./Core/Src/Homing.d ./Core/Src/Homing.o ./Core/Src/Homing.su ./Core/Src/Manejo_Interrupciones.cyclo ./Core/Src/Manejo_Interrupciones.d ./Core/Src/Manejo_Interrupciones.o ./Core/Src/Manejo_Interrupciones.su ./Core/Src/Matriz.cyclo ./Core/Src/Matriz.d ./Core/Src/Matriz.o ./Core/Src/Matriz.su ./Core/Src/Movimiento_Motores.cyclo ./Core/Src/Movimiento_Motores.d ./Core/Src/Movimiento_Motores.o ./Core/Src/Movimiento_Motores.su ./Core/Src/Movimiento_Servo.cyclo ./Core/Src/Movimiento_Servo.d ./Core/Src/Movimiento_Servo.o ./Core/Src/Movimiento_Servo.su ./Core/Src/Texto.cyclo ./Core/Src/Texto.d ./Core/Src/Texto.o ./Core/Src/Texto.su ./Core/Src/lcd.cyclo ./Core/Src/lcd.d ./Core/Src/lcd.o ./Core/Src/lcd.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

