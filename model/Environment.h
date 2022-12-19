#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "AbstractModel.h"
#include "../src/SparkFun_BME280/src/SparkFunBME280.h"

class Environment : AbstractModel {

private:
	float Humidity;
	float AmbientPressure;
	float Altitude;
	float Temperature;
	float TemperatureCompensation;
	float HumidityCompensation;
	float ReferencePressure;
	BME280 myBME280;

	void initialize(); //already from inheritance

public:
	Environment();

	void connect();   //already from inheritance

	bool isConnected; //make it accessible

	float getHumidity();

	float getAmbientPressure();

	float getAltitude();

	float getTemperature();

	float getTemperatureCompensation();

	void setTemperatureCompensation(float pTemperatureCompensation);

	float getHumidityCompensation();

	void setHumidityCompensation(float pHumidityCompensation);

	float getReferencePressure();

	void setReferencePressure(float pReferencePressure);

};

#endif
