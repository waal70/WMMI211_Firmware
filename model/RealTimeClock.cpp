/*
 * RealTimeClock.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "RealTimeClock.h"

RealTimeClock::RealTimeClock() :
		myRTC(kCePin, kIoPin, kSclkPin) {

	Serial.println(F("***DS1302 Sensor feedback***"));
	isConnected = false;
	connect();
}

void RealTimeClock::connect() {
	Time t = myRTC.time();
	if (t.mon == 165)    //when there is no clock, t.mon equals 165
			{
		isConnected = false;
		Serial.println(
				F("No Real Time Clock available! Using seconds since boot for logging."));
	} else if (t.yr == 2000) //when there is an error with the RTC, year will be set on 2000
			{
		isConnected = false;
		Serial.println(
				F("Real Time Clock error! Using seconds since boot for logging."));
	} else {
		isConnected = true;
		char buffer[50];
		sprintf(buffer, "Real Time Clock available! Current time: %02d:%02d:%02d", t.hr, t.min, t.sec);
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
	return buffer;
}

char* RealTimeClock::getDate() {
	if (!isConnected)
		connect();
	//31-12-2022
	char buffer[10];
	Time t = myRTC.time();
	sprintf(buffer, "%02d-%02d-%04d", t.date, t.mon, t.yr);
	return buffer;
}
char* RealTimeClock::dayAsString(Time t) {
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
	return dayAsString(t);
}

