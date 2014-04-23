################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../prj/clasa.cpp \
../prj/drzewo.cpp \
../prj/generator.cpp \
../prj/main.cpp 

OBJS += \
./prj/clasa.o \
./prj/drzewo.o \
./prj/generator.o \
./prj/main.o 

CPP_DEPS += \
./prj/clasa.d \
./prj/drzewo.d \
./prj/generator.d \
./prj/main.d 


# Each subdirectory must supply rules for building sources it contributes
prj/%.o: ../prj/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


