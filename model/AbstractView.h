/*
 * AbstractView.h
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_ABSTRACTVIEW_H_
#define MODEL_ABSTRACTVIEW_H_

#include "TFTHelper.h"

class AbstractView {
public:
	AbstractView();
	void setTFTHelper(const TFTHelper &myScreen);

private:
	TFTHelper myScreen;

};

#endif /* MODEL_ABSTRACTVIEW_H_ */
