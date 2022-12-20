// configuration file to hold some basic constants to avoid magic numbers -
// refactoring work in progress

#define SWversion "v4.2adw"

#ifndef CONFIG_H
#define CONFIG_H

// user.h is not checked in to github - put things like real coordinates, API keys etc, in that file
#include "user.h"

// number of screens we have configured in the system. Should be replaced with
// something smarter
#define NRSCREENS 8
#define MAXSCREEN (NRSCREENS + 2)

// clock settings
#define NTP_HOST "time.windows.com"

// default interval to log to SDCARD and mqtt
#define UPDATE_INTERVAL 10 // update sensors every 10 seconds
#define LOGGING_INTERVAL                                                       \
  30 // how many readings between logs? 10x30=300 = 5 minutes by default

#define WITH_ESP01 // for wifi

#define WEATHER_FORECAST // to get weather forecast from SMHI

#define INITIAL_SLIDESHOW_STATUS                                               \
  1 // change to 0 to not run slideshow from start. Using the slideshow from
    // start will show the config screens, before getting into the loop
    // correctly.

// sdcard settings
#define SD_CHIP_SELECT 10
#define LOGFILE "datalog.csv"   // original velleman filename
#define CONFIGFILE "config.cfg" // using the SDConfig library

// for BME280

#define SEALEVELPRESSURE 1013.25

/* --- CCS811 sensor --- */
#define CCS811_ADDR 0x5B      //Default I2C Address of CCS811 sensor (secondary Address is 0x5A if jumper is closed)

#define BME280_ADDR 0x77      //Default I2C Address of BME280 sensor, can be 0x76 if jumper closed
#define TEMP_comp  -3.3   //the EarthListener is warmed up from the TFT screen hence reporting a higher temperature. This compensation corrects this.
#define HUMI_comp 17     //same for the humidity. Values are experimental and should be changed according to your findings.
//
/* --- RTC VMA301 --- */
#define kCePin    35  // Chip Enable    RST pin on VMA301
#define kIoPin    37  // Input/Output   DAT pin on VMA301
#define kSclkPin  39  // Serial Clock   CLK pin on VMA301
/* --- DIGITAL outputs --- */
#define GreenOutPin   30
#define YellowOutPin  31
#define RedOutPin     32

// display positioning
#define startXimg 10
#define startYimg 175
#define widthImg 300
#define heightImg 1

// clock settings

#define CLOCK_X 160   // center x
#define CLOCK_Y 130   // center y
#define CLOCK_R 60    // radius
#define CLOCK_CR 2    // centre blob radius
#define CLOCK_H_LEN 4 // length of hour marks
#define CLOCK_H_HAND                                                           \
  0.7 // length of hour hand (as fraction of the clock radius)

// - from original vmm_...ino file, should normally not be touched!

#define CCS811_ADDR 0x5B // Default I2C Address

/* --- LCD panel with touch --- */
// be aware we use the TFT LCD on a Arduino Mega
#define YP A3       // must be an analog pin, use "An" notation!
#define XM A2       // must be an analog pin, use "An" notation!
#define YM 9        // can be a digital pin
#define XP 8        // can be a digital pin
#define touchPin 38 // pin to use for reading touchscreen

#define TS_MINX 100
#define TS_MAXX 920
#define TS_MINY 70
#define TS_MAXY 900
#define MINPRESSURE 10
#define MAXPRESSURE 1000

#define touchTimeout 300 // timeout between touch inputs (ms)

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET                                                              \
  A4 // Normally A4, but can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
// http://www.barth-dev.de/online/rgb565-color-picker/
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define GREY 0xD69A
#define GREYY 0xAD55

/* --- Speaker --- */
// pin setup for speaker
#define BuzzerPin A10

/* --- RGB LED --- */
#define LEDgnd A11
#define LEDg A12
#define LEDr A13
#define LEDb A14

/* EEPROM addresses */

#define AS3935_outdoor_EEPROMaddr                                              \
  0 // address to store this value in long term memory (EEPROM)
#define Buzzer_EEPROMaddr                                                      \
  1 // address to store this value in long term memory (EEPROM)
#define MetricON_EEPROMaddr                                                    \
  2 // address to store this value in long term memory (EEPROM)
#define AS3935_SPI_EEPROMaddr                                                  \
  3 // address to store this value in long term memory (EEPROM)
#define globalSense_EEPROMaddr                                                 \
  4 // address to store this value in long term memory (EEPROM)
#define firstBoot_EEPROMaddr                                                   \
  5 // EEPROM long term memory adress that we use to check if the EarthListener
    // has been booted before (default will be true).

// defines
#define AS3935_ADD                                                             \
  0x03 // Default I2C Address of AS3935 sensor: x03 <-- you can use i2C scanner
       // to see the i2c address
#define AS3935_IRQPIN                                                          \
  18                // interrupt pin on board (18 or 19 on MEGA, 2 or 3 on UNO)
#define spiCS 41    // chip select pin
#define INDOOR 0x12 // value for indoor use (do not change)
#define OUTDOOR 0xE // value for outdoor use (do not change)
#define LIGHTNING_INT 0x08 // value for lightning source (do not change)
#define DISTURBER_INT 0x04 // value for disturber source (do not change)
#define NOISE_INT 0x01     // value for noise source (do not change)

#endif
