################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\src\SparkFun_BME280\src\SparkFunBME280.cpp 

LINK_OBJ += \
.\src\SparkFun_BME280\src\SparkFunBME280.cpp.o 

CPP_DEPS += \
.\src\SparkFun_BME280\src\SparkFunBME280.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
src\SparkFun_BME280\src\SparkFunBME280.cpp.o: ..\src\SparkFun_BME280\src\SparkFunBME280.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_TFTLCD_Library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


