/*
 * Fridge.h
 *
 *  Created on: Jan 6, 2019
 *      Author: programmer
 */

#ifndef DEVICES_FRIDGE_H_
#define DEVICES_FRIDGE_H_
#include <iostream>
#include "../Device.h"

class Fridge : public Device {
public:
	Fridge(string, int, const char*);
	virtual ~Fridge();
	void handleActions();

private:
	void handleFridge();
	void handleTemp();

};


#endif /* DEVICES_FRIDGE_H_ */
