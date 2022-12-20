#ifndef LIGHTNING_H
#define LIGHTNING_H

#include <stdint.h>

#include "AbstractModel.h"
#include "../src/SparkFun_AS3935/src/SparkFun_AS3935.h"

class Lightning : AbstractModel {

private:
	uint8_t DistanceToStorm;
	uint32_t LightningEnergy;
	uint8_t IndoorOutdoor;
	uint8_t LightningThreshold;
	uint8_t MaskDisturber;
	uint8_t NoiseLevel;
	uint8_t WatchdogThreshold;
	uint8_t SpikeRejection;

	SparkFun_AS3935 myAS3935; //we know it is iic
	void initialize();

public:
	Lightning();

	~Lightning();

	void connect();

	char * getLastDetectionTime();

	bool isConnected;

	static bool isTriggered;

	static unsigned long lastTriggered;

	static void interruptFunction(void);

	void clearStatistics();

	uint8_t getDistanceToStorm();

	void setDistanceToStorm(uint8_t DistanceToStorm);

	uint32_t getLightningEnergy();

	void setLightningEnergy(uint32_t LightningEnergy);

	uint8_t getIndoorOutdoor();

	void setIndoorOutdoor(uint8_t IndoorOutdoor);

	uint8_t getLightningThreshold();

	void setLightningThreshold(uint8_t LightningThreshold);

	uint8_t getMaskDisturber();

	void setMaskDisturber(uint8_t MaskDisturber);

	uint8_t getNoiseLevel();

	void setNoiseLevel(uint8_t NoiseLevel);

	uint8_t getWatchdogThreshold();

	void setWatchdogThreshold(uint8_t WatchdogThreshold);

	uint8_t getSpikeRejection();

	void setSpikeRejection(uint8_t SpikeRejection);
};

#endif
