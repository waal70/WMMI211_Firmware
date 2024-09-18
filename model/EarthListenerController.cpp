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

EarthListenerController::EarthListenerController(Environment *myEnvironment,
		EnvironmentView *myEnvironmentView, Gas *myGas, GasView *myGasView,
		Lightning *myLightning, LightningView *myLightningView,
		RealTimeClock *myRTC, Menu *myMenu, MenuView *myMenuView) {
	Serial.println(F("EarthListenerController being created"));
	bool isMetric = myMenu->getMetric();
	this->myEnvironment = myEnvironment;
	this->myEnvironmentView = myEnvironmentView;
	this->myGas = myGas;
	this->myGasView = myGasView;
	this->myLightning = myLightning;
	this->myLightningView = myLightningView;
	this->myRTC = myRTC;
	this->myMenu = myMenu;
	this->myMenuView = myMenuView;
	//now pass metric system or idiot system:
	this->myEnvironmentView->isMetric = isMetric;
	this->myLightningView->isMetric = isMetric;
	this->CurrentScreen = OVERVIEW;
	this->PreviousScreen = OVERVIEW;
}
void EarthListenerController::showSummary() {
	//Make sure the Gas thingy has the correct reference values;
	CurrentScreen = OVERVIEW;
	myGas->setReferences(myEnvironment->getTemperature(),
			myEnvironment->getHumidity());
	myEnvironmentView->Render(EnvironmentView::ENV_ALL);
	myGasView->Render(GasView::GAS_ALL);
	myLightningView->Render(LightningView::LIGHTNING_ALL);
	myMenuView->Render(MenuView::MENU_ALL);
}
void EarthListenerController::refresh() {
	if (CurrentScreen != PreviousScreen) {
		myEnvironmentView->clear();
		PreviousScreen = CurrentScreen;
	}
	switch (CurrentScreen) {
	case OVERVIEW:
		showSummary();
		break;
	case SETTINGS:
		showSettings();
		break;
	case TEMPERATURE:
		myEnvironmentView->Render(EnvironmentView::ENV_TEMPERATURE);
		break;
	}
}
void EarthListenerController::showSettings() {
	// This responsibility is handled by MenuView
	myMenuView->Render(MenuView::MENU_SETTINGS);
}
void EarthListenerController::processTouch(int Xpos, int Ypos) {
	//Slide show button:

	// The screen is vertically divided into four touchzones: top row, first row, second row, bottom row.
	// For first and second row: horizontally, it is split in three: left, middle and right
	// the top row does not matter: always returns to home screen
	// the bottom row is divided in two: SLIDESHOW (left) and CONFIG (right)
	// Based on the touch, I will ascertain the zone that was touched.
	// First off: the vertical zone:
	if ((Ypos > 0) && (Ypos < 55)) {
		ySelect = VERT_TOP;
	}
	else if ((Ypos > 55) && (Ypos < 140)) {
		ySelect = VERT_FIRST;
	}
	else if ((Ypos > 140 ) && (Ypos < 215 ))  {
		ySelect = VERT_SECOND;
	}
	else if (Ypos > 215) {
		ySelect = VERT_BOTTOM;
	}
	if ((Xpos > 0) && (Xpos < 115)) {
		xSelect = HOR_LEFT;
	}
	else if ((Xpos > 115) && (Xpos < 210)) {
		xSelect = HOR_MIDDLE;
	}
	else if ((Xpos > 210) && (Xpos < 318)) {
		xSelect = HOR_RIGHT;
	}

	//char buffer[50];
	//sprintf(buffer, "Processing touch event: VERT, HOR %02d:%02d", ySelect, xSelect);
	//Serial.println(buffer);


	switch (ySelect) {
		case VERT_TOP: {
			CurrentScreen = OVERVIEW;
			refresh();
			break;
		}
		case VERT_BOTTOM: {
			if (xSelect == HOR_LEFT) {
				//Slideshow
			}
			else {
				//Config
			}
			break;
		}
		case VERT_FIRST: {
			Serial.print("VERT_FIRST, ");
			if (xSelect == HOR_LEFT) {
				Serial.println("LEFT");
				CurrentScreen = ECO2;
				refresh();
			}
			if (xSelect == HOR_MIDDLE) {
				Serial.println("MIDDLE");
				CurrentScreen = TEMPERATURE;
				refresh();
			}
			if (xSelect == HOR_RIGHT) {
				Serial.println("RIGHT");
				CurrentScreen = PRESSURE;
				refresh();
			}
			break;
		}
		case VERT_SECOND: {
			Serial.print("VERT_SECOND, ");
			if (xSelect == HOR_LEFT) {
				Serial.println("LEFT");
				CurrentScreen = TVOC;
				refresh();
			}
			if (xSelect == HOR_MIDDLE) {
				Serial.println("MIDDLE");
				CurrentScreen = HUMIDITY;
				refresh();
			}
			if (xSelect == HOR_RIGHT) {
				Serial.println("RIGHT");
				CurrentScreen = LIGHTNING;
				refresh();
			}
			break;
		}
	}



//      //setup screen
//      case 2:
//        //check info screen button
//        if( (Xpos > 0) && (Xpos < 40) && (Ypos > 215) && (Ypos < 245) )
//        {
//          //Serial.println("Touch on info screen button!");
//          previousScreenNr = currentScreenNr;
//          currentScreenNr = 1;
//        }
//        //check speaker button
//        else if( (Xpos > 140) && (Xpos < 220) && (Ypos > 30) && (Ypos < 80) )
//        {
//          //Serial.println("Touch on speaker button!");
//          toggleBuzzer();
//        }
//        //check metric/imperial button
//        else if( (Xpos > 140) && (Xpos < 220) && (Ypos > 100) && (Ypos < 140) )
//        {
//          //Serial.println("Touch on metric/imperial button!");
//          toggleMetric();
//        }
//        //check timer button
//        else if( (Xpos > 140) && (Xpos < 220) && (Ypos > 165) && (Ypos < 210) )
//        {
//          //Serial.println("Touch on timer button!");
//          slideshowTimer = slideshowTimer + 5;
//          if(slideshowTimer > 60){slideshowTimer = 5;}
//        }
//        //check sensitivity button
//        else if( (Xpos > 50) && (Xpos < 110) && (Ypos > 30) && (Ypos < 80) )
//        {
//          //Serial.println("Touch on sensitivity button!");
//          if(AS3935_bootOK)  //only when sensor is up and running can we change the value
//          {
//            globalSense++;
//            if(globalSense > 3){globalSense = 1;}
//            //write updated value to EEPROM long term memory
//            EEPROM.write(globalSense_EEPROMaddr, globalSense);
//            updateLightningSense(); //set the sensitivity of the sensor
//            setupAS3935();  //run setup of AS3935 sensor
//          }
//          else
//          {
//            //push warning message
//            tft.setFont();  //standard system font
//            tft.setTextSize(1);
//            tft.setTextColor(RED,BLACK);
//            tft.setCursor(20, 220);
//            tft.print("Sensor error: check wiring & interface");
//          }
//        }
//        //check indoor/outdoor button
//        else if( (Xpos > 50) && (Xpos < 110) && (Ypos > 100) && (Ypos < 140) )
//        {
//          //Serial.println("Touch on indoor/outdoor button!");
//          toggleIndoor();
//        }
//        //check interface button
//        else if( (Xpos > 50) && (Xpos < 110) && (Ypos > 165) && (Ypos < 210) )
//        {
//          //Serial.println("Touch on interface button!");
//          toggleInterface();
//        }
//        else
//        {
//          //Serial.println("No idea what you are touching there buddy...");
//        }
//        break;
//
//      //eCO² screen
//      case 3:
//        checkBaseTouch();
//        break;
//
//      //temperature screen
//      case 4:
//        checkBaseTouch();
//        break;
//
//      //pressure screen
//      case 5:
//        checkBaseTouch();
//        break;
//
//      //TVOC screen
//      case 6:
//        checkBaseTouch();
//        break;
//
//      //humidity screen
//      case 7:
//        checkBaseTouch();
//        break;
//
//      //lightning screen
//      case 8:
//        checkBaseTouch();
//        break;
//
//      //lightning screen after interrupt
//      case 81:
//        // no touch functionality (delay of 3 seconds, so touch would never be handled correct)
//        break;
//
//      default:
//        // no default statements
//        break;
//    }
}

