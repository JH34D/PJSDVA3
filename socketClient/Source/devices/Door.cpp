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
	handleDoor();
	handleFire();
	setOutputs();
}

void Door::handleDoor(){
	int doorButton = inputs.value("doorButton", 20); //get value if error return 1050
			if (doorButton == 14){ //check for error
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
	int fireDetector = inputs.value("fireDetector", 1050); //get value if error return 1050
			if (fireDetector == 1050){ //check for error
				cerr << "Error while reading input values. fireDetector could not be found in Json object in function handleFire in class Door" << endl;
				fireDetector = 0;
				//return;
			}
			if (fireDetector > 200 && fireDetector < 450) {
				outputs["openDoor"] = 0;
			}
			else {
				outputs["openDoor"] = 1;
			}
}

