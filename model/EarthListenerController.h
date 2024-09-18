/*
 * EarthListenerController.h
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_EARTHLISTENERCONTROLLER_H_
#define MODEL_EARTHLISTENERCONTROLLER_H_

#include "Environment.h"
#include "EnvironmentView.h"
#include "Gas.h"
#include "GasView.h"
#include "Lightning.h"
#include "LightningView.h"
#include "RealTimeClock.h"
//#include "RealTimeClockView.h"
#include "MenuView.h"

class EarthListenerController {
public:
	EarthListenerController(Environment *myEnvironment,
			EnvironmentView *myEnvironmentView, Gas *myGas, GasView *myGasView,
			Lightning *myLightning, LightningView *myLightningView,
			RealTimeClock *myRTC, Menu *myMenu, MenuView *myMenuView);
	void showSummary();
	void processTouch(int Xpos, int Ypos);
	void refresh();
	enum CURRENTSCREEN {
		OVERVIEW = 1,
		TEMPERATURE = 2,
		PRESSURE = 4,
		ECO2 = 8,
		TVOC = 16,
		HUMIDITY = 32,
		LIGHTNING = 64,
		SETTINGS = 128
	};
private:
	//Here the sensor pairs are declared:
	//BME280:
	Environment *myEnvironment;
	EnvironmentView *myEnvironmentView;
	//CCS811:
	Gas *myGas;
	GasView *myGasView;
	Lightning *myLightning;
	LightningView *myLightningView;
	RealTimeClock *myRTC;
	Menu *myMenu;
	MenuView *myMenuView;

	int PreviousScreen;
	int CurrentScreen;
	int ySelect;
	int xSelect;
	//RealTimeClockView myRTCView;
	void showSettings();
};

#endif /* MODEL_EARTHLISTENERCONTROLLER_H_ */
