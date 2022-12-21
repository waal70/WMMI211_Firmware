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
	RenderLogo(GREYY);
	RenderFooter();

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
void MenuView::RenderLogo(uint16_t Color){
	myScreen->showbgd(103, 20, MenuLogo_114x36, 114, 36, Color, BLACK);
}
void MenuView::RenderFooter(){
	//pauze_23x23 in case slideshow is active
      myScreen->showbgd(10, 210, play_23x23, 23, 23, GREYY, BLACK);
    //print setup button
      myScreen->showbgd(287, 210, setup_23x23, 23, 23, GREYY, BLACK);
}

void MenuView::RenderCrumbTrail() {
    //print location circles
    for(int i=0; i<6; i++)
    {
      int xPosCircle = 110 + (i * 20);
      myScreen->tft.fillCircle(xPosCircle, 221, 7, GREYY);   //fillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color)
    }
    int currentScreenNr = 4;
    //fill currentscreen circle
    int xPosCircleSelected = 110 + ((currentScreenNr - 3) * 20);
    myScreen->tft.fillCircle(xPosCircleSelected, 221, 5, BLACK);   //fillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color)
}

void MenuView::Render() { //No detail asked, so refer to detail render with detail = 0
	Render(MenuView::MENU_ALL);

}

