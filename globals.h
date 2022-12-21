/*
 * globals.h
 *
 *  Created on: 18 dec. 2022
 *      Author: awaal
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <stdint.h>
#include <Arduino.h>

#include "config.h"
#include "model/EarthListenerController.h"

extern TFTHelper *myScreen;

extern Gas *myGas;
extern Lightning *myLightning;
extern Environment *myEnv;
extern RealTimeClock *myRTC;

extern GasView *myGasView;
extern LightningView *myLightningView;
extern EnvironmentView *myEnvView;

extern EarthListenerController *elc;


#endif /* GLOBALS_H_ */
