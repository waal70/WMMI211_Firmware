/*
 * RealTimeClock.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "RealTimeClock.h"
#include <stdint.h>
#include "../config.h"
#include "Sensors.h"

RealTimeClock::RealTimeClock() :
		myRTC(kCePin, kIoPin, kSclkPin) {

	Serial.println("***DS1302 Sensor feedback***");
	isConnected = false;
	connect();
}

void RealTimeClock::connect() {
	Time t = myRTC.time();
	if (t.mon == 165)    //when there is no clock, t.mon equals 165
			{
		isConnected = false;
		Serial.println(
				"No Real Time Clock available! Using seconds since boot for logging.");
	} else if (t.yr == 2000) //when there is an error with the RTC, year will be set on 2000
			{
		isConnected = false;
		Serial.println(
				"Real Time Clock error! Using seconds since boot for logging.");
	} else {
		isConnected = true;
		Serial.print("Real Time Clock available! Current time: ");
		char buffer[8];
		sprintf(buffer, "%02d:%02d:%02d", t.hr, t.min, t.sec);
		Serial.println(buffer);
		//Serial.println(isConnected);
	}
	Serial.println();

}
char* RealTimeClock::getTime() {
	if (!isConnected)
		connect();
	//23:59:59
	char buffer[8];
	Time t = myRTC.time();
	sprintf(buffer, "%02d:%02d:%02d", t.hr, t.min, t.sec);
	Serial.println("Just got time: ");
	Serial.println(buffer);
	return buffer;
}

char* RealTimeClock::getDate() {
	if (!isConnected)
		connect();
	//31-12-2022
	char buffer[10];
	Time t = myRTC.time();
	sprintf(buffer, "%02d-%02d-%04d", t.date, t.mon, t.yr);
	Serial.println("Just got date: ");
	Serial.println(buffer);
	return buffer;
}
char* RealTimeClock::dayAsString(Time t) {
	Serial.println("Input day is: ");
	Serial.println(t.day);
	int day = t.day;
	switch (day) {
	case Time::kSunday:
		return "Sunday";
	case Time::kMonday:
		return "Monday";
	case Time::kTuesday:
		return "Tuesday";
	case Time::kWednesday:
		return "Wednesday";
	case Time::kThursday:
		return "Thursday";
	case Time::kFriday:
		return "Friday";
	case Time::kSaturday:
		return "Saturday";
	}
	return "(unknown day)";
}
char* RealTimeClock::getDayOfWeek() {
	if (!isConnected)
		connect();
	//Wednesday
	Time t = myRTC.time();
	Serial.println("Just got day of week: ");
	Serial.println(dayAsString(t));
	return dayAsString(t);
}

