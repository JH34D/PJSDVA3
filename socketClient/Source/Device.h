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
	virtual void handleActions();
	//TODO add function for php
protected:
	sockClient wemosCom; //used for communication with c on the WeMos
	nlohmann::json inputs; //used to store input data.
	nlohmann::json outputs; //used to store data to set output
	static Php *phpCom;
	static nlohmann::json interDevCom; //json object shared between all classes derived from device. Used to allow different classes to set information for other classes.
private:
	void initConnection();
};

#endif /* DEVICE_H_ */
