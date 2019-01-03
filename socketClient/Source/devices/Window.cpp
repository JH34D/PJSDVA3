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

Window::Window(string ip, int port):Device(ip,port){

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


	setOutputs();
}


