/*
 * EarthListenerController.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "EarthListenerController.h"

// This controller knows a couple of screens:
// Summary (showSummary): all sensors on screen
// Temperature (showTemperature): detail for temperature
// Pressure (showPressure): detail for barometric pressure
// Humidity (showHumidity): detail for relative humidity
// Lightning (showLightning): detail for Lightning. Also EMERGENCY.
// eCO2 (showCO2): detail for equivalent CO2 measurement
// TVOC (showTVOC): detail for Total Volatile Organic Compound
// Settings (showSettings): configuration screen for Earth Listener

EarthListenerController::EarthListenerController(Environment* myEnvironment,
			EnvironmentView* myEnvironmentView, Gas* myGas,
			GasView* myGasView, Lightning* myLightning,
			LightningView* myLightningView, RealTimeClock* myRTC, MenuView* myMenuView, bool isMetric){
	Serial.println("EarthListenerController being created");
	this->myEnvironment = myEnvironment;
	this->myEnvironmentView = myEnvironmentView;
	this->myGas = myGas;
	this->myGasView = myGasView;
	this->myLightning = myLightning;
	this->myLightningView = myLightningView;
	this->myRTC = myRTC;
	this->myMenuView = myMenuView;
	//now pass metric system or idiot system:
	this->myEnvironmentView->isMetric = isMetric;
	this->myLightningView->isMetric = isMetric;
}
void EarthListenerController::showSummary() {
	//Make sure the Gas thingy has the correct reference values;
	myGas->setReferences(myEnvironment->getTemperature(), myEnvironment->getHumidity());
	myEnvironmentView->Render(EnvironmentView::ENV_ALL);
	myGasView->Render(GasView::GAS_ALL);
	myLightningView->Render(LightningView::LIGHTNING_ALL);
	myMenuView->Render(MenuView::MENU_ALL);

}


