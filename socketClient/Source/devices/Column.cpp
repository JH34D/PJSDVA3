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
		if (fireDetector > 200 && fireDetector < 450) {
			outputs["fireAlarm"] = 0;
		}
		else {
			outputs["fireAlarm"] = 1;
		}
}
