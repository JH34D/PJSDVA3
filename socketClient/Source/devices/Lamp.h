/*
 * Lamp.h
 *
 *  Created on: Jan 10, 2019
 *      Author: programmer
 */

#ifndef DEVICES_LAMP_H_
#define DEVICES_LAMP_H_

#include <iostream>
#include "../Device.h"



class Lamp : public Device {
public:
	Lamp(string ip, int port);
	virtual ~Lamp();
	void handleActions();
private:
	void lampLight();
	void handleMotion();
	int motion;
	int forcedOn;
	bool ledStatus;

};

#endif /* DEVICES_LAMP_H_ */
