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

Window::Window(string ip, int port):Device(ip,port), potmeterLedOld(0), ledOld(0){
	phpCom->phpDataJson["window"] = 0; //create entry in json file to guarantee it exists.
	phpCom->writeToFile();
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
	phpCom->updateData();
	requestInputs();
	handleLed();
	handleSun();
	setOutputs();
	phpCom->writeToFile();
}

void Window::handleLed(){
	//when a button is pressed on the interface, the led dimmed
	int numberPressed = phpCom->phpDataJson.value("brWindowLight", 111);;
	if (numberPressed == 111){
		cerr << "Error while reading brWindowLight" << endl;
		return;
	}
	//when the value from potmeter is changed, the led dimming change
	int potmeterLed = inputs.value("potmeterLed", 1050); //get value if error return 1050
	if (potmeterLed == 1050){ //check for error
		cerr << "Error while reading input values. PotmeterLed could not be found in Json" << endl;
		potmeterLed = 0;
		//return;
	}
	int ledStatus = phpCom->phpDataJson.value("windowLight", 2);;
		if (numberPressed == 2){
			cerr << "Error while reading brWindowLight" << endl;
			return;
		}

	if(ledStatus || potmeterLed > 50){
	//demarcation potmeter at beginning and end
		if (potmeterLed > 1000){
			potmeterLed = 1020;
		}
		else if (potmeterLed < 50){
			potmeterLed = 0;
			if (ledOld != numberPressed) {
				switch (numberPressed){
				case 0 : outputs["windowLed"] = 0;break;
				case 10 : outputs["windowLed"] = 10;break;
				case 20 : outputs["windowLed"] = 20;break;
				case 30 : outputs["windowLed"] = 40;break;
				case 40 : outputs["windowLed"] = 70;break;
				case 50 : outputs["windowLed"] = 110;break;
				case 60 : outputs["windowLed"] = 140;break;
				case 70 : outputs["windowLed"] = 170;break;
				case 80 : outputs["windowLed"] = 200;break;
				case 90 : outputs["windowLed"] = 230;break;
				case 100 : outputs["windowLed"] = 255;break;
				}
				ledOld = numberPressed;
				}
		}
		else {
			int minus = potmeterLedOld - potmeterLed; //calculate difference

			if (minus > 5 || minus < -5) { //set a range

				int sendToWhemos = potmeterLed / 4;
				outputs["windowLed"] = sendToWhemos;
			}
			potmeterLedOld = potmeterLed;
		}
	}
	else{
		outputs["windowLed"] = 0;
	}

}

void Window::handleSun(){
	int blendphp = phpCom->phpDataJson.value("window", 2);;
		if (blendphp == 2){
				cerr << "Error while reading window" << endl;
				return;
		}

	int LDR = inputs.value("windowLDR", 1050); //get value if error return 1050
		if (LDR == 1050){ //check for error
			cerr << "Error while reading input values. WindowLDR could not be found in Json" << endl;
			LDR = 0;
			//return;
		}

	if (LDR > 925 || blendphp) { //if it is above 1000 the sun is to bright
		outputs["windowBlend"] = 1; //the window will blend
	}
	else {
		outputs["windowBlend"] = 0; //the window is normal
	}

}


