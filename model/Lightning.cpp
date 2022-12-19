#include "Lightning.h"

#include "../config.h"
#include "Sensors.h"

bool Lightning::isTriggered = false; //needed for static variables

Lightning::Lightning() : myAS3935(AS3935_ADD)  {
	Serial.println("***AS3935 Sensor feedback***");
	MaskDisturber = 1;
	IndoorOutdoor = OUTDOOR; // default to outdoor
	LightningEnergy = 0;
	NoiseLevel = 0;
	DistanceToStorm = 0;
	SpikeRejection = 0;
	LightningThreshold = 0;
	isConnected = false;
	//this->isTriggered = false;
	WatchdogThreshold = 0;
}

Lightning::~Lightning(){
	detachInterrupt(digitalPinToInterrupt(AS3935_IRQPIN));
}
static void Lightning::interruptFunction () {
	isTriggered = true;
}

void Lightning::initialize() {

	Wire.begin(); // IIC needs wire to begin before sensor
	   if( !myAS3935.begin() ){ // Initialize the sensor.
	      isConnected = false;
	      Serial.println("AS3935 Sensor connection failed!");
	    }
	   else {
		   isConnected = true;
		   Serial.println("AS3935 Sensor connection successful!");
		   myAS3935.resetSettings();
		   delay(500);
		   //Check indoor/outdoor:
		   myAS3935.setIndoorOutdoor(IndoorOutdoor);
		   myAS3935.maskDisturber(MaskDisturber);
		   myAS3935.setNoiseLevel(NoiseLevel);
		   myAS3935.watchdogThreshold(WatchdogThreshold);
		   myAS3935.spikeRejection(SpikeRejection);
		   myAS3935.lightningThreshold(LightningThreshold);
		   myAS3935.clearStatistics(true);

		   Serial.println("AS3935 sensor has been set!");

		   pinMode(AS3935_IRQPIN, INPUT);   // See http://arduino.cc/en/Tutorial/DigitalPins
		   attachInterrupt(digitalPinToInterrupt(AS3935_IRQPIN), interruptFunction, CHANGE);
	   }

}

void Lightning::connect () {
	//first, call initialize:
			if (!isConnected) {
				this->initialize();
			}
			//assume we're connected now
			//now populate the values
}

void Lightning::clearStatistics() {
}

uint8_t Lightning::getDistanceToStorm() {
	return DistanceToStorm;
}

void Lightning::setDistanceToStorm(uint8_t DistanceToStorm) {
}

uint32_t Lightning::getLightningEnergy() {
	return LightningEnergy;
}

void Lightning::setLightningEnergy(uint32_t LightningEnergy) {
}

uint8_t Lightning::getIndoorOutdoor() {
	return IndoorOutdoor;
}

void Lightning::setIndoorOutdoor(uint8_t IndoorOutdoor) {
}

uint8_t Lightning::getLightningThreshold() {
	return LightningThreshold;
}

void Lightning::setLightningThreshold(uint8_t LightningThreshold) {
}

uint8_t Lightning::getMaskDisturber() {
	return MaskDisturber;
}

void Lightning::setMaskDisturber(uint8_t MaskDisturber) {
}

uint8_t Lightning::getNoiseLevel() {
	return NoiseLevel;
}

void Lightning::setNoiseLevel(uint8_t NoiseLevel) {
}

uint8_t Lightning::getWatchdogThreshold() {
	return WatchdogThreshold;
}

void Lightning::setWatchdogThreshold(uint8_t WatchdogThreshold) {
}

uint8_t Lightning::getSpikeRejection() {
	return SpikeRejection;
}

void Lightning::setSpikeRejection(uint8_t SpikeRejection) {
}
