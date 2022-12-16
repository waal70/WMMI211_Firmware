################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\awaal\Documents\Arduino\libraries\Rtc_by_Makuna\src\RtcDateTime.cpp \
C:\Users\awaal\Documents\Arduino\libraries\Rtc_by_Makuna\src\RtcUtility.cpp 

LINK_OBJ += \
.\libraries\Rtc_by_Makuna\src\RtcDateTime.cpp.o \
.\libraries\Rtc_by_Makuna\src\RtcUtility.cpp.o 

CPP_DEPS += \
.\libraries\Rtc_by_Makuna\src\RtcDateTime.cpp.d \
.\libraries\Rtc_by_Makuna\src\RtcUtility.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Rtc_by_Makuna\src\RtcDateTime.cpp.o: C:\Users\awaal\Documents\Arduino\libraries\Rtc_by_Makuna\src\RtcDateTime.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -I"C:\Users\awaal\Documents\Arduino\libraries\Rtc_by_Makuna\src" -I"C:\Users\awaal\Documents\Arduino\libraries\TimeAlarms" -I"C:\Users\awaal\Documents\Arduino\libraries\Time" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Rtc_by_Makuna\src\RtcUtility.cpp.o: C:\Users\awaal\Documents\Arduino\libraries\Rtc_by_Makuna\src\RtcUtility.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -I"C:\Users\awaal\Documents\Arduino\libraries\Rtc_by_Makuna\src" -I"C:\Users\awaal\Documents\Arduino\libraries\TimeAlarms" -I"C:\Users\awaal\Documents\Arduino\libraries\Time" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


