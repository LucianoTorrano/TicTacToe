################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameData.cpp \
../UserData.cpp \
../error.cpp \
../main.cpp \
../utilities.cpp 

OBJS += \
./GameData.o \
./UserData.o \
./error.o \
./main.o \
./utilities.o 

CPP_DEPS += \
./GameData.d \
./UserData.d \
./error.d \
./main.d \
./utilities.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


