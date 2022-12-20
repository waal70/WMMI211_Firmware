/*
 * EarthListenerController.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "EarthListenerController.h"

EarthListenerController::EarthListenerController(Environment* myEnvironment,
			EnvironmentView* myEnvironmentView, Gas* myGas,
			GasView* myGasView, Lightning* myLightning,
			LightningView* myLightningView, RealTimeClock* myRTC){
	Serial.println("In constructor for ELC");
	this->myEnvironment = myEnvironment;
	this->myEnvironmentView = myEnvironmentView;
	this->myGas = myGas;
	this->myGasView = myGasView;
	this->myLightning = myLightning;
	this->myLightningView = myLightningView;
	this->myRTC = myRTC;
}
void EarthListenerController::showSummary() {
	Serial.println("In the controller. ShowSummary was called");
	myEnvironmentView->Render(EnvironmentView::ENV_ALL);

}

