################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Device.cpp \
../Source/File.cpp \
../Source/Php.cpp \
../Source/sockClient.cpp \
../Source/socketClient.cpp 

OBJS += \
./Source/Device.o \
./Source/File.o \
./Source/Php.o \
./Source/sockClient.o \
./Source/socketClient.o 

CPP_DEPS += \
./Source/Device.d \
./Source/File.d \
./Source/Php.d \
./Source/sockClient.d \
./Source/socketClient.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -I/home/programmer/jsonLib -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


