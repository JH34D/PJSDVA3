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

	requestInputs();
	fireAlarm();

	setOutputs();
}

void Column::fireAlarm(){
	
	int fireDetector = inputs.value("fireDetector", 1050); //get value if error return 1050
		if (fireDetector == 1050){ //check for error
			cerr << "Error while reading input values. fireDetector could not be found in Json" << endl;
			fireDetector = 0;
			//return;
		}
		if (fireDetector < 600) { //above 450 fire is detected
			outputs["fireAlarm"] = 0;
			//todo send to PHP no fire
		}
		else {
			outputs["fireAlarm"] = 3; //if fire then fire alarm
			interDevCom["fireDetector"] = 451;// if fire set alarm sensor value to 451 so the door can open.
			//todo send to PHP fire
		}
}
