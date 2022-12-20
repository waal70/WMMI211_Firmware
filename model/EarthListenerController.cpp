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
	Serial.println("EarthListenerController being created");
	this->myEnvironment = myEnvironment;
	this->myEnvironmentView = myEnvironmentView;
	this->myGas = myGas;
	this->myGasView = myGasView;
	this->myLightning = myLightning;
	this->myLightningView = myLightningView;
	this->myRTC = myRTC;
}
void EarthListenerController::showSummary() {
	//Make sure the Gas thingy has the correct reference values;
	myGas->setReferences(myEnvironment->getTemperature(), myEnvironment->getHumidity());
	myEnvironmentView->Render(EnvironmentView::ENV_ALL);
	myGasView->Render(GasView::GAS_ALL);
	myLightningView->Render(LightningView::LIGHTNING_ALL);

}


