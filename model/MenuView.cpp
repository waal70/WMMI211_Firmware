/*
 * MenuView.cpp
 *
 *  Created on: 21 dec. 2022
 *      Author: awaal
 */

#include "MenuView.h"
#include "bitmaps.h"

MenuView::MenuView(TFTHelper* screen) {
	this->myScreen = screen;
	Serial.println(F("MenuView instantiated"));

}
void MenuView::RenderAll() {
	//print icons that are relevant for this sensor
	myScreen->showbgd(103, 20, Velleman_114x36, 114, 36, GREYY, BLACK);
	//printValues();
}

void MenuView::Render(int detailRequested) {
	switch (detailRequested) {
	case (MenuView::MENU_ALL):
		RenderAll();
		break;
	case (MenuView::MENU_HEADER):
		break;
	case (MenuView::MENU_FOOTER):
		break;
	case (MenuView::MENU_SETTINGS):
		break;
	}
}
void MenuView::Render() { //No detail asked, so refer to detail render with detail = 0
	Render(MenuView::MENU_ALL);

}

