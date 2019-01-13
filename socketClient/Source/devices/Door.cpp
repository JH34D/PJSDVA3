/*
 * Door.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#include "Door.h"
#include <iostream>
#include "../sockClient.h"
#include "../File.h"

using namespace std;
using namespace nlohmann;

Door::Door(string ip, int port):Device(ip,port) {
	// TODO Auto-generated constructor stub

}

Door::~Door() {
	// TODO Auto-generated destructor stub
}

void Door::handleActions(){

	requestInputs();
	phpCom->updateData();
	handleDoor();
	handleFire();
	setOutputs();
	phpCom->writeToFile();
}

void Door::handleDoor(){
	int doorButton = inputs.value("doorButton", 20); //get value if error return 1050
			if (doorButton == 20){ //check for error
				cerr << "Error while reading input values. doorButton could not be found in Json object in function handleDoor() in class Door  " << endl;
				doorButton = 0;
				//return;
			}
			if (doorButton == 13) {
				outputs["openDoor"] = 1;
			}
			else {

				outputs["openDoor"] = 0;
			}
	}
void Door::handleFire(){
	int fireDetector = interDevCom.value("fireDetector", 20); //get value if error return 20
			if (fireDetector == 20){ //check for error
				cerr << "Error while reading input values. fireDetector could not be found in Json object in function handleFire in class Door" << endl;
				fireDetector = 0;
			}
			if (fireDetector) { //fire has been detected and value has been set.
				outputs["openDoor"] = 10; //if fire then the door opens
			}
			else {
				outputs["openDoor"] = 80;
			}
}

void Door::handlePhp(){
	int doorState = phpCom->phpDataJson.value("door", 20) ;
		if (doorState == 20){
			cerr << "Error while reading doorState" << endl;
			doorState = 0;
		}
		if (doorState == 1){
			outputs["phpOpen"] = 10;
		}else if (doorState == 0 && outputs["phpOpen"] == 10){
			outputs["phpOpen"] = 80;
		}
}
