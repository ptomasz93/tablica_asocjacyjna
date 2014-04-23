################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../prj/element.cpp \
../prj/generator.cpp \
../prj/main.cpp \
../prj/tablica.cpp 

OBJS += \
./prj/element.o \
./prj/generator.o \
./prj/main.o \
./prj/tablica.o 

CPP_DEPS += \
./prj/element.d \
./prj/generator.d \
./prj/main.d \
./prj/tablica.d 


# Each subdirectory must supply rules for building sources it contributes
prj/%.o: ../prj/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


