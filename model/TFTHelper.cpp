/*
 * TFTHelper.cpp
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#include "TFTHelper.h"
#include <stdint.h>
#include "../config.h"


TFTHelper::TFTHelper() {
	init();
}

// This holds the reference to the single instance
TFTHelper *TFTHelper::pinstance_ = nullptr;
;

// You should create/get instances via this method
TFTHelper* TFTHelper::GetInstance() {
	/**
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (pinstance_ == nullptr) {
		pinstance_ = new TFTHelper();
	}
	return pinstance_;
}

void TFTHelper::init() {
	Serial.println(F("***LCD screen feedback***"));
	Serial.println(F("TFT LCD test"));
#ifdef USE_ADAFRUIT_SHIELD_PINOUT
  Serial.println(F("Using Adafruit 2.4\" TFT Arduino Shield Pinout"));
#else
	Serial.println(F("Using Adafruit 2.4\" TFT Breakout Board Pinout"));
#endif
	Serial.print(F("TFT size is "));
	Serial.print(tft.width());
	Serial.print("x");
	Serial.println(tft.height());
	tft.reset();

	uint16_t identifier = tft.readID();
	if (identifier == 0x9325) {
		Serial.println(F("Found ILI9325 LCD driver"));
	} else if (identifier == 0x9328) {
		Serial.println(F("Found ILI9328 LCD driver"));
	} else if (identifier == 0x4535) {
		Serial.println(F("Found LGDP4535 LCD driver"));
	} else if (identifier == 0x7575) {
		Serial.println(F("Found HX8347G LCD driver"));
	} else if (identifier == 0x9341) {
		Serial.println(F("Found ILI9341 LCD driver"));
	} else if (identifier == 0x7783) {
		Serial.println(F("Found ST7781 LCD driver"));
	} else if (identifier == 0x8230) {
		Serial.println(F("Found UC8230 LCD driver"));
	} else if (identifier == 0x8357) {
		Serial.println(F("Found HX8357D LCD driver"));
	} else if (identifier == 0x0101) {
		identifier = 0x9341;
		Serial.println(F("Found 0x9341 LCD driver"));
	} else {
		Serial.print(F("Unknown LCD driver chip: "));
		Serial.println(identifier, HEX);
		Serial.println(
				F("If using the Adafruit 2.8\" TFT Arduino shield, the line:"));
		Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
		Serial.println(
				F("should appear in the library header (Adafruit_TFT.h)."));
		Serial.println(
				F("If using the breakout board, it should NOT be #defined!"));
		Serial.println(
				F("Also if using the breakout, double-check that all wiring"));
		Serial.println(F("matches the tutorial."));
		identifier = 0x9341;
	}
	tft.begin(identifier);
	tft.fillScreen(BLACK);
	tft.setRotation(1);
	pinMode(touchPin, OUTPUT);

}

//calls init(): kept for compatibility purposes
void TFTHelper::connect() {
	init();
}
/**
 * Display an icon on a certain area of the screen
 *
 * @param[in] X-coordinate
 * @param[in] Y-coordinate
 * @param[in] PROGMEM map of bitmap to display
 * @param[in] width in pixels
 * @param[in] height in pixels
 * @param[in] color
 * @param[in] background color
 */
void TFTHelper::showbgd(int x, int y, const uint8_t *bmp, int w, int h,
		uint16_t color, uint16_t bg) {
	uint8_t pad = 7;
	int yy, xx;
	uint8_t first = 1, RVS = pad & 0x80;
	uint16_t pixel;
	pad &= 31;
	uint16_t wid = (w + pad) & ~pad;                    //bits per row
	tft.setAddrWindow(x, y, x + w - 1, y + h - 1); //
	for (yy = 0; yy < h; yy++) {
		uint32_t ofs = (RVS ? (h - yy - 1) : yy) * wid; //bit offset
		const uint8_t *p = bmp + (ofs >> 3);            //flash address
		uint8_t mask = 0x80 >> (ofs & 7);               //bit mask
		uint8_t c = pgm_read_byte(p++);
		for (xx = 0; xx < w; xx++) {
			if (mask == 0) {
				c = pgm_read_byte(p++);
				mask = 0x80;
			}
			pixel = (c & mask) ? color : bg;
			tft.pushColors(&pixel, 1, first);
			first = 0;
			mask >>= 1;
		}
	}
	tft.setAddrWindow(0, 0, tft.width() - 1, tft.height() - 1);
}

