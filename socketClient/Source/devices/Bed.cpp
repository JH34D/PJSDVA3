/*
 * Bed.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#include "Bed.h"

Bed::Bed(string ip, int port) : Device(ip, port) {
	// TODO Auto-generated constructor stub

}

Bed::~Bed() {
	// TODO Auto-generated destructor stub
}

void Bed::handleActions(){
	requestInputs();
	bedLight();
	outOfBed();
	/*
	 * seintje als langer uit bed dan x (TODO get time of day naar functie met struct als return?)
	 * Bedlampje uit na bepaalde tijd. (10 min?)
	 * bedlampje schakelen bij druk op de knop.
	 * melding als om 22:30 nog niet in bed
	 */

	setOutputs();
}

void Bed::outOfBed(){

	//todo
	//als liggen 0 wordt, start check for x tijd verlopen, als tijd behaald, stuur melding via php
}
void Bed::bedLight(){
	int switchLed = inputs.value("switchLed", 2);
	if (switchLed == 2){
		cerr << "Error while reading switchLed" << endl;
		return;
	}
	else if(switchLed){
		ledStatus = !ledStatus;
		outputs["ledState"] = ledStatus;
	}
}
