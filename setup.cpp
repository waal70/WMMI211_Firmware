/*
 * setup.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */
/***************************************/
/* ----------- SETUP CODE ------------ */
/***************************************/

#include "functions.h"
#include "globals.h"
#include <EEPROM.h>

void setup() {
	/* --- Start serial & print sketch info --- */
	Serial.begin(9600);
	Serial.println(F("----------------------------------"));
	Serial.print(F("Arduino is running Sketch: "));
	Serial.println(__FILE__);
	Serial.print(F("Compiled on: "));
	Serial.print(__DATE__);
	Serial.print(F(" at "));
	Serial.println(__TIME__);
	Serial.print(F("Free SRAM is reported at: "));
	Serial.println(freeMemory());
	Serial.println(F("----------------------------------"));
	Serial.println();

	//pinMode(touchPin, OUTPUT);
	LEDenabled = true;
	/* --- RGB LED pins --- */
	if (LEDenabled) //set pins for RGB LED & set everything low => black, but only if LEDenabled = true
	{
		pinMode(LEDgnd, OUTPUT);
		digitalWrite(LEDgnd, LOW);
		pinMode(LEDg, OUTPUT);
		digitalWrite(LEDg, LOW);
		pinMode(LEDr, OUTPUT);
		digitalWrite(LEDr, LOW);
		pinMode(LEDb, OUTPUT);
		digitalWrite(LEDb, LOW);
	}
	/* --- DIGITAL outputs --- */
	pinMode(GreenOutPin, OUTPUT);
	digitalWrite(GreenOutPin, LOW);
	pinMode(YellowOutPin, OUTPUT);
	digitalWrite(YellowOutPin, LOW);
	pinMode(RedOutPin, OUTPUT);
	digitalWrite(RedOutPin, LOW);

	/* --- Check first boot & if true, set values to default settings --- */
	if (EEPROM.read(firstBoot_EEPROMaddr)) {
		//it's the first time the EarthListener has booted! Set default values
		EEPROM.write(AS3935_SPI_EEPROMaddr, false); //set AS3935 interface to I2C
		EEPROM.write(AS3935_outdoor_EEPROMaddr, false); //set AS3935 to indoor use
		EEPROM.write(globalSense_EEPROMaddr, 2); //set AS3935 sensitivity to 2 (medium)
		EEPROM.write(Buzzer_EEPROMaddr, true);        //set buzzer on
		EEPROM.write(MetricON_EEPROMaddr, true);      //set values to metric
		EEPROM.write(firstBoot_EEPROMaddr, false); //set firstboot on false, this will not be run again
	}

	/* --- set buzzer pin & read value from EEPROM --- */
	pinMode(BuzzerPin, OUTPUT);
	digitalWrite(BuzzerPin, LOW);

	/* --- SD card feedback --- */
	// make sure that the default chip select pin is set to
	// output, even if you don't use it:
	pinMode(SS, OUTPUT);

	//Initialize all sensors, views, helpers and controllers
	TFTHelper *myScreen = TFTHelper::GetInstance();
	Menu *myMenu = Menu::GetInstance();

	//myScreen->tft.setRotation(1);
	myGas = new Gas();
	myLightning = new Lightning();
	myEnv = new Environment();
	myRTC = new RealTimeClock();

	myGasView = new GasView(myGas, myScreen);
	myLightningView = new LightningView(myLightning, myScreen);
	myEnvView = new EnvironmentView(myEnv, myScreen);
	myMenuView = new MenuView(myMenu, myScreen);
	elc = new EarthListenerController(myEnv, myEnvView, myGas, myGasView,
			myLightning, myLightningView, myRTC, myMenu, myMenuView);
	//END Initialize all sensors, views, helpers and controllers

	// For better pressure precision, we need to know the resistance
	// between X+ and X- Use any multimeter to read it
	// For the one we're using, its 320 ohms across the X plate

	/* --- end of boot, wait for a bit, then show info screen --- */
	delay(2000);

	//Although done in initialization, make doubly sure the lightning sensor is in a
	// non-tripped state:
	myLightning->isTriggered = false;
	myLightning->lastTriggered = 0;

	//show the info-screen:
	elc->showSummary();
	Serial.print(F("setup() complete: SRAM is now: "));
	Serial.println(freeMemory());
	Serial.println(F("***End of setup, starting loop***"));
	Serial.println();

	//let's test the LED:
	controlLed('R');
	delay(1000);
	controlLed('G');
	delay(1000);
	controlLed('Y');
	delay(1000);
	controlLed('O');
	delay(1000);
	controlLed('W');
	delay(1000);
	controlLed('B');
	delay(1000);
	controlLed('X');
	delay(1000);

}

