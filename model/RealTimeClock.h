#ifndef REALTIMECLOCK_H
#define REALTIMECLOCK_H

#include "AbstractModel.h"
#include "../src/ds1302/DS1302.h" //The RTC

class RealTimeClock: public AbstractModel {

private:
	void initialize();
	char * dayAsString(Time t);
	DS1302 myRTC;
public:
	RealTimeClock();
	void connect();
	bool isConnected;

	char* getTime();
	char* getDate();
	char* getDayOfWeek();

};

#endif

