/*
 * globals.h
 *
 *  Created on: 18 dec. 2022
 *      Author: awaal
 *
 *  This header file declares some of the globally used
 *  objects.
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

extern TFTHelper *myScreen;
extern Menu * myMenu;

extern Gas *myGas;
extern Lightning *myLightning;
extern Environment *myEnv;
extern RealTimeClock *myRTC;

extern GasView *myGasView;
extern LightningView *myLightningView;
extern EnvironmentView *myEnvView;
extern MenuView *myMenuView;

extern EarthListenerController *elc;

extern unsigned long touchedTime;
extern unsigned long allSeconds;
extern unsigned long runDays;
extern unsigned long secsRemaining;
extern unsigned long runHours;
extern unsigned long runMinutes;
extern unsigned long runSeconds;

extern unsigned long lastSecond;

extern int secondCounter;

extern int Xpos; extern int Ypos;

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 320 ohms across the X plate
//inline TouchScreen ts = TouchScreen(XP, YP, XM, YM, 320);


/* --- RGB LED --- */
extern bool LEDenabled;     //1= LED on, 0= LED off. Will also declare pins for output if turned on.

/* --- menus --- */
extern int currentScreenNr;        //start with bootscreen
extern int previousScreenNr;
extern unsigned long timeStartSlide;     //time when slide was first shown;

#endif /* GLOBALS_H_ */
