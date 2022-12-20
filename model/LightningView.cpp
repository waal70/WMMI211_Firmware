/*
 * LightningView.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "LightningView.h"
#include "../bitmaps.h"
#include "../config.h"

LightningView::LightningView(Lightning* model, TFTHelper* screen) {
	this->model = model;
	this->myScreen = screen;
}
void LightningView::setModel(Lightning* model) {
	this->model = model;
}

void LightningView::printValues() {
	//print last detection time lightning sensor
	myScreen->tft.setCursor(210, 200);
	Serial.println("Call to LastDetectionTime yielded: ");
	Serial.println(model->getLastDetectionTime());
	Serial.println();
	myScreen->tft.print(model->getLastDetectionTime());
}
void LightningView::RenderAll() {
	//print icons
	myScreen->showbgd(40, 72, eCO2_65x50, 65, 50, WHITE, BLACK);
	myScreen->showbgd(40, 148, tvoc_65x50, 65, 50, WHITE, BLACK);
	//print values from sensors
	printValues();
}

void LightningView::Render(int detailRequired) {
	switch (detailRequired) {
	case (LightningView::LIGHTNING_ALL):
		RenderAll();
		break;
	case (LightningView::LIGHTNING_DIST):
		break;
	case (LightningView::LIGHTNING_INTENS):
		break;
	}
}

void LightningView::Render() {
	Render(LightningView::LIGHTNING_ALL);
}

