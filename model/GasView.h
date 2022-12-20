/*
 * GasView.h
 *
 *  Created on: 20 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_GASVIEW_H_
#define MODEL_GASVIEW_H_

#include "Gas.h"
#include "AbstractView.h"

class GasView: public AbstractView {
public:
	GasView();
	GasView(const Gas &model);
	void setModel(const Gas &model);
	//void printValues();
	void Render();
	void Render(int detailRequired);
	enum DETAIL {
		GAS_ALL = 0, GAS_CO2 = 1, GAS_TVOC = 2,
	};
private:
	Gas model;	//holds the sensor model
	void printValues();
	void RenderAll();						//renders the summary on main screen
	TFTHelper myScreen;
};

#endif /* MODEL_GASVIEW_H_ */
