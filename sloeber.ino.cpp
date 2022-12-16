#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2022-12-16 22:43:07

#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <EEPROM.h>
#include "ccs811.h"
#include "src\Adafruit-GFX-Library\Adafruit_GFX.h"
#include "src\Adafruit-GFX-Library\Fonts\FreeSans9pt7b.h"
#include "src\MCUFRIEND_kbv\MCUFRIEND_kbv.h"
#include "src\SDmega\SDmega.h"
#include "src\SparkFun_AS3935\src\SparkFun_AS3935.h"
#include "src\TFTLCD-Library\Adafruit_TFTLCD.h"
#include "src\TouchScreen\TouchScreen.h"
#include "bitmaps.h"
#include "config.h"
#include <Adafruit_BME280.h>
#include <Adafruit_CCS811.h>

void loop(void) ;
void Print_Level(int data1) ;
void printSensorError() ;
unsigned long testFillScreen() ;
void updateCCS811vars(float TEMP, float HUMIDITY) ;
void interruptFunction() ;
void controlLED(char COLOR) ;
void setOutput(char COLOR) ;
void controlLogo(uint16_t logocolor) ;
void getTimeSinceBoot() ;
int returnMinutes(unsigned long Millis) ;
String returnTime(Time currentTime)  ;
boolean touchedMe() ;
void showScreen(int screenNr) ;
void lightningscreen() ;
void setupAS3935() ;
void updateLightningSense() ;
void printValues() ;
void printMenuBtn() ;
void printLastDetectionTimeAS3935() ;
void inputControl() ;
void checkBaseTouch() ;
void toggleSlideShow() ;
void toggleBuzzer() ;
void toggleMetric() ;
void toggleIndoor() ;
void toggleInterface() ;
void showbgd(int x, int y, const uint8_t *bmp, int w, int h, uint16_t color, uint16_t bg) ;
void setup(void) ;

#include "WMMI211_Firmware.ino"

#include "functions.ino"
#include "info_and_refs.ino"
#include "setup.cpp"

#endif
