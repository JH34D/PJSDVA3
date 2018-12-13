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
	sockaddr_in server;

	void setHint();


public: //sockclient pointer? parameter or this.?





	sockClient();
	sockClient(string, int);
	int createSock();
	//no return so void? \/
	bool connectToServer();//sockaddr_in); //connect to socket
	bool sendToServer(string data); //send
	string receiveFromServer(); //receive

	void closeSocket();
};

#endif /* SOCKCLIENT_H_ */
