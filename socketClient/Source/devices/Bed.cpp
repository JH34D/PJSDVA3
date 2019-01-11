/*
 * Bed.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#include "Bed.h"

Bed::Bed(string ip, int port) : Device(ip, port), inBed(0), prevInBedState(0), timeOutOfBed(0), ledOnTime(0) {
	phpCom->phpDataJson["bedtime"] = 0; //create entry in json file to guarantee it exists.
	phpCom->phpDataJson["notInBed"] = 0;
	phpCom->writeToFile();

}

Bed::~Bed() {

}

void Bed::handleActions(){
	phpCom->updateData();
	requestInputs();
	bedLight();
	outOfBed();
	setOutputs();
	phpCom->writeToFile();
}

void Bed::outOfBed(){ //TODO add php notification to hank between 22 00 and 22 30, notfication to caretaker if not in bed after 22 30
	time_t rawTime = time(0);
	struct tm* currentTime;
	currentTime = localtime(&rawTime);
	currentTime->tm_hour = 22; currentTime->tm_min = 15;//testing
	if(currentTime->tm_hour > 21 || currentTime->tm_hour < 7){
		int lays = inputs.value("pressure", 1250); //get value if error return 1250
		if (lays == 1250){ //check for error
			cerr << "Error while reading input values. Lays could not be found in Json object." << endl;
			return;
		}
		if(lays > 700){
			inBed = 1;
			phpCom->phpDataJson["bedtime"] = 0;
		}
		else{
			inBed = 0;
			if(currentTime->tm_hour == 22 && currentTime->tm_min <= 30){
				phpCom->phpDataJson["bedtime"] = 1;
			}
			else {
				phpCom->phpDataJson["bedtime"] = 0;
			}
			if(prevInBedState){
				timeOutOfBed = time(0);
			}
		}
		if(inBed == 0 && getTimePassedInMinutes(timeOutOfBed) >= 30.00){ //if hanks is out of bed longer than 30 minutes at night, notify
			phpCom->phpDataJson["notInBed"] = 1;
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
