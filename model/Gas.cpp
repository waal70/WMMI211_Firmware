#include "Gas.h"

Gas::Gas() : myCCS811(CCS811_ADDR) //CCS811 creation requires this address
{
	Serial.println("***CCS811 Sensor feedback***");
	CO2 = 0;
	TVOC = 0;
	ReferenceTemperature = 0;
	ReferenceHumidity = 0;
	isConnected = false;
	connect();
}

void Gas::initialize() {
	CCS811Core::status returnCode;
	returnCode = myCCS811.begin();
	if (returnCode != CCS811Core::SENSOR_SUCCESS) {
		Serial.println("CCS811 Sensor connection failed!");
		isConnected = false;
	}
	else {
		Serial.println("CCS811 Sensor connection successful!");
		isConnected = true;
	}
}

void Gas::connect() {
	//first, call initialize:
		if (!isConnected) {
			this->initialize();
		}
		//assume we're connected now
		//now populate the values
		CO2 = myCCS811.getCO2();
		TVOC = myCCS811.getTVOC();
}

void Gas::setReferences(float pReferenceTemperature, float pReferenceHumidity) {
	//convenience method to set reference values
	setReferenceTemperature(pReferenceTemperature);
	setReferenceHumidity(pReferenceHumidity);
}

bool Gas::updateSensor() {
	myCCS811.setEnvironmentalData(ReferenceHumidity, ReferenceTemperature);
	myCCS811.readAlgorithmResults();
	if (myCCS811.checkForStatusError())
	{
		//error no data available
		Serial.println("ERROR; CCS811 indicates no data available!");
		return false;
	}
	else if (myCCS811.dataAvailable())
	{
		Serial.println("CCS811 indicates fresh data!");
	}
	if ((ReferenceTemperature == 0) && (ReferenceHumidity == 0))
	{Serial.println("WARNING: CCS811 values request without setting reference!");}
	return true;
}

uint16_t Gas::getCO2() {
	updateSensor();
	CO2 = myCCS811.getCO2();
	return CO2;
}

void Gas::setCO2(uint16_t pCO2) {
	CO2 = pCO2;
}

uint16_t Gas::getTVOC() {
	updateSensor();
	TVOC = myCCS811.getTVOC();
	return TVOC;
}

void Gas::setTVOC(uint16_t pTVOC) {
	TVOC = pTVOC;
}

float Gas::getReferenceTemperature() {
	return ReferenceTemperature;
}

void Gas::setReferenceTemperature(float pReferenceTemperature) {
	ReferenceTemperature = pReferenceTemperature;
}

float Gas::getReferenceHumidity() {
	return ReferenceHumidity;
}

void Gas::setReferenceHumidity(float pReferenceHumidity) {
	ReferenceHumidity = pReferenceHumidity;
}

