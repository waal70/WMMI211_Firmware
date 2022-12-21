/*
 * EnvironmentView.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "EnvironmentView.h"
#include "bitmaps.h"

EnvironmentView::EnvironmentView(Environment *model, TFTHelper *screen) {
	this->model = model;
	this->myScreen = screen;
	this->isMetric = true;
	Serial.println(F("EnvironmentView instantiated"));
}

void EnvironmentView::setModel(Environment *model) {
	this->model = model;
}
void EnvironmentView::clear(){
	  myScreen->tft.fillRect(10,60,310,180,BLACK);
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
	//cap humidity to 100%:
	if (CHUM > 100) CHUM = 100;
	dtostrf(CHUM, 3, 1, floatbuffer); //100.0
	sprintf(buffer, "%s %%", floatbuffer);
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
			RenderTemperature();
		break;
	case (EnvironmentView::ENV_PRESSURE):
		break;
	}
}

void EnvironmentView::RenderTemperature(){
    //print value, icon & update LED
	myScreen->tft.setFont();  //standard system font
	myScreen->tft.setTextSize(3);
	myScreen->tft.setCursor(140, 120);
	float CTEMP = model->getTemperature();
     if(CTEMP < 0)
     {
    	 myScreen->tft.setTextColor(GREY,BLACK);
    	 myScreen->showbgd(10, 75, temperature_100x77, 100, 77, GREY, BLACK);
       //controlLED('W');
       //controlLogo(GREY);
     }
     else if (CTEMP <= 18)
     {
    	 myScreen->tft.setTextColor(BLUE,BLACK);
    	 myScreen->showbgd(10, 75, temperature_100x77, 100, 77, BLUE, BLACK);
       //controlLED('B');
       //controlLogo(BLUE);
     }
     else if ((CTEMP > 18) && (CTEMP <= 24))
     {
    	 myScreen->tft.setTextColor(GREEN,BLACK);
    	 myScreen->showbgd(10, 75, temperature_100x77, 100, 77, GREEN, BLACK);
       //controlLED('G');
       //controlLogo(GREEN);
     }
     else if ((CTEMP > 24) && (CTEMP <= 30))
     {
    	 myScreen->tft.setTextColor(YELLOW,BLACK);
    	 myScreen->showbgd(10, 75, temperature_100x77, 100, 77, YELLOW, BLACK);
       //controlLED('Y');
       //controlLogo(YELLOW);
     }
     else if (CTEMP > 30)
     {
    	 myScreen->tft.setTextColor(RED,BLACK);
    	 myScreen->showbgd(10, 75, temperature_100x77, 100, 77, RED, BLACK);
       //controlLED('R');
       //controlLogo(RED);
     }

     if(isMetric)
     {
        if(CTEMP < 10){   myScreen->tft.print(" ");  }     //add leading spaces
        myScreen->tft.print(CTEMP,1);
        myScreen->tft.print(" ");
        myScreen->tft.print((char)247); //to print the ° symbol
        myScreen->tft.println("C");
     }
     else
     {
        float CTEMP_F = ((CTEMP * 9)/5 + 32);
        if(CTEMP < 10){   myScreen->tft.print(" ");  }     //add leading spaces
        myScreen->tft.print(CTEMP_F,1);
        myScreen->tft.print(" ");
        myScreen->tft.print((char)247); //to print the ° symbol
        myScreen->tft.println("F");
     }


     /*
     //print scale with fillRect(startX, startY, width, height, color)
     tft.fillRect( 10, 175, 33, 18, GREY);
     tft.fillRect( 44, 175,122, 18, BLUE);
     tft.fillRect(167, 175, 39, 18, GREEN);
     tft.fillRect(207, 175, 39, 18, YELLOW);
     tft.fillRect(247, 175, 63, 18, RED);
     */

     //print scale from bitmap file - file is 1 line, so print it 18 times
     for( int zz = 0; zz < 18; zz++)
     {
    	 myScreen->tft.setAddrWindow(startXimg, startYimg + zz, startXimg + widthImg - 1, startYimg + zz + heightImg - 1);
    	 myScreen->tft.pushColors((const uint8_t*)temp_graph_300x1, widthImg * heightImg, 1, false);
     }
     myScreen->tft.fillRect( 10,193,300, 6, BLACK);  //erase the bottom under the scale (from previous indicator)
     //draw indicator with drawLine(startX, startY, endX, endY, color)
     //calcVal = ( ( (TEMP_BME280+5) / (40+5) ) * 300 ) + 10;
     int calcVal = 0;
     calcVal = CTEMP + 5;
     calcVal = calcVal / (40+5);
     calcVal = calcVal * 300;
     calcVal = calcVal + 10;
     int Xindic;
     Xindic = (int) calcVal;
     if(Xindic < 10){Xindic = 10;}
     else if(Xindic > 300){Xindic = 300;}
     myScreen->tft.drawLine(Xindic, 175, Xindic, 198, WHITE);
     //print values of scale
     myScreen->tft.setTextSize(1);

     if(isMetric)
     {
    	 myScreen->tft.setCursor(10, 165); myScreen->tft.setTextColor(GREY,BLACK); myScreen->tft.print("-5");
    	 myScreen->tft.setCursor(45, 165); myScreen->tft.setTextColor(BLUE,BLACK); myScreen->tft.print("0");
    	 myScreen->tft.setCursor(167, 165); myScreen->tft.setTextColor(GREEN,BLACK); myScreen->tft.print("19");
    	 myScreen->tft.setCursor(207, 165); myScreen->tft.setTextColor(YELLOW,BLACK); myScreen->tft.print("25");
    	 myScreen->tft.setCursor(248, 165); myScreen->tft.setTextColor(RED,BLACK); myScreen->tft.print("31");
    	 myScreen->tft.setCursor(295, 165); myScreen->tft.setTextColor(RED,BLACK); myScreen->tft.print("40");
     }
     else
     {
    	 myScreen->tft.setCursor(10, 165); myScreen->tft.setTextColor(GREY,BLACK); myScreen->tft.print("23");
    	 myScreen->tft.setCursor(45, 165); myScreen->tft.setTextColor(BLUE,BLACK); myScreen->tft.print("32");
    	 myScreen->tft.setCursor(167, 165); myScreen->tft.setTextColor(GREEN,BLACK); myScreen->tft.print("66");
    	 myScreen->tft.setCursor(207, 165); myScreen->tft.setTextColor(YELLOW,BLACK); myScreen->tft.print("77");
    	 myScreen->tft.setCursor(248, 165); myScreen->tft.setTextColor(RED,BLACK); myScreen->tft.print("88");
    	 myScreen->tft.setCursor(295, 165); myScreen->tft.setTextColor(RED,BLACK); myScreen->tft.print("104");
     }

}

void EnvironmentView::Render() { //No detail asked, so refer to detail render with detail = 0
	Render(EnvironmentView::ENV_ALL);

}

