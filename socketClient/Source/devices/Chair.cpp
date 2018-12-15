/*
 * Chair.cpp
 *
 *  Created on: Dec 13, 2018
 *      Author: programmer
 */
#include <iostream>
#include "Chair.h"
#include "../sockClient.h"
#include "../File.h"

using namespace std;
using namespace nlohmann;

Chair::Chair(string ip, int port,const char* path):Device(ip,port,path){//:phpCom(path),wemosCom(ip, port){

}

Chair::~Chair(){
	//
}

void Chair::handleActions(){
	/*
	 * request inputs
	 * handle actions and set ouput value in json object
	 * set outputs
	 */

	requestInputs();
	handleBedtime();
	setOutputs();
}

void Chair::handleBedtime(){

		int sits = inputs.value("sits", 8); //get value if error return 8
		if (sits == 8){ //check for error
			cerr << "Error while reading input values. Sits could not be found in Json object int function handleBedtime() in class chair" << endl;
			sits = 0;
			//return;
		}
		time_t rawTime = time(0);
		struct tm* currentTime;
		currentTime = localtime(&rawTime);
		//currentTime->tm_hour = 22; //testing.
		if (sits && (currentTime->tm_hour > 21 || currentTime->tm_hour < 7)){ //TODO optionally add flag to only send output once
			outputs["vibrate"] = 1;
		}
		else {
			outputs["vibrate"] = 0;
		}
		/*else if(currentTime->tm_hour < 22 && currentTime->tm_hour > 6){
			wemosCom.sendToServer("noBedtime");
		}*/
}

