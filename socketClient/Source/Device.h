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
	void requestInputs();
	void setOutputs();
	//TODO add function for php
	void tempPHPHandle();
protected:
	File phpCom; //used for communication with php on the interface
	sockClient wemosCom; //used for communication with c on the WeMos
	nlohmann::json inputs;
	nlohmann::json outputs;
	nlohmann::json phpRw;
private:
	void initConnection();
};

#endif /* DEVICE_H_ */
