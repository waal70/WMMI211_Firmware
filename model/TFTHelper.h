/*
 * TFTHelper.h
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_TFTHELPER_H_
#define MODEL_TFTHELPER_H_

#include <stdint.h>
#include "../src/MCUFRIEND_kbv/MCUFRIEND_kbv.h"

class TFTHelper {
public:
	TFTHelper();
	void showbgd(int x, int y, const uint8_t *bmp, int w, int h, uint16_t color, uint16_t bg);
	MCUFRIEND_kbv tft;
private:

	void init();
};

#endif /* MODEL_TFTHELPER_H_ */
