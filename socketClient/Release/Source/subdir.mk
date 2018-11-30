################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/File.cpp \
../Source/sockClient.cpp \
../Source/socketClient.cpp 

OBJS += \
./Source/File.o \
./Source/sockClient.o \
./Source/socketClient.o 

CPP_DEPS += \
./Source/File.d \
./Source/sockClient.d \
./Source/socketClient.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


