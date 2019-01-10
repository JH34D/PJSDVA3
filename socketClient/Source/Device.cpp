/*
 * Device.cpp
 *
 *  Created on: Dec 15, 2018
 *      Author: programmer
 */

#include "Device.h"

Device::Device(string ip, int port):wemosCom(ip, port) {

	initConnection();


}

Device::~Device() {
	// TODO Auto-generated destructor stub
}
Php* Device::phpCom = new Php;

void Device::initConnection(){
	wemosCom.createSock();
	wemosCom.connectToServer();
}
void Device::requestInputs(){
	wemosCom.sendToServer("i");
	inputs = nlohmann::json::parse(wemosCom.receiveFromServer());
	//cout << "inputs received: " << inputs.dump(1) << endl;
}
void Device::setOutputs(){
	//check if outputs has changed. if so send data.
	static nlohmann::json outputsOld;
	if(outputsOld == outputs){
		return;
	}
	else{
		wemosCom.sendToServer("o " + outputs.dump());
		outputsOld = outputs;
	}
}
void Device::handleActions(){
	cout << "please overwrite this function in the derived class" << endl;
}

