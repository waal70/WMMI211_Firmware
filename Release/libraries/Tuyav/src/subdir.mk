################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\InputClass.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\OutputClass.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\TuyaSerial.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\Tuyav.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\analogInput.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\analogOutput.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\digitalInput.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\digitalOutput.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\mcu_api.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\protocol.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\system.cpp \
C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\userValue.cpp 

LINK_OBJ += \
.\libraries\Tuyav\src\InputClass.cpp.o \
.\libraries\Tuyav\src\OutputClass.cpp.o \
.\libraries\Tuyav\src\TuyaSerial.cpp.o \
.\libraries\Tuyav\src\Tuyav.cpp.o \
.\libraries\Tuyav\src\analogInput.cpp.o \
.\libraries\Tuyav\src\analogOutput.cpp.o \
.\libraries\Tuyav\src\digitalInput.cpp.o \
.\libraries\Tuyav\src\digitalOutput.cpp.o \
.\libraries\Tuyav\src\mcu_api.cpp.o \
.\libraries\Tuyav\src\protocol.cpp.o \
.\libraries\Tuyav\src\system.cpp.o \
.\libraries\Tuyav\src\userValue.cpp.o 

CPP_DEPS += \
.\libraries\Tuyav\src\InputClass.cpp.d \
.\libraries\Tuyav\src\OutputClass.cpp.d \
.\libraries\Tuyav\src\TuyaSerial.cpp.d \
.\libraries\Tuyav\src\Tuyav.cpp.d \
.\libraries\Tuyav\src\analogInput.cpp.d \
.\libraries\Tuyav\src\analogOutput.cpp.d \
.\libraries\Tuyav\src\digitalInput.cpp.d \
.\libraries\Tuyav\src\digitalOutput.cpp.d \
.\libraries\Tuyav\src\mcu_api.cpp.d \
.\libraries\Tuyav\src\protocol.cpp.d \
.\libraries\Tuyav\src\system.cpp.d \
.\libraries\Tuyav\src\userValue.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Tuyav\src\InputClass.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\InputClass.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\OutputClass.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\OutputClass.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\TuyaSerial.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\TuyaSerial.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\Tuyav.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\Tuyav.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\analogInput.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\analogInput.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\analogOutput.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\analogOutput.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\digitalInput.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\digitalInput.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\digitalOutput.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\digitalOutput.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\mcu_api.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\mcu_api.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\protocol.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\protocol.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\system.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\system.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\Tuyav\src\userValue.cpp.o: C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src\userValue.cpp
	@echo 'Building file: $<'
	@echo 'Start de C++ bouw'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\mega" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SoftwareSerial\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\EEPROM\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Users\awaal\Sloeber\arduinoPlugin\libraries\Tuyav\1.2.1\src" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BME280_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_CCS811_Library" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\awaal\Documents\Arduino\libraries\Adafruit_Unified_Sensor" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


