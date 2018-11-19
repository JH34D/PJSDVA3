/*
 * sockClient.h
 *
 *  Created on: Nov 17, 2018
 *      Author: programmer
 */
#include <iostream>



using namespace std;

#ifndef SOCKCLIENT_H_
#define SOCKCLIENT_H_


class sockClient
{
private:

	string address; //ip
	int port; //port
	int sock; //socket



public: //sockclient pointer? parameter or this.?


	sockaddr_in server; //hint for server


	sockClient();
	sockClient(string, int);
	int createSock(sockClient*);
	//no return so void? \/
	bool connectToServer(sockaddr_in , sockClient*); //connect to socket
	bool sendToServer(string data); //send
	string receiveFromServer(sockClient*); //receive
	void setHint(sockClient*);
	void closeSocket(sockClient*);
};

#endif /* SOCKCLIENT_H_ */
