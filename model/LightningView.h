/*
 * LightningView.h
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_LIGHTNINGVIEW_H_
#define MODEL_LIGHTNINGVIEW_H_

#include "AbstractView.h"
#include "Lightning.h"

class LightningView: public AbstractView {
public:
	LightningView(Lightning* model, TFTHelper* screen);
	void setModel(Lightning* model);
	//void printValues();
	void Render();
	void Render(int detailRequired);
	enum DETAIL {
		LIGHTNING_ALL = 0, LIGHTNING_DIST = 1, LIGHTNING_INTENS = 2,
	};
private:
	Lightning* model;	//holds the sensor model
	void printValues();
	void RenderAll();						//renders the summary on main screen
	TFTHelper* myScreen;
};

#endif /* MODEL_LIGHTNINGVIEW_H_ */
