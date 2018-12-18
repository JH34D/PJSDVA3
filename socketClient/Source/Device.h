/*
 * Device.h
 *
 *  Created on: Dec 15, 2018
 *      Author: programmer
 */

#ifndef DEVICE_H_
#define DEVICE_H_


#include <iostream>
#include "File.h"
#include "sockClient.h"
#include "json.hpp"
#include  "Php.h"

class Device {
public:
	Device(string ip, int port);
	virtual ~Device();
	void requestInputs(); //gets input data from connected device
	void setOutputs(); //sends data to connected device
	//TODO add function for php
protected:
	sockClient wemosCom; //used for communication with c on the WeMos
	nlohmann::json inputs; //used to store input data.
	nlohmann::json outputs; //used to store data to set output
	static Php *phpCom;
	//TODO add static Json/array for crosstalk between devices. e.g. Turn off lights when in bed after x time or open door if fire has been detected.
private:
	void initConnection();
};

#endif /* DEVICE_H_ */
