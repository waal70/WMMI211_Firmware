################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO\Adafruit_BusIO_Register.cpp \
C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO\Adafruit_I2CDevice.cpp \
C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO\Adafruit_SPIDevice.cpp 

LINK_OBJ += \
.\libraries\Adafruit_BusIO\Adafruit_BusIO_Register.cpp.o \
.\libraries\Adafruit_BusIO\Adafruit_I2CDevice.cpp.o \
.\libraries\Adafruit_BusIO\Adafruit_SPIDevice.cpp.o 

CPP_DEPS += \
.\libraries\Adafruit_BusIO\Adafruit_BusIO_Register.cpp.d \
.\libraries\Adafruit_BusIO\Adafruit_I2CDevice.cpp.d \
.\libraries\Adafruit_BusIO\Adafruit_SPIDevice.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Adafruit_BusIO\Adafruit_BusIO_Register.cpp.o: C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO\Adafruit_BusIO_Register.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_TFTLCD_Library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BusIO\Adafruit_I2CDevice.cpp.o: C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO\Adafruit_I2CDevice.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_TFTLCD_Library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Adafruit_BusIO\Adafruit_SPIDevice.cpp.o: C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO\Adafruit_SPIDevice.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_TFTLCD_Library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


