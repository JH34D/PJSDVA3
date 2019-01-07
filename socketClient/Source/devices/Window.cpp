/*
 * Window.cpp
 *
 *  Created on: Jan 3, 2019
 *      Author: programmer
 */
#include "Window.h"
#include <iostream>
#include "../sockClient.h"
#include "../File.h"

using namespace std;
using namespace nlohmann;

Window::Window(string ip, int port):Device(ip,port), potmeterLedOld(9){

}

Window::~Window(){
	//
}

void Window::handleActions(){
	/*
	 * request inputs
	 * handle actions and set ouput value in json object
	 * set outputs
	 * return json for php?
	 */

	requestInputs();
	handleLed();
	handleSun();
	handlePHP();

	setOutputs();
}

void Window::handleLed(){
	int sendToWhemos;
	int potmeterLed = inputs.value("potmeterLed", 1050); //get value if error return 1050
		if (potmeterLed == 1050){ //check for error
			cerr << "Error while reading input values. PotmeterLed could not be found in Json" << endl;
			potmeterLed = 0;
			//return;
		}
		if (potmeterLedOld != potmeterLed) {
			if (potmeterLed > 1020){
				potmeterLed = 1020;
			}
			sendToWhemos = potmeterLed / 4;
			outputs["windowLed"] = sendToWhemos;
		}
	potmeterLedOld = potmeterLed;

}

void Window::handleSun(){

	int LDR = inputs.value("windowLDR", 1050); //get value if error return 1050
		if (LDR == 1050){ //check for error
			cerr << "Error while reading input values. WindowLDR could not be found in Json" << endl;
			LDR = 0;
			//return;
		}
		if (LDR > 400) { //if it is above 400 the sun is to bright
			outputs["windowBlend"] = 1; //the window will blend
		}
		else {
			outputs["windowBlend"] = 0; //the window is normal
		}

}

void Window::handlePHP(){

	//when a button is pressed on the interface, the led dimmed
	int numberPressed = 9; //todo get number from PHP
	switch (numberPressed){
	case 0 : outputs["windowLed"] = 0;break;
	case 1 : outputs["windowLed"] = 10;break;
	case 2 : outputs["windowLed"] = 20;break;
	case 3 : outputs["windowLed"] = 40;break;
	case 4 : outputs["windowLed"] = 70;break;
	case 5 : outputs["windowLed"] = 110;break;
	case 6 : outputs["windowLed"] = 160;break;
	case 7 : outputs["windowLed"] = 255;break;
	}

}
