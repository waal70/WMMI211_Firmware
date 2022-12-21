/*
 * TFTHelper.h
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_TFTHELPER_H_
#define MODEL_TFTHELPER_H_

#include "../src/MCUFRIEND_kbv/MCUFRIEND_kbv.h"

/**
 * Class that encapsulates the MCUFRIEND_kbv TFT handling
 *
 * It is implemented as a Singleton, because there should be
 * only one physical TFT-screen in this setup.
 * The Singleton ensures only one instance is created
 *
 */
class TFTHelper {

protected:
    static TFTHelper * pinstance_;
    TFTHelper();

public:
	TFTHelper(TFTHelper &other) = delete;
	static TFTHelper *GetInstance();
	void operator=(const TFTHelper &) = delete;

	void showbgd(int x, int y, const uint8_t *bmp, int w, int h, uint16_t color, uint16_t bg);
	void connect(void);
	//TODO: is this a pointer (Singleton)
	MCUFRIEND_kbv tft;

private:
    void init();

};

#endif /* MODEL_TFTHELPER_H_ */
