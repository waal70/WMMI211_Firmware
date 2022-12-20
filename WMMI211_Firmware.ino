/******************************************************************************
  EarthListener by Pieter Sijmons @ Velleman NV
  Based on examples by Adafruit, SparkFun and Tom Igoe
  See tab 'info_and_refs' for more documentation

  This fork by André - 2022
  CHANGES:
  	  No use of Tuyav
******************************************************************************/

/***************************************/
/* ---------- DECLARATIONS ----------- */
/***************************************/
/* --- Global Libraries --- */
#include <Wire.h>                               // Wire library
#include <SPI.h>                                // SPI library
#include <EEPROM.h>                             // Library to read & store info in EEPROM long term memory

#include <Adafruit_GFX.h>     	  				// Core graphics library by Adafruit
#include <Adafruit_TFTLCD.h>				    // Hardware-specific library for TFT screen by Adafruit

/* --- Local Libraries --- */


#include "src\SparkFun_BME280\src\SparkFunBME280.h"    	  // BME280 library by SparkFun
//#include "src\SDmega\SDmega.h"
#include "src\SparkFun_CCS811\src\SparkFunCCS811.h"    	  // CCS811 library by SparkFun
#include "src\SparkFun_AS3935\src\SparkFun_AS3935.h"      // AS3935 library by SparkFun
#include "src\TouchScreen\TouchScreen.h"               	  // TouchScreen library by Adafruit
#include "src\ds1302\DS1302.h"                            // DS1302 RTC library

#include "bitmaps.h"                            			    // Icon library (local, hence the "")
#include "functions.h"
#include "config.h"
#include "globals.h"


/***************************************/
/* ----------- LOOP CODE ------------ */
/***************************************/
void loop(void)
{
  
  //timing: get time since boot: will write to global vars 
  getTimeSinceBoot();

  //get touch input (but only after XXX ms after last touchscreen event!)
  if((millis() - touchedTime) > touchTimeout)
  {
    if(touchedMe())
    {
      touchedTime = millis();
      //Serial.print("We have been touched! X=");Serial.print(Xpos);Serial.print(", Y="); Serial.println(Ypos);
      inputControl();
      showScreen(currentScreenNr);  //0:Boot, 1:Info screen, 2:Setup, 3:eCO², 4:Temperature 5:Pressure, 6:TVOC, 7:Humidity, 8:Lightning, 81:Lightning after interrupt
    }
  }

  //only do next code each second
  if(runSeconds != lastSecond)
  {
        //increase the secondCounter
        secondCounter++;
        /****** poll sensors & update vars + log to SD *****/
        // make a string for assembling the data to log on the SD card & add the current time:
        String dataString = "";
        //check if RTC is present, if it is, use real time, otherwise use running time since boot
//        if(RTCpresent)
//        {
//          Time timeNow = .time();
//          //we can use this value to show time info on the screen, but will only update this if the minute has been changed
//          if(timeNow.min == shownMinute)
//          {
//            //do nothing
//          }
//          else
//          {
//           tft.setFont();  //standard system font
//           tft.setTextSize(1); tft.setTextColor(GREYY,BLACK);
//           //print day & date
//           tft.setCursor(20, 25);
//
//           //String myDay = dayAsString(timeNow.day);
//
//           tft.print(dayAsString(timeNow.day));
//           tft.print("  ");
//           tft.setCursor(20, 40);
//           if(MetricON)
//           {
//              if(timeNow.date <10){tft.print("0");}
//              tft.print(timeNow.date); tft.print("-");
//              if(timeNow.mon <10){tft.print("0");}
//              tft.print(timeNow.mon); tft.print("-"); tft.print(timeNow.yr);
//           }
//           else
//           {
//              tft.print(timeNow.yr); tft.print("/");
//              if(timeNow.mon <10){tft.print("0");}
//              tft.print(timeNow.mon); tft.print("/");
//              if(timeNow.date <10){tft.print("0");}
//              tft.print(timeNow.date);
//           }
//           //print hour & minutes
//           tft.setTextSize(2);
//           tft.setCursor(240, 30);
//           if(timeNow.hr <10){tft.print("0");}
//           tft.print(timeNow.hr); tft.print(":");
//           if(timeNow.min <10){tft.print("0");}
//           tft.print(timeNow.min);
//
//           shownMinute = timeNow.min;
//          }
//          dataString = returnTime(timeNow);
//        }
//        else
//        {
//          char buf[17];
//          sprintf(buf,"%02d %02d:%02d:%02d",runDays,runHours,runMinutes,runSeconds);
//          dataString = buf;
//        }
        dataString += ",";

        //calculate minutes between current time & time when AS3935sensor was triggered
        minutesSinceAS3935Trigger = returnMinutes(millis() - AS3935IrqTriggeredTime);
        
        //read data from BME280
        HUMIDITY_BME280 = myBME280.readFloatHumidity();
        AMBIENTPRESSURE_BME280 = myBME280.readFloatPressure();
        AMBIENTPRESSURE_BME280_c = AMBIENTPRESSURE_BME280 / 100; //convert Pa to mBar
        ALTITUDE_BME280 = myBME280.readFloatAltitudeMeters();
        TEMP_BME280 = myBME280.readTempC();
        //compensate temp & humi data
        TEMP_BME280 = TEMP_BME280 + TEMP_comp;
        if(HUMIDITY_BME280 <= (100 - HUMI_comp))  //make sure we don't have values > 100%
        {
          HUMIDITY_BME280 = HUMIDITY_BME280 + HUMI_comp;
        }
        
        //print data from BME280 to serial
        /*
        Serial.print("BME280   data:");
        Serial.print("                                 ");
        Serial.print("Temp: ");
        Serial.print( TEMP_BME280, 2);
        Serial.print("°C");
        Serial.print("     Humidity: ");
        Serial.print(HUMIDITY_BME280, 2);
        Serial.print("%");
        Serial.print("     Pressure: ");
        Serial.print( AMBIENTPRESSURE_BME280_c, 2);
        Serial.print("mBar");
        Serial.print("     Altitude: ");
        Serial.print( ALTITUDE_BME280, 2);
        Serial.println("m");
        */
        
        //add data to dataString to write to SD
        dataString += TEMP_BME280,2;
        dataString += ",";
        dataString += HUMIDITY_BME280,2;
        dataString += ",";
        dataString += AMBIENTPRESSURE_BME280_c,2;
        dataString += ",";
        dataString += ALTITUDE_BME280,2;
        dataString += ",";

        //read data from CCS811 (or show error)
        if (myCCS811.checkForStatusError())
        {
          tft.fillRect(0,55,320,185,BLACK);  //clear part of the screen (startX, startY, width, height, color)
          printSensorError();
          delay(2000); //keep this info on screen for 2 seconds
          tft.fillScreen(BLACK); //clear screen for next run
        }
        else if (myCCS811.dataAvailable())
        {
          //Pass the temperature & humidity from BME280 sensor back into the CCS811 to compensate
          updateCCS811vars(TEMP_BME280,HUMIDITY_BME280);
          //read data from CCS811
          myCCS811.readAlgorithmResults(); //Calling this function updates the global tVOC and CO2 variables
          CO2 = myCCS811.getCO2();
          TVOC = myCCS811.getTVOC();

          //print data from CCS811 to serial
          /*
          Serial.print("CCS811   data:");
          Serial.print(" eCO²: ");
          Serial.print(CO2);
          Serial.print("ppm");
          Serial.print("     TVOC: ");
          Serial.print(TVOC);
          Serial.println("ppb");
          */
          
          //add data to dataString to write to SD
          dataString += CO2;
          dataString += ",";
          dataString += TVOC;
        }
    
        //write dataString to SD (if SD card is present & we have passed the interval to log)
        if(SDpresent && secondCounter >= loggingInterval)
        {
          secondCounter = 0;
          //File dataFile = SD.open(logFileName, FILE_WRITE);
          // open the file. note that only one file can be open at a time,
          // so you have to close this one before opening another.
           
          // if the file is available, write to it:
          //if (dataFile)
//          {
//            if(!logFileExists)  //the logfile didn't exist, so first print headers
//            {
//              Serial.print("Logfile '");
//              Serial.print(logFileName);
//              Serial.println("' did not exist, so print titles first...");
//              if(RTCpresent)  //check if there is a RTC present
//              {
//                dataFile.println("Date & Time [Day YYYY-MM-DD HH:MM:SS],Temperature [°C],Humidity [%],Pressure [mBar],Altitude [m],eCO2 [ppm],TVOC [ppb]");
//              }
//              else
//              {
//                dataFile.println("Time since boot [DD HH:MM:SS],Temperature [°C],Humidity [%],Pressure [mBar],Altitude [m],eCO2 [ppm],TVOC [ppb]");
//              }
//              logFileExists = 1;
//            }
//            dataFile.println(dataString);
//            dataFile.close();
//
//            // print to the serial port too:
//            Serial.print("Written to file ");
//            Serial.print(logFileName);
//            Serial.print(" on SD card: ");
//            Serial.println(dataString);
//          }
//          // if the file isn't open, pop up an error:
//          else
//          {
//            Serial.print("Error opening file ");
//            Serial.print(logFileName);
//            Serial.println(" on SD card! No data logged.");
//          }
        }


        /****show screens****/
        //interrupt from lightning sensor! -> show lightning screen, otherwise show info screen
        //we only do this if AS3935_bootOK is true (otherwise noise from sensor)
        if (AS3935IrqTriggered && AS3935_bootOK)
        {
          Serial.println("Interrupt from lightning sensor");
          
          //check interrupt source
          delay(5); //wait so not to overflow the bus
          if(AS3935_SPI)
          {
            int_src = lightningSPI.readInterruptReg();
          }else
          {
            int_src = lightningIIC.readInterruptReg();
          }
          
          showScreen(81);   //0:Boot, 1:Info screen, 2:Setup, 3:eCO², 4:Temperature 5:Pressure, 6:TVOC, 7:Humidity, 8:Lightning, 81:Lightning after interrupt
          AS3935IrqTriggered = 0;
        }
        else
        {
          //check if slideshow is on
          if(slideShowPlaying)
          { 
            //automatically change the screen every time the slideshowTimer value has been reached
            if( ( millis() - timeStartSlide ) > (slideshowTimer * 1000) )
            {
                  previousScreenNr = currentScreenNr;
                  currentScreenNr++;
                  if(currentScreenNr > 8){currentScreenNr = 3;}
            }
          }
          
          //if a screen has been changed, reset the slide timer
          if(currentScreenNr != previousScreenNr)
          {
            timeStartSlide = millis();
          }
          showScreen(currentScreenNr);  //0:Boot, 1:Info screen, 2:Setup, 3:eCO², 4:Temperature 5:Pressure, 6:TVOC, 7:Humidity, 8:Lightning, 81:Lightning after interrupt
        }

      
        //update lastSecond so this loop can only be run at the next second
        lastSecond = runSeconds;
  }
}
