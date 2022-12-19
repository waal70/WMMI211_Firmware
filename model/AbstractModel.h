#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include "DataChangeHandler.h"

class AbstractModel {

private:
	AbstractModel * mySensor;
	DataChangeHandler event;

public:
	char* getDisplay();
	bool isConnected = false;
	void connect();

private:
	void initialize();

public:
	void registerDataChangeHandler(DataChangeHandler handler);
};

#endif
