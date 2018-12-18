/*
 * Php.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#include "Php.h"

Php::Php() : phpRw("/home/pi/workingDir/output.json"), phpDataJson(nlohmann::json::parse(phpRw.readFile())) {
	// TODO Auto-generated constructor stub

}

Php::~Php() {
	// TODO Auto-generated destructor stub
}

void Php::updateDataRead(){
	phpDataJson = nlohmann::json::parse(phpRw.readFile());
}

void Php::writeToFile(){
	phpRw.writeToFile(phpDataJson);
}
