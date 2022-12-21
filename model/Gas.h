#ifndef GAS_H
#define GAS_H

#include <stdint.h>
#include "../config.h"
#include "Sensors.h"
#include "AbstractModel.h"

class Gas : AbstractModel {

private:
	uint16_t CO2;
	uint16_t TVOC;
	float ReferenceTemperature;
	float ReferenceHumidity;
	CCS811 myCCS811;

	void initialize();

public:
	Gas();

	void connect(); //already from inheritance

	bool isConnected; //make it accessible

	uint16_t getCO2();

	void setCO2(uint16_t pCO2);

	uint16_t getTVOC();

	void setTVOC(uint16_t pTVOC);

	void setReferences(float pReferenceTemperature, float pReferenceHumidity);

	bool updateSensor();

	float getReferenceTemperature();

	void setReferenceTemperature(float pReferenceTemperature);

	float getReferenceHumidity();

	void setReferenceHumidity(float pReferenceHumidity);
};

#endif
