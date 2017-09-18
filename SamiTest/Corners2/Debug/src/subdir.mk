################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Corners2.cpp \
../src/Sami_harris_contour.cpp \
../src/Shi-Tomasi.cpp \
../src/contours.cpp \
../src/contours2.cpp \
../src/harris_detector.cpp 

OBJS += \
./src/Corners2.o \
./src/Sami_harris_contour.o \
./src/Shi-Tomasi.o \
./src/contours.o \
./src/contours2.o \
./src/harris_detector.o 

CPP_DEPS += \
./src/Corners2.d \
./src/Sami_harris_contour.d \
./src/Shi-Tomasi.d \
./src/contours.d \
./src/contours2.d \
./src/harris_detector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


