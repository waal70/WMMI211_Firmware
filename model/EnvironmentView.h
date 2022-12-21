/*
 * EnvironmentView.h
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_ENVIRONMENTVIEW_H_
#define MODEL_ENVIRONMENTVIEW_H_

#include "Environment.h"
#include "AbstractView.h"

class EnvironmentView: public AbstractView {
public:
	EnvironmentView(Environment* model, TFTHelper* screen);

	void setModel(Environment* model);

	void Render();
	void Render(int detailRequired);
	void clear();
	enum DETAIL {
		ENV_ALL = 0,
		ENV_HUMIDITY = 1,
		ENV_PRESSURE = 2,
		ENV_ALTITUDE = 4,
		ENV_TEMPERATURE = 8,
	};
private:
	Environment* model;	//holds the sensor model
	void printValues();
	void RenderAll();						//renders the summary on main screen
	void RenderTemperature();
	TFTHelper* myScreen;

};

#endif /* MODEL_ENVIRONMENTVIEW_H_ */
