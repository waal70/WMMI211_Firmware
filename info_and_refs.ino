/******************************************************************************
  EarthListener by Pieter Sijmons @ Velleman NV
  
  This fork 2022 by waal70
  -------------------------------        
  SD card datalogger on TFT shield on Arduino Mega
  Based on the example by Tom Igoe - 9 Apr 2012
  This example shows how to log data from three analog sensors (A11 -> A14) to an SD card using the SD library.
   
 The circuit:
 ** Mega:  MOSI - pin 51, MISO - pin 50, CLK - pin 52, CS - pin 4 (CS pin can be changed)
  and pin #52 (SS) must be an output
 => because we are using an TFT shield with SD card, some modifications needs to be done in the libary
 1. Download the SD Adafruit library from https://github.com/adafruit/SD and replace the file in your library 
 2. comment out #define USE_SPI_LIB from both Sd2Card.h and Sd2Card.cpp. 
 3. Modify Sd2Card.h to enable the softSPI for Mega 2560 by modifying this line: #define MEGA_SOFT_SPI 1  //change it to non-zero from 0     
   
 -------------------------------

 Required libraries (system-wide):
   Adafruit_BusIO
   Adafruit_GFX_Library
   EEPROM
   SPI
   Wire
 Required libraries (in /src folder):
   ds1302
   MCUFRIEND_kbv
   SparkFun_AS3935
   SparkFun_BME280
   SparkFun_CCS811
   TouchScreen
******************************************************************************/
