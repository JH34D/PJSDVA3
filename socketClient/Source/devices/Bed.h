/*
 * Bed.h
 *
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#ifndef DEVICES_BED_H_
#define DEVICES_BED_H_
#include "../Device.h"

class Bed : public Device {
public:
	Bed(string ip, int port);
	virtual ~Bed();
	void handleActions();
private:
	void outOfBed(); //checks if the user is laying down
	void bedLight(); //handles actions for the bedtime
	bool ledStatus = false; //used to track ledstate
	bool inBed; //state indicates if user is laying
	bool prevInBedState; //used to track changes
	time_t timeOutOfBed; //used to time
	time_t ledOnTime; //used to time
	double getTimePassedInMinutes(time_t prev); //used to compare times

};

#endif /* DEVICES_BED_H_ */
