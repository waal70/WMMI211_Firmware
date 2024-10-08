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

// Contains utility functions:
#include "functions.h"

// Contains globally used objects:
#include "globals.h"

/***************************************/
/* ----------- LOOP CODE ------------ */
/***************************************/
void loop() {

	//timing: get time since boot: will write to global vars
	getTimeSinceBoot();

	//get touch input (but only after XXX ms after last touchscreen event!)
	if((millis() - touchedTime) > touchTimeout)
	{
		if (touchedMe()) {
			touchedTime = millis();
			elc->processTouch(Xpos, Ypos);
		}
	}

	//only do next code each second
	if (runSeconds != lastSecond) {
		//increase the secondCounter
		elc->refresh();
		//Serial.print("*");
		secondCounter++;
		/****** poll sensors & update vars + log to SD *****/
		// make a string for assembling the data to log on the SD card & add the current time:
		/****show screens****/
		//interrupt from lightning sensor! -> show lightning screen, otherwise show info screen
		//we only do this if AS3935_bootOK is true (otherwise noise from sensor)
		//check if slideshow is on
		if (myMenu->getSlideshowRunning()) {
			//automatically change the screen every time the slideshowTimer value has been reached
			if ((millis() - timeStartSlide) > (myMenu->getSlideshowTimer() * 1000)) {
				previousScreenNr = currentScreenNr;
				currentScreenNr++;
				if (currentScreenNr > 8) {
					currentScreenNr = 3;
				}
			}
		}

		//if a screen has been changed, reset the slide timer
		if (currentScreenNr != previousScreenNr) {
			timeStartSlide = millis();
		}
		//showScreen(currentScreenNr); //0:Boot, 1:Info screen, 2:Setup, 3:eCO², 4:Temperature 5:Pressure, 6:TVOC, 7:Humidity, 8:Lightning, 81:Lightning after interrupt
	}

	//update lastSecond so this loop can only be run at the next second
	lastSecond = runSeconds;
}

