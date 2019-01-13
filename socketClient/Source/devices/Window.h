/*
 * Window.h
 *
 *  Created on: Jan 3, 2019
 *      Author: programmer
 */

#ifndef DEVICES_WINDOW_H_
#define DEVICES_WINDOW_H_

#include <iostream>
#include "../Device.h"

class Window : public Device {
public:
	Window(string ip, int port);
	virtual ~Window();
	void handleActions();
private:
	int potmeterLedOld;
	int ledOld;
	void handleLed();
	void handleSun();
	void handlePHP();

};

#endif /* DEVICES_WINDOW_H_ */


