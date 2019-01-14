/*
 * File.h
 *
 *  Created on: Nov 27, 2018
 *      Author: programmer
 */
#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;

#ifndef FILE_H_
#define FILE_H_

class File {
public:
	//File();
	File(const char*); //constructor takes path to file
	virtual ~File();

	//void openFile();

	string readFile(); //opens file, returns data in file
	void writeToFile(nlohmann::json); //takes json object, converts to string and writes to file
	//setInUse(bool);


private:
	fstream *currentFile;
	const char* path;
	void closeFile();
};

#endif /* FILE_H_ */
