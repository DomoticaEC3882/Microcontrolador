################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ADC.c" \
"../Generated_Code/AS1.c" \
"../Generated_Code/Cap1.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/Hall.c" \
"../Generated_Code/IO_Map.c" \
"../Generated_Code/Iluminacion.c" \
"../Generated_Code/PE_Timer.c" \
"../Generated_Code/PWM1.c" \
"../Generated_Code/TI1.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/Ventilacion.c" \

C_SRCS += \
../Generated_Code/ADC.c \
../Generated_Code/AS1.c \
../Generated_Code/Cap1.c \
../Generated_Code/Cpu.c \
../Generated_Code/Hall.c \
../Generated_Code/IO_Map.c \
../Generated_Code/Iluminacion.c \
../Generated_Code/PE_Timer.c \
../Generated_Code/PWM1.c \
../Generated_Code/TI1.c \
../Generated_Code/Vectors.c \
../Generated_Code/Ventilacion.c \

OBJS += \
./Generated_Code/ADC_c.obj \
./Generated_Code/AS1_c.obj \
./Generated_Code/Cap1_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/Hall_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/Iluminacion_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/PWM1_c.obj \
./Generated_Code/TI1_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/Ventilacion_c.obj \

OBJS_QUOTED += \
"./Generated_Code/ADC_c.obj" \
"./Generated_Code/AS1_c.obj" \
"./Generated_Code/Cap1_c.obj" \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/Hall_c.obj" \
"./Generated_Code/IO_Map_c.obj" \
"./Generated_Code/Iluminacion_c.obj" \
"./Generated_Code/PE_Timer_c.obj" \
"./Generated_Code/PWM1_c.obj" \
"./Generated_Code/TI1_c.obj" \
"./Generated_Code/Vectors_c.obj" \
"./Generated_Code/Ventilacion_c.obj" \

C_DEPS += \
./Generated_Code/ADC_c.d \
./Generated_Code/AS1_c.d \
./Generated_Code/Cap1_c.d \
./Generated_Code/Cpu_c.d \
./Generated_Code/Hall_c.d \
./Generated_Code/IO_Map_c.d \
./Generated_Code/Iluminacion_c.d \
./Generated_Code/PE_Timer_c.d \
./Generated_Code/PWM1_c.d \
./Generated_Code/TI1_c.d \
./Generated_Code/Vectors_c.d \
./Generated_Code/Ventilacion_c.d \

C_DEPS_QUOTED += \
"./Generated_Code/ADC_c.d" \
"./Generated_Code/AS1_c.d" \
"./Generated_Code/Cap1_c.d" \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/Hall_c.d" \
"./Generated_Code/IO_Map_c.d" \
"./Generated_Code/Iluminacion_c.d" \
"./Generated_Code/PE_Timer_c.d" \
"./Generated_Code/PWM1_c.d" \
"./Generated_Code/TI1_c.d" \
"./Generated_Code/Vectors_c.d" \
"./Generated_Code/Ventilacion_c.d" \

OBJS_OS_FORMAT += \
./Generated_Code/ADC_c.obj \
./Generated_Code/AS1_c.obj \
./Generated_Code/Cap1_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/Hall_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/Iluminacion_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/PWM1_c.obj \
./Generated_Code/TI1_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/Ventilacion_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ADC_c.obj: ../Generated_Code/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/ADC.args" -ObjN="Generated_Code/ADC_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/AS1_c.obj: ../Generated_Code/AS1.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/AS1.args" -ObjN="Generated_Code/AS1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cap1_c.obj: ../Generated_Code/Cap1.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Cap1.args" -ObjN="Generated_Code/Cap1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Cpu.args" -ObjN="Generated_Code/Cpu_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Hall_c.obj: ../Generated_Code/Hall.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Hall.args" -ObjN="Generated_Code/Hall_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IO_Map_c.obj: ../Generated_Code/IO_Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/IO_Map.args" -ObjN="Generated_Code/IO_Map_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Iluminacion_c.obj: ../Generated_Code/Iluminacion.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Iluminacion.args" -ObjN="Generated_Code/Iluminacion_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_Timer_c.obj: ../Generated_Code/PE_Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/PE_Timer.args" -ObjN="Generated_Code/PE_Timer_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PWM1_c.obj: ../Generated_Code/PWM1.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/PWM1.args" -ObjN="Generated_Code/PWM1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TI1_c.obj: ../Generated_Code/TI1.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/TI1.args" -ObjN="Generated_Code/TI1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Vectors.args" -ObjN="Generated_Code/Vectors_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Ventilacion_c.obj: ../Generated_Code/Ventilacion.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Ventilacion.args" -ObjN="Generated_Code/Ventilacion_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


