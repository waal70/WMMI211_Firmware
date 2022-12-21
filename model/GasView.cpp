/* GasView.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "GasView.h"

#include "bitmaps.h"


GasView::GasView(Gas* model, TFTHelper* screen) {
	this->model = model;
	this->myScreen = screen;
	Serial.println("GasView instantiated");
}
void GasView::setModel(Gas* model) {
	this->model = model;
}
void GasView::printValues() {
	myScreen->tft.setFont();  //standard system font
	myScreen->tft.setTextSize(1);

	//Print values, deleting those previously written by using a black background color
	//CO2
	myScreen->tft.setCursor(50, 125);
	int CCO2 = model->getCO2(); //Current CO2
	if (CCO2 < 800) {
		myScreen->tft.setTextColor(GREEN, BLACK);
	} else if ((CCO2 >= 800) && (CCO2 < 1000)) {
		myScreen->tft.setTextColor(BLUE, BLACK);
	} else if ((CCO2 >= 1000) && (CCO2 < 1500)) {
		myScreen->tft.setTextColor(YELLOW, BLACK);
	} else if (CCO2 >= 1500) {
		myScreen->tft.setTextColor(RED, BLACK);
	}

	if (CCO2 < 10) {
		myScreen->tft.print("   ");
	}    //add leading spaces
	else if (CCO2 < 100) {
		myScreen->tft.print("  ");
	} else if (CCO2 < 1000) {
		myScreen->tft.print(" ");
	}
	myScreen->tft.print(CCO2);
	myScreen->tft.println(" ppm");

	//TVOC
	myScreen->tft.setCursor(50, 200);
	int CTVOC = model->getTVOC(); //Current Total Volatile Organic Compound
	if (CTVOC <= 50) {
		myScreen->tft.setTextColor(GREEN, BLACK);
	} else if ((CTVOC > 50) && (CTVOC <= 150)) {
		myScreen->tft.setTextColor(YELLOW, BLACK);
	} else if (CTVOC > 150) {
		myScreen->tft.setTextColor(RED, BLACK);
	}

	if (CTVOC < 10) {
		myScreen->tft.print("   ");
	}   //add leading spaces
	else if (CTVOC < 100) {
		myScreen->tft.print("  ");
	} else if (CTVOC < 1000) {
		myScreen->tft.print(" ");
	}
	myScreen->tft.print(CTVOC);
	myScreen->tft.println(" ppb");
}
void GasView::RenderAll(){
    //print icons
    myScreen->showbgd(40, 72, eCO2_65x50, 65, 50, WHITE, BLACK);
    myScreen->showbgd(40, 148, tvoc_65x50, 65, 50, WHITE, BLACK);
    //print values from sensors
    printValues();
}

void GasView::Render(int detailRequired){
	switch (detailRequired)
	{
	case (GasView::GAS_ALL):
			RenderAll();
			break;
	case (GasView::GAS_CO2):
			break;
	case (GasView::GAS_TVOC):
			break;
	}
}

void GasView::Render(){
	Render(GasView::GAS_ALL);
}
