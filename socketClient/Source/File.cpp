/*
 * File.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: programmer
 */

#include <fstream>
#include "File.h"
#include <iostream>

using namespace std;


File::File(string pth, fstream* fsa) {
	this->path = pth.c_str(); //string to char*
	this->currentFile = fsa;

}

File::~File() {

}

string File::readFile(){


	//this->currentFile->open(this->path, fstream::in);
	currentFile->open(path, std::fstream::in);
	if(this->currentFile->is_open()){
		string data;
		std::getline((*currentFile), data);
		this->closeFile();
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

void File::writeToFile(string data){


	this->currentFile->open(this->path, fstream::out | fstream::trunc);


	if(this->currentFile->is_open()){
		*currentFile << data;
	}
	else{
		cerr << "unable to open file for writing. " << this->path << endl;
		return;
	}
	this->closeFile();
}
