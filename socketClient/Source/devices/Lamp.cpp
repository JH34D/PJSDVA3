/*
 * Lamp.cpp
 *
 *  Created on: Jan 10, 2019
 *      Author: programmer
 */

#include "Lamp.h"

Lamp::Lamp(string ip, int port) : Device(ip, port), int motion, int forcedOn {
	// TODO Auto-generated constructor stub

}

Lamp::~Lamp() {
	// TODO Auto-generated destructor stub
}

void Lamp::handleActions(){
	requestInputs();
	lampLight();
	handleMotion
	setOutputs();
}

void Lamp::lampLight(){
	forcedOn = motion;
	int switchLed = inputs.value("switchLed", 2);
	if (switchLed == 2){
		cerr << "Error while reading switchLed" << endl;
		return;
	}
	else if(switchLed){
		ledStatus = !ledStatus;
	}
	if (forcedOn == 1) {
		outputs["lampLight"] = 1;
	} else {
		outputs["lampLight"] = ledStatus;
	}
}

void Lamp::handleMotion(){
	int lampMotion = inputs.value("lampMotion", 404); //get value if error return 404
			if (lampMotion == 404){ //check for error
				cerr << "Error while reading input values. lampMotion could not be found in Json object in function handleMotion() in class Lamp  " << endl;
				lampMotion = 0;
				//return;
			}
			if (lampMotion == 15) {
				outputs["lampMotion"] = 1;
				motion = 1;
			}
			else {
				outputs["lampMotion"] = 0;
				motion = 0;
			}
	}

