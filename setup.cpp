/*
 * setup.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "functions.h"
#include <EEPROM.h>

void setup() {
	/* --- Start serial & print sketch info --- */
	Serial.begin(9600);
	Serial.println("----------------------------------");
	Serial.print("Arduino is running Sketch: ");
	Serial.println(__FILE__);
	Serial.print("Compiled on: ");
	Serial.print(__DATE__);
	Serial.print(" at ");
	Serial.println(__TIME__);
	Serial.println("----------------------------------");
	Serial.println();

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

	//read value from EEPROM if Temp is in °F or °C and lightning units are in km or mi
	MetricON = EEPROM.read(MetricON_EEPROMaddr); //read metric or imperial state from memory. If not set, this will be true, since all EEPROM addresses are 0xFF by default

	/* --- set buzzer pin & read value from EEPROM --- */
	BuzzerEnabled = EEPROM.read(Buzzer_EEPROMaddr);
	pinMode(BuzzerPin, OUTPUT);
	digitalWrite(BuzzerPin, LOW);

	/* --- SD card feedback --- */
	//Serial.println("***SD card feedback***");
	//Serial.print("Initializing...");
	// make sure that the default chip select pin is set to
	// output, even if you don't use it:
	pinMode(SS, OUTPUT);

	/* --- check if RTC is present --- */

	//myRTC.connect();
	//myRTC.getDayOfWeek();
	/* --- end of boot, wait 2 secs & set interrupt state, then show info screen --- */
	TFTHelper* myScreen = TFTHelper::GetInstance();
	myGas = new Gas();
	myLightning = new Lightning();
	myEnv = new Environment();
	myRTC = new RealTimeClock();

	myGasView = new GasView(myGas,myScreen);
	myLightningView = new LightningView(myLightning,myScreen);
	myEnvView = new EnvironmentView(myEnv, myScreen);

	elc=new EarthListenerController(myEnv, myEnvView, myGas, myGasView, myLightning, myLightningView, myRTC);
	delay(2000);
	myLightning->isTriggered = false;
	slideShowPlaying = 0;   //we always start without slide show
	elc->showSummary();
	Serial.println("***End of setup, starting loop***");
	Serial.println();

}




