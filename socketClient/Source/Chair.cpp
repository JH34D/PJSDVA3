/*
 * Chair.cpp
 *
 *  Created on: Dec 13, 2018
 *      Author: programmer
 */
#include <iostream>
#include "Chair.h"
#include "sockClient.h"
#include "File.h"

using namespace std;
using namespace nlohmann;

Chair::Chair(string ip, int port,const char* path):phpCom(path),wemosCom(ip, port){
	//:filepath(path),wemosCom(ip, port),phpCom()
	wemosCom.createSock(); //add to init in socket class?
	wemosCom.connectToServer();

}

Chair::~Chair(){
	//
}

void Chair::handleWemos(){
	string response;
	static bool bedtime;
	wemosCom.sendToServer("hi");
	response = wemosCom.receiveFromServer();
	if(response == "error"){ //add to function in "motherclass"
		cerr << "Device Chair not responding. Please reset this device" <<endl;
	}
	else if(response == "hi"){
		time_t rawTime = time(0);
		struct tm* currentTime;
		currentTime = localtime(&rawTime);
		cout << "current hour should be: " << currentTime->tm_hour << endl;
		if (currentTime->tm_hour > 21 || currentTime->tm_hour < 7){
			bedtime = true;
			wemosCom.sendToServer("bedtime");
		}
		else{
			bedtime = false;
			wemosCom.sendToServer("noBedtime");
		}



	}

}

void Chair::handleGui(){
	json j1;
	j1 = json::parse(phpCom.readFile());
	//j1["chair"] = 1;
	phpCom.writeToFile(j1);
	if(j1.value("chair", 9) == 1){ //if value of "chair" == 1 do
		cout << "do chair stuff" << endl;
	}


}

