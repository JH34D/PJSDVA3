/*
 * Column.h
 *
 *  Created on: Dec 15, 2018
 *      Author: programmer
 */

#ifndef DEVICES_COLUMN_H_
#define DEVICES_COLUMN_H_

#include <iostream>
#include "../Device.h"

class Column : public Device {
public:
	Column(string ip, int port);
	virtual ~Column();
	void handleActions();
private:
	void fireAlarm();
};

#endif /* DEVICES_COLUMN_H_ */


