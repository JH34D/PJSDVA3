/*
 * Lamp.cpp
 *
 *  Created on: Jan 10, 2019
 *      Author: programmer
 */

#include "Lamp.h"
using namespace std;

Lamp::Lamp(string ip, int port) : Device(ip, port), latestBrightness(0), motion(0) {

}

Lamp::~Lamp() {

}

void Lamp::handleActions(){
	requestInputs();
	phpCom->updateData();
	lampLight();
	handleMotion();
	setOutputs();
	phpCom->writeToFile();
}

void Lamp::lampLight(){
	int ledState = inputs.value("lampLight", 11) ; // will set 11 as value if lampLight can't be read
	if (ledState == 11){
		cerr << "Error while reading lampLight" << endl;
		return;
	}
	else {
		ledState /= 10;
		if (ledState != 0) {
			latestBrightness = ledState;
		}
	}
	if (motion == 1 && ledState == 0) {
		outputs["lampLight"] = latestBrightness;
	} else {
		outputs["lampLight"] = ledState;
	}
}

void Lamp::handleMotion(){
	int lampMotion = inputs.value("lampMotion", 404); //get value if error return 404
	if (lampMotion == 404){ //check for error
		cerr << "Error while reading input values. lampMotion could not be found in Json object in function handleMotion() in class Lamp  " << endl;
		lampMotion = 0;
	} else if (lampMotion == 15) {
		outputs["lampMotion"] = 1;
		motion = 1;
	} else {
		outputs["lampMotion"] = 0;
		motion = 0;
	}
}

