/*
 * Device.cpp
 *
 *  Created on: Dec 15, 2018
 *      Author: programmer
 */

#include "Device.h"

Device::Device(string ip, int port, const char* path):phpCom(path),wemosCom(ip, port) {

	initConnection();

}

Device::~Device() {
	// TODO Auto-generated destructor stub
}


void Device::initConnection(){
	wemosCom.createSock(); //add to init method in socket class?
	wemosCom.connectToServer();
}
void Device::requestInputs(){
	wemosCom.sendToServer("i");
	inputs = nlohmann::json::parse(wemosCom.receiveFromServer());
	//cout << "inputs received: " << inputs.dump(1) << endl;
}
void Device::setOutputs(){
	static nlohmann::json outputsOld;
	if(outputsOld == outputs){
		return;
	}
	else{
		wemosCom.sendToServer("o " + outputs.dump());
		outputsOld = outputs;
	}
}
void Device::tempPHPHandle(){
	//phpRw = nlohmann::json::parse(phpCom.readFile());
}
