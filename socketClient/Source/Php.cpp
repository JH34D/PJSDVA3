/*
 * Php.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#include "Php.h"

Php::Php() : phpRw("/home/pi/workingDir/output.json"), phpDataJson(nlohmann::json::parse(phpRw.readFile())) {

}

Php::~Php() {

}

void Php::updateData(){
	static nlohmann::json phpDataOld;
	if(phpDataOld == phpDataJson){
		return;
	}
	else{
		phpDataJson = nlohmann::json::parse(phpRw.readFile());
		phpDataOld = phpDataJson;
	}
}

void Php::writeToFile(){
	phpRw.writeToFile(phpDataJson);
}
