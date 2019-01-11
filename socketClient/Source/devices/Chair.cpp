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

Chair::Chair(string ip, int port):Device(ip,port),lastMeasurement(time(0)),trackerIndex(0){
	phpCom->phpDataJson["aggressive"] = 0; //create entry in json file to guarantee it exists.
	phpCom->writeToFile();
}

Chair::~Chair(){
	//
}

void Chair::handleActions(){
	requestInputs();
	phpCom->updateData();
	handleBedtime();
	handleAggression();
	setOutputs();
	phpCom->writeToFile();

}

void Chair::handleBedtime(){

	int sits = inputs.value("pressure", 1250); //get value if error return 8
	if (sits == 1250){ //check for error
		cerr << "Error while reading input values. Sits could not be found in Json object in function handleBedtime() in class chair" << endl;
		sits = 0;
		//return;
	}
	time_t rawTime = time(0);
	struct tm* currentTime;
	currentTime = localtime(&rawTime);
	//currentTime->tm_hour = 22; //testing.
	if (sits > 700 && (currentTime->tm_hour > 21 || currentTime->tm_hour < 7)){
		outputs["vibrate"] = 1;
	}
	else {
		outputs["vibrate"] = 0;
	}

}

void Chair::handleAggression(){ //checks how many times user was seated during a 10 seconds timeframe.
	if(phpCom->phpDataJson.value("aggressive", 8) == 0){ //if data for php has not been set or reset by php
		if(getTimePassedInSeconds() >= 1.0){
			if (trackerIndex == 10){

				trackerIndex = 0;
				int sum = 0;
				for(int i = 0; i<10; i++){
					sum += aggressionTracker[i];
				}
				if(sum <= 8 && sum > 2){ //if user stood up twice or sat down more than twice during the last 10 seconds, make chair vibrate
					outputs["vibrate"] = 1;
					phpCom->phpDataJson["aggressive"] = 1;
				}
				else {
					outputs["vibrate"] = 0;
				}
			}
			else {

				int sits = inputs.value("pressure", 1250); //get value if error return 8
				if (sits == 1250){ //check for error
					cerr << "Error while reading input values. Sits could not be found in Json object." << endl;
					sits = 0;
					return;
				}
				if (sits > 700){
					aggressionTracker[trackerIndex++] = 1;
				}
				else{
					aggressionTracker[trackerIndex++] = 0;
				}

			}
			lastMeasurement = time(0);

		}

	}
}

double Chair::getTimePassedInSeconds(){
	return difftime(time(0), lastMeasurement);
}

