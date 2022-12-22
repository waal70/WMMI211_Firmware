/*
 * MenuView.cpp
 *
 *  Created on: 21 dec. 2022
 *      Author: awaal
 */

#include "MenuView.h"
#include "bitmaps.h"

MenuView::MenuView(Menu* model, TFTHelper* screen) {
	this->myScreen = screen;
	this->model = model;
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
			RenderSettings();
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
void MenuView::RenderSettings() {

	//global font & color
	        myScreen->tft.setFont();  //standard system font
	        myScreen->tft.setTextSize(1);
	        myScreen->tft.setTextColor(GREYY,BLACK);

	        //buzzer
	        myScreen->tft.setCursor(50, 125);
	        if(model->getBuzzerON())
	        {
	        	myScreen->showbgd(40, 72, buzzer_on_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Buzzer ON ");
	        }
	        else
	        {
	        	myScreen->showbgd(40, 72, buzzer_off_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Buzzer OFF");
	        }

	        //metric/imperial
	        myScreen->tft.setCursor(140, 125);
	        if(model->getMetric())
	        {
	        	myScreen->showbgd(127, 72, metrical_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Metrical");
	        }
	        else
	        {
	        	myScreen->showbgd(127, 72, imperial_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Imperial");
	        }

	        //slideshow timer
	        myScreen->showbgd(214, 72, slideshow_65x50, 65, 50, GREYY, BLACK);
	        myScreen->tft.setCursor(215, 125);
	        myScreen->tft.print("Timer: "); myScreen->tft.print(model->getSlideshowTimer()); if(model->getSlideshowTimer() < 10){myScreen->tft.print(" ");}

	        //lightning sensitivity
	        myScreen->tft.setCursor(40, 200);
	        int globalSense = model->getSensitivity();
	        if(globalSense == 1)
	        {
	        	myScreen->showbgd(40, 148, lightning_low_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Sense Low   ");
	        }
	        else if(globalSense == 2)
	        {
	        	myScreen->showbgd(40, 148, lightning_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Sense Medium");
	        }
	        else if(globalSense == 3)
	        {
	        	myScreen->showbgd(40, 148, lightning_high_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Sense High  ");
	        }
	        else
	        {
	        	myScreen->showbgd(40, 148, lightning_65x50, 65, 50, RED, BLACK);
	        	myScreen->tft.print("Sense Error!");
	        }

	        //indoor/outdoor mode
	        myScreen->tft.setCursor(135, 200);
	        if(model->getOutdoor())
	        {
	        	myScreen->showbgd(127, 148, outdoor_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Outdoor");
	        }
	        else
	        {
	        	myScreen->showbgd(127, 148, indoor_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print(" Indoor");
	        }

	        //chip interface AS3935
	        myScreen->tft.setCursor(215, 200);
	        if(model->getAS3935SPI())
	        {
	        	myScreen->showbgd(214, 148, SPI_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Interface");
	        }
	        else
	        {
	        	myScreen->showbgd(214, 148, IIC_65x50, 65, 50, GREYY, BLACK);
	        	myScreen->tft.print("Interface");
	        }

	        //control LED
	        //controlLED('0'); //off
	        //control Logo
	        //controlLogo(GREYY);

}

