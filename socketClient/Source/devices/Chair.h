/*
 * Chair.h
 *
 *  Created on: Dec 13, 2018
 *      Author: programmer
 */

#ifndef CHAIR_H_
#define CHAIR_H_

#include <iostream>
//#include "../File.h"
//#include "../sockClient.h"
#include "../Device.h"



class Chair : public Device {

public:
	Chair(string ip, int port);
	virtual ~Chair();
	void handleActions();
private:
	void handleBedtime(); //checks if user in is chair after bedtime
	void handleAggression(); //check if user is restless
	bool aggressionTracker[10]; //store data about sit state
	time_t lastMeasurement; //track time
	int trackerIndex; //index for array
	double getTimePassedInSeconds(); //see name


};

#endif /* CHAIR_H_ */
