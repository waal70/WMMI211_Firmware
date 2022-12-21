/*
 * MenuView.h
 *
 *  Created on: 21 dec. 2022
 *      Author: awaal
 */

#ifndef MODEL_MENUVIEW_H_
#define MODEL_MENUVIEW_H_

#include "AbstractView.h"
#include "../config.h"

//The menu does not have a model? Or is that the settings?
class MenuView: public AbstractView {
public:
	MenuView(TFTHelper* screen);
	void RenderAll();
	void Render();
	void Render(int detailRequired);
	enum DETAIL {
		MENU_ALL = 0,
		MENU_HEADER = 1,
		MENU_FOOTER = 2,
		MENU_SETTINGS = 4,
	};
private:
	TFTHelper* myScreen;
};

#endif /* MODEL_MENUVIEW_H_ */
