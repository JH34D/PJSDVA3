/*
 * File.h
 *
 *  Created on: Nov 27, 2018
 *      Author: programmer
 */
#include <iostream>
#include <fstream>

using namespace std;

#ifndef FILE_H_
#define FILE_H_

class File {
public:
	//File();
	File(string, fstream*);
	virtual ~File();

	//void openFile();

	string readFile();
	void writeToFile(string);
	//setInUse(bool);


private:
	fstream *currentFile;
	const char* path;
	void closeFile();


};

#endif /* FILE_H_ */
