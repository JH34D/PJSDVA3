/*
 * Bed.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#include "Bed.h"

Bed::Bed(string ip, int port) : Device(ip, port), inBed(0), prevInBedState(0), timeOutOfBed(0), ledOnTime(0) {
	// TODO Auto-generated constructor stub

}

Bed::~Bed() {
	// TODO Auto-generated destructor stub
}

void Bed::handleActions(){
	requestInputs();
	bedLight();
	outOfBed();
	setOutputs();
}

void Bed::outOfBed(){
	time_t rawTime = time(0);
	struct tm* currentTime;
	currentTime = localtime(&rawTime);
	if(currentTime->tm_hour > 21 || currentTime->tm_hour < 7){
		int lays = inputs.value("pressure", 1250); //get value if error return 1250
		if (lays == 1250){ //check for error
			cerr << "Error while reading input values. Sits could not be found in Json object." << endl;
			return;
		}
		if(lays > 700){
			inBed = 1;
		}
		else{
			inBed = 0;
			if(prevInBedState){
				timeOutOfBed = time(0);
			}
		}
		if(inBed == 0 && getTimePassedInMinutes(timeOutOfBed) >= 30.00){
			//write "notInBed":1 to php;
		}
		prevInBedState = inBed;
	}

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
		if(ledStatus){
			ledOnTime = time(0);
		}

	}
	if(ledStatus && getTimePassedInMinutes(ledOnTime) >= 15.00){ //if light has been on for 15 minutes, turn off
		ledStatus = 0;
		outputs["ledState"] = ledStatus;
	}

}

double Bed::getTimePassedInMinutes(time_t prev){
	return difftime(time(0), prev)/60;
}
