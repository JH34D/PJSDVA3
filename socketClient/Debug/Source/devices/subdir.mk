################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/devices/Bed.cpp \
../Source/devices/Chair.cpp \
../Source/devices/Column.cpp \
../Source/devices/Door.cpp \
../Source/devices/Frigde.cpp \
../Source/devices/Lamp.cpp \
../Source/devices/Window.cpp 

OBJS += \
./Source/devices/Bed.o \
./Source/devices/Chair.o \
./Source/devices/Column.o \
./Source/devices/Door.o \
./Source/devices/Frigde.o \
./Source/devices/Lamp.o \
./Source/devices/Window.o 

CPP_DEPS += \
./Source/devices/Bed.d \
./Source/devices/Chair.d \
./Source/devices/Column.d \
./Source/devices/Door.d \
./Source/devices/Frigde.d \
./Source/devices/Lamp.d \
./Source/devices/Window.d 


# Each subdirectory must supply rules for building sources it contributes
Source/devices/%.o: ../Source/devices/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -I/home/programmer/jsonLib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


