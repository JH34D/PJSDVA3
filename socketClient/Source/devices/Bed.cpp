/*
 * Bed.cpp
 *
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#include "Bed.h"

Bed::Bed(string ip, int port) : Device(ip, port) {
	// TODO Auto-generated constructor stub

}

Bed::~Bed() {
	// TODO Auto-generated destructor stub
}

void Bed::handleActions(){
	requestInputs();
	/*
	 * seintje als langer uit bed dan x (get time of day naar functie met struct als return?)
	 * Bedlampje uit na bepaalde tijd.
	 * melding als om 22:30 nog niet in bed
	 */

	setOutputs();
}

void Bed::outOfBed(){

}
