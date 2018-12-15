################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/devices/Chair.cpp \
../Source/devices/Column.cpp 

OBJS += \
./Source/devices/Chair.o \
./Source/devices/Column.o 

CPP_DEPS += \
./Source/devices/Chair.d \
./Source/devices/Column.d 


# Each subdirectory must supply rules for building sources it contributes
Source/devices/%.o: ../Source/devices/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -I/home/programmer/jsonLib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


