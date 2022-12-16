// draw a clock on the screen - requires that a real time clock chip is present. 
//
// (C) 2020 Kristian Wiklund
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
//
#include <Arduino.h>
#include "config.h"
#include <math.h>
#include <TimeLib.h>
#include "clock.h"

#include <Timezone.h>
TimeChangeRule myDST = CLOCK_DST_RULE;
TimeChangeRule mySTD = CLOCK_STD_RULE;
Timezone myTZ(myDST, mySTD);
TimeChangeRule *tcr;

#include <DS1307RTC.h>  

// graphics includes
#include "src/TFTLCD-Library/Adafruit_TFTLCD.h"        	  // Hardware-specific library for TFT screen by Adafruit
#include "src/Adafruit-GFX-Library/Fonts/FreeSans9pt7b.h"
#include "src/MCUFRIEND_kbv/MCUFRIEND_kbv.h"           	  // TFT library by David Prentice

// --- begin code from timelib example ---


void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void digitalClockDisplay(){
  // digital clock display of the time
  time_t utc = now();
  time_t local = myTZ.toLocal(utc, &tcr);
  Serial.print(hour(local));
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
}


// --- end code from timelib example ---


// return TRUE if we are able to sync to at least one clock source
bool setup_clock() {

  time_t ntptime=0;
  

  tmElements_t tm;


  // which source to use?
  // go for NTP, if available. Otherwise, use the RTC

  if(ntptime) {
    setSyncProvider(getNtpTime);
    if (timeStatus() != timeSet) { 
      Serial.println("Clock: Unable to sync with NTP - trying RTC instead");
    }
    else {
      Serial.println("Clock: NTP has set the system time");
      digitalClockDisplay();
      RTC.read(tm);
      if(RTC.chipPresent()) {
	Serial.println("Clock: Updating RTC chip time to NTP time");
	RTC.set(ntptime);
	Serial.print("Clock: RTC seconds = ");
	Serial.print(RTC.get());
      } else {
	Serial.println("Clock: RTC fail error");
      }
      return true;
    }

  }

  // if ntp failed, go for the ds1307

  Serial.println("Clock: No NTP available, using DS1307 for time base");
  RTC.read(tm);
  if(!ntptime) {
    setSyncProvider(RTC.get);
    if (timeStatus() != timeSet) {
      Serial.println("Clock: Unable to sync with the RTC - unable to keep real time!");

      if (RTC.read(tm)) {
	Serial.println("Clock: RTC read okay");
	digitalClockDisplay();
      } else {
	if (RTC.chipPresent()) {
	  Serial.println("Clock: The DS1307 is stopped.  Please run the TimeLib SetTime");
	  Serial.println("Clock example to initialize the time and begin running.");
	  Serial.println();
	} else {
	  Serial.println("Clock: DS1307 read error!  Please check the circuitry.");
	  Serial.println();
	}
      }
    }
    else {
      Serial.println("Clock: RTC has set the system time");
      return true;
    }
  }

  return false;
}
  


