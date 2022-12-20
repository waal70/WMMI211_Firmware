/*
 * EnvironmentView.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "EnvironmentView.h"
#include "../bitmaps.h"
#include "../config.h"
//#include "TFTHelper.h";

EnvironmentView::EnvironmentView() {
}

EnvironmentView::EnvironmentView(const Environment &model) {
	this->model = model;
}

void EnvironmentView::setModel(const Environment &model) {
	this->model = model;
}

void EnvironmentView::printValues() {
	//prints sensor information to screen (only used in info screen)
	myScreen.tft.setFont();  //standard system font
	myScreen.tft.setTextSize(1);
	//Print values, deleting those previously written by using a black background color
	//Temperature
	myScreen.tft.setCursor(140, 125);
	int CTEMP = model.getTemperature(); //Current TEMPerature
	if (CTEMP < 0) {
		myScreen.tft.setTextColor(GREY, BLACK);
	} else if (CTEMP <= 18) {
		myScreen.tft.setTextColor(BLUE, BLACK);
	} else if ((CTEMP > 18) && (CTEMP <= 24)) {
		myScreen.tft.setTextColor(GREEN, BLACK);
	} else if ((CTEMP > 24) && (CTEMP <= 30)) {
		myScreen.tft.setTextColor(YELLOW, BLACK);
	} else if (CTEMP > 30) {
		myScreen.tft.setTextColor(RED, BLACK);
	}
	//for now, assume metric because I am Dutch :)
	//TODO: implement setting metric/imperial
	//if(MetricON)
	//{
	if (CTEMP < 10) {
		myScreen.tft.print(" ");
	}     //add leading spaces
	myScreen.tft.print(CTEMP, 1);
	myScreen.tft.print(" ");
	myScreen.tft.print((char) 247); //to print the ° symbol
	myScreen.tft.println("C  ");
	//}
	//else
	//{
	//   float TEMP_BME280_F = ((TEMP_BME280 * 9)/5 + 32);
	//   if(TEMP_BME280_F < 10){   tft.print(" ");  }     //add leading spaces
	//   tft.print(TEMP_BME280_F,1);
	//   tft.print(" ");
	//   tft.print((char)247); //to print the ° symbol
	//   tft.println("F");
	//}

	//Humidity
	myScreen.tft.setCursor(140, 200);
	int CHUM = model.getHumidity(); //Current HUMidity
	if (CHUM < 30) {
		myScreen.tft.setTextColor(RED, BLACK);
	} else if ((CHUM >= 30) && (CHUM <= 50)) {
		myScreen.tft.setTextColor(GREEN, BLACK);
	} else if (CHUM > 50) {
		myScreen.tft.setTextColor(BLUE, BLACK);
	}
	if (CHUM < 10) {
		myScreen.tft.print(" ");
	}  //add leading spaces
	myScreen.tft.print(CHUM, 1);
	myScreen.tft.println(" %");

	//Pressure
	myScreen.tft.setCursor(215, 125);
	myScreen.tft.setTextColor(GREY, BLACK);
	int CPRES = model.getAmbientPressure();
	if (CPRES < 1000) {
		myScreen.tft.print(" ");     //add leading spaces
	}
	myScreen.tft.print(CPRES, 1);
	myScreen.tft.println(" mBar");
}

void EnvironmentView::RenderAll() {
	//print icons that are relevant for this sensor

	myScreen.showbgd(127, 72, temperature_65x50, 65, 50, WHITE, BLACK);
	myScreen.showbgd(214, 72, pressure_65x50, 65, 50, WHITE, BLACK);
	myScreen.showbgd(127, 148, humidity_65x50, 65, 50, WHITE, BLACK);
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

