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
	//handleDoor();
	//handleFire();
	handlePhp();
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
				phpCom->phpDataJson["door"] = 1;
				cout << "handleDoor 1"  << endl;
			}
			else if (doorButton == 12){
				outputs["openDoor"] = 0;
				phpCom->phpDataJson["door"] = 0;
				cout << "handleDoor 0"  << endl;
			}
	}
void Door::handleFire(){
	int fireDetector = interDevCom.value("fireDetector", 20); //get value if error return 20
			if (fireDetector == 20){ //check for error
				cerr << "Error while reading input values. fireDetector could not be found in Json object in function handleFire in class Door" << endl;
				fireDetector = 0;
			}
			if (fireDetector ==1) { //fire has been detected and value has been set.
				outputs["openDoorFire"] = 1; //if fire then the door opens
				phpCom->phpDataJson["door"] = 1;
				cout << "firedetector 1"  << endl;
			}
			else if (fireDetector == 0){
				outputs["openDoorFire"] = 0;
				phpCom->phpDataJson["door"] = 0;
				cout << "firedetector 0"  << endl;
			}
}

void Door::handlePhp(){
/*	int doorState = phpCom->phpDataJson.value("door", 20) ;
		if (doorState == 20){
			cerr << "Error while reading doorState" << endl;
			doorState = 0;
		}
		if (doorState == 1){
			outputs["openDoorPhp"] = 1;
			phpCom->phpDataJson["door"] = 1;
			cout << "handlephp 1"  << endl;
		}else if (doorState == 0){
			outputs["openDoorPhp"] = 0;
			phpCom->phpDataJson["door"] = 0;
			cout << "handlephp 0"  << endl;
		}
*/

	int doorButton = inputs.value("doorButton", 20); //get value if error return 1050
	if (doorButton == 20){ //check for error
		cerr << "Error while reading input values. doorButton could not be found in Json object in function handleDoor() in class Door  " << endl;
		doorButton = 0;
		//return;
	}
	int doorState = phpCom->phpDataJson.value("door", 20) ;
			if (doorState == 20){
				cerr << "Error while reading doorState" << endl;
				doorState = 0;
			}
	int fireDetector = interDevCom.value("fireDetector", 20); //get value if error return 20
			if (fireDetector == 20){ //check for error
				cerr << "Error while reading input values. fireDetector could not be found in Json object in function handleFire in class Door" << endl;
				fireDetector = 0;
			}

	if (doorButton == 13 || doorState || fireDetector) {
		outputs["openDoor"] = 1;
		//phpCom->phpDataJson["door"] = 1;
	}
	else {
		outputs["openDoor"] = 0;
		phpCom->phpDataJson["door"] = 0;
	}

}


