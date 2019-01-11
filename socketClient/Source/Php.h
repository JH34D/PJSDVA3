/*
 * Php.h
 *	handles interaction with php
 *  Created on: Dec 18, 2018
 *      Author: programmer
 */

#ifndef PHP_H_
#define PHP_H_

#include "File.h"
#include "json.hpp"



class Php {
private:
	File phpRw;
public:
	Php();
	virtual ~Php();
	nlohmann::json phpDataJson;
	void updateData(); //reads json data from file and stores it in phpDataJson. recommended to call function before checking a json value.
	void writeToFile(); //writes data to json file. Needs to be called to get the changes to interface.


};

#endif /* PHP_H_ */
