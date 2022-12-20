/*
 * globals.h
 *
 *  Created on: 18 dec. 2022
 *      Author: awaal
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <stdint.h>
#include <Arduino.h>

#include "config.h"
#include "src\SparkFun_AS3935\src\SparkFun_AS3935.h"      // AS3935 library by SparkFun
#include "src\SparkFun_CCS811\src\SparkFunCCS811.h"    	  // CCS811 library by SparkFun
#include "src\SparkFun_BME280\src\SparkFunBME280.h"    	  // BME280 library by SparkFun
#include "src\MCUFRIEND_kbv\MCUFRIEND_kbv.h"
#include "src\TouchScreen\TouchScreen.h"               	  // TouchScreen library by Adafruit
#include "src\ds1302\DS1302.h"                            // DS1302 RTC library

#include "model/EarthListenerController.h"

inline int CO2;
inline int TVOC;

//inline auto elc;

/* --- BME280 air sensor --- */
inline float HUMIDITY_BME280;
inline float AMBIENTPRESSURE_BME280;
inline float AMBIENTPRESSURE_BME280_c; //converted to mBar (= Pa / 100);
inline float ALTITUDE_BME280;
inline float TEMP_BME280;



/* --- AS3935 sensor --- */
//selection of IIC or SPI interface (also change the jumper JSI on the board!)
inline boolean AS3935_SPI = true;  //SPI= true & jumper JSI connected - IIC= false & jumper JSI disconnected

// Interrupt flag variable for AS3935 irqs that indicates interrupt has been triggered
// Variables that get changed in interrupt routines need to be declared volatile
// otherwise compiler can optimize them away, assuming they never get changed
inline volatile int AS3935IrqTriggered;
inline unsigned long AS3935IrqTriggeredTime = 0;     //time when last detection was triggered;
inline uint8_t int_src;                              //interrupt source:  This variable holds the number representing the lightning or non-lightning event issued by the lightning detector.
inline int minutesSinceAS3935Trigger;                //time since last detection
const String lastErrorLine1 =  "No Disturber (yet)...";   //Keep last error message (but set for when there is none)
const String lastErrorLine2 =  "Keep Calm and Carry On";  //Keep last error message (but set for when there is none)

inline boolean AS3935_OUTDOORS;            // Set to 1 to enabled for Outdoor Used, use 0 for Indoor Use

// Values for modifying the AS3935's settings. All of these values are set in via the globalSense variable and controlled trough the setup page
inline byte noiseFloor;        // noise threshold value between 1-7, one being the lowest. Default setting is 2
inline byte watchDogVal;       // Watchdog threshold value between 1-10, one being the lowest. Default setting is 2
inline byte spike;             // Spike Rejection value between 1-11, one being the lowest. Default setting is 2.
inline byte lightningThresh;   // lightning threshold value, can be 1, 5, 9 and 16. Default setting is 1.
inline boolean maskDisturbers; // Mask disturbers. Values can be true or false. Default setting is true.
inline byte globalSense;       // global sensitivity (sets values above + maskDisturber). Values are 1=low, 2=medium, 3=high. Default setting is 2.

inline SparkFun_AS3935 lightningSPI;              // define Lightning sensor for SPI
inline SparkFun_AS3935 lightningIIC(AS3935_ADD);  // define Lightning sensor on specific address for IIC
inline boolean AS3935_bootOK;                     // value to store OK boot status of the sensor

//now declare tft item
inline MCUFRIEND_kbv tft;    //we use a DRIVER IC ILI9341

/* --- LCD panel with touch --- */
//be aware we use the TFT LCD on a Arduino Mega
inline int Xpos;
inline int Ypos; //global positions to store touchscreen location
inline unsigned long touchedTime = 0;     //time when last touchscreen interaction occurred;


// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 320 ohms across the X plate
inline TouchScreen ts = TouchScreen(XP, YP, XM, YM, 320);


/* --- Speaker --- */
//pin setup for speaker
inline boolean BuzzerEnabled;      //1= Buzzer on, 0= Buzzer off => can be modified via TFT interface


/* --- RGB LED --- */
inline boolean LEDenabled = 1;     //1= LED on, 0= LED off. Will also declare pins for output if turned on.


/* --- datalogging & timing --- */
// Modifications:
// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work. On our TFT SD card shield we use 10
const int chipSelect = 10;
inline boolean SDpresent = 0;        //boolean to store if SD card is present during setup
inline boolean logFileExists = 0;    //boolean to store if logfile exists on SD card
inline const char * logFileName = "datalog.csv";   //CSV so you can easy load the data into MS Excel
inline unsigned long allSeconds;
inline int runDays;
inline unsigned long secsRemaining;
inline int runHours;
inline int runMinutes;
inline int runSeconds;
inline int lastSecond = 99;        //we set this value so we can know when we just booted
inline int secondCounter = 0;      //counter to calculate the number of seconds that have been passed between loggings
inline int loggingInterval = 10;   //interval to log the values to the SD card in seconds. Default: 10, min: 1, maximum: 3600 (1 hour)


/* --- RTC real time clock VMA301 module --- */
//VM301 module, set the appropriate digital I/O pin connections for the DS1302 chip
//See the DS1302 datasheet: http://datasheets.maximintegrated.com/en/ds/DS1302.pdf
//inline DS1302 rtc(kCePin, kIoPin, kSclkPin);     // Create a DS1302 object
inline boolean RTCpresent = false;    //boolean to check if a RTC is present (will be updated in boot loop)
inline int shownMinute;              //var to store the last shown minute on screen


/* --- menus --- */
inline int currentScreenNr = 0;        //start with bootscreen
inline int previousScreenNr;
inline boolean slideShowPlaying;        //is the slide show playing? yes=1, no=0
inline int slideshowTimer = 5;         //time (in seconds) to show each slide
inline unsigned long timeStartSlide = 0;     //time when slide was first shown;


/* --- metric / imperial switch --- */
inline boolean MetricON;  //boolean to check if values of temperature and lightning distance are set in Celsius/km or Fahrenheit/miles => can be modified via TFT interface

inline CCS811 myCCS811(CCS811_ADDR);
inline BME280 myBME280;




#endif /* GLOBALS_H_ */
