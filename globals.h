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

extern Gas *myGas;
extern Lightning *myLightning;
extern Environment *myEnv;
extern RealTimeClock *myRTC;

extern GasView *myGasView;
extern LightningView *myLightningView;
extern EnvironmentView *myEnvView;

extern EarthListenerController *elc;

extern unsigned long touchedTime;
extern bool touchedMe;
extern unsigned long allSeconds;
extern unsigned long runDays;
extern unsigned long secsRemaining;
extern unsigned long runHours;
extern unsigned long runMinutes;
extern unsigned long runSeconds;

extern unsigned long lastSecond;

extern int secondCounter;

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 320 ohms across the X plate
//inline TouchScreen ts = TouchScreen(XP, YP, XM, YM, 320);


/* --- Speaker --- */
//pin setup for speaker
extern bool BuzzerEnabled;      //1= Buzzer on, 0= Buzzer off => can be modified via TFT interface


/* --- RGB LED --- */
extern bool LEDenabled;     //1= LED on, 0= LED off. Will also declare pins for output if turned on.


/* --- menus --- */
extern int currentScreenNr;        //start with bootscreen
extern int previousScreenNr;
extern bool slideShowPlaying;        //is the slide show playing? yes=1, no=0
extern int slideshowTimer;         //time (in seconds) to show each slide
extern unsigned long timeStartSlide;     //time when slide was first shown;


/* --- metric / imperial switch --- */
extern bool MetricON;  //boolean to check if values of temperature and lightning distance are set in Celsius/km or Fahrenheit/miles => can be modified via TFT interface




#endif /* GLOBALS_H_ */
