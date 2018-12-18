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

class Device {
public:
	Device(string ip, int port, const char* path);
	virtual ~Device();
	void requestInputs(); //gets input data from connected device
	void setOutputs(); //sends data to connected device
	//TODO add function for php
	void tempPHPHandler();
protected:
	File phpCom; //used for communication with php on the interface
	sockClient wemosCom; //used for communication with c on the WeMos
	nlohmann::json inputs; //used to store input data.
	nlohmann::json outputs; //used to store data to set output
	nlohmann::json phpRw; //used to store data from and for the php interface
private:
	void initConnection();
};

#endif /* DEVICE_H_ */
