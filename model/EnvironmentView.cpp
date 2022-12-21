/*
 * EnvironmentView.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "EnvironmentView.h"
#include "../config.h"
#include "bitmaps.h"
//#include "TFTHelper.h";

EnvironmentView::EnvironmentView(Environment *model, TFTHelper *screen) {
	this->model = model;
	this->myScreen = screen;
	this->isMetric = true;
	Serial.println("EnvironmentView instantiated");
}

void EnvironmentView::setModel(Environment *model) {
	this->model = model;
}

void EnvironmentView::printValues() {

	//TODO: change to use sprintf
	//prints sensor information to screen (only used in info screen)
	myScreen->tft.setFont();  //standard system font
	myScreen->tft.setTextSize(1);
	//Print values, deleting those previously written by using a black background color
	//Temperature
	myScreen->tft.setCursor(140, 125);
	float CTEMP = model->getTemperature(); //Current TEMPerature
	if (CTEMP < 0) {
		myScreen->tft.setTextColor(GREY, BLACK);
	} else if (CTEMP <= 18) {
		myScreen->tft.setTextColor(BLUE, BLACK);
	} else if ((CTEMP > 18) && (CTEMP <= 24)) {
		myScreen->tft.setTextColor(GREEN, BLACK);
	} else if ((CTEMP > 24) && (CTEMP <= 30)) {
		myScreen->tft.setTextColor(YELLOW, BLACK);
	} else if (CTEMP > 30) {
		myScreen->tft.setTextColor(RED, BLACK);
	}
	//for now, assume metric because I am Dutch :)
	//TODO: implement setting metric/imperial
	//if(MetricON)
	//{
	char buffer[15] = { 0 }; //it can hold -10.2 *C - "%3s", string
	//The way in which AVR handles floats and doubles is a bit awkward
	// we use the dtostrf to pre-format the float value:
	char floatbuffer[6] = { 0 };
	char degrees = (char) 247;
	if (isMetric) {
		dtostrf(CTEMP, 5, 1, floatbuffer);
		sprintf(buffer, "%s %cC", floatbuffer, degrees);
	} else {
		float CTEMP_F = ((CTEMP * 9) / 5 + 32);
		dtostrf(CTEMP_F, 5, 1, floatbuffer);
		sprintf(buffer, "%s %cF", floatbuffer, degrees);
	}
	myScreen->tft.println(buffer);

	//Humidity
	myScreen->tft.setCursor(140, 200);
	float CHUM = model->getHumidity(); //Current HUMidity
	if (CHUM < 30) {
		myScreen->tft.setTextColor(RED, BLACK);
	} else if ((CHUM >= 30) && (CHUM <= 50)) {
		myScreen->tft.setTextColor(GREEN, BLACK);
	} else if (CHUM > 50) {
		myScreen->tft.setTextColor(BLUE, BLACK);
	}
	dtostrf(CHUM, 3, 1, floatbuffer); //100.0
	sprintf(buffer, "%s %", floatbuffer);
	myScreen->tft.println(buffer);

	//Pressure
	myScreen->tft.setCursor(215, 125);
	myScreen->tft.setTextColor(GREY, BLACK);
	int CPRES = model->getAmbientPressure();
	dtostrf(CPRES, 6, 1, floatbuffer); //100.0
	sprintf(buffer, "%s mbar", floatbuffer);
	myScreen->tft.println(buffer);
}

void EnvironmentView::RenderAll() {
	//print icons that are relevant for this sensor
	myScreen->showbgd(127, 72, temperature_65x50, 65, 50, WHITE, BLACK);
	myScreen->showbgd(214, 72, pressure_65x50, 65, 50, WHITE, BLACK);
	myScreen->showbgd(127, 148, humidity_65x50, 65, 50, WHITE, BLACK);
	printValues();
}

void EnvironmentView::Render(int detailRequested) {
	switch (detailRequested) {
	case (EnvironmentView::ENV_ALL):
		RenderAll();
		break;
	case (EnvironmentView::ENV_HUMIDITY):
		break;
	case (EnvironmentView::ENV_TEMPERATURE):
		break;
	case (EnvironmentView::ENV_PRESSURE):
		break;
	}
}

void EnvironmentView::Render() { //No detail asked, so refer to detail render with detail = 0
	Render(EnvironmentView::ENV_ALL);

}

