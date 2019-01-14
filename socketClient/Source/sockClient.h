/*
 * sockClient.h
 *
 *  Created on: Nov 17, 2018
 *      Author: programmer
 */
#include <iostream>
#include <sys/types.h> //socket
#include <unistd.h> //socket
#include <sys/socket.h> //socket
#include <netdb.h> //socket
#include <arpa/inet.h> //socket



using namespace std;

#ifndef SOCKCLIENT_H_
#define SOCKCLIENT_H_


class sockClient
{
private:

	string address; //ip
	int port; //port
	int sock; //socket
	sockaddr_in server; //hint
	void setHint(); //function to set hint

public:
	sockClient(string, int); //constructor
	int createSock(); //set socket
	bool connectToServer();//call sethint and connect to socket
	bool sendToServer(string data); //send data
	string receiveFromServer(); //receive data
	void closeSocket(); //close socket currently not used
};

#endif /* SOCKCLIENT_H_ */
