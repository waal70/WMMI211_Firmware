################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\src\SDmega\utility\Sd2Card.cpp \
..\src\SDmega\utility\SdFile.cpp \
..\src\SDmega\utility\SdVolume.cpp 

LINK_OBJ += \
.\src\SDmega\utility\Sd2Card.cpp.o \
.\src\SDmega\utility\SdFile.cpp.o \
.\src\SDmega\utility\SdVolume.cpp.o 

CPP_DEPS += \
.\src\SDmega\utility\Sd2Card.cpp.d \
.\src\SDmega\utility\SdFile.cpp.d \
.\src\SDmega\utility\SdVolume.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
src\SDmega\utility\Sd2Card.cpp.o: ..\src\SDmega\utility\Sd2Card.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_TFTLCD_Library" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

src\SDmega\utility\SdFile.cpp.o: ..\src\SDmega\utility\SdFile.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_TFTLCD_Library" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

src\SDmega\utility\SdVolume.cpp.o: ..\src\SDmega\utility\SdVolume.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_TFTLCD_Library" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


