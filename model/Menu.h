/*
 * Menu.h
 *
 *  Created on: 22 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_MENU_H_
#define MODEL_MENU_H_

#include "AbstractModel.h"
#include "EEPROM.h"
/*
 * The Menu class holds the settings for the Earth Listener.
 * Settings to keep track of are:
 * SlideshowRunning - session-based
 * SlideshowTimer - session-based
 * First boot? (EEPROM: firstBoot_EEPROMaddr: true/false)
 * Buzzer ON/OFF (EEPROM: Buzzer_EEPROMaddr: true/false)
 * Metric or Imperial (EEPROM: MetricON_EEPROMaddr: true/false)
 * Lightning Sensitivity LOW MEDIUM HIGH (EEPROM: globalSense_EEPROMaddr: 1,2,3 = LOW,MEDIUM,HIGH)
 * Indoor / Outdoor (EEPROM: AS3935_outdoor_EEPROMaddr: true/false - true=OUTDOOR)
 * AS3935 IIC or SPI (EEPROM: AS3935_SPI_EEPROMaddr: true/false)

 * As these are also unique, this class is a Singleton
 */

class Menu: public AbstractModel {
private:

	void initialize();
	int readEEPROM(int address);
	void writeEEPROM(int address, int value);

	bool SlideshowRunning;
	int SlideshowTimer; //in seconds
protected:
    static Menu * pinstance_;
    Menu();
public:
	Menu(Menu &other) = delete;
	static Menu *GetInstance();
	void operator=(const Menu &) = delete;
	//=========Methods to get settings
	bool getFirstBoot();
	void setFirstBoot(bool firstBoot);
	bool getBuzzerON();
	void setBuzzerON(bool buzzerON);
	bool getMetric();
	void setMetric(bool metricON);
	bool getOutdoor();
	void setOutdoor(bool outdoor);
	bool getAS3935SPI();
	void setAS3935SPI(bool spiON);
	int getSensitivity();
	void setSensitivity(int sensitivityLevel);
	int getSlideshowTimer();
	void setSlideshowTimer(int seconds);
	bool getSlideshowRunning();
	void setSlideshowRunning(bool isRunning);

};
#endif /* MODEL_MENU_H_ */
