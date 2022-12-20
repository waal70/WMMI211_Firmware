#include "Environment.h"

#include "Sensors.h"
#include "../config.h"

//forward method declaration:
void Environment::connect();

Environment::Environment(){ //default constructor
	//First, make sure we instantiate a sensor BME280
	Serial.println("***BME280 Sensor feedback***");
	//myBME280 = BME280();
	//now: set default values;
	Humidity = 0;
	AmbientPressure = 0;
	Altitude = 0;
	Temperature = 0;
	TemperatureCompensation = TEMP_comp;
	HumidityCompensation = HUMI_comp;
	ReferencePressure = 0;
	isConnected = false;
	connect();
}

void Environment::initialize() {

	myBME280.setI2CAddress(BME280_ADDR);
	if (!myBME280.beginI2C()) // the call to beginI2C is needed to start communicating!
	{
		Serial.println("BME280 Sensor connection failed!");
		isConnected = false;
	}
	else {
		Serial.println("BME280 Sensor connection successful!");
		myBME280.setFilter(1); //0 to 4 is valid. Filter coefficient. See 3.4.4
		myBME280.setStandbyTime(0); //0 to 7 valid. Time between readings. See table 27.
		myBME280.setTempOverSample(1); //0 to 16 are valid. 0 disables temp sensing. See table 24.
		myBME280.setPressureOverSample(1); //0 to 16 are valid. 0 disables pressure sensing. See table 23.
		myBME280.setHumidityOverSample(1); //0 to 16 are valid. 0 disables humidity sensing. See table 19.
		myBME280.setMode(MODE_NORMAL); //MODE_SLEEP, MODE_FORCED, MODE_NORMAL is valid. See 3.3
		myBME280.setReferencePressure(SEALEVELPRESSURE); //Adjust the sea level pressure used for altitude calculations. This should be a variable, not fixed!
		//If you do not set the correct sea level pressure for your location FOR THE CURRENT DAY it will not be able to calculate the altitude accurately!
		//Barometric pressure at sea level changes daily based on the weather!
		isConnected = true;
	}
}

void Environment::connect()
{
	//first, call initialize:
	if (!isConnected) {
		this->initialize();
	}
	//assume we're connected now
	//now populate the values
	Humidity = myBME280.readFloatHumidity();
	Humidity += getHumidityCompensation();
	Temperature = myBME280.readTempC();
	Temperature += getTemperatureCompensation();

	//NOTE: Returns pressure in Pa. Divide by 100 to get hPa (=mbar)
	AmbientPressure = myBME280.readFloatPressure();
	AmbientPressure = AmbientPressure / 100;

}

//returns Humidity with three decimals: 46.333 %RH
float Environment::getHumidity() {
	connect();
	return Humidity;

}

float Environment::getAmbientPressure() {
	//Update all sensor values:
	connect();
	return AmbientPressure;

}

float Environment::getAltitude() {
	connect();
	return Altitude;

}

float Environment::getTemperature() {
	connect();
	return Temperature;

}

float Environment::getTemperatureCompensation() {
	return TemperatureCompensation;

}

void Environment::setTemperatureCompensation(float pTemperatureCompensation) {
	TemperatureCompensation = pTemperatureCompensation;

}

float Environment::getHumidityCompensation() {
	return HumidityCompensation;

}

void Environment::setHumidityCompensation(float pHumidityCompensation) {
	HumidityCompensation = pHumidityCompensation;

}

float Environment::getReferencePressure() {
	return ReferencePressure;

}

void Environment::setReferencePressure(float pReferencePressure) {
	ReferencePressure = pReferencePressure;

}
