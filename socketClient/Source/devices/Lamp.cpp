/*
 * Lamp.cpp
 *
 *  Created on: Jan 10, 2019
 *      Author: programmer
 */

#include "Lamp.h"
using namespace std;

Lamp::Lamp(string ip, int port) : Device(ip, port), motion(0), forcedOn(0), ledStatus(0) {
	// TODO Auto-generated constructor stub

}

Lamp::~Lamp() {
	// TODO Auto-generated destructor stub
}

void Lamp::handleActions(){
	requestInputs();
	lampLight();
	handleMotion();
	setOutputs();
}

void Lamp::lampLight(){
	forcedOn = motion; // Hergebruik motion?
	int switchLed = inputs.value("switchLed", 2) ; //switchled bestaat niet in je arduino code
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

