/*
 * File.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: programmer
 */

#include <fstream>
#include "File.h"
#include <iostream>
#include "json.hpp"

using namespace std;


File::File(const char* pth) {
	this->path = pth;
	currentFile = new fstream;

}

File::~File() {

}

string File::readFile(){



	currentFile->open(path, std::fstream::in);
	if(currentFile->is_open()){
		string data;
		std::getline((*currentFile), data);
		closeFile();
		return data;
	}
	else{
		cerr << "unable to open file for reading" << endl;
		return "error";
	}
}

void File::closeFile(){
	this->currentFile->close();
}

void File::writeToFile(nlohmann::json jp){

	this->currentFile->open(this->path, fstream::out | fstream::trunc);
	if(this->currentFile->is_open()){

		*currentFile <<  jp;

	}
	else{
		cerr << "unable to open file for writing. " << this->path << endl;
		return;
	}
	this->closeFile();
}
