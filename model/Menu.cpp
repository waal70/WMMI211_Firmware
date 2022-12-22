/*
 * Menu.cpp
 *
 *  Created on: 22 dec. 2022
 *      Author: awaal
 */

#include "Menu.h"
#include "../config.h"

Menu::Menu() {
	//constructor is protected, but still can be used to populate
	// all settings:
	SlideshowRunning = false;
	SlideshowTimer = 5;

}
// This holds the reference to the single instance
Menu *Menu::pinstance_ = nullptr;

// You should create/get instances via this method
Menu* Menu::GetInstance() {
	/**
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (pinstance_ == nullptr) {
		pinstance_ = new Menu();
	}
	return pinstance_;
}
int Menu::readEEPROM(int address) {
	int readValue;
	readValue = EEPROM.read(address);
	return readValue;
}

void Menu::writeEEPROM(int address, int value) {
	//double safe. This method is only called on
	// a difference.
	// EEPROM.update also checks for different value
	EEPROM.update(address, value);
}

bool Menu::getAS3935SPI() {
	return readEEPROM(AS3935_SPI_EEPROMaddr);
}
void Menu::setAS3935SPI(bool spiON) {
	if (readEEPROM(AS3935_SPI_EEPROMaddr) != spiON)
		writeEEPROM(AS3935_SPI_EEPROMaddr, spiON);
}
bool Menu::getBuzzerON() {
	return readEEPROM(Buzzer_EEPROMaddr);
}
void Menu::setBuzzerON(bool buzzerON) {
	if (readEEPROM(Buzzer_EEPROMaddr) != buzzerON)
		writeEEPROM(Buzzer_EEPROMaddr, buzzerON);
}
bool Menu::getFirstBoot() {
	return readEEPROM(firstBoot_EEPROMaddr);
}
void Menu::setFirstBoot(bool firstBoot) {
	if (readEEPROM(firstBoot_EEPROMaddr) != firstBoot)
		writeEEPROM(firstBoot_EEPROMaddr, firstBoot);
}
bool Menu::getMetric() {
	return readEEPROM(MetricON_EEPROMaddr);
}
void Menu::setMetric(bool metricON) {
	if (readEEPROM(MetricON_EEPROMaddr) != metricON)
		writeEEPROM(MetricON_EEPROMaddr, metricON);
}
bool Menu::getOutdoor() {
	return readEEPROM(AS3935_outdoor_EEPROMaddr);
}
void Menu::setOutdoor(bool outdoor) {
	if (readEEPROM(AS3935_outdoor_EEPROMaddr) != outdoor)
		writeEEPROM(AS3935_outdoor_EEPROMaddr, outdoor);
}
int Menu::getSensitivity() {
	return readEEPROM(globalSense_EEPROMaddr);
}
void Menu::setSensitivity(int sensitivityLevel) {
	//cap the level, only 1,2 and 3 are permitted
	if (sensitivityLevel > 3)
		sensitivityLevel = 3;
	if (sensitivityLevel < 1)
		sensitivityLevel = 1;
	if (readEEPROM(globalSense_EEPROMaddr) != sensitivityLevel)
		writeEEPROM(globalSense_EEPROMaddr, sensitivityLevel);
}
int Menu::getSlideshowTimer(){
	return SlideshowTimer;
}
void Menu::setSlideshowTimer(int seconds){
	SlideshowTimer = seconds;
}
bool Menu::getSlideshowRunning(){
	return SlideshowRunning;
}
void Menu::setSlideshowRunning(bool isRunning){
	if (SlideshowRunning != isRunning) SlideshowRunning = isRunning;
}
