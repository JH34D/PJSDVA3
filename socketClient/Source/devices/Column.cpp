/*
 * Column.cpp
 *
 *  Created on: Dec 15, 2018
 *      Author: programmer
 */
#include "Column.h"
#include <iostream>
#include "../sockClient.h"
#include "../File.h"

using namespace std;
using namespace nlohmann;

Column::Column(string ip, int port):Device(ip,port){
	phpCom->phpDataJson["fire"] = 0; //create entry in json file to guarantee it exists.
	phpCom->writeToFile();
}

Column::~Column(){
	//
}

void Column::handleActions(){
	/*
	 * request inputs
	 * handle actions and set ouput value in json object
	 * set outputs
	 * return json for php?
	 */
	phpCom->updateData();
	requestInputs();
	fireAlarm();
	setOutputs();
	phpCom->writeToFile();
}

void Column::fireAlarm(){
	
	int fireDetector = inputs.value("fireDetector", 1050); //get value if error return 1050
		if (fireDetector == 1050){ //check for error
			cerr << "Error while reading input values. fireDetector could not be found in Json" << endl;
			fireDetector = 0;
			//return;
		}
		if (fireDetector < 750) { //above 600 fire is detected
			outputs["fireAlarm"] = 0;
			interDevCom["fireDetector"] = 0;// if no fire reset value.
			phpCom->phpDataJson["fire"] = 0;
		}
		else {
			outputs["fireAlarm"] = 3; //if fire then fire alarm
			interDevCom["fireDetector"] = 1;// if fire set value.
			phpCom->phpDataJson["fire"] = 1;
			//todo send to PHP fire
		}
}
