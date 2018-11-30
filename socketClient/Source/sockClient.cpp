/*
 * sockClient.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: programmer
 */

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "sockClient.h"

using namespace std;

/*to do:
 * create object X
 * Create socket X
 * create hint for server we re connecting to
 * connect to socket
 * read
 * write
 * close/destroy
 */

//create object
sockClient::sockClient()
{
	sock = -1; //default -1 to indicate it hasnt been started yet
	port = 0; //variable to store port number
	address = ""; //variable to store address

	//server;
}

sockClient::sockClient(string addr, int prt)
{
	sock = -1; //default -1 to indicate it hasnt been started yet
	port = prt; //variable to store port number
	address = addr; //variable to store address
	//server;
}

//create socket
int sockClient::createSock(sockClient* sc)
{

	if (sc->sock == -1) //Socket not yet created or failed to create on last try.
	{
		sc->sock = socket(AF_INET, SOCK_STREAM, 0); //create socket(ipv4, tcp, protocol auto)
	}
	if (sc->sock == -1) //Failed to create socket
	{
		cerr << "Failed to create socket" << endl;
		return -1;
	}
	return sc->sock;
}

//create hint structure for the server we want to connect with./////////
void sockClient::setHint(sockClient* sc)
{
	sc->server.sin_family = AF_INET; //ipv4
	sc->server.sin_port = htons(sc->port); //string to network short (small endian?)
	inet_pton(AF_INET, sc->address.c_str(), &sc->server.sin_addr); //convert to sin addr
}


bool sockClient::connectToServer(sockaddr_in sa, sockClient* sc)
{
	//connect to hint

	int connection = connect(sc->sock, (sockaddr*)&sa, sizeof(sa));
	if (connection == -1)
	{
		cerr << " unable to connect" <<endl;
		return false;
	}
	else
	{
		return connection;
	}
}

bool sockClient::sendToServer(string data) //send
{

	//socket, data as c string, datasize +1 because the conversion to a c string adds an extra (\0) to the string
	int sendResult = send(this->sock, data.c_str(), data.size() + 1, 0);
	if (sendResult == -1) //unable to send
	{
		cerr << "Unable to send data to server." << endl;
		return false;
	}
	else
	{
		return true;
	}

}

string sockClient::receiveFromServer(sockClient* sc) //receive
{

	struct timeval tv; //timeout settings for receive timeout
		tv.tv_sec = 3; //seconds
		tv.tv_usec = 0; //mircoseconds

	setsockopt(sc->sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));


	char buffer[4096]; //buffer for received data
	memset(buffer, 0, 4096); // clear buffer (flush with 0)
	int dataReceived = recv(sc->sock, buffer, 4096, 0); //socket, store in buffer, size, flag.
	if(dataReceived == -1){ //if there is no data
		cerr << "There was an error while getting the data from the server" << endl;
		return "error"; //is there a better way?
	}
	else //print received data
	{
		cout << "Server> " << string(buffer, dataReceived) << endl;
	}

	return buffer;
}

void sockClient::closeSocket(sockClient* sc){
	if(sc->sock == -1){ //check if socket exists
		cerr << "Socket has already been closed" << endl;
	}
	else{ //close socket
		close(sc->sock);
	}
}
