################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../prj/src/generator.cpp \
../prj/src/main.cpp 

OBJS += \
./prj/src/generator.o \
./prj/src/main.o 

CPP_DEPS += \
./prj/src/generator.d \
./prj/src/main.d 


# Each subdirectory must supply rules for building sources it contributes
prj/src/%.o: ../prj/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


