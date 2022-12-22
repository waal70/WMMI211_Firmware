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
	if ((Xpos > 0) && (Xpos < 45) && (Ypos > 0) && (Ypos < 30)) {
		//Serial.println("Touch on slide show button!");
		CurrentScreen = OVERVIEW;
		refresh();
	}
	//Setup screen button
	else if ((Xpos > 0) && (Xpos < 45) && (Ypos > 210) && (Ypos < 245)) {
		//Serial.println("Touch on setup screen button!");
		CurrentScreen = SETTINGS;
		refresh();
	}
	//check eCO2 button
	else if ((Xpos > 140) && (Xpos < 220) && (Ypos > 30) && (Ypos < 80)) {
		//Serial.println("Touch on eCO2 button!");
	}
	//check temp button
	else if ((Xpos > 140) && (Xpos < 220) && (Ypos > 100) && (Ypos < 140)) {
		//Serial.println("Touch on temp button!");
		CurrentScreen = TEMPERATURE;
		refresh();
	}
	//check pressure button
	else if ((Xpos > 140) && (Xpos < 220) && (Ypos > 165) && (Ypos < 210)) {
		//Serial.println("Touch on pressure button!");
	}
	//check tvoc button
	else if ((Xpos > 50) && (Xpos < 110) && (Ypos > 30) && (Ypos < 80)) {
		//Serial.println("Touch on tvoc button!");
	}
	//check humidity button
	else if ((Xpos > 50) && (Xpos < 110) && (Ypos > 100) && (Ypos < 140)) {
		//Serial.println("Touch on humidity button!");
	}
	//check lightning button
	else if ((Xpos > 50) && (Xpos < 110) && (Ypos > 165) && (Ypos < 210)) {
		//Serial.println("Touch on lightning button!");
	} else {
		//Serial.println("I do not know what you are touching...");
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

