/*
 * Chair.h
 *
 *  Created on: Dec 13, 2018
 *      Author: programmer
 */

#ifndef CHAIR_H_
#define CHAIR_H_

#include <iostream>
#include "File.h"
#include "sockClient.h"


class Chair { //might make "motherclass" with common attributes like file, socket etc.

public:
	Chair(string ip, int port, const char* path);
	virtual ~Chair();
	void handleWemos();
	void handleGui();



private:
//const char* filepath;
File phpCom; //used for communication with php on the interface
sockClient wemosCom; //used for communication with c on the WeMos

//located = hanks room?
//data bought?

};

#endif /* CHAIR_H_ */
