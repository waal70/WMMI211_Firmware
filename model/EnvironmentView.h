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
	EnvironmentView();
	EnvironmentView(const Environment &model);

	void setModel(const Environment &model);

	void Render();
	void Render(int detailRequired);
	enum DETAIL {
		ENV_ALL = 0,
		ENV_HUMIDITY = 1,
		ENV_PRESSURE = 2,
		ENV_ALTITUDE = 4,
		ENV_TEMPERATURE = 8,
	};
private:
	Environment model;	//holds the sensor model
	void printValues();
	void RenderAll();						//renders the summary on main screen
	TFTHelper myScreen;

};

#endif /* MODEL_ENVIRONMENTVIEW_H_ */
