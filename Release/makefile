################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ..\makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src\ds1302\examples\set_clock\subdir.mk
-include src\ds1302\examples\ram\subdir.mk
-include src\ds1302\subdir.mk
-include src\TouchScreen\examples\touchscreendemoshield\subdir.mk
-include src\TouchScreen\examples\touchscreendemo\subdir.mk
-include src\TouchScreen\subdir.mk
-include src\SparkFun_CCS811\src\subdir.mk
-include src\SparkFun_CCS811\examples\setEnvironmentalReadings\subdir.mk
-include src\SparkFun_CCS811\examples\WakeAndInterrupt\subdir.mk
-include src\SparkFun_CCS811\examples\TwentyMinuteTest\subdir.mk
-include src\SparkFun_CCS811\examples\NTCCompensated\subdir.mk
-include src\SparkFun_CCS811\examples\Core\subdir.mk
-include src\SparkFun_CCS811\examples\BasicReadings\subdir.mk
-include src\SparkFun_CCS811\examples\BaselineOperator\subdir.mk
-include src\SparkFun_CCS811\examples\BME280Compensated\subdir.mk
-include src\SparkFun_BME280\src\subdir.mk
-include src\SparkFun_AS3935\src\subdir.mk
-include src\SparkFun_AS3935\examples\Example3_Tune_Antenna_SPI\subdir.mk
-include src\SparkFun_AS3935\examples\Example3_Tune_Antenna_I2C\subdir.mk
-include src\SparkFun_AS3935\examples\Example2_More_Lightning_Features_SPI\subdir.mk
-include src\SparkFun_AS3935\examples\Example2_More_Lightning_Features_I2C\subdir.mk
-include src\SparkFun_AS3935\examples\Example1_BasicLightning_SPI\subdir.mk
-include src\SparkFun_AS3935\examples\Example1_BasicLightning_I2C\subdir.mk
-include src\MCUFRIEND_kbv\subdir.mk
-include src\I2C\examples\HMC5883L\subdir.mk
-include src\I2C\subdir.mk
-include src\AS3935_I2C_PSImod\subdir.mk
-include libraries\Wire\src\utility\subdir.mk
-include libraries\Wire\src\subdir.mk
-include libraries\SoftwareSerial\src\subdir.mk
-include libraries\SPI\src\subdir.mk
-include libraries\Adafruit_TFTLCD_Library\subdir.mk
-include libraries\Adafruit_GFX_Library\subdir.mk
-include libraries\Adafruit_BusIO\subdir.mk
-include core\core\subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ..\makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:\Users\awaal\Documents\sloeber-workspace\WMMI211_Firmware\Release\arduino.ar \

ELF += \
WMMI211_Firmware.elf \

HEX += \
WMMI211_Firmware.hex \



#bootloaderTest
BurnBootLoader: 
	@echo trying to burn bootloader ${bootloader.tool}
	${tools.${bootloader.tool}.erase.pattern}
	${tools.${bootloader.tool}.bootloader.pattern}

uploadWithBuild: all
	@echo trying to build and upload with upload tool ${upload.tool}
	${tools.${upload.tool}.upload.pattern}

uploadWithoutBuild: 
	@echo trying to upload without build with upload tool ${upload.tool}
	${tools.${upload.tool}.upload.pattern}
    
uploadWithProgrammerWithBuild: all
	@echo trying to build and upload with programmer ${program.tool}
	${tools.${program.tool}.program.pattern}

uploadWithProgrammerWithoutBuild: 
	@echo trying to upload with programmer ${program.tool} without build
	${tools.${program.tool}.program.pattern}

# All Target
all: WMMI211_Firmware

# Tool invocations
WMMI211_Firmware: $(HEX)
	@echo 'Building target: $@'
	@echo 'Druk de grote af:'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "C:\Users\awaal\Documents\sloeber-workspace\WMMI211_Firmware\Release/WMMI211_Firmware.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:\Users\awaal\Documents\sloeber-workspace\WMMI211_Firmware\Release\arduino.ar: $(AR_OBJ)
	@echo 'Start de archief bouwer'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs     C:\Users\awaal\Documents\sloeber-workspace\WMMI211_Firmware\Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

WMMI211_Firmware.elf: $(LINK_OBJ) $(AR)
	@echo 'Start de samenvoeger'
	"C:\Users\awaal\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections,--relax -mmcu=atmega2560   -o "C:\Users\awaal\Documents\sloeber-workspace\WMMI211_Firmware\Release/WMMI211_Firmware.elf"   $(LINK_OBJ)    C:\Users\awaal\Documents\sloeber-workspace\WMMI211_Firmware\Release/arduino.ar  "-LC:\Users\awaal\Documents\sloeber-workspace\WMMI211_Firmware\Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

WMMI211_Firmware.hex: $(ELF)
	@echo 'Voer alle objcopy opdrachten uit'
	${recipe.objcopy.eep.pattern}
	${recipe.objcopy.hex.pattern}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ..\makefile.targets
