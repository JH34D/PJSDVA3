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
	void outOfBed();
	void bedLight();
	bool ledStatus = false;
};

#endif /* DEVICES_BED_H_ */